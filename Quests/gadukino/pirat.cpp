#include "pirat.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "../../Functions.h"
#include "../../nav/questHandler.h"

PiratQuest::PiratQuest(QuestHandler* ptr): Quest(ptr)
{
    initStrings();
    initDefault();
}

void PiratQuest::start()
{
    if (pir_pirat == 0 && know_no_pirat == 1 && pir_pirat_search == 0)
    {
        root->makeActBtn(this, "search", "Искать Пирата");
    }
    else
    {
        root->addDesc("<br>В будке сидит <a href='pir_pirat'>Пират</a>");
    }
    if(pir_piratsuka >= 50 && pir_piratfriend >= 70 && pir_pirat_sex != root->getVStatus(daystart))
    {
        pirat_forced();
    }
}

void PiratQuest::slotActHandler(QString act)
{
    root->clearLayout();
    root->switchImageVideo("image");

    if(act == "pir_pirat")
    {
        pirPirat();
    }
    if(act == "search")
    {
        pirat_search();
    }
    if(act == "go&watch")
    {
        root->incTime(5);
        pirat = 1;
        pir_pirat_search = 1;
        root->setImage(":/qwest/pirat/pirat_fuck.jpg");
        root->setDesc(getEvStr(23));
        root->makeActBtn(this, "disperse", "Разогнать их");
        root->makeActBtn(this, "wait", "Подождать");
    }
    if(act == "goaway" || act == "next")
    {
        root->changeLoc("gadukino");
    }
    if(act == "disperse")
    {
        root->incTime(5);
        root->updVSkill(domination, 1);
        pir_piratfriend -= 5;
        root->setImage(":/qwest/pirat/girl_bawl.jpg");
        root->setDesc(getEvStr(24));
        root->makeActBtn(this, "next2", "Далее");
    }
    if(act == "wait")
    {
        root->incTime(10);
        root->updVStatus(horny,10);
        pir_piratfriend += 1;
        root->setImage(":/qwest/pirat/girl_pry.jpg");
        root->setDesc(getEvStr(25));
        root->makeActBtn(this, "next2", "Далее");
    }
    if(act == "next2")
    {
        root->incTime(10);
        root->changeLoc("sarai");
    }
    if(act == "goHome")
    {
        root->changeLoc("izba");
    }
    if(act == "push_away")
    {
        spurn();
    }
    if(act == "submiss")
    {
        root->updVStatus(horny, getRandInt(5,10));
        root->incTime(2);
        root->updVSkill(domination, -1);
        pir_piratknow = getRandInt(0,1);
        pir_piratHorny = 0;
        pir_pirat_sex = root->getVStatus(daystart);
        pir_zoo += 1;
        root->setImage(":/qwest/pirat/predoggy.jpg");
        root->setDesc(getEvStr(4));
        if(pir_piratknow == 1)
        {
            if(root->getVBody(vagina) == 0)
            {
                root->makeActBtn(this, "submiss_wait1", "Ждать");
            }
            else
            {
                root->setImage(":/qwest/pirat/piratvag.jpg");
                root->makeActBtn(this, "submiss_wait2", "Ждать");
            }
        }
        else
        {
            root->makeActBtn(this, "submiss_wait3", "Ждать");
        }
    }
    if(act == "submiss_wait1")
    {
        if(pir_piratsuka < 30)
            pir_piratsuka += 5;
        root->updVStatus(horny, getRandInt(5,10));
        root->incTime(30);
        root->setVBody(vagina,5);
        root->setVSex(vgape,3);
        //vgape_time
        root->setVStatus(mood, root->getVStatus(mood)/2);
        root->updVSkill(domination, -10);
        root->setImage(":/qwest/pirat/doggyvirgin.jpg");
        root->setDesc(getEvStr(5));
        root->makeActBtn(this, "next3", "Вот я больше и не девочка");
    }
    if(act == "next3")
    {
        root->changeLoc("sarai");
    }
    if(act == "submiss_wait2")
    {
        int vag = root->getVBody(vagina);
        if(vag < 10)
        {
            root->incTime(2);
            root->updVBody(vagina,5);
            root->setVSex(vgape,3);
            root->setVStatus(horny, 0);
            root->setImage(":/qwest/pirat/piratvagknot.jpg");
            root->setDesc(getEvStr(6));
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(vag >= 10 && vag < 25)
        {
            root->incTime(20);
            root->updVBody(vagina,4);
            root->setVSex(vgape, 2);
            root->updVStatus(horny, getRandInt(15,25));
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->setVStatus(horny, 0);
                root->setVStatus(mood, 100);
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getEvStr(7));
            }
            else
            {
                root->setImage(":/qwest/pirat/piratvagknot.jpg");
                root->setDesc(getEvStr(8));
            }
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(vag >=25 && vag < 35)
        {
            root->incTime(20);
            root->updVBody(vagina,3);
            root->updVStatus(horny, getRandInt(25,50));
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood, 100);
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getEvStr(9));
            }
            else
            {
                root->setImage(":/qwest/pirat/piratvagcum.jpg");
                root->setDesc(getEvStr(10));
            }
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(vag >= 35)
        {
            root->incTime(15);
            root->updVBody(vagina,1);
            root->updVStatus(horny, getRandInt(99,100));
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getEvStr(11));
            }
            else
            {
                root->setImage(":/qwest/pirat/piratvagcum.jpg");
                root->setDesc(getEvStr(12));
            }
            root->makeActBtn(this, "next3", "Закончить");
        }
    }
    if(act == "submiss_wait3")
    {
        int anusVal = root->getVBody(anus);
        root->incTime(2);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        root->setVideo("qrc:/qwest/pirat/analknot1.webm", 868, 540);
        root->switchImageVideo("video");
        if(anusVal < 10)
        {
            root->incTime(20);
            root->updVBody(anus,5);
            root->setVSex(agape,3);
            root->setVStatus(horny,0);
            //zz_funs, cum, anus
            //gs stat
            root->setVideoDesc(getEvStr(13));
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(anusVal >= 10 && anusVal < 25)
        {
            root->incTime(20);
            root->updVBody(anus,3);
            root->setVSex(agape,2);
            root->updVStatus(horny, -getRandInt(15,30));
            //zz_funs, cum, anus
            //gs stat
            root->setVideoDesc(getEvStr(14));
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(anusVal >= 25 && anusVal < 35)
        {
            root->incTime(20);
            root->updVBody(anus,2);
            root->setVSex(agape,1);
            root->updVStatus(horny, getRandInt(15,30));
            //zz_funs, cum, anus
            //gs stat
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                root->updVStatistic(analOrgasm,1);
                root->setImage(":/qwest/pirat/analknotcum.jpg");
                root->switchImageVideo("image");
                root->setDesc(getEvStr(15));
            }
            else
            {
                root->setVideoDesc(getEvStr(16));
            }
            root->makeActBtn(this, "next3", "Закончить");
        }
        else if(anusVal >= 35)
        {
            root->incTime(20);
            root->updVBody(anus,1);
            root->updVStatus(horny, getRandInt(50,100));
            //zz_funs, cum, anus
            //gs stat
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->updVStatistic(analOrgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                root->setImage(":/qwest/pirat/analcum.jpg");
                root->setDesc(getEvStr(17));
                root->switchImageVideo("image");
            }
            else
            {
                root->setVideoDesc(getEvStr(18));
            }
            root->makeActBtn(this, "next3", "Закончить");
        }
    }
    if(act == "stroking")
    {
        stroking();
    }
    if(act == "stroking_horny")
    {
        strokingHorny();
    }
    if(act == "scream")
    {
        scream();
    }
    if(act == "dog_lick")
    {
        dogLick();
    }
    if(act == "dog_lick_ass")
    {
        dogLickAss();
    }
    if(act == "tolerate")
    {
        pir_piratHorny = 0;
        root->incTime(5);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        pir_piratsuka += 1;
        pir_pirat_sex = root->getVStatus(daystart);
        root->updVSkill(domination, -1);
        //gs stat
        root->setImage(":/qwest/pirat/leghump.jpg");
        if(grandparents_ingadsarai == 0)
            root->setDesc(getStr(8));
        if(grandpa_ingadsarai == 1)
            root->addDesc(getStr(9));
        if(grandma_ingadsarai == 1)
            root->addDesc(getStr(10));
        if(grandpa_ingadsarai == 1)
            root->makeActBtn(this, "push_away", "Оттолкнуть Пирата");
        if(grandpa_ingadsarai == 1)
            root->makeActBtn(this, "scream", "Наорать на Пирата");
        root->makeActBtn(this, "next4", "Уйти");
    }
    if(act == "next4")
    {
        if(grandpa_ingadsarai == 1)
        {
            //grandpaQW -= 1
        }
        if(grandma_ingadsarai == 1)
        {
            //grandmaQW -= 1
        }
        root->changeLoc("sarai");
    }
    if(act == "onAllFour")
    {
        root->updVStatus(horny, getRandInt(10,20));
        pir_piratHorny = 0;
        root->incTime(5);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        pir_piratsuka += 1;
        root->updVSkill(domination, -1);
        root->updVStatus(cumFrot, 1);
        pir_pirat_sex = root->getVStatus(daystart);
        //gs stat
        root->setImage(":/qwest/pirat/hump.jpg");
        if(grandparents_ingadsarai == 0)
            root->setDesc(getStr(12));
        if(grandpa_ingadsarai == 1)
        {
            root->setDesc(getStr(13));
            //grandpaQW -= 5
        }
        if(grandma_ingadsarai == 1)
        {
            root->setDesc(getStr(14));
            //grandmaQW -= 5
        }
        root->makeActBtn(this, "next3", "Уйти");
    }
    if(act == "handjob")
    {
        pirDogHJ();
    }
    if(act == "blowjob")
    {
        pirDogBJ();
    }
    if(act == "undress&onAllFour")
    {
        root->updVStatus(horny, getRandInt(5,10));
        root->incTime(2);
        root->setImage(":/qwest/pirat/predoggy.jpg");
        root->setDesc(getStr(16));
        root->makeActBtn(this, "pir_DogVag", "Направить его член себе в киску");
        root->makeActBtn(this, "pir_DogAnal", "Направить его член себе в попку");
    }
    if(act == "pir_DogVag")
        pirDogVag();
    if(act == "pir_DogAnal")
        pirDogAnal();
    if(act == "next5")
    {
        pir_piratfriend -= 1;
        root->changeLoc("sarai");
    }
    if(act == "preHandJob")
    {
        root->incTime(5);
        //gs stat
        root->setImage(":/qwest/pirat/dog_dick.jpg");
        root->setDesc(getSexStr(19));
        root->makeActBtn(this, "handjob", "Взять в руку его член");
        root->makeActBtn(this, "next3", "Отвести взгляд и уйти");
    }
    if(act == "comeToLife")
    {
        root->incTime(5);
        //gs stat
        root->setImage(":/qwest/pirat/dog_back1.jpg");
        root->setDesc(getSexStr(20));
        root->makeActBtn(this, "takeoff", "Попытаться сбросить");
        if(pir_DogVag == 1 || pir_DogAnal == 1)
        {
            root->makeActBtn(this, "pir_DogVag", "Направить его член себе в киску");
            root->makeActBtn(this, "pir_DogAnal", "Направить его член себе в попку");
        }
    }
    if(act == "takeoff")
    {
        int temp = getRandInt(50,120);
        if(root->getVSkill(agility) > temp)
        {
            root->incTime(1);
            pir_piratHorny -= 40;
            root->setImage(":/qwest/pirat/girl_bowl.jpg");
            root->setDesc(getSexStr(21));
            root->makeActBtn(this, "next3", "Уйти");
        }
        else
        {
            root->incTime(10);
            pir_piratHorny = 0;
            pir_pirat_sex = root->getVStatus(daystart);
            int temp = getRandInt(1,3);
            //gs stat
            root->setImage(":/qwest/pirat/dog_back2.jpg");
            root->setDesc(getSexStr(22));
            root->makeActBtn(this, "next6" + intQStr(temp), "Далее");
        }
    }
    if(act == "next61")
    {
        root->incTime(30);
        pir_DogAnal = 1;
        root->updVStatistic(analSex, 1);
        int anusVal = root->getVBody(anus);
        if(anusVal < 10)
        {
            root->updVStatus(mood, -50);
            root->updVBody(anus,5);
            root->setVSex(agape,3);
            root->setVStatus(horny,0);
        }
        if(anusVal >= 10 && anusVal < 25)
        {
            root->updVStatus(mood, -20);
            root->updVBody(anus,3);
            root->setVSex(agape,2);
            root->updVStatus(horny, -getRandInt(15,30));
        }
        if(anusVal >= 25 && anusVal < 35)
        {
            root->updVStatus(mood, -10);
            root->updVBody(anus,2);
            root->setVSex(agape,1);
            root->updVStatus(horny,getRandInt(15,30));
        }
        if(anusVal >= 35)
        {
            root->updVBody(anus,1);
            root->updVStatus(horny,getRandInt(50,100));
        }
        root->updVSkill(domination, -1);
        //gs zzfuncs, cum, anus
        //gs stat
        root->setImage(":/qwest/pirat/analknot.jpg");
        if(root->getVStatus(horny) >= 100)
        {
            root->updVStatistic(orgasm,1);
            root->updVStatistic(analOrgasm,1);
            root->setVStatus(horny,0);
            root->setVStatus(mood,100);
            //gs stat
            root->setDesc(getSexStr(23));
        }
        else
        {
            if(anusVal < 10)
                root->setDesc(getSexStr(24));
            else if(anusVal >= 10 && anusVal < 25)
                root->setDesc(getSexStr(25));
            else if(anusVal >= 25 && anusVal < 35)
                root->setDesc(getSexStr(26));
            else if(anusVal >= 35)
                root->setDesc(getSexStr(27));
        }
        root->makeActBtn(this, "next3", "Уйти");
    }
    if(act == "next62" || act == "next63")
    {
        if(root->getVBody(vagina) == 0)
        {
            pir_DogVag = 1;
            pir_piratsuka += 5;
            root->updVStatus(horny,0);
            root->incTime(10);
            root->updVBody(vagina,1);
            root->setVSex(vgape,1);
            root->updVStatus(mood, -50);
            root->updVSkill(domination, -10);
            root->updVStatistic(vaginalSex, 1);
            //gs stat
            root->setImage(":/qwest/pirat/doggyvirgin.jpg");
            root->setDesc(getSexStr(28));
            root->makeActBtn(this, "next64", "Далее");
        }
        else
        {
            pir_DogVag = 1;
            root->incTime(30);
            root->updVStatistic(vaginalSex,1);
            int vag = root->getVBody(vagina);
            if(vag < 10)
            {
                root->updVStatus(mood,-50);
                root->updVBody(vagina,5);
                root->setVSex(vgape,3);
                root->setVStatus(horny,0);
            }
            else if(vag >= 10 && vag < 25)
            {
                root->updVBody(vagina,4);
                root->setVSex(vgape,2);
                root->updVStatus(horny, getRandInt(15,25));
            }
            else if(vag >= 25 && vag < 35)
            {
                root->updVBody(vagina,3);
                root->setVSex(vgape,1);
                root->updVStatus(horny,getRandInt(25,50));
            }
            else if(vag >= 35)
            {
                root->updVBody(vagina,1);
                root->updVStatus(horny,getRandInt(50,75));
            }
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->updVStatistic(vaginalOrgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                if(root->getVBody(piercingG) == 1)
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                else
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                root->setDesc(getSexStr(30));
            }
            else
            {
                int vag = root->getVBody(vagina);
                root->setImage(":/qwest/pirat/piratvagknot.jpg");
                if(vag < 10)
                    root->setDesc(getSexStr(31));
                else if(vag >= 10 && vag < 25)
                    root->setDesc(getSexStr(32));
                else if (vag >= 25 && vag < 35)
                    root->setDesc(getSexStr(33));
                else if(vag >= 35)
                    root->setDesc(getSexStr(34));
            }
            root->makeActBtn(this, "next3", "Уйти");
        }
    }
    if(act == "next64")
    {
        root->incTime(20);
        root->updVBody(vagina,5);
        root->setVSex(vgape,3);
        root->updVStatus(mood, -50);
        //gs zzfuncs cum pussy
        //gs stat
        root->setImage(":/qwest/pirat/piratvagknot.jpg");
        root->setDesc(getSexStr(29));
        root->makeActBtn(this,"next3", "Уйти");
    }
    if(act == "mastr")
    {
        root->updVStatus(horny, getRandInt(20,30));
        root->incTime(10);
        pir_piratHorny = 0;
        root->updVStatus(mood, root->getVStatus(mood)/20);
        pir_DogHJ = 1;
        //gs stat
        root->setImage(":/qwest/pirat/HandCanine1.jpg");
        if(pir_piratsuka < 10)
        {
            root->setDesc(getSexStr(39));
            root->makeActBtn(this, "pir_pirat", "Уйти");
        }
        else
        {
            root->setDesc(getSexStr(40));
            root->makeActBtn(this, "takeInMouth", "Взять в рот");
            root->makeActBtn(this, "next3", "Отвернуться и уйти");
        }
    }
    if(act == "takeInMouth")
    {
        root->updVStatus(horny, getRandInt(5,15));
        root->incTime(5);
        pir_piratsuka += 5;
        pir_DogBJ = 1;
        pir_pirat_sex = root->getVStatus(daystart);
        //gs stat
        root->setImage(":/qwest/pirat/PiratMouth.jpg");
        root->setDesc(getSexStr(41));
        root->makeActBtn(this,"suckNext", "Сосать дальше");
    }
    if(act == "suckNext")
    {
        root->updVStatus(horny, getRandInt(25,40));
        root->incTime(5);
        pir_piratHorny = 0;
        root->setVStatus(mood, root->getVStatus(mood)/2);
        root->updVStatus(cumLips,1);
        //gs stat
        root->setImage(":/qwest/pirat/PiratMouth1.jpg");
        root->setDesc(getSexStr(42));
        root->makeActBtn(this, "pir_pirat", "Уйти");
    }
    if(act == "mastr2")
    {
        root->updVStatus(horny, getRandInt(20,30));
        root->incTime(10);
        pir_piratHorny = 0;
        pir_piratsuka += 1;
        root->updVStatus(mood, root->getVStatus(mood)/20);
        //gs stat
        root->setImage(":/qwest/pirat/HandCanine1.jpg");
        root->setDesc(getSexStr(46));
        root->makeActBtn(this, "pir_pirat", "Уйти");
    }
    if(act == "suck2")
    {
        root->updVStatus(horny, getRandInt(5,15));
        root->incTime(5);
        pir_piratsuka += 2;
        pir_DogBJ = 1;
        pir_pirat_sex = root->getVStatus(daystart);
        int temp = getRandInt(1,3);
        root->setImage(":/qwest/pirat/PiratMouth.jpg");
        if(temp == 1)
        {
            root->makeActBtn(this, "cumOnFace", "На лицо");
        }
        else
        {
            root->makeActBtn(this, "cumInMouth", "В рот");
        }
    }
    if(act == "cumOnFace")
    {
        root->updVStatus(horny, getRandInt(15,30));
        root->incTime(5);
        pir_piratHorny = 0;
        root->setVStatus(mood, root->getVStatus(mood)/2);
        //gs zzfuncs cum face
        root->setImage(":/qwest/pirat/PiratMouth2.jpg");
        root->setDesc(getSexStr(48));
        root->makeActBtn(this, "pir_pirat", "Уйти");
    }
    if(act == "cumInMouth")
    {
        root->updVStatus(horny, getRandInt(25,40));
        root->incTime(5);
        pir_piratHorny = 0;
        root->setVStatus(mood, root->getVStatus(mood)/2);
        //gs zzfuncs cum lip
        root->setImage(":/qwest/pirat/PiratMouth1.jpg");
        root->setDesc(getSexStr(49));
        root->makeActBtn(this, "pir_pirat", "Уйти");
    }
    if(act == "allowVag")
    {
        root->incTime(2);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        root->updVSkill(domination, -1);
        //gs stat
        root->setImage(":/qwest/pirat/piratvagknot.jpg");
        root->setDesc(getSexStr(53));
        int vag = root->getVBody(vagina);
        if(vag < 10)
        {
            root->incTime(20);
            root->updVBody(vagina,4);
            root->setVSex(vgape,3);
            root->setVStatus(horny,0);
            //gs stat
            root->addDesc(getSexStr(54));
            root->makeActBtn(this, "next3", "Уйти");
        }
        else if(vag >= 10 && vag < 25)
        {
            root->incTime(20);
            root->updVBody(vagina,3);
            root->setVSex(vgape,2);
            root->updVStatus(horny, -getRandInt(15,30));
            //gs stat
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->updVStatistic(vaginalOrgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                //gs stat
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getSexStr(55));
            }
            else
                root->setDesc(getSexStr(56));
            root->makeActBtn(this, "next3", "Уйти");
        }
        else if(vag >=25 && vag < 35)
        {
            root->incTime(20);
            root->updVBody(vagina,2);
            root->updVStatus(horny, getRandInt(25,50));
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->updVStatistic(vaginalOrgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                //gs stat
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getSexStr(57));
            }
            else
            {
                root->setDesc(getSexStr(58));
            }
            root->makeActBtn(this, "next3", "Уйти");
        }
        else if(vag >= 35)
        {
            root->incTime(20);
            root->updVBody(vagina,1);
            root->updVStatus(horny, getRandInt(50,100));
            if(root->getVStatus(horny) >= 100)
            {
                root->updVStatistic(orgasm,1);
                root->updVStatistic(vaginalOrgasm,1);
                root->setVStatus(horny,0);
                root->setVStatus(mood,100);
                if(root->getVBody(piercingG) == 1)
                {
                    root->setImage(":/qwest/pirat/piratvagcumpirs.jpg");
                }
                else
                {
                    root->setImage(":/qwest/pirat/piratvagcum.jpg");
                }
                root->setDesc(getSexStr(60));
            }
            else
                root->setDesc(getSexStr(61));
            root->makeActBtn(this, "next3", "Уйти");
        }
    }
    if(act == "notAllowVag")
    {
        root->incTime(2);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        int piratboggle = getRandInt(1,5);
        if(piratboggle <= 2)
        {
            root->setImage(":/qwest/pirat/piratvag.jpg");
            root->setDesc(getSexStr(62));
            int vag = root->getVBody(vagina);
            if(vag < 15)
            {
                root->incTime(10);
                root->updVBody(vagina,1);
                if(root->getVSex(vgape) < 3)
                    root->updVSex(vgape,1);
                root->updVStatus(horny, -getRandInt(10,20));
                root->addDesc(getSexStr(63));
                root->makeActBtn(this, "next3", "Уйти");
            }
            else if(vag >=15 && vag < 25)
            {
                root->incTime(10);
                root->updVBody(vagina,1);
                root->updVStatus(horny, getRandInt(15,30));
                if(root->getVStatus(horny) >= 100)
                {
                    root->updVStatistic(orgasm,1);
                    root->updVStatistic(vaginalOrgasm,1);
                    root->setVStatus(horny,0);
                    root->setVStatus(mood,100);
                    if(root->getVBody(piercingG) == 1)
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1pirs.jpg");
                    }
                    else
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1.jpg");
                    }
                    root->addDesc(getSexStr(64));
                }
                else
                    root->addDesc(getSexStr(65));
                root->makeActBtn(this, "next3", "Уйти");
            }
            else if(vag >= 25 && vag < 35)
            {
                root->incTime(20);
                root->updVStatus(horny,getRandInt(30,50));
                if(root->getVStatus(horny) >= 100)
                {
                    root->updVStatistic(orgasm,1);
                    root->updVStatistic(vaginalOrgasm,1);
                    root->setVStatus(horny,0);
                    root->setVStatus(mood,100);
                    if(root->getVBody(piercingG) == 1)
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1pirs.jpg");
                    }
                    else
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1.jpg");
                    }
                    root->addDesc(getSexStr(66));
                }
                else
                    root->addDesc(getSexStr(67));
                root->makeActBtn(this, "next3", "Уйти");
            }
            else if(vag >= 35)
            {
                root->incTime(20);
                root->updVStatus(horny, getRandInt(15,30));

                if(root->getVStatus(horny) >= 100)
                {
                    root->updVStatistic(orgasm,1);
                    root->updVStatistic(vaginalOrgasm,1);
                    root->setVStatus(horny,0);
                    root->setVStatus(mood,100);
                    if(root->getVBody(piercingG) == 1)
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1pirs.jpg");
                    }
                    else
                    {
                        root->setImage(":/qwest/pirat/piratvagcum1.jpg");
                    }
                    root->addDesc(getSexStr(68));
                }
                else
                    root->addDesc(getSexStr(69));
                root->makeActBtn(this, "next3", "Уйти");
            }

        }
        else
        {
            int vag = root->getVBody(vagina);
            if(vag < 15)
            {
                root->incTime(10);
                root->updVBody(vagina,1);
                if(root->getVSex(vgape) < 3)
                    root->updVSex(vgape,1);
                root->updVStatus(horny, - getRandInt(10,20));
                root->setImage(":/qwest/pirat/piratbreak.jpg");
                root->setDesc(getSexStr(70));
                root->makeActBtn(this, "pir_DogVag", "Попробовать снова");
                root->makeActBtn(this, "pir_pirat", "Оставить эту затею");
            }
            else if(vag >= 15 && vag < 25)
            {
                root->incTime(10);
                root->updVBody(vagina,1);
                root->updVStatus(horny, getRandInt(15,30));
                root->setImage(":/qwest/pirat/piratbreak.jpg");
                root->setDesc(getSexStr(71));
                root->makeActBtn(this, "pir_DogVag", "Попробовать снова");
                root->makeActBtn(this, "pir_pirat", "Оставить эту затею");
            }
            else if(vag >= 25 && vag < 35)
            {
                root->incTime(20);
                root->updVStatus(horny, getRandInt(30,50));
                root->setImage(":/qwest/pirat/piratbreak.jpg");
                root->setDesc(getSexStr(72));
                root->makeActBtn(this, "pir_DogVag", "Попробовать снова");
                root->makeActBtn(this, "pir_pirat", "Оставить эту затею");
            }
            else if(vag >= 35)
            {
                root->incTime(20);
                root->updVStatus(horny, getRandInt(15,30));
                root->setImage(":/qwest/pirat/piratbreak.jpg");
                root->setDesc(getSexStr(73));
                root->makeActBtn(this, "pir_DogVag", "Попробовать снова");
                root->makeActBtn(this, "pir_pirat", "Оставить эту затею");
            }
        }
    }
    if(act == "allowAnal")
    {
        root->incTime(2);
        root->setVStatus(mood, root->getVStatus(mood)/2);
        root->updVSkill(domination, -1);
        //gs stat
        root->setImage(":/qwest/pirat/analknot.jpg");
        root->setDesc(getSexStr(76));
        int piratboggle = getRandInt(0,5);
        if(piratboggle <= 4)
        {
            int anusVal = root->getVBody(anus);
            if(anusVal < 15)
            {
                root->incTime(20);
                root->updVBody(anus,4);
                root->setVSex(agape,3);
                root->setVStatus(horny,0);
                //gs zzfuncs cum anus
            }
        }
    }
}

