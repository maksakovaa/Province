#include "ccsex.h"
#include "../Functions.h"

CCSex::CCSex() {

}

void CCSex::ability(Body holeType, int value)
{
    int maxStoreVagina {10}, maxStoreAnus {10};
    int tmp_vstore = maxStoreVagina - getVSexVar(storeVagina) / maxStoreVagina;
    int tmp_astore = maxStoreAnus - getVSexVar(storeAnus) / maxStoreAnus;
    if (holeType == Body::vagina)
    {
        if (value > 0) { updVSexVar(vagina_ability, 1); }
        else
        {
            if(getVSexVar(vagina_ability) <= 0) { updVSexVar(vagina_ability, 0); }
            else { updVSexVar(vagina_ability, -1); }
        }
        if(getVSexVar(vagina_ability) > maxStoreVagina)
        {
            updVSexVar(storeVagina, tmp_vstore);
            updVSexVar(vagina_ability, -tmp_vstore);
        }
    }
    else if (holeType == Body::anus)
    {
        if (value > 0) { updVSexVar(anus_ability, 1); }
        else
        {
            if (getVSexVar(anus_ability) > maxStoreAnus)
            {
                updVSexVar(storeAnus, tmp_astore);
                updVSexVar(anus_ability, -tmp_astore);
            }
        }
        if (getVSexVar(anus_ability) > maxStoreAnus)
        {
            updVSexVar(storeAnus, tmp_astore);
            updVSexVar(anus_ability, - tmp_astore);
        }
    }
}

QString CCSex::sextToysBlock(int arg)
{
    QString res;

    if (arg == 1)
    {
        QString vag[] {"<br>У вас немного болит влагалище.","<br>У вас болит влагалище и вы с трудом можете свести ноги вместе.",
                        "<br>У вас сильно болит влагалище, вы даже с трудом ходите, при этом стараясь пошире расставлять ноги."   
        };
        if (getVSexVar(stat_vgape) != 0)
        {
            res = vag[getVSexVar(stat_vgape)];
            res += "<br><br><b>Вы не можете вопользоваться вибратором, ждите пока заживёт, а пока посмотрите кино или почитайте порножурнал.</b>";
        }
        else if (getVSexVar(dry_v_rubbing) > 24 || getVSexVar(level_v_rubbing) > 10)
        {
            res = "<br>Ваше влагалище натёрто и болит.<br><br><b>Вы не можете вопользоваться анальной пробкой - вашей попе и так досталось.</b>";
        }
        else if (m_reproductSys->isMesec())
        {
            QString red[] { "Гости из Краснодара","Красная армия","Борщ без сметаны","Монстры",
                "Красные дни календаря","Праздники","Красный москвич","Мурзики","Месячный отчёт", "Бесячные"
            };

            res = "<br><b>Вы куда засовываете вибратор?! У вас же <font color = red><b>'" + red[getRandInt(0,9)] + "</b></font> - потрепите. А пока почитайте книжку что ли...</b>";
        }
        else
        {
            res = "";
        }

    }
    if (arg == 2)
    {
        QString anal[] {"<br>У вас немного болит и чешется анус.","<br>У вас болит анус.","<br>У вас сильно болит и кровоточит анус."};

        if (getVSexVar(stat_agape) != 0)
        {
            res = anal[getVSexVar(stat_agape)];
            res += "<br><br><b>Вы не можете вопользоваться анальной пробкой - вашей попе и так досталось.</b>";
        }
        else if (getVSexVar(dry_a_rubbing) > 24 || getVSexVar(level_a_rubbing) > 10)
        {
            res = "<br>Ваш анус натёрт и болит.<br><br><b>Вы не можете вопользоваться анальной пробкой - вашей попе и так досталось.</b>";
        }
        else
        {
            res = "";
        }
    }
    
    return res;
}

void CCSex::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
}

void CCSex::setPregPtr(Pregnancy *ptr)
{
    m_reproductSys = ptr;
}

int CCSex::getVaginaDampness()
{
    int vag_grease = getVStatus(Status::vaginal_grease);
    if(vag_grease <= 0)
    {
        return 0;
    }
    else if (vag_grease < m_player->getVConst(out_vaginal_grease))
    {
        return 1;
    }
    else if (vag_grease >= m_player->getVConst(out_vaginal_grease) && vag_grease < (m_player->getVConst(out_vaginal_grease) * 3))
    {
        return 2;
    }
    else if (vag_grease >= (m_player->getVConst(out_vaginal_grease) * 3) && vag_grease < (m_player->getVConst(out_vaginal_grease) * 5))
    {
        return 3;
    }
    else if (vag_grease >= (m_player->getVConst(out_vaginal_grease) * 5) && vag_grease < m_player->getVConst(many_vaginal_grease))
    {
        return 4;
    }
    else /* (vag_grease >= m_many_vaginal_grease) */
    {
        return 5;
    }
}

