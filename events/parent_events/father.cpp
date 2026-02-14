#include "father.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Father::Father(Game* ptr): root(ptr)
{
    for (int i = 0; i < 190; ++i)
        m_cloth_remember[i] = -1;
}

void Father::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("main");
    else
        actionHandler(arg);
}

void Father::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Mother");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Father::actionHandler);
    root->addActions(btn);
}

void Father::actionHandler(QString action)
{
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "korrPar")
        root->changeLoc(lkorrpar);
    if(action == "main")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->startEvent(eFamily, "father_sheduler");
        root->gNPC(father).talk_max_count = root->gNPC(father).relation/20;
        root->rendNpcProfile(father);
        if(!root->isCloth())
        {
            root->startEvent(eFather, "check_naked");
            return;
        }
        if(root->vStatus(cumLips) + root->vStatus(cumFace) + root->vStatus(cumFrot) > 0)
        {
            root->startEvent(eFather, "cum_reaction");
            return;
        }
        if(root->vAddict(alko) > 0)
        {
            root->startEvent(eDrunkReaction, "father");
            return;
        }
        root->startEvent(eFather, "talk");
        if(root->gNPC(father).location == lsitrpar)
        {
            if(root->vEvent(fatherPayDay) != root->getDay())
                makeActBtn("request_money",act(0));
            makeActBtn("watch_tv",act(1));
            if(root->getHour() == 16 || root->getHour() == 17)
            {
                if(root->vQuest(qwOtchim) >= 2)
                {
                    root->startEvent(eFather, "check_clothing");
                    root->startEvent(eFather, "seduce");
                }
            }
        }
        if(root->vEvent(fatherHColor) != root->vBody(hairColor))
            root->startEvent(eFather, "check_hair");
        if(root->vEvent(fatherPirsDay) != root->getDay())
            root->startEvent(eFather, "check_piercing");
        if(root->vEvent(fatherLipTatto) == 0)
            root->startEvent(eFather, "check_tattoo");
        if(root->vEvent(fatherPregTalk) == 0)
            root->startEvent(eFather, "check_pregnant");
        if(root->vQuest(qwKolka) == 7 && root->getWeek() >= 2 && root->getWeek() <= 5 && root->getHour() == 17 && root->gNPC(father).sex == 1 && root->vQuest(qwOtchim) == 0)
            makeActBtn("incest_event_otchim",act(2));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "incest_event_otchim")
    {
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwOtchim) = 1;
        root->setImage(media(0));
        root->setText(str(0));
        makeActBtn("sitrPar",act(4));
    }
    if(action == "check_hair")
    {
        root->addText(str(1));
        root->vEvent(fatherHColor) = root->vBody(hairColor);
    }
    if(action == "check_piercing")
    {
        if(root->vBody(piercingC) == 1 && root->vEvent(pirsCfather) == 0)
        {
            root->vEvent(pirsCfather) = 1;
            root->vEvent(fatherPirsDay) = root->getDay();
            root->setText(str(2));
            return;
        }
        if(root->vBody(piercingD) == 1 && root->vEvent(pirsDfather) == 0)
        {
            root->vEvent(pirsDfather) = 1;
            root->vEvent(fatherPirsDay) = root->getDay();
            root->setText(str(3));
            return;
        }
        if(root->vBody(piercingE) == 1 && root->vEvent(pirsEfather) == 0)
        {
            root->vEvent(pirsEfather) = 1;
            root->vEvent(fatherPirsDay) = root->getDay();
            root->setText(str(4));
            return;
        }
        if(root->vBody(piercingA) >= 1 && root->vEvent(pirsAfather) == 0 && root->vEvent(fatherPirsAday) != root->getDay())
        {
            if(getRandInt(1,100) >= 75)
            {
                root->clearActions();
                root->vEvent(fatherPirsAday) = root->getDay();
                root->vEvent(fatherPirsDay) = root->getDay();
                root->clearActions();
                root->setText(str(5));
                makeActBtn("piercingA.nothing",act(5));
                makeActBtn("piercingA.show",act(6));
                return;
            }
        }
        if(root->vBody(piercingB) == 1 && root->vEvent(pirsBfather) == 0)
        {
            root->clearActions();
            root->vEvent(fatherPirsDay) = root->getDay();
            root->vEvent(pirsBfather) = root->getDay();
            root->setText(str(10));
            makeActBtn("piercingB.show",act(8));
        }
    }
    if(action == "piercingA.nothing")
    {
        root->clearActions();
        root->addText(str(6));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "piercingA.show")
    {
        root->clearActions();
        root->vEvent(pirsAfather) = 1;
        root->setImage(media(1));
        root->addText(str(7));
        if(root->vEvent(fatherTouched) == 0)
            root->addText(str(8));
        else
            root->addText(str(9));
        makeActBtn("main",act(7));
    }
    if(action == "piercingB.show")
    {
        root->clearActions();
        root->vEvent(pirsBfather) = 1;
        root->setImage(media(2));
        root->setText(str(11));
        if(root->vEvent(fatherTouched) == 0)
            root->addText(str(12));
        else
            root->addText(str(13));
        makeActBtn("main",act(7));
    }

    if(action == "check_naked")
    {
        if(!root->isCloth())
        {
            int rel = root->gNPC(father).relation;
            if(rel < 40 || root->getHour() >= 18)
            {
                root->changeRep('-',father);
                root->setText(str(14));
                makeActBtn("korrPar",act(3));
            }
            else if(rel >= 40 && rel < 60)
            {
                root->changeRep('-',father);
                root->setText(str(15));
                makeActBtn("korrPar",act(3));
            }
            else if(rel >= 60)
            {
                root->setText(str(16));
                if(root->gNPC(father).sex == 1)
                    root->addText(str(17));
                else
                    root->addText(str(18));
                makeActBtn("korrPar",act(3));
            }
        }
    }

    if(action == "check_tattoo")
    {
        if(root->vBody(tattooLip) > 0 && root->vEvent(fatherLipTatto) == 0 && root->gNPC(father).relation >= 60)
        {
            makeActBtn("check_tattoo.show",act(9));
        }
    }
    if(action == "check_tattoo.show")
    {
        root->clearActions();
        root->vEvent(fatherLipTatto) = 1;
        root->setImage(media(root->vBody(tattooLip) + 2));
        root->setText(str(19));
        makeActBtn("main",act(7));
    }

    if(action == "check_pregnant")
    {
        if(root->PregVisibility() == true)
        {
            root->addText(str(20));
            root->vEvent(fatherPregTalk) = 1;
        }
    }

    if(action == "check_talktime")
    {
        root->clearActions();
        i = 0;
        if(root->vEvent(fatherSorryDay) == root->getDay())
        {
            i = 1;
            root->setText(str(21));
        }
        else if(root->gNPC(father).talk_count == root->gNPC(father).talk_max_count)
        {
            i = 1;
            root->gNPC(father).talk_count += 1;
            root->setText(str(22));
            if(root->getCurLoc() == lsitrpar)
            {
                if(root->getHour() <= 17 && root->getSunWeather() >= 0)
                    root->addText(str(23));
                else if(root->getHour() <= 17 && root->getSunWeather() < 0)
                    root->addText(str(24));
                if(root->getHour() >= 18)
                    root->addText(str(25));
                if(root->getHour() >= 18 && root->vSchool(vacation) == 0 && root->getWeek() > 0 && root->getWeek() < 6)
                    root->addText(str(26));
            }
            else
                root->setText(str(27));
        }
        else if(root->gNPC(father).talk_count > root->gNPC(father).talk_max_count && root->gNPC(father).talk_count < 100)
        {
            i = 1;
            root->changeRep('-',father);
            root->vStatus(mood) -= 5;
            root->gNPC(father).talk_count = 100;
            root->setText(str(28));
        }
        if(i == 1)
        {
            root->clearActions();
            makeActBtn("back_to_loc",act(3));
        }
    }
    if(action == "talk")
    {
        makeActBtn("talk.talk",act(10));
    }
    if(action == "talk.talk")
    {
        root->startEvent(eFather, "check_talktime");
        if(root->gNPC(father).talk_count == 100 && i == 0)
        {
            root->setText(str(29));
            root->clearActions();
            makeActBtn("back_to_loc",act(3));
        }
        else
        {
            if(i == 0)
            {
                root->clearActions();
                root->incTime(getRandInt(10,15));
                root->changeRep('+',father);
                root->gNPC(father).talk_count += 1;
                makeActBtn("back_to_loc",act(3));
                root->rendNpcProfile(father);
                if(root->gNPC(father).location == lsitrpar)
                    root->setText(str(30));
                if(root->gNPC(father).location == lkuhrpar)
                    root->setText(str(31));
                root->startEvent(eFather,"talk_variants");
            }
        }
    }
    if(action == "talk_variants")
    {
        if(root->gNPC(father).relation < 20)
            root->startEvent(eFather, "dialogues.0");
        else if(root->gNPC(father).relation >= 20 && root->gNPC(father).relation < 40)
            root->startEvent(eFather, "dialogues.1");
        else if(root->gNPC(father).relation >= 40)
        {
            if(root->vStatus(vnesh) <= 60)
                root->startEvent(eFather, "dialogues.2");
            else
                root->startEvent(eFather, "dialogues.3");
        }
    }

    if(action == "dialogues.0")
    {
        if(root->gNPC(father).location == lgargazel)
            root->setText(str(32));
        else
            root->setText(str(33));
        if(root->vEvent(fatherSorryDay) != root->getDay())
        {
            makeActBtn("father_sorry",act(11));
        }
    }
    if(action == "father_sorry")
    {
        root->clearActions();
        root->vEvent(fatherSorryDay) = root->getDay();
        root->changeRep('+',father);
        root->setText(str(34));
        makeActBtn("main",act(7));
    }
    if(action == "dialogues.1")
    {
        if(root->gNPC(father).location == lgargazel)
            root->setText(str(35));
        else
            root->setText(str(36));
        if(root->vEvent(fatherSorryDay) != root->getDay())
            makeActBtn("father_sorry.2",act(12));
    }
    if(action == "father_sorry.2")
    {
        root->clearActions();
        root->vEvent(fatherSorryDay) = root->getDay();
        root->changeRep('+',father);
        root->setText(str(37));
        makeActBtn("main",act(7));
    }
    if(action == "dialogues.2")
    {
        if(root->gNPC(father).location == lgargazel)
            root->setText(str(38) + str(getRandInt(39,43)));
        else
            root->setText(str(getRandInt(44,48)));
    }
    if(action == "dialogues.3")
    {
        if(root->vQuest(qwOtchim) >= 3 && root->gNPC(father).location != lkuhrpar && root->gNPC(mother).location != root->gNPC(father).location)
        {
            if(root->gNPC(father).location == lgargazel)
                root->setText(str(49));
            else
                root->setText(str(50));
            if(root->gNPC(father).location == lgargazel)
            {
                if(root->vStatus(horny) >= 60 || root->vEvent(fatherTouched) == 1)
                    makeActBtn("molest_act.3",act(16));
            }
            else
                makeActBtn("molest_act.0",act(13));
            if(root->vEvent(father_horny) > 60)
                makeActBtn("molest_act.1",act(14));
            if(root->gNPC(father).location != root->gNPC(brother).location)
                makeActBtn("molest_act.2",act(15));
        }
        else
            root->startEvent(eFather, "dialogues.2");
    }
    if(action == "molest_act.0")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(13));
        root->setText(str(51));
        int rel = root->gNPC(father).relation;
        if(rel < 60)
        {
            root->clearActions();
            root->vStatus(horny) -= 20;
            root->changeRep('-',father);
            root->gNPC(father).talk_count = root->gNPC(father).talk_max_count;
            root->addText(str(52));
            makeActBtn("back_to_loc",act(3));
        }
        else
        {
            if(root->vEvent(father_horny) < 50)
            {
                root->vStatus(horny) -= 5;
                root->vEvent(father_horny) += getRandInt(1,5);
                root->addText(str(53));
            }
            else
            {
                root->vStatus(horny) += getRandInt(5,10);
                root->vEvent(father_horny) += getRandInt(5,10);
                root->addText(str(54));
            }
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "molest_act.1")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(11));
        root->setText(str(55));
        int rel = root->gNPC(father).relation;
        if(rel < 60)
        {
            root->vStatus(horny) -= 10;
            root->changeRep('-',father);
            root->gNPC(father).talk_count = root->gNPC(father).talk_max_count;
            root->addText(str(56));
        }
        else if(rel >= 60 && rel < 80)
        {
            root->vStatus(horny) -= 5;
            root->vEvent(father_horny) += getRandInt(1,5);
            root->addText(str(57));
        }
        else
        {
            root->vStatus(horny) += getRandInt(5,10);
            root->vEvent(father_horny) += getRandInt(5,10);
            root->addText(str(58));
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "molest_act.2")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += getRandInt(1,5);
        root->setText(str(59));
        int rel = root->gNPC(father).relation;
        if(rel < 60)
        {
            root->vStatus(horny) -= 10;
            root->gNPC(father).talk_count = root->gNPC(father).talk_max_count;
            if(root->isPanties())
            {
                root->changeRep('-',father);
                root->setImage(media(14));
                root->addText(str(60));
            }
            else
            {
                root->changeRep('-',father, 10);
                root->setImage(media(8));
                root->addText(str(61));
            }
        }
        else if(rel >= 60 && rel < 80)
        {
            root->vStatus(horny) -= 5;
            root->changeRep('-',father);
            if(root->isPanties())
            {
                root->setImage(media(14));
                root->addText(str(62));
            }
            else
            {
                root->setImage(media(8));
                root->addText(str(63));
            }
        }
        else
        {
            root->vStatus(horny) += getRandInt(5,10);
            if(root->isPanties())
            {
                root->vEvent(father_horny) += getRandInt(1,5);
                root->setImage(media(7));
                root->addText(str(64));
            }
            else
            {
                root->vEvent(father_horny) += getRandInt(5,10);
                root->setImage(media(9));
                root->addText(str(65));
            }
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "molest_act.3")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += getRandInt(5,10);
        root->setImage(media(getRandInt(24,29)));
        root->setText(str(66));
        makeActBtn("molest_act.3.1",act(17));
    }
    if(action == "molest_act.3.1")
    {
        root->clearActions();
        if(root->gNPC(father).relation < 60)
        {
            root->vStatus(horny) -= 20;
            root->changeRep('-',father,10);
            root->gNPC(father).talk_count = root->gNPC(father).talk_max_count;
            root->addText(str(67));
        }
        else
        {
            if(root->vEvent(father_horny) < 50)
            {
                root->vStatus(horny) -= 5;
                root->vEvent(father_horny) += getRandInt(1,5);
                if(root->isPanties())
                {
                    root->setImage(media(12));
                    root->addText(str(68));
                }
                else
                {
                    root->setImage(media(10));
                    root->addText(str(69));
                }
            }
            else
            {
                root->vStatus(horny) += getRandInt(5,10);
                root->vEvent(father_horny) += getRandInt(5,10);
                root->addText(str(70));
            }
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "request_money")
    {
        root->clearActions();
        if(root->gNPC(father).talk_count == 100)
        {
            root->addText(str(71));
            makeActBtn("back_to_loc",act(3));
            return;
        }
        root->incTime(getRandInt(5,10));
        makeActBtn("back_to_loc",act(3));
        root->rendNpcProfile(father);
        root->setText(str(72));
        if(root->vEvent(fatherPayDay) == root->getDay())
            root->addText(str(73));
        else
        {
            root->addText(str(74));
            if(root->vEvent(fatherTouched) == 1 || (root->gNPC(father).relation >= 40 && root->vStatus(vnesh) >= 60))
            {
                if(root->vEvent(father_horny) >= 70)
                    i = 0;
                else
                    i = getRandInt(1,100);
                if(i == 0)
                    root->addText(str(75));
                else if(i > 0 && i < 30)
                    root->addText(str(76));
                else if(i >= 30)
                    root->addText(str(77));
                makeActBtn("request_money.please",act(18));
            }
        }
    }
    if(action == "request_money.please")
    {
        root->clearActions();
        root->incTime(5);
        root->vEvent(fatherPayDay) = root->getDay();
        if(root->vEvent(father_horny) >= 70)
            i = 30;
        root->addText(str(78));
        if(i < 30)
        {
            root->addText(str(79));
        }
        else if(i >= 30 && i < 70)
        {
            if(root->gNPC(father).sex == 1)
            {
                root->clearActions();
                makeActBtn("request_money.areYouForget",act(19));
            }
            else
            {
                root->addText(str(81));
                makeActBtn("request_money.please2",act(20));
            }
        }
        else
        {
            root->vStatus(money) += 200;
            root->addText(str(83));
        }
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "request_money.areYouForget")
    {
        root->clearActions();
        root->vStatus(money) += 100;
        root->changeRep('-',father);
        root->addText(str(80));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "request_money.please2")
    {
        root->vStatus(money) += 200;
        root->addText(str(82));
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "cum_reaction")
    {
        makeActBtn("korrPar",act(4));
        if(root->gNPC(father).sex == 0)
        {
            root->changeRep('-',father,100);
            root->setText(str(84));
        }
        else
        {
            root->changeRep('-',father,3);
            root->setText(str(85));
        }
    }
    if(action == "seduce")
    {
        if(root->vQuest(qwOtchim) >= 5 && root->vEvent(dadQWday) != root->getDay() && root->gNPC(father).relation >= 80)
        {
            if((root->getHour() == 16 || root->getHour() == 17) && (root->gNPC(father).sex == 1 || (root->vEvent(fatherTouched) == 1 && root->vStatus(horny) >= 60)))
            {
                makeActBtn("seduce2",act(21));
            }
        }
    }
    if(action == "seduce2")
    {
        root->clearActions();
        root->gNPC(father).sex = 1;
        root->vEvent(dadQWday) = root->getDay();
        root->changeRep('+',father,10);
        root->incTime(30);
        if(root->vSex(analplugIN) == 0)
        {
            if(root->isPanties())
                root->startEvent(eFatherSex, "father_bend.1");
            else
                root->startEvent(eFatherSex, "father_bend.2");
        }
        else
        {
            root->startEvent(eFatherSex, "father_bend.0");
        }
    }

    if(action == "watch_tv")
    {
        root->clearActions();
        root->setImage(media(29));
        if(root->gNPC(father).talk_count == 100)
        {
            root->startEvent(eFather, "watch_tv_act.1");
        }
        else
        {
            int rel = root->gNPC(father).relation;
            if(rel < 20)
                root->startEvent(eFather, "watch_tv_act.0");
            if(rel >= 20 && rel < 40)
                root->startEvent(eFather, "watch_tv_act.1");
            if(rel >= 40)
            {
                if(root->vStatus(vnesh) < 60)
                    root->startEvent(eFather, "watch_tv_act.2");
                else
                    root->startEvent(eFather, "watch_tv_act.3");
            }
            makeActBtn("back_to_loc",act(3));
        }
    }
    if(action == "watch_tv_change_stat.0")
    {
        root->incTime(getRandInt(2,5));
        root->vStatus(mood) -= getRandInt(1,10);
    }
    if(action == "watch_tv_change_stat.1")
    {
        root->incTime(getRandInt(50,70));
        root->vStatus(mood) += getRandInt(10,20);
    }
    if(action == "watch_tv_act.0")
    {
        root->setText(str(86));
        if(root->vEvent(fatherSorryDay) != root->getDay())
            makeActBtn("watch_tv_sorry",act(11));
        root->startEvent(eFather, "watch_tv_change_stat.0");
    }
    if(action == "watch_tv_sorry")
    {
        root->clearActions();
        root->vEvent(fatherSorryDay) = root->getDay();
        root->changeRep('+',father);
        root->setImage(media(30));
        root->setText(str(87));
        root->startEvent(eFather, "watch_tv_act.2");
    }
    if(action == "watch_tv_act.1")
    {
        root->setText(str(88));
        if(root->gNPC(father).talk_count == 100)
        {
            if(getRandInt(2,5) <= root->gNPC(father).relation / 20)
            {
                root->clearActions();
                root->setImage(media(29));
                root->addText(str(89));
                makeActBtn("watch_tv_act.1.sorry",act(22));
            }
            root->startEvent(eFather, "watch_tv_change_stat.0");
        }
        else
        {
            if(root->vEvent(fatherSorryDay) != root->getDay())
            {
                makeActBtn("watch_tv_act.1.sorry2",act(12));
            }
        }
    }
    if(action == "watch_tv_act.1.sorry")
    {
        root->clearActions();
        root->changeRep('+',father);
        root->setText(str(90));
        root->gNPC(father).talk_count = root->gNPC(father).talk_max_count;
        makeActBtn("watch_tv_act.1.sorry.1",act(23));
    }
    if(action == "watch_tv_act.1.sorry.1")
    {
        root->setImage(media(29));
        root->startEvent(eFather, "watch_tv");
    }
    if(action == "watch_tv_act.1.sorry2")
    {
        root->clearActions();
        root->vEvent(fatherSorryDay) = root->getDay();
        root->changeRep('+',father);
        root->addText(str(91));
        root->startEvent(eFather, "watch_tv_act.2");
    }
    if(action == "watch_tv_act.2")
    {
        if(root->vEvent(fatherTvDay) != root->getDay())
        {
            root->changeRep('+',father);
            root->vEvent(fatherTvDay) = root->getDay();
        }
        root->setText(str(92) + str(getRandInt(93,97)));
        root->startEvent(eFather, "watch_tv_change_stat.1");
    }
    if(action == "watch_tv_act.3")
    {
        if(root->vEvent(fatherTvDay) != root->getDay())
        {
            root->changeRep('+',father);
            root->vEvent(fatherTvDay) = root->getDay();
        }
        root->setText(str(98));
        if(root->vEvent(father_horny) >= 50 && root->vEvent(dadQWday) != root->getDay() && root->gNPC(mother).location != root->gNPC(father).location && root->gNPC(brother).location != root->gNPC(father).location)
        {
            if(root->vStatus(horny) >= 60 || root->vEvent(fatherTouched) == 1)
                root->startEvent(eFather, "watch_tv_act.4");
            root->startEvent(eFather, "watch_tv_change_stat.1");
            return;
        }
        else
        {
            root->startEvent(eFather, "watch_tv_act.2");
        }
    }
    if(action == "watch_tv_act.4")
        makeActBtn("lieOnHisChest",act(24));
    if(action == "lieOnHisChest")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += getRandInt(1,5);
        root->setText(str(99));
        if(root->vEvent(father_horny) < 70)
        {
            root->vStatus(horny) -= getRandInt(1,5);
            root->setImage(media(31));
            root->addText(str(100));
        }
        else
        {
            root->addText(str(101));
        }
        if(getRandInt(0,1) == 1)
        {
            root->addText(str(102));
            makeActBtn("lieOnHisChest.allow",act(25));
            makeActBtn("back_to_loc",act(3));
        }
        else
        {
            root->addText(str(104));
            makeActBtn("lieOnHisChest.allow2",act(25));
        }
    }
    if(action == "lieOnHisChest.allow")
    {
        root->clearActions();
        root->vStatus(horny) += 20;
        root->vEvent(fatherTouched) = 1;
        root->setImage(media(32));
        root->setText(str(103));
        root->startEvent(eFather, "watch_tv_act.5");
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "lieOnHisChest.allow2")
    {
        root->clearActions();
        root->vStatus(horny) += 20;
        root->vEvent(fatherTouched) = 1;
        if(root->vBody(anus) < 5)
            root->vBody(anus) += 1;
        if(root->isPanties())
        {
            root->setImage(media(33));
            root->setText(str(105));
        }
        else
        {
            root->setImage(media(34));
            root->setText(str(106));
            root->startEvent(eFather, "watch_tv_act.5");
            makeActBtn("back_to_loc",act(3));
        }
    }
    if(action == "watch_tv_act.5")
    {
        if(root->gNPC(father).sex == 1 && (root->getHour() == 16 || root->getHour() == 17))
        {
            root->vEvent(dadQWday) = root->getDay();
            root->clearActions();
            root->setImage(media(35));
            root->setText(str(107));
            makeActBtn("father_blow2",act(26));
        }
    }
    if(action == "father_blow2")
        root->startEvent(eFatherSex, "father_blow.2");
    if(action == "show_hidden_piercing")
    {
        if((root->vBody(piercingF) > 0 && root->vEvent(pirsFfather) == 0) || (root->vBody(piercingG) > 0 && root->vEvent(pirsGfather) == 0))
        {
            root->vEvent(father_horny) += 20;
            makeActBtn("back_to_loc",act(3));
            if(root->isNude())
                root->addText(str(108));
            else
                root->addText(str(109));
            if(root->vBody(piercingF) > 0 && root->vEvent(pirsFfather) == 0)
            {
                root->startEvent(eFather, "show_hidden_piercing_reaction.0");
                if(root->vBody(piercingG) > 0 && root->vEvent(pirsGfather) == 0)
                    makeActBtn("show_intim_piercing",act(27));
            }
            else if(root->vBody(piercingG) > 0 && root->vEvent(pirsGfather) == 0)
                root->startEvent(eFather, "show_hidden_piercing_reaction.1");
        }
    }
    if(action == "show_intim_piercing")
    {
        root->startEvent(eFather, "show_hidden_piercing_reaction.1");
        makeActBtn("back_to_loc",act(3));
    }
    if(action == "show_hidden_piercing_reaction.0")
    {
        root->vEvent(pirsFfather) = 1;
        root->addText(str(110));
        if(root->vEvent(fatherTouched) == 0)
            root->addText(str(111));
        else if(root->vEvent(fatherTouched) == 1 && root->gNPC(father).sex == 0)
            root->addText(str(112));
        else if(root->gNPC(father).sex == 1)
            root->addText(str(113));
    }
    if(action == "show_hidden_piercing_reaction.1")
    {
        root->vEvent(pirsGfather) = 1;
        root->addText(str(114));
        if(root->vEvent(fatherTouched) == 0)
            root->addText(str(115));
        else if(root->vEvent(fatherTouched) == 1 && root->gNPC(father).sex == 0)
            root->addText(str(116));
        else if(root->gNPC(father).sex == 1)
            root->addText(str(117));
    }
    if(action == "check_clothing")
    {
        m_cloth_remember[0] = 1;
        m_cloth_remember[1] = 1;
        if(m_cloth_remember[root->getCurClothId()] > -1)
        {
            root->addText(str(118));
        }
        else
            makeActBtn("check_clothing.howIt",act(28));
    }
    if(action == "check_clothing.howIt")
    {
        root->clearActions();
        root->incTime(getRandInt(10,15));
        root->rendNpcProfile(father);
        if(root->gNPC(father).relation <= 40 || root->vStatus(vnesh) < 60)
        {
            root->clearActions();
            root->vStatus(mood) -= getRandInt(10,20);
            root->setText(str(119));
            makeActBtn("korrPar",act(29));
        }
        else
        {
            m_cloth_remember[root->getCurClothId()] = 1;
            root->setText(str(120));
            if(root->vQuest(qwOtchim) < 3 || root->gNPC(father).relation < 60)
            {
                root->clearActions();
                root->vStatus(horny) += getRandInt(1,5);
                root->setText(str(121));
                makeActBtn("back_to_loc",act(3));
            }
            else
            {
                root->vStatus(horny) += getRandInt(1,5);
                root->vStatus(mood) += getRandInt(1,5);
                root->vEvent(father_horny) += getRandInt(5,10);
                root->setText(str(122));
                if(root->vStatus(horny) >= 50 || root->vEvent(fatherTouched) == 1)
                    makeActBtn("shake_ass",act(30));
                if(root->vStatus(horny) >= 80 || root->vEvent(fatherTouched) == 1)
                {
                    if(root->isCloth())
                    {
                        makeActBtn("corr_cloth",act(31));
                        makeActBtn("touch_cloth",act(32));
                    }
                }
                makeActBtn("back_to_loc",act(3));
            }
        }
    }
    if(action == "shake_ass")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += getRandInt(1,5);
        root->setText(str(123));
        if(root->vEvent(father_horny) < 50)
        {
            root->vStatus(horny) -= getRandInt(1,5);
            if(root->isPanties())
            {
                root->setImage(media(36));
                root->addText(str(124));
            }
            else
            {
                root->setImage(media(37));
                root->addText(str(125));
            }
        }
        else
        {
            root->vEvent(father_horny) += getRandInt(5,10);
            if(root->isPanties())
            {
                root->setImage(media(38));
                root->setText(str(126));
                if(root->vStatus(horny) >= 90)
                    makeActBtn("down_panty",act(33));
            }
            else
            {
                root->setImage(media(40));
                root->setText(str(128));
            }
        }
        makeActBtn("back_to_loc",act(7));
    }
    if(action == "down_panty")
    {
        root->clearActions();
        root->vEvent(father_horny) += getRandInt(5,15);
        root->setImage(media(39));
        root->setText(str(127));
        makeActBtn("back_to_loc",act(7));
    }
    if(action == "corr_cloth")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += getRandInt(1,5);
        root->setText(str());
    }
}

