#include "timeServer.h"
#include <chrono>
#include "Functions.h"
#include "menu/mainwindow.h"

TimeServer::TimeServer(Game *ptr): root(ptr)
{
    counters.division = 0;
    counters.min_05 = 0;
    counters.min_10 = 0;
    counters.min_15 = 0;
    counters.min_20 = 0;
    counters.min_30 = 0;
    counters.min_60 = 0;
    nul = intQStr(0);
}

TimeServer::TimeServer(Game *ptr, int year, int month, int day, int hour, int minutes) : root(ptr)
{
    counters.division = 0;
    counters.min_05 = 0;
    counters.min_10 = 0;
    counters.min_15 = 0;
    counters.min_20 = 0;
    counters.min_30 = 0;
    counters.min_60 = 0;

    currTimePoint.tm_year = year - 1900;
    currTimePoint.tm_mon = month - 1;
    currTimePoint.tm_mday = day;
    currTimePoint.tm_hour = hour;
    currTimePoint.tm_min = minutes;
    currTimePoint.tm_sec = 0;
    
    nul = intQStr(0);
    mktime(&currTimePoint);
    updOldTime();
    mktime(&oldTime);
}

QString TimeServer::getTime()
{
    QString hour, minutes;

    if(currTimePoint.tm_hour < 10)
        hour += nul;
    hour += intQStr(currTimePoint.tm_hour);

    if (currTimePoint.tm_min < 10)
        minutes += nul;
    minutes += QString::number(currTimePoint.tm_min);

    if (root->isCheats())
    {
        makeLink(hour, "hour");
        makeLink(minutes, "minutes");
    }
    
    return hour + ":" + minutes;
}

QString TimeServer::getDateStr()
{
    return getDateStr(currTimePoint);
}

QString TimeServer::getDateStr(struct tm tp)
{
    QString day, year, month;
    if (tp.tm_mday < 10)
        day += nul;
    day += intQStr(tp.tm_mday);
    if (tp.tm_mon + 1 < 10)
        month += nul;
    month += intQStr(tp.tm_mon +1);
    year += intQStr(tp.tm_year + 1900);
    if (root->isCheats())
    {
        makeLink(day, "day");
        makeLink(month, "month");
        makeLink(year, "year");
    }    
    return day + "." + month + "." + year;
}

