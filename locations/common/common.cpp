#include "common.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Common::Common(Game* ptr): root(ptr) {}

void Common::icecream()
{
    root->rendImagePage(this);
    root->setImage(media(1));
    root->setText(str(1));
    makeActBtn("go_back", act(1));
    if(root->vStatus(money) >= 50)
    {
        makeActBtn("eat_icecream", act(2));
    }
}

void Common::coffee()
{
    root->rendImagePage(this);
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
    root->setText(table);
    connect(root->getTextPtr(), &QLabel::linkActivated, this, &Common::select_coffee);
}

void Common::go_back()
{
    watch_tv_count = 0;
    root->changeLoc(root->getCurLoc(),0);
}

void Common::read_porn()
{
    makeActBtn("read_porn",act(3));
}

void Common::crossing(int arg)
{
    root->rendImagePage(this);
    if(root->vJob(workout) > 1)
    {
        root->setImage(media(3));
        root->setText(str(66));
        return;
    }

    //! ограничения по наркоте
    if(root->drugBlock() == true)
    {
        root->addText(str(15));
        return;
    }
    //! ограничения по алкоголю
    if(root->alkoBlock() != 0)
    {
        root->addText(str(60 + root->alkoBlock()));
        return;
    }

    if(arg == 1)
        root->vJob(workout) += 1;
    else
        root->vStatus(sport) += 1;
    root->vStatus(day_weight) -= 1;
    root->vSkill(runner) += getRandInt(2,5)*arg;
    root->vSkill(speed) += getRandInt(1,2)*arg;
    root->incTime(30);

    fnsport(arg*4);

    root->decreaseClothCond(getClothDecreaseLevel());
    if(arg == 1)
    {
        if(root->getSnow() <= 0)
            root->setImage(media(4));
        else
            root->setImage(media(5));
        root->setText(str(16));
    }
    else
    {
        if(root->getSnow() <= 0)
            root->setImage(media(6));
        else
            root->setImage(media(7));
        root->setText(str(17));
    }
}

void Common::home_workout()
{
    connect(root->getTextPtr(), &QLabel::linkActivated, this, &Common::actionHandler);
    //! ограничения по наркоте
    if(root->drugBlock() == true)
    {
        root->addText(str(15));
        return;
    }
    //! ограничения по алкоголю
    if(root->alkoBlock() != 0)
    {
        root->addText(str(60 + root->alkoBlock()));
        return;
    }

    QString res;
    if(root->getItmCount(iHoop) > 0)
        res += "<a href='sitrobrd'>" + str(18) + "</a>";
    if(root->getItmCount(iJumpRope) > 0)
        res += "<a href='sitrskakd'>" + str(19) + "<a>";
    res += "<a href='sitrpressd'>" + str(20) + "</a>";
    res += "<a href='sitrpushd'>" + str(21) + "</a>";
    if(root->vJob(workout) < 2)
        root->addText(str(22) + res);
}

void Common::lokerchoice()
{
    root->rendImagePage(this);
    root->setImage(media(8));
    root->setText(str(23));
    root->incTime(5);
    makeActBtn("wardrobe_start", act(0));
}

void Common::sitrobrd()
{
    check_sport_suit();
    root->rendVideoPage(this);
    root->incTime(15);
    root->vJob(workout) += 1;
    int tmp = upSportSkill(root->vSkill(agility));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->vSkill(agility) += tmp;
    }
    fnsport();
    root->setVideo(media(9),960,540);
    root->setText(str(24));
    makeActBtn("go_back", act(4));
}

void Common::sitrskakd()
{
    check_sport_suit();
    root->rendImagePage(this);
    root->incTime(15);
    root->vJob(workout) += 1;
    int tmp = upSportSkill(root->vSkill(speed));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->vSkill(speed) += tmp;
    }

    fnsport();
    root->setImage(media(10));
    root->setText(str(25));
    makeActBtn("go_back", act(4));
}

void Common::sitrpressd()
{
    check_sport_suit();
    root->rendImagePage(this);
    root->incTime(15);
    root->vJob(workout) += 1;
    int tmp = upSportSkill(root->vSkill(endurance));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->vSkill(endurance) += tmp;
    }
    fnsport();
    root->setImage(media(11));
    root->setText(str(26));
    makeActBtn("go_back",act(4));
}

void Common::sitrpushd()
{
    check_sport_suit();
    root->rendImagePage(this);
    root->incTime(15);
    root->vJob(workout) += 1;
    int tmp = upSportSkill(root->vSkill(strenght));
    if(tmp == 0)
    {
        root->sendNotif("<p style='color: red'>" + str(0) + "</p>");
    }
    else
    {
        root->vSkill(strenght) += tmp;
    }
    fnsport();
    root->setImage(media(12));
    root->setText(str(27));
    makeActBtn("go_back",act(4));
}