void PiratQuest::pirat_search()
{
    root->incTime(60);
    int tmp = getRandInt(1,2);
    if (tmp == 1)
    {
        root->setImage(":/qwest/pirat/turn_back.jpg");
        root->setDesc(getEvStr(21));
        root->makeActBtn(this, "go&watch", "Пойти посмотреть");
        root->makeActBtn(this, "goaway", "Пройти мимо");
    }
    else
    {
        root->setImage(":/qwest/pirat/pirat_search.jpg");
        root->setDesc(getEvStr(22));
        root->makeActBtn(this, "next", "Далее");
    }
}

void PiratQuest::pirat_forced()
{
    root->incTime(5);
    root->setImage(":/qwest/pirat/leghump.jpg");
    root->setDesc(getEvStr(1));
    if(grandpa_ingadsarai == 1)
    {
        //grandpaQW -= 5
        root->addDesc(getEvStr(2));
    }
    if(grandma_ingadsarai == 1)
    {
        //grandmaQW -= 5
        root->addDesc(getEvStr(3));
    }
    if(grandparents_ingadsarai == 1)
    {
        root->makeActBtn(this, "goHome", "Уйти");
    }
    if(root->getVSkill(domination) > 0)
    {
        root->makeActBtn(this, "push_away", "Оттолкнуть");
    }
    if(grandparents_ingadsarai == 0)
    {
        root->makeActBtn(this, "submiss", "Подчиниться");
    }
}

