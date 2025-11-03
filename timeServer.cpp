#include "timeServer.h"
#include <chrono>
#include "Functions.h"
#include "mainwindow.h"

TimeServer::TimeServer(QWidget* ptr, int year, int month, int day, int hour, int minutes): root(ptr)
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

    if (((MainWindow*)root)->page4->settings()->isCheats())
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
    if (((MainWindow*)root)->page4->settings()->isCheats())
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
    // Elapsed5minutes();
    // Elapsed10minutes();
    // Elapsed15minutes();
    // Elapsed20minutes();
    // Elapsed30minutes();
    // Elapsed60minutes();
    // ElapsedDay();
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
    ((MainWindow*)root)->slotUpdParams();
}

void TimeServer::statNoTime()
{
    //****************************************
    // автоприменение салфеток
    // if $settings['auto_wipes'] = 1: gs 'zz_common','wet_wipes',1
    //    ! наркомания
    //  gs 'zz_drugs','set_values'
    //  if hour >= 21 and week = 7 and family_trip_month ! month: family_trip_month = month & family_trip = 0
    //  gs 'uni_events','university_status'
    //  ! Геморой с временем для Логистики "работы" - условия внесены из эстетических соображений
    //  if logist >= 4 and hour >= 10 and hour <= 17 and logist_progul_day ! day and logist_Otgul = 0: gs 'logist', 'logist_counter_time'
    //  ! Условия прогула работы в Логистике
    //  if logist >= 4 and hour => 12 and week <= 5 and logist_work_day ! day and logist_progul_day ! day and logist_day ! day and logist_Otgul = 
    //  !Корректор отрицательных значений, так проще чем лазить по коду
    // if salfetka < 0: salfetka = 0
    // if kosmetica < 0: kosmetica = 0
    // if condom < 0: condom = 0
    // if tabletki < 0: tabletki = 0
    // if lubri < 0: lubri = 0
    // if abonement < 0: abonement = 0
    // if tkan < 0: tkan = 0
    // if pregnancy <= 0:pregnancy = 0 & pregnancyKnow = 0
    // !расчет попоболь
    setVSex(stat_vgape,vSex(vgape)/24);
    setVSex(stat_agape, vSex(agape)/24);
    if(vSex(analplay) >= 2 && vBody(anus) <= 10)
    {
        updVBody(anus,1); setVSex(analplay,0);
    }
    if (vSex(analplay) >= 4 && vBody(anus) <= 15)
    {
        updVBody(anus,1); setVSex(analplay,0);
    }
    if (vSex(analplay) >= 8 && vBody(anus) <= 20)
    {
        updVBody(anus,1); setVSex(analplay,0);
    }
    if(vAddict(alko) > 0) setVStatus(frost,0);
    // if func('zz_reputation','get') > 0:
    // $_gnik[0] = $stat_str[1]
    // $_gnik[1] = $stat_str[2]
    // $_gnik[2] = $stat_str[3]
    // $_gnik[3] = $stat_str[4]
    // $gnikname = $_gnik[func('zz_reputation','get')-1]

    // !!!Новая формула развратности основана на собранной статистике.(старая формула: shameless = guy+bj+anal+hj+(slutty*2)+(gang*2)) bj+anal+hj+slutty+gang
    ((MainWindow*)root)->m_player->calcShamelessFlag();

    // if husbizvradd > 5:izvratH = 1
    // if husbharmin > 10:harakHusb = 0
    // if husband = 0:
    //     husbizvradd = 0
    //     husbharmin = 0
    //     husbandMark = 0
    // end

    setVSick(Venera ,0);
    if (vSick(VeneraOnce) > 0) setVSick(VeneraOnce,0);
    if (vSick(SifacOnce) == 1) updVSick(Venera, 1);
    if (vSick(GerpesOnce) == 1) updVSick(Venera, 1);
    if (vSick(TriperOnce) == 1) updVSick(Venera, 1);
//    !-------
//    !Задаём учёт гормональных противозачаточных
//    !Влияют на вес снижают либидо
//    !-
//    father['horny'] = func('zz_funcs','checker',father['horny'])
//    school['progress'] = func('zz_funcs','checker',school['progress'],0,100)
    // poSkill = func('zz_funcs','checker',poSkill,0,1000)
    // vokal = func('zz_funcs','checker',vokal)
    // dance = func('zz_funcs','checker',dance)
    // stripdance = func('zz_funcs','checker',stripdance)
    // poledance = func('zz_funcs','checker',poledance)
    // goforest = func('zz_funcs','checker',goforest)
    // bucket = func('zz_funcs','checker',bucket,0,10)
    // beg = func('zz_funcs','checker',beg,0,2000)
    // oficiant = func('zz_funcs','checker',oficiant)
    // vagina = func('zz_funcs','checker',vagina)
    // throat = func('zz_funcs','checker',throat)
    // anus = func('zz_funcs','checker',anus)
    // Jab = func('zz_funcs','checker',Jab,0,120)
    // Punch = func('zz_funcs','checker',Punch,0,120)
    // Kik = func('zz_funcs','checker',Kik,0,120)
    // KikDef = func('zz_funcs','checker',KikDef,0,120)
    // boxing = func('zz_funcs','checker',boxing,0,120)
    // volleyboll = func('zz_funcs','checker',volleyboll,0,100)
    // stren = func('zz_funcs','checker',stren)
    // speed = func('zz_funcs','checker',speed)
    // agil = func('zz_funcs','checker',agil)
    // react = func('zz_funcs','checker',react)
    // vital = func('zz_funcs','checker',vital)
    // intel = func('zz_funcs','checker',intel)
    // dom = func('zz_funcs','checker',dom,-100,100)
    // horny = func('zz_funcs','checker',horny)
    // health = func('zz_funcs','checker',health)
    // stat_vgape = func('zz_funcs','checker',stat_vgape,0,3)
    // stat_agape = func('zz_funcs','checker',stat_agape,0,3)
    // spanked = func('zz_funcs','checker',spanked)
    // !--
    // boxing = Jab/4 + Punch/4 + Kik/4 + KikDef/4
    // !--
    // if bfa < 0:bfa = 0
    if(vStatus(vidageday) <= 0)
    {
        setVStatus(vidageday,360);
        updVBody(vidage,1);
    }

    if (vStatus(mood) >= (100 - vSex(spanked))) setVStatus(mood, 100 - vSex(spanked));

    //Бесплодие при barrenness = 100 беременность блокируется. Рабочий диапазон от 0 до 99
    //Чем выше число тем труднее зачать, зависит от многих причин.
    //Выл/Вкл беременности в Настройках, по умолчанию включено
    //barrenness = 100
    //barrenness = 0
    
    if(vStatus(horny) >= vStatus(last_horny))
        setVStatus(last_horny, vStatus(horny));
    else    //Проверка на оргазм(любой)
    {
        if(vStatus(horny) == 0)
        {
            updVStatus(vaginal_grease, -vStatus(vaginal_grease)/4);
            setVStatus(last_horny,0);
            setVStatus(hour_lust, vConst(max_hour_lust));
            setVStatus(soft_lust,1);
        }
    }
}

