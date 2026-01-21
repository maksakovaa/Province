#include "family.h"
#include "../eventhandler.h"
#include "../../Functions.h"

Family::Family(EventHandler* parent): root(parent) {}

void Family::start(QString arg)
{
    if(arg == "checkTrip")
        checkTrip();
    if(arg == "mother_sheduler")
        mother_sheduler();
    if(arg == "father_sheduler")
        father_sheduler();
    if(arg == "sister_sheduler")
        sister_sheduler();
    if(arg == "brother_sheduler")
        brother_sheduler();
    if(arg == "mother_act")
        mother_act();
    if(arg == "father_act")
        father_act();
    if(arg == "brother_act")
        brother_act();
    if(arg == "sister_act")
        sister_act();
}

void Family::checkTrip()
{
    int trip_month = root->gVEvent(family_trip_month);
    int month = root->getMonth();
    int week = root->getWeekNum();
    if(trip_month == month || (trip_month != month && week > 0 && week < 6) || (trip_month != month && week == 6 && root->getHour() < 12))
    {
        root->sVEvent(family_trip, 0);
    }
    else
    {
        if(week == 0 && root->gNPC(NatalyaLebedeva).location == lgadhouse)
        {
            root->sVEvent(family_trip_month,month);
            root->sVEvent(family_trip,1);
        }
    }
}

void Family::mother_sheduler()
{
    checkTrip();
    if(root->gVEvent(family_trip) == 0)
    {
        int hour = root->getHour();
        int week = root->getWeekNum();

        if(hour < 6 || hour >= 21)
            root->gNPC(NatalyaLebedeva).location = lbedrpar2;
        if(hour == 6 || hour == 7 || hour == 18 || hour == 19)
            root->gNPC(NatalyaLebedeva).location = lkuhrpar;
        if(week > 0 && week < 6)
        {
            if(hour >= 8 && hour <= 17)
                root->gNPC(NatalyaLebedeva).location = lgkafe;
        }
        else
        {
            if(hour == 8) root->gNPC(NatalyaLebedeva).location = lbedrpar2;
            if(hour == 9 || hour == 10)
            {
                if(root->getSunWeather() < 0)
                    root->gNPC(NatalyaLebedeva).location = lshop;
                else
                    root->gNPC(NatalyaLebedeva).location = lgrinok;
            }
            if(hour == 11 || hour == 12)
                root->gNPC(NatalyaLebedeva).location = lsitrpar;
            if(hour >= 13 && hour <= 15)
            {
                if(root->getMonth() >= 5 && root->getMonth() <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(NatalyaLebedeva).location = lglake;
                        else
                            root->gNPC(NatalyaLebedeva).location = lpark;
                    }
                    else
                        root->gNPC(NatalyaLebedeva).location = lsitrpar;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (root->getMonth() == 4 || root->getMonth() == 10))
                        root->gNPC(NatalyaLebedeva).location = lpark;
                    else
                        root->gNPC(NatalyaLebedeva).location = lsitrpar;
                }
            }
        }
        if(hour == 20)
            root->gNPC(NatalyaLebedeva).location = lsitrpar;
    }
    else
        root->gNPC(NatalyaLebedeva).location = lgadhouse;
    //$mother['at_home'] = iif($mother['location'] = 'bedrPar2' or $mother['location'] = 'kuhrPar' or $mother['location'] = 'sitrPar',1,0)
    if(root->gNPC(NatalyaLebedeva).location == root->getCurLoc())
        mother_act();
}

