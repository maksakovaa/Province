#include "pregnancy.h"
#include "../Functions.h"
#include "../game.h"

Pregnancy::Pregnancy(Game *ptr): root(ptr) {}

bool Pregnancy::isEstrus()
{
    return estrus >= m_vag_estrus;
}

bool Pregnancy::isMesec()
{
    return root->vStatus(mesec) > 0;
}

bool Pregnancy::isPregnancy()
{
    return root->vStatus(pregnancy) > 0;
}

void Pregnancy::chanceOfPregnancy()
{
    root->vPreg(pregOdds) = getRandInt(1, 100);

    if (root->vPreg(againstPregOdds) == 0)
    {
        root->vPreg(againstPregOdds) = getRandInt(1, 3);
    }
    if (root->vPreg(mesecPregOdds) == 0)
    {
        root->vPreg(mesecPregOdds) = 1;
    }
    if (root->vPreg(withoutPregOdds) == 0)
    {
        root->vPreg(withoutPregOdds) = 35;
    }

    if (root->vStatus(mesec) == 0 && root->vPreg(birthCtrlPills) == 0 && root->vStatus(pregnancy) == 0)
    {//нет месячных и нет таблеток
        if (root->vPreg(pregOdds) >= 1 && root->vPreg(pregOdds) <= root->vPreg(withoutPregOdds))
        {
            if (root->vPreg(barrenness) != 100)
            {
                /* $father = $boy*/
                root->vStatus(pregnancy) = 1;
            }
        }
    }
    else if (root->vStatus(mesec) == 0 && root->vPreg(birthCtrlPills) > 0 && root->vStatus(pregnancy) == 0)
    {//нет месячных с таблетками
        if (root->vPreg(pregOdds) >= 1 && root->vPreg(pregOdds) <= root->vPreg(againstPregOdds))
        {
            if (root->vPreg(barrenness) != 100)
            {
                /* code */
                root->vStatus(pregnancy) = 1;
            }
            root->vPreg(pregRisc) = getRandInt(150,240);
        }
    }
    else if (root->vStatus(mesec) > 0 && root->vPreg(birthCtrlPills) > 0 && root->vStatus(pregnancy) == 0)
    {//месячные с таблетками
        if (root->vPreg(pregOdds) >= 1 && root->vPreg(pregOdds) <= root->vPreg(mesecPregOdds) && root->vPreg(pregOdds) <= root->vPreg(againstPregOdds))
        {
            if (root->vPreg(barrenness) != 100)
            {
                /* $father = $boy */
                root->vStatus(pregnancy) = 1;
            }
            root->vPreg(pregRisc) = getRandInt(150,250);
        }
    }
    else if (root->vStatus(mesec) > 0 && root->vPreg(birthCtrlPills) == 0 && root->vStatus(pregnancy) == 0)
    {//месячные без таблеток
        if (root->vPreg(pregOdds) >= 1 && root->vPreg(pregOdds) <= root->vPreg(mesecPregOdds))
        {
            if(root->vPreg(barrenness) != 100)
            {
                /* $father = $boy*/
                root->vStatus(pregnancy) = 1;
            }
        }
    }   
}