QString Father::media(int id)
{
    QString med[50];
    med[0] = "data/npc/pavlovo/parents/count.jpg";
    med[1] = "data/img/body/piercing/pirsA.jpg";
    med[2] = "data/img/body/piercing/pirsB.jpg";
    med[3] = "data/img/body/tattoo/lip/0.jpg";
    med[4] = "data/img/body/tattoo/lip/1.jpg";
    med[5] = "data/img/body/tattoo/lip/2.jpg";
    med[6] = "data/img/body/tattoo/lip/3.jpg";
    med[7] = "data/sex/fatherSex/fatherim20.jpg";
    med[8] = "data/sex/fatherSex/fatherim24.jpg";
    med[9] = "data/sex/fatherSex/fatherim26.jpg";
    med[10] = "data/sex/fatherSex/fatherim27.jpg";
    med[10] = "data/sex/fatherSex/fatherim28.jpg";
    med[11] = "data/sex/fatherSex/fatherim29.jpg";
    med[12] = "data/sex/fatherSex/fatherim30.jpg";
    med[13] = "data/sex/fatherSex/fatherim31.jpg";
    med[14] = "data/sex/incest/gar/father.gar.0,0.jpg";
    med[15] = "data/sex/incest/gar/father.gar.0,1.jpg";
    med[16] = "data/sex/incest/gar/father.gar.0,2.jpg";
    med[17] = "data/sex/incest/gar/father.gar.0,3.jpg";
    med[18] = "data/sex/incest/gar/father.gar.0,4.jpg";
    med[19] = "data/sex/incest/gar/father.gar.1,0.jpg";
    med[20] = "data/sex/incest/gar/father.gar.1,1.jpg";
    med[21] = "data/sex/incest/gar/father.gar.1,2.jpg";
    med[22] = "data/sex/incest/gar/father.gar.cum1,0.jpg";
    med[23] = "data/sex/incest/gar/father.gar.pre0.jpg";
    med[24] = "data/sex/incest/gar/father.gar.pre1.jpg";
    med[25] = "data/sex/incest/gar/father.gar.pre2.jpg";
    med[26] = "data/sex/incest/gar/father.gar.pre3.jpg";
    med[27] = "data/sex/incest/gar/father.gar.pre4.jpg";
    med[28] = "data/sex/incest/gar/father.gar.pre5.jpg";
    med[29] = "data/actions/tv/telek.jpg";
    med[30] = "data/sex/fatherSex/fatherim36.jpg";
    med[31] = "data/sex/fatherSex/fatherim22.jpg";
    med[32] = "data/sex/fatherSex/fatherim18.jpg";
    med[33] = "data/sex/fatherSex/fatherim17.jpg";
    med[34] = "data/sex/fatherSex/fatherim16.jpg";
    med[35] = "data/sex/fatherSex/fatherim21.jpg";
    med[36] = "data/sex/fatherSex/fatherim47.jpg";
    med[37] = "data/sex/fatherSex/fatherim48.jpg";
    med[38] = "data/sex/fatherSex/fatherim49.jpg";
    med[39] = "data/sex/fatherSex/fatherim50.jpg";
    med[40] = "data/sex/fatherSex/fatherim51.gif";
    return med[id];
}

