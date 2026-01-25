#include "sitrpar.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

SitrPar::SitrPar(Game* ptr): root(ptr) {}

void SitrPar::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("sitrPar");
    else
        actionHandler(arg);
}

LocId SitrPar::getLocId()
{
    return lsitrpar;
}

LocId SitrPar::getParId()
{
    return lkorrpar;
}

LocId SitrPar::getLocIn()
{
    return lgorodok;
}

QString SitrPar::getLocName()
{
    return act(1);
}

bool SitrPar::isParent()
{
    return true;
}

void SitrPar::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "BedrPar2");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SitrPar::actionHandler);
    root->addActions(btn);
}

void SitrPar::actionHandler(QString action)
{
    if(action == "sitrPar")
    {
        root->incTime(1);
        makeActBtn("korrPar",act(0));
        root->setImage(media(0));
        root->setText(str(0));
        root->startEvent(eFamily, "mother_sheduler");
        if(root->gNPC(father).location != lgargazel)
            root->startEvent(eFamily, "father_sheduler");
        root->startEvent(eFamily, "brother_sheduler");

        int month = root->getMonth();
        int day = root->getDay();
        int week = root->getWeek();
        int hour = root->getHour();
        int min = root->getMin();

        if(month == 1 && day >= 1 && day <= 6 && hour >= 21 && hour < 23 && root->vQuest(qwKolkaNewYear) == 0 && root->vEvent(family_trip) == 0)
            root->startEvent(eBrotherEvents, "happy_ny_1");
        if(root->vBody(anus) >= 13 && root->vBody(vagina) >= 13)
        {
            if(root->vQuest(qwKolka) == 1 && week > 0 && week <= 6 && hour == 6)
                root->startEvent(eSisterQW, "incest_event2");
            if(root->vQuest(qwKolka) == 2 && week > 0 && week <= 5 && hour == 16)
                root->startEvent(eSisterQW, "incest_event3");
            if(root->vQuest(qwKolka) >= 3 && week <= 5 && hour == 16 && getRandInt(1,5) == 1)
                root->startEvent(eSisterQW, "incest_event3_sub");
            if(root->vQuest(qwKolka) == 6 && week >= 2 && week <= 5 && hour == 16 && min >= 30)
                root->startEvent(eSisterQW, "incest_event7");
        }
        if(root->vQuest(qwKolka) == 7 && root->vEvent(family_trip) == 0 && week == 0 && hour >= 9 && hour <= 11 && root->getItmCount(iLubri) > 0 && root->vQuest(qwOtchim) == 1)
            root->startEvent(eSisterQW, "incest_event8");
        if(root->vQuest(qwKolka) >= 8 && week == 6 && hour == 10 && root->vEvent(family_trip) == 0 && root->getItmCount(iLubri) > 0 && root->vStatus(horny) > 60)
            root->startEvent(eSisterQW, "incest_event8sub");
        //если гг голой или бухой в стельку завалилась в зал
        if(!root->isCloth() || root->vAddict(alko) >= 6)
        {
            if(root->gNPC(mother).location == lsitrpar)
            {
                root->startEvent(eMother);
                return;
            }
            if(root->gNPC(father).location == lsitrpar)
            {
                root->startEvent(eFather, "main");
                return;
            }
        }

        if(root->vQuest(TsarevMainQW) == 125 && root->gNPC(father).location == lsitrpar)
            root->startEvent(eTsarevEvents, "teacher_choice_detective12");

        if(root->gNPC(mother).location == lsitrpar && root->gNPC(father).location == lsitrpar && root->gNPC(brother).location == lsitrpar && root->vEvent(familyTvDay) != day)
            makeActBtn("family_watch_tv", act(1));

        if(week != 0 && root->gNPC(father).location == lsitrpar && root->gNPC(brother).location != lsitrpar && root->gNPC(mother).location != lsitrpar && root->vEvent(fatherCleanDay) != day && hour <= 19)
            root->startEvent(eFather, "cleaning");

        if(month == 12 && day >= 25)
            root->addText(str(1));

        if(month == 31 && day == 31 && hour >= 20)
            makeActBtn("meetNYwithFamily",act(2));
        else if(month == 1 && day == 1)
        {
            makeActBtn("endNYtable",act(3));
        }
        // !------------ Входящие звонки ------------
        //  gs 'zz_phone', 'boyfriend_call_init'
        //  if Gcall = 1 : exit
        //  gs 'zz_phone','oilers_call_init'
        //  if Gcall = 1 : exit
    }
    if(action == "korrPar")
    {
        root->changeLoc(lkorrpar);
    }
    if(action == "meetNYwithFamily")
    {
        root->changeRep('+',mother,20);
        root->changeRep('+',father,20);
        root->changeRep('+',sister,20);
        root->changeRep('+',brother,20);
        root->vStatus(money) += 5000;
        root->vStatus(day_weight) += 1;
        root->setTime(23,00);
        root->vStatus(mood) += 50;
        root->vStatus(energy) += 20;
        root->vStatus(water) += 20;
        root->setImage(media(1));
        root->setText(str(2));
        makeActBtn("sitrPar",act(5));
    }
    if(action == "endNYtable")
    {
        root->setImage(media(2));
        root->incTime(15);
        root->vStatus(cumLips) = 0;
        root->vStatus(day_weight) += 1;
        if(root->vStatus(energy) >= 50)
            root->setText(str(3));
        else
        {
            root->setText(str(4));
            root->vStatus(health) += 10;
            root->vStatus(mood) += 20;
            root->vStatus(energy) += 20;
            root->vStatus(water) += 20;
        }
        makeActBtn("sitrPar",act(4));
    }
    if(action == "family_watch_tv")
    {
        root->setImage(media(3));
        root->setText(str(5));
        root->startEvent(efamilySmallTalks, "tv_talk");
        root->changeRep('+',mother);
        root->changeRep('+',father);
        root->changeRep('+',brother);
        root->changeRep('+',sister);
        root->vStatus(mood) += getRandInt(1,5);
        root->incTime(getRandInt(50,70));
        root->vEvent(familyTvDay) = root->getDay();
        makeActBtn("sitrPar",act(6));
    }
}

