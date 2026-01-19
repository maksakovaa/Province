#include "korrPar.h"
#include "../../menu/buttons.h"
korrPar::korrPar(LocationHandler *ptr): Location(ptr){}

void korrPar::show(QString arg)
{
    actionHandler("korrPar");
}

LocId korrPar::getLocId()
{
    return lkorrpar;
}

LocId korrPar::getParId()
{
    return lpodezd;
}

LocId korrPar::getLocIn()
{
    return lgorodok;
}

QString korrPar::getLocName()
{
    return "Квартира родителей";
}

bool korrPar::isParent()
{
    return true;
}

void korrPar::actionHandler(QString action)
{
    if(action == "korrPar")
    {
        //popolaini = 0
        sVStatus(frost, 0);
        incTime(1);

        //if father['in_garage'] = 0: gs 'zz_family', 'father_sheduler'
        //gs 'zz_family', 'mother_sheduler'
        //gs 'zz_family', 'sister_sheduler'
        //gs 'zz_family', 'brother_sheduler'
        //if $npc['38,wedding'] >= 2 and month >= 5 and month <= 9 and week = 7 and hour = 10 and sunWeather > 0: gt 'sisterQW','incest_event12sub'
        // if cloth[0] = 0 and $mother['at_home'] = 1:
        //  *clr & cla
        //  gs 'npc_editor','get_npc_profile',37
        //  $npc['37,relation'] -= 1
        //  gs 'zz_render', '', '', func('korrPar_strings'+$lang, '16')
        //  act func('korrPar_strings'+$lang, 'act14'): gt 'bedrPar'
        //  exit
        //  end
        // if week = 7 and hour = 10 and $npc['38,anayslut'] = 1 and $npc['38,incest_event14'] = 0: gt 'sisterQW','incest_event14'
        //  if hour ! 18 and blockBedrPar = 1: blockBedrPar = 0
        //  if blockBedrPar = 0 and sisboyday + 1 = daystart and hour = 18 and ($npc['38,qwSisterBoy'] = 3 or $npc['38,qwSisterBoy'] = 5 or $npc['38,qwSisterBoy'] = 7 or ($npc['38,qwSisterBoy'] = 9 and $npc['38,qwSisterTrio'] ! 1)):
        //   act func('korrPar_strings'+$lang, 'act1'): gt 'sisterQW','sisboyQW_bedroom'
        //  elseif blockBedrPar = 0 and sisboyday + 1 = daystart and hour = 18 and $npc['38,qwSisterTrio'] = 1:
        //    act func('korrPar_strings'+$lang, 'act1'): gt 'sisterQW','sisboytrioQW_bedroom'
        // elseif blockBedrPar = 0:
        makeActBtn("bedrPar",act(1));
        //if parentsexday ! day: act func('korrPar_strings'+$lang, 'act2'): gt 'bedrPar2','main'
        //if isday_bathroom_peek ! day: isday_bathroom_peek = day & rand_bathroom_peek = rand(0,1) & border_bathroom_peek = 1
        makeActBtn("sitrPar",act(3));
        makeActBtn("bathroom",act(4));
        makeActBtn("kuhrPar",act(5));
        makeActBtn("pod_ezd_etaj2",act(6));
        makeActBtn("pavlovo",act(7));
        rendImagePage();
        setImage("data/locations/pavlovo/parents_home/parents_home.jpg");
        setDesc(str(12));
        // if cloth[0] = 1 and $brother['location'] = 'sitrPar' and RAND(0,5) = 0 and hour >= 20 and hour < 23 and $npc['39,rand_event_day']!day: gt 'short_random','pol_rand1'
        // !конец коротких ивентов
        // if palto > 0: gs 'zz_render', '', '', func('korrPar_strings'+$lang, '13')
        // if family_trip = 0 and (week < 6 and (hour = 7 or hour >= 18 and hour <= 20) or week >= 6 and hour >= 7 and hour <= 20):
        // if gad_punishment = 1 and $npc['37,relation'] < 80:gt 'gadukino_event', 'punishment'
        // if gadukino_blok = 1 and grandmaQW > 40 and grandpaQW > 40: gt 'gadukino_event', 'absolution'
        // if gadukino_blok = 1 and gad_offense = 1:gt 'gadukino_event', 'offense'
        // end
        // if hour >= 17 and hour <= 20 and family_trip = 0:
        //  if school['block'] < 3:
        //    if (school['absent'] >= 30 and school['certificate'] = 0) or absent['stage'] = 3:
        //       *clr & cla
        //       gs 'npc_editor','get_npc_profile',37
        //       school['block'] += 1
        //       $npc['37,relation'] = 0
        //       dom -= 1
        //       school['absent'] = 0
        //       absent['stage'] = 0
        //       gs 'zz_render', '', '', func('korrPar_strings'+$lang, '<<(4+school[''block''])>>')
        //       if school['block'] = 3:
        //          ParHomeBlock = 1
        //          gs 'zz_clothing2','remove_at',4
        //          act func('korrPar_strings'+$lang, 'act14'): gt 'gorodok'
        //          exit
        //       end
        //    act func('korrPar_strings'+$lang, 'act15'): gt $curloc
        //    exit
        //    end
        //  end
        //end
        //if $npc['37,worry_check'] = 1 and family_trip = 0:gs 'dinmother', 'worry'
        //if notathomesleep > 7 and hour >= 18 and hour <= 20 and family_trip = 0:
        //notathomesleep = 0
        //*clr & cla
        //act func('korrPar_strings'+$lang, 'act16'): gt 'korrPar'
        //gs 'zz_render', '', 'images/common/npc/37.jpg', func('korrPar_strings'+$lang, iif($npc['37,relation'] < 40,'8','9'))
        //end
        // !---
        // ! гг слышит странные звуки с комнаты родителей
        // if hour = 21 and week ! 1 and father['horny'] >= 70 and family_trip = 0:
        //  gs 'zz_render', '', '', func('korrPar_strings'+$lang, '10')
        // end
        // Брат приниает душ
        // if hour = 17 and minut >= 30 and family_trip = 0 and rand_bathroom_peek = border_bathroom_peek:
        //  !images\pavlovo\family\apartment\elsa_jean_01.jpg
        // gs 'zz_render', '', '', func('korrPar_strings'+$lang, '14')
        // end
        // !Отчим приниает душ
        // if hour = 16 and minut >= 30 and family_trip = 0 and week <> 1 and rand_bathroom_peek = border_bathroom_peek:
        //  gs 'zz_render', '', '', func('korrPar_strings'+$lang, '15')
        //  end
        // !------------------------------------------!
        // !если ГГ шлюха и она отдавалась уже пацанам в подъезде, то клиенты долбят в дверь: !
        // if set_prostitute = ON_prostitute:
        // gs 'pod_whore'
        // $_visit_to_slut = '<p style="margin-left: 20px;"><font size="5">Кто-то трезвонит вам в дверь: <a href="exec: dynamic $pod_client_talk">Открыть</a></font></p>'
        // if RAND(1,100) <= iif(pod_whore_countQW <= 15,5,20) and hour >= 10 and hour <= 23 and func('zz_reputation','get') >= 4 and $npc['0,qwPodezdWhore'] >=3: $_visit_to_slut
        // killvar '$_visit_to_slut'
        // end
        // !==========================================!
        // !------------ Входящие звонки ------------
        // gs 'zz_phone', 'boyfriend_call_init'
        // if Gcall = 1 : exit
        // gs 'zz_phone','oilers_call_init'
        // if Gcall = 1 : exit
    }
}

