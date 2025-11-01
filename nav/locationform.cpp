#include "locationform.h"
#include "ui_locationform.h"
#include "../Functions.h"
#include "qactionbutton.h"
#include <sexviewform.h>
#include "objviewform.h"

LocationForm::LocationForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LocationForm)
{
    ui->setupUi(this);
    videoWidg = new Video(ui->widget);
    ui->videoLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->videoLayout->addWidget(videoWidg);
    ui->labelLocDesc->setWordWrap(true);
    m_currentLoc = nullptr;
    m_bath = new BathRoom(this);
}

LocationForm::~LocationForm()
{
    delete ui;
}

void LocationForm::setPlayerPtr(Player* ptr)
{
    m_player = ptr;
}

void LocationForm::setActionsLayout(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

void LocationForm::setTimePtr(TimeServer *ptr)
{
    m_time = ptr;
}

void LocationForm::setPagePtr(QStackedWidget *ptr)
{
    m_page = ptr;
    m_bag = m_page->widget(3)->findChild<BagForm*>("BagForm");
    m_settings = (SettingsForm*)m_page->widget(6);
}

void LocationForm::setWeatherPtr(Weather *ptr)
{
    m_weather = ptr;
}

void LocationForm::setCCSEX(CCSex *ptr)
{
    m_ccsex = ptr;
}

void LocationForm::init(QString loc)
{
    createLocations();

    if (m_currentLoc == nullptr)
    {
        m_currentLoc = m_locations[loc];
        slotChangeLoc(m_currentLoc, 0);
    }
    else
    {
        std::cout << "m_current_loc in not null!" << std::endl;
    }
}

Location *LocationForm::getCurPtr()
{
    return m_currentLoc;
}

Location *LocationForm::getPrevPtr()
{
    return m_prevLoc;
}

void LocationForm::reloadLocation()
{
    fillSubLocs();
    bool status = !m_currentLoc->isParent();
    emit sigIsMapAwaylable(status);
}

QLabel *LocationForm::getImageLblPtr()
{
    return ui->labelLocImage;
}

void LocationForm::slotOnChangeLocation(const QString &name, int min)
{
    m_currentLoc = m_locations[name];
    slotChangeLoc(m_currentLoc, min);
}

void LocationForm::slotChangeLoc(Location *locPtr, int min)
{
    m_page->setCurrentIndex(0);
    ui->imageAndWideoWdgt->setCurrentIndex(0);
    m_prevLoc = m_currentLoc;
    m_currentLoc = locPtr;

    if(m_currentLoc != nullptr)
    {
        setImage(m_currentLoc->getLocPic(m_weather->isDay(), m_weather->isSnow()));
        setDesc(m_currentLoc->getLocDesc());
    }
    m_time->increaseTime(min);
    if(m_currentLoc->isParent() || m_currentLoc->getLocId() == "gadukino")
    {
        emit sigIsMapAwaylable(false);
    }
    else
    {
        emit sigIsMapAwaylable(true);
    }
    fillSubLocs();
}

void LocationForm::DFSlocations(Location* parent)
{
    std::vector<Location*> tmp = parent->awailableLocs();
    for (int i = 0; i < tmp.size(); ++i)
    {
        m_locations[tmp[i]->getLocId()] = tmp[i];
        if(!tmp[i]->awailableLocs().empty())
        {
            DFSlocations(tmp[i]);
        }
    }
}

void LocationForm::fillSubLocs()
{
    ClearLayout(m_actLayout);
    if(m_currentLoc->getLocId().startsWith("bathroom"))
    {
        m_bath->start();
        return;
    }
    std::vector<Location*> locs = m_currentLoc->awailableLocs();
    std::vector<QString> objs = m_currentLoc->availableObjs();
    std::vector<struct Action*> acts = m_currentLoc->availableActions();

    if(m_currentLoc->isParent())
    {
        locs.push_back(m_currentLoc->getParentPtr());
    }
    for (auto& i: objs)
    {
        QActionButton* actionbtn = new QActionButton;
        actionbtn->setText(i);
        actionbtn->setObjName(i);
        m_actLayout->addWidget(actionbtn);
        ObjViewForm* m_objView = (ObjViewForm*)m_page->widget(4);
        connect(actionbtn, &QActionButton::sigViewObj, m_objView, &ObjViewForm::slotViewObj);
    }
    for (auto& i: locs)
    {
        QActionButton* actionbtn = new QActionButton(1);
        actionbtn->setText(i->getActName());
        actionbtn->setLocPtr(i);
        m_actLayout->addWidget(actionbtn);
        connect(actionbtn, &QActionButton::sigChangeSubLoc, this, &LocationForm::slotChangeLoc);
    }
}

void LocationForm::createLocations()
{
    QFile file(":/locations/locations.list");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file! " + file.fileName();
    }
    else
    {
        QTextStream in(&file);
        QString line;
        QString indStart[] {"<parent>" , "<pavlovo>" , "<gadukino>"};
        QString indEnd[] {"</parent>" ,  "</pavlovo>", "</gadukino>"}; 
        while (!in.atEnd())
        {
            line = in.readLine();
            if (line.startsWith(indStart[0]))
            {
                line = line.sliced(indStart[0].size(), line.indexOf(indEnd[0]) - indStart[0].size());
                Location* parent = new Location(line);
                m_locations[line] = parent;
                DFSlocations(parent);
            }
            else if (line.startsWith(indStart[1]))
            {
                Location *par = m_locations[indStart[1].sliced(1, indStart[1].size() - 2)];
                line = line.sliced(indStart[1].size(), line.indexOf(indEnd[1]) - indStart[1].size());
                Location *child = new Location(par, line, ":/locations/" + par->getLocId() + "/");
                m_locations[line] = child;
                DFSlocations(child);
            }
            else if (line.startsWith(indStart[2]))
            {
                Location *par = m_locations[indStart[2].sliced(1, indStart[2].size() - 2)];
                line = line.sliced(indStart[2].size(), line.indexOf(indEnd[2]) - indStart[2].size());
                Location *child = new Location(par, line, ":/locations/" + par->getLocId() + "/");
                m_locations[line] = child;
                DFSlocations(child);
            }
        }
    }
}

