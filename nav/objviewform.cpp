#include "objviewform.h"
#include "qactionbutton.h"
#include "ui_objviewform.h"
#include "../Functions.h"
#include "locationform.h"
#include "../sexviewform.h"

ObjViewForm::ObjViewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ObjViewForm)
{
    ui->setupUi(this);
    old_cloth = nullptr;
    old_panties = nullptr;
    old_stockings = nullptr;
    ui->labelObjDesc->setWordWrap(true);
}

ObjViewForm::~ObjViewForm()
{
    delete ui;
}

void ObjViewForm::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
    m_objs[Objects::bed] = new Bed(m_player);
}

void ObjViewForm::setActLayoutPtr(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

void ObjViewForm::setPagePtr(QStackedWidget *ptr)
{
    m_page = ptr;
    m_bag = m_page->widget(3)->findChild<BagForm*>("BagForm");
    m_loc = (LocationForm*)m_page->widget(0);
    m_objs[Objects::mirror] = new Mirror(m_player, m_bag);
}

void ObjViewForm::setSettingsPtr(Settings *ptr)
{
    m_settings = ptr;
}

void ObjViewForm::setTimeServerPtr(TimeServer *ptr)
{
    m_time = ptr;
}

void ObjViewForm::slotViewObj(QString objName)
{
    m_page->setCurrentIndex(4);

    ClearLayout(m_actLayout);

    if (objName == "wardrobe")
    {
        ui->labelObjDesc->setText("wardrovbe");
        ui->labelObjImage->setText("wardrobe");
    }
    else if (objName == "bed")
    {
        viewBed();
    }
    else if (objName == "mirror")
    {
        viewMirror();
    }

    QActionButton* actionbtn = new QActionButton(0);
    actionbtn->setText("Назад");
    actionbtn->setLocPtr(getCurLoc());
    m_actLayout->addWidget(actionbtn);
    connect(actionbtn, &QActionButton::sigChangeSubLoc, m_loc, &LocationForm::slotChangeLoc);
}

void ObjViewForm::viewMirror()
{
    ui->labelObjImage->setText(m_objs[Objects::mirror]->getImage());
    ui->labelObjDesc->setText(m_objs[Objects::mirror]->getDesc());
    if(getVBody(hairStatus) == 0 && m_settings->isHapri())
    {
        makeMirrorActBtn("Причесаться");
    }
    if(getVBody(makeup) != 1)
    {
        makeMirrorActBtn("Стереть макияж");
    }
    if(getVBody(makeup) == 1 && (m_bag->getQuantityof(Items::cosmetic) + m_bag->getQuantityof(Items::cosmeticBig)) > 0)
    {
        makeMirrorActBtn("Нанести макияж");
    }
    if (getVBody(Body::eyeBrows) >= 0 && getVBody(Body::eyeBrows) <= 10)
    {
        makeMirrorActBtn("Выщипывать брови");
    }
    if (m_bag->getQuantityof(Items::lipBalm) > 0 && getVBody(Body::lipbalmstat) <= 0)
    {
        makeMirrorActBtn("Намазать губы увлажняющим бальзамом");
    }
}


void ObjViewForm::slotMirrorActHandler(QString actName)
{
    if(actName == "Причесаться")
    {
        emit sigSpendTime(3);
        m_player->setVBody(hairStatus, 1);
        emit sigUpdParams();
        ui->labelObjDesc->setText("Вы расчесали волосы у зеркала");

        makeBackBtn("mirror");
    }
    if(actName == "Стереть макияж")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(3);
        m_player->setVBody(makeup, 1);
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
        ui->labelObjDesc->setText("Вы быстро вытерли макияж.");

        makeBackBtn("mirror");
    }
    if(actName == "Нанести макияж")
    {
        ClearLayout(m_actLayout);

        makeMirrorActBtn("Лёгкий макияж");

        if(m_bag->getQuantityof(Items::cosmetic) + m_bag->getQuantityof(Items::cosmeticBig) >= 2)
        {
            makeMirrorActBtn("Нормальный макияж");
        }

        if(m_bag->getQuantityof(Items::cosmetic) + m_bag->getQuantityof(Items::cosmeticBig) >= 3)
        {
            makeMirrorActBtn("Вызывающий макияж");
        }
        makeBackBtn("mirror");
    }
    if(actName == "Лёгкий макияж")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(3);
        if(m_bag->getQuantityof(cosmeticBig) >= 1)
        {
            m_bag->removeFromBag(cosmeticBig);
        }
        else
        {
            m_bag->removeFromBag(cosmetic);
        }
        m_player->setVBody(makeup, 2);
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_2.jpg'></img>");
        ui->labelObjDesc->setText("Вы легонечко подвели глаза и немного подкрасили губы.");

        makeBackBtn("mirror");
    }
    if(actName == "Нормальный макияж")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(5);
        if(m_bag->getQuantityof(cosmeticBig) >= 2)
        {
            m_bag->removeFromBag(cosmeticBig, 2);
        }
        else
        {
            m_bag->removeFromBag(cosmetic, 2);
        }
        m_player->setVBody(makeup, 3);
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_3.jpg'></img>");
        ui->labelObjDesc->setText("Вы накрасили губы, подвели глаза и наложили тени.");

        makeBackBtn("mirror");
    }
    if(actName == "Вызывающий макияж")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(3);
        if(m_bag->getQuantityof(cosmeticBig) >= 3)
        {
            m_bag->removeFromBag(cosmeticBig, 3);
        }
        else
        {
            m_bag->removeFromBag(cosmetic, 3);
        }
        m_player->setVBody(makeup, 4);
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/mop_4.jpg'></img>");
        ui->labelObjDesc->setText("Вы густо накрасили глаза, наложили тени и тушь для ресниц, накрасили контур губ карандашом и губы помадой.");

        makeBackBtn("mirror");
    }

    if(actName == "Выщипывать брови")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(10);
        m_player->setVBody(Body::eyeBrows, 19);
        updVStatus(Status::mood, -5);
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/eyebrows.jpg'></img>");
        ui->labelObjDesc->setText("Вы выщипали ненужные волоски на бровях придав им красивый контур. Правда это довольно больно.");

        makeBackBtn("mirror");
    }

    if(actName == "Намазать губы увлажняющим бальзамом")
    {
        ClearLayout(m_actLayout);
        sigSpendTime(10);
        m_bag->removeFromBag(Items::lipBalm, 1);
        m_player->updVBody(Body::lipbalmstat, 8);
        updVStatus(Status::lipkoef, 5);
        if (getVStatus(Status::lipkoef) >= 50)
        {
            setVStatus(Status::lipkoef, 0);
            m_player->updVBody(Body::lip, 1);
        }
        emit sigUpdParams();
        ui->labelObjImage->setText("<img src=':/img/objects/mirror/wet_lips.jpg'></img>");
        ui->labelObjDesc->setText("Вы намазали губы увлажняющим бальзамом.");

        makeBackBtn("mirror");
    }
}


