#include "objviewform.h"
#include "qactionbutton.h"
#include "ui_objviewform.h"
#include "../Functions.h"
#include "locationform.h"

#include "../mainwindow.h"
#include "../ui_mainwindow.h"
#include "bed.h"
#include "mirror.h"
#include "wardrobe.h"

ObjViewForm::ObjViewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjViewForm)
{
    ui->setupUi(this);
    ui->labelObjDesc->setWordWrap(true);
    ui->labelHeader->setWordWrap(true);
    root = parent;
    m_bed = new Bed(this);
    m_mirror = new Mirror(this);
    m_wardrobe = new Wardrobe(this);
    videoWidg = new Video(ui->widget);
    ui->videoLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->videoLayout->addWidget(videoWidg);
    ui->ObjListLayout->setAlignment(Qt::AlignTop);
}

ObjViewForm::~ObjViewForm()
{
    delete ui;
}

void ObjViewForm::setActLayoutPtr(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

void ObjViewForm::storeCloth(Cloth *thing, int count)
{
    m_wardrobe->addCloth(thing, count);
}

Cloth *ObjViewForm::wearCloth(Cloth *thing)
{
    return m_wardrobe->wearCloth(thing);
}

void ObjViewForm::reloadActions()
{
    emit sigReload();
}

void ObjViewForm::slotViewObj(QString objName)
{
    ((MainWindow*)root)->prevPage = 4;
    ((MainWindow*)root)->ui->stackedWidget->setCurrentIndex(4);

    if (objName == "wardrobe")
    {
        connect(this, &ObjViewForm::sigReload, m_wardrobe, &Wardrobe::reloadActions);
        m_wardrobe->viewWardrobe();
    }
    else if (objName == "bed")
    {
        connect(this, &ObjViewForm::sigReload, m_bed, &Bed::reloadActions);
        m_bed->viewBed();
    }
    else if (objName == "mirror")
    {
        connect(this, &ObjViewForm::sigReload, m_mirror, &Mirror::reloadActions);
        m_mirror->viewMirror();
    }

    // QActionButton* actionbtn = new QActionButton(0);
    // actionbtn->setText("Назад");
    // actionbtn->setLocPtr(getCurLoc());
    // m_actLayout->addWidget(actionbtn);
    // connect(actionbtn, &QActionButton::sigChangeSubLoc, ((MainWindow*)root)->ui->page_0_main, &LocationForm::slotChangeLoc);
}

void ObjViewForm::slotInitWardrobe()
{
    m_wardrobe->initWarDrobe();
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
    ((MainWindow*)root)->m_player->redressMain(newCloth);
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

void ObjViewForm::startSelfPlay()
{
    ((MainWindow*)root)->ui->page_6_sexView->findChild<SexViewForm*>("SexViewForm")->selfPlayStart();
}

Player *ObjViewForm::player()
{
    return ((MainWindow*)root)->m_player;
}

bool ObjViewForm::isHapri()
{
    return ((MainWindow*)root)->page4->isHapri();
}