void PiratQuest::grandparentsIngadsarai()
{
    if(grandma_ingadsarai == 1)
    {
        root->addDesc(getEvStr(26));
    }
    if(grandpa_ingadsarai == 1)
    {
        root->addDesc(getEvStr(27));
    }
}

void PiratQuest::spurn()
{
    pir_piratHorny = 20;
    pir_piratfriend -= 1;
    root->incTime(1);
    root->updVSkill(domination,1);
    root->setImage(":/qwest/pirat/pirat.jpg");
    if(pir_piratsuka < 3)
    {
        root->setDesc(getSexStr(36));
    }
    else
    {
        root->setDesc(getSexStr(37));
    }
    root->makeActBtn(this, "pir_pirat", "Уйти");
}

void PiratQuest::stroking()
{
    if(pir_piratfriend < 5 && pir_stroking != root->getDay())
    {
        pir_stroking = root->getDay();
        pir_piratfriend += 1;
    }
    if(pir_pirat_sex != root->getVStatus(daystart) && pir_stroking != root->getDay() && pir_piratfriend > 5)
    {
        pir_stroking = root->getDay();
        pir_piratHorny += 5;
    }
    root->incTime(15);
    root->switchImageVideo("video");
    if(((ClothMain*)root->getCloth(ClothType::Main))->getClothGroup() == ClothGroup::eveningDress)
        root->setVideo("qrc:/qwest/pirat/dog.webm", 768, 540);
    else
    {
        int val = getRandInt(1,2);
        if(val == 1)
            root->setVideo("qrc:/qwest/pirat/dog1.webm", 720, 540);
        else
            root->setVideo("qrc:/qwest/pirat/dog2.webm", 768, 540);
    }
    root->setVideoDesc(getSexStr(1));
    root->makeActBtn(this, "next3", "Уйти");
}