QString TimeServer::getDayOfWeek()
{
    QString week[] {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    return week[currTimePoint.tm_wday];
}

int TimeServer::getYear()
{
    return currTimePoint.tm_year + 1900;
}

int TimeServer::getMonth()
{
    return currTimePoint.tm_mon + 1;
}

int TimeServer::getDay()
{
    return currTimePoint.tm_mday;
}

int TimeServer::getHour()
{
    return currTimePoint.tm_hour;
}

int TimeServer::getMin()
{
    return currTimePoint.tm_min;
}

int TimeServer::getWeekNum()
{
    return currTimePoint.tm_wday;
}

void TimeServer::firstStart()
{
    statNoTime();
    ElapsedTime();
    calcEnding();
    slotUpdParams();
}

int TimeServer::calcDateDiffInDays()
{
    std::chrono::time_point tp1 = std::chrono::system_clock::from_time_t(mktime(&currTimePoint));
    std::chrono::time_point tp2 = std::chrono::system_clock::from_time_t(mktime(&oldTime));
    auto diff = tp1 - tp2;
    return std::chrono::duration_cast<std::chrono::days>(diff).count();
}

void TimeServer::increaseTime(int minutes)
{
    if (minutes == 0)
    {
        slotUpdParams();
    }
    else
    {
        currTimePoint.tm_min += minutes;
        mktime(&currTimePoint);
        statNoTime();
        updCounters(minutes);
        calcEnding();
        slotUpdParams();
    }
}

void TimeServer::slotUpdParams()
{
    root->updateParams();
}

void TimeServer::statNoTime()
{
    //****************************************
    // автоприменение салфеток
    // if $settings['auto_wipes'] = 1: gs 'zz_common','wet_wipes',1

    //    ! наркомания
    root->setValues();
    //  if hour >= 21 and week = 7 and family_trip_month ! month: family_trip_month = month & family_trip = 0
    //  gs 'uni_events','university_status'
    //  ! Геморой с временем для Логистики "работы" - условия внесены из эстетических соображений
    //  if logist >= 4 and hour >= 10 and hour <= 17 and logist_progul_day ! day and logist_Otgul = 0: gs 'logist', 'logist_counter_time'
    //  ! Условия прогула работы в Логистике
    //  if logist >= 4 and hour => 12 and week <= 5 and logist_work_day ! day and logist_progul_day ! day and logist_day ! day and logist_Otgul =

    //  !Корректор отрицательных значений, так проще чем лазить по коду
    if(root->getItmCount(iWetWipes) < 0)
        root->setItemCount(iWetWipes,0);
    if(root->getItmCount(iCosmetic) < 0)
        root->setItemCount(iCosmetic,0);
    if(root->getItmCount(iCosmeticBig) < 0)
        root->setItemCount(iCosmeticBig,0);
    if(root->getItmCount(iCondoms) < 0)
        root->setItemCount(iCondoms,0);
    if(root->getItmCount(iAntiPregPills) < 0)
        root->setItemCount(iAntiPregPills,0);
    if(root->getItmCount(iLubri) < 0)
        root->setItemCount(iLubri,0);
    if(root->vStatus(pregnancy) < 0)
    {
        root->vStatus(pregnancy) = 0;
        root->vStatus(pregnancyKnow) = 0;
    }
    // if abonement < 0: abonement = 0
    // if tkan < 0: tkan = 0

    // !расчет попоболь
    root->vSex(stat_vgape) = root->vSex(vgape)/24;
    root->vSex(stat_agape) = root->vSex(agape)/24;
    if(root->vSex(analplay) >= 2 && root->vBody(anus) <= 10)
    {
        root->vBody(anus) += 1; root->vSex(analplay) = 0;
    }
    if(root->vSex(analplay) >= 4 && root->vBody(anus) <= 15)
    {
        root->vBody(anus) += 1; root->vSex(analplay) = 0;
    }
    if (root->vSex(analplay) >= 8 && root->vBody(anus) <= 20)
    {
        root->vBody(anus) += 1; root->vSex(analplay) = 0;
    }
    if(root->vAddict(alko) > 0) root->vStatus(frost) = 0;

    // if func('zz_reputation','get') > 0:
    // $_gnik[0] = $stat_str[1]
    // $_gnik[1] = $stat_str[2]
    // $_gnik[2] = $stat_str[3]
    // $_gnik[3] = $stat_str[4]
    // $gnikname = $_gnik[func('zz_reputation','get')-1]

    // !!!Новая формула развратности основана на собранной статистике.(старая формула: shameless = guy+bj+anal+hj+(slutty*2)+(gang*2)) bj+anal+hj+slutty+gang
    root->calcShamelessFlag();

    // if husbizvradd > 5:izvratH = 1
    // if husbharmin > 10:harakHusb = 0
    // if husband = 0:
    //     husbizvradd = 0
    //     husbharmin = 0
    //     husbandMark = 0
    // end

    root->vSick(Venera) = 0;
    if (root->vSick(VeneraOnce) > 0) root->vSick(VeneraOnce) = 0;
    if (root->vSick(SifacOnce) == 1) root->vSick(Venera) += 1;
    if (root->vSick(GerpesOnce) == 1) root->vSick(Venera) += 1;
    if (root->vSick(TriperOnce) == 1) root->vSick(Venera) += 1;

    root->vEvent(father_horny) = valChecker(root->vEvent(father_horny));
    root->vSchool(progress) = valChecker(root->vSchool(progress), 0, 100);
    root->vSkill(posSkill) = valChecker(root->vSkill(posSkill),0,100);
    root->vSkill(vokal) = valChecker(root->vSkill(vokal));
    root->vSkill(dance) = valChecker(root->vSkill(dance));
    root->vSkill(danceStrip) = valChecker(root->vSkill(danceStrip));
    root->vSkill(dancePole) = valChecker(root->vSkill(dancePole));
    root->vEvent(goforest) = valChecker(root->vEvent(goforest));
    root->vEvent(bucket) = valChecker(root->vEvent(bucket),0,10);
    root->vSkill(runner) = valChecker(root->vSkill(runner),0,2000);
    root->vSkill(oficiant) = valChecker(root->vSkill(oficiant));
    root->vBody(vagina) = valChecker(root->vBody(vagina));
    root->vBody(throat) = valChecker(root->vBody(throat));
    root->vBody(anus) = valChecker(root->vBody(anus));
    root->vSkill(jab) = valChecker(root->vSkill(jab),0,120);
    root->vSkill(punch) = valChecker(root->vSkill(punch),0,120);
    root->vSkill(kik) = valChecker(root->vSkill(kik),0,120);
    root->vSkill(kikDef) = valChecker(root->vSkill(kikDef),0,120);
    root->vSkill(boxing) = valChecker(root->vSkill(boxing),0,120);
    root->vSkill(volleyball) = valChecker(root->vSkill(volleyball),0,100);
    root->vSkill(strenght) = valChecker(root->vSkill(strenght));
    root->vSkill(speed) = valChecker(root->vSkill(strenght));
    root->vSkill(agility) = valChecker(root->vSkill(agility));
    root->vSkill(react) = valChecker(root->vSkill(react));
    root->vSkill(endurance) = valChecker(root->vSkill(endurance));
    root->vSkill(intellect) = valChecker(root->vSkill(intellect));
    root->vSkill(domination) = valChecker(root->vSkill(domination),-100,100);
    root->vStatus(horny) = valChecker(root->vStatus(horny));
    root->vStatus(health) = valChecker(root->vStatus(health));
    root->vSex(stat_vgape) = valChecker(root->vSex(stat_vgape),0,3);
    root->vSex(stat_agape) = valChecker(root->vSex(stat_agape),0,3);
    root->vSex(spanked) = valChecker(root->vSex(spanked));
    root->vSkill(boxing) = root->vSkill(jab) / 4 + root->vSkill(punch) / 4 + root->vSkill(kik) / 4 + root->vSkill(kikDef) / 4;

    // if bfa < 0:bfa = 0

    if(root->vStatus(vidageday) <= 0)
    {
        root->vStatus(vidageday) = 360;
        root->vBody(vidage) +=1;
    }

    if (root->vStatus(mood) >= (100 - root->vSex(spanked))) root->vStatus(mood) = 100 - root->vSex(spanked);

    //Бесплодие при barrenness = 100 беременность блокируется. Рабочий диапазон от 0 до 99
    //Чем выше число тем труднее зачать, зависит от многих причин.
    //Выл/Вкл беременности в Настройках, по умолчанию включено
    //barrenness = 100
    //barrenness = 0
    
    if(root->vStatus(horny) >= root->vStatus(last_horny))
        root->vStatus(last_horny) = root->vStatus(horny);
    else    //Проверка на оргазм(любой)
    {
        if(root->vStatus(horny) == 0)
        {
            root->vStatus(vaginal_grease) -= root->vStatus(vaginal_grease)/4;
            root->vStatus(last_horny) = 0;
            root->vStatus(hour_lust) = root->vConst(max_hour_lust);
            root->vStatus(soft_lust) = 1;
        }
    }
}

void TimeServer::Elapsed5minutes()
{

}

void TimeServer::Elapsed10minutes()
{
    if (root->vStatus(hormonal_drug) == 1)
    {
        if (root->vSex(vibratorIN) == 1)
        {
            root->vStatus(horny) += getRandInt(1,2);
        }
    }
    else
    {
        if (root->vSex(vibratorIN) == 1)
        {
            root->vStatus(horny) += getRandInt(7,14);
        }
    }
    if (root->vSex(analplugIN) == 1 && root->vSex(analStore) <= root->vBody(anus))
    {
        root->vSex(analStore) = root->vBody(anus);
    }
    if (root->vSex(analplugIN) == 1 && root->vSex(analStore) != 0)
    {
        root->vBody(anus) = root->vSex(analStore);
    }
    if (root->vSex(analplugIN) == 0)
    {
        root->vSex(analStore) = 0;
    }
}

void TimeServer::Elapsed15minutes()
{
    if (root->vSex(agape) > 0)
    {
        root->vSex(agape) -= 1;
    }
}

void TimeServer::Elapsed20minutes()
{
    root->calcRubbing();
    if (root->vSex(vgape) > 0)
    {
        root->vSex(vgape) -= 1;
    }
}

void TimeServer::Elapsed30minutes()
{
    root->vagGelTouch();
}

void TimeServer::Elapsed60minutes()
{
    if(root->vStatus(pregnancy) == 0) { root->vStatus(inc_preg_weight) = 0; }
    if(root->vStatus(pregnancy) > 0) { root->slotPregRecalc(); }

    if(root->vStatus(hygiene) <= 0) { root->vStatus(hygiene) = 0; }
    else { root->vStatus(hygiene) -= 1; }

    if(root->vStatus(nerdism) > 0)
    {
        root->vStatus(nerdism) -= 1;
        root->vStatus(mood) -= 4 - root->vStatus(nerdism)/20;
    }

    if(root->vStatus(no_sleep_time) > 0)
    {
        root->vStatus(mood) -= 5;
        root->vStatus(health) -= 2;
    }

    if(root->vSex(spanked) > 0)
    {
        root->vSex(spanked) -=1;
    }

    if(root->vStatus(obkvsdam) > 0)
    {
        root->vStatus(obkvsdam) = getRandInt(2,5);
    }

    if(root->vStatus(energy) < 8)
    {
        root->vStatus(mood) -= 2;
        root->vStatus(hungry_time) += 1;
    }

    if(root->vStatus(energy) >= 24)
    {
        root->vStatus(hungry_time) = 0;
    }
    root->vStatus(energy) -= 1;
    if(root->vSex(analplugIN) == 1)
    {
        root->vStatus(mood) += getRandInt(2,7);
    }

    if(root->vStatus(hormonal_drug) == 0 && root->vStatus(addHorny) >= 1)
    {
        root->vStatus(horny) += getRandInt(1, root->vStatus(addHorny));
    }
    else if (root->vStatus(hormonal_drug) == 0 && root->vStatus(addHorny) <= 0)
    {
        root->vStatus(horny) += getRandInt(root->vStatus(addHorny),1);
    }

    if(root->vStatus(shamelessFlag) == 0)
    {
        root->vStatus(shameless_lust_min) = 0;
        root->vStatus(shameless_lust_max) = 1;
    }

    if(root->vStatus(shamelessFlag) > 0)
    {
        root->vStatus(shameless_lust_min) = 0;
        root->vStatus(shameless_lust_max) = root->vStatus(shamelessFlag);
    }

    if(root->vStatus(hour_lust) > 0 && root->vStatus(soft_lust) == 1)
    {
        root->vStatus(hour_lust) -= 1;
        if(root->vStatus(hour_lust) == 0)
        {
            root->vStatus(soft_lust) = 0;
        }
        root->vStatus(div_lust) = 50;
        if(root->vStatus(hormonal_drug) == 1)
        {
            root->vStatus(div_lust) = 60;
        }
    }
    else
    {
        root->vStatus(soft_lust) = 0;
        root->vStatus(div_lust) = 30;
        if(root->vStatus(hormonal_drug) == 1)
        {
            root->vStatus(div_lust) = 40;
        }
    }

    int randLust = getRandInt(root->vStatus(shameless_lust_min), root->vStatus(shameless_lust_max));
    if(root->vStatus(lust) < 100) { root->vStatus(lust) += randLust; }
    if(root->vStatus(lust) > 100) { root->vStatus(lust) = 100; }
    int hornyInc = root->vStatus(lust)/root->vStatus(div_lust) - root->vStatus(hour_lust)/3;
    root->vStatus(horny) += hornyInc;
    if(root->vStatus(horny) > 100) { root->vStatus(horny) = 100; }
    if(root->vStatus(horny) < 0) { root->vStatus(horny) = 0; }
    if(root->vStatus(horny) >= 95) { root->vStatus(mood) -= getRandInt(1,3);}

    root->sexCorrector();
    root->decRubbing(vagina);
    root->decRubbing(anus);

    //Пьянство отходняк алкоголизм
    root->slotDataInitAlko();
    root->slotHangOver();
    root->slotRiscsUpdate();

    root->vStatus(water) -= 1;
    if(root->vStatus(water) < 8) { root->vStatus(mood) -= 2; }
    if(root->vStatus(InSleep) == 0) { root->vStatus(son) -= 1; }

    if(root->vAddict(alko) >= root->vAddict(maxAlko) && root->vAddict(alkoday) != root->vStatus(daystart))
    {
        root->vAddict(alko) = root->vStatus(daystart);
        if(root->vSkill(intellect) > 10) { root->vSkill(intellect) -= 1; }
        if(root->vSkill(volleyball) > 10) { root->vSkill(volleyball) -= 1; }
        if(root->vSkill(jab) > 10) { root->vSkill(jab) -= 1; }
        if(root->vSkill(punch) > 10) { root->vSkill(punch) -= 1; }
        if(root->vSkill(kik) > 10) { root->vSkill(kik) -= 1; }
        if(root->vSkill(kikDef) > 10) { root->vSkill(kikDef) -= 1; }
        if(root->vSkill(runner) > 10) { root->vSkill(runner)  -= 1; }
        if(root->vSkill(strenght) > 10) { root->vSkill(strenght) -= 1; }
        if(root->vSkill(endurance) > 10) { root->vSkill(endurance) -= 1; }
        if(root->vSkill(react) > 10) { root->vSkill(react) -= 1; }
        if(root->vSkill(speed) > 10) { root->vSkill(speed) -= 1; }
        if(root->vSkill(agility) > 10) { root->vSkill(agility) -= 1; }
        root->vAddict(alko) -= 1;
    }

    //cumstatus
    if(root->vStatus(cumFace) > 0) { root->vStatus(cumFace) -= 1; }
    if(root->vStatus(cumLips) > 0) { root->vStatus(cumLips) -= 1; }
    if(root->vStatus(cumBelly) > 0) { root->vStatus(cumBelly) -= 1; }
    if(root->vStatus(cumAss) > 0) { root->vStatus(cumAss) -= 1; }
    if(root->vStatus(cumPussy) > 0) { root->vStatus(cumPussy) -= 1; }
    if(root->vStatus(cumAnus) > 0) { root->vStatus(cumAnus) -= 1; }

    if(root->vBody(lipbalmstat) > 0) { root->vBody(lipbalmstat) -= 1; }
    if(root->vSick(sickStage) == 1) { root->vSick(sick) += 1; root->vSick(sickTimer) += 1; }
    if(root->vSick(sickStage) == 1 && root->vSick(sickTimer) == 80)
    {
        root->vSick(sickTimer) = 0;
        root->vSick(sickStage) = 2;
    }
    if(root->vSick(sickStage) == 2 && root->vSick(sick) > 0)
    { root->vSick(sick) -= 1; }
    if(root->vSick(sickStage) == 2 && root->vSick(sick) <= 0)
    {
        root->vSick(sick) = 0;
        root->vSick(sickStage) = 0;
    }

    if(root->vStatus(sweat) > 2)
    {
        root->updSkin('-',1);
    }

    if(root->vStatus(clearClothes) > 0) { root->vStatus(clearClothes) -= 1; }

    if(root->vEvent(hantersAndreisex) > 0)
        root->vEvent(hantersAndreisex) -= 1;
    if(root->vEvent(hantersSergeisex) > 0)
        root->vEvent(hantersSergeisex) -= 1;
    if(root->vEvent(hantersIgorsex) > 0)
        root->vEvent(hantersIgorsex) -= 1;
    if(root->vEvent(hantslutsex) > 0)
        root->vEvent(hantslutsex) -= 1;
    if(root->vEvent(mira_dog) > 0)
        root->vEvent(mira_dog) -= 1;
    if(root->vEvent(mira_go_blok) > 0)
        root->vEvent(mira_go_blok) -= 1;
    if(root->vEvent(lost_girl) > 0)
        root->vEvent(lost_girl) -= 1;
    if(root->vEvent(mira_no_home) > 0)
        root->vEvent(mira_no_home) -= 1;

    if(root->vStatus(vaginal_grease) > root->vConst(many_vaginal_grease))
    {
        root->vStatus(panties_grease) = (root->vStatus(vaginal_grease) - root->vConst(many_vaginal_grease))/10;
    }

    root->checkPanties();

    root->hourRecalc();

    // проверка статуса ветки Царева - Светка прогуляла свидание - закрываем ветку
    if(root->vQuest(TsarevMainQW) == 116 || root->vQuest(TsarevMainQW) == 118 && root->vQuest(TsarevMainQWday) != root->getDay() && root->getHour() >= 21)
        root->vQuest(TsarevMainQW) = 255;

    if(root->vStatus(vaginal_grease) > root->vConst(max_vaginal_grease))
    {
        root->vStatus(sweat) += 1;
        root->vStatus(mood) -= 10;
    }

    if(root->vStatus(isprok) == 0 && root->vStatus(mesec) > 0 && root->vStatus(pregnancy) == 0)
    {
        //message
        root->vStatus(sweat) += 1;
        root->vStatus(mood) -= 10;
        root->decreaseClothCond();
    }
}

void TimeServer::ElapsedDay()
{
    if(root->vStatistics(peek1day) > 0) { root->vStatistics(peek1day) = 0; }
    if(root->vStatistics(peek2day) > 0) { root->vStatistics(peek2day) = 0; }
    if(root->vStatistics(peek3day) > 0) { root->vStatistics(peek3day) = 0; }
    if(root->vStatistics(peek4day) > 0) { root->vStatistics(peek4day) = 0; }

    if(root->vSex(painpub) > 0) { root->vSex(painpub) -= 1; }
    if(root->vSex(nippain) > 0) { root->vSex(nippain) -= 1; }

    //gs 'zz_reputation','increase_all'

    // gs 'zz_school','recalc_stats'

    if(root->vBody(colorfulLenses) > 0) { root->vBody(colorfulLenses) -= 1; }
    if(root->vBody(blizoruk) < 200) { root->vBody(blizoruk) -= 1; }
    if(root->vBody(blizoruk) < 0) { root->vBody(blizoruk) = 0; }

    if(root->vStatus(mood) < 10) { root->vSick(crazy) += 1; }
    if(root->vStatus(no_sleep_time) >= 36) { root->vSick(crazy) += 1; }
    if(root->vStatus(mood) >= 25 && root->vSick(crazy) > 0) { root->vSick(crazy) -=1; }
    if(root->vSick(crazy) >= 12) { /*gameover*/ }

    if(root->vSex(pirs_pain_ton) > 0) { root->vSex(pirs_pain_ton) -= 1; }
    if(root->vBody(eyeBrows) > 19) { root->vBody(eyeBrows) = 19; }
    if(root->vBody(eyeBrows) > 0) { root->vBody(eyeBrows) -= 1; }
    if(root->vBody(hairLength) > 0)
    {
        root->vBody(hairLengthDay) += 1;
        if(root->vBody(hairLengthDay) >= 60)
        {
            root->vBody(hairLengthDay) = 0;
            root->vBody(hairLength) -= 1;
        }
    }

    if(root->vStatus(horny) > root->vStatus(hornyStat))
    {
        root->vStatus(hornyStat) = root->vStatus(horny);
        if(root->vBody(piercingA) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingB) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingC) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingD) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingE) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingF) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingG) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingN) > 0) { root->vStatus(horny) += 1; }
        if(root->vBody(piercingGL) > 0) { root->vStatus(horny) += 1; }
    }
    if(root->vStatus(horny) < root->vStatus(hornyStat)) { root->vStatus(hornyStat) = root->vStatus(horny); }

    root->vStatus(daystart) += 1;

    //gs 'zz_school','vacation_status'
    //ЗПП
    if (root->vSick(SifacOnce) == 1) root->vSick(Sifilis) += 1;
    if (root->vSick(GerpesOnce) == 1) root->vSick(Gerpes) += 1;
    if (root->vSick(TriperOnce) == 1) root->vSick(Triper) += 1;
    if (root->vSick(KandidozOnce) == 1) root->vSick(Kandidoz) += 1;
    
    if(root->vSkill(runner) >= 100)
    {
        root->vSkill(runner) = root->vSkill(runner) / 500;
    }
    else
    {
        root->vSkill(runner) = 0;
    }

    root->vStatus(vidageday) -= 1;
 
