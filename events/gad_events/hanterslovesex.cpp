#include "hanterslovesex.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

HantersLoveSex::HantersLoveSex(EventHandler* ptr): root(ptr) {}

void HantersLoveSex::start(QString arg)
{
    if(!arg.isEmpty())
    {
        actionHandler(arg);
        return;
    }
    if(root->gVEvent(hantersIgorLove) > 0 && root->gVQuest(hantersIgorQW) <= 50)
    {
        root->rendImagePage();
        root->sVSex(dick,16);
        root->sVSex(silavag,2);
        root->sVSex(harakBoy,0);
        root->setBoyName(str(185));
        root->incTime(5);
        // if(root->gVEvent(hantersIgorLove) == 2) bfa += 1;
        if(root->gVEvent(hantersIgorsex) == 0)
        {
            root->uVSex(guy,1);
            root->sVEvent(hantersIgorsex,1);
        }
        root->sVEvent(boyonceA,1);
        root->sVEvent(hanters_bj_times,0);
        root->setImage(media(184));
        root->setDesc(str(188));
        if(root->vBody(vagina) == 0 && root->vSC(vaginalSex) == 0)
        {
            if(root->gVSchool(vacation) == 0)
                makeActBtn("virgin_schoolgirl",act(35));
            else
                makeActBtn("virgin",act(35));
        }
        else
            makeActBtn("undress",act(34));
    }
    else if(root->gVEvent(hantersIgorLove) > 0 && root->gVQuest(hantersIgorQW) > 50)
    {
        root->rendVideoPage();
        root->sVSex(dick,16);
        root->sVSex(silavag,2);
        root->sVSex(harakBoy,0);
        root->setBoyName(str(185));
        // if(root->gVEvent(hantersIgorLove) == 2) bfa += 1;
        if(root->gVEvent(hantersIgorsex) == 0)
        {
            root->uVSex(guy,1);
            root->sVEvent(hantersIgorsex,1);
        }
        root->sVEvent(boyonceA,1);
        root->sVEvent(hanters_bj_times,0);
        root->incTime(5);
        root->uVStatus(horny,getRandInt(10,20));
        int i = getRandInt(1,3);
        if(root->vStatus(horny) >= 60)
        {
            setVideo(media(getRandInt(92,113)));
            root->setDesc(str(195));
            if(root->isMesec())
                root->addDesc(str(194));
            makeActBtn("jumpOnIt",act(39));
            makeActBtn("undress_v2",act(34));
        }
        else if(root->vStatus(horny) < 60 && i == 1)
        {
            setVideo(media(108));
            root->setDesc(str(198));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_misionary",act(42));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 1)
        {
            setVideo(media(112));
            root->setDesc(str(199));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_kuni",act(17));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 0)
        {
            setVideo(media(113));
            root->setDesc(str(200));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("bj200",act(9));
        }
        else if(root->vStatus(horny) < 60 && i == 3)
        {
            setVideo(media(getRandInt(109,111)));
            root->setDesc(str(201));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_dog",act(5));
        }
    }
    if(root->gVEvent(hantersAndreiLove) > 0 && root->vBody(vagina) == 0)
    {
        root->rendImagePage();
        root->sVSex(dick,20);
        root->sVSex(silavag,0);
        root->sVSex(harakBoy,2);
        root->setBoyName(str(186));
        root->incTime(5);
        root->sVEvent(hanters_bj_times,0);
        if(root->gVEvent(hantersAndreisex) == 0)
        {
            root->sVEvent(hantersAndreisex,1);
            root->sVSex(guy,1);
        }
        root->setImage(media(185));
        root->setDesc(str(188));
        makeActBtn("virginA",act(35));
    }
    else if(root->gVEvent(hantersAndreiLove) > 0 && root->vBody(vagina) > 0)
    {
        root->rendVideoPage();
        root->sVSex(dick,20);
        root->sVSex(silavag,0);
        root->sVSex(harakBoy,2);
        root->setBoyName(str(186));
        root->incTime(5);
        root->sVEvent(hanters_bj_times,0);
        root->uVStatus(horny,getRandInt(10,20));
        if(root->gVEvent(hantersAndreisex) == 0)
        {
            root->sVEvent(hantersAndreisex,1);
            root->sVSex(guy,1);
        }
        int i = getRandInt(1,3);
        if(root->vStatus(horny) >= 60)
        {
            setVideo(media(getRandInt(92,113)));
            root->setDesc(str(195));
            if(root->isMesec())
                root->addDesc(str(194));
            makeActBtn("jumpOnIt",act(39));
            makeActBtn("undress_v2",act(34));
        }
        else if(root->vStatus(horny) < 60 && i == 1)
        {
            setVideo(media(108));
            root->setDesc(str(198));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_misionary",act(42));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 1)
        {
            setVideo(media(112));
            root->setDesc(str(199));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_kuni",act(17));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 0)
        {
            setVideo(media(113));
            root->setDesc(str(200));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("bj200",act(9));
        }
        else if(root->vStatus(horny) < 60 && i == 3)
        {
            setVideo(media(getRandInt(109,111)));
            root->setDesc(str(201));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_dog",act(5));
        }
    }
    if(root->gVEvent(hantersSergeiLove) > 0 && root->gVQuest(hantersSergeiQW) <= 40)
    {
        root->rendImagePage();
        root->sVSex(dick,18);
        root->sVSex(silavag,1);
        root->sVSex(harakBoy,1);
        root->setBoyName(str(187));
        root->incTime(5);
        if(root->gVEvent(hantersSergeisex) == 0)
        {
            root->sVEvent(hantersSergeisex,1);
            root->uVSex(guy,1);
        }
        root->sVEvent(boyonceA,1);
        root->sVEvent(hanters_bj_times,0);
        root->setImage(media(186));
        root->setDesc(str(188));
        if(root->vBody(vagina) == 0 && root->vSC(vaginalSex) == 0)
        {
            if(root->gVSchool(vacation) == 0)
                makeActBtn("virgin_schoolgirl2",act(35));
            else
                makeActBtn("virgin",act(35));
        }
        else
            makeActBtn("undress",act(34));
    }
    else if(root->gVEvent(hantersSergeiLove) > 0 && root->gVQuest(hantersSergeiQW) > 40)
    {
        root->rendVideoPage();
        root->sVSex(dick,18);
        root->sVSex(silavag,1);
        root->sVSex(harakBoy,1);
        root->setBoyName(str(187));
        root->incTime(5);
        if(root->gVEvent(hantersSergeisex) == 0)
        {
            root->sVEvent(hantersSergeisex,1);
            root->uVSex(guy,1);
        }
        root->sVEvent(boyonceA,1);
        root->sVEvent(hanters_bj_times,0);
        root->uVStatus(horny,getRandInt(10,20));
        int i = getRandInt(1,3);
        if(root->vStatus(horny) >= 60)
        {
            setVideo(media(getRandInt(92,96)));
            root->setDesc(str(195));
            if(root->isMesec())
                root->addDesc(str(194));
            makeActBtn("jumpOnIt",act(39));
            makeActBtn("undress_v2",act(34));
        }
        else if(root->vStatus(horny) < 60 && i == 1)
        {
            setVideo(media(108));
            root->setDesc(str(198));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_misionary",act(42));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 1)
        {
            setVideo(media(112));
            root->setDesc(str(199));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_kuni",act(17));
        }
        else if(root->vStatus(horny) < 60 && i == 2 && root->vSex(hanters_kuni) == 0)
        {
            setVideo(media(113));
            root->setDesc(str(200));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("bj200",act(9));
        }
        else if(root->vStatus(horny) < 60 && i == 3)
        {
            setVideo(media(getRandInt(109,111)));
            root->setDesc(str(201));
            if(root->isMesec())
            {
                root->addDesc(str(194));
                bj();
            }
            else
                makeActBtn("sex_dog",act(5));
        }
    }
}

void HantersLoveSex::actionHandler(QString action)
{
    if(action == "virgin_schoolgirl")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(91));
        if(root->gVQuest(hantersIgorQW) <= 45)
        {
            root->setDesc(str(189));
            bj();
        }
        if(root->gVQuest(hantersIgorQW) > 45)
        {
            root->setDesc(str(190));
            makeActBtn("first_sex",act(36));
            makeActBtn("breakUpWithGuy",act(37));
        }
    }
    if(action == "breakUpWithGuy")
    {
        root->rendVideoPage();
        root->incTime(5);
        //if hantersIgorLove = 2: bfA = 0
        root->sVEvent(hantersIgorLove,0);
        root->sVQuest(hantersIgorQW,-100);
        root->uVSkill(domination,1);
        setVideo(media(91));
        root->setDesc(str(191));
        makeActBtn("back_to_loc",act(38));
    }
    if(action == "virgin")
    {
        root->incTime(5);
        root->addDesc(str(192));
        bj();
        makeActBtn("first_sex",act(36));
    }
    if(action == "undress")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(getRandInt(97,103)));
        root->setDesc(str(193));
        if(root->isMesec())
        {
            root->addDesc(str(194));
            bj();
        }
        if(!root->isMesec())
            makeActBtn("bj200",act(9));
    }

    if(action == "jumpOnIt")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(getRandInt(104,107)));
        root->setDesc(str(196));
        if(root->vStatus(horny) >= 80 && !root->isMesec())
            makeActBtn("sex_cow",act(40));
        if(root->vStatus(horny) < 80 && !root->isMesec())
            makeActBtn("bj200",act(9));
        if(root->isMesec())
            bj();
    }
    if(action == "undress_v2")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(getRandInt(97,103)));
        root->setDesc(str(197));
        int dom = root->vSkill(domination);
        if(dom > 50 && !root->isMesec())
            makeActBtn("sex_cow",act(4));
        if(dom > 30 && !root->isMesec())
            makeActBtn("sex_misionary",act(42));
        if(dom > 10 && !root->isMesec())
            makeActBtn("bj200",act(9));
        if(dom <= 10 && !root->isMesec())
            makeActBtn("sub",act(41));
        if(root->isMesec()) bj();
    }

    if(action == "virginA")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(91));
        root->setDesc(str(202));
        makeActBtn("first_sex",act(36));
        makeActBtn("breakUpWithGuyA",act(37));
    }
    if(action == "breakUpWithGuyA")
    {
        root->rendVideoPage();
        root->incTime(5);
        root->sVEvent(hantersAndreiLove,0);
        root->uVQuest(hantersAndreiQW,-1);
        root->uVSkill(domination,1);
        setVideo(media(91));
        root->setDesc(str(203));
        makeActBtn("back_to_loc",act(38));
    }

    if(action == "virgin_schoolgirl2")
    {
        root->rendVideoPage();
        root->incTime(5);
        setVideo(media(91));
        if(root->gVQuest(hantersSergeiQW) <= 35)
        {
            root->setDesc(str(189));
            bj();
        }
        if(root->gVQuest(hantersSergeiQW) > 35)
        {
            root->setDesc(str(204));
            makeActBtn("first_sex",act(36));
            makeActBtn("breakUpWithGuyS",act(37));
        }
    }

    if(action == "breakUpWithGuyS")
    {
        root->rendVideoPage();
        root->incTime(5);
        root->sVEvent(hantersSergeiLove,0);
        root->uVQuest(hantersSergeiQW,-1);
        root->uVSkill(domination,1);
        setVideo(media(91));
        root->setDesc(str(203));
        makeActBtn("back_to_loc",act(38));
    }

    if(action == "bj") bj();
    if(action == "bj1") bj1();
    if(action == "bj2") bj2();
    if(action == "bj3") bj3();
    if(action == "bj4") bj4();
    if(action == "bj5") bj5();
    if(action == "bj6") bj6();
    if(action == "bj7") bj7();
    if(action == "bj8") bj8();
    if(action == "bj9") bj9();
    if(action == "bj10") bj10();
    if(action == "bj11") bj11();
    if(action == "bj12") bj12();
    if(action == "bj13") bj13();
    if(action == "bj14") bj14();
    if(action == "bj200") bj200();
    if(action == "bj_bonus1") bj_bonus1();
    if(action == "bj_bonus2") bj_bonus2();
    if(action == "bj_bonus3") bj_bonus3();
    if(action == "bj_bonus4") bj_bonus4();
    if(action == "bj_bonus5") bj_bonus5();
    if(action == "bj_bonus6") bj_bonus6();
    if(action == "bj_bonus7") bj_bonus7();
    if(action == "bj_bonus8") bj_bonus8();
    if(action == "bj_bonus11") bj_bonus11();
    if(action == "bj_bonus12") bj_bonus12();
    if(action == "bj_bonusH1") bj_bonusH1();
    if(action == "bj_bonusH2") bj_bonusH2();
    if(action == "bj_bonusH3") bj_bonusH3();
    if(action == "bj_bonusH4") bj_bonusH4();

    if(action == "bj_bonusH6") bj_bonusH6();
    if(action == "bj_bonusH7") bj_bonusH7();
    if(action == "bj_bonusH8") bj_bonusH8();

    if(action == "bjH1") bjH1();
    if(action == "bjH2") bjH2();
    if(action == "bjH3") bjH3();
    if(action == "bjH4") bjH4();

    if(action == "bjH6") bjH6();
    if(action == "bjH7") bjH7();
    if(action == "bjH8") bjH8();

    if(action == "sex_69") sex_69();

    if(action == "sex_bell") sex_bell();
    if(action == "sex_bell_anal") sex_bell_anal();
    if(action == "sex_bell_analH") sex_bell_analH();
    if(action == "sex_bell_bonus") sex_bell_bonus();
    if(action == "sex_bell_bonus1") sex_bell_bonus1();

    if(action == "sex_cow") sex_cow();
    if(action == "sex_cow_anal") sex_cow_anal();
    if(action == "sex_cow_anal1") sex_cow_anal1();
    if(action == "sex_cow_anal2") sex_cow_anal2();
    if(action == "sex_cow_analH") sex_cow_analH();
    if(action == "sex_cow_bonus") sex_cow_bonus();
    if(action == "sex_cow_bonus1") sex_cow_bonus1();
    if(action == "sex_cow_bonus2") sex_cow_bonus2();
    if(action == "sex_cow_bonus3") sex_cow_bonus3();

    if(action == "sex_dog") sex_dog();
    if(action == "sex_dog_anal") sex_dog_anal();
    if(action == "sex_dog_analH") sex_dog_analH();
    if(action == "sex_dog_bonus") sex_dog_bonus();
    if(action == "sex_dog_bonus1") sex_dog_bonus1();
    if(action == "sex_dog_bonus2") sex_dog_bonus2();

    if(action == "sex_kuni") sex_kuni();
    if(action == "sex_kuni_bonus") sex_kuni_bonus();

    if(action == "sex_misionary") sex_misionary();
    if(action == "sex_misionary_anal") sex_misionary_anal();
    if(action == "sex_misionary_analH") sex_misionary_analH();
    if(action == "sex_misionary_bonus") sex_misionary_bonus();
    if(action == "sex_misionary_bonus1") sex_misionary_bonus1();
    if(action == "sex_misionary_bonus2") sex_misionary_bonus2();

    if(action == "sex_hand") sex_hand();
    if(action == "sex_hand_bonus") sex_hand_bonus();

    if(action == "sex_cum1") sex_cum1();
    if(action == "sex_cum2") sex_cum2();
    if(action == "sex_cum3") sex_cum3();
    if(action == "sex_cum4") sex_cum4();
    if(action == "sex_cum41") sex_cum41();
    if(action == "sex_cum5") sex_cum5();
    if(action == "sex_cum6") sex_cum6();
    if(action == "sex_cum7") sex_cum7();
    if(action == "sex_cum8") sex_cum8();
    if(action == "sex_cum81") sex_cum81();
    if(action == "sex_cum9") sex_cum9();
    if(action == "sex_cum10") sex_cum10();
    if(action == "sex_cum11") sex_cum11();

    if(action == "sex_cumface1") sex_cumface1();
    if(action == "sex_cumface2") sex_cumface2();
    if(action == "sex_cumface3") sex_cumface3();
    if(action == "sex_cumface4") sex_cumface4();
    if(action == "sex_cumface5") sex_cumface5();
    if(action == "sex_cumface6") sex_cumface6();
    if(action == "sex_cumface7") sex_cumface7();

    if(action == "first_sex") first_sex();
    if(action == "start_bj")
    {
        root->rendVideoPage();
        root->incTime(5);
        root->uVSex(bj_temp,1);
        setVideo(media(getRandInt(25,30)));
        root->setDesc(str(44));
        if(root->vSC(blowJob) > 10)
            makeActBtn("bjH2",act(10));
        if(root->vSC(blowJob) > 5 && root->vSC(blowJob) <= 10)
            makeActBtn("bjH1",act(11));
        if(root->vSC(blowJob) > 2 && root->vSC(blowJob) <= 5)
            makeActBtn("bjH3",act(12));
        if(root->vSC(blowJob) <= 2)
            makeActBtn("bjH4",act(13));
    }
    if(action == "want_more1.0")
    {
        root->rendVideoPage();
        root->uVSex(dikos,1);
        root->incTime(5);
        root->sVEvent(hanters_bj_times,0);
        setVideo(media(88));
        root->setDesc(str(56));
        if(root->vBody(vagina) == 0) bj();
        if(root->vBody(vagina) > 0)
        {
            int i = getRandInt(1,5);
            if(i == 1) makeActBtn("sex_cow",act(16));
            if(i == 2) makeActBtn("sex_misionary",act(3));
            if(i == 3) makeActBtn("bj200",act(9));
            if(i == 4 && root->vSex(hanters_kuni) == 0) makeActBtn("bj200",act(9));
            if(i == 4 && root->vSex(hanters_kuni) == 1) makeActBtn("sex_kuni",act(17));
            if(i == 5) makeActBtn("sex_dog",act(5));
        }
    }
    if(action == "want_more2.0")
    {
        root->rendVideoPage();
        root->uVSex(dikos,1);
        root->incTime(5);
        root->sVEvent(hanters_bj_times,0);
        setVideo(media(88));
        root->setDesc(str(57));
        if(root->vBody(vagina) == 0) bj();
        if(root->vBody(vagina) > 0)
        {
            int i = getRandInt(1,5);
            if(i == 1) makeActBtn("sex_cow",act(16));
            if(i == 2) makeActBtn("sex_misionary",act(3));
            if(i == 3) makeActBtn("bj200",act(9));
            if(i == 4 && root->vSex(hanters_kuni) == 0) makeActBtn("bj200",act(9));
            if(i == 4 && root->vSex(hanters_kuni) == 1) makeActBtn("sex_kuni",act(17));
            if(i == 5) makeActBtn("sex_dog",act(5));
        }

    }
    if(action == "exit_sex")
    {
        root->sVEvent(hanters_bj_times,0);
        root->sVSex(dikos,0);
        root->changeLoc(root->getCurLoc());
    }
    if(action == "swallow")
    {
        root->rendImagePage();
        root->incTime(1);
        root->uVSC(swallow,1);
        root->setImage(media(getRandInt(181,182)));
        root->setDesc(str(66));
        if(root->vSex(harakBoy) == 2) root->addDesc(str(67));
        sex_cum_common();
    }
    if(action == "spit_it_out")
    {
        root->rendImagePage();
        root->incTime(1);
        root->setImage(media(183));
        root->setDesc(str(68));
        if(root->vSex(harakBoy) == 2) root->addDesc(str(69));
        sex_cum_common();
    }
    if(action == "start_kuni")
    {
        root->rendVideoPage();
        root->incTime(5);
        root->sVSex(hanters_kuni,1);
        root->uVSC(getKuni,1);
        root->uVSex(kuni_temp,1);
        if(root->vSex(silavag) == 0) root->uVStatus(horny,15);
        if(root->vSex(silavag) == 1) root->uVStatus(horny,20);
        if(root->vSex(silavag) == 2) root->sVStatus(horny,25);
        setVideo(media(getRandInt(125,128)));
        root->setDesc(str(135));
        if(root->vStatus(horny) >= 90)
        {
            root->sVStatus(lust,0);
            root->sVStatus(horny,0);
            root->uVStatus(mood,15);
            root->uVSC(orgasm,1);
            root->addDesc(str(85));
        }
        else
            root->addDesc(str(86));
        if(root->vSkill(domination) >= 75)
            root->addDesc(str(136));
        int i = getRandInt(1,5);
        if(i == 1) makeActBtn("sex_misionary",act(0));
        if(i == 2) makeActBtn("sex_cow",act(0));
        if(i == 3) makeActBtn("sex_dog",act(0));
        if(i == 4) makeActBtn("sex_bell",act(0));
        if(i == 5) makeActBtn("sex_hand",act(0));
    }
    if(action == "first_sex_next")
    {
        root->incTime(5);
        root->setImage(media(89));
        if(root->vSex(harakBoy) == 2) root->addDesc(str(178));
        if(root->vSex(harakBoy) == 1) root->addDesc(str(179));
        if(root->vSex(harakBoy) == 0) root->addDesc(str(180));
        root->addDesc(str(181));
        if(root->vSex(harakBoy) == 2) root->addDesc(str(182));
        if(root->vSex(harakBoy) == 1) root->addDesc(str(183));
        if(root->vSex(harakBoy) == 0) root->addDesc(str(184));
        makeActBtn("back_to_loc",act(33));
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
}