void ObjViewForm::viewBed()
{
    ui->labelObjImage->setPixmap(QPixmap(m_objs[Objects::bed]->getImage()));
    ui->labelObjDesc->setText(m_objs[Objects::bed]->getDesc());
    makeBedActBtn("Завести будильник");
    if(m_player->getVStatus(Status::son) < 10)
    {
        makeBedActBtn("Раздеться и лечь спать");
    }
    else
    {
        makeBedActBtn("Постараться уснуть");
    }
    if (m_player->getVStatus(Status::horny) >= 60)
    {
        makeBedActBtn("Мастурбировать");
    }
}

void ObjViewForm::slotBedActHandler(QString actName)
{
    if(actName == "Завести будильник")
    {
        ClearLayout(m_actLayout);
        budilnik();
    }
    if(actName == "Раздеться и лечь спать")
    {
        ClearLayout(m_actLayout);
        sleepInBed();
    }
    if(actName == "Постараться уснуть")
    {
        ClearLayout(m_actLayout);
        sleepInBed();
    }
    if(actName == "Мастурбировать")
    {
        ClearLayout(m_actLayout);
        selfPlay();
    }
    if(actName == "Встать с кровати и одеться")
    {
        ClearLayout(m_actLayout);
        m_player->redress(old_cloth);
        m_player->redress(old_panties);
        m_player->redress(old_stockings);

        setVStatus(InSleep, 0);
        m_time->increaseTime(15);
        // if clothesswamphouse = 1 or clothesbackwater = 1: gs 'zz_clothing2','redress',0
        // if swamp_clothes = 1: gs 'zz_clothing2','redress',1
        setVSexVar(analplugIN, 0);
        m_loc->slotChangeLoc(getCurLoc(),0);
    }
    if(actName == "Встать с кровати")
    {
        ClearLayout(m_actLayout);
        setVStatus(InSleep, 0);
        setVSexVar(analplugIN, 0);
        m_loc->slotChangeLoc(getCurLoc(),0);
    }
    if(actName == "Еще минутку...")
    {
        ClearLayout(m_actLayout);
        relaxInBed();
    }
}

