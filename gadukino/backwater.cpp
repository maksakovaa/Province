#include "backwater.h"
#include "../Functions.h"
#include "../common/bathroom.h"
#include "../menu/buttons.h"
Backwater::Backwater(LocationHandler *ptr): Location(ptr) {}

void Backwater::show(QString arg)
{
    actionHandler("backwater");
}

LocId Backwater::getLocId()
{
    return lbackwater;
}

LocId Backwater::getParId()
{
    return lswampyard;
}

LocId Backwater::getLocIn()
{
    return lgadukino;
}

QString Backwater::getLocName()
{
    return "Затон";
}

bool Backwater::isParent()
{
    return true;
}

void Backwater::actionHandler(QString action)
{
    if(action == "backwater")
    {
        setImage(makeImage(img(0),isDay(),getMonth()));
        setDesc(str(0));

        if(gVStatus(clothesbackwater) == 1 && gVStatus(clearClothes) == 0)
            addText(str(1));
        ClothMain* ptr = (ClothMain*)getCloth(ClothType::Main);
        if(isCloth() && gVStatus(clothesbackwater) == 0 && getTemp() >= 20)
        {
            makeActBtn("undress",act(0));
            if(ptr != nullptr && ptr->getClothGroup() > nude && checkBodyCum())
                makeActBtn("wash_sperm_body",act(2));
            if(gVStatus(cumFrot) > 0 && ptr != nullptr)
                makeActBtn("clearClothesSperm",act(3));
        }
        if(getTemp() >= 10 && ptr != nullptr)
            makeActBtn("wash_face",act(6));
        if(gVStatus(dirtyClothes) == 1 && (ptr == nullptr || ptr->getClothGroup() < sundress))
            makeActBtn("wash_clothes",act(7));
        if(gVStatus(dirtyClothes) == 1 && isCloth())
            makeActBtn("clearClothesDirt",act(9));
        if(ptr == nullptr || ptr->getClothGroup() < sundress || gVStatus(swamp_clothes) == 1)
            makeActBtn("wash_swim",act(10));
        makeActBtn("exit",act(11));
        if(gVEvent(hantersRape) == 2)
        {
            startEvent("swamp_events","backwater_ralax");
        }
        if(ptr == nullptr && gVEvent(hantersKnowSlut) == 0 && gVEvent(hanters) == 1 && getHour() > 8 && getHour() < 20 && gVEvent(hantersday) != getDay())
        {
            startEvent("swamp_events","hunter_looks");
        }
    }
    if(action == "dress_after_backwater")
    {
        startEvent("swamp_events","dress_after_backwater");
    }
    if(action == "undress")
    {
        if(gVEvent(hantersKnowSlut) > 0 || gVEvent(hanters) == 0 || getHour() < 8 || getHour() >= 20 || gVStatus(shamelessFlag) > 0)
        {
            sVStatus(clothesbackwater,1);
            incTime(5);
            if(gVEvent(hantersRape) == 1)
                sVEvent(hantersRape,2);
            redress(ClothType::Main,nullptr);
            setImage(img(1));
            setDesc(str(2));
            makeActBtn("backwater",act(1));
        }
        else
        {
            setImage(img(2));
            setDesc(str(3));
            makeActBtn("backwater",act(1));
        }
    }
    if(action == "wash_sperm_body")
    {
        ((BathRoom*)getLocPtr(lbathroom))->cleanMe();
        incTime(10);
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        setImage(img(3));
        setDesc(str(4));
        makeActBtn("backwater",act(5));
    }
    if(action == "clearClothesSperm")
    {
        sVStatus(cumFrot,0);
        incTime(5);
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        setImage(img(4));
        setDesc(str(5));
        makeActBtn("backwater",act(4));
    }
    if(action == "wash_face")
    {
        sVBody(makeup,1);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        uVStatus(sweat,-1);
        incTime(5);
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        setImage(img(5));
        makeActBtn("backwater",act(5));
    }
    if(action == "wash_clothes")
    {
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        incTime(60);
        sVStatus(dirtyClothes,0);
        sVStatus(cumFrot,0);
        setImage(img(6));
        setDesc(str(7));
        makeActBtn("hangupcloth",act(8));

    }
    if(action == "clearClothesDirt")
    {
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        incTime(30);
        sVStatus(dirtyClothes,0);
        sVStatus(cumFrot,0);
        setImage(img(7));
        setDesc(str(9));
        makeActBtn("exit",act(5));
    }
    if(action == "wash_swim")
    {
        ((BathRoom*)getLocPtr(lbathroom))->cleanMe();
        uVStatus(mood,10);
        if(gVEvent(hantersRape) == 1)
            sVEvent(hantersRape,2);
        setImage(img(8));
        setDesc(str(10));
        makeActBtn("backwater",act(5));
    }
    if(action == "exit")
    {
        changeLoc(lswampyard,5);
    }
    if(action == "hangupcloth")
    {
        incTime(10);
        sVStatus(clearClothes,3);
        sVStatus(clearclothesH,0);
        setImage(img(9));
        setDesc(str(8));
        makeActBtn("exit",act(5));
    }
    if(action == "dress_after_backwater")
    {
        redressOld();
        startEvent("swamp_events", "dress_after_backwater");
    }
}