void HantersLoveSex::first_sex()
{
    root->rendImagePage();
    root->incTime(30);
    root->uVEvent(hantersVagSex,1);
    root->setImage(media(90));
    root->setDesc(str(177));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    makeActBtn("first_sex_next",act(32));
}

void HantersLoveSex::bj_common()
{
    //part1
    int h = getRandInt(1,3);
    bj_common1(h);
    //part2
    bj_common2();
    //part3
    bj_common3(h);
    //part4
    bj_common4(h);
}
void HantersLoveSex::bj_common1(int h)
{
    if(h < 3 && root->gVEvent(hanters_bj_times) == 3)
        root->addDesc(str(7));
    if(root->gVEvent(hanters_bj_times) < 3 && root->gVEvent(hanters_bj_times) >= 1)
    {
        int k = getRandInt(1,4);
        if(k == 1) root->addDesc(str(8));
        if(k == 2) root->addDesc(str(9));
        if(k == 3) root->addDesc(str(10));
        if(k == 4) root->addDesc(str(11));
    }
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        root->addDesc(str(12));
}
void HantersLoveSex::bj_common1_alt(int h)
{
    if(h < 3 && root->gVEvent(hanters_bj_times) == 3)
        root->addDesc(str(7));
    if(root->gVEvent(hanters_bj_times) < 3 && root->gVEvent(hanters_bj_times) >= 1)
    {
        int k = getRandInt(1,4);
        if(k == 1) root->addDesc(str(143));
        if(k == 2) root->addDesc(str(144));
        if(k == 3) root->addDesc(str(145));
        if(k == 4) root->addDesc(str(146));
    }
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        root->addDesc(str(12));
}
void HantersLoveSex::bj_common2()
{
    if(root->gVEvent(hanters_bj_times) < 3)
    {
        int i = getRandInt(1,2);
        if(root->vSC(blowJob) <= 10) makeActBtn("bjH7",act(1));
        if(root->vSC(blowJob) > 10 && i == 1) makeActBtn("bjH7",act(1));
        if(root->vSC(blowJob) > 10 && i == 2) makeActBtn("bjH8",act(2));
    }
}
void HantersLoveSex::bj_common2_alt()
{
    if(root->gVEvent(hanters_bj_times) < 3)
        makeActBtn("bjH6",act(8));
}
void HantersLoveSex::bj_common2_alt2()
{
    if(root->gVEvent(hanters_bj_times) < 3)
    {
        int i = getRandInt(1,4);
        int j = getRandInt(1,4);
        int dom = root->vSkill(domination);
        int rot = root->vBody(throat);
        if(i == 1) makeActBtn("bj6",act(8));
        if(i == 2 && dom >= 10) makeActBtn("bj7",act(25));
        if(i == 2 && dom < 10)  makeActBtn("bj8",act(26));
        if(i == 3 && dom >= 30 && rot > 15) makeActBtn("bj9",act(27));
        if(i == 3 && dom < 30 && rot > 15) makeActBtn("bj10",act(28));
        if(i == 3 && dom >= 30 && rot <= 15) makeActBtn("bj11",act(1));
        if(i == 3 && dom < 30 && rot <= 15) makeActBtn("bj12",act(2));
        if(i == 4 && j == 1) makeActBtn("bj1",act(11));
        if(i == 4 && j == 2) makeActBtn("bj2",act(10));
        if(i == 4 && j == 3) makeActBtn("bj3",act(12));
        if(i == 4 && j == 4) makeActBtn("bj5",act(29));
    }
}
void HantersLoveSex::bj_common2_alt3()
{
    if(root->gVEvent(hanters_bj_times) < 3)
    {
        int i = getRandInt(1,3);
        int j = getRandInt(1,4);
        int dom = root->vSkill(domination);
        int tits = root->vBody(breastsSize);
        if(i == 1) makeActBtn("bj6",act(8));
        if(i == 2 && dom >= 10 && dom < 30) makeActBtn("bj7",act(25));
        if(i == 2 && dom < 10)  makeActBtn("bj8",act(26));
        if(i == 2 && dom >= 30 && tits < 3) makeActBtn("bj13",act(30));
        if(i == 2 && dom >= 30 && tits >= 3) makeActBtn("bj14",act(31));
        if(i == 3 && j == 1) makeActBtn("bj1",act(11));
        if(i == 3 && j == 2) makeActBtn("bj2",act(10));
        if(i == 3 && j == 3) makeActBtn("bj3",act(12));
        if(i == 3 && j == 4) makeActBtn("bj5",act(29));
    }
}

void HantersLoveSex::bj_common2_alt4()
{
    if(root->gVEvent(hanters_bj_times) < 3)
    {
        int i = getRandInt(1,3);
        int j = getRandInt(1,4);
        int dom = root->vSkill(domination);
        int tits = root->vBody(breastsSize);
        int rot = root->vBody(throat);
        if(i == 1 && dom >= 30 && rot > 15) makeActBtn("bj9",act(27));
        if(i == 1 && dom < 30 && rot > 15) makeActBtn("bj10",act(28));
        if(i == 1 && dom >= 30 && rot <= 15) makeActBtn("bj11",act(1));
        if(i == 1 && dom < 30 && rot <= 15) makeActBtn("bj12",act(2));
        if(i == 2 && tits < 3) makeActBtn("bj13",act(30));
        if(i == 2 && tits >= 3) makeActBtn("bj14",act(31));
        if(i == 3 && j == 1) makeActBtn("bj1",act(11));
        if(i == 3 && j == 2) makeActBtn("bj2",act(10));
        if(i == 3 && j == 3) makeActBtn("bj3",act(12));
        if(i == 3 && j == 4) makeActBtn("bj5",act(29));
    }
}

