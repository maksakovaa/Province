// #include "bathroom.h"
#include "locationform.h"
#include "../Functions.h"
#include "ui_locationform.h"

BathRoom::BathRoom(LocationForm* ptr): root(ptr)
{
    bath_lock = 0;
    family_trip = 0;
}

void BathRoom::start()
{
    no_bath = 0;
    // 	!Брат в душе
//	if (back_loc == "parents_home" && gTime()->getHour() == 17 && gTime()->getMin() >= 30 && family_trip = 0 && rand_bathroom_peek = border_bathroom_peek)
//        peek();
	// !отчим в душе
//    else if (back_loc == "parents_home" && gTime()->getHour() == 16 && gTime()->getMin() >= 30 && family_trip = 0 && gTime()->getWeekNum() != 1 && rand_bathroom_peek = border_bathroom_peek)
//        peek();

// описания
    if (backLoc() == "tanya_apartment")
    {

    }
//		!Ванная Тани Центр-Сити Point Call = gt 'zz_bathroom','init','tanya_apartment'
//		gs 'zz_render',func('zz_bathroom_strings'+$lang, 'txt_1'),'city/center/tanya/bathroom0.jpg',func('zz_bathroom_strings'+$lang, 'txt_5')
    else if (backLoc() == "parents_home" || backLoc() == "shulgahome") //кв.родителей, кв.Шульги
    {
        root->setImage(":/locations/pavlovo/ghomeyard/podezd/2floor/parents_home/bathroom_parents/bath4.jpg");
        root->setDesc(bathStr(3));
    }
    else if (backLoc() == "banda_home") {}
//		!кв. Бандитов-Сити
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'city/north/banda/home/bath.jpg', func('zz_bathroom_strings'+$lang, 'txt_4')
    else if (backLoc() == "albina_ev") {}
//		!кв. Альбины Барловской
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath7.jpg', func('zz_bathroom_strings'+$lang, 'txt_5')
    else if (backLoc() == "mey_home") {}
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath5', func('zz_bathroom_strings'+$lang, 'txt_6')
    else if (backLoc() == "stwork" || backLoc() == "skk") {}
//		! стрипклуб Центр и СКК
//		no_bath = 1
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_2'),'common/interior/bathroom/bath6', func('zz_bathroom_strings'+$lang, 'txt_7')
    else if (backLoc() == "korr") {}
//		! квартира Южн.рн.
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath'+iif(my_house = 1,'',remvanr)+'.jpg',iif(remvanr = 0 and my_house = 2, func('zz_bathroom_strings'+$lang, 'txt_8'), '')
    else if (backLoc() == "uni_dorm") {}
//		no_bath = 1
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_2'),'city/center/university/dorm/interiors/bath',func('zz_bathroom_strings'+$lang, 'txt_9')
    else if (backLoc() == "Gadbana") {}
//		gt 'Gadbana'

    if (root->getVStatus(bawdy_body) != 0)
    {
        makeActBtn(actBath28);
    }
    //	gs 'zz_render', '', '', func('zz_bathroom_strings'+$lang, 'txt_51') ???
//Задвижка
    if (backLoc() == "parents_home")
    {
        if (bath_lock == 0)
        {
            makeActBtn(actBath29);
        }
        else
        {
            makeActBtn(actBath30);
        }
        // if $npc['38,qwKolka'] >= 5 and week <= 5 and hour = 6 and cloth[1] = 1 and anus >= 13 and vagina >= 13: gt 'sisterQW','incest_event5sub'
    }

    if((root->getCloth(ClothType::Main) == nullptr || ((ClothMain*)root->getCloth(ClothType::Main))->getClothGroup() == 1) && prevCloth != nullptr)
    {
        makeActBtn(actBath31);
    }
    else
    {
        makeActBtn(actBath32);
    }

    if (backLoc() == "parents_home")
    {
        if (root->getVStatus(shamelessFlag) >= 1)
        {
            makeActBtn(actBath23);
        }
        if (root->getVStatus(shamelessFlag) >= 2)
        {
            makeActBtn(actBath24);
        }
    }
    if (root->getItmCount(iRazor) > 0)
    {
        root->addDesc(bathStr(15));
    }
    if (root->getItmCount(iTampon) > 0)
    {
        if (no_bath == 0)
        {
            root->addDesc(bathStr(16));
        }
        else
        {
            root->addDesc(bathStr(17));
        }
        root->addDesc(bathStr(18));
    }
    else
    {
        root->addDesc(bathStr(19));
    }
    if (backLoc() == "korr" && my_house == 2 && remvanr == 0)
    {
        root->addDesc(bathStr(20));
    }
    else
    {
        root->addDesc(bathStr(21));
        makeActBtn(actBath25);
    }
    int bad_vanr;
    if (backLoc() == "korr" && remvanr == 0 && my_house == 2) bad_vanr = 1;
    else bad_vanr = 0;

    if(bad_vanr == 0 || backLoc() != "korr")
    {
        makeActBtn(actBath22);
        if(no_bath == 0)
        {
            makeActBtn(actBath27);
        }
    }
    else
    {
        makeActBtn(actBath4);
    }
    if(root->getItmCount(iTampon) > 0 && root->getVStatus(mesec) > 0 && root->getVStatus(isprok) == 0 && !root->isAutoTampon())
    {
        makeActBtn(actBath6);
    }

    if(root->getVStatus(cumPussy) > 0 || root->getVStatus(cumBelly) > 0 || root->getVStatus(cumAss) > 0 || root->getVStatus(cumAnus) > 0)
    {
        makeActBtn(actBath7);
    }

    if(root->getVStatus(cumLips) > 0 || root->getVStatus(cumFace) > 0)
    {
        makeActBtn(actBath8);
    }

    if(root->getVBody(makeup) != 1)
    {
        makeActBtn(actBath9);
    }

    if(root->getVStatus(cumFrot) > 0)
    {
        makeActBtn(actBath10);
    }

    if(root->getVBody(legHair) > 0 && root->getItmCount(iRazor) > 0)
    {
        makeActBtn(actBath11);
    }

    if(root->getVBody(pubisHair) > 0 && root->getItmCount(iRazor) > 0)
    {
        makeActBtn(actBath13);
    }

    if(root->getItmCount(iAnalPlug) > 0)
    {
        if(root->getSexVar(analplugIN) == 1)
            makeActBtn(actBath14);
        else
            makeActBtn(actBath15);
    }

    if(root->getItmCount(iPregtest) > 0)
    {
        makeActBtn(actBath16);
    }

    if(root->getItmCount(iVibrator) > 0)
    {
        if(root->getSexVar(vibratorIN) == 0)
            makeActBtn(actBath17);
        else
            makeActBtn(actBath18);
    }

    if(backLoc() == "korr")
    {
        if(stiralka > 0 || my_house == 1)
        {
            if(husband > 0 && husbandday > 0 && husporday != root->getDay() && poroshok >= 2)
            {
                husband += 5;
                poroshok -= 2;
                husporday = root->getDay();
                root->addDesc(bathStr(43));
            }
            if(poroshok < 2)
            {
                root->addDesc(bathStr(44));
            }
        }
        if(root->getItmCount(iShampoo) > 0)
        {
            root->addDesc(bathStr(45));
        }
        else
        {
            root->addDesc(bathStr(46));
        }
        if(poroshok > 0)
        {
            root->addDesc(bathStr(47));
        }
        if(stiralka > 0)
        {
            root->addDesc(bathStr(48));
        }
        if(husband > 0 && husbandday > 0 && husporday != root->getDay() && poroshok >= 2)
        {
            makeActBtn(actBath19);
        }
    }
}