void ObjViewForm::sleepInBed()
{
    m_player->slotWearAndTear();

    old_cloth = m_player->getCloth(ClothType::Main);
    old_panties = m_player->getCloth(ClothType::Panties);
    old_stockings = m_player->getCloth(ClothType::Stockings);

    m_player->redress(nullptr);
    if(getVStatus(energy) >=8)
    {
        updVStatus(health, 5);
    }
    setVStatus(no_sleep_time, 0);
    setVStatus(InSleep, 1);
    m_player->setVBody(hairStatus,0);
    if(getVStatus(alko) > 1)
    {
        if(getVStatus(alko) >= 6)
        {
            int moodNew = getVStatus(mood) / 3;
            setVStatus(mood, moodNew);
        }
        else if(getVStatus(alko) >= 3)
        {
            int moodNew = getVStatus(mood) / 2;
            setVStatus(mood, moodNew);
        }
        int waterDec = getVStatus(alko) * 3;
        updVStatus(alko, -waterDec);
    }
    int diffSon = 24 - getVStatus(son);
    int zz_sleep_time;
    if(getVStatus(alko) < 3 && getVStatus(sick) == 0)
    {
        zz_sleep_time = diffSon / 3;
    }
    else
    {
        zz_sleep_time = diffSon / 2;
    }
    int son_minutes = 0;
    if(diffSon % 3 == 1)
    {
        son_minutes = 20;
    }
    if(diffSon % 3 == 2)
    {
        son_minutes = 40;
    }
    int zzBudTime = m_player->getVBuzzer(timerH) * 60 + m_player->getVBuzzer(timerM);
    int zzTime = m_time->getHour() * 60 + m_time->getMin();
    if(zzBudTime < zzTime) { zzBudTime += 24*60; }
    int zzWakeupdiff = zz_sleep_time*60 + son_minutes;
    int zzWakeup = zzWakeupdiff + zzTime;
    int zzBudilnik = m_player->getVBuzzer(budilnik::timerH)*60 + m_player->getVBuzzer(budilnik::timerM);
    if(m_player->getVBuzzer(budilnikOn) == 1 && zzWakeup > zzBudTime)
    {
        diffSon = zzBudTime - zzTime;
        if(getVStatus(alko) < 3)
        {
            updVStatus(son, 3*diffSon/60);
        }
        else
        {
            updVStatus(son, 2*diffSon/60);
        }
        m_time->increaseTime(diffSon);
    }
    else
    {
        if(getVStatus(son) > 12)
        {
            m_time->increaseTime(zzWakeup - zzTime);
            setVStatus(son, 24);
        }
        else
        {
            m_time->increaseTime(7*60);
            updVStatus(son, 7*3);
        }
    }

    bedDreams();

    if(getVBody(makeup) != 1) { m_player->setVBody(makeup, 1); }
    if(getVsexVar(vibratorIN) == 1) { setVSexVar(vibratorIN, 0); }
    int budInMin = m_player->getVBuzzer(timerH)*60 + m_player->getVBuzzer(timerM);
    int curTimeInMin = m_time->getHour()*60 + m_time->getMin();
    if(m_player->getVBuzzer(budilnikOn) == 1 && budInMin == curTimeInMin)
    {
        ui->labelObjDesc->setText("Звенит будильник");
        updVStatus(mood, -3);
    }
    if(getVStatus(oversleep) == 1)
    {
        ui->labelObjDesc->setText("Черт, черт, черт! Вот тебе и \"подремлю еще минутку\"!");
    }
    makeBedActBtn("Еще минутку...");
    makeBedActBtn("Встать с кровати и одеться");

    if(getVStatus(shamelessFlag) >= 2)
    {
        makeBedActBtn("Встать с кровати");
    }
    makeBedActBtn("Постараться уснуть");
    setVStatus(oversleep, 0);
    //AUTOSAVE
}

void ObjViewForm::relaxInBed()
{
    m_time->increaseTime(getRandInt(5,10));
    int i = 0;
//SUNWEATHER
    if(getVStatus(son) < 10) i++;
    if(getVStatus(mood) < 33) i++;
    if(getVsexVar(painpub) > 0) i++;
    if(getVsexVar(nippain) > 0) i++;
    if(getVStatus(sick) > 0) i++;
    if(getVStatus(mesec) > 0) i++;
    if(getVStatus(pregnancy) > 0) i++;
    if(getVsexVar(spanked) > 0) i++;
    if(getVStatus(alko) > 0) i++;
    int max = 0;
    if(getVStatus(son) <= 10) max = 10;
    else max = 20;
    if(getRandInt(0, max) < 3)
    {
        setVStatus(oversleep, 1);
        sleepInBed();
    }
    else
    {
        slotViewObj("bed");
    }
}

void ObjViewForm::selfPlay()
{
    m_page->widget(6)->findChild<SexViewForm*>("SexViewForm")->selfPlayStart(getCurLoc());
}

void ObjViewForm::budilnik()
{
    QString text = "<a style='text-decoration: none; color: black;' href='hour'>" + intQStr(m_player->getVBuzzer(timerH)) + "</a>:";
    text += "<a style='text-decoration: none; color: black' href = 'minut'>" + intQStr(m_player->getVBuzzer(timerM)) + "</a>";
    ui->labelObjImage->setText(text);
    ui->labelObjImage->setStyleSheet("font-size: 160px");
    ui->labelObjDesc->clear();
    makeBackBtn("bed");
}

