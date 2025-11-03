#include "mainwindow.h"
#include "sexviewform.h"
#include "player/enums.h"
#include "../ui_mainwindow.h"
#include "ui_sexviewform.h"
#include "Functions.h"

SelfPlay::SelfPlay(QWidget* parent)
{
    root = (SexViewForm*)parent;
    m_dildohand = 0;
}

void SelfPlay::start(Location *current)
{
    root->clearLayout();
    root->setMainWidgetpage(5);

    if(getVSexVar(mastrOnce) == 0)
    {
        root->updVSC(SC::masturbation,1);
        setVSexVar(mastrOnce, 1);
    }

    if(current->getLocId() == "bathroom_parents")
    {
        setImg("startvann");
    }
    else
    {
        setImg("start");
    }

    if(getCurLoc()->getLocId() == "my_bedr_parents")
    {
        // gs 'zz_family','sister_sheduler'
        // if $sister['location'] = 'bedrPar':
        //     *clr & cla
        //     gs 'stat'
        //     gs 'zz_render','','qwest/selfplay/start'
        //     SisterKnowMastr += 1
        //     gs 'zz_render', '', '', func('selfplay_strings'+$lang, 'txt_18')
        // end
    }

    // gs 'gadukino_event', 'gadsarai_check'
    // gs 'apartment_south_event','husband_check'
    // if selfplaytime > 5 and husband_inhouse > 0 and husband_know_mastr = 0:gt 'apartment_south_event','selfplay_husband'
    // if $loc = 'Gadsarai' and grandma_ingadsarai = 1:grandmaknowmastr = 1 & func('selfplay_strings'+$lang, 'txt_51')
    // if $loc = 'Gadsarai' and grandpa_ingadsarai = 1:grandpaknowmastr = 1 & func('selfplay_strings'+$lang, 'txt_52')

    if(getItemCount(iDildo) >= 1) appendDesc(getActDesc(descSP53));
    if(getItemCount(iMidDildo) >= 1) appendDesc(getActDesc(descSP54));
    if(getItemCount(iLargeDildo)>=1) appendDesc(getActDesc(descSP55));
    if(getItemCount(iBigDildo)>=1) appendDesc(getActDesc(descSP56));
    if(getItemCount(iExtraDildo)>=1) appendDesc(getActDesc(descSP57));
    if(getItemCount(iSuperDildo)>=1) appendDesc(getActDesc(descSP58));
    if(getItemCount(iMadDildo)>=1) appendDesc(getActDesc(descSP59));

    if (getVStatus(Status::horny) > 0 && getVSexVar(grandmaknowmastr) == 0 && getVSexVar(grandpaknowmastr) == 0)
    {
        makeActBtn(actSP8);
    }
    if (getVStatus(Status::horny) > 0 && getVSexVar(stat_agape) < 3 && getVSexVar(grandmaknowmastr) == 0 && getVSexVar(grandpaknowmastr) == 0)
    {
        makeActBtn(actSP9);
    }
    if (getVStatus(Status::horny) > 25 && getVSexVar(grandmaknowmastr) == 0 && getVSexVar(grandpaknowmastr) == 0)
    {
        if(getCurLoc()->getLocId() == "bedr_parents" ||
                 getItemCount(Items::iDildo) >= 1 ||
                 getItemCount(Items::iBigDildo) >= 1 ||
                 getItemCount(Items::iExtraDildo) >= 1||
                 getItemCount(Items::iLargeDildo) >= 1||
                 getItemCount(Items::iMadDildo) >= 1||
                 getItemCount(Items::iMidDildo) >=1 ||
                 getItemCount(Items::iSuperDildo) >= 1)
        {
            if(getCurLoc()->getLocId() == "bedr_parents")
            {
                m_dildohand = 10;
            }
            if(m_dildohand > 0)
            {
                setDesc(getActDesc(descSP45));
                if(getVSexVar(stat_vgape) <= 0)
                    makeActBtn(actSP14);
                if(getVSexVar(stat_agape) <= 0)
                    makeActBtn(actSP15);
                makeActBtn(actSP17);
            }
            else
            {
                if(getItemCount(iDildo) >= 1)
                    makeActBtn(actSP18);
                if(getItemCount(iMidDildo) >= 1)
                    makeActBtn(actSP19);
                if(getItemCount(iLargeDildo) >= 1)
                    makeActBtn(actSP20);
                if(getItemCount(iBigDildo) >= 1)
                    makeActBtn(actSP21);
                if(getItemCount(iExtraDildo) >= 1)
                    makeActBtn(actSP22);
                if(getItemCount(iSuperDildo) >= 1)
                    makeActBtn(actSP23);
                if(getItemCount(iMadDildo) >= 1)
                    makeActBtn(actSP24);
            }
        }
    }
    if (getVStatus(Status::horny) > 0 && getVSexVar(grandmaknowmastr) == 0 && getVSexVar(grandpaknowmastr) == 0)
    {
        makeActBtn(actSP1);
    }
    makeActBtn(actSP25);
    if(getCurLoc()->getLocId() == "bathroom_parents" && getVSexVar(selfplaytime) >= 60)
    {
        bathInvasion();
    }
}