void korrPar::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "korrparr");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &korrPar::actionHandler);
    addActBtn(btn);
}

QString korrPar::str(int id)
{
    QString add1;
    if(gVEvent(mother_spanking) == 0)
        add1 = "Я никогда не порола тебя, да, видать, напрасно...";
    else
        add1 = "Похоже, предыдущая порка тебя ничему не научила.";
    QString str[17];
    str[1] = "Мама упёрла руки в боки.<br> - Мне тут подкинули видео с тобой. " + add1 + " Ты понимаешь, что возможно это видео есть не только у меня? Что о тебе теперь будут говорить?! Да что о тебе - о всей нашей семье! Нужно преподать тебе урок. Володя!";
    str[2] = "Вы разревелись:<br> - Мамочка, ну мам! Прости! Это никогда не повторится! Я дура, что допустила это! Я больше никогда, никогда...<br>Вы рыдаете и становитесь на колени. Мать смотрит на вас, качает головой и молча уходит.";
    str[3] = "Вы стоите уставившись в пол. А что тут можно сказать?<br>Мать берёт вас за руку и ведет в комнату:<br> - Снимай трусы и нагнись!<br>Вы отрицательно качаете головой.<br> - Володя – держи ее!<br>Отчим хватает вас и держит. Мать стягивает с вас нижнее белье, берёт ремень, и начинает охаживать им вас по голой заднице. Сжав зубы, вы выдерживаете экзекуцию, не проронив ни звука. Подняв голову, вы видите, как через незакрытую дверь за всем этим наблюдают ваши брат и сестра.";
    str[4] = " - Ну давай-давай - зови отца! Я расскажу - какая у него дочь! И в кого пошла!<br>Мать смотрит на вас, и, плюнув в пол, уходит.";
    str[5] = "В коридоре вас встречает мать. С порога она принимается метать громы и молнии.<br>- Звонили из школы! У тебя сплошные прогулы! На первый раз тебя простили, но в следующий тебя точно выгонят. Ты что творишь, балбеска!? - Мать в гневе ушла в комнату.";
    str[6] = "В коридоре вас встречает мать. С порога она мечет громы и молнии.<br>- Звонили из школы. У тебя опять прогулы. Тебя хотели уже исключить из школы, я буквально на коленях умоляла директора не исключать тебя и дать тебе последний шанс исправиться. Больше я из-за тебя унижаться не буду, так и запомни! В следующий раз ты вылетишь из школы! И если ты вылетишь из школы, я тебя лично из дома вышвырну. Если ты не понимаешь нормального отношения - тогда проваливай и живи своим умом, которого у тебя нет, никто тебя тут не держит!<br> Мать в гневе ушла в комнату.";
    str[7] = "В коридоре вас встречает мать. Её выражение лица обещает громы и молнии.<br>- Что, допрыгалась? Тебя выгнали из школы. Всё, сил моих больше нет! И у отца терпения тоже не осталось. Живи теперь сама как хочешь! - Мать собрала ваши вещи в сумку, сунула вам сумку в руки и за шкирку выкинула из квартиры. - Сюда не смей возвращаться - и она захлопнула дверь.";
    str[8] = "В коридоре вы натыкаетесь на мать: - Смотрите, кто явился. Надолго?";
    str[9] = "В коридоре вы натыкаетесь на мать: - Вот это сюрприз! Моя доча приехала! Я так соскучилась!";
    str[10] = "Из комнаты родителей доносятся странные звуки. Надо бы расследовать...";
    str[11] = "<red>ВАМ НАДО ОДЕТЬСЯ.</red>";
    str[12] = "На стене возле входной двери висит <a href='mirror'>зеркало</a>.";
    str[13] = "На крючке висит <<$palto>>";
    str[14] = "Из ванной слышен шум воды: Колька принимает душ после футбола.";
    str[15] = "Из ванной слышен шум воды: отчим принимает душ.";
    str[16] = "Света, ты чего по дому голяком скачешь? Живо оделась!";
    return str[id];
}

QString korrPar::act(int id)
{
    QString act[17];
    act[1] = "<B>Ваша комната</B>";
    act[2] = "В комнату родителей";
    act[3] = "В зал";
    act[4] = "В ванную";
    act[5] = "В кухню";
    act[6] = "<B>Выйти на лестничную клетку</B>";
    act[7] = "<font color = maroon>Идти на улицу</font>";
    act[8] = "Коридор";
    act[9] = "Умолять ничего не делать";
    act[10] = "Молчать";
    act[11] = "Отойти";
    act[12] = "Угрожать";
    act[13] = "Отойти";
    act[14] = "Уйти";
    act[15] = "Отойти";
    act[16] = "<B>Отойти</B>";
    return act[id];
}

