#include "gadforest.h"
#include "../../menu/buttons.h"
#include "../locationhandler.h"
#include "../../Functions.h"

Gadforest::Gadforest(LocationHandler* ptr): Location(ptr) {}

void Gadforest::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("1");
    else
        actionHandler(arg);
}

LocId Gadforest::getLocId()
{
    return lgadforest;
}

LocId Gadforest::getParId()
{
    return lgadroad;
}

LocId Gadforest::getLocIn()
{
    return lgadukino;
}

QString Gadforest::getLocName()
{
    return "Окраина леса";
}

bool Gadforest::isParent()
{
    return true;
}

void Gadforest::actionHandler(QString action)
{
    clearActions();
    if(action == "1")
    {
        sVEvent(edge_forestday_current,1);
        if(gVEvent(goforestday) != gVStatus(daystart))
        {
            if(!isJeans())
                decrease_condition();
            if(isGlamour())
                decrease_condition(4);
        }
        if(gVEvent(goforest) < 20)
            uVEvent(goforest, getRandInt(0,1));
        sVEvent(lost,1);
        sVEvent(foresteventrand,getRandInt(1,20));
        sVEvent(new_bilberry,0);
        sVEvent(new_boletus,0);
        if(getSnow() <= 0)
        {
            if(isDay())
            {
                setImage(media(0));
                setDesc(str(0));
            }
            else
            {
                setImage(media(1));
                setDesc(str(1));
            }
        }
        else
        {
            if(isDay())
            {
                setImage(media(2));
                setDesc(str(2));
            }
            else
            {
                setImage(media(3));
                setDesc(str(3));
            }
        }
        if(gVEvent(forestpicnic) == 1)
            addText(str(4));
        if(gVEvent(mirainforest) == 1)
            addText(str(5));
        if(gVStatus(clothesforest) == 1)
            addText(str(6));
        if(gVEvent(findvel) == 2)
            addText(str(7));
        if(gVEvent(goforest) < 20)
            addText(str(8));
        if(getTemp() >= 20 && getSunWeather() >= 0 && getHour() >= 6 && getHour() <= 20 && gVEvent(miratalkforest) == 1)
            startEvent(eGadForestEvent, "nude_event");
        if(gVEvent(foresteventrand) < 3 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(mushroom_pickersday) != gVStatus(daystart))
        {
            sVEvent(mushroom_pickers,1);
            startEvent(eGadForestEvent,"mushroom_pickers1");
        }
        if(gVEvent(foresteventrand) == 3 && getMonth() >= 5 && getMonth() <= 9 && getTemp() >= 20 && getSunWeather() >= 0 && (getWeekNum() == 0 || getWeekNum() > 5) && gVEvent(forestpicnic) == 0)
        {
            sVEvent(forestpicnic,1);
            startEvent(eGadForestEvent,"picnic");
        }
        if(gVEvent(foresteventrand) == 4 && getMonth() >= 6 && getMonth() <= 9)
            startEvent(eGadForestEvent,"mushroom_pickers2");
        if(getMonth() >= 4 && getMonth() <= 10 && gVEvent(gadboyday) != gVStatus(daystart))
        {
            if(gVEvent(foresteventrand) == 5 && getHour() >= 8 && getHour() <= 15 && getWeekNum() > 0 && getWeekNum() <= 5)
                startEvent(eGadForestEvent, "gopforest_mitka");
            if(gVEvent(foresteventrand) == 6 && getHour() >= 8 && getHour() <= 18 && getWeekNum() > 0 && getWeekNum() <= 5)
                startEvent(eGadForestEvent,"gopforest_kolyamba");
            if(gVEvent(foresteventrand) == 7 && getHour() >= 8 && getHour() <= 18 && getWeekNum() > 0 && getWeekNum() <= 5)
                startEvent(eGadForestEvent,"gopforest_vasyan");
            if(gVEvent(foresteventrand) == 8 && getHour() >= 8 && getHour() <= 15 && (getWeekNum() == 0 || getWeekNum() > 5))
                startEvent(eGadForestEvent,"gopforest_2boys");
            if(gVEvent(foresteventrand) == 9 && getHour() >= 8 && getHour() <= 15 && (getWeekNum() == 0 || getWeekNum() > 5))
                startEvent(eGadForestEvent,"gopforest_3boys");
        }
        if(gVStatus(clothesforest) == 1 && isNude())
            makeActBtn("wear_clothes",act(0));
        if(gVStatus(clothesforest) == 1 && !isNude())
            makeActBtn("collect_clothes",act(1));
        if(getHour() >= getSunrise() && getHour() < getSunset())
        {
            if(isCloth() && gVStatus(clothesforest) == 0 && getTemp() >= 20 && getSunWeather() >= 0 && gVEvent(miratalkforest) > 1 && gVEvent(mirainforest) == 0)
            {
                makeActBtn("undress_all",act(3));
            }
            if(getSunWeather() >= 0)
                makeActBtn("walk_in_forest",act(6));
            if(getMonth() >= 6 && getMonth() <= 9 && gVStatus(boletus) + gVStatus(bilberry) < 10 && gVEvent(edge_forestday1) != gVStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
            if(gVEvent(mirainforest) == 0)
                makeActBtn("deep_in_forest",act(9));
        }

        if(gVEvent(goswamp) == 1 && gVEvent(mirainforest) == 0)
            makeActBtn("swamp",act(4));

        makeActBtn("gadroad",act(5));
    }
    if(action == "wear_clothes")
    {
        redressOld();
        sVStatus(swamp_clothes,0);
        sVStatus(clothesforest,0);
        incTime(5);
        if(isSkirt())
            setImage(media(4));
        else
            setImage(media(5));
        setDesc(str(9));
        makeActBtn("1",act(2));
    }
    if(action == "collect_clothes")
    {
        storeOldToWardrobe();
        sVStatus(clothesforest,0);
        addText(str(10));
        makeActBtn("1",act(2));
    }
    if(action == "undress_all")
    {
        if(gVEvent(forestpicnic) == 0)
        {
            sVStatus(clothesforest,1);
            incTime(5);
            if(isSkirt())
                setImage(media(4));
            else
                setImage(media(5));
            setDesc(str(11));
            redress(ClothType::Main, nullptr);
            makeActBtn("1",act(2));
        }
        else
        {
            setImage(media(6));
            setDesc(str(12));
            makeActBtn("1",act(2));
        }
    }
    if(action == "swamp")
    {
        if(isDay())
            changeLoc(lswamp,75);
        else
            startEvent(eGadForestEvent,"swamp_road");
        sVEvent(edge_forestday_current,1);
    }
    if(action == "gadroad")
    {
        sVEvent(mirainforest,0);
        changeLoc(lgadroad,30);
        sVEvent(edge_forestday_current,1);
    }
    if(action == "walk_in_forest")
    {
        incTime(30);
        if(isNude())
        {
            uVStatus(mood,30);
            uVStatus(health,20);
            uVStatus(horny,5);
        }
        else
            uVStatus(mood,20);
        if(getMonth() >= 4 && getMonth() <= 10)
        {
            if(gVEvent(mirainforest) == 0)
            {
                if(isCloth() && !isSkirt())
                    setImage(media(7));
                if(isCloth() && isPanties() && isSkirt())
                    setImage(media(8));
                if(isCloth() && !isPanties() && isSkirt())
                    setImage(media(9));
                if(isNude())
                    setImage(media(10));
                setDesc(str(13));
            }
            else
            {
                if(isNude())
                    setImage(media(11));
                else
                    setImage(media(12));
                setDesc(str(14));
            }
        }
        else
        {
            if(gVEvent(mirainforest) == 0)
            {
                setImage(media(13));
                setDesc(str(15));
            }
            else
            {
                setImage(media(14));
                setDesc(str(16));
            }
        }
        makeActBtn("1",act(7));
    }
    if(action == "deep_in_forest")
    {
        if (gVEvent(goforest) >= getRandInt(1,30))
        {
            incTime(30);
            actionHandler("2");
        }
        else
        {
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
        
    }
    if(action == "2")
    {
        sVEvent(edge_forestday_current,2);
        if(gVEvent(goforest) < 40)
            uVEvent(goforest, getRandInt(0,1));
        sVEvent(lost, 2);
        sVEvent(foresteventrand, getRandInt(1,10));
        sVEvent(new_bilberry,0);
        sVEvent(new_boletus,0);
        if(getSnow() == 0)
        {
            if(isDay())
            {
                setImage(media(15));
                setDesc(str(17));
            }
            else
            {
                setImage(media(16));
                setDesc(str(18));
            }
        }
        else
        {
            if(isDay())
            {
                setImage(media(17));
                setDesc(str(19));
            }
            else
            {
                setImage(media(18));
                setDesc(str(20));
            }
        }
        if(gVEvent(goforest) < 40)
            addText(str(21));
        if(gVEvent(foresteventrand) == 1 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(mushroom_pickersday) != gVStatus(daystart))
        {
            sVEvent(mushroom_pickers,2);
            startEvent(eGadForestEvent, "mushroom_pickers1");
        }
        if(gVEvent(foresteventrand) == 2 && getHour() > 8 && getHour() < 20 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "forest_hanters");
        if(gVEvent(foresteventrand) > 7 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(foresteventday) != gVStatus(daystart))
        {
            sVEvent(mushroom_pickers,2);
            startEvent(eGadForestEvent,"mushroom_pickers3");
        }
        makeActBtn("go_back",act(10));
        if(getHour() >= getSunrise() && getHour() < getSunset())
        {
            if (getMonth() >= 6 && getMonth() <= 9 && gVStatus(boletus) + gVStatus(bilberry) < 10 && gVEvent(edge_forestday2) != gVStatus(daystart) + action.toInt())
            {
                makeActBtn("search_bb",act(8));
            }
            makeActBtn("deep_in_forest2",act(9));
        }
    }
    if(action == "go_back")
    {
        if(gVEvent(goforest) >= getRandInt(1,30))
        {
            incTime(30);
            actionHandler("1");
        }
        else
        {
            sVEvent(lost, 1);
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "search_bb")
    {
        startEvent(eGadForestEvent, "search");
    }
    if(action == "deep_in_forest2")
    {
        if(gVEvent(goforest) >= getRandInt(1,60))
        {
            incTime(30);
            actionHandler("3");
        }
        else
        {
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "3")
    {
        sVEvent(edge_forestday_current,3);
        if(gVEvent(goforest) < 60)
            uVEvent(goforest, getRandInt(0,1));
        sVEvent(lost, 3);
        sVEvent(foresteventrand,getRandInt(1,10));
        sVEvent(new_bilberry,0);
        sVEvent(new_boletus,0);
        if(getSnow() == 0)
        {
            if(isDay())
            {
                setImage(media(19));
                setDesc(str(22));
            }
            else
            {
                setImage(media(20));
                setDesc(str(23));
            }
        }
        else
        {
            if(isDay())
            {
                setImage(media(21));
                setDesc(str(24));
            }
            else
            {
                setImage(media(22));
                setDesc(str(25));
            }
        }
        if(gVEvent(goforest) < 60)
            addText(str(21));
        if(gVEvent(foresteventrand) == 1 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "basket");
        if(gVEvent(foresteventrand) == 2 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent,"billberry");
        if(gVEvent(foresteventrand) == 3 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "mushroom");
        if(gVEvent(foresteventrand) == 4 && getHour() > 8 && getHour() < 20 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "forest_hanters");
        makeActBtn("go_back2",act(10));
        if(getHour() >= getSunrise() && getHour() < getSunset())
        {
            if(getMonth() >= 6 && getMonth() <= 9 && gVStatus(boletus) + gVStatus(bilberry) < 10 && gVEvent(edge_forestday3) != gVStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
        }
        makeActBtn("deep_in_forest3",act(9));
    }
    if(action == "go_back2")
    {
        if (gVEvent(goforest) >= getRandInt(1,60))
        {
            incTime(30);
            actionHandler("2");
        }
        else
        {
            sVEvent(lost, 2);
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "deep_in_forest3")
    {
        if(gVEvent(goforest) >= getRandInt(1,100))
        {
            incTime(30);
            actionHandler("4");
        }
        else
        {
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "4")
    {
        sVEvent(edge_forestday_current,4);
        if(gVEvent(goforest) < 80)
            uVEvent(goforest, getRandInt(0,1));
        sVEvent(lost, 4);
        sVEvent(lostrand, getRandInt(1,120));
        sVEvent(foresteventrand,getRandInt(1,10));
        sVStatus(dirty, 0);
        sVEvent(new_bilberry,0);
        sVEvent(new_boletus,0);
        if(getSnow() == 0)
        {
            if(isDay())
            {
                setImage(media(23));
                setDesc(str(22));
            }
            else
            {
                setImage(media(24));
                setDesc(str(23));
            }
        }
        else
        {
            if(isDay())
            {
                setImage(media(25));
                setDesc(str(24));
            }
            else
            {
                setImage(media(26));
                setDesc(str(25));
            }
        }
        if(gVEvent(goforest) < 80)
            addText(str(21));
        if(gVEvent(foresteventrand) < 2 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "billberry");
        if(gVEvent(foresteventrand) > 7 && getMonth() >= 6 && getMonth() <= 9 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "mushroom");
        if(gVEvent(foresteventrand) == 5 && getHour() > 8 && getHour() < 20 && gVEvent(foresteventday) != gVStatus(daystart))
            startEvent(eGadForestEvent, "forest_hanters");
        makeActBtn("go_back3",act(10));
        if(getHour() >= getSunrise() && getHour() < getSunset())
        {
            if(getMonth() >= 6 && getMonth() <= 9 && gVStatus(boletus) + gVStatus(bilberry) < 10 && gVEvent(edge_forestday4) != gVStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
        }
        makeActBtn("deep_in_forest4",act(9));
    }
    if(action == "go_back3")
    {
        if(gVEvent(goforest) >= getRandInt(1,100))
        {
            incTime(30);
            actionHandler("3");
        }
        else
        {
            sVEvent(lost, 3);
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "deep_in_forest4")
    {
        if(gVEvent(goforest) >= gVEvent(lostrand) && (gVEvent(goswamp) == 1 || getSnow() > 0))
        {
            changeLoc(lswamp,30);
        }
        else if(gVEvent(goforest) >= gVEvent(lostrand) && gVEvent(goswamp) == 0)
        {
            changeLoc(lgadforestswamp,30);
        }
        else
        {
            startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "picnic")
    {
        startEvent(eGadForestEvent,"picnic");
    }
    if(action == "Miroslava")
    {
        startEvent(eMiroslava);
    }
    if(action == "bicycle")
    {
        startEvent(eBicycle,"forest");
    }
}

void Gadforest::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadforest");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadforest::actionHandler);
    addActBtn(btn);
}

QString Gadforest::str(int id)
{
    QString str[26];
    str[0] = "Окраина леса. Здесь мало грибов и часто можно встретить грибников.";
    str[1] = "Ночью в лесу страшно и неуютно.";
    str[2] = "Окраина леса. Зимний лес очень красив.";
    str[3] = "Ночью в зимнем лесу очень страшно и неуютно.";
    str[4] = "На окраине леса вы видите людей. Судя по всему у них тут семейный <a href='gadforest_event_picnic'>пикник</a>.";
    str[5] = "Недалеко от вас по лесу бродит <a href='Miroslava'>Мира</a>.";
    str[6] = "На земле лежит ваша одежда.";
    str[7] = "Возле дерева стоит старый <a href='bicycle'>велосипед</a>.";
    str[8] = "Вы плохо знаете эту часть леса, дальше лучше не ходить.";
    str[9] = "Вы переоделись в свою одежду.";
    str[10] = "Вы забрали свою одежду.";
    str[11] = "Вы не стеснясь разделись, оставшись в чем мать родила.";
    str[12] = "Рядом люди, вы стесняетесь.";
    str[13] = "Вы гуляете по лесу, наслаждаясь шумом деревьев и свежим воздухом.";
    str[14] = "Вы гуляете c Мирой по лесу, наслаждаясь шумом деревьев и свежим воздухом.";
    str[15] = "Вы гуляете по зимнему лесу, наслаждаясь шумом деревьев и свежим воздухом.";
    str[16] = "Вы гуляете с Мирой по зимнему лесу, наслаждаясь шумом деревьев и свежим воздухом.";
    str[17] = "От опьяняюще свежего воздуха и пения птиц на душе у вас светло и радостно.";
    str[18] = "Ночью в лесу страшно и неуютно.";
    str[19] = "Зимний лес очень красив, свежий воздух поднимает вам настроение.";
    str[20] = "Ночью в зимнем лесу очень страшно и неуютно.";
    str[21] = "Вы плохо знаете эту часть леса, дальше лучше не ходить.";
    str[22] = "От опьяняюще свежего воздуха и пения птиц на душе у вас светло и радостно.";
    str[23] = "Ночью в лесу страшно и неуютно.";
    str[24] = "Зимний лес очень красив, свежий воздух поднимает вам настроение.";
    str[25] = "Ночью в зимнем лесу очень страшно и неуютно.";
    return str[id];
}

QString Gadforest::act(int id)
{
    QString str[11];
    str[0] = "Одеться";
    str[1] = "Забрать брошеную одежду";
    str[2] = "Назад";
    str[3] = "Раздеться догола";
    str[4] = "Идти на болото";
    str[5] = "Выйти из леса";
    str[6] = "Гулять по лесу";
    str[7] = "Далее";
    str[8] = "Искать грибы и ягоды";
    str[9] = "Идти дальше в лес";
    str[10] = "Вернуться назад";
    return str[id];
}

QString Gadforest::media(int id)
{
    QString med[27];
    med[0] = "data/locations/gadukino/forest/gadforest1.jpg";
    med[1] = "data/locations/gadukino/forest/gadforest_night1.jpg";
    med[2] = "data/locations/gadukino/forest/gadforest_winter1.jpg";
    med[3] = "data/locations/gadukino/forest/gadforest_winter_night1.jpg";
    med[4] = "data/locations/gadukino/forest/nudeforest1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[5] = "data/locations/gadukino/forest/nudeforest.jpg";
    med[6] = "data/actions/backwater/noundress.jpg";
    med[7] = "data/locations/gadukino/forest/gulforest0" + intQStr(getRandInt(1,2)) + ".jpg";
    med[8] = "data/locations/gadukino/forest/gulforest1." + intQStr(getRandInt(1,3)) + ".jpg";
    med[9] = "data/locations/gadukino/forest/gulforest_tanga0." + intQStr(getRandInt(1,2)) + ".jpg";
    med[10] = "data/locations/gadukino/forest/gulforest_nude0." + intQStr(getRandInt(1,4)) + ".jpg";
    med[11] = "data/locations/gadukino/forest/miraforest_nude" + intQStr(getRandInt(1,3)) + ".jpg";
    med[12] = "data/locations/gadukino/forest/miraforest" + intQStr(getRandInt(1,3)) + ".jpg";
    med[13] = "data/locations/gadukino/forest/gulforestwinter0." + intQStr(getRandInt(1,2)) + ".jpg";
    med[14] = "data/locations/gadukino/forest/miraforestwinter.jpg";
    med[15] = "data/locations/gadukino/forest/gadforest2.jpg";
    med[16] = "data/locations/gadukino/forest/gadforest_night2.jpg";
    med[17] = "data/locations/gadukino/forest/gadforest_winter2.jpg";
    med[18] = "data/locations/gadukino/forest/gadforest_winter_night2.jpg";
    med[19] = "data/locations/gadukino/forest/gadforest3.jpg";
    med[20] = "data/locations/gadukino/forest/gadforest_night3.jpg";
    med[21] = "data/locations/gadukino/forest/gadforest_winter3.jpg";
    med[22] = "data/locations/gadukino/forest/gadforest_winter_night3.jpg";
    med[23] = "data/locations/gadukino/forest/gadforest4.jpg";
    med[24] = "data/locations/gadukino/forest/gadforest_night4.jpg";
    med[25] = "data/locations/gadukino/forest/gadforest_winter4.jpg";
    med[26] = "data/locations/gadukino/forest/gadforest_winter_night4.jpg";
    return med[id];
}
