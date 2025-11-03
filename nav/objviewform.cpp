#include "objviewform.h"
#include "qactionbutton.h"
#include "ui_objviewform.h"
#include "../Functions.h"
#include "locationform.h"

#include "../mainwindow.h"
#include "../ui_mainwindow.h"

ObjActionButton::ObjActionButton(QString actName)
{
    m_actionName = actName;
    connect(this, &ObjActionButton::clicked, this, &ObjActionButton::handleButtonClick);
    this->setCursor(Qt::PointingHandCursor);
}

void ObjActionButton::handleButtonClick()
{
    emit sigAction(m_actionName);
}


ObjViewForm::ObjViewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjViewForm)
{
    ui->setupUi(this);
    ui->labelObjDesc->setWordWrap(true);
}

ObjViewForm::~ObjViewForm()
{
    delete ui;
}

void ObjViewForm::setRoot(QWidget *ptr)
{
    root = ptr;
    m_bed = new Bed(this);
    m_mirror = new Mirror(this);
}

// void ObjViewForm::setPlayerPtr(Player *ptr)
// {
//     m_player = ptr;
//     m_bed = new Bed(this);
// }

void ObjViewForm::setActLayoutPtr(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

// void ObjViewForm::setPagePtr(QStackedWidget *ptr)
// {
//     m_page = ptr;
//     m_bag = m_page->widget(3)->findChild<BagForm*>("BagForm");
//     m_loc = (LocationForm*)m_page->widget(0);
//     m_mirror = new Mirror(this);
// }

// void ObjViewForm::setSettingsPtr(Settings *ptr)
// {
//     m_settings = ptr;
// }

// void ObjViewForm::setTimeServerPtr(TimeServer *ptr)
// {
//     m_time = ptr;
// }

void ObjViewForm::slotViewObj(QString objName)
{
    ((MainWindow*)root)->ui->stackedWidget->setCurrentIndex(4);
//    m_page->setCurrentIndex(4);

    ClearLayout(m_actLayout);

    if (objName == "wardrobe")
    {
        ui->labelObjDesc->setText("wardrovbe");
        ui->labelObjImage->setText("wardrobe");
    }
    else if (objName == "bed")
    {
        m_bed->viewBed();
    }
    else if (objName == "mirror")
    {
        m_mirror->viewMirror();
    }

    QActionButton* actionbtn = new QActionButton(0);
    actionbtn->setText("Назад");
    actionbtn->setLocPtr(getCurLoc());
    m_actLayout->addWidget(actionbtn);
    connect(actionbtn, &QActionButton::sigChangeSubLoc, ((MainWindow*)root)->ui->page_0_main, &LocationForm::slotChangeLoc);
}

int ObjViewForm::getVStatus(Status type)
{
    return ((MainWindow*)root)->m_player->getVStatus(type);
}

int ObjViewForm::getVBody(Body type)
{
    return ((MainWindow*)root)->m_player->getVBody(type);
}

int ObjViewForm::getVsexVar(SexVar type)
{
    return ((MainWindow*)root)->m_player->getVSexVar(type);
}

int ObjViewForm::getVAddict(Addiction type)
{
    return ((MainWindow*)root)->m_player->getVAddict(type);
}

int ObjViewForm::getVSick(Sickness type)
{
    return ((MainWindow*)root)->m_player->getVSick(type);
}

int ObjViewForm::getItmCount(Items type)
{
    return ((MainWindow*)root)->m_bag->getQuantityof(type);
}

int ObjViewForm::getVBuzzer(budilnik type)
{
    return ((MainWindow*)root)->m_player->getVBuzzer(type);
}

int ObjViewForm::getHour()
{
    return ((MainWindow*)root)->m_time.getHour();
}

int ObjViewForm::getMin()
{
    return ((MainWindow*)root)->m_time.getMin();
}

int ObjViewForm::getVSC(SC param)
{
    return ((MainWindow*)root)->m_player->getStatisticsValue(param);
}

void ObjViewForm::useItem(Items type, int count)
{
    ((MainWindow*)root)->m_bag->removeFromBag(type,count);
}

void ObjViewForm::setVStatus(Status type, int value)
{
    ((MainWindow*)root)->m_player->setVStatus(type, value);
}

void ObjViewForm::setVSexVar(SexVar type, int value)
{
    ((MainWindow*)root)->m_player->setVSexVar(type,value);
}

void ObjViewForm::setVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->setVBody(param,val);
}

void ObjViewForm::updVStatus(Status type, int value)
{
    ((MainWindow*)root)->m_player->updVStatus(type, value);
}

void ObjViewForm::updVAddict(Addiction type, int val)
{
    ((MainWindow*)root)->m_player->updVAddict(type, val);
}

void ObjViewForm::updVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->updVBody(param,val);
}

void ObjViewForm::redress(Cloth *newCloth)
{
    ((MainWindow*)root)->m_player->redress(newCloth);
}

void ObjViewForm::incTime(int min)
{
    ((MainWindow*)root)->m_time.increaseTime(min);
}

void ObjViewForm::decreaseClothCond()
{
    ((MainWindow*)root)->m_player->slotWearAndTear();
}

void ObjViewForm::updBuzzer(budilnik type, int val)
{
    ((MainWindow*)root)->m_player->updVBuzzer(type,val);
}

Cloth *ObjViewForm::getCloth(ClothType type)
{
    return ((MainWindow*)root)->m_player->getCloth(type);
}

bool ObjViewForm::isPanties()
{
    return ((MainWindow*)root)->m_player->isPanties();
}

Location *ObjViewForm::getCurLoc()
{
    return ((MainWindow*)root)->ui->page_0_main->getCurPtr();
}

void ObjViewForm::changeLoc(Location *newLoc, int min)
{
    ((MainWindow*)root)->ui->page_0_main->slotChangeLoc(newLoc, min);
}

void ObjViewForm::startSelfPlay(Location *loc)
{
    ((MainWindow*)root)->ui->page_6_sexView->findChild<SexViewForm*>("SexViewForm")->selfPlayStart(loc);
}