void TimeServer::Elapsed5minutes()
{

}

void TimeServer::Elapsed10minutes()
{
    if (vStatus(hormonal_drug) == 1)
    {
        if (vSex(vibratorIN) == 1)
        {
            updVStatus(horny,getRandInt(1,2));
        }
    }
    else
    {
        if (vSex(vibratorIN) == 1)
        {
            updVStatus(horny,getRandInt(7,14));
        }
    }
    if (vSex(analplugIN) == 1 && vSex(analStore) <= vBody(anus))
    {
        setVSex(analStore,vBody(anus));
    }
    if (vSex(analplugIN) == 1 && vSex(analStore) != 0)
    {
        setVBody(anus, vSex(analStore));
    }
    if (vSex(analplugIN) == 0)
    {
        setVSex(analStore,0);
    }
}

void TimeServer::Elapsed15minutes()
{
    if (vSex(agape) > 0)
    {
        updVSex(agape,-1);
    }
}

void TimeServer::Elapsed20minutes()
{
    ((MainWindow*)root)->m_ccsex.slotCalcRubbing();
    if (vSex(vgape) > 0)
    {
        updVSex(vgape,-1);
    }
}

void TimeServer::Elapsed30minutes()
{
    ((MainWindow*)root)->m_ccsex.slotVagGelTouch();
}

