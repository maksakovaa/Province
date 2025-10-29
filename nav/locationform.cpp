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
    videoWidg->setFixedSize(900,600);
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
    std::cout << " locationForm init started for " << loc.toStdString() << std::endl;
    if (m_currentLoc == nullptr)
    {
        if (loc == "gaddvor")
        {
            m_currentLoc = new Location("gadukino", "gaddvor", nullptr, m_bag);
        }
        else
        {
            m_currentLoc = new Location("pavlovo", "parents_home", nullptr, m_bag);
        }
        
    }
    else
    {
        std::cout << "m_current_loc in not null!" << std::endl;
    }
    slotChangeLoc(m_currentLoc, 0);
}

Location *LocationForm::getCurPtr()
{
    return m_currentLoc;
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

void LocationForm::slotOnChangeLocation(const QString name, int min)
{
    Location* newLocation = new Location(m_currentLoc->getLocIn(), name, nullptr, m_bag);
    slotChangeLoc(newLocation, min);
}

void LocationForm::slotChangeLoc(Location *locPtr, int min)
{
    m_page->setCurrentIndex(0);
    ui->imageAndWideoWdgt->setCurrentIndex(0);

    m_currentLoc = locPtr;

    if(m_currentLoc != nullptr)
    {
        setImage(m_currentLoc->getLocPic(m_weather->isDay(), m_weather->isSnow()));
        setDesc(m_currentLoc->getLocDesc());
    }
    m_time->increaseTime(min);
    if(m_currentLoc->getLocIn() == "gadukino")
    {
        emit sigIsMapAwaylable(false);
    }
    else
    {
        bool status = !m_currentLoc->isParent();
        emit sigIsMapAwaylable(status);
    }
    fillSubLocs();
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
    connect(this, &BathActBtn::clicked, this, &BathActBtn::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void BathActBtn::handleButtonClick()
{
    emit sigAction(m_action);
}
