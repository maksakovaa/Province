#include "hanters.h"
#include "../eventhandler.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Hanters::Hanters(EventHandler* ptr): root(ptr) {}

void Hanters::start(QString arg)
{
    root->rendImagePage();
    if(root->gVEvent(hantersKnow) > 0)
    {
        if(root->getHour() == 8 || root->getHour() == 14 || root->getHour() == 19)
        {
            root->setImage(media(0));
            root->setDesc(str(0));
            if(root->gVEvent(hantersKnowSlut) > 0 && root->vStatus(horny) > 50 && !root->isMesec())
                makeActBtn("tease_hanters",act(4));
            makeActBtn("talk_hanters",act(5));
            if(root->gVQuest(hantersAndreiQW) >= 10 && root->gVQuest(hantersSergeiQW) >= 10 && root->gVQuest(hantersIgorQW) >= 10 && root->gVEvent(shootingday) != root->vStatus(daystart))
            {
                if(root->gVEvent(hantersKnowSlut) == 0)
                {
                    if(root->gVEvent(shooting) == 0)
                        makeActBtn("learn_shooting",act(6));
                    else
                        makeActBtn("ask_shooting",act(7));
                }
                else
                {
                    if(root->gVEvent(hantslutsex) == 0)
                    {
                        root->incTime(5);
                        root->sVEvent(shootingday,root->vStatus(daystart));
                        root->sVEvent(hantersexnude,1);
                        root->setImage(media(11));
                        root->setDesc(str(9));
                        makeActBtn("hanters",act(8));
                    }
                    else
                    {
                        root->incTime(5);
                        root->sVEvent(shootingday,root->vStatus(daystart));
                        root->setImage(media(11));
                        root->setDesc(str(10));
                        makeActBtn("swamp_yard",act(0));
                    }
                }
            }
        }
        else
        {
            root->setImage(media(getRandInt(1,9)));
            root->setDesc(str(1));
            makeActBtn("AndreiHanter",act(14));
            makeActBtn("SergeiHanter",act(15));
            makeActBtn("IgorHanter",act(16));
        }
    }
    else
    {
        root->setImage(media(0));
        root->setDesc(str(2));
        makeActBtn("become_acquainted",act(1));
    }
    makeActBtn("swamp_yard",act(0));

    //действия если ГГ шлюха в Гадюкино
    if(root->gVEvent(hantersRape) == 3)
    {
        root->incTime(5);
        root->sVEvent(hantersKnowSlut,1);
        resetCounters();
        if(root->gVEvent(hantersAndreisex) == 0)
        {
            root->sVEvent(hantersAndreisex,1);
            root->uVSex(guy,1);
        }
        if(root->gVEvent(hantersSergeisex) == 0)
        {
            root->sVEvent(hantersSergeisex,1);
            root->uVSex(guy,1);
        }
        if(root->gVEvent(hantersIgorsex) == 0)
        {
            root->sVEvent(hantersIgorsex,1);
            root->uVSex(guy,1);
        }
        if(root->gVEvent(hantersIgorLove) == 1)
        {
            root->sVEvent(hantersIgorLove,0);
            root->uVQuest(hantersIgorQW,-100);
        }
        if(root->gVEvent(hantersIgorLove) == 2)
        {
            root->sVEvent(hantersIgorLove,0);
            root->uVQuest(hantersIgorQW,-100);
            //bFa = 0
        }
        if(root->gVEvent(hantersIgorLove) == 3)
        {
            root->sVEvent(hantersIgorLove,0);
            root->uVQuest(hantersIgorQW,-100);
            //husband = 0 & divorced += 1 & husbandMark = 0 & husbharmin = 0 & husbizvradd = 0
        }
        if(root->gVEvent(hantersSergeiLove) == 1)
        {
            root->sVEvent(hantersSergeiLove,0);
            root->uVQuest(hantersSergeiQW,-100);
        }
        if(root->gVEvent(hantersAndreiLove) == 1)
        {
            root->sVEvent(hantersAndreiLove,0);
            root->uVQuest(hantersAndreiQW,-100);
        }
        root->setImage(media(19));
        root->setDesc(str(29));
        makeActBtn("agree_serve_0",act(17));
        makeActBtn("disagree_serve_0",act(18));
    }

    //если ГГ согласилась отсосать после стриптиза и последующего секса
    if(root->gVEvent(hantdanceslut) == 2)
    {
        root->incTime(1);
        root->sVEvent(hantdanceslut,4);
        root->sVEvent(hantersRape,5);
        root->uVSkill(domination,-1);
        resetCounters();
        root->setImage(media(19));
        root->setDesc(str(46));
        makeActBtn("danceSlutSuck1",act(10));
    }

    //если ГГ сотказалась отсосать после стриптиза и последующего секса
    if(root->gVEvent(hantdanceslut) == 3)
    {
        root->incTime(1);
        root->uVSkill(domination,1);
        root->sVEvent(hantdanceslut,4);
        resetCounters();
        root->setImage(media(48));
        root->setDesc(str(50));
        makeActBtn("danceSlutExit",act(0));
    }

    //секс если ГГ голая перед охотниками
    if(sexHanters() || sexGopGuys())
    {
        root->rendImagePage();
        root->incTime(1);
        root->uVSC(blowJob,3);
        root->uVEvent(hantslutsex,getRandInt(3,6));
        root->uVSC(gangBang,1);
        root->uVSkill(domination,-1);
        resetCounters();
        if(sexHanters())
        {
            if(root->gVEvent(hantersAndreisex) == 0)
            {
                root->sVEvent(hantersAndreisex,1);
                root->uVSex(guy,1);
            }
            if(root->gVEvent(hantersSergeisex) == 0)
            {
                root->sVEvent(hantersSergeisex,1);
                root->uVSex(guy,1);
            }
            if(root->gVEvent(hantersIgorsex) == 0)
            {
                root->sVEvent(hantersIgorsex,1);
                root->uVSex(guy,1);
            }
        }

        if(sexHanters())
        {
            root->setImage(media(10));
            root->setDesc(str(52));
        }
        else if(sexGopGuys())
            root->setImage(media(49));
        root->addDesc(str(53));
        hantsexa = getRandInt(1,3);
        hantsexb = getRandInt(1,3);
        if(hantsexa < 3) makeActBtn("groupORALasi",act(10));
        if(hantsexa == 3 && hantsexb == 1) makeActBtn("groupORALsi",act(10));
        if(hantsexa == 3 && hantsexb == 2) makeActBtn("groupORALai",act(10));
        if(hantsexa == 3 && hantsexb == 3) makeActBtn("groupORALas",act(10));
    }

    //секс если ГГ шлюха
    if(root->gVEvent(slutgosex) == 1 || root->gVEvent(forest_hantersex) == 1 || root->gVEvent(forest_gopsex) == 1)
    {
        root->incTime(5);
        root->uVSkill(domination,-1);
        resetCounters();
        root->uVEvent(hantslutsex,getRandInt(3,6));
        if(root->gVEvent(slutgosex) == 1 || root->gVEvent(forest_hantersex) == 1)
            root->sVStatus(clothesbackwater,1);
        if(root->gVEvent(forest_gopsex) == 1)
            root->sVStatus(clothesforest,1);
        root->redress(ClothType::Main,nullptr);

        if(root->gVEvent(temphant) == 1)
        {
            if(root->gVEvent(hantersAndreisex) == 0)
            {
                root->sVEvent(hantersAndreisex,1);
                root->uVSex(guy,1);
            }
            setAndrei();
        }
        if(root->gVEvent(temphant) == 2)
        {
            if(root->gVEvent(hantersSergeisex) == 0)
            {
                root->sVEvent(hantersSergeisex,1);
                root->uVSex(guy,1);
            }
            setSergei();
        }
        if(root->gVEvent(temphant) == 3)
        {
            if(root->gVEvent(hantersIgorsex) == 0)
            {
                root->sVEvent(hantersIgorsex,1);
                root->uVSex(guy,1);
            }
            setIgor();
        }
        if(root->gVEvent(temphant) == 4)
            setMitka();
        if(root->gVEvent(temphant) == 5)
            setKolyamba();
        if(root->gVEvent(temphant) == 6)
            setVasyan();
        root->setImage(media(50));
        root->setDesc(str(57));
        makeActBtn("slutSTART",act(23));
    }
}

