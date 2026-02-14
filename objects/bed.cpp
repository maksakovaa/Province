#include "bed.h"
#include "../Functions.h"
#include <QDebug>
#include "../player/enums.h"
#include "../menu/buttons.h"
#include "../game.h"

Bed::Bed(Game* ptr): root(ptr)
{
    m_name = "bed";
}

Bed::~Bed()
{

}

void Bed::reloadActions()
{
    makeButtons();
}

QString Bed::getName()
{
    return m_name;
}

QString Bed::getImage()
{
    if(root->getCloth(ClothType::Main) == nullptr && !root->isPanties())
    {
        return "data/img/objects/bed/son.jpg";
    }
    else if (root->getCloth(ClothType::Main) == nullptr && root->isPanties())
    {
        return "data/img/objects/bed/son_tanga.jpg";
    }
    else
    {
        return "data/img/objects/bed/bed" + intQStr(getRandInt(1,4)) + ".jpg";
    }

}

QString Bed::getDesc()
{
    QString text = "Вы лежите на кровати. Будильник заведен на " + intQStr(root->vBuzzer(timerH)) + " часов, " + intQStr(root->vBuzzer(timerM)) + " минут. ";
    if(root->vBuzzer(budilnikOn) == 1)
    {
        text += "(Будильник <a href='budilnikOn'>Включен</a>)";
    }
    else
    {
        text +=  "(Будильник <a href='budilnikOn'>Выключен</a>)";
    }
    if(root->vStatus(son) > 10)
    {
        text += "<br>Спать почему то не хочется.";
    }
    return text;
}



void Bed::viewBed()
{
    slotActHandler(actBed0);
}


void Bed::slotActHandler(BedActs act)
{
    current = act;
    root->clearActions();
    switch (act)
    {
    case actBed0:
        {
            root->rendImagePage(this);
            root->setImage(getImage());
            root->setText(getDesc());
            makeButtons();
        }
        break;
    case actBed1:
        {
            relaxInBed();
        }
        break;
    case actBed2:
        {
            QString text = "<a style='text-decoration: none; color: black;' href='hour'>" + intQStr(root->vBuzzer(timerH)) + "</a>:";
            text += "<a style='text-decoration: none; color: black' href = 'minut'>" + intQStr(root->vBuzzer(timerM)) + "</a>";
            root->rendImagePage(this);
            root->getImagePtr()->setText(text);
            root->getImagePtr()->setStyleSheet("font-size: 160px");
            root->getTextPtr()->clear();
        }
        break;
    case actBed6:
    case actBed7:
        {
            sleepInBed();
        }
        break;
    case actBed8:
        {
            root->vStatus(InSleep) = 0;
            root->vSex(analplugIN) = 0;
            root->changeLoc(root->getCurLoc());
        }
        break;
    case actBed9:
        {
            root->selfPlayStart();
        }
        break;
    case actBed10:
        {
            root->redressOld();
            root->vStatus(InSleep) = 0;
            root->incTime(15);
            // if clothesswamphouse = 1 or clothesbackwater = 1: gs 'zz_clothing2','redress',0
            // if swamp_clothes = 1: gs 'zz_clothing2','redress',1
            root->vSex(analplugIN) = 0;
            root->changeLoc(root->getCurLoc());
        }
    break;
    case actBed11:
        {
            root->vStatus(InSleep) = 0;
            root->vSex(analplugIN) = 0;
            root->changeLoc(root->getCurLoc());
        }
        break;
    }
}

