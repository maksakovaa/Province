#include "common.h"
#include "../nav/locationhandler.h"
#include "../Functions.h"
#include "../menu/qactbutton.h"

Common::Common(LocationHandler* ptr): root(ptr) {}

void Common::icecream()
{
    root->m_render->rendImagePage(root);
    root->m_render->setImage(media(1));
    root->m_render->setText(str(1));
    makeActBtn("go_back", act(1));
    if(root->getVStatus(money) >= 50)
    {
        makeActBtn("eat_icecream", act(2));
    }
}

void Common::coffee()
{
    root->m_render->rendImagePage(root);
    makeActBtn("go_back",act(1));
    root->setImage(media(2));
    QString table = "<table>";
    table += "<th>" + str(9) + "</th>";
    table += "<tr><td>" + str(3) + "</td><td><a href='coffee0'>" + intQStr(30) + "</a></td>";
    table += "<tr><td>" + str(4) + "</td><td><a href='coffee1'>" + intQStr(30) + "</a></td>";
    table += "<tr><td>" + str(5) + "</td><td><a href='coffee2'>" + intQStr(30) + "</a></td>";
    table += "<tr><td>" + str(6) + "</td><td><a href='coffee3'>" + intQStr(40) + "</a></td>";
    table += "<tr><td>" + str(7) + "</td><td><a href='coffee4'>" + intQStr(50) + "</a></td>";
    table += "<tr><td>" + str(8) + "</td><td><a href='coffee5'>" + intQStr(50) + "</a></td>";
    table += "</table>";
    root->setDesc(table);
    connect(root->m_render->getTextPtr(), &QLabel::linkActivated, this, &Common::select_coffee);
}

void Common::go_back()
{
    watch_tv_count = 0;
    root->slotChangeLoc(root->getCurLoc(),0);
}

void Common::read_porn()
{
    makeActBtn("read_porn",act(3));
}

void Common::crossing(int arg)
{
    root->m_render->rendImagePage(root);
    if(root->getVJob(workout) > 1)
    {
        root->setImage(media(3));
        root->setDesc(str(66));
        return;
    }

    //! ограничения по наркоте
    //if func('zz_drugs','block') = 1: gs 'zz_render','','', func('zz_common_strings'+$lang, 'txt_15') & exit
    //! ограничения по алкоголю
    //if func('cc_alco','alkoblock') ! 0: gs 'zz_render','','', func('zz_common_strings'+$lang, 'txt_6' + func('cc_alco','alkoblock')) & exit

    if(arg == 1)
        root->updVJob(workout,1);
    else
        root->updVStatus(sport,1);
    root->updVStatus(day_weight,-1);
    root->updVSkill(runner, getRandInt(2,5)*arg);
    root->updVSkill(speed, getRandInt(1,2)*arg);
    root->incTime(30);

    fnsport(arg*4);

    root->decreaseCondition(getClothDecreaseLevel());
    if(arg == 1)
    {
        if(root->getSnow() <= 0)
            root->setImage(media(4));
        else
            root->setImage(media(5));
        root->setDesc(str(16));
    }
    else
    {
        if(root->getSnow() <= 0)
            root->setImage(media(6));
        else
            root->setImage(media(7));
        root->setDesc(str(17));
    }
}

void Common::home_workout()
{
    connect(root->m_render->getTextPtr(), &QLabel::linkActivated, this, &Common::actionHandler);

    // ! ограничения по наркоте
    //     if func('zz_drugs','block') = 1: gs 'zz_render','','',func('zz_common_strings'+$lang, 'txt_15') & exit
    // ! ограничения по алкоголю
    //     if func('cc_alco','alkoblock') ! 0: gs 'zz_render','','', func('zz_common_strings'+$lang, 'txt_6' + func('cc_alco','alkoblock')) & exit

    QString res;
    if(root->getItmCount(iHoop) > 0)
        res += "<a href='sitrobrd'>" + str(18) + "</a>";
    if(root->getItmCount(iJumpRope) > 0)
        res += "<a href='sitrskakd'>" + str(19) + "<a>";
    res += "<a href='sitrpressd'>" + str(20) + "</a>";
    res += "<a href='sitrpushd'>" + str(21) + "</a>";
    if(root->getVJob(workout) < 2)
        root->addDesc(str(22) + res);
}