int CCSex::calc_rubb(QString holeType)
{
    if(holeType == "vagina")
    {
        int dry = getVSexVar(dry_v_rubbing);
        if(dry <= 0)
            return 0;
        else if(dry <= 15)
            return 1;
        else if(dry <= 30)
            return 2;
        else if(dry <= 45)
            return 3;
        else if(dry <= 60)
            return 4;
        else
            return 5;
    }
    else
    {
        int dry = getVSexVar(dry_a_rubbing);
        if(dry <= 0)
            return 0;
        else if(dry <= 15)
            return 1;
        else if(dry <= 30)
            return 2;
        else if(dry <= 45)
            return 3;
        else if(dry <= 60)
            return 4;
        else
            return 5;
    }
}

void CCSex::slotCalcRubbing()
{
    if (getVSexVar(level_v_rubbing) + getVSexVar(level_a_rubbing) > 0)
    {
        updVStatus(Status::horny, -(getVSexVar(level_a_rubbing) + getVSexVar(level_v_rubbing))*2/3);
        if (getVStatus(Status::horny) <= 0)
        {
            m_player->setVStatus(Status::horny, 1);
        }
    }
    if (getVSexVar(dry_v_rubbing) > 0)
    {
        updVStatus(Status::vaginal_grease, getRandInt(0,getVStatus(Status::inc_vag_grease)/2));
    }
    int hornyVal = getVStatus(horny);
    int v_level = getVSexVar(level_v_rubbing);
    int a_level = 0;
    if(getVSexVar(level_a_rubbing) != 0)
    {
        a_level = getVSexVar(level_a_rubbing) / 2;
    }
    int a_dry = getVSexVar(dry_a_rubbing);
    int v_dry = getVSexVar(dry_v_rubbing);

    updVStatus(vaginal_grease, hornyVal/(10+v_level + a_level) - (v_dry + a_dry/2)*2/3);

    int d = getVSexVar(vgape)/3 + getVSexVar(agape)/5;
    updVStatus(Status::vaginal_grease, -d);

    if (getVStatus(Status::vaginal_grease) < 0)
    {
       m_player->setVStatus(Status::vaginal_grease, 0);
    }
    if (getVStatus(Status::vaginal_grease) > m_player->getVConst(max_vaginal_grease))
    {
        m_player->setVStatus(Status::vaginal_grease, m_player->getVConst(max_vaginal_grease));
    }
}

void CCSex::slotVagGelTouch()
{
    int useAntiRub = getVSexVar(use_anti_rubbing);
    int vagRubLvl = getVSexVar(level_v_rubbing);
    int dryVagRub = getVSexVar(dry_v_rubbing);

    if (useAntiRub > 0 || (useAntiRub > 0 && (vagRubLvl > 0 || dryVagRub > 0)))
    {
        updVSexVar(dry_v_rubbing, -m_player->getVConst(dec_anti_rubbing));
        updVSexVar(level_v_rubbing, - m_player->getVConst(dec_anti_rubbing) / 2);
        updVSexVar(use_anti_rubbing, - m_player->getVConst(dec_anti_rubbing));
    }
}

void CCSex::slotDecRubbing(Body holeType)
{
    if(holeType == Body::vagina)
    {
        if(getVSexVar(dry_v_rubbing) <= 0)
        {
            m_player->setVSexVar(dry_v_rubbing, 0);
            m_player->setVSexVar(level_v_rubbing,0);
        }
        int _tmp = getVSexVar(dry_v_rubbing) / 24;
        int moodDec = getRandInt(0, 3 + _tmp);
        updVStatus(mood, -moodDec);
        if(getVStatus(mood) < 0) { setVStatus(mood, 0); }
        int healthDec = getRandInt(0, 1 + _tmp);
        updVStatus(health, -healthDec);
        if(getVStatus(health) < 0) { setVStatus(health, 0); }
        updVStatus(horny, -getVStatus(horny) / 10);

        int dryDec  = getVSexVar(vagina_ability) / 2;
        if(getVSexVar(dry_v_rubbing) > 0)
        {
            dryDec += getRandInt(1,2);
        }
        updVSexVar(dry_v_rubbing, -dryDec);
        int levelDex = getVSexVar(vagina_ability) / 3;
        if(getVSexVar(level_v_rubbing) > 0)
        {
            levelDex += 1;
        }
        updVSexVar(level_v_rubbing, -levelDex);
    }

    if(holeType == Body::anus)
    {
        if(getVSexVar(dry_a_rubbing) <= 0)
        {
            m_player->setVSexVar(dry_a_rubbing, 0);
            m_player->setVSexVar(level_a_rubbing,0);
        }
        int _tmp = getVSexVar(dry_a_rubbing) / 24;
        int moodDec = getRandInt(0, 3 + _tmp);
        updVStatus(mood, -moodDec);
        if(getVStatus(mood) < 0) { setVStatus(mood, 0); }
        int healthDec = getRandInt(0, 1+_tmp);
        updVStatus(health, -healthDec);
        if(getVStatus(health) < 0) { setVStatus(health, 0); }
        updVStatus(horny, -getVStatus(horny) / 10);

        int dryDec  = getVSexVar(anus_ability) / 2;
        if(getVSexVar(dry_a_rubbing) > 0)
        {
            dryDec += getRandInt(1,2);
        }
        updVSexVar(dry_a_rubbing, -dryDec);
        int levelDex = getVSexVar(anus_ability) / 3;
        if(getVSexVar(level_a_rubbing) > 0)
        {
            levelDex += 1;
        }
        updVSexVar(level_a_rubbing, -levelDex);
    }
}