void TimeServer::Elapsed60minutes()
{
    if(vStatus(pregnancy) == 0) { setVStatus(inc_preg_weight,0); }
    if(vStatus(pregnancy) > 0) { ((MainWindow*)root)->m_reproductSys.slotPregRecalc(); }

    if(vStatus(hygiene) <= 0) { setVStatus(hygiene, 0); }
    else { updVStatus(hygiene,-1); }

    if(vStatus(nerdism) > 0)
    {
        updVStatus(nerdism,-1);
        updVStatus(mood, -(4 - vStatus(nerdism)/20));
    }

    if(vStatus(no_sleep_time) > 0)
    {
        updVStatus(mood, -5);
        updVStatus(health, -2);
    }

    if(vSex(spanked) > 0)
    {
        updVSex(spanked, -1);
    }

    if(vStatus(obkvsdam) > 0)
    {
        setVStatus(obkvsdam, getRandInt(2,5));
    }

    if(vStatus(energy) < 8)
    {
        updVStatus(mood, -2);
        updVStatus(hungry_time,1);
    }

    if(vStatus(energy) >= 24)
    {
        setVStatus(hungry_time, 0);
    }
    updVStatus(energy, -1);
    if(vSex(analplugIN) == 1)
    {
        updVStatus(mood, getRandInt(2,7));
    }

    if(vStatus(hormonal_drug) == 0 && vStatus(addHorny) >= 1)
    {
        updVStatus(horny, getRandInt(1,vStatus(addHorny)));
    }
    else if (vStatus(hormonal_drug) == 0 && vStatus(addHorny) <= 0)
    {
        updVStatus(horny, getRandInt(vStatus(addHorny),1));
    }

    if(vStatus(shamelessFlag) == 0)
    {
        setVStatus(shameless_lust_min,0);
        setVStatus(shameless_lust_max,1);
    }

    if(vStatus(shamelessFlag) > 0)
    {
        setVStatus(shameless_lust_min, 0);
        setVStatus(shameless_lust_max, vStatus(shamelessFlag));
    }

    if(vStatus(hour_lust) > 0 && vStatus(soft_lust) == 1)
    {
        updVStatus(hour_lust, -1);
        if(vStatus(hour_lust) == 0)
        {
            setVStatus(soft_lust,0);
        }
        setVStatus(div_lust, 50);
        if(vStatus(hormonal_drug) == 1)
        {
            setVStatus(div_lust, 60);
        }
    }
    else
    {
        setVStatus(soft_lust,0);
        setVStatus(div_lust, 30);
        if(vStatus(hormonal_drug) == 1)
        {
            setVStatus(div_lust, 40);
        }
    }

    int randLust = getRandInt(vStatus(shameless_lust_min), vStatus(shameless_lust_max));
    if(vStatus(lust) < 100) { updVStatus(lust, randLust); }
    if(vStatus(lust) > 100) { setVStatus(lust,100); }
    int hornyInc = vStatus(lust)/vStatus(div_lust) - vStatus(hour_lust)/3;
    updVStatus(horny, hornyInc);
    if(vStatus(horny) > 100) { setVStatus(horny, 100); }
    if(vStatus(horny) < 0) { setVStatus(horny, 0); }
    if(vStatus(horny) >= 95) { updVStatus(mood,-getRandInt(1,3));}
    ((MainWindow*)root)->m_ccsex.slotSexCorrector();
    ((MainWindow*)root)->m_ccsex.slotDecRubbing(Body::vagina);
    ((MainWindow*)root)->m_ccsex.slotDecRubbing(Body::anus);

    //Пьянство отходняк алкоголизм
    ((MainWindow*)root)->m_ccalko.slotDataInitAlko();
    ((MainWindow*)root)->m_ccalko.slotHangOver();
    ((MainWindow*)root)->m_reproductSys.slotRiscsUpdate();

    updVStatus(water,-1);
    if(vStatus(water) < 8) { updVStatus(mood,-2); }
    if(vStatus(InSleep) == 0) { updVStatus(son, -1); }

    if(vAddict(alko) >= vAddict(maxAlko) && vAddict(alkoday) != vStatus(daystart))
    {
        setVAddict(alko, vStatus(daystart));
        // school[intellect, -1);
        if(vSkill(intellect) > 10) { updVSkill(intellect,-1); }
        if(vSkill(volleyball) > 10) { updVSkill(volleyball, -1); }
        if(vSkill(jab) > 10) { updVSkill(jab, -1); }
        if(vSkill(punch) > 10) { updVSkill(punch, -1); }
        if(vSkill(kik) > 10) { updVSkill(kik, -1); }
        if(vSkill(kikDef) > 10) { updVSkill(kikDef, -1); }
        if(vSkill(runner) > 10) { updVSkill(runner, -1); }
        if(vSkill(strenght) > 10) { updVSkill(strenght, -1); }
        if(vSkill(endurance) > 10) { updVSkill(endurance, -1); }
        if(vSkill(react) > 10) { updVSkill(react, -1); }
        if(vSkill(speed) > 10) { updVSkill(speed, -1); }
        if(vSkill(agility) > 10) { updVSkill(agility, -1); }
        updVAddict(alko, -1);
    }

    //cumstatus
    if(vStatus(cumFace) > 0) { updVStatus(cumFace, -1); }
    if(vStatus(cumLips) > 0) { updVStatus(cumLips, -1); }
    if(vStatus(cumBelly) > 0) { updVStatus(cumBelly, -1); }
    if(vStatus(cumAss) > 0) { updVStatus(cumAss, -1); }
    if(vStatus(cumPussy) > 0) { updVStatus(cumPussy, -1); }
    if(vStatus(cumAnus) > 0) { updVStatus(cumAnus, -1); }

    if(vBody(lipbalmstat) > 0) { updVBody(lipbalmstat, -1); }
    if(vSick(sickStage) == 1) { updVSick(sick, 1); updVSick(sickTimer, 1); }
    if(vSick(sickStage) == 1 && vSick(sickTimer) == 80)
    {
        setVSick(sickTimer, 0);
        setVSick(sickStage, 2);
    }
    if(vSick(sickStage) == 2 && vSick(sick) > 0)
    { updVSick(sick, -1); }
    if(vSick(sickStage) == 2 && vSick(sick) <= 0)
    {
        setVSick(sick, 0);
        setVSick(sickStage,0);
    }

    if(vStatus(sweat) > 2)
    {
        ((MainWindow*)root)->m_player->updSkin('-',1);
    }

    if(vStatus(clearClothes) > 0) { updVStatus(clearClothes, -1); }

    // if hantersAndreisex > 0: hantersAndreisex -= 1
    // if hantersSergeisex > 0: hantersSergeisex -= 1
    // if hantersIgorsex > 0: hantersIgorsex -= 1
    // if hantslutsex > 0: hantslutsex -= 1
    // if mira_dog > 0: mira_dog - 1
    // if mira_go_blok > 0: mira_go_blok -= 1
    // if lost_girl > 0: lost_girl -= 1
    // if mira_no_home > 0: mira_no_home -= 1

    if(vStatus(vaginal_grease) > vConst(many_vaginal_grease))
    {
        setVStatus(panties_grease, (vStatus(vaginal_grease) - vConst(many_vaginal_grease))/10);
    }
    ((MainWindow*)root)->m_player->checkPanties();

    //gs 'zz_drugs','hour_recalc'
    // проверка статуса ветки Царева - Светка прогуляла свидание - закрываем ветку
    //	if ($npc['26,qwMain'] = 116 or $npc['26,qwMain'] = 118) and $npc['26,qwMain_day'] ! day and hour >= 21: $npc['26,qwMain'] = 255

    if(vStatus(vaginal_grease) > vConst(max_vaginal_grease))
    {
        updVStatus(sweat, 1);
        updVStatus(mood, -10);
    }

    if(vStatus(isprok) == 0 && vStatus(mesec) > 0 && vStatus(pregnancy) == 0)
    {
        //message
        updVStatus(sweat, 1);
        updVStatus(mood, -10);
        ((MainWindow*)root)->m_player->getCloth(ClothType::Main)->decreaseCondition();
    }

}