void PiratQuest::strokingHorny()
{
    root->updVStatus(horny, 20);
    root->incTime(15);
    pir_stroking = root->getDay();
    //gs stat

    if(root->isSkirt())
    {
        if(root->isPanties())
        {
            root->setImage(":/qwest/pirat/sniff1.jpg");
            root->setDesc(getSexStr(2));
        }
        else
        {
            root->setImage(":/qwest/pirat/sniff2.jpg");
            root->setDesc(getSexStr(3));
        }
    }
    else
    {
        root->setImage(":/qwest/pirat/sniff3.jpg");
        root->setDesc(getSexStr(4));
    }
    root->addDesc(getSexStr(5));
    if(grandparents_ingadsarai == 0)
        root->makeActBtn(this, "dog_lick", "Дать полизать киску");
    root->makeActBtn(this, "next5", "Уйти(я же не извращенка какая-нибудь");
}

void PiratQuest::scream()
{
    pir_piratHorny = 0;
    pir_piratfriend -= 5;
    root->incTime(1);
    root->updVSkill(domination,1);
    if(grandpa_ingadsarai == 1) { }
    if(grandma_ingadsarai == 1) {}
    root->setImage(":/qwest/pirat/girl_bawl.jpg");
    root->setDesc(getSexStr(6));
    root->makeActBtn(this, "next3", "Уйти");
}