/* 
 	if husband > 0:husbanday += 1
	if husband > 10 and husbanday > 0:husband -= 15
	if husbandMark = 1 and husband <= 10:
		husbizvradd = 0
		husbharmin = 0
		husbandMark = 0
		husband = 0
		divorced += 1
		!Ваш муж подал на развод.
		gs 'zz_render','','','<red>'+$stat_str[6]+'</red>'
	end*/

    root->slotMenstruus();
    root->slotEstrus();
}

void TimeServer::ElapsedTime()
{
    if (root->vStatus(son) <= 0)
    {
        root->vStatus(no_sleep_time) += 1;
        if (root->vStatus(no_sleep_time) >= 60)
        {
            root->startEvent(eGameOver, "12");
        }
        root->vStatus(son) = 0;
        root->vStatus(mood) -= 5;
    }
    if (root->vStatus(son) > 24) root->vStatus(son) = 24;
    if (root->vStatus(energy) < 0)
    {
        root->vStatus(energy) = 0;
        root->vStatus(health) -= 1;
    }
    if (root->vStatus(water) < 0)
    {
        root->vStatus(water) +=1;
        root->vStatus(health) -= 1;
    }
    if (root->vStatus(mood) < 0)
    {
        root->vStatus(mood) = 0;
    }
    if (root->vStatus(health) < 0)
    {
        root->startEvent(eGameOver,"0");
    }

    if(root->vStatistics(raped) > 0 && root->vStatistics(raped) != root->vSex(rape_count) && root->vStatistics(orgasm) == root->vSex(orgasm_count))
    {
        root->vStatus(mood) = 10;
        root->vSex(rape_count) = root->vStatistics(raped);
    }
    else if(root->vStatistics(orgasm) > 0 && root->vStatistics(orgasm) != root->vSex(orgasm_count))
    {
        root->vStatus(mood) = 100;
        root->vSex(orgasm_count) = root->vStatistics(orgasm);
    }
    else if(root->vStatistics(raped) > 0 && root->vStatistics(raped) != root->vSex(rape_count) && root->vStatistics(orgasm) > 0 && root->vStatistics(orgasm) != root->vSex(orgasm_count))
    {
        root->vStatus(mood) = 100;
        root->vSex(orgasm_count) = root->vStatistics(orgasm);
        root->vSex(rape_count) = root->vStatistics(raped);
    }
    
    //! Смотрим был ли прогул работы в "Школьнике" сегодня:
    //! Смотрим прогуляла ли ГГ бизнес-командировку от "Школьника"
    //! Смотрим прогуляла ли ГГ работу в качестве директора магазина "Школьник"    
}

