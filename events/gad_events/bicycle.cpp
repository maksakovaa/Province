#include "bicycle.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

Bicycle::Bicycle(EventHandler *ptr): root(ptr) {}

void Bicycle::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("sarai");
    else
        actionHandler(arg);
}

void Bicycle::actionHandler(QString action)
{
    if(action == "sarai")
    {
        root->incTime(1);
        root->setImage(media(0));
        root->setDesc(str(0));
        int hour = root->getHour();
        int month = root->getMonth();
        if(month >= 4 && month <= 10 && root->getSunWeather() >= 0)
        {
            if(hour >= 6 && hour <= 20 && root->gVEvent(findvel) != root->vStatus(daystart))
                makeActBtn("drive_bicycle",act(1));
            if(root->gVEvent(goforest) > 0)
                makeActBtn("drive_forest",act(2));
            if(root->gVEvent(goswamp) == 1)
                makeActBtn("drive_swamp",act(3));
        }
        makeActBtn("gadsarai",act(0));
    }
    if(action == "drive_bicycle")
    {
        root->sVEvent(findvel,root->vStatus(daystart));
        root->incTime(60);
        root->uVSkill(runner,getRandInt(0,2));
        root->uVSkill(speed,getRandInt(0,2));
        root->uVStatus(day_weight,-1);
        root->uVStatus(mood,5);
        root->uVStatus(sweat,2);
        if(root->gVQuest(QWgets_bicycle_day) != root->vStatus(daystart))
        {
            root->uVQuest(QWgets_bicycle,1);
            root->sVQuest(QWgets_bicycle_day,root->vStatus(daystart));
        }
        if(root->isNude())
        {
            root->uVStatus(horny,20);
            root->setImage(media(1));
            root->setDesc(str(1));
            makeActBtn("gadsarai",act(4));
        }
        if(root->isSkirt())
        {
            if(getRandInt(0,100) > 70)
            {
                root->uVStatus(horny,5);
                if(root->isPanties())
                {
                    root->setImage(media(2));
                    root->setDesc(str(2));
                }
                else
                {
                    root->setImage(media(3));
                    root->setDesc(str(3));
                }
                makeActBtn("gadsarai",act(4));
            }
            else
            {
                root->setImage(media(4));
                root->setDesc(str(4));
                makeActBtn("gadsarai",act(4));
            }
        }
        else
        {
            root->setImage(media(5));
            root->setDesc(str(4));
            makeActBtn("gadsarai",act(4));
        }
    }
    if(action == "gadsarai")
    {
        root->changeLoc(lgadsarai,0);
    }
    if(action == "drive_forest")
    {
        root->incTime(25);
        root->uVStatus(mood,5);
        root->sVEvent(findvel,2);
        actionHandler("clothes_findvel");
        root->setDesc(str(5));
        makeActBtn("gadforest",act(5));
    }
    if(action == "gadforest")
    {
        root->changeLoc(lgadforest,0);
    }
    if(action == "drive_swamp")
    {
        root->incTime(75);
        root->uVSkill(runner,getRandInt(0,1));
        root->uVSkill(speed,getRandInt(0,1));
        root->uVStatus(day_weight,-1);
        root->uVStatus(mood,5);
        root->uVStatus(sweat,1);
        root->sVEvent(findvel,3);
        actionHandler("clothes_findvel");
        root->setDesc(str(6));
        if(root->isDay())
            makeActBtn("swamp_yard",act(5));
        else
            makeActBtn("gameover",act(5));
    }
    if(action == "swamp_yard")
    {
        root->changeLoc(lswampyard,0);
    }
    if(action == "gameover")
    {
        root->eventStart("gameover", "9");
    }
    if(action == "forest")
    {
        root->incTime(1);
        root->setImage(media(0));
        makeActBtn("go_gaddvor",act(6));
        if(root->gVEvent(goswamp) > 0)
            makeActBtn("drive_swamp2",act(3));
         makeActBtn("gadforest",act(0));
    }
    if(action == "go_gaddvor")
    {
        if(!root->isNude() || (root->isNude() && root->vSC(exhibi) > 0))
        {
            root->uVStatus(mood,5);
            root->sVEvent(findvel,1);
            root->incTime(25);
            actionHandler("clothes_findvel");
            root->setDesc(str(7));
            makeActBtn("gaddvor",act(5));
        }
        else
        {
            root->setImage(media(6));
            root->setDesc(str(8));
            makeActBtn("gadforest",act(5));
        }
    }
    if(action == "gaddvor")
    {
        root->changeLoc(lgaddvor);
    }
    if(action == "drive_swamp2")
    {
        root->incTime(50);
        root->uVStatus(mood,5);
        root->sVEvent(findvel,3);
        actionHandler("clothes_findvel");
        root->setDesc(str(6));
        if(root->isDay())
            makeActBtn("swamp_yard",act(5));
        else
            makeActBtn("gameover",act(5));
    }
    if(action == "swamp")
    {
        root->incTime(1);
        root->setImage(media(0));
        makeActBtn("go_gaddvor2",act(6));
        makeActBtn("drive_forest2",act(2));
        makeActBtn("swamp_yard",act(0));
    }
    if(action == "go_gaddvor2")
    {
        if(!root->isNude() || (root->isNude() && root->vSC(exhibi) > 0))
        {
            root->incTime(75);
            root->uVSkill(runner,getRandInt(0,1));
            root->uVSkill(speed,getRandInt(0,1));
            root->uVStatus(day_weight,-1);
            root->uVStatus(sweat,1);
            root->uVStatus(mood,10);
            root->sVEvent(findvel,1);
            root->sVEvent(hanters,0);
            actionHandler("clothes_findvel");
            root->setDesc(str(7));
            if(root->isDay())
                makeActBtn("gaddvor",act(5));
            else
                makeActBtn("gameover",act(5));
        }
        else
        {
            root->addDesc(str(8));
            makeActBtn("swamp_yard",act(5));
        }
    }
    if(action == "drive_forest2")
    {
        root->incTime(50);
        root->uVStatus(mood,5);
        root->sVEvent(hanters,0);
        root->sVEvent(findvel,2);
        actionHandler("clothes_findvel");
        root->setDesc(str(5));
        if(root->isDay())
            makeActBtn("gadforest",act(5));
        else
            makeActBtn("gameover",act(5));
    }
    if(action == "clothes_findvel")
    {
        root->setImage(media(7));
    }
}