void PiratQuest::dogLick()
{
    root->setVStatus(horny, 0);
    root->updVStatistic(orgasm, 1);
    root->incTime(1);
    pir_zoo += 1;
    pir_pir_zoo += 1;
    pir_piratfriend = 6;
    root->setVStatus(mood, 100);
    pir_piratHorny += 10;
    //gs stat
    root->switchImageVideo("video");
    root->setVideo("qrc:/qwest/pirat/dog_lick" + intQStr(getRandInt(1,3)) + ".webm", 768, 540);
    if(root->isSkirt() && root->isPanties())
        root->setVideoDesc(getSexStr(7));
    else if(root->isSkirt() && !root->isPanties())
        root->setVideoDesc(getSexStr(8));
    else
        root->setVideoDesc(getSexStr(9));

    if(piratlick == 0)
    {
        piratlick = 1;
        root->addVideoDesc(getSexStr(10));
    }
    else
    {
        root->addVideoDesc(getSexStr(11));
    }
    if(pir_piratsuka >= 7 && pir_DogHJ == 0)
    {
        root->addVideoDesc(getSexStr(12));
        root->makeActBtn(this, "nandjob", "Взять в руку его член");
        root->makeActBtn(this, "next3", "Отвести взгляд и уйти");
    }
    else
    {
        root->makeActBtn(this, "pir_pirat", "Уйти");
    }
}