QString Father::str(int id)
{
    QString str[150];
    str[0] = "Отчим высказал все, что он думает о вашем развратном поведении. Однако, вам показалось, что он больше смакует подробности:<br>"
             "<npc>- Совсем как проститутка в две дырки даешь. Может, еще и в одну тебе оба суют, а?</npc><br><hero>- Может, и суют,</hero> -"
             " зло буркнули вы,<hero>- хочу и даю, я уже взрослая!</hero><br><npc>- Взрослая она, едрена кочерыжка, ну коли такая взрослая иди"
             " на панель - зарабатывай!</npc><br><hero>- Да поняла я все! Ну увидел, увлеклись мы слегка, ну прям такой ужас! Я извиняюсь. "
             "Честно,</hero> - резко сбавили вы обороты.<br><npc>- А папке почему задик не подставляешь, а?</npc> - уже несколько игриво "
             "хохотнул отчим и придвинулся к вам,<npc>- Знаешь же, как папка любит?</npc><br><hero>- Так я не против.</hero><br><npc>- И "
             "хорошо. Значит, так и решим. Я уж помолчу про твои похождения, так и быть. Но и сам хочу поучаствовать. Как время посвободнее"
             " - попочку мне изволь нарисовать. И раз уж такая вся готовая: хочу попробовать, как это два сразу в зад. Давно интересно, да"
             " никак не получалось. Ну что, согласна?</npc><br><hero>- Ну не знаю, это ж с кем-то надо...</hero><br><npc>- Да вот с Колькой "
             "и отдолбаем по-родственному. Я ему еще мозги вправлю, конечно, ну да это тебя не касается.</npc><br><hero>- Как скажешь, пап, я"
             " смотрю ты все решил. Мне, в принципе, без разницы, только чтоб со смазкой,</hero> - вы вздохнули и пожали плечами.<br><npc>- А "
             "паренек-то этот второй чего? Хороший ебарь, поди,</npc> - отчим похабно рассмеялся.<br><hero>- Ничего так.</hero><br><npc>- Но "
             "папочка-то лучше, да? Ладно, пусть приходит. Каши не испортит. Я уж ваше блядство от Ольги прикрою.</npc><b>В воскресенье в 9 "
             "матери не будет дома тогда и попрактикуемся</b>- добавил он.";
    str[1] = "Отчим с интересом посмотрел на ваши волосы: <npc>- О, я вижу, ты перекрасилась? ' + func('barbershop','change_haircolor') + '</npc>";
    str[2] = "Отчим смотрит на ваши уши, замечая серёжки: <npc>- Я гляжу, ты обзавелась серёжками? Очень мило.</npc>";
    str[3] = "Отчим смотрит немного шокированно на ваше кольцо в носу: <npc>- Господи, Света, а это-то ещё зачем? Я понимаю, быкам кольцо в нос вставляют, чтобы их за это кольцо таскать, но тебе-то зачем?</npc>";
    str[4] = "Отчим качает головой, смотря на ваш пирсинг брови: <npc>- Света, ну зачем тебе эта ерунда в брови?</npc>, - после чего сокрушенно качает головой: <npc>- Эх молодёжь, молодёжь...</npc>";
    str[5] = "Отчим заглядывает вам в рот: <npc>- Света, а что у тебя там на языке блестит?</npc>";
    str[6] = "Вы отрицательно мотаете головой: <hero>- Ничего!</hero>, - и тут же отворачиваетесь, чтобы отчим не заметил пирсинг языка.";
    str[7] = "Вы открываете рот и высовываете язык, показывая отчиму пирсинг языка.";
    str[8] = "Отчим качает головой: <npc>- Света, пирсинг языка делают распутные женщины, обслуживающие мужчин ртом.</npc>";
    str[9] = "Отчим ухмыляется: <npc>- Это чтобы лучше ротиком работать?</npc>";
    str[10] = "Ваш отчим смотрит на вашу губу, в которой появился пирсинг: <npc>- А это ещё зачем?</npc>";
    str[11] = "Вы пожимаете плечами и говорите, что просто вам понравилось, вот вы и решили сделать себе такое.";
    str[12] = "Отчим качает головой: <npc>- Эх молодежь, вечно всё у вас к новым дыркам сводится...</npc>";
    str[13] = "Отчим ухмыляется: <npc>- Ну да, выглядит сексуально!</npc>";
    str[14] = "<npc>- Стыд совсем потеряла? Быстро пошла оделась!</npc> - рявкнул отчим, и вы поспешили долой с его глаз.";
    str[15] = "<npc>- Ты чего в таком виде по дому разгуливаешь? Иди оденься, блядинка малолетняя!</npc> - строго сказал отчим, и вы поспешили прочь с его глаз.";
    str[16] = "Отчим с ухмылкой смотрит на вас: <npc>- Ни фига! Блядинка растет. Ты хоть постыдись, всё-таки я мужчина.</npc>";
    str[17] = "Продолжив смотреть на вас, он добавил: <npc>- Красота... ";
    if(root->getHour() > 17)
    {
        str[17] += "но иди оденься, мать дома";
    }
    str[17] += "</npc>";
    str[18] = "<npc>- А тело так ничё, я вдул бы...";
    if(root->getHour() > 17)
        str[18] += "но иди оденься, мать дома";
    str[18] += "</npc>";
    str[19] = "Вы выворачиваете губу и показываете татуировку на внутренней её стороне. Отчим смотрит удивленным взглядом: <npc>- Офигеть! И до чего только не додумаются в наше время!</npc>";
    str[20] = "Отчим удивлённо смотрит на ваш животик: <npc>- Светик, ты залетела что ли? ";
    if(root->gNPC(father).sex > 0)
        str[20] += "Не от меня, надеюсь?";
    str[20] += "</npc>";
    str[21] = "<npc>- Света, на сегодня разговор закончен, иди займись чем-нибудь полезным.</npc>";
    str[22] = "<npc>- Ну ты, Света, и болтушка!</npc>";
    str[23] = "<npc>- Сходи на улицу, погуляй, погодка-то прекрасная.</npc>";
    str[24] = "<npc>- Может, к подружкам сходишь?</npc>";
    str[25] = "<npc>- Иди лучше мамке на кухне помоги...</npc>";
    str[26] = "<npc>- Или вон Кольке с уроками.</npc>";
    str[27] = "<npc>- Света, разве не видишь - я занят, не мешай.</npc>";
    str[28] = "<npc>Света, будь же ты человеком - не мешай!</npc> - отмахнулся отчим, немного повысив голос.";
    str[29] = "Вы вспоминаете, что уже задолбали отчима своими разговорами, и предпочитаете ...";
    str[30] = "Отчим сидит на диване и смотрит телевизор. Вы присели рядом с ним на диван.";
    str[31] = "Отчим сидит и пьет чай. Вы присели рядом с ним.";
    str[32] = "Вы пытаетесь предложить свою помощь отчиму, но он отмахивается: - Не, мешай мне! Не видишь, что я занят?";
    str[33] = "Вы пытаетесь поговорить с отчимом, но он отказывается с вами говорить.";
    str[34] = "Вы извиняетесь перед отчимом и он, кажется, вас прощает.";
    str[35] = "Вы пытаетесь предложить свою помощь отчиму, но он отмахивается, намекая, что от вас больше пользы будет на кухне.";
    str[36] = "Вы пытаетесь поговорить с отчимом, но он разговаривает с вами сухо.";
    str[37] = "Вы подлизываетесь к отчиму и он, кажется, начинает к вам лучше относиться.";

    str[38] = "Пока вы помогаете отчиму, он, не отвлекаясь от Газельки, ";
    str[39] = "рассказывает вам о том, что у каждой машины свой характер.";
    str[40] = "рассказывает вам об устройстве двигателя.";
    str[41] = "жалуется на ненадёжность машины и ужасную дороговизну запчастей.";
    str[42] = "жалуется на плохое состояние дорог.";
    str[43] = "рассказывает вам об устройстве ходовой.";

    str[44] = "Немного поболтав, вы уходите";
    str[45] = "Вы спросили у отчима, как он познакомился с мамой. Отчим почесал уже лысеющую голову и ответил: - \"Я тогда таксистом работал. Подвозил как-то Наташу, твою маму. Она еще тогда совсем соплюшкой была, немногим старше Анютки, но уже успела выскочить замуж за однокласника и родить вас с Аней. Вашего отца я не знал, видел только пару раз. Знаю что его зовут Михаил Кузнецов. Он уехал куда-то, в другой город.\"";
    str[46] = "Вы спросили у отчима про его работу. Отчим потянулся, хрустя суставами. \"Раньше таксёрил. Сейчас надоело. И опасно, и старею. Купил Газель, и сейчас на грузовичке продукты развожу торгашам. Сама знаешь, у меня два гаража, в одном наша Волга стоит, в другом я Газель держу.\"";
    str[47] = "Отчим рассказывает вам забавную историю: \"Поступил вызов к кафе. Подъехал. Мужик сажает свою жену на заднее сидение, говорит адрес, а ей что-то в стиле: \"Да дорогая я ещё здесь останусь, так что рано не жди\". - Я отъехал дальше по дороге, чтобы развернутся и, возвращаясь обратно мимо кафе, вижу что этот же мужик машет рукой, ну думаю мало ли чего забыл там. Останавливаюсь, а мужик без задней мысли садится на переднее сидение и, разговаривая по телефону, говорит в трубку \"Да я свою мымру отправил, в общем, жди меня, скоро буду\"...";
    str[48] = "Отчим рассказывает вам забавную историю: \"В какие-то длинные праздники подвозил супружескую пару. Оба пьяные - как сапожники! Ну, думаю, сейчас дадут прикурить, ан нет - тихонечко заснули на заднем сиденье. Довез их, мужик говорит, погоди, мол, жена посидит, а я тебе деньги вынесу. Я согласился, чего делать-то. Но он и правда деньги принес. У меня еще вызова четыре было, но люди садились все по одному. И вот сворачиваю к заправке... Смотрю: в зеркале заднего вида что-то мохнатое, непонятное, ворчит и ко мне тянется. Я чуть не заорал от страха! Оказалось, муж деньги-то отдал, а жену забрать забыл. Вот она со мной и каталась. Самое смешное, когда я ее домой привез, он не хотел ей дверь открывать: у меня, говорит, жена дома. Она как взвоет: \"я сейчас посмотрю, кто у тебя там жена!\"";

    str[49] = "Вы принялись помогать отчиму чинить машину, подавая ему ключи и болтики.";
    str[50] = "Вы расслабленно сидите и смеётесь, пока отчим рассказывает вам очередную смешную байку.";

    str[51] = "Повинуясь сиюминутному порыву, вы с игривой улыбкой на губах вполне естественно и ненавязчиво наклоняетесь вперёд, предоставляя отчиму вид своей груди.";
    str[52] = "<npc>- Ты чего творишь, засранка! Пошла вон отсюда, а то еще ремня заработаешь!</npc>- рассердился отчим.";
    str[53] = "Отчим явно смущён и удивлён вашей выходкой. Его красноречивое \"Кхе-кхе\" приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[54] = "<npc>- Ох...</npc> - Отчим явно не ожидал от вас такого, но по его непроизвольному выдоху и зажёгшимся глазам вы понимаете, что ему это, как минимум, весьма понравилось.";

    str[55] = "Не в силах удержаться, вы смотрите на его топорщащийся сквозь штаны член, и, не отдавая себе отчёт в своих действиях, непроизвольно начинаете одной рукой мять свою грудь.";
    str[56] = "И не стыдно тебе, Свет? Брысь с глаз моих, а то еще ремня заработаешь!";
    str[57] = "Отчим явно смущён и удивлён вашей выходкой. Его красноречивое \"Кхе-кхе\" приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[58] = "Отчим вместо ответа промычал нечто совершенно невразумительное, но по его жадному взгляду, которым он вас пожирает, и по вздыбленной ширинке вы понимаете, что эффект превзошёл все ваши ожидания.";

    str[59] = "Вы, как бы случайно, чуть-чуть раздвигаете ножки во время разговора, открывая ему взор на свою промежность.";
    str[60] = "<npc>- И не стыдно тебе, <<name[1]>>? Брысь с глаз моих, а то еще ремня заработаешь!</npc>\" - гневно говорит он.";
    str[61] = "Глаза отчима лезут на лоб когда он осознает увиденное. На вас нет трусиков, и он видит вашу нежную молодую писю. <npc>- Света, немедленно иди одень трусы.</npc> - гневно говорит он.";
    str[62] = "Отчим явно смущён и удивлён вашей выходкой. Он с трудом отрывает взгляд от ваших трусиков, что приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[63] = "Глаза отчима лезут на лоб когда он осознаёт увиденное. На вас нет трусиков, и он видит вашу нежную молодую писю. <npc>- Света, ну-ка марш к себе труселя надевать!</npc> - строго приказывает он.";
    str[64] = "Отчим прижимает вас к себе, его глаза горят желанием. В это время его руки бродят по вашим бёдрам и ягодицам. Вы сами не заметили как руки отчима отодвинули в сторону трусики и начали ласкать ваш анус.";
    str[65] = "<npc>- Света... мне показалось? Или ты не надела трусики? Раздвинь ножки пошире - папа должен убедиться...</npc> - вы раздвигаете ноги пошире, а руки отчима бесцеремонно обследуют вашу киску, неприкрытую бельем.";

    str[66] = "Повинуясь сиюминутному порыву, вы с вскриком \"Ой!\" как-бы случайно роняете деталь и наклоняетесь, чтоб поднять её, при этом не сгибая ног в коленях, что предоставляет вашему отчиму отличный обзор вашей попки.";
    str[67] = "<npc>- Ты чего творишь, засранка! Пошла вон отсюда, а то ещё ремня заработаешь!</npc>";
    str[68] = "Отчим явно смущён и удивлён вашей выходкой. Его красноречивое \"Кхе-кхе\" приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[69] = "Отчим явно смущён и удивлён вашей выходкой. Его фраза произнесеная с улыбкой: \"Светик, а трусы потерялись что ли?\" приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[70] = "<npc>- Ох...</npc> - Отчим явно не ожидал от вас такого, но по его непроизвольному выдоху и зажёгшимся глазам вы понимаете, что ему это, как минимум, весьма понравилось.";

    str[71] = "Вы вспоминаете, что своей болтовней уже исчерпали лимит терпения отчима , и решаете не рисковать";
    str[72] = "Отчим сидит на диване и смотрит телевизор. Вы присаживаетесь рядом с ним.";
    str[73] = "Состроив умильную рожицу, вы начали клянчить у отчима денег, на что он только устало покачал головой: <npc>- Нет, Света. Я тебе уже давал деньги. На сегодня хватит.</npc>";
    str[74] = "Вы попросили у отчима денег, но в ответ он только отрицательно покачал головой: <npc>- Я всю зарплату матери приношу, вот иди и у неё спрашивай.</npc>";
    str[75] = "Во время разговора вы замечаете, что отчим сегодня ведет себя немного странно";
    if(root->vEvent(fatherTouched) == 1)
        str[75] += " и вы догадываетесь почему";
    str[75] += ", так что, возможно, у вас есть шанс его уговорить...";
    str[76] = "Судя по всему, настроение у отчима не очень, может не стоит его доставать? Или стоит?";
    str[77] = "Во время разговора вы замечаете, что отчим сегодня в хорошем настроении, так что, возможно, у вас есть шанс его уговорить...";
    str[78] = "<hero>- Ну пожа-а-алуйста</hero>, - протяжно просите вы, глядя на него щенячьим взглядом и выразительно хлопая глазками.";
    str[79] = "<npc>- Нет, Света. Я же тебе уже сказал.</npc> - Судя по всему, денег от него сейчас вы явно не получите.";

    str[80] = "<hero>- Ты ничего не забыл?</hero> - спрашиваете вы, явно намекая на ваши с ним недавние \"отношения\".<br><npc>- Вот, зараза! Не можешь этим не воспользоваться теперь! Так уж и быть, на. Только рот держи на замке!</npc>";
    str[81] = "<npc>- Света, ну я же сказал, что нет у меня денег. Иди к маме.</npc>";
    str[82] = "<npc>- Вот же приставучая, эх.., ладно, держи сотню, только маме не говори!</npc> - устало говорит он, стреляя глазами в сторону кухни. Вы изображаете неподдельный восторг, берёте деньги, целуете его в щёку и с довольным видом уходите.";
    str[83] = "<npc>- Эх... Ладно. Только маме не говори!</npc> - устало говорит он, стреляя глазами в сторону кухни. Вы изображаете неподдельный восторг, берёте деньги, целуете его в щёку и с довольным видом уходите.";

    str[84] = "Отчим глядит на вас гневным взором: на вас заметна сперма.<br>- Ах ты, шлюха малолетняя, это что такое на тебе? Всем говорю, что дочь приличная, а она ебётся где-то с кем попало! Блядина! Пошла отсюда, не попадайся мне на глаза!";
    str[85] = "Отчим глядит на вас суровым взором: на вас заметна сперма.<br>- Света, я конечно всё понимаю, но не могла бы ты убирать художества своих хахалей, а не таскаться, хвастаясь этими \"орденами\", что они на тебя понавешали? Быстро приведи себя в порядок, пока мать не увидела!";

    str[86] = "Вы пытаетесь прилечь на диван рядом с отчимом, но он прогоняет вас и всячески дает понять, что ваше присутствие ему неприятно.";
    str[87] = "Вы извиняетесь перед отчимом и он, кажется, вас прощает.";
    str[88] = "Вы пытаетесь прилечь на диван рядом с отчимом, но он вам сухо отвечает, чтобы вы ему не мешали.";
    str[89] = "Вы вспоминаете, что были сегодня очень разговорчивой и решаете...";
    str[90] = "<hero> - Пап, ну не дуйся! Ну я же девочка, нам положено болтать без остановки. Ну пааап!<hero>"
              "<br><npc>- Девочка, девочка... хуевочка!</npc>, - бормочет отчим, но все таки двигается на диване, позволяя вам сесть рядом";
    str[91] = "Вы подлизываетесь к отчиму и он, кажется, начинает к вам лучше относиться.";

    str[92] = "Вы вместе около часа смотрите передачу, в которой";
    str[93] = " разные люди показывают свои таланты в надежде на денежный приз.";
    str[94] = " десяток красавиц-моделей борются за возможность пойти на свидание с красавцем-холостяком.";
    str[95] = ", якобы экстрасенсы, занимаются поиском по фотографии одной полной из дюжины пустых коробок.";
    str[96] = " ведущий в очках и еще несколько \"экспертов\" обсуждают половую жизнь какой-то девочки, которая рано забеременела.";
    str[97] = " громко орут друг на друга и лезут в драку два толстых депутата.";
    str[98] = "Вы расслабленно смеётесь, когда он рассказывает вам очередную смешную историю.";
    str[99] = "Вы сами не заметили, как телепередача начала клонить вас ко сну. Вы сонно кладете голову отчиму на грудь, что сразу же прогоняет сонливость, сменяя ее нарастающим возбуждением.";
    str[100] = "Он, не отвлекаясь от экрана, молча обнимает вас за плечи и вы дальше вместе смотрите телевизор; при этом все ваши мысли крутятся только вокруг пылающей жаром промежности.";
    str[101] = "Отчим явно не против такой тесной близости, и поощрённые таким отношением, вы совсем уж бесцеремонно закидываете на него ножку.";
    str[102] = "Чувствуя, как его рука медленно поднимается вверх по вашему телу и обхватывает вашу грудь, вы, затаив дыхание, дожидаетесь продолжения - отчим легонько сжимает и мнёт сисечку, отчего стремительно нарастает возбуждение.";
    str[103] = "Прикусив губу, вы тихо лежите на груди отчима и наслаждаетесь его ласками, прикусив губу и сдерживая шумное дыхание, норовящее перейти в стоны.";
    str[104] = "Вы чувствуете, как его рука медленно скользит по вашим бедрам и обхватывает вашу попку, крепко сжимая её в ладони. Даже немного болезненно, но возбуждение куда сильнее...";
    str[105] = "Рука отчима, не встречая никакого сопротивления, проходится вверх по вашей попе к талии, после чего ныряет под одежду и по голой коже средним пальцем скользит между ягодиц. В то время, когда вы сквозь томную пелену наслаждения начинаете понимать сексуальные предпочтения своего отчима, его палец уже вовсю массирует ваше сморщенное и подрагивающее от прикосновений колечко ануса. В такт его движениям вы, сами того не замечая, начинаете легонько вращать бедрами и внимательный отчим это замечает - давление его пальца на ваш анус растет и через несколько секунд вы понимаете, что он уже начинает проникать им внутрь.";
    str[106] = "Проскользнув под одежду, рука отчима не находит преграды в виде трусиков. На миг его рука замирает, но дальше начинает действовать с большей смелостью. Повернув вас попкой кверху, он вставляет в неё два пальца, от чего с ваших губ срывается едва слышный стон. Пальцы отчима тем временем двигаются в вашей попке, проникая всё глубже.";
    str[107] = "Вы замечаете, как его член стал заметно выпирать через одежду. Отчим, недолго думая, расстёгивает штаны и достает его, одновременно опуская вашу голову ниже.";
    str[108] = "<npc>- Света, что это там такое у тебя блестит?</npc>";
    str[109] = "<hero>- Папочка, а у меня тут есть кое-что интересненькое, хочешь увидеть?</hero> - и не дожидаясь ответа, вы стащили с себя верх одежды.";
    str[110] = "<hero>- Это мой новый пирсинг, нравится?</hero> - вы подошли впритык к отчиму, играясь пальчиками с соском прямо перед его лицом.";
    str[111] = "<npc>- Красиво смотрится</npc>, - отчим жадно рассматривает ваши проколотые соски.";
    str[112] = "<npc>- Забавно смотрится</npc>, - отчиму понравился ваш пирсинг сосков.";
    str[113] = "<npc>- Очень сексуально</npc>, - отчим легонько пощёлкивает ногтем по штангам в ваших сосках, вызывая у вас лёгкую сладкую дрожь.";
    str[114] = "<hero>- Думаю, папочке это понравится<hero>, - озорно усмехаетесь вы";
    if(root->isPanties())
        str[114] += ", приспуская трусики";
    str[115] = "Отчим ошарашено смотрит на ваш интимный пирсинг. Но так и не сказав ничего о вашей обновке, отправляет вас одеться.";
    str[116] = "Отчим, заметив блеск у вас между ног, отвесил несколько пошлых комплиментов и отправил вас одеваться.";
    str[117] = "Подойдя поближе, вы демонстрируете свой лобок отчиму. Он, заметив блеск у вас между ног, некоторое время играет с украшением, при этом отвешивая пошлые комплименты.";
    str[118] = "Вам захотелось покрасоваться перед отчимом, но ваш нынешний наряд он уже видел.";
    str[119] = "Вы просите отчима оценить ваш наряд. Он, что-то недовольно пробурчав себе под нос, отмахивается: - Не мешай, Света, я занят. Похоже, он даже не обратил внимания на вашу обновку. Обидно. Даже настроение испортилось.";
    str[120] = "Вы, кокетливо улыбнувшись отчиму, просите оценить ваш наряд.";
    str[121] = "Вы, покрутившись на месте, даёте ему оглядеть себя со всех сторон, после чего с удовлетворённым видом уходите.";
    str[122] = "Он, похоже, довольно серьезно относится к вашей просьбе и просит немного покрутиться, чтобы оглядеть ваш наряд со всех сторон. По одобрительному кивку вы поняли, что одежда пришлась ему по вкусу больше, чем он хотел вам показать.";

    str[123] = "Повинуясь сиюминутному порыву, вы с шаловливой улыбкой на губах неожиданно, как для себя самой, так и для отчима, поворачиваетесь к нему попкой и соблазнительно покачиваете бёдрами.";
    str[124] = "Отчим явно смущён и удивлён вашей выходкой. Его красноречивое \"Кхе-кхе\" приводит вас в чувство и вам становится неловко из-за своего поведения.";
    str[125] = "Проведя руками по попе, вы чуть наклоняетесь и демонстрируете ошеломленному отчиму свою голую промежность. Тяжело вздохнув и уставившись в стену, отчим вздыхает: «Света, я же не железный! Доча, иди, не сверкай передо мной голой жопой!» - вам ничего не остаётся, как подчиниться.";
    str[126] = "Не столько красуясь одеждой, сколько трусиками, выставляя попку так, чтобы отчиму было видно как можно больше, вы оглядываетесь на него: «Ну как?» - отчим, молча, смотрит на то, что скрыто трусиками, и, похоже, очень хотел бы, чтобы трусиков там не было.";
    str[127] = "От переполняющего вас возбуждения в голове что-то замкнуло, не отдавая отчёта своим действиям, не думая, что дома может кто-то быть, вы быстро сдёргиваете трусики вниз, и, прогнув спину, выставляете свою попку с голой писей отчиму на обозрение. Воровато оглянувшись на дверь в комнату, отчим судорожно начинает натягивать на вас трусы, при этом натужно выговаривая: «Светуляка, с ума сошла! А ну-ка брысь отсюда! Вдруг мама войдёт - а ты тут раскорячилась!» Стряхнув с себя наваждение, вы помогаете отчиму справиться с трусами и отходите.";
    str[128] = "Вертя задом перед отчимом вы, похоже, делаете насколько неосторожных движений, благодаря которым отчим замечает, что трусики - это не ваш любимый предмет одежды. Взяв вашу попку в ладони, отчим с нежностью жмакает ее, рассматривая открывающуюся картину. От его прикосновений пульсация внизу живота только усиливается, а пися становится влажной.";
    str[129] = "Поощрённые реакцией отчима, вы вполне естественным жестом кладете руки себе на грудь, якобы поправляя одежду. Ваши пальцы быстро пробегаются по мягкой ткани, и, не останавливаясь, скользят вниз, к животу, где, не доходя до самого сокровенного, и останавливаются. Отчим от этих довольно недвусмысленных манипуляций заметно покраснел, а его дыхание участилось; он, не сводя глаз с вашего тела, буквально пожирает вас взглядом.";
    return str[id];
}