void Hanters::actionHandler(QString action)
{
    if(action == "become_acquainted")
    {
        root->incTime(5);
        root->sVEvent(hantersKnow,1);
        root->uVQuest(hantersAndreiQW,1);
        root->uVQuest(hantersIgorQW,1);
        root->uVQuest(hantersSergeiQW,1);
        root->setImage(media(10));
        root->setDesc(str(3));
        if(root->vStatus(vnesh) >= 40) root->addDesc(str(4));
        if(root->vStatus(vnesh) < 40) root->addDesc(str(5));
        root->addDesc(str(6));
        if(root->gVEvent(gadriver_gang) == 0)
            root->addDesc(str(7));
        else
        {
            root->addDesc(str(8));
            root->sVEvent(hantersKnowSlut,1);
            root->sVEvent(hantersRape,1);
        }
        makeActBtn("hanters",act(2));
        makeActBtn("swamp_yard",act(3));
    }

    if(action == "tease_hanters")
    {
        root->uVStatus(horny,5);
        root->incTime(5);
        if(root->gVEvent(hantersAndreisex) == 0)
        {
            root->sVEvent(hantersAndreisex,1);
            root->uVSex(guy,1);
        }
        if(root->gVEvent(hantersSergeisex) == 0)
        {
            root->sVEvent(hantersSergeisex,1);
            root->uVSex(guy,1);
        }
        if(root->gVEvent(hantersIgorsex) == 0)
        {
            root->sVEvent(hantersIgorsex,1);
            root->uVSex(guy,1);
        }
        root->setImage(media(10));
        root->setDesc(str(11));
        makeActBtn("tease_hanters_next",act(9));
    }
    if(action == "tease_hanters_next")
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->uVStatus(horny,5);
        root->setImage(media(12));
        root->setDesc(str(12));
        makeActBtn("tease_hanters_next2",act(9));
    }
    if(action == "tease_hanters_next2")
    {
        root->incTime(1);
        root->uVStatus(horny,5);
        root->uVSC(blowJob,1);
        hantsexa = getRandInt(1,3);
        hantsexb = getRandInt(1,3);
        root->sVEvent(hantslutsex,getRandInt(9,12));
        root->setImage(media(13));
        root->setDesc(str(13));
        if(hantsexa < 3) makeActBtn("groupORALasi",act(10));
        if(hantsexa == 3 && hantsexb == 1) makeActBtn("groupORALsi",act(10));
        if(hantsexa == 3 && hantsexb == 2) makeActBtn("groupORALai",act(10));
        if(hantsexa == 3 && hantsexb == 3) makeActBtn("groupORALas",act(10));
    }

    if(action == "talk_hanters")
    {
        root->incTime(getRandInt(30,90));
        root->uVStatus(mood,getRandInt(10,20));
        if(root->gVQuest(hantersAndreiQW) < 10) root->uVQuest(hantersAndreiQW,1);
        if(root->gVQuest(hantersIgorQW) < 10) root->uVQuest(hantersIgorQW,1);
        if(root->gVQuest(hantersSergeiQW) < 10) root->uVQuest(hantersSergeiQW,1);
        if(root->isSkirt() && !root->isPanties())
        {
            if(root->gVEvent(hantersKnowSlut) > 0)
                root->uVEvent(hanterslut,1);
            root->uVStatus(horny,getRandInt(10,20));
            root->setImage(media(14));
            root->setDesc(str(14));
        }
        else
        {
            root->setImage(media(10));
            root->setDesc(str(15));
            hanters_talk();
            root->addDesc(str(16));
        }
        makeActBtn("swamp_yard",act(3));
    }

    if(action == "learn_shooting")
    {
        root->incTime(5);
        root->sVEvent(shootingday,root->vStatus(daystart));
        root->setImage(media(11));
        root->setDesc(str(17));
        if(root->vStatus(vnesh) >= 40)
        {
            root->sVEvent(shooting,1);
            if(root->gVQuest(hantersAndreiQW) < 20) root->uVQuest(hantersAndreiQW,1);
            if(root->gVQuest(hantersIgorQW) < 20) root->uVQuest(hantersIgorQW,1);
            if(root->gVQuest(hantersSergeiQW) < 20) root->uVQuest(hantersSergeiQW,1);
            root->addDesc(str(18));
        }
        if(root->vStatus(vnesh) < 40)
        {
            root->uVQuest(hantersAndreiQW,-1);
            root->uVQuest(hantersIgorQW,-1);
            root->uVQuest(hantersSergeiQW,-1);
            root->addDesc(str(19));
        }
        if(root->gVEvent(shooting) == 1)
            makeActBtn("go_shoot",act(11));
        else
            makeActBtn("swamp_yard",act(0));
    }
    if(action == "go_shoot")
    {
        root->incTime(30);
        root->setImage(media(15));
        root->setDesc(str(20));
        makeActBtn("shoot",act(12));
    }
    if(action == "shoot")
    {
        root->incTime(1);
        root->uVEvent(shoot,1);
        root->setImage(media(16));
        root->setDesc(str(21));
        makeActBtn("groupfaint",act(13));
    }
    if(action == "ask_shooting")
    {
        root->incTime(5);
        root->sVEvent(shootingday,root->vStatus(daystart));
        root->setImage(media(11));
        root->setDesc(str(22));
        if(root->gVEvent(shooting) == 1) root->addDesc(str(23));
        if(root->gVEvent(shooting) == 1) root->addDesc(str(24));
        if(root->gVEvent(shooting) == 1) root->addDesc(str(25));
        if(root->gVEvent(shooting) >= 1 && root->gVEvent(shooting) <= 10)
            makeActBtn("go_shoot2",act(11));
        else
            makeActBtn("go_shoot3",act(11));
    }
    if(action == "go_shoot2")
    {
        int tmp = getRandInt(1,2);
        if((root->vSkill(strenght) + root->gVEvent(shooting) > 20) || (root->vSkill(strenght) + root->gVEvent(shooting) < 20 && tmp == 1))
        {
            root->incTime(60);
            root->uVEvent(shoot,1);
            root->setImage(media(17));
            root->setDesc(str(26));
            makeActBtn("swamp_yard",act(9));
        }
        else
        {
            root->incTime(5);
            root->uVEvent(shoot,1);
            root->setImage(media(16));
            root->setDesc(str(27));
            makeActBtn("after_bad_shoot2",act(9));
        }
    }
    if(action == "after_bad_shoot2")
    {
        root->incTime(1);
        root->setImage(media(18));
        root->setDesc(str(28));
        makeActBtn("swamp_yard",act(9));
    }
    if(action == "go_shoot3")
    {
        root->incTime(60);
        root->uVEvent(shoot,1);
        root->setImage(media(17));
        root->setDesc(str(26));
        makeActBtn("swamp_yard",act(9));
    }

    if(action == "agree_serve_0")
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->sVEvent(hantersRape,5);
        root->uVSkill(domination,-2);
        root->setImage(media(12));
        root->setDesc(str(12));
        makeActBtn("agree_serve_01",act(9));
    }
    if(action == "agree_serve_01")
    {
        root->incTime(1);
        root->uVSC(blowJob,3);
        hantsexa = getRandInt(1,3);
        hantsexb = getRandInt(1,3);
        root->uVEvent(hantslutsex,getRandInt(9,12));
        root->sVEvent(hantersexnude,1);
        root->setImage(media(13));
        root->setDesc(str(13));
        if(hantsexa < 3) makeActBtn("groupORALasi",act(10));
        if(hantsexa == 3 && hantsexb == 1) makeActBtn("groupORALsi",act(10));
        if(hantsexa == 3 && hantsexb == 2) makeActBtn("groupORALai",act(10));
        if(hantsexa == 3 && hantsexb == 3) makeActBtn("groupORALas",act(10));
    }
    if(action == "disagree_serve_0")
    {
        root->incTime(5);
        root->setImage(media(20));
        root->setDesc(str(30));
        makeActBtn("agree_serve_1",act(17));
        makeActBtn("disagree_serve_1",act(19));
    }
    if(action == "agree_serve_1")
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->sVEvent(hantersRape,5);
        root->uVSkill(domination,-1);
        root->setImage(media(21));
        root->setDesc(str(31));
        makeActBtn("agree_serve_11",act(20));
        root->setDesc(str(32));
    }
    if(action == "agree_serve_11")
    {
        root->incTime(5);
        root->setImage(media(getRandInt(22,24)));
        makeActBtn("agree_serve_01",act(9));
    }
    if(action == "disagree_serve_1")
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->uVSC(raped,1);
        root->sVEvent(hantersRape,4);
        root->uVSkill(domination,1);
        root->setImage(media(25));
        root->setDesc(str(33));
        makeActBtn("disagree_serve_11",act(9));
    }
    if(action == "disagree_serve_11")
    {
        root->incTime(5);
        root->setImage(media(26));
        root->setDesc(str(34));
        makeActBtn("disagree_serve_12",act(9));
    }
    if(action == "disagree_serve_12")
    {
        root->incTime(5);
        root->setImage(media(27));
        root->setDesc(str(35));
        root->setBoyName(str(36));
        root->sVSex(silavag,0);
        root->sVSex(dick,20);
        root->blow_job();
        root->addDesc(str(39));
        makeActBtn("disagree_serve_13",act(9));
    }
    if(action == "disagree_serve_13")
    {
        root->incTime(5);
        root->setImage(media(28));
        root->setDesc(str(40));
        makeActBtn("disagree_serve_14",act(9));
    }
    if(action == "disagree_serve_14")
    {
        root->incTime(5);
        root->setImage(media(29));
        root->setDesc(str(41));
        makeActBtn("disagree_serve_15",act(9));
    }
    if(action == "disagree_serve_15")
    {
        root->incTime(5);
        root->setImage(media(30));
        root->setDesc(str(42));
        makeActBtn("disagree_serve_16",act(9));
    }
    if(action == "disagree_serve_16")
    {
        root->incTime(5);
        root->setImage(media(31));
        root->setDesc(str(43));
        makeActBtn("disagree_serve_17",act(9));
    }
    if(action == "disagree_serve_17")
    {
        root->incTime(5);
        root->setImage(media(33));
        root->setDesc(str(44));
        makeActBtn("disagree_serve_18",act(9));
    }
    if(action == "disagree_serve_18")
    {
        root->incTime(1);
        root->uVSC(blowJob,3);
        hantsexa = getRandInt(1,3);
        hantsexb = getRandInt(1,3);
        root->uVEvent(hantslutsex,getRandInt(9,12));
        root->sVEvent(hantersexnude,1);
        root->setImage(media(32));
        root->setDesc(str(45));
        makeActBtn("groupORALasi",act(10));
    }

    if(action == "danceSlutSuck1")
    {
        root->incTime(15);
        root->uVStatus(horny,getRandInt(10,20));
        root->setImage(media(40));
        root->setDesc(str(47));
        setAndrei();
        root->blow_job();
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
        makeActBtn("danceSlutSuck1next",act(21));
    }
    if(action == "danceSlutSuck1next")
    {
        root->incTime(1);
        root->uVSkill(domination,-1);
        root->uVSC(blowJob,3);
        root->cum("face");
        root->sVEvent(hantersKnowSlut,2);
        if(root->isNude())
            root->cum("belly");
        if(root->isCloth())
            root->uVStatus(cumFrot,getRandInt(0,1));
        root->uVEvent(hantslutsex,getRandInt(9,12));
        root->setImage(media(43));
        root->setDesc(str(48));
        makeActBtn("beSurprised",act(22));
    }
    if(action == "beSurprised")
    {
        root->incTime(5);
        root->setImage(media(45));
        root->setDesc(str(49));
        makeActBtn("back_to_loc",act(9));
    }

    if(action == "danceSlutExit")
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->uVSC(raped,1);
        root->sVEvent(hantersRape,4);
        root->setImage(media(25));
        root->setDesc(str(51));
        makeActBtn("danceSlutExitNext",act(9));
    }
    if(action == "danceSlutExitNext")
    {
        root->incTime(5);
        root->setImage(media(27));
        root->setDesc(str(35));
        setAndrei();
        root->blow_job();
        root->addDesc(str(39));
        makeActBtn("disagree_serve_13",act(9));
    }

    if(action == "wakeup1")
    {
        root->incTime(10);
        root->sVStatus(health,100);
        root->uVStatus(mood,10);
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        root->sVEvent(slutgosex,0);
        root->setImage(media(52));
        root->setDesc(str(60));
        makeActBtn("back_to_loc",act(9));
    }
    if(action == "wakeup2")
    {
        root->incTime(10);
        root->sVStatus(health,100);
        root->uVStatus(mood,10);
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        root->sVEvent(slutgosex,0);
        root->setImage(media(53));
        root->setDesc(str(61));
        makeActBtn("swamphouse",act(9));
    }

//Dynamic
    if(action == "hanters_talk") hanters_talk();

    if(action == "groupfaint") groupfaint();
    if(action == "groupORALend1") groupORALend1();
    if(action == "groupORALs") groupORALs();
    if(action == "groupORALs1") groupORALs1();
    if(action == "groupORALs1end") groupORALs1end();
    if(action == "groupORALa1end") groupORALa1end();
    if(action == "groupORALi") groupORALi();
    if(action == "groupORALi1") groupORALi1();
    if(action == "groupORALi1end") groupORALi1end();
    if(action == "groupORALai") groupORALai();
    if(action == "groupORALai1") groupORALai1();
    if(action == "groupORALas") groupORALas();
    if(action == "groupORALsi") groupORALsi();
    if(action == "groupORALsi1") groupORALsi1();
    if(action == "groupORALasi") groupORALasi();

    if(action == "groupOis") groupOis();
    if(action == "groupOia") groupOia();
    if(action == "groupOsa") groupOsa();
    if(action == "groupOsend") groupOsend();
    if(action == "groupOaend") groupOaend();
    if(action == "groupOiend") groupOiend();

    if(action == "groupAsOa") groupAsOa();
    if(action == "groupAsO") groupAsO();
    if(action == "groupAOa") groupAOa();
    if(action == "groupAa") groupAa();
    if(action == "groupAaEnd1") groupAaEnd1();
    if(action == "groupAaEnd2") groupAaEnd2();
    if(action == "groupAs") groupAs();
    if(action == "groupAsEnd1") groupAsEnd1();
    if(action == "groupAsEnd2") groupAsEnd2();
    if(action == "groupAi") groupAi();
    if(action == "groupAiEnd1") groupAiEnd1();
    if(action == "groupAiEnd2") groupAiEnd2();

    if(action == "groupVa") groupVa();
    if(action == "groupVa1") groupVa1();
    if(action == "groupVa2") groupVa2();
    if(action == "groupVa2end") groupVa2end();
    if(action == "groupVas") groupVas();
    if(action == "groupVas1") groupVas1();
    if(action == "groupVi") groupVi();
    if(action == "groupVi1") groupVi1();
    if(action == "groupVi2") groupVi2();
    if(action == "groupVi3") groupVi3();
    if(action == "groupVi3end") groupVi3end();
    if(action == "groupVia") groupVia();
    if(action == "groupVia1") groupVia1();
    if(action == "groupVis") groupVis();
    if(action == "groupVis1") groupVis1();
    if(action == "groupVias") groupVias();
    if(action == "groupVs") groupVs();
    if(action == "groupVs1") groupVs1();
    if(action == "groupVs2") groupVs2();
    if(action == "groupVs2end") groupVs2end();

    if(action == "groupVaOsHi") groupVaOsHi();
    if(action == "groupVOsHi") groupVOsHi();
    if(action == "groupVaOHi") groupVaOHi();
    if(action == "groupVsOaHi") groupVsOaHi();
    if(action == "groupVsOHi") groupVsOHi();
    if(action == "groupVsOi") groupVsOi();
    if(action == "groupVOi") groupVOi();
    if(action == "groupVsO") groupVsO();
    if(action == "groupVOaHi") groupVOaHi();
    if(action == "groupViOa") groupViOa();
    if(action == "groupViO") groupViO();
    if(action == "groupVaOs") groupVaOs();
    if(action == "groupVOs") groupVOs();
    if(action == "groupVaO") groupVaO();

    if(action == "groupDPasi") groupDPasi();
    if(action == "groupDPsi") groupDPsi();
    if(action == "groupDPas") groupDPas();
    if(action == "groupDPai") groupDPai();
    if(action == "groupDPis") groupDPis();
    if(action == "groupDPia") groupDPia();

    if(action == "slutSTART") slutSTART();
    if(action == "slutEND") slutEND();
    if(action == "slutORAL") slutORAL();
    if(action == "slutCOW") slutCOW();
    if(action == "slutHANDS") slutHANDS();
    if(action == "slutTREE") slutTREE();
    if(action == "slutTREELEG") slutTREELEG();
    if(action == "slutLEG1") slutLEG1();
    if(action == "slutLEG2") slutLEG2();
//Navigation
    if(action == "exit1")
    {
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        actionHandler("back_to_loc");
    }
    if(action == "exit2")
    {
        root->sVEvent(forest_hantersex,0);
        root->incTime(60);
        root->changeLoc(lswampyard);
    }
    if(action == "exit3")
    {
        root->sVEvent(slutgosex,0);
        root->changeLoc(lbackwater);
    }
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "swamp_yard")
        root->changeLoc(lswampyard);
    if(action == "swamphouse")
        root->changeLoc(lswamphouse);
    if(action == "hanters")
        root->eventStart("hanters");
    if(action == "AndreiHanter")
        root->eventStart("AndreiHanter");
    if(action == "SergeiHanter")
        root->eventStart("SergeiHanter");
    if(action == "IgorHanter")
        root->eventStart("IgorHanter");
}

void Hanters::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Hanters::actionHandler);
    root->addActBtn(btn);
}

void Hanters::groupfaint()
{
    root->incTime(1);
    root->uVStatus(horny,getRandInt(5,10));
    root->setImage(media(51));
    if(root->gVEvent(shooting) == 1)
    {
        root->sVEvent(shooting,2);
        root->setDesc(str(58));
    }
    else
        root->setDesc(str(59));
    if(root->gVEvent(hantersRape) == 4 || root->gVEvent(hantdanceslut) == 4 || root->gVEvent(forest_gopsex) == 1)
        makeActBtn("wakeup1",act(24));
    else
        makeActBtn("wakeup2",act(24));

}

void Hanters::groupORALend1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->setImage(media(65));
    if(sexHanters())
    {
        root->setDesc(str(63));
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(64));
        setVasyan();
        root->blow_job();
        setKolyamba();
    }
    root->cum("face");
    root->blow_job();
    root->fnswallow();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->cum("face");
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(69));
    if(sexGopGuys())
        root->addDesc(str(70));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupORALa1end()
{
    root->sVSex(pose,0);
    root->incTime(5);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->setImage(media(getRandInt(66,67)));
    root->setDesc(str(68));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(67));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupORALi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(68));
    if(sexHanters())
    {
        root->setDesc(str(63));
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(64));
        setVasyan();
        root->blow_job();
        setKolyamba();
    }
    root->blow_job();
    root->fnswallow();
    root->setDesc(str(62));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupORALi1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(69));
    root->setDesc(str(71));
    if(sexHanters())
    {
        setIgor();
        root->blow_job();
        setAndrei();
    }
    if(sexGopGuys())
    {
        setVasyan();
        root->blow_job();
        setMitka();
    }
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(72));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupORALi1end()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->setImage(media(getRandInt(66,67)));
    root->setDesc(str(68));
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(67));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupORALs()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(61));
    if(sexHanters())
    {
        root->setDesc(str(63));
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(64));
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    root->fnswallow();
    root->setDesc(str(62));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupORALs1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(62,63)));
    if(sexHanters())
    {
        root->setDesc(str(65));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(66));
        setKolyamba();
    }
    root->blow_job();
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupORALs1end()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->setImage(media(64));
    if(sexHanters())
    {
        root->setDesc(str(65));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(66));
        setKolyamba();
    }
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(67));
    makeActBtn("back_to_loc",act(9));
}
void Hanters::groupORALai()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny, getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(54,57)));
    root->setDesc(str(47));
    if(sexHanters())
    {
        setAndrei();
        root->blow_job();
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(sexGopGuys())
    {
        setMitka();
        root->blow_job();
        setVasyan();
        root->blow_job();
        setKolyamba();
    }
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(62));
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupORALai1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny, getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(70,73)));
    root->setDesc(str(71));
    if(sexHanters())
    {
        setAndrei();
        root->blow_job();
        setIgor();
    }
    if(sexGopGuys())
    {
        setMitka();
        root->blow_job();
        setVasyan();
    }
    root->blow_job();
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupORALas()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny, getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(54,57)));
    root->setDesc(str(47));
    if(sexHanters())
    {
        setAndrei();
        root->blow_job();
        setSergei();
        root->blow_job();
        setIgor();
    }
    if(sexGopGuys())
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
        setVasyan();
    }
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(62));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupORALsi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(54,57)));
    root->setDesc(str(47));
    if(sexHanters())
    {
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
        setAndrei();
    }
    if(sexGopGuys())
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
        setMitka();
    }
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(62));
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupORALsi1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(58,60)));
    if(sexHanters())
    {
        root->setDesc(str(63));
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(64));
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupORALasi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->uVSex(lubonus,3);
    root->setImage(media(getRandInt(34,42)));
    root->setDesc(str(47));
    if(sexHanters())
    {
        setAndrei();
        root->blow_job();
        setSergei();
        root->blow_job();
        setIgor();
    }
    if(sexGopGuys())
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
        setVasyan();
    }
    root->blow_job();
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    actions6();
}