void Family::father_sheduler()
{
    checkTrip();
    int week = root->getWeekNum();
    int hour = root->getHour();
    if(root->gVEvent(family_trip) == 0)
    {
        if(hour < 7 || hour >= 21) root->gNPC(VladimirSkryabin).location = lbedrpar2;
        if(hour == 7) root->gNPC(VladimirSkryabin).location = lkuhrpar;
        if(week < 6 && week > 0)
        {
            if(hour >= 8 && hour <= 16)
                root->gNPC(VladimirSkryabin).location = l_work;
            if(hour >= 18 && hour <= 20)
            {
                if(week == 1)
                    root->gNPC(VladimirSkryabin).location = l_null;
                else
                {
                    if(root->gVEvent(father_horny) >= 70)
                        root->gNPC(VladimirSkryabin).location = lsitrpar;
                    else
                        root->gNPC(VladimirSkryabin).location = lgargazel;
                }
            }
        }
        else
        {
            if(hour >= 8 && hour <= 15)
                root->gNPC(VladimirSkryabin).location = lsitrpar;
            if(hour >= 18 && hour <= 20)
            {
                if(week == 6)
                {
                    if(root->gVEvent(father_horny) >= 70)
                        root->gNPC(VladimirSkryabin).location = lsitrpar;
                    else
                        root->gNPC(VladimirSkryabin).location = lgargazel;
                }
                if(week == 0)
                    root->gNPC(VladimirSkryabin).location = lsitrpar;
            }
        }
        if(hour == 17)
        {
            if(week == 1)
                root->gNPC(VladimirSkryabin).location = l_null;
            else
                root->gNPC(VladimirSkryabin).location = lsitrpar;
        }
    }
    else
    {
        root->gNPC(VladimirSkryabin).location = lgadhouse;
    }
    //	if $father['location'] = 'gargazel': father['in_garage'] = 1
    //	$father['at_home'] = iif($father['location'] = 'bedrPar2' or $father['location'] = 'kuhrPar' or $father['location'] = 'sitrPar',1,0)
    if(root->gNPC(VladimirSkryabin).location == root->getCurLoc())
        father_act();
}

void Family::sister_sheduler()
{
    int hour = root->getHour();
    int week = root->getWeekNum();
    int month = root->getMonth();
    checkTrip();
    if(root->gVEvent(family_trip) == 0)
    {
        if(hour < 7 || hour >= 22)
            root->gNPC(AnyaLebedeva).location = lbedrpar;
        if(week < 6 && week > 0)
        {
            if(hour == 7)
                root->gNPC(AnyaLebedeva).location = lkuhrpar;
            if(hour >= 8 && hour < 16)
                root->gNPC(AnyaLebedeva).location = lshop;
            if(hour == 16)
            {
                if(month >= 5 && month <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(AnyaLebedeva).location = lglake;
                        else
                            root->gNPC(AnyaLebedeva).location = lgdk;
                    }
                    else
                        root->gNPC(AnyaLebedeva).location = lcafeparco;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (month == 4 || month == 10))
                        root->gNPC(AnyaLebedeva).location = lgdk;
                    else
                        root->gNPC(AnyaLebedeva).location = lcafeparco;
                }
            }
        }
        else
        {
            if(hour >= 8 && hour <= 11)
                root->gNPC(AnyaLebedeva).location = lbedrpar;
            if(hour >= 12 && hour <= 16)
            {
                if(month >= 5 && month <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(AnyaLebedeva).location = lglake;
                        else
                            root->gNPC(AnyaLebedeva).location = lgdk;
                    }
                    else
                        root->gNPC(AnyaLebedeva).location = lcafeparco;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (month == 4 || month == 10))
                        root->gNPC(AnyaLebedeva).location = lgdk;
                    else
                        root->gNPC(AnyaLebedeva).location = lcafeparco;
                }
            }
        }
        if(hour >= 17 && hour <= 21)
        {
            if(week == 5)
                root->gNPC(AnyaLebedeva).location = lreks_home;
            else
                root->gNPC(AnyaLebedeva).location = lroma_home;
        }
    }
    else
        root->gNPC(AnyaLebedeva).location = lgadhouse;
    //	$sister['at_home'] = iif($sister['location'] = 'bedrPar' or $sister['location'] = 'kuhrPar' or $sister['location'] = 'sitrPar',1,0)
    if(root->gNPC(AnyaLebedeva).location == root->getCurLoc())
        sister_act();
}

