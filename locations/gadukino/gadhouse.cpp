#include "gadhouse.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Gadhouse::Gadhouse(LocationHandler *ptr): Location(ptr) {}

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
    clearActions();
    if(action == "gadhouse")
    {
        setImage(media(0));
        setDesc(str(0));
        if(getRandInt(0,5) == 0)
            addText(str(1));
        if(getHour() < 6 || getHour() > 21)
            addText(str(2));
        else if (getHour() == 6)
        {
            addText(str(3));
            addText(str(4));
        }
        else if(getHour() == 7 || getHour() == 13 || getHour() == 18)
            addText(str(5));
        else if(getHour() > 13 && getHour() < 18 && getWeekNum() == 0 && (getMonth() >= 5 || getMonth() <= 9))
            addText(str(6));
        else if(getHour() > 19 && getHour() < 22)
            addText(str(7));
        else if(getHour() > 20 && getHour() < 22)
            addText(str(8));

        //Логистика
        //////////

        if(getMonth() < 5 || getMonth() > 9 || getSunWeather() < 0)
        {
            if(getHour() > 7 && getHour() < 13)
                addText(str(10));
            else if(getHour() > 13 && getHour() < 18)
                addText(str(11));
        }
        if(gVEvent(mira_guest) == 1)
            addText(str(12));
        makeActBtn("to_gaddvor", str(13));
        makeActBtn("eat", str(15));
        drinkAll();
        cookies();
        fatDel();
        vitamin();
        pills();
        if(gVStatus(boletus) > 0 || gVStatus(bilberry) > 0)
        {
            makeActBtn("dry_food", str(17));
        }
        fancywork();
        home_workout();
        // gs 'zz_family', 'father_sheduler'

        // if $father['location'] = $curloc:
        // gs 'zz_render', '', '', 'В комнате отдыхают родители.'
        startEvent(eGadukinoEvents,"go_home");
        // end

        connect(getTextPtr(), &QLabel::linkActivated, this, &Gadhouse::actionHandler);
    }
    if(action == "to_gaddvor")
    {
        if(isCloth())
        {
            changeLoc(lgaddvor, 5);
        }
        else
        {
            addText(str(14));
        }
    }
    if(action == "eat")
    {
        eat();
        drink("tea");
        makeActBtn("gadhouse", str(16));
    }
    if(action == "dry_food")
    {
        uVStatus(eda, gVStatus(boletus) + gVStatus(bilberry));
        sVStatus(boletus,0);
        sVStatus(bilberry,0);
        setImage(media(1));
        setDesc(str(18));
        makeActBtn("gadhouse", str(19));
    }
    if(action == "grandma")
    {
        startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        startEvent(eGrandPa);
    }
    if(action == "loker")
    {
        viewObj("wardrobe");
    }
    if(action == "mirror")
    {
        viewObj("mirror");
    }
    if(action == "bed")
    {
        viewObj("bed");
    }
    if(action == "villagecat")
    {
        startEvent(eGrandParentEvents,"villagecat");
    }
    if(action == "zz_books_custom_shelf_0_9")
    {

    }
    if(action == "Miroslava")
    {
        startEvent(eMiroslava);
    }
    if(action == "HR_Nina")
    {
        startEvent(eLogistEvents,"HR_Nina");
    }
}

QString Gadhouse::str(int id)
{
    QString ded, bab;
    if(gVEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";
    if(gVEvent(grandpa_notalk) == 0)
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
    addActBtn(btn);
}
