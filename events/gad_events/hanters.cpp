#include "hanters.h"
#include "../eventhandler.h"
#include "../../Functions.h"

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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3 || root->gVEvent(forest_gopsex) == 3)
    {
        root->rendImagePage();
        root->incTime(1);
        root->uVSC(blowJob,3);
        root->uVEvent(hantslutsex,getRandInt(3,6));
        root->uVSC(gangBang,1);
        root->uVSkill(domination,-1);
        resetCounters();
        if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
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

        if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
        {
            root->setImage(media(10));
            root->setDesc(str(52));
        }
        else if(root->gVEvent(forest_gopsex) == 3)
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

    //Сосать
    if(action == "groupORALend1") groupORALend1();
    if(action == "groupORALa1end") groupORALa1end();
    if(action == "groupORALi") groupORALi();
    if(action == "groupORALi1") groupORALi1();
    if(action == "groupORALi1end") groupORALi1end();
    if(action == "groupORALs") groupORALs();
    if(action == "groupORALs1") groupORALs1();
    if(action == "groupORALs1end") groupORALs1end();
    if(action == "groupORALai") groupORALai();
    if(action == "groupORALai1") groupORALai1();
    if(action == "groupORALas") groupORALas();
    if(action == "groupORALsi") groupORALsi();
    if(action == "groupORALsi1") groupORALsi1();
    if(action == "groupORALasi") groupORALasi();
    if(action == "groupOia") groupOia();
    if(action == "groupOiend") groupOiend();
    if(action == "groupOis") groupOis();
    if(action == "groupOsend") groupOsend();
    if(action == "groupOsa") groupOsa();

    //Стать на четвереньки/раком
    if(action == "groupVa") groupVa();
    if(action == "groupVa1") groupVa1();
    if(action == "groupVi1") groupVi1();
    if(action == "groupVi2") groupVi2();
    if(action == "groupVs") groupVs();
    if(action == "groupVs1") groupVs1();
    if(action == "groupVas1") groupVas1();
    if(action == "groupVia1") groupVia1();
    if(action == "groupVis1") groupVis1();

    if(action == "groupVaOsHi") groupVaOsHi();
    if(action == "groupVaOHi") groupVaOHi();
    if(action == "groupVOsHi") groupVOsHi();

    if(action == "groupAi") groupAi();
    if(action == "groupAiEnd1") groupAiEnd1();
    if(action == "groupAiEnd2") groupAiEnd2();
    if(action == "groupAs") groupAs();
    if(action == "groupAsEnd1") groupAsEnd1();
    if(action == "groupAsEnd2") groupAsEnd2();
    if(action == "groupAsOa") groupAsOa();
    if(action == "groupAsO") groupAsO();
    if(action == "groupAOa") groupAOa();

    //Лечь на бок
    if(action == "groupViOa") groupViOa();
    if(action == "groupViO") groupViO();
    if(action == "groupVsOi") groupVsOi();
    if(action == "groupVOi") groupVOi();
    if(action == "groupVsO") groupVsO();
    if(action == "groupVsOaHi") groupVsOaHi();
    if(action == "groupVsOHi") groupVsOHi();
    if(action == "groupVOaHi") groupVOaHi();

    //Лечь на живот
    if(action == "groupVaOsv") groupVaOsv();
    if(action == "groupVOs") groupVOs();
    if(action == "groupVaO") groupVaO();

    //Сесть сверху
    if(action == "groupDPai") groupDPai();
    if(action == "groupDPas") groupDPas();
    if(action == "groupDPia") groupDPia();
    if(action == "groupDPis") groupDPis();
    if(action == "groupDPsi") groupDPsi();
    if(action == "groupDPasi") groupDPasi();

    if(action == "groupVi") groupVi();
    if(action == "groupVi3") groupVi3();
    if(action == "groupVi3end") groupVi3end();
    if(action == "groupVs2") groupVs2();
    if(action == "groupVs2end") groupVs2end();
    if(action == "groupVias") groupVias();
    if(action == "groupVas") groupVas();
    if(action == "groupVia") groupVia();
    if(action == "groupVis") groupVis();

    if(action == "groupfaint") groupfaint();
    if(action == "slutSTART") slutSTART();

//Navigation
    if(action == "exit_ORALi1")
    {
        root->sVEvent(forest_hantersex,0);
        root->incTime(60);
        root->changeLoc(lswampyard);
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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(63));
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
    {
        root->setDesc(str(64));
        setVasyan();
        root->blow_job();
        setKolyamba();
    }
    root->cum("face");
    root->blow_job();
    root->fnswallow();
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
        setIgor();
    if(root->gVEvent(forest_gopsex) == 3)
        setVasyan();
    root->cum("face");
    root->fnswallow();
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
        root->addDesc(str(69));
    if(root->gVEvent(forest_gopsex) == 3)
        root->addDesc(str(70));
    if(root->gVEvent(forest_hantersex) == 0)
    {
        root->sVEvent(hantersexnude,0);
        root->sVEvent(forest_gopsex,0);
        makeActBtn("back_to_loc",act(9));
    }
    if(root->gVEvent(forest_hantersex) > 0)
    {
        root->sVEvent(forest_hantersex,0);
        root->incTime(60);
        makeActBtn("swamp_yard",act(9));
    }
}
void Hanters::groupORALa1end() //not sure, maybe Andrei instead Igor
{
    root->sVSex(pose,0);
    root->incTime(5);
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
        setIgor();
    if(root->gVEvent(forest_gopsex) == 3)
        setVasyan();
    root->setImage(media(getRandInt(66,67)));
    root->setDesc(str(68));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(67));
    if(root->gVEvent(forest_hantersex) == 0) makeActBtn("back_to_loc",act(9));
    if(root->gVEvent(forest_hantersex) > 0) makeActBtn("exit_ORALi1",act(9));
}
void Hanters::groupORALi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(68));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(63));
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("groupORALi1end",act(21));

        if(hantsexa == 2 && hantsexb == 5) makeActBtn("groupAi",act(25));
        if(hantsexa == 2 && hantsexb < 5) makeActBtn("groupAiEnd1",act(25));
        if(hantsexa == 2 && hantsexb > 5) makeActBtn("groupAiEnd2",act(25));

        if(hantsexa == 3 && hantsexb <= 3) makeActBtn("groupVi3",act(26));
        if(hantsexa == 3 && hantsexb > 3) makeActBtn("groupVi3end",act(26));

        if(hantsexa == 4) makeActBtn("groupOiend",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));

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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setIgor();
        root->blow_job();
        setAndrei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("groupORALi1end",act(21));
        if(hantsexa == 2 && hantsexb == 5) makeActBtn("groupAi",act(25));
        if(hantsexa == 2 && hantsexb < 5) makeActBtn("groupAiEnd1",act(25));
        if(hantsexa == 2 && hantsexb > 5) makeActBtn("groupAiEnd2",act(25));
        if(hantsexa == 3 && hantsexb <= 3) makeActBtn("groupVi3", act(27));
        if(hantsexa == 3 && hantsexb > 3) makeActBtn("groupVi3end",act(27));
        if(hantsexa == 4) makeActBtn("groupOiend",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::groupORALi1end()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->setImage(media(getRandInt(66,67)));
    root->setDesc(str(68));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
        setIgor();
    if(root->gVEvent(forest_gopsex) == 3)
        setVasyan();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(67));
    if(root->gVEvent(forest_hantersex) == 0) makeActBtn("back_to_loc",act(9));
    if(root->gVEvent(forest_hantersex) > 0) makeActBtn("exit_ORALi1",act(9));
}
void Hanters::groupORALs()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(61));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(63));
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1 && hantsexb <= 4) makeActBtn("groupORALs1",act(21));
        if(hantsexa == 1 && hantsexb > 4) makeActBtn("groupORALs1end",act(21));

        if(hantsexa == 2 && hantsexb == 5) makeActBtn("groupAs",act(25));
        if(hantsexa == 2 && hantsexb < 5) makeActBtn("groupAsEnd1",act(25));
        if(hantsexa == 2 && hantsexb > 5) makeActBtn("groupAsEnd2",act(25));

        if(hantsexa == 3 && hantsexb <= 3) makeActBtn("groupVs2",act(26));
        if(hantsexa == 3 && hantsexb > 3) makeActBtn("groupVs2end",act(26));

        if(hantsexa == 4) makeActBtn("groupOsend",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::groupORALs1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(62,63)));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(65));
        setSergei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
    {
        root->setDesc(str(66));
        setKolyamba();
    }
    root->blow_job();
    hantsexa = getRandInt(1,4);
    hantsexb = getRandInt(1,8);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1 && hantsexb <= 3) makeActBtn("groupORALs1",act(21));
        if(hantsexa == 1 && hantsexb > 3) makeActBtn("groupORALs1end",act(21));

        if(hantsexa == 2 && hantsexb == 5) makeActBtn("groupAs",act(25));
        if(hantsexa == 2 && hantsexb < 5) makeActBtn("groupAsEnd1",act(25));
        if(hantsexa == 2 && hantsexb > 5) makeActBtn("groupAsEnd2",act(25));

        if(hantsexa == 3 && hantsexb <= 3) makeActBtn("groupVs2",act(26));
        if(hantsexa == 3 && hantsexb > 3) makeActBtn("groupVs2end",act(26));

        if(hantsexa == 4) makeActBtn("groupOsend",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::groupORALs1end()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->setImage(media(64));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(65));
        setSergei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setAndrei();
        root->blow_job();
        setIgor();
        root->blow_job();
        setSergei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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

    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1 && hantsexb <= 6) makeActBtn("groupORALai1",act(21));
        if(hantsexa == 1 && hantsexb > 6) makeActBtn("groupORALi1",act(21));

        if(hantsexa == 2 && hantsexb < 6) makeActBtn("groupVia1",act(28));
        if(hantsexa == 2 && hantsexb == 6) makeActBtn("groupVi2",act(28));
        if(hantsexa == 2 && hantsexb > 6) makeActBtn("groupVa1",act(28));

        if(hantsexa == 3 && hantsexb <= 6) makeActBtn("groupViOa",act(26));
        if(hantsexa == 3 && hantsexb > 6) makeActBtn("groupViO",act(26));

        if(hantsexa == 4) makeActBtn("groupDPia",act(27));
        if(hantsexa == 5) makeActBtn("groupOia",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));

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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setAndrei();
        root->blow_job();
        setIgor();
    }
    if(root->gVEvent(forest_gopsex) == 3)
    {
        setMitka();
        root->blow_job();
        setVasyan();
    }
    root->blow_job();
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1 && hantsexb <= 6) makeActBtn("groupORALai1",act(21));
        if(hantsexa == 1 && hantsexb > 6) makeActBtn("groupORALi1",act(21));

        if(hantsexa == 2 && hantsexb < 6) makeActBtn("groupVia1",act(28));
        if(hantsexa == 2 && hantsexb == 6) makeActBtn("groupVi2",act(28));
        if(hantsexa == 2 && hantsexb > 6) makeActBtn("groupVa1",act(28));

        if(hantsexa == 3 && hantsexb <= 6) makeActBtn("groupViOa",act(26));
        if(hantsexa == 3 && hantsexb > 6) makeActBtn("groupViO",act(26));

        if(hantsexa == 4) makeActBtn("groupDPia",act(27));
        if(hantsexa == 5) makeActBtn("groupOia",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setAndrei();
        root->blow_job();
        setSergei();
        root->blow_job();
        setIgor();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1)
        {
            if(hantsexb < 6) makeActBtn("groupVas1",act(25));
            if(hantsexb == 6) makeActBtn("groupVa",act(25));
            if(hantsexb > 6) makeActBtn("groupVs",act(25));
        }
        else if(hantsexa == 2)
        {
            if(hantsexb < 6) makeActBtn("groupVaOsv",act(29));
            if(hantsexb > 6) makeActBtn("groupVOs",act(29));
            if(hantsexb == 6) makeActBtn("groupVaO",act(29));
        }
        else if(hantsexa == 3)
        {
            if(hantsexb < 5) makeActBtn("groupAsOa",act(25));
            if(hantsexb == 5) makeActBtn("groupAsO",act(25));
            if(hantsexb > 5) makeActBtn("groupAOa",act(25));
        }
        else
            makeActBtn("groupOsa",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
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
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
        setAndrei();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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

    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1 && hantsexb < 6) makeActBtn("groupORALsi1",act(21));
        if(hantsexa == 1 && hantsexb == 6) makeActBtn("groupORALs",act(21));
        if(hantsexa == 1 && hantsexb == 7) makeActBtn("groupORALi",act(21));
        if(hantsexa == 1 && hantsexb == 8) makeActBtn("groupORALend1",act(21));

        if(hantsexa == 2 && hantsexb <= 5) makeActBtn("groupVis1",act(25));
        if(hantsexa == 2 && hantsexb > 6) makeActBtn("groupVi1",act(25));
        if(hantsexa == 2 && hantsexb == 6) makeActBtn("groupVs1",act(25));

        if(hantsexa == 3 && hantsexb <= 5) makeActBtn("groupVsOi",act(26));
        if(hantsexa == 3 && hantsexb > 6) makeActBtn("groupVOi",act(26));
        if(hantsexa == 3 && hantsexb == 6) makeActBtn("groupVsO",act(26));

        if(hantsexa == 4) makeActBtn("groupDPis",act(27));
        if(hantsexa == 5) makeActBtn("groupOis",act(21));
    }
    else
        makeActBtn("groupfaint",act(13));
}
void Hanters::groupORALsi1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(58,60)));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(63));
        setSergei();
        root->blow_job();
        setIgor();
        root->blow_job();
    }
    if(root->gVEvent(forest_gopsex) == 3)
    {
        root->setDesc(str(64));
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    hantsexa = getRandInt(1,5);
    hantsexb = getRandInt(1,8);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1)
        {
            if(hantsexb < 6) makeActBtn("groupORALsi1",act(21));
            if(hantsexb == 6) makeActBtn("groupORALs",act(21));
            if(hantsexb == 7) makeActBtn("groupORALi",act(21));
            if(hantsexb == 8) makeActBtn("groupORALend1",act(21));
        }
        else if(hantsexa == 2)
        {
            if(hantsexb <= 5) makeActBtn("groupVis1",act(25));
            if(hantsexb > 6) makeActBtn("groupVi1",act(25));
            if(hantsexb == 6) makeActBtn("groupVs1",act(25));
        }
        else if(hantsexa == 3)
        {
            if(hantsexb <= 5) makeActBtn("groupVsOi",act(26));
            if(hantsexb > 6) makeActBtn("groupVOi",act(26));
            if(hantsexb == 6) makeActBtn("groupVsO",act(26));
        }
        else if(hantsexa == 4)
            makeActBtn("groupDPis",act(27));
        else
            makeActBtn("groupOis",act(21));
    }
    else
       makeActBtn("groupfaint",act(13));
}
void Hanters::groupORALasi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->uVSex(lubonus,3);
    root->setImage(media(getRandInt(34,42)));
    root->setDesc(str(47));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        setAndrei();
        root->blow_job();
        setSergei();
        root->blow_job();
        setIgor();
    }
    if(root->gVEvent(forest_gopsex) == 3)
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
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("groupORALasi",act(21));
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
        if(hantsexa == 5) //Лечь на бок
        {
            if(hantsexb > 5) makeActBtn("groupVsOaHi",act(26));
            if(hantsexb == 5) makeActBtn("groupVsOHi",act(26));
            if(hantsexb < 5) makeActBtn("groupVOaHi",act(26));
        }
    }
    else
        makeActBtn("groupfaint",act(13));
}

