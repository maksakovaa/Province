#include "gadbeach.h"
#include "../Functions.h"
#include "../menu/buttons.h"
Gadbeach::Gadbeach(LocationHandler* ptr): Location(ptr) {}

void Gadbeach::show(QString arg)
{
    actionHandler("gadbeach");
}

LocId Gadbeach::getLocId()
{
    return lgadbeach;
}

LocId Gadbeach::getParId()
{
    return lgadriver;
}

LocId Gadbeach::getLocIn()
{
    return lgadukino;
}

QString Gadbeach::getLocName()
{
    return "Деревенский пляж";
}

bool Gadbeach::isParent()
{
    return true;
}

void Gadbeach::actionHandler(QString action)
{
    if(action == "gadbeach")
    {
        clearActions();
        if(gVEvent(mirainriver) == 1 && gVEvent(miratalkforest) < 3)
            sVEvent(lake_people, 2);
        else
            sVEvent(lake_people, 0);

        int i = getRandInt(0,10);
        setImage(makeImage(media(0),isDay(),getMonth()));
        setDesc(str(0));
        ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
        if(ptr == nullptr || ptr->getClothGroup() <= swimsuit)
            addText(str(1));
        if(gVEvent(mirainriver) == 1)
            addText(str(2));
        if(gVJob(horse_river) > 0)
            addText(str(3));
        if(getTemp() >= 20 && isDay())
        {
            if(gVEvent(mirainriver) == 0 && gVEvent(mitkasextimes) >= 13 && i == 0 && getSunWeather() >= 0 && gVEvent(guysriver) != getDay())
            {
                startEvent("river_events", "guys_beach");
            }
            ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
            if(ptr != nullptr && ptr->getClothGroup() != swimsuit)
                makeActBtn("wear_swimsuit",act(0));
            if(ptr != nullptr && ptr->getClothGroup() > 0)
                makeActBtn("undress_all", act(1));
            if(ptr == nullptr || ptr->getClothGroup() == swimsuit)
            {
                makeActBtn("swim30",act(2));
                if(getSunWeather() >= 0)
                {
                    if(getItemCount(iSunscreen) <= 0)
                        makeActBtn("sunbathe",act(3));
                    else
                        makeActBtn("useSunscreen",act(4));
                }
                //if reading['in_bag'] >= 0: act 'Читать '+func('zz_books','get_name',reading['in_bag']): gt 'zz_books','read_on_walk'
            }
        }
        if(ptr == nullptr || ptr->getClothGroup() <= swimsuit)
            makeActBtn("wearClothes",act(5));
        makeActBtn("exit",act(6));
        startEvent("river_events","mira_in_river");
    }
    if(action == "Miroslava")
    {
        startEvent("Miroslava");
    }
    if(action == "wear_swimsuit")
    {
        clearActions();
        undress();
    }
    if(action == "undress_all")
    {
        clearActions();
        undress(1);
    }
    if(action == "swim30")
    {
        clearActions();
        swim();
    }
    if(action == "sunbathe")
    {
        clearActions();
        sunbathe();
    }
    if(action == "useSunscreen")
    {
        cream();
    }
    if(action == "wearClothes")
    {
        clearActions();
        if(getCloth(ClothType::Main) == nullptr)
            getDressed(1);
        else
            getDressed(0);
    }
    if(action == "exit")
    {
        ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
        if((isCloth()) || (ptr == nullptr && gVSC(exhibi) > 0))
        {
            sVStatus(inriver,0);
            changeLoc(lgadriver,5);
        }
        else
        {
            addText(str(4));
        }
    }
    if(action == "horse_river")
        startEvent("river_event","horse_river");
}

void Gadbeach::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadbeach::actionHandler);
    addActBtn(btn);
}

QString Gadbeach::str(int id)
{
    QString str[6];
    str[0] = "Небольшой деревенский пляж, на котором можно худо-бедно позагорать и искупаться.";
    str[1] = "На берегу лежит ваша одежда.";
    str[2] = "На пляже вы видите <a href='Miroslava'>Миру</a>.";
    str[3] = "В реке стоит дедушкин конь <a href='horse_river'>Буян</a>.";
    str[4] = "<p style='color:red'>Вы не можете появиться в деревне в таком виде, нужно одеться.</p>";
    str[5] = "Вы снимаете свою одежду, и надеваете купальник. Теперь можно спокойно идти купаться и загорать.";
    return str[id];
}

QString Gadbeach::act(int id)
{
    QString act[8];
    act[0] = "Надеть купальник";
    act[1] = "Раздеться догола";
    act[2] = "Купаться полчаса";
    act[3] = "Загорать полчаса";
    act[4] = "Намазаться кремом и лечь загорать";
    act[5] = "Одетсься";
    act[6] = "Уйти";
    act[7] = "Назад";
    return act[id];
}

QString Gadbeach::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/river/gadbeach.jpg";
    return med[id];
}
