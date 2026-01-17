#include "bathroom.h"
#include "../Functions.h"
#include "locationhandler.h"

BathActBtn::BathActBtn(bathActs act, QString actName)
{
    this->setCursor(Qt::PointingHandCursor);
    connect(this, &BathActBtn::clicked, this, &BathActBtn::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void BathActBtn::handleButtonClick()
{
    emit sigAction(m_action);
}

BathRoom::BathRoom(LocationHandler* ptr): Location(ptr)
{
    bath_lock = 0;
    family_trip = 0;
}

void BathRoom::show(QString arg)
{
    no_bath = 0;
    // 	!Брат в душе
//	if (back_loc == "korrParr" && gTime()->getHour() == 17 && gTime()->getMin() >= 30 && family_trip = 0 && rand_bathroom_peek = border_bathroom_peek)
//        peek();
	// !отчим в душе
//    else if (back_loc == "korrParr" && gTime()->getHour() == 16 && gTime()->getMin() >= 30 && family_trip = 0 && gTime()->getWeekNum() != 1 && rand_bathroom_peek = border_bathroom_peek)
//        peek();

// описания
    if (getPrevId() == ltanyaapartment)
    {

    }
//		!Ванная Тани Центр-Сити Point Call = gt 'zz_bathroom','init','tanya_apartment'
//		gs 'zz_render',func('zz_bathroom_strings'+$lang, 'txt_1'),'city/center/tanya/bathroom0.jpg',func('zz_bathroom_strings'+$lang, 'txt_5')
    else if (getPrevId() == lkorrpar || getPrevId() == lshulgahome) //кв.родителей, кв.Шульги
    {
        setImage("data/locations/pavlovo/ghomeyard/podezd/2floor/korrParr/bathroom_parents/bath4.jpg");
        setDesc(bathStr(3));
    }
    else if (getPrevId() == lbandahome) {}
//		!кв. Бандитов-Сити
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'city/north/banda/home/bath.jpg', func('zz_bathroom_strings'+$lang, 'txt_4')
    else if (getPrevId() == lalbinaev) {}
//		!кв. Альбины Барловской
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath7.jpg', func('zz_bathroom_strings'+$lang, 'txt_5')
    else if (getPrevId() == lmeyhome) {}
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath5', func('zz_bathroom_strings'+$lang, 'txt_6')
    else if (getPrevId() == lstwork || getPrevId() == lskk) {}
//		! стрипклуб Центр и СКК
//		no_bath = 1
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_2'),'common/interior/bathroom/bath6', func('zz_bathroom_strings'+$lang, 'txt_7')
    else if (getPrevId() == lkorr) {}
//		! квартира Южн.рн.
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_1') ,'common/interior/bathroom/bath'+iif(my_house = 1,'',remvanr)+'.jpg',iif(remvanr = 0 and my_house = 2, func('zz_bathroom_strings'+$lang, 'txt_8'), '')
    else if (getPrevId() == lunidorm) {}
//		no_bath = 1
//		gs 'zz_render', func('zz_bathroom_strings'+$lang, 'txt_2'),'city/center/university/dorm/interiors/bath',func('zz_bathroom_strings'+$lang, 'txt_9')
    else if (getPrevId() == lgadbana) {}
//		gt 'Gadbana'

    if (gVStatus(bawdy_body) != 0)
    {
        makeActBtn(actBath28);
    }
    //	gs 'zz_render', '', '', func('zz_bathroom_strings'+$lang, 'txt_51') ???
//Задвижка
    if (getPrevId() == lkorrpar)
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

    if(isNude() || getClothGroup() == 1)
    {
        makeActBtn(actBath31);
    }
    else
    {
        makeActBtn(actBath32);
    }

    if (getPrevId() == lkorrpar)
    {
        if (gVStatus(shamelessFlag) >= 1)
        {
            makeActBtn(actBath23);
        }
        if (gVStatus(shamelessFlag) >= 2)
        {
            makeActBtn(actBath24);
        }
    }
    if (getItemCount(iRazor) > 0)
    {
        addText(bathStr(15));
    }
    if (getItemCount(iTampon) > 0)
    {
        if (no_bath == 0)
        {
            addText(bathStr(16));
        }
        else
        {
            addText(bathStr(17));
        }
        addText(bathStr(18));
    }
    else
    {
        addText(bathStr(19));
    }
    if (getPrevId() == lkorr && my_house == 2 && remvanr == 0)
    {
        addText(bathStr(20));
    }
    else
    {
        addText(bathStr(21));
        makeActBtn(actBath25);
    }
    int bad_vanr;
    if (getPrevId() == lkorr && remvanr == 0 && my_house == 2) bad_vanr = 1;
    else bad_vanr = 0;

    if(bad_vanr == 0 || getPrevId() != lkorr)
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
    if(getItemCount(iTampon) > 0 && gVStatus(mesec) > 0 && gVStatus(isprok) == 0 && !isAutoTampon())
    {
        makeActBtn(actBath6);
    }

    if(gVStatus(cumPussy) > 0 || gVStatus(cumBelly) > 0 || gVStatus(cumAss) > 0 || gVStatus(cumAnus) > 0)
    {
        makeActBtn(actBath7);
    }

    if(gVStatus(cumLips) > 0 || gVStatus(cumFace) > 0)
    {
        makeActBtn(actBath8);
    }

    if(gVBody(makeup) != 1)
    {
        makeActBtn(actBath9);
    }

    if(gVStatus(cumFrot) > 0)
    {
        makeActBtn(actBath10);
    }

    if(gVBody(legHair) > 0 && getItemCount(iRazor) > 0)
    {
        makeActBtn(actBath11);
    }

    if(gVBody(pubisHair) > 0 && getItemCount(iRazor) > 0)
    {
        makeActBtn(actBath13);
    }

    if(getItemCount(iAnalPlug) > 0)
    {
        if(gVSex(analplugIN) == 1)
            makeActBtn(actBath14);
        else
            makeActBtn(actBath15);
    }

    if(getItemCount(iPregtest) > 0)
    {
        makeActBtn(actBath16);
    }

    if(getItemCount(iVibrator) > 0)
    {
        if(gVSex(vibratorIN) == 0)
            makeActBtn(actBath17);
        else
            makeActBtn(actBath18);
    }

    if(getPrevId() == lkorr)
    {
        if(stiralka > 0 || my_house == 1)
        {
            if(husband > 0 && husbandday > 0 && husporday != getDay() && poroshok >= 2)
            {
                husband += 5;
                poroshok -= 2;
                husporday = getDay();
                addText(bathStr(43));
            }
            if(poroshok < 2)
            {
                addText(bathStr(44));
            }
        }
        if(getItemCount(iShampoo) > 0)
        {
            addText(bathStr(45));
        }
        else
        {
            addText(bathStr(46));
        }
        if(poroshok > 0)
        {
            addText(bathStr(47));
        }
        if(stiralka > 0)
        {
            addText(bathStr(48));
        }
        if(husband > 0 && husbandday > 0 && husporday != getDay() && poroshok >= 2)
        {
            makeActBtn(actBath19);
        }
    }
}

LocId BathRoom::getLocId()
{
    return lbathroom;
}

void BathRoom::slotBathActionHandler(bathActs action)
{
    clearActions();

    switch (action)
    {
    case actBath1:
    {
        show();
    }
    break;

    case actBath2:
    {
        if(gVStatus(horny) >= 90)
        {
            sVStatus(lust,0);
            sVStatus(horny,0);
            incTime(10);
            uVSC(masturbation,1);
            uVSC(orgasm,1);
            uVStatus(mood,15);
            setImage("data/actions/bathroom/wash7.jpg");
            setDesc(bathStr(25));
            makeActBtn(actBath1);
        }
        if(gVStatus(horny) >= 40 && gVStatus(horny) < 90)
        {
            uVStatus(horny,5);
            incTime(10);
            uVStatus(mood,10);
            setImage("data/actions/bathroom/wash8.jpg");
            setDesc(bathStr(26));
            makeActBtn(actBath1);
        }
    }
    break;
    
    case actBath3:
    {
        startSelfPlay();
    }
    break;
    
    case actBath4:
    {
        incTime(5);
        sVBody(makeup,1);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        uVStatus(sweat, -1);
        setImage("data/actions/bathroom/facesp.jpg");
        setDesc(bathStr(27));
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
        useItem(iTampon,1);
        sVStatus(isprok,1);
        incTime(5);
        uVStatus(mood, -5);
        setImage("data/actions/bathroom/tampon.jpg");
        setDesc(bathStr(29));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath7:
    {
        sVStatus(cumPussy,0);
        sVStatus(cumBelly,0);
        sVStatus(cumAss,0);
        sVStatus(cumAnus,0);
        uVStatus(sweat, -1);
        incTime(5);
        setImage("data/actions/bathroom/wash" + intQStr(getRandInt(5,6)) + ".jpg");
        setDesc(bathStr(28));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath8:
    {
        sVBody(makeup, 1);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        uVStatus(sweat, -1);
        incTime(5);
        setImage("data/actions/bathroom/facesp.jpg");
        setDesc(bathStr(30));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath9:
    {
        sVBody(makeup,1);
        incTime(15);
        setImage("data/actions/bathroom/facesp.jpg");
        setDesc(bathStr(31));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath10:
    {
        sVStatus(cumFrot,0);
        getCloth(ClothType::Main)->decreaseCondition();
        incTime(15);
        setImage("data/actions/bathroom/frotsp" + intQStr(getRandInt(0,6)) + ".jpg");
        setDesc(bathStr(32));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath11:
    {
        incTime(15);
        uVBody(legHair, -5);
        uVStatus(horny, 5);
        useItem(iRazor, 1);
        updateParams();
        rendVideoPage();
        setDesc(bathStr(33));
        setVideo("data/actions/bathroom/legs.webm",900,508);
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
        incTime(15);
        uVBody(pubisHair, -5);
        uVStatus(horny, 5);
        useItem(iRazor, 1);
        updateParams();
        rendVideoPage();
        setVideo("data/actions/bathroom/pubic.webm",900,448);
        setDesc(bathStr(34));
        makeActBtn(actBath12);
    }
    break;
    
    case actBath14:
    {
        incTime(1);
        sVSex(analplugIN,0);
        setImage("data/sex/toys/analplug.jpg");
        if (gVBody(anus) >= 5)
        {
            setDesc(bathStr(35));
        }
        else
        {
            setDesc(bathStr(36));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath15:
    {
        incTime(5);

        if (sextToysBlock(2).isEmpty())
        {
            sVSex(analplugIN, 1);
            if (gVBody(anus) < 10)
            {
                uVBody(anus, 1);
            }
            setImage("data/sex/toys/analplug.jpg");
            if (gVBody(anus) >= 5)
            {
                setDesc(bathStr(37));
            }
            else
            {
                setDesc(bathStr(38));
            }
        }
        else
        {
            setImage("data/sex/toys/no_anus.jpg");
            setDesc(sextToysBlock(2));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath16:
    {
        useItem(iPregtest,1);
        if(gVStatus(pregnancy) > 0)
        {
            sVStatus(pregnancyKnow,1);
            setDesc(bathStr(39));
        }
        else
        {
            setDesc(bathStr(40));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath17:
    {
        incTime(5);
        if (sextToysBlock(1).isEmpty())
        {
            sVSex(vibratorIN, 1);
            if (gVBody(vagina) < 6)
            {
                uVBody(vagina, 1);
            }
            setImage("data/sex/toys/vibrator" + intQStr(getRandInt(0, 1)) + ".jpg");
            setDesc(bathStr(41));
        }
        else
        {
            setImage("data/sex/toys/no_pussy.jpg");
            setDesc(sextToysBlock(1));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath18:
    {
        incTime(2);
        sVSex(vibratorIN, 0);
        setImage("data/sex/toys/vibrator" + intQStr(getRandInt(0, 1)) + ".jpg");
        setDesc(bathStr(42));
        makeActBtn(actBath1);
    }
    break;
    
    case actBath19:
    {
        husband += 5;
        poroshok -= 2;
        incTime(60);
        husporday = getDay();
        uVStatus(mood, -25);
        setImage("data/actions/bathroom/stir.jpg");
        setDesc(bathStr(49));
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
        if((getPrevId() == lkorr || getPrevId() == lskk || getPrevId() == lunidorm) && getItemCount(iShampoo) == 0)
        {
            noShampoo();
        }
        else
        {
            uVStatus(horny, -gVStatus(horny)/5);
            uVStatus(vaginal_grease, -gVStatus(vaginal_grease)/3);
            uVStatus(mood, 5);
            uVStatus(hygiene, 3);
            shower();
            redress(ClothType::Main, new ClothMain(1, ClothGroup::towel, "Полотенце"));
            setImage("data/actions/bathroom/dush.jpg");
            setDesc(bathStr(22));
            if(bath_lock == 0 && getPrevId() == lkorrpar)
            {
                addText("<br>" + bathStr(23));
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
        redress(ClothType::Main, new ClothMain(1,ClothGroup::towel,"Полотенце"));
        changeLoc(getParId(),1);
    }
    break;
    
    case actBath24:
    {
        redress(ClothType::Main,nullptr);
        changeLoc(getParId(),1);
    }
    break;
    
    case actBath25:
    {
        viewObj("mirror");
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
            show();
        }
    }
    break;
    
    case actBath27:
    {
        if(getParId() == lkorr && getItemCount(iShampoo) <= 0)
        {
            noShampoo();
        }
        incTime(45);
        if(skinday != gVStatus(daystart))
        {
            skinday = gVStatus(daystart);
            updSkin('+', 3);
        }
        shower();
        redress(ClothType::Main,nullptr);
        uVStatus(horny, -gVStatus(horny)/4);
        uVStatus(vaginal_grease, -gVStatus(vaginal_grease)/2);
        uVStatus(hygiene,15);
        setImage("data/actions/bathroom/wash4.jpg");
        setDesc(bathStr(24));
        makeActBtn(actBath1);
        if(gVStatus(horny) >= 40)
        {
            makeActBtn(actBath2);
        }
        if(gVStatus(horny) >= 50)
        {
            makeActBtn(actBath3);
        }
    }
    break;
    
    case actBath28:
    {
        incTime(10);
        sVStatus(bawdy_body, 0);
        show();
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
        redressOld();
        slotBathActionHandler(actBath32);
    }
    break;

    case actBath32:
    {
        if(bath_lock == 1) bath_lock = 0;
        changeLoc(getParId(),1);
    }
    break;
    }
    updateParams();
}

LocId BathRoom::getParId()
{
    return getPrevId();
}

LocId BathRoom::getLocIn()
{
    return getPrevIn();
}

QString BathRoom::getLocName()
{
    return "Ванная";
}

bool BathRoom::isParent()
{
    return true;
}

void BathRoom::slotPeekActHandler(peekActs action)
{
    switch (action)
    {
    case actPeek1:
    {
        changeLoc(getParId(),0);
    }
        break;
    case actPeek2:
    {
        if (gVSC(peek1day) == 1)
        {
            setImage("data/qwest/brotherpeek/brotherpeek2.jpg");
            setDesc(peekStr(2));
            makePeekActBtn(actPeek1);
        }
        else if (gVStatus(shamelessFlag) == 0 && peek1day == 0)
        {
            incTime(getRandInt(2,4));
            setImage("data/qwest/brotherpeek/brotherpeek1.jpg");
            setDesc(peekStr(1));
            makePeekActBtn(actPeek5);
        }
        else if (brotherpeekstage >= 5 && brotherpeekhelp <= 5 && peek1day == 0 && gVStatus(shamelessFlag) > 0 && npc_39relation > 60)
        {
            incTime(getRandInt(2,4));
            setImage("data/qwest/brotherpeek/brotherpeek3.jpg");
            setDesc(peekStr(6));
            makePeekActBtn(actPeek3);
            makePeekActBtn(actPeek7);
        }
    }
        break;
    case actPeek3:
    {
        incTime(getRandInt(2,4));
        uVStatus(mood,5);
        setImage("data/qwest/brotherpeek/brotherpeek7.jpg");
        setDesc(peekStr(3));
        if (gVStatus(shamelessFlag) > 1)
        {
            makePeekActBtn(actPeek4); //brother_jerk
        }
        makePeekActBtn(actPeek8);
    }
        break;
    case actPeek4:
    {
        incTime(getRandInt(2,4));
        setImage("data/qwest/brotherpeek/brotherpeek6.jpg");
        setDesc(peekStr(8));
        makePeekActBtn(actPeek9);
    }
        break;
    case actPeek5:
    {
        incTime(getRandInt(2,4));
        setImage("data/qwest/brotherpeek/brotherpeek5.jpg");
        setDesc(peekStr(7));
        brotherpeekstage += 1;
        uVSC(peek1day, 1);
        uVStatus(horny, getRandInt(10,15));
        makePeekActBtn(actPeek6);
    }
        break;
    case actPeek6:
    {
        incTime(getRandInt(2,4));
        slotPeekActHandler(actPeek1);
    }
        break;
    case actPeek7:
    {
        brotherpeekstage +=1;
        uVSC(peek1day, 1);
        uVStatus(horny, getRandInt(5,10));
        uVSC(voyeurism,1);
        slotPeekActHandler(actPeek1);
    }
        break;
    case actPeek8:
    {
        incTime(getRandInt(2,4));
        setImage("data/qwest/brotherpeek/brotherpeek4.jpg");
        setDesc(peekStr(5));
        makePeekActBtn(actPeek7);
    }
        break;
    case actPeek9:
    {
        incTime(getRandInt(2,4));
        uVStatus(mood, -5);
        setImage("data/qwest/brotherpeek/brotherpeek8.jpg");
        setDesc(peekStr(9));
        makePeekActBtn(actPeek10);
    }
        break;
    case actPeek10:
    {
        incTime(getRandInt(5,10));
        uVStatus(mood, -5);
        setImage("data/qwest/brotherpeek/brotherpeek4.jpg");
        setDesc(peekStr(10));
        makePeekActBtn(actPeek11);
    }
    break;

    case actPeek11:
    {
        brotherpeekstage +=1;
        uVSC(peek1day, 1);
        uVStatus(horny, getRandInt(20,30));
        slotPeekActHandler(actPeek1);
    }
        break;
    }
    updateParams();
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
    updateParams();
}

void BathRoom::actionHandler(QString action)
{

}

void BathRoom::peek()
{
    setImage("data/qwest/brotherpeek/brotherpeek0.jpg");
    setDesc(peekStr(0));
    if(getParId() == lkorrpar)
    {
        makePeekActBtn(actPeek1);
    }
    if(family_trip == 0 && getHour() == 17 && getMin() >= 30)
        makePeekActBtn(actPeek2);
    
}

void BathRoom::makeActBtn(bathActs action)
{
    BathActBtn* btn = new BathActBtn(action, bathActStr(action));
    connect(btn, &BathActBtn::sigAction, this, &BathRoom::slotBathActionHandler);
    addActBtn(btn);
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
    str[15] = "Вашего бритвенного станка хватит ещё на " + intQStr(getItemCount(iRazor)) + " раз.";
    str[16] = "На полке лежит";
    str[17] = "У вас имеется";
    str[18] = " упаковка тампонов. Ее хватит ещё на <b>" + intQStr(getItemCount(iTampon)) + "</b> раз.";
    str[19] = "У вас нет тампонов.";
    str[20] = "Судя по оставшемуся контуру, на этом месте висело зеркало.";
    str[21] = "Над раковиной висит зеркало.";
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
             "<span class=\"npc_dialogue\">- Ффух</span> - он устало выдыхает, вытирая пот со лба:<br>"
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

void BathRoom::shower()
{
    incTime(15);
    cleanMe();
    if(getParId() == lkorr && getItemCount(iShampoo) > 0)
    {
        useItem(iShampoo, 1);
    }
}

void BathRoom::cleanMe()
{
    sVStatus(cumPussy, 0);
    sVStatus(cumBelly, 0);
    sVStatus(cumAss, 0);
    sVStatus(cumAnus, 0);
    sVStatus(cumLips, 0);
    sVStatus(cumFace, 0);
    sVStatus(cumFrot, 0);
    sVStatus(sweat, 0);
    sVBody(makeup, 1);
    sVBody(hairStatus,0);
    uVStatus(horny, -gVStatus(horny)/5);
    uVStatus(vaginal_grease, -gVStatus(vaginal_grease)/3);
}

void BathRoom::noShampoo()
{
    setDesc(bathStr(50));
    makeActBtn(actBath21);
}

void BathRoom::voyer()
{
    father_dadqw_day = getDay();
    brother_ev1 = getDay();
    int week = getWeekNum();
    int hour = getHour();
    if (
        (((week == 0 || week == 6) && hour >= 7 && hour <= 17) || (week > 1 && week < 6 && (hour == 7 || hour == 17))) && father_dadqw_day != getDay())
    {
        father_dadqw_day = getDay();
        // if $npc['35,relation'] < 60 or $npc['35,qwOtchim'] < 3:
        // gs 'zz_render','','qwest/alter/father/bath_voyer_0.webm',func('zz_bathroom_voyer_strings'+$lang, 'txt_1')
        //$npc['35,qwOtchim'] += 1
        // makeActBtn(actBath1);
    }
    else if (hour >= 18 && hour <= 21 && brother_ev1 != getDay() && brother_location == "guestroom")
    {
    }
    else
    {
        setImage("data/qwest/father/bath_voyer_4.jpg");
        setDesc(voyerStr(4));
        makeActBtn(actBath1);
    }
}