void LocationForm::incTime(int min)
{
    m_time->increaseTime(min);
}

void LocationForm::updVBody(Body param, int val)
{
    m_player->updVBody(param, val);
}

void LocationForm::updVStatus(Status param, int val)
{
    m_player->updVStatus(param,val);
}

void LocationForm::updVStatistic(SC param, int val)
{
    m_player->updVStatistic(param,val);
}

void LocationForm::useItem(Items item, int count)
{
    m_bag->removeFromBag(item, count);
}

void LocationForm::setSexVar(SexVar var, int value)
{
    m_player->setVSexVar(var, value);
}

void LocationForm::setVStatus(Status param, int value)
{
    m_player->setVStatus(param, value);
}

void LocationForm::setVBody(Body param, int value)
{
    m_player->setVBody(param, value);
}

int LocationForm::getVBody(Body param)
{
    return m_player->getVBody(param);
}

int LocationForm::getVStatus(Status param)
{
    return m_player->getVStatus(param);
}

int LocationForm::getItmCount(Items item)
{
    return m_bag->getQuantityof(item);
}

int LocationForm::getSexVar(SexVar var)
{
    return m_player->getVSexVar(var);
}

int LocationForm::getVStatistic(SC param)
{
    return m_player->getStatisticsValue(param);
}

void LocationForm::setImage(QString path)
{
    ui->labelLocImage->setText("<img src='" + path + "'></img>");
}

void LocationForm::setDesc(QString text)
{
    ui->labelLocDesc->setText(text);
}

void LocationForm::addDesc(QString str)
{
    ui->labelLocDesc->setText(ui->labelLocDesc->text() + str);
}

BathActBtn::BathActBtn(bathActs act, QString actName)
{
    this->setCursor(Qt::PointingHandCursor);
    connect(this, &BathActBtn::clicked, this, &BathActBtn::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void BathActBtn::handleButtonClick()
{
    emit sigAction(m_action);
}
