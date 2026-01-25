#include "gadhouse.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"
Gadhouse::Gadhouse(Game *ptr): root(ptr) {}

void Gadhouse::show(QString arg)
{
    actionHandler("gadhouse");
}

LocId Gadhouse::getLocId()
{
    return lgadhouse;
}

LocId Gadhouse::getParId()
{
    return lgaddvor;
}

LocId Gadhouse::getLocIn()
{
    return lgadukino;
}

QString Gadhouse::getLocName()
{
    return "Изба";
}

bool Gadhouse::isParent()
{
    return true;
}

void Gadhouse::actionHandler(QString action)
{
    root->clearActions();
    if(action == "gadhouse")
    {
        root->setImage(media(0));
        root->setText(str(0));
        if(getRandInt(0,5) == 0)
            root->addText(str(1));
        if(root->getHour() < 6 || root->getHour() > 21)
            root->addText(str(2));
        else if (root->getHour() == 6)
        {
            root->addText(str(3));
            root->addText(str(4));
        }
        else if(root->getHour() == 7 || root->getHour() == 13 || root->getHour() == 18)
            root->addText(str(5));
        else if(root->getHour() > 13 && root->getHour() < 18 && root->getWeek() == 0 && (root->getMonth() >= 5 || root->getMonth() <= 9))
            root->addText(str(6));
        else if(root->getHour() > 19 && root->getHour() < 22)
            root->addText(str(7));
        else if(root->getHour() > 20 && root->getHour() < 22)
            root->addText(str(8));

        //Логистика
        //////////

        if(root->getMonth() < 5 || root->getMonth() > 9 || root->getSunWeather() < 0)
        {
            if(root->getHour() > 7 && root->getHour() < 13)
                root->addText(str(10));
            else if(root->getHour() > 13 && root->getHour() < 18)
                root->addText(str(11));
        }
        if(root->vEvent(mira_guest) == 1)
            root->addText(str(12));
        makeActBtn("to_gaddvor", str(13));
        makeActBtn("eat", str(15));
        root->drinkAll();
        root->cookies();
        root->fatDel();
        root->vitamin();
        root->pills();
        if(root->vStatus(boletus) > 0 || root->vStatus(bilberry) > 0)
        {
            makeActBtn("dry_food", str(17));
        }
        root->fancywork();
        root->home_workout();
        root->startEvent(eFamily, "father_sheduler");
        if(root->gNPC(father).location == lgadhouse)
        {
            root->addText("В комнате отдыхают родители.");
            root->startEvent(eGadukinoEvents,"go_home");
        }

        connect(root->getTextPtr(), &QLabel::linkActivated, this, &Gadhouse::actionHandler);
    }
    if(action == "to_gaddvor")
    {
        if(root->isCloth())
        {
            root->changeLoc(lgaddvor, 5);
        }
        else
        {
            root->addText(str(14));
        }
    }
    if(action == "eat")
    {
        root->eat();
        root->drink("tea");
        makeActBtn("gadhouse", str(16));
    }
    if(action == "dry_food")
    {
        root->vStatus(eda) += root->vStatus(boletus) + root->vStatus(bilberry);
        root->vStatus(boletus) = 0;
        root->vStatus(bilberry) = 0;
        root->setImage(media(1));
        root->setText(str(18));
        makeActBtn("gadhouse", str(19));
    }
    if(action == "grandma")
    {
        root->startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        root->startEvent(eGrandPa);
    }
    if(action == "loker")
    {
        root->viewObj("wardrobe");
    }
    if(action == "mirror")
    {
        root->viewObj("mirror");
    }
    if(action == "bed")
    {
        root->viewObj("bed");
    }
    if(action == "villagecat")
    {
        root->startEvent(eGrandParentEvents,"villagecat");
    }
    if(action == "zz_books_custom_shelf_0_9")
    {

    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
    if(action == "HR_Nina")
    {
        root->startEvent(eLogistEvents,"HR_Nina");
    }
}

QString Gadhouse::str(int id)
{
    QString ded, bab;
    if(root->vEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";
    if(root->vEvent(grandpa_notalk) == 0)
        ded = "<a href='grandpa'>дедушка</a>";
    else
        ded = "дедушка";
    QString str[20];
    str[0] = "Простая деревенская изба.<br>В маленькой комнате стоит <a href='loker'>шкаф</a> и <a href='bed'>кровать</a> на которой вы можете спать.<br>"
             "В большой комнате, посередине, стоит стол. Возле окна стоит <a href='watch_tv_on_sofa'>телевизор</a>, а рядом с ним древний <a href='mirror'>трельяж</a> и <a href='zz_books_custom_shelf_0_9'>книжный шкаф</a>.";
    str[1] = "На столе у окна возле батареи лениво валяется кот <a href='villagecat'>Бонифаций</a>.";
    str[2] = "В отдельных кроватях спят ваши дедушка с бабушкой.";
    str[3] = "У печи крутится, готовя завтрак, ваша " + bab + ".";
    str[4] = "По комнате ходит ваш " + ded + ".";
    str[5] = "За столом, у окна, кушают " + bab + " и " + ded + ".";
    str[6] = "На кровати отдыхает ваш дедушка.";
    str[7] = "На диване сидит ваша " + bab + " и смотрит телевизор.";
    str[8] = "На диване сидят ваши " + ded + " и " + bab + " и смотрят телевизор";
    str[9] = "На диване сидит <a href='logist_events_HR_Nina'>кадровичка</a> и смотрит телевизор.";
    str[10] = "В избе хлопочет по хозяйству ваша " + bab + ". " + ded + " занимается какими-то своими делами";
    str[11] = "На диване сидит и что-то вяжет ваша " + bab + ". " + ded + " смотрит телевизор.";
    str[12] = "На диване, рядом с вами, сидит <a href='Miroslava'>Мира</a>.";
    str[13] = "Выйти во двор";
    str[14] = "<p style='color:red; font-size: 30px;'>ВАМ НАДО ОДЕТЬСЯ.</p>";
    str[15] = "Есть";
    str[16] = "Встать из за стола";
    str[17] = "Засушить грибы и ягоды(продукты)";
    str[18] = "Посчитав, что вам нужны продукты, вы отправили на сушку найденные грибы и ягоды.";
    str[19] = "Далее";
    return str[id];
}

QString Gadhouse::media(int id)
{
    QString med[2];
    med[0] = "data/locations/gadukino/gaddvor/izba.jpg";
    med[1] = "data/actions/dried_mushrooms.jpg";
    return med[id];
}

void Gadhouse::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "gadhouse");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadhouse::actionHandler);
    root->addActions(btn);
}