void Common::lokerchoice()
{
    root->m_render->rendImagePage(root);
    root->setImage(media(8));
    root->setDesc(str(23));
    root->incTime(5);
    makeActBtn("wardrobe_start", act(0));
}

void Common::sitrobrd()
{
    check_sport_suit();
    root->m_render->rendVideoPage(root);
    root->incTime(15);
    root->updVJob(workout,1);
    int tmp = upSportSkill(root->getVSkill(agility));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->updVSkill(agility, tmp);
    }
    fnsport();
    root->m_render->setVideo(media(9),960,540);
    root->setDesc(str(24));
    makeActBtn("go_back", act(4));
}

void Common::sitrskakd()
{
    check_sport_suit();
    root->m_render->rendImagePage(root);
    root->incTime(15);
    root->updVJob(workout,1);
    int tmp = upSportSkill(root->getVSkill(speed));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->updVSkill(speed, tmp);
    }

    fnsport();
    root->setImage(media(10));
    root->setDesc(str(25));
    makeActBtn("go_back", act(4));
}

void Common::sitrpressd()
{
    check_sport_suit();
    root->m_render->rendImagePage(root);
    root->incTime(15);
    root->updVJob(workout,1);
    int tmp = upSportSkill(root->getVSkill(endurance));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->updVSkill(endurance, tmp);
    }
    fnsport();
    root->setImage(media(11));
    root->setDesc(str(26));
    makeActBtn("go_back",act(4));
}

void Common::sitrpushd()
{
    check_sport_suit();
    root->m_render->rendImagePage(root);
    root->incTime(15);
    root->updVJob(workout,1);
    int tmp = upSportSkill(root->getVSkill(strenght));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->updVSkill(strenght, tmp);
    }
    fnsport();
    root->setImage(media(12));
    root->setDesc(str(27));
    makeActBtn("go_back",act(4));
}

void Common::watch_tv_on_sofa()
{
    root->m_render->rendImagePage(root);
    if(watch_tv_count == 0)
    {
        root->setImage(media(13));
        root->setDesc(str(28));
        makeActBtn("watch_tv", act(5));
    }
    else
    {
        if(root->getVStatus(son) < 8 && root->getHour() < 5 && getRandInt(0,100) < root->getVStatus(mood))
        {
            makeActBtn("go_back",act(13));
            root->setImage(media(13));
            root->setDesc(str(29));
            root->incTime(getRandInt(60,120));
            root->updVStatus(son,4);
            return;
        }
        root->setImage(media(14));
        root->setDesc(str(30));
        //if(root->getCurLoc() == "sitrPar" && root->getHour() == 23)
        makeActBtn("switch_channel", act(6));
    }
    makeActBtn("go_back", act(7));
}