void Hanters::groupOis()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->cum("face");
    root->setImage(media(getRandInt(43,44)));
    root->setDesc(str(133));
    if(root->gVEvent(forest_hantersex) == 0)
    {
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        makeActBtn("back_to_loc",act(9));
    }
    if(root->gVEvent(forest_hantersex) > 0)
    {
        makeActBtn("exit2",act(9));
    }
}
void Hanters::groupOia()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->cum("face");
    root->setImage(media(getRandInt(43,44)));
    root->setDesc(str(134));
    if(root->gVEvent(forest_hantersex) == 0)
    {
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        makeActBtn("back_to_loc",act(9));
    }
    if(root->gVEvent(forest_hantersex) > 0)
    {
        makeActBtn("exit2",act(9));
    }
}
void Hanters::groupOsa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->cum("face");
    if(root->isNude()) root->cum("belly");
    if(root->isCloth()) root->uVStatus(cumFrot, getRandInt(0,1));
    root->setImage(media(getRandInt(43,44)));
    root->setDesc(str(135));
    if(root->gVEvent(forest_hantersex) == 0)
    {
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        makeActBtn("back_to_loc",act(9));
    }
    if(root->gVEvent(forest_hantersex) > 0)
    {
        makeActBtn("exit2",act(9));
    }
}
void Hanters::groupOsend()
{
    root->sVSex(pose,0);
    root->incTime(5);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->cum("face");
    if(root->isNude()) root->cum("belly");
    if(root->isCloth()) root->uVStatus(cumFrot,getRandInt(0,1));
    root->setImage(media(getRandInt(144,146)));
    root->setDesc(str(140));
    root->blow_job();
    root->addDesc(str(141));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupOaend()
{
    root->sVSex(pose,0);
    root->incTime(5);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->cum("face");
    if(root->isNude()) root->cum("belly");
    if(root->isCloth()) root->uVStatus(cumFrot,getRandInt(0,1));
    root->setImage(media(getRandInt(144,146)));
    root->setDesc(str(140));
    root->blow_job();
    root->addDesc(str(141));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupOiend()
{
    root->sVSex(pose,0);
    root->incTime(5);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->cum("face");
    if(root->isNude()) root->cum("belly");
    if(root->isCloth()) root->uVStatus(cumFrot,getRandInt(0,1));
    root->setImage(media(getRandInt(144,146)));
    root->setDesc(str(140));
    root->blow_job();
    root->addDesc(str(141));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}

void Hanters::groupAsOa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(128));
    if(sexHanters())
    {
        root->setDesc(str(125));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(126));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupAsO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(129));
    if(sexHanters())
    {
        root->setDesc(str(125));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(126));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(127));
    if(sexGopGuys())
        root->addDesc(str(128));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupAOa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(130));
    if(sexHanters())
    {
        root->setDesc(str(125));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(126));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->uVSex(lubonus,getRandInt(2,3));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}
void Hanters::groupAa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsexAnal();
    root->setImage(media(getRandInt(133,137)));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}
void Hanters::groupAaEnd1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsexAnal();
    root->setImage(media(138));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupAaEnd2()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsexAnal();
    root->setImage(media(139));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(137));
    root->cum("ass");
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupAs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->setImage(media(getRandInt(133,137)));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupAsEnd1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->setImage(media(138));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupAsEnd2()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsexAnal();
    root->setImage(media(140));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(137));
    root->cum("ass");
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupAi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsexAnal();
    root->setImage(media(getRandInt(133,137)));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupAiEnd1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsexAnal();
    root->setImage(media(138));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupAiEnd2()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsexAnal();
    root->setImage(media(139));
    root->setDesc(str(136));
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(137));
    root->cum("ass");
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}

void Hanters::groupVa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(85));
    if(sexHanters())
    {
        root->setDesc(str(75));
        setSergei();
        root->blow_job();
        setAndrei();
        root->vaginal(tDick);
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(76));
        setKolyamba();
        root->blow_job();
        setMitka();
        root->vaginal(tDick);
        setKolyamba();
    }
    root->fnswallow();
    root->addDesc(str(77));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}
void Hanters::groupVa1()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(86));
    if(sexHanters())
    {
        root->setDesc(str(90));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(91));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    if(sexHanters())
        root->addDesc(str(94));
    if(sexGopGuys())
        root->addDesc(str(95));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}
void Hanters::groupVa2()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->setImage(media(getRandInt(141,142)));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}
void Hanters::groupVa2end()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->setImage(media(143));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(139));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupVas()
{
    root->sVSex(pose,2);
    root->incTime(5);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(79));
    if(sexHanters())
    {
        root->setDesc(str(73));
        setSergei();
        root->blow_job();
        setAndrei();
        root->blow_job();
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(74));
        setKolyamba();
        root->blow_job();
        setMitka();
        root->blow_job();
        setVasyan();
    }
    checkBoyCsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupVas1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(80,84)));
    if(sexHanters())
    {
        root->setDesc(str(75));
        setSergei();
        root->blow_job();
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(76));
        setKolyamba();
        root->blow_job();
        setMitka();
    }
    checkBoyAsex();
    root->vaginal(tDick);
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupVi()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(89));
    if(sexHanters())
    {
        root->setDesc(str(73));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(74));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->cum("face");
    root->fnswallow();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->cum("face");
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(79));
    if(sexGopGuys())
        root->addDesc(str(80));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVi1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(90));
    if(sexHanters())
    {
        root->setDesc(str(83));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(84));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(85));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVi2()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(91));
    if(sexHanters())
    {
        root->setDesc(str(90));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(91));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->fnswallow();
    if(sexHanters())
        root->setDesc(str(92));
    if(sexGopGuys())
        root->setDesc(str(93));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVi3()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->setImage(media(getRandInt(141,142)));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVi3end()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->setImage(media(143));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(139));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}
void Hanters::groupVia()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(98));
    if(sexHanters())
    {
        root->setDesc(str(73));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(74));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->cum("face");
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(88));
    if(sexGopGuys())
        root->addDesc(str(89));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupVia1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(99,101)));
    if(sexHanters())
    {
        root->setDesc(str(90));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(91));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupVis()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(92));
    if(sexHanters())
    {
        root->setDesc(str(73));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(74));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(81));
    if(sexGopGuys())
        root->addDesc(str(82));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupVis1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(93,97)));
    if(sexHanters())
    {
        root->setDesc(str(83));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(84));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();

}
void Hanters::groupVias()
{
    root->sVSex(pose,2);
    root->incTime(5);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(74,78)));
    if(sexHanters())
    {
        root->setDesc(str(73));
        setSergei();
        root->blow_job();
        setAndrei();
        root->blow_job();
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(74));
        setKolyamba();
        root->blow_job();
        setMitka();
        root->blow_job();
        setVasyan();
    }
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions6();
}
void Hanters::groupVs()
{
    root->sVSex(pose,2);
    root->incTime(5);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(87));
    if(sexHanters())
    {
        root->setDesc(str(75));
        setSergei();
        root->blow_job();
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(76));
        setKolyamba();
        root->blow_job();
        setMitka();
    }
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(78));
    actions2();
}
void Hanters::groupVs1()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(88));
    if(sexHanters())
    {
        root->setDesc(str(83));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(84));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(86));
    if(sexGopGuys())
        root->addDesc(str(87));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupVs2()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->setImage(media(getRandInt(141,142)));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupVs2end()
{
    root->incTime(5);
    root->sVSex(pose,2);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->setImage(media(143));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(139));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("exit1",act(9));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit2",act(9));
}

void Hanters::groupVaOsHi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(102,105)));
    if(sexHanters())
    {
        root->setDesc(str(96));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(97));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions6();
}
void Hanters::groupVOsHi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(104));
    if(sexHanters())
    {
        root->setDesc(str(96));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(97));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupVaOHi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(106));
    if(sexHanters())
    {
        root->setDesc(str(96));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(97));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(98));
    if(sexGopGuys())
        root->addDesc(str(99));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupVsOaHi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(112,113)));
    if(sexHanters())
    {
        root->setDesc(str(106));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(107));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(sexHanters())
        root->addDesc(str(108));
    if(sexGopGuys())
        root->addDesc(str(109));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions6();
}
void Hanters::groupVsOHi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(getRandInt(112,113)));
    if(sexHanters())
    {
        root->setDesc(str(106));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(107));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(110));
    if(sexGopGuys())
        root->addDesc(str(111));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupVsOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(114,116)));
    if(sexHanters())
    {
        root->setDesc(str(112));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(113));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupVOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(117));
    if(sexHanters())
    {
        root->setDesc(str(112));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(113));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVsO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(118));
    if(sexHanters())
    {
        root->setDesc(str(112));
        setIgor();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(113));
        setVasyan();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(114));
    if(sexGopGuys())
        root->addDesc(str(115));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupVOaHi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(112,113)));
    if(sexHanters())
    {
        root->setDesc(str(116));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(117));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupViOa()
{
    root->incTime(5);
    root->sVSex(pose,0);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(119,120)));
    if(sexHanters())
    {
        root->setDesc(str(118));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(119));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupViO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(121));
    if(sexHanters())
    {
        root->setDesc(str(118));
        setAndrei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(119));
        setMitka();
    }
    root->blow_job();
    if(sexHanters())
        setIgor();
    if(sexGopGuys())
        setVasyan();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    root->fnswallow();
    root->addDesc(str(120));
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions1();
}
void Hanters::groupVaOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(122,125)));
    if(sexHanters())
    {
        root->setDesc(str(121));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(122));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupVOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(126));
    if(sexHanters())
    {
        root->setDesc(str(121));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(122));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    hantsexa = getRandInt(2,4);
    hantsexb = getRandInt(1,8);
    actions2();
}
void Hanters::groupVaO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(127));
    if(sexHanters())
    {
        root->setDesc(str(121));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(122));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
        setAndrei();
    if(sexGopGuys())
        setMitka();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(123));
    if(sexGopGuys())
        root->addDesc(str(124));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions7();
}

void Hanters::groupDPasi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(107,108)));
    if(sexHanters())
    {
        root->setDesc(str(100));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(101));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
    {
        setAndrei();
        setIgor2();
    }
    if(sexGopGuys())
    {
        setMitka();
        setVasyan2();
    }
    checkBoyAsex();
    checkBoyCsexAnal();
    root->dp_start();
    root->double_penetration();
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions6();
}
void Hanters::groupDPsi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(110));
    if(sexHanters())
    {
        root->setDesc(str(100));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(101));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
    {
        setAndrei();
        setIgor2();
    }
    if(sexGopGuys())
    {
        setMitka();
        setVasyan2();
    }
    checkBoyAsex();
    checkBoyCsexAnal();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    root->sex_cum();
    root->setDesc(str(102));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupDPas()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(111));
    if(sexHanters())
    {
        root->setDesc(str(100));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(101));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
    {
        setAndrei();
        setIgor2();
    }
    if(sexGopGuys())
    {
        setMitka();
        setVasyan2();
    }
    checkBoyAsex();
    checkBoyCsexAnal();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    root->addDesc(str(103));
    root->uVSex(lubonus,getRandInt(2,3));
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    actions4();
}
void Hanters::groupDPai()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(110));
    if(sexHanters())
    {
        root->setDesc(str(100));
        setSergei();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(101));
        setKolyamba();
    }
    root->blow_job();
    if(sexHanters())
    {
        setAndrei();
        setIgor2();
    }
    if(sexGopGuys())
    {
        setMitka();
        setVasyan2();
    }
    checkBoyAsex();
    checkBoyCsexAnal();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    if(sexHanters())
        setSergei();
    if(sexGopGuys())
        setKolyamba();
    root->fnswallow();
    if(sexHanters())
        root->addDesc(str(104));
    if(sexGopGuys())
        root->addDesc(str(105));
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}
void Hanters::groupDPis()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(131));
    if(sexHanters())
    {
        root->setDesc(str(129));
        setIgor();
        setSergei2();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(130));
        setVasyan();
        setKolyamba2();
    }
    checkBoyCsex();
    checkBoyBsexAnal();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions5();
}
void Hanters::groupDPia()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(132));
    if(sexHanters())
    {
        root->setDesc(str(131));
        setIgor();
        setAndrei2();
    }
    if(sexGopGuys())
    {
        root->setDesc(str(132));
        setVasyan();
        setMitka2();
    }
    checkBoyCsex();
    checkBoyAsexAnal();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    actions3();
}

