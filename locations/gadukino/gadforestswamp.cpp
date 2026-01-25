#include "gadforestswamp.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"
#include "../../game.h"
GadForestSwamp::GadForestSwamp(Game *ptr): root(ptr) {}

void GadForestSwamp::show(QString arg)
{
    actionHandler(arg);
}

LocId GadForestSwamp::getLocId()
{
    return lgadforestswamp;
}

LocId GadForestSwamp::getParId()
{
    return lgadforest;
}

LocId GadForestSwamp::getLocIn()
{
    return lgadukino;
}

QString GadForestSwamp::getLocName()
{
    return "Болото";
}

bool GadForestSwamp::isParent()
{
    return true;
}

void GadForestSwamp::actionHandler(QString action)
{
    if(action == "1")
    {
        makeImage(media(0),root->isDay(),root->getMonth());
        root->setText(str(0));
        makeActBtn("gadforestlost",act(0));
        makeActBtn("go_swamp",act(1));
    }
    if(action == "2")
    {
        root->vBody(hairStatus) = 0;
        if(root->vBody(makeup) > 1)
        {
            root->vBody(makeup) = 0;
            root->vStatus(vidageday)-=1;
        }
        if(root->vStatus(dirtyClothes) == 0 && root->isCloth())
        {
            root->decreaseClothCond(10);
            root->vStatus(dirtyClothes) = 1;
        }
        root->setImage(media(1));
        root->setText(str(2));
        makeActBtn("call_help",act(3));
        makeActBtn("try_to_forest",act(6));
        makeActBtn("try_to_swamp",act(8));
    }
    if(action == "gadforestlost")
    {
        root->startEvent(eGadForestLost,"main");
    }
    if(action == "go_swamp")
    {
        root->incTime(10);
        root->vStatus(sweat) += 1;
        if(root->isCloth())
        {
            if(!root->isSkirt())
                root->setImage(media(2));
            else
                root->setImage(media(3));
        }
        else
            root->setImage(media(4));
        root->setText(str(1));
        makeActBtn("go_swamp2",act(2));
    }
    if(action == "go_swamp2")
    {
        int i = getRandInt(1,100);
        if(root->vSkill(strenght) + root->vSkill(agility) > i)
        {
            root->changeLoc(lswampyard,0);
        }
        else if(root->vSkill(strenght) + root->vSkill(agility) < i)
        {
            root->startEvent(eGameOver,"10");
        }
        else
        {
            actionHandler("2");
        }
    }
    if(action == "call_help")
    {
        root->incTime(10);
        if(root->vStatus(sweat) < 10)
            root->vStatus(sweat) += 1;
        root->setImage(media(5));
        root->setText(str(3));
        makeActBtn("wait",act(4));
    }
    if(action == "wait")
    {
        root->incTime(10);
        int y = 0;
        if(root->getWeek() > 5 || root->getWeek() == 0)
            y = 3;
        else
            y = 5;
        if(getRandInt(1, y) == 1)
        {
            root->vEvent(hanters) =1;
            root->vEvent(hantershelp) = 1;
            root->setImage(media(6));
            root->setText(str(4));
            makeActBtn("swamp_yard",act(5));
        }
        else
        {
            root->setImage(media(1));
            root->setText(str(5));
            makeActBtn("2",act(5));
        }
    }
    if(action == "swamp_yard")
    {
        root->changeLoc(lswampyard,0);
    }
    if(action == "try_to_forest")
    {
        root->incTime(10);
        root->vSkill(strenght) += 1;
        root->vSkill(agility) += 1;
        if(root->vStatus(sweat) < 10)
            root->vStatus(sweat) += 3;
        swampClothes();
        root->setText(str(6));
        makeActBtn("walk",act(7));
    }
    if(action == "walk")
    {
        int i = getRandInt(1,100);
        if(root->vSkill(strenght) + root->vSkill(agility) > i)
        {
            actionHandler("1");
        }
        else if(root->vSkill(strenght) + root->vSkill(agility) < i)
        {
            root->startEvent(eGameOver,"10");
        }
        else
        {
            actionHandler("2");
        }
    }
    if(action == "try_to_swamp")
    {
        root->incTime(10);
        root->vSkill(strenght) += 1;
        root->vSkill(agility) += 1;
        if(root->vStatus(sweat) < 10)
            root->vStatus(sweat) += 3;
        swampClothes();
        root->setText(str(7));
        makeActBtn("walk2",act(7));
    }
    if(action == "walk2")
    {
        int i = getRandInt(1,100);
        if(root->vSkill(strenght) + root->vSkill(agility) > i)
        {
            root->changeLoc(lswampyard,0);
        }
        else if(root->vSkill(strenght) + root->vSkill(agility) < i && i <= 30)
        {
            root->startEvent(eGameOver,"10");
        }
        else
        {
            actionHandler("2");
        }
    }
}