void SelfPlay::slotActionHandler(SelfPlayActs act)
{
    root->clearLayout();
    switch (act) {
    case actSP1:
    {
        incTime(2);
        updVSexVar(selfplaytime, 2);
        if(getVBody(vagina) == 0 && getVStatus(mesec) <= 0)
        {
            setImg("finger");
            setDesc(getActDesc(descSP1));
            makeActBtn(actSP2);
        }
        else if (getVBody(vagina) > 0)
        {
            emit root->sigSetGape(vagina, getVStatus(horny), 3, 1);
            setDesc(getActDesc(descSP3));
            if (getVBody(vagina) < 5)
            {
                updVStatus(horny, getRandInt(2,5));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP4));
            }
            else if (getVBody(vagina) >= 5 && getVBody(vagina) < 10)
            {
                updVStatus(horny, getRandInt(5,10));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP5));
            }
            else if (getVBody(vagina) >= 10)
            {
                updVStatus(horny, getRandInt(2,5));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP6));
            }
            if (getVBody(vagina) < 5)
            {
                m_vagTemp += 1;
            }
            makeActBtn(actSP3);
        }
        else if (getVStatus(mesec) > 0)
        {
            updVStatus(mood, -5);
            setDesc(getActDesc(descSP9));
        }
        makeActBtn(actSP4);
    }
        break;
    case actSP2:
    {
        updVStatus(horny, -25);
        root->updVBody(vagina, 1);
        updVSexVar(selfplaytime, 5);
        updVStatus(mood, -100);
        incTime(5);
        setImg("finger.jpg");
        setDesc(getActDesc(descSP2));
        makeActBtn(actSP4);
    }
        break;
    case actSP3:
    {
        emit root->sigSetGape(vagina, getVStatus(horny), 10, 1);
        incTime(5);
        updVSexVar(selfplaytime, 5);
        if (getVBody(vagina) <= 10)
        {
            updVStatus(horny, getRandInt(5,10));
        }
        else
        {
            updVStatus(horny, getRandInt(2,5));
        }
        setImg("finger");
        setDesc(getActDesc(descSP7));
        if (getVBody(vagina) <= 10)
        {
            setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP47));
        }
        if (getVBody(vagina) > 10)
        {
            setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP48));
        }
        if (getVBody(vagina) < 10)
        {
            m_vagTemp += 1;
        }
        if (getVStatus(horny) >= 100)
        {
            root->updVSC(SC::orgasm, 1);
            setVStatus(mood, 100);
            setVStatus(horny,0);
            setVStatus(lust, 0);
            selfPlayEnding();
            setDesc(getActDesc(descSP8));
        }
        if(getVStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
        break;
    case actSP4:
        start(getCurLoc());
        break;
    case actSP5:
    {
        emit root->sigSetGape(vagina, getVStatus(horny), 15, 1);
        incTime(2);
        updVSexVar(selfplaytime, 2);
        setImg("hand");
        if (getVBody(vagina) > 0)
        {
            setDesc(getActDesc(descSP10));
            if (getVBody(vagina) < 10)
            {
                updVStatus(horny, -10);
                updVStatus(mood, -10);
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP11));
            }
            else if (getVBody(vagina) >= 10 && getVBody(vagina) < 15)
            {
                updVStatus(horny, getRandInt(1,3));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP12));
            }
            else if (getVBody(vagina) >= 15 && getVBody(vagina) < 20)
            {
                updVStatus(horny, getRandInt(3,6));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP13));
            }
            else if (getVBody(vagina) >= 20)
            {
                updVStatus(horny, getRandInt(6,12));
                setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP14));
            }
            if (getVBody(vagina) < 15)
            {
                m_vagTemp += 1;
            }
            makeActBtn(actSP6);               
        }
        makeActBtn(actSP4);
    }
        break;
    case actSP6:
    {
        emit root->sigSetGape(vagina, getVStatus(horny), 15, 1);
        incTime(5);
        updVSexVar(selfplaytime, 5);
        if (getVBody(vagina) < 10)
        {
            updVStatus(horny, -10);
            updVStatus(mood, -10);
        }
        setImg("hand");
        setDesc(getActDesc(descSP15));
        if (getVBody(vagina) <= 15)
        {
            updVStatus(horny, -10);
            updVStatus(mood, -10);
            setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP49));
        }
        if (getVBody(vagina) > 10)
        {
            updVStatus(horny, getRandInt(10,20));
            setDesc(root->ui->labelSexDesc->text() + "<br>" + getActDesc(descSP50));
        }
        if (getVBody(vagina) < 20)
        {
            m_vagTemp += 1;
        }
        if (getVStatus(horny) >= 100)
        {
            root->updVSC(SC::orgasm, 1);
            setVStatus(mood, 100);
            setVStatus(horny,0);
            setVStatus(lust, 0);
            selfPlayEnding();
        }
        if (getVStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
        break;
    case actSP7:
    {
        setVSexVar(analplay, 0);
        setVSexVar(selfplaytime, 0);
        setVSexVar(mastrOnce, 0);
        if(m_vagTemp > getVBody(vagina)*2)
        {
            root->updVBody(vagina, 1);
            m_vagTemp = 0;
        }
        root->changeLoc(root->getCurLoc());
    }
        break;
    case actSP8:
    {
        incTime(5);
        updVSexVar(selfplaytime, 5);
        if(getCurLoc()->getLocId() == "bathroom_parents")
        {
            setImg("klitvann");
        }
        else
        {
            setImg("klit");
        }
        if(getVStatus(mood) >= 50)
        {
            updVStatus(horny, getRandInt(5,10));
            setDesc(getActDesc(descSP19));
        }
        else
        {
            updVStatus(horny, getRandInt(0,1));
            setDesc(getActDesc(descSP20));
        }
        if(getVStatus(horny) >= 100)
        {
            root->updVSC(orgasm, 1);
            setVStatus(mood, 100);
            setVStatus(horny, 0);
            setVStatus(lust, 0);
            selfPlayEnding();
            setDesc(getActDesc(descSP21));
        }
        makeActBtn(actSP4);
        if(getVStatus(horny) > 0)
        {
            makeActBtn(actSP1);
        }
    }
        break;
    case actSP9:
    {
        incTime(5);
        updVSexVar(selfplaytime, 5);
        setImg("1");
        if(getVBody(anus) >= 3)
        {
            updVStatus(horny,1);
            setDesc(getActDesc(descSP22));
        }
        else if (getVBody(anus) < 3)
        {
            setDesc(getActDesc(descSP23));
        }
        if(root->getItemCount(lubri) > 0)
        {
            emit root->sigSetGape(anus, 10, 3, 0);
        }
        else
        {
            emit root->sigSetGape(anus, 0, 3, 0);
        }
        if(getCurLoc()->getLocId() == "bathroom_parents"
            && getVSexVar(selfplaytime) >= 60)
        {
            bathInvasion();
        }
        makeActBtn(actSP4);
        makeActBtn(actSP10);
    }
        break;
    case actSP10:
    {
        incTime(5);
        updVSexVar(selfplaytime,5);
        setImg("2");
        if(getVBody(anus) >= 5)
        {
            updVStatus(horny, 1);
            setDesc(getActDesc(descSP25));
            if(getVSexVar(stat_agape) > 0)
            {
                setDesc(getActDesc(descSP26));
            }
        }
        else if (getVBody(anus) >= 3 && getVBody(anus) < 5)
        {
            updVStatus(horny, getRandInt(3,5));
            setDesc(getActDesc(descSP27));
            if(getVSexVar(agape) > 0)
            {
                setDesc(getActDesc(descSP28));
            }
        }
        else if (getVBody(anus) >= 1 && getVBody(anus) < 3)
        {
            updVStatus(horny, -50);
            setDesc(getActDesc(descSP29));
        }
        if(root->getItemCount(lubri) > 0)
        {
            emit root->sigSetGape(anus, 10, 5, 0);
        }
        else
        {
            emit root->sigSetGape(anus, 0, 5, 0);
        }
        if(getVStatus(horny) >= 100)
        {
            root->updVSC(analOrgasm, 1);
            setVStatus(mood, 100);
            setVStatus(lust, 0);
            setVStatus(horny, 0);
            selfPlayEnding();
            setDesc(getActDesc(descSP16));
        }
        makeActBtn(actSP4);
        if(getCurLoc()->getLocId() == "bathroom_parents" && getVSexVar(selfplaytime) >= 60)
        {
            bathInvasion();
        }
        if(getVStatus(horny) > 0 && getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP11);
        }
    }
        break;
    case actSP11:
    {
        incTime(5);
        updVSexVar(selfplaytime,5);
        setImg("3");
        if(getVBody(anus) >= 10)
        {
            updVStatus(horny, 1);
            setDesc(getActDesc(descSP30));
            if(getVSexVar(stat_agape) > 0)
            {
                setDesc(getActDesc(descSP31));
            }
        }
        else if(getVBody(anus) >= 5 && getVBody(anus) < 10)
        {
            updVStatus(horny, getRandInt(2,5));
            setDesc(getActDesc(descSP32));
            if(getVSexVar(stat_agape) > 0)
            {
                setDesc(getActDesc(descSP33));
            }
        }
        else if(getVBody(anus) < 5)
        {
            updVStatus(horny, -50);
            setDesc(getActDesc(descSP34));
        }
        if(root->getItemCount(lubri) > 0)
        {
            emit root->sigSetGape(anus, 10, 10, 0);
        }
        else
        {
            emit root->sigSetGape(anus, 0, 10, 0);
        }
        if(getVStatus(horny) >= 100)
        {
            root->updVSC(analOrgasm, 1);
            setVStatus(mood, 100);
            setVStatus(lust, 0);
            setVStatus(horny, 0);
            selfPlayEnding();
            setDesc(getActDesc(descSP16));
        }
        makeActBtn(actSP4);
        if(getCurLoc()->getLocId() == "bathroom_parents" && getVSexVar(selfplaytime) >= 60)
        {
            bathInvasion();
        }
        if(getVStatus(horny) > 0 && getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP12);
        }
    }
        break;
    case actSP12:
    {
        incTime(5);
        updVSexVar(selfplaytime,5);
        setImg("4");
        if(getVBody(anus) >= 15)
        {
            setDesc(getActDesc(descSP35));
            if(getVSexVar(stat_agape) > 0)
            {
                updVStatus(horny,1);
                setDesc(getActDesc(descSP36));
            }
        }
        else if (getVBody(anus) >= 10 && getVBody(anus) < 15)
        {
            updVStatus(horny, getRandInt(2,5));
            setDesc(getActDesc(descSP37));
            if(getVSexVar(stat_agape) > 0)
            {
                setDesc(getActDesc(descSP38));
            }
        }
        else if(getVBody(anus) < 10)
        {
            updVStatus(horny, -50);
            setDesc(getActDesc(descSP39));
        }
        if(root->getItemCount(lubri) > 0)
        {
            emit root->sigSetGape(anus, 10, 15, 0);
        }
        else
        {
            emit root->sigSetGape(anus, 0, 15, 0);
        }
        if(getVStatus(horny) >= 100)
        {
            root->updVSC(analOrgasm, 1);
            setVStatus(mood, 100);
            setVStatus(lust, 0);
            setVStatus(horny, 0);
            selfPlayEnding();
            setDesc(getActDesc(descSP16));
        }
        makeActBtn(actSP4);
        if(getCurLoc()->getLocId() == "bathroom_parents" && getVSexVar(selfplaytime) >= 60)
        {
            bathInvasion();
        }
        if(getVStatus(horny) > 0 && getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP13);
        }
    }
        break;
    case actSP13:
    {
        updVSexVar(SelfFisting, 1);
        incTime(5);
        updVSexVar(selfplaytime, 5);
        setImg("5");
        if(getVBody(anus) >= 20)
        {
            updVStatus(horny, getRandInt(5,10));
            setDesc(getActDesc(descSP40));
            if(getVSexVar(stat_agape) > 0)
            {
                setDesc(getActDesc(descSP41));
            }
            else if (getVBody(anus) >= 15 && getVBody(anus) < 20)
            {
                updVStatus(horny, getRandInt(2,5));
                setDesc(getActDesc(descSP42));
                if(getVSexVar(stat_agape) > 0)
                {
                    setDesc(getActDesc(descSP43));
                }
            }
            else if(getVBody(anus) < 15)
            {
                updVStatus(horny, -50);
                setDesc(getActDesc(descSP44));
            }
            if(root->getItemCount(lubri) > 0)
            {
                emit root->sigSetGape(anus, 10, 15, 0);
            }
            else
            {
                emit root->sigSetGape(anus, 0, 15, 0);
            }
            makeActBtn(actSP4);
            if(getCurLoc()->getLocId() == "bathroom_parents" && getVSexVar(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            if(getVStatus(horny) >= 100)
            {
                root->updVSC(analOrgasm, 1);
                setVStatus(mood, 100);
                setVStatus(lust, 0);
                setVStatus(horny, 0);
                selfPlayEnding();
                setDesc(getActDesc(descSP16));
                makeActBtn(actSP4);            }
        }
    }
        break;
    case actSP14:
    {
        incTime(15);
        updVSexVar(selfplaytime,15);
        setVSexVar(dick, m_dildohand);
        //protect = 1;
        if(getCurLoc()->getLocId() == "bathroom_parents")
            setImg("dildovann");
        else
            setImg("dildo");
        root->m_sex->sexStart(1);
        root->m_sex->vaginal(tDildo);
        if(getVStatus(horny) == 0 || getVStatus(horny) < 35)
            selfPlayEnding();
        //if husband > 0 and husbandrink ! 10 and $loc = 'bedr': dynamic $husb_mastr_vtor
        makeActBtn(actSP4);
    }
        break;
    case actSP15:
    {
        incTime(15);
        updVSexVar(selfplaytime,15);
        setVSexVar(dick, m_dildohand);
        if(getCurLoc()->getLocId() == "bathroom_parents")
            setImg("dildovann");
        else
            setImg("dildo");
        root->m_sex->analStart(tDildo);
        root->m_sex->anal(tDildo);
        makeActBtn(actSP4);
    }
        break;
    case actSP16:
        break;
    case actSP17:
    {
        m_dildohand = 0;
        start(getCurLoc());
    }
        break;
    case actSP18:
    {
        m_dildohand = 10;
        start(getCurLoc());
    }
        break;
    case actSP19:
    {
        m_dildohand = 15;
        start(getCurLoc());
    }
        break;
    case actSP20:
    {
        m_dildohand = 20;
        start(getCurLoc());
    }
        break;
    case actSP21:
    {
        m_dildohand = 25;
        start(getCurLoc());
    }
        break;
    case actSP22:
    {
        m_dildohand = 30;
        start(getCurLoc());
    }
        break;
    case actSP23:
    {
        m_dildohand = 35;
        start(getCurLoc());
    }
        break;
    case actSP24:
    {
        m_dildohand = 40;
        start(getCurLoc());
    }
        break;
    case actSP25:
    {
        setVSexVar(analplay, 0);
        setVSexVar(selfplaytime, 0);
        setVSexVar(mastrOnce, 0);
        if(m_vagTemp > getVBody(vagina)*2)
        {
            root->updVBody(vagina, 1);
            m_vagTemp = 0;
        }
        if(getCurLoc()->getLocId() == "bedr_parents")
        {

        }
        root->changeLoc(root->getCurLoc());
    }
        break;
    case actSP26:
    {
        setVSexVar(analplay, 0);
        setVSexVar(selfplaytime, 0);
        setVSexVar(mastrOnce, 0);
        if(m_vagTemp > getVBody(vagina)*2)
        {
            root->updVBody(vagina, 1);
            m_vagTemp = 0;
        }
        root->changeLoc(root->getCurLoc());
    }
        break;
    default:
        break;
    }
    emit root->sigUpdParams();
}

