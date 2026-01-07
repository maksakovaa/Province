#include "selfplay.h"
#include "player/enums.h"
#include "Functions.h"
#include "sexhandler.h"

SelfPlay::SelfPlay(SexHandler* parent): root(parent)
{
    m_dildohand = 0;
}

void SelfPlay::start()
{
    slotActionHandler(actSP0);
}

void SelfPlay::slotActionHandler(SelfPlayActs act)
{
    current = act;
    ClearLayout(root->m_actions);
    switch (act) {
    case actSP0:
    case actSP4:
        {
            root->m_render->rendImagePage(root);
//            root->setMainWidgetpage(5);

            if(root->getVSexVar(mastrOnce) == 0)
            {
                root->updVSC(SC::masturbation,1);
                root->setVSexVar(mastrOnce, 1);
            }

            if(root->getCurLoc() == lbathroom)
                root->m_render->setImage("data/qwest/selfplay/startvann.jpg");
            else
                root->m_render->setImage("data/qwest/selfplay/start.jpg");

            if(root->getCurLoc() == lbedrpar)
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

            if(root->getItemCount(iDildo) >= 1) root->m_render->addText(getActDesc(descSP53));
            if(root->getItemCount(iMidDildo) >= 1) root->m_render->addText(getActDesc(descSP54));
            if(root->getItemCount(iLargeDildo)>=1) root->m_render->addText(getActDesc(descSP55));
            if(root->getItemCount(iBigDildo)>=1) root->m_render->addText(getActDesc(descSP56));
            if(root->getItemCount(iExtraDildo)>=1) root->m_render->addText(getActDesc(descSP57));
            if(root->getItemCount(iSuperDildo)>=1) root->m_render->addText(getActDesc(descSP58));
            if(root->getItemCount(iMadDildo)>=1) root->m_render->addText(getActDesc(descSP59));

            if (root->getVStatus(Status::horny) > 25 && root->getVSexVar(grandmaknowmastr) == 0 && root->getVSexVar(grandpaknowmastr) == 0)
            {
                if(root->getCurLoc() == lbedrpar2 ||
                        root->getItemCount(Items::iDildo) >= 1 ||
                        root->getItemCount(Items::iBigDildo) >= 1 ||
                        root->getItemCount(Items::iExtraDildo) >= 1||
                        root->getItemCount(Items::iLargeDildo) >= 1||
                        root->getItemCount(Items::iMadDildo) >= 1||
                        root->getItemCount(Items::iMidDildo) >=1 ||
                        root->getItemCount(Items::iSuperDildo) >= 1)
                {
                    if(root->getCurLoc() == lbedrpar2 && root->getVSexVar(selfmomtoyplay) == 1)
                    {
                        m_dildohand = 10;
                    }
                    if(m_dildohand > 0)
                    {
                        root->m_render->addText(getActDesc(descSP45));
                    }
                }
            }
            makeButtons();
            if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60) bathInvasion();
        }
        break;
    case actSP1:
        {
            root->incTime(2);
            root->updVSexVar(selfplaytime, 2);
            if(root->getVBody(vagina) == 0 && root->getVStatus(mesec) <= 0)
            {
                root->m_render->setImage("data/qwest/selfplay/finger.jpg");
                root->m_render->setText(getActDesc(descSP1));
            }
            else if (root->getVBody(vagina) > 0)
            {
                emit root->setGape(vagina, root->getVStatus(horny), 3, 1);
                root->m_render->setText(getActDesc(descSP3));
                if (root->getVBody(vagina) < 5)
                {
                    root->updVStatus(horny, getRandInt(2,5));
                    root->m_render->addText("<br>" + getActDesc(descSP4));
                }
                else if (root->getVBody(vagina) >= 5 && root->getVBody(vagina) < 10)
                {
                    root->updVStatus(horny, getRandInt(5,10));
                    root->m_render->addText("<br>" + getActDesc(descSP5));
                }
                else if (root->getVBody(vagina) >= 10)
                {
                    root->updVStatus(horny, getRandInt(2,5));
                    root->m_render->addText("<br>" + getActDesc(descSP6));
                }
                if (root->getVBody(vagina) < 5)
                {
                    m_vagTemp += 1;
                }
            }
            else if (root->getVStatus(mesec) > 0)
            {
                root->updVStatus(mood, -5);
                root->m_render->setText(getActDesc(descSP9));
            }
            makeButtons();
        }
        break;
    case actSP2:
        {
            root->updVStatus(horny, -25);
            root->updVBody(vagina, 1);
            root->updVSexVar(selfplaytime, 5);
            root->updVStatus(mood, -100);
            root->incTime(5);
            root->m_render->setImage("data/qwest/selfplay/finger.jpg");
            root->m_render->setText(getActDesc(descSP2));
            makeButtons();
        }
        break;
    case actSP3:
        {
            emit root->setGape(vagina, root->getVStatus(horny), 10, 1);
            root->incTime(5);
            root->updVSexVar(selfplaytime, 5);
            if (root->getVBody(vagina) <= 10)
            {
                root->updVStatus(horny, getRandInt(5,10));
            }
            else
            {
                root->updVStatus(horny, getRandInt(2,5));
            }
            root->m_render->setImage("data/qwest/selfplay/finger.jpg");
            root->m_render->setText(getActDesc(descSP7));
            if (root->getVBody(vagina) <= 10)
            {
                root->m_render->addText("<br>" + getActDesc(descSP47));
            }
            if (root->getVBody(vagina) > 10)
            {
                root->m_render->addText("<br>" + getActDesc(descSP48));
            }
            if (root->getVBody(vagina) < 10)
            {
                m_vagTemp += 1;
            }
            if (root->getVStatus(horny) >= 100)
            {
                root->updVSC(SC::orgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(horny,0);
                root->setVStatus(lust, 0);
                selfPlayEnding();
                root->m_render->addText(getActDesc(descSP8));
            }
            makeButtons();
        }
        break;
    case actSP5:
        {
            emit root->setGape(vagina, root->getVStatus(horny), 15, 1);
            root->incTime(2);
            root->updVSexVar(selfplaytime, 2);
            root->m_render->setImage("data/qwest/selfplay/hand.jpg");
            if (root->getVBody(vagina) > 0)
            {
                root->m_render->setText(getActDesc(descSP10));
                if (root->getVBody(vagina) < 10)
                {
                    root->updVStatus(horny, -10);
                    root->updVStatus(mood, -10);
                    root->m_render->addText("<br>" + getActDesc(descSP11));
                }
                else if (root->getVBody(vagina) >= 10 && root->getVBody(vagina) < 15)
                {
                    root->updVStatus(horny, getRandInt(1,3));
                    root->m_render->addText("<br>" + getActDesc(descSP12));
                }
                else if (root->getVBody(vagina) >= 15 && root->getVBody(vagina) < 20)
                {
                    root->updVStatus(horny, getRandInt(3,6));
                    root->m_render->addText("<br>" + getActDesc(descSP13));
                }
                else if (root->getVBody(vagina) >= 20)
                {
                    root->updVStatus(horny, getRandInt(6,12));
                    root->m_render->addText("<br>" + getActDesc(descSP14));
                }
                if (root->getVBody(vagina) < 15)
                {
                    m_vagTemp += 1;
                }              
            }
            makeButtons();
        }
        break;
    case actSP6:
        {
            emit root->setGape(vagina, root->getVStatus(horny), 15, 1);
            root->incTime(5);
            root->updVSexVar(selfplaytime, 5);
            if (root->getVBody(vagina) < 10)
            {
                root->updVStatus(horny, -10);
                root->updVStatus(mood, -10);
            }
            root->m_render->setImage("data/qwest/selfplay/hand.jpg");
            root->m_render->setText(getActDesc(descSP15));
            if (root->getVBody(vagina) <= 15)
            {
                root->updVStatus(horny, -10);
                root->updVStatus(mood, -10);
                root->m_render->addText("<br>" + getActDesc(descSP49));
            }
            if (root->getVBody(vagina) > 10)
            {
                root->updVStatus(horny, getRandInt(10,20));
                root->m_render->addText("<br>" + getActDesc(descSP50));
            }
            if (root->getVBody(vagina) < 20)
            {
                m_vagTemp += 1;
            }
            if (root->getVStatus(horny) >= 100)
            {
                root->updVSC(SC::orgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(horny,0);
                root->setVStatus(lust, 0);
                selfPlayEnding();
            }
            makeButtons();
        }
        break;
    case actSP7:
        {
            root->setVSexVar(analplay, 0);
            root->setVSexVar(selfplaytime, 0);
            root->setVSexVar(mastrOnce, 0);
            if(m_vagTemp > root->getVBody(vagina)*2)
            {
                root->updVBody(vagina, 1);
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    case actSP8:
        {
            root->incTime(5);
            root->updVSexVar(selfplaytime, 5);
            if(root->getCurLoc() == lbathroom)
            {
                root->m_render->setImage("data/qwest/selfplay/klitvann.jpg");
            }
            else
            {
                root->m_render->setImage("data/qwest/selfplay/klit.jpg");
            }
            if(root->getVStatus(mood) >= 50)
            {
                root->updVStatus(horny, getRandInt(5,10));
                root->m_render->setText(getActDesc(descSP19));
            }
            else
            {
                root->updVStatus(horny, getRandInt(0,1));
                root->m_render->setText(getActDesc(descSP20));
            }
            if(root->getVStatus(horny) >= 100)
            {
                root->updVSC(orgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(horny, 0);
                root->setVStatus(lust, 0);
                selfPlayEnding();
                root->m_render->addText(getActDesc(descSP21));
            }
            makeButtons();
        }
        break;
    case actSP9:
        {
            root->incTime(5);
            root->updVSexVar(selfplaytime, 5);
            root->m_render->setImage("data/qwest/selfplay/1.jpg");
            if(root->getVBody(anus) >= 3)
            {
                root->updVStatus(horny,1);
                root->m_render->setText(getActDesc(descSP22));
            }
            else if (root->getVBody(anus) < 3)
            {
                root->m_render->setText(getActDesc(descSP23));
            }
            if(root->getItemCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 3, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 3, 0);
            }
            if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP10:
        {
            root->incTime(5);
            root->updVSexVar(selfplaytime,5);
            root->m_render->setImage("data/qwest/selfplay/2.jpg");
            if(root->getVBody(anus) >= 5)
            {
                root->updVStatus(horny, 1);
                root->m_render->setText(getActDesc(descSP25));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP26));
                }
            }
            else if (root->getVBody(anus) >= 3 && root->getVBody(anus) < 5)
            {
                root->updVStatus(horny, getRandInt(3,5));
                root->m_render->setText(getActDesc(descSP27));
                if(root->getVSexVar(agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP28));
                }
            }
            else if (root->getVBody(anus) >= 1 && root->getVBody(anus) < 3)
            {
                root->updVStatus(horny, -50);
                root->m_render->setText(getActDesc(descSP29));
            }
            if(root->getItemCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 5, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 5, 0);
            }
            if(root->getVStatus(horny) >= 100)
            {
                root->updVSC(analOrgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(lust, 0);
                root->setVStatus(horny, 0);
                selfPlayEnding();
                root->m_render->setText(getActDesc(descSP16));
            }
            makeButtons();            
            if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60)
            {
                bathInvasion();
            }
        }
        break;
    case actSP11:
        {
            root->incTime(5);
            root->updVSexVar(selfplaytime,5);
            root->m_render->setImage("data/qwest/selfplay/3.jpg");
            if(root->getVBody(anus) >= 10)
            {
                root->updVStatus(horny, 1);
                root->m_render->setText(getActDesc(descSP30));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP31));
                }
            }
            else if(root->getVBody(anus) >= 5 && root->getVBody(anus) < 10)
            {
                root->updVStatus(horny, getRandInt(2,5));
                root->m_render->setText(getActDesc(descSP32));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP33));
                }
            }
            else if(root->getVBody(anus) < 5)
            {
                root->updVStatus(horny, -50);
                root->m_render->setText(getActDesc(descSP34));
            }
            if(root->getItemCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 10, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 10, 0);
            }
            if(root->getVStatus(horny) >= 100)
            {
                root->updVSC(analOrgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(lust, 0);
                root->setVStatus(horny, 0);
                selfPlayEnding();
                root->m_render->setText(getActDesc(descSP16));
            }
            
            if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP12:
        {
            root->incTime(5);
            root->updVSexVar(selfplaytime,5);
            root->m_render->setImage("data/qwest/selfplay/4.jpg");
            if(root->getVBody(anus) >= 15)
            {
                root->m_render->setText(getActDesc(descSP35));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->updVStatus(horny,1);
                    root->m_render->setText(getActDesc(descSP36));
                }
            }
            else if (root->getVBody(anus) >= 10 && root->getVBody(anus) < 15)
            {
                root->updVStatus(horny, getRandInt(2,5));
                root->m_render->setText(getActDesc(descSP37));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP38));
                }
            }
            else if(root->getVBody(anus) < 10)
            {
                root->updVStatus(horny, -50);
                root->m_render->setText(getActDesc(descSP39));
            }
            if(root->getItemCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 15, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 15, 0);
            }
            if(root->getVStatus(horny) >= 100)
            {
                root->updVSC(analOrgasm, 1);
                root->setVStatus(mood, 100);
                root->setVStatus(lust, 0);
                root->setVStatus(horny, 0);
                selfPlayEnding();
                root->m_render->setText(getActDesc(descSP16));
            }
            
            if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP13:
        {
            root->updVSexVar(SelfFisting, 1);
            root->incTime(5);
            root->updVSexVar(selfplaytime, 5);
            root->m_render->setImage("data/qwest/selfplay/5.jpg");
            if(root->getVBody(anus) >= 20)
            {
                root->updVStatus(horny, getRandInt(5,10));
                root->m_render->setText(getActDesc(descSP40));
                if(root->getVSexVar(stat_agape) > 0)
                {
                    root->m_render->setText(getActDesc(descSP41));
                }
                else if (root->getVBody(anus) >= 15 && root->getVBody(anus) < 20)
                {
                    root->updVStatus(horny, getRandInt(2,5));
                    root->m_render->setText(getActDesc(descSP42));
                    if(root->getVSexVar(stat_agape) > 0)
                    {
                        root->m_render->setText(getActDesc(descSP43));
                    }
                }
                else if(root->getVBody(anus) < 15)
                {
                    root->updVStatus(horny, -50);
                    root->m_render->setText(getActDesc(descSP44));
                }
                if(root->getItemCount(iLubri) > 0)
                {
                    emit root->setGape(anus, 10, 15, 0);
                }
                else
                {
                    emit root->setGape(anus, 0, 15, 0);
                }
                if(root->getPrevLoc() == lkorrpar && root->getVSexVar(selfplaytime) >= 60)
                {
                    bathInvasion();
                }
                if(root->getVStatus(horny) >= 100)
                {
                    root->updVSC(analOrgasm, 1);
                    root->setVStatus(mood, 100);
                    root->setVStatus(lust, 0);
                    root->setVStatus(horny, 0);
                    selfPlayEnding();
                    root->m_render->setText(getActDesc(descSP16));
                }
                makeButtons();
            }
        }
        break;
    case actSP14:
        {
            root->incTime(15);
            root->updVSexVar(selfplaytime,15);
            root->setVSexVar(dick, m_dildohand);
            //protect = 1;
            if(root->getPrevLoc() == lkorrpar)
                root->m_render->setImage("data/qwest/selfplay/dildovann.jpg");
            else
                root->m_render->setImage("data/qwest/selfplay/dildo.jpg");
            root->setVSexVar(protect,1);
            root->m_sex->sexStart();
            root->m_sex->vaginal(tDildo);
            if(root->getVStatus(horny) == 0 || root->getVStatus(horny) < 35)
                selfPlayEnding();
            //if husband > 0 and husbandrink ! 10 and $loc = 'bedr': dynamic $husb_mastr_vtor
            makeButtons();
        }
        break;
    case actSP15:
        {
            root->incTime(15);
            root->updVSexVar(selfplaytime,15);
            root->setVSexVar(dick, m_dildohand);
            if(root->getPrevLoc() == lkorrpar)
                root->m_render->setImage("data/qwest/selfplay/dildovann.jpg");
            else
                root->m_render->setImage("data/qwest/selfplay/dildo.jpg");
            root->m_sex->analStart(tDildo);
            root->m_sex->anal(tDildo);
            makeButtons();
        }
        break;
    case actSP16://RESERVED
        break;
    case actSP17:
        {
            m_dildohand = 0;
            slotActionHandler(actSP0);
        }
        break;
    case actSP18:
        {
            m_dildohand = 10;
            slotActionHandler(actSP0);
        }
        break;
    case actSP19:
        {
            m_dildohand = 15;
            slotActionHandler(actSP0);
        }
        break;
    case actSP20:
        {
            m_dildohand = 20;
            slotActionHandler(actSP0);
        }
        break;
    case actSP21:
        {
            m_dildohand = 25;
            slotActionHandler(actSP0);
        }
        break;
    case actSP22:
        {
            m_dildohand = 30;
            slotActionHandler(actSP0);
        }
        break;
    case actSP23:
        {
            m_dildohand = 35;
            slotActionHandler(actSP0);
        }
        break;
    case actSP24:
        {
            m_dildohand = 40;
            slotActionHandler(actSP0);
        }
        break;
    case actSP25:
        {
            root->setVSexVar(analplay, 0);
            root->setVSexVar(selfplaytime, 0);
            root->setVSexVar(mastrOnce, 0);
            if(m_vagTemp > root->getVBody(vagina)*2)
            {
                root->updVBody(vagina, 1);
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    case actSP26:
        {
            root->setVSexVar(analplay, 0);
            root->setVSexVar(selfplaytime, 0);
            root->setVSexVar(mastrOnce, 0);
            if(m_vagTemp > root->getVBody(vagina)*2)
            {
                root->updVBody(vagina, 1);
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    default:
        break;
    }
    root->updParams();
}

void SelfPlay::makeButtons()
{
    if (current == actSP0 || current == actSP4)
    {
        if (root->getVStatus(Status::horny) > 0 && root->getVSexVar(grandmaknowmastr) == 0 && root->getVSexVar(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP8);
        }
        if (root->getVStatus(Status::horny) > 0 && root->getVSexVar(stat_agape) < 3 && root->getVSexVar(grandmaknowmastr) == 0 && root->getVSexVar(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP9);
        }
        if (root->getVStatus(Status::horny) > 25 && root->getVSexVar(grandmaknowmastr) == 0 && root->getVSexVar(grandpaknowmastr) == 0)
        {
            if (root->getCurLoc() == lbedrpar2 ||
                root->getItemCount(Items::iDildo) >= 1 ||
                root->getItemCount(Items::iBigDildo) >= 1 ||
                root->getItemCount(Items::iExtraDildo) >= 1 ||
                root->getItemCount(Items::iLargeDildo) >= 1 ||
                root->getItemCount(Items::iMadDildo) >= 1 ||
                root->getItemCount(Items::iMidDildo) >= 1 ||
                root->getItemCount(Items::iSuperDildo) >= 1)
            {
                if (m_dildohand > 0)
                {
                    if (root->getVSexVar(stat_vgape) <= 0)
                        makeActBtn(actSP14);
                    if (root->getVSexVar(stat_agape) <= 0)
                        makeActBtn(actSP15);
                    makeActBtn(actSP17);
                }
                else
                {
                    if (root->getItemCount(iDildo) >= 1)
                        makeActBtn(actSP18);
                    if (root->getItemCount(iMidDildo) >= 1)
                        makeActBtn(actSP19);
                    if (root->getItemCount(iLargeDildo) >= 1)
                        makeActBtn(actSP20);
                    if (root->getItemCount(iBigDildo) >= 1)
                        makeActBtn(actSP21);
                    if (root->getItemCount(iExtraDildo) >= 1)
                        makeActBtn(actSP22);
                    if (root->getItemCount(iSuperDildo) >= 1)
                        makeActBtn(actSP23);
                    if (root->getItemCount(iMadDildo) >= 1)
                        makeActBtn(actSP24);
                }
            }
        }
        if (root->getVStatus(Status::horny) > 0 && root->getVSexVar(grandmaknowmastr) == 0 && root->getVSexVar(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP1);
        }
        makeActBtn(actSP25);
    }
    else if (current == actSP1)
    {
        if(root->getVBody(vagina) == 0 && root->getVStatus(mesec) <= 0)
        {
            makeActBtn(actSP2);
        }
        else if (root->getVBody(vagina) > 0)
        {
            makeActBtn(actSP3);
        }
        makeActBtn(actSP4);
    }
    else if (current == actSP2 || current == actSP13 || current == actSP14 || current == actSP15)
    {
        makeActBtn(actSP4);
    }
    else if (current == actSP3)
    {
        if (root->getVStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
    else if(current == actSP5)
    {
        if (root->getVBody(vagina) > 0)
        {
            makeActBtn(actSP6); 
        }
        makeActBtn(actSP4);
    }
    else if (current == actSP6)
    {
        if (root->getVStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
    else if(current == actSP8)
    {
        makeActBtn(actSP4);
        if (root->getVStatus(horny) > 0)
        {
            makeActBtn(actSP1);
        }
    }
    else if (current == actSP9)
    {
        makeActBtn(actSP4);
        makeActBtn(actSP10);
    }
    else if (current == actSP10)
    {
        makeActBtn(actSP4);
        if (root->getVStatus(horny) > 0 && root->getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP11);
        }
    }
    else if (current == actSP11)
    {
        makeActBtn(actSP4);
        if (root->getVStatus(horny) > 0 && root->getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP12);
        }
    }
    else if (current == actSP12)
    {
        makeActBtn(actSP4);
        if (root->getVStatus(horny) > 0 && root->getVSexVar(stat_agape) < 3)
        {
            makeActBtn(actSP13);
        }
    }    
}

void SelfPlay::makeActBtn(SelfPlayActs act)
{
    SexActionButton* btnx = new SexActionButton(act, getActName(act));
    connect(btnx, &SexActionButton::sigAction, this, &SelfPlay::slotActionHandler);
    root->m_actions->addWidget(btnx);
}

void SelfPlay::bathInvasion()
{
    if(/*$father['location'] = 'korrPar' or $mother['location'] = 'korrPar' or $sister['location'] = 'korrPar' or $brother['location'] = 'korrPar'*/false)
    {
        root->updVStatus(mood, -10);
        root->updVStatus(horny, -50);
        root->m_render->setText(getActDesc(descSP17));
        makeActBtn(actSP7);
    }
}

void SelfPlay::selfPlayEnding()
{
    root->m_render->setText(getActDesc(descSP16));
    makeActBtn(actSP26);
}

QString SelfPlay::getActName(SelfPlayActs act)
{
    std::vector<QString> strings(27);
    strings[actSP0] = "";
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
