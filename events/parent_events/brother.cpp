#include "brother.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

Brother::Brother(Game* ptr): root(ptr) {}

void Brother::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("main");
    else
        actionHandler(arg);
}

void Brother::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Brother");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Brother::actionHandler);
    root->addActions(btn);
}

void Brother::actionHandler(QString action)
{
    if(action == "main")
    {
        age = root->getAge() - 1;
        root->rendNpcProfile(brother);
        if(root->getWeek() == 0 && root->vEvent(turnirWin) == 0 && root->vEvent(family_trip) == 0 && root->vQuest(qwPornoFootball) > 40 && root->getHour() >= 8 && root->getHour() <= 9)
            makeActBtn("incest_event",act(1));
        if(root->vQuest(qwKolka) == 8 && root->vQuest(qwKolkaTel) == 0)
            makeActBtn("incest_event_Kolka",act(2));
        makeActBtn("back_to_loc",act(0));
        if(root->gNPC(brother).location == lsitrpar && (root->getHour() > 22 || root->getHour() < 7))
        {
            actionHandler("get_off");
            return;
        }
        if(!root->isCloth())
        {
            actionHandler("check_naked");
            return;
        }
        if(root->vStatus(cumLips) + root->vStatus(cumFrot) + root->vStatus(cumFace) + root->vStatus(cumAss) + root->vStatus(cumBelly) > 0)
        {
            actionHandler("cum_reaction");
            return;
        }
        if(root->vAddict(alko) > 0)
        {
            root->startEvent(eDrunkReaction, "brother");
            return;
        }
        if(root->gNPC(brother).location == lgschool)
            actionHandler("football");
        root->startEvent(eKolkaPrince, "main");
        if(root->vEvent(brother_pirsF) == 0 && root->vBody(piercingF) > 0 && root->getHour() >= 21)
        {
            actionHandler("check_piercing");
            return;
        }
        if(root->vSchool(vacation) == 0 && root->getWeek() > 0 && root->getWeek() < 6 && root->vEvent(brother_homeWork) != root->getDay() && root->getHour() >= 18 && root->getHour() <= 20 && age < 18)
        {
            actionHandler("homework_init");
            return;
        }
        if(root->vEvent(pregTalkBrother) == 0 && root->PregVisibility())
        {
            actionHandler("check_pregnant");
            return;
        }
        if(root->vSex(spanked) >= 25 && root->isNude() && !root->isPanties())
        {
            actionHandler("spank_reaction");
            return;
        }
        if(root->gNPC(brother).location == lkuhrpar && root->getHour() == 7)
            actionHandler("smalltalk.kitchen");
        else if(root->gNPC(brother).location == lsitrpar && ((root->getHour() >= 18 && root->getHour() <= 20) || (root->getHour() > 7 && root->getHour() < 11)))
        {
            if(getRandInt(0,1) == 1)
                actionHandler("smalltalk.tv_talk");
            else
                actionHandler("smalltalk.hobby_talk");
        }
        if(root->vQuest(qwKolkaPrince) >= 2)
            root->startEvent(eKolkaPrince,"KolkaStats");
    }

    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action.startsWith("smalltalk."))
    {
        smalltalk(action.split(".").at(1));
    }
    if(action == "incest_event")
    {
        root->incTime(30);
        root->setText(str(211));
        makeActBtn("incest_event.0",act(28));
    }
    if(action == "incest_event.0")
    {
        root->incTime(480);
        root->setImage(media(75));
        root->setText(str(212));
        makeActBtn("incest_event.1",act(28));
    }
    if(action == "incest_event.1")
    {
        root->incTime(30);
        root->setImage(media(76));
        root->setText(str(213));
        makeActBtn("incest_event.2",act(28));
    }
    if(action == "incest_event.2")
    {
        root->incTime(60);
        root->setImage(media(77));
        root->setText(str(214));
        makeActBtn("incest_event.3",act(28));
    }
    if(action == "incest_event.3")
    {
        root->incTime(10);
        root->setImage(media(78));
        root->setText(str(215));
        makeActBtn("incest_event.4",act(28));
    }
    if(action == "incest_event.4")
    {
        root->incTime(120);
        root->fnAlko(1);
        root->vEvent(turnirWin) = 1;
        root->setImage(media(79));
        root->setText(str(216));
        makeActBtn("korrPar",act(39));
    }
    if(action == "korrPar")
        root->changeLoc(lkorrpar);
    if(action == "incest_event_Kolka")
    {
        root->incTime(5);
        root->gNPC(Misha).know = 1;
        root->vQuest(qwKolkaTel) = 1;
        root->gNPC(Misha).relation = 100;
        root->addText(str(217));
        makeActBtn("sitrPar",act(3));
    }
    if(action == "sitrPar")
        root->changeLoc(lsitrpar);
    if(action == "get_off")
    {
        if(root->gNPC(brother).relation < 40)
        {
            root->changeRep('-',brother);
            root->setText(str(31));
        }
        else
            root->setText(str(32));
        if(root->vSchool(vacation) == 0 && ((root->getWeek() > 0 && root->getWeek() < 5 ) || root->getWeek() == 0) && age < 18)
            root->addText(str(33));
    }
    if(action == "check_naked")
    {
        if(root->getClothGroup() == towel)
        {
            if(root->gNPC(brother).sex < 1)
                root->addText(str(34));
            else
                root->addText(str(35));
        }
        else if(root->isNude() && root->vBody(pubisHair) > 2 && !root->isPanties())
        {
            root->addText(str(36));
        }
        else if(root->isNude())
        {
            if(root->gNPC(brother).sex >= 1)
                root->addText(str(37));
            else
            {
                root->addText(str(38));
                root->changeRep('+',brother);
            }
        }
    }
    if(action == "cum_reaction")
    {
        if(root->vStatus(cumFace) + root->vStatus(cumLips) > 0)
        {
            if(root->vEvent(broKnowSlut) < 1)
                root->vEvent(broKnowSlut) = 1;
            root->changeRep('-',brother);
            root->addText(str(39));
        }
        if(root->vStatus(cumFrot) > 0 && root->isCloth())
            root->addText(str(40));
        if(root->vStatus(cumBelly) > 0 && root->isNude())
        {
            if(root->vEvent(broKnowSlut) < 1)
                root->vEvent(broKnowSlut) = 1;
            root->changeRep('-',brother);
            root->addText(str(41));
        }
        if(root->vStatus(cumAss) > 0 && !root->isCloth() && !root->isPanties())
        {
            root->addText(str(42));
            if(root->vEvent(broKnowSlut) < 1)
                root->vEvent(broKnowSlut) = 1;
            root->changeRep('-',brother);
        }
    }
    if(action == "football")
    {
        root->rendNpcProfile(brother);
        if(root->gNPC(brother).relation < 40)
        {
            root->addText(str(46));
            makeActBtn("gschool",act(3));
        }
        else
        {
            if(root->getSunWeather() >= 0 && root->getMonth() > 2 && root->getMonth() < 12)
            {
                root->addText(str(47));
                makeActBtn("gschool",act(3));
                if(root->getClothGroup() == sportsSuit)
                    makeActBtn("playFootball",act(4));
                makeActBtn("watchFootball",act(5));
            }
            else
                actionHandler("gt_porn_view");
        }
    }
    if(action == "check_piercing")
    {
        if(root->isNude())
        {
            int rel = root->gNPC(brother).relation;
            root->incTime(1);
            root->vEvent(brother_pirsF) = 1;
            if(rel < 40)
                root->setText(str(57));
            else if(rel >= 40 && rel < 60)
                root->setText(str(58));
            else
            {
                root->vStatus(horny) += 3;
                if(root->gNPC(brother).sex == 0)
                    root->setText(str(59));
                else
                    root->setText(str(60));
            }
            makeActBtn("back_to_loc",act(0));
        }
        else
        {
            makeActBtn("showNipplePirs",act(10));
        }
    }
    if(action == "showNipplePirs")
    {
        root->incTime(1);
        root->vEvent(brother_pirsF) = 1;
        root->rendVideoPage(this);
        root->setVideo(media(5),824,600);
        root->setText(str(61));
        if(root->gNPC(brother).relation < 40)
        {
            root->addText(str(57));
            makeActBtn("back_to_loc",act(0));
            return;
        }
        root->vStatus(horny) += 3;
        root->changeRep('+',brother);
        root->addText(str(62));
        if(root->gNPC(brother).sex == 0)
            root->addText(str(63));
        else
            root->addText(str(64));
        root->vStatus(horny) += 10;
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "homework_init")
    {
        if(root->vQuest(qwPornoFootball) >= 7 || root->vQuest(qwBrotherNude) >= 2)
        {
            root->rendNpcProfile(brother);
            root->setText(str(65));
            makeActBtn("homework",act(11));
            makeActBtn("homeworkLater",act(12));
        }
        else
        {
            makeActBtn("homeworkOffer",act(13));
        }
    }
    if(action == "homework")
    {
        root->vEvent(brother_homeWork) = root->getDay();
        root->incTime(getRandInt(50,70));
        root->setImage(media(6));
        root->setText(str(70));
        root->changeRep('+',brother);
        makeActBtn("sitrPar",act(15));
        if(root->vQuest(qwBrotherNude) == 2)
        {
            root->rendVideoPage(this);
            root->setVideo(media(7),960,432);
            root->setText(str(71));
            makeActBtn("ignore&continue",act(16));
            makeActBtn("removeHand",act(17));
            return;
        }
        else if(root->vQuest(qwPornoFootball) >= 7 || root->vQuest(qwBrotherNude) >= 3)
        {
            root->vStatus(horny) += getRandInt(5,10);
            root->addText(str(74));
            makeActBtn("ignore&continue2",act(16));
            makeActBtn("removeHand2",act(17));
        }
    }
    if(action == "ignore&continue2")
    {
        root->rendVideoPage(this);
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(5,10);
        root->incTime(getRandInt(5,10));
        root->setVideo(media(7),960,432);
        makeActBtn("back_to_loc",act(15));
        if(root->getHour() == 21)
        {
            if(root->getMonth() == 12 && root->getDay() >= 25 && root->getDay() <= 29 && root->vQuest(qwBrotherNewYear) == 0)
                root->startEvent(eBrotherEvents, "happy_ny");
            root->addText(str(75));
            makeActBtn("back_to_loc",act(18));
            if(root->gNPC(brother).sex < 4)
            {
                if(root->vQuest(qwBrotherNude) == 3)
                    makeActBtn("show_body",act(19));
                else
                    makeActBtn("show_body",act(20));
            }
            else
                actionHandler("brotherSexStart");
        }
    }
    if(action == "removeHand2")
    {
        root->rendImagePage(this);
        root->vStatus(horny) += getRandInt(1,5);
        root->changeRep('-',brother);
        root->setImage(media(6));
        root->setText(str(76));
        makeActBtn("back_to_loc",act(15));
    }
    if(action == "ignore&continue")
    {
        root->vQuest(qwBrotherNude) = 3;
        root->changeRep('+', brother);
        root->vStatus(horny) += getRandInt(5,10);
        root->addText(str(72));
        makeActBtn("back_to_loc",act(15));
    }
    if(action == "removeHand")
    {
        root->vStatus(horny) += getRandInt(1,5);
        root->vSkill(domination) += 1;
        root->addText(str(73));
        makeActBtn("back_to_loc",act(15));
    }
    if(action == "homeworkLater")
    {
        root->addText(str(66));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "homeworkOffer")
    {
        root->addText(str(67));
        if(root->gNPC(brother).relation < 40)
        {
            root->addText(str(68));
            makeActBtn("back_to_loc",act(0));
        }
        else
        {
            root->changeRep('+',brother);
            root->addText(str(69));
            makeActBtn("homework",act(14));
        }
    }
    if(action == "check_pregnant")
    {
        if(root->PregVisibility())
        {
            root->addText(str(45));
            root->vEvent(pregTalkBrother) = 1;
        }
    }
    if(action == "spank_reaction")
    {
        if(root->gNPC(brother).relation < 40)
            root->addText(str(43));
        else
            root->addText(str(44));
    }
    if(action == "gschool")
    {
        root->changeLoc(lgschool);
    }
    if(action == "playFootball")
    {
        root->incTime(60);
        root->changeRep('+',brother);
        root->vSkill(agility) += getRandInt(0,2);
        root->vSkill(speed) += getRandInt(0,2);
        root->vStatus(sweat) += getRandInt(2,5);
        root->setImage(media(0));
        root->setText(str(48));
        makeActBtn("gt_porn_view",act(6));
    }
    if(action == "watchFootball")
    {
        if(root->getMonth() < 3 || root->getMonth() == 12)
            root->setImage(media(1));
        else
            root->setImage(media(getRandInt(2,3)));
        root->setText(str(49));
        makeActBtn("gt_porn_view",act(6));
    }
    if(action == "gt_porn_view")
    {
        if(root->vQuest(qwPornoFootball) == 0)
        {
            root->setImage(media(4));
            root->setText(str(50));
            makeActBtn("talkingAbout?",act(7));
        }
        else
        {
            root->setImage(media(4));
            root->setText(str(51));
            if(root->vQuest(qwPornoFootball) < 5)
                root->addText(str(52));
            else
                root->addText(str(53));
            makeActBtn("watch_porn",act(8));
            makeActBtn("back_to_loc",act(3));
        }
    }
    if(action == "talkingAbout?")
    {
        makeActBtn("back_to_loc",act(0));
        root->setText(str(54));
        if(root->vSkill(domination) > 0)
        {
            root->addText(str(55));
            makeActBtn("takeMeView",act(9));
        }
    }
    if(action == "watch_porn")
    {
        root->incTime(getRandInt(5,15));
        root->startEvent(ePornView);
    }
    if(action == "takeMeView")
    {
        root->addText(str(56));
        makeActBtn("watch_porn",act(8));
    }
    if(action == "show_body")
    {
        root->rendImagePage(this);
        root->setImage(media(6));
        root->setText(str(77));
        if(root->vQuest(qwBrotherNude) <= 3)
        {
            int statSex = 0;
            statSex = root->vStatistics(vaginalSex) + root->vStatistics(blowJob) + root->vStatistics(handJob) + root->vStatistics(analSex) + root->vStatistics(getKuni);
            if(statSex == 0 && root->vQuest(qwPornoFootball) < 12)
                makeActBtn("areYouCrazy",act(21));
            else
            {
                if(root->vSkill(domination) > -30)
                {
                    makeActBtn("back_to_loc",act(15));
                }
            }
            makeActBtn("hmm",act(22));
        }
        else
        {
            if(root->vSkill(domination) > -30)
            {
                makeActBtn("back_to_loc",act(15));
            }
            makeActBtn("brother_voyeur_ev4",act(23));
        }
    }
    if(action == "areYouCrazy")
    {
        root->addText(str(82));
        makeActBtn("back_to_loc",act(15));
    }
    if(action == "hmm")
    {
        int statSex = 0;
        statSex = root->vStatistics(vaginalSex) + root->vStatistics(blowJob) + root->vStatistics(handJob) + root->vStatistics(analSex) + root->vStatistics(getKuni);

        root->vQuest(qwBrotherNude) = 4;
        if((root->vQuest(qwPornoFootball) >= 12 && statSex == 0) ||
            (root->vQuest(qwPornoFootball) >= 7 && statSex > 0))
        {
            root->addText(str(78));
        }
        else
        {
            root->addText(str(79));
            root->addText(str(80));
        }
        root->addText(str(81));
        makeActBtn("brother_voyeur_ev4",act(23));
    }
    if(action == "brother_go_away")
    {
        root->vStatus(horny) += getRandInt(5,10);
        root->incTime(getRandInt(5,10));
        root->changeRep('-',brother,10);
        root->vSkill(domination) += 1;
        root->setImage(media(17));
        root->setText(str(83));
        makeActBtn("bathroom",act(6));
    }
    if(action == "bathroom")
    {
        root->changeLoc(lbathroom);
    }
    if(action == "brother_voyeur_end")
    {
        root->vStatus(horny) += getRandInt(5,10);
        root->incTime(getRandInt(5,10));
        root->changeRep('+',brother);
        root->vStatus(mood) += 10;
        root->setImage(media(getRandInt(25,26)));
        root->setText(str(84));
        makeActBtn("bathroom",act(24));
    }
    if(action == "brother_voyeur_ev1")
    {
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        root->changeRep('+',brother);
        if(root->vQuest(qwBrotherNude) < 1)
            root->vQuest(qwBrotherNude) = 1;
        root->setImage(media(getRandInt(18,23)));
        root->setText(str(85));
        makeActBtn("brother_voyeur_end",act(25));
        if(root->vStatus(horny) >= 40)
            makeActBtn("brother_voyeur_ev2",act(26));
    }
    if(action == "brother_voyeur_ev2")
    {
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        root->changeRep('+',brother);
        root->setImage(media(getRandInt(27,33)));
        root->setText(str(86));
        makeActBtn("brother_voyeur_end",act(25));
        if(root->vStatus(horny) >= 90)
            makeActBtn("brother_voyeur_ev3",act(27));
    }
    if(action == "brother_voyeur_ev3")
    {
        if(root->vQuest(qwBrotherNude) <= 1)
            root->vQuest(qwBrotherNude) = 2;
        root->incTime(getRandInt(5,10));
        root->changeRep('+',brother);
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatistics(orgasm) += 1;
        root->vStatistics(masturbation) += 1;
        root->vStatus(mood) += 15;
        root->setImage(media(getRandInt(34,35)));
        root->setText(str(87));
        makeActBtn("brother_voyeur_end",act(25));
    }
    if(action == "brother_voyeur_ev4")
    {
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        root->setImage(media(8));
        if(root->vQuest(qwBrotherNude) == 4)
        {
            root->setText(str(88));
            root->addText(str(89));
            makeActBtn("brother_voyeur_ev5",act(28));
        }
        else if(root->vQuest(qwBrotherNude) > 4)
        {
            root->setText(str(90));
            makeActBtn("brother_voyeur_ev5",act(28));
        }
    }
    if(action == "brother_voyeur_ev5")
    {
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        if(root->vEvent(broBodyShow) == 0)
        {
            root->vEvent(broBodyShow) = 1;
            QString anuspic = root->getPlayerAnus();
            QStringList list = anuspic.split("/");
            int anpic = list[list.size() - 1].split(".")[0].toInt();
            root->vEvent(broAnusMem) = anpic;
        }
        QString result = str(91);
        if(root->vSex(analplugIN) == 1) result += str(92);
        else result += ":";
        result += "<br><npc>";
        if(root->vQuest(qwBrotherNude) == 4) result += str(93);
        else result += str(94);
        result += "</npc>" + str(95);
        if(root->vSex(analplugIN) == 1)
        {
            if(root->vEvent(broSawAnalplug) == 0)
            {
                root->vEvent(broSawAnalplug) = 1;
                result += str(96) + str(97) + str(98) + str(99) + str(100) + str(101) + str(102) + str(103);
            }
            else
            {
                result += str(104) + str(105);
                if(root->gNPC(brother).sex == 1)
                {
                    result += str(106) + str(107) + str(108);
                }
                else
                    result += str(109) + str(110);
            }
        }
        else
        {
            QString anuspic = root->getPlayerAnus();
            QStringList list = anuspic.split("/");
            int anpic = list[list.size() - 1].split(".")[0].toInt();
            if(root->vEvent(broAnusMem) < anpic)
            {
                root->vEvent(broAnusMem) = anpic;
                result += str(111) + str(112) + str(113) +str(114);
                if(root->vQuest(qwPornoFootball) < 22)
                {
                    result += str(115) + str(116) + str(117) + str(118) + str(119);
                }
            }
        }
        result += str(120) + str(121) + str(122) + str(123) + str(124) + str(125);
        if(root->vBody(vagina) > 0)
        {
            result += str(126);
            if(root->vEvent(broKnowNotVirgin) == 0)
            {
                root->vEvent(broKnowNotVirgin) = 1;
                result += str(127) + str(128) + str(129);
                if(root->vStatistics(vaginalSex) == 0)
                    result += str(130);
                else if(root->vStatistics(vaginalSex) >= 1 && root->vStatistics(vaginalSex) < 10)
                    result += str(131);
                else
                {
                    result += str(132) + str(133) + "<br><hero>";
                    if(root->vStatistics(vaginalSex) >= 20)
                        result += str(134);
                    else
                        result += str(135);
                    result += "</hero>";
                }
            }
        }
        else
        {
            result += str(136) + str(137);
        }
        root->setImage(media(9));
        root->setText(result);
        makeActBtn("brother_voyeur_ev6",act(28));
    }
    if(action == "brother_voyeur_ev6")
    {
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        QString result = str(138);
        if(root->vQuest(qwBrotherNude) == 4)
        {
            result += str(139) + str(140) + str(141) + str(142) + str(143);
        }
        else if(root->vQuest(qwBrotherNude) > 4)
        {
            result += str(144) + str(145) + str(146);
        }
        if(root->vEvent(broKnowNotVirgin) == 1)
            result += str(147);
        root->setImage(media(10));
        root->setText(result);
        if(root->vSkill(domination) > -30)
            makeActBtn("back_to_loc",act(29));
        makeActBtn("brother_voyeur_ev7",act(30));
    }
    if(action == "brother_voyeur_ev7")
    {
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        root->setImage(media(11));
        QString result;
        if(root->vQuest(qwBrotherNude) == 4)
        {
            root->vQuest(qwBrotherNude) = 5;
            result += str(148) + str(149) + str(150) + str(151) + str(152) + str(153) + str(154);
            root->setText(result);
            makeActBtn("back_to_loc",act(0));
        }
        else if(root->vQuest(qwBrotherNude) > 4)
        {
            result = str(155) + str(156) + str(157) + str(158);
            if(root->vEvent(broKnowNotVirgin) == 1 && root->vBody(vagina) > 0 && getRandInt(1,2) == 1)
            {
                result += str(159) + str(160) + str(161) + str(162);
                root->setText(result);
                makeActBtn("refuseFingerInPussy",act(31));
                makeActBtn("putFingerInPussy",act(32));
            }
            else
            {
                if(root->vQuest(qwBrotherNude) == 5)
                {
                    result += str(172) + str(173) + str(174) + str(175);
                }
                else if(root->vQuest(qwBrotherNude) > 5)
                {
                    result += str(176) + str(177);
                }
                root->setText(result);
                if(root->vSkill(domination) > -30)
                    makeActBtn("back_to_loc",act(29));
                if(root->vQuest(qwBrotherNude) == 7)
                    makeActBtn("brother_voyeur_ev9",act(14));
                else
                    makeActBtn("brother_voyeur_ev8",act(14));
            }
        }
    }
    if(action == "refuseFingerInPussy")
    {
        root->addText(str(163) + str(164) + str(165));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "putFingerInPussy")
    {
        root->incTime(getRandInt(5,10));
        QString result = str(166);
        if(root->vBody(vagina) < 5)
        {
            root->vStatus(horny) += getRandInt(2,5);
            result += str(167);
        }
        else if(root->vBody(vagina) >= 5 && root->vBody(vagina) < 10)
        {
            root->vStatus(horny) += getRandInt(5,10);
            result += str(168);
        }
        else if(root->vBody(vagina) >= 10)
        {
            root->vStatus(horny) += getRandInt(2,5);
            result += str(169);
        }
        result += str(170) + str(171);
        root->setImage(media(12));
        root->setText(result);
        makeActBtn("brother_voyeur_ev8",act(28));
    }
    if(action == "brother_voyeur_ev8")
    {
        root->changeRep('+',brother);
        root->vStatus(horny) += getRandInt(10,15);
        root->incTime(getRandInt(5,10));
        QString result = str(178);
        if(root->vBody(vagina) > 0) result += str(179);
        result += str(180);
        root->cum("belly");
        root->setImage(media(getRandInt(13,14)));
        root->setText(result);
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        makeActBtn("brother_voyeur_ev8.5",act(28));
    }
    if(action == "brother_voyeur_ev8.5")
    {
        QString result;
        if(root->vQuest(qwBrotherNude) == 5)
        {
            result = str(181) + str(182) + str(183) + str(184) + str(185) + str(186) + str(187);
        }
        else if(root->vQuest(qwBrotherNude) >= 6)
        {
            result = str(188) + str(189) + str(190) + str(191) + str(192);
        }
        root->vQuest(qwBrotherNude) += 1;
        root->setImage(media(getRandInt(15,16)));
        root->setText(result);
        makeActBtn("back_to_loc",act(33));
    }
    if(action == "brother_voyeur_ev9")
    {
        root->changeRep('+',brother);
        root->incTime(getRandInt(5,10));
        QString result = str(178);
        if(root->vBody(vagina) > 0) result += str(179);
        result += str(193) + str(194);
        if(root->vQuest(qwPornoFootball) <= 10)
        {
            result += str(195);
            root->cum("belly");
            root->setImage(media(getRandInt(15,16)));
            root->setText(result);
            makeActBtn("back_to_loc",act(3));
        }
        else
        {
            result += str(196);
            root->setImage(media(getRandInt(13,14)));
            root->setText(result);
            actionHandler("brotherSexStart");
        }
    }
    if(action == "brotherSexStart")
    {
        root->vEvent(brother_tv_enable) = 1;
        if(root->gNPC(brother).sex == 0)
        {
            root->gNPC(brother).sex = 1;
            root->vSex(guy) += 1;
        }
        makeActBtn("handjob",act(34));
        if(root->gNPC(brother).sex > 4)
            makeActBtn("blowjob",act(35));
        actionHandler("brotherSex_sex");
    }
    if(action == "handjob")
    {
        root->incTime(5);
        root->vSex(dick) = root->gNPC(brother).dick;
        root->vStatistics(handJob) += 1;
        root->setImage(media(36));
        root->setText(str(197));
        actionHandler("brotherSexEnd");
    }
    if(action == "blowjob")
    {
        root->rendVideoPage(this);
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->vSex(dick) = root->gNPC(brother).dick;
        root->setVideo(media(getRandInt(37,47)),960,540);
        root->setText(str(198));
        root->blow_job();
        root->addText(str(199));
        makeActBtn("bjNext",act(36));
        makeActBtn("bjNext2",act(37));
        actionHandler("brotherSex_sex");
    }
    if(action == "bjNext")
    {
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->setVideo(media(getRandInt(48,56)),960,540);
        root->fnswallow();
        actionHandler("brotherSexEnd");
    }
    if(action == "bjNext2")
    {
        root->rendImagePage(this);
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->cum("face");
        root->setImage(media(getRandInt(57,61)));
        root->setText(str(200));
        actionHandler("brotherSexEnd");
    }
    if(action == "brotherSex_sex")
    {
        if(root->gNPC(brother).sex > 6)
        {
            makeActBtn("giveHim",act(38));
        }
    }
    if(action == "giveHim")
    {
        root->rendVideoPage(this);
        if(root->gNPC(brother).sex > 10)
            root->gNPC(brother).sex = 10;
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->setBoyName(str(201));
        root->vSex(dick) = root->gNPC(brother).dick;
        root->vSex(silavag) = 0;
        root->vSex(pose) = 0;
        if(getRandInt(0,1) == 0)
        {
            root->setVideo(media(getRandInt(62,68)),960,540);
            root->setText(str(202));
            root->vSex(protect) = 1;
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->setVideo(media(getRandInt(69,74)),960,540);
            root->setText(str(203));
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        actionHandler("brotherSexEnd");
    }
    if(action == "brotherSexEnd")
    {
        root->gNPC(brother).sex += 1;
        root->incTime(getRandInt(5,15));
        if(root->getCurLoc() == lsitrpar)
        {
            root->addText(str(204));
            if(root->vSkill(domination) < 0)
                root->addText(str(205));
            else
                root->addText(str(206));
            root->addText(str(207));
        }
        else
        {
            root->addText(str(208));
            if(root->vSkill(domination) < 0)
                root->addText(str(209));
            else
                root->addText(str(210));
        }
        makeActBtn("back_to_loc",act(3));
    }
}