void Family::brother_sheduler()
{
    int hour = root->getHour();
    int week = root->getWeekNum();
    int month = root->getMonth();
    int min = root->getMin();
    checkTrip();
    if(root->gVEvent(family_trip) == 0)
    {
        if(root->gVQuest(qwKolkaPrince) < 4 || root->gVSchool(vacation) == 0)
        {
            if(hour < 7)
                root->gNPC(KolyaSkryabin).location = lsitrpar;
            if(hour == 17)
            {
                if(root->getSunWeather() >= 0)
                    root->gNPC(KolyaSkryabin).location = lgschool;
                else
                    root->gNPC(KolyaSkryabin).location = lmishahome;
            }
            if(hour >= 18)
                root->gNPC(KolyaSkryabin).location = lsitrpar;
        }
        else
        {
            if(hour < 6 || (hour == 6 && min < 30))
                root->gNPC(KolyaSkryabin).location = lsitrpar;
            if(hour == 6 && min >= 30)
                root->gNPC(KolyaSkryabin).location = lbedrpar;
            if(hour >= 17 && hour <= 20)
                root->gNPC(KolyaSkryabin).location = lbedrpar;
            if(hour > 20)
                root->gNPC(KolyaSkryabin).location = lsitrpar;
        }
        if(hour == 7)
            root->gNPC(KolyaSkryabin).location = lkuhrpar;
        if(week > 0 && week < 6 && root->gVSchool(vacation) == 0)
        {
            if(hour >= 8 && hour < 16)
                root->gNPC(KolyaSkryabin).location = lgschool;
        }
        else
        {
            if(hour >= 8 && hour < 11)
                root->gNPC(KolyaSkryabin).location = lsitrpar;
            if(hour >= 11 && hour < 16)
            {
                if(root->getSunWeather() >= 0 && month > 2 && month < 12)
                    root->gNPC(KolyaSkryabin).location = lgschool;
                else
                    root->gNPC(KolyaSkryabin).location = lmishahome;
            }
        }
        if(hour == 15 || hour == 16)
            root->gNPC(KolyaSkryabin).location = lgschool;
    }
    else
    {
        root->gNPC(KolyaSkryabin).location = lgadhouse;
    }
    //	$brother['at_home'] = iif($brother['location'] = 'kuhrPar' or $brother['location'] = 'sitrPar',1,0)
    if(root->gNPC(KolyaSkryabin).location == root->getCurLoc())
        brother_act();

}

void Family::mother_act()
{
    if(root->gNPC(NatalyaLebedeva).location == lkuhrpar && root->getHour() > 7)
    {
        QString img[5] {media(getRandInt(0,2)), media(3), media(4),media(getRandInt(5,15)), media(getRandInt(16,18))};
        QString txt[5] {str(0),str(1),str(2),str(3),str(4)};
        if(root->gVEvent(momActHour) != root->getHour())
        {
            if(root->gVEvent(momAction) < 4)
                root->uVEvent(momAction,1);
            else
                root->sVEvent(momAction,0);
            root->sVEvent(momActHour,root->getHour());
        }
        root->setImage(img[root->gVEvent(momAction)]);
        root->setDesc(txt[root->gVEvent(momAction)]);
    }
    if(root->gNPC(NatalyaLebedeva).location == lbedrpar2)
    {
        if(root->getHour() == 8 && (root->getWeekNum() == 6 || root->getWeekNum() == 0))
            root->addDesc(str(5));
    }
    if(root->gNPC(NatalyaLebedeva).location == lsitrpar)
    {
        root->addDesc(str(6));
    }
    if(root->gNPC(NatalyaLebedeva).location == lpark)
    {
        root->addDesc(str(7));
    }
    if(root->gNPC(NatalyaLebedeva).location == lglake)
    {
        root->addDesc(str(8));
    }
    if(root->gNPC(NatalyaLebedeva).location == lshop || root->gNPC(NatalyaLebedeva).location == lgrinok)
    {
        root->addDesc(str(9));
    }
}

void Family::father_act()
{
    if(root->gNPC(VladimirSkryabin).location == lsitrpar)
        root->addDesc(str(10));
}

