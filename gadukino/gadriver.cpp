#include "gadriver.h"
#include "../Functions.h"
#include "../nav/locationhandler.h"
#include "../menu/buttons.h"

Gadriver::Gadriver(LocationHandler *ptr): Location(ptr) {}

void Gadriver::show(QString arg)
{
    actionHandler("gadriver");
}

LocId Gadriver::getLocId()
{
    return lgadriver;
}

LocId Gadriver::getParId()
{
    return lgadukino;
}

LocId Gadriver::getLocIn()
{
    return lgadukino;
}

QString Gadriver::getLocName()
{
    return "Речка Змеявка";
}

bool Gadriver::isParent()
{
    return true;
}

void Gadriver::actionHandler(QString action)
{
    if(action == "gadriver")
    {
        int i = getRandInt(0,20);
        int month = getMonth();
        int sunWeather = getSunWeather();
        if(i > 10 && month >= 5 && month <= 9 && sunWeather >= 0)
            sVEvent(fishers,1);
        setImage(makeImage(media(0),isDay(),month));
        setDesc(str(0));
        if(gVEvent(fishers) == 1 && isDay())
            addText(str(1));
        if(i <= 5 && getHour() <= 8 && month <= 9 && gVQuest(miragopQW) >= 20)
            addText(str(2));
        if(getCloth(ClothType::Main) == nullptr)
            startEvent("gadukino_event", "gadriver_nude");
        if(gVEvent(mitkasextimes) == 20 && isDay() && month >=5 && month <= 9 && sunWeather >= 0 && getTemp() >= 20)
            startEvent("gadukino_event", "gadriver_gang");
        if(i < 5 && gVEvent(mirainriver) == 0 && gVEvent(mitkasextimes) >= 13 && getHour() > 8 && getHour() < 20 && gVSkill(domination) < 0 && gVEvent(guysriver) != getDay())
            startEvent("river_events", "guys_river");
        makeActBtn("gadbeach",act(0));
        makeActBtn("gadukino",act(1));
    }
    if(action == "gadukino")
    {
        sVEvent(mirainriver,0);
        changeLoc(lgadukino,10);
    }
    if(action == "gadbeach")
    {
        changeLoc(lgadbeach,5);
    }
    if(action == "mira_punish")
    {
        startEvent("river_events","mira_punish");
    }
    if(action == "fishers")
    {
        startEvent("river_events","fishers");
    }
}

void Gadriver::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadriver::actionHandler);
    addActBtn(btn);
}

QString Gadriver::str(int id)
{
    QString str[3];
    str[0] = "Небольшая деревенская речушка, протекающая совсем рядом от Гадюкино.";
    str[1] = "На берегу раскинули свои удочки местные <a href='fishers'>рыбаки</a>.";
    str[2] = "Прямо возле тропинки, ведущей к речке, стоит совершенно голая <a href='mira_punish'>Мира</a>, распятая между двумя деревьями...";
    return str[id];
}

QString Gadriver::act(int id)
{
    QString act[2];
    act[0] = "На пляж";
    act[1] = "В деревню";
    return act[id];
}

QString Gadriver::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/river/gadriver.jpg";
    return med[id];
}
