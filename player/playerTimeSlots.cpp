#include "player.h"
#include "../Functions.h"

void Player::slotElapsed10min()
{
    if (m_status[Status::hormonal_drug] == 1)
    {
        if (m_sex[vibratorIN])
        {
            m_status[Status::horny] += getRandInt(1,2);
        }
    }
    else
    {
        if (m_sex[vibratorIN])
        {
            m_status[Status::horny] += getRandInt(7,14);
        }
    }
    if (m_sex[analplugIN] == 1 && m_sex[analStore] <= m_body[Body::anus])
    {
        m_sex[analStore] = m_body[Body::anus];
    }
    if (m_sex[analplugIN] == 1 && m_sex[analStore] != 0)
    {
        m_body[Body::anus] = m_sex[analStore];
    }
    if (m_sex[analplugIN] == 0)
    {
        m_sex[analStore] = 0;
    }
}

void Player::slotElapsed15min()
{
    if (m_sex[agape] > 0)
    {
        m_sex[agape] -= 1;
    }
}

void Player::slotElapsed20min()
{
    emit sigCalcRubbing();
    if (m_sex[vgape] > 0)
    {
        m_sex[vgape] -= 1;
    }
}

void Player::slotElapsed30min()
{
    emit sigVagGelTouch();
}

void Player::slotElapsed60min()
{
    if(m_status[pregnancy] == 0) { m_status[inc_preg_weight] = 0; }
    if(m_status[pregnancy] > 0) { emit sigPregRecalc(); }

    if(m_status[hygiene] <= 0) { m_status[hygiene] = 0; }
    else { m_status[hygiene] = 1; }

    if (m_status[nerdism] > 0)
    {
        m_status[nerdism] -= 1;
        m_status[mood] -= 4 - m_status[nerdism]/20;
    }

    if (m_status[Status::no_sleep_time] > 0)
    {
        m_status[mood] -= 5;
        m_status[health] -= 2;
    }

    if (m_sex[spanked] > 0)
    {
        m_sex[spanked] -= 1;
    }

    if(m_status[obkvsdam] > 0)
    {
        m_status[obkvsdam] = getRandInt(2,5);
    }

    if(m_status[energy] < 8)
    {
        m_status[mood] -= 2;
        m_status[hungry_time] += 1;
    }

    if(m_status[energy] >= 24)
    {
        m_status[hungry_time] = 0;
    }
    m_status[energy] -= 1;
    if(m_sex[analplugIN] == 1)
    {
        m_status[mood] += getRandInt(2,7);
    }

    if(m_status[hormonal_drug] == 0 && m_status[addHorny] >= 1)
    {
        m_status[horny] += getRandInt(1,m_status[addHorny]);
    }

    if (m_status[shamelessFlag] == 0)
    {
        m_status[shameless_lust_min] = 0;
        m_status[shameless_lust_max] = 1;
    }

    if (m_status[shamelessFlag] > 0)
    {
        m_status[shameless_lust_min] = 0;
        m_status[shameless_lust_max] = m_status[shamelessFlag];
    }

    if(m_status[hour_lust] > 0 && m_status[soft_lust] == 1)
    {
        m_status[hour_lust] -= 1;
        if(m_status[hour_lust] == 0)
        {
            m_status[soft_lust] = 0;
        }
        m_status[div_lust] = 50;
        if(m_status[hormonal_drug] == 1)
        {
            m_status[div_lust] = 60;
        }
    }
    else
    {
        m_status[soft_lust] = 0;
        m_status[div_lust] = 30;
        if(m_status[hormonal_drug] == 1)
        {
            m_status[div_lust] = 40;
        }
    }

    int randLust = getRandInt(m_status[shameless_lust_min], m_status[shameless_lust_max]);
    if(m_status[lust] < 100) { m_status[lust] += randLust; }
    if(m_status[lust] > 100) {m_status[lust] = 100; }
    m_status[horny] += m_status[lust] / m_status[div_lust] - m_status[hour_lust] / 3;
    if (m_status[horny] > 100) { m_status[horny] = 100; }
    if (m_status[horny] < 0) { m_status[horny] = 0; }
    if (m_status[horny] >= 95) { m_status[mood] -= getRandInt(1,3);}
    emit sigSexCorrector();
    emit sigDecRubbing(Body::vagina);
    emit sigDecRubbing(Body::anus);


    //Пьянство отходняк алкоголизм
    emit sigDataInitAlko();
    emit sigHangOver();
    emit sigRiscsUpdate();

    m_status[water] -= 1;
    if(m_status[water] < 8) { m_status[mood] -=2; }
    if(m_status[InSleep] == 0) { m_status[son] -= 1; }

    if(m_status[alko] >= m_status[maxAlko] && m_status[alkoday] != daystart)
    {
        setVStatus(alko, m_status[daystart]);
        // school[intellect] -= 1;
        if(m_skills[intellect] > 10) { m_skills[intellect] -= 1; }
        if(m_skills[volleyball] > 10) { m_skills[volleyball] -= 1; }
        if(m_skills[jab] > 10) { m_skills[jab] -= 1; }
        if(m_skills[punch] > 10) { m_skills[punch] -= 1; }
        if(m_skills[kik] > 10) { m_skills[kik] -= 1; }
        if(m_skills[kikDef] > 10) { m_skills[kikDef] -= 1; }
        if(m_skills[runner] > 10) { m_skills[runner] -= 1; }
        if(m_skills[strenght] > 10) { m_skills[strenght] -= 1; }
        if(m_skills[endurance] > 10) { m_skills[endurance] -= 1; }
        if(m_skills[react] > 10) { m_skills[react] -= 1; }
        if(m_skills[speed] > 10) { m_skills[speed] -= 1; }
        if(m_skills[agility] > 10) { m_skills[agility] -= 1; }
        m_status[alko] -= 1;
    }

    //cumstatus
    if(m_status[cumFace] > 0) { m_status[cumFace] -= 1; }
    if(m_status[cumLips] > 0) { m_status[cumLips] -= 1; }
    if(m_status[cumBelly] > 0) { m_status[cumBelly] -= 1; }
    if(m_status[cumAss] > 0) { m_status[cumAss] -= 1; }
    if(m_status[cumPussy] > 0) { m_status[cumPussy] -= 1; }
    if(m_status[cumAnus] > 0) { m_status[cumAnus] -= 1; }

    if(m_body[Body::lipbalmstat] > 0) { m_body[Body::lipbalmstat] -= 1; }
    if(m_status[sickStage] == 1) { m_status[sick] += 1; m_status[sickTimer] += 1; }
    if(m_status[sickStage] == 1 && m_status[sickTimer] >= 80)
    {
        m_status[sickTimer] = 0;
        m_status[sickStage] = 2;
    }
    if(m_status[sickStage] == 2 && m_status[sick] > 0)
    { m_status[sick] -= 1; }
    if(m_status[sickStage] == 2 && m_status[sick] <= 0)
    {
        m_status[sick] = 0;
        m_status[sickStage] = 0;
    }

    if(m_status[sweat] > 2)
    {
        skinDecrement();
    }

    if(m_status[clearClothes] > 0) { m_status[clearClothes] -= 1; }


    if(m_status[vaginal_grease] > m_const[many_vaginal_grease])
    {
        m_status[panties_grease] = (m_status[vaginal_grease] - m_const[many_vaginal_grease])/10;
    }
    checkPanties();

    //gs 'zz_drugs','hour_recalc'
    // проверка статуса ветки Царева - Светка прогуляла свидание - закрываем ветку

    if(m_status[vaginal_grease] > m_const[max_vaginal_grease])
    {
        m_status[sweat] += 1;
        m_status[mood] -= 10;
    }

    if(m_status[isprok] == 0 && m_status[mesec] > 0 && m_status[pregnancy] == 0)
    {
        //message
        m_status[sweat] += 1;
        m_status[mood] -= 10;
        m_clothSLots[ClothType::Main]->decreaseCondition();
    }
}