void Family::brother_act()
{
    int hour = root->getHour();
    int month = root->getMonth();
    int week = root->getWeekNum();
    int min = root->getMin();

    if(root->gNPC(KolyaSkryabin).location == lgschool)
    {
        if(root->getSunWeather() >= 0 && month > 2 && month < 12)
        {
            root->setDesc(str(11));
        }
        else
        {
            root->setDesc(str(12));
        }
    }
    if(root->gNPC(KolyaSkryabin).location == lsitrpar)
    {
        if(hour >= 18 && hour <= 20)
        {
            if(week < 6 && root->gVSchool(vacation) == 0)
                root->addDesc(str(13));
            else
                root->addDesc(str(14));
        }
        if(hour == 21 || hour == 22 || (hour > 7 && hour < 11))
            root->addDesc(str(14));
        if(hour == 23 || hour < 7)
            root->addDesc(str(15));
    }
    if(root->gNPC(KolyaSkryabin).location == lbedrpar)
    {
        if(hour == 6 && min >= 30)
            root->addDesc(str(16));
        if(hour >= 17 && hour <= 20)
            root->addDesc(str(17));
    }
}

void Family::sister_act()
{
    int hour = root->getHour();
    int week = root->getWeekNum();
    int min = root->getMin();

    if(root->gVQuest(wedding) < 3)
    {
        if(root->gNPC(AnyaLebedeva).location == lbedrpar)
        {
            if(hour >= 22)
            {
                if(week == 5)
                    root->addDesc(str(18));
                else
                    root->addDesc(str(19));
            }
            if((hour < 7 && week < 6) || (hour < 10 && week >= 6))
                root->addDesc(str(20));
            if((hour == 10 || hour == 11) && week >= 6)
                root->addDesc(str(21));
        }
        if(root->gNPC(AnyaLebedeva).location == lgdk)
            root->addDesc(str(22));
        if(root->gNPC(AnyaLebedeva).location == lcafeparco)
            root->addDesc(str(22));
        if(root->gNPC(AnyaLebedeva).location == lglake)
            root->addDesc(str(23));
    }
    else
    {
        if(root->gNPC(AnyaLebedeva).location == lRoom)
        {
            if(hour >= 0 && hour <= 7)
                root->addDesc(str(24));
            if(week <= 5)
            {
                if(hour >= 18 && hour < 0)
                    root->addDesc(str(25));
            }
            else
            {
                if((hour >= 9 && hour <= 15) || (hour >= 20 && hour < 0))
                    root->addDesc(str(26));
            }
        }
        if(root->gNPC(AnyaLebedeva).location == lKitchen)
        {
            if(hour == 8 && min <= 30)
                root->addDesc(str(27));
            if((week <= 5 && hour >= 16 && hour <= 18) || (week > 5 && hour == 19))
                root->addDesc(str(28));
        }
        if(root->gNPC(AnyaLebedeva).location == lbathroom)
        {
            if(hour == 8 && min <= 30)
                root->addDesc(str(29));
        }
        if(root->gNPC(AnyaLebedeva).location == lcafeparco)
        {
            if(week > 5 && hour > 15 && hour <= 18)
                root->addDesc(str(30));
        }
    }
}

QString Family::media(int id)
{
    QString med[19];
    med[0] = "data/npc/pavlovo/mother/posuda1.jpg";
    med[1] = "data/npc/pavlovo/mother/posuda2.jpg";
    med[2] = "data/npc/pavlovo/mother/posuda3.jpg";
    med[3] = "data/npc/pavlovo/mother/gotovka.jpg";
    med[4] = "data/npc/pavlovo/mother/tea.jpg";
    med[5] = "data/npc/pavlovo/mother/prost1.jpg";
    med[6] = "data/npc/pavlovo/mother/prost2.jpg";
    med[7] = "data/npc/pavlovo/mother/prost3.jpg";
    med[8] = "data/npc/pavlovo/mother/prost4.jpg";
    med[9] = "data/npc/pavlovo/mother/prost5.jpg";
    med[10] = "data/npc/pavlovo/mother/prost6.jpg";
    med[11] = "data/npc/pavlovo/mother/prost7.jpg";
    med[12] = "data/npc/pavlovo/mother/prost8.jpg";
    med[13] = "data/npc/pavlovo/mother/prost9.jpg";
    med[14] = "data/npc/pavlovo/mother/prost10.jpg";
    med[15] = "data/npc/pavlovo/mother/prost11.jpg";
    med[16] = "data/npc/pavlovo/mother/uborka1.jpg";
    med[17] = "data/npc/pavlovo/mother/uborka2.jpg";
    med[18] = "data/npc/pavlovo/mother/uborka3.jpg";
    return med[id];
}