void Hanters::groupVias()
{
    root->sVSex(pose,2);
    root->incTime(5);
    if(root->vSex(lubonus) == 0)
        root->uVSex(lubonus,2);
    root->setImage(media(getRandInt(74,78)));
    if(root->gVEvent(hantersexnude) == 1 || root->gVEvent(forest_hantersex) == 3)
    {
        root->setDesc(str(73));
        setSergei();
        root->blow_job();
        setAndrei();
        root->blow_job();
        setIgor();
    }
    if(root->gVEvent(forest_gopsex) == 3)
    {
        root->setDesc(str(74));
        setKolyamba();
        root->blow_job();
        setMitka();
        root->blow_job();
        setVasyan();
    }
    if(boyCsex == 0)
    {
        boyCsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,5);
    hantsexb = getRandInt(1,8);
    if(root->vStatus(health) > 50)
    {
        if (hantsexa == 1) makeActBtn();
        if (hantsexa == 2)
        {
            if(hantsexb > 5) makeActBtn();
            if(hantsexb == 3) makeActBtn();
            if(hantsexb == 4) makeActBtn();
            if(hantsexb == 5) makeActBtn();
            if(hantsexb < 3) makeActBtn();
        }
        if(hantsexa == 3)
        {
            if(hantsexb > 5) makeActBtn();
            if(hantsexb == 5) makeActBtn();
            if(hantsexb < 5) makeActBtn();
        }
        if(hantsexa == 4)
        {
            if(hantsexb < 5) makeActBtn();
            if(hantsexb > 5) makeActBtn();
            if(hantsexb == 6) makeActBtn();
            if(hantsexb == 5) makeActBtn();
        }
        if(hantsexa == 5)
        {
            if(hantsexb > 5) makeActBtn();
            if(hantsexb == 5) makeActBtn();
            if(hantsexb < 5) makeActBtn();
        }
    }
    else

}

