#include "gadriver.h"
#include "../../Functions.h"
#include "../../game.h"
#include "../../menu/buttons.h"

Gadriver::Gadriver(Game *ptr):  root(ptr) {}

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
        int month = root->getMonth();
        int sunWeather = root->getSunWeather();
        if(i > 10 && month >= 5 && month <= 9 && sunWeather >= 0)
            root->vEvent(fishers) = 1;
        root->setImage(makeImage(media(0),root->isDay(),month));
        root->setText(str(0));
        if(root->vEvent(fishers) == 1 && root->isDay())
            root->addText(str(1));
        if(i <= 5 && root->getHour() <= 8 && month <= 9 && root->vQuest(miragopQW) >= 20)
            root->addText(str(2));
        if(root->getCloth(ClothType::Main) == nullptr)
            root->startEvent(eGadukinoEvents, "gadriver_nude");
        if(root->vEvent(mitkasextimes) == 20 && root->isDay() && month >=5 && month <= 9 && sunWeather >= 0 && root->getTemp() >= 20)
            root->startEvent(eGadukinoEvents, "gadriver_gang");
        if(i < 5 && root->vEvent(mirainriver) == 0 && root->vEvent(mitkasextimes) >= 13 && root->getHour() > 8 && root->getHour() < 20 && root->vSkill(domination) < 0 && root->vEvent(guysriver) != root->getDay())
            root->startEvent(eRiverEvents, "guys_river");
        makeActBtn("gadbeach",act(0));
        makeActBtn("gadukino",act(1));
    }
    if(action == "gadukino")
    {
        root->vEvent(mirainriver) = 0;
        root->changeLoc(lgadukino,10);
    }
    if(action == "gadbeach")
    {
        root->changeLoc(lgadbeach,5);
    }
    if(action == "mira_punish")
    {
        root->startEvent(eRiverEvents,"mira_punish");
    }
    if(action == "fishers")
    {
        root->startEvent(eRiverEvents,"fishers");
    }
}

void Gadriver::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "gadriver");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadriver::actionHandler);
    root->addActions(btn);
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
