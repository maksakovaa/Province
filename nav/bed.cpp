#include "objviewform.h"
#include "ui_objviewform.h"
#include "../Functions.h"
#include "../sex/sexviewform.h"

Bed::Bed(QWidget* ptr)
{
    m_name = "bed";
    root = (ObjViewForm*)ptr;
    old_cloth = nullptr;
    old_panties = nullptr;
    old_stockings = nullptr;
}

Bed::~Bed()
{

}

QString Bed::getName()
{
    return m_name;
}

QString Bed::getImage()
{
    if(root->getCloth(ClothType::Main) == nullptr && !root->isPanties())
    {
        return ":/img/objects/bed/son.jpg";
    }
    else if (root->getCloth(ClothType::Main) == nullptr && root->isPanties())
    {
        return ":/img/objects/bed/son_tanga.jpg";
    }
    else
    {
        return ":/img/objects/bed/bed" + intQStr(getRandInt(1,4)) + ".jpg";
    }

}

QString Bed::getDesc()
{
    QString text = "Вы лежите на кровати. Будильник заведен на " + intQStr(root->getVBuzzer(timerH)) + " часов, " + intQStr(root->getVBuzzer(timerM)) + " минут. ";
    if(root->getVBuzzer(budilnikOn) == 1)
    {
        text += "(Будильник <a href='budilnikOn'>Включен</a>)";
    }
    else
    {
        text +=  "(Будильник <a href='budilnikOn'>Выключен</a>)";
    }
    if(root->getVStatus(son) > 10)
    {
        text += "<br>Спать почему то не хочется.";
    }
    return text;
}

QString Bed::getDreamsDesc(int i)
{
    QString strArray[28];
    strArray[0] = "Вам снится какой-то старый город, стоящий на противоположных берегах высокого водопада, а между его шпилей летают какие-то существа";
    strArray[1] = "Вам снится какая-то башня, окутанная снегом льдом на вершине замерзшей скалы";
    strArray[2] = "Вам снится ледяная гора, на вершине которой стоит непонятное здание похожее на монастырь";
    strArray[3] = "Вам снится высокая незнакомая девушка, идущая под проливным дождем по темной и узкой улице";
    strArray[4] = "Вам снится ваша улыбающаяся мать в комнате, полной старых вещей из прошлого или позапрошлого века. Странно, к чему бы это";
    strArray[5] = "Вам снится какой-то всадник, стоящий у озера, окруженного высокими и отвесными горами";
    strArray[6] = "Вам снится страшный мужчина с обгоревшей кожей, держащий на цепи непонятное существо, пока на него с мечом идет беловолосый средних лет парень. Пора прекращая смотреть телевизор..";
    strArray[7] = "Вам снова снится беловолосый парень, но заметно постаревший и с густой бородой, а рядом с ним стоит красивая беловолосая девушка. Может это его дочь? Почему вам вообще это снится";
    strArray[8] = "Вам снится, будто вы стоите среди людей на улице и наблюдаете большой ядерный гриб. О, боже, как это страшно";
    strArray[9] =  "Вам снится плотно застроенная из какого-то мусора улица и большая очередь к какому-то прилавку";
    strArray[10] = "Вам снится красивый и величественный собор на берегу реки";
    strArray[11] = "Вам снится, что вы стоите зимой на берегу озера и наблюдаете за темной фигурой, стоящей на окруженной водой верандой, под светом Луны, которая почему-то выглядит как светящийся циферблат часов";
    strArray[12] = "Вам снится, что в школе всех девочек обязали присутствовать на уроках только в обнаженном виде";
    strArray[13] = "Вам снится, что вас голую ласкает какой-то атлетичный парень на диване. Он целует вашу шею и опускается поцелуями к вашей груди, лаская своим языком ваши сосочки";
    strArray[14] = "Вам снится, что вы моетесь голышом в душе с каким-то парнем. Он мылит ваше тело, уделяя особое внимание вашей груди и киске, в то время как его твердый член упирается вам в спину";
    strArray[15] = "Вам снится, что вы голышом целуетесь и ласкаете друг-друга с какой-то девушкой на кровати";
    strArray[16] = "Вам снится, что вы абсолютно голые страстно целуетесь с каким-то незнакомым парнем";
    strArray[17] = "Вам снится, что вы, стоя раком, попкой к верху, делаете минет какому-то парню в лучах заката, на берегу океана";
    strArray[18] = "Вам снится, что вы, прикованная к лестнице, сидя на корточках с широко раздвинутыми ножками, смакуя отсасываете член какому-то парню в хорошем костюме";
    strArray[19] = "Вам снится, что вы занимаетесь сексом с атлетичным парнем возле бассейна дорогого особняка. Вы скачете верхом на его члене, пока он крепко сжимает вашу попку";
    strArray[20] = "Вам снится, что вы занимаетесь сексом с незнакомым парнем на диване. Он нежно вас целует и ласкает вашу грудь руками, пока его член поршнем работает в вашей текущей киске";
    strArray[21] = "Вам снится, что вы на берегу океана занимаетесь сексом с незнакомым парнем. Вы лежите вся в песке, а он ритмично имеет вас в миссионерской позе, лаская поцелуями вашу шею";
    strArray[22] = "Вам снится, что вас на светлом диване жестко имеет раком какой-то парень. Он крепко сжимает своими руками вашу попку, а вы старательно подмахиваете ему, прикусив губу от удовольствия";
    strArray[23] = "Вам снится, что вы скачите верхом на крепком члене какого-то парня";
//только анальный секс
    strArray[24] = "Вам снится, что вас раком жестко имеет в попку какой-то парень, пока вы теребите пальчиками свой клитор";
    strArray[25] = "Вам снится, что вас сзади, на боку трахает в попку парень, а вы громко стонете";
//только групповуха
    strArray[26] = "Вам снится, что вы занимаетесь сексом с двумя парнями. Вы лежите между ними и смакуете член одного, пока другой имеет вас в попку";
    strArray[27] = "Вам снится, что вас страстно трахают в два ствола какие-то парни. Их члены, как поршни, поочередно и с силой входят в обе ваши дырочки и вы громко стонете от удовольствия";
    return strArray[i];
}

