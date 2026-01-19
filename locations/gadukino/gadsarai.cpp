#include "gadsarai.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
Gadsarai::Gadsarai(LocationHandler* ptr): Location(ptr){}

void Gadsarai::show(QString arg)
{
    actionHandler("sarai");
}

LocId Gadsarai::getLocId()
{
    return lgadsarai;
}

LocId Gadsarai::getParId()
{
    return lgaddvor;
}

LocId Gadsarai::getLocIn()
{
    return lgadukino;
}

QString Gadsarai::getLocName()
{
    return "Сарай";
}

bool Gadsarai::isParent()
{
    return true;
}

void Gadsarai::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadsarai");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadsarai::actionHandler);
    addActBtn(btn);
}

QString Gadsarai::str(int id)
{
    QString bab, ded;
    if(gVEvent(grandma_notalk) == 0) { bab = "<a href='grandma'>бабушка</a>"; }
    else { bab = "сердитая бабушка"; }
    if(gVEvent(grandpa_notalk) == 0) { ded = "<a href='grandpa'>дедушка</a>"; }
    else { ded = "дедушка"; }
    QString str[17];
    str[0] = "Ветхий сарай в котором хранятся инструменты.";
    str[1] = "Возле сарая пустует будка Пирата.";
    str[2] = "Возле сарая стоит будка Пирата в которой на цепи сидит голая <a href='mira_dog'>Мира</a>.";
    str[3] = "Справа находится загон для коровы.";
    str[4] = "<a href='grandma'>Бабушка</a> в загоне доит корову Зорьку .";
    str[5] = "Справа находится загон для <a href='cow'>коровы</a>.";
    str[6] = "Слева находится загон для коня.";
    str[7] = "Слева находится загон с <a href='horse'>конем</a>.";
    str[8] = "В отдельном загоне живет <a href='boar'>кабан</a>.";
    str[9] = "В углу стоит старый <a href='bicycle'>велосипед</a>.";
    str[10] = "В сарае ковыряется ваша " + bab + ",";
    str[11] = "В сарае что-то делает ваш " + ded + ".";
    str[12] = "В дальнем углу сарая вам удаётся найти старый велосипед. На удивление, он в хорошем состоянии";
    str[13] = "В шкафчике старые журналы \"Здоровье\", \"Техника молодежи\" и пыльные пожелтевшие книги.<br>\"Хмм, а это что такое?\" - подумали вы, когда нашли колоду карт.";
    str[14] = "- А где же Пират? Наверное сбежал, сволочь, - подумали с грустью вы, осматривая пустую будку и с нежностью вспоминая своего любимого пса.";
    str[15] = "- Ах ты бесстыдница!, - услышали вы голос бабушки. - А ну-ка брысь отсюда, пока дубцом не получила! Ишь чего удумала!";
    str[16] = "- Кхе-кхе! - неожиданно вы услышали дедушкин голос. Он стоял и во все глаза смотрел на вас.<br>- Ой!, - воскликнули вы от неожиданности и бросились со всег ног прочь, на ходу поправляя одежду.";
    return str[id];
}

QString Gadsarai::act(int id)
{
    QString act[10];
    act[0] = "Выйти во двор";
    act[1] = "Ковыряться в сарае";
    act[2] = "Положить на место";
    act[3] = "Взять колоду карт";
    act[4] = "Мастурбировать";
    act[5] = "Далее";
    act[6] = "Убежать";
    act[7] = "Вытянуть карту";
    act[8] = "Убрать карты";
    act[9] = "Положить в колоду";

    return act[id];
}

QString Gadsarai::media(int id)
{
    QString med[6];
    med[0] = "data/locations/gadukino/gaddvor/sarai.jpg";
    med[1] = "data/qwest/gadukino/know_no_pirat.jpg";
    med[2] = "data/npc/gadukino/grandma/grandma.jpg";
    med[3] = "data/npc/gadukino/grandpa/grandpa.jpg";
    med[4] = "data/actions/transport/bicycle/findvel.jpg";
    med[5] = "data/qwest/card/Cor.jpg";
    return med[id];
}