void ObjViewForm::bedDreams()
{
    int _after = -1;
    int i = 0;
    //if(father=3)
    if(getVStatus(horny) <= 50)
    {
        if(getVStatus(mood) > 60)
        {
            i = getRandInt(0,16);
        }
        else
        {
            i = getRandInt(0,11);
        }
    }
    else
    {
        if(m_player->getStatisticsValue(SC::blowJob) > 0)
        {
            i = getRandInt(12,23);
        }
        else if (m_player->getStatisticsValue(SC::vaginalSex) > 0)
        {
            i = getRandInt(12,25);
        }
        else if (m_player->getStatisticsValue(SC::analSex) > 0 || m_player->getStatisticsValue(SC::gangBang) > 0)
        {
            i = getRandInt(12,27);
        }
        else
        {
            i = getRandInt(12,18);
        }

        if(i == 17 || i == 18)
        {
            if(m_player->getStatisticsValue(SC::blowJob) == 0)
            {
                _after = 0;
            }
            else
            {
                _after = 1;
            }
        }
        if (i >= 19 && i <= 23)
        {
            if(getVBody(vagina) == 0)
            {
                _after = 2;
            }
            else if (m_player->getStatisticsValue(vaginalSex) == 0)
            {
                _after = 3;
            }
            else
            {
                _after = 4;
            }
        }
        if(i == 24 || i == 25)
        {
            if(m_player->getStatisticsValue(SC::analSex) == 0)
            {
                if(getVBody(anus) == 0)
                {
                    _after = 5;
                }
                else
                {
                    _after = 6;
                }
            }
            else
            {
                _after = 7;
            }
        }
        if(i >= 25)
        {
            if(m_player->getStatisticsValue(SC::gangBang) == 0)
            {
                _after = 8;
            }
            else
            {
                _after = 9;
            }
        }
        if(i < 12) { updVStatus(horny, 0); }
        else if(i >= 12 && i < 24) { updVStatus(horny, 10); }
        else { updVStatus(horny,20); }
    }
    if(i > 27)
    {
        ui->labelObjImage->setText("qwest/alter/father/bath_voyer_1.jpg");
    }
    else
    {
        ui->labelObjImage->setText("<img src=':/img/dreams/" + intQStr(i) + ".jpg'></img>");
    }

    QString text = ((Bed*)m_objs[bed])->getDreamsDesc(i);
    if(_after >= 0)
    {
        text += "<br>" + ((Bed*)m_objs[bed])->getDreamsAfter(_after);
    }
    ui->labelObjDesc->setText(text);
}

void ObjViewForm::makeMirrorActBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText(text);
    connect(btnx, &ObjActionButton::sigAction, this, &ObjViewForm::slotMirrorActHandler);
    m_actLayout->addWidget(btnx);
}

void ObjViewForm::makeBedActBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText(text);
    connect(btnx, &ObjActionButton::sigAction, this, &ObjViewForm::slotBedActHandler);
    m_actLayout->addWidget(btnx);
}

void ObjViewForm::makeBackBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText("Назад");
    connect(btnx, &ObjActionButton::sigAction, this, &ObjViewForm::slotViewObj);
    m_actLayout->addWidget(btnx);
}

int ObjViewForm::getVStatus(Status type)
{
    return m_player->getVStatus(type);
}

int ObjViewForm::getVBody(Body type)
{
    return m_player->getVBody(type);
}

int ObjViewForm::getVsexVar(SexVar type)
{
    return m_player->getVSexVar(type);
}

void ObjViewForm::setVStatus(Status type, int value)
{
    m_player->setVStatus(type, value);
}

void ObjViewForm::setVSexVar(SexVar type, int value)
{
    m_player->setVSexVar(type,value);
}

void ObjViewForm::updVStatus(Status type, int value)
{
    m_player->updVStatus(type, value);
}

Location *ObjViewForm::getCurLoc()
{
    return m_loc->getCurPtr();
}

void ObjViewForm::on_labelObjImage_linkActivated(const QString &link)
{
    if(link == "hour")
    {
        m_player->updVBuzzer(budilnik::timerH, 1);
        slotBedActHandler("Завести будильник");
    }
    if(link == "minut")
    {
        m_player->updVBuzzer(budilnik::timerM, 5);
        slotBedActHandler("Завести будильник");
    }
}


void ObjViewForm::on_labelObjDesc_linkActivated(const QString &link)
{
    if(link == "budilnikOn")
    {
        m_player->updVBuzzer(budilnik::budilnikOn, 1);
        ui->labelObjDesc->setText(m_objs[Objects::bed]->getDesc());
    }
}