void Bed::sleepInBed()
{
    root->decreaseClothCond();
    root->redress(ClothType::Main,nullptr);
    if(root->vStatus(energy) >=8)
    {
        root->vStatus(health) += 5;
    }
    root->vStatus(no_sleep_time) = 0;
    root->vStatus(InSleep) = 1;
    root->vBody(hairStatus) = 0;
    if(root->vAddict(alko) > 1)
    {
        if(root->vAddict(alko) >= 6)
        {
            int moodNew = root->vStatus(mood) / 3;
            root->vStatus(mood) = moodNew;
        }
        else if(root->vAddict(alko) >= 3)
        {
            int moodNew = root->vStatus(mood) / 2;
            root->vStatus(mood) = moodNew;
        }
        int waterDec = root->vAddict(alko) * 3;
        root->vAddict(alko) -= waterDec;
    }
    int diffSon = 24 - root->vStatus(son);
    int zz_sleep_time;
    if(root->vAddict(alko) < 3 && root->vSick(sick) == 0)
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
    int zzBudTime = root->vBuzzer(timerH) * 60 + root->vBuzzer(timerM);
    int zzTime = root->getHour() * 60 + root->getMin();
    if(zzBudTime < zzTime) { zzBudTime += 24*60; }
    int zzWakeupdiff = zz_sleep_time*60 + son_minutes;
    int zzWakeup = zzWakeupdiff + zzTime;
    int zzBudilnik = root->vBuzzer(budilnik::timerH)*60 + root->vBuzzer(budilnik::timerM);
    if(root->vBuzzer(budilnikOn) == 1 && zzWakeup > zzBudTime)
    {
        diffSon = zzBudTime - zzTime;
        if(root->vAddict(alko) < 3)
        {
            root->vStatus(son) += 3*diffSon/60;
        }
        else
        {
            root->vStatus(son) += 2*diffSon/60;
        }
        root->incTime(diffSon);
    }
    else
    {
        if(root->vStatus(son) > 12)
        {
            root->incTime(zzWakeup - zzTime);
            root->vStatus(son) = 24;
        }
        else
        {
            root->incTime(7*60);
            root->vStatus(son) += 7*3;
        }
    }

    bedDreams();

    if(root->vBody(makeup) != 1) { root->vBody(makeup) = 1; }
    if(root->vSex(vibratorIN) == 1) { root->vSex(vibratorIN) = 0; }
    int budInMin = root->vBuzzer(timerH)*60 + root->vBuzzer(timerM);
    int curTimeInMin = root->getHour()*60 + root->getMin();
    if(root->vBuzzer(budilnikOn) == 1 && budInMin == curTimeInMin)
    {
        root->addText(actStr(actBed3));
        root->vStatus(mood) -= 3;
    }
    if(root->vStatus(oversleep) == 1)
    {
        root->addText(actStr(actBed4));
    }
    makeButtons();
    //AUTOSAVE
}

void Bed::relaxInBed()
{
    root->incTime(getRandInt(5,10));
    int i = 0;
//SUNWEATHER
    if(root->vStatus(son) < 10) i++;
    if(root->vStatus(mood) < 33) i++;
    if(root->vSex(painpub) > 0) i++;
    if(root->vSex(nippain) > 0) i++;
    if(root->vSick(sick) > 0) i++;
    if(root->vStatus(mesec) > 0) i++;
    if(root->vStatus(pregnancy) > 0) i++;
    if(root->vSex(spanked) > 0) i++;
    if(root->vAddict(alko) > 0) i++;
    int max = 0;
    if(root->vStatus(son) <= 10) max = 10;
    else max = 20;
    if(getRandInt(0, max) < 3)
    {
        root->vStatus(oversleep) = 1;
        sleepInBed();
    }
    else
    {
        slotActHandler(actBed0);
    }
}

