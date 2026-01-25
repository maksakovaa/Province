#include "family.h"
#include "../../game.h"
#include "../../Functions.h"

Family::Family(Game* parent): root(parent) {}

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
    int trip_month = root->vEvent(family_trip_month);
    int month = root->getMonth();
    int week = root->getWeek();
    if(trip_month == month || (trip_month != month && week > 0 && week < 6) || (trip_month != month && week == 6 && root->getHour() < 12))
    {
        root->vEvent(family_trip) = 0;
    }
    else
    {
        if(week == 0 && root->gNPC(mother).location == lgadhouse)
        {
            root->vEvent(family_trip_month) = month;
            root->vEvent(family_trip) = 1;
        }
    }
}

void Family::mother_sheduler()
{
    checkTrip();
    if(root->vEvent(family_trip) == 0)
    {
        int hour = root->getHour();
        int week = root->getWeek();

        if(hour < 6 || hour >= 21)
            root->gNPC(mother).location = lbedrpar2;
        if(hour == 6 || hour == 7 || hour == 18 || hour == 19)
            root->gNPC(mother).location = lkuhrpar;
        if(week > 0 && week < 6)
        {
            if(hour >= 8 && hour <= 17)
                root->gNPC(mother).location = lgkafe;
        }
        else
        {
            if(hour == 8) root->gNPC(mother).location = lbedrpar2;
            if(hour == 9 || hour == 10)
            {
                if(root->getSunWeather() < 0)
                    root->gNPC(mother).location = lshop;
                else
                    root->gNPC(mother).location = lgrinok;
            }
            if(hour == 11 || hour == 12)
                root->gNPC(mother).location = lsitrpar;
            if(hour >= 13 && hour <= 15)
            {
                if(root->getMonth() >= 5 && root->getMonth() <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(mother).location = lglake;
                        else
                            root->gNPC(mother).location = lpark;
                    }
                    else
                        root->gNPC(mother).location = lsitrpar;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (root->getMonth() == 4 || root->getMonth() == 10))
                        root->gNPC(mother).location = lpark;
                    else
                        root->gNPC(mother).location = lsitrpar;
                }
            }
        }
        if(hour == 20)
            root->gNPC(mother).location = lsitrpar;
    }
    else
        root->gNPC(mother).location = lgadhouse;
    //$mother['at_home'] = iif($mother['location'] = 'bedrPar2' or $mother['location'] = 'kuhrPar' or $mother['location'] = 'sitrPar',1,0)
    if(root->gNPC(mother).location == root->getCurLoc())
        mother_act();
}

void Family::father_sheduler()
{
    checkTrip();
    int week = root->getWeek();
    int hour = root->getHour();
    if(root->vEvent(family_trip) == 0)
    {
        if(hour < 7 || hour >= 21) root->gNPC(father).location = lbedrpar2;
        if(hour == 7) root->gNPC(father).location = lkuhrpar;
        if(week < 6 && week > 0)
        {
            if(hour >= 8 && hour <= 16)
                root->gNPC(father).location = l_work;
            if(hour >= 18 && hour <= 20)
            {
                if(week == 1)
                    root->gNPC(father).location = l_null;
                else
                {
                    if(root->vEvent(father_horny) >= 70)
                        root->gNPC(father).location = lsitrpar;
                    else
                        root->gNPC(father).location = lgargazel;
                }
            }
        }
        else
        {
            if(hour >= 8 && hour <= 15)
                root->gNPC(father).location = lsitrpar;
            if(hour >= 18 && hour <= 20)
            {
                if(week == 6)
                {
                    if(root->vEvent(father_horny) >= 70)
                        root->gNPC(father).location = lsitrpar;
                    else
                        root->gNPC(father).location = lgargazel;
                }
                if(week == 0)
                    root->gNPC(father).location = lsitrpar;
            }
        }
        if(hour == 17)
        {
            if(week == 1)
                root->gNPC(father).location = l_null;
            else
                root->gNPC(father).location = lsitrpar;
        }
    }
    else
    {
        root->gNPC(father).location = lgadhouse;
    }
    //	if $father['location'] = 'gargazel': father['in_garage'] = 1
    //	$father['at_home'] = iif($father['location'] = 'bedrPar2' or $father['location'] = 'kuhrPar' or $father['location'] = 'sitrPar',1,0)
    if(root->gNPC(father).location == root->getCurLoc())
        father_act();
}