void Common::watch_tv_on_sofa()
{
    root->rendImagePage(this);
    if(watch_tv_count == 0)
    {
        root->setImage(media(13));
        root->setText(str(28));
        makeActBtn("watch_tv", act(5));
    }
    else
    {
        if(root->vStatus(son) < 8 && root->getHour() < 5 && getRandInt(0,100) < root->vStatus(mood))
        {
            makeActBtn("go_back",act(13));
            root->setImage(media(13));
            root->setText(str(29));
            root->incTime(getRandInt(60,120));
            root->vStatus(son) += 4;
            return;
        }
        root->setImage(media(14));
        root->setText(str(30));
        if(root->getCurLoc() == lsitrpar && root->getHour() == 23 && root->vEvent(brother_tv_enable) == 0 && root->vEvent(family_trip) == 0)
            root->startEvent(eBrotherEvents, "go_away");
        makeActBtn("switch_channel", act(6));
    }
    makeActBtn("go_back", act(7));
}

void Common::run_competition(QString arg)
{
    root->rendImagePage(this);
    root->setImage(media(15));
    root->setText(str(31));
    int base = 0;
    int step = 10;
    int i = 0;
    int prize = 0;
    QString wins[6], result[8];
    if(arg == "school") { base = 0; wins[0] = ""; }
    else if(arg == "city") { base = 70; wins[0] = ""; }
    else if(arg == "run0") { base = 0; root->vEvent(begPrize) = 300; wins[0] = str(32); }
    else if(arg == "run1") { base = 70; root->vEvent(begPrize) = 600; wins[0] = str(33); }
    else if(arg == "run2") { base = 130; root->vEvent(begPrize) = 1000; wins[0] = str(34); }
    else if(arg == "run3") { base = 200; root->vEvent(begPrize) = 1500; wins[0] = str(35); }
    else if(arg == "run4") { base = 270; root->vEvent(begPrize) = 2000; wins[0] = str(36); }
    else if(arg == "run5") { base = 330; root->vEvent(begPrize) = 3000; wins[0] = str(37); }
    else if(arg == "run6") { base = 450; step = 50; root->vEvent(begPrize) = 5000; wins[0] = ""; }
    else if(arg == "run7") { base = 450; step = 340; root->vEvent(begPrize) = 6000; wins[0] = str(38); }
    for(int i = 0; i < 8; i++)
    {
        result[i] = str(39 + i);
    }
    for(int i = 1; i < 6; i++)
    {
        result[i] = str(46 + i);
    }
    root->vSkill(runner) += 1;
    root->vStatus(day_weight) -= 1;
    int begres = root->vSkill(runner) + root->vSkill(speed)*5 + root->vSkill(endurance) *5 + getRandInt(-100,100) - root->vBody(bodyGroup)*100;
    if(begres < base)
    {
        root->setText(result[0]);
        makeActBtn("go_back",act(8));
    }
    else if(begres >= base + step*7)
    {
        if(arg == "school" || arg == "city")
        {
            root->setText(result[7] + wins[2]);
            if(arg == "school")
                root->vStatistics(sWinBeg) += 1;
            if(arg == "city")
                root->vStatistics(sWinBegGor) += 1;
        }
        else
        {
            root->vStatistics(goldBeg) += 1;
            root->vStatus(money) += prize*3;
            root->vStatistics(razradBeg) += 1;
            if(root->vStatistics(razradBeg) >= 6 && root->vStatistics(razradBeg) < 16)
                root->vStatistics(razradBegK) += 1;
            if(arg == "run7")
                root->vStatistics(razradBegEG) += 1;
            root->setText(result[7] + wins[5] + wins[0]);
        }
        makeActBtn("go_back",act(8));
    }
    else
    {
        while (true)
        {
            if(begres >= base + step * i && begres < base + step * (i + 1))
            {
                root->setText(result[i]);
                if(arg == "school" || arg == "city")
                    root->setText(wins[0]);
                else
                {
                    if(i == 5)
                    {
                        root->setText(wins[3]);
                        root->vStatus(money) += prize;
                        root->vStatistics(bronzBeg) += 1;
                        if(root->vStatistics(razradBeg) >= 6 && root->vStatistics(razradBeg) < 16)
                            root->vStatistics(razradBegK) += 1;
                        if(arg == "run7")
                            root->vStatistics(razradBegEB) += 1;
                    }
                    if(i == 6)
                    {
                        root->setText(wins[4]);
                        root->vStatus(money) += prize*2;
                        root->vStatistics(silverBeg) +=1;
                        if(root->vStatistics(razradBeg) >= 6 && root->vStatistics(razradBeg) < 16)
                            root->vStatistics(razradBegK) += 1;
                        if(arg == "run7")
                            root->vStatistics(razradBegES) += 1;
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
    if(root->vStatistics(gobelen) > 0)
        root->setText(str(52));
    if(root->vSkill(posSkill) >= 50)
    {
        if(root->getItmCount(iFabric) > 0)
            root->addText(str(53));
        else
            root->addText(str(54));
    }
    if(root->vSkill(posSkill) >= 200)
    {
        if(root->vStatistics(newGobelen) == 0 && root->getItmCount(iFabric) > 0)
            makeActBtn("new_gobelen",act(9));
        if(root->vStatistics(newGobelen) >= 1)
        {
            root->addText(str(56));
            makeActBtn("cont_gobelen",act(11));
        }
    }
}

bool Common::check_inhome()
{
    return ((root->vSchool(vacation) > 0 || root->getWeek() == 6 || root->getWeek() == 0) && root->getHour() > 10 && root->getHour() < 20) ||
           (root->getWeek() > 0 && root->getWeek() <= 5 && root->getHour() >= 15 && root->getHour() < 20);
}

void Common::wet_wipes()
{
    if(root->getItmCount(iWetWipes) == 0)
        return;
    else if(root->vStatus(cumFace) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumFace) = 0;
        root->useItem(iWetWipes,1);
    }
    if(root->vStatus(cumFrot) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumFrot) = 0;
        root->useItem(iWetWipes,1);
    }
    if(root->vStatus(cumBelly) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumBelly) = 0;
        root->useItem(iWetWipes,1);
    }
    if(root->vStatus(cumAss) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumAss) = 0;
        root->useItem(iWetWipes,1);
    }
    if(root->vStatus(cumPussy) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumPussy) = 0;
        root->useItem(iWetWipes,1);
    }
    if(root->vStatus(cumAnus) > 0 && root->getItmCount(iWetWipes) > 0)
    {
        root->vStatus(cumAnus) = 0;
        root->useItem(iWetWipes,1);
    }
    root->incTime(getRandInt(5,10));
    root->addText(str(59));
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
    root->vStatus(frost) = 0;
    if(arg == 0)
    {
        root->vStatus(energy) -= 1;
        root->vStatus(water) -= 2;
        root->vStatus(son) -= 1;
        root->vStatus(sweat) += 1;
    }
    else
    {
        root->vStatus(energy) -= arg;
        root->vStatus(water) -= arg*2;
        root->vStatus(son) -= arg/2;
        root->vStatus(sweat) += arg;
    }
}

