#include "grandmahelp.h"
#include "../../menu/buttons.h"
#include "../eventhandler.h"
#include "../../Functions.h"

GrandmaHelp::GrandmaHelp(EventHandler* ptr) {}

void GrandmaHelp::start(QString arg)
{
    actionHandler("grandmahelp");
}

void GrandmaHelp::actionHandler(QString action)
{
    if(action == "grandmahelp")
    {
        root->sVStatus(frost,0);
        root->setImage(media(0));
        root->setDesc(str(0));
        if(root->getMonth() <= 4 || root->getMonth() >= 10)
            root->sVEvent(grandmahelping,getRandInt(0,2));
        if(root->getMonth() == 5 || root->getMonth() == 6)
            root->sVEvent(grandmahelping,getRandInt(0,5));
        if(root->getMonth() == 7)
            root->sVEvent(grandmahelping,getRandInt(0,6));
        if(root->getMonth() == 8)
            root->sVEvent(grandmahelping,getRandInt(7,13));
        if(root->getMonth() == 9)
            root->sVEvent(grandmahelping,getRandInt(14,19));
        fnGrandmaHelping();
    }
    if(action == "wash_floor")
    {
        root->incTime(60);
        root->uVEvent(grandmahelp,1);
        root->uVQuest(grandmaQW,1);
        root->setImage(media(1));
        root->setDesc(str(2));
        makeActBtn("gadhouse",act(1));
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "wash_clothes")
    {
        root->incTime(60);
        root->uVEvent(grandmahelp,1);
        root->uVQuest(grandmaQW,1);
        root->setImage(media(2));
        root->setDesc(str(4));
        makeActBtn("bringup_cloth",act(3));
    }
    if(action == "bringup_cloth")
    {
        root->incTime(10);
        root->setImage(media(3));
        root->setDesc(str(5));
        makeActBtn("gaddvor",act(1));
    }
    if(action == "gaddvor")
    {
        root->changeLoc(lgaddvor,0);
    }
    if(action == "milk_a_cow")
    {
        root->incTime(10);
        root->sVJob(milk_cow,1);
        root->setImage(media(4));
        root->setDesc(str(7));
        makeActBtn("gadsarai",act(5));
    }
    if(action == "take_food_for_chicken")
    {
        root->sVJob(feed_chickens,1);
        root->incTime(30);
        root->setImage(media(5));
        root->setDesc(str(9));
        makeActBtn("gaddvor",act(1));
    }
    if(action == "work_garden")
    {
        root->sVJob(workGarden,1);
        root->incTime(10);
        root->setImage(media(4));
        root->setDesc(str(11));
        makeActBtn("in_garden",act(5));
    }
    if(action == "water_garden")
    {
        root->sVJob(waterGarden,1);
        root->incTime(10);
        root->setImage(media(4));
        root->setDesc(str(11));
        makeActBtn("in_garden",act(5));
    }
    if(action == "in_garden")
    {
        root->changeLoc(lgadgarden,0,"garden");
    }
    if(action == "coolect_straw")
    {
        root->sVJob(collect_strawberries,1);
        root->incTime(15);
        root->setImage(media(4));
        root->setDesc(str(14));
        makeActBtn("in_strawberry",act(5));
    }
    if(action == "in_strawberry")
    {
        root->changeLoc(lgadgarden,0,"strawberry");
    }
    if(action == "collect_fruits")
    {
        root->sVJob(fruit_collect,1);
        root->incTime(15);
        root->setImage(media(4));
        root->setDesc(str(16));
        makeActBtn("in_fruitgarden",act(5));
    }
    if(action == "in_fruitgarden")
    {
        root->changeLoc(lgadgarden,0,"fruit_garden");
    }
    if(action == "harvest_garden")
    {
        root->sVJob(harvest_garden,1);
        root->incTime(10);
        root->setImage(media(4));
        root->setDesc(str(11));
        makeActBtn("in_garden",act(5));
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc(),0);
    }
}

void GrandmaHelp::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GrandmaHelp::actionHandler);
    root->addActBtn(btn);
}