void Player::slotElapsedDay()
{
    if(m_statistic[peek1day] > 0) { m_statistic[peek1day] = 0; }
    if(m_statistic[peek2day] > 0) { m_statistic[peek2day] = 0; }
    if(m_statistic[peek3day] > 0) { m_statistic[peek3day] = 0; }
    if(m_statistic[peek4day] > 0) { m_statistic[peek4day] = 0; }

    if(m_sex[painpub] > 0) { m_sex[painpub] -= 1; }
    if(m_sex[nippain] > 0) { m_sex[nippain] -= 1; }

    //gs 'zz_reputation','increase_all'

    // gs 'zz_school','recalc_stats'

    if(m_body[colorfulLenses] > 0) { m_body[colorfulLenses] -= 1; }
    if(m_body[blizoruk] < 200) { m_body[blizoruk] -= 1; }
    if(m_body[blizoruk] < 0) { m_body[blizoruk] = 0; }

    if(m_status[mood] < 10) { m_status[crazy] += 1; }
    if(m_status[no_sleep_time] >= 36) { m_status[crazy] += 1; }
    if(m_status[mood] >= 25 && m_status[crazy] > 0) { m_status[crazy] -= 1; }
    if(m_status[crazy] >= 12) { /*gameover*/ }

    if(m_sex[pirs_pain_ton] > 0) { m_sex[pirs_pain_ton] -= 1; }
    if(m_body[eyeBrows] > 19) { m_body[eyeBrows] = 19; }
    if(m_body[eyeBrows] > 0) { m_body[eyeBrows] -= 1; }
    if(m_body[hairLength] > 0)
    {
        m_body[hairLengthDay] +=1;
        if(m_body[hairLengthDay] >= 60)
        {
            m_body[hairLengthDay] = 0;
            m_body[hairLength] -= 1;
        }
    }

    if(m_status[horny] > m_status[hornyStat])
    {
        m_status[hornyStat] = m_status[horny];
        if(m_body[piercingA] > 0) { m_status[horny] += 1; }
        if(m_body[piercingB] > 0) { m_status[horny] += 1; }
        if(m_body[piercingC] > 0) { m_status[horny] += 1; }
        if(m_body[piercingD] > 0) { m_status[horny] += 1; }
        if(m_body[piercingE] > 0) { m_status[horny] += 1; }
        if(m_body[piercingF] > 0) { m_status[horny] += 1; }
        if(m_body[piercingG] > 0) { m_status[horny] += 1; }
        if(m_body[piercingN] > 0) { m_status[horny] += 1; }
        if(m_body[piercingGL] > 0) { m_status[horny] += 1; }
    }
    if(m_status[horny] < m_status[hornyStat]) { m_status[hornyStat] = m_status[horny]; }

    m_status[daystart] += 1;

    //ЗПП

    if(m_skills[runner] >= 100)
    {
        m_skills[runner] = m_skills[runner] / 500;
    }
    else
    {
        m_skills[runner] = 0;
    }

    m_status[vidageday] -= 1;
}