void Common::waiting(int arg)
{
    if(arg == 0)
        makeActBtn("waiting",act(15));
    if(arg > 0)
        makeActBtn("waiting1",act(16));
}

void Common::actionHandler(QString action)
{
    if(action == "waiting")
    {
        root->clearActions();
        makeActBtn("waiting_1m",act(16));
        makeActBtn("waiting_5m",act(17));
        makeActBtn("waiting_15m",act(18));
        makeActBtn("waiting_30m",act(19));
        makeActBtn("waiting_1h",act(20));
    }
    if(action == "waiting1")
    {
        root->clearActions();
        makeActBtn("waiting1_1m",act(16));
        makeActBtn("waiting1_5m",act(17));
        makeActBtn("waiting1_15m",act(18));
        makeActBtn("waiting1_30m",act(19));
        makeActBtn("waiting1_1h",act(20));
    }
    if(action == "waiting_1m")
        root->changeLoc(root->getCurLoc(),1);
    if(action == "waiting_5m")
        root->changeLoc(root->getCurLoc(),5);
    if(action == "waiting_15m")
        root->changeLoc(root->getCurLoc(),15);
    if(action == "waiting_30m")
        root->changeLoc(root->getCurLoc(),30);
    if(action == "waiting_1h")
        root->changeLoc(root->getCurLoc(),60);
    if(action == "waiting1_1m")
        root->changeLoc(root->getCurLoc(),0);
    if(action == "waiting1_5m")
        root->changeLoc(root->getCurLoc(),4);
    if(action == "waiting1_15m")
        root->changeLoc(root->getCurLoc(),14);
    if(action == "waiting1_30m")
        root->changeLoc(root->getCurLoc(),29);
    if(action == "waiting1_1h")
        root->changeLoc(root->getCurLoc(),59);

    if(action == "go_back")
        go_back();
    if(action == "eat_icecream")
    {
        root->incTime(10);
        root->vStatus(money) -= 50;
        root->vStatus(day_weight) += 1;
        root->vStatus(mood) += 10;
        root->vStatus(water) += 3;
        root->vStatus(energy) += 3;
        root->setImage(media(16));
        root->setText(str(2));
        makeActBtn("go_back", act(1));
    }
    if(action == "read_porn")
    {
        root->setImage(media(17));
        if(root->getItmCount(iPornMagazine) == 1)
            root->setText(str(13));
        else
        {
            root->useItem(iPornMagazine,1);
            root->vStatus(horny) += getRandInt(5,10);
            root->incTime(5);
            root->setText(str(14));
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
        root->vStatus(mood) += getRandInt(10,50);
        watch_tv_on_sofa();
    }
    if(action == "watch_tv")
    {
        root->incTime(60);
        root->vStatus(mood) += getRandInt(10,50);
        watch_tv_count =1;
        watch_tv_on_sofa();
    }
    if(action == "new_gobelen")
    {
        root->useItem(iFabric,1);
        root->vStatistics(newGobelen) = 1;
        root->incTime(15);
        root->setImage(media(0));
        root->setText(str(55));
        makeActBtn("go_back",act(10));
    }
    if(action == "cont_gobelen")
    {
        root->incTime(60);
        root->vSkill(posSkill) += getRandInt(root->vSkill(intellect) / 20, root->vSkill(intellect) / 10);
        root->vStatistics(newGobelen) += root->vSkill(agility)/20 + root->vSkill(posSkill)/200;
        if(root->vSkill(intellect) < 50)
            root->vSkill(intellect) += getRandInt(0,1);
        if(root->vSkill(agility) < 50)
            root->vSkill(agility) += getRandInt(0,1);
        root->setImage(media(20));
        if(root->vStatistics(newGobelen) < 100)
            root->setText(str(57));
        else
        {
            root->vStatistics(newGobelen) = 0;
            root->vStatistics(gobelen) =1;
            root->setText(str(58));
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
        root->vStatus(money) -= 30;
        root->vStatus(water) += 1;
        root->vStatus(mood) += 5;
    }
    if(coffee == "coffee1")
    {
        name = str(4);
        root->vStatus(money) -= 30;
        root->vStatus(water) += 1;
        root->vStatus(mood) += 5;
    }
    if(coffee == "coffee2")
    {
        name = str(5);
        root->vStatus(money) -= 30;
        root->vStatus(water) += 3;
        root->vStatus(mood) += 5;
    }
    if(coffee == "coffee3")
    {
        name = str(6);
        root->vStatus(money) -= 40;
        root->vStatus(water) += 3;
        root->vStatus(mood) += 10;
    }
    if(coffee == "coffee4")
    {
        name = str(7);
        root->vStatus(money) -= 50;
        root->vStatus(water) += 3;
        root->vStatus(mood) += 15;
    }
    if(coffee == "coffee5")
    {
        name = str(8);
        root->vStatus(money) -= 50;
        root->vStatus(water) += 3;
        root->vStatus(mood) += 15;
    }
    root->incTime(15);
    root->vStatus(son) += 3;
    root->vStatus(coffee_drink) += 1;
    if(root->vStatus(coffee_drink) == 3)
    {
        root->vStatus(mood) -= getRandInt(15,30);
        root->vStatus(health) -=5;
        root->setImage(media(18));
        root->setText(str(10));
    }
    else
    {
        root->setImage(media(19));
        root->setText(str(11) + name + str(12));
    }
    makeActBtn("go_back", act(1));
}

void Common::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"common");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Common::actionHandler);
    root->addActions(btn);
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
    str[27] = "Вы отжимаетесь от пола в течение пятнадцати минут, развивая силу.<br>Вам удалось чисто отжаться " + intQStr(getRandInt(root->vSkill(strenght) / 10, root->vSkill(strenght) / 5)) + " раз.";
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
    str[49] = " Вы получаете бронзовую медаль и приз " + intQStr(root->vEvent(begPrize)) + " рублей";
    str[50] = " Вы получаете серебряную медаль и приз " + intQStr(root->vEvent(begPrize) * 2) + " рублей";
    str[51] = " Вы получаете золотую медаль, приз " + intQStr(root->vEvent(begPrize) * 3) + " рублей";
    str[52] = "Готовых гобеленов " + intQStr(root->vStatistics(gobelen)) + " шт";
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
    QString act[21];
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
    act[14] = "Бездельничать";
    act[15] = "Ждать";
    act[16] = "1 минуту";
    act[17] = "5 минут";
    act[18] = "15 минут";
    act[19] = "Полчаса";
    act[20] = "Час";
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