QString Family::str(int id)
{
    QString str[31];
    str[0] = "Возле мойки стоит <a href='mother'>мама</a> и моет посуду.";
    str[1] = "Возле плиты стоит <a href='mother'>мама</a> и что-то готовит.";
    str[2] = "<a href='mother'>Мама</a> пьет чай.";
    str[3] = "На кухне крутится <a href='mother'>мама</a> и что-то ищет.";
    str[4] = "<a href='mother'>Мама</a> с веником в руках наводит порядок.";
    str[5] = "Ваша <a href='mother'>мать</a>, похоже, решила раслабиться в выходной и поваляться в кровати.";
    str[6] = "На диване сидит ваша <a href='mother'>мать</a>, совмещая просмотр телевизора и листание журнала.";
    str[7] = "В парке на лавочке с другими тетками сидит ваша <a href='mother'>мама</a>.";
    str[8] = "В компании других теток на пляже загорает ваша <a href='mother'>мама</a>.";
    str[9] = "Как обычно, по выходных с утра ваша <a href='mother'>мама</a> пошла за покупками.";
    str[10] = "На диване сидит <a href='eFather-main'>отчим</a> и смотрит телевизор.";
    str[11] = "Возле школы <a href='brother_main'>Колька</a> с друганами гоняет футбол.";
    str[12] = "Возле школы в сторонке заговорщицки о чем-то болтает <a href='brother_main'>Колька</a> с друганами.";

    str[13] = "За столом сидит ваш младший брат <a href='brother_main'>Колька</a> и учит уроки.";
    str[14] = "<a href='brother_main'>Колька</a>, развалившись на диване, смотрит телик.";
    str[15] = "На диване спит ваш младший брат <a href='brother_main'>Колька</a>.";

    str[16] = "<a href='brother_main'>Колька</a> занимается зарядкой по середине комнаты.";
    str[17] = "За вашим столом сидит <a href='brother_main'>Колька</a> и учит уроки.";

    str[18] = "Ваша пьяная сестра Аня спит на кровати.";
    str[19] = "Ваша сестра <a href='sister'>Аня</a> сидит на кровати и читает книгу.";
    str[20] = "Ваша сестра <a href='sistersleep'>Аня</a> спит на кровати.";
    str[21] = "Ваша сестра <a href='sister'>Аня</a> собирается на прогулку.";

    str[22] = "Ваша сестра <a href='sister'>Аня</a> сидит в компании друзей и пьет пиво.";
    str[23] = "Ваша сестра <a href='sister'>Аня</a> загорает в компании друзей.";

    str[24] = "Аня с Михаилом спят на диване";
    str[25] = "<a href='sister'>Аня</a> с <a href='misha'>Мишей</a> сидят на диване";
    str[26] = "<a href='sister'>Аня</a> с <a href='misha'>Мишей</a> сидят на диване";
    str[27] = "<a href='sister'>Аня</a> завтракает на кухне";
    str[28] = "<a href='sister'>Аня</a> готовит еду";
    str[29] = "<a href='sister'>Аня</a> и <a href='misha'>Мишей</a> вместе принимают душ";
    str[30] = "<a href='sister'>Аня</a> и <a href='misha'>Мишей</a> вместе сидят в кафе";
    return str[id];
}

