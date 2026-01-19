#include "gadroad.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
Gadroad::Gadroad(LocationHandler *ptr): Location(ptr) {}

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
        setImage(makeImage(media(0), isDay(), getMonth()));
        setDesc(str(0));
        makeActBtn("gadfield",act(0));
        makeActBtn("gadforest",act(1));
        ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
        if(ptr != nullptr && ptr->getClothGroup() == sportsSuit && getHour() >= 6 && getHour() < 21 && gVEvent(daybegskver) != gVStatus(daystart) && getSunWeather() >= 0)
        {
            if(gVSick(sick) > 0)
                addText(str(1));
            else
                makeActBtn("run_road",act(2));
        }
        if(ptr == nullptr || ptr->getClothGroup() < sundress)
            makeActBtn("backdoors",act(3));
        makeActBtn("gadukino",act(4));
    }
    if(action == "gadfield")
    {
        changeLoc(lgadfield,10);
    }
    if(action == "gadforest")
    {
        changeLoc(lgadforest,30);
    }
    if(action == "run_road")
    {
        incTime(60);
        uVStatus(day_weight,-1);
        uVSkill(runner,getRandInt(3,6));
        fnSport(2);
        if(gVSkill(speed) < 40)
            uVSkill(speed,1);
        else
            uVSkill(speed,getRandInt(0,1));
        if(gVSkill(endurance) < 20)
            uVSkill(endurance,1);
        sVEvent(daybegskver,gVStatus(daystart));
        if(getSnow() > 0)
            setImage(media(1));
        else if(getSnow() == 0 && (getMonth() < 5 || getMonth() > 9))
            setImage(media(2));
        else
        {
            int group = gVBody(bodyGroup);
            if(group > 1)
            {
                if(group == 2)
                    setImage(media(5));
                else
                    setImage(media(6));
            }
            else
            {
                if(gVSkill(strenght) + gVSkill(endurance) < 50)
                    setImage(media(4));
                else
                    setImage(media(3));
            }
            setDesc(str(2));
            makeActBtn("gadroad",act(5));
        }
    }
    if(action == "backdoors")
    {
        startEvent(eGadukinoEvents, "gadukino_back");
    }
    if(action == "gadukino")
    {
        changeLoc(lgadukino,20);
    }
}

void Gadroad::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"gadroad");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadroad::actionHandler);
    addActBtn(btn);
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