void TimeServer::calcEnding()
{
    root->slotAlkoholism();
    if (root->vStatus(mesec) > 0 && root->vStatus(vnesh) > 3)
    {
        root->vStatus(vnesh) -= 3 + root->vStatus(vneshAlko);
    }
    else
    {
        root->vStatus(vnesh) += root->vStatus(sexyAppeal) - root->vStatus(vneshAlko);
    }
    int vagDump = root->getVagDamp();
    if(vagDump >= 3)
    {
        root->vStatus(vnesh) += 2-vagDump;
    }

    root->updBody();
    root->updateParams();

    root->vStatus(horny) = valChecker(root->vStatus(horny),1,100);
    root->vStatus(lust) = valChecker(root->vStatus(lust),1,100);
    root->vStatus(health) = valChecker(root->vStatus(health));
    root->vStatus(mood) = valChecker(root->vStatus(mood));
    root->vStatus(energy) = valChecker(root->vStatus(energy),0,24);
    root->vStatus(water) = valChecker(root->vStatus(water),0,24);
    root->vStatus(son) = valChecker(root->vStatus(son),0,24);

    root->fnWeather();

    if(root->vStatus(sweat) > 4) root->vStatus(sweat) = 4;
}

void TimeServer::updCounters(int min)
{
    if (min == 0)
    {
        return;
    }
    
    int time = min + counters.division;
    counters.division = 0;

    while (time != 0)
    {
        if (time >= 5)
        {
            counters.min_05++;
            time -= 5;
        }
        else
        {
            counters.division = time;
            time = 0;
        }
        chkCounters();
    }
}