void Common::run_competition(QString arg)
{
    root->m_render->rendImagePage(root);
    root->setImage(media(15));
    root->setDesc(str(31));
    int base = 0;
    int step = 10;
    int i = 0;
    int prize = 0;
    QString wins[6], result[8];
    if(arg == "school") { base = 0; wins[0] = ""; }
    else if(arg == "city") { base = 70; wins[0] = ""; }
    else if(arg == "run0") { base = 0; root->m_events->sVEvent(begPrize, 300); wins[0] = str(32); }
    else if(arg == "run1") { base = 70; root->m_events->sVEvent(begPrize, 600); wins[0] = str(33); }
    else if(arg == "run2") { base = 130; root->m_events->sVEvent(begPrize, 1000); wins[0] = str(34); }
    else if(arg == "run3") { base = 200; root->m_events->sVEvent(begPrize, 1500); wins[0] = str(35); }
    else if(arg == "run4") { base = 270; root->m_events->sVEvent(begPrize, 2000); wins[0] = str(36); }
    else if(arg == "run5") { base = 330; root->m_events->sVEvent(begPrize, 3000); wins[0] = str(37); }
    else if(arg == "run6") { base = 450; step = 50; root->m_events->sVEvent(begPrize, 5000); wins[0] = ""; }
    else if(arg == "run7") { base = 450; step = 340; root->m_events->sVEvent(begPrize, 6000); wins[0] = str(38); }
    for(int i = 0; i < 8; i++)
    {
        result[i] = str(39 + i);
    }
    for(int i = 1; i < 6; i++)
    {
        result[i] = str(46 + i);
    }
    root->updVSkill(runner,1);
    root->updVStatus(day_weight,-1);
    int begres = root->getVSkill(runner) + root->getVSkill(speed)*5 + root->getVSkill(endurance) *5 + getRandInt(-100,100) - root->getVBody(bodyGroup)*100;
    if(begres < base)
    {
        root->setDesc(result[0]);
        makeActBtn("go_back",act(8));
    }
    else if(begres >= base + step*7)
    {
        if(arg == "school" || arg == "city")
        {
            root->setDesc(result[7] + wins[2]);
            if(arg == "school")
                root->updVStatistic(sWinBeg,1);
            if(arg == "city")
                root->updVStatistic(sWinBegGor,1);
        }
        else
        {
            root->updVStatistic(goldBeg,1);
            root->updVStatus(money,prize*3);
            root->updVStatistic(razradBeg,1);
            if(root->getVStatistic(razradBeg) >= 6 && root->getVStatistic(razradBeg) < 16)
                root->updVStatistic(razradBegK,1);
            if(arg == "run7")
                root->updVStatistic(razradBegEG,1);
            root->setDesc(result[7] + wins[5] + wins[0]);
        }
        makeActBtn("go_back",act(8));
    }
    else
    {
        while (true)
        {
            if(begres >= base + step * i && begres < base + step * (i + 1))
            {
                root->setDesc(result[i]);
                if(arg == "school" || arg == "city")
                    root->setDesc(wins[0]);
                else
                {
                    if(i == 5)
                    {
                        root->setDesc(wins[3]);
                        root->updVStatus(money,prize);
                        root->updVStatistic(bronzBeg,1);
                        if(root->getVStatistic(razradBeg) >= 6 && root->getVStatistic(razradBeg) < 16)
                            root->updVStatistic(razradBegK,1);
                        if(arg == "run7")
                            root->updVStatistic(razradBegEB,1);
                    }
                    if(i == 6)
                    {
                        root->setDesc(wins[4]);
                        root->updVStatus(money,prize*2);
                        root->updVStatistic(silverBeg,1);
                        if(root->getVStatistic(razradBeg) >= 6 && root->getVStatistic(razradBeg) < 16)
                            root->updVStatistic(razradBegK,1);
                        if(arg == "run7")
                            root->updVStatistic(razradBegES,1);
                    }
                }
                makeActBtn("go_back",act(8));
                break;
            }
            else
            {
                i++;
            }
        }
    }
}

void Common::fancywork()
{
    if(root->getVStatistic(gobelen) > 0)
        root->setDesc(str(52));
    if(root->getVSkill(posSkill) >= 50)
    {
        if(root->getItmCount(iFabric) > 0)
            root->addDesc(str(53));
        else
            root->addDesc(str(54));
    }
    if(root->getVSkill(posSkill) >= 200)
    {
        if(root->getVStatistic(newGobelen) == 0 && root->getItmCount(iFabric) > 0)
            makeActBtn("new_gobelen",act(9));
        if(root->getVStatistic(newGobelen) >= 1)
        {
            root->addDesc(str(56));
            makeActBtn("cont_gobelen",act(11));
        }
    }
}

void Common::check_inhome()
{

}