void HantersLoveSex::bj_common2_alt5()
{
    if(root->gVEvent(hanters_bj_times) < 3)
    {
        int i = getRandInt(1,3);
        int dom = root->vSkill(domination);
        int rot = root->vBody(throat);
        int tits = root->vBody(breastsSize);
        if(i == 1) makeActBtn("bj6",act(8));
        if(i == 2 && dom >= 10 && dom < 30) makeActBtn("bj7",act(25));
        if(i == 2 && dom < 10) makeActBtn("bj8",act(26));
        if(i == 3 && dom >= 30 && rot > 15) makeActBtn("bj9",act(27));
        if(i == 3 && dom < 30 && rot > 15) makeActBtn("bj10",act(28));
        if(i == 3 && dom >= 30 && rot <= 15) makeActBtn("bj11",act(1));
        if(i == 3 && dom < 30 && rot <= 15) makeActBtn("bj12",act(2));
        if(i == 3 && dom >= 30 && tits < 3) makeActBtn("bj13",act(30));
        if(i == 3 && dom >= 30 && tits >= 3) makeActBtn("bj14",act(31));
    }
}
void HantersLoveSex::bj_common3(int h)
{
    if(h < 3 && root->gVEvent(hanters_bj_times) >= 3)
    {
        int i = getRandInt(1,4);
        if(i == 1) makeActBtn("sex_misionary_analH",act(3));
        if(i == 2) makeActBtn("sex_cow_analH",act(4));
        if(i == 3) makeActBtn("sex_dog_analH",act(5));
        if(i == 4) makeActBtn("sex_bell_analH",act(6));
        i = getRandInt(1,2);
        if(root->vSC(blowJob) <= 10) makeActBtn("bjH7",act(1));
        if(root->vSC(blowJob) > 10 && i == 1) makeActBtn("bjH7",act(1));
        if(root->vSC(blowJob) > 10 && i == 2) makeActBtn("bjH8",act(2));
    }
}
void HantersLoveSex::bj_common3_alt(int h)
{
    if(h < 3 && root->gVEvent(hanters_bj_times) >= 3)
    {
        int i = getRandInt(1,4);
        if(i == 1) makeActBtn("sex_misionary_analH",act(3));
        if(i == 2) makeActBtn("sex_cow_analH",act(4));
        if(i == 3) makeActBtn("sex_dog_analH",act(5));
        if(i == 4) makeActBtn("sex_bell_analH",act(6));
    }
}
void HantersLoveSex::bj_common3_alt2(int h)
{
    if(h < 3 && root->gVEvent(hanters_bj_times) >= 3)
    {
        int i = getRandInt(1,5);
        if(i == 1) makeActBtn("sex_misionary",act(3));
        if(i == 2) makeActBtn("sex_cow",act(4));
        if(i == 3) makeActBtn("sex_dog",act(5));
        if(i == 4) makeActBtn("sex_bell",act(6));
        if(i == 5) makeActBtn("sex_hand",act(22));
    }
}
void HantersLoveSex::bj_common4(int h)
{
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
    {
        int i = getRandInt(1,2);
        if(i == 1) makeActBtn("sex_cumface1",act(7));
        if(i == 2) makeActBtn("sex_cumface2",act(7));
    }
}
void HantersLoveSex::bj_common4_alt(int h)
{
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        makeActBtn("sex_cumface3",act(7));
}

void HantersLoveSex::bj()
{
    makeActBtn("start_bj",act(9));
}
void HantersLoveSex::bj1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(31,34)));
    int h = getRandInt(1,3);
    if(root->vBody(piercingA) == 0) root->setDesc(str(3));
    if(root->vBody(piercingA) > 0) root->setDesc(str(4));
    root->addDesc(str(5));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(175));
    bj_common1_alt(h);
    bj_common2_alt5();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(35,41)));
    int h = getRandInt(1,3);
    if(root->vBody(piercingA) == 0) root->setDesc(str(17));
    if(root->vBody(piercingA) > 0) root->setDesc(str(18));
    root->addDesc(str(19));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(174));
    bj_common1_alt(h);
    bj_common2_alt5();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(42,43)));
    int h = getRandInt(1,3);
    root->setDesc(str(22));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(173));
    bj_common1_alt(h);
    bj_common2_alt5();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj4()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(44,45)));
    int h = getRandInt(1,3);
    root->setDesc(str(170));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSkill(domination) < 30)
        root->addDesc(str(171));
    bj_common1_alt(h);
    bj_common2_alt5();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj5()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(46,49)));
    int h = getRandInt(1,3);
    root->setDesc(str(168));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSC(blowJob) > 20)
        root->addDesc(str(169));
    bj_common1_alt(h);
    bj_common2_alt5();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj6()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(hj_temp,1);
    setVideo(media(getRandInt(50,51)));
    int h = getRandInt(1,3);
    root->setDesc(str(32));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(33));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(34));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSC(blowJob) > 10)
        root->addDesc(str(166));
    bj_common1_alt(h);
    bj_common2_alt4();
    bj_common3_alt2(h);
    bj_common4_alt(h);
}
void HantersLoveSex::bj7()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(52,56)));
    int h = getRandInt(1,3);
    root->setDesc(str(164));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSC(blowJob) > 15)
        root->addDesc(str(165));

    bj_common1_alt(h);
    bj_common2_alt4();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj8()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(57,58)));
    int h = getRandInt(1,3);
    root->setDesc(str(161));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSkill(domination) > 0)
        root->addDesc(str(162));
    bj_common1_alt(h);
    bj_common2_alt4();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj9()
{
    root->rendVideoPage();
    root->incTime(5);
    if(root->vSex(dick) > root->vBody(throat))
        root->uVBody(throat,1);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(59,60)));
    int h = getRandInt(1,3);
    root->setDesc(str(156));
    bj_common1_alt(h);
    bj_common2_alt3();
    bj_common3_alt2(h);
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        makeActBtn("sex_cumface6",act(7));
}
void HantersLoveSex::bj10()
{
    root->rendVideoPage();
    root->incTime(5);
    if(root->vSex(dick) > root->vBody(throat))
        root->uVBody(throat,1);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(61,64)));
    int h = getRandInt(1,3);
    root->setDesc(str(155));
    bj_common1_alt(h);
    bj_common2_alt3();
    bj_common3_alt2(h);
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        makeActBtn("sex_cumface6",act(7));
}
void HantersLoveSex::bj11()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(65,69)));
    int h = getRandInt(1,3);
    root->setDesc(str(37));
    if(root->gVEvent(hanters_bj_times) < 3 && root->vSC(blowJob) > 20)
        root->addDesc(str(154));
    bj_common1_alt(h);
    bj_common2_alt3();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj12()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(70,72)));
    int h = getRandInt(1,3);
    root->setDesc(str(42));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(149));
    bj_common1_alt(h);
    bj_common2_alt3();
    bj_common3_alt2(h);
    bj_common4(h);
}
void HantersLoveSex::bj13()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(73,74)));
    int h = getRandInt(1,3);
    root->setDesc(str(142));
    bj_common1_alt(h);
    bj_common2_alt2();
    bj_common3_alt2(h);
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        makeActBtn("sex_cumface4",act(7));
}
void HantersLoveSex::bj14()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(75,77)));
    int h = getRandInt(1,3);
    root->setDesc(str(141));
    bj_common1_alt(h);
    bj_common2_alt2();
    bj_common3_alt2(h);
    if(h == 3 && root->gVEvent(hanters_bj_times) >= 3)
        makeActBtn("sex_cumface5",act(7));
}
void HantersLoveSex::bj200()
{
    root->rendVideoPage();
    root->incTime(5);
    setVideo(media(getRandInt(25,30)));
    root->setDesc(str(44));
    if(root->vSC(blowJob) >= 10 && root->vSC(blowJob) < 15) makeActBtn("bj1",act(11));
    if(root->vSC(blowJob) >= 20) makeActBtn("bj2",act(10));
    if(root->vSC(blowJob) >= 5 && root->vSC(blowJob) < 10) makeActBtn("bj3",act(12));
    if(root->vSC(blowJob) < 5) makeActBtn("bj4",act(13));
    if(root->vSC(blowJob) >= 15 && root->vSC(blowJob) < 20) makeActBtn("bj5",act(29));
}
void HantersLoveSex::bj_bonus1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(78));
    root->setDesc(str(0));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(1));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(2));
    makeActBtn("bj1",act(0));
}
void HantersLoveSex::bj_bonus2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(79));
    root->setDesc(str(13));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(14));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(15));
    root->addDesc(str(16));
    makeActBtn("bj2",act(0));
}
void HantersLoveSex::bj_bonus3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(80));
    root->setDesc(str(172));
    makeActBtn("bj3",act(0));
}
void HantersLoveSex::bj_bonus4()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,-1);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(81));
    root->setDesc(str(24));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(25));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(26));
    makeActBtn("bj4",act(0));
}
void HantersLoveSex::bj_bonus5()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    root->uVSex(lubonus,getRandInt(1,3));
    setVideo(media(82));
    root->setDesc(str(167));
    makeActBtn("bj5",act(0));
}
void HantersLoveSex::bj_bonus6()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,1);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(83));
    root->setDesc(str(29));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(30));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(31));
    makeActBtn("bj6",act(0));
}
void HantersLoveSex::bj_bonus7()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(84));
    root->setDesc(str(163));
    makeActBtn("bj7",act(0));
}
void HantersLoveSex::bj_bonus8()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,1);
    if(root->vSex(harakBoy) > 0) root->uVEvent(hanters_bj_times,-1);
    if(root->vSex(harakBoy) == 0) root->uVEvent(hanters_bj_times,1);
    setVideo(media(85));
    root->setDesc(str(157));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(158));
    if(root->vSex(harakBoy) == 1) root->addDesc(str(159));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(160));
    makeActBtn("bj8",act(0));
}
void HantersLoveSex::bj_bonus11()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    setVideo(media(86));
    root->setDesc(str(150));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(151));
    if(root->vSex(harakBoy) == 1) root->addDesc(str(152));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(153));
    makeActBtn("bj11",act(0));
}
void HantersLoveSex::bj_bonus12()
{
    root->rendVideoPage();
    root->incTime(5);
    if(root->vSex(dick) > root->vBody(throat))
        root->uVBody(throat,1);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(87));
    root->setDesc(str(39));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(40));
    if(root->vSex(harakBoy) == 1) root->addDesc(str(148));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(41));
    makeActBtn("bj12",act(0));
}

void HantersLoveSex::bj_bonusH1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(78));
    root->setDesc(str(0));
    if(root->vSex(harakBoy) == 2)
        root->addDesc(str(1));
    if(root->vSex(harakBoy) < 2)
        root->addDesc(str(2));
    makeActBtn("bjH1",act(0));
}
void HantersLoveSex::bj_bonusH2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(79));
    root->setDesc(str(13));
    if(root->vSex(harakBoy) == 2)
        root->addDesc(str(14));
    if(root->vSex(harakBoy) < 2)
        root->addDesc(str(15));
    root->addDesc(str(16));
    makeActBtn("bjH2",act(0));
}
void HantersLoveSex::bj_bonusH3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(80));
    root->setDesc(str(21));
    makeActBtn("bjH3",act(0));
}
void HantersLoveSex::bj_bonusH4()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(81));
    root->setDesc(str(24));
    if(root->vSex(harakBoy) == 2)
        root->addDesc(str(25));
    if(root->vSex(harakBoy) < 2)
        root->addDesc(str(26));
    makeActBtn("bjH4",act(0));
}
void HantersLoveSex::bj_bonusH6()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(83));
    root->setDesc(str(29));
    if(root->vSex(harakBoy) == 2)
        root->addDesc(str(30));
    if(root->vSex(harakBoy) < 2)
        root->addDesc(str(31));
    makeActBtn("bjH6",act(0));
}
void HantersLoveSex::bj_bonusH7()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(86));
    root->setDesc(str(36));
    makeActBtn("bjH7",act(0));
}
void HantersLoveSex::bj_bonusH8()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVBody(throat,1);
    root->uVEvent(hanters_bj_times,-1);
    setVideo(media(87));
    root->setDesc(str(39));
    if(root->vSex(harakBoy) == 2)
        root->addDesc(str(40));
    if(root->vSex(harakBoy) < 2)
        root->addDesc(str(41));
    makeActBtn("bjH8",act(0));
}

void HantersLoveSex::bjH1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(31,34)));
    if(root->vBody(piercingA) == 0)
        root->setDesc(str(3));
    if(root->vBody(piercingA) > 0)
        root->setDesc(str(4));
    root->addDesc(str(5));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(6));
    bj_common();
}
void HantersLoveSex::bjH2()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(35,41)));
    if(root->vBody(piercingA) == 0)
        root->addDesc(str(17));
    if(root->vBody(piercingA) > 0)
        root->addDesc(str(18));
    root->addDesc(str(19));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(20));
    bj_common();
}
void HantersLoveSex::bjH3()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(42,43)));
    root->addDesc(str(22));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(23));
    bj_common();
}
void HantersLoveSex::bjH4()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(44,45)));
    root->setDesc(str(27));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(28));

    int h = getRandInt(1,3);
    bj_common1(h);
    bj_common2_alt();
    bj_common3_alt(h);
    bj_common4(h);
}
void HantersLoveSex::bjH6()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(50,51)));
    root->addDesc(str(32));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(33));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(34));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(35));
    int h = getRandInt(1,3);
    bj_common1(h);
    bj_common2();
    bj_common3(h);
    bj_common4_alt(h);
}
void HantersLoveSex::bjH7()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(65,69)));
    root->addDesc(str(37));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(38));
    bj_common();
}
void HantersLoveSex::bjH8()
{
    root->incTime(5);
    root->uVEvent(hanters_bj_times,1);
    root->uVSex(bj_temp,1);
    setVideo(media(getRandInt(70,72)));
    root->addDesc(str(42));
    if(root->gVEvent(hanters_bj_times) < 3)
        root->addDesc(str(43));
    bj_common();
}

