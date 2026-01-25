#include "swampspring.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"
#include "../../game.h"

SwampSpring::SwampSpring(Game* ptr): root(ptr) {}

void SwampSpring::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("swampspring");
    else
        actionHandler(arg);
}

LocId SwampSpring::getLocId()
{
    return lswampspring;
}

LocId SwampSpring::getParId()
{
    return lswampyard;
}

LocId SwampSpring::getLocIn()
{
    return lgadukino;
}

QString SwampSpring::getLocName()
{
    return "Родник";
}

bool SwampSpring::isParent()
{
    return true;
}

void SwampSpring::actionHandler(QString action)
{
    if(action == "swampspring")
    {
        root->setImage(makeImage(media(0),root->isDay(),root->getMonth()));
        root->setText(str(0));
        makeActBtn("drink_water",act(0));
        if(root->vEvent(bucket) < 10)
            makeActBtn("fill_bucket",act(2));
        makeActBtn("swamp_yard",act(3));
    }
    if(action == "drink_water")
    {
        root->incTime(5);
        if(root->vStatus(water) >= 20)
        {
            root->setImage(media(1));
            root->setText(str(1));
        }
        else
        {
            root->vStatus(water) +=20;
            root->vStatus(cumLips) = 0;
            root->vStatus(dirtylip) = 0;
            root->setImage(media(1));
            root->setText(str(2));
        }
        makeActBtn("swampspring",act(1));
    }
    if(action == "fill_bucket")
    {
        root->incTime(10);
        root->vEvent(bucket) += 10;
        root->setImage(media(2));
        root->setText(str(3));
        makeActBtn("swampspring",act(1));
    }
    if(action == "swamp_yard")
    {
        root->changeLoc(lswampyard,5);
    }
}

void SwampSpring::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"swampspring");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SwampSpring::actionHandler);
    root->addActions(btn);
}

QString SwampSpring::str(int id)
{
    QString str[20];
    str[0] = "Родник с чистой ключевой водой.";
    str[1] = "Вода в вас больше не лезет.";
    str[2] = "Вы с удовольствием напились родниковой воды.";
    str[3] = "Вы набрали воды в ведро.";
    return str[id];
}

QString SwampSpring::act(int id)
{
    QString act[4];
    act[0] = "Попить воды";
    act[1] = "Закончить";
    act[2] = "Набрать воды в ведро";
    act[3] = "Уйти";
    return act[id];
}

QString SwampSpring::media(int id)
{
    QString med[3];
    med[0] = "data/locations/gadukino/swamp/swampspring.jpg";
    med[1] = "data/actions/backwater/hands.jpg";
    med[2] = "data/locations/gadukino/swamp/vedro.jpg";
    return med[id];
}