void Common::wet_wipes()
{
    if(root->getItmCount(iWetWipes) == 0)
        return;
    else if(root->getVStatus(cumFace) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumFace,0);
        root->useItem(iWetWipes,1);
    }
    if(root->getVStatus(cumFrot) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumFrot,0);
        root->useItem(iWetWipes,1);
    }
    if(root->getVStatus(cumBelly) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumBelly,0);
        root->useItem(iWetWipes,1);
    }
    if(root->getVStatus(cumAss) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumAss,0);
        root->useItem(iWetWipes,1);
    }
    if(root->getVStatus(cumPussy) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumPussy,0);
        root->useItem(iWetWipes,1);
    }
    if(root->getVStatus(cumAnus) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->setVStatus(cumAnus,0);
        root->useItem(iWetWipes,1);
    }
    root->incTime(getRandInt(5,10));
    root->addDesc(str(59));
}

int Common::getClothDecreaseLevel()
{
    ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
    if(ptr != nullptr)
    {
        ClothGroup cur = ptr->getClothGroup();
        if(cur == sportsSuit)
            return 0;
        else if(cur == jeans)
            return 2;
        else if(cur == skirt)
            return 3;
        else if(cur == casualDress)
            return 3;
        else if(cur == eveningDress)
            return 10;
        else if(cur == revealingOutfit)
            return 4;
        else if(cur == officeSuit)
            return 4;
        else if (cur == blouseWithShorts)
            return 4;
        else if (cur == sexualUnderwear)
            return 2;
        else return 0;
    }
    else return 0;
}

void Common::fnsport(int arg)
{
    root->setVStatus(frost,0);
    if(arg == 0)
    {
        root->updVStatus(energy, - 1);
        root->updVStatus(water, -2);
        root->updVStatus(son, -1);
        root->updVStatus(sweat, 1);
    }
    else
    {
        root->updVStatus(energy, -arg);
        root->updVStatus(water, -arg*2);
        root->updVStatus(son, -arg/2);
        root->updVStatus(sweat, arg);
    }
}

void Common::actionHandler(QString action)
{
    if(action == "go_back")
        go_back();
    if(action == "eat_icecream")
    {
        root->incTime(10);
        root->updVStatus(money,-50);
        root->updVStatus(day_weight,1);
        root->updVStatus(mood,10);
        root->updVStatus(water,3);
        root->updVStatus(energy,3);
        root->m_render->setImage(media(16));
        root->m_render->setText(str(2));
        makeActBtn("go_back", act(1));
    }
    if(action == "read_porn")
    {
        root->setImage(media(17));
        if(root->getItmCount(iPornMagazine) == 1)
            root->setDesc(str(13));
        else
        {
            root->useItem(iPornMagazine,1);
            root->updVStatus(horny, getRandInt(5,10));
            root->incTime(5);
            root->setDesc(str(14));
        }
        makeActBtn("go_back", act(4));
    }
    if(action == "wardrobe_start")
    {
        root->viewObj("wardrobe");
    }
    if(action == "sitrobrd")
        sitrobrd();
    if(action == "sitrskakd")
        sitrskakd();
    if(action == "sitrpressd")
        sitrpressd();
    if(action == "sitrpushd")
        sitrpushd();
    if(action == "watch_tv_on_sofa")
        watch_tv_on_sofa();
    if(action == "fancywork")
        fancywork();
    if(action == "check_inhome")
        check_inhome();
    if(action == "switch_channel")
    {
        root->incTime(60);
        root->updVStatus(mood, getRandInt(10,50));
        watch_tv_on_sofa();
    }
    if(action == "watch_tv")
    {
        root->incTime(60);
        root->updVStatus(mood, getRandInt(10,50));
        watch_tv_count =1;
        watch_tv_on_sofa();
    }
    if(action == "new_gobelen")
    {
        root->useItem(iFabric,1);
        root->setVSC(newGobelen,1);
        root->incTime(15);
        root->setImage(media(0));
        root->setDesc(str(55));
        makeActBtn("go_back",act(10));
    }
    if(action == "cont_gobelen")
    {
        root->incTime(60);
        root->updVSkill(posSkill,getRandInt(root->getVSkill(intellect) / 20, root->getVSkill(intellect) / 10));
        root->updVStatistic(newGobelen, root->getVSkill(agility)/20 + root->getVSkill(posSkill)/200);
        if(root->getVSkill(intellect) < 50)
            root->updVSkill(intellect,getRandInt(0,1));
        if(root->getVSkill(agility) < 50)
            root->updVSkill(agility,getRandInt(0,1));
        root->setImage(media(20));
        if(root->getVStatistic(newGobelen) < 100)
            root->setDesc(str(57));
        else
        {
            root->setVSC(newGobelen,0);
            root->setVSC(gobelen,1);
            root->setDesc(str(58));
        }
        makeActBtn("go_back",act(10));
    }
}