void Gadsarai::actionHandler(QString action)
{
    clearActions();
    if (action == "grandma")
    {
        startEvent(eGrandMa);
    }
    if (action == "grandpa")
    {
        startEvent(eGrandPa);
    }
    if (action == "sarai")
    {
        startEvent(eGadukinoEvents, "gadsarai_check");

        setImage(makeImage(media(0),isDay(), getMonth()));
        setDesc(str(0));
        if(gVEvent(mira_dog) == 0)
            addText(str(1));
        else
            addText(str(2));

        if (getSnow() == 0)
        {
            if(getHour() > 9 && getHour() < 19)
                addText(str(3));
            else if(getHour() == 19)
                addText(str(4));
            else
                addText(str(5));
            if (getHour() > 9 && getHour() < 20 && getWeekNum() > 1 || horse_river == 2)
                addText(str(6));
            else
                addText(str(7));
        }
        else
        {
            addText(str(5));
            addText(str(7));
        }
        addText(str(8));
        if (gVEvent(findvel) == 1)
            addText(str(9));
        if(gVEvent(grandma_ingadsarai) == 1)
            addText(str(10));
        if(gVEvent(grandpa_ingadsarai) == 1)
            addText(str(11));
        makeActBtn("go_dvor", act(0));
        if (gVEvent(card) == 0 || gVEvent(findvel) == 0)
            makeActBtn("search", act(1));
        if(cardCheck() == 1)
            makeActBtn("takeCards",act(3));
        if (gVStatus(horny) >= 50 && gVEvent(grandparents_ingadsarai) == 0)
        {
            makeActBtn("mastr", act(4));
        }
        int month = getMonth(), SunWeather = getSunWeather(), hour = getHour(), week = getWeekNum();
        if (month >= 5 && month <= 9 && SunWeather >= 0 && hour > 13 && hour < 18 && week > 1 && week < 7 && gVEvent(grandmaknowsick) == 1)
        {
            startEvent(eGrandMa);
        }
        if (gVEvent(know_no_pirat) == 0)
        {
            clearActions();
            incTime(60);
            sVEvent(know_no_pirat, 1);
            setImage(media(1));
            setDesc(str(14));
            makeActBtn("sarai", act(5));
        }
        if (gVSex(grandmaknowmastr) == 1 || gVSex(grandpaknowmastr) == 1)
        {
            incTime(5);
            if (gVSex(grandmaknowmastr) == 1)
            {
                uVQuest(grandmaQW,-5);
                sVEvent(grandma_notalk,1);
                setImage(media(2));
                setDesc(str(15));
            }
            else if(gVSex(grandpaknowmastr) == 1)
            {
                sVEvent(grandpa_notalk, 1);
                setImage(media(3));
                setDesc(str(16));
            }
            makeActBtn("run", act(6));
        }
        startEvent(ePirat);
    }
    if (action == "go_dvor")
    {
        changeLoc(lgaddvor,5);
    }
    if (action == "search")
    {
        incTime(15);
        if (gVEvent(findvel) == 0)
        {
            sVEvent(findvel, 1);
            setImage(media(4));
            setDesc(str(12));
        }
        else if (cardCheck() == 0)
        {
            sVEvent(card,1);
            cardInit(100,5);
            setImage(media(5));
            setDesc(str(13));
        }
        makeActBtn("sarai", act(2));
    }
    if (action == "takeCards")
    {
        setImage(media(5));
        setDesc("");
        makeActBtn("pullOutCard", act(7));
        makeActBtn("sarai", act(8));
    }
    if (action == "pullOutCard")
    {
        setImage(getCard());
        uVStatus(horny,getCardHorny());
        incTime(getCardTime());
        makeActBtn("takeCards", act(9));
    }
    if (action == "mastr")
    {
        startSelfPlay();
    }
    if (action == "run")
    {
        sVSex(grandmaknowmastr,0);
        sVSex(grandpaknowmastr,0);
        changeLoc(lgaddvor,1);
    }
    if (action == "mira_dog")
    {
        startEvent(eGrandParentEvents,"mira_dog");
    }
    if (action == "cow")
    {
        startEvent(eGrandParentEvents,"cow");
    }
    if(action == "horse")
    {
        startEvent(eGrandParentEvents,"horse");
    }
    if(action == "boar")
    {
        startEvent(eGrandParentEvents,"boar");
    }
    if(action == "bicycle")
    {
        startEvent(eBicycle,"sarai");
    }
    updateParams();
}
