#include "kuhrpar.h"
#include "../../menu/buttons.h"
#include "../../game.h"
KuhrPar::KuhrPar(Game* ptr): root(ptr) {}

void KuhrPar::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("kuhrPar");
    else
        actionHandler(arg);
}

LocId KuhrPar::getLocId()
{
    return lkuhrpar;
}

LocId KuhrPar::getParId()
{
    return lkorrpar;
}

LocId KuhrPar::getLocIn()
{
    return lgorodok;
}

QString KuhrPar::getLocName()
{
    return act(1);
}

bool KuhrPar::isParent()
{
    return true;
}

void KuhrPar::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "korrparr");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &KuhrPar::actionHandler);
    root->addActions(btn);
}

void KuhrPar::actionHandler(QString action)
{
    if(action == "kuhrPar")
    {
        root->incTime(1);
        int week = root->getWeek();
        int hour = root->getHour();
        int day = root->getDay();

        if(root->vQuest(qwKolka) == 3 && week > 0 && week <= 4 && root->vStatus(horny) >= 30 && hour == 0)
            root->startEvent(eSisterQW,"incest_event4");
        if(root->vQuest(qwKolka) == 4 && week > 0 && week <= 5 && root->vStatus(horny) >= 30 && hour == 6 && root->vBody(anus) >= 13 && root->vBody(vagina) >= 13)
            root->startEvent(eSisterQW, "incest_event5");
        makeActBtn("korrPar",act(0));
        root->setImage(media(0));
        // семейство завтракает
        if (hour == 7 && root->vEvent(family_trip) == 0)
        {
            if(root->vEvent(famBreakfastDay) != day && week > 0 && week < 6)
                makeActBtn("family_breakfast",act(2));
            if(root->vQuest(qwSonya) == 20 && root->vQuest(qwSonyaDay) != day)
            {
                root->startEvent(eSonya,"father_talk_about_sonya");
            }
            root->setText(str(0));
        }
        else
            root->setText(str(1));
        root->startEvent(eFamily, "mother_sheduler");
        root->startEvent(eFamily, "father_sheduler");
        root->startEvent(eFamily, "brother_sheduler");
        if(root->gNPC(mother).location == lkuhrpar && (!root->isCloth() || root->vAddict(alko) >= 6))
        {
            root->startEvent(eMother);
            return;
        }
        root->kitchenActsAll();
        root->startEvent(eKolkaPrince, "main");
        /////////////////////////////////////////////
        /// !------------ Входящие звонки ------------
        /// gs 'zz_phone', 'boyfriend_call_init'
        /// if Gcall = 1 : exit
        /// gs 'zz_phone','oilers_call_init'
        /// if Gcall = 1 : exit
        /// ////////////////////////////////////////
    }
    if(action == "family_breakfast")
    {
        root->eat();
        root->drink("tea");
        root->setText(str(2));
        root->startEvent(efamilySmallTalks, "kitchen_talk");
        root->changeRep('+',father);
        root->changeRep('+',mother);
        root->changeRep('+',brother);
        if(root->getWeek() > 0 && root->getWeek() < 6)
            root->changeRep('+',sister);
        root->vEvent(famBreakfastDay) = root->getDay();
        makeActBtn("kuhrPar",act(3));
    }
}

QString KuhrPar::str(int id)
{
    QString str[20];
    str[0] = "За столом сидят и завтракают <a href='father_main'>отчим</a> и ваш брат <a href='brother_main'>Колька</a>. <a href='mother'>Мать</a>, как всегда, крутится возле плиты.";
    if(root->getWeek() > 0 && root->getWeek() <= 5)
        str[0] += "<br><a href='sister'>Анька</a>, хоть и говорит, что против диет, но с утра лишь чай пьёт.";
    str[1] = "На кухне, рядом с плитой, находится мойка. Большой холодильник стоит в углу. У стены находится кухонный стол со стульями.";
    str[2] = "Во время заврака происходят занятные разговоры:";
    return str[id];
}

QString KuhrPar::act(int id)
{
    QString act[10];
    act[0] = "Выйти из комнаты";
    act[1] = "Кухня";
    act[2] = "Позавтракать с семьёй";
    act[3] = "Встать из-за стола";
    return act[id];
}

QString KuhrPar::media(int id)
{
    QString med[20];
    med[0] = "data/locations/pavlovo/parents_home/kitchen.jpg";
    return med[id];
}