void PiratQuest::dogLickAss()
{
    root->setVStatus(horny,0);
    root->updVStatistic(orgasm,1);
    root->incTime(1);
    pir_piratsuka += 1;
    pir_zoo += 1;
    root->setVStatus(mood,100);
    pir_piratHorny += getRandInt(10,30);
    //gs stat

    root->setVideo("qrc:/qwest/pirat/dog_lick" + intQStr(getRandInt(4,7)), 768,540);
    if(root->isSkirt() && root->isPanties())
        root->setVideoDesc(getSexStr(13));
    else if(root->isSkirt() && !root->isPanties())
        root->setVideoDesc(getSexStr(14));
    else
        root->setVideoDesc(getSexStr(15));
    if(piratlickass == 0)
    {
        piratlickass = 1;
        root->addVideoDesc(getSexStr(16));
        root->makeActBtn(this, "next3", "Уйти");
    }
    else
    {
        root->addVideoDesc(getSexStr(17));
        if(pir_piratHorny < 40)
        {
            root->addVideoDesc(getSexStr(18));
            root->makeActBtn(this, "next3", "Уйти");
        }
        else
        {
            if(pir_piratsuka >= 7 && pir_DogHJ == 0)
            {
                root->makeActBtn(this, "preHandJob", "Далее");
            }
            else if(pir_piratsuka >= 12)
            {
                root->makeActBtn(this, "comeToLife", "Приходить в себя");
            }
            else
            {
                root->addVideoDesc(getSexStr(35));
                root->makeActBtn(this, "pir_pirat", "Уйти");
            }
        }
    }
}