void Hanters::slutSTART()
{
    root->sVSex(pose,0);
    root->incTime(5);
    resetCounters();
    root->uVStatus(horny,getRandInt(5,10));
    int tmp = getRandInt(1,2);
    if(tmp == 1)
    {
        root->setImage(media(147));
        root->setDesc(str(142));
    }
    else
    {
        root->setImage(media(148));
        root->setDesc(str(143));
    }
    makeActBtn("slutORAL",act(10));
}
void Hanters::slutEND()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->setImage(media(149));
    if(root->vSex(protect) == 1) root->setDesc(str(144));
    if(root->vSex(protect) == 0) root->setDesc(str(145));
    makeActBtn("slutMASTR",act(31));
}
void Hanters::slutORAL()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVSC(blowJob,1);
    root->uVStatus(horny,getRandInt(5,10));
    root->setImage(media(getRandInt(152,153)));
    root->setDesc(str(147));
    root->blow_job();
    hantsexa = getRandInt(1,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(148));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::slutCOW()
{
    root->incTime(5);
    root->sVSex(pose,0);
    checkBoyAsex();
    root->setImage(media(getRandInt(154,157)));
    root->setDesc(str(138));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::slutHANDS()
{
    root->sVSex(pose,0);
    root->incTime(5);
    checkBoyAsex();
    root->setImage(media(getRandInt(158,159)));
    root->setDesc(str(151));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::slutTREE()
{
    root->sVSex(pose,1);
    root->incTime(5);
    checkBoyAsex();
    root->setImage(media(getRandInt(160,162)));
    root->setDesc(str(152));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));

}
void Hanters::slutTREELEG()
{
    root->sVSex(pose,1);
    root->incTime(5);
    checkBoyAsex();
    root->setImage(media(getRandInt(163,166)));
    root->setDesc(str(153));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));

}
void Hanters::slutLEG1()
{
    root->sVSex(pose,1);
    root->incTime(5);
    checkBoyAsex();
    root->setImage(media(getRandInt(167,168)));
    root->setDesc(str(154));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::slutLEG2()
{
    root->sVSex(pose,1);
    root->incTime(5);
    checkBoyAsex();
    root->setImage(media(getRandInt(169,170)));
    root->setDesc(str(155));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa <= 7) root->addDesc(str(150));
        if(hantsexa > 7) root->addDesc(str(149));
        if(hantsexa == 1) makeActBtn("slutORAL",act(21));
        if(hantsexa == 2) makeActBtn("slutCOW",act(27));
        if(hantsexa == 3) makeActBtn("slutHANDS",act(32));
        if(hantsexa == 4) makeActBtn("slutTREE",act(33));
        if(hantsexa == 5) makeActBtn("slutTREELEG",act(34));
        if(hantsexa == 6) makeActBtn("slutLEG1",act(35));
        if(hantsexa == 7) makeActBtn("slutLEG2",act(36));
        if(hantsexa > 7) makeActBtn("slutEND",act(30));
    }
    else
        makeActBtn("groupfaint",act(13));
}

void Hanters::hanters_talk()
{
    int tmp = getRandInt(156,191);
    root->addDesc(str(tmp));
    if(tmp == 167 || tmp == 171 || tmp == 172 || tmp == 173 || tmp == 176 || tmp == 181 || tmp == 183 || tmp == 187)
        root->uVStatus(horny,getRandInt(5,20));
}

