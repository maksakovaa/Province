#include "gadroad.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadroad::Gadroad(Game *ptr): root(ptr) {}

void Gadroad::show(QString arg)
{
    actionHandler("gadroad");
}

LocId Gadroad::getLocId()
{
    return lgadroad;
}

LocId Gadroad::getParId()
{
    return lgadukino;
}

LocId Gadroad::getLocIn()
{
    return lgadukino;
}

QString Gadroad::getLocName()
{
    return "Дорога к лесу";
}

bool Gadroad::isParent()
{
    return true;
}

void Gadroad::actionHandler(QString action)
{
    if(action == "gadroad")
    {
        root->setImage(makeImage(media(0), root->isDay(), root->getMonth()));
        root->setText(str(0));
        makeActBtn("gadfield",act(0));
        makeActBtn("gadforest",act(1));
        ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
        if(ptr != nullptr && ptr->getClothGroup() == sportsSuit && root->getHour() >= 6 && root->getHour() < 21 && root->vEvent(daybegskver) != root->vStatus(daystart) && root->getSunWeather() >= 0)
        {
            if(root->vSick(sick) > 0)
                root->addText(str(1));
            else
                makeActBtn("run_road",act(2));
        }
        if(ptr == nullptr || ptr->getClothGroup() < sundress)
            makeActBtn("backdoors",act(3));
        makeActBtn("gadukino",act(4));
    }
    if(action == "gadfield")
    {
        root->changeLoc(lgadfield,10);
    }
    if(action == "gadforest")
    {
        root->changeLoc(lgadforest,30);
    }
    if(action == "run_road")
    {
        root->incTime(60);
        root->vStatus(day_weight) -= 1;
        root->vSkill(runner) += getRandInt(3,6);
        root->fnSport(2);
        if(root->vSkill(speed) < 40)
            root->vSkill(speed) += 1;
        else
            root->vSkill(speed) += getRandInt(0,1);
        if(root->vSkill(endurance) < 20)
            root->vSkill(endurance) += 1;
        root->vEvent(daybegskver) = root->vStatus(daystart);
        if(root->getSnow() > 0)
            root->setImage(media(1));
        else if(root->getSnow() == 0 && (root->getMonth() < 5 || root->getMonth() > 9))
            root->setImage(media(2));
        else
        {
            int group = root->vBody(bodyGroup);
            if(group > 1)
            {
                if(group == 2)
                    root->setImage(media(5));
                else
                    root->setImage(media(6));
            }
            else
            {
                if(root->vSkill(strenght) + root->vSkill(endurance) < 50)
                    root->setImage(media(4));
                else
                    root->setImage(media(3));
            }
            root->setText(str(2));
            makeActBtn("gadroad",act(5));
        }
    }
    if(action == "backdoors")
    {
        root->startEvent(eGadukinoEvents, "gadukino_back");
    }
    if(action == "gadukino")
    {
        root->changeLoc(lgadukino,20);
    }
}

void Gadroad::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"gadroad");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadroad::actionHandler);
    root->addActions(btn);
}

QString Gadroad::str(int id)
{
    QString str[3];
    str[0] = "Обыкновенная сельская дорога идущая через поле к лесу.";
    str[1] = "Вы болеете, поэтому заниматься физическими упражнениями совсем не хочется.";
    str[2] = "Вы в течение часа бегали по дороге.";
    return str[id];
}

QString Gadroad::act(int id)
{
    QString act[6];
    act[0] = "Идти на поле";
    act[1] = "Идти в лес";
    act[2] = "Бегать по дороге в течении часа";
    act[3] = "Пробраться в деревню огородами";
    act[4] = "Идти в деревню";
    act[5] = "Далее";
    return act[id];
}

QString Gadroad::media(int id)
{
    QString med[7];
    med[0] = "data/locations/gadukino/gadroad/gadroad.jpg";
    med[1] = "data/locations/gadukino/gadroad/gadbeg4.jpg";
    med[2] = "data/locations/gadukino/gadroad/gadbeg3.jpg";
    med[3] = "data/locations/gadukino/gadroad/gadbeg1.jpg";
    med[4] = "data/locations/gadukino/gadroad/gadbeg2.jpg";
    med[5] = "data/locations/gadukino/gadroad/gadbeg5.jpg";
    med[6] = "data/locations/gadukino/gadroad/gadbeg6.jpg";
    return med[id];
}