void PiratQuest::pirDogHJ()
{
    root->updVStatus(horny, getRandInt(5,15));
    root->incTime(1);
    pir_piratsuka += 1;
    pir_zoo += 1;
    pir_pirat_sex = root->getVStatus(daystart);
    //gs stat
    root->setImage(":/qwest/pirat/HandCanine.jpg");
    root->setDesc(getSexStr(38));
    root->makeActBtn(this, "mastr", "Дрочить");
}

void PiratQuest::pirDogBJ()
{
    root->updVStatus(horny, getRandInt(5,15));
    root->incTime(1);
    pir_zoo += 1;
    pir_pirat_sex = root->getVStatus(daystart);
    int temp = getRandInt(1,2);
    //gs stat
    root->setImage(":/qwest/pirat/HandCanine.jpg");
    root->setDesc(getSexStr(45));
    root->makeActBtn(this, "mastr2", "Дрочить");
    root->makeActBtn(this, "suck2", "Взять в рот");

}

void PiratQuest::pirDogVag()
{
    if(root->getVSex(vgape) > 1)
    {
        root->setImage(":/qwest/pirat/predoggy.jpg");
        root->setDesc(getSexStr(50));
        root->makeActBtn(this, "pir_pirat", "Закончить");
    }
    else
    {
        root->incTime(2);
        pir_piratHorny = 0;
        root->setVStatus(mood, root->getVStatus(mood)/2);
        pir_piratsuka += 3;
        pir_zoo += 1;
        pir_DogVag = 1;
        root->updVStatistic(vaginalSex,1);
        pir_pirat_sex = root->getVStatus(daystart);
        //gs stat
        if(root->getVBody(vagina) == 0)
        {
            pir_piratsuka += 5;
            root->setVStatus(horny,0);
            root->incTime(30);
            root->updVBody(vagina,5);
            root->setVSex(vgape,3);
            root->updVStatus(mood,-50);
            root->setImage(":/qwest/pirat/doggyvirgin.jpg");
            root->setDesc(getSexStr(51));
        }
        else
        {
            root->setImage(":/qwest/pirat/piratvag.jpg");
            root->setDesc(getSexStr(52));
        }
        if(root->getVBody(vagina) == 0)
        {
            root->makeActBtn(this, "next3", "Уйти");
        }
        if(root->getVBody(vagina) > 0)
        {
            root->makeActBtn(this, "allowVag", "Позволить");
            root->makeActBtn(this, "notAllowVag", "Предотвратить");
        }
    }
}

void PiratQuest::pirDogAnal()
{
    if(root->getVSex(agape) > 1)
    {
        root->setImage(":/qwest/pirat/predoggy.jpg");
        root->setDesc(getSexStr(74));
        root->makeActBtn(this, "pir_pirat", "Закончить");
    }
    else
    {
        pir_piratsuka += 3;
        root->incTime(5);
        pir_piratHorny = 0;
        root->setVStatus(mood, root->getVStatus(mood)/2);
        pir_DogAnal = 1;
        root->updVStatistic(analSex, 1);
        pir_zoo +=1;
        pir_pirat_sex = root->getVStatus(daystart);
        //gs stat
        root->setImage(":/qwest/pirat/piratanal/jpg");
        root->setDesc(getSexStr(75));
        root->makeActBtn(this, "allowAnal", "Позволить");
    }
}

void PiratQuest::lickingAss()
{
    pir_piratHorny += 30;
    root->incTime(10);
    root->updVStatus(horny, getRandInt(10,20));
    //gs stat
    root->setImage(":/qwest/pirat/piratlickass.jpg");
    root->setDesc(getSexStr(95));
    root->makeActBtn(this, "pir_pirat", "Закончить");
}

void PiratQuest::excite()
{
    root->incTime(10);
    pir_piratHorny = 20;
    int temp = getRandInt(1,10);
    if(temp == 1)
    {
        pir_pirat_sex = root->getVStatus(daystart);
        root->setVideo("qrc:/qwest/pirat/HandCanine1.webm", 768, 540);
        root->setVideoDesc(getSexStr(43));
    }
    if(temp > 1)
    {
        root->setVideo("qrc:/qwest/pirat/HandCanine.webm", 768, 540);
    }
    root->addVideoDesc(getSexStr(44));
    if(temp > 1)
        root->makeActBtn(this, "pir_pirat", "Далее");
    if(temp == 1)
        root->makeActBtn(this, "next3", "Далее");
}