QString Hanters::str(int id)
{
    QString str[192];
    if(id < 20)
    {
        str[0] = "Расположившись на поляне возле избушки три охотника, Сергей, Игорь и Андрей расказывают друг другу всякие охотничьи байки.";
        str[1] = "На поляне возле избушки три охотника, Сергей, Игорь и Андрей, занимаются своими делами.";
        str[2] = "На поляне возле избушки вы видите трех незнакомых мужчин которые расказывают друг другу всякие охотничьи байки.";
        str[3] = "Вы подошли поближе и вежливо поздороваливались. Мужчины прервав разговор ответили тем же.";
        str[4] = "<npc>- Как звать-величать тебя, красавица?</npc> - спросил один из них.";
        str[5] = "<npc>- Как звать-величать то тебя?</npc> - спросил один из них.";
        str[6] = "<hero>- Света,</hero> - ответили вы.";
        str[7] = "<npc>- А я Андрей,</npc> - ответил ответил мужчина постарше, <npc>- а это друзья мои из центра, Игорь и Сергей.</npc>"
                 "<npc>- А твоя фамилия не Лебедева случайно?</npc> - спросил он. Вы удивленно посмотрели на него и кивнули."
                 "<npc>- Не удивляйся Света, ты очень похожа на маму в молодости. А я её... Хммм... очень хорошо знал когда-то, я ведь тоже из Гадюкино,</npc> - сказал Андрей."
                 "<npc>- Да ты не стесняйся, присаживайся, в ногах правды нет,</npc> - сказал Сергей, освобождая для вас место.";
        str[8] = "<npc>- Ба, кого к нам занесло,</npc> - удивлённо протянул мужчина постарше, <npc>- это же Света Лебедева, местная шлюшка.</npc>"
                 "Вы удивленно посмотрели на него."
                 "<npc>- Не удивляйся, я ведь тоже из Гадюкино, а ты очень похожа на маму в молодости, и судя по всему такая же блядоватая,</npc> - сказал он."
                 "<npc>- Я Андрей,</npc> - добавил он дальше, <npc>- а это друзья мои из центра, Игорь и Сергей.</npc>"
                 "<npc>- Да ты иди сюда, присаживайся, мы дяди добрые, не кусаемся,</npc> - сказал Сергей, освобождая для вас место.";
        str[9] = "<hero>- Ребята, дайте из ружья стрелять,</hero> - попросили вы парней, сидя на поляне."
                 "<npc>- Светик, харэ херней страдать,</npc> - ответил Андрей. <npc>- Иди-ка лучше к нам,делом займись.</npc>";
        str[10] = "<hero>- Ребята, дайте из ружья стрелять,</hero> - попросили вы парней, сидя на поляне."
                  "<npc>- Светик, харэ херней страдать,</npc> - ответил Андрей. <npc>- У тебя другие таланты.</npc>"
                  "И засмеялся, довольный своей шуткой.";
        str[11] = "Вы парням строите глазки и делаете недвусмысленные намеки. Парни сразу заинтересовались...<br>"
                  "<npc>- Светик у нас ненасытная прямо,</npc> - сказал Андрей улыбаясь. <npc>- Я рад, что мы не разачаровались в тебе.</npc>";
        str[12] = "Растелив покрывало, ребята взяли вас под руки и подвели к нему, раздевая на ходу...";
        str[13] = "Стянув с вас трусики, парни растегнув ширинки и дастав уже вставшие члены обступили вас.";
        str[14] = "Вы сидите напротив парней, забыв, что не одели трусики, поэтому рассказы у них получаются сбившимися и большую часть времени они искоса поглядывают на вашу голую письку, сверкающую из под юбки.";
        str[15] = "Вы подсев к парням стали слушать их охотничьи байки и расказывая им свои истории.";
        str[16] = "За разговорами время пролетело незаметно.";
        str[17] = "<hero>- Ребята, а научите меня из ружья стрелять,</hero> - попросили вы парней, сидя на поляне."
                  "<npc>- Светик , ну зачем тебе это? Ты же девочка,</npc> - сказал Андрей улыбаясь. <npc>- Тебе шитьем бы увлекаться, спортом, ну или еще не знаю чем. Стрельба это для мальчиков хобби.</npc>"
                  "<hero>- Ну пожааааалуйста,</hero> - захлопали вы глазками, сделав невинное личико.";
        str[18] = "<npc>- Все, все, Светик, сдаемся,</npc> - со смехом сказал Анрей. <npc>- Уговорила, научим мы тебя стрелять.</npc>";
        str[19] = "<npc>- Нет, Светик, не получится,</npc> - ответил сказал Анрей. <npc>- И не хлопай глазками, на нас это не действует.</npc><br><hero>- Ну и ладно,</hero> - надули вы губки и обиженно отвернулись. <hero>- Злые вы, уйду я от вас.</hero>";
    }
    if(id >= 20 && id < 40)
    {
        str[20] = "Ребята вам долго объясняли, как нужно целиться, как лержать ружьё и прижимать приклад. В итоге вы решили, что готовы и решили сделать...";
        str[21] = "Все произошло не так как вы себе представляли и ожидали. Раздался ужасный гром, что-то больно ударило вас по лбу...";
        str[22] = "<hero>- Ребята, дайте из ружья по стрелять,</hero> - попросили вы парней, сидя на поляне, испульзуя проверенный, обезаруживающий взгляд.";
        str[23] = "<npc>- Хорошо, Светик, только смотри не как в первый раз,</npc> - сказал Андрей улыбаясь.";
        str[24] = "<npc>- Хорошо, Светик, только смотри осторожно,</npc> - сказал Андрей улыбаясь.";
        str[25] = "<npc>- Хорошо, Светик, только не увлекайся сильно, патроны не казенные,</npc> - сказал Андрей улыбаясь.";
        str[26] = "Целый час под присмотром парней вы палили из ружья.";
        str[27] = "Все произошло не так как в первый раз. Выстрел, удар в лоб, трава перед глазами..."
                  "<npc>- Света, ты там как, живая?</npc> - спросил Игорь с тревогой в голосе."
                  "<hero>- Вроде да,</hero> - ответили вы, держась за ушибленный лоб и морщась."
                  "<npc>- Это хорошо,</npc> - сказал Андрей смеясь. <npc>- Иди отдохни, Рэмбо ты наш.</npc>";
        str[28] = "<hero>- Я не Рэмбо, я Лара Крофт,</hero> - ответили вы Андрею, и показав на последок язык ушли.";
        str[29] = "Вы не успели толком расслабится, как неожиданно вас обступили парни-охотники."
                  "<npc>- Слыш, Светик,</npc> - сказал один из них. <npc>- Мы тут подумали, раз уж ты всем даешь, может и нас обслужишь?</npc>";
        str[30] = "Вы решили отказаться и начали их отталкивать, но парней такой вариант явно не устраивал."
                  "<npc>- Света, давай не выебывайся,</npc> - сказал Андрей, схватив вас за волосы.";
        str[31] = "Растелив покрывало, ребята схватив крепко вас под руки, чтобы вы и не подумали больше перечить, повели к нему...";
        str[32] = "Пока вас вели, руки ребят гуляли по всему вашему телу, ощупывая каждый сантиметр...";
        str[33] = "Вы принялись отчаянно сопротивляться, но тут же получили оплеуху от Андрея, аж в ушах зазвенело...";
        str[34] = "Он вас схватил за одежду и начал валить на землю...";
        str[35] = "Оказавшись на земле, вы увидели перед глазами члеми Андрея. Мотнув головой вы попытались отстранится, но он крепко зажав вашу голову, насильно засунул его вам в рот."
                  "<npc>- Соси, сука,</npc> - услышали сквозь слёзы вы. <npc>- И не дай бог укусишь, живьем закопаю!</npc>";
        str[36] = "Андрей";
        str[37] = "Игорь";
        str[38] = "Сергей";
        str[39] = "Сергей в это время, пользуясь вашей беспомощностью, оттянул полоску трусиков в сторону и начал орудовать пальцами в вашей писе."
                  "Игорь же схватив вас за руку притянул её к своему члену и вам ничего не оставалось как начать двигать вверх вниз.";
    }
    if(id >= 40 && id < 60)
    {
        str[40] = "Наигравшись таким образов парни схватили вас за руки и ноги и понесли на поляну перед избушкой.";
        str[41] = "Там вас поставили на ноги, заломав руки, чтобы присечь попытки к сопротивлению, пока Игорь не растелил покрывало...";
        str[42] = "Растелив покрывало, вас бросили на него и стянули трусики...";
        str[43] = "Пока Сергей с Игорем держали ваши руки и мяли ваши груди, Андрей принялся ощупывать вашу писю...";
        str[44] = "Он засунул в неё пальцы и принялся разрабатывать, вам оставалось только наблюдать, подрачивая члены Сергей с Игорем, которые они всунули вам в руки...";
        str[45] = "Наконец он вынул из вас свои пальцы и парни став вокруг вас поднесли свои члены к вашему лицу.<br><npc>- Ну Света, приступим,</npc> - сказал Андрей.";
        str[46] = "Парни подошли к вам и окружили со всех сторон.";
        str[47] = "Вы принялись сосать, поочередно уделяя внимание каждому члену.";
        str[48] = "Через пару минут парни, кончили вам на лицо и отошли в сторону."
                  "<npc>- Вот видишь Света,</npc> - бросил отходя Андрей. <npc>- Теперь ты и сама понимаешь кто ты.</npc>"
                  "<npc>- И кстати, Светик,</npc> - обернулся, чуть отойдя он. <npc>- Ты не расстраивайся и не обижайся, ничего страшного в этом нет.</npc>";
        str[49] = "<hero>- Как нет?</hero> - чуть не плача спросили вы. <hero>- Вы только, что сделали из меня шлюху.</hero>"
                  "<npc>- Светик, пойми, ты была такой всегда, просто это до поры, до времени скрывалось от тебя,</npc> - сказал Андрей. <npc>- И уж лучше, что это выяснилось здесь, с нами. Мы по крайней мере никому не расскажем. А ты , зная свою сущность, сможешь лучше контролировать себя.</npc>"
                  "<hero>- Ты так считаешь?</hero> - уже веселее спросили вы."
                  "<npc>- Конечно!</npc> - ответил он. <npc>- Ты любишь секс, мы любим секс, так зачем же нам стесняться в нашем узком кругу.</npc>"
                  "<npc>- Да и чем черт не шутит, может и в жизни пригодится такой опыт,</npc> - добавил Андрей, задумчиво почесав подбородок.";
        str[50] = "<hero>- Да пошел ты!</hero> - вы показали Андрею средний палец и развернулись, что бы уйти.";
        str[51] = "<npc>- Ты совсем охуела тварь?!!!</npc> - услышали вы за спиной голос Андрея. Он схватил вас на волосы и повалил на землю."
                  "Вы принялись отчаянно сопротивляться, но тут же получили оплеуху от Андрея, аж в ушах зазвенело...";
        str[52] = "Вы подошли к парням с игривой улыбкой...";
        str[53] = "<npc>- Ты знаешь, что делать Светик,</npc> - сказал один из парней улыбаясь. <npc>- Приступай.</npc>";
        str[54] = "Митька";
        str[55] = "Колямба";
        str[56] = "Васян";
        str[57] = "Вы ушли с парнем с поляны под деревья. Он тут же принялся вас раздевать.<br><npc>- Ты знаешь, что делать Светик,</npc> - сказал парень улыбаясь. <npc>- Приступай.</npc>";
        str[58] = "От боли в глазах у вас потемнело, мир закружился и вы потеряли сознание...";
        str[59] = "Вдруг от нестерпимой боли в глазах у вас потемнело, мир закружился и вы потеряли сознание...";
    }
    if(id >= 60 && id < 80)
    {
        str[60] = "Вы очнулись от потока воды, вылившегося на вас..."
                  "<npc>- Ну что, Света, живая?</npc> - спросил " + root->getBoyName() + " убедившись, что вы пришли в себя."
                  "Вы слабо качнули головой."
                  "<npc>- Ну и ладно,</npc> - сказал он и отошел в сторону.";
        str[61] = "Вы очнулись от легкого похлопывания по щекам..."
                  "<npc>- Ну что, Светик, ты как, живая?</npc> - спросил " + root->getBoyName() + " убедившись, что вы пришли в себя."
                  "Вы слабо качнули головой."
                  "<npc>- Напугала ты нас, признаться, пиздец,</npc> - сказал он и отошел в сторону. <npc>- Иди в избушку, отдохни.</npc>";
        str[62] = root->getBoyName() + " кончил и отошел в сторону с блаженной улыбкой на лице.";
        str[63] = "Вы принялись сосать Сергею и Игорю, поочередно уделяя внимание каждому члену.";
        str[64] = "Вы принялись сосать Колямбе и Васяну, поочередно уделяя внимание каждому члену.";
        str[65] = "Вы принялись сосать Сергею. Он взяв вас за голову просто насаживал на свой член...";
        str[66] = "Вы принялись сосать Колямбе. Он взяв вас за голову просто насаживал на свой член...";
        str[67] = root->getBoyName() + " кончил и отошел с довольной улыбкой на лице и вы остались на покрывале в одиночестве...";
        str[68] = "Вы стали на колени. " + root->getBoyName() + " взяв вас за голову просто насаживал на свой член....";
        str[69] = "Спермы оказалось так много, что вы не сумели всю проглотить и часть осталась на вашем лице. Сергей с Игорем отошли в сторону, оставив вас сидеть на покрывале.";
        str[70] = "Спермы оказалось так много, что вы не сумели всю проглотить и часть осталась на вашем лице. Колямба с Васяном отошли в сторону, оставив вас сидеть на покрывале...";
        str[71] = "Вы принялись сосать, пытаясь взять сразу два члена в рот одновременно.";
        str[72] = root->getBoyName() + " со вздохом кончил и отошел в сторону.";
        str[73] = "Игорь лёг на землю, потянув вас за собой. Андрей и Сергей стали перед вами выставив свои члены перед вашим лицом.";
        str[74] = "Васян лёг на землю, потянув вас за собой. Митька и Колямба стали перед вами выставив свои члены перед вашим лицом.";
        str[75] = "Андрей поставил вас на четвереньки и начал пристраиваться сзади, Сергей подошел спереди...";
        str[76] = "Митька поставил вас на четвереньки и начал пристраиваться сзади, Колямба подошел спереди...";
        str[77] = root->getBoyName() + " кончил и отошел в сторону.. ";
        str[78] = root->getBoyName() + " кончил и отвалил отдыхать.";
        str[79] = "Спермы оказалось так много, что вы не сумели всю проглотить и стряхнув остатки вам на лицо Андрей с Сергеем довольные отошли в сторону, а вы продолжили скакать на Игоре...";
    }
    if(id >= 80 && id < 100)
    {
        str[80] = "Спермы оказалось так много, что вы не сумели всю проглотить и стряхнув остатки вам на лицо Митька с Колямбой довольные отошли в сторону, а вы продолжили скакать на Васяне...";
        str[81] = "Удовлетворённый Андрей отошел в сторону, а вы продолжили скакать на Игоре, отсасывая у Сергея...";
        str[82] = "Удовлетворённый Митька отошел в сторону, а вы продолжили скакать на Васяне, отсасывая у Колямбы...";
        str[83] = "Сергей поставил вас на четвереньки и начал пристраиваться сзади, Игорь поднес член к вашему лицу...";
        str[84] = "Колямба поставил вас на четвереньки и начал пристраиваться сзади, Васян поднес член к вашему лицу...";
        str[85] = root->getBoyName() + " кончил и отправился отдыхать в тенек...";
        str[86] = "Игорь кончил и отвалил, а вы продолжили с Сергеем...";
        str[87] = "Васян кончил и отвалил, а вы продолжили с Колямбой...";
        str[88] = "Спермы оказалось так много, что вы не сумели всю проглотить и часть размазалась по вашему лицу. Удовлетворённый Сергей отошел в сторону, а вы продолжили скакать на Игоре, отсасывая у Андрея...";
        str[89] = "Спермы оказалось так много, что вы не сумели всю проглотить и часть размазалась по вашему лицу. Удовлетворённый Колямба отошел в сторону, а вы продолжили скакать на Васяне, отсасывая у Митьки...";
        str[90] = "Игорь поставил вас раком и начал пристраиваться сзади, Андрей поднес член к вашему лицу...";
        str[91] = "Васян поставил вас раком и начал пристраиваться сзади, Митька поднес член к вашему лицу...";
        str[92] = "Удовлетворённый Андрей отошел в сторону, а вы продолжили раскачиваться в такт размеренных движений Игоря...";
        str[93] = "Удовлетворённый Митька отошел в сторону, а вы продолжили раскачиваться в такт размеренных движений Васяна...";
        str[94] = "Удовлетворённый Игорь отошел в сторону, а вы продолжили с Андреем...";
        str[95] = "Удовлетворённый Васян отошел в сторону, а вы продолжили с Митькой...";
        str[96] = "Андрей поставил вас на четвереньки и начал пристраиваться сзади, Сергей подошел спереди, а вы в это время взяв в руку член Игоря начали надрачивать его...";
        str[97] = "Митька поставил вас на четвереньки и начал пристраиваться сзади, Колямба подошел спереди, а вы в это время взяв в руку член Васяна начали надрачивать его...";
        str[98] = "Удовлетворённый Сергей отошел в сторону, а вы продолжили раскачиваться под толками Андрея и дроча Игорю...";
        str[99] = "Удовлетворённый Колямба отошел в сторону, а вы продолжили раскачиваться под толками Митьки и дроча Васяну...";
    }
    if(id >= 100 && id < 120)
    {
        str[100] = "Андрей лёг на землю, потянув вас за собой, Игорь сразу же начал пристраиваться к вашей второй дырочке, вам остается лишь расслабиться и сосать член Сергея...";
        str[101] = "Митька лёг на землю, потянув вас за собой, Васян сразу же начал пристраиваться к вашей второй дырочке, вам остается лишь расслабиться и сосать член Колямбы...";
        str[102] = root->getBoyName() + " кончил и ушел...";
        str[103] = "Через некоторое время " + root->getBoyName() + " застонал и вы почувствовали как вашу попу наполняет тепло. Он кончил и отошел в сторону.";
        str[104] = "Удовлетворённый Сергей отошел в сторону, а Андрей с Игорем продолжили вас драть...";
        str[105] = "Удовлетворённый Колямба отошел в сторону, а Митька с Васяном продолжили вас драть...";
        str[106] = "Сергей положил вас на бок и вы уткнулись лицом в член Андрея...";
        str[107] = "Колямба положил вас на бок и вы уткнулись лицом в член Митьки...";
        str[108] = "Протянув руку вверх вы нащупали член Игоря и начали его дрочить...";
        str[109] = "Протянув руку вверх вы нащупали член Васяна и начали его дрочить...";
        str[110] = "Удовлетворённый Андрей отошел в сторону, а вы продолжили с Сергеем и Игорем...";
        str[111] = "Удовлетворённый Митька отошел в сторону, а вы продолжили с Колямбой и Васяном...";
        str[112] = "Сергей положил вас на бок, а Игорь поднес член к вашим губам";
        str[113] = "Колямба положил вас на бок, а Васян поднес член к вашим губам...";
        str[114] = "Удовлетворённый Игорь отошел в сторону, а вы продолжили с Сергеем";
        str[115] = "Удовлетворённый Васян отошел в сторону, а вы продолжили с Колямбой...";
        str[116] = "Сергей положил вас на бок и вы уткнулись лицом в член Андрея. Протянув руку вверх вы нащупали член Игоря и начали его дрочить.";
        str[117] = "Колямба положил вас на бок и вы уткнулись лицом в член Митьки. Протянув руку вверх вы нащупали член Васяна и начали его дрочить.";
        str[118] = "Игорь положил вас на бок и вы уткнулись лицом в член Андрея...";
        str[119] = "Васян положил вас на бок и вы уткнулись лицом в член Митьки...";
    }
    if(id >= 120 && id < 140)
    {
        str[120] = "Удовлетворённый " + root->getBoyName() + " отошел в сторону, а вы продолжили со вторым парнем...";
        str[121] = "Андрей положил вас на живот и растянул ваши руки, а Сергей поднес член к вашим губам...";
        str[122] = "Митька положил вас на живот и растянул ваши руки, а Колямба поднес член к вашим губам...";
        str[123] = "Удовлетворённый Сергей отошел в сторону, а Андрей продолжил вас драть...";
        str[124] = "Удовлетворённый Колямба отошел в сторону, а Андрей продолжил вас драть...";
        str[125] = "Сергей поставил вас на четвереньки и начал пристраиваться сзади, Андрей подошел спереди...";
        str[126] = "Колямба поставил вас на четвереньки и начал пристраиваться сзади, Митька подошел спереди...";
        str[127] = "Удовлетворённый Андрей отошел в сторону, а Сергей продолжил натягивать ваш зад...";
        str[128] = "Удовлетворённый Митька отошел в сторону, а Колямба продолжил натягивать ваш зад...";
        str[129] = "Игорь лёг на землю, потянув вас за собой, Сергей сразу же начал пристраиватться к вашей второй дырочке";
        str[130] = "Васян лёг на землю, потянув вас за собой, Колямба сразу же начал пристраиватться к вашей второй дырочке...";
        str[131] = "Игорь лёг на землю, потянув вас за собой, Андрей сразу же начал пристраиваться к вашей второй дырочке...";
        str[132] = "Васян лёг на землю, потянув вас за собой, Митька сразу же начал пристраиваться к вашей второй дырочке...";
        str[133] = "Парни поставили вас на колени и принялись дрочить перед вашим лицом пока струи спермы ударили вам в лицо. Кончив они отошли в сторону, а вы остались на покрывале обтекать.";
        str[134] = "Парни поставили вас на колени и принялись дрочить перед вашим лицом пока струи спермы ударили вам в лицо. Обкончав вас они отошли в сторону, а вы остались сидеть на покрывале переводить дух.";
        str[135] = "Парни поставили вас на колени и принялись дрочить. Вскоре струи спермы ударили вам в лицо, она стекала по подбородку, капая вниз. Кончив они отошли в сторону, а вы остались сидеть на покрывале.";
        str[136] = root->getBoyName() + " поставил вас на четвереньки и начал пристраиваться к вашей попе...";
        str[137] = "Через некоторое время " + root->getBoyName() + " застонал и вы почувствовали как член покинул вашу попу и следом на неё брызнули струи спермы. " + root->getBoyName() + " отошел в сторону оставив вас одну на покрывале...";
        str[138] = root->getBoyName() + " лег на землю и потянул вас за собой...";
        str[139] = root->getBoyName() + " отошел в сторону оставив вас одну на покрывале...";
    }
    if(id >= 140 && id < 156)
    {
        str[140] = root->getBoyName() + " поставил вас на колени и поднес член к лицу...";
        str[141] = "Вы почувствовали как " + root->getBoyName() + " напрягся и тут же вытащил член из вашего рта. Горячая струя спермы ударяет вас по лицу, потом еще одна струя и еще. Она стекает по подбородку, капая вниз, а " + root->getBoyName() + " убрал член в штаны и отошел в сторону.";
        str[142] = "Вы опустились на корточки, взяли член в руки, поднесли к губам и поцеловав головку принялись...";
        str[143] = "Вы опустились на корточки, взяли член в руки, поднесли к губам и облизав головку принялись...";
        str[144] = root->getBoyName() + " выкинув использованый презерватив, посадил вас перед собой на корточки. Вы, подразнивая и облизывая головку члена языком, принялись дрочить...";
        str[145] = "Вы опустились на колени. Взяв член в руку, вы принялись дрочить, подразнивая и облизывая головку члена языком...";
        str[146] = "Спермы оказалось слишком много. Она стекает по подбородку, капая вниз и пачкая вашу грудь и живот. " + root->getBoyName() + " убрал член в штаны и пошел по своим делам, оставив вас одну, приводить себя в порядок.";
        str[147] = "Вы стоя на корточках, взяли член в руку и поднесли его к губам...";
        str[148] = "Прервав вас, парень говорит...";
        str[149] = "Внезапно " + root->getBoyName() + " начал двигаться быстрее и вы поняли что он уже на грани и готов кончить.";
        str[150] = "Вдоволь насладившись в этой позе " + root->getBoyName() + " говорит вам...";
        str[151] = root->getBoyName() + " взял вас в свои крепкие руки и резко вошел в вас.";
        str[152] = "Вы повернулись к дереву и оперлись о него рукой, " + root->getBoyName() + " пристроился сзади...";
        str[153] = "Вы повернулись к дереву и оперлись о него рукой, " + root->getBoyName() + " приподнял вашу ногу для удобства и вошел в вас...";
        str[154] = "Вы повернулись задом к парню и обняли его за шею, <<$boy>> приподнял вашу ногу для удобства и вошел в вас...";
        str[155] = "Вы, стоя на ногах, повернулись к парню лицом и обняли его за шею, " + root->getBoyName() + " приподнял вашу ногу для удобства и вошел в вас...";
    }
    if(id >= 156)
    {
        str[156] = "<npc>— Какая разница между собакой и лисицей?</npc> — <npc>\"2 стакана водки!\"</npc>";
        str[157] = "<npc>\"Такса\" – это такая охотничья собака примерно половина собаки в высоту и полтора в длину.</npc>";
        str[158] = "<npc>Пошли мы как-то на охоту. Все взяли: ружья, патроны, собаку, соленые огурцы. А водку забыли. Пришлось возвращаться.</npc>";
        str[159] = "<npc>Собрались мужики на охоту, да вот беда, одного жена не пускает, мол, знаю я вашу охоту, нажрётесь как свиньи и на бровях "
                   "домой приползёте... Вот, мол, возьмёте с собой, тогда можно. Посовещались мужики и решили взять - что-нибудь по ходу придумают.."
                    "Приехали в лес, нашли полянку подходящую, дали жене двустволку и говорят:"
                    "- Ты тут в кустах сиди, а мы пойдём лося загонять. Будем гнать прямо на тебя, а ты смотри не промахнись, а то весь труд на смарку пойдёт..."
                    "Оставили её, а сами в свой шалашик потопали водку кушать. Очнулись, когда уже луна светила... Муж схватился за голову, мол "
                   "что с ним жена сделает и решили пойти сдаваться."
                    "Пришли на поляну и видят такую картину: в центре лужайки лежит туша, вокруг неё с ружьём на плече вышагивает женщина, а рядом "
                   "стоит незнакомый мужичок, потирает лысину."
                    "- Это мой лось, это я его убила!!!"
                    "- Да твой это лось, твой. Дай только седло сниму.</npc>";
        str[160] = "<npc>Слyжил в кpаях далёких, на подводной лодке командиp, котоpый очень любил постpелять. Даже в дальние походы с собой винтовкy "
                   "бpал. Hy мало ли, y беpега всплывyт, так какyю дичь заметит с капитанского мостика, так всё пpистpелить ноpовит. Видать, папа "
                   "y него был сибиpский охотник, белке в глаз бил без пpомаха. Hадо сказать, что капитан этот стpелял тоже неплохо. Так вот, всплыли"
                   " они как-то y скалистого pодного беpега, не знаю yж по какой пpичине, только заметил вдpyг капитан со своего мостика, что на yтёсе"
                   " олень стоит, да так кpасиво, гоpдый такой, одинокий, на фоне хмypого севеpного неба. Пpинесли кэпy винтовкy, он тщательно пpицелился,"
                   " все свободные от вахты сбежались посмотpеть на это пpедставление, ставки делать стали, попадёт или нет... Раздаётся выстpел, олень"
                   " как подкошенный падает с обpыва в водy, за ним следом летят наpты с чyкчей... Коpоткая немая сцена... Сpочное погpyжение!!!!!!!</npc>";
        str[161] = "<npc>Приехал депутат на охоту на медведя. Джип - хамер, камуфляж, супер навороченный автомат с оптическим прицелом ночного виденья..."
                   " Заходит в лес, навстречу мужичок в лаптях, в ушанке, в телогрейке - типичный деревенский мужик."
                   "Мужик: - О, мил человек, куда путь держишь?"
                   "Депутат: - На медведя!"
                   "Мужик: - Да неблагодарное это занятие... Медведь - ХОЗЯИН! На него мой дед с рогатиной ходил, отец с рогатиной ходил..."
                   "Депутат: - Да ты смотри! Автомат - хоть слона вали... Оптика, пули со стальным сердечником..."
                   "И уходит в лес."
                   "Мужик:- Да, (затягивается махоркой) теперь в лес вообще не стоит ходить... У медведя теперь не только две рогатины, а и автомат еще будет...</npc>";
        str[162] = "<npc>После выстрела по дичи охотник просит напарника:"
                   "- Сходи, посмотри, что за зверя я уложил."
                   "Тот возвращается:"
                   "- Судя по паспорту, его фамилия Иванов.</npc>";
        str[163] = "<npc>Стоят два гриба в лесу - Белый и Мухомор. Видят грибника."
                    "Белый: - Все, сейчас резня начнется!!!"
                    "Мухомор: - Не знаю, как на счет резни, но по шапке сапогом точно кто-то получит!</npc>";
        str[164] = "<npc>Охотники:"
                   "- В Антарктиде я одним выстрелом убил кита."
                   "- А я на Северном полюсе своими руками задушил медведя."
                   "- А ты когда-нибудь слышал о Мертвом море?"
                   "- Кто же не слышал?"
                   "- Так это я его...</npc>";
        str[165] = "<npc>Выхожу я как из дому. Смотрю прям на моем телефонном столбе"
                   "Орел сидит. Ну я вскидываю ружье, целюсь, Ба-Бах, Баx-Бах."
                                "Попал. Со столба. Когти в одну сторону, плоскогубцы и пасатижи в другую.</npc>";
        str[166] = "<npc>Если во время охоты вы ни в кого не попали, значит, в лесу стало одним косым больше.</npc>";
        str[167] = "<npc>Встретились три охотника и обсуждают достоинства своих собак."
                   "Первый: - Пошел я один раз на охоту - ружье взял, а патроны забыл. Дал собаке понюхать ружье - она патроны принесла!"
                   "Второй: - Пошел я один раз на охоту - патроны взял, а ружье забыл. Дал собаке понюхать патроны - она ружье принесла!!"
                   "Третий: - А я как-то пошел с женой купаться, а она купальник забыла. Дал собаке у жены промеж ног понюхать - она соседа за яйца притащила!!!</npc>";
        str[168] = "<npc>Мужик возражается с охоты довольный. Жена:"
                   "- Как охота?"
                   "- Класс! Ежей целую гору настрелял!"
                   "- Ты что совсем ебнулся? На хуй они нужны!"
                   "- Ну как же. Тебе на воротник, теще на стельки.</npc>";
        str[169] = "<npc>Встречаются два зайца. Один белый и пушистый, а второй перебинтован от лапок до ушей."
                   "- Первый спрашивает: - на охоте?"
                   "- На охоте... - отвечает второй."
                   "- Охотник?"
                   "- Охотник."
                   "- Подстрелил?!"
                   "- Не..., наступил.</npc>";
        str[170] = "<npc>Мужик возвращается с охоты домой. И заявляет приятелю:"
                   "- Ну все теперь целый месяц жена не будет покупать мясо!"
                   "- Что так много настелял?"
                   "- Нет, только пропил всю зарплату.</npc>";
        str[171] = "<npc>Гонится, значит, охотник за медведем. Медведь хоть и здоровый был, но бегал быстро и охотник отстал. А медведь-то и "
                   "бегал, пока между двух деревьев и застрял. А мимо заяц пробегал и спрашивает у медведя:"
                   "- Ты что здесь делаешь?"
                   "Ну, тот зайцу все рассказал, а заяц взял и выебал медведя в жопу. Медведь расстроился, а выбраться не смог."
                   "Тут он увидел пробегающего лиса и подзывает его:"
                   "- Лис, помоги, так мол так!"
                   "Лис подумал и тоже, как заяц, его и выебал. Медведь уже совсем отчаялся, когда увидел волка. Волк подходит и спрашивает:"
                   "- Что случилось?"
                   "Медведь: - Ну ладно, волк, еби, потом расскажу!!</npc>";
        str[172] = "<npc>Мужики пошли на охоту. Как водится напились. Пошли стрелять зверьё. И вдрцуг откуда ни возьмись медведь. Загнал одного охотника на дерево. Тот кричит:"
                   "- Мужики, спасите! Убейте медведя."
                   "Товарищ пьяный, целится, качается, промахивается, отстреливает медведю одно яйцо. Медведь лезет дальше. Мужик орёт:"
                   "- Мужики, спасите скорее! Убейте этого гада медведя."
                   "Опять товарищ пьяный, целится, качается, промахивается, отстреливает медведю другое яйцо. Мужик на дереве орёт:"
                   "- Ну что вы, гады, делаете! Он же меня не ебать лезет!</npc>";
        str[173] = "<npc>Короче сидят три охотника как в той картине и о своих подвигах разговаривают. Ну один говорит:"
                   "- Я такого зайца вчера завалил, кое-как до дому донес."
                   "Второй: - Фигня, это я такого глухаря завалил, что поднять не смог."
                   "Третий: - Я один раз такого лося завалил тяжелый собака! Отрезал ляжки, закинул на плечи..."
                   "Тут один из охотников говорит:"
                   "- Слушай, давай пропустим по одной, потом доскажешь."
                   "Ну вмазали."
                   "Третий: - Ну так на чем я остановился?"
                   "- Ляжки у тебя на плечах..."
                   "- А-а-а, вспомнил. Ну, положил я ляжки на плечи, и как впердолил ей на всю длинну!<npc>";
        str[174] = "<npc>Отправился охотник на охоту, из-за кустов выскочили 2 зайца - и в стороны, у него глаза и разошлись по сторонам..."
                   "Привозят его в больницу, думают, как лечить. Профессор, с умным видом говорит практикантам:"
                   "- Недуг вылечить не сложно, просто положите между глаз яйцо, и зрение придет в норму."
                   "На другое утро, придя на работу, профессор видит: охотника на каталке бодро везут в морг."
                   "- Что случилось? - спрашивает."
                   "- Ну так вы же сами сказали, чтобы ему между глаз яйцо положили. Так мы и хотели так сделать, только до пупа дотянули, а он уж и околел...</npc>";
        str[175] = "<npc>Охотник садится в трамвай и кладет себе на колени ружье, направив дулом на соседа."
                   "- Поосторожней, а то выстрелит!"
                   "- Ну и что? Еще раз заряжу.</npc>";
        str[176] = "<npc>Пошел мужик на охоту. Ходит весь день, никого подстрелить не может. И тут - выходит он на опушку - а там братки водку пьют,"
                   "и зверья у них настрелянного - видимо-невидимо. Обидно мужику стало."
                   "- Мужики, - говорит - поделились бы каким трофеем охотничьим, а то весь день хожу, никого подстрелить не могу, чего жене домой нести?"
                   "- О чем разговор, - те отвечают. - Только давай так: мы тебе глаза завяжем, а ты будешь зверя щупать и говорить,как его убили."
                   " Договорились. Завязали мужику глаза, начал он зверье ощупывать."
                   "- Вот кабанчик, одногодка, выстрел под лопатку, вод косуля, двухлетка, выстрел в голову... Ну и так далее."
                   "Набрал мужик зверья, напоили его братки, пришел он домой, завалился спать. Утром встал, жена на него как-то странно поглядывает."
                   "- Ты чего это, - спрашивает."
                   "- А что это, Вася, с тобой вчера было?"
                   "- А что?"
                   "- А что это ты меня всю ночь по пизде гладил да приговаривал: \"Ежик, трехлетка, удар топором...\"</npc>";
        str[177] = "<npc>- Ты знаешь, когда я в командировку последний раз уезжал, в шкафу капкан на медведя поставил. Представляешь, "
                   "приезжаю и сразу бегу к шкафу. Смотрю - сидит, красавец!"
                   "- Кто? Любовник?"
                   "- Медведь!</npc>";
        str[178] = "<npc>Встретились как-то два друга-охотника, один перед одним хвастается."
                   "- У меня собака, где утка подстреленная не упала найдет и принесет. Ну и тут же демонстрирует. Точно."
                   "Второй говорит: - А моя, круче. Hапример, летит стая уток я ее раскручиваю, бросаю по направлению к стае, она туда залетает, "
                   "хватает самую жирную утку и приносит мне. И для подтверждения раскручивает и бросает в пролетающую стая, а рядышком"
                   " на лугу пасется корова с теленком (ну, травку жуют), теленок поднимает голову вверх и видит летящую собаку и говорит:"
                   "- МУ, Мама-кoрoва, смотри собачка за утками летит."
                   "Корова отвечает: - Я ж говорила трава хорошая.</npc>";
        str[179] = "<npc>Заядлый охотник в дверях кабачка столкнулся с местным врачом:"
                   "- Знаете, доктор, что я сегодня подстрелил?"
                   "- Да, знаю, я его уже перевязал.</npc>";
        str[180] = "<npc>- Вчера я подстрелил двух гусей..."
                   "- Они были дикие?"
                   "- Они-то нет, а вот их хозяин!</npc>";
        str[181] = "<npc>Пошёл мужик на охоту. Подходит к берлоге медведя, сунул в берлогу ствол, выстрелил раз-другой. Вылез медведь и говорит:"
                   "- Мужик, либо я тебя заломаю, либо трахну, выбирай! - Делать нечего, жить-то хочется... Но обиду на окаянного затаил,"
                   " пошёл домой, достал пулемет, вернулся к месту бесчестия (берлоге), расстрелял в неё весь боекомплект. Вылезает медведь, говорит:"
                   "- Мужик, либо я тебя опять трахну, либо заломаю насмерть, выбирай! - Выжил мужик и на этот раз, но обида пуще прежней "
                   "не давала жить. Пошёл домой, достал динамит, решил взорвать аспида подлого, вернулся к берлоге, обложил её со всех сторон "
                   "динамитом, укрылся неподалёку, взорвал. Позади него голос медведя:"
                   "- Мужик, я чего-то не понял, ты охотник или пидор?</npc>";
        str[182] = "<npc>Приходит охотник домой с охоты."
                   "- Что это от тебя такой запах?"
                   "- Да понимаешь, пошел на медведя, а Тузика оставил дома. Пусть, думаю, дома побегает. Смотрю - берлога. Взял дрын,"
                   " давай там шуровать. Когда слышу, кто-то мне сзади лапы на плечи положил. Поворачиваюсь. Ну вижу, что Тузик, а перестать срать не могу!</npc>";
        str[183] = "<npc>Охотничий сезон. Охота на гусей. Охотник, изрядно уставший в поисках дичи, наконец-то увидел одинокого гуся,"
                   " застывшего в оцепенении у берега озера. Охотник стал подкрадываться к гусю, стараясь приблизится как можно ближе."
                   " Гусь не шевелится. Когда, наконец, ствол двустволки коснулся затылка гуся, гусь обернулся и прошипел:"
                   "- Тс-с-с-с! Карась!"
                   "- Что, клюет? - спросил с надеждой и шепотом обалдевший охотник. - Нет, сосет!!!</npc>";
        str[184] = "<npc>Опытный охотник делится опытом с начинающим:"
                   "- Запомни, лучше всего охотиться с собаками: сколько бы ты ни ходил, ни блуждал, а домой они дорогу всегда "
                   "найдут, как проголодаются. Но уж тогда поводка из рук не выпускай!</npc>";
        str[185] = "<npc>Будучи проездом в одной из областей, некий министр был приглашен на охоту на зайцев. По окончании он единогласно "
                   "был провозглашен королем стрелков. Министр один застрелил тридцать зайцев."
                   "- Да, это великолепный результат,- скромно заметил он, - особенно, если учесть, что у меня было только десять патронов.</npc>";
        str[186] = "<npc>Разговаривают два охотника:"
                   "- Говорят, ты на прошлой неделе медведицу завалил?"
                   "- Было дело."
                   "- Так расскажи же, как?"
                   "- Да как обычно - вино, легкая музыка, эротические журналы...</npc>";
        str[187] = "<npc>Идут два охотника по лесу. Видят перед ними баба голая с раздвинупыми ногами лежит. Первый посмотрел и говорит:"
                   "- Хорош зверь!"
                   "Второй смотрит на жопу и говорит:"
                   "- Не-е-е стреляный.</npc>";
        str[188] = "<npc>Трое охотников."
                   "Один:"
                   "- Я как-то раз, на охоте, такого огромного кабана одним выстрем убил..."
                   "Второй:"
                   "- А я лося..."
                   "Третий:"
                   "- Пошел я, как-то на охоту. Один патрон в стволе.... И тут стая волков... Я стреляю - промах. Волки за мной. Я на сосну."
                   " Вожак за мой. Я на самую верхушку - вожак за мной. Я выше и он за мной. Тут ветка хрустнула и я вниз упал..."
                   "- Ну и чего?"
                   "- Сожрали на фиг...</npc>";
        str[189] = "<npc>Охотник идет по лесу, ему навстречу - кабан. Он из обоих стволов - бабах! Все в дыму, охотник думает: попал или не попал? Дым "
                   "рассеивается, кабан стоит целехонек и говорит:"
                   "- Ну, мужик, ты попал...</npc>";
        str[190] = "<npc>Разговаривают два охотника:"
                   "- Представляешь, вчера я набрел на парочку прекрасных фазанов, у меня сердце затрепетало, когда я их увидел!"
                   "- И ты их добыл?"
                   "- Нет, нескольких рублей не хватило.</npc>";
    }
    return str[id];
}

