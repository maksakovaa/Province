#include "bedrpar.h"
#include "../../menu/buttons.h"
#include "../../npc/npc_enum.h"

BedrPar::BedrPar(LocationHandler* ptr): Location(ptr) {}

void BedrPar::show(QString arg)
{
    int hour = getHour();
    int week = getWeekNum();
    int month = getMonth();

    if(gVQuest(qwSisterBoy) > 10)
        sVQuest(qwSisterBoy,10);
    incTime(1);
    setImage(img(0));
    setDesc(str(0));
    if(gVQuest(qwSisterLesbi) >= 3 && week == 0 && gNPC(AnyaLebedeva).relation >= 80 && gVEvent(sister_show) == 0 && hour >= 10 && hour <= 11 && gVEvent(family_trip) == 0)
        startEvent(eDinSister,"sister_show");
    if(gVQuest(gets_bicycleQW) >= 10 && month >= 9 && hour >= 9 && gVEvent(have_bicycle) == 0 && gVEvent(msg_bicycle) == 0)
        sendNotif(str(7));
    if((getItemCount(iDildo) >= 1 || getItemCount(iMidDildo) >= 1 || getItemCount(iLargeDildo) >= 1 || getItemCount(iBigDildo) || getItemCount(iExtraDildo) >= 1
         || getItemCount(iSuperDildo) >= 1 || getItemCount(iMadDildo) >= 1) && gVEvent(turnirWin) == 1 && gVBody(anus) >= 13 && gVStatus(shamelessFlag) == 3
        && gVBody(vagina) >= 13 && gNPC(KolyaSkryabin).sex >= 3 && gVQuest(qwKolka) == 0 && week == 5 && hour == 23)
    {
        startEvent(eSisterQW,"incest_event1");
    }

    if(gVQuest(qwKolka) >= 5 && gVQuest(qwShopping) == getDay() && week == 0 && hour == 22 && gVEvent(family_trip) == 0)
    {
        if(getItemCount(iAntiPregPills) > 0 && gVBody(anus) >= 13 && gVBody(vagina) >= 13)
            startEvent(eSisterQW,"incest_event6");
        if(gVBody(anus) >= 13 && gVBody(vagina) >= 18 && getItemCount(iLargeDildo) >= 1 && gVStatus(horny) >= 40)
            startEvent(eSisterQW,"incest_event6sub");
    }
    if(gVBody(anus) >= 13 && gVBody(vagina) >= 13)
    {
        if(gVEvent(incest_event9_flag) == 1 && gVQuest(qwKolka) == 8)
            startEvent(eSisterQW,"incest_event9");
        if(gVEvent(incest_event10_flag) == 1 && gVQuest(qwKolka) == 9)
            startEvent(eSisterQW,"incest_event10");
    }

    if(gVQuest(qwMisha) == 1 && week == 6 && hour == 10 && getItemCount(iLubri) > 0 && gVQuest(anayslut) == 0 && gVQuest(wedding) == 0 && gVBody(anus) >= 18 && gVBody(vagina) >= 18)
        startEvent(eSisterQW,"incest_event11");
    if(gVQuest(wedding) == 1 && hour == 18 && gVEvent(family_trip) == 0)
        startEvent(eSisterQW,"incest_mini1");
    if(gVQuest(wedding) == 1 && hour == 17 && gVEvent(family_trip) == 0)
        startEvent(eSisterQW,"incest_mini2");

    //if arrsize('books') = 0: gs 'zz_books','init'

    if(getItemCount(iLaptop) == 1)
        addText(str(1));
    if(gVSick(sick) < 1)
        home_workout();
    else
        addText(str(2));

    if(((((week >= 1 && week <= 4) || week == 0) && hour < 6) || (week == 5 && hour >= 22) || ((week == 6 || week == 0) && hour < 9)) && gVEvent(rexCarCount) >= 9 && gVEvent(rexSmsDay) != gVStatus(daystart) && gVEvent(smsForRex) < 13)
        makeActBtn("takeSisPhone",act(10));
    makeActBtn("korrPar",act(1));
    //wait button
    makeActBtn("locker",act(2));
    makeActBtn("bed",act(3));
    makeActBtn("books",act(4));
    //gs 'zz_family', 'brother_sheduler'
    //gs 'zz_family', 'sister_sheduler'
    fancywork();
    //if reading['erotic_enable'] = 1 and hour >= 18 and hour < 21 and func('zz_books','ero_readed') > 0: gt 'zz_books', 'erotic_block'
    if(gVStatus(horny) >= 50 && gNPC(AnyaLebedeva).location != getLocId())
        makeActBtn("selfplay",act(5));

    if(getItemCount(iPornMagazine) > 0)
    {
        addText(str(3));
        if(gNPC(AnyaLebedeva).location != getLocId())
            read_porn();
    }

    if(gVJob(tovarL) > 0)
        addText(str(4));
    if(cardCheck() == 1)
        makeActBtn("takeCards",act(6));
    if(gNPC(AnyaLebedeva).location != getLocId() && gVQuest(TsarevMainQWday) != getDay())
    {
        if(gVQuest(TsarevMainQW) == 103)
            addText(str(5));
        if(gVQuest(TsarevMainQW) >= 105 && gVQuest(TsarevMainQW) <= 112)
            addText(str(6));
        if((gVQuest(TsarevMainQW) == 115 || gVQuest(TsarevMainQW) == 117) && hour >= 8 && hour <= 18 && !isMesec())
            startEvent(eTsarevEvents,"teacher_choice_detective9");
        if(gVQuest(TsarevMainQW) == 120)
            startEvent(eTsarevEvents,"teacher_choice_detective11");
    }

    //gs 'zz_school','homework'
    // if university['student'] > 0 and (month <= 6 or month >= 9):
    //    if university['course'] = 1:
    //         act func('bedrPar_strings'+$lang, 'act8'): gt'uni_events','course_work'
    //    else
    //         act func('bedrPar_strings'+$lang, 'act9'): gt'uni_events','graduate_work'
    //    end
    // end

    if(getItemCount(iLaptop) == 1)
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
    addActBtn(btn);
}

void BedrPar::actionHandler(QString action)
{
    if(action == "takeSisPhone")
    {
        startEvent(eReks, "sms");
    }
    if(action == "korrParr")
        changeLoc(lkorrpar,5);
    if(action == "locker")
        viewObj("wardrobe");
    if(action == "bed")
        viewObj("bed");
    if(action == "selfplay")
        startSelfPlay();
    if(action == "Komp")
    {

    }
    if(action == "takeCards")
    {
        setImage(img(1));
        setDesc("");
        makeActBtn("pullOutCard", act(11));
        makeActBtn("back_to_cur_loc", act(12));
    }
    if(action == "pullOutCard")
    {
        setImage(getCard());
        uVStatus(horny,getCardHorny());
        incTime(getCardTime());
        makeActBtn("takeCards", act(13));
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