void Backwater::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Backwater::actionHandler);
    addActBtn(btn);
}

QString Backwater::str(int id)
{
    QString str[11];
    str[0] = "Тихая заводь, с относительно чистой водой, в которой в теплую погоду можно помыться.<br>"
             "Так же, предварительно раздевшись, тут можно постирать одежду, если она грязная или просто отчистить от грязи не раздеваясь.";
    str[1] = "На берегу лежит ваша <a href='dress_after_backwater'>одежда</a>.";
    str[2] = "Вы не стеснясь разделись, оставшись в чем мать родила.";
    str[3] = "Вы стесняетесь раздеться, а вдруг кто-нибудь увидит?";
    str[4] = "Вы тщательно смыли сперму в затоне.";
    str[5] = "Вы замыли пятна спермы на своей одежде.";
    str[6] = "Вы тщательно умыли лицо.";
    str[7] = "Вы разделись и постирали свою грязную одежду. К сожалению в холодной воде она до конца не отстиралась, но хоть так.";
    str[8] = "Вы развесили одежду сушиться на поляне.";
    str[9] = "Вы не раздеваясь залезли в воду и как могли стали чистить свою одежду от грязи. "
             "К сожалению в холодной воде и не раздеваясь она очень плохо отчистилась, но хоть так.";
    str[10] = "Вы помылись в затоне.";
    return str[id];
}

QString Backwater::act(int id)
{
    QString act[12];
    act[0] = "Снять одежду";
    act[1] = "Назад";
    act[2] = "Подмыться";
    act[3] = "Оттирать сперму с одежды";
    act[4] = "Закончить";
    act[5] = "Далее";
    act[6] = "Умыться";
    act[7] = "Стирать одежду";
    act[8] = "Развесить на поляне";
    act[9] = "Чистить одежду от грязи";
    act[10] = "Помыться";
    act[11] = "Уйти";
    return act[id];
}

QString Backwater::img(int id)
{
    QString img[10];
    QString add;
    img[0] = "data/locations/gadukino/swamp/backwater.JPG";
    if(isSkirt())
        add = "_ski";
    img[1] = "data/actions/backwater/backwaterundress" + add + ".jpg";
    img[2] = "data/actions/backwater/noundress.jpg";
    img[3] = "data/actions/backwater/backwaterswim1.jpg";
    img[4] = "data/actions/bathroom/frotsp.jpg";
    img[5] = "data/actions/bathroom/facesp.jpg";
    img[6] = "data/actions/backwater/backwaterwash.jpg";
    img[7] = "data/actions/backwater/backwaterwash2.jpg";
    if(isPanties()) { add = "3"; }
    else { add = "2"; }
    img[8] = "data/actions/backwater/backwaterswim" + add + ".jpg";
    img[9] = "data/actions/backwater/basinwash2.jpg";
    return img[id];
}

bool Backwater::checkBodyCum()
{
    return gVStatus(cumPussy) > 0 || gVStatus(cumBelly) > 0 || gVStatus(cumAss) > 0 || gVStatus(cumAnus) > 0;
}