void Family::sister_sheduler()
{
    int hour = root->getHour();
    int week = root->getWeek();
    int month = root->getMonth();
    checkTrip();
    if(root->vEvent(family_trip) == 0)
    {
        if(hour < 7 || hour >= 22)
            root->gNPC(sister).location = lbedrpar;
        if(week < 6 && week > 0)
        {
            if(hour == 7)
                root->gNPC(sister).location = lkuhrpar;
            if(hour >= 8 && hour < 16)
                root->gNPC(sister).location = lshop;
            if(hour == 16)
            {
                if(month >= 5 && month <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(sister).location = lglake;
                        else
                            root->gNPC(sister).location = lgdk;
                    }
                    else
                        root->gNPC(sister).location = lcafeparco;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (month == 4 || month == 10))
                        root->gNPC(sister).location = lgdk;
                    else
                        root->gNPC(sister).location = lcafeparco;
                }
            }
        }
        else
        {
            if(hour >= 8 && hour <= 11)
                root->gNPC(sister).location = lbedrpar;
            if(hour >= 12 && hour <= 16)
            {
                if(month >= 5 && month <= 9)
                {
                    if(root->getSunWeather() >= 0)
                    {
                        if(root->getTemp() >= 20)
                            root->gNPC(sister).location = lglake;
                        else
                            root->gNPC(sister).location = lgdk;
                    }
                    else
                        root->gNPC(sister).location = lcafeparco;
                }
                else
                {
                    if(root->getSunWeather() >= 0 && (month == 4 || month == 10))
                        root->gNPC(sister).location = lgdk;
                    else
                        root->gNPC(sister).location = lcafeparco;
                }
            }
        }
        if(hour >= 17 && hour <= 21)
        {
            if(week == 5)
                root->gNPC(sister).location = lreks_home;
            else
                root->gNPC(sister).location = lroma_home;
        }
    }
    else
        root->gNPC(sister).location = lgadhouse;
    //	$sister['at_home'] = iif($sister['location'] = 'bedrPar' or $sister['location'] = 'kuhrPar' or $sister['location'] = 'sitrPar',1,0)
    if(root->gNPC(sister).location == root->getCurLoc())
        sister_act();
}

void Family::brother_sheduler()
{
    int hour = root->getHour();
    int week = root->getWeek();
    int month = root->getMonth();
    int min = root->getMin();
    checkTrip();
    if(root->vEvent(family_trip) == 0)
    {
        if(root->vQuest(qwKolkaPrince) < 4 || root->vSchool(vacation) == 0)
        {
            if(hour < 7)
                root->gNPC(brother).location = lsitrpar;
            if(hour == 17)
            {
                if(root->getSunWeather() >= 0)
                    root->gNPC(brother).location = lgschool;
                else
                    root->gNPC(brother).location = lmishahome;
            }
            if(hour >= 18)
                root->gNPC(brother).location = lsitrpar;
        }
        else
        {
            if(hour < 6 || (hour == 6 && min < 30))
                root->gNPC(brother).location = lsitrpar;
            if(hour == 6 && min >= 30)
                root->gNPC(brother).location = lbedrpar;
            if(hour >= 17 && hour <= 20)
                root->gNPC(brother).location = lbedrpar;
            if(hour > 20)
                root->gNPC(brother).location = lsitrpar;
        }
        if(hour == 7)
            root->gNPC(brother).location = lkuhrpar;
        if(week > 0 && week < 6 && root->vSchool(vacation) == 0)
        {
            if(hour >= 8 && hour < 16)
                root->gNPC(brother).location = lgschool;
        }
        else
        {
            if(hour >= 8 && hour < 11)
                root->gNPC(brother).location = lsitrpar;
            if(hour >= 11 && hour < 16)
            {
                if(root->getSunWeather() >= 0 && month > 2 && month < 12)
                    root->gNPC(brother).location = lgschool;
                else
                    root->gNPC(brother).location = lmishahome;
            }
        }
        if(hour == 15 || hour == 16)
            root->gNPC(brother).location = lgschool;
    }
    else
    {
        root->gNPC(brother).location = lgadhouse;
    }
    //	$brother['at_home'] = iif($brother['location'] = 'kuhrPar' or $brother['location'] = 'sitrPar',1,0)
    if(root->gNPC(brother).location == root->getCurLoc())
        brother_act();

}

