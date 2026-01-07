#include "gadforestswamp.h"
#include "../menu/buttons.h"
#include "../Functions.h"

GadForestSwamp::GadForestSwamp(LocationHandler *ptr): Location(ptr) {}

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
        makeImage(media(0),isDay(),getMonth());
        setDesc(str(0));
        makeActBtn("gadforestlost",act(0));
        makeActBtn("go_swamp",act(1));
    }
    if(action == "2")
    {
        sVBody(hairStatus,0);
        if(gVBody(makeup) > 1)
        {
            sVBody(makeup,0);
            uVStatus(vidageday,-1);
        }
        if(gVStatus(dirtyClothes) == 0 && isCloth())
        {
            decrease_condition(10);
            sVStatus(dirtyClothes,1);
        }
        setImage(media(1));
        setDesc(str(2));
        makeActBtn("call_help",act(3));
        makeActBtn("try_to_forest",act(6));
        makeActBtn("try_to_swamp",act(8));
    }
    if(action == "gadforestlost")
    {
        startEvent("gadforestlost","main");
    }
    if(action == "go_swamp")
    {
        incTime(10);
        uVStatus(sweat,1);
        if(isCloth())
        {
            if(!isSkirt())
                setImage(media(2));
            else
                setImage(media(3));
        }
        else
            setImage(media(4));
        setDesc(str(1));
        makeActBtn("go_swamp2",act(2));
    }
    if(action == "go_swamp2")
    {
        int i = getRandInt(1,100);
        if(gVSkill(strenght) + gVSkill(agility) > i)
        {
            changeLoc(lswampyard,0);
        }
        else if(gVSkill(strenght) + gVSkill(agility) < i)
        {
            startEvent("gameover","10");
        }
        else
        {
            actionHandler("2");
        }
    }
    if(action == "call_help")
    {
        incTime(10);
        if(gVStatus(sweat) < 10)
            uVStatus(sweat,1);
        setImage(media(5));
        setDesc(str(3));
        makeActBtn("wait",act(4));
    }
    if(action == "wait")
    {
        incTime(10);
        int y = 0;
        if(getWeekNum() > 5 || getWeekNum() == 0)
            y = 3;
        else
            y = 5;
        if(getRandInt(1, y) == 1)
        {
            sVEvent(hanters,1);
            sVEvent(hantershelp,1);
            setImage(media(6));
            setDesc(str(4));
            makeActBtn("swamp_yard",act(5));
        }
        else
        {
            setImage(media(1));
            setDesc(str(5));
            makeActBtn("2",act(5));
        }
    }
    if(action == "swamp_yard")
    {
        changeLoc(lswampyard,0);
    }
    if(action == "try_to_forest")
    {
        incTime(10);
        uVSkill(strenght,1);
        uVSkill(agility,1);
        if(gVStatus(sweat) < 10)
            uVStatus(sweat,3);
        swampClothes();
        setDesc(str(6));
        makeActBtn("walk",act(7));
    }
    if(action == "walk")
    {
        int i = getRandInt(1,100);
        if(gVSkill(strenght) + gVSkill(agility) > i)
        {
            actionHandler("1");
        }
        else if(gVSkill(strenght) + gVSkill(agility) < i)
        {
            startEvent("gameover","10");
        }
        else
        {
            actionHandler("2");
        }
    }
    if(action == "try_to_swamp")
    {
        incTime(10);
        uVSkill(strenght,1);
        uVSkill(agility,1);
        if(gVStatus(sweat) < 10)
            uVStatus(sweat,3);
        swampClothes();
        setDesc(str(7));
        makeActBtn("walk2",act(7));
    }
    if(action == "walk2")
    {
        int i = getRandInt(1,100);
        if(gVSkill(strenght) + gVSkill(agility) > i)
        {
            changeLoc(lswampyard,0);
        }
        else if(gVSkill(strenght) + gVSkill(agility) < i && i <= 30)
        {
            startEvent("gameover","10");
        }
        else
        {
            actionHandler("2");
        }
    }
}

void GadForestSwamp::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadForestSwamp::actionHandler);
    addActBtn(btn);
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
    if(isCloth())
    {
        if(!isSkirt())
            setImage(media(7));
        else
            setImage(media(8));
    }
    else
        setImage(media(9));
}

