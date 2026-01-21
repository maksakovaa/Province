#include "korrPar.h"
#include "../../menu/buttons.h"
#include "../../npc/npc_enum.h"
#include "../../Functions.h"

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
        int month = getMonth();
        int week = getWeekNum();
        int hour = getHour();
        int sun = getSunWeather();

        if(gNPC(VladimirSkryabin).location != lgargazel)
            startEvent(eFamily, "father_sheduler");
        startEvent(eFamily, "mother_sheduler");
        startEvent(eFamily, "sister_sheduler");
        startEvent(eFamily, "brother_sheduler");

        if(gVQuest(wedding) >= 2 && month >= 5 && month <= 9 && week == 0 && hour == 10 && sun > 0)
            startEvent(eSisterQW,"incest_event12sub");
        if(isNude() && (gNPC(NatalyaLebedeva).location == lbedrpar2 || gNPC(NatalyaLebedeva).location == lkuhrpar || gNPC(NatalyaLebedeva).location == lsitrpar))
        {
            rendNpcProfile(NatalyaLebedeva);
            gNPC(NatalyaLebedeva).relation -= 1;
            setDesc(str(0));
            makeActBtn("bedrPar",act(14));
            return;
        }
        if(week == 0 && hour == 10 && gVQuest(anayslut) == 1 && gVEvent(incest_event14) == 0)
            startEvent(eSisterQW, "incest_event14");
        if(hour != 18 && gVEvent(blockBedrPar) == 1)
            sVEvent(blockBedrPar,0);
        if(gVEvent(blockBedrPar) == 0 && gVEvent(sisBoyDay) + 1 == gVStatus(daystart) && hour == 18 && gVQuest(qwSisterBoy) == 3  || gVQuest(qwSisterBoy) == 5 || gVQuest(qwSisterBoy) == 7 || (gVQuest(qwSisterBoy) == 9 && gVQuest(qwSisterTrio) != 1))
            makeActBtn("sisboyQW_bedroom",act(1));
        else if(gVEvent(blockBedrPar) == 0 && gVEvent(sisBoyDay) + 1 == gVStatus(daystart) && hour == 18 && gVQuest(qwSisterTrio) == 1)
            makeActBtn("sisboytrioQW_bedroom",act(1));
        else if(gVEvent(blockBedrPar) == 0)
            makeActBtn("bedrPar",act(1));
        if(gVEvent(parentSexDay) != getDay())
            makeActBtn("bedrPar2",act(2));
        if(gVEvent(isday_bathroom_peek) != getDay())
        {
            sVEvent(isday_bathroom_peek,getDay());
            sVEvent(rand_bathroom_peek,getRandInt(0,1));
            sVEvent(border_bathroom_peek,1);
        }
        makeActBtn("sitrPar",act(3));
        makeActBtn("bathroom",act(4));
        makeActBtn("kuhrPar",act(5));
        makeActBtn("pod_ezd_etaj2",act(6));
        makeActBtn("pavlovo",act(7));
        rendImagePage();
        setImage("data/locations/pavlovo/parents_home/parents_home.jpg");
        setDesc(str(12));

        if(getClothGroup() == towel && gNPC(KolyaSkryabin).location == lsitrpar && getRandInt(0,5) == 0 && hour >= 20 && hour < 23 && gVEvent(rand_event_day) != getDay())
            startEvent(eShortRandom, "pol_rand1");

        // if palto > 0: gs 'zz_render', '', '', func('korrPar_strings'+$lang, '13')

        if(gVEvent(family_trip) == 0 && ((week > 0 && week < 6) && (hour == 7 || (hour >= 18 && hour <=20))) || ((week == 6 || week == 0) && hour >= 7 && hour <= 20))
        {
            if(gVEvent(gad_punishment) == 1 && gNPC(NatalyaLebedeva).relation < 80)
                startEvent(eGadukinoEvents, "punishment");
            if(gVEvent(gadukino_blok) == 1 && gVQuest(grandmaQW) > 40 && gVQuest(grandpaQW) > 40)
                startEvent(eGadukinoEvents, "absolution");
            if(gVEvent(gadukino_blok) == 1 && gVEvent(gad_offense) == 1)
                startEvent(eGadukinoEvents, "offense");
        }

        if(hour >= 17 && hour <= 20 && gVEvent(family_trip) == 0)
        {
            if(gVSchool(block) < 3)
            {
                if((gVSchool(absent) >= 30 && gVSchool(certificate) == 0) || gVSchool(absentStage) == 3)
                {
                    rendNpcProfile(NatalyaLebedeva);
                    uVSchool(block,1);
                    gNPC(NatalyaLebedeva).relation = 0;
                    uVSkill(domination,-1);
                    sVSchool(absent,0);
                    sVSchool(absentStage,0);
                    setDesc(str(4+gVSchool(block)));
                    if(gVSchool(block) == 3)
                    {
                        sVEvent(ParHomeBlock,1);
                        removeCloth(ClothGroup::schoolUniform);
                        makeActBtn("gorodok",act(14));
                        return;
                    }
                    makeActBtn("korrPar",act(15));
                    return;
                }
            }
        }

        if(gVEvent(worry_check) == 1 && gVEvent(family_trip) == 0)
            startEvent(eDinMother,"worry");

        if(gVEvent(NotAtHomeSleep) > 7 && hour >= 18 && hour <= 20 && gVEvent(family_trip) == 0)
        {
            sVEvent(NotAtHomeSleep,0);
            makeActBtn("korrPar",act(16));
            rendNpcProfile(NatalyaLebedeva);
            if(gNPC(NatalyaLebedeva).relation < 40)
                setDesc(str(8));
            else
                setDesc(str(9));
        }

        // гг слышит странные звуки с комнаты родителей
        if(hour == 21 && week != 1 && gVEvent(father_horny) >= 70 && gVEvent(family_trip) == 0)
        {
            addText(str(10));
        }

        // Брат приниает душ
        if(hour == 17 && getMin() >= 30 && gVEvent(family_trip) == 0 && gVEvent(rand_bathroom_peek) == gVEvent(border_bathroom_peek))
            addText(str(14));
        // Отчим приниает душ
        if(hour == 16 && getMin() >= 30 && gVEvent(family_trip) == 0 && week != 1 && gVEvent(rand_bathroom_peek) == gVEvent(border_bathroom_peek))
            addText(str(15));
        // если ГГ шлюха и она отдавалась уже пацанам в подъезде, то клиенты долбят в дверь:
        if(whoreState() == true)
        {
            startEvent(ePodWhore);
            if(gVQuest(podWhoreCountQW) <= 15)
            {
                if(getRandInt(1,100) <= 5 && hour >= 10 && hour <= 23 && /*func('zz_reputation','get') >= 4 && */ gVQuest(qwPodezdWhore) >= 3)
                    addText(str(16));
            }
        }

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
    str[0] = "Света, ты чего по дому голяком скачешь? Живо оделась!";
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
    str[16] = "<p style=margin-left: 20px;>Кто-то трезвонит вам в дверь: <a href=\"pod_client_talk\">Открыть</a></p>";
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