QString Bed::getDreamsAfter(int i)
{
    QString strArray[10];
    strArray[0] = "Вы еще ни разу не делали никому минет, но ощущения и форма члена в вашем ротике были настолько реальные, что это одновременно вас испугало и не на шутку возбудило";
    strArray[1] = "Похоже, что ваше подсознание очень настойчиво вам намекает";
    strArray[2] = "В вашей девственной киске и члена-то ни разу не было, но ощущения были настолько реальные что вас это не на шутку возбудило";
    strArray[3] = "В вашей киске и члена-то ни разу не было, хоть вы и не девственница, но ощущения были настолько реальные что вас это не на шутку возбудило";
    strArray[4] = "Похоже, что ваша <<$vaginatipe>> киска срочно требует чем-то себя заполнить";
    strArray[5] = "У вас ни разу не было анального секса, но ощущения были настолько реальные что вас это не на шутку возбудило";
    strArray[6] = "В вашей попке и члена-то ни разу не было, хоть она и не девственна, но ощущения были настолько реальные что вас это не на шутку возбудило";
    strArray[7] = "Похоже, что ваш <<$anustipe>> анус срочно требует чем-то себя заполнить";
    strArray[8] = "Похоже, что ваш опыт групповухи с не прошел даром и ваше подсознание активно вам об этом напоминает";
    strArray[9] = "Сегодня вам приснился весьма странный сон: вы с завязанными глазами занимались сексом с незнакомцем и лишь по завершению действа, сняв повязку, вы узнали своего отчима";
    return strArray[i];
}



void Bed::viewBed()
{
    root->ui->labelObjImage->setPixmap(QPixmap(getImage()));
    root->ui->labelObjDesc->setText(getDesc());
    makeBedActBtn("Завести будильник");
    if(root->getVStatus(Status::son) < 10)
    {
        makeBedActBtn("Раздеться и лечь спать");
    }
    else
    {
        makeBedActBtn("Постараться уснуть");
    }
    if (root->getVStatus(Status::horny) >= 60)
    {
        makeBedActBtn("Мастурбировать");
    }
}

