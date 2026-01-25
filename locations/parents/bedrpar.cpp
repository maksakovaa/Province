#include "bedrpar.h"
#include "../../menu/buttons.h"
#include "../../npc/npc_enum.h"
#include "../../game.h"

BedrPar::BedrPar(Game* ptr): root(ptr){}

void BedrPar::show(QString arg)
{
    int hour = root->getHour();
    int week = root->getWeek();
    int month = root->getMonth();

    if(root->vQuest(qwSisterBoy) > 10)
        root->vQuest(qwSisterBoy) = 10;
    root->incTime(1);
    root->setImage(img(0));
    root->setText(str(0));
    if(root->vQuest(qwSisterLesbi) >= 3 && week == 0 && root->gNPC(sister).relation >= 80 && root->vEvent(sister_show) == 0 && hour >= 10 && hour <= 11 && root->vEvent(family_trip) == 0)
        root->startEvent(eDinSister,"sister_show");
    if(root->vQuest(gets_bicycleQW) >= 10 && month >= 9 && hour >= 9 && root->vEvent(have_bicycle) == 0 && root->vEvent(msg_bicycle) == 0)
        root->sendNotif(str(7));
    if((root->getItmCount(iDildo) >= 1 || root->getItmCount(iMidDildo) >= 1 || root->getItmCount(iLargeDildo) >= 1 || root->getItmCount(iBigDildo) || root->getItmCount(iExtraDildo) >= 1
         || root->getItmCount(iSuperDildo) >= 1 || root->getItmCount(iMadDildo) >= 1) && root->vEvent(turnirWin) == 1 && root->vBody(anus) >= 13 && root->vStatus(shamelessFlag) == 3
        && root->vBody(vagina) >= 13 && root->gNPC(brother).sex >= 3 && root->vQuest(qwKolka) == 0 && week == 5 && hour == 23)
    {
        root->startEvent(eSisterQW,"incest_event1");
    }

    if(root->vQuest(qwKolka) >= 5 && root->vQuest(qwShopping) == root->getDay() && week == 0 && hour == 22 && root->vEvent(family_trip) == 0)
    {
        if(root->getItmCount(iAntiPregPills) > 0 && root->vBody(anus) >= 13 && root->vBody(vagina) >= 13)
            root->startEvent(eSisterQW,"incest_event6");
        if(root->vBody(anus) >= 13 && root->vBody(vagina) >= 18 && root->getItmCount(iLargeDildo) >= 1 && root->vStatus(horny) >= 40)
            root->startEvent(eSisterQW,"incest_event6sub");
    }
    if(root->vBody(anus) >= 13 && root->vBody(vagina) >= 13)
    {
        if(root->vEvent(incest_event9_flag) == 1 && root->vQuest(qwKolka) == 8)
            root->startEvent(eSisterQW,"incest_event9");
        if(root->vEvent(incest_event10_flag) == 1 && root->vQuest(qwKolka) == 9)
            root->startEvent(eSisterQW,"incest_event10");
    }

    if(root->vQuest(qwMisha) == 1 && week == 6 && hour == 10 && root->getItmCount(iLubri) > 0 && root->vQuest(anayslut) == 0 && root->vQuest(wedding) == 0 && root->vBody(anus) >= 18 && root->vBody(vagina) >= 18)
        root->startEvent(eSisterQW,"incest_event11");
    if(root->vQuest(wedding) == 1 && hour == 18 && root->vEvent(family_trip) == 0)
        root->startEvent(eSisterQW,"incest_mini1");
    if(root->vQuest(wedding) == 1 && hour == 17 && root->vEvent(family_trip) == 0)
        root->startEvent(eSisterQW,"incest_mini2");

    //if arrsize('books') = 0: gs 'zz_books','init'

    if(root->getItmCount(iLaptop) == 1)
        root->addText(str(1));
    if(root->vSick(sick) < 1)
        root->home_workout();
    else
        root->addText(str(2));

    if(((((week >= 1 && week <= 4) || week == 0) && hour < 6) || (week == 5 && hour >= 22) || ((week == 6 || week == 0) && hour < 9)) && root->vEvent(rexCarCount) >= 9 && root->vEvent(rexSmsDay) != root->vStatus(daystart) && root->vEvent(smsForRex) < 13)
        makeActBtn("takeSisPhone",act(10));
    makeActBtn("korrPar",act(1));
    root->waiting();
    makeActBtn("locker",act(2));
    makeActBtn("bed",act(3));
    makeActBtn("books",act(4));

    root->startEvent(eFamily,"brother_sheduler");
    root->startEvent(eFamily,"sister_sheduler");

    root->fancywork();
    if(root->vEvent(reading_erotic_enable) == 1 && hour >= 18 && hour < 21 && root->eroReaded() > 0)
        root->eroBlock();
    if(root->vStatus(horny) >= 50 && root->gNPC(sister).location != getLocId())
        makeActBtn("selfplay",act(5));

    if(root->getItmCount(iPornMagazine) > 0)
    {
        root->addText(str(3));
        if(root->gNPC(sister).location != getLocId())
            root->read_porn();
    }

    if(root->vJob(tovarL) > 0)
        root->addText(str(4));
    if(root->cardCheck() == 1)
        makeActBtn("takeCards",act(6));
    if(root->gNPC(sister).location != getLocId() && root->vQuest(TsarevMainQWday) != root->getDay())
    {
        if(root->vQuest(TsarevMainQW) == 103)
            root->addText(str(5));
        if(root->vQuest(TsarevMainQW) >= 105 && root->vQuest(TsarevMainQW) <= 112)
            root->addText(str(6));
        if((root->vQuest(TsarevMainQW) == 115 || root->vQuest(TsarevMainQW) == 117) && hour >= 8 && hour <= 18 && !root->isMesec())
            root->startEvent(eTsarevEvents,"teacher_choice_detective9");
        if(root->vQuest(TsarevMainQW) == 120)
            root->startEvent(eTsarevEvents,"teacher_choice_detective11");
    }

    //gs 'zz_school','homework'
    // if university['student'] > 0 and (month <= 6 or month >= 9):
    //    if university['course'] = 1:
    //         act func('bedrPar_strings'+$lang, 'act8'): gt'uni_events','course_work'
    //    else
    //         act func('bedrPar_strings'+$lang, 'act9'): gt'uni_events','graduate_work'
    //    end
    // end

    if(root->getItmCount(iLaptop) == 1)
        makeActBtn("Komp",act(9));

    ////////////////////////
    ///
    /// gs 'zz_phone', 'boyfriend_call_init'
    /// if Gcall = 1 : exit
    /// gs 'zz_phone','oilers_call_init'
    /// if Gcall = 1 : exit
}