QString Father::act(int id)
{
    QString act[50];
    act[0] = "Просить денег";
    act[1] = "Смотреть вместе телевизор";
    act[2] = "Поговорить о том что он видел";
    act[3] = "Отойти";
    act[4] = "Уйти";
    act[5] = "Ничего";
    act[6] = "Показать пирсинг языка";
    act[7] = "Далее";
    act[8] = "Просто мне понравилось";
    act[9] = "Показать татуировку на губе";
    act[10] = "Болтать";
    act[11] = "Просить прощения";
    act[12] = "Пытаться сгладить отношения";
    act[13] = "Соблазнительно нагнуться";
    act[14] = "Пялиться на его стояк";
    act[15] = "Раздвинуть ножки";
    act[16] = "Уронить деталь";
    act[17] = "...";
    act[18] = "Ну пожалуйста";
    act[19] = "Ты ничего не забыл?";
    act[20] = "Ну па-а-по-очка...";
    act[21] = "Соблазнить";
    act[22] = "Извиниться";
    act[23] = "Плюхнуться рядом";
    act[24] = "Лечь ему на грудь";
    act[25] = "Позволить ему";
    act[26] = "Спуститься на колени";
    act[27] = "Показать интимный пирсинг";
    act[28] = "Спросить, как ему наряд";
    act[29] = "Выбежать в коридор";
    act[30] = "Вертеть попкой";
    act[31] = "Поправить одежду";
    act[32] = "Дать ему потрогать ткань";
    act[33] = "Спустить трусики";
    return act[id];
}