void Common::select_coffee(QString coffee)
{
    QString name;
    if(coffee == "coffee0")
    {
        name = str(3);
        root->updVStatus(money,-30);
        root->updVStatus(water,1);
        root->updVStatus(mood,5);
    }
    if(coffee == "coffee1")
    {
        name = str(4);
        root->updVStatus(money,-30);
        root->updVStatus(water,1);
        root->updVStatus(mood,5);
    }
    if(coffee == "coffee2")
    {
        name = str(5);
        root->updVStatus(money,-30);
        root->updVStatus(water,3);
        root->updVStatus(mood,5);
    }
    if(coffee == "coffee3")
    {
        name = str(6);
        root->updVStatus(money,-40);
        root->updVStatus(water,3);
        root->updVStatus(mood,10);
    }
    if(coffee == "coffee4")
    {
        name = str(7);
        root->updVStatus(money,-50);
        root->updVStatus(water,3);
        root->updVStatus(mood,15);
    }
    if(coffee == "coffee5")
    {
        name = str(8);
        root->updVStatus(money,-50);
        root->updVStatus(water,3);
        root->updVStatus(mood,15);
    }
    root->incTime(15);
    root->updVStatus(son,3);
    root->updVStatus(coffee_drink,1);
    if(root->getVStatus(coffee_drink) == 3)
    {
        root->updVStatus(mood, - getRandInt(15,30));
        root->updVStatus(health, -5);
        root->setImage(media(18));
        root->m_render->setText(str(10));
    }
    else
    {
        root->setImage(media(19));
        root->setDesc(str(11) + name + str(12));
    }
    makeActBtn("go_back", act(1));
}

void Common::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Common::actionHandler);
    root->m_actions->addWidget(btn);
}

void Common::check_sport_suit()
{
    ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);

    if(ptr != nullptr && ptr->getClothGroup() != sportsSuit)
    {
        lokerchoice();
        return;
    }
}