QString GrandmaHelp::str(int id)
{
    QString str[20];
    str[0] = "Вы подошли к бабушке и спросили не нужна ли ей помочь по хозяйству. Бабушка немного подумала, взглянув на погоду и сказала:";
    str[1] = "<npc>- Конечно внученька, я уже старая совсем, сил не хватает пол помыть.</npc>";
    str[2] = "Вы вооружились ведром и тряпкой, сели на корточки и принялись драить пол. После того как все засияло чистотой, вы довольная собой поставили инвентарь в угол и отправились по своим делам.";
    str[3] = "<npc>- Конечно внученька, нужно белье постирать, а то мы с дедом скоро грязью зарастем.</npc>";
    str[4] = "Вы взяли тазик и принялись стирать белье в течение часа.";
    str[5] = "Вы взяли постиранное белье и аккуратно развесили его во дворе.";
    str[6] = "<npc>- Внучка, сходи-ка в сарай, подоить корову нужно.</npc>";
    str[7] = "Вы пошли в сарай где вас уже заждалась Зорька";
    str[8] = "<npc>- Конечно внученька, ты у меня такая молодец, иди на двор, покорми кур.</npc>";
    str[9] = "Вы взяли корм для кур и двинулись на двор.";
    str[10] = "<npc>- Светуля, сходи на огород, пора там порядок наводить.</npc>";
    str[11] = "Вы собрались и двинулись на огород.";
    str[12] = "<npc>- Света, внучка, сбегай полей огород, а то весь урожай посохнет.</npc>";
    str[13] = "<npc>- Светуля, внученька, пора бы уже начать клубнику собирать, займись этим сегодня.</npc>";
    str[14] = "Вы собрались и двинулись на клубничную делянку.";
    str[15] = "<npc>- Светуля, внученька, пора бы уже начать фрукты собирать в саду, займись этим сегодня.</npc>";
    str[16] = "Вы собрались и двинулись в сад.";
    str[17] = "<npc>- Света, внучка, сегодня на огород иди, пришла пора урожай собирать.</npc>";
    str[18] = "<npc>- Сегодня нет работы внучка, отдыхай.</npc>";
    return str[id];
}

QString GrandmaHelp::act(int id)
{
    QString act[20];
    act[0] = "Мыть пол";
    act[1] = "Уйти";
    act[2] = "Стирать белье";
    act[3] = "Развесить белье";
    act[4] = "Идти в сарай";
    act[5] = "Далее";
    act[6] = "Взять корм для кур";
    act[7] = "Идти на огород";
    act[8] = "Идти на делянку";
    act[9] = "Идти в сад";
    return act[id];
}

QString GrandmaHelp::media(int id)
{
    QString med[6];
    med[0] = "data/npc/gadukino/grandma/grandmahelp.jpg";
    med[1] = "data/actions/Washfloor.jpg";
    med[2] = "data/actions/Washclothes1.jpg";
    med[3] = "data/actions/Washclothes2.jpg";
    med[4] = "data/locations/gadukino/go_yard.jpg";
    med[5] = "data/img/items/feed_chickens.JPG";
    return med[id];
}

void GrandmaHelp::fnGrandmaHelping()
{
    int val = root->gVEvent(grandmahelping);
    if(val == 0 || val == 7 || val == 14)
    {
        root->setDesc(str(1));
        makeActBtn("wash_floor",act(0));
    }
    else if (val == 1 || val == 8 || val == 15)
    {
        root->setDesc(str(3));
        makeActBtn("wash_clothes",act(2));
    }
    else if((val == 2 || val == 10 || val == 17) && root->getHour() < 9 && root->getHour() > 20)
    {
        root->setDesc(str(6));
        makeActBtn("milk_a_cow",act(4));
    }
    else if(val == 3 || val == 9 || val == 16)
    {
        root->setDesc(str(8));
        makeActBtn("take_food_for_chicken",act(6));
    }
    else if((val == 4 || val == 11 || val == 18) && root->getSunWeather() >= 0)
    {
        root->setDesc(str(10));
        makeActBtn("work_garden",act(7));
    }
    else if((val == 5 || val == 12) && root->getSunWeather() >= 0)
    {
        root->setDesc(str(12));
        makeActBtn("water_garden",act(7));
    }
    else if(val == 6 && root->getSunWeather() >= 0)
    {
        root->setDesc(str(13));
        makeActBtn("coolect_straw",act(8));
    }
    else if(val == 13 && root->getSunWeather() >= 0)
    {
        root->setDesc(str(15));
        makeActBtn("collect_fruits",act(9));
    }
    else if(val == 19 && root->getSunWeather() >= 0)
    {
        root->setDesc(str(17));
        makeActBtn("harvest_garden",act(7));
    }
    else
    {
        root->setDesc(str(18));
        makeActBtn("back_to_loc",act(1));
    }
}
