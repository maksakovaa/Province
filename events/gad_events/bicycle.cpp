#include "bicycle.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

Bicycle::Bicycle(Game *ptr): root(ptr) {}

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
        root->setText(str(0));
        int hour = root->getHour();
        int month = root->getMonth();
        if(month >= 4 && month <= 10 && root->getSunWeather() >= 0)
        {
            if(hour >= 6 && hour <= 20 && root->vEvent(findvel) != root->vStatus(daystart))
                makeActBtn("drive_bicycle",act(1));
            if(root->vEvent(goforest) > 0)
                makeActBtn("drive_forest",act(2));
            if(root->vEvent(goswamp) == 1)
                makeActBtn("drive_swamp",act(3));
        }
        makeActBtn("gadsarai",act(0));
    }
    if(action == "drive_bicycle")
    {
        root->vEvent(findvel) = root->vStatus(daystart);
        root->incTime(60);
        root->vSkill(runner) += getRandInt(0,2);
        root->vSkill(speed) += getRandInt(0,2);
        root->vStatus(day_weight) -= 1;
        root->vStatus(mood) += 5;
        root->vStatus(sweat) += 2;
        if(root->vQuest(QWgets_bicycle_day) != root->vStatus(daystart))
        {
            root->vQuest(QWgets_bicycle) += 1;
            root->vQuest(QWgets_bicycle_day) = root->vStatus(daystart);
        }
        if(root->isNude())
        {
            root->vStatus(horny) += 20;
            root->setImage(media(1));
            root->setText(str(1));
            makeActBtn("gadsarai",act(4));
        }
        if(root->isSkirt())
        {
            if(getRandInt(0,100) > 70)
            {
                root->vStatus(horny) += 5;
                if(root->isPanties())
                {
                    root->setImage(media(2));
                    root->setText(str(2));
                }
                else
                {
                    root->setImage(media(3));
                    root->setText(str(3));
                }
                makeActBtn("gadsarai",act(4));
            }
            else
            {
                root->setImage(media(4));
                root->setText(str(4));
                makeActBtn("gadsarai",act(4));
            }
        }
        else
        {
            root->setImage(media(5));
            root->setText(str(4));
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
        root->vStatus(mood) += 5;
        root->vEvent(findvel) = 2;
        actionHandler("clothes_findvel");
        root->setText(str(5));
        makeActBtn("gadforest",act(5));
    }
    if(action == "gadforest")
    {
        root->changeLoc(lgadforest,0);
    }
    if(action == "drive_swamp")
    {
        root->incTime(75);
        root->vSkill(runner) += getRandInt(0,1);
        root->vSkill(speed) += getRandInt(0,1);
        root->vStatus(day_weight) -=1;
        root->vStatus(mood) +=5;
        root->vStatus(sweat) += 1;
        root->vEvent(findvel) = 3;
        actionHandler("clothes_findvel");
        root->setText(str(6));
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
        root->startEvent(eGameOver, "9");
    }
    if(action == "forest")
    {
        root->incTime(1);
        root->setImage(media(0));
        makeActBtn("go_gaddvor",act(6));
        if(root->vEvent(goswamp) > 0)
            makeActBtn("drive_swamp2",act(3));
         makeActBtn("gadforest",act(0));
    }
    if(action == "go_gaddvor")
    {
        if(!root->isNude() || (root->isNude() && root->vStatistics(exhibi) > 0))
        {
            root->vStatus(mood) +=5;
            root->vEvent(findvel) = 1;
            root->incTime(25);
            actionHandler("clothes_findvel");
            root->setText(str(7));
            makeActBtn("gaddvor",act(5));
        }
        else
        {
            root->setImage(media(6));
            root->setText(str(8));
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
        root->vStatus(mood) +=5;
        root->vEvent(findvel) = 3;
        actionHandler("clothes_findvel");
        root->setText(str(6));
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
        if(!root->isNude() || (root->isNude() && root->vStatistics(exhibi) > 0))
        {
            root->incTime(75);
            root->vSkill(runner) += getRandInt(0,1);
            root->vSkill(speed) += getRandInt(0,1);
            root->vStatus(day_weight) -= 1;
            root->vStatus(sweat) += 1;
            root->vStatus(mood) += 10;
            root->vEvent(findvel) = 1;
            root->vEvent(hanters) = 0;
            actionHandler("clothes_findvel");
            root->setText(str(7));
            if(root->isDay())
                makeActBtn("gaddvor",act(5));
            else
                makeActBtn("gameover",act(5));
        }
        else
        {
            root->addText(str(8));
            makeActBtn("swamp_yard",act(5));
        }
    }
    if(action == "drive_forest2")
    {
        root->incTime(50);
        root->vStatus(mood) += 5;
        root->vEvent(hanters) = 0;
        root->vEvent(findvel) = 2;
        actionHandler("clothes_findvel");
        root->setText(str(5));
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
    QActButton* btn = new QActButton(action, "bicycle");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Bicycle::actionHandler);
    root->addActions(btn);
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