QString Common::str(int id)
{
    QString str[67];
    str[1] = "Мороженое предлагают за 50 рублей.";
    str[2] = "Вы купили мороженое и съели его не отходя далеко от прилавка.";
    str[3] = "Эспрессо";
    str[4] = "Допио";
    str[5] = "Американо";
    str[6] = "Капуччино";
    str[7] = "Мокаччино";
    str[8] = "Латте";
    str[9] = "<center>На ваш выбор есть несколько напитков:<br>";
    str[10] = "Сегодня вы выпили слишком много кофе и у вас поднялось давление.";
    str[11] = "Вы выпили чашечку ароматного ";
    str[12] = ", отчего чувствуете себя немного бодрее и веселее.";
    str[13] = "Скукота, этот журнал вы уже наизусть запомнили. Кажется, пора купить новый.";
    str[14] = "Вы листаете порножурнал, читая истории и разглядывая картинки. Потихоньку возбуждение начинает охватывать вас.";
    str[15] = "<b>Наркотики и спорт несовместимы! Вы не можете заниматься спортивными упражнениями</b>";
    str[16] = "Вы бегаете около получаса, не давая себе заплыть жирком.";
    str[17] = "Вы в течении часа бегаете стадиону, развивая скорость и навыки бега.";
    str[18] = "крутить обруч";
    str[19] = "прыжки на скакалке";
    str[20] = "упражнения на пресс";
    str[21] = "отжимания";
    str[22] = "В тесной комнатке однако есть место, где можно поделать разные спортивные упражнения, такие как ";
    str[0] = "<b>Не удалось поднять навык, повторите и получится обязательно!</b>";
    str[23] = "Вам надо одеть в спортивную форму!";
    str[24] = "Вы крутите обруч в течение пятнадцати минут, развивая ловкость.";
    str[25] = "Вы в течение пятнадцати минут прыгаете на скакалке, развивая скорость.";
    str[26] = "Вы делаете упражнения на пресс в течение пятнадцати минут, развивая выносливость.";
    str[27] = "Вы отжимаетесь от пола в течение пятнадцати минут, развивая силу.<br>Вам удалось чисто отжаться " + intQStr(getRandInt(root->getVSkill(strenght) / 10, root->getVSkill(strenght) / 5)) + " раз.";
    str[28] = "Вы садитесь рядом с выключенным телевизором";
    str[29] = "Вы задремали под монотонное бубнение телевизора и проспали некоторое время.";
    str[30] = "Вы смотрите телевизор, лёжа на диване. Смотреть почти нечего - сплошная реклама, идиотские телешоу и унылые сериалы.";
    str[31] = "Девушки, забег на 400 метров. Вы переодеваетесь, выходите на беговую дорожку и встаёте на старт. Раздаётся стартовый выстрел.";
    str[32] = " и 3й спортивный разряд по бегу.";
    str[33] = " и 2й спортивный разряд по бегу.";
    str[34] = " и 1й спортивный разряд по бегу. Вы становитесь Чемпионкой города по бегу.";
    str[35] = " и звание КМС по бегу. Вы становитесь чемпионкой области.";
    str[36] = " и звание Мастер спорта по бегу. Вы становитесь чемпионкой региона.";
    str[37] = " и звание Мастер спорта международного класса по бегу. Вы становитесь Чемпионкой России.";
    str[38] = " Вы чемпионка Европы.";
    str[39] = "Вы неплохо пробежали, для дилетантки конечно, заняв последнее 8 место.";
    str[40] = "Вы упорно боролись, но сумели занять только предпоследнее 7 место.";
    str[41] = "Вы упорно боролись, но сумели занять только 6 место.";
    str[42] = "Вы упорно боролись, но сумели занять только 5 место.";
    str[43] = "Вы упорно боролись, но сумели занять только 4 место.";
    str[44] = "Вы упорно боролись, и сумели занять призовое 3 место.";
    str[45] = "Вы упорно боролись, и сумели занять призовое 2 место.";
    str[46] = "Вы упорно боролись, и сумели занять 1 место.";
    str[47] = " Физрук поздравляет вас с успехом.";
    str[48] = " Физрук поздравляет вас с победой на соревнованиях.";
    str[49] = " Вы получаете бронзовую медаль и приз " + intQStr(root->m_events->gVEvent(begPrize)) + " рублей";
    str[50] = " Вы получаете серебряную медаль и приз " + intQStr(root->m_events->gVEvent(begPrize) * 2) + " рублей";
    str[51] = " Вы получаете золотую медаль, приз " + intQStr(root->m_events->gVEvent(begPrize) * 3) + " рублей";
    str[52] = "Готовых гобеленов " + intQStr(root->getVStatistic(gobelen)) + " шт";
    str[53] = "Вашей ткани хватит ещё на " + intQStr(root->getItmCount(iFabric)) + " уроков";
    str[54] = "У вас нет ткани. Её можно купить в хозяйственном отделе супермаркета.";
    str[55] = "Вы в течение 15 минут приготовили ткань, на которой будете вышивать узор, и в общих чертах разметили контуры узора.";
    str[56] = "Гобелен готов на <<newgobelen>> процентов.";
    str[57] = "Вы в течение часа вышиваете гобелен и теперь он готов на <<newgobelen>> процентов";
    str[58] = "Вы полностью закончили гобелен.";
    str[59] = "С помощью влажных салфеток вы быстро подчистили себя и одежду от неприятных следов.";
    str[60] = "ВАМИ ТОЛЬКО ЧТО БЫЛ ИСПОЛЬЗОВАН АВАРИЙНЫЙ ВЫХОД ИЗ БАГА ПУСТОГО ЭКРАНА!**НЕ ИСПОЛЬЗУЙТЕ ЭТУ ВОЗМОЖНОСТЬ БЕЗ ВЕСКОЙ ПРИЧИНЫ: ЭТИМ ВЫ МОЖЕТЕ ВЫЗВАТЬ СБОЙ, КОТОРЫЙ РАЗРУШИТ ВАШИ СОХРАНЕНИЯ";
    str[61] = "<b>Пьянство и спорт несовместимы!</b>";
    str[62] = "<b>У Вас похмелье и вам так паршиво - какой там спорт!</b>";
    str[63] = "<b>Алкоголизм и спорт несовместимы!</b>";
    str[64] = "<b>У вас похмелье и болит голова, а тут ещё уроки... нафиг всё!</b>";
    str[65] = "У вас в голове шумит, всё путается. Вы пытаетесь не перепутать учебники с порножуралами, тетрадки с любовными записками. Вроде получилось, и всё верно, хотя... ХЗ";
    str[66] = "Вы сегодня уже достаточно тренировались, стоит сделать перерыв.";
    return str[id];
}

