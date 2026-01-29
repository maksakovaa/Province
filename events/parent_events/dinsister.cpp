#include "dinsister.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../locations/common/bathroom.h"
#include "../../menu/buttons.h"

DinSister::DinSister(Game* ptr): root(ptr) {}

void DinSister::start(QString arg)
{
    if(arg == "check_talktime")
        check_talktime();
    else if(arg == "talk")
        talk();
    else if(arg == "sex_stories")
        sex_stories();
    else if(arg == "piercing")
        piercing();
    else if(arg == "sister_show")
        sister_show();
    else if(arg == "beach_events")
        beach_events();
}

void DinSister::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"DinSister");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &DinSister::actionHandler);
    root->addActions(btn);
}

void DinSister::check_talktime()
{
    i = 0;
    if(root->gNPC(sister).talk_count == root->gNPC(sister).talk_max_count)
    {
        root->gNPC(sister).talk_count += 1;
        root->addText(str(0));
        i = 1;
    }
    else if(root->gNPC(sister).talk_count > root->gNPC(sister).talk_max_count)
    {
        root->changeRep('-',sister);
        root->vStatus(mood) -= 5;
        root->gNPC(sister).talk_count = 100;
        root->addText(str(78));
        i = 1;
    }
}

void DinSister::talk()
{
    check_talktime();
    if(i == 0)
    {
        if(root->gNPC(sister).relation < 40)
        {
            if(root->gNPC(sister).relation < 20)
                root->addText(str(26));
            else
                root->addText(str(30));
            if(root->vEvent(sisterSorryDay) != root->getDay())
            {
                makeActBtn("SisterSorry", act(0));
            }
        }
        else
        {
            root->addText(str(32) + str(getRandInt(33,65)));
            root->gNPC(sister).talk_count += 1;
            root->changeRep('+',sister);
        }
    }
}

void DinSister::sex_stories()
{
    int i = getRandInt(66,73);
    root->setImage(media(i - 66));
    root->setText(str(i));
}

void DinSister::piercing()
{
    if(root->vBody(piercingA) >= 1 && root->vEvent(pirsAsister) == 0 && root->vEvent(sisPirsADayTalk) != root->getDay())
    {
        root->vEvent(sisPirsADayTalk) = root->getDay();
        if(getRandInt(1,100) >= 75)
        {
            root->addText(str(1));
            makeActBtn("pirsAnothing",act(2));
            makeActBtn("pirsAshow",act(3));
        }
    }
    if(root->vBody(piercingB) == 1 && root->vEvent(pirsBsister) == 0)
    {
        root->addText(str(4));
        makeActBtn("pirsBthanks",act(4));
    }
    if(root->vBody(piercingC) == 1 && root->vEvent(pirsCsister) == 0)
    {
        root->vEvent(pirsCsister) = 1;
        root->addText(str(6));
    }
    if(root->vBody(piercingD) == 1 && root->vEvent(pirsDsister) == 0)
    {
        root->vEvent(pirsDsister) = 1;
        root->addText(str(7));
    }
    if(root->vBody(piercingE) == 1 && root->vEvent(pirsEsister) == 0)
    {
        root->vEvent(pirsEsister) = 1;
        root->addText(str(8));
    }
}

void DinSister::sister_show()
{
    root->setImage(media(10));
    root->setText(str(9));
    makeActBtn("sisterShow1",act(5));
}

void DinSister::beach_events()
{
    root->setImage(media(14));
    root->setText(str(getRandInt(74,77)));
    makeActBtn("volleyball",act(6));
    makeActBtn("swim",act(7));
    makeActBtn("takeSunBath",act(11));
}