LocId BedrPar::getLocId()
{
    return lbedrpar;
}

LocId BedrPar::getParId()
{
    return lkorrpar;
}

LocId BedrPar::getLocIn()
{
    return lgadukino;
}

QString BedrPar::getLocName()
{
    return "Ваша комната";
}

bool BedrPar::isParent()
{
    return true;
}

void BedrPar::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "BedrPar");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &BedrPar::actionHandler);
    root->addActions(btn);
}

void BedrPar::actionHandler(QString action)
{
    if(action == "takeSisPhone")
    {
        root->startEvent(eReks, "sms");
    }
    if(action == "korrPar")
        root->changeLoc(lkorrpar,5);
    if(action == "locker")
        root->viewObj("wardrobe");
    if(action == "bed")
        root->viewObj("bed");
    if(action == "selfplay")
        root->selfPlayStart();
    if(action == "Komp")
    {

    }
    if(action == "takeCards")
    {
        root->setImage(img(1));
        root->setText("");
        makeActBtn("pullOutCard", act(11));
        makeActBtn("back_to_cur_loc", act(12));
    }
    if(action == "pullOutCard")
    {
        root->setImage(root->getCard());
        root->vStatus(horny) += root->getCardHorny();
        root->incTime(root->getCardTime());
        makeActBtn("takeCards", act(13));
    }
    if (action == "books")
    {
        root->viewObj("books");
    }
    
}

QString BedrPar::str(int id)
{
    QString str[8];
    str[0] = "Маленькая комната, куда с трудом втиснулись <a href='loker'>шкаф</a>, ваши <a href='bed'>кровать</a> и кровать сестры, письменный стол и <a href='zz_books'>книжная полка</a>.";
    str[1] = "На столе стоит ваш <a href='Komp'ноутбук</a>.";
    str[2] = "Вы болеете, поэтому заниматься физическими упражнениями совсем не хочется.";
    str[3] = "Под матрацем у вас спрятан порножурнал.";
    str[4] = "У вас хранится <<tovarL>> единиц мелкого товара. Максимально вы можете хранить в своей комнате 30 единиц товара.";
    str[5] = "С вашей головы никак не выходят мысли об увиденном в доме Царева, может, стоит все <a href='tsarev_events_teacher_choice_detective4'>тщательно обдумать?</a>";
    str[6] = "Зайдя в комнату, вы вспоминаете, что надо бы <a href='tsarev_events_teacher_choice_detective5'>проверить соц сети</a> с форумами - вдруг всплывет что-то интересное о Цареве.";
    str[7] = "Вы хотите получить велосипед(В процессе написания)";
    return str[id];
}

QString BedrPar::act(int id)
{
    QString act[14];
    act[0] = "Ваша комната";
    act[1] = "Выйти из комнаты";
    act[2] = "Шкаф";
    act[3] = "Кровать";
    act[4] = "Книжная полка";
    act[5] = "Мастурбировать";
    act[6] = "Взять колоду карт";
    act[7] = "Писать курсовую работу";
    act[8] = "Писать дипломную работу";
    act[9] = "Ноутбук";
    act[10] = "Взять телефон сестры";
    act[11] = "Вытянуть карту";
    act[12] = "Убрать карты";
    act[13] = "Положить в колоду";
    return act[id];
}

QString BedrPar::img(int id)
{
    QString med[2];
    med[0] = "data/locations/pavlovo/parents_home/my_bedr_parents.jpg";
    med[1] = "data/qwest/card/Cor.jpg";
    return med[id];
}