void Bed::bedDreams()
{
    int _after = -1;
    int i = 0;
    //if(father=3)
    if(root->vStatus(horny) <= 50)
    {
        if(root->vStatus(mood) > 60)
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
        if(root->vStatistics(SC::blowJob) > 0)
        {
            i = getRandInt(12,23);
        }
        else if (root->vStatistics(SC::vaginalSex) > 0)
        {
            i = getRandInt(12,25);
        }
        else if (root->vStatistics(SC::analSex) > 0 || root->vStatistics(SC::gangBang) > 0)
        {
            i = getRandInt(12,27);
        }
        else
        {
            i = getRandInt(12,18);
        }

        if(i == 17 || i == 18)
        {
            if(root->vStatistics(SC::blowJob) == 0)
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
            if(root->vBody(vagina) == 0)
            {
                _after = 2;
            }
            else if (root->vStatistics(vaginalSex) == 0)
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
            if(root->vStatistics(SC::analSex) == 0)
            {
                if(root->vBody(anus) == 0)
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
            if(root->vStatistics(SC::gangBang) == 0)
            {
                _after = 8;
            }
            else
            {
                _after = 9;
            }
        }
        if(i < 12) { root->vStatus(horny) += 0; }
        else if(i >= 12 && i < 24) { root->vStatus(horny) += 10; }
        else { root->vStatus(horny) += 20; }
    }
    if(i > 27)
    {
        root->setImage("data/sex/fatherSex/bath_voyer_1.jpg");
    }
    else
    {
        root->setImage("data/img/dreams/" + intQStr(i) + ".jpg");
    }

    QString text = getDreamsDesc(i);
    if(_after >= 0)
    {
        text += "<br>" + getDreamsAfter(_after);
    }
    root->setText(text);
}

void Bed::makeBedActBtn(BedActs act)
{
    BedActionButton* btn = new BedActionButton(actStr(act), act);
    connect(btn, &BedActionButton::sigAction, this, &Bed::slotActHandler);
    root->addActions(btn);
}

void Bed::on_labelObjImage_linkActivated(const QString &link)
{
    if(link == "hour")
    {
        root->vBuzzer(timerH) += 1;
        if(root->vBuzzer(timerH) > 23) root->vBuzzer(timerH) = 0;
        slotActHandler(actBed2);
    }
    if(link == "minut")
    {
        root->vBuzzer(timerM) += 5;
        if(root->vBuzzer(timerM) > 59) root->vBuzzer(timerM) = 0;
        slotActHandler(actBed2);
    }
    root->setText(getDesc());
}


void Bed::on_labelObjDesc_linkActivated(const QString &link)
{
    if(link == "budilnikOn")
    {
        root->vBuzzer(budilnikOn) += 1;
        if(root->vBuzzer(budilnikOn) > 1) root->vBuzzer(budilnikOn) = 0;
        root->setText(getDesc());
    }
}


QString Bed::str(BedActs act)
{
    return QString();
}

QString Bed::actStr(BedActs act)
{
    QString str[12];
    str[0] = "";
    str[1] = "Еще минутку...";
    str[2] = "Завести будильник";

    str[3] = "Звенит будильник";
    str[4] = "Черт, черт, черт! Вот тебе и \"подремлю еще минутку\"!";
    str[5] = "Спать почему то не хочется.";
    
    str[6] = "Раздеться и лечь спать";
    str[7] = "Постараться уснуть";
    str[8] = "Встать с кровати";
    str[9] = "Мастурбировать";
    str[10] = "Встать с кровати и одеться";
    str[11] = "Встать с кровати";
    return  str[act];
}

void Bed::makeButtons()
{
    if (current == actBed0)
    {
        makeBedActBtn(actBed2);
        if (root->vStatus(Status::son) < 10)
        {
            makeBedActBtn(actBed6);
        }
        else
        {
            makeBedActBtn(actBed7);
        }
        if (root->vStatus(Status::horny) >= 60)
        {
            makeBedActBtn(actBed9);
        }
        makeBedActBtn(actBed8);
    }
    else if(current == actBed6 || current == actBed7)
    {
        makeBedActBtn(actBed1);
        makeBedActBtn(actBed10);

        if(root->vStatus(shamelessFlag) >= 2)
        {
            makeBedActBtn(actBed11);
        }
        makeBedActBtn(actBed7);
        root->vStatus(oversleep) = 0;
    }
    
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