void DinSister::actionHandler(QString action)
{
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "korrPar")
    {
        root->changeLoc(lkorrpar);
    }
    if(action == "glake")
    {
        root->changeLoc(lglake);
    }
    if(action == "SisterSorry")
    {
        root->vEvent(sisterSorryDay) = root->getDay();
        root->gNPC(sister).talk_count += 1;
        root->changeRep('+',sister,10);
        if(root->gNPC(sister).relation < 20)
            root->addText(str(28));
        else
            root->addText(str(31));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "pirsAnothing")
    {
        root->addText(str(2));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "pirsAshow")
    {
        root->vEvent(pirsAsister) = 1;
        root->setImage(media(8));
        root->setText(str(3));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "pirsBthanks")
    {
        root->vEvent(pirsBsister) = 1;
        root->setImage(media(9));
        root->setText(str(5));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "sisterShow1")
    {
        root->vStatus(horny) += 20;
        root->incTime(2);
        root->setImage(media(11));
        root->setImage(str(10));
        makeActBtn("sisterShow2",act(5));
    }
    if(action == "sisterShow2")
    {
        root->vStatus(horny) += 20;
        root->incTime(2);
        root->setImage(media(12));
        root->setText(str(11));
        makeActBtn("sisterShow3",act(5));
    }
    if(action == "sisterShow3")
    {
        root->vStatus(horny) += 20;
        root->incTime(1);
        root->vEvent(EventParams::sister_show) = 1;
        root->setImage(media(13));
        root->setText(str(12));
        makeActBtn("korrPar",act(5));
    }
    if(action == "volleyball")
    {
        root->incTime(getRandInt(40,60));
        root->fnSport();
        root->setImage(media(getRandInt(15,17)));
        root->setText(str(13));
        makeActBtn("glake",act(1));
    }
    if(action == "swim")
    {
        root->incTime(getRandInt(10,20));
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->setImage(media(getRandInt(18,20)));
        root->setText(str(14));
        makeActBtn("swinSinel",act(8));
        makeActBtn("swimSis",act(9));
    }
    if(action == "swimSingle")
    {
        root->setImage(media(getRandInt(20,22)));
        root->setText(str(15));
        makeActBtn("glake",act(5));
    }
    if(action == "swimSis")
    {
        if(root->vStatus(horny) >= 70 && root->vEvent(sisBoyTrio) > 0 && root->vQuest(wedding) == 0)
        {
            root->setImage(media(getRandInt(23,24)));
            root->setText(str(16));
            makeActBtn("kissSis",act(18));
        }
        else
        {
            root->setImage(media(getRandInt(28,30)));
            root->setText(str(18));
            makeActBtn("glake",act(5));
        }
    }
    if(action == "kissSis")
    {
        root->setImage(media(getRandInt(25,27)));
        root->setText(str(17));
        makeActBtn("glake",act(10));
    }
    if(action == "takeSunBath")
    {
        root->setImage(media(getRandInt(31,33)));
        root->setText(str(19));
        makeActBtn("layDown",act(12));
    }
    if(action == "layDown")
    {
        root->vStatus(horny) += getRandInt(2,7);
        root->incTime(getRandInt(5,10));
        root->setImage(media(34));
        root->setText(str(20));
        makeActBtn("cream1",act(13));
    }
    if(action == "cream1")
    {
        root->incTime(getRandInt(2,5));
        root->setImage(media(34));
        root->setText(str(21));
        makeActBtn("onBack",act(14));
    }
    if(action == "onBack")
    {
        root->setImage(media(35));
        root->setText(str(22));
        if(root->vStatus(horny) >= 70 && root->vEvent(sisBoyTrio) > 0)
        {
            makeActBtn("topless",act(15));
        }
        makeActBtn("onBackThanks",act(17));
    }
    if(action == "topless")
    {
        root->setImage(media(36));
        root->setText(str(23));
        makeActBtn("sunBatheTopLess",act(16));
    }
    if(action == "sunBatheTopLess")
    {
        root->incTime(getRandInt(2,5));
        root->vStatus(horny) += getRandInt(2,7);
        root->setImage(media(33));
        root->setText(str(24));
        makeActBtn("toplessEnd",act(5));
    }
    if(action == "toplessEnd")
    {
        root->incTime(getRandInt(15,30));
        root->vStatus(mood) += 5;
        if(root->getSunWeather() < 2)
            root->vBody(skinTan) += 1;
        else
            root->vBody(skinTan) += 2;
        if(root->getTemp() < 30)
            root->vStatus(sweat) += 1;
        else
            root->vStatus(sweat) += 2;
        root->changeLoc(lglake);
    }
    if(action == "onBackThanks")
    {
        root->setImage(media(32));
        root->setText(str(25));
        makeActBtn("onBackEnd",act(5));
    }
    if(action == "onBackEnd")
    {
        root->incTime(getRandInt(15,30));
        root->vStatus(mood) += 5;
        if(root->getSunWeather() < 2)
            root->vBody(skinTan) += 1;
        else
            root->vBody(skinTan) += 2;
        if(root->getTemp() < 22)
            root->vStatus(sweat) += 0;
        else if(root->getTemp() < 30 )
            root->vStatus(sweat) +=1;
        else
            root->vStatus(sweat) += 2;
        root->changeLoc(lglake);
    }
}