void TimeServer::ElapsedDay()
{
    if(vSC(peek1day) > 0) { setVSC(peek1day, 0); }
    if(vSC(peek2day) > 0) { setVSC(peek2day, 0); }
    if(vSC(peek3day) > 0) { setVSC(peek3day, 0); }
    if(vSC(peek4day) > 0) { setVSC(peek4day, 0); }

    if(vSex(painpub) > 0) { updVSex(painpub, -1); }
    if(vSex(nippain) > 0) { updVSex(nippain, -1); }

    //gs 'zz_reputation','increase_all'

    // gs 'zz_school','recalc_stats'

    if(vBody(colorfulLenses) > 0) { setVBody(colorfulLenses, -1); }
    if(vBody(blizoruk) < 200) { updVBody(blizoruk, -1); }
    if(vBody(blizoruk) < 0) { setVBody(blizoruk,0); }

    if(vStatus(mood) < 10) { updVSick(crazy, 1); }
    if(vStatus(no_sleep_time) >= 36) { updVSick(crazy,1); }
    if(vStatus(mood) >= 25 && vSick(crazy) > 0) { updVSick(crazy, -1); }
    if(vSick(crazy) >= 12) { /*gameover*/ }

    if(vSex(pirs_pain_ton) > 0) { updVSex(pirs_pain_ton, -1); }
    if(vBody(eyeBrows) > 19) { setVBody(eyeBrows, 19); }
    if(vBody(eyeBrows) > 0) { updVBody(eyeBrows,-1); }
    if(vBody(hairLength) > 0)
    {
        updVBody(hairLengthDay, 1);
        if(vBody(hairLengthDay) >= 60)
        {
            setVBody(hairLengthDay,0);
            updVBody(hairLength,-1);
        }
    }

    if(vStatus(horny) > vStatus(hornyStat))
    {
        setVStatus(hornyStat, vStatus(horny));
        if(vBody(piercingA) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingB) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingC) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingD) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingE) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingF) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingG) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingN) > 0) { updVStatus(horny, 1); }
        if(vBody(piercingGL) > 0) { updVStatus(horny, 1); }
    }
    if(vStatus(horny) < vStatus(hornyStat)) { setVStatus(hornyStat, vStatus(horny)); }

    updVStatus(daystart, 1);

    //gs 'zz_school','vacation_status'
    //ЗПП
    if (vSick(SifacOnce) == 1) updVSick(Sifilis,1);
    if (vSick(GerpesOnce) == 1) updVSick(Gerpes,1);
    if (vSick(TriperOnce) == 1) updVSick(Triper,1);
    if (vSick(KandidozOnce) == 1) updVSick(Kandidoz,1);
    
    if(vSkill(runner) >= 100)
    {
        setVSkill(runner, vSkill(runner) / 500);
    }
    else
    {
        setVSkill(runner, 0);
    }

    updVStatus(vidageday, -1);
 
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
    ((MainWindow*)root)->m_reproductSys.slotMenstruus();
    ((MainWindow*)root)->m_reproductSys.slotEstrus();

}