void Hanters::hanters_talk()
{

}

QString Hanters::str(int id)
{
    QString str[101];
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
        str[75] = "";
        str[76] = "";
        str[77] = "";
        str[78] = "";
        str[79] = "";
    }
    if(id >= 80 && id < 100)
    {
        str[80] = "";
        str[81] = "";
        str[82] = "";
        str[83] = "";
        str[84] = "";
        str[85] = "";
        str[86] = "";
        str[87] = "";
        str[88] = "";
        str[89] = "";
        str[90] = "";
        str[91] = "";
        str[92] = "";
        str[93] = "";
        str[94] = "";
        str[95] = "";
        str[96] = "";
        str[97] = "";
        str[98] = "";
        str[99] = "";
    }
    str[100] = "";

    return str[id];
}

QString Hanters::act(int id)
{
    QString act[51];
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
        act[30] = "";
        act[31] = "";
        act[32] = "";
        act[33] = "";
        act[34] = "";
        act[35] = "";
        act[36] = "";
        act[37] = "";
        act[38] = "";
        act[39] = "";
    }
    if(id >= 40)
    {
        act[40] = "";
        act[41] = "";
        act[42] = "";
        act[43] = "";
        act[44] = "";
        act[45] = "";
        act[46] = "";
        act[47] = "";
        act[48] = "";
        act[49] = "";
        act[50] = "";
    }
    return act[id];
}