void HantersLoveSex::sex_common1(int i, int j, int h)
{
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_cow",act(4));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_bell",act(6));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_dog_anal",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_cow",act(4));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_bell",act(6));
}
void HantersLoveSex::sex_common2(int i, int j, int h)
{
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_cow",act(4));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_hand",act(22));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_bell_anal",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_cow",act(4));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_hand",act(22));
}
void HantersLoveSex::sex_common3(int i, int j, int h)
{
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_hand",act(22));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_cow_anal",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_hand",act(22));
}
void HantersLoveSex::sex_common4(int i, int j, int h)
{
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_cow",act(4));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_misionary",act(20));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_hand",act(22));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_dog_anal",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_cow",act(4));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_hand",act(22));
}
void HantersLoveSex::sex_common5(int i, int j, int h)
{
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_cow",act(4));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_hand",act(22));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_misionary_anal",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_dog",act(5));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_cow",act(4));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_hand",act(22));
}

void HantersLoveSex::sex_69()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(horny,getRandInt(10,20));
    root->uVSex(bj_temp,1);
    root->uVSex(kuni_temp,1);
    setVideo(media(getRandInt(139,141)));
    root->setDesc(str(84));
    if(root->vStatus(horny) >= 90)
    {
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
        root->uVSC(orgasm,1);
        root->addDesc(str(85));
    }
    else
        root->addDesc(str(86));
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common1(i,j,h);
    if(h == 3) makeActBtn("sex_cumface7",act(7));
}

void HantersLoveSex::sex_bell()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(sex_temp,1);
    root->sVSex(pose,1);
    setVideo(media(getRandInt(129,134)));
    root->setDesc(str(94));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h,g;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    g = getRandInt(1,2);
    if(g == 1 && h < 3 && root->vSC(vaginalSex) > 10) root->addDesc(str(95));
    if(g == 2 && h < 3 && root->vSC(vaginalSex) > 20) root->addDesc(str(96));
    sex_common2(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum5",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum9",act(7));
}
void HantersLoveSex::sex_bell_anal()
{
    root->rendVideoPage();
    root->incTime(10);
    root->uVSex(anal_temp,1);
    setVideo(media(146));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum5",act(7));
}
void HantersLoveSex::sex_bell_analH()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(anal_temp,1);
    setVideo(media(146));
    root->setDesc(str(45));
    root->analStart(tDick);
    root->anal(tDick);
    int i = getRandInt(1,2);
    int j = getRandInt(1,3);
    int h = getRandInt(1,2);
    if(h == 1) root->addDesc(str(46));
    if(h == 2) root->addDesc(str(47));
    if(h == 1 && i == 1) makeActBtn("sex_cum1",act(7));
    if(h == 1 && i == 2) makeActBtn("sex_cum5",act(7));
    if(h == 2 && j == 1) makeActBtn("sex_missionary_analH",act(3));
    if(h == 2 && j == 2) makeActBtn("sex_cow_analH",act(4));
    if(h == 2 && j == 3) makeActBtn("sex_dog_analH",act(5));
}
void HantersLoveSex::sex_bell_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,1);
    setVideo(media(175));
    root->setDesc(str(93));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common2(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum5",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum9",act(7));
}
void HantersLoveSex::sex_bell_bonus1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,1);
    setVideo(media(165));
    root->setDesc(str(90));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(91));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(92));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common2(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum5",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum9",act(7));
}

void HantersLoveSex::sex_cow()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(getRandInt(123,124)));
    root->setDesc(str(106));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h,g;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    g = getRandInt(1,2);
    if(g == 1 && h < 3 && root->vSC(vaginalSex) > 20) root->addDesc(str(107));
    if(g == 2 && h < 3 && root->vSC(vaginalSex) > 10) root->addDesc(str(108));
    sex_common3(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum4",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum8",act(7));
}
void HantersLoveSex::sex_cow_anal()
{
    root->rendVideoPage();
    root->incTime(10);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(149,150)));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum4",act(7));
}
void HantersLoveSex::sex_cow_anal1()
{
    root->rendVideoPage();
    root->incTime(10);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(147,148)));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum4",act(7));
}
void HantersLoveSex::sex_cow_anal2()
{
    root->rendVideoPage();
    root->incTime(10);
    root->uVSex(anal_temp,1);
    setVideo(media(151));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum4",act(7));
}
void HantersLoveSex::sex_cow_analH()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(147,151)));
    root->setDesc(str(48));
    root->analStart(tDick);
    root->anal(tDick);
    int i = getRandInt(1,2);
    int j = getRandInt(1,3);
    int h = getRandInt(1,2);
    if(h == 1) root->addDesc(str(46));
    if(h == 2) root->addDesc(str(47));
    if(h == 1 && i == 1) makeActBtn("sex_cum1",act(7));
    if(h == 1 && i == 2) makeActBtn("sex_cum4",act(7));
    if(h == 2 && j == 1) makeActBtn("sex_missionary_analH",act(3));
    if(h == 2 && j == 2) makeActBtn("sex_dog_analH",act(5));
    if(h == 2 && j == 3) makeActBtn("sex_bell_analH",act(6));
}
void HantersLoveSex::sex_cow_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(getRandInt(169,171)));
    root->setDesc(str(104));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(root->vSC(vaginalSex) > 30) root->addDesc(str(105));
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common3(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum4",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum8",act(7));
}
void HantersLoveSex::sex_cow_bonus1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(getRandInt(172,174)));
    root->setDesc(str(101));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(102));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(103));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);

    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(h < 3 && j < 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(h < 3 && j < 3 && i == 4) makeActBtn("sex_hand",act(22));
    if(root->vSex(anal_no) == 0 && h < 3 && j == 3) makeActBtn("sex_cow_anal2",act(21));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 1) makeActBtn("sex_misionary",act(20));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 2) makeActBtn("sex_dog",act(5));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 3) makeActBtn("sex_bell",act(6));
    if(root->vSex(anal_no) == 1 && h < 3 && j == 3 && i == 4) makeActBtn("sex_hand",act(22));

    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum41",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum81",act(7));
}
void HantersLoveSex::sex_cow_bonus2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(137));
    root->setDesc(str(98));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(99));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(100));
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common3(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum4",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum8",act(7));
}
void HantersLoveSex::sex_cow_bonus3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(138));
    root->setDesc(str(97));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common3(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum4",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum8",act(7));
}

void HantersLoveSex::sex_dog()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,1);
    setVideo(media(getRandInt(119,122)));
    root->setDesc(str(115));
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h,g;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    g = getRandInt(1,2);
    if(g == 1 && h < 3 && root->vSC(vaginalSex) > 20) root->addDesc(str(116));
    if(g == 1 && h < 3 && root->vSC(vaginalSex) <= 20) root->addDesc(str(117));
    if(g == 2 && h < 3 && root->vSC(vaginalSex) > 20) root->addDesc(str(118));
    sex_common4(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum3",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum7",act(7));
}
void HantersLoveSex::sex_dog_anal()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(144,145)));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum3",act(7));
}
void HantersLoveSex::sex_dog_analH()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(144,145)));
    root->setDesc(str(49));
    root->analStart(tDick);
    root->anal(tDick);
    int i = getRandInt(1,2);
    int j = getRandInt(1,3);
    int h = getRandInt(1,2);
    if(h == 1) root->addDesc(str(46));
    if(h == 2) root->addDesc(str(47));
    if(h == 1 && i == 1) makeActBtn("sex_cum1",act(7));
    if(h == 1 && i == 2) makeActBtn("sex_cum3",act(7));
    if(h == 2 && j == 1) makeActBtn("sex_missionary_analH",act(3));
    if(h == 2 && j == 2) makeActBtn("sex_cow_analH",act(4));
    if(h == 2 && j == 3) makeActBtn("sex_bell_analH",act(6));
}
void HantersLoveSex::sex_dog_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,1);
    root->sVSex(pose,1);
    setVideo(media(getRandInt(166,168)));
    root->setDesc(str(109));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(110));
    if(root->vSex(harakBoy) == 1) root->addDesc(str(111));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(112));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common4(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum3",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum7",act(7));
}
void HantersLoveSex::sex_dog_bonus1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,1);
    setVideo(media(getRandInt(162,164)));
    root->setDesc(str(113));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common4(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum3",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum7",act(7));
}
void HantersLoveSex::sex_dog_bonus2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,1);
    setVideo(media(getRandInt(176,177)));
    root->setDesc(str(114));
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common4(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum3",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum7",act(7));
}

void HantersLoveSex::sex_kuni()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,1);
    if(root->vSex(hanters_kuni) == 0)
    {
        setVideo(media(88));
        if(root->vSkill(domination) <= 50)
        {
            root->addDesc(str(129));
            if(root->vSex(harakBoy) == 2) root->addDesc(str(130));
            if(root->vSex(harakBoy) == 0) root->addDesc(str(131));
            makeActBtn("sex_misionary",act(0));
        }
        else
        {
            if(root->vSex(harakBoy) == 2) root->addDesc(str(132));
            if(root->vSex(harakBoy) == 1) root->addDesc(str(133));
            if(root->vSex(harakBoy) == 0) root->addDesc(str(134));
            makeActBtn("start_kuni",act(23));
        }
    }
    else
    {
        root->uVSC(getKuni,1);
        root->uVSex(kuni_temp,1);
        setVideo(media(getRandInt(125,128)));
        root->setDesc(str(135));
        if(root->vStatus(horny) >= 90)
        {
            root->sVStatus(lust,0);
            root->sVStatus(horny,0);
            root->uVStatus(mood,15);
            root->uVSC(orgasm,1);
            root->addDesc(str(85));
        }
        else
            root->addDesc(str(86));
        if(root->vSkill(domination) >= 75)
            root->addDesc(str(136));
        int i = getRandInt(1,5);
        if(i == 1) makeActBtn("sex_misionary",act(0));
        if(i == 2) makeActBtn("sex_cow",act(0));
        if(i == 3) makeActBtn("sex_dog",act(0));
        if(i == 4) makeActBtn("sex_bell",act(0));
        if(i == 5) makeActBtn("sex_hand",act(0));
    }
}
void HantersLoveSex::sex_kuni_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    if(root->vSex(silavag) == 0) root->uVStatus(horny,15);
    if(root->vSex(silavag) == 1) root->uVStatus(horny,20);
    if(root->vSex(silavag) == 2) root->sVStatus(horny,25);
    setVideo(media(getRandInt(178,179)));
    if(root->vSex(harakBoy) == 2) root->setDesc(str(123));
    root->setDesc(str(124));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(125));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(126));
    if(root->vStatus(horny) >= 90)
    {
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
        root->uVSC(orgasm,1);
        root->addDesc(str(85));
    }
    else
        root->addDesc(str(86));
    root->addDesc(str(127));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(128));
    int i = getRandInt(1,5);
    if(i == 1) makeActBtn("sex_misionary",act(0));
    if(i == 2) makeActBtn("sex_cow",act(0));
    if(i == 3) makeActBtn("sex_dog",act(0));
    if(i == 4) makeActBtn("sex_bell",act(0));
    if(i == 5) makeActBtn("sex_hand",act(0));
}

void HantersLoveSex::sex_misionary()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(sex_temp,1);
    root->sVSex(pose,0);
    setVideo(media(getRandInt(115,118)));
    root->setDesc(str(137));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h,g;
    i = getRandInt(1,9);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    g = getRandInt(1,2);
    if(g == 1 && h < 3 && root->vSC(vaginalSex) > 30) root->addDesc(str(138));
    if(g == 2 && h < 3) root->addDesc(str(139));
    if(root->vSex(hanters_kuni) == 0 && root->vSkill(domination) > 30 && h < 3)
        root->addDesc(str(140));
    if(h < 3) root->addDesc(str(47));
    if(h == 3) root->addDesc(str(46));
    if(h < 3 && j < 3 && root->vSex(hanters_kuni) == 0 && (i == 8 || i == 1 || i == 2))
        makeActBtn("sex_cow",act(4));
    if(h < 3 && j < 3 && root->vSex(hanters_kuni) == 0 && (i == 9 || i == 3 || i == 4))
        makeActBtn("sex_dog",act(5));
    if(h < 3 && j < 3 && (i == 5 || i == 6))
        makeActBtn("sex_bell",act(6));
    if(h < 3 && j < 3 && i == 7)
        makeActBtn("sex_hand",act(22));
    if(h < 3 && j < 3 && root->vSex(hanters_kuni) == 1 && i == 8)
        makeActBtn("sex_kuni",act(23));
    if(h < 3 && j == 3 && root->vSex(hanters_kuni) == 1 && i == 9)
        makeActBtn("sex_69",act(24));
    if(h < 3 && j == 3)
        makeActBtn("sex_misionary_anal",act(21));
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum2",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum6",act(7));

}
void HantersLoveSex::sex_misionary_anal()
{
    root->rendVideoPage();
    root->incTime(10);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(142,143)));
    root->setDesc(str(83));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(46));
    int i = getRandInt(1,2);
    if(i == 1) makeActBtn("sex_cum1",act(7));
    if(i == 2) makeActBtn("sex_cum2",act(7));
}
void HantersLoveSex::sex_misionary_analH()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(anal_temp,1);
    setVideo(media(getRandInt(142,143)));
    root->setDesc(str(50));
    root->analStart(tDick);
    root->anal(tDick);
    int i = getRandInt(1,2);
    int j = getRandInt(1,3);
    int h = getRandInt(1,2);
    if(h == 1) root->addDesc(str(46));
    if(h == 2) root->addDesc(str(47));
    if(h == 1 && i == 1) makeActBtn("sex_cum1",act(7));
    if(h == 1 && i == 2) makeActBtn("sex_cum2",act(7));
    if(h == 2 && j == 1) makeActBtn("sex_cow_analH",act(4));
    if(h == 2 && j == 2) makeActBtn("sex_dog_analH",act(5));
    if(h == 2 && j == 3) makeActBtn("sex_bell_analH",act(6));

}
void HantersLoveSex::sex_misionary_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(domination,1);
    root->sVSex(pose,0);
    setVideo(media(getRandInt(155,158)));
    root->setDesc(str(120));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    if(root->vSkill(agility) > 60 && root->vSkill(domination) > 30 && root->vBody(bodyGroup) < 2)
        root->addDesc(str(121));
    sex_common5(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum2",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum6",act(7));

}
void HantersLoveSex::sex_misionary_bonus1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSkill(agility,1);
    root->uVSkill(domination,1);
    root->sVSex(pose,0);
    setVideo(media(159));
    root->setDesc(str(120));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common5(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum2",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum6",act(7));
}
void HantersLoveSex::sex_misionary_bonus2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,0);
    setVideo(media(getRandInt(160,161)));
    root->setDesc(str(119));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common5(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum2",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum6",act(7));
}