QString Hanters::act(int id)
{
    QString act[37];
    if(id < 20)
    {
        act[0] = "Уйти";
        act[1] = "Познакомиться";
        act[2] = "Присесть";
        act[3] = "Отойти";
        act[4] = "Приставать";
        act[5] = "Поболтать";
        act[6] = "Попросить научить стрелять из ружья";
        act[7] = "Попросить пострелять из ружья";
        act[8] = "Подойти";
        act[9] = "Далее";
        act[10] = "Сосать";
        act[11] = "Идти стрелять";
        act[12] = "Выстрел";
        act[13] = "Потерять сознание";
        act[14] = "Поговорить с Андреем";
        act[15] = "Поговорить с Сергеем";
        act[16] = "Поговорить с Игорем";
        act[17] = "Согласиться";
        act[18] = "Отказаться";
        act[19] = "Сопротивляться";
    }
    if(id >= 20 && id < 40)
    {
        act[20] = "Идти";
        act[21] = "Сосать дальше";
        act[22] = "Удивиться";
        act[23] = "Сесть на корточки";
        act[24] = "Очнуться";
        act[25] = "Стать на четвереньки";
        act[26] = "Лечь на бок";
        act[27] = "Сесть сверху";
        act[28] = "Стать раком";
        act[29] = "Лечь на живот";
        act[30] = "Стать на колени";
        act[31] = "Дрочить";
        act[32] = "Запрыгнуть на руки";
        act[33] = "Опереться на дерево";
        act[34] = "Опереться на дерево и поднять ногу";
        act[35] = "Повернуться спиной";
        act[36] = "Повернуться лицом";
    }
    return act[id];
}