QString Hanters::media(int id)
{
    QString med[101];
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
        med[79] = "";
    }
    if(id >= 80 && id < 100)
    {
        med[80] = "";
        med[81] = "";
        med[82] = "";
        med[83] = "";
        med[84] = "";
        med[85] = "";
        med[86] = "";
        med[87] = "";
        med[88] = "";
        med[89] = "";
        med[90] = "";
        med[91] = "";
        med[92] = "";
        med[93] = "";
        med[94] = "";
        med[95] = "";
        med[96] = "";
        med[97] = "";
        med[98] = "";
        med[99] = "";
    }
    med[100] = "";
    return med[id];
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

void Hanters::setSergei()
{
    root->setBoyName(str(38));
    root->sVSex(silavag,1);
    root->sVSex(dick,18);
}

void Hanters::setIgor()
{
    root->setBoyName(str(37));
    root->sVSex(silavag,2);
    root->sVSex(dick,16);
}

void Hanters::setMitka()
{
    root->setBoyName(str(54));
    root->sVSex(silavag,0);
    root->sVSex(dick,16);
}

void Hanters::setKolyamba()
{
    root->setBoyName(str(55));
    root->sVSex(silavag,0);
    root->sVSex(dick,15);
}

void Hanters::setVasyan()
{
    root->setBoyName(str(56));
    root->sVSex(silavag,0);
    root->sVSex(dick,14);
}