QString DinSister::media(int id)
{
    QString med[37];
    med[0] = "data/sex/sis_stories/sister1.jpg";
    med[1] = "data/sex/sis_stories/sister2.jpg";
    med[2] = "data/sex/sis_stories/sister3.jpg";
    med[3] = "data/sex/sis_stories/sister4.jpg";
    med[4] = "data/sex/sis_stories/sister5.jpg";
    med[5] = "data/sex/sis_stories/sister6.jpg";
    med[6] = "data/sex/sis_stories/sister7.jpg";
    med[7] = "data/sex/sis_stories/sister8.jpg";
    med[8] = "data/img/body/piercing/pirsA.jpg";
    med[9] = "data/img/body/piercing/pirsB.jpg";
    med[10] = "data/npc/pavlovo/sister/dreaming00.jpg";
    med[11] = "data/npc/pavlovo/sister/dreaming01.jpg";
    med[12] = "data/npc/pavlovo/sister/dreaming02.jpg";
    med[13] = "data/npc/pavlovo/sister/dreaming03.jpg";
    med[14] = "data/npc/pavlovo/sister/beach_ev/0.jpg";
    med[15] = "data/npc/pavlovo/sister/beach_ev/0/0.jpg";
    med[16] = "data/npc/pavlovo/sister/beach_ev/0/1.jpg";
    med[17] = "data/npc/pavlovo/sister/beach_ev/0/2.jpg";
    med[18] = "data/npc/pavlovo/sister/beach_ev/1/0.jpg";
    med[19] = "data/npc/pavlovo/sister/beach_ev/1/1.jpg";
    med[20] = "data/npc/pavlovo/sister/beach_ev/1/2.jpg";
    med[20] = "data/npc/pavlovo/sister/beach_ev/2/0.jpg";
    med[21] = "data/npc/pavlovo/sister/beach_ev/2/1.jpg";
    med[22] = "data/npc/pavlovo/sister/beach_ev/2/2.jpg";
    med[23] = "data/npc/pavlovo/sister/beach_ev/3/0.jpg";
    med[24] = "data/npc/pavlovo/sister/beach_ev/3/1.jpg";
    med[25] = "data/npc/pavlovo/sister/beach_ev/4/0.jpg";
    med[26] = "data/npc/pavlovo/sister/beach_ev/4/1.jpg";
    med[27] = "data/npc/pavlovo/sister/beach_ev/4/2.jpg";
    med[28] = "data/npc/pavlovo/sister/beach_ev/5/0.jpg";
    med[29] = "data/npc/pavlovo/sister/beach_ev/5/1.jpg";
    med[30] = "data/npc/pavlovo/sister/beach_ev/5/2.jpg";
    med[31] = "data/npc/pavlovo/sister/beach_ev/6/0.jpg";
    med[32] = "data/npc/pavlovo/sister/beach_ev/6/1.jpg";
    med[33] = "data/npc/pavlovo/sister/beach_ev/6/2.jpg";
    med[34] = "data/npc/pavlovo/sister/beach_ev/7/0.jpg";
    med[35] = "data/npc/pavlovo/sister/beach_ev/8/0.jpg";
    med[36] = "data/npc/pavlovo/sister/beach_ev/9/0.jpg";
    return med[id];
}