Location *SelfPlay::getCurLoc()
{
    return root->getCurLoc();
}

void SelfPlay::makeActBtn(SelfPlayActs act)
{
    SexActionButton* btnx = new SexActionButton(act, getActName(act));
    connect(btnx, &SexActionButton::sigAction, this, &SelfPlay::slotActionHandler);
    root->m_actLayout->addWidget(btnx);
}

void SelfPlay::incTime(int min)
{
    root->incTime(min);
}

void SelfPlay::updVSexVar(SexVar var, int count)
{
    root->updSexVar(var, count);
}

int SelfPlay::getVSexVar(SexVar var)
{
    return root->getSexVar(var);
}

void SelfPlay::bathInvasion()
{
    if(/*$father['location'] = 'korrPar' or $mother['location'] = 'korrPar' or $sister['location'] = 'korrPar' or $brother['location'] = 'korrPar'*/false)
    {
        updVStatus(mood, -10);
        updVStatus(horny, -50);
        setDesc(getActDesc(descSP17));
        makeActBtn(actSP7);
    }
}

void SelfPlay::selfPlayEnding()
{
    setDesc(getActDesc(descSP16));
    makeActBtn(actSP26);
}

int SelfPlay::getVStatus(Status param)
{
    return root->getVStatus(param);
}

