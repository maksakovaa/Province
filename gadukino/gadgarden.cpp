#include "gadgarden.h"
#include "../Functions.h"
#include "../menu/buttons.h"
Gadgarden::Gadgarden(LocationHandler *ptr): Location(ptr) {}

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
    clearActions();
    if(action == "garden")
    {
        sVEvent(grandma_ingadgarden, 0);
        sVEvent(grandpa_ingadgarden, 0);
        int month = getMonth();
        setImage(makeImage(media(0),isDay(),month));
        setDesc(str(0));
        if(getSnow() == 0)
            addText(str(1));
        if((month >= 6 && month <= 8 && gVJob(graze_cow) == 0) || (month >= 5 && month <= 9 && gVJob(graze_cow) > 0) )
            if(getSunWeather() >= 0 && getHour() > 7 && getHour() < 13)
            {
                sVEvent(grandma_ingadgarden, 1);
                addText(str(2));
            }
        if(getSunWeather() >= 0 && getHour() > 7 && getHour() < 13 && gVJob(graze_cow) == 0 && (month == 5 || month == 9))
        {
            sVEvent(grandpa_ingadgarden, 1);
            sVEvent(grandma_ingadgarden, 1);
            addText(str(3));
        }
        if(grandma_ingadgarden == 1 && gVEvent(grandmaknowsick) == 1)
        {
            startEvent(eGrandMa);
        }
        if(gVJob(workGarden) == 1)
            makeActBtn("work_garden", str(4));
        if(gVJob(waterGarden) == 1)
            makeActBtn("water_garden", str(7));
        if(gVJob(harvest_garden) == 1)
            makeActBtn("harvest_garden", str(9));
        makeActBtn("gaddvor", str(11));
        if(getCloth(ClothType::Main) == nullptr)
        {
            startEvent(eGrandParentEvents,"garden_nude");
        }
        connect(getTextPtr(), &QLabel::linkActivated, this, &Gadgarden::actionHandler);
    }
    if(action == "work_garden")
    {
        incTime(180);
        uVStatus(sweat, 1);
        sVJob(workGarden, 0);
        uVEvent(grandmahelp,3);
        uVQuest(grandmaQW,1);
        if(gVSkill(strenght) < 30)
            uVSkill(strenght,1);
        uVStatus(day_weight, -1);
        setImage(media(1));
        setDesc(str(5));
        makeActBtn("garden", str(6));
    }
    if(action == "water_garden")
    {
        uVStatus(sweat,1);
        incTime(60);
        sVJob(waterGarden, 0);
        uVEvent(grandmahelp, 1);
        uVQuest(grandmaQW,1);
        if(gVSkill(endurance) < 30)
            uVSkill(endurance,1);
        uVStatus(day_weight, -1);
        setImage(media(2));
        setDesc(str(8));
        makeActBtn("garden", str(6));
    }
    if(action == "harvest_garden")
    {
        incTime(180);
        uVStatus(sweat,1);
        sVJob(harvest_garden, 0);
        uVEvent(grandmahelp,3);
        uVQuest(grandmaQW,1);
        if(gVSkill(strenght) < 30)
            uVSkill(strenght,1);
        uVStatus(day_weight,-1);
        setImage(media(3));
        setDesc(str(10));
        makeActBtn("garden", str(6));
    }
    if(action == "gaddvor")
    {
        changeLoc(lgaddvor,5);
    }
    if(action == "strawberry")
    {
        setImage(media(4));
        setDesc(str(12));
        if((getMonth() == 6 || getMonth() == 7) && gVEvent(strawberriesday) != gVStatus(daystart))
        {
            makeActBtn("eatStrawberry", str(13));
        }
        if(gVJob(collect_strawberries) == 1)
        {
            makeActBtn("collect_strawberries", str(15));
        }
        makeActBtn("go_garden", str(17));
    }
    if(action == "eatStrawberry")
    {
        sVEvent(strawberriesday,gVStatus(daystart));
        incTime(30);
        uVStatus(mood,10);
        uVStatus(water,10);
        uVStatus(energy,5);
        sVStatus(cumLips,0);
        setImage(media(5));
        setDesc(str(14));
        makeActBtn("strawberry", str(6));
    }
    if(action == "collect_strawberries")
    {
        incTime(180);
        uVStatus(sweat,1);
        sVJob(collect_strawberries, 0);
        uVEvent(grandmahelp, 5);
        uVQuest(grandmaQW,1);
        if(gVSkill(agility) < 30)
            uVSkill(agility,1);
        uVStatus(day_weight,-1);
        if(isSkirt() && isPanties())
            setImage(media(6));
        else if(isSkirt() && !isPanties())
            setImage(media(7));
        else
            setImage(media(8));
        setDesc(str(16));
        makeActBtn("strawberry", str(6));
    }
    if(action == "go_garden")
    {
        incTime(5);
        actionHandler("garden");
    }
    if(action == "fruit_garden")
    {
        if(isDay())
            setImage(media(9));
        else
            setImage(media(10));
        setDesc(str(18));
        int month = getMonth();
        int sunWeather = getSunWeather();
        int hour = getHour();
        if(month >= 6 && month <= 8 && sunWeather >= 0 && hour > 7 && hour < 13 && getWeekNum() == 7 && gVJob(graze_cow) == 0)
            setDesc(str(19));
        if(month >= 7 && month <= 9 && gVEvent(fruitday) != gVStatus(daystart))
            makeActBtn("eatFruits", str(20));
        if(gVJob(fruit_collect) == 1)
            makeActBtn("fruit_collect", str(22));
        makeActBtn("go_garden", str(17));
    }
    if(action == "eatFruits")
    {
        sVEvent(fruitday, gVStatus(daystart));
        incTime(30);
        uVStatus(mood,10);
        uVStatus(water,5);
        uVStatus(energy,10);
        sVStatus(cumLips,0);
        setImage(media(11));
        setDesc(str(21));
        makeActBtn("fruit_garden", str(6));
    }
    if(action == "fruit_collect")
    {
        incTime(180);
        uVStatus(sweat,1);
        sVJob(fruit_collect, 0);
        uVEvent(grandmahelp, 5);
        uVQuest(grandmaQW,1);
        if(gVSkill(agility) < 30)
            uVSkill(agility,1);
        uVStatus(day_weight,-1);
        if(isSkirt() && isPanties())
            setImage(media(12));
        else if(isSkirt() && !isPanties())
            setImage(media(13));
        else
            setImage(media(14));
        setDesc(str(23));
        makeActBtn("fruit_garden", str(23));
    }
    if(action == "grandma")
    {
        startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        startEvent(eGrandPa);
    }
}

QString Gadgarden::str(int id)
{
    QString bab,ded;
    if(gVEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";
    if(gVEvent(grandpa_notalk) == 0)
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
    if(isDay() && (getMonth() == 6|| getMonth() == 7))
        med[4] += intQStr(1) + ".jpg";
    else if(isDay() && getMonth() != 6 && getMonth() != 7)
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
    addActBtn(btn);
}