QString DinSister::str(int id)
{
    QString str[79];
    str[0] = "<npc>- Ну ты, Света, и болтушка!</npc>";
    str[78] = "<npc>Света, ну хватит трещать! Уже голова от тебя болит!</npc> - повысила на вас голос Анька.";
    str[1] = "Сестра заглядывает вам в рот: <npc>- Света, а что у тебя там на языке?</npc>";
    str[2] = "Вы отрицательно качаете головой: <hero>- Ничего,</hero> - и тут же отворачиваетесь, чтобы сестра не заметила пирсинг языка.";
    str[3] = "Вы открываете рот и высовываете язык, показывая сестре пирсинг языка.<br>Сестра заулыбалась: <npc>- Ну ты даешь, Светик! Решила приукрасить свою внешность?</npc>";
    str[4] = "Сестра смотрит на ваши губы, в которых появился пирсинг: <npc>- Слушай, а неплохо выглядит, мне нравится!<npc>";
    str[5] = "Вы благодарите сестру за её комплимент вашей маленькой обновке.";
    str[6] = "Сестра смотрит на ваши уши и замечает серёжки: <npc>- Ну наконец-то! Я думала ты так и собралась без серёжек ходить.</npc>";
    str[7] = "Сестра смотрит немного шокированно на ваше кольцо в носу: <npc>- Фу, Света, это ещё что за гадость?</npc>";
    str[8] = "Сестра замечает ваш пирсинг брови: <npc>- Смотри, осторожно, чтоб никто не вырвал случайно!</npc>";
    str[9] = "Войдя в комнату, вы замерли от удивления - ваша сестрица в весьма откровенном наряде пританцовывает перед зеркалом.";
    str[10] = "Пытаясь не шуметь, вы тихонько прокрадываетесь в комнату, не сводя глаз с сестрицы, а она, в свою очередь, совершенно вас не разочаровывает - лёгкими плавными движениями Аня проводит от груди к ножкам, как-бы разглаживая невидимые складки её сексуального наряда, при этом выгибаясь и выпячивая попку.";
    str[11] = "Вдруг вы заметили, что Анька не надела трусики... <hero>\"Интересно, устоят ли парни, если увидят её в таком виде?\"</hero> - но вы знали ответ на свой вопрос, нервно заёрзав от нахлынувшего возбуждения.";
    str[12] = "Но, похоже, это были цветочки - сестрица увлеклась не на шутку - запустила руку между ножек и уже через несколько мгновений с легким стоном блаженства закончила свой танец, опустившись по стенке на пол.<br>Немного отдышавшись, Анька повернулась к вам, и лыбясь от уха до уха, хитро спросила:<br><npc>- Ну как тебе шоу?</npc><br>Не зная, что ответить, вы под хихиканье сестры, пулей вылетели в коридор.";
    str[13] = "Около часа вы дружно стучали по мячику, подшучивая над неудавшимися приёмами Рекса. В конце-концов, напрыгавшись, все устали и ушли с площадки.";
    str[14] = "Вся компания с хохотом наперегонки забежала в воду и принялась нырять, плескаться и брызгаться, шутя пытаясь утопить друг друга и сдёрнуть трусы, поднырнув втихаря.";
    str[15] = "Немного побарахтавшись в тёплой воде, вы выбрались на берег, и дождавшись остальных, вернулись на своё место.";
    str[16] = "Вы подплыли к Ане, стоящей на мелководье по шею в воде. <hero>- Аньк, я тебя тааак люблю - вот прям не могу!</hero> - верещите вы, повиснув на ней, обхватив руками и ногами. <npc>- Слезь с меня, оглашенная! Утопишь!</npc> - хохочет сестра, безуспешно пытаясь отодрать вас от себя.<br><hero>- Аньк, ты же моя любимая сестра - дай я тебя поцелую!</hero>";
    str[17] = "<npc>- Эй, ты чего!</npc> - опешила Аня, - <npc>на нас ведь смотрят!</npc> - наконец отпихнув вас, сестра отплыла и выбралась на берег.";
    str[18] = "Вы подплыли к Аньке, и как в детстве, начали брызгаться, после чего, немного поплавав, выбрались на берег.";
    str[19] = "<hero>- Не, я лучше позагораю, а то совсем бледная.</hero><br><npc>- Ну как знаешь,</npc> - проведя взглядом сверху вниз, как будто намекая, что не всё так плохо с загаром, хмыкнул Рекс.<br><npc>- Надоест лежать в одиночестве - присоединяйся.</npc><br><npc>- Эй, сестрёнка, а крем-то у тебя есть? Сгоришь ведь. Ложись, я тебя намажу</npc> - Аня достала из сумочки тюбик крема и подошла к вам.";
    str[20] = "Вы легли на живот, подставив спинку лучам солнца и мягким ладошкам сестры.<br>Аня начала нежно втирать крем, попутно болтая без умолку: к примеру, рассказывая, что Рекс сходит с ума от спермотоксикоза, потому и ведёт порой себя как мудак.<br>Спустя пару минут вы разомлели и уже не слушали Аньку, пропуская её болтовню мимо ушей.<br><npc>- Алё, Светик, ты что уснула?</npc> - спросила Анька, тормоша вас за плечо.<br><hero>- Да, так, что-то замоталась...</hero><br><npc>- Ладно, народ уже заждался, иду я.</npc><br><hero>- Погоди!</hero>";
    str[21] = "<hero>- Ань, а животик? Он тоже обгорит!</hero><br><npc>- Сама справишься, делов-то,</npc> - засобиралась Анька.<br><hero>- Ну Ань, ну пожалуйста! У тебя такие классные руки!</hero> - хлопая глазами, упрашиваете вы сестру.<br><npc>- Ладно, но давай быстро, все уже ждут,</npc> - сдалась Анька.";
    str[22] = "Вы быстро перевернулись на спинку, подставив сестре свой животик. Аня, улыбнувшись, занялась процедурой.";
    str[23] = "Решив немного пошалить, вы ловким движением сняли верх купальника, освободив грудь.<br>Не ожидав такого поворота, Анька замерла, но, взяв себя в руки, хитро улыбнулась, выдавила крем и начала массировать ваши груди, поигрывая с набухшими сосками.<br><npc>- Анька! Ну долго ты ещё там? Давай сюда уже!</npc> - оборвал идиллию громогласный оклик Рекса.<br><npc>- Ладно, сестренка, пошалила и хватит. Прикройся, а то парни на пляже своими вигвамами из трусов всех перепугают.</npc> - Анька чмокнула вас в щёчку и помахав рукой, побежала к компании.";
    str[24] = "<hero>\"Ну и ладно!\"</hero> - подумали вы, и надев купальник, перевернулись на живот.";
    str[25] = "<hero>- Спасибо, Ань. Ты такая заботливая!</hero><br><npc>- Ого, Светик, столько комплиментов за пять минут! К чему бы это?</npc> - хихикнула Анька у побежала к компании играть в волейбол, оставив вас загорать.";
    str[26] = "Вы пытаетесь поговорить с сестрой, но она отказывается с вами говорить.";
    str[27] = "Просить прощения";
    str[28] = "Вы извиняетесь перед сестрой и она, кажется, вас прощает.";
    str[29] = "Вы пытаетесь поговорить с сестрой, но она сухо разговаривает с вами.";
    str[30] = "Пытаться сгладить отношения";
    str[31] = "Вы подлизываетесь к сестре и она, кажется, начинает к вам лучше относиться.";
    str[32] = "Вы решили поболтать с сестрой.<br>";
    str[33] = "Вы болтаете с сестрой и она говорит, что можно снять квартиру в городе и жить-работать там, но её пока в Павлово всё устраивает.";
    str[34] = "Вы болтаете с сестрой и она говорит, что можно снять квартиру в городе и жить-работать там, но её пока в Павлово всё устраивает.";
    str[35] = "Вы спросили у Ани про университет. Она ухмыльнулась: \"Ну, я почти поступила... Недобрала баллов. А теперь забила: нафига он нужен, этот университет? Что мне даст эта бумажка?\"";
    str[36] = "Вы спросили Аньку про её парня. Она улыбается, облизнувшись: \"Ну, у меня есть парень... Хотя ничего серьёзного. Он мне больше друг\" - хихикает сестрица, почему-то вдруг краснея и томно облизываясь.";
    str[37] = "Вы болтаете с сестрицей. Она увлечённо взахлёб рассказывает о мальчиках, с которыми познакомилась, о вечеринках, о косметике.";
    str[38] = "Вы болтаете с сестрой, делясь всяким разным, в основном сплетнями. Анька \"по-секрету\" делится мыслями о странном поведении мамы: \"Она после работы стала частенько задерживаться, и вечно ругается, если к ней на работу прийти!.";
    str[39] = "Аня рассказывает, что однажды с утра забыла закрыть щеколду в ванной. Так за несколько минут всему семейству что-то в ванной понадобилось! \"Меня голой за пять минут увидели и мать, и отчим, и даже Колька нос сунул! - всем же непременно нужно что-нибудь в ванной именно тогда, когда я там моюсь!\" - фыркнула сестрица.";
    str[40] = "Аня болтает про спортивные секции в доме культуры, фыркая:<br>- Ой, ну я конечно всё понимаю, что это на попу влияет! Но у меня и так хорошая и мне лениво! Но подкачать жопу там можно!";
    str[41] = "Аня рассказывает, что одна из ее подруг залетела от парня, который не успел вытащить из неё.<br>- Презервативы или таблетки в аптеке покупай! Эти идиоты вечно секса хотят - а резинок сроду у них нет! Лучше самой иметь гондоны в сумочке - так надёжнее.";
    str[42] = "Аня недоуменно хмыкает: - что отчим почти каждый вечер после шести вечера вечно торчит в гараже? Машину за это время можно было разобрать и собрать раз сто!";
    str[43] = "Аня рассказывает, что отчим - человек старой закалки: он всегда всё делает по графику: например, в пять вечера он всегда в зале смотрит новости по телевизору.";
    str[44] = "Аня признаётся, что раньше она увлекалась диетами, но от них испортилась кожа и пошли прыши, да и болеть начала, так что теперь она трескает за троих и становится только красивей.";
    str[45] = "Вы болтаете с сестрой и она рассказывает вам, что ходила раньше на танцы, но ей это быстро надоело.";
    str[46] = "Вы болтаете с сестрой и она советует вам где-нибудь подрабатывать.";
    str[47] = "Вы болтаете с сестрой и она говорит вам, что если побродить по рынку, то можно найти много чего интересного и дешёвого.";
    str[48] = "Аня рассказывает вам страшилку о том, как одна симпатичная девушка не мылась и не брила ноги, и потом стала настолько страшной, что ее за километр все оббегали, и советует вам ухаживать за телом.";
    str[49] = "Аня рассказывает вам, что модная причёска всенепременно положительно скажется на вашей внешности.";
    str[50] = "Аня говорит вам, что прятать стройные ножки себе дороже: если носить юбку или платье - парни будут считать более привлекательной и обращать больше внимания, а кривоногие курицы пускай обзавидуются.";
    str[51] = "Аня советует вам поддерживать хорошие отношения со всей семьёй - у отчима и матери можно порой выклянчить пару рублей, а Колька не заложит в случае чего.";
    str[52] = "Аня рассказывает вам, что обожает летом загорать на пляже, только вот после работы времени совсем мало.";
    str[53] = "Аня рассказывает вам, что в дождь они всей компанией зависают в кафешке в парке по выходным или после её работы.";
    str[54] = "Аня рассказывает вам, что ей хотелось бы проводить свободное время более разнообразно, а не только в кафе или возде ДК пить пиво, но мододелы пока ничего интересного не написали.";
    str[55] = "Аня рассказывает вам, что дважды вечером, в часиков восемь, заходила к отчиму в гараж, и дважды он бухал с вашим соседом по площадке дядей Мишей, который работает сторожем в этом гаражном кооперативе.";
    str[56] = "Аня, краснея, рассказывает вам, что однажды поздно вечером подсматривала, как мать с отчимом занимались сексом.";
    str[57] = "Аня рассказывает вам, что как-то вечером она забыла закрыть щеколду в ванной и за ней подглядывал мелкий извращенец Колька, за что потом получил по шапке.";
    str[58] = "Аня рассказывает вам, что Колька ещё совсем дитё - только футбол у него на уме, постоянно возле школы с друганами трётся, пиная мячик на школьном стадионе.";
    str[59] = "Аня рассказывает вам, что не любит ездить в деревню, но деду с бабкой надо помогать, кроме того они иногда радуют любимую внучку денежкой.";
    str[60] = "Аня рассказывает вам, что однажды сдуру попёрлась в Гадюкино в лес в платье - так через несколько часов была похожа на чучело. А платье пришлось потом выкинуть. Туда если ходить - то только в джинсах. А осенью так и ватничек лишним не будет. Всё равно ж никто не увидит!";
    str[61] = "Аня рассказывает вам, что в Гадюкино её одногодки бухают, что кони, и с ними надо быть осторожной.";
    str[62] = "Аня рассказывает вам, что однажды в парке ее с подружкой за час пытались склеить три компании пацанов, явно птушников.";
    str[63] = "Аня рассказывает вам, что единственный способ набрать вес - много есть, а сбросить - это много-много бегать.";
    str[64] = "Аня рассказывает вам, что по понедельникам отчим ездит на своей Газельке в город на оптовые склады и обычно возвращается домой к полуночи.";
    str[65] = "Аня рассказывает вам, что в городе в поликлинике можно купить модные цветные контактные линзи - одна из ее богатеньких подружек носит такие - так все парни только за ней и бегают.";
    str[66] = "Сестра хвастается вам, как хорош в постели её парень.";
    str[67] = "Сестра рассказывает вам историю о том, как она с подругой отсасывала своему другу на его день рождения.";
    str[68] = "Сестра признается вам, что просто обожает в попу: <npc>- У меня мама точно так же справки проверяла, поэтому я немного схитрила...</npc> - немного покраснев добавляет: <npc>- и мне это очень понравилось. Хотя сперва было не очень приятно. Особенно без смазочки.</npc>";
    str[69] = "Сестра рассказывает вам, как она делает минет своему парню: <npc>- Ох, ты бы видела его лицо!</npc>";
    str[70] = "Сестра рассказывает вам, как в школе одноклассник помогал ей с изучением иностранного языка.";
    str[71] = "Сестра признается вам, что просто обожает оральный секс.";
    str[72] = "Сестра признается вам, что на одной из вечеринок отдалась сразу двоим.";
    str[73] = "Сестра признается вам, что мечтает заняться сексом с негром.";
    //! массив начальных диалогов, все сводим к выбору ГГ
    str[74] = "<npc>- Народ, может хватит пиво жрать? Давайте займёмся чем-нибудь поинтересней!?</npc> - предложила Аня.<br><npc>- Да я не против, раздевайся,</npc> - недолго думая, Рекс схватил Аньку за ноги, и под хохот компании потащил к себе.<br><npc>- Эй, Рексик, не для тебя мама цветочек растила!</npc> - понарошку отбиваясь, Анька повалилась на Рекса и чмокнула его.<br><npc>- Идёмте лучше поплаваем или волейбол поиграем! Света, что скажешь?</npc>";
    str[75] = "<npc>- Народ, может хватит пиво жрать? Давайте займёмся чем-нибудь поинтересней!?</npc> - предложила Аня.<br><npc>- И чем тебе пиво не нравится?</npc> - лениво потянул Рекс.<br><npc>- Ну и лежи себе колодой, а мы пойдем поплаваем!</npc> - хмыкнула в ответ Анька.<br><npc>- Ань, вот если б ты потрахаться предложила...</npc> - зевнул тот, отхлебнув из баклажки.<br><npc>- Да ну тебя, дурня!..</npc> - обиженно огрызнулась Аня - <npc>Светик, идём от этого извращенца!</npc><br><npc>- Ну Ань, я же пошутил</npc>, - начал оправдываться Рекс - <npc>ты ж знаешь, я б никогда...</npc><br><npc>- Ничего не слышу, ничего не знаю...</npc> - не сдавалась Анька, хоть по её ухмылке и понятно было, что обиды за дурацкие шутки она не держит - <npc>Света, куда идём?</npc>";
    str[76] = "<npc>- Ну что, может поплаваем?</npc> - предложил Рекс.<br><npc>- Да ну, лениво...</npc> - протянула Анька.<br><npc>- Скучно как-то... Ань, повесели честный народ - покажи сиськи!</npc> - Рекс потянулся к Анькиному купальнику.<br><npc>- Да ну тебя! Не даст спокойно отдохнуть! Светик, пойдём куда-нибудь от этого извращуги?</npc>";
    str[77] = "<npc>- У тебя такие классные ножки, так бы и зацеловал,</npc> - мечтательно протянул Рекс, поглаживая Анькину ногу.<br><npc>- Эй, Рекс, заведи себе наконец девушку и лапай её! У меня, между прочим, парень есть</npc> - парировала Анька, правда руку Рекса со своей ноги так и не убрала.<br><npc>- Я в раю!</npc> - выдавил с себя Рекс, чмокнув Аньку в коленку.<br><npc>- Рексик, потешился и хватит! Идёмте лучше в волейбол поиграем. Или ещё куда.</npc>";
    return str[id];
}

QString DinSister::act(int id)
{
    QString act[19];
    act[0] = "Просить прощения";
    act[1] = "Отойти";
    act[2] = "Ничего";
    act[3] = "Показать пирсинг языка";
    act[4] = "Спасибо";
    act[5] = "...";
    act[6] = "Играть в волейбол";
    act[7] = "Плавать";
    act[8] = "Плавать самой";
    act[9] = "Плавать с Аней";
    act[10] = "Вернуться и самой";
    act[11] = "Я лучше позагораю";
    act[12] = "Лечь";
    act[13] = "Намажь мне ещё животик";
    act[14] = "Перевернуться на спину";
    act[15] = "Оголить грудь";
    act[16] = "Загорать";
    act[17] = "Спасибо!";
    act[18] = "Поцеловать";
    return act[id];
}