int SelfPlay::getVBody(Body param)
{
    return root->getVBody(param);
}

void SelfPlay::updVStatus(Status param, int value)
{
    root->updVStatus(param, value);
}

void SelfPlay::setVStatus(Status param, int value)
{
    root->setVStatus(param, value);
}

void SelfPlay::setVSexVar(SexVar param, int value)
{
    root->setSexVar(param,value);
}

void SelfPlay::setImg(QString text)
{
    root->ui->labelSexImg->setText("<img src=':/qwest/selfplay/" + text + ".jpg'></img>");
}

void SelfPlay::setDesc(QString text)
{
    root->ui->labelSexDesc->setText(text);
}

void SelfPlay::appendDesc(QString text)
{
    root->ui->labelSexDesc->setText(root->ui->labelSexDesc->text() + "<br>" + text);
}

int SelfPlay::getItemCount(Items i)
{
    return root->getItemCount(i);
}

QString SelfPlay::getActName(SelfPlayActs act)
{
    std::vector<QString> strings(26);
    strings[actSP1] = "Засунуть пальчик во влагалище";
    strings[actSP2] = "Проткнуть плеву";
    strings[actSP3] = "Трахать себя пальцами";
    strings[actSP4] = "Передохнуть";
    strings[actSP5] = "Засунуть ладонь во влагалище";
    strings[actSP6] = "Трахать себя ладонью";
    strings[actSP7] = "Выйти из ванной";
    strings[actSP8] = "Ласкать клитор";
    strings[actSP9] = "Засунуть палец в попу";
    strings[actSP10] = "Засунуть два пальца";
    strings[actSP11] = "Засунуть три пальца";
    strings[actSP12] = "Засунуть четыре пальца";
    strings[actSP13] = "Засунуть всю руку";
    strings[actSP14] = "Дилдо в киску";
    strings[actSP15] = "Дилдо в попу";
    strings[actSP16] = "res";
    strings[actSP17] = "Положить дилдо на место";
    strings[actSP18] = "Взять 10ти сантиметровый дилдо";
    strings[actSP19] = "Взять 15ти сантиметровый дилдо";
    strings[actSP20] = "Взять 20ти сантиметровый дилдо";
    strings[actSP21] = "Взять 25ти сантиметровый дилдо";
    strings[actSP22] = "Взять 30ти сантиметровый дилдо";
    strings[actSP23] = "Взять 35ти сантиметровый дилдо";
    strings[actSP24] = "Взять 40ти сантиметровый дилдо";
    strings[actSP25] = "Отказаться от этой затеи";
    strings[actSP26] = "Завершить маструбацию";
    return strings[act];
}

