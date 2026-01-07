#include "gadforestlost.h"
#include "../eventhandler.h"
#include "../../menu/qactbutton.h"
#include "../../Functions.h"

GadforestLost::GadforestLost(EventHandler* ptr): root(ptr) {}

void GadforestLost::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("main");
    else
        actionHandler(arg);
}

void GadforestLost::actionHandler(QString action)
{
    root->clearActions();
    if(action == "main")
    {
        if(root->getSnow() == 0)
        {
            if(root->isDay())
            {
                root->setImage(media(0));
                root->setDesc(str(0));
            }
            else
            {
                root->setImage(media(1));
                root->setDesc(str(1));
            }
        }
        else
        {
            if(root->isDay())
            {
                root->setImage(media(2));
                root->setDesc(str(2));
            }
            else
            {
                root->setImage(media(3));
                root->setDesc(str(3));
            }
        }
        if(root->gVEvent(lost) >= getRandInt(1,5) && !root->isDay())
            root->eventStart("gadforest_event","lost");
        if(root->gVEvent(lost) > 1 && getRandInt(1,10) == 1 && root->isDay())
        {
            root->sVEvent(forest_lost,1);
            root->eventStart("gadforest_event","forest_hanters");
        }
        makeActBtn("search_path",act(0));

    }
    if(action == "finish")
    {
        root->uVStatus(mood,20);
        root->setImage(media(4));
        root->setDesc(str(4));
        makeActBtn("get_out",act(3));
    }
    if(action == "search_path")
    {
        root->incTime(getRandInt(50,70));
        root->uVStatus(mood,-5);
        root->uVEvent(goforest,getRandInt(0,1));
        if(root->isNude())
            root->setImage(media(5));
        else if(root->isSkirt())
            root->setImage(media(6));
        else
            root->setImage(media(7));
        makeActBtn("search_next",act(1));
        makeActBtn("relax",act(2));
    }
    if(action == "search_next")
    {
        int tmp = getRandInt(1,40*root->gVEvent(lost));
        if(root->gVEvent(goforest) > tmp)
            actionHandler("finish");
        else
        {
            if(root->gVEvent(lost) == 4 && getRandInt(1,10) > 7)
                root->changeLoc(lgadforestswamp);
            else
                actionHandler("main");
        }
    }
    if(action == "relax")
    {
        root->eventStart("gadforestrelax");
    }
    if(action == "get_out")
    {
        root->incTime(15);
        int tmp = getRandInt(1,root->gVEvent(lost)*3);
        if(tmp == 1)
            root->changeLoc(lgadforest,0,"1");
        if(tmp == 2)
            root->changeLoc(lgadfield,0,"field");
        if(tmp == 3)
            root->changeLoc(lgadroad,0);
        if(tmp == 4)
            root->changeLoc(lgadriver,0);
        if(tmp == 5)
            root->changeLoc(lgadbeach,0);
        if(tmp == 6)
            root->changeLoc(lmeadow,0);
        if(tmp == 7)
            root->changeLoc(lroad,0,"main2");
        if(tmp == 8 || tmp == 9)
            root->changeLoc(lroad,0,"3");
        if(tmp >= 10)
        {
            if(root->gVEvent(goswamp) == 0 && root->getSnow() <= 0)
                root->changeLoc(lgadforestswamp,0,"1");
            else
                root->changeLoc(lswamp,0);
        }
    }
}

void GadforestLost::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadforestLost::actionHandler);
    root->addActBtn(btn);
}

QString GadforestLost::str(int id)
{
    QString str[20];
    str[0] = "Вы заблудились в лесу. Вокруг незнакомые места и вам не до красот природы.";
    str[1] = "Вы заблудились в лесу. Ночью от этого становится ещё страшнее.";
    str[2] = "Вы заблудились в лесу. Вокруг незнакомые места и вам не до красот природы.";
    str[3] = "Вы заблудились в лесу. Ночью от этого становится ещё страшнее.";
    str[4] = "Вы присматриваетесь и понимаете, что видите обжитые места места, и с радостью устремляетесь вперед.";
    return str[id];
}

QString GadforestLost::act(int id)
{
    QString act[20];
    act[0] = "Искать дорогу";
    act[1] = "Искать дорогу дальше";
    act[2] = "Сесть передохнуть";
    act[3] = "Выбежать из леса";
    return act[id];
}

QString GadforestLost::media(int id)
{
    QString med[10];
    med[0] = "data/locations/gadukino/forest/gadforestlost0." + intQStr(getRandInt(1,6)) + ".jpg";
    med[1] = "data/locations/gadukino/forest/gadforestlost_night0." + intQStr(getRandInt(1,4)) + ".jpg";
    med[2] = "data/locations/gadukino/forest/gadforestlost_winter0." + intQStr(getRandInt(1,5)) + ".jpg";
    med[3] = "data/locations/gadukino/forest/gadforestlost_winter_night0." + intQStr(getRandInt(1,4)) + ".jpg";
    med[4] = "data/locations/gadukino/forest/gadjoy.jpg";
    med[5] = "data/locations/gadukino/forest/gadforestsearch_nude0." + intQStr(getRandInt(1,4)) + ".jpg";
    med[6] = "data/locations/gadukino/forest/gadforestsearch_ski0." + intQStr(getRandInt(1,4)) + ".jpg";
    med[7] = "data/locations/gadukino/forest/gadforestsearch0." + intQStr(getRandInt(1,4)) + ".jpg";
    return med[id];
}