void PiratQuest::pirPirat()
{
    if(pir_piratfriend < 5)
    {
        root->incTime(5);
        //gs stat
        root->setImage(":/qwest/pirat/pirat.jpg");
        root->setDesc(getStr(1));
        grandparentsIngadsarai();
        root->makeActBtn(this, "stroking", "Погладить Пирата");
    }
    if(pir_piratfriend == 5)
    {
        root->incTime(5);
        //gs stat
        root->setImage(":/qwest/pirat/pirat.jpg");
        if(root->getVStatus(horny) < 40)
            root->setDesc(getStr(2));
        else
            root->setDesc(getStr(3));
        grandparentsIngadsarai();
        if(root->getVStatus(horny) < 40)
            root->makeActBtn(this, "stroking", "Погладить Пирата");
        else if(root->getVStatus(horny) >= 40)
            root->makeActBtn(this, "stroking_horny", "Погладить Пирата");
        root->makeActBtn(this, "next3", "Уйти");
    }
    if(pir_piratfriend > 5)
    {
        if(pir_piratHorny < 40)
        {
            if(root->getVStatus(horny) < 40)
            {
                root->setImage(":/qwest/pirat/pirat.jpg");
                if(pir_piratHorny < 20)
                    root->setDesc(getStr(4));
                else
                    root->setDesc(getStr(5));
            }
            else
            {
                root->setImage(":/qwest/pirat/sniff1.jpg");
                root->setDesc(getStr(6));
            }
            grandparentsIngadsarai();
            if(root->getVStatus(horny) >= 40)
                root->makeActBtn(this, "scream", "Наорать на Пирата");
            if(root->getVStatus(horny) >= 40 && grandparents_ingadsarai == 0)
                root->makeActBtn(this, "dog_lick", "Дать полизать писю");
            if(root->getVStatus(horny) >= 40 && pir_piratsuka >= 5 && grandparents_ingadsarai == 0)
                root->makeActBtn(this, "dog_lick_ass", "Дать полизать попу");
            if(pir_piratsuka >= 12 && pir_DogHJ == 1 && (pir_DogVag == 1 || pir_DogAnal == 1) && pir_pirat_sex != root->getVStatus(daystart) && grandparents_ingadsarai == 0)
                root->makeActBtn(this, "excite", "Возбудить Пирата");
            if(pir_piratsuka >= 35 && pir_DogBJ == 1 && (pir_DogVag == 1 || pir_DogAnal == 1) && pir_pirat_sex != root->getVStatus(daystart) && grandparents_ingadsarai == 0)
                root->makeActBtn(this, "licking_ass", "Полизать Пирату задницу");
            root->makeActBtn(this, "stroking", "Погладить Пирата");
            root->makeActBtn(this, "next3", "Уйти");
        }
        else
        {
            if(pir_piratsuka < 5)
            {
                root->setImage(":/qwest/pirat/leghump.jpg");
                root->setDesc(getStr(7));
                grandparentsIngadsarai();
                root->makeActBtn(this, "push_away", "Оттолкнуть Пирата");
                root->makeActBtn(this, "tolerate", "Терпеть");
            }
            else if(pir_piratsuka >= 5 && pir_piratsuka < 7)
            {
                root->setImage(":/qwest/pirat/hump.jpg");
                root->setDesc(getStr(11));
                grandparentsIngadsarai();
                root->makeActBtn(this, "push_away", "Оттолкнуть Пирата");
                root->makeActBtn(this, "onAllFour", "Встать на четвереньки");
            }
            else if(pir_piratsuka > 7)
            {
                root->setImage(":/qwest/pirat/hump.jpg");
                root->setDesc(getStr(15));
                grandparentsIngadsarai();
                root->makeActBtn(this, "push_away", "Оттолкнуть Пирата");
                if(grandparents_ingadsarai == 1)
                    root->makeActBtn(this, "scream", "Наорать на Пирата");
                if(root->getVStatus(horny) >= 40 && pir_DogHJ == 0 && grandparents_ingadsarai == 0)
                    root->makeActBtn(this, "dog_lick", "Дать полизать писю");
                if(root->getVStatus(horny) >= 40 && pir_piratsuka >= 15 && (pir_DogVag == 0 || pir_DogAnal == 0) && grandparents_ingadsarai == 0)
                    root->makeActBtn(this, "dog_lick_ass", "Дать полизать попу");
                if(pir_DogHJ == 1 && pir_DogBJ == 0 && grandparents_ingadsarai == 0)
                    root->makeActBtn(this, "handjob", "Взять в руку его член");
                if(pir_piratsuka >= 10 && pir_DogBJ == 1 && grandparents_ingadsarai == 0)
                    root->makeActBtn(this, "blowjob", "Взять в руку его член");
                if(pir_piratsuka >= 12 && (pir_DogVag == 1 || pir_DogAnal == 1) && grandparents_ingadsarai == 0)
                    root->makeActBtn(this, "undress&onAllFour", "Снять трусики и встать на четвереньки");
            }
            root->makeActBtn(this, "next3", "Отойти");
        }
    }
}

void PiratQuest::initDefault()
{
    pir_pirat = 0;
    know_no_pirat = 1;
    pir_pirat_search = 0;
    pirat = 0;
    pir_piratfriend = 0;
    pir_piratsuka = 0;
    pir_pirat_sex = 0;
}

void PiratQuest::initStrings()
{
    getStrings(":/Quests/gadukino/str", str);
    getStrings(":/Quests/gadukino/evStr", evStrings);
    getStrings(":/Quests/gadukino/sexStr", sexStrings);
}

void PiratQuest::getStrings(QString path, QString arr[])
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file! " + file.fileName();
    }
    else
    {
        QTextStream in(&file);
        QString line; int i = 0;
        while (!in.atEnd())
        {
            arr[i] = in.readLine();
            i++;
        }
    }
}

QString &PiratQuest::getStr(int id)
{
    return str[id - 1];
}

QString &PiratQuest::getEvStr(int id)
{
    return evStrings[id - 1];
}

QString &PiratQuest::getSexStr(int id)
{
    return sexStrings[id - 1];
}