void TimeServer::chkCounters()
{

    if (counters.min_05 == 2)
    {
        counters.min_10++;
        counters.min_05 = 0;
        Elapsed10minutes();
    }

    if (counters.min_10 == 1 && counters.min_05 == 1)
    {
        Elapsed15minutes();
    }

    if (counters.min_10 == 2)
    {
        counters.min_20++;
        counters.min_10 = 0;
        Elapsed20minutes();
    }

    if (counters.min_20 == 1 && counters.min_10 == 1)
    {
        counters.min_30++;
        counters.min_20 = 0;
        counters.min_10 = 0;
        Elapsed30minutes();
    }

    if (counters.min_30 == 2)
    {
        counters.min_60++;
        counters.min_30 = 0;
        Elapsed60minutes();
        ElapsedTime();
    }

    if(counters.min_60 == 24)
    {
        counters.min_60 = 0;
        ElapsedDay();
    }
}

void TimeServer::isDayOver()
{
    int dayDiff = calcDateDiffInDays();
    if (dayDiff > 0)
    {
        while (dayDiff != 0)
        {
            ElapsedDay();
            dayDiff--;
        }
        updOldTime();
    }
}

void TimeServer::updOldTime()
{
    oldTime.tm_year = currTimePoint.tm_year;
    oldTime.tm_mon = currTimePoint.tm_mon;
    oldTime.tm_mday = currTimePoint.tm_mday;
    oldTime.tm_hour = currTimePoint.tm_hour;
    oldTime.tm_min = currTimePoint.tm_min;
    oldTime.tm_sec = currTimePoint.tm_sec;
    mktime(&oldTime);
}

int TimeServer::calcYears(struct tm from)
{
    std::chrono::time_point tp1 = std::chrono::system_clock::from_time_t(mktime(&currTimePoint));
    std::chrono::time_point tp2 = std::chrono::system_clock::from_time_t(mktime(&from));
    auto diff = tp1 - tp2;
    return std::chrono::duration_cast<std::chrono::years>(diff).count();
}

void TimeServer::setTime(int hour, int min)
{
    struct tm pointEnd = currTimePoint;
    pointEnd.tm_hour = hour;
    pointEnd.tm_min = min;
    std::chrono::time_point tp1 = std::chrono::system_clock::from_time_t(mktime(&currTimePoint));
    std::chrono::time_point tp2 = std::chrono::system_clock::from_time_t(mktime(&pointEnd));
    int result = 0;
    if(pointEnd.tm_hour > currTimePoint.tm_hour)
    {
        auto diff = tp2 - tp1;
        result = std::chrono::duration_cast<std::chrono::minutes>(diff).count();
        increaseTime(result);
    }
}

