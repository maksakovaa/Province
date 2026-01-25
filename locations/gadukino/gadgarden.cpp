#include "gadgarden.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadgarden::Gadgarden(Game *ptr): root(ptr) {}

void Gadgarden::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("garden");
    else
        actionHandler(arg);
}

LocId Gadgarden::getLocId()
{
    return lgadgarden;
}

LocId Gadgarden::getParId()
{
    return lgaddvor;
}

LocId Gadgarden::getLocIn()
{
    return lgadukino;
}

QString Gadgarden::getLocName()
{
    return "Огород";
}

bool Gadgarden::isParent()
{
    return true;
}

void Gadgarden::actionHandler(QString action)
{
    root->clearActions();
    if(action == "garden")
    {
        root->vEvent(grandma_ingadgarden) = 0;
        root->vEvent(grandpa_ingadgarden) = 0;
        int month = root->getMonth();
        root->setImage(makeImage(media(0),root->isDay(),month));
        root->setText(str(0));
        if(root->getSnow() == 0)
            root->addText(str(1));
        if((month >= 6 && month <= 8 && root->vJob(graze_cow) == 0) || (month >= 5 && month <= 9 && root->vJob(graze_cow) > 0) )
            if(root->getSunWeather() >= 0 && root->getHour() > 7 && root->getHour() < 13)
            {
                root->vEvent(grandma_ingadgarden) = 1;
                root->addText(str(2));
            }
        if(root->getSunWeather() >= 0 && root->getHour() > 7 && root->getHour() < 13 && root->vJob(graze_cow) == 0 && (month == 5 || month == 9))
        {
            root->vEvent(grandpa_ingadgarden) = 1;
            root->vEvent(grandma_ingadgarden) = 1;
            root->addText(str(3));
        }
        if(grandma_ingadgarden == 1 && root->vEvent(grandmaknowsick) == 1)
        {
            root->startEvent(eGrandMa);
        }
        if(root->vJob(workGarden) == 1)
            makeActBtn("work_garden", str(4));
        if(root->vJob(waterGarden) == 1)
            makeActBtn("water_garden", str(7));
        if(root->vJob(harvest_garden) == 1)
            makeActBtn("harvest_garden", str(9));
        makeActBtn("gaddvor", str(11));
        if(root->getCloth(ClothType::Main) == nullptr)
        {
            root->startEvent(eGrandParentEvents,"garden_nude");
        }
        connect(root->getTextPtr(), &QLabel::linkActivated, this, &Gadgarden::actionHandler);
    }
    if(action == "work_garden")
    {
        root->incTime(180);
        root->vStatus(sweat) += 1;
        root->vJob(workGarden) = 0;
        root->vEvent(grandmahelp) += 3;
        root->vQuest(grandmaQW) += 1;
        if(root->vSkill(strenght) < 30)
            root->vSkill(strenght) += 1;
        root->vStatus(day_weight) -= 1;
        root->setImage(media(1));
        root->setText(str(5));
        makeActBtn("garden", str(6));
    }
    if(action == "water_garden")
    {
        root->vStatus(sweat) += 1;
        root->incTime(60);
        root->vJob(waterGarden) = 0;
        root->vEvent(grandmahelp) += 1;
        root->vQuest(grandmaQW) += 1;
        if(root->vSkill(endurance) < 30)
            root->vSkill(endurance) += 1;
        root->vStatus(day_weight) -= 1;
        root->setImage(media(2));
        root->setText(str(8));
        makeActBtn("garden", str(6));
    }
    if(action == "harvest_garden")
    {
        root->incTime(180);
        root->vStatus(sweat) += 1;
        root->vJob(harvest_garden) = 0;
        root->vEvent(grandmahelp) += 3;
        root->vQuest(grandmaQW) += 1;
        if(root->vSkill(strenght) < 30)
            root->vSkill(strenght) += 1;
        root->vStatus(day_weight) -= 1;
        root->setImage(media(3));
        root->setText(str(10));
        makeActBtn("garden", str(6));
    }
    if(action == "gaddvor")
    {
        root->changeLoc(lgaddvor,5);
    }
    if(action == "strawberry")
    {
        root->setImage(media(4));
        root->setText(str(12));
        if((root->getMonth() == 6 || root->getMonth() == 7) && root->vEvent(strawberriesday) != root->vStatus(daystart))
        {
            makeActBtn("eatStrawberry", str(13));
        }
        if(root->vJob(collect_strawberries) == 1)
        {
            makeActBtn("collect_strawberries", str(15));
        }
        makeActBtn("go_garden", str(17));
    }
    if(action == "eatStrawberry")
    {
        root->vEvent(strawberriesday) = root->vStatus(daystart);
        root->incTime(30);
        root->vStatus(mood) += 10;
        root->vStatus(water) += 10;
        root->vStatus(energy) += 5;
        root->vStatus(cumLips) = 0;
        root->setImage(media(5));
        root->setText(str(14));
        makeActBtn("strawberry", str(6));
    }
    if(action == "collect_strawberries")
    {
        root->incTime(180);
        root->vStatus(sweat) += 1;
        root->vJob(collect_strawberries) = 0;
        root->vEvent(grandmahelp) += 5;
        root->vQuest(grandmaQW) += 1;
        if(root->vSkill(agility) < 30)
            root->vSkill(agility) += 1;
        root->vStatus(day_weight) -= 1;
        if(root->isSkirt() && root->isPanties())
            root->setImage(media(6));
        else if(root->isSkirt() && !root->isPanties())
            root->setImage(media(7));
        else
            root->setImage(media(8));
        root->setText(str(16));
        makeActBtn("strawberry", str(6));
    }
    if(action == "go_garden")
    {
        root->incTime(5);
        actionHandler("garden");
    }
    if(action == "fruit_garden")
    {
        if(root->isDay())
            root->setImage(media(9));
        else
            root->setImage(media(10));
        root->setText(str(18));
        int month = root->getMonth();
        int sunWeather = root->getSunWeather();
        int hour = root->getHour();
        if(month >= 6 && month <= 8 && sunWeather >= 0 && hour > 7 && hour < 13 && root->getWeek() == 7 && root->vJob(graze_cow) == 0)
            root->setText(str(19));
        if(month >= 7 && month <= 9 && root->vEvent(fruitday) != root->vStatus(daystart))
            makeActBtn("eatFruits", str(20));
        if(root->vJob(fruit_collect) == 1)
            makeActBtn("fruit_collect", str(22));
        makeActBtn("go_garden", str(17));
    }
    if(action == "eatFruits")
    {
        root->vEvent(fruitday) = root->vStatus(daystart);
        root->incTime(30);
        root->vStatus(mood) += 10;
        root->vStatus(water) += 5;
        root->vStatus(energy) += 10;
        root->vStatus(cumLips) = 0;
        root->setImage(media(11));
        root->setText(str(21));
        makeActBtn("fruit_garden", str(6));
    }
    if(action == "fruit_collect")
    {
        root->incTime(180);
        root->vStatus(sweat) += 1;
        root->vJob(fruit_collect) = 0;
        root->vEvent(grandmahelp) += 5;
        root->vQuest(grandmaQW) += 1;
        if(root->vSkill(agility) < 30)
            root->vSkill(agility) += 1;
        root->vStatus(day_weight) -= 1;
        if(root->isSkirt() && root->isPanties())
            root->setImage(media(12));
        else if(root->isSkirt() && !root->isPanties())
            root->setImage(media(13));
        else
            root->setImage(media(14));
        root->setText(str(23));
        makeActBtn("fruit_garden", str(23));
    }
    if(action == "grandma")
    {
        root->startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        root->startEvent(eGrandPa);
    }
}

