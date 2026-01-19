#include "gadmarket.h"
#include "../../menu/buttons.h"

Gadmarket::Gadmarket(LocationHandler *ptr): Location(ptr) {}

void Gadmarket::show(QString arg)
{
    actionHandler("gadmarket");
}

LocId Gadmarket::getLocId()
{
    return lgadmarket;
}

LocId Gadmarket::getParId()
{
    return lgadukino;
}

LocId Gadmarket::getLocIn()
{
    return lgadukino;
}

QString Gadmarket::getLocName()
{
    return "Магазин";
}

bool Gadmarket::isParent()
{
    return true;
}

void Gadmarket::actionHandler(QString action)
{
    if(action == "gadmarket")
    {
        setImage(media(0));
        if(getHour() == 14 && getWeekNum() == 0)
            setDesc(str(0));
        if(gVStatus(money) >= 500)
            makeActBtn("buy_cookies", act(0));
        if(gVStatus(money) >= 75)
            makeActBtn("buy_water",act(1));
        if(gVStatus(money) >= 300)
            makeActBtn("buy_tampon", act(2));
        makeActBtn("exit", act(3));
        if(gVQuest(grandmaQW) >= 60 && getItemCount(iCookies) == 0 && getHour() == 14 && (getWeekNum() == 6 || getWeekNum() == 0))
        {
            startEvent(eGrandParentEvents,"market");
        }
    }
    if(action == "buy_cookies")
    {
        uVStatus(money,-500);
        addItem(iCookies,10);
        addText(str(1));
    }
    if(action == "buy_water")
    {
        uVStatus(money,-75);
        addItem(iBottledWater,1);
        addText(str(2));
    }
    if(action == "buy_tampon")
    {
        uVStatus(money,-300);
        addItem(iTampon,20);
        addText(str(3));
    }
    if(action == "exit")
    {
        changeLoc(lgadukino,5);
    }
    if(action == "grandma")
    {
        startEvent(eGrandMa);
    }
}

void Gadmarket::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"gadmarket");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadmarket::actionHandler);
    addActBtn(btn);
}

QString Gadmarket::str(int id)
{
    QString str[4];
    str[0] = "В магазине у прилавка ваша <a href='grandma'>бабушка</a> рассматривает товары.";
    str[1] = "Вы купили печенье.";
    str[2] = "Вы купили бутылочку воды и положили ее в свою сумочку.";
    str[3] = "Вы купили упаковку тампонов.";
    return str[id];
}

QString Gadmarket::act(int id)
{
    QString act[4];
    act[0] = "Купить печенье";
    act[1] = "Купить бутылочку воды";
    act[2] = "Купить тампоны(20шт - 300руб)";
    act[3] = "Уйти";
    return act[id];
}

QString Gadmarket::media(int id)
{
    QString med[1];
    med[0] = "data/locations/gadukino/market.jpg";
    return med[id];
}