void Brother::smalltalk(QString arg)
{
    int maxVal = 0;
    int rel = root->gNPC(brother).relation;
    if(rel >= 0 && rel < 60)
        maxVal = 4;
    else if(rel >= 60 && rel < 80)
        maxVal = 9;
    else if(rel >= 80)
    {
        if(root->gNPC(brother).sex == 1 || root->vQuest(qwPornoFootball) > 10)
            maxVal = 12;
        else
            maxVal = 9;
    }
    if(arg == "tv_talk")
        root->setText(str(getRandInt(0, maxVal)));
    if(arg == "hobby_talk")
        root->setText(str(12 + getRandInt(0,maxVal)));
    if(arg == "kitchen")
    {
        if(maxVal > 4)
            maxVal = 4;
        root->setText(str(26 + getRandInt(0, maxVal)));
    }
}

QString Brother::media(int id)
{
    QString med[80];
    med[0] = "data/actions/sport/football3.jpg";
    med[1] = "data/actions/sport/football4.jpg";
    med[2] = "data/actions/sport/football1.jpg";
    med[3] = "data/actions/sport/football2.jpg";
    med[4] = "data/npc/pavlovo/brother/boys_talk.jpg";
    med[5] = "data/npc/pavlovo/brother/pirsf.webm";
    med[6] = "data/actions/broHomework/homework1.jpg";
    med[7] = "data/actions/broHomework/homework_touch.webm";
    med[8] = "data/actions/broHomework/f1.jpg";
    med[9] = "data/actions/broHomework/f2.jpg";
    med[10] = "data/actions/broHomework/f3.jpg";
    med[11] = "data/actions/broHomework/f4.jpg";
    med[12] = "data/actions/broHomework/f5.jpg";
    med[13] = "data/actions/broHomework/f61.jpg";
    med[14] = "data/actions/broHomework/f62.jpg";
    med[15] = "data/actions/broHomework/f71.jpg";
    med[16] = "data/actions/broHomework/f72.jpg";
    med[17] = "data/actions/broPeeking/b13.jpg";
    med[18] = "data/actions/broPeeking/b2.jpg";
    med[19] = "data/actions/broPeeking/b3.jpg";
    med[20] = "data/actions/broPeeking/b4.jpg";
    med[21] = "data/actions/broPeeking/b5.jpg";
    med[22] = "data/actions/broPeeking/b6.jpg";
    med[23] = "data/actions/broPeeking/b7.jpg";
    med[24] = "data/actions/broPeeking/bath_voyer.jpg";
    med[25] = "data/actions/broPeeking/b_end1.jpg";
    med[26] = "data/actions/broPeeking/b_end2.jpg";
    med[27] = "data/actions/broPeeking/c1.jpg";
    med[28] = "data/actions/broPeeking/c2.jpg";
    med[29] = "data/actions/broPeeking/c3.jpg";
    med[30] = "data/actions/broPeeking/c4.jpg";
    med[31] = "data/actions/broPeeking/c5.jpg";
    med[32] = "data/actions/broPeeking/c6.jpg";
    med[33] = "data/actions/broPeeking/c7.jpg";
    med[34] = "data/actions/broPeeking/d1.jpg";
    med[35] = "data/actions/broPeeking/d2.jpg";
    med[36] = "data/sex/misc/hj.jpg";
    med[37] = "data/sex/common_sex/bj/0.webm";
    med[38] = "data/sex/common_sex/bj/10.webm";
    med[39] = "data/sex/common_sex/bj/1.webm";
    med[40] = "data/sex/common_sex/bj/2.webm";
    med[41] = "data/sex/common_sex/bj/3.webm";
    med[42] = "data/sex/common_sex/bj/4.webm";
    med[43] = "data/sex/common_sex/bj/5.webm";
    med[44] = "data/sex/common_sex/bj/6.webm";
    med[45] = "data/sex/common_sex/bj/7.webm";
    med[46] = "data/sex/common_sex/bj/8.webm";
    med[47] = "data/sex/common_sex/bj/9.webm";
    med[48] = "data/sex/common_sex/bj_cum/mouth/0.webm";
    med[49] = "data/sex/common_sex/bj_cum/mouth/1.webm";
    med[50] = "data/sex/common_sex/bj_cum/mouth/2.webm";
    med[51] = "data/sex/common_sex/bj_cum/mouth/3.webm";
    med[52] = "data/sex/common_sex/bj_cum/mouth/4.webm";
    med[53] = "data/sex/common_sex/bj_cum/mouth/5.webm";
    med[54] = "data/sex/common_sex/bj_cum/mouth/6.webm";
    med[55] = "data/sex/common_sex/bj_cum/mouth/7.webm";
    med[56] = "data/sex/common_sex/bj_cum/mouth/8.webm";
    med[57] = "data/sex/common_sex/facial/0.jpg";
    med[58] = "data/sex/common_sex/facial/1.jpg";
    med[59] = "data/sex/common_sex/facial/2.jpg";
    med[60] = "data/sex/common_sex/facial/3.jpg";
    med[61] = "data/sex/common_sex/facial/4.jpg";
    med[62] = "data/sex/common_sex/sex/0.webm";
    med[63] = "data/sex/common_sex/sex/1.webm";
    med[64] = "data/sex/common_sex/sex/2.webm";
    med[65] = "data/sex/common_sex/sex/3.webm";
    med[66] = "data/sex/common_sex/sex/4.webm";
    med[67] = "data/sex/common_sex/sex/5.webm";
    med[68] = "data/sex/common_sex/sex/6.webm";
    med[69] = "data/sex/common_sex/anal/0.webm";
    med[70] = "data/sex/common_sex/anal/1.webm";
    med[71] = "data/sex/common_sex/anal/2.webm";
    med[72] = "data/sex/common_sex/anal/3.webm";
    med[73] = "data/sex/common_sex/anal/4.webm";
    med[74] = "data/sex/common_sex/anal/5.webm";
    med[75] = "data/actions/broTurnirWin/01.jpg";
    med[76] = "data/actions/broTurnirWin/02.jpg";
    med[77] = "data/actions/broTurnirWin/03.jpg";
    med[78] = "data/actions/broTurnirWin/04.jpg";
    med[79] = "data/actions/broTurnirWin/05.jpg";

    return med[id];
}

