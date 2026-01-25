#include "backwater.h"
#include "../../Functions.h"
#include "../common/bathroom.h"
#include "../../menu/buttons.h"
#include "../../game.h"
Backwater::Backwater(Game *ptr): root(ptr) {}

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
        root->setImage(makeImage(img(0),root->isDay(),root->getMonth()));
        root->setText(str(0));

        if(root->vStatus(clothesbackwater) == 1 && root->vStatus(clearClothes) == 0)
            root->addText(str(1));
        ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
        if(root->isCloth() && root->vStatus(clothesbackwater) == 0 && root->getTemp() >= 20)
        {
            makeActBtn("undress",act(0));
            if(ptr != nullptr && ptr->getClothGroup() > nude && checkBodyCum())
                makeActBtn("wash_sperm_body",act(2));
            if(root->vStatus(cumFrot) > 0 && ptr != nullptr)
                makeActBtn("clearClothesSperm",act(3));
        }
        if(root->getTemp() >= 10 && ptr != nullptr)
            makeActBtn("wash_face",act(6));
        if(root->vStatus(dirtyClothes) == 1 && (ptr == nullptr || ptr->getClothGroup() < sundress))
            makeActBtn("wash_clothes",act(7));
        if(root->vStatus(dirtyClothes) == 1 && root->isCloth())
            makeActBtn("clearClothesDirt",act(9));
        if(ptr == nullptr || ptr->getClothGroup() < sundress || root->vStatus(swamp_clothes) == 1)
            makeActBtn("wash_swim",act(10));
        makeActBtn("exit",act(11));
        if(root->vEvent(hantersRape) == 2)
        {
            root->startEvent(eSwampEvents,"backwater_ralax");
        }
        if(ptr == nullptr && root->vEvent(hantersKnowSlut) == 0 && root->vEvent(hanters) == 1 && root->getHour() > 8 && root->getHour() < 20 && root->vEvent(hantersday) != root->getDay())
        {
            root->startEvent(eSwampEvents,"hunter_looks");
        }
    }
    if(action == "dress_after_backwater")
    {
        root->startEvent(eSwampEvents,"dress_after_backwater");
    }
    if(action == "undress")
    {
        if(root->vEvent(hantersKnowSlut) > 0 || root->vEvent(hanters) == 0 || root->getHour() < 8 || root->getHour() >= 20 || root->vStatus(shamelessFlag) > 0)
        {
            root->vStatus(clothesbackwater) = 1;
            root->incTime(5);
            if(root->vEvent(hantersRape) == 1)
                root->vEvent(hantersRape) = 2;
            root->redress(ClothType::Main,nullptr);
            root->setImage(img(1));
            root->setText(str(2));
            makeActBtn("backwater",act(1));
        }
        else
        {
            root->setImage(img(2));
            root->setText(str(3));
            makeActBtn("backwater",act(1));
        }
    }
    if(action == "wash_sperm_body")
    {
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->incTime(10);
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) =2;
        root->setImage(img(3));
        root->setText(str(4));
        makeActBtn("backwater",act(5));
    }
    if(action == "clearClothesSperm")
    {
        root->vStatus(cumFrot) = 0;
        root->incTime(5);
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) = 2;
        root->setImage(img(4));
        root->setText(str(5));
        makeActBtn("backwater",act(4));
    }
    if(action == "wash_face")
    {
        root->vBody(makeup) = 1;
        root->vStatus(cumLips) = 0;
        root->vStatus(cumFace) = 0;
        root->vStatus(sweat) -= 1;
        root->incTime(5);
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) = 2;
        root->setImage(img(5));
        makeActBtn("backwater",act(5));
    }
    if(action == "wash_clothes")
    {
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) = 2;
        root->incTime(60);
        root->vStatus(dirtyClothes) = 0;
        root->vStatus(cumFrot) = 0;
        root->setImage(img(6));
        root->setText(str(7));
        makeActBtn("hangupcloth",act(8));

    }
    if(action == "clearClothesDirt")
    {
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) = 2;
        root->incTime(30);
        root->vStatus(dirtyClothes) = 0;
        root->vStatus(cumFrot) = 0;
        root->setImage(img(7));
        root->setText(str(9));
        makeActBtn("exit",act(5));
    }
    if(action == "wash_swim")
    {
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->vStatus(mood) += 10;
        if(root->vEvent(hantersRape) == 1)
            root->vEvent(hantersRape) = 2;
        root->setImage(img(8));
        root->setText(str(10));
        makeActBtn("backwater",act(5));
    }
    if(action == "exit")
    {
        root->changeLoc(lswampyard,5);
    }
    if(action == "hangupcloth")
    {
        root->incTime(10);
        root->vStatus(clearClothes) = 3;
        root->vStatus(clearclothesH) = 0;
        root->setImage(img(9));
        root->setText(str(8));
        makeActBtn("exit",act(5));
    }
    if(action == "dress_after_backwater")
    {
        root->redressOld();
        root->startEvent(eSwampEvents, "dress_after_backwater");
    }
}

void Backwater::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "backwater");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Backwater::actionHandler);
    root->addActions(btn);
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
    if(root->isSkirt())
        add = "_ski";
    img[1] = "data/actions/backwater/backwaterundress" + add + ".jpg";
    img[2] = "data/actions/backwater/noundress.jpg";
    img[3] = "data/actions/backwater/backwaterswim1.jpg";
    img[4] = "data/actions/bathroom/frotsp.jpg";
    img[5] = "data/actions/bathroom/facesp.jpg";
    img[6] = "data/actions/backwater/backwaterwash.jpg";
    img[7] = "data/actions/backwater/backwaterwash2.jpg";
    if(root->isPanties()) { add = "3"; }
    else { add = "2"; }
    img[8] = "data/actions/backwater/backwaterswim" + add + ".jpg";
    img[9] = "data/actions/backwater/basinwash2.jpg";
    return img[id];
}

bool Backwater::checkBodyCum()
{
    return root->vStatus(cumPussy) > 0 || root->vStatus(cumBelly) > 0 || root->vStatus(cumAss) > 0 || root->vStatus(cumAnus) > 0;
}
