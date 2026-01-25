#include "gadbeach.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadbeach::Gadbeach(Game* ptr):  root(ptr) {}

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
        root->clearActions();
        if(root->vEvent(mirainriver) == 1 && root->vEvent(miratalkforest) < 3)
            root->vEvent(lake_people) = 2;
        else
            root->vEvent(lake_people) = 0;

        int i = getRandInt(0,10);
        root->setImage(makeImage(media(0),root->isDay(),root->getMonth()));
        root->setText(str(0));
        ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
        if(ptr == nullptr || ptr->getClothGroup() <= swimsuit)
            root->addText(str(1));
        if(root->vEvent(mirainriver) == 1)
            root->addText(str(2));
        if(root->vJob(horse_river) > 0)
            root->addText(str(3));
        if(root->getTemp() >= 20 && root->isDay())
        {
            if(root->vEvent(mirainriver) == 0 && root->vEvent(mitkasextimes) >= 13 && i == 0 && root->getSunWeather() >= 0 && root->vEvent(guysriver) != root->getDay())
            {
                root->startEvent(eRiverEvents, "guys_beach");
            }
            ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
            if(ptr != nullptr && ptr->getClothGroup() != swimsuit)
                makeActBtn("wear_swimsuit",act(0));
            if(ptr != nullptr && ptr->getClothGroup() > 0)
                makeActBtn("undress_all", act(1));
            if(ptr == nullptr || ptr->getClothGroup() == swimsuit)
            {
                makeActBtn("swim30",act(2));
                if(root->getSunWeather() >= 0)
                {
                    if(root->getItmCount(iSunscreen) <= 0)
                        makeActBtn("sunbathe",act(3));
                    else
                        makeActBtn("useSunscreen",act(4));
                }
                if(root->vEvent(book_in_bag) >= 0)
                    makeActBtn("read_book", act(8) + root->getBookName(root->vEvent(book_in_bag)));
            }
        }
        if(ptr == nullptr || ptr->getClothGroup() <= swimsuit)
            makeActBtn("wearClothes",act(5));
        makeActBtn("exit",act(6));
        root->startEvent(eRiverEvents,"mira_in_river");
    }
    if(action == "read_book")
    {
        root->readOnWalk();
    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
    if(action == "wear_swimsuit")
    {
        root->clearActions();
        root->undress();
    }
    if(action == "undress_all")
    {
        root->clearActions();
        root->undress(1);
    }
    if(action == "swim30")
    {
        root->clearActions();
        root->swim();
    }
    if(action == "sunbathe")
    {
        root->clearActions();
        root->sunbathe();
    }
    if(action == "useSunscreen")
    {
        root->cream();
    }
    if(action == "wearClothes")
    {
        root->clearActions();
        if(root->getCloth(ClothType::Main) == nullptr)
            root->getDressed(1);
        else
            root->getDressed(0);
    }
    if(action == "exit")
    {
        ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
        if((root->isCloth()) || (ptr == nullptr && root->vStatistics(exhibi) > 0))
        {
            root->vStatus(inriver) = 0;
            root->changeLoc(lgadriver,5);
        }
        else
        {
            root->addText(str(4));
        }
    }
    if(action == "horse_river")
        root->startEvent(eRiverEvents,"horse_river");
}

void Gadbeach::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "gadbeach");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadbeach::actionHandler);
    root->addActions(btn);
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
    QString act[9];
    act[0] = "Надеть купальник";
    act[1] = "Раздеться догола";
    act[2] = "Купаться полчаса";
    act[3] = "Загорать полчаса";
    act[4] = "Намазаться кремом и лечь загорать";
    act[5] = "Одетсься";
    act[6] = "Уйти";
    act[7] = "Назад";
    act[8] = "Читать ";
    return act[id];
}

QString Gadbeach::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/river/gadbeach.jpg";
    return med[id];
}