void TimeServer::ElapsedTime()
{
    if (vStatus(son) <= 0)
    {
        updVStatus(no_sleep_time,1);
        if (vStatus(no_sleep_time) >= 60)
        {
            //go to GAMEOVER 12;
        }
        setVStatus(son,0);
        updVStatus(mood,-5);
    }
    if (vStatus(son)>24) setVStatus(son,24);
    if (vStatus(energy) < 0)
    {
        setVStatus(energy,0);
        updVStatus(health,-1);
    }
    if (vStatus(water) < 0)
    {
        setVStatus(water,1);
        updVStatus(health, -1);
    }
    if (vStatus(mood) < 0)
    {
        setVStatus(mood,0);
    }
    if (vStatus(health) < 0)
    {
        //go to GAMEOVER 0
    }

    if(vSC(raped) > 0 && vSC(raped) != vSex(rape_count) && vSC(orgasm) == vSex(orgasm_count))
    {
        setVStatus(mood,10);
        setVSex(rape_count, vSC(raped));
    }
    else if(vSC(orgasm) > 0 && vSC(orgasm) != vSex(orgasm_count))
    {
        setVStatus(mood,100);
        setVSex(orgasm_count, vSC(orgasm));
    }
    else if(vSC(raped) > 0 && vSC(raped) != vSex(rape_count) && vSC(orgasm) > 0 && vSC(orgasm) != vSex(orgasm_count))
    {
        setVStatus(mood,100);
        setVSex(orgasm_count,orgasm);
        setVSex(rape_count,vSC(raped));
    }
    
    //! Смотрим был ли прогул работы в "Школьнике" сегодня:
    //! Смотрим прогуляла ли ГГ бизнес-командировку от "Школьника"
    //! Смотрим прогуляла ли ГГ работу в качестве директора магазина "Школьник"    
}