QString Hanters::media(int id)
{
    QString med[171];
    if(id < 20)
    {
        med[0] = "data/locations/gadukino/swamp/hanters.jpg";
        med[1] = "data/actions/backwater/hanterswork1.1.jpg";
        med[2] = "data/actions/backwater/hanterswork1.2.jpg";
        med[3] = "data/actions/backwater/hanterswork1.3.jpg";
        med[4] = "data/actions/backwater/hanterswork1.4.jpg";
        med[5] = "data/actions/backwater/hanterswork1.5.jpg";
        med[6] = "data/actions/backwater/hanterswork1.6.jpg";
        med[7] = "data/actions/backwater/hanterswork1.7.jpg";
        med[8] = "data/actions/backwater/hanterswork1.8.jpg";
        med[9] = "data/actions/backwater/hanterswork1.9.jpg";
        med[10] = "data/locations/gadukino/swamp/hanters1.jpg";
        med[11] = "data/actions/backwater/claps_eyes.jpg";
        med[12] = "data/qwest/hantersex/hantersgroupundress.jpg";
        med[13] = "data/qwest/hantersex/hantersgrouptanga.jpg";
        med[14] = "data/locations/gadukino/swamp/hantersnotanga1.jpg";
        med[15] = "data/actions/backwater/shooting.jpg";
        med[16] = "data/actions/backwater/shooting1.gif";
        med[17] = "data/actions/backwater/shooting2.gif";
        med[18] = "data/actions/backwater/tongue.jpg";
        med[19] = "data/qwest/hantersex/backwaterrelax2.jpg";
    }
    if(id >= 20 && id < 40)
    {
        med[20] = "data/qwest/hantersex/backwaterrelax3.jpg";
        med[21] = "data/qwest/hantersex/backwaterrelax4.jpg";
        med[22] = "data/qwest/hantersex/backwaterrelax5.1.jpg";
        med[23] = "data/qwest/hantersex/backwaterrelax5.2.jpg";
        med[24] = "data/qwest/hantersex/backwaterrelax5.3.jpg";
        med[25] = "data/qwest/hantersex/backwaterrelax6.jpg";
        med[26] = "data/qwest/hantersex/backwaterrelax7.jpg";
        med[27] = "data/qwest/hantersex/backwaterrelax8.jpg";
        med[28] = "data/qwest/hantersex/backwaterrelax9.jpg";
        med[29] = "data/qwest/hantersex/backwaterrelax10.jpg";
        med[30] = "data/qwest/hantersex/backwaterrelax11.jpg";
        med[31] = "data/qwest/hantersex/backwaterrelax12.jpg";
        med[32] = "data/qwest/hantersex/backwaterrelax13.jpg";
        med[33] = "data/qwest/hantersex/backwaterrelax14.jpg";
        med[34] = "data/qwest/hantersex/hantersgroupBJ3.0.jpg";
        med[35] = "data/qwest/hantersex/hantersgroupBJ3.1.jpg";
        med[36] = "data/qwest/hantersex/hantersgroupBJ3.2.jpg";
        med[37] = "data/qwest/hantersex/hantersgroupBJ3.3.jpg";
        med[38] = "data/qwest/hantersex/hantersgroupBJ3.4.jpg";
        med[39] = "data/qwest/hantersex/hantersgroupBJ3.5.jpg";
    }
    if(id >= 40 && id < 60)
    {
        med[40] = "data/qwest/hantersex/hantersgroupBJ3.6.jpg";
        med[41] = "data/qwest/hantersex/hantersgroupBJ3.7.jpg";
        med[42] = "data/qwest/hantersex/hantersgroupBJ3.8.jpg";
        med[43] = "data/qwest/hantersex/hantersgroupO1.0.jpg";
        med[44] = "data/qwest/hantersex/hantersgroupO1.1.jpg";
        med[45] = "data/npc/gadukino/swamp/AndreiHanter.jpg";
        med[46] = "data/npc/gadukino/swamp/SergeiHanter.jpg";
        med[47] = "data/npc/gadukino/swamp/IgorHanter.jpg";
        med[48] = "data/qwest/hantersex/fuck.jpg";
        med[49] = "data/locations/gadukino/forest/3boys.1.jpg";
        med[50] = "data/qwest/hantersex/slutgosex1.jpg";
        med[51] = "data/qwest/hantersex/hantersgroupfaint.jpg";
        med[52] = "data/qwest/hantersex/hantersgroupfaint1.jpg";
        med[53] = "data/qwest/hantersex/hantersgroupfaint2.jpg";
        med[54] = "data/qwest/hantersex/hantersgroupORALsi1.0.jpg";
        med[55] = "data/qwest/hantersex/hantersgroupORALsi1.1.jpg";
        med[56] = "data/qwest/hantersex/hantersgroupORALsi1.2.jpg";
        med[57] = "data/qwest/hantersex/hantersgroupORALsi1.3.jpg";
        med[58] = "data/qwest/hantersex/hantersgroupORALsi2.0.jpg";
        med[59] = "data/qwest/hantersex/hantersgroupORALsi2.1.jpg";
    }
    if(id >= 60 && id < 80)
    {
        med[60] = "data/qwest/hantersex/hantersgroupORALsi2.2.jpg";
        med[61] = "data/qwest/hantersex/hantersgroupORALs.jpg";
        med[62] = "data/qwest/hantersex/hantersgroupORALs1.0.jpg";
        med[63] = "data/qwest/hantersex/hantersgroupORALs1.1.jpg";
        med[64] = "data/qwest/hantersex/hantersgroupORALs1end.jpg";
        med[65] = "data/qwest/hantersex/hantersgroupORALend1.jpg";
        med[66] = "data/qwest/hantersex/hantersgroupORALend1.0.jpg";
        med[67] = "data/qwest/hantersex/hantersgroupORALend1.1.jpg";
        med[68] = "data/qwest/hantersex/hantersgroupORALi.jpg";
        med[69] = "data/qwest/hantersex/hantersgroupORALi1.jpg";
        med[70] = "data/qwest/hantersex/hantersgroupORALai1.0.jpg";
        med[71] = "data/qwest/hantersex/hantersgroupORALai1.1.jpg";
        med[72] = "data/qwest/hantersex/hantersgroupORALai1.2.jpg";
        med[73] = "data/qwest/hantersex/hantersgroupORALai1.3.jpg";
        med[74] = "data/qwest/hantersex/hantersgroupVias3.0.jpg";
        med[75] = "data/qwest/hantersex/hantersgroupVias3.1.jpg";
        med[76] = "data/qwest/hantersex/hantersgroupVias3.2.jpg";
        med[77] = "data/qwest/hantersex/hantersgroupVias3.3.jpg";
        med[78] = "data/qwest/hantersex/hantersgroupVias3.4.jpg";
        med[79] = "data/qwest/hantersex/hantersgroupVas.jpg";
    }
    if(id >= 80 && id < 100)
    {
        med[80] = "data/qwest/hantersex/hantersgroupVas1.0.jpg";
        med[81] = "data/qwest/hantersex/hantersgroupVas1.1.jpg";
        med[82] = "data/qwest/hantersex/hantersgroupVas1.2.jpg";
        med[83] = "data/qwest/hantersex/hantersgroupVas1.3.jpg";
        med[84] = "data/qwest/hantersex/hantersgroupVas1.4.jpg";
        med[85] = "data/qwest/hantersex/hantersgroupVa.jpg";
        med[86] = "data/qwest/hantersex/hantersgroupVa1.jpg";
        med[87] = "data/qwest/hantersex/hantersgroupVs.jpg";
        med[88] = "data/qwest/hantersex/hantersgroupVs1.jpg";
        med[89] = "data/qwest/hantersex/hantersgroupVi.jpg";
        med[90] = "data/qwest/hantersex/hantersgroupVi1.jpg";
        med[91] = "data/qwest/hantersex/hantersgroupVi2.jpg";
        med[92] = "data/qwest/hantersex/hantersgroupVis.jpg";
        med[93] = "data/qwest/hantersex/hantersgroupVis1.0.jpg";
        med[94] = "data/qwest/hantersex/hantersgroupVis1.1.jpg";
        med[95] = "data/qwest/hantersex/hantersgroupVis1.2.jpg";
        med[96] = "data/qwest/hantersex/hantersgroupVis1.3.jpg";
        med[97] = "data/qwest/hantersex/hantersgroupVis1.4.jpg";
        med[98] = "data/qwest/hantersex/hantersgroupVia.jpg";
        med[99] = "data/qwest/hantersex/hantersgroupVia1.0.jpg";
    }
    if(id >= 100 && id < 120)
    {
        med[100] = "data/qwest/hantersex/hantersgroupVia1.1.jpg";
        med[101] = "data/qwest/hantersex/hantersgroupVia1.1.jpg";
        med[102] = "data/qwest/hantersex/hantersgroupVaOsHi1.0.jpg";
        med[103] = "data/qwest/hantersex/hantersgroupVaOsHi1.1.jpg";
        med[104] = "data/qwest/hantersex/hantersgroupVaOsHi1.2.jpg";
        med[105] = "data/qwest/hantersex/hantersgroupVaOsHi1.3.jpg";
        med[106] = "data/qwest/hantersex/hantersgroupVaOHi.jpg";
        med[107] = "data/qwest/hantersex/hantersgroupDPasi1.0.jpg";
        med[108] = "data/qwest/hantersex/hantersgroupDPasi1.1.jpg";
        med[109] = "data/qwest/hantersex/hantersgroupDPasi1.2.jpg";
        med[110] = "data/qwest/hantersex/hantersgroupDPai.jpg";
        med[111] = "data/qwest/hantersex/hantersgroupDPas.jpg";
        med[112] = "data/qwest/hantersex/hantersgroupVsOaHi1.0.jpg";
        med[113] = "data/qwest/hantersex/hantersgroupVsOaHi1.1.jpg";
        med[114] = "data/qwest/hantersex/hantersgroupVsOi1.0.jpg";
        med[115] = "data/qwest/hantersex/hantersgroupVsOi1.1.jpg";
        med[116] = "data/qwest/hantersex/hantersgroupVsOi1.2.jpg";
        med[117] = "data/qwest/hantersex/hantersgroupVOi.jpg";
        med[118] = "data/qwest/hantersex/hantersgroupVsO.jpg";
        med[119] = "data/qwest/hantersex/hantersgroupViOa1.0.jpg";
    }
    if(id >= 120 && id < 140)
    {
        med[120] = "data/qwest/hantersex/hantersgroupViOa1.1.jpg";
        med[121] = "data/qwest/hantersex/hantersgroupViO.jpg";
        med[122] = "data/qwest/hantersex/hantersgroupVaOs1.0.jpg";
        med[123] = "data/qwest/hantersex/hantersgroupVaOs1.1.jpg";
        med[124] = "data/qwest/hantersex/hantersgroupVaOs1.2.jpg";
        med[125] = "data/qwest/hantersex/hantersgroupVaOs1.3.jpg";
        med[126] = "data/qwest/hantersex/hantersgroupVOs.jpg";
        med[127] = "data/qwest/hantersex/hantersgroupVaO.jpg";
        med[128] = "data/qwest/hantersex/hantersgroupAsOa.jpg";
        med[129] = "data/qwest/hantersex/hantersgroupAsO.jpg";
        med[130] = "data/qwest/hantersex/hantersgroupAOa.jpg";
        med[131] = "data/qwest/hantersex/hantersgroupDPis.jpg";
        med[132] = "data/qwest/hantersex/hantersgroupDPia.jpg";
        med[133] = "data/qwest/hantersex/hantersgroupA1.0.jpg";
        med[134] = "data/qwest/hantersex/hantersgroupA1.1.jpg";
        med[135] = "data/qwest/hantersex/hantersgroupA1.2.jpg";
        med[136] = "data/qwest/hantersex/hantersgroupA1.3.jpg";
        med[137] = "data/qwest/hantersex/hantersgroupA1.4.jpg";
        med[138] = "data/qwest/hantersex/hantersgroupAEnd1.jpg";
        med[139] = "data/qwest/hantersex/hantersgroupAaEnd2.jpg";
    }
    if(id >= 140 && id < 160)
    {
        med[140] = "data/qwest/hantersex/hantersgroupAEnd2.jpg";
        med[141] = "data/qwest/hantersex/hantersgroupV0.0.jpg";
        med[142] = "data/qwest/hantersex/hantersgroupV0.1.jpg";
        med[143] = "data/qwest/hantersex/hantersgroupVend.jpg";
        med[144] = "data/qwest/hantersex/hantersgroupOend1.0.jpg";
        med[145] = "data/qwest/hantersex/hantersgroupOend1.1.jpg";
        med[146] = "data/qwest/hantersex/hantersgroupOend1.2.jpg";
        med[147] = "data/qwest/hantersex/hanterslutSTART1.jpg";
        med[148] = "data/qwest/hantersex/hanterslutSTART2.jpg";
        med[149] = "data/qwest/hantersex/hanterslutEND1.jpg";
        med[150] = "data/qwest/hantersex/hanterslutEND2.1.jpg";
        med[151] = "data/qwest/hantersex/hanterslutEND2.2.jpg";
        med[152] = "data/qwest/hantersex/hanterslutORAL1.1.jpg";
        med[153] = "data/qwest/hantersex/hanterslutORAL1.2.jpg";
        med[154] = "data/qwest/hantersex/hanterslutCOW1.1.jpg";
        med[155] = "data/qwest/hantersex/hanterslutCOW1.2.jpg";
        med[156] = "data/qwest/hantersex/hanterslutCOW1.3.jpg";
        med[157] = "data/qwest/hantersex/hanterslutCOW1.4.jpg";
        med[158] = "data/qwest/hantersex/hanterslutHANDS1.1.jpg";
        med[159] = "data/qwest/hantersex/hanterslutHANDS1.2.jpg";
    }
    if(id >= 160 && id < 171)
    {
        med[160] = "data/qwest/hantersex/hanterslutTREE1.1.jpg";
        med[161] = "data/qwest/hantersex/hanterslutTREE1.2.jpg";
        med[162] = "data/qwest/hantersex/hanterslutTREE1.3.jpg";
        med[163] = "data/qwest/hantersex/hanterslutTREELEG1.1.jpg";
        med[164] = "data/qwest/hantersex/hanterslutTREELEG1.2.jpg";
        med[165] = "data/qwest/hantersex/hanterslutTREELEG1.3.jpg";
        med[166] = "data/qwest/hantersex/hanterslutTREELEG1.4.jpg";
        med[167] = "data/qwest/hantersex/hanterslutLEG1.1.jpg";
        med[168] = "data/qwest/hantersex/hanterslutLEG1.2.jpg";
        med[169] = "data/qwest/hantersex/hanterslutLEG2.1.jpg";
        med[170] = "data/qwest/hantersex/hanterslutLEG2.2.jpg";
    }
    return med[id];
}

