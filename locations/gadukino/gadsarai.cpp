#include "gadsarai.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadsarai::Gadsarai(Game* ptr): root(ptr){}

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
    root->addActions(btn);
}

QString Gadsarai::str(int id)
{
    QString bab, ded;
    if(root->vEvent(grandma_notalk) == 0) { bab = "<a href='grandma'>бабушка</a>"; }
    else { bab = "сердитая бабушка"; }
    if(root->vEvent(grandpa_notalk) == 0) { ded = "<a href='grandpa'>дедушка</a>"; }
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
    root->clearActions();
    if (action == "grandma")
    {
        root->startEvent(eGrandMa);
    }
    if (action == "grandpa")
    {
        root->startEvent(eGrandPa);
    }
    if (action == "sarai")
    {
        root->startEvent(eGadukinoEvents, "gadsarai_check");

        root->setImage(makeImage(media(0),root->isDay(), root->getMonth()));
        root->setText(str(0));
        if(root->vEvent(mira_dog) == 0)
            root->addText(str(1));
        else
            root->addText(str(2));

        if (root->getSnow() == 0)
        {
            if(root->getHour() > 9 && root->getHour() < 19)
                root->addText(str(3));
            else if(root->getHour() == 19)
                root->addText(str(4));
            else
                root->addText(str(5));
            if (root->getHour() > 9 && root->getHour() < 20 && root->getWeek() > 1 || horse_river == 2)
                root->addText(str(6));
            else
                root->addText(str(7));
        }
        else
        {
            root->addText(str(5));
            root->addText(str(7));
        }
        root->addText(str(8));
        if (root->vEvent(findvel) == 1)
            root->addText(str(9));
        if(root->vEvent(grandma_ingadsarai) == 1)
            root->addText(str(10));
        if(root->vEvent(grandpa_ingadsarai) == 1)
            root->addText(str(11));
        makeActBtn("go_dvor", act(0));
        if (root->vEvent(card) == 0 || root->vEvent(findvel) == 0)
            makeActBtn("search", act(1));
        if(root->cardCheck() == 1)
            makeActBtn("takeCards",act(3));
        if (root->vStatus(horny) >= 50 && root->vEvent(grandparents_ingadsarai) == 0)
        {
            makeActBtn("mastr", act(4));
        }
        int month = root->getMonth(), SunWeather = root->getSunWeather(), hour = root->getHour(), week = root->getWeek();
        if (month >= 5 && month <= 9 && SunWeather >= 0 && hour > 13 && hour < 18 && week > 1 && week < 7 && root->vEvent(grandmaknowsick) == 1)
        {
            root->startEvent(eGrandMa);
        }
        if (root->vEvent(know_no_pirat) == 0)
        {
            root->clearActions();
            root->incTime(60);
            root->vEvent(know_no_pirat) = 1;
            root->setImage(media(1));
            root->setText(str(14));
            makeActBtn("sarai", act(5));
        }
        if (root->vSex(grandmaknowmastr) == 1 || root->vSex(grandpaknowmastr) == 1)
        {
            root->incTime(5);
            if (root->vSex(grandmaknowmastr) == 1)
            {
                root->vQuest(grandmaQW) -= 5;
                root->vEvent(grandma_notalk) = 1;
                root->setImage(media(2));
                root->setText(str(15));
            }
            else if(root->vSex(grandpaknowmastr) == 1)
            {
                root->vEvent(grandpa_notalk) = 1;
                root->setImage(media(3));
                root->setText(str(16));
            }
            makeActBtn("run", act(6));
        }
        root->startEvent(ePirat);
    }
    if (action == "go_dvor")
    {
        root->changeLoc(lgaddvor,5);
    }
    if (action == "search")
    {
        root->incTime(15);
        if (root->vEvent(findvel) == 0)
        {
            root->vEvent(findvel) = 1;
            root->setImage(media(4));
            root->setText(str(12));
        }
        else if (root->cardCheck() == 0)
        {
            root->vEvent(card) =1;
            root->cardInit(100,5);
            root->setImage(media(5));
            root->setText(str(13));
        }
        makeActBtn("sarai", act(2));
    }
    if (action == "takeCards")
    {
        root->setImage(media(5));
        root->setText("");
        makeActBtn("pullOutCard", act(7));
        makeActBtn("sarai", act(8));
    }
    if (action == "pullOutCard")
    {
        root->setImage(root->getCard());
        root->vStatus(horny) += root->getCardHorny();
        root->incTime(root->getCardTime());
        makeActBtn("takeCards", act(9));
    }
    if (action == "mastr")
    {
        root->selfPlayStart();
    }
    if (action == "run")
    {
        root->vSex(grandmaknowmastr) = 0;
        root->vSex(grandpaknowmastr) = 0;
        root->changeLoc(lgaddvor,1);
    }
    if (action == "mira_dog")
    {
        root->startEvent(eGrandParentEvents,"mira_dog");
    }
    if (action == "cow")
    {
        root->startEvent(eGrandParentEvents,"cow");
    }
    if(action == "horse")
    {
        root->startEvent(eGrandParentEvents,"horse");
    }
    if(action == "boar")
    {
        root->startEvent(eGrandParentEvents,"boar");
    }
    if(action == "bicycle")
    {
        root->startEvent(eBicycle,"sarai");
    }
    root->updateParams();
}