QString Gadgarden::str(int id)
{
    QString bab,ded;
    if(root->vEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";
    if(root->vEvent(grandpa_notalk) == 0)
        ded = "<a href='grandpa'>дедушка</a>";
    else
        ded = "дедушка";
    QString str[24];
    str[0] = "Большой огород на котором растет практически все.";
    str[1] = "Немного в стороне есть <a href='strawberry'>клубничная делянка</a> и <a href='fruit_garden'>фруктовый сад</a>.";
    str[2] = "На огороде ковыряется в грядках ваша " + bab + ".";
    str[3] = "На огороде работают ваши " + ded + " и " + bab + ".";
    str[4] = "Работать на огороде";
    str[5] = "Вы некоторое время выполняете различную работу на огороде.";
    str[6] = "Закончить";
    str[7] = "Поливать огород";
    str[8] = "Вы в течение часа поливаете грядки на огороде.";
    str[9] = "Собирать урожай";
    str[10] = "Вы в течение нескольких часов собираете овощи на огороде.";
    str[11] = "Выйти во двор";
    str[12] = "Клубничная делянка на которой, в сезон, можно вырастить немного клубники.";
    str[13] = "Поесть клубники";
    str[14] = "Вы некоторое время бродите по делянке собирая спелые ягоды тут же кидая их в рот.";
    str[15] = "Собирать клубнику";
    str[16] = "Вы бродите по делянке собирая спелые ягоды в корзину.";
    str[17] = "Уйти";
    str[18] = "Фруктовый сад в котором растут яблоки и груши.";
    str[19] = "Ваш " + ded + " косит в саду траву.";
    str[20] = "Поесть фруктов";
    str[21] = "Вы некоторое время бродите по саду жуя спелые фрукты.";
    str[22] = "Собирать фрукты";
    str[23] = "Вы собираете в саду спелые фрукты.";
    return str[id];
}

QString Gadgarden::media(int id)
{
    QString med[15];
    med[0] = "data/locations/gadukino/gaddvor/garden.jpg";
    med[1] = "data/actions/work_garden/work_garden" + intQStr(getRandInt(1,5)) + ".jpg";
    med[2] = "data/actions/work_garden/water_garden.jpg";
    med[3] = "data/actions/work_garden/harvest_garden" + intQStr(getRandInt(1,5)) + ".jpg";
    med[4] = "data/locations/gadukino/gaddvor/strawberry";
    if(root->isDay() && (root->getMonth() == 6|| root->getMonth() == 7))
        med[4] += intQStr(1) + ".jpg";
    else if(root->isDay() && root->getMonth() != 6 && root->getMonth() != 7)
        med[4] += intQStr(2) + ".jpg";
    else
        med[4] += "_night.jpg";
    med[5] = "data/actions/eat/eat_strawberries.jpg";
    med[6] = "data/actions/work_garden/collect_strawberries_ski.jpg";
    med[7] = "data/actions/work_garden/collect_strawberries_tanga.jpg";
    med[8] = "data/actions/work_garden/collect_strawberries.jpg";
    med[9] = "data/locations/gadukino/gaddvor/fruit_garden.jpg";
    med[10] = "data/locations/gadukino/gaddvor/fruit_garden_night.jpg";
    med[11] = "data/actions/eat/eat_fruit.jpg";
    med[12] = "data/actions/work_garden/fruit_collect_ski.jpg";
    med[13] = "data/actions/work_garden/fruit_collect_tanga.jpg";
    med[14] = "data/actions/work_garden/fruit_collect.jpg";
    return med[id];
}

void Gadgarden::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "gadgarden");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadgarden::actionHandler);
    root->addActions(btn);
}