void Family::mother_act()
{
    if(root->gNPC(mother).location == lkuhrpar && root->getHour() > 7)
    {
        QString img[5] {media(getRandInt(0,2)), media(3), media(4),media(getRandInt(5,15)), media(getRandInt(16,18))};
        QString txt[5] {str(0),str(1),str(2),str(3),str(4)};
        if(root->vEvent(momActHour) != root->getHour())
        {
            if(root->vEvent(momAction) < 4)
                root->vEvent(momAction) +=1;
            else
                root->vEvent(momAction) += 0;
            root->vEvent(momActHour) = root->getHour();
        }
        root->setImage(img[root->vEvent(momAction)]);
        root->setText(txt[root->vEvent(momAction)]);
    }
    if(root->gNPC(mother).location == lbedrpar2)
    {
        if(root->getHour() == 8 && (root->getWeek() == 6 || root->getWeek() == 0))
            root->addText(str(5));
    }
    if(root->gNPC(mother).location == lsitrpar)
    {
        root->addText(str(6));
    }
    if(root->gNPC(mother).location == lpark)
    {
        root->addText(str(7));
    }
    if(root->gNPC(mother).location == lglake)
    {
        root->addText(str(8));
    }
    if(root->gNPC(mother).location == lshop || root->gNPC(mother).location == lgrinok)
    {
        root->addText(str(9));
    }
}

void Family::father_act()
{
    if(root->gNPC(father).location == lsitrpar)
        root->addText(str(10));
}

void Family::brother_act()
{
    int hour = root->getHour();
    int month = root->getMonth();
    int week = root->getWeek();
    int min = root->getMin();

    if(root->gNPC(brother).location == lgschool)
    {
        if(root->getSunWeather() >= 0 && month > 2 && month < 12)
        {
            root->setText(str(11));
        }
        else
        {
            root->setText(str(12));
        }
    }
    if(root->gNPC(brother).location == lsitrpar)
    {
        if(hour >= 18 && hour <= 20)
        {
            if(week < 6 && root->vSchool(vacation) == 0)
                root->addText(str(13));
            else
                root->addText(str(14));
        }
        if(hour == 21 || hour == 22 || (hour > 7 && hour < 11))
            root->addText(str(14));
        if(hour == 23 || hour < 7)
            root->addText(str(15));
    }
    if(root->gNPC(brother).location == lbedrpar)
    {
        if(hour == 6 && min >= 30)
            root->addText(str(16));
        if(hour >= 17 && hour <= 20)
            root->addText(str(17));
    }
}

void Family::sister_act()
{
    int hour = root->getHour();
    int week = root->getWeek();
    int min = root->getMin();

    if(root->vQuest(wedding) < 3)
    {
        if(root->gNPC(sister).location == lbedrpar)
        {
            if(hour >= 22)
            {
                if(week == 5)
                    root->addText(str(18));
                else
                    root->addText(str(19));
            }
            if((hour < 7 && week < 6) || (hour < 10 && week >= 6))
                root->addText(str(20));
            if((hour == 10 || hour == 11) && week >= 6)
                root->addText(str(21));
        }
        if(root->gNPC(sister).location == lgdk)
            root->addText(str(22));
        if(root->gNPC(sister).location == lcafeparco)
            root->addText(str(22));
        if(root->gNPC(sister).location == lglake)
            root->addText(str(23));
    }
    else
    {
        if(root->gNPC(sister).location == lRoom)
        {
            if(hour >= 0 && hour <= 7)
                root->addText(str(24));
            if(week <= 5)
            {
                if(hour >= 18 && hour < 0)
                    root->addText(str(25));
            }
            else
            {
                if((hour >= 9 && hour <= 15) || (hour >= 20 && hour < 0))
                    root->addText(str(26));
            }
        }
        if(root->gNPC(sister).location == lKitchen)
        {
            if(hour == 8 && min <= 30)
                root->addText(str(27));
            if((week <= 5 && hour >= 16 && hour <= 18) || (week > 5 && hour == 19))
                root->addText(str(28));
        }
        if(root->gNPC(sister).location == lbathroom)
        {
            if(hour == 8 && min <= 30)
                root->addText(str(29));
        }
        if(root->gNPC(sister).location == lcafeparco)
        {
            if(week > 5 && hour > 15 && hour <= 18)
                root->addText(str(30));
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