void HantersLoveSex::sex_hand()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVSex(sex_temp,1);
    root->sVSex(pose,2);
    setVideo(media(135));
    root->setDesc(str(88));
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    if(h < 3) root->addDesc(str(89));
    sex_common1(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum10",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum11",act(7));
}
void HantersLoveSex::sex_hand_bonus()
{
    root->rendVideoPage();
    root->incTime(5);
    root->sVSex(pose,2);
    setVideo(media(136));
    root->setDesc(str(87));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    int i,j,h;
    i = getRandInt(1,4);
    j = getRandInt(1,3);
    h = getRandInt(1,3);
    sex_common1(i,j,h);
    int k = getRandInt(1,2);
    if(k == 1 && h == 3) makeActBtn("sex_cum10",act(7));
    if(k == 2 && h == 3) makeActBtn("sex_cum11",act(7));
}

void HantersLoveSex::sex_cum_common()
{
    if(root->vSex(silavag) == 0 && root->vSex(dikos) == 0) root->addDesc(str(53));
    if(root->vSex(silavag) == 1 && root->vSex(dikos) == 1) root->addDesc(str(54));
    if(root->vSex(silavag) == 2 && root->vSex(dikos) == 2) root->addDesc(str(55));
    if(root->vSex(silavag) == 1 && root->vSex(dikos) < 1 && root->vStatus(horny) >= 60 && root->vBody(vagina) > 0)
        makeActBtn("want_more1.0",act(14));
    if(root->vSex(silavag) == 2 && root->vSex(dikos) < 2 && root->vStatus(horny) >= 60 && root->vBody(vagina) > 0)
        makeActBtn("want_more2.0",act(14));
    makeActBtn("exit_sex",act(15));
}
void HantersLoveSex::sex_cum1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("anus");
    setVideo(media(2));
    root->setDesc(str(82));
    sex_cum_common();
}
void HantersLoveSex::sex_cum2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("belly");
    setVideo(media(3));
    root->setDesc(str(80));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(81));
    sex_cum_common();
}
void HantersLoveSex::sex_cum3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("ass");
    setVideo(media(4));
    root->setDesc(str(77));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(78));
    if(root->vSex(harakBoy) == 0) root->addDesc(str(79));
    sex_cum_common();
}
void HantersLoveSex::sex_cum4()
{
    root->rendImagePage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("ass");
    root->setImage(media(5));
    root->setDesc(str(75));
    sex_cum_common();
}
void HantersLoveSex::sex_cum41()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("belly");
    setVideo(media(11));
    root->setDesc(str(76));
    sex_cum_common();
}
void HantersLoveSex::sex_cum5()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("ass");
    setVideo(media(6));
    root->setDesc(str(75));
    sex_cum_common();
}
void HantersLoveSex::sex_cum6()
{
    root->rendImagePage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->setImage(media(12));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->setImage(media(7));
        root->setDesc(str(73));
        root->cum("pussy");
        sex_cum_common();
    }
}
void HantersLoveSex::sex_cum7()
{
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->rendImagePage();
        root->setImage(media(13));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->rendVideoPage();
        setVideo(media(8));
        root->setDesc(str(73));
        root->cum("pussy");
        sex_cum_common();
    }
}
void HantersLoveSex::sex_cum8()
{
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->rendImagePage();
        root->setImage(media(14));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->rendVideoPage();
        setVideo(media(9));
        root->setDesc(str(73));
        root->cum("pussy");
        sex_cum_common();
    }
}
void HantersLoveSex::sex_cum81()
{
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->rendImagePage();
        root->setImage(media(16));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->rendVideoPage();
        setVideo(media(15));
        root->setDesc(str(73));
        root->cum("pussy");
        sex_cum_common();
    }
}
void HantersLoveSex::sex_cum9()
{
    root->rendImagePage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->setImage(media(17));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->setImage(media(10));
        root->setDesc(str(73));
        sex_cum_common();
    }
}
void HantersLoveSex::sex_cum10()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("belly");
    setVideo(media(0));
    root->setDesc(str(74));
    sex_cum_common();
}
void HantersLoveSex::sex_cum11()
{
    root->rendImagePage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    if(root->vSex(protect) == 1)
    {
        root->setImage(media(12));
        root->setDesc(str(72));
        sex_cum_common();
    }
    else
    {
        root->setImage(media(1));
        root->setDesc(str(73));
        root->cum("pussy");
        sex_cum_common();
    }
}

void HantersLoveSex::sex_cumface1()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("face");
    setVideo(media(18));
    root->setDesc(str(70));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(71));
    sex_cum_common();
}
void HantersLoveSex::sex_cumface2()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("lip");
    setVideo(media(19));
    root->setDesc(str(51));
    makeActBtn("swallow",act(18));
    makeActBtn("spit_it_out",act(19));
}
void HantersLoveSex::sex_cumface3()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    root->uVSC(handJob,1);
    resetCounters();
    setVideo(media(20));
    root->setDesc(str(64));
    if(root->vSex(harakBoy) > 0) root->addDesc(str(65));
    sex_cum_common();
}
void HantersLoveSex::sex_cumface4()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("belly");
    setVideo(media(21));
    root->setDesc(str(62));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(63));
    sex_cum_common();
}
void HantersLoveSex::sex_cumface5()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("face");
    setVideo(media(22));
    root->setDesc(str(60));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(61));
    sex_cum_common();
}
void HantersLoveSex::sex_cumface6()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    root->cum("lip");
    root->uVSC(swallow,1);
    resetCounters();
    setVideo(media(23));
    root->setDesc(str(58));
    if(root->vSex(harakBoy) == 2) root->addDesc(str(59));
    sex_cum_common();
}
void HantersLoveSex::sex_cumface7()
{
    root->rendVideoPage();
    root->incTime(5);
    root->uVStatus(sweat,1);
    resetCounters();
    root->cum("lip");
    root->cum("face");
    setVideo(media(24));
    root->setDesc(str(51));
    if(root->vSex(harakBoy) < 2) root->addDesc(str(52));
    sex_cum_common();
}

void HantersLoveSex::sub()
{
    root->rendImagePage();
    root->incTime(5);
    root->setImage(media(180));
    root->setDesc(str(176));
    int i = getRandInt(1,8);
    if(i == 1 || i == 7) makeActBtn("bj200",act(9));
    if(i == 2 || i == 8) makeActBtn("sex_misionary",act(3));
    if(i == 3) makeActBtn("sex_cow",act(4));
    if(i == 4) makeActBtn("sex_dog",act(5));
    if(i == 5) makeActBtn("sex_bell",act(6));
    if(i == 6) makeActBtn("sex_hand",act(22));
}

void HantersLoveSex::resetCounters()
{
    if(root->vSex(sex_temp) > 0)
    {
        root->sVSex(sex_temp,0);
        root->uVSC(vaginalSex,1);
    }
    if(root->vSex(bj_temp) > 0)
    {
        root->sVSex(bj_temp,0);
        root->uVSC(blowJob,1);
    }
    if(root->vSex(hj_temp) > 0)
    {
        root->sVSex(hj_temp,0);
        root->uVSC(handJob,1);
    }
    if(root->vSex(kuni_temp) > 0)
    {
        root->sVSex(kuni_temp,0);
        root->uVSC(getKuni,1);
    }
    if(root->vSex(anal_temp) > 0)
    {
        root->sVSex(anal_temp,0);
        root->uVSC(analSex,1);
    }
}

void HantersLoveSex::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"HantersLoveSex");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &HantersLoveSex::actionHandler);
    root->addActBtn(btn);
}