void TimeServer::calcEnding()
{
    ((MainWindow*)root)->m_ccalko.slotAlkoholism();
    if (vStatus(mesec) > 0 && vStatus(vnesh) > 3)
    {
        updVStatus(vnesh, -(3 + vStatus(vneshAlko)));
    }
    else
    {
        updVStatus(vnesh, vStatus(sexyAppeal) - vStatus(vneshAlko));
    }
    int vagDump = ((MainWindow*)root)->m_ccsex.getVagDamp();
    if(vagDump >= 3)
    {
        updVStatus(vnesh, 2-vagDump);
    }
    ((MainWindow*)root)->m_player->updBody();
    ((MainWindow*)root)->slotUpdParams();

    setVStatus(horny, valChecker(vStatus(horny),1,100));
    setVStatus(lust, valChecker(vStatus(lust),1,100));
    setVStatus(health, valChecker(vStatus(health)));
    setVStatus(mood, valChecker(vStatus(mood)));
    setVStatus(energy, valChecker(vStatus(energy),0,24));
    setVStatus(water, valChecker(vStatus(water),0,24));
    setVStatus(son, valChecker(vStatus(son),0,24));

    ((MainWindow*)root)->m_weather->mainFunc();
}

int TimeServer::vBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

int TimeServer::vSex(SexVar param)
{
    return ((MainWindow*)root)->m_player->getVSexVar(param);
}

int TimeServer::vStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int TimeServer::vSkill(Skills param)
{
    return ((MainWindow*)root)->m_player->getSkillValue(param);
}

int TimeServer::vConst(Const param)
{
    return ((MainWindow*)root)->m_player->getVConst(param);
}

int TimeServer::vSC(SC param)
{
    return ((MainWindow*)root)->m_player->getStatisticsValue(param);
}

int TimeServer::vAddict(Addiction param)
{
    return ((MainWindow*)root)->m_player->getVAddict(param);
}

int TimeServer::vSick(Sickness param)
{
    return ((MainWindow*)root)->m_player->getVSick(param);
}

void TimeServer::updVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->updVBody(param,val);
}

void TimeServer::updVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->updVStatus(param,val);
}

void TimeServer::updVSex(SexVar param, int val)
{
    ((MainWindow*)root)->m_player->updVSexVar(param,val);
}

void TimeServer::updVSkill(Skills param, int val)
{
    ((MainWindow*)root)->m_player->updVSkill(param,val);
}

void TimeServer::updVSick(Sickness param, int val)
{
    ((MainWindow*)root)->m_player->updVSick(param,val);
}

void TimeServer::updVAddict(Addiction param, int val)
{
    ((MainWindow*)root)->m_player->updVAddict(param,val);
}

void TimeServer::setVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->setVBody(param,val);
}

void TimeServer::setVSex(SexVar param, int val)
{
    ((MainWindow*)root)->m_player->setVSexVar(param,val);
}

void TimeServer::setVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->setVStatus(param,val);
}

void TimeServer::setVSC(SC param, int val)
{
    ((MainWindow*)root)->m_player->setVSC(param,val);
}

void TimeServer::setVSkill(Skills param, int val)
{
    ((MainWindow*)root)->m_player->setVSkill(param,val);
}

void TimeServer::setVSick(Sickness param, int val)
{
    ((MainWindow*)root)->m_player->setVSick(param,val);
}

void TimeServer::setVAddict(Addiction param, int val)
{
    ((MainWindow*)root)->m_player->setVAddict(param,val);
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