QString SelfPlay::getActDesc(SelfPlayDesc desc)
{
    std::vector<QString> strings(59);

    strings[descSP1] = "Вы поласкали пальчиками губки на своей мягкой и влажной киске и начали постепенно вводить себе палец в киску, но вы уткнулись в упругую преграду своей девственной плевы.";
    strings[descSP2] = "Вы засунули себе палец в киску и с силой надавили на плеву, она немного прогнулась внутрь вашего тела и вдруг прорвалась и ваш палец вошел внутрь полностью. Внутри киски стало немного больно, вы достали из себя палец и увидели, что он в крови.";
    strings[descSP3] = "Вы ввели себе палец во влагалище и затем еще один.";
    strings[descSP4] = "Скользкие стенки вашей киски очень плотно обхватили пальчики.";
    strings[descSP5] = "Вы чувствуете скользкие стенки вашей киски вокруг ваших пальчиков.";
    strings[descSP6] = "Ваша киска довольно просторна для пары пальцев и вы двигая пальцами чувствуете скользкие стенки вашей киски.";
    strings[descSP7] = "Вы начали трахать свою киску пальчиками вводя их себе в лоно и двигая ими.";
    strings[descSP8] = "Внезапно вас будто бы ударило током и внизу живота начались приятные спазмы ,вы извиваетесь закусив губу, что бы не закричать от удовольствия.";
    strings[descSP9] = "Вход во влагалище немного покрыт засохшей кровью от ваших месячных. Вы попробовали засунуть в себя палец, но вам тут же стало не приятно.";
    strings[descSP10] = "Вы ввели себе всю ладонь во влагалище.";
    strings[descSP11] = "Вы засунули все пальцы в киску и вам тут же стало очень больно.";
    strings[descSP12] = "Вы засунули все пальцы в вашу киску и почувствовали как ваше влагалище очень туго обхватывает пальцы, кажется еще чуть чуть и у вас что-нибудь порвется.";
    strings[descSP13] = "Вы засунули все пальцы в вашу киску и почувствовали как ваше влагалище туго обхватывает пальцы своими горячими и влажными стенками.";
    strings[descSP14] = "Вы засунули все пальцы в вашу киску и почувствовали как ваше влагалище обхватывает пальцы своими горячими и влажными стенками. Вас охватывает приятное ощущение наполненности.";
    strings[descSP15] = "Вы начали трахать свою киску пальчиками вводя их себе в лоно и двигая ими.";
    strings[descSP16] = "Внезапно вас будто бы ударило током и внизу живота начались приятные спазмы ,вы извиваетесь закусив губу, что бы не закричать от удовольствия.";
    strings[descSP17] = "В ванную постучали:\"Света! Ты что, утонула что ли? Выходи из ванной!\"";
    strings[descSP18] = "<font color = red><b>Аня увидела, что вы мастурбируете.</b></font>";
    strings[descSP19] = "Вы опустили руку себе между ног и нащупали в складках своей мягкой и влажной киски маленький бугорок прикосновения к которому очень приятны, вы начали ласкать пальчиками этот бугорок и наслаждаться чувством приятного тепла охватывающего вас между ног.";
    strings[descSP20] = "Вы ласкаете пальчиками клитор, вам хорошо и приятно, но ваше плохое настроение сказывается, вы никак не можете отвлечься от своих размышлений и у вас не получается возбудиться.";
    strings[descSP21] = "Внезапно вас будто бы ударило током и внизу живота начались приятные спазмы ,вы извиваетесь закусив губу, что бы не закричать от удовольствия.";
    strings[descSP22] = "Вы засунули пальчик в свою попу и он свободно проскользнул в ваш анус.";
    strings[descSP23] = "Вы засунули пальчик в свою попу и почувствовали как анус туго обхватил ваш палец.";
    strings[descSP24] = "Вы засунули пальчик в свою девственную попу и почувствовали как анус туго обхватил ваш палец.";
    strings[descSP25] = "Вы спокойно засунули два пальчика в вашу попку.";
    strings[descSP26] = "У вас уже болит попа и засунув два пальчика вы еще сильнее ее повредили.";
    strings[descSP27] = "Вы засунули два пальчика в свою попу и ваш анус туго обхватил их.";
    strings[descSP28] = "У вас уже болит попа и засунув два пальчика вы еще сильнее ее повредили.";
    strings[descSP29] = "Вы засунули два пальца в свою попу и почувствовали резкую боль в вашем анусе.";
    strings[descSP30] = "Вы спокойно засунули три пальчика в вашу попку.";
    strings[descSP31] = "У вас уже болит попа и засунув три пальчика вы еще сильнее ее повредили.";
    strings[descSP32] = "Вы засунули три пальчика в свою попу и ваш анус туго обхватил их.";
    strings[descSP33] = "У вас уже болит попа и засунув три пальчика вы еще сильнее ее повредили.";
    strings[descSP34] = "Вы засунули три пальца в свою попу и почувствовали резкую боль в вашем анусе.";
    strings[descSP35] = "Вы спокойно засунули ладонь в вашу попку.";
    strings[descSP36] = "У вас уже болит попа и засунув четыре пальчика вы еще сильнее ее повредили.";
    strings[descSP37] = "Вы засунули ладонь в свою попу и ваш анус туго обхватил их.";
    strings[descSP38] = "У вас уже болит попа и засунув ладонь вы еще сильнее ее повредили.";
    strings[descSP39] = "Вы засунули ладонь в свою попу и почувствовали резкую боль в вашем анусе.";
    strings[descSP41] = "У вас уже болит попа и засунув руку вы еще сильнее ее повредили.";
    strings[descSP42] = "Вы засунули руку в свою попу и ваш анус туго ее обхватил.";
    strings[descSP43] = "У вас уже болит попа и засунув руку вы еще сильнее ее повредили.";
    strings[descSP44] = "Вы засунули руку в свою попу и почувствовали резкую боль в вашем анусе.";
    strings[descSP45] = "У вас в руках " + intQStr(m_dildohand) + "ти сантиметровый дилдо";
    strings[descSP46] = "У вас нет дилдо в руках";
    strings[descSP47] = "Ваша киска нежно обхватывает ваши пальчики и вы чувствуете приятно тепло разливающееся внизу живота.";
    strings[descSP48] = "Вагина довольно просторная и вам приходится довольно сильно потрудиться, что бы хоть что-то ощущать от своих пальцев.";
    strings[descSP49] = "Вам больно когда вы пытаетесь трахать свою киску всей ладонью.";
    strings[descSP50] = "Вагина довольно просторная и вам приходится довольно сильно потрудиться, что бы хоть что-то ощущать от своих пальцев.";
    strings[descSP51] = "<font color = red><b>Бабушка увидела, что вы мастурбируете.</b></font>";
    strings[descSP52] = "<font color = red><b>Дед увидел, что вы мастурбируете.</b></font>";
    strings[descSP53] = "У вас есть маленький дилдо длиной 10 см.";
    strings[descSP54] = "У вас есть дилдо длиной 15 см.";
    strings[descSP55] = "У вас есть дилдо длиной 20 см.";
    strings[descSP56] = "У вас есть дилдо длиной 25 см.";
    strings[descSP57] = "У вас есть дилдо длиной 30 см.";
    strings[descSP58] = "У вас есть дилдо длиной 35 см.";
    strings[descSP59] = "У вас есть дилдо длиной 40 см.";

    return strings[desc];
}