QString HantersLoveSex::str(int id)
{
    QString str[205];
    if(id < 20)
    {
        str[0] = "Вы засунули кончик языка в маленькую дырочку головки члена.";
        str[1] = root->getBoyName() + " от этого аж вздрогнул: <npc>- Светик, что ты делаешь, перестань, я ща кончу бля от этого.</npc>";
        str[2] = root->getBoyName() + " от этого аж вздрогнул: <npc>- Светик, что ты делаешь, перестань, так же и кончить сразу можно.</npc>";
        str[3] = "Вы лижете язычком головку";
        str[4] = "Вы лижете язычком головку чувствуя как штанга в вашем языке шевелится от ударов об член";
        str[5] = "Нежно и быстро щекочете кончиком языка самую вершину головки, ее отверстие.";
        str[6] = "<a href=\"bj_bonusH1\">Засунуть</a> кончик языка в дырочку.";
        str[7] = "Вдоволь насладившись вашими оральными ласками, парень просит вас...";
        str[8] = "Вы можете прекратить минет и <a href=\"sex_misionary_analH\">лечь на спину</a>.";
        str[9] = "Вы можете прекратить минет и <a href=\"sex_cow_analH\">запрыгнуть на парня</a>.";
        str[10] = "Вы можете прекратить минет и <a href=\"sex_dog_analH\">нагнуться</a>.";
        str[11] = "Вы можете прекратить минет и <a href=\"sex_bell_analH\">лечь на живот</a>.";
        str[12] = "Внезапно член парня еще сильнее налился кровью и начал пульсировать, и вы поняли, что он уже на грани и готов...";
        str[13] = "Решивишсь слегка укусить его, вы нежно прикусываете головку своими белыми зубами.";
        str[14] = "<npc>- Эй, бля, Светик, ты че, мой член с бананом перепутала? Не шути так больше.</npc>";
        str[15] = "<npc>- Осторожно, Светик, не шути так больше.</npc>";
        str[16] = "Вы с улыбкой посмотрели на него и решили...";
        str[17] = "Вы причмокивая сосете головку, и плотно его сжимаете своими " + root->getLipTalk() + " ";
        str[18] = "Вы причмокивая сосете головку чувствуя как штанга в вашем языке шевелится от ударов о член, и плотно его сжимаете своими " + root->getLipTalk() + " ";
        str[19] = "Нежность ваших губ сводит парня с ума";
    }
    if(id >= 20 && id < 40)
    {
        str[20] = "Попробовать слегка <a href=\"bj_bonusH2\">укусить</a> красную головку члена";
        str[21] = "Смотря в глаза своего парня, вы дразните язычком одну из самых эрогенных зон члена.<br>"
                  "<npc>- Класс, Светик, знаешь как меня завести еще сильнее.";
        str[22] = "Вы покрываете член сладкими поцелуями, нежно его касаясь своими " + root->getLipTalk();
        str[23] = "Можно слегка <a href=\"bj_bonusH3\">подразнить</a> тонкую уздечку члена";
        str[24] = "Взявшись за основание члена, вы выполняете просьбу парня, и шлепаете головкой по вашим щекам.";
        str[25] = "<npc>- О да, ты моя покорная сучка, так меня заводишь, давай продолжай милая.</npc>";
        str[26] = "<npc>- О да, ты так меня заводишь, давай продолжай милая.</npc>";
        str[27] = "Вы слегка обхватили член рукой и натянули кожу, оголяя сверкающую головку.";
        str[28] = root->getBoyName() + " просит вас <a href=\"bj_bonusH4\">шлепнуть</a> членом по вашей щечке.";
        str[29] = root->getBoyName() + " шлепает членом по вашему языку.";
        str[30] = "<npc>- Плохая девочка, ща папочка тебя накажет.</npc>";
        str[31] = "<npc>- А ты оказывается развратная девчока,</npc> - с улыбкой говорит он.";
        str[32] = "Захватив член в свои цепкие руки, вы начали его уверенно надрачивать, и наблюдаете за реакцией парня.";
        str[33] = "<npc>- Неплохо,Светик, но дрочить я и сам себе могу, ты там давай включай все свои женские инструменты.</npc>";
        str[34] = "<npc>- Давай, Светик, покажи, на что ты способна,</npc> - с улыбкой говорит " + root->getBoyName() + ", глядя вам в глаза.";
        str[35] = "Высунуть язык и <a href=\"bj_bonusH6\">шлепать</a> по нему горячей головкой.";
        str[36] = "Вы взяли и плотно прижали головку за щекой и " + root->getBoyName() + " начал грубо трахать вас в таком положении, расстягивая все лицо."
                  "<npc>- О да, детка, давай еще немного, твое личико так сексуально выглядит.</npc>";
        str[37] = "Вы хватаетесь за основание члена и начинаете жадно сосать. Член парня полностью не помещается в вашем маленьком ротике и входит лишь наполовину, вы сосете и нежно надрачиваете остальную часть.";
        str[38] = "Взять член <a href=\"bj_bonusH7\">за щеку</a> и плотно прижать головку.";
        str[39] = "Вы попытались взять член еще глубжe, но у вас ничего не получилось, и едва не вырвало прямо на парня.";
    }
    if(id >= 40 && id < 60)
    {
        str[40] = "<npc>- Фу бля, Светик, если не можешь нормально глотать, то лучше потренируйся дома на банане, а не на моем хую.</npc>";
        str[41] = "<npc>- Не расстраивайся Светик, может в следующий раз получится.</npc>";
        str[42] = "Вы начали сосать член не притрагиваясь к нему ручками, думая, что парню так вы доставите больше удовольствия."
                  "Член парня польностью не помещается в вашем рту, и вы причмокивая сосете лишь до половины.";
        str[43] = "Попробовать <a href=\"bj_bonusH8\">заглотить</a> член глубже.";
        str[44] = "Вы опустились на колени перед парнем. Он с интересом смотрит на вас, ожидая ваших действий. И вы принимаетесь...";
        str[45] = "Парень, положив вас на живот, принялся ласкать вашу попку.";
        str[46] = "Внезапно " + root->getBoyName() + " начал двигаться быстрее и вы поняли что он уже на грани и готов...";
        str[47] = "Вдоволь насладившись в этой позе, парень просит вас...";
        str[48] = "Парень лег на спину и потянул вас на верх.";
        str[49] = "Парень поставил вас на четвереньки и принялся ласкать вашу попку.";
        str[50] = "Парень положил вас на спину и принялся пристраиваться к вашей попке.";
        str[51] = "Вы чувствуете как член начинает пульсировать у вас во рту и в небо бьют потоки терпкой спермы.";
        str[52] = "<npc>- Прости Светик, не смог сдержаться от твоей сладкой киски.</npc>";
        str[53] = "<npc>- Всё Светик харэ. Я больше не могу.</npc>";
        str[54] = "<npc>- Всё Светик. Я больше не могу.</npc>";
        str[55] = "<npc>- Всё Светик, хватит. Я больше не могу.</npc>";
        str[56] = "Вы сказали парню, что ещё хотите.<br>На что " + root->getBoyName() + " ответил: <npc>- Пипец ты Светик ненасытная, я фигею.</npc>";
        str[57] = "Вы сказали парню, что ещё хотите.<br><npc>- Ну ты Светик и ненасытная,</npc> - улыбнулся в ответ вам " + root->getBoyName() + ".";
        str[58] = "Вы чувствуете как член начинает пульсировать у вас во рту и в небо бьют потоки терпкой спермы. Во рту совсем нет места и вы глотаете всю сперму.";
        str[59] = "<npc>- Ненасытная шлюшка, вот тебе чего не хватало сегодня.</npc>";
    }
    if(id >= 60 && id < 80)
    {
        str[60] = "Мощные струи ударили вам в подбородок, несколько капель попали в лицо, сперма медленно стекает вниз к груди.";
        str[61] = "<npc>- Светик, просто тащусь от твоих охуеннх сисек.</npc>";
        str[62] = root->getBoyName() + " кончил вам на грудь, горячие капельки стекают вниз к животу, вы размазываете липкую сперму по всему телу.";
        str[63] = "<npc>- Светик, говорят так сиськи растут. Будешь моей пышногрудой красавицей.</npc>";
        str[64] = "Твердый член начал пульсировать в объятиях вашей ладони и " + root->getBoyName() + " кончил вам в ладошки покрыв их горячей и липкой спермой.";
        str[65] = "<npc>- Детка, у тебя просто золотые ручки, одолжишь их на время?</npc>";
        str[66] = "С большим удовольствием проглотили все до единой капельки.";
        str[67] = "<npc>- Бля Светик, ты та еще вафлитска, рот не забудь помыть, я тебе еще иногда целовать хочу.</npc>";
        str[68] = "Вам не нравится этот вкус и вы быстро выплюнули эту омерзительную жидкость.";
        str[69] = "<npc>- Что, не вкусно Светик? Я то думал все бабы тащатся от спермы, жаль ты у меня не такая.</npc>";
        str[70] = "Брызги горячей спермы ударили вам по лицу, и капельки медленно стекают вниз.";
        str[71] = "<npc>- Охх, Светик, круто мы с тобой сегодня оторвались.</npc>";
        str[72] = root->getBoyName() + " застонал и вы поняли, что он кончил в презерватив. Ваш парень полностью расслабился, выбросил куда-то презик и удовлетворенно лег на кровать.";
        str[73] = root->getBoyName() + " застонал и вы почувствовали как струя спермы ударила вам внутрь вашего тела.";
        str[74] = root->getBoyName() + " вытащил член, застонал и вы почувствовали как горячие струйки спермы стреляют вам на живот и на сиськи, и медленно стекают вниз. Ваш парень полностью расслабился и удовлетворенно лег на кровать.";
        str[75] = root->getBoyName() + " вытащил член, застонал и вы почувствовали как горячие струйки спермы стреляют вам на попу и спину. Ваш парень полностью расслабился и удовлетворенно лежит на спине.";
        str[76] = root->getBoyName() + " вытащил член, застонал и вы почувствовали как горячие струйки спермы стреляют на животик, и медленно стекают вниз. Ваш парень полностью расслабился и удовлетворенно лежит на спине.";
        str[77] = root->getBoyName() + " вытащил член, застонал и вы почувствовали как горячие капли спермы падают на вашу попу и спину.";
        str[78] = "<npc>- Черт,Светик, в такой позе тебя ебать и ебать.</npc> Парень легонько шлепнул вас по попе.";
        str[79] = "<npc>- Светик, в такой позе ты выглидишь просто неотразимо.</npc> Парень нежно поцеловал вас в щечку.";
    }
    if(id >= 80 && id < 100)
    {
        str[80] = root->getBoyName() + " вытащил член, застонал и вы почувствовали как горячие капли спермы падают на ваш животик.";
        str[81] = "<npc>- Бля, было круто, Светик,</npc> - сказал " + root->getBoyName() + " и страстно поцеловал вас.";
        str[82] = " застонал и вы почувствовали как вашу попу наполняет тепло.<br>"
                  "<npc>- О да, крошка, ты просто супер.</npc> И после " + root->getBoyName() + " чмокнул вас в лоб.";
        str[83] = "К счастью вы успели подготовить попку к аналу. Парень вытащил член из вашей киски и принялся ласкать вашу попку.";
        str[84] = "Вы сели на лицо парня и схватившись за его член, стали страстно сосать."
                  "" + root->getBoyName() + " умело облизывал вашу киску, вы постанывая и тяжело дыша продолжали сосать.";
        str[85] = "От умелых действий парня вас охватил оргазм.";
        str[86] = "Действия парня хоть и были возбуждающие, но они начали вас утомлять.";
        str[87] = "Обвивая шею парня вы глубоко насаживаетесь на него, чувствуя как глубоко входит член.";
        str[88] = root->getBoyName() + " взял вас в свои крепкие руки и резко вошел в вас.";
        str[89] = "Начать <a href=\"sex_hand_bonus\">двигаться</a> парню навстречу.";
        str[90] = "Расслаблено лежа на животе, вы лениво крутите попкой. " + root->getBoyName() + " застывает и наслаждается происходящим.";
        str[91] = "<npc>- О да, моя кошечка, просто кайфую от твоей вкусной попки.<br>- Ухх, Светик, не останавливайся...</npc>";
        str[92] = "<npc>- Это супер, милая...</npc>";
        str[93] = "Вы страстно целуетесь, " + root->getBoyName() + " продолжает грубо таранить вас сзади.";
        str[94] = "Вы легли на живот и ваш парень пристроился сзади.";
        str[95] = "Поднять голову и <a href=\"sex_bell_bonus\">целоваться</a> с парнем.";
        str[96] = "Покрутить <a href=\"sex_bell_bonus1\">попкой</a> пока член внутри.";
        str[97] = "Вы горячо поцеловались, прижимаясь друг другу все сильнее.";
        str[98] = root->getBoyName() + " приподнялся и крепко и плотно прижал к себе. Вы приобняли его за шею, и двигаетесь и извиваете талию.";
        str[99] = "<npc>- Умм, какая горячая сучка, дай зацелую твои сисечки.</npc>";
    }
    if(id >= 100 && id < 120)
    {
        str[100] = "Прильнуть к его губам и <a href=\"sex_cow_bonus3\">целоваться</a>.";
        str[101] = "Вы повернулись спиной к парню и продолжили скользить на нем своей мокрой киской.";
        str[102] = "<npc>- Ухх, детка, твоя жопа так выглядит просто охуенно...</npc>";
        str[103] = "<npc>- Круто выглядишь, Светик.</npc>";
        str[104] = root->getBoyName() + " остановился, предоставляя вам всю инициативу. Вы начали ритмично двигаться и скакать.";
        str[105] = "Повернуться к нему <a href=\"sex_cow_bonus1\">спиной</a> и продолжить скакать на члене.";
        str[106] = root->getBoyName() + " взял вас за руку чуть помогая вам, и вы сели на него сверху.";
        str[107] = "Дать парню передохнуть и <a href=\"sex_cow_bonus\">прыгать</a> самой на крепком члене.";
        str[108] = "Попросить парня приподняться и <a href=\"sex_cow_bonus2\">обнять</a> вас.";
        str[109] = "Не послувшавшись парня, вы начали двигать попой навстречу горячему члену.";
        str[110] = root->getBoyName() + " чуть сбавил свои движения и сказал: <npc>- Отлично работаешь, жопастая сучка.</npc>";
        str[111] = root->getBoyName() + " чуть сбавил свои движения и сказал: <npc>- Круто Светик.</npc>";
        str[112] = root->getBoyName() + " чуть сбавил свои движения и сказал: <npc>- Ты умница просто,Светик.</npc>";
        str[113] = "Проигнорировав парня, вы лениво уткнулись лицом в мягкую постель.";
        str[114] = "Вы вместе встали на ноги, " + root->getBoyName() + " поддерживая вас продолжил яростно долбить вашу дырку.";
        str[115] = root->getBoyName() + " поставил вас раком и вы сексуально прогнули спинку оттопырили попку перед ним.";
        str[116] = "Начать движения <a href=\"sex_dog_bonus\">попой</a> ему навстречу.";
        str[117] = "Уткнуться <a href=\"sex_dog_bonus1\">лицом</a> в постель, продолжая трахаться в этой позе.";
        str[118] = "Попросить парня помочь вам <a href=\"sex_dog_bonus2\">приподняться</a> .";
        str[119] = "Вы страстно целуетесь, его ощущая жаркое дыхание. " + root->getBoyName() + " продолжает вас трахать во время поцелуя.";
    }
    if(id >= 120 && id < 140)
    {
        str[120] = "Не послувшавшись парня, вы достаточно ловко закинули ножки себе за голову, внутри все расстянулось и вы еще лучше почувствовали движение члена внутри."
                   "<npc>- Ох, детка, ничего себе ты исполняешь.</npc>";
        str[121] = "Не послувшавшись парня, вы подняли свои ножки вверх, приоткрывая невероятный вид вашей киски, и предоставляя парню еще больше свободы."
                   "" + root->getBoyName() + " продолжил яростно вас трахать в такой позе.";
        str[122] = "Закинуть ножки <a href=\"sex_misionary_bonus1\">за голову</a>.";
        str[123] = "<npc>- Что ты делаешь? О черт, Светик, только не это, и почему я разрешаю тебе такое дел....</npc>";
        str[124] = "Вы сели на парня, и третесь влажной киской об его лицо.";
        str[125] = "Ему это не сильно нравится, но он подолжает тщательно вам облизывать, вызывая у вас бурные чувства.";
        str[126] = "Судя по всему ему это даже нравится, и он подолжает тщательно вылизывать, вызывая у вас бурные чувства.";
        str[127] = "Насладившись сладким куни своего парня.<br>"
                   "<hero>- Все, " + root->getBoyName() + ", давай уже трахаться.</hero>";
        str[128] = "<npc>- Да бля, сама набросилась, как сумашедшая. Давай, а то член уже как каменный.</npc>";
        str[129] = root->getBoyName() + " отказался лизать вашу киску.";
        str[130] = "<npc>- Не Светик, отстань, не подобает нормальному мужику лизать пизду, лучше раздвинь ножки.</npc>";
        str[131] = "<npc>- Может в другой раз, милая</npc>";
        str[132] = root->getBoyName() + " нехотя согласился полизать вам."
                   "<npc>- Ладно, Светик, только никому не говори, а то потеряю всякое уважение.</npc>";
        str[133] = root->getBoyName() + " согласился полизать вам.";
        str[134] = root->getBoyName() + " с радостью согласился полизать вам.<br><npc>- Светик, я доставлю тебе неземное наслождение.</npc>";
        str[135] = root->getBoyName() + " лег между ваших ног и начал работать язычком по вашей киске.";
        str[136] = "Уложить парня на спину и <a href=\"sex_kuni_bonus\">сесть</a> на его лицо своей киской.";
        str[137] = root->getBoyName() + " уложил вас на спину и раздвинул ваши ножки.";
        str[138] = "Вы наслаждаетесь каждым его движением, и хотите поднять ножки <a href=\"sex_misionary_bonus\">вверх</a> .";
        str[139] = "Вы громко стонете под своим парнем, <a href=\"sex_misionary_bonus2\">поцеловать</a> парня.";
    }
    if(id >= 140 && id < 160)
    {
        str[140] = "Попросить парня <a href=\"sex_kuni\">полизать</a> вам киску.";
        str[141] = " вставил свой член между ваших сисек " + intQStr(root->vBody(breastsSize)) + "го размера и вы, плюнув и немного смазав член,"
                   " сжали сиськи вместе. И ваш парень начал двигаться, жестко трахая ваши сиськи. Вы испытываете необычные, но приятные ощущения от этих действий.";
        str[142] = "Крепко взявшись за член, вы проводите головкой по своим твердым чувствительным сосочкам. И парню и вам такой массаж доставляет массу эмоций.";
        str[143] = "Вы можете прекратить минет и <a href=\"sex_misionary\">лечь на спину</a>.";
        str[144] = "Вы можете прекратить минет и <a href=\"sex_cow\">запрыгнуть на парня</a>.";
        str[145] = "Вы можете прекратить минет и <a href=\"sex_dog\">нагнуться</a>.";
        str[146] = "Вы можете прекратить минет и <a href=\"sex_bell\">лечь на живот</a>.";
        str[147] = "Вы можете прекратить минет и <a href=\"sex_hand\">запрыгнуть на руки</a>.";
        str[148] = "<npc>- Не расстраивайся Светик, тяжело в учении, легко в бою.</npc>";
        str[149] = "Попробовать <a href=\"bj_bonus12\">заглотить</a> член глубже.";
        str[150] = "Вы взяли и плотно прижали головку за щекой и " + root->getBoyName() + " начал трахать вас в таком положении, расстягивая все лицо.";
        str[151] = "<npc>- О да, детка, давай еще немного, твое личико так сексуально выглядит.</npc>";
        str[152] = "<npc>- О да, Светик, давай еще немного, это круто.</npc>";
        str[153] = "<npc>- Милая, это супер, твое личико так сексуально выглядит.</npc>";
        str[154] = "Взять член <a href=\"bj_bonus11\">за щеку</a> и плотно прижать головку.";
        str[155] = "Вы подчинились парню и полностью расслабили горло. " + root->getBoyName() + " начал двигать членом, погружаясь все глубже. Вы едва задыхаетесь но сдерживаете"
                   " себя от рвотного порыва. Чувствуете как головка упирается и едва входит вам в горло и при этом делаете глотательные движения, сжимая головку внутри.";
        str[156] = "Вы начали ритмичные движения головой и глотаете член все глубже и глубже. Чувствуете как головка упирается и едва входит вам в горло и при этом делаете"
                   " глотательные движения, сжимая головку внутри.";
        str[157] = "Пока " + root->getBoyName() + " продолжал наслаждаться, вы засунули кончик языка внутрь, и парень вздрогнул от неожиданности";
        str[158] = "<npc>- Решила трахнуть меня в жопу своим языком? Не, Светик, мне такое не по душе, прекрати нахуй это дело</npc>";
        str[159] = "<npc>- Лучше не нужно Светик , прекрати.</npc>";
    }
    if(id >= 160 && id < 180)
    {
        str[160] = "<npc>- Кайф Светик, не останавливайся,</npc> - попросил " + root->getBoyName() + ".";
        str[161] = "Вы спустились еще ниже, проведя языком ниже яичек, достигли ануса парня и начали ритмично дразнить кончиком языка."
                   "<npc>- Ой бля,Светик, что ты делаешь? Хотя охуенно, но только пацанам про это не рассказывай.</npc>";
        str[162] = "Попробовать пойти ещё дальше и <a href=\"bj_bonus8\">засунуть</a> язык в дырку.";
        str[163] = "Вы продолжили играться с яичками парня и обхватив их " + root->getLipTalk() + ", поместили их в рот, дразня внутри языком."
                   "<npc>- Охуенно, детка, не останавливайся</npc>";
        str[164] = "Вы спускаетесь ниже, нежно проводите язычком и облизываете яйца, покрывая их своей слюной.";
        str[165] = "Сосать и <a href=\"bj_bonus7\">взять</a> яйца в рот.";
        str[166] = "Высунуть язык и <a href=\"bj_bonus6\">шлепать</a> по нему горячей головкой.";
        str[167] = "Вы плюнулю на член, и хорошенько ладошкой размазали слюну по всему члену."
                   "<npc>- Ухх, Светик, так и на смазку можно совсем не тратиться.";
        str[168] = "Вы проводите влажным языком по всей длине пениса, смазывая его свой липкой слюной.";
        str[169] = "Смазать член и <a href=\"bj_bonus5\">плюнуть</a> на него порцией своей липкой слюны.";
        str[170] = "Перед тем как облизнуть и приняться сосать сладкий член, вы слегка обхватили член рукой и натянули кожу, оголяя сверкающую головку.";
        str[171] = root->getBoyName() + " просит вас <a href=\"bj_bonus4\">шлепнуть</a> членом по вашей щечке.";
        str[172] = "Смотря в глаза своего парня, вы дразните язычком одну из самых эрогенных зон члена."
                   "<npc>- Класс, Светик, знаешь как меня завести еще сильнее.</npc>";
        str[173] = "Можно слегка <a href=\"bj_bonus3\">подразнить</a> тонкую уздечку члена";
        str[174] = "Попробовать слегка <a href=\"bj_bonus2\">укусить</a> красную головку члена";
        str[175] = "<a href=\"bj_bonus1\">Засунуть</a> кончик языка в дырочку.";
        str[176] = "Вы как послушная девочка, полностью подчиняетесь воле парня. Еще немного поласкавшись, " + root->getBoyName() + " просит вас...";
        str[177] = root->getBoyName() + " уложил вас на спину и раздвинул ножки, приоткрывая ваше девственное лоно.";
        str[178] = "<npc>- Ох,Светик, ты охуенная девочка, поздравляю, теперь ты настоящая баба. Как себя чувствуешь?</npc>";
        str[179] = "<npc>- Ну вот Светик, поздравляю, ты больше не девочка. Как себя чувствуешь?</npc>";
    }
    if(id >= 180 && id < 200)
    {
        str[180] = "<npc>- Светик, все хорошо, как ты себя чувствуешь?</npc>";
        str[181] = "<hero>- Все болит блин, никогда больше не буду этим заниматься.</hero>";
        str[182] = "<npc>- Ха ха, это мы еще посмотрим, еще добавки просить будешь.</npc>";
        str[183] = "<npc>- Да ладно тебе, все через девушки это проходят.</npc>";
        str[184] = "<npc>- Успокойся, милая, в следующий раз будет гораздо лучше, тебе еще понравится, обещаю,</npc> - с улыбкой произнес " + root->getBoyName() + " и нежно вас поцеловал.";
        str[185] = "Игорь";
        str[186] = "Андрей";
        str[187] = "Сергей";
        str[188] = root->getBoyName() + " обнял вас и начал целовать и после говорит: <npc>- Светик, раздевайся.</npc>";
        str[189] = "Вы, покраснев, прошептали парню, что вы еще девочка. " + root->getBoyName() + " растерянно почесал подбородок,"
                   " <npc>- Вот блин, да еще и школу не окончила. Ну тогда может в рот или попу?</npc>";
        str[190] = "<npc>- Светик, я хочу быть первым твоим мужчиной, я не сделаю тебе больно, только если чуть-чуть.</npc>"
                   "<hero>- " + root->getBoyName() + ", милый, я сама очень хочу, но если мама узнает, она меня просто убьет.</hero>"
                   "<npc>- Ну узнает? Скажешь, что у нас все серьезно, любовь и все прочее...</npc>";
        str[191] = "<hero>- Прости, " + root->getBoyName() + ", я бы очень хотела, но пока мне рано.</hero>"
                   "<npc>- Светик, я нормальный парень и хочу нормального секса со своей девушкой, раз мы встречаемся.</npc>"
                   "<hero>- " + root->getBoyName() + ", я уже сказала нет. И я думаю нам лучше растаться, раз ты меня не хочешь понять."
                   "Вы расстались с парнем";
        str[192] = "Вы сказали парню, что вы еще девочка. " + root->getBoyName() + " улыбнулся: - Света ты же школу закончила, взрослая"
                   " уже теперь. Не ну конечно можешь взять в рот или дать в попу.";
        str[193] = "Вы быстро скинули с себя одежду и " + root->getBoyName() + " тоже разделся.";
        str[194] = "<hero>- " + root->getBoyName() + ", блин, у меня эти самые дни,</hero> - растерянно сказали вы."
                   "<npc>- Ничего страшного, Светик, можно же в попку или в ротик,</npc> - ответил он."
                   "<hero>- Ну ладно...</hero> - пробормотали вы.";
        str[195] = root->getBoyName() + " начал вас обнимать и целовать. Вас дико заводят эти ласки, и вы вместе возбуждаетесь еще сильнее";
        str[196] = "Вы запрыгнули на колени своего парня.<br>Продолжаете с ним целоваться и нежно третесь промежностью об его каменный ствол";
        str[197] = "Вы быстро скинули с себя одежду и " + root->getBoyName() + ", не отрывая от вас взгляда тоже разделся.";
        str[198] = root->getBoyName() + " закинул вас на кровать и набросился сверху"
                   "Вы долго целуетесь, " + root->getBoyName() + " успел сорвать с вас одежду и еще сильнее возбудиться.";
        str[199] = root->getBoyName() + " бросил вас на кровать и жадно прильнул губами между ваших ножек.";
    }
    if(id >= 200 && id <= 219)
    {
        str[200] = "Вы целуетесь с парнем, раздевая друг друга, он ласкает ваши сиськи, вы дотронулись до его члена и начали нежно его массировать.<br>" + root->getBoyName() + " немного давит на ваши плечи и вы все прекрасно понимаете...";
        str[201] = "Ворвавшись в комнату, " + root->getBoyName() + " поставил вас раком, и раздевая ласкает вашу попу";
        str[202] = "Вы, покраснев, прошептали парню, что вы еще девочка."
                   "<npc>- Светик, я хочу быть первым твоим мужчиной, я не сделаю тебе больно, не бойся.<npc>"
                   "<hero>- <<$boy>>, милый, я сама очень хочу, но если мама узнает, она меня просто убьет.</hero>"
                   "<npc>- Ну узнает? И что? Короче выбирай, или мама или я...</npc>";
        str[203] = "<hero>- Прости, " + root->getBoyName() + ", я бы очень хотела, но пока мне рано.</hero>"
                   "<npc>- Света, я нормальный мужик и хочу нормального секса с тобой, раз мы решили быть вместе.</npc>"
                   "<hero>- " + root->getBoyName() + ", я уже сказала нет. И я думаю нам лучше растаться, раз ты меня не хочешь понять.</hero>"
                   "Вы расстались с парнем.";
        str[204] = "<npc>- Светик, я хочу быть первым твоим мужчиной, я не сделаю тебе больно.</npc>"
                   "<hero>- <<$boy>>, милый, я сама очень хочу, но если мама узнает, она меня просто убьет.</hero>"
                   "<npc>- Ну узнает? Скажешь, что у нас любовь и все.</npc>";
    }
    return str[id];
}