bool Pregnancy::condomDef()
{
    int var_chanceGap = 5;
    int tmpDefCondom = getRandInt(1,100);
    if (tmpDefCondom <= var_chanceGap)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Pregnancy::PregVisibility()
{
    int con_pregsee = 28;
    if (root->vStatus(pregnancy) >= con_pregsee && getRandInt(0,2) == 0)
    {
        root->vStatus(pregnancyKnow) = true;
        return true;
    }
    else
    {
        return false;
    }
}

void Pregnancy::slotPregRecalc()
{
    root->vPreg(pregWeeks) = root->vStatus(pregnancy) / 7;
    if (root->vPreg(pregWeeks) <= 6)
    {
        root->vStatus(horny) += 10;
        root->vStatus(lust) += 10*getRandInt(0,1);
        root->vStatus(energy) += 0;
        root->vStatus(water) -= 1;
        if (root->vStatus(son) < 3)
        {
            root->vStatus(health) -= 1;
        }
        
        slotRiscsUpdate(); //0
    }
    if (root->vPreg(pregWeeks) <= 16)
    {
        root->vStatus(mood) += getRandInt(-1,1) * 10;
        root->vStatus(horny) += 15;
        root->vStatus(lust) += 15*getRandInt(0,1);
        root->vStatus(energy) -= 2;
        root->vStatus(water) -= 2;
        root->vStatus(son) += getRandInt(-1,0);
        if (root->vStatus(water) + root->vStatus(energy) < 10)
        {
            root->vStatus(son) -= 1;
        }
        if (root->vStatus(son) < 5)
        {
            root->vStatus(health) -= 1;
        }
        slotRiscsUpdate(); //1
    }
    if (root->vPreg(pregWeeks) <= 24)
    {
        root->vStatus(horny) += 7;
        root->vStatus(lust) += 7*getRandInt(0,1);
        root->vStatus(energy) -= 1;
        root->vStatus(water) -= 1;
        if (root->vStatus(water) + root->vStatus(energy) < 10)
        {
            root->vStatus(son) -= 1;
        }
        if (root->vStatus(son) < 5)
        {
            root->vStatus(health) -= 1;
        }
        slotRiscsUpdate(); //2
    }
    if (root->vPreg(pregWeeks) <= 33)
    {
        root->vStatus(mood) += getRandInt(-1,1) * 12;
        root->vStatus(horny) += 7;
        root->vStatus(lust) += 7*getRandInt(0,1);
        root->vStatus(energy) += 0;
        root->vStatus(water) -= 1;
        if (root->vStatus(water) + root->vStatus(energy) < 10)
        {
            root->vStatus(son) -= 1;
        }
        if (root->vStatus(son) < 5)
        {
            root->vStatus(health) -= 1;
        }
        slotRiscsUpdate(); //3
    }
    if (root->vPreg(pregWeeks) <= 40)
    {
        root->vStatus(horny) += 7;
        root->vStatus(lust) += 7*getRandInt(0,1);
        root->vStatus(son) -= 1;
        if (root->vStatus(water) + root->vStatus(energy) < 10)
        {
            root->vStatus(son) -= 1;
        }
        if (root->vStatus(son) < 10)
        {
            root->vStatus(health) -=2;
        }
        slotRiscsUpdate(); //4
    }
}

void Pregnancy::slotMenstruus()
{
    if (root->vBody(Body::hairCurly) > 0)
    {
        root->vBody(Body::hairCurly) -= 1;
    }
    
    root->vStatus(sweat) += 1;

    if (root->vBody(Body::skinTan) > 0)
    {
        root->vBody(Body::skinTan) -= 2;
    }

    if (root->getItmCount(iAntiPregPills) > 0)
    {
        root->useItem(iAntiPregPills,1);
    }
    
    root->vBody(legHair) += 1;
    root->vBody(pubisHair) += 1;

    root->vStatus(mood) -= 10;

    root->vStatus(lipkoef) -=1;

    if (root->vStatus(pregnancy) == 0)
    {
        if (root->vStatus(mesec) > 0)
        {
            root->vStatus(mesec) -= 1;
        }
        if (root->vStatus(mesec) == 0)
        {
            root->vPreg(cikl) += 1;
        }
        if (root->vPreg(cikl) >= 23 && root->vStatus(pregnancy) == 0)
        {
            root->vStatus(mesec) = 4;
            root->vPreg(cikl) = 0;
        }
        if (root->vStatus(mesec) > 0 && root->isAutoTampon() && root->getItmCount(iTampon) > 0)
        {
            root->vStatus(isprok) = 1;
            root->useItem(iTampon,1);
        }
    }
    else
    {
        if (root->vStatus(pregnancy) < 280)
        {
            root->vStatus(pregnancy) += 1;
        }
        else if (root->vStatus(pregnancy) == 280)
        {
            QString msg = "<red>Резко толкнуло в живот и что-то потекло по ногам. Черт, у вас отошли воды! Надо срочно в поликлинику!</red>";
            // send notification msg
        }
        else
        {
            QString msg = "<red>Страшная боль пронзила вас внизу живота.</red>";
            // send notification msg
        }
    }
    if (root->vStatus(horny) < 0)
    {
        root->vStatus(horny) = 0;
    }
    if (root->vStatus(horny) > 100)
    {
        root->vStatus(horny) = 100;
    }

    if (root->getItmCount(iAntiPregPills) > 0)
    {
        root->vStatus(inc_day_weight) = 2;
        root->vStatus(hormonal_drug) = 1;
    }
    else
    {
        root->vStatus(inc_day_weight) = 3;
        root->vStatus(hormonal_drug) = 0;
    }

    if (root->vStatus(pregnancy) > 0)
    {
        if (root->vPreg(pregWeeks) <= 6) { root->vStatus(inc_preg_weight) = 3; }
        if (root->vPreg(pregWeeks) > 6 && root->vPreg(pregWeeks) <= 24) { root->vStatus(inc_preg_weight) = 2; }
        if (root->vPreg(pregWeeks) > 24 && root->vPreg(pregWeeks) <= 33) { root->vStatus(inc_preg_weight) = getRandInt(1,2); }
        if (root->vPreg(pregWeeks) > 33) { root->vStatus(inc_preg_weight) = getRandInt(1,2); }
    }
    else
    {
        root->vStatus(inc_preg_weight) = 0;
    }

    if (root->vStatus(day_weight) >= root->vStatus(inc_day_weight))
    {
        root->vStatus(increase_weight) += 1;
        root->vStatus(day_weight) = 0;
    }
    else if (root->vStatus(inc_preg_weight) != 0 && root->vStatus(day_weight) >= root->vStatus(inc_preg_weight))
    {
        root->vStatus(increase_weight) += root->vStatus(inc_preg_weight);
        root->vStatus(day_weight) = 0;
    }
    else if (root->vStatus(day_weight) <= 0 && root->getItmCount(iAntiPregPills) == 0)
    {
        if (root->vStatus(hungry_time) >= 36)
        {
            root->vBody(Body::weight) -=1;
            root->vStatus(hungry_time) = 0;
            root->vStatus(health) -= 10;
        }
        else
        {
            if (root->vBody(Body::weight) > (root->vBody(base_weight) + 5))
            {
                root->vStatus(increase_weight) -=1;
                root->vStatus(day_weight) = 0;
            }
        }
    }
    root->vStatus(day_weight) = 0;
    if (root->vStatus(fatdel_day) > 0)
    {
        root->vStatus(fatdel_day) -=1;
        root->vStatus(increase_weight) -= 1;
    }
    if (root->vStatus(day_weight) >= 5)
    {
        root->vBody(Body::weight) += 1;
        root->vStatus(increase_weight) = 0;
    }
    else if (root->vStatus(increase_weight) <= -5)
    {
        root->vBody(Body::weight) -= 1;
        root->vStatus(increase_weight) = 0;
    }
    
    root->vStatus(downmuscl) += 1;
    if (root->vStatus(downmuscl) > 5)
    {
        root->vStatus(downmuscl) = 0;
        if (root->vSkill(Skills::strenght) > 10)
        {
            root->vSkill(Skills::strenght) -=1;
        }
        if (root->vSkill(Skills::endurance) > 10)
        {
            root->vSkill(Skills::endurance) -=1;
        }
        if (root->vSkill(Skills::speed) > 10)
        {
            root->vSkill(Skills::speed) -=1;
        }
        if (root->vSkill(Skills::agility) > 10)
        {
            root->vSkill(Skills::agility) -=1;
        }
        if (root->vSkill(Skills::react) > 10)
        {
            root->vSkill(Skills::react) -=1;
        }
        if (root->vSkill(Skills::jab) > 10)
        {
            root->vSkill(Skills::jab) -=1;
        }
        if (root->vSkill(Skills::punch) > 10)
        {
            root->vSkill(Skills::punch) -=1;
        }
        if (root->vSkill(Skills::kik) > 10)
        {
            root->vSkill(Skills::kik) -=1;
        }
        if (root->vSkill(Skills::kikDef) > 10)
        {
            root->vSkill(Skills::kikDef) -=1;
        }
    }
    root->decreaseClothCond();
}

void Pregnancy::slotEstrus()
{
    if (root->vPreg(cikl) > 14)
    {
        root->vPreg(estrus) = 28 - root->vPreg(cikl);
    }
    else
    {
        root->vPreg(estrus) = root->vPreg(cikl);
    }

    if (root->vStatus(pregnancy) == 0 && root->vStatus(mesec) == 0)
    {
        root->vPreg(status_mc_vagina) = root->vPreg(estrus) / 3;
    }

    if (root->vStatus(pregnancy) > 0)
    {
        root->vStatus(addHorny) = 0;
        root->vStatus(sexyAppeal) = 0;
        root->vStatus(inc_vag_grease) = 2;
    }
    else if (root->vStatus(mesec) > 0)
    {
        root->vPreg(mesecPregOdds) = 1;
        root->vPreg(withoutPregOdds) = root->vPreg(mesecPregOdds);
        root->vPreg(againstPregOdds) = getRandInt(1, 2);
        root->vStatus(sexyAppeal) = -3;
        root->vStatus(addHorny) = -3;
        root->vStatus(inc_vag_grease)=1;
    }
    else if (root->vStatus(mesec) == 0)
    {
        initPregData();
        int tmp_rand = getRandInt(1, 5);
        int _tmp = m_Arr_Estrus[root->vPreg(estrus)] + getRandInt(-tmp_rand, tmp_rand);
        if (_tmp > 100)
        {
            _tmp = 100;
        }
        root->vPreg(withoutPregOdds) = _tmp;
        root->vPreg(againstPregOdds) = getRandInt(1, 2);
        root->vStatus(inc_vag_grease) = _tmp / 10 - root->vSex(level_v_rubbing);
        if (root->vStatus(inc_vag_grease) < 0)
        {
            root->vStatus(inc_vag_grease) = 0;
        }
        root->vStatus(sexyAppeal) = -1;
        root->vStatus(addHorny) = root->vPreg(estrus)/3;
        if (root->vPreg(estrus) > 2)
        {
            root->vStatus(sexyAppeal) = 0;
        }
        if (root->vPreg(estrus) > 6)
        {
            root->vStatus(sexyAppeal) = 1;
        }
        if (root->vPreg(estrus) > 11)
        {
            root->vStatus(sexyAppeal) = 2;
        }
    }
}

void Pregnancy::slotIncreaseRiscs(int value)
{
    root->vPreg(pregRisc) += value;
}

void Pregnancy::slotRiscsUpdate()
{
    int alkoVal, max_alko;
    alkoVal = root->vAddict(alko);
    max_alko = root->vAddict(maxAlko);

    if (alkoVal == 0)
    {
        root->vPreg(pregAlko) = 0;
    }
    else
    {
        root->vPreg(pregAlko) = 1;
    }   
    if (root->vPreg(pregAlko) == 1)
    {
        if(alkoVal < max_alko) { root->vPreg(pregRisc) += 1; }
        else { root->vPreg(pregRisc) += 5; }
        root->vPreg(pregRisc) += 1;
    }
}

void Pregnancy::initPregData()
{
    m_Arr_Estrus[0] = 16;
    m_Arr_Estrus[1]  = 20;
    m_Arr_Estrus[2]  = 24;
    m_Arr_Estrus[3]  = 28;
    m_Arr_Estrus[4]  = 32;
    m_Arr_Estrus[5]  = 36;
    m_Arr_Estrus[6]  = 38;
    m_Arr_Estrus[7]  = 42;
    m_Arr_Estrus[8]  = 44;
    m_Arr_Estrus[9]  = 48;
    m_Arr_Estrus[10]  = 52;
    m_Arr_Estrus[11]  = 54;
    m_Arr_Estrus[12]  =	56;
    m_Arr_Estrus[13]  =	80;
    m_Arr_Estrus[14]  = 95;
}