void GadForestSwamp::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadforestswamp");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadForestSwamp::actionHandler);
    root->addActions(btn);
}

QString GadForestSwamp::str(int id)
{
    QString str[8];
    str[0] = "Вы вышли к болоту, за ним виднеется какая-то избушка. Можно вернуться назад в лес или попробовать пройти к ней, но хватит ли вам сил и ловкости преодолеть эту грязь?";
    str[1] = "Вы вошли в болото и почувствовали, что ваши ноги начинает засасывать в грязь...";
    str[2] = "Вы застряли посреди болота. \"Во попала!\", - в панике думаете вы, - \"Что же делать?\".";
    str[3] = "Вы совершенно выбились из сил и стали кричать и звать на помощь, вдруг в домике есть люди...";
    str[4] = "Вы услышали мужские голоса и стали кричать громче. Голоса раздавались все ближе и вот наконец чьи-то сильные руки схватили вас и потащили в сторону берега.";
    str[5] = "Никто не откликается на ваш зов, похоже тут вы совершенно одни.";
    str[6] = "Вы решили не испытывать больше судьбу и повернуть назад...";
    str[7] = "Вы посчитали, что к домику все же добраться предпочтительнее и стали продвигаться дальше...";
    return str[id];
}

QString GadForestSwamp::act(int id)
{
    QString str[9];
    str[0] = "Вернуться назад в лес";
    str[1] = "Идти через трясину";
    str[2] = "Идти дальше";
    str[3] = "Позвать на помощь";
    str[4] = "Ждать";
    str[5] = "Далее";
    str[6] = "Пробовать вернуться к лесу";
    str[7] = "Идти";
    str[8] = "Пробовать идти дальше к домику";

    return str[id];
}

QString GadForestSwamp::media(int id)
{
    QString med[10];
    med[0] = "data/locations/gadukino/swamp/gadforestlostswamp.jpg";
    med[1] = "data/locations/gadukino/swamp/panicswamp.jpg";
    med[2] = "data/actions/backwater/goswamp.jpg";
    med[3] = "data/actions/backwater/goswamp_ski.jpg";
    med[4] = "data/actions/backwater/goswamp_nude0." + intQStr(getRandInt(1,3)) + ".jpg";
    med[5] = "data/locations/gadukino/swamp/gadforestlosthelp.jpg";
    med[6] = "data/actions/backwater/handshelp.jpg";
    med[7] = "data/actions/backwater/goswamp1.jpg";
    med[8] = "data/actions/backwater/goswamp_ski1.jpg";
    med[9] = "data/actions/backwater/goswamp_nude0." + intQStr(getRandInt(4,5)) + ".jpg";
    return med[id];
}

void GadForestSwamp::swampClothes()
{
    if(root->isCloth())
    {
        if(!root->isSkirt())
            root->setImage(media(7));
        else
            root->setImage(media(8));
    }
    else
        root->setImage(media(9));
}

