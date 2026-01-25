#include "selfplay.h"
#include "../player/enums.h"
#include "../Functions.h"
#include "../game.h"

SelfPlay::SelfPlay(Game* parent): root(parent) {}

void SelfPlay::start()
{
    slotActionHandler(actSP0);
}

void SelfPlay::slotActionHandler(SelfPlayActs act)
{
    current = act;
    root->clearActions();
    switch (act) {
    case actSP0:
    case actSP4:
        {
            root->rendImagePage(root);
            if(root->vSex(mastrOnce) == 0)
            {
                root->vStatistics(masturbation) += 1;
                root->vSex(mastrOnce) = 1;
            }

            if(root->getCurLoc() == lbathroom)
                root->setImage("data/sex/selfplay/startvann.jpg");
            else
                root->setImage("data/sex/selfplay/start.jpg");

            if(root->getCurLoc() == lbedrpar)
            {
                root->startEvent(eFamily, "sister_sheduler");
                if(root->gNPC(sister).location == lbedrpar)
                {
                    root->setImage("data/sex/selfplay/start.jpg");
                    root->vEvent(sisterKnowMastr) += 1;
                    root->setText(getActDesc(descSP18));
                }
            }

            root->startEvent(eGadukinoEvents,"gadsarai_check");
            if(root->getCurLoc() == lgadsarai && root->vEvent(grandma_ingadsarai) == 1)
            {
                root->vSex(grandmaknowmastr) = 1;
                root->addText(getActDesc(descSP51));
            }
            if(root->getCurLoc() == lgadsarai && root->vEvent(grandpa_ingadsarai) == 1)
            {
                root->vSex(grandpaknowmastr) = 1;
                root->addText(getActDesc(descSP52));
            }
            // gs 'apartment_south_event','husband_check'
            // if selfplaytime > 5 and husband_inhouse > 0 and husband_know_mastr = 0:gt 'apartment_south_event','selfplay_husband'

            if(root->getItmCount(iDildo) >= 1) root->addText(getActDesc(descSP53));
            if(root->getItmCount(iMidDildo) >= 1) root->addText(getActDesc(descSP54));
            if(root->getItmCount(iLargeDildo)>=1) root->addText(getActDesc(descSP55));
            if(root->getItmCount(iBigDildo)>=1) root->addText(getActDesc(descSP56));
            if(root->getItmCount(iExtraDildo)>=1) root->addText(getActDesc(descSP57));
            if(root->getItmCount(iSuperDildo)>=1) root->addText(getActDesc(descSP58));
            if(root->getItmCount(iMadDildo)>=1) root->addText(getActDesc(descSP59));

            if (root->vStatus(Status::horny) > 25 && root->vSex(grandmaknowmastr) == 0 && root->vSex(grandpaknowmastr) == 0)
            {
                if(root->getCurLoc() == lbedrpar2 ||
                        root->getItmCount(Items::iDildo) >= 1 ||
                        root->getItmCount(Items::iBigDildo) >= 1 ||
                        root->getItmCount(Items::iExtraDildo) >= 1||
                        root->getItmCount(Items::iLargeDildo) >= 1||
                        root->getItmCount(Items::iMadDildo) >= 1||
                        root->getItmCount(Items::iMidDildo) >=1 ||
                        root->getItmCount(Items::iSuperDildo) >= 1)
                {
                    if(root->getCurLoc() == lbedrpar2 && root->vSex(selfmomtoyplay) == 1)
                    {
                        root->vSex(dildoHand) = 10;
                    }
                    if(root->vSex(dildoHand) > 0)
                    {
                        root->addText(getActDesc(descSP45));
                    }
                }
            }
            makeButtons();
            if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60) bathInvasion();
        }
        break;
    case actSP1:
        {
            root->incTime(2);
            root->vSex(selfplaytime) += 2;
            if(root->vBody(vagina) == 0 && root->vStatus(mesec) <= 0)
            {
                root->setImage("data/sex/selfplay/finger.jpg");
                root->setText(getActDesc(descSP1));
            }
            else if (root->vBody(vagina) > 0)
            {
                emit root->setGape(vagina, root->vStatus(horny), 3, 1);
                root->setText(getActDesc(descSP3));
                if (root->vBody(vagina) < 5)
                {
                    root->vStatus(horny) += getRandInt(2,5);
                    root->addText("<br>" + getActDesc(descSP4));
                }
                else if (root->vBody(vagina) >= 5 && root->vBody(vagina) < 10)
                {
                    root->vStatus(horny) += getRandInt(5,10);
                    root->addText("<br>" + getActDesc(descSP5));
                }
                else if (root->vBody(vagina) >= 10)
                {
                    root->vStatus(horny) += getRandInt(2,5);
                    root->addText("<br>" + getActDesc(descSP6));
                }
                if (root->vBody(vagina) < 5)
                {
                    m_vagTemp += 1;
                }
            }
            else if (root->vStatus(mesec) > 0)
            {
                root->vStatus(mood) -= 5;
                root->setText(getActDesc(descSP9));
            }
            makeButtons();
        }
        break;
    case actSP2:
        {
            root->vStatus(mood) -= 25;
            root->vBody(vagina) += 1;
            root->vSex(selfplaytime) += 5;
            root->vStatus(mood) -= 100;
            root->incTime(5);
            root->setImage("data/sex/selfplay/finger.jpg");
            root->setText(getActDesc(descSP2));
            makeButtons();
        }
        break;
    case actSP3:
        {
            emit root->setGape(vagina, root->vStatus(horny), 10, 1);
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            if (root->vBody(vagina) <= 10)
            {
                root->vStatus(horny) += getRandInt(5,10);
            }
            else
            {
                root->vStatus(horny) += getRandInt(2,5);
            }
            root->setImage("data/sex/selfplay/finger.jpg");
            root->setText(getActDesc(descSP7));
            if (root->vBody(vagina) <= 10)
            {
                root->addText("<br>" + getActDesc(descSP47));
            }
            if (root->vBody(vagina) > 10)
            {
                root->addText("<br>" + getActDesc(descSP48));
            }
            if (root->vBody(vagina) < 10)
            {
                m_vagTemp += 1;
            }
            if (root->vStatus(horny) >= 100)
            {
                root->vStatistics(orgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(horny) = 0;
                root->vStatus(lust) = 0;
                selfPlayEnding();
                root->addText(getActDesc(descSP8));
            }
            makeButtons();
        }
        break;
    case actSP5:
        {
            emit root->setGape(vagina, root->vStatus(horny), 15, 1);
            root->incTime(2);
            root->vSex(selfplaytime) += 2;
            root->setImage("data/sex/selfplay/hand.jpg");
            if (root->vBody(vagina) > 0)
            {
                root->setText(getActDesc(descSP10));
                if (root->vBody(vagina) < 10)
                {
                    root->vStatus(horny) -= 10;
                    root->vStatus(mood) -= 10;
                    root->addText("<br>" + getActDesc(descSP11));
                }
                else if (root->vBody(vagina) >= 10 && root->vBody(vagina) < 15)
                {
                    root->vStatus(horny) += getRandInt(1,3);
                    root->addText("<br>" + getActDesc(descSP12));
                }
                else if (root->vBody(vagina) >= 15 && root->vBody(vagina) < 20)
                {
                    root->vStatus(horny) += getRandInt(3,6);
                    root->addText("<br>" + getActDesc(descSP13));
                }
                else if (root->vBody(vagina) >= 20)
                {
                    root->vStatus(horny) += getRandInt(6,12);
                    root->addText("<br>" + getActDesc(descSP14));
                }
                if (root->vBody(vagina) < 15)
                {
                    m_vagTemp += 1;
                }              
            }
            makeButtons();
        }
        break;
    case actSP6:
        {
            emit root->setGape(vagina, root->vStatus(horny), 15, 1);
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            if (root->vBody(vagina) < 10)
            {
                root->vStatus(horny) -= 10;
                root->vStatus(mood) -= 10;
            }
            root->setImage("data/sex/selfplay/hand.jpg");
            root->setText(getActDesc(descSP15));
            if (root->vBody(vagina) <= 15)
            {
                root->vStatus(horny) -= 10;
                root->vStatus(mood) -= 10;
                root->addText("<br>" + getActDesc(descSP49));
            }
            if (root->vBody(vagina) > 10)
            {
                root->vStatus(horny) += getRandInt(10,20);
                root->addText("<br>" + getActDesc(descSP50));
            }
            if (root->vBody(vagina) < 20)
            {
                m_vagTemp += 1;
            }
            if (root->vStatus(horny) >= 100)
            {
                root->vStatistics(orgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(horny) = 0;
                root->vStatus(lust) = 0;
                selfPlayEnding();
            }
            makeButtons();
        }
        break;
    case actSP7:
        {
            root->vSex(analplay) = 0;
            root->vSex(selfplaytime) = 0;
            root->vSex(mastrOnce) = 0;
            if(m_vagTemp > root->vBody(vagina)*2)
            {
                root->vBody(vagina) += 1;
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    case actSP8:
        {
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            if(root->getCurLoc() == lbathroom)
            {
                root->setImage("data/sex/selfplay/klitvann.jpg");
            }
            else
            {
                root->setImage("data/sex/selfplay/klit.jpg");
            }
            if(root->vStatus(mood) >= 50)
            {
                root->vStatus(horny) += getRandInt(5,10);
                root->setText(getActDesc(descSP19));
            }
            else
            {
                root->vStatus(horny) += getRandInt(0,1);
                root->setText(getActDesc(descSP20));
            }
            if(root->vStatus(horny) >= 100)
            {
                root->vStatistics(orgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(horny) = 0;
                root->vStatus(lust) = 0;
                selfPlayEnding();
                root->addText(getActDesc(descSP21));
            }
            makeButtons();
        }
        break;
    case actSP9:
        {
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            root->setImage("data/sex/selfplay/1.jpg");
            if(root->vBody(anus) >= 3)
            {
                root->vStatus(horny) += 1;
                root->setText(getActDesc(descSP22));
            }
            else if (root->vBody(anus) < 3)
            {
                root->setText(getActDesc(descSP23));
            }
            if(root->getItmCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 3, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 3, 0);
            }
            if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP10:
        {
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            root->setImage("data/sex/selfplay/2.jpg");
            if(root->vBody(anus) >= 5)
            {
                root->vStatus(horny) += 1;
                root->setText(getActDesc(descSP25));
                if(root->vSex(stat_agape) > 0)
                {
                    root->setText(getActDesc(descSP26));
                }
            }
            else if (root->vBody(anus) >= 3 && root->vBody(anus) < 5)
            {
                root->vStatus(horny) += getRandInt(3,5);
                root->setText(getActDesc(descSP27));
                if(root->vSex(agape) > 0)
                {
                    root->setText(getActDesc(descSP28));
                }
            }
            else if (root->vBody(anus) >= 1 && root->vBody(anus) < 3)
            {
                root->vStatus(horny) -= 50;
                root->setText(getActDesc(descSP29));
            }
            if(root->getItmCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 5, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 5, 0);
            }
            if(root->vStatus(horny) >= 100)
            {
                root->vStatistics(analOrgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(lust) = 0;
                root->vStatus(horny) = 0;
                selfPlayEnding();
                root->setText(getActDesc(descSP16));
            }
            makeButtons();            
            if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60)
            {
                bathInvasion();
            }
        }
        break;
    case actSP11:
        {
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            root->setImage("data/sex/selfplay/3.jpg");
            if(root->vBody(anus) >= 10)
            {
                root->vStatus(horny) += 1;
                root->setText(getActDesc(descSP30));
                if(root->vSex(stat_agape) > 0)
                {
                    root->setText(getActDesc(descSP31));
                }
            }
            else if(root->vBody(anus) >= 5 && root->vBody(anus) < 10)
            {
                root->vStatus(horny) += getRandInt(2,5);
                root->setText(getActDesc(descSP32));
                if(root->vSex(stat_agape) > 0)
                {
                    root->setText(getActDesc(descSP33));
                }
            }
            else if(root->vBody(anus) < 5)
            {
                root->vStatus(horny) -= 50;
                root->setText(getActDesc(descSP34));
            }
            if(root->getItmCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 10, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 10, 0);
            }
            if(root->vStatus(horny) >= 100)
            {
                root->vStatistics(analOrgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(lust) = 0;
                root->vStatus(horny) = 0;
                selfPlayEnding();
                root->setText(getActDesc(descSP16));
            }
            
            if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP12:
        {
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            root->setImage("data/sex/selfplay/4.jpg");
            if(root->vBody(anus) >= 15)
            {
                root->setText(getActDesc(descSP35));
                if(root->vSex(stat_agape) > 0)
                {
                    root->vStatus(horny) += 1;
                    root->setText(getActDesc(descSP36));
                }
            }
            else if (root->vBody(anus) >= 10 && root->vBody(anus) < 15)
            {
                root->vStatus(horny) += getRandInt(2,5);
                root->setText(getActDesc(descSP37));
                if(root->vSex(stat_agape) > 0)
                {
                    root->setText(getActDesc(descSP38));
                }
            }
            else if(root->vBody(anus) < 10)
            {
                root->vStatus(horny) -= 50;
                root->setText(getActDesc(descSP39));
            }
            if(root->getItmCount(iLubri) > 0)
            {
                emit root->setGape(anus, 10, 15, 0);
            }
            else
            {
                emit root->setGape(anus, 0, 15, 0);
            }
            if(root->vStatus(horny) >= 100)
            {
                root->vStatistics(analOrgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(lust) = 0;
                root->vStatus(horny) = 0;
                selfPlayEnding();
                root->setText(getActDesc(descSP16));
            }
            
            if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60)
            {
                bathInvasion();
            }
            makeButtons();
        }
        break;
    case actSP13:
        {
            root->vSex(SelfFisting) += 1;
            root->incTime(5);
            root->vSex(selfplaytime) += 5;
            root->setImage("data/sex/selfplay/5.jpg");
            if(root->vBody(anus) >= 20)
            {
                root->vStatus(horny) += getRandInt(5,10);
                root->setText(getActDesc(descSP40));
                if(root->vSex(stat_agape) > 0)
                {
                    root->setText(getActDesc(descSP41));
                }
                else if (root->vBody(anus) >= 15 && root->vBody(anus) < 20)
                {
                    root->vStatus(horny) += getRandInt(2,5);
                    root->setText(getActDesc(descSP42));
                    if(root->vSex(stat_agape) > 0)
                    {
                        root->setText(getActDesc(descSP43));
                    }
                }
                else if(root->vBody(anus) < 15)
                {
                    root->vStatus(horny) -= 50;
                    root->setText(getActDesc(descSP44));
                }
                if(root->getItmCount(iLubri) > 0)
                {
                    emit root->setGape(anus, 10, 15, 0);
                }
                else
                {
                    emit root->setGape(anus, 0, 15, 0);
                }
                if(root->getPrevLoc() == lkorrpar && root->vSex(selfplaytime) >= 60)
                {
                    bathInvasion();
                }
                if(root->vStatus(horny) >= 100)
                {
                    root->vStatistics(analOrgasm) += 1;
                    root->vStatus(mood) = 100;
                    root->vStatus(lust) = 0;
                    root->vStatus(horny) = 0;
                    selfPlayEnding();
                    root->setText(getActDesc(descSP16));
                }
                makeButtons();
            }
        }
        break;
    case actSP14:
        {
            root->incTime(15);
            root->vSex(selfplaytime) += 15;
            root->vSex(dick) = root->vSex(dildoHand);
            if(root->getPrevLoc() == lkorrpar)
                root->setImage("data/sex/selfplay/dildovann.jpg");
            else
                root->setImage("data/sex/selfplay/dildo.jpg");
            root->vSex(protect) = 1;
            root->sexStart();
            root->vaginal(tDildo);
            if(root->vStatus(horny) == 0 || root->vStatus(horny) < 35)
                selfPlayEnding();
            //if husband > 0 and husbandrink ! 10 and $loc = 'bedr': dynamic $husb_mastr_vtor
            makeButtons();
        }
        break;
    case actSP15:
        {
            root->incTime(15);
            root->vSex(selfplaytime) += 15;
            root->vSex(dick) = root->vSex(dildoHand);
            if(root->getPrevLoc() == lkorrpar)
                root->setImage("data/sex/selfplay/dildovann.jpg");
            else
                root->setImage("data/sex/selfplay/dildo.jpg");
            root->analStart(tDildo);
            root->anal(tDildo);
            makeButtons();
        }
        break;
    case actSP16://RESERVED
        break;
    case actSP17:
        {
            root->vSex(dildoHand) = 0;
            slotActionHandler(actSP0);
        }
        break;
    case actSP18:
        {
            root->vSex(dildoHand) = 10;
            slotActionHandler(actSP0);
        }
        break;
    case actSP19:
        {
            root->vSex(dildoHand) = 15;
            slotActionHandler(actSP0);
        }
        break;
    case actSP20:
        {
            root->vSex(dildoHand) = 20;
            slotActionHandler(actSP0);
        }
        break;
    case actSP21:
        {
            root->vSex(dildoHand) = 25;
            slotActionHandler(actSP0);
        }
        break;
    case actSP22:
        {
            root->vSex(dildoHand) = 30;
            slotActionHandler(actSP0);
        }
        break;
    case actSP23:
        {
            root->vSex(dildoHand) = 35;
            slotActionHandler(actSP0);
        }
        break;
    case actSP24:
        {
            root->vSex(dildoHand) = 40;
            slotActionHandler(actSP0);
        }
        break;
    case actSP25:
        {
            root->vSex(analplay) = 0;
            root->vSex(selfplaytime) = 0;
            root->vSex(mastrOnce) = 0;
            if(m_vagTemp > root->vBody(vagina)*2)
            {
                root->vBody(vagina) += 1;
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    case actSP26:
        {
            root->vSex(analplay) = 0;
            root->vSex(selfplaytime) = 0;
            root->vSex(mastrOnce) = 0;
            if(m_vagTemp > root->vBody(vagina)*2)
            {
                root->vBody(vagina) += 1;
                m_vagTemp = 0;
            }
            root->changeLoc(root->getCurLoc(),1);
        }
        break;
    default:
        break;
    }
    root->updateParams();
}

void SelfPlay::makeButtons()
{
    if (current == actSP0 || current == actSP4)
    {
        if (root->vStatus(Status::horny) > 0 && root->vSex(grandmaknowmastr) == 0 && root->vSex(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP8);
        }
        if (root->vStatus(Status::horny) > 0 && root->vSex(stat_agape) < 3 && root->vSex(grandmaknowmastr) == 0 && root->vSex(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP9);
        }
        if (root->vStatus(Status::horny) > 25 && root->vSex(grandmaknowmastr) == 0 && root->vSex(grandpaknowmastr) == 0)
        {
            if (root->getCurLoc() == lbedrpar2 ||
                root->getItmCount(Items::iDildo) >= 1 ||
                root->getItmCount(Items::iBigDildo) >= 1 ||
                root->getItmCount(Items::iExtraDildo) >= 1 ||
                root->getItmCount(Items::iLargeDildo) >= 1 ||
                root->getItmCount(Items::iMadDildo) >= 1 ||
                root->getItmCount(Items::iMidDildo) >= 1 ||
                root->getItmCount(Items::iSuperDildo) >= 1)
            {
                if (root->vSex(dildoHand) > 0)
                {
                    if (root->vSex(stat_vgape) <= 0)
                        makeActBtn(actSP14);
                    if (root->vSex(stat_agape) <= 0)
                        makeActBtn(actSP15);
                    makeActBtn(actSP17);
                }
                else
                {
                    if (root->getItmCount(iDildo) >= 1)
                        makeActBtn(actSP18);
                    if (root->getItmCount(iMidDildo) >= 1)
                        makeActBtn(actSP19);
                    if (root->getItmCount(iLargeDildo) >= 1)
                        makeActBtn(actSP20);
                    if (root->getItmCount(iBigDildo) >= 1)
                        makeActBtn(actSP21);
                    if (root->getItmCount(iExtraDildo) >= 1)
                        makeActBtn(actSP22);
                    if (root->getItmCount(iSuperDildo) >= 1)
                        makeActBtn(actSP23);
                    if (root->getItmCount(iMadDildo) >= 1)
                        makeActBtn(actSP24);
                }
            }
        }
        if (root->vStatus(Status::horny) > 0 && root->vSex(grandmaknowmastr) == 0 && root->vSex(grandpaknowmastr) == 0)
        {
            makeActBtn(actSP1);
        }
        makeActBtn(actSP25);
    }
    else if (current == actSP1)
    {
        if(root->vBody(vagina) == 0 && root->vStatus(mesec) <= 0)
        {
            makeActBtn(actSP2);
        }
        else if (root->vBody(vagina) > 0)
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
        if (root->vStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
    else if(current == actSP5)
    {
        if (root->vBody(vagina) > 0)
        {
            makeActBtn(actSP6); 
        }
        makeActBtn(actSP4);
    }
    else if (current == actSP6)
    {
        if (root->vStatus(horny) > 0)
        {
            makeActBtn(actSP5);
        }
        makeActBtn(actSP4);
    }
    else if(current == actSP8)
    {
        makeActBtn(actSP4);
        if (root->vStatus(horny) > 0)
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
        if (root->vStatus(horny) > 0 && root->vSex(stat_agape) < 3)
        {
            makeActBtn(actSP11);
        }
    }
    else if (current == actSP11)
    {
        makeActBtn(actSP4);
        if (root->vStatus(horny) > 0 && root->vSex(stat_agape) < 3)
        {
            makeActBtn(actSP12);
        }
    }
    else if (current == actSP12)
    {
        makeActBtn(actSP4);
        if (root->vStatus(horny) > 0 && root->vSex(stat_agape) < 3)
        {
            makeActBtn(actSP13);
        }
    }    
}

void SelfPlay::makeActBtn(SelfPlayActs act)
{
    SexActionButton* btnx = new SexActionButton(act, getActName(act));
    connect(btnx, &SexActionButton::sigAction, this, &SelfPlay::slotActionHandler);
    root->addActions(btnx);
}

void SelfPlay::bathInvasion()
{
    if(root->gNPC(father).location == lkorrpar || root->gNPC(mother).location == lkorrpar || root->gNPC(sister).location == lkorrpar || root->gNPC(brother).location == lkorrpar)
    {
        root->vStatus(mood) -= 10;
        root->vStatus(horny) -= 50;
        root->setText(getActDesc(descSP17));
        makeActBtn(actSP7);
    }
}

void SelfPlay::selfPlayEnding()
{
    root->setText(getActDesc(descSP16));
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
    strings[descSP45] = "У вас в руках " + intQStr(root->vSex(dildoHand)) + "ти сантиметровый дилдо";
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
