#include "locationform.h"
#include "objviewform.h"
#include "ui_locationform.h"
#include "../Functions.h"
#include "qactionbutton.h"
#include <sexviewform.h>

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
}

void LocationForm::setWeatherPtr(Weather *ptr)
{
    m_weather = ptr;
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
    ui->imageAndWideoWdgt->setCurrentIndex(0);
    m_currentLoc = locPtr;

    if(m_currentLoc != nullptr)
    {
        ui->labelLocImage->setText(m_currentLoc->getLocPic(m_weather->isDay(), m_weather->isSnow()));
        ui->labelLocDesc->setText(m_currentLoc->getLocDesc());
    }
    fillSubLocs();
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
    m_page->setCurrentIndex(0);
}

void LocationForm::fillSubLocs()
{
    ClearLayout(m_actLayout);
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
        QWidget* w = m_page->widget(4);
        ObjViewForm* objview = (ObjViewForm*) w;
        connect(actionbtn, &QActionButton::sigViewObj, objview, &ObjViewForm::slotViewObj);
    }
    for (auto& i: locs)
    {
        QActionButton* actionbtn = new QActionButton(1);
        actionbtn->setText(i->getLocId());
        actionbtn->setLocPtr(i);
        m_actLayout->addWidget(actionbtn);
        connect(actionbtn, &QActionButton::sigChangeSubLoc, this, &LocationForm::slotChangeLoc);
    }

    if(m_currentLoc->getLocId() == "bathroom_parents")
    {
        bathActions(acts);
    }
}