QString SitrPar::str(int id)
{
    QString str[6];
    str[0] = "У окна стоит <a href='brother_events_watch_tv'>телевизор</a>. Напротив телевизора находится диван, на котором по ночам спит ваш брат. У стены стоит стенка с посудой и книгами.";
    str[1] = "Возле телевизора стоит новогодняя ёлка, украшенная игрушками и гирляндами.";
    str[2] = "Вы сели за праздничный стол, накрытый перед телевизором, и стали провожать Старый Год в семейном кругу под неизменные \"Голубой огонёк\" и \"Иронию судьбы, или С легким паром!\" по телевизору. За столом завязалась общая беседа, и проблемы были забыты, все веселились и разговаривали между собой. За несколько минут до полуночи, перед курантами, вы выслушали традиционные поздравления президента с не менее традиционными обещаниями, что в наступающем году обязательно станет всё лучше, если вы будете лучше трудиться. Затем выпили шампанского, чокаясь и поздравляя друг друга с новым годом. Мама вам подарила конвертик с поздравительной открыткой и пятью тысячами рублей. Какое-то время вы, продолжая смотреть телевизор, ели и пили шампанское, но вскоре стало заметно ,что члены семьи выдохлись и стали разбредаться поближе к кроватям.";
    str[3] = "Вы больше не можете есть.";
    str[4] = "Вы доедали салаты, оставшиеся на столе после праздника.";
    str[5] = "В комнате слышны тихие разговоры: ";
    return str[id];
}

QString SitrPar::act(int id)
{
    QString act[7];
    act[0] = "Выйти из комнаты";
    act[1] = "Зал";
    act[2] = "Встречать новый год с семьёй.";
    act[3] = "Доедать салаты с праздничного стола";
    act[4] = "Встать из-за стола";
    act[5] = "Уйти";
    act[6] = "Отойти";
    return act[id];
}

QString SitrPar::media(int id)
{
    QString med[4];
    med[0] = "data/locations/pavlovo/parents_home/guestroom.jpg";
    med[1] = "pavlovo/family/newyear"; // notfound
    med[2] = "data/actions/eat/food.jpg";
    med[3] = "data/actions/tv/family_tv.jpg";
    return med[id];

}