QString Brother::str(int id)
{
    QString str[218];
    str[0] = "-  Света, а тебе «Дом-2» нравится?"
             "-  Да ну нафиг! Я пару серий посмотрела. Ну дебилы, блин!"
             "-  О как!"
             "-  Ага.";
    str[1] = ""
             "-  Коль, ты всё ещё смотришь «Спокойной ночи, малыши»?"
             "-  Да."
             "-  Почему?"
             "-  Тебе не понять…"
             "-  Да ладно! Я тоже смотрю! - улыбаетесь вы.";
    str[2] = "-  Света, тебе из всех «Терминаторов» какая часть больше всего нравится?"
             "-  Первая."
             "-  Почему?"
             "-  Риз - няшка.";
    str[3] = "-  Света, «Дивергента» смотреть будем?"
             "-  Нет. Будет возможность - посмотрим обзор в интернете. Хоть поржём."
             "-  Но там же про подростков…"
             "-  Нет. Там про дебилов.";
    str[4] = "-  Коль, тебе фильм «Пролетая над гнездом кукушки» понравился?"
             "-  Пролетарий над где?";
    str[5] = "-  Света, ты «Диалоги о рыбалке» смотрела?"
             "-  Зачем?"
             "-  Ну, как… Рыбалка, всё такое…"
             "-  Коля - хочешь на рыбалку? - поедем в деревню - порыбачим. В Змеявке клёв роскошный! И полянка, где клюёт, с мягкой травкой!"
             "-  Можно я тебя расцелую?"
             "-  Позже.";
    str[6] = "-  Коль, тебе из «Зачарованных» какая из сестёр больше всех нравится?"
             "-  Младшая."
             "-  Блин, я знала."
             "-  А тебе из мужиков?"
             "-  Балтазар."
             "-  Почему?!"
             "-  Тупые овцы его не ценят.";
    str[7] = "-  Я на днях «ДМБ» посмотрел…"
             "-  Ну и как? Это вам не это?"
             "-  Ага, понял всю глубину наших глубин."
             "-  Здорово. Будешь херово  учиться…"
             "-  Ага. - Увлекательно проведу два года."
             "-  Не забывай.";
    str[8] = "-  Света, а ты б кому дала не глядя?"
             "-  Акселю Руди Пеллу."
             "-  Это кто?"
             "-  Неважно. Он - не Пеле и не Мохаммед Али."
             "-  Ы, задрот какой-то - осклабился братец.";
    str[9] = "-  Света, а почему мы с тобой порно вдвоём не смотрим?"
             "-  Не дорос еще. Иди мячик пинай с друзьями."
             "-  И ваще никак?"
             "-  Иди мячик пинай с друзьями. А я погляжу. А может даже и с вами поиграю.";
    str[10] = "-  Света, тебе из братьев Винчестеров который больше нравится?"
              "-  Оба больше нравятся."
              "-  Нет, ты точно нимфоманка."
              "-  А кто-то рискует получить неделю воздержания."
              "-  Ну прости."
              "-  Позже делом извинишься.";
    str[11] = "-  Коль, ты «Стриптиз» с Деми Мур смотрел?"
              "-  Ну да…"
              "-  У кого из нас сиськи лучше?"
              "-  У тебя конечно!!!"
              "-  Спасибо.";
    str[12] = "-  Свет, давай домашнее видео снимем?!"
              "-  А мы ещё не сняли?"
              "-  Нет кажись."
              "-  Упущение.";
    str[13] = "- Света, кроссворды гадать вместе будем?"
              "- Может быть.";
    str[14] = "- Света, а давай я тебя пофоткаю?"
              "- А нельзя!"
              "- А почему?!"
              "- А, блядь, очередь уже!";
    str[15] = "- Коль, а ты хотел бы путешествовать?"
              "- Не знаю, скорее да, чем нет."
              "- Я тож.";
    str[16] = "- Света давай воздушку купим, постреляем…"
              "- Купи - постреляем.";
    str[17] = "- Света, а давай я тебя нарисую!"
              "- Киса, я хочу вас спросить, как художник - художника: вы рисовать умеете? И как ты меня рисовать собрался?"
              "- Голышом конечно!"
              "- Давай позже…"
              "- Жадина.";
    str[18] = "- Света, а шоппинг - это хобби или зависимость?"
              "- Если за свой счёт - зависимость, за твой - терапия.";
    str[19] = "- Коль ты хотел бы сёрфинг попробовать?"
              "- Да."
              "- Такая же фигня.";
    str[20] = "- Коль, а пиво в бане можно?"
              "- Нужно.";
    str[21] = "- Света, а совместное посещение сауны или парилки - это хобби?"
              "- Если париться - да."
              "- А если перепихнуться?"
              "- Тогда это попытка суицида.";
    str[22] = "- Света! Я решил марки коллекционировать!"
              "- Ну молодец… Совсем ебанулся."
              "- А ты что коллекционировать собираешься?"
              "- Мужиков.";
    str[23] = "- Коль давай на курсы танго запишемся?"
              "- Как только найдёшь их - так сразу.";
    str[24] = "- Света, сделай мне журавлика…"
              "- Я такой позы не знаю!"
              "- Идиётина! А про оригами!"
              "- А это чё такое?";
    str[25] = "- Света, я кажется понял разницу между мужчинами и женщинами."
              "- Удиви меня!"
              "- Мужчины хотят от женщин секс, и всё. А женщины от мужчин хотят всё, и секс."
              "- Ну, в общем, да.";
    str[26] = "- <npc> Света, бутер будешь?</npc>"
              "- <hero>Буду!</hero>"
              "- <npc>Как будешь, меня позовешь!</npc>";
    str[27] = "<npc>- По части корейской кухни я собаку съел.</npc>";
    str[28] = "<npc>— Светка, отгадай слово — есть буква «х», вторая «у», заканчивается на «ня».</npc>"
              "<hero>— Опять хулиганишь?</hero>"
              "<npc>— А что такого, это - «кухня».</npc>";
    str[29] = "Захожу вчера ночью на кухню, а там отец сидит с паяльником в руке. Спрашиваю:"
              "<npc>— Кого пытаешь?</npc>"
              "<hero>— Резисторы.</hero>"
              "<npc>— И как, сопротивляются?</npc>";
    str[30] = "<hero>— Котик, ты где/?/?/?</hero>"
              "<npc>— Ты что, я же здесь!</npc>"
              "<hero>— Заткнись, придурок! Я кота ищу!</hero>";

    str[31] = "<npc>- Отвали, дура, я спать хочу!</npc>";
    str[32] = "<npc>- Света, не мешай спать!</npc>";
    str[33] = "<npc>- Мне с утра вообще-то в школу!</npc>";
    str[34] = "Ваш брат ехидно комментирует коротенькое полотенце на вас:<npc>- Светик, ты уверена что это не полотенце для рук?</npc>";
    str[35] = "Ваш брат ехидно комментирует коротенькое полотенце на вас:<npc>- Сестричка, ты специально для меня выбрала полотенце покороче?</npc>";
    str[36] = "<npc>- Светик, ты не думала сбрить эти свои заросли? Или хоть подстичь свои джунгли?</npc>";
    str[37] = "<npc>Светик, у тебя потрясающее тело!</npc>";
    str[38] = "<npc>Классно выглядишь. Ты что, нудизмом решила заняться?</npc>";
    str[39] = "<npc>- Вымой лицо, смотреть противно на всю эту кончу.</npc>";
    str[40] = "<npc>- У тебя вся одежда перепачкалась. Постирай, или мать попроси.</npc>";
    str[41] = "<npc>- Иди помойся, дура - смотреть противно на всю эту кончу!</npc>";
    str[42] = "<npc>- Иди помойся - а то вся жопа в конче! И барахло своё постирай обшликанное.</npc>";
    str[43] = "<npc>- Чё, дуреха, получила по заслугам?</npc> - не скрывая радости выдал Колька.";
    str[44] = "<npc>- Что у тебя с попой? Наказали за что-то?</npc>";
    str[45] = "Брат удивлённо смотрит на ваш животик: <npc>- Светик, ты залетела что-ли?</npc>";
    str[46] = "Брат хмурится: <npc>Отвали от меня, придурошная!</npc>";
    str[47] = "Брат приветственно машет рукой: <npc>- Светик, давай к нам! Может, и с нами поиграешь?</npc>";
    str[48] = "Вы в течение часа носитесь по полю, гоняя мячик с братом и его друзьями Мишкой и Жендосом.";
    str[49] = "Вы целый час сидите на лавочке, наблюдая за тем, как ребята играют в футбол.";
    str[50] = "Пацаны шушукаются между собой, обсуждая что-то.";
    str[51] = "Пацаны, пошушукавшись промеж собой, предлагают вам: ";
    str[52] = "<npc>Светик, пойдешь порнушку смотреть?</npc>";
    str[53] = "<npc>Да ну его, этот футбол, пойдем лучше порнушку смотреть!</npc>";
    str[54] = "Пацаны замялись: <npc>- Да так, ни о чём...</npc>";
    str[55] = "Вы немного надавили на них:<br><hero>- Вы что как малышня? Секретики какие-то у вас! - ехидно ухмыльнулись вы.</hero><br>Один из пацанов почти сразу \"раскололся\":<br><npc>- Да мы, это, того... мы хотим сходить порнуху поглядеть...</npc>";
    str[56] = "- А мне можно с вами, а? - спрашиваете вы - мне тоже интересно! Пацаны, немного посмущавшись и перетёрши тихонько промеж собой, соглашаются.";
    str[57] = "<npc>- Ты это всем подряд показываешь, шлюха пришибленная?</npc> - заходясь от смеха еле выдавил с себя Колька.";
    str[58] = "<npc>- Не понимаю, зачем так издеваться над собой?</npc>- Колька заметил ваши проколотые соски.";
    str[59] = "<npc>- Тебе идёт</npc>, - брат, подмигнув, кивает на ваши проколотые соски.";
    str[60] = "<npc>- Какая прелесть!</npc> - Колька играет с вашими проколотыми сосками.";
    str[61] = "<hero>- Смотри, что у меня есть</hero>, - вы подходите к Кольке поближе и оголяете грудь, показывая брату украшение в вашем соске,- <hero>не стесняйся, можешь потрогать</hero>.";
    str[62] = "Брат, ошарашеный вашим предложением, нерешительно дотрагивается к пирсингу в вашем соске, вызывая непроизвольный стон.";
    str[63] = "Колька резко убирает руку и извиняется за свою грубость. Вам ничего не остаётся, как уверить, что это не его вина и спрятать грудь.";
    str[64] = "Видя, что манипуляции с соском доставляют вам удовольствие, Колька начинает настойчивей играть с пирсингом, иногда сжимая выставленную грудь. Наигравшись, он отпускает вашу грудь, и говорит, что подобные украшения ему очень нравятся.";
    str[65] = "<npc>- Светик, поможешь мне с домашкой, а то у меня тут задачка не получается?</npc>";
    str[66] = "- Извини, я сейчас занята. Потом помогу.";
    str[67] = "<hero>- Коль, с уроками помощь не нужна?</hero>";
    str[68] = "<npc>Сам разберусь, отвали.</npc>";
    str[69] = "<npc>Да, не помешала бы.</npc>";
    str[70] = "Вы около часа помогали брату усвоить новый материал и разобраться в нем.";
    str[71] = "Пока вы объясняли материал, Колька неожиданно начал гладить вашу ножку своей ладонью. Вы замерли от удивления, не зная что делать.";
    str[72] = "Вы решаете продолжить заниматься домашкой, стараясь не обращать внимание на Колькину ладонь у вас на бедре. Поняв, что вы не против, он продолжает вас гладить чуть-чуть не дотягиваясь до вашей промежности.";
    str[73] = "Вы решаете убрать его руку и продолжить заниматься домашкой. Колька, покраснев как рак, усердно начинает делать вид, что решает задачки, стараясь не смотреть вам в глаза.";
    str[74] = "Пока вы объясняли материал, Колька опять начал гладить вашу ножку.";
    str[75] = "Вы закончили с домашкой, когда уже родители пошли спать, оставив вас с братцем самих. Колька c красным от возбуждения лицом спрашивает: <npc>- Светик, может немного пошалим?</npc>";
    str[76] = "<hero>- Не надо, вдруг родители увидят</hero> - шепчете вы, убирая его руку с ножки.<br><npc>- Тю...</npc> - буркнул себе под нос Колька и с гримассой обиды на лице продолжил заниматься.";
    str[77] = "<npc>- Светик, у меня скоро контрольная по анатомии будет, а я всё никак выучить её не могу. Не поможешь мне?</npc><br><hero>- В смысле?...</hero> - в недоумении переспрашиваете вы.<br><npc>- Ну там...</npc> - брат немного замешкался - <npc>посмотреть как у девочек всё там устроено, объяснить...</npc>";
    str[78] = "<hero>- Как будто ты не видел</hero> - хихикнули вы, вспоминая совместные просмотры порно с компанией Колькиных друганов.<br><npc>- Ну это не то...</npc> - начал мямлить он.";
    str[79] = "<hero>- И как ты себе это представляешь? Мне перед тобой раздеться?</hero><br><npc>- Ну... Было бы неплохо еще и рассказать</npc> - добавил он.";
    str[80] = "<hero>- А в книжке у тебя что картинок нет?</hero><br><npc>- Есть, но там всё так коряво описано, а учительница пропустила этот урок, мол \"вы и так все знаете\", а контрольную ей напиши</npc> - начал он вас уговаривать с разгоряченным лицом.";
    str[81] = "<hero>- Ладно, помогу тебе, но только если никому не скажешь. Договорились? Я серьёзно: \"никому\" - значит вообще никому!</hero> - строго говорите вы.<br><npc>- Слово пионера!</npc><br><hero>- Ты не пионер...</hero><br><npc>- А... ну тогда просто честное слово!</npc><br><hero>- Ладно, я поняла. Не продолжай.";
    str[82] = "<hero>- Коля, ты ничего не путаешь? Я ведь твоя сестра! Ты что совсем офигел, как ты себе это представляешь?</hero><br><npc>- Ну да, ты права. Глупость ляпнул...</npc>";
    str[83] = "Вы прикрываете двумя руками свою киску и выкрикиваете брату:<br><hero>- Коля, какого хрена!? Быстро свалил отсюда, мелюзга!</hero><br>Пойманный на горячем, Колька хлопает дверью и убегает прочь. Вы спокойно заканчиваете мыться и начинаете вытираться.";
    str[84] = "Смущённо, исподтишка глядя на брата, вы берёте полотенце и оборачиваете вокруг вашего разгорячённого, распаренного тела.<br>Вас бьёт дрожь от осознания неправильности и наказуемости ваших действий. Колька аккуратно прикрывает дверь и на цыпочках уходит.";
    str[85] = "Вы продолжаете мыться как ни в чём ни бывало, изредка поглядывая на своего зрителя. Тщательно мылите свое тело, особое внимание уделяя груди и киске, от чего чувствуете нарастающее возбуждение внизу живота.";
    str[86] = "Вы поворачиваетесь лицом к двери, давая Кольке лучший обзор, и эротично мнете свои сисечки <<body[''tits'']>> размера. Сжимаете пальчиками сосочек, поливая из другой руки душем свою грудь, пристально глядя при этом на брата. Вы на миг прикрываете глаза и погружаетесь в фантазии, от чего с ваших непроизвольно срывается легкий стон.";
    str[87] = "Вы расставляете ножки пошире и направляете воду из шланга на свою киску. От нахлынувшего удовольствия вы начинаете тяжело дышать и тихонько постанывать. Вскоре вы почувствовали, как теплая волна охватывает всё ваше тело, и вы начали содрогаться в оргазме.";

    str[88] = "Вы проверяете закрыта ли дверь в зал, затем молча быстро снимаете с себя всю одежду и усаживаетесь в кресло рядом с диваном, немного смущенно прикрывая свою грудь руками:<br><hero>- Ну что \"пионер\", что тебе объяснять?</hero> - спрашиваете вы, глядя на офигевшего от реальности происходящего брата.<br><npc>- Охренеть...</npc> - единственное, что смог выдавить из себя Колька, глазея на вас выпученными глазами.";
    str[89] = "<hero>- Коля, ты просто полюбоваться захотел или тебе действительно нужна помощь?</hero> - строго говорите вы, замечая увеличивающийся бугорок у него в штанах.<br><npc>- Нет-нет, нужна-нужна!</npc><br><hero>- Так может, быстрее начнем - быстрее закончим?</hero><br><npc>- Эм-да, хорошо...</npc>";
    str[90] = "Вы проверяете закрыта ли дверь в зал, затем молча быстро снимаете с себя всю одежду и усаживаетесь в кресло рядом с диваном:<br><npc>- Ну что, повторение - мать учения?</npc> - спрашивает брат.<br><hero>- Вроде того</hero> - с улыбкой отвечаете вы.";

    str[91] = "Вы разворачиваетесь попкой к брату и наклоняетесь, опираясь локтями на спинку кресла, открывая ему вид на " + root->getVaginaTipe2() + " киску и " + root->getAnusTipe() + " анус";
    str[92] = "в который вставлена анальная пробка:";
    str[93] = "Блин, офигеть";
    str[94] = "Крутой вид!";
    str[95] = "- после небольшой паузы говорит брат.";

    str[96] = "<br><npc>- Ого, а это еще зачем?</npc> - в недоумении заёрзав, спрашивает Коля, явно имея ввиду секс-игрушку в вашей попе.";
    str[97] = "<br><hero>- Мне так нравится.</hero>";
    str[98] = "<br><npc>- Вау! Серьёзно?</npc>";
    str[99] = "<br><hero>- Ну да...</hero> - смутившись, отвечаете вы.";
    str[100] = "<br><npc>- И как ощущения?</npc>";
    str[101] = "<br><hero>- Хочешь попробовать?</hero>";
    str[102] = "<br><npc>- Эм... Нет, спасибо. А, всем девчонкам такие вещи нравятся?</npc>";
    str[103] = "<br><hero>- Не знаю... Я у всех не спрашивала</hero> - краснея, отвечаете вы.";

    str[104] = "<br><npc>- Опять ты с этой штукой в заднице?</npc> - спрашивает Коля, явно имея ввиду секс-игрушку в вашей попе.";
    str[105] = "<br><hero>- Ага...</hero> - кокетливо отвечаете вы.";

    str[106] = "<br><npc>- Может лучше туда что-нибудь другое вставлять?</npc> - спрашивает он, явно намекая.";
    str[107] = "<br><hero>- В другой раз, Коля</hero>";
    str[108] = "<br><npc>- Облом...</npc>";

    str[109] = "<br><npc>- Извращенка!</npc>";
    str[110] = "<br><hero>- Ну разве что совсем чуть-чуть</hero>";

    str[111] = "<br><npc>- Светик, мне кажется или у тебя очко шире стало?</npc>";
    str[112] = "<br><hero>- Чего?</hero>";
    str[113] = "<br><npc>- Я серьезно, раньше меньше было!</npc>";
    str[114] = "<br><hero>- Не выдумывай, ничего там не изменилось и не надо на него пялиться!</hero>";

    str[115] = "<br><npc>- Изменилось, точно говорю! Раньше меньше было! Светик, ты даешь в жопу?</npc>";
    str[116] = "<br><hero>- Охренел? Нет конечно!</hero> - краснеете вы.";
    str[117] = "<br><npc>- Точно даёшь!</npc>";
    str[118] = "<br><hero>- Коля, иди нахрен!</hero>";
    str[119] = "<br><npc>- Ладно-ладно, молчу...</npc>";

    str[120] = "<br><hero>- Ты так и будешь таращиться?</hero>";
    str[121] = "<br><npc>- Ладно, давай начнём.</npc>";
    str[122] = "<br>Вы начинаете объяснять брату всю разницу между мужским и женским телом, зачем женщине грудь и тому подобное, попутно борясь с возбуждением вперемешку со стыдом от осознания того, что вы стоите раком голая перед своим родным братом.";
    str[123] = "<br><npc>- А это больно?</npc> - перебивает вас брат.";
    str[124] = "<br><hero>- Что?</hero>";
    str[125] = "<br><npc>- Ну, когда в тебя пихают член?</npc>";

    str[126] = "<br><hero>- Только в первый раз или два.</hero>";

    str[127] = "<br><npc>- Ты уже пробовала?</npc>";
    str[128] = "<br><hero>- Неважно...</hero>";
    str[129] = "<br><npc>- Ну, скажи!</npc>";

    str[130] = "<br><hero>- Нет, не пробовала.</hero>";

    str[131] = "<br><hero>- Ну, было несколько раз</hero> - отвечаете вы.";

    str[132] = "<br><hero>- Ну было дело, пробовала</hero> - отвечаете вы.";
    str[133] = "<br><npc>- А много раз уже?</npc>";
    str[134] = "Много";
    str[135] = "Достаточно";

    str[136] = "<br><hero>- Не знаю, я не пробовала.</hero>";
    str[137] = "<br><npc>- Понятно...</npc>";

    str[138] = "Вы присаживаетесь попой на пятки и разворачиваясь, чтоб посмотреть на Кольку и замечаете, что у него уже крепкий стояк, который сильно заметен через легкую домашнюю одежду, а его лицо красное от возбуждения.";

    str[139] = "<br><npc>- Света, а можешь поближе показать?</npc><br>";
    str[140] = "<hero>- Что показать?</hero><br>";
    str[141] = "<npc>- Ну ты поняла...</npc><br>";
    str[142] = "<hero>- Тебе мало что ли? И так далеко зашло...</hero> - возмущённо отвечаете вы.<br>";
    str[143] = "<npc>- Ну покажи!</npc><br>";

    str[144] = "<npc>- Светик, а покажи поближе?</npc><br>";
    str[145] = "<hero>- Опять?</hero><br>";
    str[146] = "<npc>- Снова</npc> - улыбается он - <npc>ну давай, чё ты ломаешься?</npc><br>";

    str[147] = "<hero>- Коль, ты же всё это уже видел...</hero><br>";

    str[148] = "Вы усаживаетесь в кресло и широко раздвигаете ноги. Немного нерешительно вы берете пальчиками кончики ваших половых губ и оттягиваете их немного в стороны, раскрывая слегка этим свою <<$vaginatipe2>> киску:";
    str[149] = "<br><npc>- Охренеть!...</npc> - вырывается дрожащим голосом у вашего брата.";
    str[150] = "<br><hero>- Всё? Доволен?</hero>";
    str[151] = "<br><npc>- Подожди-подожди, дай рассмотреть!</npc>";
    str[152] = "<br><hero>- Всё, хватит.</hero> - вы убираете руки и встаёте.";
    str[153] = "<br><npc>- Ну, Света!</npc>";
    str[154] = "<br><hero>- Я сказала всё!</hero> - строго отрезаете вы и одеваетесь.";

    str[155] = "Вы усаживаетесь в кресло и широко раздвигаете ноги. Вы берете пальчиками кончики ваших половых губ и оттягиваете их немного в стороны, раскрывая слегка этим свою <<$vaginatipe2>> киску:";
    str[156] = "<br><npc>- Охуенно!</npc> - вырывается у вашего брата.";
    str[157] = "<br><hero>- Доволен?</hero> - спрашиваете вы.";
    str[158] = "<br><npc>- Почти...</npc>";

    str[159] = "<br><hero>- Что еще?</hero>";
    str[160] = "<br><npc>- Светик, а можешь пальчик внутрь засунуть?</npc>";
    str[161] = "<br><hero>- Зачем?</hero>";
    str[162] = "<br><npc>- Ну, мне интересно посмотреть.</npc>";

    str[163] = "<br><hero>- Нет, конечно!</hero>";
    str[164] = "<br><npc>- Почему?</npc> - в недоуменнии спрашивает он.";
    str[165] = "<br><hero>- Сам как думаешь?</hero> - строго говорите вы и встаёте, начиная одеваться.";

    str[166] = "<br>Вы, не говоря ни слова, вводите палец во влагалище и затем ещё один. Вторая рука машинально потянулась к клитору.";

    str[167] = "<br>Скользкие стенки вашей киски очень плотно обхватили пальчики.";

    str[168] = "<br>Вы чувствуете скользкие стенки вашей киски вокруг собственных пальчиков.";

    str[169] = "<br>Ваша киска довольно просторна для пары пальцев, и вы, двигая пальцами, чувствуете скользкие стенки вашей киски.";

    str[170] = "<br>Сгорая от желания, вы, сами того не понимая, начинаете мастурбировать прямо перед лицом вашего брата.";

    str[171] = "<br>Накопившееся возбуждение полностью затуманило ваш рассудок и вы даже не обратили внимание на то, что Колька, глядя на вас, занялся тем же самым прямо напротив.";

    str[172] = "<br><hero>- Что еще?</hero>";
    str[173] = "<br><npc>- Помоги мне сбросить напряжение</npc> - выдаёт Колька.";
    str[174] = "<br><hero>- Ты охуел?</hero>";
    str[175] = "<br><npc>- Просто не одевайся и посиди на месте - я сам всё сделаю!</npc>";

    str[176] = "<br><hero>- Что еще?</hero>";
    str[177] = "<br><npc>- Давай как в прошлый раз? Мне очень понравилось</npc> - выдаёт Колька.";

    str[178] = "Опустившись с кресла на ковёр, вы, не в силах преодолеть возбуждение и желание, лежите под дрочащим над вами братом и ласкаете свою киску.";
    str[179] = " Ваши пальцы проникают внутрь и вы извиваетесь на полу, тихо постанывая и тяжело дыша.";
    str[180] = "Ваш взгляд прикован к члену брата и вы пристально следите за каждым его движением, пока внизу живота не ударяет током и вы не отдаетесь волне сильного оргазма, совсем не обращая внимание на то, что ваш брат начинает кончать прямо на вас. Струи его теплой спермы падают вам на живот и вы, извиваясь в оргазме, неспециально немного размазываете её своими руками.";

    str[181] = "Придя в себя, вы начинаете осознавать случившееся:";
    str[182] = "<br><hero>- Офигеть!</hero> - взволнованно почти выкрикиваете вы, глядя на капли спермы у себя на животе.";
    str[183] = "<br><npc>- Ага...</npc> - Колька тяжело переводит дыхание.";
    str[184] = "<br><hero>- Блядь!.. Ты... НЕТ СЛОВ!</hero>";
    str[185] = "<br><npc>- А мне понравилось...</npc> - отвечает он.";
    str[186] = "<br><hero>- Никому! Слышышь?! НИКОМУ НИ СЛОВА!</hero>";
    str[187] = "<br><npc>- Да понял я, понял. Не кричи, а то мама услышит!</npc>";

    str[188] = "Придя в себя, вы поднимаете голову на улыбающегося брата:";
    str[189] = "<br><hero>- Опять всю меня забрызгал...</hero>";
    str[190] = "<br><npc>- Ага...</npc> - Колька тяжело переводит дыхание.";
    str[191] = "<br><hero>- Засранец! Ладно, пойду, пока никто нас не застукал.</hero>";
    str[192] = "<br><npc>- Давай... Было круто, Светик!</npc>";

    str[193] = "Ваш взгляд прикован к члену брата и вы пристально следите за каждым его движением, пока внизу живота не ударяет током и вы не отдаетесь волне сильного оргазма. Но Колька в этот раз явно не спешит.";
    str[194] = "<br>Вы терпеливо ждёте, бросая взляды то на него, то на дверь в комнату, чем еще больше смущаете братца.";

    str[195] = "<br>Наконец, спустя несколько минут, он кончает, снова попадая на вас. Не говоря ни слова, вы одеваетесь и уходите.";

    str[196] = "<br><npc>- Светик, помоги мне</npc> - прошептал Колька.";

    str[197] = "Вы взяли его твердый и горячий член в руку и начали дрочить его. Наконец брат сдавленно застонал, и вы увидели как из его члена вылетает сперма.";
    str[198] = "Вы сели на корточки перед братом и приблизили лицо к его члену.";
    str[199] = "Вскоре Колька застонал: \"Светик, я сейчас кончу!\"";
    str[200] = "Вы вынули изо рта член и тут же вам в лицо ударила струя горячей спермы, потом еще и еще. Наконец брат прекратил кончать на ваше лицо.";
    str[201] = "Колька";
    str[202] = "Вы легли на диван и брат лег на вас сверху.";
    str[203] = "Вы легли на диван и брат пристролися к вашему заду.";
    str[204] = "Колька дал вам немного передохнуть, после чего сказав: ";
    str[205] = "<npc>- Молодец, Светик, хорошо поработала, а теперь вали давай!</npc>";
    str[206] = "<npc>- Спасибо, Светик, ты мне очень помогла</npc>";
    str[207] = ", продолжил заниматься своими делами.";
    str[208] = "Колька сказав: ";
    str[209] = "<npc>- Молодец, Светик, хорошо постаралась, а теперь вали давай!</npc>";
    str[210] = "<npc>- Спасибо, сеструх. Ну я пошёл.</npc>";

    str[211] = "<npc>- Свет, мы сейчас на городские соревнования поедем, хочешь с нами? Поболеешь за нас!</npc><br><hero>- Конечно, поеду! Куда вы теперь без меня!</hero> - с энтузиазмом воскликнули вы.";
    str[212] = "Вместе с ребятами вы поехали на большой городской стадион, там сегодня проходили соревнования любительских команд. Парни без особых проблем добрались до финала, но там им предстояло столкнуться с прошлогодними чемпионами, так что ребята немного приуныли. Вы решили их подбодрить:<br><hero>- Мальчишки, я вас верю, давайте! Кстати, призы в этом году отличные!</hero><br>Затем вы подошли к ним поближе и вполголоса сказали, подмигнув:<br><hero>- Если вы выиграете, то я вам особый подарочек приготовлю - уж точно не пожалеете.</hero>";
    str[213] = "После таких напутствий парни взбодрились и неожиданно разнесли соперника в пух и прах, забив 8 безответных голов. Колька был признан самым ценным игроком турнира и получил игровую приставку X-box в подарок. Сама же команда получила 25 тысяч рублей и памятные медали. На дворе был уже вечер и вы решили все вместе потратить часть призовых денег, отпраздновав победу в кафе.";
    str[214] = "Немного посидев в кафе, парни решили, что им не мешало бы немного выпить, но несовершеннолетним тут не продавали спиртное. Оглядевшись по сторонам, вы увидели сидящего рядом с вашим столиком парня, на вид лет 20. Вы встали и подошли к нему.";
    str[215] = "<hero>- Привет! Не мог бы ты нам помочь?</hero> - ни чуточки не стесняясь, сказали вы.<br><npc>- Привет! Помочь с чем конкретно?</npc> - улыбнулся парень, с удовольствием рассматривая вас.<br><hero>- Тут такое дело... у мальчишек праздник сегодня, а пиво им тут не продают. Не мог бы ты купить нам немного и отпраздновать, конечно, вместе!</hero><br><npc>- Да без проблем! Пойдем, сейчас вместе все и принесем.</npc>";
    str[216] = "Вы принесли пиво и стали праздновать. Как выяснилось позднее, вашего нового знакомого звали Михаил, парень он был довольно простой, хотя по виду деньги у него водились. Весь вечер он увивался за вами, а узнав, что Колька ваш брат - быстренько с ним подружился и даже дал ему свой номер телефона. В кафе вы просидели почти до закрытия, а потом отправились по домам.";
    str[217] = "Вы быстро оглянулись, затем с многозначительной улыбкой провели рукой по бедру брата:<hero>- Ко-оленькаа, а дай-ка мне телефончик Михаила!</hero><br><npc>- А чего вдруг понадобился?</npc><br><hero>- Сюрприз!</hero><br><npc>- Ну ладно, не такая уж тайна, вот, записывай.</npc><br>Николай надиктовал вам номер мобильного Мишки.<br>\"Вау! Ну держись Анькина попка! Сейчас замутим!\" - обрадовались вы, строя коварные планы по дальнейшему развращению сестры.";
    return str[id];
}