void CCSex::antiRubbing()
{
    if (getVSexVar(use_anti_rubbing) != 0)
    {
        //return to bag
    }
    else
    {
        updVSexVar(use_anti_rubbing, 160);
        //return to bag
    }
}

void CCSex::slotSetGape(Body holeType, int horny, int dick, int silavag)
{
    int setGapeDick, gapeBase;
    if(dick == 0)
    {
        setGapeDick = genDick();
    }
    else
    {
        setGapeDick = dick;
    }
    if(holeType == Body::vagina)
    {
        gapeBase = getVBody(Body::vagina) + horny / 20 + silavag * 2 + 2;
    }
    else if (holeType == Body::anus)
    {
        if(horny == 10)
        {
            updVSexVar(lubricant, -1);
        }
        int k = 0;
        if(horny > 0) { k = 10; }
        gapeBase = getVBody(Body::anus) + k + silavag * 2 + 2;
    }
    int gapeDiff = setGapeDick - gapeBase;
    int gapeTime;
    if (gapeDiff <= 0)
    {
        gapeTime = 0;
    }
    else if (gapeDiff <= 5)
    {
        gapeTime = 1*24 + getRandInt(6,12);
    }
    else if (gapeDiff <= 10)
    {
        gapeTime = 2*24 + getRandInt(6,16);
    }
    else
    {
        gapeTime = 3-24 + getRandInt(6,20);
    }

    if(holeType == Body::vagina)
    {
        if(getVSexVar(stat_vgape) > 0)
        {
            updVSexVar(vgape, 4);
        }
        updVSexVar(vgape, gapeTime);
        if(gapeDiff <= 3)
        {
            if(setGapeDick - 2 > getVBody(Body::vagina))
            {
                updVBody(Body::vagina, 1);
            }
        }
        else
        {
            updVBody(Body::vagina, 2);
        }
        int stat = getVSexVar(vgape)/24;
        if (getVSexVar(stat_vgape) > stat)
        {
            stat = stat - getVSexVar(stat_vgape);
        }
        else if (getVSexVar(stat_vgape) < stat)
        {
            stat = getVSexVar(stat_vgape) - stat;
        }
        updVSexVar(stat_vgape, stat);
    }
    if(holeType == Body::anus)
    {
        if(getVSexVar(stat_agape) > 0)
        {
            updVSexVar(agape, 4);
        }
        updVSexVar(agape, gapeTime);
        if(gapeDiff <= 3)
        {
            if((setGapeDick - 2) > getVBody(Body::anus))
            {
                updVBody(Body::anus, 1);
            }
        }
        else
        {
            updVBody(Body::anus, 2);
        }
        int stat = getVSexVar(agape)/24;
        if (getVSexVar(stat_agape) > stat)
        {
            stat = stat - getVSexVar(stat_agape);
        }
        else if (getVSexVar(stat_agape) < stat)
        {
            stat = getVSexVar(stat_agape) - stat;
        }
        updVSexVar(stat_agape, stat);
    }
}

void CCSex::slotSexCorrector()
{
    if (m_global_level_sex > 5) { m_global_level_sex = 5; }
    if (m_global_level_sex < 0) { m_global_level_sex = 0; }
    m_vag_corrector = (getRandInt(3+m_global_level_sex, 7+m_global_level_sex) + m_vag_corrector) / 2;
    m_anal_corrector = (getRandInt(4+m_global_level_sex, 10+m_global_level_sex) + m_anal_corrector) / 2;
}

int CCSex::getVagDamp()
{
    return getVaginaDampness();
}

int CCSex::getVStatus(Status param)
{
    return m_player->getVStatus(param);
}

int CCSex::getVBody(Body param)
{
    return m_player->getVBody(param);
}

int CCSex::getVSexVar(SexVar param)
{
    return m_player->getVSexVar(param);
}

void CCSex::updVStatus(Status param, int value)
{
    m_player->updVStatus(param, value);
}

void CCSex::updVBody(Body param, int value)
{
    m_player->updVBody(param, value);
}

void CCSex::updVSexVar(SexVar param, int value)
{
    m_player->updVSexVar(param, value);
}

void CCSex::setVSexVar(SexVar param, int value)
{
    m_player->setVSexVar(param,value);
}

void CCSex::setVStatus(Status param, int value)
{
    m_player->setVStatus(param, value);
}