void Hanters::actions1()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("groupORALi1end",act(21));
        if(hantsexa == 2)
        {
            if(hantsexb == 5) makeActBtn("groupAi",act(25));
            if(hantsexb < 5) makeActBtn("groupAiEnd1",act(25));
            if(hantsexb > 5) makeActBtn("groupAiEnd2",act(25));
        }
        if(hantsexa == 3)
        {
            if(hantsexb <= 3) makeActBtn("groupVi3",act(26));
            if(hantsexb > 3) makeActBtn("groupVi3end",act(26));
        }
        if(hantsexa == 4) makeActBtn("groupOiend",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions2()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) // Сосать дальше
        {
            if(hantsexb <= 4) makeActBtn("groupORALs1",act(21));
            if(hantsexb > 4) makeActBtn("groupORALs1end",act(21));
        }
        if(hantsexa == 2) // Стать на четвереньки
        {
            if(hantsexb == 5) makeActBtn("groupAs",act(25));
            if(hantsexb < 5) makeActBtn("groupAsEnd1",act(25));
            if(hantsexb > 5) makeActBtn("groupAsEnd2",act(25));
        }
        if(hantsexa == 3) // Сесть сверху
        {
            if(hantsexb <= 3) makeActBtn("groupVs2",act(27));
            if(hantsexb > 3) makeActBtn("groupVs2end",act(27));
        }
        if(hantsexa == 4) makeActBtn("groupOsend",act(30)); // Стать на колени
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions3()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) // Сосать дальше
        {
            if(hantsexb <= 6) makeActBtn("groupORALai1",act(21));
            if(hantsexb > 6) makeActBtn("groupORALi1",act(21));
        }
        if(hantsexa == 2) // Стать раком
        {
            if(hantsexb < 6) makeActBtn("groupVia1",act(28));
            if(hantsexb == 6) makeActBtn("groupVi2",act(28));
            if(hantsexb > 6) makeActBtn("groupVa1",act(28));
        }
        if(hantsexa == 3) // Лечь на бок
        {
            if(hantsexb <= 6) makeActBtn("groupViOa",act(26));
            if(hantsexb > 6) makeActBtn("groupViO",act(26));
        }
        if(hantsexa == 4) makeActBtn("groupDPia",act(27)); // Сесть сверху
        if(hantsexa == 5) makeActBtn("groupOia",act(30)); // Стать на колени
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions4()
{
    if(root->vStatus(health) > 50)
    {
        if (hantsexa == 1) // Стать на четвереньки
        {
            if(hantsexb < 6) makeActBtn("groupVas1",act(25));
            if(hantsexb == 6) makeActBtn("groupVa",act(25));
            if(hantsexb > 6) makeActBtn("groupVs",act(25));
        }
        if (hantsexa == 2) // Лечь на живот
        {
            if(hantsexb < 6) makeActBtn("groupVaOs",act(29));
            if(hantsexb > 6) makeActBtn("groupVOs",act(29));
            if(hantsexb == 6) makeActBtn("groupVaO",act(29));
        }
        if(hantsexa == 3) // Стать на четвереньки
        {
            if(hantsexb > 5) makeActBtn("groupAsOa",act(25));
            if(hantsexb == 5) makeActBtn("groupAsO",act(25));
            if(hantsexb < 5) makeActBtn("groupAOa",act(25));
        }
        if(hantsexa == 4) makeActBtn("groupOsa",act(30)); // Стать на колени
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions5()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) // Сосать дальше
        {
            if(hantsexb < 6) makeActBtn("groupORALsi1",act(21));
            if(hantsexb == 6) makeActBtn("groupORALs",act(21));
            if(hantsexb == 7) makeActBtn("groupORALi",act(21));
            if(hantsexb == 8) makeActBtn("groupORALend1",act(21));
        }
        if(hantsexa == 2) // Стать на четвереньки
        {
            if(hantsexb <= 5) makeActBtn("groupVis1",act(25));
            if(hantsexb > 6) makeActBtn("groupVi1",act(25));
            if(hantsexb == 6) makeActBtn("groupVs1",act(25));
        }
        if(hantsexa == 3) // Лечь на бок
        {
            if(hantsexb <= 5) makeActBtn("groupVsOi",act(26));
            if(hantsexb > 6) makeActBtn("groupVOi",act(26));
            if(hantsexb == 6) makeActBtn("groupVsO",act(26));
        }
        if(hantsexa == 4) makeActBtn("groupDPis",act(27)); // Сесть сверху
        if(hantsexa == 5) makeActBtn("groupOis",act(30)); // Стать на колени
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions6()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("groupORALasi",act(21)); // Сосать дальше
        if(hantsexa == 2) // Сесть сверху
        {
            if(hantsexb > 5) makeActBtn("groupVias",act(27));
            if(hantsexb == 3) makeActBtn("groupVia",act(27));
            if(hantsexb == 4) makeActBtn("groupVis",act(27));
            if(hantsexb == 5) makeActBtn("groupVi",act(27));
            if(hantsexb < 3) makeActBtn("groupVas",act(27));
        }
        if(hantsexa == 3) // Стать раком
        {
            if(hantsexb > 5) makeActBtn("groupVaOsHi",act(28));
            if(hantsexb == 5) makeActBtn("groupVaOHi",act(28));
            if(hantsexb < 5) makeActBtn("groupVOsHi",act(28));
        }
        if(hantsexa == 4) // Сесть сверху
        {
            if(hantsexb < 5) makeActBtn("groupDPasi",act(27));
            if(hantsexb > 6) makeActBtn("groupDPas",act(27));
            if(hantsexb == 6) makeActBtn("groupDPsi",act(27));
            if(hantsexb == 5) makeActBtn("groupDPai",act(27));
        }
        if(hantsexa == 5) // Лечь на бок
        {
            if(hantsexb > 5) makeActBtn("groupVsOaHi",act(26));
            if(hantsexb == 5) makeActBtn("groupVsOHi",act(26));
            if(hantsexb < 5) makeActBtn("groupVOaHi",act(26));
        }
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::actions7()
{
    if(root->vStatus(health) > 50)
    {
        if (hantsexa == 1) makeActBtn("groupORALa1end",act(10)); // Сосать
        if (hantsexa == 2) // Стать на четвереньки
        {
            if(hantsexb == 5) makeActBtn("groupAa",act(25));
            if(hantsexb < 5) makeActBtn("groupAaEnd1",act(25));
            if(hantsexb > 5) makeActBtn("groupAaEnd2",act(25));
        }
        if(hantsexa == 3) // Сесть сверху
        {
            if(hantsexb <= 3) makeActBtn("groupVa2",act(27));
            if(hantsexb > 3) makeActBtn("groupVa2end",act(27));
        }
        if(hantsexa == 4) makeActBtn("groupOaend",act(30)); // Стать на колени
    }
    else
        makeActBtn("groupfaint",act(13));
}

bool Hanters::sexHanters()
{
    return root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3;
}

bool Hanters::sexGopGuys()
{
    return root->gVEvent(forest_gopsex) == 3;
}

void Hanters::resetCounters()
{
    boyAsex = 0;
    boyAsexA = 0;
    boyBsex = 0;
    boyBsexA = 0;
    boyCsex = 0;
    boyCsexA = 0;
}

void Hanters::setAndrei()
{
    root->setBoyName(str(36));
    root->sVSex(silavag,0);
    root->sVSex(dick,20);
}

void Hanters::setAndrei2()
{
    root->setBoy2Name(str(36));
    root->sVSex(silavag,0);
    root->sVSex(dick2,20);
}

void Hanters::setSergei()
{
    root->setBoyName(str(38));
    root->sVSex(silavag,1);
    root->sVSex(dick,18);
}

void Hanters::setSergei2()
{
    root->setBoy2Name(str(38));
    root->sVSex(silavag,1);
    root->sVSex(dick2,18);
}

void Hanters::setIgor()
{
    root->setBoyName(str(37));
    root->sVSex(silavag,2);
    root->sVSex(dick,16);
}

void Hanters::setIgor2()
{
    root->setBoy2Name(str(37));
    root->sVSex(silavag,2);
    root->sVSex(dick2,16);
}

void Hanters::setMitka()
{
    root->setBoyName(str(54));
    root->sVSex(silavag,0);
    root->sVSex(dick,16);
}

void Hanters::setMitka2()
{
    root->setBoy2Name(str(54));
    root->sVSex(silavag,0);
    root->sVSex(dick2,16);
}

void Hanters::setKolyamba()
{
    root->setBoyName(str(55));
    root->sVSex(silavag,0);
    root->sVSex(dick,15);
}

void Hanters::setKolyamba2()
{
    root->setBoy2Name(str(55));
    root->sVSex(silavag,0);
    root->sVSex(dick2,15);

}

void Hanters::setVasyan()
{
    root->setBoyName(str(56));
    root->sVSex(silavag,0);
    root->sVSex(dick,14);
}

void Hanters::setVasyan2()
{
    root->setBoy2Name(str(56));
    root->sVSex(silavag,0);
    root->sVSex(dick2,14);
}

void Hanters::checkBoyAsex()
{
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void Hanters::checkBoyBsex()
{
    if(boyBsex == 0)
    {
        boyBsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void Hanters::checkBoyCsex()
{
    if(boyCsex == 0)
    {
        boyCsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void Hanters::checkBoyAsexAnal()
{
    if(boyAsexA == 0)
    {
        boyAsexA = 1;
        root->uVSC(analSex,1);
    }
}

void Hanters::checkBoyBsexAnal()
{
    if(boyBsexA == 0)
    {
        boyBsexA = 1;
        root->uVSC(analSex,1);
    }
}

void Hanters::checkBoyCsexAnal()
{
    if(boyCsexA == 0)
    {
        boyCsexA = 1;
        root->uVSC(analSex,1);
    }
}