void Player::slotElapsedTime()
{
    if(m_status[son] < 0)
    {
        m_status[no_sleep_time] += 1;
        if(m_status[no_sleep_time] >= 60)
        {
            //GAMEOVER
        }
        m_status[son] = 0;
        m_status[mood] -= 5;
    }
    if(m_status[son] > 24)
    {
        m_status[son] = 24;
    }
    if(m_status[energy] < 0)
    {
        m_status[energy] = 0;
        m_status[health] -= 1;
    }
    if(m_status[water] < 0)
    {
        m_status[water] = 1;
        m_status[health] -= 1;
    }
    if(m_status[mood] < 0)
    {
        m_status[mood] = 0;
    }
    if(m_status[health] <= 0)
    {
        //GAMEOVER
    }

    if (m_statistic[raped] > 0 && m_statistic[raped] != m_sex[rape_count] && m_statistic[orgasm] == m_sex[orgasm_count])
    {
        m_status[mood] = 10;
        m_sex[rape_count] = m_statistic[raped];
    }
    else if (m_statistic[orgasm] > 0 && m_statistic[orgasm] != m_sex[orgasm_count])
    {
        m_status[mood] = 100;
        m_sex[orgasm_count] = m_statistic[orgasm];
    }
    else if (m_statistic[raped] > 0 && m_statistic[raped] != m_sex[rape_count] && m_statistic[orgasm] > 0 && m_statistic[orgasm] != m_sex[orgasm_count])
    {
        m_status[mood] = 100;
        m_sex[orgasm_count] = m_statistic[orgasm];
        m_sex[rape_count] = m_statistic[raped];
    }
    
    emit sigAlcoholism();

    if (m_status[mesec] > 0 && m_status[vnesh] > 3)
    {
        m_status[vnesh] -= 3 + m_status[vneshAlko];
    }
    else
    {
        m_status[vnesh] += m_status[sexyAppeal] - m_status[vneshAlko];
    }

    int vag_damp = 0;
    emit sigGetVagDamp(vag_damp);
    if (vag_damp >= 3)
    {
        m_status[vnesh] += 2 - vag_damp;
    }
}

void Player::slotWearAndTear(int value)
{
    if (m_clothSLots[ClothType::Main] != nullptr)
    {
        m_clothSLots[ClothType::Main]->decreaseCondition(value);
    }
}
