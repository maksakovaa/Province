#include "gadforestrelax.h"
#include "../../menu/qactbutton.h"
#include "../../Functions.h"
#include "../eventhandler.h"

GadforestRelax::GadforestRelax(EventHandler* ptr): root(ptr) {}

void GadforestRelax::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("gadforestrelax");
    else
        actionHandler(arg);
}

void GadforestRelax::actionHandler(QString action)
{
    root->clearActions();
    if(action == "gadforestrelax")
    {
        if(!root->isNude())
        {
            if(!root->isSkirt())
            {
                if(root->gVEvent(bonfire) == 0)
                    root->setImage(media(0));
                else
                    root->setImage(media(1));
            }
            else
            {
                if(root->gVEvent(bonfire) == 0)
                    root->setImage(media(2));
                else if(root->isPanties())
                    root->setImage(media(3));
                else if(!root->isPanties())
                    root->setImage(media(4));
            }
        }
        else
        {
            root->setImage(media(5));
        }
        root->setDesc(str(0));
        int hour = root->getHour();
        if(root->gVEvent(lost) >= getRandInt(1,5) && root->gVEvent(bonfire) == 0 && (hour < root->getSunrise() || hour > root->getSunset()))
        {
            root->eventStart("gadforest_event","relax");
        }
        if(root->isCloth() && root->gVEvent(bonfire) == 0)
            makeActBtn("light_bonfire",act(0));
        if(root->isCloth() && root->gVEvent(bonfire) == 1)
        {
            if(root->vStatus(boletus_hot) == 1)
                makeActBtn("eat_boletus_hot",act(2));
            makeActBtn("warm_bonfire",act(3));
            makeActBtn("sleep_bonfire",act(4));
            if(root->vStatus(boletus) > 0)
                makeActBtn("make_hot_boletus",act(6));
        }
        if(root->gVEvent(bonfire) == 0)
        {
            makeActBtn("sit_grass",act(7));
            makeActBtn("sleep_grass",act(8));
        }
        if(root->vStatus(bilberry) > 0)
            makeActBtn("eat_bilbery",act(9));
        makeActBtn("search_road",act(10));
    }
    if(action == "light_bonfire")
    {
        root->incTime(10);
        root->sVEvent(bonfire,1);
        root->setImage(media(6));
        root->setDesc(str(1));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "eat_boletus_hot")
    {
        root->incTime(15);
        root->uVStatus(boletus_hot,-1);
        root->uVStatus(health,10);
        root->uVStatus(mood,20);
        root->eat("",media(7));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "warm_bonfire")
    {
        root->incTime(60);
        root->uVStatus(son,3);
        root->uVStatus(health,10);
        root->sVStatus(frost,0);
        root->uVStatus(mood,10);
        QString add;
        if(root->isDay())
            root->setImage(media(8));
        else
            root->setImage(media(9));
        root->setDesc(str(2));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "sleep_bonfire")
    {
        if(root->vStatus(son) < 20)
        {
            root->uVStatus(son,10);
            root->uVStatus(health,20);
            root->incTime(180);
            root->sVStatus(frost,0);
            root->uVStatus(mood,50);
            root->setImage(media(10));
            root->setDesc(str(3));
            makeActBtn("gadforestrelax",act(5));
        }
        if(root->vStatus(son) >= 20)
        {
            root->incTime(5);
            root->sVStatus(frost,0);
            root->setImage(media(10));
            root->setDesc(str(4));
            makeActBtn("gadforestrelax",act(1));
        }
    }
    if(action == "make_hot_boletus")
    {
        root->incTime(30);
        root->uVStatus(boletus_hot,1);
        root->uVStatus(boletus,-1);
        root->sVStatus(frost,0);
        root->setImage(media(11));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "sit_grass")
    {
        if(root->getTemp() < 15)
            root->uVStatus(health,-5);
        root->incTime(60);
        root->uVStatus(son,2);
        root->uVStatus(mood,10);
        if(!root->isNude())
        {
            if(!root->isSkirt())
                root->setImage(media(12));
            else
            {
                if(root->isPanties())
                    root->setImage(media(13));
                else
                    root->setImage(media(14));
            }
        }
        else
            root->setImage(media(15));
        root->setDesc(str(5));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "sleep_grass")
    {
        if(root->vStatus(son) < 24)
        {
            root->uVStatus(son,8);
            if(root->getTemp() < 15)
                root->uVStatus(health,-10);
            root->incTime(180);
            root->uVStatus(mood,20);
            if(!root->isNude())
            {
                if(!root->isSkirt())
                    root->setImage(media(16));
                else
                {
                    if(root->isPanties())
                        root->setImage(media(17));
                    else
                        root->setImage(media(18));
                }
            }
            else
                root->setImage(media(19));
            root->setDesc(str(3));
            makeActBtn("gadforestrelax",act(5));
        }
        else
        {
            root->incTime(5);
            root->setImage(media(20));
            root->setDesc(str(4));
            makeActBtn("gadforestrelax",act(1));
        }
    }
    if(action == "eat_bilbery")
    {
        root->incTime(10);
        root->uVStatus(energy,5);
        root->uVStatus(water,10);
        root->uVStatus(bilberry,-1);
        root->uVStatus(health,5);
        root->uVStatus(mood,10);
        root->setImage(media(21));
        root->setDesc(str(6));
        makeActBtn("gadforestrelax",act(1));
    }
    if(action == "search_road")
    {
        root->eventStart("gadforestlost","main");
    }
}