QString HantersLoveSex::act(int id)
{
    QString act[43];
    act[0] = "Продолжить";
    act[1] = "Сосать подрачивая";
    act[2] = "Сосать без рук";
    act[3] = "Раздвинуть ноги";
    act[4] = "Сесть сверху";
    act[5] = "Нагнуться";
    act[6] = "Лечь на живот";
    act[7] = "Кончить";
    act[8] = "Дрочить";
    act[9] = "Опуститься на колени";
    act[10] = "Сосать головку";
    act[11] = "Лизать головку";
    act[12] = "Поцеловать головку";
    act[13] = "Ласкать ладошкой";
    act[14] = root->getBoyName() + " еще хочу.";
    act[15] = "Отойти";
    act[16] = "Запрыгнуть сверху";
    act[17] = "Наслажаться";
    act[18] = "Проглотить";
    act[19] = "Выплюнуть";
    act[20] = "Лечь на спину";
    act[21] = "Подставить попку";
    act[22] = "Запрыгнуть на руки";
    act[23] = "Раздвинуть ножки для куни";
    act[24] = "Взаимно ласкать друг друга";
    act[25] = "Лизать яйца";
    act[26] = "Лизать очко";
    act[27] = "Заглотить глубоко";
    act[28] = "Расслабить горло";
    act[29] = "Провести языком";
    act[30] = "Провести вокруг соска";
    act[31] = "Сжать между сисек";
    act[32] = "Приходить в себя";
    act[33] = "Далее";

    act[34] = "Раздеваться";
    act[35] = "Я еще девочка";
    act[36] = "Лишиться невинности";
    act[37] = "Расстаться с парнем";
    act[38] = "Уйти";
    act[39] = "Запрыгнуть на него";
    act[40] = "Сесть на член";
    act[41] = "Подчиниться парню";
    act[42] = "Раздвинуть ножки";

    return act[id];
}