void Bed::slotBedActHandler(QString actName)
{
    if(actName == "Завести будильник")
    {
        ClearLayout(root->m_actLayout);
        budilnik();
    }
    if(actName == "Раздеться и лечь спать")
    {
        ClearLayout(root->m_actLayout);
        sleepInBed();
    }
    if(actName == "Постараться уснуть")
    {
        ClearLayout(root->m_actLayout);
        sleepInBed();
    }
    if(actName == "Мастурбировать")
    {
        ClearLayout(root->m_actLayout);
        selfPlay();
    }
    if(actName == "Встать с кровати и одеться")
    {
        ClearLayout(root->m_actLayout);
        root->redress(old_cloth);
        root->redress(old_panties);
        root->redress(old_stockings);

        root->setVStatus(InSleep, 0);
        root->incTime(15);
        // if clothesswamphouse = 1 or clothesbackwater = 1: gs 'zz_clothing2','redress',0
        // if swamp_clothes = 1: gs 'zz_clothing2','redress',1
        root->setVSexVar(analplugIN, 0);
        root->changeLoc(root->getCurLoc(),0);
    }
    if(actName == "Встать с кровати")
    {
        ClearLayout(root->m_actLayout);
        root->setVStatus(InSleep, 0);
        root->setVSexVar(analplugIN, 0);
        root->changeLoc(root->getCurLoc(),0);
    }
    if(actName == "Еще минутку...")
    {
        ClearLayout(root->m_actLayout);
        relaxInBed();
    }
}

void Bed::sleepInBed()
{
    root->decreaseClothCond();

    old_cloth = root->getCloth(ClothType::Main);
    old_panties = root->getCloth(ClothType::Panties);
    old_stockings = root->getCloth(ClothType::Stockings);

    root->redress(nullptr);
    if(root->getVStatus(energy) >=8)
    {
        root->updVStatus(health, 5);
    }
    root->setVStatus(no_sleep_time, 0);
    root->setVStatus(InSleep, 1);
    root->setVBody(hairStatus,0);
    if(root->getVAddict(alko) > 1)
    {
        if(root->getVAddict(alko) >= 6)
        {
            int moodNew = root->getVStatus(mood) / 3;
            root->setVStatus(mood, moodNew);
        }
        else if(root->getVAddict(alko) >= 3)
        {
            int moodNew = root->getVStatus(mood) / 2;
            root->setVStatus(mood, moodNew);
        }
        int waterDec = root->getVAddict(alko) * 3;
        root->updVAddict(alko, -waterDec);
    }
    int diffSon = 24 - root->getVStatus(son);
    int zz_sleep_time;
    if(root->getVAddict(alko) < 3 && root->getVSick(sick) == 0)
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
    int zzBudTime = root->getVBuzzer(timerH) * 60 + root->getVBuzzer(timerM);
    int zzTime = root->getHour() * 60 + root->getMin();
    if(zzBudTime < zzTime) { zzBudTime += 24*60; }
    int zzWakeupdiff = zz_sleep_time*60 + son_minutes;
    int zzWakeup = zzWakeupdiff + zzTime;
    int zzBudilnik = root->getVBuzzer(budilnik::timerH)*60 + root->getVBuzzer(budilnik::timerM);
    if(root->getVBuzzer(budilnikOn) == 1 && zzWakeup > zzBudTime)
    {
        diffSon = zzBudTime - zzTime;
        if(root->getVAddict(alko) < 3)
        {
            root->updVStatus(son, 3*diffSon/60);
        }
        else
        {
            root->updVStatus(son, 2*diffSon/60);
        }
        root->incTime(diffSon);
    }
    else
    {
        if(root->getVStatus(son) > 12)
        {
            root->incTime(zzWakeup - zzTime);
            root->setVStatus(son, 24);
        }
        else
        {
            root->incTime(7*60);
            root->updVStatus(son, 7*3);
        }
    }

    bedDreams();

    if(root->getVBody(makeup) != 1) { root->setVBody(makeup, 1); }
    if(root->getVsexVar(vibratorIN) == 1) { root->setVSexVar(vibratorIN, 0); }
    int budInMin = root->getVBuzzer(timerH)*60 + root->getVBuzzer(timerM);
    int curTimeInMin = root->getHour()*60 + root->getMin();
    if(root->getVBuzzer(budilnikOn) == 1 && budInMin == curTimeInMin)
    {
        root->ui->labelObjDesc->setText("Звенит будильник");
        root->updVStatus(mood, -3);
    }
    if(root->getVStatus(oversleep) == 1)
    {
        root->ui->labelObjDesc->setText("Черт, черт, черт! Вот тебе и \"подремлю еще минутку\"!");
    }
    makeBedActBtn("Еще минутку...");
    makeBedActBtn("Встать с кровати и одеться");

    if(root->getVStatus(shamelessFlag) >= 2)
    {
        makeBedActBtn("Встать с кровати");
    }
    makeBedActBtn("Постараться уснуть");
    root->setVStatus(oversleep, 0);
    //AUTOSAVE
}