void GadforestRelax::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadforestRelax::actionHandler);
    root->addActBtn(btn);
}

QString GadforestRelax::str(int id)
{
    QString str[20];
    str[0] = "Вы устали и решили немного передохнуть.";
    str[1] = "Вы достали спички и решили разжечь костер...";
    str[2] = "В течение часа вы сидели молча, глядя на костер.Вы согрелись и отдохнули, наверное пора двигаться дальше.";
    str[3] = "Вы дремали около 3 часов и прснувшись почувствовали себя бодрее часа.";
    str[4] = "Вы пытаетесь уснуть, но у вас ничего не выходит.";
    str[5] = "В течение часа вы сидели молча, глядя себе под ноги. Вы немного отдохнули, наверное пора двигаться дальше.";
    str[6] = "Вы поели ягод.";
    return str[id];
}

QString GadforestRelax::act(int id)
{
    QString act[20];
    act[0] = "Разжечь костер";
    act[1] = "Далее";
    act[2] = "Поесть жареных грибов";
    act[3] = "Греться у костра";
    act[4] = "Прилечь вздремнуть у костра";
    act[5] = "Проснуться";
    act[6] = "Пожарить грибы на костре";
    act[7] = "Посидеть на траве";
    act[8] = "Прилечь вздремнуть";
    act[9] = "Поесть ягод";
    act[10] = "Искать дорогу";
    return act[id];
}

QString GadforestRelax::media(int id)
{
    QString med[22];
    med[0] = "data/locations/gadukino/forest/gadforestrelax1.jpg";
    med[1] = "data/locations/gadukino/forest/gadforestrelax2.jpg";
    med[2] = "data/locations/gadukino/forest/gadforestrelax_ski1.jpg";
    med[3] = "data/locations/gadukino/forest/gadforestrelax_ski2.jpg";
    med[4] = "data/locations/gadukino/forest/gadforestrelax_ski3.jpg";
    med[5] = "data/locations/gadukino/forest/gadforestrelax_nude1.3.jpg";
    med[6] = "data/locations/gadukino/forest/gadforestrelax_bonfire1.jpg";
    med[7] = "data/locations/gadukino/forest/boletuscook.jpg";
    med[8] = "data/locations/gadukino/forest/gadforestrelax_bonfire2.jpg";
    med[9] = "data/locations/gadukino/forest/gadforestrelax_bonfire3.jpg";
    med[10] = "data/locations/gadukino/forest/gadforestrelax_bonfiresleep.jpg";
    med[11] = "data/locations/gadukino/forest/boletushot.jpg";
    med[12] = "data/locations/gadukino/forest/gadforestrelax3.jpg";
    med[13] = "data/locations/gadukino/forest/gadforestrelax_ski4.jpg";
    med[14] = "data/locations/gadukino/forest/gadforestrelax_ski5.jpg";
    med[15] = "data/locations/gadukino/forest/gadforestrelax_nude1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[16] = "data/locations/gadukino/forest/gadforestrelax_sleep.jpg";
    med[17] = "data/locations/gadukino/forest/gadforestrelax_sleepski.jpg";
    med[18] = "data/locations/gadukino/forest/gadforestrelax_sleepski1.jpg";
    med[19] = "data/locations/gadukino/forest/gadforestrelax_sleepnude1." + intQStr(getRandInt(1,2)) + ".jpg";
    med[20] = "data/locations/gadukino/forest/gadforestrelax_nosleep.jpg";
    med[21] = "data/locations/gadukino/forest/bilberry.jpg";
    return med[id];
}
