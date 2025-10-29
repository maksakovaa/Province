#include "locationform.h"
#include "../Functions.h"
#include "sexviewform.h"
#include "ui_locationform.h"
#include "objviewform.h"

BathRoom::BathRoom(LocationForm* ptr): root(ptr)
{
    bath_lock = 0;
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
        root->setImage(":/locations/pavlovo/parents_home/bath4.jpg");
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
            /* code */
        }
        else
        {
            /* code */
        }
        // if $npc['38,qwKolka'] >= 5 and week <= 5 and hour = 6 and cloth[1] = 1 and anus >= 13 and vagina >= 13: gt 'sisterQW','incest_event5sub'
    }

    // act одеться и выйти {}

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
    if (root->getItmCount(razor) > 0)
    {
        root->addDesc(bathStr(15));
    }
    if (root->getItmCount(tampon) > 0)
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
    if(root->getItmCount(tampon) > 0 && root->getVStatus(mesec) > 0 && root->getVStatus(isprok) == 0 && !root->m_settings->isAutoTampon())
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

    if(root->getVBody(legHair) > 0 && root->getItmCount(razor) > 0)
    {
        makeActBtn(actBath11);
    }

    if(root->getVBody(pubisHair) > 0 && root->getItmCount(razor) > 0)
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

    if(root->getItmCount(pregtest) > 0)
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
            if(husband > 0 && husbandday > 0 && husporday != root->m_time->getDay() && poroshok >= 2)
            {
                husband += 5;
                poroshok -= 2;
                husporday = root->m_time->getDay();
                root->addDesc(bathStr(43));
            }
            if(poroshok < 2)
            {
                root->addDesc(bathStr(44));
            }
        }
        if(root->getItmCount(shampoo) > 0)
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
        if(husband >0 && husbandday > 0 && husporday != root->m_time->getDay() && poroshok >=2)
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
        start();
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
        root->m_page->widget(5)->findChild<SexViewForm*>("SexViewForm")->selfPlayStart(root->getCurPtr());
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
        start();
    }
    break;
    
    case actBath6:
    {
        root->useItem(tampon,1);
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
        root->m_player->getCloth(ClothType::Main)->decreaseCondition();
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
        root->useItem(razor, 1);
        emit root->sigUpdParams();
        root->setDesc(bathStr(33));
        root->videoWidg->setQUrl("qrc:/actions/shave/legs.webm");
        root->ui->imageAndWideoWdgt->setCurrentIndex(1);

        makeActBtn(actBath12);
    }
    break;
    
    case actBath12:
    {
        start();
    }
    break;
    
    case actBath13:
    {
        root->incTime(15);
        root->updVBody(pubisHair, -5);
        root->updVStatus(horny, 5);
        root->useItem(razor, 1);
        emit root->sigUpdParams();
        root->videoWidg->setQUrl("qrc:/actions/shave/pubic.webm");
        root->setDesc(bathStr(34));
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
        if (root->m_ccsex->sextToysBlock(2).isEmpty())
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
            root->setDesc(root->m_ccsex->sextToysBlock(2));
        }
        makeActBtn(actBath1);
    }
    break;
    
    case actBath16:
    {
        root->useItem(pregtest,1);
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
        if (root->m_ccsex->sextToysBlock(1).isEmpty())
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
            root->setDesc(root->m_ccsex->sextToysBlock(1));
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
        husporday = root->m_time->getDay();
        root->updVStatus(mood, -25);
        root->setImage(":/actions/bathroom/stir.jpg");
        root->setDesc(bathStr(49));
        makeActBtn(actBath20);
    }
    break;
    
    case actBath20:
    {
        start();
    }
    break;
    
    case actBath21:
    {
        start();
    }
    break;
    
    case actBath22:
    {
        if((backLoc() == "korr" || backLoc() == "skk" || backLoc() == "uni_dorm") && root->getItmCount(Items::shampoo) == 0)
        {
            root->setDesc(bathStr(50));
            makeActBtn(actBath21);
        }
        else
        {
            root->updVStatus(horny, -root->getVStatus(horny)/5);
            root->updVStatus(vaginal_grease, -root->getVStatus(vaginal_grease)/3);
            root->updVStatus(mood, 5);
            root->updVStatus(hygiene, 3);
            root->m_player->redress(new ClothMain(1, ClothType::Main, ClothGroup::towel, "Полотенце"));
            root->setImage(":/actions/bathroom/dush.jpg");
            root->setDesc(bathStr(22));
            makeActBtn(actBath1);
            if(bath_lock == 0 && backLoc() == "parents_home")
            {
                root->addDesc(bathStr(23));
                makeActBtn(actBath26);
            }
        }

    }
    break;
    
    case actBath23:
    {
        root->m_player->redress(new ClothMain(1,ClothType::Main,ClothGroup::towel,"Полотенце"));
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),1);
    }
    break;
    
    case actBath24:
    {
        root->m_player->redress(nullptr);
        root->slotChangeLoc(root->getCurPtr()->getParentPtr(),1);
    }
    break;
    
    case actBath25:
    {
        ObjViewForm* ptr = (ObjViewForm*)root->m_page->widget(4);
        ptr->slotViewObj("mirror");
    }
    break;
    
    case actBath26:
    {
        if(family_trip == 0)
        {
            //gs 'zz_bathroom_voyer','start'
        }
        else
        {
            start();
        }
    }
    break;
    
    case actBath27:
    {
        if(backLoc() == "korr" && root->getItmCount(shampoo) <= 0)
        {
            noShampoo();
        }
        root->incTime(45);
        //if skinday ! daystart: skinday = daystart & gs 'zz_funcs','skin','+',3
        shower();
        root->m_player->redress(nullptr);
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
        start();
    }
    break;
    }
    emit root->sigUpdParams();
}

void BathRoom::makeActBtn(bathActs action)
{
    BathActBtn* btn = new BathActBtn(action, bathActStr(action));
    connect(btn, &BathActBtn::sigAction, this, &BathRoom::slotBathActionHandler);
    root->m_actLayout->addWidget(btn);
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
    str[10] = "Закрыть щеколду на двери";
    str[11] = "Открыть щеколду на двери";
//    str[12] = " щеколду на двери";
    str[13] = "<b>Одеться и выйти</b>";
    str[14] = "<b>Выйти</b>";
    str[15] = "<br>Вашего бритвенного станка хватит ещё на " + intQStr(root->getItmCount(razor)) + " раз.";
    str[16] = "<br>На полке лежит";
    str[17] = "<br>У вас имеется";
    str[18] = " упаковка тампонов. Ее хватит ещё на <b>" + intQStr(root->getItmCount(tampon)) + "</b> раз.";
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
    QString actStr[28];
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
    return actStr[value];
}

TimeServer *BathRoom::gTime()
{
    return root->m_time;
}

QString BathRoom::backLoc()
{
    return root->getCurPtr()->getLocIn();
}

void BathRoom::shower()
{
    root->incTime(15);
    cleanMe();
    if(backLoc() == "korr" && root->getItmCount(shampoo) > 0)
    {
        root->useItem(shampoo, 1);
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

}
