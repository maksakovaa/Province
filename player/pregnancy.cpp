#include "pregnancy.h"
#include "../Functions.h"
#include "cloth.h"

Pregnancy::Pregnancy() : m_Arr_Estrus{0, 20, 24, 28, 32, 36, 38, 42, 44, 48, 52, 54, 56, 80, 95}{}

bool Pregnancy::isEstrus()
{
    return m_estrus >= m_vag_estrus;
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
    m_pregOdds = getRandInt(1, 100);

    if (m_againstPregOdds == 0)
    {
        m_againstPregOdds = getRandInt(1, 3);
    }
    if (m_mesecPregOdds == 0)
    {
        m_mesecPregOdds = 1;
    }
    if (m_withoutPregOdds == 0)
    {
        m_withoutPregOdds = 35;
    }

    if (getVStatus(mesec) == 0 && m_birthCtrlPills == 0 && getVStatus(pregnancy) == 0)
    {//нет месячных и нет таблеток
        if (m_pregOdds >= 1 && m_pregOdds <= m_withoutPregOdds)
        {
            if (m_barrenness != 100)
            {
                /* $father = $boy*/
                m_player->setVStatus(pregnancy,1);
            }
        }
    }
    else if (getVStatus(mesec) == 0 && m_birthCtrlPills > 0 && getVStatus(pregnancy) == 0)
    {//нет месячных с таблетками
        if (m_pregOdds >= 1 && m_pregOdds <= m_againstPregOdds)
        {
            if (m_barrenness != 100)
            {
                /* code */
                m_player->setVStatus(pregnancy,1);
            }
            m_pregRisc = getRandInt(150,240);
        }
    }
    else if (getVStatus(mesec) > 0 && m_birthCtrlPills > 0 && getVStatus(pregnancy) == 0)
    {//месячные с таблетками
        if (m_pregOdds >= 1 && m_pregOdds <= m_mesecPregOdds && m_pregOdds <= m_againstPregOdds)
        {
            if (m_barrenness != 100)
            {
                /* $father = $boy */
                m_player->setVStatus(pregnancy,1);
            }
            m_pregRisc = getRandInt(150,250);
        }
    }
    else if (getVStatus(mesec) > 0 && m_birthCtrlPills == 0 && getVStatus(pregnancy) == 0)
    {//месячные без таблеток
        if (m_pregOdds >= 1 && m_pregOdds <= m_mesecPregOdds)
        {
            if(m_barrenness != 100)
            {
                /* $father = $boy*/
                m_player->setVStatus(pregnancy,1);
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
    m_pregWeeks = getVStatus(pregnancy) / 7;
    if (m_pregWeeks <= 6)
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
    if (m_pregWeeks <= 16)
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
    if (m_pregWeeks <= 24)
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
    if (m_pregWeeks <= 33)
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
    if (m_pregWeeks <= 40)
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

void Pregnancy::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
}

void Pregnancy::setBagPtr(BagForm *ptr)
{
    m_bag = ptr;
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

    if (m_bag->getQuantityof(Items::antiPregPills) > 0)
    {
        m_bag->removeFromBag(Items::antiPregPills);
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
            m_cikl++;
        }
        if (m_cikl >= 23 && getVStatus(pregnancy) == 0)
        {
            m_player->setVStatus(mesec, 4);
            m_cikl = 0;
        }
        if (getVStatus(mesec) > 0 && m_player->isAutoTampon() && m_bag->getQuantityof(Items::tampon) > 0)
        {
            m_player->setVStatus(isprok, 1);
            m_bag->removeFromBag(Items::tampon);
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
        m_player->setVStatus(Status::horny, 0);
    }
    if (getVStatus(Status::horny) > 100)
    {
        m_player->setVStatus(Status::horny, 100);
    }

    if (m_bag->getQuantityof(Items::antiPregPills) > 0)
    {
        m_player->setVStatus(Status::inc_day_weight, 2);
        m_player->setVStatus(Status::hormonal_drug, 1);
    }
    else
    {
        m_player->setVStatus(Status::inc_day_weight, 3);
        m_player->setVStatus(Status::hormonal_drug, 0);
    }

    if (getVStatus(pregnancy) > 0)
    {
        if (m_pregWeeks <= 6) { m_player->setVStatus(Status::inc_preg_weight, 3); }
        if (m_pregWeeks > 6 && m_pregWeeks <= 24) { m_player->setVStatus(Status::inc_preg_weight, 2); }
        if (m_pregWeeks > 24 && m_pregWeeks <= 33) { m_player->setVStatus(Status::inc_preg_weight, getRandInt(1,2)); }
        if (m_pregWeeks > 33) { m_player->setVStatus(Status::inc_preg_weight, getRandInt(1,2)); }
    }
    else
    {
        m_player->setVStatus(Status::inc_preg_weight, 0);
    }

    if (getVStatus(Status::day_weight) >= getVStatus(Status::inc_day_weight))
    {
        updVStatus(Status::increase_weight, 1);
        m_player->setVStatus(Status::day_weight, 0);
    }
    else if (getVStatus(Status::inc_preg_weight) != 0 && getVStatus(Status::day_weight) >= getVStatus(Status::inc_preg_weight))
    {
        updVStatus(Status::increase_weight, getVStatus(Status::inc_preg_weight));
        m_player->setVStatus(Status::day_weight, 0);
    }
    else if (getVStatus(Status::day_weight) <= 0 && m_bag->getQuantityof(Items::antiPregPills) == 0)
    {
        if (getVStatus(Status::hungry_time) >= 36)
        {
            updVBody(Body::weight, -1);
            m_player->setVStatus(Status::hungry_time, 0);
            updVStatus(Status::health, -10);
        }
        else
        {
            if (getVBody(Body::weight) > (getVBody(base_weight) + 5))
            {
                updVStatus(Status::increase_weight, -1);
                m_player->setVStatus(Status::day_weight, 0);
            }
        }
    }
    m_player->setVStatus(Status::day_weight, 0);
    if (getVStatus(Status::fatdel_day) > 0)
    {
        updVStatus(Status::fatdel_day, -1);
        updVStatus(Status::increase_weight, -1);
    }
    if (getVStatus(Status::day_weight) >= 5)
    {
        updVBody(Body::weight, 1);
        m_player->setVStatus(Status::increase_weight, 0); 
    }
    else if (getVStatus(Status::increase_weight) <= -5)
    {
        updVBody(Body::weight, -1);
        m_player->setVStatus(Status::increase_weight, 0);
    }
    
    updVStatus(Status::downmuscl, 1);
    if (getVStatus(Status::downmuscl) > 5)
    {
        m_player->setVStatus(Status::downmuscl, 0);
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
    m_player->getCloth(ClothType::Main)->decreaseCondition();
    slotEstrus();
}

void Pregnancy::slotEstrus()
{
    if (m_cikl > 14)
    {
        m_estrus = 28 - m_cikl;
    }
    else
    {
        m_estrus = m_cikl;
    }

    if (getVStatus(pregnancy) == 0 && getVStatus(mesec) == 0)
    {
        status_mc_vagina = m_estrus / 3;
    }

    if (getVStatus(pregnancy) > 0)
    {
        m_player->setVStatus(addHorny, 0);
        m_player->setVStatus(sexyAppeal, 0);
        m_player->setVStatus(inc_vag_grease, 2);
    }
    else if (getVStatus(mesec) > 0)
    {
        m_mesecPregOdds = 1;
        m_withoutPregOdds = m_mesecPregOdds;
        m_againstPregOdds = getRandInt(1, 2);
        m_player->setVStatus(sexyAppeal, -3);
        m_player->setVStatus(addHorny, -3);
        m_player->setVStatus(inc_vag_grease, 1);
    }
    else if (getVStatus(mesec) == 0)
    {
        int tmp_rand = getRandInt(1, 5);
        int _tmp = m_Arr_Estrus[m_estrus] + getRandInt(-tmp_rand, tmp_rand);
        if (_tmp > 100)
        {
            _tmp = 100;
        }
        m_withoutPregOdds = _tmp;
        m_againstPregOdds = getRandInt(1, 2);
        m_player->setVStatus(inc_vag_grease, _tmp / 10 - level_v_rubbing);
        if (getVStatus(inc_vag_grease) < 0)
        {
            m_player->setVStatus(inc_vag_grease, 0);
        }
        m_player->setVStatus(sexyAppeal, -1);
        m_player->setVStatus(addHorny, m_estrus/3);
        if (m_estrus > 2)
        {
            m_player->setVStatus(sexyAppeal, 0);
        }
        if (m_estrus > 6)
        {
            m_player->setVStatus(sexyAppeal, 1);
        }
        if (m_estrus > 11)
        {
            m_player->setVStatus(sexyAppeal, 2);
        }
    }
}

void Pregnancy::slotIncreaseRiscs(int value)
{
    m_pregRisc += value;
}

void Pregnancy::slotRiscsUpdate()
{
    int alkoVal, max_alko;
    alkoVal = getVStatus(alko);
    max_alko = getVStatus(maxAlko);

    if (alkoVal == 0)
    {
        m_pregAlko = 0;
    }
    else
    {
        m_pregAlko = 1;
    }   
    if (m_pregAlko == 1)
    {
        if(alkoVal < max_alko) { m_pregRisc += 1; }
        else { m_pregRisc += 5; }
        m_pregRisc += 1;
    }
}

int Pregnancy::getVBody(Body param)
{
    return m_player->getVBody(param);
}

int Pregnancy::getVStatus(Status param)
{
    return m_player->getVStatus(param);
}

int Pregnancy::getVSkill(Skills skil)
{
    return m_player->getSkillValue(skil);
}

void Pregnancy::updVBody(Body param, int value)
{
    m_player->updVBody(param, value);
}

void Pregnancy::updVStatus(Status param, int value)
{
    m_player->updVStatus(param, value);
}

void Pregnancy::updVSkill(Skills skil, int value)
{
    m_player->updVSkill(skil,value);
}