QString HantersLoveSex::media(int id)
{
    QString med[187];
    med[0] = "data/sex/Kotovsexsyst/cum110.webm";
    med[1] = "data/sex/Kotovsexsyst/cum111.jpg";
    med[2] = "data/sex/Kotovsexsyst/cum1.webm";
    med[3] = "data/sex/Kotovsexsyst/cum2.webm";
    med[4] = "data/sex/Kotovsexsyst/cum3.webm";
    med[5] = "data/sex/Kotovsexsyst/cum4.jpg";
    med[6] = "data/sex/Kotovsexsyst/cum5.webm";
    med[7] = "data/sex/Kotovsexsyst/cum6.jpg";
    med[8] = "data/sex/Kotovsexsyst/cum7.webm";
    med[9] = "data/sex/Kotovsexsyst/cum8.webm";
    med[10] = "data/sex/Kotovsexsyst/cum9.jpg";
    med[11] = "data/sex/Kotovsexsyst/cum41.webm";
    med[12] = "data/sex/Kotovsexsyst/cum61.jpg";
    med[13] = "data/sex/Kotovsexsyst/cum71.jpg";
    med[14] = "data/sex/Kotovsexsyst/cum81.jpg";
    med[15] = "data/sex/Kotovsexsyst/cum81.webm";
    med[16] = "data/sex/Kotovsexsyst/cum82.jpg";
    med[17] = "data/sex/Kotovsexsyst/cum91.jpg";
    med[18] = "data/sex/Kotovsexsyst/cumf10.webm";
    med[19] = "data/sex/Kotovsexsyst/cumf20.webm";
    med[20] = "data/sex/Kotovsexsyst/cumf30.webm";
    med[21] = "data/sex/Kotovsexsyst/cumf40.webm";
    med[22] = "data/sex/Kotovsexsyst/cumf50.webm";
    med[23] = "data/sex/Kotovsexsyst/cumf60.webm";
    med[24] = "data/sex/Kotovsexsyst/cumf70.webm";
    med[25] = "data/sex/Kotovsexsyst/kotovbj0.webm";
    med[26] = "data/sex/Kotovsexsyst/kotovbj1.webm";
    med[27] = "data/sex/Kotovsexsyst/kotovbj2.webm";
    med[28] = "data/sex/Kotovsexsyst/kotovbj3.webm";
    med[29] = "data/sex/Kotovsexsyst/kotovbj4.webm";
    med[30] = "data/sex/Kotovsexsyst/kotovbj5.webm";
    med[31] = "data/sex/Kotovsexsyst/kotovbj10.webm";
    med[32] = "data/sex/Kotovsexsyst/kotovbj11.webm";
    med[33] = "data/sex/Kotovsexsyst/kotovbj12.webm";
    med[34] = "data/sex/Kotovsexsyst/kotovbj13.webm";
    med[35] = "data/sex/Kotovsexsyst/kotovbj20.webm";
    med[36] = "data/sex/Kotovsexsyst/kotovbj21.webm";
    med[37] = "data/sex/Kotovsexsyst/kotovbj22.webm";
    med[38] = "data/sex/Kotovsexsyst/kotovbj23.webm";
    med[39] = "data/sex/Kotovsexsyst/kotovbj24.webm";
    med[40] = "data/sex/Kotovsexsyst/kotovbj25.webm";
    med[41] = "data/sex/Kotovsexsyst/kotovbj26.webm";
    med[42] = "data/sex/Kotovsexsyst/kotovbj30.webm";
    med[43] = "data/sex/Kotovsexsyst/kotovbj31.webm";
    med[44] = "data/sex/Kotovsexsyst/kotovbj40.webm";
    med[45] = "data/sex/Kotovsexsyst/kotovbj41.webm";
    med[46] = "data/sex/Kotovsexsyst/kotovbj50.webm";
    med[47] = "data/sex/Kotovsexsyst/kotovbj51.webm";
    med[48] = "data/sex/Kotovsexsyst/kotovbj52.webm";
    med[49] = "data/sex/Kotovsexsyst/kotovbj53.webm";
    med[50] = "data/sex/Kotovsexsyst/kotovbj60.webm";
    med[51] = "data/sex/Kotovsexsyst/kotovbj61.webm";
    med[52] = "data/sex/Kotovsexsyst/kotovbj70.webm";
    med[53] = "data/sex/Kotovsexsyst/kotovbj71.webm";
    med[54] = "data/sex/Kotovsexsyst/kotovbj72.webm";
    med[55] = "data/sex/Kotovsexsyst/kotovbj73.webm";
    med[56] = "data/sex/Kotovsexsyst/kotovbj74.webm";
    med[57] = "data/sex/Kotovsexsyst/kotovbj80.webm";
    med[58] = "data/sex/Kotovsexsyst/kotovbj81.webm";
    med[59] = "data/sex/Kotovsexsyst/kotovbj90.webm";
    med[60] = "data/sex/Kotovsexsyst/kotovbj91.webm";
    med[61] = "data/sex/Kotovsexsyst/kotovbj100.webm";
    med[62] = "data/sex/Kotovsexsyst/kotovbj101.webm";
    med[63] = "data/sex/Kotovsexsyst/kotovbj102.webm";
    med[64] = "data/sex/Kotovsexsyst/kotovbj103.webm";
    med[65] = "data/sex/Kotovsexsyst/kotovbj110.webm";
    med[66] = "data/sex/Kotovsexsyst/kotovbj111.webm";
    med[67] = "data/sex/Kotovsexsyst/kotovbj112.webm";
    med[68] = "data/sex/Kotovsexsyst/kotovbj113.webm";
    med[69] = "data/sex/Kotovsexsyst/kotovbj114.webm";
    med[70] = "data/sex/Kotovsexsyst/kotovbj120.webm";
    med[71] = "data/sex/Kotovsexsyst/kotovbj121.webm";
    med[72] = "data/sex/Kotovsexsyst/kotovbj122.webm";
    med[73] = "data/sex/Kotovsexsyst/kotovbj130.webm";
    med[74] = "data/sex/Kotovsexsyst/kotovbj131.webm";
    med[75] = "data/sex/Kotovsexsyst/kotovbj140.webm";
    med[76] = "data/sex/Kotovsexsyst/kotovbj141.webm";
    med[77] = "data/sex/Kotovsexsyst/kotovbj142.webm";
    med[78] = "data/sex/Kotovsexsyst/kotovbjbonus1.webm";
    med[79] = "data/sex/Kotovsexsyst/kotovbjbonus2.webm";
    med[80] = "data/sex/Kotovsexsyst/kotovbjbonus3.webm";
    med[81] = "data/sex/Kotovsexsyst/kotovbjbonus4.webm";
    med[82] = "data/sex/Kotovsexsyst/kotovbjbonus5.webm";
    med[83] = "data/sex/Kotovsexsyst/kotovbjbonus6.webm";
    med[84] = "data/sex/Kotovsexsyst/kotovbjbonus7.webm";
    med[85] = "data/sex/Kotovsexsyst/kotovbjbonus8.webm";
    med[86] = "data/sex/Kotovsexsyst/kotovbjbonus11.webm";
    med[87] = "data/sex/Kotovsexsyst/kotovbjbonus12.webm";
    med[88] = "data/sex/Kotovsexsyst/kotovecho.webm";
    med[89] = "data/sex/Kotovsexsyst/kotovfirst1.jpg";
    med[90] = "data/sex/Kotovsexsyst/kotovfirst.jpg";
    med[91] = "data/sex/Kotovsexsyst/kotovotkaz.webm";
    med[92] = "data/sex/Kotovsexsyst/kotovpre0.webm";
    med[93] = "data/sex/Kotovsexsyst/kotovpre1.webm";
    med[94] = "data/sex/Kotovsexsyst/kotovpre2.webm";
    med[95] = "data/sex/Kotovsexsyst/kotovpre3.webm";
    med[96] = "data/sex/Kotovsexsyst/kotovpre4.webm";
    med[97] = "data/sex/Kotovsexsyst/kotovpre10.webm";
    med[98] = "data/sex/Kotovsexsyst/kotovpre11.webm";
    med[99] = "data/sex/Kotovsexsyst/kotovpre12.webm";
    med[100] = "data/sex/Kotovsexsyst/kotovpre13.webm";
    med[101] = "data/sex/Kotovsexsyst/kotovpre14.webm";
    med[102] = "data/sex/Kotovsexsyst/kotovpre15.webm";
    med[103] = "data/sex/Kotovsexsyst/kotovpre16.webm";
    med[104] = "data/sex/Kotovsexsyst/kotovpre20.webm";
    med[105] = "data/sex/Kotovsexsyst/kotovpre21.webm";
    med[106] = "data/sex/Kotovsexsyst/kotovpre22.webm";
    med[107] = "data/sex/Kotovsexsyst/kotovpre23.webm";
    med[108] = "data/sex/Kotovsexsyst/kotovpre30.webm";
    med[109] = "data/sex/Kotovsexsyst/kotovpre40.webm";
    med[110] = "data/sex/Kotovsexsyst/kotovpre41.webm";
    med[111] = "data/sex/Kotovsexsyst/kotovpre42.webm";
    med[112] = "data/sex/Kotovsexsyst/kotovpre50.webm";
    med[113] = "data/sex/Kotovsexsyst/kotovpre60.webm";
    med[114] = "data/sex/Kotovsexsyst/kotovpr.webm";
    med[115] = "data/sex/Kotovsexsyst/kotovsex0.webm";
    med[116] = "data/sex/Kotovsexsyst/kotovsex1.webm";
    med[117] = "data/sex/Kotovsexsyst/kotovsex2.webm";
    med[118] = "data/sex/Kotovsexsyst/kotovsex3.webm";
    med[119] = "data/sex/Kotovsexsyst/kotovsex10.webm";
    med[120] = "data/sex/Kotovsexsyst/kotovsex11.webm";
    med[121] = "data/sex/Kotovsexsyst/kotovsex12.webm";
    med[122] = "data/sex/Kotovsexsyst/kotovsex13.webm";
    med[123] = "data/sex/Kotovsexsyst/kotovsex20.webm";
    med[124] = "data/sex/Kotovsexsyst/kotovsex21.webm";
    med[125] = "data/sex/Kotovsexsyst/kotovsex30.webm";
    med[126] = "data/sex/Kotovsexsyst/kotovsex31.webm";
    med[127] = "data/sex/Kotovsexsyst/kotovsex32.webm";
    med[128] = "data/sex/Kotovsexsyst/kotovsex33.webm";
    med[129] = "data/sex/Kotovsexsyst/kotovsex40.webm";
    med[130] = "data/sex/Kotovsexsyst/kotovsex41.webm";
    med[131] = "data/sex/Kotovsexsyst/kotovsex42.webm";
    med[132] = "data/sex/Kotovsexsyst/kotovsex43.webm";
    med[133] = "data/sex/Kotovsexsyst/kotovsex44.webm";
    med[134] = "data/sex/Kotovsexsyst/kotovsex45.webm";
    med[135] = "data/sex/Kotovsexsyst/kotovsex50.webm";
    med[136] = "data/sex/Kotovsexsyst/kotovsex51.webm";
    med[137] = "data/sex/Kotovsexsyst/kotovsex60.webm";
    med[138] = "data/sex/Kotovsexsyst/kotovsex61.webm";
    med[139] = "data/sex/Kotovsexsyst/kotovsex70.webm";
    med[140] = "data/sex/Kotovsexsyst/kotovsex71.webm";
    med[141] = "data/sex/Kotovsexsyst/kotovsex72.webm";
    med[142] = "data/sex/Kotovsexsyst/kotovsexanal0.webm";
    med[143] = "data/sex/Kotovsexsyst/kotovsexanal1.webm";
    med[144] = "data/sex/Kotovsexsyst/kotovsexanal10.webm";
    med[145] = "data/sex/Kotovsexsyst/kotovsexanal11.webm";
    med[146] = "data/sex/Kotovsexsyst/kotovsexanal20.webm";
    med[147] = "data/sex/Kotovsexsyst/kotovsexanal30.webm";
    med[148] = "data/sex/Kotovsexsyst/kotovsexanal31.webm";
    med[149] = "data/sex/Kotovsexsyst/kotovsexanal32.webm";
    med[150] = "data/sex/Kotovsexsyst/kotovsexanal33.webm";
    med[151] = "data/sex/Kotovsexsyst/kotovsexanal34.webm";
    med[152] = "data/sex/Kotovsexsyst/kotovsexanal35.webm";
    med[153] = "data/sex/Kotovsexsyst/kotovsexanal36.webm";
    med[154] = "data/sex/Kotovsexsyst/kotovsexanalno.webm";
    med[155] = "data/sex/Kotovsexsyst/kotovsexbonus0.webm";
    med[156] = "data/sex/Kotovsexsyst/kotovsexbonus1.webm";
    med[157] = "data/sex/Kotovsexsyst/kotovsexbonus2.webm";
    med[158] = "data/sex/Kotovsexsyst/kotovsexbonus3.webm";
    med[159] = "data/sex/Kotovsexsyst/kotovsexbonus4.webm";
    med[160] = "data/sex/Kotovsexsyst/kotovsexbonus5.webm";
    med[161] = "data/sex/Kotovsexsyst/kotovsexbonus6.webm";
    med[162] = "data/sex/Kotovsexsyst/kotovsexbonus7.webm";
    med[163] = "data/sex/Kotovsexsyst/kotovsexbonus8.webm";
    med[164] = "data/sex/Kotovsexsyst/kotovsexbonus9.webm";
    med[165] = "data/sex/Kotovsexsyst/kotovsexbonus10.webm";
    med[166] = "data/sex/Kotovsexsyst/kotovsexbonus11.webm";
    med[167] = "data/sex/Kotovsexsyst/kotovsexbonus12.webm";
    med[168] = "data/sex/Kotovsexsyst/kotovsexbonus13.webm";
    med[169] = "data/sex/Kotovsexsyst/kotovsexbonus14.webm";
    med[170] = "data/sex/Kotovsexsyst/kotovsexbonus15.webm";
    med[171] = "data/sex/Kotovsexsyst/kotovsexbonus16.webm";
    med[172] = "data/sex/Kotovsexsyst/kotovsexbonus17.webm";
    med[173] = "data/sex/Kotovsexsyst/kotovsexbonus18.webm";
    med[174] = "data/sex/Kotovsexsyst/kotovsexbonus19.webm";
    med[175] = "data/sex/Kotovsexsyst/kotovsexbonus20.webm";
    med[176] = "data/sex/Kotovsexsyst/kotovsexbonus21.webm";
    med[177] = "data/sex/Kotovsexsyst/kotovsexbonus22.webm";
    med[178] = "data/sex/Kotovsexsyst/kotovsexbonus23.webm";
    med[179] = "data/sex/Kotovsexsyst/kotovsexbonus24.webm";
    med[180] = "data/sex/Kotovsexsyst/kotovsub.jpg";
    med[181] = "data/sex/ReksHome/reksParty_party_kuh_4_13.gif";
    med[182] = "data/sex/ReksHome/reksParty_party_kuh_4_14.gif";
    med[183] = "data/sex/ReksHome/reksParty_party_kuh_4_16.gif";
    med[184] = "data/npc/gadukino/swamp/IgorHanter.jpg";
    med[185] = "data/npc/gadukino/swamp/AndreiHanter.jpg";
    med[186] = "data/npc/gadukino/swamp/SergeiHanter.jpg";
    return med[id];
}

void HantersLoveSex::setVideo(QString path)
{
    root->setVideo(path, 800, 600);
}
