#include "pirat.h"
#include "../eventhandler.h"
#include "../../Functions.h"
#include "../../menu/qactbutton.h"

Pirat::Pirat(EventHandler* ptr): root(ptr) {}

void Pirat::start(QString arg)
{
    if (root->gVEvent(pir_pirat) == 0 && root->gVEvent(know_no_pirat) == 1 && root->gVEvent(pir_pirat_search) == 0)
    {
        makeActBtn("search", act(0));
    }
    else
    {
        root->addDesc("<br>В будке сидит Пират");
        makeActBtn("pir_pirat", act(1));
    }
    if(root->gVEvent(pir_piratsuka) >= 50 && root->gVEvent(pir_piratfriend) >= 70 && root->gVEvent(pir_pirat_sex) != root->vStatus(daystart))
    {
        pirat_forced();
    }
}

void Pirat::actionHandler(QString action)
{
    root->rendImagePage();
    root->clearActions();
    if(action == "pir_pirat")
    {
        pirPirat();
    }
    if(action == "search")
    {
        pirat_search();
    }
    if(action == "go&watch")
    {
        root->incTime(5);
        root->sVEvent(pirat, 1);
        root->sVEvent(pir_pirat_search, 1);
        root->setImage(media(0));
        root->setDesc(evStr(22));
        makeActBtn("disperse", act(2));
        makeActBtn("wait", act(3));
    }
    if(action == "goaway" || action == "next")
    {
        root->changeLoc(lgadukino);
    }
    if(action == "disperse")
    {
        root->incTime(5);
        root->uVSkill(domination, 1);
        root->uVEvent(pir_piratfriend, -5);
        root->setImage(media(1));
        root->setDesc(evStr(23));
        makeActBtn("next2", act(4));
    }
    if(action == "wait")
    {
        root->incTime(10);
        root->uVStatus(horny,10);
        root->uVEvent(pir_piratfriend, 1);
        root->setImage(media(2));
        root->setDesc(evStr(24));
        makeActBtn("next2", act(4));
    }
    if(action == "next2")
    {
        root->incTime(10);
        root->changeLoc(lgadsarai);
    }
    if(action == "goHome")
    {
        root->changeLoc(lgadhouse);
    }
    if(action == "push_away")
    {
        spurn();
    }
    if(action == "submiss")
    {
        root->uVStatus(horny, getRandInt(5,10));
        root->incTime(2);
        root->uVSkill(domination, -1);
        root->sVEvent(pir_piratknow, getRandInt(0,1));
        root->sVEvent(pir_piratHorny, 0);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        root->uVEvent(pir_zoo,1);
        root->setImage(media(3));
        root->setDesc(evStr(3));
        if(root->gVEvent(pir_piratknow) == 1)
        {
            if(root->vBody(vagina) == 0)
            {
                makeActBtn("submiss_wait1", act(5));
            }
            else
            {
                root->setImage(media(4));
                makeActBtn("submiss_wait2", act(5));
            }
        }
        else
        {
            makeActBtn("submiss_wait3", act(5));
        }
    }
    if(action == "submiss_wait1")
    {
        if(root->gVEvent(pir_piratsuka) < 30)
            root->uVEvent(pir_piratsuka, 5);
        root->uVStatus(horny, getRandInt(5,10));
        root->incTime(30);
        root->sVBody(vagina,5);
        root->sVSex(vgape,3);
        //vgape_time
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVSkill(domination, -10);
        root->setImage(media(5));
        root->setDesc(evStr(4));
        makeActBtn("next3", act(6));
    }
    if(action == "next3")
    {
        root->changeLoc(lgadsarai);
    }
    if(action == "submiss_wait2")
    {
        int vag = root->vBody(vagina);
        if(vag < 10)
        {
            root->incTime(2);
            root->uVBody(vagina,5);
            root->sVSex(vgape,3);
            root->sVStatus(horny, 0);
            root->setImage(media(6));
            root->setDesc(evStr(5));
            makeActBtn("next3", act(7));
        }
        else if(vag >= 10 && vag < 25)
        {
            root->incTime(20);
            root->uVBody(vagina,4);
            root->sVSex(vgape, 2);
            root->uVStatus(horny, getRandInt(15,25));
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->sVStatus(horny, 0);
                root->sVStatus(mood, 100);
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(evStr(6));
            }
            else
            {
                root->setImage(media(6));
                root->setDesc(evStr(7));
            }
            makeActBtn("next3", act(7));
        }
        else if(vag >=25 && vag < 35)
        {
            root->incTime(20);
            root->uVBody(vagina,3);
            root->uVStatus(horny, getRandInt(25,50));
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood, 100);
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(evStr(8));
            }
            else
            {
                root->setImage(media(8));
                root->setDesc(evStr(9));
            }
            makeActBtn("next3", act(7));
        }
        else if(vag >= 35)
        {
            root->incTime(15);
            root->uVBody(vagina,1);
            root->uVStatus(horny, getRandInt(99,100));
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(evStr(10));
            }
            else
            {
                root->setImage(media(8));
                root->setDesc(evStr(11));
            }
            makeActBtn("next3", act(7));
        }
    }
    if(action == "submiss_wait3")
    {
        int anusVal = root->vBody(anus);
        root->incTime(2);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->rendVideoPage();
        root->setVideo(media(9), 868, 540);
        if(anusVal < 10)
        {
            root->incTime(20);
            root->uVBody(anus,5);
            root->sVSex(agape,3);
            root->sVStatus(horny,0);
            root->cum("anus");
            //gs stat
            root->setDesc(evStr(12));
            makeActBtn("next3", act(7));
        }
        else if(anusVal >= 10 && anusVal < 25)
        {
            root->incTime(20);
            root->uVBody(anus,3);
            root->sVSex(agape,2);
            root->uVStatus(horny, -getRandInt(15,30));
            root->cum("anus");
            //gs stat
            root->setDesc(evStr(13));
            makeActBtn("next3", act(7));
        }
        else if(anusVal >= 25 && anusVal < 35)
        {
            root->incTime(20);
            root->uVBody(anus,2);
            root->sVSex(agape,1);
            root->uVStatus(horny, getRandInt(15,30));
            root->cum("anus");
            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                root->uVSC(analOrgasm,1);
                root->rendImagePage();
                root->setImage(media(10));
                root->setDesc(evStr(14));
            }
            else
            {
                root->setDesc(evStr(15));
            }
            makeActBtn("next3", act(7));
        }
        else if(anusVal >= 35)
        {
            root->incTime(20);
            root->uVBody(anus,1);
            root->uVStatus(horny, getRandInt(50,100));
            root->cum("anus");
            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(analOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                root->rendImagePage();
                root->setImage(media(11));
                root->setDesc(evStr(16));
            }
            else
            {
                root->setDesc(evStr(17));
            }
            makeActBtn("next3", act(7));
        }
    }
    if(action == "stroking")
    {
        stroking();
    }
    if(action == "stroking_horny")
    {
        strokingHorny();
    }
    if(action == "scream")
    {
        scream();
    }
    if(action == "dog_lick")
    {
        dogLick();
    }
    if(action == "dog_lick_ass")
    {
        dogLickAss();
    }
    if(action == "tolerate")
    {
        root->sVEvent(pir_piratHorny, 0);
        root->incTime(5);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVEvent(pir_piratsuka, 1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        root->uVSkill(domination, -1);
        //gs stat
        root->setImage(media(12));
        if(root->gVEvent(grandparents_ingadsarai) == 0)
            root->setDesc(str(7));
        if(root->gVEvent(grandpa_ingadsarai) == 1)
            root->addDesc(str(8));
        if(root->gVEvent(grandma_ingadsarai) == 1)
            root->addDesc(str(9));
        if(root->gVEvent(grandpa_ingadsarai) == 1)
            makeActBtn("push_away", act(9));
        if(root->gVEvent(grandpa_ingadsarai) == 1)
            makeActBtn("scream", act(10));
        makeActBtn("next4", act(8));
    }
    if(action == "next4")
    {
        if(root->gVEvent(grandpa_ingadsarai) == 1)
        {
            root->uVQuest(grandpaQW,-1);
        }
        if(root->gVEvent(grandma_ingadsarai) == 1)
        {
            root->uVQuest(grandmaQW,-1);
        }
        root->changeLoc(lgadsarai);
    }
    if(action == "onAllFour")
    {
        root->uVStatus(horny, getRandInt(10,20));
        root->sVEvent(pir_piratHorny, 0);
        root->incTime(5);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVEvent(pir_piratsuka,1);
        root->uVSkill(domination, -1);
        root->uVStatus(cumFrot, 1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        //gs stat
        root->setImage(media(13));
        if(root->gVEvent(grandparents_ingadsarai) == 0)
            root->setDesc(str(11));
        if(root->gVEvent(grandpa_ingadsarai) == 1)
        {
            root->setDesc(str(12));
            root->uVQuest(grandpaQW,-5);
        }
        if(root->gVEvent(grandma_ingadsarai) == 1)
        {
            root->setDesc(str(13));
            root->uVQuest(grandmaQW, -5);
        }
        makeActBtn("next3", act(8));
    }
    if(action == "handjob")
    {
        pirDogHJ();
    }
    if(action == "blowjob")
    {
        pirDogBJ();
    }
    if(action == "undress&onAllFour")
    {
        root->uVStatus(horny, getRandInt(5,10));
        root->incTime(2);
        root->setImage(media(3));
        root->setDesc(str(15));
        makeActBtn("pir_DogVag", act(11));
        makeActBtn("pir_DogAnal", act(12));
    }
    if(action == "pir_DogVag")
        pirDogVag();
    if(action == "pir_DogAnal")
        pirDogAnal();
    if(action == "next5")
    {
        root->uVEvent(pir_piratfriend, -1);
        root->changeLoc(lgadsarai);
    }
    if(action == "preHandJob")
    {
        root->incTime(5);
        //gs stat
        root->setImage(media(14));
        root->setDesc(sexStr(18));
        makeActBtn("handjob", act(13));
        makeActBtn("next3", act(14));
    }
    if(action == "comeToLife")
    {
        root->incTime(5);
        //gs stat
        root->setImage(media(15));
        root->setDesc(sexStr(19));
        makeActBtn("takeoff", act(15));
        if(root->gVEvent(pir_DogVag) == 1 || root->gVEvent(pir_DogAnal) == 1)
        {
            makeActBtn("pir_DogVag", act(11));
            makeActBtn("pir_DogAnal", act(12));
        }
    }
    if(action == "takeoff")
    {
        int temp = getRandInt(50,120);
        if(root->vSkill(agility) > temp)
        {
            root->incTime(1);
            root->uVEvent(pir_piratHorny, -40);
            root->setImage(media(1));
            root->setDesc(sexStr(20));
            makeActBtn("next3", act(8));
        }
        else
        {
            root->incTime(10);
            root->sVEvent(pir_piratHorny,0);
            root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
            int temp = getRandInt(1,3);
            //gs stat
            root->setImage(media(16));
            root->setDesc(sexStr(21));
            makeActBtn("next6" + intQStr(temp), act(4));
        }
    }
    if(action == "next61")
    {
        root->incTime(30);
        root->sVEvent(pir_DogAnal, 1);
        root->uVSC(analSex, 1);
        int anusVal = root->vBody(anus);
        if(anusVal < 10)
        {
            root->uVStatus(mood, -50);
            root->uVBody(anus,5);
            root->sVSex(agape,3);
            root->sVStatus(horny,0);
        }
        if(anusVal >= 10 && anusVal < 25)
        {
            root->uVStatus(mood, -20);
            root->uVBody(anus,3);
            root->sVSex(agape,2);
            root->uVStatus(horny, -getRandInt(15,30));
        }
        if(anusVal >= 25 && anusVal < 35)
        {
            root->uVStatus(mood, -10);
            root->uVBody(anus,2);
            root->sVSex(agape,1);
            root->uVStatus(horny,getRandInt(15,30));
        }
        if(anusVal >= 35)
        {
            root->uVBody(anus,1);
            root->uVStatus(horny,getRandInt(50,100));
        }
        root->uVSkill(domination, -1);
        root->cum("anus");
        //gs stat
        root->setImage(media(17));
        if(root->vStatus(horny) >= 100)
        {
            root->uVSC(orgasm,1);
            root->uVSC(analOrgasm,1);
            root->sVStatus(horny,0);
            root->sVStatus(mood,100);
            //gs stat
            root->setDesc(sexStr(22));
        }
        else
        {
            if(anusVal < 10)
                root->setDesc(sexStr(23));
            else if(anusVal >= 10 && anusVal < 25)
                root->setDesc(sexStr(24));
            else if(anusVal >= 25 && anusVal < 35)
                root->setDesc(sexStr(25));
            else if(anusVal >= 35)
                root->setDesc(sexStr(26));
        }
        makeActBtn("next3", act(8));
    }
    if(action == "next62" || action == "next63")
    {
        if(root->vBody(vagina) == 0)
        {
            root->sVEvent(pir_DogVag, 1);
            root->uVEvent(pir_piratsuka,5);
            root->uVStatus(horny,0);
            root->incTime(10);
            root->uVBody(vagina,1);
            root->sVSex(vgape,1);
            root->uVStatus(mood, -50);
            root->uVSkill(domination, -10);
            root->uVSC(vaginalSex, 1);
            //gs stat
            root->setImage(media(5));
            root->setDesc(sexStr(27));
            makeActBtn("next64", act(4));
        }
        else
        {
            root->sVEvent(pir_DogVag, 1);
            root->incTime(30);
            root->cum("pussy");
            root->uVSC(vaginalSex,1);
            int vag = root->vBody(vagina);
            if(vag < 10)
            {
                root->uVStatus(mood,-50);
                root->uVBody(vagina,5);
                root->sVSex(vgape,3);
                root->sVStatus(horny,0);
            }
            else if(vag >= 10 && vag < 25)
            {
                root->uVBody(vagina,4);
                root->sVSex(vgape,2);
                root->uVStatus(horny, getRandInt(15,25));
            }
            else if(vag >= 25 && vag < 35)
            {
                root->uVBody(vagina,3);
                root->sVSex(vgape,1);
                root->uVStatus(horny,getRandInt(25,50));
            }
            else if(vag >= 35)
            {
                root->uVBody(vagina,1);
                root->uVStatus(horny,getRandInt(50,75));
            }
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(vaginalOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                if(root->vBody(piercingG) == 1)
                    root->setImage(media(7));
                else
                    root->setImage(media(8));
                root->setDesc(sexStr(29));
            }
            else
            {
                int vag = root->vBody(vagina);
                root->setImage(media(6));
                if(vag < 10)
                    root->setDesc(sexStr(30));
                else if(vag >= 10 && vag < 25)
                    root->setDesc(sexStr(31));
                else if (vag >= 25 && vag < 35)
                    root->setDesc(sexStr(32));
                else if(vag >= 35)
                    root->setDesc(sexStr(33));
            }
            makeActBtn("next3", act(8));
        }
    }
    if(action == "next64")
    {
        root->incTime(20);
        root->uVBody(vagina,5);
        root->sVSex(vgape,3);
        root->uVStatus(mood, -50);
        root->cum("pussy");
        //gs stat
        root->setImage(media(6));
        root->setDesc(sexStr(28));
        makeActBtn("next3", act(8));
    }
    if(action == "mastr")
    {
        root->uVStatus(horny, getRandInt(20,30));
        root->incTime(10);
        root->sVEvent(pir_piratHorny, 0);
        root->uVStatus(mood, root->vStatus(mood)/20);
        root->sVEvent(pir_DogHJ, 1);
        //gs stat
        root->setImage(media(18));
        if(root->gVEvent(pir_piratsuka) < 10)
        {
            root->setDesc(sexStr(38));
            makeActBtn("pir_pirat", act(8));
        }
        else
        {
            root->setDesc(sexStr(39));
            makeActBtn("takeInMouth", act(16));
            makeActBtn("next3", act(17));
        }
    }
    if(action == "takeInMouth")
    {
        root->uVStatus(horny, getRandInt(5,15));
        root->incTime(5);
        root->uVEvent(pir_piratsuka, 5);
        root->sVEvent(pir_DogBJ,1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        //gs stat
        root->setImage(media(19));
        root->setDesc(sexStr(40));
        makeActBtn("suckNext", act(18));
    }
    if(action == "suckNext")
    {
        root->uVStatus(horny, getRandInt(25,40));
        root->incTime(5);
        root->sVEvent(pir_piratHorny,0);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVStatus(cumLips,1);
        //gs stat
        root->setImage(media(20));
        root->setDesc(sexStr(41));
        makeActBtn("pir_pirat", act(8));
    }
    if(action == "mastr2")
    {
        root->uVStatus(horny, getRandInt(20,30));
        root->incTime(10);
        root->sVEvent(pir_piratHorny,0);
        root->uVEvent(pir_piratsuka, 1);
        root->uVStatus(mood, root->vStatus(mood)/20);
        //gs stat
        root->setImage(media(18));
        root->setDesc(sexStr(45));
        makeActBtn("pir_pirat", act(8));
    }
    if(action == "suck2")
    {
        root->uVStatus(horny, getRandInt(5,15));
        root->incTime(5);
        root->uVEvent(pir_piratsuka, 2);
        root->sVEvent(pir_DogBJ,1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        int temp = getRandInt(1,3);
        root->setImage(media(19));
        root->setDesc(sexStr(46));
        if(temp == 1)
        {
            makeActBtn("cumOnFace", act(19));
        }
        else
        {
            makeActBtn("cumInMouth", act(20));
        }
    }
    if(action == "cumOnFace")
    {
        root->uVStatus(horny, getRandInt(15,30));
        root->incTime(5);
        root->sVEvent(pir_piratHorny,0);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->cum("face");
        root->setImage(media(21));
        root->setDesc(sexStr(47));
        makeActBtn("pir_pirat", act(8));
    }
    if(action == "cumInMouth")
    {
        root->uVStatus(horny, getRandInt(25,40));
        root->incTime(5);
        root->sVEvent(pir_piratHorny,0);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->cum("lip");
        root->setImage(media(20));
        root->setDesc(sexStr(48));
        makeActBtn("pir_pirat", act(8));
    }
    if(action == "allowVag")
    {
        root->incTime(2);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVSkill(domination, -1);
        //gs stat
        root->setImage(media(6));
        root->setDesc(sexStr(52));
        int vag = root->vBody(vagina);
        if(vag < 10)
        {
            root->incTime(20);
            root->uVBody(vagina,4);
            root->sVSex(vgape,3);
            root->sVStatus(horny,0);
            root->cum("pussy");
            //gs stat
            root->addDesc(sexStr(53));
            makeActBtn("next3", act(8));
        }
        else if(vag >= 10 && vag < 25)
        {
            root->incTime(20);
            root->uVBody(vagina,3);
            root->sVSex(vgape,2);
            root->uVStatus(horny, -getRandInt(15,30));

            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(vaginalOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                root->cum("pussy");
                //gs stat
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(sexStr(54));
            }
            else
                root->setDesc(sexStr(55));
            makeActBtn("next3", act(8));
        }
        else if(vag >=25 && vag < 35)
        {
            root->incTime(20);
            root->uVBody(vagina,2);
            root->uVStatus(horny, getRandInt(25,50));
            root->cum("pussy");
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(vaginalOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                //gs stat
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(sexStr(56));
            }
            else
            {
                root->setDesc(sexStr(57));
            }
            makeActBtn("next3", act(8));
        }
        else if(vag >= 35)
        {
            root->incTime(20);
            root->uVBody(vagina,1);
            root->uVStatus(horny, getRandInt(50,100));
            root->cum("pussy");
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(vaginalOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                if(root->vBody(piercingG) == 1)
                {
                    root->setImage(media(7));
                }
                else
                {
                    root->setImage(media(8));
                }
                root->setDesc(sexStr(59));
            }
            else
                root->setDesc(sexStr(60));
            makeActBtn("next3", act(8));
        }
    }
    if(action == "notAllowVag")
    {
        root->incTime(2);
        root->sVStatus(mood, root->vStatus(mood)/2);
        int piratboggle = getRandInt(1,5);
        if(piratboggle <= 2)
        {
            root->setImage(media(4));
            root->setDesc(sexStr(61));
            int vag = root->vBody(vagina);
            if(vag < 15)
            {
                root->incTime(10);
                root->uVBody(vagina,1);
                if(root->vSex(vgape) < 3)
                    root->uVSex(vgape,1);
                root->uVStatus(horny, -getRandInt(10,20));
                root->cum("pussy");
                root->addDesc(sexStr(62));
                makeActBtn("next3", act(8));
            }
            else if(vag >=15 && vag < 25)
            {
                root->incTime(10);
                root->uVBody(vagina,1);
                root->uVStatus(horny, getRandInt(15,30));
                root->cum("pussy");
                if(root->vStatus(horny) >= 100)
                {
                    root->uVSC(orgasm,1);
                    root->uVSC(vaginalOrgasm,1);
                    root->sVStatus(horny,0);
                    root->sVStatus(mood,100);
                    if(root->vBody(piercingG) == 1)
                    {
                        root->setImage(media(22));
                    }
                    else
                    {
                        root->setImage(media(23));
                    }
                    root->addDesc(sexStr(63));
                }
                else
                    root->addDesc(sexStr(64));
                makeActBtn("next3", act(8));
            }
            else if(vag >= 25 && vag < 35)
            {
                root->incTime(20);
                root->uVStatus(horny,getRandInt(30,50));
                root->cum("pussy");
                if(root->vStatus(horny) >= 100)
                {
                    root->uVSC(orgasm,1);
                    root->uVSC(vaginalOrgasm,1);
                    root->sVStatus(horny,0);
                    root->sVStatus(mood,100);
                    if(root->vBody(piercingG) == 1)
                    {
                        root->setImage(media(22));
                    }
                    else
                    {
                        root->setImage(media(23));
                    }
                    root->addDesc(sexStr(65));
                }
                else
                    root->addDesc(sexStr(66));
                makeActBtn("next3", act(8));
            }
            else if(vag >= 35)
            {
                root->incTime(20);
                root->uVStatus(horny, getRandInt(15,30));
                root->cum("pussy");
                if(root->vStatus(horny) >= 100)
                {
                    root->uVSC(orgasm,1);
                    root->uVSC(vaginalOrgasm,1);
                    root->sVStatus(horny,0);
                    root->sVStatus(mood,100);
                    if(root->vBody(piercingG) == 1)
                    {
                        root->setImage(media(22));
                    }
                    else
                    {
                        root->setImage(media(23));
                    }
                    root->addDesc(sexStr(67));
                }
                else
                    root->addDesc(sexStr(68));
                makeActBtn("next3", act(8));
            }

        }
        else
        {
            int vag = root->vBody(vagina);
            if(vag < 15)
            {
                root->incTime(10);
                root->uVBody(vagina,1);
                if(root->vSex(vgape) < 3)
                    root->uVSex(vgape,1);
                root->uVStatus(horny, - getRandInt(10,20));
                root->setImage(media(24));
                root->setDesc(sexStr(69));
                makeActBtn("pir_DogVag", act(21));
                makeActBtn("pir_pirat", act(22));
            }
            else if(vag >= 15 && vag < 25)
            {
                root->incTime(10);
                root->uVBody(vagina,1);
                root->uVStatus(horny, getRandInt(15,30));
                root->setImage(media(24));
                root->setDesc(sexStr(70));
                makeActBtn("pir_DogVag", act(21));
                makeActBtn("pir_pirat", act(22));
            }
            else if(vag >= 25 && vag < 35)
            {
                root->incTime(20);
                root->uVStatus(horny, getRandInt(30,50));
                root->setImage(media(24));
                root->setDesc(sexStr(71));
                makeActBtn("pir_DogVag", act(21));
                makeActBtn("pir_pirat", act(22));
            }
            else if(vag >= 35)
            {
                root->incTime(20);
                root->uVStatus(horny, getRandInt(15,30));
                root->setImage(media(24));
                root->setDesc(sexStr(72));
                makeActBtn("pir_DogVag", act(21));
                makeActBtn("pir_pirat", act(22));
            }
        }
    }
    if(action == "allowAnal")
    {
        root->incTime(2);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVSkill(domination, -1);
        //gs stat
        root->setImage(media(17));
        root->setDesc(sexStr(75));
        int piratboggle = getRandInt(0,5);
        int anusVal = root->vBody(anus);
        if(piratboggle <= 4)
        {
            if(anusVal < 15)
            {
                root->incTime(20);
                root->uVBody(anus,4);
                root->sVSex(agape,3);
                root->sVStatus(horny,0);
                root->cum("anus");
                //gs stat
                root->addDesc(sexStr(76));
                makeActBtn("next3", act(8));
            }
            else if(anusVal >= 15 && anusVal < 25)
            {
                root->incTime(20);
                root->uVBody(anus,3);
                root->sVSex(agape,2);
                root->uVStatus(horny, -getRandInt(15,30));
                root->cum("anus");
                //gs stat
                root->addDesc(sexStr(77));
                makeActBtn("pir_pirat", act(8));
            }
            else if (anusVal >= 25 && anusVal < 35)
            {
                root->incTime(20);
                root->uVBody(anus,2);
                root->sVSex(agape,1);
                root->uVStatus(horny, getRandInt(15,30));
                root->cum("anus");
                //gs stat
                if(root->vStatus(horny) >= 100)
                {
                    root->uVSC(orgasm,1);
                    root->uVSC(analOrgasm,1);
                    root->sVStatus(horny,0);
                    root->sVStatus(mood,100);
                    //gs stat
                    root->setImage(media(11));
                    root->addDesc(sexStr(78));
                    makeActBtn("next3", act(8));
                }
                else
                {
                    root->addDesc(sexStr(79));
                    makeActBtn("pir_pirat", act(8));
                }
            }
            else if(anusVal >= 35)
            {
                root->incTime(20);
                root->uVBody(anus,1);
                root->uVStatus(horny, getRandInt(50,100));
                root->cum("anus");
                if(root->vStatus(horny) >= 100)
                {
                    root->uVSC(orgasm,1);
                    root->uVSC(analOrgasm,1);
                    root->sVStatus(horny,0);
                    root->sVStatus(mood,100);
                    root->setImage(media(11));
                    root->addDesc(sexStr(80));
                    makeActBtn("next3", act(8));
                }
                else
                {
                    root->addDesc(sexStr(81));
                    makeActBtn("pir_pirat", act(8));
                }
            }
        }
        else
        {
            if(anusVal < 15)
            {
                root->incTime(20);
                root->uVBody(anus,5);
                root->sVSex(agape,3);
                root->sVStatus(horny,0);
                root->cum("anus");
                //gs stat
                root->setImage(media(25));
                root->addDesc(sexStr(82));
                makeActBtn("next3", act(8));
            }
            else if(anusVal >= 15 && anusVal < 25)
            {
                root->incTime(20);
                root->uVBody(anus,5);
                root->sVSex(agape,3);
                root->sVStatus(horny,0);
                root->cum("anus");
                //gs stat
                root->setImage(media(25));
                root->addDesc(sexStr(83));
                makeActBtn("next3", act(8));
            }
            else if(anusVal >= 25 && anusVal < 35)
            {
                root->incTime(20);
                root->uVBody(anus,4);
                root->sVSex(agape,2);
                root->uVStatus(horny, -getRandInt(40,60));
                root->cum("anus");
                //gs stat
                root->setImage(media(25));
                root->addDesc(sexStr(84));
                makeActBtn("pir_pirat", act(8));
            }
            else if(anusVal >= 35)
            {
                root->incTime(5);
                root->uVBody(anus,3);
                root->sVSex(agape,1);
                root->uVStatus(horny, getRandInt(15,30));
                //gs stat
                root->setImage(media(25));
                root->addDesc(sexStr(85));
                makeActBtn("pir_pirat", act(8));
            }
        }
    }
    if (action == "notAllowAnal")
    {
        root->incTime(2);
        root->sVStatus(mood, root->vStatus(mood)/2);
        //gs stat
        root->setImage(media(26));
        root->setDesc(sexStr(86));
        int vAnus = root->vBody(anus);
        if(vAnus < 15)
        {
            root->incTime(10);
            root->uVBody(anus,1);
            root->sVSex(agape,2);
            root->uVStatus(horny, - getRandInt(15,30));
            root->cum("anus");
            //gs stat
            root->addDesc(sexStr(87));
            makeActBtn("pir_pirat", act(8));
        }
        else if(vAnus >= 15 && vAnus < 25)
        {
            root->incTime(10);
            root->uVBody(anus,1);
            root->uVStatus(horny, getRandInt(15,30));
            root->cum("anus");
            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(analOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                //gs stat
                root->setImage(media(27));
                root->addDesc(sexStr(88));
                makeActBtn("pir_pirat", act(8));
            }
            else
            {
                root->addDesc(sexStr(89));
                makeActBtn("next3", act(8));
            }
        }
        else if(vAnus >= 25 && vAnus < 35)
        {
            root->incTime(20);
            root->uVStatus(horny, getRandInt(30,50));
            root->cum("anus");
            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(analOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                //gs stat
                root->setImage(media(27));
                root->addDesc(sexStr(90));
                makeActBtn("next3", act(8));
            }
            else
            {
                root->addDesc(sexStr(91));
                makeActBtn("pir_pirat", act(8));
            }
        }
        else if(vAnus >= 35)
        {
            root->incTime(20);
            root->uVStatus(horny, getRandInt(50,100));
            root->cum("anus");
            //gs stat
            if(root->vStatus(horny) >= 100)
            {
                root->uVSC(orgasm,1);
                root->uVSC(analOrgasm,1);
                root->sVStatus(horny,0);
                root->sVStatus(mood,100);
                //gs stat
                root->setImage(media(27));
                root->addDesc(sexStr(92));
                makeActBtn("next3", act(8));
            }
            else
            {
                root->addDesc(sexStr(93));
                makeActBtn("pir_pirat", act(8));
            }
        }
    }
    if(action == "excite")
        excite();
    if(action == "licking_ass")
        lickingAss();
}

void Pirat::pirat_search()
{
    root->incTime(60);
    int tmp = getRandInt(1,2);
    if (tmp == 1)
    {
        root->setImage(media(28));
        root->setDesc(evStr(20));
        makeActBtn( "go&watch", act(23));
        makeActBtn( "goaway", act(24));
    }
    else
    {
        root->setImage(media(29));
        root->setDesc(evStr(21));
        makeActBtn( "next", act(4));
    }
}

void Pirat::pirat_forced()
{
    root->incTime(5);
    root->setImage(media(12));
    root->setDesc(evStr(0));
    if(root->gVEvent(grandpa_ingadsarai) == 1)
    {
        root->uVQuest(grandpaQW, -5);
        root->addDesc(evStr(1));
    }
    if(root->gVEvent(grandma_ingadsarai) == 1)
    {
        root->uVQuest(grandmaQW, -5);
        root->addDesc(evStr(2));
    }
    if(root->gVEvent(grandparents_ingadsarai) == 1)
    {
        makeActBtn( "goHome", act(8));
    }
    if(root->vSkill(domination) > 0)
    {
        makeActBtn( "push_away", act(25));
    }
    if(root->gVEvent(grandparents_ingadsarai) == 0)
    {
        makeActBtn( "submiss", act(26));
    }
}

void Pirat::grandparentsIngadsarai()
{
    if(root->gVEvent(grandma_ingadsarai) == 1)
    {
        root->addDesc(evStr(25));
    }
    if(root->gVEvent(grandpa_ingadsarai) == 1)
    {
        root->addDesc(evStr(26));
    }
}

void Pirat::spurn()
{
    root->sVEvent(pir_piratHorny, 20);
    root->uVEvent(pir_piratfriend, -1);
    root->incTime(1);
    root->uVSkill(domination,1);
    root->setImage(media(30));
    if(root->gVEvent(pir_piratsuka) < 3)
    {
        root->setDesc(sexStr(35));
    }
    else
    {
        root->setDesc(sexStr(36));
    }
    makeActBtn( "pir_pirat", act(8));
}

void Pirat::stroking()
{
    if(root->gVEvent(pir_piratfriend) < 5 && root->gVEvent(pir_stroking) != root->getDay())
    {
        root->sVEvent(pir_stroking, root->getDay());
        root->uVEvent(pir_piratfriend, 1);
    }
    if(root->gVEvent(pir_pirat_sex) != root->vStatus(daystart) && root->gVEvent(pir_stroking) != root->getDay() && root->gVEvent(pir_piratfriend) > 5)
    {
        root->sVEvent(pir_stroking,root->getDay());
        root->uVEvent(pir_piratHorny, 5);
    }
    root->incTime(15);
    root->rendVideoPage();
    if(((ClothMain*)root->getCloth(ClothType::Main))->getClothGroup() == ClothGroup::eveningDress)
        root->setVideo(media(31), 768, 540);
    else
    {
        int val = getRandInt(1,2);
        if(val == 1)
            root->setVideo(media(32), 720, 540);
        else
            root->setVideo(media(33), 768, 540);
    }
    root->setDesc(sexStr(0));
    makeActBtn( "next3", act(8));
}

void Pirat::strokingHorny()
{
    root->uVStatus(horny, 20);
    root->incTime(15);
    root->sVEvent(pir_stroking, root->getDay());
    //gs stat

    if(root->isSkirt())
    {
        if(root->isPanties())
        {
            root->setImage(media(34));
            root->setDesc(sexStr(1));
        }
        else
        {
            root->setImage(media(35));
            root->setDesc(sexStr(2));
        }
    }
    else
    {
        root->setImage(media(36));
        root->setDesc(sexStr(3));
    }
    root->addDesc(sexStr(4));
    if(root->gVEvent(grandparents_ingadsarai) == 0)
        makeActBtn( "dog_lick", act(27));
    makeActBtn( "next5", act(28));
}

void Pirat::scream()
{
    root->sVEvent(pir_piratHorny, 0);
    root->uVEvent(pir_piratfriend, -5);
    root->incTime(1);
    root->uVSkill(domination,1);
    if(root->gVEvent(grandpa_ingadsarai) == 1) { }
    if(root->gVEvent(grandma_ingadsarai) == 1) {}
    root->setImage(media(1));
    root->setDesc(sexStr(5));
    makeActBtn( "next3", act(8));
}

void Pirat::dogLick()
{
    root->sVStatus(horny, 0);
    root->uVSC(orgasm, 1);
    root->incTime(1);
    root->uVEvent(pir_zoo, 1);
    root->uVEvent(pir_pir_zoo, 1);
    root->sVEvent(pir_piratfriend, 6);
    root->sVStatus(mood, 100);
    root->uVEvent(pir_piratHorny, 10);
    //gs stat
    root->rendVideoPage();
    root->setVideo(media(37), 768, 540);
    if(root->isSkirt() && root->isPanties())
        root->setDesc(sexStr(6));
    else if(root->isSkirt() && !root->isPanties())
        root->setDesc(sexStr(7));
    else
        root->setDesc(sexStr(8));

    if(root->gVEvent(piratlick) == 0)
    {
        root->sVEvent(piratlick, 1);
        root->addDesc(sexStr(9));
    }
    else
    {
        root->addDesc(sexStr(10));
    }
    if(root->gVEvent(pir_piratsuka) >= 7 && root->gVEvent(pir_DogHJ) == 0)
    {
        root->addDesc(sexStr(11));
        makeActBtn( "nandjob", act(13));
        makeActBtn( "next3", act(14));
    }
    else
    {
        makeActBtn( "pir_pirat", act(8));
    }
}

void Pirat::dogLickAss()
{
    root->sVStatus(horny,0);
    root->uVSC(orgasm,1);
    root->incTime(1);
    root->uVEvent(pir_piratsuka, 1);
    root->uVEvent(pir_zoo, 1);
    root->sVStatus(mood,100);
    root->uVEvent(pir_piratHorny, getRandInt(10,30));
    //gs stat
    root->rendVideoPage();
    root->setVideo(media(38), 768,540);
    if(root->isSkirt() && root->isPanties())
        root->setDesc(sexStr(12));
    else if(root->isSkirt() && !root->isPanties())
        root->setDesc(sexStr(13));
    else
        root->setDesc(sexStr(14));
    if(root->gVEvent(piratlickass) == 0)
    {
        root->sVEvent(piratlickass,  1);
        root->addDesc(sexStr(15));
        makeActBtn( "next3", act(8));
    }
    else
    {
        root->addDesc(sexStr(16));
        if(root->gVEvent(pir_piratHorny) < 40)
        {
            root->addDesc(sexStr(17));
            makeActBtn( "next3", act(8));
        }
        else
        {
            if(root->gVEvent(pir_piratsuka) >= 7 && root->gVEvent(pir_DogHJ) == 0)
            {
                makeActBtn( "preHandJob", act(4));
            }
            else if(root->gVEvent(pir_piratsuka) >= 12)
            {
                makeActBtn( "comeToLife", act(29));
            }
            else
            {
                root->addDesc(sexStr(34));
                makeActBtn( "pir_pirat", act(8));
            }
        }
    }
}

void Pirat::pirDogHJ()
{
    root->uVStatus(horny, getRandInt(5,15));
    root->incTime(1);
    root->uVEvent(pir_piratsuka, 1);
    root->uVEvent(pir_zoo, 1);
    root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
    //gs stat
    root->setImage(media(39));
    root->setDesc(sexStr(37));
    makeActBtn( "mastr", act(30));
}

void Pirat::pirDogBJ()
{
    root->uVStatus(horny, getRandInt(5,15));
    root->incTime(1);
    root->uVEvent(pir_zoo, 1);
    root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
    //gs stat
    root->setImage(media(39));
    root->setDesc(sexStr(44));
    makeActBtn( "mastr2", act(30));
    makeActBtn( "suck2", act(16));
}

void Pirat::pirDogVag()
{
    if(root->vSex(vgape) > 1)
    {
        root->setImage(media(3));
        root->setDesc(sexStr(49));
        makeActBtn( "pir_pirat", act(7));
    }
    else
    {
        root->incTime(2);
        root->sVEvent(pir_piratHorny, 0);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->uVEvent(pir_piratsuka, 3);
        root->uVEvent(pir_zoo, 1);
        root->sVEvent(pir_DogVag, 1);
        root->uVSC(vaginalSex,1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        //gs stat
        if(root->vBody(vagina) == 0)
        {
            root->uVEvent(pir_piratsuka, 5);
            root->sVStatus(horny,0);
            root->incTime(30);
            root->uVBody(vagina,5);
            root->sVSex(vgape,3);
            root->uVStatus(mood,-50);
            root->cum("pussy");
            //gs stat
            root->setImage(media(5));
            root->setDesc(sexStr(50));
        }
        else
        {
            root->setImage(media(4));
            root->setDesc(sexStr(51));
        }
        if(root->vBody(vagina) == 0)
        {
            makeActBtn( "next3", act(8));
        }
        if(root->vBody(vagina) > 0)
        {
            makeActBtn( "allowVag", act(31));
            makeActBtn( "notAllowVag", "Предотвратить");
        }
    }
}

void Pirat::pirDogAnal()
{
    if(root->vSex(agape) > 1)
    {
        root->setImage(media(3));
        root->setDesc(sexStr(73));
        makeActBtn( "pir_pirat", act(7));
    }
    else
    {
        root->uVEvent(pir_piratsuka, 3);
        root->incTime(5);
        root->sVEvent(pir_piratHorny, 0);
        root->sVStatus(mood, root->vStatus(mood)/2);
        root->sVEvent(pir_DogAnal,1);
        root->uVSC(analSex, 1);
        root->uVEvent(pir_zoo,1);
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        //gs stat
        root->setImage(media(26));
        root->setDesc(sexStr(74));
        makeActBtn( "allowAnal", act(31));
        makeActBtn( "notAllowAnal", act(32));
    }
}

void Pirat::lickingAss()
{
    root->uVEvent(pir_piratHorny, 30);
    root->incTime(10);
    root->uVStatus(horny, getRandInt(10,20));
    //gs stat
    root->setImage(media(40));
    root->setDesc(sexStr(94));
    makeActBtn( "pir_pirat", act(7));
}

void Pirat::excite()
{
    root->rendVideoPage();
    root->incTime(10);
    root->sVEvent(pir_piratHorny, 20);
    int temp = getRandInt(1,10);
    if(temp == 1)
    {
        root->sVEvent(pir_pirat_sex, root->vStatus(daystart));
        root->setVideo(media(42), 768, 540);
        root->setDesc(sexStr(42));
        makeActBtn( "next3", act(4));
    }
    if(temp > 1)
    {
        root->setVideo(media(41), 768, 540);
        root->setDesc(sexStr(43));
        makeActBtn( "pir_pirat", act(4));
    }
}

void Pirat::pirPirat()
{
    if(root->gVEvent(pir_piratfriend) < 5)
    {
        root->incTime(5);
        //gs stat
        root->setImage(media(30));
        root->setDesc(str(0));
        grandparentsIngadsarai();
        makeActBtn( "stroking", act(33));
    }
    if(root->gVEvent(pir_piratfriend) == 5)
    {
        root->incTime(5);
        //gs stat
        root->setImage(media(30));
        if(root->vStatus(horny) < 40)
            root->setDesc(str(1));
        else
            root->setDesc(str(2));
        grandparentsIngadsarai();
        if(root->vStatus(horny) < 40)
            makeActBtn( "stroking", act(33));
        else if(root->vStatus(horny) >= 40)
            makeActBtn( "stroking_horny", act(33));
        makeActBtn( "next3", act(8));
    }
    if(root->gVEvent(pir_piratfriend) > 5)
    {
        if(root->gVEvent(pir_piratHorny) < 40)
        {
            if(root->vStatus(horny) < 40)
            {
                root->setImage(media(30));
                if(root->gVEvent(pir_piratHorny) < 20)
                    root->setDesc(str(3));
                else
                    root->setDesc(str(4));
            }
            else
            {
                root->setImage(media(34));
                root->setDesc(str(5));
            }
            grandparentsIngadsarai();
            if(root->vStatus(horny) >= 40)
                makeActBtn( "scream", act(10));
            if(root->vStatus(horny) >= 40 && root->gVEvent(grandparents_ingadsarai) == 0)
                makeActBtn( "dog_lick", act(34));
            if(root->vStatus(horny) >= 40 && pir_piratsuka >= 5 && root->gVEvent(grandparents_ingadsarai) == 0)
                makeActBtn( "dog_lick_ass", act(35));
            if(root->gVEvent(pir_piratsuka) >= 12 && pir_DogHJ == 1 && (root->gVEvent(pir_DogVag) == 1 || root->gVEvent(pir_DogAnal) == 1) && root->gVEvent(pir_pirat_sex) != root->vStatus(daystart) && root->gVEvent(grandparents_ingadsarai) == 0)
                makeActBtn( "excite", act(36));
            if(root->gVEvent(pir_piratsuka) >= 35 && pir_DogBJ == 1 && (root->gVEvent(pir_DogVag) == 1 || root->gVEvent(pir_DogAnal) == 1) && root->gVEvent(pir_pirat_sex) != root->vStatus(daystart) && root->gVEvent(grandparents_ingadsarai) == 0)
                makeActBtn( "licking_ass", act(37));
            makeActBtn( "stroking", act(33));
            makeActBtn( "next3", act(8));
        }
        else
        {
            if(root->gVEvent(pir_piratsuka) < 5)
            {
                root->setImage(media(12));
                root->setDesc(str(6));
                grandparentsIngadsarai();
                makeActBtn( "push_away", act(9));
                makeActBtn( "tolerate", act(38));
            }
            else if(root->gVEvent(pir_piratsuka) >= 5 && root->gVEvent(pir_piratsuka) < 7)
            {
                root->setImage(media(13));
                root->setDesc(str(10));
                grandparentsIngadsarai();
                makeActBtn( "push_away", act(9));
                makeActBtn( "onAllFour", act(39));
            }
            else if(root->gVEvent(pir_piratsuka) > 7)
            {
                root->setImage(media(13));
                root->setDesc(str(14));
                grandparentsIngadsarai();
                makeActBtn( "push_away", act(9));
                if(root->gVEvent(grandparents_ingadsarai) == 1)
                    makeActBtn( "scream", act(10));
                if(root->vStatus(horny) >= 40 && pir_DogHJ == 0 && root->gVEvent(grandparents_ingadsarai) == 0)
                    makeActBtn( "dog_lick", act(34));
                if(root->vStatus(horny) >= 40 && pir_piratsuka >= 15 && (root->gVEvent(pir_DogVag) == 0 || root->gVEvent(pir_DogAnal) == 0) && root->gVEvent(grandparents_ingadsarai) == 0)
                    makeActBtn( "dog_lick_ass", act(35));
                if(pir_DogHJ == 1 && pir_DogBJ == 0 && root->gVEvent(grandparents_ingadsarai) == 0)
                    makeActBtn( "handjob", act(13));
                if(root->gVEvent(pir_piratsuka) >= 10 && root->gVEvent(pir_DogBJ) == 1 && root->gVEvent(grandparents_ingadsarai) == 0)
                    makeActBtn( "blowjob", act(13));
                if(root->gVEvent(pir_piratsuka) >= 12 && (root->gVEvent(pir_DogVag) == 1 || root->gVEvent(pir_DogAnal) == 1) && root->gVEvent(grandparents_ingadsarai) == 0)
                    makeActBtn( "undress&onAllFour", act(40));
            }
            makeActBtn( "next3", "Отойти");
        }
    }
}

void Pirat::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Pirat::actionHandler);
    root->addActBtn(btn);
}

QString Pirat::act(int id)
{
    QString act[41];
    act[0] = "Искать Пирата";
    act[1] = "Идти к Пирату";
    act[2] = "Разогнать их";
    act[3] = "Подождать";
    act[4] = "Далее";
    act[5] = "Ждать";
    act[6] = "Вот я больше и не девочка";
    act[7] = "Закончить";
    act[8] = "Уйти";
    act[9] = "Оттолкнуть Пирата";
    act[10] = "Наорать на Пирата";
    act[11] = "Направить его член себе в киску";
    act[12] = "Направить его член себе в попку";
    act[13] = "Взять в руку его член";
    act[14] = "Отвести взгляд и уйти";
    act[15] = "Попытаться сбросить";
    act[16] = "Взять в рот";
    act[17] = "Отвернуться и уйти";
    act[18] = "Сосать дальше";
    act[19] = "На лицо";
    act[20] = "В рот";
    act[21] = "Попробовать снова";
    act[22] = "Оставить эту затею";
    act[23] = "Пойти посмотреть";
    act[24] = "Пройти мимо";
    act[25] = "Оттолкнуть";
    act[26] = "Подчиниться";
    act[27] = "Дать полизать киску";
    act[28] = "Уйти(я же не извращенка какая-нибудь";
    act[29] = "Приходить в себя";
    act[30] = "Дрочить";
    act[31] = "Позволить";
    act[32] = "Предотвратить";
    act[33] = "Погладить Пирата";
    act[34] = "Дать полизать писю";
    act[35] = "Дать полизать попу";
    act[36] = "Возбудить Пирата";
    act[37] = "Полизать Пирату задницу";
    act[38] = "Терпеть";
    act[39] = "Встать на четвереньки";
    act[40] = "Снять трусики и встать на четвереньки";
    return act[id];
}

QString Pirat::str(int id)
{
    QString str[16];
    str[0] = "<br>Беспородный пес по кличке Пират равнодушно сидит возле сарая.";
    str[1] = "Беспородный пес по кличке Пират виляет хвостом при вашем появлении.";
    str[2] = "Беспородный пес по кличке Пират крутится вокруг вас виляя хвостом и принюхиваясь.";
    str[3] = "Беспородный пес по кличке Пират виляет хвостом при вашем появлении.";
    str[4] = "Беспородный пес по кличке Пират крутится вокруг вас виляя хвостом и принюхиваясь.";
    str[5] = "Беспородный пес по кличке Пират крутится вокруг вас виляя хвостом и тыкается носом вам между ног.";
    str[6] = "Беспородный пес по кличке Пират набрасывается на вашу ногу и трется об нее.";
    str[7] = "Вы стояли не двигаясь пока Пират терся об вашу ногу. Вдруг на нее полилась какая то горячая белая жидкость, "
             "Пират тут же отскочил в сторону и стал чесаться как не в чем не бывало.";
    str[8] = "Вы стояли не двигаясь, пока Пират терся об вашу ногу, но тут вы услышали голос дедушки:<br>- Видать суки давно не было."
             " Света, пни его посильнее, а то так и будет приставать.";
    str[9] = "Вы стояли не двигаясь, пока Пират терся об вашу ногу, но тут вы услышали крик бабушки:<br>- Ах ты негодник! Иш чего "
             "удумал, паразит. А ты Света, чего стоишь молча? Если ему не дать острастку, так ведь и будет на тебя кидаться.";
    str[10] = "Беспородный пес по кличке Пират встает на задние лапы и кладет свои передние лапы вам на плечи. Вы чувствуете как вам "
              "в попу упирается, словно шило, горячий член Пирата.";
    str[11] = "Вы встаете на четвереньки и подставив задницу псине, начинаете ждать, пока Пират закончит усиленно тыкаться своим"
              " членом вам в попу. Вы чувствуете, как его горячий член беспорядочно тыкается вам то в промежность, то в ягодицы "
              "и эти хаотичные движения начинают вас возбуждать... Но вскоре это заканчивается и вы чувствуете, как сквозь одежду"
              " по вашим ягодицам начинает разливаться что-то горячее и теплое, после чего Пират наконец спрыгивает с вас и "
              "начинает чесаться как ни в чем не бывало.";
    str[12] = "Вы встаете на четвереньки и подставив задницу псине, но тут вы услышали голос дедушки:<br>- Это еще что такое?."
              "<br>Дед, не долго думая, пнул Пират под зад, и ток с визгом бросился в свою будку.<br>- А ты, Света,"
              " чего тут раскорячилась? - обернулся он к вам. - А ну марш отсюда!.";
    str[13] = "Вы встаете на четвереньки и подставив задницу псине, но тут вы услышали крик бабушки:<br>- Ах ты негодник! "
              "Иш чего удумал, паразит.<br>Вы услышали свист палки и жалобный визг Пирата.<br>- А ты, Света, чего стоишь? - "
              "грозно обернулась она к вам. - А ну марш отсюда, пока тоже не получила!";
    str[14] = "Пират, радостно погавкивая, игриво кружится вокруг вас, иногда забрасывая лапы вам на бедра, суматошно тычась"
              " возбужденным членом то в ногу, то в попку...";
    str[15] = "Вы снимаете трусики и встаете перед Пиратом на четвереньки, оттопыривая ему свою голую задницу. Пес, пару раз "
              "громко подав голос, тут же запрыгивает на вас и начинает беспорядочно тыкаться вам в промежность...";
    return str[id];
}

QString Pirat::evStr(int id)
{
    QString str[27];
    str[0] = "Пират набрасывается на вас и положив лапы вам на бедра, начинает настойчиво и ощутимо давить на вас, угрожающе рыча...";
    str[1] = "Но тут вы услышали негодующий голос дедушки:<br>- Ах ты мелкий паршивец! На людей уже кидаться вздумал? Ну погоди у меня!."
             "<br>Дед схватил Пирата за ошейник и потянул в сторону будки, на ходу вырывая из колоды топор.<br>- Светка, иди в дом, живо!"
             " - обернулся он к вам, на ходу. - Нечего тебе на такое смотреть!.<br>Вы кинулись прочь, но не пробежав и полпути услышали"
             " короткий взвизг.<br>\"Всё, пиздец Пирату\" - пронеслась мысль в вашей голове.";
    str[2] = "Но тут вы услышали крик бабушки:<br>- Ах ты негодник! Ах ты паразит! Дед беги сюда быстрее! Пират Светку искусать вздумал!"
             "<br>Прибежавший дед, оценив ситуацию, кинулся к Пирату:<br>- Ах ты мелкий паршивец! На людей уже кидаться вздумал? "
             "Ну погоди у меня!.<br>Схватив его за ошейник, дед потянул  его в сторону будки, на ходу вырывая из колоды топор."
             "<br>- Мать, уведи Светку в дом, живо! - обернулся он к вам, на ходу. - Нечего ей на такое смотреть!."
             "<br>Бабушка обняла вас за плечи и причитая повела в сторону избы. Но не пройдя и полпути  вы услышали короткий взвизг. "
             "<br>\"Всё, пиздец Пирату\" - пронеслась мысль в вашей голове.";
    str[3] = "Вы снимаете трусики и встаете перед Пиратом на четвереньки, оттопыривая ему свою голую задницу. Пес уже сам зная, что"
             " ему делать, привычно закидывает передние лапы вам на спину и начинает тыкаться вам в промежность своим горячим членом.";
    str[4] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом, "
             "совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в вашу "
             "девственную плеву и начинает бешено тыкаться в нее. Острая боль заставляет вас протяжно застонать и покрепче упереться обеими "
             "руками в пол, чтобы не свалиться оземь от собачьих фрикций. Закусив губу, вы мычите от боли, пока животное лишает вас "
             "девственности. Его член становится все больше и больше, с каждой секундой до боли растягивая вашу киску. Пес, пару минут"
             " подолбив вашу разорванную кровоточащую вагину, перестал наконец двигаться и тихонько затих у вас на спине. "
             "В то время, пока вы кусаете от острой тянущей боли губы, его узел намертво закупорил вашу тугую дырочку, которая, "
             "как вы чувствуете, переполнена собачьими выделениями и вашей собственной кровью. Простояв полчаса на четвереньках"
             " в связке с Пиратом, вам наконец удается освободиться и кое-как привести себя в порядок...";
    str[5] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу тугую вагину и начинает бешено и "
             "глубоко молотить, доставая кончиком почти до самой матки. Ваши глаза моментально мокреют от невольно выступивших слез, "
             "а из уст сами по себе вырываются болезненные стенания. Вы вертите бедрами, пытаясь как-то уменьшить боль, но Пират "
             "рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного, как покорно терпеть. "
             "Он настолько сильно, быстро и глубоко вколачивает в вашу тесную щелку свой член, что через минуту вы чувствуете, "
             "как в нее проникает горячий узел и уверенно начинает раздуваться. Стенки вашего влагалища болезненно растягиваются,"
             " причиняя новые страдания, но вы не смеете пошевелиться, боясь, что Пират опять схватит вас за шею... "
             "Но через пару минут он слезает с вас и развернувшись задом к вашей заднице, затихает. Все остальное время"
             " вы ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[6] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и "
             "глубоко молотить, доставая кончиком до самой матки. Из ваших губ сами по себе срываются стоны и мычания, наполненные "
             "одновременно и болью и наслаждением. Вы вертите бедрами, пытаясь как-то уменьшить ноющую боль в вагине, которую, впрочем,"
             " почти заглушает приближающийся оргазм, но Пират рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не "
             "остается ничего иного, как покорно терпеть. Он настолько сильно, быстро и глубоко вколачивает в вашу хлюпающую щелку"
             " свой член, что через минуту вы чувствуете, как в нее проникает горячий узел и уверенно начинает раздуваться. "
             "Стенки вашего влагалища растягиваются, доставляя новые болезненно-приятные ощущения и вы начинаете протяжно кончать, "
             "громко мыча и постанывая. Через пару минут вас отпускает и Пират слезает с вас и развернувшись задом к вашей заднице, "
             "затихает. Все остальное время вы обессиленные ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[7] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и "
             "глубоко молотить, доставая кончиком до самой матки. Из ваших губ сами по себе срываются стоны и мычания, наполненные "
             "одновременно и болью и наслаждением. Вы вертите бедрами, пытаясь как-то уменьшить ноющую боль в вагине, но Пират рычит"
             " и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного, как покорно терпеть. Он настолько"
             " сильно, быстро и глубоко вколачивает в вашу хлюпающую щелку свой член, что через минуту вы чувствуете, как в нее проникает"
             " горячий узел и уверенно начинает раздуваться. Стенки вашего влагалища растягиваются, доставляя новые болезненно-приятные"
             " ощущения, но вы не смеете пошевелиться, боясь, что Пират опять схватит вас за шею... Но через пару минут он слезает с вас"
             " и развернувшись задом к вашей заднице, затихает. Все остальное время вы ждете, пока откупорится ваша сочащаяся собачьей "
             "спермой киска...";
    str[8] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено "
             "и глубоко молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются сладострастные "
             "стоны и мычания, наполненные одновременно и животной похотью и человеческим наслаждением. Вы вертите бедрами, пытаясь "
             "увеличить эти ощущения, но Пират рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного,"
             " как покорно терпеть. Он настолько сильно, быстро и глубоко вколачивает в вашу хлюпающую дырку свой член, что через минуту,"
             " визжа и крича, вы начинаете обильно кончать, совершенно забыв о том, что вас может кто-нибудь услышать. Приходите в себя вы "
             "только через пару минут, когда Пират стоит задницей к вашей промежности, ожидая, когда сдуется узел...";
    str[9] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и"
             " глубоко молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются сладострастные "
             "стоны и мычания, наполненные одновременно и животной похотью и человеческим наслаждением. Вы вертите бедрами, пытаясь "
             "увеличить эти ощущения, но Пират рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного,"
             " как покорно терпеть. Он настолько сильно, быстро и глубоко вколачивает в вашу хлюпающую дырку свой член, что через минуту"
             " вы чувствуете, как в нее проникает горячий узел и уверенно начинает раздуваться. Стенки вашего влагалища приятно "
             "растягиваются, доставляя новые порции удовольствия, но вы не смеете пошевелиться, боясь, что Пират опять схватит вас за"
             " шею... Через пару минут он слезает с вас и развернувшись задом к вашей заднице, затихает. Все остальное время вы ждете,"
             " пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[10] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную дыру и начинает бешено и"
              " глубоко молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются животные "
              "стоны и мычания, абсолютно лишенные какой-либо человечности. Вы как сука в течке вертите задницей и посильнее "
              "сжимаете мышцы влагалища, чтобы из него, не дай боже, не выскочил ваш любимый собачий член. Пират еще пару минут"
              " яростно долбит ваше раздолбанное влагалище, доводя вас до животного оргазма, а потом устало спрыгивает с вашей "
              "спины и повернувшись задницей к вашей истекающей животными соками промежности, затихает. Все оставшиеся десять "
              "минут вы покорно ждете, пока член вашего кобеля не выскользнет из вашей дыры...";
    str[11] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную дыру и начинает бешено и "
              "глубоко молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются животные "
              "стоны и мычания, абсолютно лишенные какой-либо человечности. Вы как сука в течке вертите задницей и посильнее "
              "сжимаете мышцы влагалища, чтобы из него, не дай боже, не выскочил ваш любимый собачий член. Пират еще пару минут "
              "яростно долбит ваше раздолбанное влагалище, а потом устало спрыгивает с вашей спины и повернувшись задницей к вашей"
              " истекающей животными соками промежности, затихает. Все оставшиеся десять минут вы, так и не удовлетворенная, "
              "похотливо ерзаете задницей в ожидании, пока член вашего кобеля не выскользнет из вашей дыры...";
    str[12] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом,"
              " совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в ваш тугой, "
              "но уже обильно смоченный собачьей смазкой, сморщенный анус и начинает бешено тыкаться в него, с каждым разом проникая "
              "все глубже и глубже. Острая боль заставляет вас протяжно застонать и покрепче упереться обеими руками в пол, чтобы не"
              " свалиться оземь от собачьих фрикций. Закусив губу, вы мычите от боли, пока животное проникает вам в прямую кишку. "
              "Его член становится все больше и больше, с каждой секундой до боли растягивая вашу попку и с каждым движением проникая "
              "все глубже и глубже. Вы стонете от острой боли и рези в анусе, но Пират, злобно рыча, властно хватает вас зубами за шею."
              " Вам не остается ничего другого, кроме как стараться получше расслабить многострадальный анус, пока наконец в него "
              "не ныряет пиратов узел. Боль тут же немного утихает, но не надолго - до тех пор, пока горячий пульсирующий "
              "комок живой плоти не начинает быстро увеличиваться в размерах, закупоривая вам попку. Боль становится еще сильнее,"
              " когда он увеличивается до своих максимальных размеров и вы нова непроизвольно начинаете ерзать, при этом не "
              "переставая стонать и мычать. Но Пират уже не обращает на вас никакого внимания - он властно затихает у вас на"
              " спине и ждет, пока сдуется узел...";
    str[13] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом,"
              " совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в ваш уже "
              "обильно смоченный собачьей смазкой анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже."
              " Тупая ноющая боль заставляет вас протяжно застонать и покрепче упереться обеими руками в пол, чтобы не свалиться оземь"
              " от собачьих фрикций. Закусив губу, вы мычите от боли, пока животное проникает вам в прямую кишку. Его член становится "
              "все больше и больше, с каждой секундой все сильнее растягивая вашу попку и с каждым движением проникая все глубже и глубже. "
              "Вы болезненно стонете и повизгиваете после каждой собачьей фрикции, но Пират, злобно рыча, властно хватает вас зубами за "
              "шею и вам поневоле приходится поутихнуть. Чтобы уменьшить боль, вы пытаетесь расслабить анус, но становитсмя только хуже -"
              " вслед за членом вам в задницу проникает и сам узел, тут же быстро начиная увеличиваться в размерах. Вы, помня недовольство "
              "Пирата, пытаетесь потужиться, чтобы вытолкнуть узел, но уже поздно - он плотно закупорил вашу прямую кишку и вы уже даже "
              "ощущаете, как в нее из пульсирующего члена извергается горячая жидкость. Пират наконец успокаивается и тихо замирает на"
              " своей суке - вас в ожидании, когда сдуется узел...";
    str[14] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом, "
              "совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в ваш уже "
              "обильно смоченный собачьей смазкой растянутый анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже"
              " и глубже. Боли почти нет, но вы начинаете протяжно стонать от наслаждения, когда Пират с животной силой вгоняет в вас"
              " свой твердый член. Вы покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете даже немного "
              "подмахивать своему кобелю. Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас зубами за шею"
              " и вам поневоле приходится поутихнуть. Узел без труда проникает в ваше влажную задницу, а когда начинает увеличиваться,"
              " вы ощущаете лишь легкий дискомфорт, который почти не портит сладостного возбуждения. В попытке достичь оргазма, "
              "вы запускаете руку себе в промежность, в надежде удовлетворить себя рукой, но Пират тут же спрыгивает с вашец спины "
              "на землю и повернувшись своей задницей к вашей, начинает сильно тянуться вперед, пытаясь высвободиться. От столь "
              "неожиданного поворота действий вы начинаете бурно и продолжительно кончать, не замечая вокруг ни Пирата, который"
              " все сильнее скребет лапами по земле, пытаясь освободиться, ни тянущей боли в раздолбанном анусе, который, впрочем, "
              "через полминуты все-таки отпускает собачий член и зияя дырой, начинает извергать из себя теплую вязкую собачью сперму...";
    str[15] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом,"
              " совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в ваш уже"
              " обильно смоченный собачьей смазкой растянутый анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже"
              " и глубже. Боли почти нет, но вы начинаете протяжно стонать от наслаждения, когда Пират с животной силой вгоняет в вас"
              " свой твердый член. Вы покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете даже немного "
              "подмахивать своему кобелю. Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас зубами за"
              " шею и вам поневоле приходится поутихнуть. Узел без труда проникает в ваше влажную задницу, а когда начинает увеличиваться,"
              " вы ощущаете лишь легкий дискомфорт, который почти не портит сладостного возбуждения. Но, тем не менее, оргазма вам достичь"
              " так и не удается, так как едва вы попробовали удовлетворить себя рукой, как Пират сразу же спрыгнул на землю и повернувшись"
              " своеей задницей к вашей, обернулся и начал недовольно угрожающе рычать. Решив не рисковать, все остальное время вы покорно "
              "ждете в сцепке, пока собачий член не опадет...";
    str[16] = "Вы покорно ждете, пока пес приноравливается к вашим дырочкам. Он, высунув язык, громко сопит и пыхтит у вас над ухом, "
              "совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете, как кончик его петуха упирается в ваш уже обильно"
              " смоченный собачьей смазкой раздолбанный анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже"
              " и глубже. Боли нет абсолютно, но вы начинаете протяжно стонать от животной похоти и наслаждения, когда Пират с дикой"
              " силой вгоняет в вас свой твердый член. Вы покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете "
              "даже немного подмахивать своему кобелю. Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас"
              " зубами за шею и вам поневоле приходится поутихнуть. Узел без труда проникает в вашу раздолбанную анальную дыру, а когда "
              "начинает увеличиваться, вы чувствуете только наслаждение и желание, чтобы он рос в вашей заднице бесконечно. В попытке"
              " достичь оргазма, вы запускаете руку себе в промежность, в надежде удовлетворить себя рукой, но Пират тут же спрыгивает "
              "с вашец спины на землю и повернувшись своей задницей к вашей, начинает сильно тянуться вперед, пытаясь высвободиться. "
              "От столь неожиданного поворота действий вы начинаете бурно и продолжительно кончать, не замечая, что узел уже давно "
              "выскочил из вашей бездонной кишки и Пират теперь сидит напротив и равнодушно наблюдает за вашими послеоргазменными "
              "конвульсиями и повизгиваниями...";
    str[17] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Вы с животной похотью и наслаждением ощущаете, как он приятно растягивает стенки вашего ануса и следующие двадцать "
              "минут извиваетесь и мычите, чувствуя в своей заднице горячий собачий член...";
    str[18] = "Зайдя в сарай, вы видите постанывающую Мирославу в сцепке с Пиратом. Часть набухшего узла краснеет из ее растянувшегося "
              "влагалища, а Пират радостно виляет вам хвостом и пытается подойти. Мира мычит от боли и на карачках, задницей к вам, "
              "ползет вслед за псом. Вы треплете его за ушами и напоследок ухмыльнувшись, уходите, прикрыв за собой дверь...";
    str[19] = "Зайдя в сарай, вы видите охающую под Пиратом Мирославу. Тот бешено долбится в ее киску, а она, стараясь сдерживать "
              "стоны и визги, каждый раз по сантиметру ползет вперед под его напором... Они оба вас даже не заметили, поэтому вы, еще "
              "немного понаблюдав за этой картиной, прикрываете дверь и уходите...";
    str[20] = "Вы в течении часа бродите по деревне в поисках Пирата, громко выкривая его имя. Неожиданно, когда вы уже собрались "
              "прекратить поиски, вы услышали какую-то возню и поскуливание в кустах.";
    str[21] = "Вы в течении часа бродите по деревне в поисках Пирата, громко выкривая его имя, но так его и не находите.";
    str[22] = "То, что вы увидели вас поразило. Пират и какая-то сучка, стояли жопами друг друг, причем сучка временами поскуливала.";
    str[23] = "- Ах ты засранец! - закричали вы на Пирата. - Я тут с ног сбилась в поисках его, а он по кустам с какими-то суками лазит!"
              " А ну марш домой, скотина!<br>Собаки в испуге попытались ломануться в разные, стороны, но не тут то было, закок"
              " крепко их удерживал. Наконец с громким хлюпом они смогли расцепиться и вы подгоняя громки криками погнали Пирата домой.";
    str[24] = "Вы решили не пугать собак и тихонечко притаились в сторонке, с любопытством наблюдая. Наконец собаки расцепились и "
              "Пират, с довольным видом, подбежал к вам. Потрепав и погладив Пирата пару минут, вы повели его домой.";
    str[25] = "В сарае ковыряется ваша бабушка.";
    str[26] = "В сарае что-то делает ваш дедушка.";
    return str[id];
}

QString Pirat::sexStr(int id)
{
    QString str[95];
    str[0] = "Вы погладили Пирата по спине.";
    str[1] = "Вы подошли к Пирату, чтобы как всегда его погладить. Но он вдруг, выскользнув из под вашей руки, залез головой под юбку, "
             "уткнувшись носом прямо в ваши трусики.";
    str[2] = "Вы подошли к Пирату, чтобы как всегда его погладить. Но он вдруг, выскользнув из под вашей руки, залез головой под юбку, "
             "уткнувшись влажным носом прямо в вашу голенькую киску.";
    str[3] = "Вы подошли к Пирату, чтобы как всегда погладить. Но он вдруг, выскользнув из под вашей руки, уткнулся носом"
             " прямо в вашу промежность.";
    str[4] = "От неожиданности и дикости произошедшего вы так растерялись, что даже не попытались по препятствовать Пирату."
             " Его горячее дыхание между ваших ног возбуждало не на шутку, заставляя лезть в голову самые грязные мысли. "
             "Взглянув возбужденно на Пирата, вы решили...";
    str[5] = "Вы грубо оттолкнули Пирата и наорали на него. Он шарахнулся от вас и обижено побрел в будку.";
    str[6] = "Сняв трусики, чтобы не мешали, вы присели перед собакой на корточки, широко разведя ноги.";
    str[7] = "Вы присели перед собакой на корточки, широко разведя ноги.";
    str[8] = "Сняв штаны и трусики, чтобы не мешали, вы присели перед собакой на корточки, широко разведя ноги.";
    str[9] = "- Пират, иди сюда, дам что-то вкусненькое, - с лукавой улыбкой вы начали подзывать собаку. - Ну, давай же, не бойся."
             "<br>Голова подбежавшего на зов Пирата тут же исчезла между ваших, широко расставленых ножек. Лизнув пару раз ваши бедра,"
             " он ткнулся холодным носом в вашу, истекающую соками, киску. Его шершавый язык прошелся по всей её длине, заставив вас "
             "возбужденно застонать, потом еще раз, и еще. Язык Пирата порхал между ваших ног, доставляя вам неимоверное наслаждение, "
             "заставляя забыть обо всем. Буквально через пару минут вы начали бурно кончать, буквально заливая морду пса своими соками."
             "<br>Отойдя от оргазма, вы оттолкнули голову Пирата, продолжавшего слизывать остатки жидкости с ваших бедер и приведя себя"
             " в порядок отправились по своим делам...";
    str[10] = "Пират тут же пристроился головой между ними и принялся привычно вылизывать вашу, истекающую соками, киску, своим шершавым"
              " языком, доставляя вам массу наслаждений. Буквально через пару минут вы, громко застонав, бурно кончили, и приведя себя"
              " в порядок, отправились по своим делам...";
    str[11] = "Но отойдя буквально на пару шагов, вы замечаете красную колбаску возбужденного члена, висящую между ног. Вас обуяло "
              "любопытство и вам вдруг захотелось рассмотреть его поближе ...";
    str[12] = "Сняв трусики, чтобы не мешали, вы, оттопырив попу, встали перед собакой на четвереньки.";
    str[13] = "Вы, оттопырив попу, встали перед собакой на четвереньки.";
    str[14] = "Сняв штаны и трусики, чтобы не мешали, вы, оттопырив попу, встали перед собакой на четвереньки.";
    str[15] = "- Пиратик, смотри-ка какое я тебе новое угощение приготовила, - позвали вы собаку возбужденным голосом"
              "<br>Пират нерешительно замер, принихиваясь, около вашей попы. Потом вы почуствовали как он лизнул вашу писечку раз,"
              " потом другой и видимо уловив знакомый вкус, принялся во всю лизать своим языком, проходя по всей длине, от писи "
              "до ануса. Вы выгнули спинку, специально подставляя под его шершавый язык свою " + root->getAnusTipe2() + " заднюю"
              " дырочку, получая непередаваемое удовольствие, одновременно пальчиками руки теребя свой клиторок. Долго так продолжаться"
              " не могло и вскоре вы бурно кончили.<br>Отойдя от оргазма  и приведя себя в порядок отправились по своим делам...";
    str[16] = "Пират тут же принялся быстро лизать вас своим языком, проходя по всей длине, от писи до ануса. Вы выгнули спинку, специально"
              " подставляя под его шершавый язык свой " + root->getAnusTipe2() + ", получая непередаваемое удовольсвие, одновременно "
              "пальчиками руки теребя свой клиторок. Долго так продолжаться не могло и вскоре вы бурно кончили, на время потеряв связь"
              " с реальностью.";
    str[17] = "Отойдя от оргазма и приведя себя в порядок отправились по своим делам...";
    str[18] = "Отойдя от оргазма и приведя себя в порядок отправились по своим делам. Но отойдя буквально на пару шагов, вы замечаете "
              "красную колбаску возбужденного члена, висящую между ног. Вас обуяло любопытство и вам вдруг захотелось рассмотреть его поближе...";
    str[19] = "Придя в себя  в себя, вы почувствовали на спине тяжесть, а в промежность вам что-то тычется, пытаясь найти вход в вашу"
              " пещерку. Быстро оглянувшись через плечо, вы увидели перед собой морду Пирата, обхватившего передними лапами ваши бедра"
              " и делающего фрикции своим тазом...";
    str[20] = "Изловчившись, вы скинули пса со своей спины, и отругав его, за плохое поведение, отправились по своим делам...";
    str[21] = "Вы начали возмущено кричать и крутить попой, пытаясь сбросить пса со своей спины, но результат оказался совершенно"
              " противоположный...";
    str[22] = "Спустя пару мгновений вы чувствуете, как кончик члена Пирата уперся в ваш, уже обильно смоченный собачьей смазкой"
              " " + root->getAnusTipe() + " анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже. "
              "Боли почти нет, но вы начинаете протяжно стонать от наслаждения, когда Пират с животной силой вгоняет в вас свой "
              "твердый член. Вы покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете даже немного подмахивать"
              " своему кобелю. Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас зубами за шею и вам "
              "поневоле приходится поутихнуть. Узел без труда проникает в ваше влажную задницу, а когда начинает увеличиваться, вы "
              "ощущаете лишь легкий дискомфорт, который почти не портит сладостного возбуждения. В попытке достичь оргазма, вы "
              "запускаете руку себе в промежность, в надежде удовлетворить себя рукой, но Пират тут же спрыгивает с вашец спины на"
              " землю и повернувшись своей задницей к вашей, начинает сильно тянуться вперед, пытаясь высвободиться. От столь неожиданного"
              " поворота действий вы начинаете бурно и продолжительно кончать, не замечая вокруг ни Пирата, который все сильнее скребет"
              " лапами по земле, пытаясь освободиться, ни тянущей боли в раздолбанном анусе, который, впрочем, через полминуты все-таки"
              " отпускает собачий член и зияя дырой, начинает извергать из себя теплую вязкую собачью сперму...";
    str[23] = "Спустя пару мгновений вы чувствуете, как кончик члена Пирата уперся в ваш, уже обильно смоченный собачьей смазкой"
              " " + root->getAnusTipe() + " анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже. Острая боль заставляет"
              " вас протяжно застонать и покрепче упереться обеими руками в пол, чтобы не свалиться оземь от собачьих фрикций. Закусив "
              "губу, вы мычите от боли, пока животное проникает вам в прямую кишку. Его член становится все больше и больше, с каждой "
              "секундой до боли растягивая вашу попку и с каждым движением проникая все глубже и глубже. Вы стонете от острой боли и рези"
              " в анусе, но Пират, злобно рыча, властно хватает вас зубами за шею. Вам не остается ничего другого, кроме как стараться "
              "получше расслабить многострадальный анус, пока наконец в него не ныряет Пиратов узел. Боль тут же немного утихает, но"
              " не надолго - до тех пор, пока горячий пульсирующий комок живой плоти не начинает быстро увеличиваться в размерах, "
              "закупоривая вам попку. Боль становится еще сильнее, когда он увеличивается до своих максимальных размеров и вы снова"
              " непроизвольно начинаете ерзать, при этом не переставая стонать и мычать. Но Пират уже не обращает на вас никакого "
              "внимания - он затихает у вас на спине и ждет, пока сдуется узел...";
    str[24] = "Спустя пару мгновений вы чувствуете, как кончик члена Пирата уперся в ваш, уже обильно смоченный собачьей смазкой "
              "" + root->getAnusTipe() + " анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже. Тупая ноющая боль"
              " заставляет вас протяжно застонать и покрепче упереться обеими руками в пол, чтобы не свалиться оземь от собачьих фрикций. "
              "Закусив губу, вы мычите от боли, пока животное проникает вам в прямую кишку. Его член становится все больше и больше, с "
              "каждой секундой все сильнее растягивая вашу попку и с каждым движением проникая все глубже и глубже. Вы болезненно стонете"
              " и повизгиваете после каждой собачьей фрикции, но Пират, злобно рыча, властно хватает вас зубами за шею и вам поневоле "
              "приходится поутихнуть. Чтобы уменьшить боль, вы пытаетесь расслабить анус, но становитсмя только хуже - вслед за членом "
              "вам в задницу проникает и сам узел, тут же быстро начиная увеличиваться в размерах. Вы, помня недовольство Пирата, "
              "пытаетесь потужиться, чтобы вытолкнуть узел, но уже поздно - он плотно закупорил вашу прямую кишку и вы уже даже ощущаете,"
              " как в нее из пульсирующего члена извергается горячая жидкость. Пират наконец успокаивается и тихо замирает на своей "
              "суке - вас в ожидании, когда сдуется узел...";
    str[25] = "Спустя пару мгновений вы чувствуете, как кончик члена Пирата уперся в ваш, уже обильно смоченный собачьей смазкой"
              " " + root->getAnusTipe() + " анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже. Боли почти нет,"
              " но вы начинаете протяжно стонать от наслаждения, когда Пират с животной силой вгоняет в вас свой твердый член. Вы"
              " покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете даже немного подмахивать своему кобелю. "
              "Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас зубами за шею и вам поневоле приходится"
              " поутихнуть. Узел без труда проникает в ваше влажную задницу, а когда начинает увеличиваться, вы ощущаете лишь легкий "
              "дискомфорт, который почти не портит сладостного возбуждения. Но, тем не менее, оргазма вам достичь так и не удается,"
              " так как едва вы попробовали удовлетворить себя рукой, как Пират сразу же спрыгнул на землю и повернувшись своеей задницей"
              " к вашей, обернулся и начал недовольно угрожающе рычать. Решив не рисковать, все остальное время вы покорно ждете в сцепке,"
              " пока собачий член не опадет...";
    str[26] = "Спустя пару мгновений вы чувствуете, как кончик члена Пирата уперся в ваш, уже обильно смоченный собачьей смазкой"
              " " + root->getAnusTipe() + " анус и начинает бешено тыкаться в него, с каждым разом проникая все глубже и глубже. Боли нет абсолютно,"
              " но вы начинаете протяжно стонать от животной похоти и наслаждения, когда Пират с дикой силой вгоняет в вас свой твердый"
              " член. Вы покрепче упираетесь обеими руками в пол, чтобы не свалиться оземь и начинаете даже немного подмахивать своему кобелю."
              " Но ему это, видимо, не нравится, потому что он злобно рыча, властно хватает вас зубами за шею и вам поневоле приходится "
              "поутихнуть. Узел без труда проникает в вашу раздолбанную анальную дыру, а когда начинает увеличиваться, вы чувствуете только"
              " наслаждение и желание, чтобы он рос в вашей заднице бесконечно. В попытке достичь оргазма, вы запускаете руку себе в "
              "промежность, в надежде удовлетворить себя рукой, но Пират тут же спрыгивает с вашец спины на землю и повернувшись своей "
              "задницей к вашей,обернулся и начал недовольно угрожающе рычать. Решив не рисковать, все остальное время вы покорно ждете "
              "в сцепке, пока собачий член не опадет...";
    str[27] = "Когда вам уже казалось, что удалось сбросить Пирата со спины, вы вдруг почувствовали, как он ворвался в вашу вагину, упершись"
              " кончиком члена в вашу девственную плеву, и начал бешено тыкаться в нее. Острая боль заставляет вас протяжно застонать и "
              "покрепче упереться обеими руками в пол, чтобы не свалиться оземь от собачьих фрикций. Проникая в вас, член Пирата все глубже"
              " и быстрее стучится в тонкую перегородку. Закусив губу от боли, вы впрогибаетесь больше, пока наконец не чувствуете, как "
              "внутри вас что-то рвётся и горячая плоть начинает заполнять все ваше нутро.";
    str[28] = "Через пару минут, пока вы все это осмысливали и приходили в себя, постепенно осознавая, что только что только что произошло..."
              " Собачий член становился все больше и больше, с каждой секундой до боли растягивая вашу киску. Пес, пару минут подолбив вашу"
              " разорванную кровоточащую вагину, перестал наконец двигаться и подозрительно затих у вас на спине. Решив, что все кончено"
              " и попробовали сбросить с себя Пирата. Тот недовольно рыкнул и сразу же спрыгнул с вашей спины, а вашу промежность пронзила"
              " дикая острая боль... Наконец-то до вас дошло, что его узел полностью проник вам во влагалище и вы теперь оказались с ним "
              "в связке. Вы еще пару раз тщетно попытались освободиться, но все оказалось напрасно - Пират недовольно рычал и злился,"
              " а вагина начинала болеть еще больше. В итоге вы минут двадцать простояли с псом задница к заднице, пока наконец его "
              "член сам не выскользнул из вашей окровавленной растерзанной киски вместе с приличной порцией собачьей спермы, окрашенной "
              "вашей собственной кровью.<br>Кое-как поднявшись на ноги и приведя себя в порядок вы отправились по своим делам...";
    str[29] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и глубоко"
              " молотить, доставая кончиком до самой матки. Из ваших губ сами по себе срываются стоны и мычания, наполненные одновременно "
              "и болью и наслаждением. Вы вертите бедрами, пытаясь как-то уменьшить ноющую боль в вагине, которую, впрочем, почти заглушает "
              "приближающийся оргазм, но Пират рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного,"
              " как покорно терпеть. Он настолько сильно, быстро и глубоко вколачивает в вашу хлюпающую щелку свой член, что через минуту "
              "вы чувствуете, как в нее проникает горячий узел и уверенно начинает раздуваться. Стенки вашего влагалища растягиваются,"
              " доставляя новые болезненно-приятные ощущения и вы начинаете протяжно кончать, громко мыча и постанывая. Через пару минут"
              " вас отпускает и Пират слезает с вас и развернувшись задом к вашей заднице, затихает. Все остальное время вы обессиленные"
              " ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[30] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу тугую вагину и начинает бешено и глубоко"
              " молотить, доставая кончиком почти до самой матки. Ваши глаза моментально мокреют от невольно выступивших слез, а из уст "
              "сами по себе вырываются болезненные стенания. Вы вертите бедрами, пытаясь как-то уменьшить боль, но Пират рычит и злится, "
              "довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного, как покорно терпеть. Он настолько сильно, быстро"
              " и глубоко вколачивает в вашу тесную щелку свой член, что через минуту вы чувствуете, как в нее проникает горячий узел и "
              "уверенно начинает раздуваться. Стенки вашего влагалища болезненно растягиваются, причиняя новые страдания, но вы не смеете"
              " пошевелиться, боясь, что Пират опять схватит вас за шею... Но через пару минут он слезает с вас и развернувшись задом "
              "к вашей заднице, затихает. Все остальное время вы ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[31] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и глубоко"
              " молотить, доставая кончиком до самой матки. Из ваших губ сами по себе срываются стоны и мычания, наполненные одновременно и"
              " болью и наслаждением. Вы вертите бедрами, пытаясь как-то уменьшить ноющую боль в вагине, но Пират рычит и злится, довольно "
              "ощутимо хватает вас зубами за шею и вам не остается ничего иного, как покорно терпеть. Он настолько сильно, быстро и глубоко "
              "вколачивает в вашу хлюпающую щелку свой член, что через минуту вы чувствуете, как в нее проникает горячий узел и уверенно "
              "начинает раздуваться. Стенки вашего влагалища растягиваются, доставляя новые болезненно-приятные ощущения, но вы не смеете "
              "пошевелиться, боясь, что Пират опять схватит вас за шею... Но через пару минут он слезает с вас и развернувшись задом к "
              "вашей заднице, затихает. Все остальное время вы ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[32] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную вагину и начинает бешено и глубоко"
              " молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются сладострастные стоны и "
              "мычания, наполненные одновременно и животной похотью и человеческим наслаждением. Вы вертите бедрами, пытаясь увеличить"
              " эти ощущения, но Пират рычит и злится, довольно ощутимо хватает вас зубами за шею и вам не остается ничего иного, "
              "как покорно терпеть. Он настолько сильно, быстро и глубоко вколачивает в вашу хлюпающую дырку свой член, что через"
              " минуту вы чувствуете, как в нее проникает горячий узел и уверенно начинает раздуваться. Стенки вашего влагалища приятно"
              " растягиваются, доставляя новые порции удовольствия, но вы не смеете пошевелиться, боясь, что Пират опять схватит вас"
              " за шею... Через пару минут он слезает с вас и развернувшись задом к вашей заднице, затихает. Все остальное"
              " время вы ждете, пока откупорится ваша сочащаяся собачьей спермой киска...";
    str[33] = "Спустя пару мгновений вы чувствуете, как его горячий член резко проникает в вашу влажную дыру и начинает бешено и глубоко"
              " молотить, при каждой фрикции приятно упираясь вам в матку. Из ваших губ сами по себе срываются животные стоны и мычания,"
              " абсолютно лишенные какой-либо человечности. Вы как сука в течке вертите задницей и посильнее сжимаете мышцы влагалища, "
              "чтобы из него, не дай боже, не выскочил ваш любимый собачий член. Пират еще пару минут яростно долбит ваше раздолбанное"
              " влагалище, а потом устало спрыгивает с вашей спины и повернувшись задницей к вашей истекающей животными соками промежности, "
              "затихает. Все оставшиеся десять минут вы, так и не удовлетворенная, похотливо ерзаете задницей в ожидании, пока член "
              "вашего кобеля не выскользнет из вашей дыры...";
    str[34] = "Отойдя от оргазма и приведя себя в порядок отправились по своим делам...";
    str[35] = "Вы оттолкнули Пирата сбросив его с ноги.";
    str[36] = "Вы оттолкнули Пирата сбросив его со своей спины.";
    str[37] = "Вы подзываете Пирата к себе, а когда он доверчиво подходит, немного помедлив, берете его горячий возбужденный член себе в руку."
              " Его температура больше температуры человеческого тела и вы, как завороженная, наблюдаете как пульсируют на нем кровяные жилки...";
    str[38] = "Вы, не отрывая глаз от собачьего члена, начинаете нежно надрачивать его так, как будто это был бы мужской. Из него сочится смазка, "
              "а Пират пытается вырваться, но вы крепко удерживаете его за член, а потому через пару минут пес обильно кончает на пол прямо вам под ноги..";
    str[39] = "Вы, не отрывая глаз от собачьего члена, начинаете нежно надрачивать его так, как будто это был бы мужской. Пират пытается вырваться, но "
              "вы крепко удерживаете его за член.<br>Неожиданно, даже для себя, вам захотелось попробовать его на вкус. Желание было так велико,"
              " что вы непроизвольно приблизили губы к собачьему члену...";
    str[40] = "Вы ловите возбужденного пса и осторожно схватив его член у самых яиц, минуту завороженно смотрите на его жилистый член, "
              "после чего, закрыв глаза, с наслаждением засовываете его себе в рот. Он горячий, а на вкус слегка солоноватый, к тому же"
              " с него постоянно выделяется смазка, которую, впрочем, вы чувствуете только по обилию, а не по вкусу. С закрытыми глазами"
              " и в неудобной позе вы начинаете с блаженством сосать член Пирата...<br>Вскоре вы чувствуете, как он напрягается, а пес "
              "начинает ерзать и бешено двигать тазом, что говорит вам о том, что он сейчас кончит...";
    str[41] = "Вы быстро пригибаетесь лицом к земле и вывернув голову, широко открываете рот, кончиком направляя в него собачий член, "
              "который тут же начинает обильно извергаться. Горячая собачья сперма толчками вылетает из члена Пирата и попадает в ваш"
              " широко распахнутый рот, откуда, стекая по губам и подбородку, капает на пол.";
    str[42] = "Вы приседаете на корточки возле Пирата и взяв в руку его член, ласкаете его, возбуждая.<br>Но вы не расчитываете силу "
              "своих ласк и вскоре чувствуете, как начинает пульсировать собачий член у вас во рту...";
    str[43] = "";
    str[44] = "Вы подзываете Пирата к себе, а когда он доверчиво подходит, немного помедлив, берете его горячий возбужденный член себе"
              " в руку. Его температура больше температуры человеческого тела и вы, как завороженная, наблюдаете как пульсируют на нем кровяные жилки...";
    str[45] = "Вы, не отрывая глаз от собачьего члена, начинаете нежно надрачивать его так, как будто это был бы мужской. Из него сочится смазка,"
              " а Пират пытается вырваться, но вы крепко удерживаете его за член, а потому через пару минут пес обильно кончает на пол прямо вам под ноги..";
    str[46] = "Вы ловите возбужденного пса и осторожно схватив его член у самых яиц, минуту завороженно смотрите на его жилистый член, после чего,"
              " закрыв глаза, с наслаждением засовываете его себе в рот. Он горячий, а на вкус слегка солоноватый, к тому же с него постоянно "
              "выделяется смазка, которую, впрочем, вы чувствуете только по обилию, а не по вкусу. С закрытыми глазами и в неудобной позе вы "
              "начинаете с блаженством сосать член Пирата...<br>Вскоре вы чувствуете, как он напрягается, а пес начинает ерзать и бешено двигать"
              " тазом, что говорит вам о том, что он сейчас кончит...";
    str[47] = "Продолжая крепко удерживать Пирата за член, вы на мгновение отвлекаетесь, чтобы выбрать более удобную позу, и в этот момент"
              " пес начинает кончать. Большинство спермы приземляется на пол, но все же вы успеваете лечь на бок и вывернув голову, засунуть "
              "ее под пса, но вам достаются лишь крохи - большинство жидкости осталось на земле...";
    str[48] = "Вы быстро пригибаетесь лицом к земле и вывернув голову, широко открываете рот, кончиком направляя в него собачий член, который"
              " тут же начинает обильно извергаться. Горячая собачья сперма толчками вылетает из члена Пирата и попадает в ваш широко распахнутый"
              " рот, откуда, стекая по губам и подбородку, капает на пол.";
    str[49] = "У вас болит киска, незачем усугублять ее и так незавидное положение.";
    str[50] = "Вы пропускаете руку у себя между ног и пошарив рукой, находите горячий собачий член, после чего направляете его себе в промежность."
              " Пират, высунув язык, громко сопит и пыхтит у вас над ухом, совершая тазом быстрые резкие движения, а потому вы сразу же чувствуете,"
              " как кончик его петуха упирается вам в девственную плеву и начинает бешено тыкаться в нее. Острая боль заставляет вас протяжно "
              "застонать и покрепче упереться обеими руками в пол, чтобы не свалиться оземь от собачьих фрикций. Понимая, что чем быстрее"
              " порвется ваша девственная плева, тем быстрее это все закончится, вы подаетесь задницей назад, чувствуя, как все глубже и быстрее"
              " стучится в тонкую перегородку петух Пирата. Закусив губу, вы выгибаетесь все больше, пока наконец не чувствуете, как у вас внутри"
              " что-то резко рвется и горячая плоть начинает заполнять все ваше нутро. Через пару минут, пока вы все это осмысливали и приходили "
              "в себя, постепенно осознавая, что только что лишились девственности с собакой, член Пирата становился все больше и больше, с каждой"
              " секундой до боли растягивая вашу киску. Пес уже перестал двигаться и подозрительно затих у вас на спине, поэтому вы решили, что все"
              " кончено и попробовали сбросить с себя Пирата. Тот недовольно рыкнул и сразу же спрыгнул с вашей спины, а вашу промежность пронзила"
              " дикая острая боль... Наконец-то до вас дошло, что его узел полностью проник вам во влагалище и вы теперь оказались с ним в связке. "
              "Вы еще пару раз тщетно попытались освободиться, но все оказалось напрасно - Пират недовольно рычал и злился, а вагина начинала "
              "болеть еще больше. В итоге вы минут двадцать простояли с псом задница к заднице, пока наконец его член сам не выскользнул из "
              "вашей окровавленной растерзанной киски вместе с приличной порцией собачьей спермы, окрашенной вашей собственной кровью...";
    str[51] = "Вы пропускаете руку у себя между ног и пошарив рукой, находите горячий собачий член, после чего направляете его себе во влагалище."
              " Пират тут же первым рывком проникает вам в дырочку и начинает бешено и безостановочно молотить своим пушистым задом вам по промежности,"
              " старась как можно глубже засунуть вам узел...";
    str[52] = "Вы упираетесь руками в пол и выпячиваете подальше попку, пытаясь расслабить получше мышцы. Пират бешено молотит своим членом "
              "у вас в кишке и ерзает на спине, царапая ее когтями, пока наконец не загоняет свою упругую горячую плоть до самых яиц. "
              "Вы сразу же чувствуете, как начинает набухать его узел, расстягивая стенки вашего влагалища, и сосредотачиваетесь на этих ощущениях...";
    str[53] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от тупой ноющей боли в вагине. "
              "Но поделать вы уже ничего не можете, поэтому следующие двадцать минут мучительно стоните и мычите в связке с Пиратом...";
    str[54] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Ваше возбуждение настолько велико, что вы начинаете кончать даже не смотря на легкую ноющую боль в вагине...";
    str[55] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от боли в вагине. "
              "Но поделать вы уже ничего не можете, поэтому следующие двадцать минут покорно терпите неприятную растягивающую резь во влагалище...";
    str[56] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Ваше возбуждение настолько велико, что вы начинаете безостановочно и бурно кончать от пульсаций собачьего члена в вашей вагине...";
    str[57] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Следующие двадцать минут вы с легким дискомфортом, но вместе с тем и возбуждением ощущаете, как он растягивает стенки вашего влагалища...";
    str[58] = "<center><img src=\"images/mod_pirat/piratvagcum.jpg\"></center>";
    str[59] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Ваше возбуждение настолько велико, что вы начинаете безостановочно и бурно кончать от пульсаций собачьего члена в вашей вагине...";
    str[60] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров. "
              "Вы с животной похотью и наслаждением ощущаете, как он приятно растягивает стенки вашего влагалище и следующие двадцать минут"
              " извиваетесь и мычите, чувствуя в своей киске горячий собачий узел...";
    str[61] = "Пират настолько сильно долбится в вашу вагину, что вам приходится упереться руками в пол, чтобы не свалиться, но вы лишь "
              "покрепче сжимаете влагалищные мышцы и ему не удается протолкнуть в вашу вагину свой увеличивающийся узел.";
    str[62] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей киске бешено двигается горячий член возбужденного животного."
              " Минут через десять все это заканчивается и пес начинает извергаться в вашу ноющую щелку...";
    str[63] = "Пират начинает бешено молотить вам по заднице своим пушистым тазом и от этих животных движений вы сладострастно мычите"
              " и постанываете до тех пор, пока вас не настигает мощный оргазм. Вы, закатив глаза и содрогаясь в послеоргазменных конвульсиях,"
              " дожидаетесь, пока пес не начинает кончать в вашу истекающую соками киску и его член не выскальзывает из вашего влажного лона...";
    str[64] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей киске бешено двигается горячий член возбужденного животного."
              " Но, тем не менее, вы прекрасно все контролируете и не даете псу проникнуть узлом вам внутрь. Минут через десять все это "
              "заканчивается и пес начинает извергаться вам в щелку...";
    str[65] = "Пират начинает бешено молотить вам по заднице своим пушистым тазом и от этих животных движений вы сладострастно мычите и"
              " постанываете до тех пор, пока вас не настигает мощный оргазм. Вы, закатив глаза и содрогаясь в послеоргазменных конвульсиях,"
              " дожидаетесь, пока пес не начинает кончать в вашу раздолбанную истекающую соками киску и его член не выскальзывает из вашей влажной хлюпающей дырки...";
    str[66] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей киске бешено хлюпает горячий член возбужденного животного. "
              "Но, тем не менее, вы прекрасно все контролируете и не даете псу проникнуть узлом вам внутрь. Минут через десять все это"
              " заканчивается и пес начинает извергаться вам в растянутую рабочую щелку...";
    str[67] = "Пират начинает бешено молотить вам по заднице своим пушистым тазом и от этих животных движений вы сладострастно "
              "мычите и постанываете до тех пор, пока вас не настигает мощный оргазм. Вы, закатив глаза и содрогаясь в послеоргазменных"
              " конвульсиях, дожидаетесь, пока пес не начинает кончать в вашу раздолбанную истекающую соками приоткрытую дыру, из которой"
              " тут же обильно начинает струиться мутная собачья сперма...";
    str[68] = "Вы содрогаетесь от мощных диких толчков, слабо чувствуя, как в вашей бездонной дыре бешено, но малочувствительно "
              "двигается горячий член возбужденного животного... Вы пытаетесь сосредоточиться на этих ощущениях, но ваше влагалище "
              "слишком широкое, чтобы достичь оргазма от члена подобных размеров...";
    str[69] = "Вы содрогаетесь от мощных диких толчков, с болью чувствуя, как в вашей ноюшей киске бешено двигается горячий член "
              "возбужденного животного. Пират настолько сильно долбится в вашу изнывающую киску, что его член выскакивает из нее...";
    str[70] = "Вы содрогаетесь от мощных диких толчков, с наслаждением чувствуя, как в вашей хлюпающей киске бешено двигается горячий"
              " член возбужденного животного. Пират настолько сильно долбится в вашу хлюпающую киску, что его член выскакивает из нее...";
    str[71] = "Вы содрогаетесь от мощных диких толчков, с животной похотью чувствуя, как в вашей хлюпающей киске бешено двигается "
              "горячий член возбужденного животного. Пират настолько сильно долбится в вашу громко хлюпающую и чвакающую киску,"
              " что его член выскакивает из нее...";
    str[72] = "Вы содрогаетесь от мощных диких толчков, из-за растянутости влагалища слабо ощущая, как в ней бешено двигается "
              "горячий член возбужденного животного, но ваша киска настолько раздолбанна и растянута, что его член просто вываливается из нее...";
    str[73] = "У вас болит попка, незачем усугублять ее и так незавидное положение.";
    str[74] = "Вы пропускаете руку у себя между ног и пошарив рукой, находите горячий собачий член, после чего направляете"
              " его себе в анус. Смазка, немного щекоча, обильно изливается вам на анус и стекает по промежности. Ее так много,"
              " что никаких лубрикантов не надо, поэтому, не теряя зря ни времени, ни столь драгоценной жидкости, вы вводите собачий"
              " член себе в задницу. Пират тут же начинает бешено дергать бедрами, старась как можно глубже засунуть в вашу кишку свое хозяйство...";
    str[75] = "Вы упираетесь руками в пол и выпячиваете подальше попку, пытаясь получше расслабить анус. Пират бешено молотит своим членом у"
              " вас в кишке и ерзает на спине, царапая ее когтями, пока наконец не загоняет свою упругую горячую плоть до самых яиц."
              " Вы сразу же чувствуете, как начинает набухать его узел, расстягивая стенки вашего ануса, и сосредотачиваетесь на этих ощущениях...";
    str[76] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от острой бешеной боли в анусе."
              " Но поделать вы уже ничего не можете, поэтому следующие двадцать минут мучитесь и корчитесь в связке с Пиратом...";
    str[77] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от тупой ноющей боли в анусе."
              " Но поделать вы уже ничего не можете, поэтому следующие двадцать минут покорно терпите острую резь в анусе...";
    str[78] = "Но едва он начинает сдуваться, как вы запускаете руку себе между ног и начинаете яростно надрачивать свою киску."
              " Как только узел выскакивает из вашей попки, вы тут же мощно кончаете...";
    str[79] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров."
              " Следующие двадцать минут вы с с легким дискомфортом, но вместе с тем и возбуждением ощущаете, как он растягивает стенки вашего ануса...";
    str[80] = "Но едва он начинает сдуваться, как вы запускаете руку себе между ног и начинаете яростно надрачивать свою киску."
              " Как только узел выскакивает из вашей попки, вы тут же мощно кончаете...";
    str[81] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров."
              " Вы с животной похотью и наслаждением ощущаете, как он приятно растягивает стенки вашего ануса и следующие двадцать"
              " минут извиваетесь и мычите, чувствуя в своей заднице горячий собачий член...";
    str[82] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от острой бешеной "
              "боли в анусе. Внезапно Пират, навострив уши, словно что-то учуял, и пару раз громко гавкнув, спрыгивает с вашей "
              "спины на землю и силой начинает тянуть вас на себя. Вы кричите от сильной, разрывающей боли в анусе и пару минут"
              " пытаетесь утихомирить Пирата, пока он наконец не успокаивается. Все последующее время вы всхлипываете от боли, "
              "дожидаясь, когда сдуется узел и откупорит вашу многострадальную попку...";
    str[83] = "Узел все продолжает и продолжает увеличиваться в размерах, пока вы наконец не начинаете стонать от тупой ноющей боли"
              " в анусе. Внезапно Пират, навострив уши, словно что-то учуял, и пару раз громко гавкнув, спрыгивает с вашей спины на"
              " землю и силой начинает тянуть вас на себя. Вы кричите от острой боли в анусе и пару минут пытаетесь утихомирить Пирата,"
              " пока он наконец не успокаивается. Все последующее время вы всхлипываете от боли, дожидаясь, когда сдуется узел и "
              "откупорит вашу многострадальную попку...";
    str[84] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров."
              " Внезапно Пират, навострив уши, словно что-то учуял, и пару раз громко гавкнув, спрыгивает с вашей спины на землю"
              " и силой начинает тянуть вас на себя. Вы кричите от тупой боли в анусе и пару минут пытаетесь утихомирить Пирата,"
              " пока он наконец не успокаивается. Все последующее время вы мычите от боли, дожидаясь, когда сдуется узел и откупорит вашу попку...";
    str[85] = "Узел все продолжает и продолжает увеличиваться в размерах, пока наконец не достигает своих максимальных размеров."
              " Внезапно Пират, навострив уши, словно что-то учуял, и пару раз громко гавкнув, спрыгивает с вашей спины на землю"
              " и силой начинает тянуть вас на себя. Вы вскрикиваете от неожиданности и член с приличной порцией смазки и спермы"
              " пулей внезапно выскакивает из вашей попки...";
    str[86] = "Вы упираетесь одной рукой в пол, а другой берете член пса у основания. Пират бешено молотит своим хозяйством у вас "
              "в кишке и ерзает на спине, царапая ее когтями, но ваша ладонь мешает ему протолкнуть в вашу задницу свой узел.";
    str[87] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей заднице бешено двигается горячий член возбужденного"
              " животного, а по руке из ноющего ануса стекает теплая тягучая жидкость.";
    str[88] = "Вскоре Пират начинает кончать вам в попку, а когда поток спермы в вашую прямую кишку прекращается, вы, продолжая "
              "удерживать одной рукой его член у своей промежности, другой полностью сосредотачиваетесь на своем клиторе, а еще"
              " через пару минут содрогаетесь в мощном оргазме.";
    str[89] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей заднице бешено двигается горячий член возбужденного"
              " животного, а по руке из то и дело непроизвольно сжимающегося ануса стекает теплая тягучая жидкость.";
    str[90] = "Вскоре Пират начинает кончать вам в попку, а когда поток спермы в вашую прямую кишку прекращается, вы, продолжая"
              " удерживать одной рукой его член у своей промежности, другой полностью сосредотачиваетесь на своем клиторе, а еще"
              " через пару минут содрогаетесь в мощном оргазме.";
    str[91] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей заднице бешено двигается горячий член возбужденного"
              " животного, а по руке из растянутого ануса стекает теплая тягучая жидкость.";
    str[92] = "Вскоре Пират начинает кончать вам в попку, а когда поток спермы в вашую прямую кишку прекращается, вы, продолжая"
              " удерживать одной рукой его член у своей промежности, другой полностью сосредотачиваетесь на своем клиторе, а еще"
              " через пару минут содрогаетесь в мощном оргазме.";
    str[93] = "Вы содрогаетесь от мощных диких толчков, чувствуя, как в вашей заднице бешено двигается горячий член возбужденного"
              " животного, а по руке из раздолбанного ануса стекает теплая тягучая жидкость.";
    str[94] = "Вы садитесь на коленки возле возбужденного Пирата и задрав ему хвост, начинаете вылизывать его грязный анус. "
              "Пес пытается то и дело вильнуть хвостом или лизнуть вам руку, но вы полностью сосредотачиваетесь на его "
              "сморщенном собачьем анусе...";
    return str[id];
}

QString Pirat::media(int id)
{
    QString med[43];
    med[0] = "data/qwest/pirat/pirat_fuck.jpg";
    med[1] = "data/qwest/pirat/girl_bawl.jpg";
    med[2] = "data/qwest/pirat/girl_pry.jpg";
    med[3] = "data/qwest/pirat/predoggy.jpg";
    med[4] = "data/qwest/pirat/piratvag.jpg";
    med[5] = "data/qwest/pirat/doggyvirgin.jpg";
    med[6] = "data/qwest/pirat/piratvagknot.jpg";
    med[7] = "data/qwest/pirat/piratvagcumpirs.jpg";
    med[8] = "data/qwest/pirat/piratvagcum.jpg";
    med[9] = "data/qwest/pirat/analknot1.webm";
    med[10] = "data/qwest/pirat/analknotcum.jpg";
    med[11] = "data/qwest/pirat/analcum.jpg";
    med[12] = "data/qwest/pirat/leghump.jpg";
    med[13] = "data/qwest/pirat/hump.jpg";
    med[14] = "data/qwest/pirat/dog_dick.jpg";
    med[15] = "data/qwest/pirat/dog_back1.jpg";
    med[16] = "data/qwest/pirat/dog_back2.jpg";
    med[17] = "data/qwest/pirat/analknot.jpg";
    med[18] = "data/qwest/pirat/HandCanine1.jpg";
    med[19] = "data/qwest/pirat/PiratMouth.jpg";
    med[20] = "data/qwest/pirat/PiratMouth1.jpg";
    med[21] = "data/qwest/pirat/PiratMouth2.jpg";
    med[22] = "data/qwest/pirat/piratvagcum1pirs.jpg";
    med[23] = "data/qwest/pirat/piratvagcum1.jpg";
    med[24] = "data/qwest/pirat/piratbreak.jpg";
    med[25] = "data/qwest/pirat/analpain.jpg";
    med[26] = "data/qwest/pirat/piratanal.jpg";
    med[27] = "data/qwest/pirat/analcum1.jpg";
    med[28] = "data/qwest/gadukino/turn_back.jpg";
    med[29] = "data/qwest/pirat/pirat_search.jpg";
    med[30] = "data/npc/gadukino/pirat.jpg";
    med[31] = "data/qwest/pirat/dog.webm";
    med[32] = "data/qwest/pirat/dog1.webm";
    med[33] = "data/qwest/pirat/dog2.webm";
    med[34] = "data/qwest/pirat/sniff1.jpg";
    med[35] = "data/qwest/pirat/sniff2.jpg";
    med[36] = "data/qwest/pirat/sniff3.jpg";
    med[37] = "data/qwest/pirat/dog_lick" + intQStr(getRandInt(1,3)) + ".webm";
    med[38] = "data/qwest/pirat/dog_lick" + intQStr(getRandInt(4,7)) + ".webm";
    med[39] = "data/qwest/pirat/HandCanine.jpg";
    med[40] = "data/qwest/pirat/piratlickass.jpg";
    med[41] = "data/qwest/pirat/HandCanine.webm";
    med[42] = "data/qwest/pirat/HandCanine1.webm";
    return med[id];
}