QString Brother::act(int id)
{
    QString act[40];
    act[0] = "Отойти";
    act[1] = "Спросить у брата куда он собирается";
    act[2] = "Спросить телефон Миши";
    act[3] = "Уйти";
    act[4] = "Играть с пацанами в футбол";
    act[5] = "Смотреть как пацаны играют";
    act[6] = "...";
    act[7] = "Вы тут о чем говорите?";
    act[8] = "Идти смотреть порнуху";
    act[9] = "Возьмите меня";
    act[10] = "Показать пирсинг сосков";
    act[11] = "Конечно помогу";
    act[12] = "Потом, сейчас не могу";
    act[13] = "Предложить помощь с домашкой";
    act[14] = "Помочь";
    act[15] = "Закончить";
    act[16] = "Игнорировать и продолжить";
    act[17] = "Убрать руку и продолжить";
    act[18] = "Отказаться";
    act[19] = "В смысле?";
    act[20] = "Ну давай...";
    act[21] = "Ты что совсем офигел?";
    act[22] = "Хм...";
    act[23] = "Раздеваться";
    act[24] = "Выйти из ванной";
    act[25] = "Вытираться";
    act[26] = "Поиграть с грудью";
    act[27] = "Направить воду на киску";
    act[28] = "Далее";
    act[29] = "Отказать и одеваться";
    act[30] = "Показать";
    act[31] = "Отказать";
    act[32] = "Засунуть";
    act[33] = "Одеваться";
    act[34] = "Дрочить брату";
    act[35] = "Сосать у брата";
    act[36] = "Сосать дальше";
    act[37] = "Вынуть изо рта";
    act[38] = "Отдаться";
    act[39] = "Идти домйо";
    return act[id];
}
