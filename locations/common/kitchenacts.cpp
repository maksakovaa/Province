#include "kitchenacts.h"
#include "../location.h"
#include "../locationhandler.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

KitchenActs::KitchenActs(LocationHandler* ptr): root(ptr) {}

void KitchenActs::drink(QString napitokType)
{
    QString str0, str1;
    if(napitokType == "tea")
    {
        str0 = str(0);
        str1 = str(1);
    }
    if(napitokType == "water")
    {
        str0 = str(2);
        str1 = str(3);
    }
    if(napitokType == "coffee")
    {
        str0 = str(4);
        str1 = str(5);
    }
    else
    {
        str0 = str(6);
        str1 = str(7);
    }
    root->setVStatus(cumLips,0);
    if(root->getVStatus(water) > 20)
    {
        root->setVStatus(water,24);
        root->m_render->addText(str0 + str(8));
    }
    else
    {
        root->updVStatus(water, 20);
        root->m_render->addText(str(9) + str1);
    }
    root->updateParams();
}

void KitchenActs::drink_all()
{
    makeActBtn("tea", act(0));
}

void KitchenActs::eat(QString foodtype, QString image, QString text)
{
    QString eatStr;
    if(foodtype == "lunch" || foodtype == "diet")
        root->updVStatus(mood,10);
    else
        root->updVStatus(mood, 20);

    if(foodtype == "lunch")
        root->incTime(15);
    else
        root->incTime(30);

    if(foodtype == "lunch" || foodtype == "diet")
        root->updVStatus(health, 5);
    else
        root->updVStatus(health,10);

    root->setVStatus(cumLips,0);
    if(root->getCurLoc() == lkuhr)
    {
        root->updVStatus(edahot, -1);
        root->updVStatus(dirttarelka, 1);
        root->updVStatus(garbage,1);
        root->updVStatus(clrtarelka, -1);
    }
    int energ = root->getVStatus(energy);
    if(energ >= 24)
    {
        root->setVStatus(energy,24);
        eatStr = str(10);
    }
    else if(energ >= 18 && energ < 18)
    {
        if(foodtype == "diet")
        {
            root->useItem(iDietFood,1);
            root->updVStatus(day_weight,1);
        }
        else if(foodtype == "lunch")
        {
            root->updVStatus(day_weight,2);
        }
        else
            root->updVStatus(day_weight,3);

        root->setVStatus(energy,24);
        eatStr = str(11);
    }
    else if(energ >= 8 && energ < 18)
    {
        if(foodtype == "diet")
            root->useItem(iDietFood,1);
        else if(foodtype == "lunch")
            root->updVStatus(day_weight,1);
        else
            root->updVStatus(day_weight,2);
        if(foodtype == "lunch")
            root->updVStatus(energy,10);
        else
            root->updVStatus(energy,20);
        eatStr = str(12);
    }
    else
    {
        if(foodtype == "diet")
        {
            root->useItem(iDietFood,1);
            root->updVStatus(day_weight,-1);
        }
        else if(foodtype == "lunch")
            root->updVStatus(day_weight,0);
        else
            root->updVStatus(day_weight,1);
        if(foodtype == "lunch")
            root->updVStatus(energy,10);
        else
            root->updVStatus(energy,20);
        eatStr = str(13);
    }

    if(image.isEmpty())
        root->setImage("data/actions/eat/food.jpg");
    else
        root->setImage(image);
    if(text.isEmpty())
        root->setDesc(eatStr);
    else
        root->setDesc(text);

    if(root->getVStatus(energy) >= 24)
        root->setVStatus(energy,24);
    root->updateParams();
}

void KitchenActs::eat_full()
{
    makeActBtn("eatFull", str(1));
}

void KitchenActs::eat_diet()
{
    if(root->getItmCount(iDietFood) > 0)
    {
        root->m_render->addText(str(14));
        makeActBtn("eat_diet",act(2));
    }
}

void KitchenActs::lunch()
{
    makeActBtn("eat_lunch",act(4));
}

void KitchenActs::vitamin()
{
    if(root->getItmCount(iVitamins) > 0)
    {
        root->m_render->addText(str(15));
        if(vitaminday != root->getDay())
        {
            makeActBtn("vitamin", act(6));
        }
    }
}

void KitchenActs::pills()
{
    if(root->getItmCount(iAntibiotics) > 0)
    {
        root->m_render->addText(str(17));
        if(root->getVSick(sick) > 0 && lekarday != root->getDay())
        {
            makeActBtn("pills", act(8));
        }
    }
}

void KitchenActs::fatdel()
{
    if(root->getItmCount(iFatBurners) > 0)
        makeActBtn("fatburn",act(9));
}

void KitchenActs::cookie()
{
    if(root->getItmCount(iCookies) > 0)
    {
        root->m_render->addText(str(20));
        makeActBtn("cookies",act(10));
    }
}

void KitchenActs::all(int arg)
{
    if(arg != 1 || (arg == 1 && root->getVStatus(edahot) > 0 && root->getVStatus(clrtarelka) > 0))
    {
        eat_full();
        lunch();
    }
    eat_diet();
    drink_all();
    cookie();
    fatdel();
    vitamin();
    pills();
}

