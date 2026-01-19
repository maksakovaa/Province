#include "pregnancy.h"
#include "../Functions.h"
#include "../menu/mainwindow.h"

Pregnancy::Pregnancy(QWidget *ptr): root(ptr) {}

bool Pregnancy::isEstrus()
{
    return estrus >= m_vag_estrus;
}

bool Pregnancy::isMesec()
{
    return getVStatus(mesec) > 0;
}

bool Pregnancy::isPregnancy()
{
    return getVStatus(pregnancy) > 0;
}

int Pregnancy::getPregValue()
{
    return getVStatus(pregnancy);
}

void Pregnancy::chanceOfPregnancy()
{
    vPreg(pregOdds) = getRandInt(1, 100);

    if (vPreg(againstPregOdds) == 0)
    {
        vPreg(againstPregOdds) = getRandInt(1, 3);
    }
    if (vPreg(mesecPregOdds) == 0)
    {
        vPreg(mesecPregOdds) = 1;
    }
    if (vPreg(withoutPregOdds) == 0)
    {
        vPreg(withoutPregOdds) = 35;
    }

    if (getVStatus(mesec) == 0 && vPreg(birthCtrlPills) == 0 && getVStatus(pregnancy) == 0)
    {//нет месячных и нет таблеток
        if (vPreg(pregOdds) >= 1 && vPreg(pregOdds) <= vPreg(withoutPregOdds))
        {
            if (vPreg(barrenness) != 100)
            {
                /* $father = $boy*/
                setVStatus(pregnancy,1);
            }
        }
    }
    else if (getVStatus(mesec) == 0 && vPreg(birthCtrlPills) > 0 && getVStatus(pregnancy) == 0)
    {//нет месячных с таблетками
        if (vPreg(pregOdds) >= 1 && vPreg(pregOdds) <= vPreg(againstPregOdds))
        {
            if (vPreg(barrenness) != 100)
            {
                /* code */
                setVStatus(pregnancy,1);
            }
            vPreg(pregRisc) = getRandInt(150,240);
        }
    }
    else if (getVStatus(mesec) > 0 && vPreg(birthCtrlPills) > 0 && getVStatus(pregnancy) == 0)
    {//месячные с таблетками
        if (vPreg(pregOdds) >= 1 && vPreg(pregOdds) <= vPreg(mesecPregOdds) && vPreg(pregOdds) <= vPreg(againstPregOdds))
        {
            if (vPreg(barrenness) != 100)
            {
                /* $father = $boy */
                setVStatus(pregnancy,1);
            }
            vPreg(pregRisc) = getRandInt(150,250);
        }
    }
    else if (getVStatus(mesec) > 0 && vPreg(birthCtrlPills) == 0 && getVStatus(pregnancy) == 0)
    {//месячные без таблеток
        if (vPreg(pregOdds) >= 1 && vPreg(pregOdds) <= vPreg(mesecPregOdds))
        {
            if(vPreg(barrenness) != 100)
            {
                /* $father = $boy*/
                setVStatus(pregnancy,1);
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
    if (getVStatus(pregnancy) >= con_pregsee && getRandInt(0,2) == 0)
    {
        updVStatus(Status::pregnancyKnow, true);
        return true;
    }
    else
    {
        return false;
    }
}

void Pregnancy::slotPregRecalc()
{
    vPreg(pregWeeks) = getVStatus(pregnancy) / 7;
    if (vPreg(pregWeeks) <= 6)
    {
        updVStatus(Status::horny, 10);
        updVStatus(Status::lust, 10*getRandInt(0,1));
        updVStatus(Status::energy, 0);
        updVStatus(Status::water, -1);
        if (getVStatus(Status::son) < 3)
        {
            updVStatus(Status::health, -1);
        }
        
        slotRiscsUpdate(); //0
    }
    if (vPreg(pregWeeks) <= 16)
    {
        updVStatus(Status::mood, getRandInt(-1,1) * 10);
        updVStatus(Status::horny, 15);
        updVStatus(Status::lust, 15*getRandInt(0,1));
        updVStatus(Status::energy, -2);
        updVStatus(Status::water, -2);
        updVStatus(Status::son, getRandInt(-1,0));
        if (getVStatus(Status::water) + getVStatus(Status::energy) < 10)
        {
            updVStatus(Status::son, -1);
        }
        if (getVStatus(Status::son) < 5)
        {
            updVStatus(Status::health, -1);
        }
        slotRiscsUpdate(); //1
    }
    if (vPreg(pregWeeks) <= 24)
    {
        updVStatus(Status::horny, 7);
        updVStatus(Status::lust, 7*getRandInt(0,1));
        updVStatus(Status::energy, -1);
        updVStatus(Status::water, -1);
        if (getVStatus(Status::water) + getVStatus(Status::energy) < 10)
        {
            updVStatus(Status::son, -1);
        }
        if (getVStatus(Status::son) < 5)
        {
            updVStatus(Status::health, -1);
        }
        slotRiscsUpdate(); //2
    }
    if (vPreg(pregWeeks) <= 33)
    {
        updVStatus(Status::mood, getRandInt(-1,1) * 12);
        updVStatus(Status::horny, 7);
        updVStatus(Status::lust, 7*getRandInt(0,1));
        updVStatus(Status::energy, 0);
        updVStatus(Status::water, -1);
        if (getVStatus(Status::water) + getVStatus(Status::energy) < 10)
        {
            updVStatus(Status::son, -1);
        }
        if (getVStatus(Status::son) < 5)
        {
            updVStatus(Status::health, -1);
        }
        slotRiscsUpdate(); //3
    }
    if (vPreg(pregWeeks) <= 40)
    {
        updVStatus(Status::horny, 7);
        updVStatus(Status::lust, 7*getRandInt(0,1));
        updVStatus(Status::son, -1);
        if (getVStatus(Status::water) + getVStatus(Status::energy) < 10)
        {
            updVStatus(Status::son, -1);
        }
        if (getVStatus(Status::son) < 10)
        {
            updVStatus(Status::health, -2);
        }
        slotRiscsUpdate(); //4
    }
}

void Pregnancy::slotMenstruus()
{
    if (getVBody(Body::hairCurly) > 0)
    {
        updVBody(Body::hairCurly, -1);
    }
    
    updVStatus(Status::sweat, 1);

    if (getVBody(Body::skinTan) > 0)
    {
        updVBody(Body::skinTan, -2);
    }

    if (getQuantityof(iAntiPregPills) > 0)
    {
        useItem(iAntiPregPills,1);
    }
    
    updVBody(legHair, 1);
    updVBody(pubisHair, 1);

    updVStatus(mood, -10);

    updVStatus(lipkoef, -1);

    if (getVStatus(pregnancy) == 0)
    {
        if (getVStatus(mesec) > 0)
        {
            updVStatus(mesec, -1);
        }
        if (getVStatus(mesec) == 0)
        {
            vPreg(cikl) += 1;
        }
        if (vPreg(cikl) >= 23 && getVStatus(pregnancy) == 0)
        {
            setVStatus(mesec, 4);
            vPreg(cikl) = 0;
        }
        if (getVStatus(mesec) > 0 && ((MainWindow*)root)->m_player->isAutoTampon() && getQuantityof(iTampon) > 0)
        {
            setVStatus(isprok, 1);
            useItem(iTampon,1);
        }
    }
    else
    {
        if (getVStatus(pregnancy) < 280)
        {
            updVStatus(pregnancy,1);
        }
        else if (getVStatus(pregnancy) == 280)
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
    if (getVStatus(Status::horny) < 0)
    {
        setVStatus(Status::horny, 0);
    }
    if (getVStatus(Status::horny) > 100)
    {
        setVStatus(Status::horny, 100);
    }

    if (getQuantityof(iAntiPregPills) > 0)
    {
        setVStatus(Status::inc_day_weight, 2);
        setVStatus(Status::hormonal_drug, 1);
    }
    else
    {
        setVStatus(Status::inc_day_weight, 3);
        setVStatus(Status::hormonal_drug, 0);
    }

    if (getVStatus(pregnancy) > 0)
    {
        if (vPreg(pregWeeks) <= 6) { setVStatus(Status::inc_preg_weight, 3); }
        if (vPreg(pregWeeks) > 6 && vPreg(pregWeeks) <= 24) { setVStatus(Status::inc_preg_weight, 2); }
        if (vPreg(pregWeeks) > 24 && vPreg(pregWeeks) <= 33) { setVStatus(Status::inc_preg_weight, getRandInt(1,2)); }
        if (vPreg(pregWeeks) > 33) { setVStatus(Status::inc_preg_weight, getRandInt(1,2)); }
    }
    else
    {
        setVStatus(Status::inc_preg_weight, 0);
    }

    if (getVStatus(Status::day_weight) >= getVStatus(Status::inc_day_weight))
    {
        updVStatus(Status::increase_weight, 1);
        setVStatus(Status::day_weight, 0);
    }
    else if (getVStatus(Status::inc_preg_weight) != 0 && getVStatus(Status::day_weight) >= getVStatus(Status::inc_preg_weight))
    {
        updVStatus(Status::increase_weight, getVStatus(Status::inc_preg_weight));
        setVStatus(Status::day_weight, 0);
    }
    else if (getVStatus(Status::day_weight) <= 0 && getQuantityof(iAntiPregPills) == 0)
    {
        if (getVStatus(Status::hungry_time) >= 36)
        {
            updVBody(Body::weight, -1);
            setVStatus(Status::hungry_time, 0);
            updVStatus(Status::health, -10);
        }
        else
        {
            if (getVBody(Body::weight) > (getVBody(base_weight) + 5))
            {
                updVStatus(Status::increase_weight, -1);
                setVStatus(Status::day_weight, 0);
            }
        }
    }
    setVStatus(Status::day_weight, 0);
    if (getVStatus(Status::fatdel_day) > 0)
    {
        updVStatus(Status::fatdel_day, -1);
        updVStatus(Status::increase_weight, -1);
    }
    if (getVStatus(Status::day_weight) >= 5)
    {
        updVBody(Body::weight, 1);
        setVStatus(Status::increase_weight, 0);
    }
    else if (getVStatus(Status::increase_weight) <= -5)
    {
        updVBody(Body::weight, -1);
        setVStatus(Status::increase_weight, 0);
    }
    
    updVStatus(Status::downmuscl, 1);
    if (getVStatus(Status::downmuscl) > 5)
    {
        setVStatus(Status::downmuscl, 0);
        if (getVSkill(Skills::strenght) > 10)
        {
            updVSkill(Skills::strenght, -1);
        }
        if (getVSkill(Skills::endurance) > 10)
        {
            updVSkill(Skills::endurance, -1);
        }
        if (getVSkill(Skills::speed) > 10)
        {
            updVSkill(Skills::speed, -1);
        }
        if (getVSkill(Skills::agility) > 10)
        {
            updVSkill(Skills::agility, -1);
        }
        if (getVSkill(Skills::react) > 10)
        {
            updVSkill(Skills::react, -1);
        }
        if (getVSkill(Skills::jab) > 10)
        {
            updVSkill(Skills::jab, -1);
        }
        if (getVSkill(Skills::punch) > 10)
        {
            updVSkill(Skills::punch, -1);
        }
        if (getVSkill(Skills::kik) > 10)
        {
            updVSkill(Skills::kik, -1);
        }
        if (getVSkill(Skills::kikDef) > 10)
        {
            updVSkill(Skills::kikDef, -1);
        }
    }
    ((MainWindow*)root)->m_player->decreaseCondition();
}

void Pregnancy::slotEstrus()
{
    if (vPreg(cikl) > 14)
    {
        vPreg(estrus) = 28 - vPreg(cikl);
    }
    else
    {
        vPreg(estrus) = vPreg(cikl);
    }

    if (getVStatus(pregnancy) == 0 && getVStatus(mesec) == 0)
    {
        vPreg(status_mc_vagina) = vPreg(estrus) / 3;
    }

    if (getVStatus(pregnancy) > 0)
    {
        setVStatus(addHorny, 0);
        setVStatus(sexyAppeal, 0);
        setVStatus(inc_vag_grease, 2);
    }
    else if (getVStatus(mesec) > 0)
    {
        vPreg(mesecPregOdds) = 1;
        vPreg(withoutPregOdds) = vPreg(mesecPregOdds);
        vPreg(againstPregOdds) = getRandInt(1, 2);
        setVStatus(sexyAppeal, -3);
        setVStatus(addHorny, -3);
        setVStatus(inc_vag_grease, 1);
    }
    else if (getVStatus(mesec) == 0)
    {
        initPregData();
        int tmp_rand = getRandInt(1, 5);
        int _tmp = m_Arr_Estrus[vPreg(estrus)] + getRandInt(-tmp_rand, tmp_rand);
        if (_tmp > 100)
        {
            _tmp = 100;
        }
        vPreg(withoutPregOdds) = _tmp;
        vPreg(againstPregOdds) = getRandInt(1, 2);
        setVStatus(inc_vag_grease, _tmp / 10 - ((MainWindow*)root)->m_player->getVSexVar(level_v_rubbing));
        if (getVStatus(inc_vag_grease) < 0)
        {
            setVStatus(inc_vag_grease, 0);
        }
        setVStatus(sexyAppeal, -1);
        setVStatus(addHorny, vPreg(estrus)/3);
        if (vPreg(estrus) > 2)
        {
            setVStatus(sexyAppeal, 0);
        }
        if (vPreg(estrus) > 6)
        {
            setVStatus(sexyAppeal, 1);
        }
        if (vPreg(estrus) > 11)
        {
            setVStatus(sexyAppeal, 2);
        }
    }
}

void Pregnancy::slotIncreaseRiscs(int value)
{
    vPreg(pregRisc) += value;
}

void Pregnancy::slotRiscsUpdate()
{
    int alkoVal, max_alko;
    alkoVal = ((MainWindow*)root)->m_player->getVAddict(alko);
    max_alko = ((MainWindow*)root)->m_player->getVAddict(maxAlko);

    if (alkoVal == 0)
    {
        vPreg(pregAlko) = 0;
    }
    else
    {
        vPreg(pregAlko) = 1;
    }   
    if (vPreg(pregAlko) == 1)
    {
        if(alkoVal < max_alko) { vPreg(pregRisc) += 1; }
        else { vPreg(pregRisc) += 5; }
        vPreg(pregRisc) += 1;
    }
}

int Pregnancy::getVBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

int Pregnancy::getVStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int Pregnancy::getVSkill(Skills skil)
{
    return ((MainWindow*)root)->m_player->getSkillValue(skil);
}

void Pregnancy::updVBody(Body param, int value)
{
    ((MainWindow*)root)->m_player->updVBody(param, value);
}

void Pregnancy::updVStatus(Status param, int value)
{
    ((MainWindow*)root)->m_player->updVStatus(param, value);
}

void Pregnancy::updVSkill(Skills skil, int value)
{
    ((MainWindow*)root)->m_player->updVSkill(skil,value);
}

void Pregnancy::setVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->setVStatus(param,val);
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

int &Pregnancy::vPreg(PregVar param)
{
    return ((MainWindow*)root)->m_player->vPreg(param);
}

int Pregnancy::getQuantityof(Items id)
{
    return ((MainWindow*)root)->m_bag->getQuantityof(id);
}

void Pregnancy::useItem(Items id, int count)
{
    ((MainWindow*)root)->m_bag->useItem(id,count);
}