void Bicycle::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Bicycle::actionHandler);
    root->addActBtn(btn);
}

QString Bicycle::str(int id)
{
    QString str[20];
    str[0] = "Старенький велосипед. Но с виду он в исправном состоянии, так что ездить можно.";
    str[1] = "Вы катаетесь голышем, избегая людных мест и ликуя от своей смелости. Трудно сказать, чего в вас больше: страха или желания быть замеченой.";
    str[2] = "Во время поездки у вас несколько раз задирается юбка, открывая прохожим вид на ваши трусы и попу";
    str[3] = "Во время поездки у вас несколько раз задирается юбка, открывая прохожим вид на вашу ничем не прикрытую попу";
    str[4] = "Вы катаетесь на велосипеде, наслаждаясь окружающей вас природой.";
    str[5] = "Вы сели на велосипед и отправились в лес.";
    str[6] = "Вы сели на велосипед и отправились на болото.";
    str[7] = "Вы сели на велосипед и отправились в деревню.";
    str[8] = "Вы не можете появиться в таком виде в деревне.";
    str[9] = "";
    return str[id];
}

QString Bicycle::act(int id)
{
    QString act[10];
    act[0] = "Поставить велосипед";
    act[1] = "Кататься на велосипеде";
    act[2] = "Ехать в лес";
    act[3] = "Ехать на болото";
    act[4] = "Закончить поездку";
    act[5] = "Далее";
    act[6] = "Ехать в деревню";
    return act[id];
}

QString Bicycle::media(int id)
{
    QString med[10];
    med[0] = "data/actions/transport/bicycle/findvel.jpg";
    med[1] = "data/actions/transport/bicycle/bike_nude.jpg";
    med[2] = "data/actions/transport/bicycle/bike_tanga_1.jpg";
    med[3] = "data/actions/transport/bicycle/bike_tanga_2.jpg";
    med[4] = "data/actions/transport/bicycle/bike_2.jpg";
    med[5] = "data/actions/transport/bicycle/bike.jpg";
    med[6] = "data/actions/transport/bicycle/findvel_nude.jpg";
    med[7] = "data/actions/transport/bicycle/bike";
    if(root->isNude())
        med[7] += "_nude";
    if(root->isSkirt())
        med[7] += "_2";
    med[7] += ".jpg";
    return med[id];
}