void KitchenActs::actionHandler(QString action)
{
    if(action == "tea")
    {
        root->setVStatus(cumLips,0);
        root->incTime(1);
        drink(action);
    }
    if(action == "eatFull")
    {
        eat();
        drink("tea");
        makeActBtn("goCurLoc", act(11));
    }
    if(action == "goCurLoc")
    {
        root->slotChangeLoc(root->getCurLoc(),0);
    }
    if(action == "eat_diet")
    {
        eat("diet");
        drink("tea");
        makeActBtn("goCurLoc", act(3));
    }
    if(action == "eat_lunch")
    {
        eat("lunch");
        drink("tea");
        makeActBtn("goCurLoc", act(3));
    }
    if(action == "vitamin")
    {
        root->incTime(2);
        root->updVStatus(water,5);
        vitaminday = root->getDay();
        root->useItem(iVitamins,1);
        if(root->getVSick(KandidozOnce) == 1)
            root->updVSick(Kandidoz, -2);
        if(root->getVSick(GerpesOnce) == 1)
            root->updVSick(Gerpes,-2);
        if(root->getVSick(SifacOnce) == 1 && root->getVSick(Sifilis) > 10)
            root->updVSick(Sifilis, -getRandInt(0,1));
        root->updSkin('+',1);
        root->setVStatus(cumLips,0);
        root->m_render->setImage("data/actions/eat/vitamin.jpg");
        root->m_render->setText(str(16));
        makeActBtn("goCurLoc",act(7));
    }
    if(action == "pills")
    {
        root->incTime(5);
        lekarday = root->getDay();
        root->useItem(iAntibiotics,1);
        root->updVSick(sick, -root->getVSick(sick)/5);
        root->setVStatus(cumLips,0);
        root->m_render->setImage("data/actions/inBed/lekr" + intQStr(getRandInt(1,9)) + ".jpg");
        root->m_render->setText(str(18));
        makeActBtn("goCurLoc",act(7));
    }
    if(action == "faburn")
    {
        root->useItem(iFatBurners,1);
        root->updVStatus(fatdel_day,10);
        root->setVStatus(cumLips,0);
        root->m_render->setImage("data/actions/eat/fat_burner.jpg");
        root->m_render->setText(str(19));
        makeActBtn("goCurLoc", "...");
    }
    if(action == "cookies")
    {
        root->incTime(5);
        root->useItem(iCookies,1);
        root->updVStatus(health,5);
        root->updVStatus(mood,10);
        root->updVStatus(energy,10);
        root->updVStatus(water,10);
        root->setVStatus(cumLips,0);
        if(root->getVStatus(energy) > 24)
            root->updVStatus(day_weight,2);
        else if(root->getVStatus(energy) > 15 && root->getVStatus(energy) < 24)
            root->updVStatus(day_weight,1);
        root->m_render->setImage("data/actions/eat/food.jpg");
        root->m_render->setText(str(21));
        makeActBtn("goCurLoc",act(6));
    }
    root->updateParams();
}

void KitchenActs::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "kitchActs");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &KitchenActs::actionHandler);
    root->m_actions->addWidget(btn);
}

QString KitchenActs::str(int id)
{
    QString str[22];
    str[0] = "Чай";
    str[1] = "кружку чая";
    str[2] = "Вода";
    str[3] = "стакан воды";
    str[4] = "Кофе";
    str[5] = "кружку кофе";
    str[6] = "Лимонад";
    str[7] = "банку лимонада";
    str[8] = " в вас больше не лезет.";
    str[9] = "Вы с удовольствием выпили ";
    str[10] = "Еда в вас больше не лезет, и вы просто ковыряетесь в ней.";
    str[11] = "Вы через силу затолкали в себя еду.";
    str[12] = "Вы с удовольствием поели.";
    str[13] = "Вы с большим удовольствием поели.";
    str[14] = "В холодильнике хранится диетическая еда, которой хватит на <b>" + intQStr(root->getItmCount(iDietFood)) + "</b> порций.";
    str[15] = "У вас " + intQStr(root->getItmCount(iVitamins)) + " витаминок.";
    str[16] = "Вы выпили витаминку";
    str[17] = "У вас " + intQStr(root->getItmCount(iAntibiotics)) + " таблеток.";
    str[18] = "Вы выпили таблетку";
    str[19] = "Вы выпили жиросжигающую капсулу. Эти капсулы действуют постепенно и результаты будут видны не сразу.";
    str[20] = "Печенья хватит ещё на " + intQStr(root->getItmCount(iCookies)) + "; раз.";
    str[21] = "Вы попили чаю с печеньем: очень сладко и вредно для фигуры, но так приятно!";
    return str[id];
}

QString KitchenActs::act(int id)
{
    QString act[14];
    act[0] = "Пить";
    act[1] = "Плотно покушать";
    act[2] = "Есть диетическую еду (30 мин)";
    act[3] = "Встать из за стола";
    act[4] = "Перекусить";
    act[5] = "Встать из за стола";
    act[6] = "Выпить витаминку";
    act[7] = "Отойти";
    act[8] = "Выпить таблетку";
    act[9] = "Употребить жиросжигатели";
    act[10] = "Выпить чаю с печеньем (5 мин)";
    act[11] = "Встать из за стола";
    return act[id];
}