void BathRoom::slotBathActionHandler(bathActs action)
{
    ClearLayout(root->m_actLayout);

    switch (action)
    {
    case actBath1:
    {
        root->slotChangeLoc(root->getCurPtr(),0);
    }
    break;

    case actBath2:
    {
        if(root->getVStatus(horny) >= 90)
        {
            root->setVStatus(lust,0);
            root->setVStatus(horny,0);
            root->incTime(10);
            root->updVStatistic(masturbation,1);
            root->updVStatistic(orgasm,1);
            root->updVStatus(mood,15);
            root->setImage(":/actions/bathroom/wash7.jpg");
            root->setDesc(bathStr(25));
            makeActBtn(actBath1);
        }
        if(root->getVStatus(horny) >= 40 && root->getVStatus(horny) < 90)
        {
            root->updVStatus(horny,5);
            root->incTime(10);
            root->updVStatus(mood,10);
            root->setImage(":/actions/bathroom/wash8.jpg");
            root->setDesc(bathStr(26));
            makeActBtn(actBath1);
        }
    }
    break;
    
    case actBath3:
    {
        root->startSelfPlay();
    }
    break;
    
    case actBath4:
    {
        root->incTime(5);
        root->setVBody(makeup,1);
        root->setVStatus(cumLips,0);
        root->setVStatus(cumFace,0);
        root->updVStatus(sweat, -1);
        root->setImage(":/actions/bathroom/facesp.jpg");
        root->setDesc(bathStr(27));
        makeActBtn(actBath5);
    }
    break;
    
    case actBath5:
    {
        slotBathActionHandler(actBath1);
    }
    break;
    
    case actBath6:
    {
        root->useItem(iTampon,1);
        root->setVStatus(isprok,1);
        root->incTime(5);
        root->updVStatus(mood, -5);
        root->setImage(":/actions/bathroom/tampon.jpg");
        root->setDesc(bathStr(29));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath7:
    {
        root->setVStatus(cumPussy,0);
        root->setVStatus(cumBelly,0);
        root->setVStatus(cumAss,0);
        root->setVStatus(cumAnus,0);
        root->updVStatus(sweat, -1);
        root->incTime(5);
        root->setImage(":/actions/bathroom/wash" + intQStr(getRandInt(5,6)) + ".jpg");
        root->setDesc(bathStr(28));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath8:
    {
        root->setVBody(makeup, 1);
        root->setVStatus(cumLips,0);
        root->setVStatus(cumFace,0);
        root->updVStatus(sweat, -1);
        root->incTime(5);
        root->setImage(":/actions/bathroom/facesp.jpg");
        root->setDesc(bathStr(30));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath9:
    {
        root->setVBody(makeup,1);
        root->incTime(15);
        root->setImage(":/actions/bathroom/facesp.jpg");
        root->setDesc(bathStr(31));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath10:
    {
        root->setVStatus(cumFrot,0);
        root->getCloth(ClothType::Main)->decreaseCondition();
        root->incTime(15);
        root->setImage(":/actions/bathroom/frotsp" + intQStr(getRandInt(0,6)) + ".jpg");
        root->setDesc(bathActStr(32));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath11:
    {
        root->incTime(15);
        root->updVBody(legHair, -5);
        root->updVStatus(horny, 5);
        root->useItem(iRazor, 1);
        emit root->sigUpdParams();
        root->setVideoDesc(bathStr(33));
        root->videoWidg->setQUrl("qrc:/actions/shave/legs.webm",900,508);
        root->ui->imageAndWideoWdgt->setCurrentIndex(1);

        makeActBtn(actBath12);
    }
    break;
    
    case actBath12:
    {
        slotBathActionHandler(actBath1);
    }
    break;
    
    case actBath13:
    {
        root->incTime(15);
        root->updVBody(pubisHair, -5);
        root->updVStatus(horny, 5);
        root->useItem(iRazor, 1);
        emit root->sigUpdParams();
        root->videoWidg->setQUrl("qrc:/actions/shave/pubic.webm",900,448);
        root->setVideoDesc(bathStr(34));
        root->ui->imageAndWideoWdgt->setCurrentIndex(1);
        makeActBtn(actBath12);
    }
    break;
    
    case actBath14:
    {
        root->incTime(1);
        root->setSexVar(analplugIN,0);
        root->setImage(":/actions/analplug/analplug.jpg");
        if (root->getVBody(anus) >= 5)
        {
            root->setDesc(bathStr(35));
        }
        else
        {
            root->setDesc(bathStr(36));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath15:
    {
        root->incTime(5);

        if (root->sextToysBlock(2).isEmpty())
        {
            root->setSexVar(analplugIN, 1);
            if (root->getVBody(anus) < 10)
            {
                root->updVBody(anus, 1);
            }
            root->setImage(":/actions/analplug/analplug.jpg");
            if (root->getVBody(anus) >= 5)
            {
                root->setDesc(bathStr(37));
            }
            else
            {
                root->setDesc(bathStr(38));
            }
        }
        else
        {
            root->setImage(":/actions/analplug/no_anus.jpg");
            root->setDesc(root->sextToysBlock(2));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath16:
    {
        root->useItem(iPregtest,1);
        if(root->getVStatus(pregnancy) > 0)
        {
            root->setVStatus(pregnancyKnow,1);
            root->setDesc(bathStr(39));
        }
        else
        {
            root->setDesc(bathStr(40));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath17:
    {
        root->incTime(5);
        if (root->sextToysBlock(1).isEmpty())
        {
            root->setSexVar(vibratorIN, 1);
            if (root->getVBody(vagina) < 6)
            {
                root->updVBody(vagina, 1);
            }
            root->setImage(":/actions/vibrator/vibrator" + intQStr(getRandInt(0, 1)) + ".jpg");
            root->setDesc(bathStr(41));
        }
        else
        {
            root->setImage(":/actions/vibrator/no_pussy.jpg");
            root->setDesc(root->sextToysBlock(1));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath18:
    {
        root->incTime(2);
        root->setSexVar(vibratorIN, 0);
        root->setImage(":/actions/vibrator/vibrator" + intQStr(getRandInt(0, 1)) + ".jpg");
        root->setDesc(bathStr(42));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath19:
    {
        husband += 5;
        poroshok -= 2;
        root->incTime(60);
        husporday = root->getDay();
        root->updVStatus(mood, -25);
        root->setImage(":/actions/bathroom/stir.jpg");
        root->setDesc(bathStr(49));
        makeActBtn(actBath20);
    }
    break;
    
    case actBath20:
    {
        slotBathActionHandler(actBath1);
    }
    break;
    
    case actBath21:
    {
         slotBathActionHandler(actBath1);
    }
    break;
    
    case actBath22:
    {
        if((backLoc() == "korr" || backLoc() == "skk" || backLoc() == "uni_dorm") && root->getItmCount(iShampoo) == 0)
        {
            noShampoo();
        }
        else
        {
            root->updVStatus(horny, -root->getVStatus(horny)/5);
            root->updVStatus(vaginal_grease, -root->getVStatus(vaginal_grease)/3);
            root->updVStatus(mood, 5);
            root->updVStatus(hygiene, 3);
            shower();
            savePrevCloth();
            root->redress(new ClothMain(1, ClothGroup::towel, "Полотенце"));
            root->setImage(":/actions/bathroom/dush.jpg");
            root->setDesc(bathStr(22));
            if(bath_lock == 0 && backLoc() == "parents_home")
            {
                root->addDesc("<br>" + bathStr(23));
                makeActBtn(actBath26);
            }
            else
            {
                makeActBtn(actBath1);
            }
        }
    }
    break;
    
    case actBath23:
    {
        savePrevCloth();
        root->redress(new ClothMain(1,ClothGroup::towel,"Полотенце"));
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),1);
    }
    break;
    
    case actBath24:
    {
        savePrevCloth();
        root->redress(nullptr);
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),1);
    }
    break;
    
    case actBath25:
    {
        root->viewObj("mirror");
    }
    break;
    
    case actBath26:
    {
        if(family_trip == 0)
        {
            voyer();
        }
        else
        {
            root->slotChangeLoc(root->getCurPtr(),0);
        }
    }
    break;
    
    case actBath27:
    {
        if(backLoc() == "korr" && root->getItmCount(iShampoo) <= 0)
        {
            noShampoo();
        }
        root->incTime(45);
        if(skinday != root->getVStatus(daystart))
        {
            skinday = root->getVStatus(daystart);
            root->updSkin('+', 3);
        }
        shower();
        savePrevCloth();
        root->redress(nullptr);
        root->updVStatus(horny, -root->getVStatus(horny)/4);
        root->updVStatus(vaginal_grease, -root->getVStatus(vaginal_grease)/2);
        root->updVStatus(hygiene,15);
        root->setImage(":/actions/bathroom/wash4.jpg");
        root->setDesc(bathStr(24));
        makeActBtn(actBath1);
        if(root->getVStatus(horny) >= 40)
        {
            makeActBtn(actBath2);
        }
        if(root->getVStatus(horny) >= 50)
        {
            makeActBtn(actBath3);
        }
    }
    break;
    
    case actBath28:
    {
        root->incTime(10);
        root->setVStatus(bawdy_body, 0);
        root->slotChangeLoc(root->getCurPtr(),0);
    }
    break;

    case actBath29:
    {
        bath_lock = 1;
        slotBathActionHandler(actBath1);
    }
    break;

    case actBath30:
    {
        bath_lock = 0;
        slotBathActionHandler(actBath1);
    }
    break;

    case actBath31:
    {
        root->redress(prevCloth);
        slotBathActionHandler(actBath32);
    }
    break;

    case actBath32:
    {
        if(bath_lock == 1) bath_lock = 0;
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),1);
    }
    break;
    }
    emit root->sigUpdParams();
}

void BathRoom::slotPeekActHandler(peekActs action)
{
    switch (action)
    {
    case actPeek1:
    {
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),0);
    }
        break;
    case actPeek2:
    {
        if (root->getVStatistic(peek1day) == 1)
        {
            root->setImage(":/qwest/brotherpeek/brotherpeek2.jpg");
            root->setDesc(peekStr(2));
            makePeekActBtn(actPeek1);
        }
        else if (root->getVStatus(shamelessFlag) == 0 && peek1day == 0)
        {
            root->incTime(getRandInt(2,4));
            root->setImage(":/qwest/brotherpeek/brotherpeek1.jpg");
            root->setDesc(peekStr(1));
            makePeekActBtn(actPeek5);
        }
        else if (brotherpeekstage >= 5 && brotherpeekhelp <= 5 && peek1day == 0 && root->getVStatus(shamelessFlag) > 0 && npc_39relation > 60) 
        {
            root->incTime(getRandInt(2,4));
            root->setImage(":/qwest/brotherpeek/brotherpeek3.jpg");
            root->setDesc(peekStr(6));
            makePeekActBtn(actPeek3);
            makePeekActBtn(actPeek7);
        }
    }
        break;
    case actPeek3:
    {
        root->incTime(getRandInt(2,4));
        root->updVStatus(mood,5);
        root->setImage(":/qwest/brotherpeek/brotherpeek7.jpg");
        root->setDesc(peekStr(3));
        if (root->getVStatus(shamelessFlag) > 1)
        {
            makePeekActBtn(actPeek4); //brother_jerk
        }
        makePeekActBtn(actPeek8);
    }
        break;
    case actPeek4:
    {
        root->incTime(getRandInt(2,4));
        root->setImage(":/qwest/brotherpeek/brotherpeek6.jpg");
        root->setDesc(peekStr(8));
        makePeekActBtn(actPeek9);
    }
        break;
    case actPeek5:
    {
        root->incTime(getRandInt(2,4));
        root->setImage(":/qwest/brotherpeek/brotherpeek5.jpg");
        root->setDesc(peekStr(7));
        brotherpeekstage += 1;
        root->updVStatistic(peek1day, 1);
        root->updVStatus(horny, getRandInt(10,15));
        makePeekActBtn(actPeek6);
    }
        break;
    case actPeek6:
    {
        root->incTime(getRandInt(2,4));
        slotPeekActHandler(actPeek1);
    }
        break;
    case actPeek7:
    {
        brotherpeekstage +=1;
        root->updVStatistic(peek1day, 1);
        root->updVStatus(horny, getRandInt(5,10));
        root->updVStatistic(voyeurism,1);
        slotPeekActHandler(actPeek1);
    }
        break;
    case actPeek8:
    {
        root->incTime(getRandInt(2,4));
        root->setImage(":/qwest/brotherpeek/brotherpeek4.jpg");
        root->setDesc(peekStr(5));
        makePeekActBtn(actPeek7);
    }
        break;
    case actPeek9:
    {
        root->incTime(getRandInt(2,4));
        root->updVStatus(mood, -5);
        root->setImage(":/qwest/brotherpeek/brotherpeek8.jpg");
        root->setDesc(peekStr(9));
        makePeekActBtn(actPeek10);
    }
        break;
    case actPeek10:
    {
        root->incTime(getRandInt(5,10));
        root->updVStatus(mood, -5);
        root->setImage(":/qwest/brotherpeek/brotherpeek4.jpg");
        root->setDesc(peekStr(10));
        makePeekActBtn(actPeek11);
    }
    break;

    case actPeek11:
    {
        brotherpeekstage +=1;
        root->updVStatistic(peek1day, 1);
        root->updVStatus(horny, getRandInt(20,30));
        slotPeekActHandler(actPeek1);
    }
        break;
    }
    emit root->sigUpdParams();
}

void BathRoom::slotVoyerActHandler(bathVoyerActs action)
{
    switch (action)
    {
    case actBV1:

        break;
    case actBV2:
        break;
    case actBV3:
        break;
    case actBV4:
        break;
    case actBV5:
        break;
    case actBV6:
        break;
    case actBV7:
        break;
    case actBV8:
        break;
    }
    emit root->sigUpdParams();

}

void BathRoom::peek()
{
    root->setImage(":/qwest/brotherpeek/brotherpeek0.jpg");
    root->setDesc(peekStr(0));
    if(backLoc() == "parents_home")
    {
        makePeekActBtn(actPeek1);
    }
    if(family_trip == 0 && hour() == 17 && minut() >= 30)
        makePeekActBtn(actPeek2);
    
}

void BathRoom::makeActBtn(bathActs action)
{
    BathActBtn* btn = new BathActBtn(action, bathActStr(action));
    connect(btn, &BathActBtn::sigAction, this, &BathRoom::slotBathActionHandler);
    root->m_actLayout->addWidget(btn);
}

void BathRoom::makeVoyerActBtn(bathVoyerActs action)
{

}

void BathRoom::makePeekActBtn(peekActs action)
{

}

QString BathRoom::bathStr(int value)
{
    QString str[51];
    str[1] = "Ванная";
    str[2] = "Душевая";
    str[3] = "Ванная тесная и очень простенькая.";
    str[4] = "Ванная комната. Здесь вы можете принять душ или ванну.";
    str[5] = "Чистая и роскошная ванная комната.";
    str[6] = "Чистый и опрятный санузел.";
    str[7] = "Небольшая и очень простенькая уборная.";
    str[8] = "В этой ванне явно помыться не получится.";
    str[9] = "Душевая общежития. Явно не роскошная сауна. Но чистенько. Скромненько.";
    str[10] = "";
    str[11] = "";
    str[12] = "";
    str[13] = "";
    str[14] = "";
    str[15] = "<br>Вашего бритвенного станка хватит ещё на " + intQStr(root->getItmCount(iRazor)) + " раз.";
    str[16] = "<br>На полке лежит";
    str[17] = "<br>У вас имеется";
    str[18] = " упаковка тампонов. Ее хватит ещё на <b>" + intQStr(root->getItmCount(iTampon)) + "</b> раз.";
    str[19] = "У вас нет тампонов.";
    str[20] = "<br>Судя по оставшемуся контуру, на этом месте висело зеркало.";
    str[21] = "<br>Над раковиной висит <a href='mirror'>зеркало</a>.";
    str[22] = "Вы залезли под душ. Намылившись мочалкой, вы смыли пену и вымыли волосы шампунем. Теперь вы чистенькая и благоухающая свежестью.";
    str[23] = "Стараясь побыстрее умыться и вернуться к своим делам, вы совершенно забываете закрыть дверь - не до неё.<br>Мысль о том, что дверь открыта, настигает вас уже под конец, когда вы вытираетесь полотенцем. Было бы очень неловко, если бы брат или отчим заглянули бы не вовремя.";
    str[24] = "Включив воду, вы залезли в ванную и легли в теплую воду. Понаслаждавшись приятным теплом вы намылили свое тело мочалкой и волосы шампунем. Затем вы все смыли водой.";
    str[25] = "Вы направили кран с водой на киску и тугая струя теплой воды начали ласкать вас. Вскоре вы почувствовали как теплая волна охватывает весь ваш организм и вы начали содрогаться в оргазме.";
    str[26] = "Вы направили кран с водой на киску и тугая струя теплой воды начали ласкать вас. Сначала было очень даже не плохо, но потом возбуждение спало и стало даже как-то не приятно. Поэтому вы прекратили мастурбировать.";
    str[27] = "Вы тщательно умыли лицо и смыли косметику.";
    str[28] = "Вы тщательно смыли сперму в ванной.";
    str[29] = "Вы поменяли тампон";
    str[30] = "Вы тщательно смыли сперму с лица.";
    str[31] = "Вы смыли косметику.";
    str[32] = "Вы замыли пятна спермы на своей одежде.";
    str[33] = "Вы намыливаете ноги, и взяв бритву, ловкими движениями сбриваете волоски на ногах, смыв затем пенку для бритья.";
    str[34] = "Вы намыливаете лобок, и взяв бритву, ловкими движениями сбриваете волоски вокруг киски.";
    str[35] = "Вы наклонились и привычным движением вынули из себя анальную пробку.";
    str[36] = "Вы поднатужились и, закусив губу, с громким чпоком вынули из ануса пробку.";
    str[37] = "Вы наклонились и привычным движением вставили себе анальную пробку.";
    str[38] = "Вы постарались как можно сильнее расслабить попу и стали вставлять себе пробку. Закусив губу от чувства, что ваша попа вот вот лопнет, вы аккуратно протолкнули толстую часть в свою попу, и наконец-то пробка встала на место.";
    str[39] = "Тест показал две полоски. Вы беременны. Вы думаете, что отец <<$father>>.";
    str[40] = "Тест показал одну полоску.";
    str[41] = "Разведя ноги, вы вставляете вибратор в киску.";
    str[42] = "Наклонились, вы вынимаете вибратор из влагалища.";
    str[43] = "Стиральная машинка выстирала вещи мужа.";
    str[44] = "У вас кончился порошок для стиральной машины.";
    str[45] = "У вас хватит шампуня на <<shampoo>> раз.";
    str[46] = "У вас кончился шампунь, поэтому с мытьём проблемы.";
    str[47] = "Под ванной стоит упаковка стирального порошка, которого хватит на <b><<poroshok>></b> стирок.";
    str[48] = "В ванной стоит стиральная машинка.";
    str[49] = "Вы целый час отстирывали носки мужа и его труселя.";
    str[50] = "<red>Чёрт, шампунь-то закончился!</red>";
    return str[value];
}

QString BathRoom::bathActStr(int value)
{
    QString actStr[32];
    actStr[actBath1] = "Закончить";
    actStr[actBath2] = "Направить воду на киску";
    actStr[actBath3] = "Мастурбировать";
    actStr[actBath4] = "Умыться";
    actStr[actBath5] = "Далее";
    actStr[actBath6] = "Поменять тампон";
    actStr[actBath7] = "Подмыться 5 мин";
    actStr[actBath8] = "Смыть сперму с лица 5 мин";
    actStr[actBath9] = "Смыть косметику";
    actStr[actBath10] = "Оттирать сперму с одежды";
    actStr[actBath11] = "Брить ноги 15 мин";
    actStr[actBath12] = "Отложить станок";
    actStr[actBath13] = "Брить лобок 15 мин";
    actStr[actBath14] = "Вынуть анальную пробку";
    actStr[actBath15] = "Вставить анальную пробку";
    actStr[actBath16] = "Сделать тест на беременность";
    actStr[actBath17] = "Вставить вибратор 5 мин.";
    actStr[actBath18] = "Вынуть вибратор 2 мин";
    actStr[actBath19] = "Стирать одежду мужа (1ч, 2 ед. стирального порошка)";
    actStr[actBath20] = "Отойти от ванной";
    actStr[actBath21] = "Назад";
    actStr[actBath22] = "Мыться под душем 15 мин";
    actStr[actBath23] = "Выйти из ванной в полотенце";
    actStr[actBath24] = "Выйти из ванной голышом";
    actStr[actBath25] = "Зеркало";
    actStr[actBath26] = "Вытираться";
    actStr[actBath27] = "Мыться в ванной 1 час";
    actStr[actBath28] = "Оттирать похабные надписи.";
    actStr[actBath29] = "Закрыть щеколду на двери";
    actStr[actBath30] = "Открыть щеколду на двери";
    actStr[actBath31] = "Одеться и выйти";
    actStr[actBath32] = "Выйти";

    return actStr[value];
}

QString BathRoom::voyerStr(int value)
{
    QString str[10];
    str[1] = "Как назло, за дверью слышатся шаги. Обернувшись, вы успеваете заметить фигуру отчима и его глаза. "
             "Он, пробурчав что-то о двери, тут же уходит, оставив вас в смущении и с быстро колотящимся сердцем.";
    str[2] = "Неожиданно дверь ванной слегка скрипит, приотворяясь. Обернувшись, вы видите отчима. "
             "Он стоит в коридоре и пожирает ваше обнажённое тело глазами. "
             "В вашем воображении тут же вспыхивают все те сцены, которые уже были между вами - а потом вы вспоминаете,"
             " что мама на работе. На вашем лице появляется улыбка, а внизу живота приятно наливается тепло:<br>"
             "<span class=\"hero_dialogue\">- Папочка хочет присоединиться?</span>";
    str[3] = "s";
    str[4] = "К счастью, за дверью совсем никого нет - и вы, быстренько вытеревшись одним полотенцем и замотав голову "
             "другим, заканчиваете свои дела.";
    str[5] = "Получается пошло и глупо, но эта пошлость возбуждает - и вас, и его. Нервно облизав губы, отчим открывает"
             " дверь, быстро заходит внутрь, и запирает её за собой. Из за того, что он мужчина крупный, в маленькой"
             " ванной резко становится тесно - и вы ощущаете сладкое чувство собственной слабости по сравнению с ним."
             "<br><span class=\"npc_dialogue\">- Ты меня когда-нибудь с ума сведёшь, Света</span> - пыхтит отчим, судорожно сдирая с себя одежду.<br>"
             "Вы только смеётесь, прислонившись лопатками к холодному кафелю стены и выпятив вперед животик и бёдра. "
             "Вы знаете, что сейчас похожи на похотливого маленького мокрого чертёнка - и, чёрт возьми, вам это "
             "нравится! Вас от этого прёт! А отчим уже разделся: он залезает к вам в ванну, прижимает своим брюшком к "
             "стене, грубо шаря по вашему телу руками - а потом вдруг резко разворачивает, вжимая в стену. "
             "Вы прижимаетесь к кафелю горячей щекой и чуть пошире расставляете ножки - а пальцы отчима уже пробуют "
             "на ощупь вашу дырочку. Предательски-мокрую. Вы закусываете губу, ожидая какой-нибудь грубой фразочки - "
             "но вместо этого ощущаете, как палец без долгих церемоний сменяется членом, вызывая у вас протяжный вздох.";
    str[6] = "Как бы вам ни было хорошо в этот момент, ваша голова работает - и забывать о предохранении вы не "
             "собираетесь. В конце-концов, это вам, если что, спиногрыза вынашивать, не ему. Так что, задрыгав попкой,"
             " вы обеспокоенно спрашиваете:"
             "<span class=\"hero_dialogue\">- Эй, а как же презерватив?</span>"
             "Отчим на секунду замирает - ему тоже явно не улыбается заделать своей падчерице ребёночка. Но он слишком"
             " заведён, чтобы отступать - так что шепчет успокаивающе:"
             "<span class=\"npc_dialogue\">- Чшш, Света, всё будет хорошо! Я выну.</span>"
             "И вы, закусив губу, умолкаете. Всё-таки вам тоже очень хочется - аж печёт внутри, как хочется! И вот уже"
             " крепкий мужской член обманчиво-медленно и мягко входит в вас на полшишечки, раздвигая набухшие влажные "
             "лепестки половых губок, вызвав невольный сладкий стон - а уже через пару секунд отчим загоняет его по на"
             " всю глубину, заставив ваши глаза вылезти из орбит. Похоже, ваши постоянные шалости довели человека до "
             "ручки. Истерически хихикая, вы стонете под его напором, мощными толчками вминаемая в кафель стены, "
             "расплющенная по ней - а отчим пыхтит сзади, трудясь как Стаханов в забое, серьезно намереваясь показать"
             " вам, кто здесь главный. И у него получается - очень скоро вы превращаетесь в маленькую пищащую сучку, "
             "стонущую под кобелём и просящую ещё. Это длится не так уж долго - всё-таки отчим взял слишком быстрый "
             "темп - но вам обоим хватает. Вы кончаете, не то чтобы очень сильно, но ярко; тепло разливается по всему "
             "телу, а пальчики на руках и ногах конвульсивно сжимаются. А под ваши сладкие стоны кончает и отчим - успев"
             " таки вытащить из вас член и щедро оросив своим семенем вашу попку. Сквозь вспыхивающие в голове разноцветные"
             " искорки проскальзывает мысль: \"Теперь понятно - чего мама так за него держится столько лет!\""
             "<span class=\"npc_dialogue\">- Ффух</span> - он устало выдыхает, вытирая пот со лба:**"
             "<span class=\"npc_dialogue\">- Я же говорил. Спасибо, Света</span>."
             "И легонько шлёпает вас по мокрой попке. После чего выбирается из ванной и начинает одеваться - ну а вам, "
             "похоже, снова придётся мыться.";
    str[7] = "В этот момент вам слишком хорошо, так что вовремя ваша голова сработать не успевает - и о предохранении вы"
             " забываете. Отчиму тоже сейчас не до этого - он слишком сильно жаждет вас. Так что сначала крепкий мужской"
             " член обманчиво-медленно и мягко входит в вас на полшишечки, раздвигая набухшие влажные лепестки половых "
             "губок, вызвав невольный сладкий стон - и только после этого вы соображаете, что на нем нет презерватива. "
             "И обеспокоенно просите, постанывая:"
             "<span class=\"hero_dialogue\">- Ох... Только не кончи в меня... случайно...</span>"
             "Отчим на секунду замирает. А потом с неожиданной прытью загоняет свой член в ваше влагалище по самые "
             "помидоры, заставив ваши глаза вылезти на лоб. Это не очень на него похоже - обычно он осторожнее. Но вам "
             "так хорошо, что сопротивляться вы не в силах. Перевозбужденная, вы стонете под его напором, вминаемая мощными"
             " толчками в мокрую кафельную стенку, расплющенная по ней - а отчим пыхтит сзади, трудясь как Стаханов в забое,"
             " серьезно намереваясь показать вам, кто здесь главный. И у него получается - очень скоро вы превращаетесь в "
             "маленькую пищащую сучку, стонущую под кобелём и просящую ещё. Это длится не так уж долго - всё-таки отчим взял "
             "слишком быстрый темп - но вам обоим хватает. Вы кончаете, не то чтобы очень сильно, но ярко; тепло разливается"
             " по всему вашему телу, а пальчики на руках и ногах конвульсивно сжимаются. В голове снова вспыхивает мысль: "
             "\"Только бы не в меня! Успеет ли он вынуть, взяв такой темп?\" Оказывается - он и не собирается вынимать. "
             "Отчим трахает вас до упора, забыв про всё на свете - и без зазрения совести кончает прямо в вашу незащищённую "
             "киску, в самую её сердцевинку, прямо под маточку. Смесь наслаждения и страха едва не заставляет вас кончить ещё раз."
             "<span class=\"hero_dialogue\">- Эй! Я же сказала!</span>"
             "Вынув член, отчим смущённо чешет в затылке:"
             "<span class=\"npc_dialogue\">- Прости, Светочка, бес попутал. Совсем из головы вылетело. Не волнуйся, ничего "
             "такого не будет, все будет хорошо!</span>"
             "И улыбается, гад такой, довольный как слон. Старый козёл. Нахмурившись, вы выталкиваете его с его одёжкой из ванной"
             " - вам еще его кончу из себя вымывать.";
    str[8] = "В этот момент вам так хорошо, что всё, о чём вы можете думать - это как бы получить в себя этот сладкий, крепкий член."
             " И отчим сейчас не сильно от вас отличается - примерного семьянина и осторожного рассудительного человека больше нет, "
             "есть просто мужик, самец, который хочет оттрахать попавшуюся ему в лапы сучку. Ваша попка призывно виляет - и вскоре в"
             " вашу киску обманчиво-медленно и мягко входит крепкий мужской член, совсем неглубоко, на полшишечки, раздвинув головкой "
             "мокрые скользкие половые губки, вызвав невольный сладкий стон, и ненадолго замирает. Вы, тяжело дыша, просите его, умоляете:"
             "<span class=\"hero_dialogue\">- Ох... Трахни меня!..</span>"
             "Но он не спешит. Он берёт вас уверенно и неторопливо, смакуя каждый сантиметр вашей узенькой молоденькой щёлки,"
             " заставляя вас сладко постанывать и снова и снова просить ещё. Не сразу, но он дает вам ещё - постепенно разгоняется,"
             " все быстрее и быстрее, все сильнее и сильнее, пока не начинает буквально драть, звонко шлёпая яйцами по вашим ягодицам."
             " Похоже, ваши постоянные шалости довели человека до ручки. Истерически хихикая, вы стонете под его членом, вминаемая в"
             " мокрый кафель стены, расплющенная по ней - а отчим пыхтит сзади, мощными ударами сотрясая вас, серьезно намереваясь "
             "покачать вам, кто здесь главный. Это длится не так уж долго - все-таки отчим взял слишком быстрый темп - но вам обоим "
             "хватает. Вы кончаете, не то чтобы очень сильно, но ярко; тепло разливается по всему телу, а пальчики на руках и ногах "
             "конвульсивно сжимаются. А под ваши сладкие стоны кончает и отчим - успев вытащить член и щедро оросив своим семенем вашу попку."
             "<span class=\"npc_dialogue\">- Ффух, - он устало выдыхает, вытирая пот со лба, - ох и шлюшка же ты, Света!</span>"
             "Он произносит это ласково, и вы улыбаетесь довольно, все ещё переживая самые сладкие моменты и едва не съезжая по "
             "стеночке на подгибающихся ногах. Через пару минут отчим выбирается из ванны и начинает одеваться - ну а вам, похоже, "
             "снова придется мыться.";
    str[9] = "Услышав за дверью какое-то движение, вы оборачиваетесь. Это, кажется, отчим проходил мимо - и заглянул нечаянно. Встретившись "
             "с ним взглядом, вы испытываете приятное шкодливое возбуждение - и озорно посылаете ему воздушный поцелуй. Без слов, он "
             "молча исчезает - а вы, довольная собой, хихикая, вытираете волосы.";
    return str[value];
}

QString BathRoom::voyerActStr(int value)
{
    QString actStr[8];
    actStr[actBV1] = "Закончить";
    actStr[actBV2] = "Прогнать его";
    actStr[actBV3] = "Пусть смотрит";
    actStr[actBV4] = "Папочка хочет присоединиться?";
    actStr[actBV5] = "Эй, а как же презерватив?";
    actStr[actBV6] = "Только не кончай в меня!";
    actStr[actBV7] = "Трахни меня!";
    actStr[actBV8] = "Опять надо мыться";
    return actStr[value];
}

QString BathRoom::peekStr(int value)
{
    QString str[11];
    str[0] = "В ванной шумит вода. Вам хочется посмотреть, хоть одним глазком, на то что происходит за дверью. Хотя это, конечно, неправильно.";
    str[1] = "Вы тихонько приоткрываете дверь и ввидите стоящего под душем  голого Колю. Он вас не видит, еще не поздно закрыть дверь и уйти.";
    str[2] = "Вы сегодня уже это делали, незачем пробовать еще.";
    str[3] = "Вы заходите в ванную."
             "- Ой, а тут занято? А я как раз хотела душ принять! - вы делеет вид, что  удивлены не меньше, чем Коля."
             "- Блин, Светка, ты что, шум воды не слышишь?"
             "А, ну да, - вы киваете. - Но раз уж я тут, может, тебе помочь? "
             "Не дожидаеясь ответа, вы принимаетесь намыливать брата. Чтобы добить его, вы обнажаете свою грудь,"
             " и продолжаете намыливаеть его, как ни в чем не бывало. Его член увеличивается в размерах, особенно,"
             " когда вы  как бы случайно его трогаете, но вы делете вид, что так и надо.";
    str[5] = "Хватит с него... да и с вас, а то так можно и доиграться. Вы оставляете брата в покое,"
             " отходите к зеркалу и начинаете наводить марафет, делая вид, что  ничего не было. "
             "Но халатик при этом задираете - пусть полюбуется на вашу попку!";
    str[6] = "Вы приоткрываете дверь. Коля намыливает свое мускулистое тело, вас он пока не видит. "
             "Вы можете зайти - конечно, это неправильно и он может и не одобрить. Но зато какая это возможность подразнить его!";
    str[7] = "Вы решаете остаться и посмотреть. Затаив дыхание, вы смотрите, как брат намыливает свое мускулистое тело."
             "  У вас перехватывает дыхание от неправильности происходящего, но вы не в силах оторвать взгляд. "
             "\"А он накачался\", - думаете вы, - \"И агрегат ничего себе так. Вот бы...\" Вы не успеваете додумать"
             " - вы слышиет шаги и отскакиваете от двери. Не хватало еще попасться!";
    str[8] = "Вы водите вокруг твердеющего члена. Коля не выдерживает и почти кричит:"
             "- Светка! Ты что творишь?!"
             "- Ори громче, пусть отчим услышит, - вы хихикаете, уже в открытую надрачивая член."
             "Коля тут же замолкает, двигая тазом навстречу вашей руке.";
    str[9] = "Все происходящее не нашутку завело и вас, и Кольку. Проходит несколько минут и он с хриплым стоном кончает. Вы завистливо вздыхаете.";
    str[10] = "Вы оставляете его в покое, отворачиваетесь к раковине и принмаетесь наводить марафет."
              " Но халатик при этом задираете - пусть полюбуется на вашу попку!"
              "- Блин, Светка, - Колька тяжело дышит."
              "- Спасибо, да?"
              "- С-спасибо, - выдавливает он.";
    return str[value];
}

QString BathRoom::peekActStr(int value)
{
    QString actStr[5];
    actStr[actPeek1] = "Уйти";
    actStr[actPeek2] = "Подсмотреть";
    actStr[actPeek3] = "Заглянуть";
    actStr[actPeek4] = "Подрочить";
    actStr[actPeek5] = "Далее";
    if (value == actPeek11 || actPeek7 || actPeek6)
        return actStr[actPeek1];
    else if (value == actPeek10 || actPeek9 || actPeek8)
        return actStr[actPeek5];
    else
        return actStr[value];
}

void BathRoom::savePrevCloth()
{
    ClothMain* playerCloth = (ClothMain*)root->getCloth(ClothType::Main);
    if(playerCloth != nullptr && playerCloth->getClothGroup() >= sundress)
    {
        prevCloth = playerCloth;
    }
}

TimeServer *BathRoom::gTime()
{
    return root->gTime();
}

QString BathRoom::backLoc()
{
    return root->getCurPtr()->getParentPtr()->getLocId();
}

void BathRoom::shower()
{
    root->incTime(15);
    cleanMe();
    if(backLoc() == "korr" && root->getItmCount(iShampoo) > 0)
    {
        root->useItem(iShampoo, 1);
    }
}

void BathRoom::cleanMe()
{
    root->setVStatus(cumPussy, 0);
    root->setVStatus(cumBelly, 0);
    root->setVStatus(cumAss, 0);
    root->setVStatus(cumAnus, 0);
    root->setVStatus(cumLips, 0);
    root->setVStatus(cumFace, 0);
    root->setVStatus(cumFrot, 0);
    root->setVStatus(sweat, 0);
    root->setVBody(makeup, 1);
    root->setVBody(hairStatus,0);
    root->updVStatus(horny, -root->getVStatus(horny)/5);
    root->updVStatus(vaginal_grease, -root->getVStatus(vaginal_grease)/3);
}

void BathRoom::noShampoo()
{
    root->setDesc(bathStr(50));
    makeActBtn(actBath21);
}

void BathRoom::voyer()
{
    father_dadqw_day = day();
    brother_ev1 = day();
    if (
        (((week() == 0 || week() == 6) && hour() >= 7 && hour() <= 17) || (week() > 1 && week() < 6 && (hour() == 7 || hour() == 17))) && father_dadqw_day != day())
    {
        father_dadqw_day = day();
        // if $npc['35,relation'] < 60 or $npc['35,qwOtchim'] < 3:
        // gs 'zz_render','','qwest/alter/father/bath_voyer_0.webm',func('zz_bathroom_voyer_strings'+$lang, 'txt_1')
        //$npc['35,qwOtchim'] += 1
        // makeActBtn(actBath1);
    }
    else if (hour() >= 18 && hour() <= 21 && brother_ev1 != day() && brother_location == "guestroom")
    {
    }
    else
    {
        root->setImage(":/qwest/father/bath_voyer_4.jpg");
        root->setDesc(voyerStr(4));
        makeActBtn(actBath1);
    }
}

int BathRoom::week()
{
    return gTime()->getWeekNum();
}

int BathRoom::hour()
{
    return gTime()->getHour();
}

int BathRoom::minut()
{
    return gTime()->getMin();
}

int BathRoom::day()
{
    return gTime()->getDay();
}