QString Common::act(int id)
{
    QString act[14];
    act[0] = "Открыть шкаф";
    act[1] = "Назад";
    act[2] = "Купить мороженое";
    act[3] = "Листать порножурнал";
    act[4] = "Выйти";
    act[5] = "Включить телевизор";
    act[6] = "Переключить канал";
    act[7] = "Встать с дивана";
    act[8] = "Уйти";
    act[9] = "Начать новый гобелен";
    act[10] = "Отложить";
    act[11] = "Вышивать гобелен в течение часа.";
    act[12] = "Далее >>";
    act[13] = "Встать";
    return act[id];
}

QString Common::media(int id)
{
    QString med[21];
    med[0] = "data/actions/fancywork/newgobelen_start.jpg";
    med[1] = "data/locations/common/icecream_shop.jpg";
    med[2] = "data/locations/common/coffee_shop.jpg";
    med[3] = "data/actions/sport/cross/no_sport_beg.jpg";
    med[4] = "data/actions/sport/cross/cross_park.jpg";
    med[5] = "data/actions/sport/cross/cross_park_winter.jpg";
    med[6] = "data/actions/sport/cross/cross.jpg";
    med[7] = "data/actions/sport/cross/cross_winter.jpg";
    med[8] = "data/actions/choice_clothes.jpg";
    med[9] = "data/actions/sport/obruch.webm";
    med[10] = "data/actions/sport/skak.jpg";
    med[11] = "data/actions/sport/gym/press.jpg";
    med[12] = "data/actions/sport/gym/push.jpg";
    med[13] = "data/actions/tv/tv_off.jpg";
    med[14] = "data/actions/tv/tv_watch_" + intQStr(getRandInt(1,3)) + ".jpg";
    med[15] = "data/actions/sport/begsor.jpg";
    med[16] = "data/actions/eat/icecream1.jpg";
    med[17] = "data/actions/porn.jpg";
    med[18] = "data/actions/davlenie.jpg";
    med[19] = "data/actions/park_cafe/coffee_cup.jpg";
    med[20] = "data/actions/fancywork/newgobelen_work" + intQStr(getRandInt(1,2)) + ".jpg";
    return med[id];
}
