#include "gadforest.h"
#include "../../menu/buttons.h"
#include "../../game.h"
#include "../../Functions.h"

Gadforest::Gadforest(Game* ptr): root(ptr) {}

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
    root->clearActions();
    if(action == "1")
    {
        root->vEvent(edge_forestday_current) = 1;
        if(root->vEvent(goforestday) != root->vStatus(daystart))
        {
            if(!root->isJeans())
                root->decreaseClothCond();
            if(root->isGlamour())
                root->decreaseClothCond(4);
        }
        if(root->vEvent(goforest) < 20)
            root->vEvent(goforest) += getRandInt(0,1);
        root->vEvent(lost) = 1;
        root->vEvent(foresteventrand) = getRandInt(1,20);
        root->vEvent(new_bilberry) = 0;
        root->vEvent(new_boletus) = 0;
        if(root->getSnow() <= 0)
        {
            if(root->isDay())
            {
                root->setImage(media(0));
                root->setText(str(0));
            }
            else
            {
                root->setImage(media(1));
                root->setText(str(1));
            }
        }
        else
        {
            if(root->isDay())
            {
                root->setImage(media(2));
                root->setText(str(2));
            }
            else
            {
                root->setImage(media(3));
                root->setText(str(3));
            }
        }
        if(root->vEvent(forestpicnic) == 1)
            root->addText(str(4));
        if(root->vEvent(mirainforest) == 1)
            root->addText(str(5));
        if(root->vStatus(clothesforest) == 1)
            root->addText(str(6));
        if(root->vEvent(findvel) == 2)
            root->addText(str(7));
        if(root->vEvent(goforest) < 20)
            root->addText(str(8));
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->getHour() >= 6 && root->getHour() <= 20 && root->vEvent(miratalkforest) == 1)
            root->startEvent(eGadForestEvent, "nude_event");
        if(root->vEvent(foresteventrand) < 3 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(mushroom_pickersday) != root->vStatus(daystart))
        {
            root->vEvent(mushroom_pickers) = 1;
            root->startEvent(eGadForestEvent,"mushroom_pickers1");
        }
        if(root->vEvent(foresteventrand) == 3 && root->getMonth() >= 5 && root->getMonth() <= 9 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && (root->getWeek() == 0 || root->getWeek() > 5) && root->vEvent(forestpicnic) == 0)
        {
            root->vEvent(forestpicnic) = 1;
            root->startEvent(eGadForestEvent,"picnic");
        }
        if(root->vEvent(foresteventrand) == 4 && root->getMonth() >= 6 && root->getMonth() <= 9)
            root->startEvent(eGadForestEvent,"mushroom_pickers2");
        if(root->getMonth() >= 4 && root->getMonth() <= 10 && root->vEvent(gadboyday) != root->vStatus(daystart))
        {
            if(root->vEvent(foresteventrand) == 5 && root->getHour() >= 8 && root->getHour() <= 15 && root->getWeek() > 0 && root->getWeek() <= 5)
                root->startEvent(eGadForestEvent, "gopforest_mitka");
            if(root->vEvent(foresteventrand) == 6 && root->getHour() >= 8 && root->getHour() <= 18 && root->getWeek() > 0 && root->getWeek() <= 5)
                root->startEvent(eGadForestEvent,"gopforest_kolyamba");
            if(root->vEvent(foresteventrand) == 7 && root->getHour() >= 8 && root->getHour() <= 18 && root->getWeek() > 0 && root->getWeek() <= 5)
                root->startEvent(eGadForestEvent,"gopforest_vasyan");
            if(root->vEvent(foresteventrand) == 8 && root->getHour() >= 8 && root->getHour() <= 15 && (root->getWeek() == 0 || root->getWeek() > 5))
                root->startEvent(eGadForestEvent,"gopforest_2boys");
            if(root->vEvent(foresteventrand) == 9 && root->getHour() >= 8 && root->getHour() <= 15 && (root->getWeek() == 0 || root->getWeek() > 5))
                root->startEvent(eGadForestEvent,"gopforest_3boys");
        }
        if(root->vStatus(clothesforest) == 1 && root->isNude())
            makeActBtn("wear_clothes",act(0));
        if(root->vStatus(clothesforest) == 1 && !root->isNude())
            makeActBtn("collect_clothes",act(1));
        if(root->getHour() >= root->getSunrise() && root->getHour() < root->getSunset())
        {
            if(root->isCloth() && root->vStatus(clothesforest) == 0 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->vEvent(miratalkforest) > 1 && root->vEvent(mirainforest) == 0)
            {
                makeActBtn("undress_all",act(3));
            }
            if(root->getSunWeather() >= 0)
                makeActBtn("walk_in_forest",act(6));
            if(root->getMonth() >= 6 && root->getMonth() <= 9 && root->vStatus(boletus) + root->vStatus(bilberry) < 10 && root->vEvent(edge_forestday1) != root->vStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
            if(root->vEvent(mirainforest) == 0)
                makeActBtn("deep_in_forest",act(9));
        }

        if(root->vEvent(goswamp) == 1 && root->vEvent(mirainforest) == 0)
            makeActBtn("swamp",act(4));

        makeActBtn("gadroad",act(5));
    }
    if(action == "wear_clothes")
    {
        root->redressOld();
        root->vStatus(swamp_clothes) = 0;
        root->vStatus(clothesforest) = 0;
        root->incTime(5);
        if(root->isSkirt())
            root->setImage(media(4));
        else
            root->setImage(media(5));
        root->setText(str(9));
        makeActBtn("1",act(2));
    }
    if(action == "collect_clothes")
    {
        root->storeOldToWardrobe();
        root->vStatus(clothesforest) =0;
        root->addText(str(10));
        makeActBtn("1",act(2));
    }
    if(action == "undress_all")
    {
        if(root->vEvent(forestpicnic) == 0)
        {
            root->vStatus(clothesforest) = 1;
            root->incTime(5);
            if(root->isSkirt())
                root->setImage(media(4));
            else
                root->setImage(media(5));
            root->setText(str(11));
            root->redress(ClothType::Main, nullptr);
            makeActBtn("1",act(2));
        }
        else
        {
            root->setImage(media(6));
            root->setText(str(12));
            makeActBtn("1",act(2));
        }
    }
    if(action == "swamp")
    {
        if(root->isDay())
            root->changeLoc(lswamp,75);
        else
            root->startEvent(eGadForestEvent,"swamp_road");
        root->vEvent(edge_forestday_current) = 1;
    }
    if(action == "gadroad")
    {
        root->vEvent(mirainforest) = 0;
        root->changeLoc(lgadroad,30);
        root->vEvent(edge_forestday_current) = 1;
    }
    if(action == "walk_in_forest")
    {
        root->incTime(30);
        if(root->isNude())
        {
            root->vStatus(mood) += 30;
            root->vStatus(health) += 20;
            root->vStatus(horny) += 5;
        }
        else
            root->vStatus(mood) += 20;
        if(root->getMonth() >= 4 && root->getMonth() <= 10)
        {
            if(root->vEvent(mirainforest) == 0)
            {
                if(root->isCloth() && !root->isSkirt())
                    root->setImage(media(7));
                if(root->isCloth() && root->isPanties() && root->isSkirt())
                    root->setImage(media(8));
                if(root->isCloth() && !root->isPanties() && root->isSkirt())
                    root->setImage(media(9));
                if(root->isNude())
                    root->setImage(media(10));
                root->setText(str(13));
            }
            else
            {
                if(root->isNude())
                    root->setImage(media(11));
                else
                    root->setImage(media(12));
                root->setText(str(14));
            }
        }
        else
        {
            if(root->vEvent(mirainforest) == 0)
            {
                root->setImage(media(13));
                root->setText(str(15));
            }
            else
            {
                root->setImage(media(14));
                root->setText(str(16));
            }
        }
        makeActBtn("1",act(7));
    }
    if(action == "deep_in_forest")
    {
        if (root->vEvent(goforest) >= getRandInt(1,30))
        {
            root->incTime(30);
            actionHandler("2");
        }
        else
        {
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
        
    }
    if(action == "2")
    {
        root->vEvent(edge_forestday_current) = 2;
        if(root->vEvent(goforest) < 40)
            root->vEvent(goforest) += getRandInt(0,1);
        root->vEvent(lost) = 2;
        root->vEvent(foresteventrand) = getRandInt(1,10);
        root->vEvent(new_bilberry) = 0;
        root->vEvent(new_boletus) = 0;
        if(root->getSnow() == 0)
        {
            if(root->isDay())
            {
                root->setImage(media(15));
                root->setText(str(17));
            }
            else
            {
                root->setImage(media(16));
                root->setText(str(18));
            }
        }
        else
        {
            if(root->isDay())
            {
                root->setImage(media(17));
                root->setText(str(19));
            }
            else
            {
                root->setImage(media(18));
                root->setText(str(20));
            }
        }
        if(root->vEvent(goforest) < 40)
            root->addText(str(21));
        if(root->vEvent(foresteventrand) == 1 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(mushroom_pickersday) != root->vStatus(daystart))
        {
            root->vEvent(mushroom_pickers) = 2;
            root->startEvent(eGadForestEvent, "mushroom_pickers1");
        }
        if(root->vEvent(foresteventrand) == 2 && root->getHour() > 8 && root->getHour() < 20 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "forest_hanters");
        if(root->vEvent(foresteventrand) > 7 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(foresteventday) != root->vStatus(daystart))
        {
            root->vEvent(mushroom_pickers) = 2;
            root->startEvent(eGadForestEvent,"mushroom_pickers3");
        }
        makeActBtn("go_back",act(10));
        if(root->getHour() >= root->getSunrise() && root->getHour() < root->getSunset())
        {
            if (root->getMonth() >= 6 && root->getMonth() <= 9 && root->vStatus(boletus) + root->vStatus(bilberry) < 10 && root->vEvent(edge_forestday2) != root->vStatus(daystart) + action.toInt())
            {
                makeActBtn("search_bb",act(8));
            }
            makeActBtn("deep_in_forest2",act(9));
        }
    }
    if(action == "go_back")
    {
        if(root->vEvent(goforest) >= getRandInt(1,30))
        {
            root->incTime(30);
            actionHandler("1");
        }
        else
        {
            root->vEvent(lost) = 1;
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "search_bb")
    {
        root->startEvent(eGadForestEvent, "search");
    }
    if(action == "deep_in_forest2")
    {
        if(root->vEvent(goforest) >= getRandInt(1,60))
        {
            root->incTime(30);
            actionHandler("3");
        }
        else
        {
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "3")
    {
        root->vEvent(edge_forestday_current) = 3;
        if(root->vEvent(goforest) < 60)
            root->vEvent(goforest) += getRandInt(0,1);
        root->vEvent(lost) = 3;
        root->vEvent(foresteventrand) = getRandInt(1,10);
        root->vEvent(new_bilberry) = 0;
        root->vEvent(new_boletus) = 0;
        if(root->getSnow() == 0)
        {
            if(root->isDay())
            {
                root->setImage(media(19));
                root->setText(str(22));
            }
            else
            {
                root->setImage(media(20));
                root->setText(str(23));
            }
        }
        else
        {
            if(root->isDay())
            {
                root->setImage(media(21));
                root->setText(str(24));
            }
            else
            {
                root->setImage(media(22));
                root->setText(str(25));
            }
        }
        if(root->vEvent(goforest) < 60)
            root->addText(str(21));
        if(root->vEvent(foresteventrand) == 1 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "basket");
        if(root->vEvent(foresteventrand) == 2 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent,"billberry");
        if(root->vEvent(foresteventrand) == 3 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "mushroom");
        if(root->vEvent(foresteventrand) == 4 && root->getHour() > 8 && root->getHour() < 20 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "forest_hanters");
        makeActBtn("go_back2",act(10));
        if(root->getHour() >= root->getSunrise() && root->getHour() < root->getSunset())
        {
            if(root->getMonth() >= 6 && root->getMonth() <= 9 && root->vStatus(boletus) + root->vStatus(bilberry) < 10 && root->vEvent(edge_forestday3) != root->vStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
        }
        makeActBtn("deep_in_forest3",act(9));
    }
    if(action == "go_back2")
    {
        if (root->vEvent(goforest) >= getRandInt(1,60))
        {
            root->incTime(30);
            actionHandler("2");
        }
        else
        {
            root->vEvent(lost) = 2;
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "deep_in_forest3")
    {
        if(root->vEvent(goforest) >= getRandInt(1,100))
        {
            root->incTime(30);
            actionHandler("4");
        }
        else
        {
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "4")
    {
        root->vEvent(edge_forestday_current) = 4;
        if(root->vEvent(goforest) < 80)
            root->vEvent(goforest) += getRandInt(0,1);
        root->vEvent(lost) = 4;
        root->vEvent(lostrand) = getRandInt(1,120);
        root->vEvent(foresteventrand) = getRandInt(1,10);
        root->vStatus(dirty) = 0;
        root->vEvent(new_bilberry) = 0;
        root->vEvent(new_boletus) = 0;
        if(root->getSnow() == 0)
        {
            if(root->isDay())
            {
                root->setImage(media(23));
                root->setText(str(22));
            }
            else
            {
                root->setImage(media(24));
                root->setText(str(23));
            }
        }
        else
        {
            if(root->isDay())
            {
                root->setImage(media(25));
                root->setText(str(24));
            }
            else
            {
                root->setImage(media(26));
                root->setText(str(25));
            }
        }
        if(root->vEvent(goforest) < 80)
            root->addText(str(21));
        if(root->vEvent(foresteventrand) < 2 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "billberry");
        if(root->vEvent(foresteventrand) > 7 && root->getMonth() >= 6 && root->getMonth() <= 9 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "mushroom");
        if(root->vEvent(foresteventrand) == 5 && root->getHour() > 8 && root->getHour() < 20 && root->vEvent(foresteventday) != root->vStatus(daystart))
            root->startEvent(eGadForestEvent, "forest_hanters");
        makeActBtn("go_back3",act(10));
        if(root->getHour() >= root->getSunrise() && root->getHour() < root->getSunset())
        {
            if(root->getMonth() >= 6 && root->getMonth() <= 9 && root->vStatus(boletus) + root->vStatus(bilberry) < 10 && root->vEvent(edge_forestday4) != root->vStatus(daystart) + action.toInt())
                makeActBtn("search_bb",act(8));
        }
        makeActBtn("deep_in_forest4",act(9));
    }
    if(action == "go_back3")
    {
        if(root->vEvent(goforest) >= getRandInt(1,100))
        {
            root->incTime(30);
            actionHandler("3");
        }
        else
        {
            root->vEvent(lost) = 3;
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "deep_in_forest4")
    {
        if(root->vEvent(goforest) >= root->vEvent(lostrand) && (root->vEvent(goswamp) == 1 || root->getSnow() > 0))
        {
            root->changeLoc(lswamp,30);
        }
        else if(root->vEvent(goforest) >= root->vEvent(lostrand) && root->vEvent(goswamp) == 0)
        {
            root->changeLoc(lgadforestswamp,30);
        }
        else
        {
            root->startEvent(eGadForestEvent, "gadforest_lost_start");
        }
    }
    if(action == "picnic")
    {
        root->startEvent(eGadForestEvent,"picnic");
    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
    if(action == "bicycle")
    {
        root->startEvent(eBicycle,"forest");
    }
}

void Gadforest::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadforest");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadforest::actionHandler);
    root->addActions(btn);
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
