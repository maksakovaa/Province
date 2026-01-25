#include "ccsex.h"
#include "../Functions.h"
#include "../menu/mainwindow.h"

CCSex::CCSex(Game *ptr): root(ptr) {}

void CCSex::ability(Body holeType, int value)
{
    int maxStoreVagina {10}, maxStoreAnus {10};
    int tmp_vstore = maxStoreVagina - root->vSex(storeVagina) / maxStoreVagina;
    int tmp_astore = maxStoreAnus - root->vSex(storeAnus) / maxStoreAnus;
    if (holeType == Body::vagina)
    {
        if (value > 0) { /*update*/ root->vSex(vagina_ability) +=1; }
        else
        {
            if(root->vSex(vagina_ability) <= 0) { /*update*/ root->vSex(vagina_ability) += 0; }
            else { /*update*/ root->vSex(vagina_ability) -=1; }
        }
        if(root->vSex(vagina_ability) > maxStoreVagina)
        {
            /*update*/ root->vSex(storeVagina) += tmp_vstore;
            /*update*/ root->vSex(vagina_ability) -= tmp_vstore;
        }
    }
    else if (holeType == Body::anus)
    {
        if (value > 0) { /*update*/ root->vSex(anus_ability) += 1; }
        else
        {
            if (root->vSex(anus_ability) > maxStoreAnus)
            {
                /*update*/ root->vSex(storeAnus) += tmp_astore;
                /*update*/ root->vSex(anus_ability) -= tmp_astore;
            }
        }
        if (root->vSex(anus_ability) > maxStoreAnus)
        {
            /*update*/ root->vSex(storeAnus) += tmp_astore;
            /*update*/ root->vSex(anus_ability) += - tmp_astore;
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
        if (root->vSex(stat_vgape) != 0)
        {
            res = vag[root->vSex(stat_vgape)];
            res += "<br><br><b>Вы не можете вопользоваться вибратором, ждите пока заживёт, а пока посмотрите кино или почитайте порножурнал.</b>";
        }
        else if (root->vSex(dry_v_rubbing) > 24 || root->vSex(level_v_rubbing) > 10)
        {
            res = "<br>Ваше влагалище натёрто и болит.<br><br><b>Вы не можете вопользоваться анальной пробкой - вашей попе и так досталось.</b>";
        }
        else if (root->isMesec())
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

        if (root->vSex(stat_agape) != 0)
        {
            res = anal[root->vSex(stat_agape)];
            res += "<br><br><b>Вы не можете вопользоваться анальной пробкой - вашей попе и так досталось.</b>";
        }
        else if (root->vSex(dry_a_rubbing) > 24 || root->vSex(level_a_rubbing) > 10)
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

int CCSex::getVaginaDampness()
{
    int vag_grease = root->vStatus(vaginal_grease);
    if(vag_grease <= 0)
    {
        return 0;
    }
    else if (vag_grease < root->vConst(out_vaginal_grease))
    {
        return 1;
    }
    else if (vag_grease >= root->vConst(out_vaginal_grease) && vag_grease < (root->vConst(out_vaginal_grease) * 3))
    {
        return 2;
    }
    else if (vag_grease >= (root->vConst(out_vaginal_grease) * 3) && vag_grease < (root->vConst(out_vaginal_grease) * 5))
    {
        return 3;
    }
    else if (vag_grease >= (root->vConst(out_vaginal_grease) * 5) && vag_grease < root->vConst(many_vaginal_grease))
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
        int dry = root->vSex(dry_v_rubbing);
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
        int dry = root->vSex(dry_a_rubbing);
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
    if (root->vSex(level_v_rubbing) + root->vSex(level_a_rubbing) > 0)
    {
        root->vStatus(horny) -= (root->vSex(level_a_rubbing) + root->vSex(level_v_rubbing))*2/3;
        if (root->vStatus(horny) <= 0)
        {
            root->vStatus(horny) = 1;
        }
    }
    if (root->vSex(dry_v_rubbing) > 0)
    {
        root->vStatus(vaginal_grease) += getRandInt(0,root->vStatus(inc_vag_grease)/2);
    }
    int hornyVal = root->vStatus(horny);
    int v_level = root->vSex(level_v_rubbing);
    int a_level = 0;
    if(root->vSex(level_a_rubbing) != 0)
    {
        a_level = root->vSex(level_a_rubbing) / 2;
    }
    int a_dry = root->vSex(dry_a_rubbing);
    int v_dry = root->vSex(dry_v_rubbing);

    root->vStatus(vaginal_grease) += hornyVal/(10+v_level + a_level) - (v_dry + a_dry/2)*2/3;

    int d = root->vSex(vgape)/3 + root->vSex(agape)/5;
    root->vStatus(vaginal_grease) -= d;

    if (root->vStatus(vaginal_grease) < 0)
    {
       root->vStatus(vaginal_grease) = 0;
    }
    if (root->vStatus(vaginal_grease) > root->vConst(max_vaginal_grease))
    {
        root->vStatus(vaginal_grease) = root->vConst(max_vaginal_grease);
    }
}

void CCSex::slotVagGelTouch()
{
    int useAntiRub = root->vSex(use_anti_rubbing);
    int vagRubLvl = root->vSex(level_v_rubbing);
    int dryVagRub = root->vSex(dry_v_rubbing);

    if (useAntiRub > 0 || (useAntiRub > 0 && (vagRubLvl > 0 || dryVagRub > 0)))
    {
        /*update*/ root->vSex(dry_v_rubbing) -= root->vConst(dec_anti_rubbing);
        /*update*/ root->vSex(level_v_rubbing) -= root->vConst(dec_anti_rubbing) / 2;
        /*update*/ root->vSex(use_anti_rubbing) -= root->vConst(dec_anti_rubbing);
    }
}

void CCSex::slotDecRubbing(Body holeType)
{
    if(holeType == Body::vagina)
    {
        if(root->vSex(dry_v_rubbing) <= 0)
        {
            /*set*/ root->vSex(dry_v_rubbing) = 0;
            /*set*/ root->vSex(level_v_rubbing) = 0;
        }
        int _tmp = root->vSex(dry_v_rubbing) / 24;
        int moodDec = getRandInt(0, 3 + _tmp);
        root->vStatus(mood) -= moodDec;
        if(root->vStatus(mood) < 0) { root->vStatus(mood) = 0; }
        int healthDec = getRandInt(0, 1 + _tmp);
        root->vStatus(health) -= healthDec;
        if(root->vStatus(health) < 0) { root->vStatus(health) = 0; }
        root->vStatus(horny) -= root->vStatus(horny) / 10;

        int dryDec  = root->vSex(vagina_ability) / 2;
        if(root->vSex(dry_v_rubbing) > 0)
        {
            dryDec += getRandInt(1,2);
        }
        root->vSex(dry_v_rubbing) -= dryDec;
        int levelDex = root->vSex(vagina_ability) / 3;
        if(root->vSex(level_v_rubbing) > 0)
        {
            levelDex += 1;
        }
        /*update*/ root->vSex(level_v_rubbing) -= levelDex;
    }

    if(holeType == Body::anus)
    {
        if(root->vSex(dry_a_rubbing) <= 0)
        {
            /*set*/ root->vSex(dry_a_rubbing) = 0;
            /*set*/ root->vSex(level_a_rubbing) = 0;
        }
        int _tmp = root->vSex(dry_a_rubbing) / 24;
        int moodDec = getRandInt(0, 3 + _tmp);
        root->vStatus(mood) -= moodDec;
        if(root->vStatus(mood) < 0) { root->vStatus(mood) = 0; }
        int healthDec = getRandInt(0, 1+_tmp);
        root->vStatus(health) -= healthDec;
        if(root->vStatus(health) < 0) { root->vStatus(health) = 0; }
        root->vStatus(horny) -= root->vStatus(horny) / 10;

        int dryDec  = root->vSex(anus_ability) / 2;
        if(root->vSex(dry_a_rubbing) > 0)
        {
            dryDec += getRandInt(1,2);
        }
        /*update*/ root->vSex(dry_a_rubbing) -= dryDec;
        int levelDex = root->vSex(anus_ability) / 3;
        if(root->vSex(level_a_rubbing) > 0)
        {
            levelDex += 1;
        }
        /*update*/ root->vSex(level_a_rubbing) -= levelDex;
    }
}

void CCSex::antiRubbing()
{
    if (root->vSex(use_anti_rubbing) != 0)
    {
        //return to bag
    }
    else
    {
        /*update*/ root->vSex(use_anti_rubbing) += 160;
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
        gapeBase = root->vBody(Body::vagina) + horny / 20 + silavag * 2 + 2;
    }
    else if (holeType == Body::anus)
    {
        if(horny == 10)
        {
            /*update*/ root->vSex(lubricant) -=1;
        }
        int k = 0;
        if(horny > 0) { k = 10; }
        gapeBase = root->vBody(Body::anus) + k + silavag * 2 + 2;
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
        if(root->vSex(stat_vgape) > 0)
        {
            /*update*/ root->vSex(vgape) += 4;
        }
        /*update*/ root->vSex(vgape) += gapeTime;
        if(gapeDiff <= 3)
        {
            if(setGapeDick - 2 > root->vBody(Body::vagina))
            {
                root->vBody(vagina)  += 1;
            }
        }
        else
        {
            root->vBody(vagina)  += 2;
        }
        int stat = root->vSex(vgape)/24;
        if (root->vSex(stat_vgape) > stat)
        {
            stat = stat - root->vSex(stat_vgape);
        }
        else if (root->vSex(stat_vgape) < stat)
        {
            stat = root->vSex(stat_vgape) - stat;
        }
        /*update*/ root->vSex(stat_vgape) += stat;
    }
    if(holeType == Body::anus)
    {
        if(root->vSex(stat_agape) > 0)
        {
            /*update*/ root->vSex(agape) += 4;
        }
        /*update*/ root->vSex(agape) += gapeTime;
        if(gapeDiff <= 3)
        {
            if((setGapeDick - 2) > root->vBody(Body::anus))
            {
                root->vBody(Body::anus) += 1;
            }
        }
        else
        {
            root->vBody(Body::anus) += 2;
        }
        int stat = root->vSex(agape)/24;
        if (root->vSex(stat_agape) > stat)
        {
            stat = stat - root->vSex(stat_agape);
        }
        else if (root->vSex(stat_agape) < stat)
        {
            stat = root->vSex(stat_agape) - stat;
        }
        /*update*/ root->vSex(stat_agape) += stat;
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