void Bed::relaxInBed()
{
    root->incTime(getRandInt(5,10));
    int i = 0;
//SUNWEATHER
    if(root->getVStatus(son) < 10) i++;
    if(root->getVStatus(mood) < 33) i++;
    if(root->getVsexVar(painpub) > 0) i++;
    if(root->getVsexVar(nippain) > 0) i++;
    if(root->getVSick(sick) > 0) i++;
    if(root->getVStatus(mesec) > 0) i++;
    if(root->getVStatus(pregnancy) > 0) i++;
    if(root->getVsexVar(spanked) > 0) i++;
    if(root->getVAddict(alko) > 0) i++;
    int max = 0;
    if(root->getVStatus(son) <= 10) max = 10;
    else max = 20;
    if(getRandInt(0, max) < 3)
    {
        root->setVStatus(oversleep, 1);
        sleepInBed();
    }
    else
    {
        root->slotViewObj("bed");
    }
}

void Bed::selfPlay()
{
    root->startSelfPlay(root->getCurLoc());
    // root->m_page->widget(5)->findChild<SexViewForm*>("SexViewForm")->selfPlayStart(root->getCurLoc());
}

void Bed::budilnik()
{
    QString text = "<a style='text-decoration: none; color: black;' href='hour'>" + intQStr(root->getVBuzzer(timerH)) + "</a>:";
    text += "<a style='text-decoration: none; color: black' href = 'minut'>" + intQStr(root->getVBuzzer(timerM)) + "</a>";
    root->ui->labelObjImage->setText(text);
    root->ui->labelObjImage->setStyleSheet("font-size: 160px");
    root->ui->labelObjDesc->clear();
    makeBackBtn("bed");
}

void Bed::bedDreams()
{
    int _after = -1;
    int i = 0;
    //if(father=3)
    if(root->getVStatus(horny) <= 50)
    {
        if(root->getVStatus(mood) > 60)
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
        if(root->getVSC(SC::blowJob) > 0)
        {
            i = getRandInt(12,23);
        }
        else if (root->getVSC(SC::vaginalSex) > 0)
        {
            i = getRandInt(12,25);
        }
        else if (root->getVSC(SC::analSex) > 0 || root->getVSC(SC::gangBang) > 0)
        {
            i = getRandInt(12,27);
        }
        else
        {
            i = getRandInt(12,18);
        }

        if(i == 17 || i == 18)
        {
            if(root->getVSC(SC::blowJob) == 0)
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
            if(root->getVBody(vagina) == 0)
            {
                _after = 2;
            }
            else if (root->getVSC(vaginalSex) == 0)
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
            if(root->getVSC(SC::analSex) == 0)
            {
                if(root->getVBody(anus) == 0)
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
            if(root->getVSC(SC::gangBang) == 0)
            {
                _after = 8;
            }
            else
            {
                _after = 9;
            }
        }
        if(i < 12) { root->updVStatus(horny, 0); }
        else if(i >= 12 && i < 24) { root->updVStatus(horny, 10); }
        else { root->updVStatus(horny,20); }
    }
    if(i > 27)
    {
        root->ui->labelObjImage->setText("qwest/alter/father/bath_voyer_1.jpg");
    }
    else
    {
        root->ui->labelObjImage->setText("<img src=':/img/dreams/" + intQStr(i) + ".jpg'></img>");
    }

    QString text = getDreamsDesc(i);
    if(_after >= 0)
    {
        text += "<br>" + getDreamsAfter(_after);
    }
    root->ui->labelObjDesc->setText(text);
}

void Bed::makeBedActBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText(text);
    connect(btnx, &ObjActionButton::sigAction, this, &Bed::slotBedActHandler);
    root->m_actLayout->addWidget(btnx);
}

void Bed::makeBackBtn(QString text)
{
    ObjActionButton* btnx = new ObjActionButton(text);
    btnx->setText("Назад");
    connect(btnx, &ObjActionButton::sigAction, root, &ObjViewForm::slotViewObj);
    root->m_actLayout->addWidget(btnx);
}

void Bed::on_labelObjImage_linkActivated(const QString &link)
{
    if(link == "hour")
    {
        root->updBuzzer(budilnik::timerH, 1);
        slotBedActHandler("Завести будильник");
    }
    if(link == "minut")
    {
        root->updBuzzer(budilnik::timerM, 5);
        slotBedActHandler("Завести будильник");
    }
}


void Bed::on_labelObjDesc_linkActivated(const QString &link)
{
    if(link == "budilnikOn")
    {
        root->updBuzzer(budilnik::budilnikOn, 1);
        root->ui->labelObjDesc->setText(getDesc());
    }
}
