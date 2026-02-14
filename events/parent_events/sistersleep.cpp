#include "sistersleep.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

SisterSleep::SisterSleep(Game* ptr): root(ptr) {}

void SisterSleep::start(QString arg)
{
    if(root->vStatistics(lesbianSex) > 0)
    {
        root->vStatus(horny) += 5;
        root->vEvent(sisWatch) += 1;
    }
    root->setImage(media(getRandInt(0,1)));
    root->setText(str(2));
    if(root->getCurLoc() == lbedrpar)
    {
        if(root->vQuest(qwSisterBoy) >= 8 && root->vQuest(qwSisterLesbi) == 0 && root->vStatus(horny) >= 60)
        {
            makeActBtn("touchSis1",act(1));
        }
        else if(root->vQuest(qwSisterLesbi) == 1 && root->vStatus(horny) >= 60 && root->vEvent(sisPryNight) != root->getDay())
        {
            makeActBtn("touchSis2",act(1));
        }
        if(root->vQuest(qwSisterLesbi) == 3 && root->vStatus(horny) >= 60 && root->vEvent(sisPryNight) != root->getDay())
        {
            makeActBtn("touchSis3",act(1));
        }
    }
    else
        makeActBtn("back_to_loc",act(0));
}

void SisterSleep::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Sister");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SisterSleep::actionHandler);
    root->addActions(btn);
}

void SisterSleep::actionHandler(QString action)
{
    if(action == "bedrPar")
        root->changeLoc(lbedrpar);
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "touchSis1")
    {
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->vQuest(qwSisterLesbi) = 1;
        root->vEvent(sisPryNight) = root->getDay();
        root->setImage(media(2));
        root->setText(str(3));
        makeActBtn("sisboyQW_prycaress",act(2));
        makeActBtn("bedrPar",act(0));
    }
    if(action == "touchSis2")
    {
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->vEvent(sisPryNight) = root->getDay();
        root->setImage(media(4));
        root->setText(str(4));
        makeActBtn("touchSis2.1",act(3));
        makeActBtn("sisboyQW_prycaress",act(2));
        makeActBtn("bedrPar",act(0));
    }
    if(action == "touchSis2.1")
    {
        root->incTime(2);
        root->vStatus(horny) += 5;
        root->setImage(media(5));
        root->setText(str(5));
        makeActBtn("touchSis2.2",act(4));
        makeActBtn("touchSis2_1.1",act(6));
    }
    if(action == "touchSis2.2")
    {
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->setImage(media(7));
        root->setText(str(6));
        makeActBtn("touchSis2.3",act(5));
    }
    if(action == "touchSis2.3")
    {
        root->incTime(1);
        if(root->vStatus(horny) < 95)
            root->vStatus(horny) += 5;
        root->vQuest(qwSisterLesbi) = 2;
        root->vSex(girl) += 1;
        root->setImage(media(8));
        root->setText(str(7));
        makeActBtn("bedrPar",act(0));
    }

    if(action == "touchSis2_1.1")
    {
        root->incTime(1);
        root->setImage(media(6));
        root->setText(str(8));
        makeActBtn("touchSis2_1.2",act(0));
    }
    if(action == "touchSis2_1.2")
    {
        root->incTime(1);
        root->gNPC(sister).relation = 0;
        root->setImage(media(9));
        root->setText(str(9));
        makeActBtn("bedrPar",act(0));
    }
    if(action == "touchSis3")
    {
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->vEvent(sisPryNight) = root->getDay();
        root->vStatistics(lesbianSex) += 1;
        if(root->vEvent(sisLesbiScene) == 0)
        {
            root->setImage(media(10));
            root->setText(str(10));
        }
        else if(root->vEvent(sisLesbiScene) == 1)
        {
            root->setImage(media(11));
            root->setText(str(11));
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            root->vStatistics(orgasm) += 1;
        }
        else if(root->vEvent(sisLesbiScene) == 2)
        {
            root->setImage(media(12));
            root->setText(str(12));
        }
        else if(root->vEvent(sisLesbiScene) == 3)
        {
            root->setImage(media(13));
            root->setText(str(13));
            if(root->vBody(anus) <= 5)
                root->addText(str(14));
            else if(root->vBody(anus) > 5 && root->vBody(anus) <= 10)
                root->addText(str(15));
            else if(root->vBody(anus) > 10 && root->vBody(anus) <= 15)
                root->addText(str(16));
            else
                root->addText(str(17));
            if(root->vBody(anus) > 5)
                root->addText(str(18));
            root->setGape(anus,0,15,0);
            root->vStatistics(lesbianSex) += 1;
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            if(root->vSex(agape) < 3)
                root->vStatistics(orgasm) += 1;
            makeActBtn("suckDildo",act(7));
        }
        else if(root->vEvent(sisLesbiScene) >= 4)
        {
            root->setImage(media(15));
            root->setText(str(20));
            root->vQuest(qwSisterLesbi) = 4;
            root->vQuest(qwSisterTrio) = 0;
        }
        root->vEvent(sisLesbiScene) += 1;
    }
    if(action == "suckDildo")
    {
        root->vBody(throat) += 1;
        root->vEvent(sisLesbiScene) += 1;
        root->setImage(media(14));
        root->setText(str(19));
        makeActBtn("bedrPar",act(0));
    }
}

void SisterSleep::sisboyQW_prycaress()
{
    root->incTime(5);
    root->vStatus(horny) += 10;
    root->setImage(media(3));
    root->setText(str(1));
    makeActBtn("bedrPar",act(0));
}

QString SisterSleep::media(int id)
{
    QString med[16];
    med[0] = "data/npc/pavlovo/sister/sleep0.jpg";
    med[1] = "data/npc/pavlovo/sister/sleep1.jpg";
    med[2] = "data/sex/sisBoyQW/sisboyQW_16.jpg";
    med[3] = "data/sex/sisBoyQW/sisboyQW_17.jpg";
    med[4] = "data/sex/sisBoyQW/sisboyQW_18.jpg";
    med[5] = "data/sex/sisBoyQW/sisboyQW_19.jpg";
    med[6] = "data/sex/sisBoyQW/sisboyQW_20.jpg";
    med[7] = "data/sex/sisBoyQW/sisboyQW_21.jpg";
    med[8] = "data/sex/sisBoyQW/sisboyQW_22.jpg";
    med[9] = "data/sex/sisBoyQW/sisboyQW_23.jpg";
    med[10] = "data/sex/sisBoyQW/sisboyQW_30.jpg";
    med[11] = "data/sex/sisBoyQW/sisboyQW_31.jpg";
    med[12] = "data/sex/sisBoyQW/sisboyQW_32.jpg";
    med[13] = "data/sex/sisBoyQW/sisboyQW_33.jpg";
    med[14] = "data/sex/sisBoyQW/sisboyQW_34.jpg";
    med[15] = "data/sex/sisBoyQW/sisboyQW_35.jpg";
    return med[id];
}

QString SisterSleep::str(int id)
{
    QString str[21];
    str[1] = "От неожиданных бурных чувств вы откинулись на спину, расставили ножки пошире и расслабились.<br>Вы ласкаете себя медленно и нежно, наслаждаясь каждой секундой,"
             " глядя на сексуальную попку Аньки.<br>Не покидает мысль: продолжить ли лапать спящую сестру, прикоснуться к её нежной писе? Но что-то останавливает.<br>"
             "<hero>\"Может в следующий раз буду решительней?\"</hero> - подумали вы про себя, продолжая дразнить клитор.";
    str[2] = "На кровати, выставив попку, лежит Аня";
    str[3] = "Вы решились потрогать спящую сестрёнку за упругую попу. Дотронувшись да мягкой ягодицы - вас будто ударило током, вызвав какое-то странное чувство: вам неожиданно"
             " захотелось заняться сексом с родной сестрой.";
    str[4] = "Вас не покидали ощущения, испытанные в прошлый раз от прикосновения к голой попке сестры.<br>Убедившись, что Анька крепко спит, вы снова решились коснуться её нежной"
             " попки.<br>Но в этот раз вы ласкаете булочки чуть дольше, наслаждаясь моментом.<br>Сексуальное тело сестры вас не на шутку завело и вы решаете...";
    str[5] = "Вы продолжили исследовать горячее тело сестренки, ваши резвые пальчики случайно скользнули между ножек Ани.<br>Ощущения тепла и влаги вас сильно поразили, киска"
             " сочится от желания - похоже, сестрице снится что-то весьма приятное.<br><dh><hero>\"То ли ей снится увлекательный сон, или это всё я?\"</hero> - проскальзывает "
             "мысль.</dh><br>Вы продолжаете нежно и осторожно ласкать сестру, вторую ладошку запустив себе в трусики.<br>Внезапно Анька заворочалась, случайно зажав вашу руку "
             "промеж ног. <hero>\"Чёрт... Чёрт, она просыпается! А я не успеваю убрать руку...\"</hero> - возникает паническая мысль.";
    str[6] = "Вы достаточно смелая девушка, - и пока полусонная Анька не опомнилась, - чувственно целуете её в губы.<br>Сильно возбужденная Аня и не думает сопротивляться: её"
             " мягкое тело легко поддалось вашему напору.<br>Ваша ладошка снова скользнула в трусики сестрёнки, но теперь ваши ласки куда увереннее.";
    str[7] = "Анька внезапно забилась в сладких судорогах, и со стоном бурно кончила. Открыв глаза, она сперва оторопело смотрит на вас, но затем благодарно улыбается:<br>"
             "<do>- Ну ты даёшь, сестрёнка!..</do><br>И тут же опять засыпает с блаженной улыбкой, уткнувшись носом в подушку. Вы, сильно возбужденная и неудовлетворенная, "
             "даже чуть расстроились, но всё равно классно получилось!";
    str[8] = "Сонная и мятая Аня просыпается и замечает вас на её кровати, и как вы спешно убираете руку и прячете за спиной.<br><do>- Что...что тут происходит, "
             "<<$name[2]>>? Ты чего, сдурела? Ты что тут делаешь?</do><br>Вы сидите перед сестрой на её кровати, возбужденная, застуканная врасплох, и совсем не зная что делать...";
    str[9] = "Вы решили ничего не делать и тихо отойти от полусонной сестры: может она к утру всё забудет и пдумает, что это ей приснилось?<br>Едва вы сделали шаг от её кровати,"
             " - она буркает раздражённо:<br><do>- Я ничего не хочу знать - что ты делала со мной пока я спала, - но больше не подходи ко мне!</do>";
    str[10] = "Разбудив полуголую Аню, вы покрываете её поцелуями, постепенно спускаясь вниз.<br>Спустив трусики вы моментально прильнули к столь желанному лону сестренки, "
              "вдыхая опьяняющий аромат.<br>Крепко обняв и удобно устроились между ножек сестрёнки, вы облизываете мягкие скользкие от влаги складочки губ и лаская клитор."
              "<br>Аня блаженствует под вашим язычком, гладя по волосам.<br>Она так сильно завелась, что внезапно задергалась, схватила вас за голову, и не отпуская её,"
              " бурно кончила. И почти моментально вновь уснула.";
    str[11] = "Вы начали нежно целоваться, лаская друг друга, уделяя внимание каждому миллиметру тела.<br>Аня садится, и раздвинув ваши ноги, легонько целует вашу набухшую "
              "и сочащуюся <npc>\"розочку\"</npc>, пройдясь языком по клитору.<br>Затем она, чуть помедлив, вводит пальчик в киску и начинает двигать им туда-сюда. От "
              "возбуждения кровь в голове бухает молотами. Вы почувствовали что приближается оргазм, и тяжело дыша, просите срывающимся голосом:<br><dh>- Только не "
              "останавливайся... продолжай! Ааа... А... Аааххх...</dh><br>Сестрёнка вовсю старается и пальчиками, и язычком. Её язык проникает всё глубже и глубже,"
              " меняясь местами в киске с пальцами, а другой рукой Аня мнёт ваши сиськи.<br><dh>- Аааааааааааа!!!</dh> Вас накрывает волна блаженства и вы бурно кончаете"
              " со сдавленными стонами - а то ещё, не дай бог, родителей разбудить не хватало!";
    str[12] = "Вы спустились к Анькиному бутону, от которого исходит дразнящий аромат, который кружит голову.<br>Проведя между губок пальчиком чтобы их раздвинуть, вы касаетесь"
              " клитора и начинаете делать круговые движения, лаская его.<br>Анька начала тихонько постанывать.<br>Теперь палец сменяется ртом. От ваших ласк сестра извивается,"
              " тяжело сопит и сладострастно стонет, зажав рот рукой. Наконец её тело забилось в конвульсиях - она кончает, выгнувшись дугой, и опадает в сладком изнеможении. ";
    str[13] = "На этот раз Анька подошла к ящику и достала страпон.<br>Она надевает его и ложится на спину, поманив вас на себя. Вы забираетесь на неё, но страпон зашёл не туда,"
              " куда вы предполагали, а в вашу попку!";
    str[14] = "От зверской боли вы, взвизгнув, резво соскочили с искуственной елды.<br><dh>- Ты что - дура!? Больно же!</dh><br><do>- Ты такая узенькая там... А Ромка меня в"
              " попку частенько - вот я и забыла. У меня-то разработана попа уже давно. Извини, не расчитала,</do> - хихикает в ответ эта сучка! <do>- А сосать-то ты хоть "
              "умеешь?</do>";
    str[15] = "Первое ощущение - это невыносимая боль! Вы даже хотели спрыгнуть, но потом стало приятно...";
    str[16] = "Вы почувствовали лёгкую боль в попе от неожиданного проникновения, но это быстро прошло...";
    str[17] = "Он без проблем вошел в ваш " + root->getAnusTipe() + " анус, вызвав стон наслаждения.";
    str[18] = "Аня, держась за ваши сиськи, подкидывает попу, сношая вас в зад.<br><dh>- Ааа!.. Даааа... Сууукааа!.. Давай!... Хорошо... Даааа... Ещё!.. </dh>- стонете вы."
              "<br>Вы обильно кончили, и Аня подсовывает страпон к вашему носу: а вы слизываете с него свои выделения.";
    str[19] = "Аня глядит на вас - и вы с наслаждением облизываете страпон";
    if(root->vBody(anus) > 5)
        str[19] += ", чувствуя терпкий вкус собственных соков.";
    else
        str[19] += ".";
    str[19] += "<br>";
    if(root->vBody(anus) > 5)
        str[19] += "Вылизав всё, вы принимаетесь сосать головку.";
    else
        str[19] += "Вы принимаетесь сосать головку,";
    str[19] += "Аня следит за вашими движениями и поучает как правильней сосать. Неожиданно Анька хватает вас за волосы и резко запихивает страпон в горло, так что вы"
               " задохнулись, отмахиваясь от неё.<br><dh>- Ты чё творишь, дура! Я ж так задохнусь! </dh>- зашипели вы на неё. - <dh>Хоть бы предупредила!</dh><br>"
               "<do>- Давай, учись сестрёнка, парням такое нравится!</do> - лыбится эта засранка в ответ.";
    str[20] = "Вы страстно целуетесь с любимой сестрёнкой, как вдруг она отодвигается.<br><do>- Слушай, <<$name[2]>>, я тебя очень люблю, но я не лесбиянка, и не хочу"
              " чтоб между нами такие отношения развивались. А то мне что-то это нравиться начинает...</do> - краснеет неожиданно она. - <do>Да и Ромка, кажется, начинает"
              " меня к тебе ревновать... Ой, проговорилась!</do><br><dh>- Ты что - всё рассказала ему?! Не ожидала от тебя такой подлости!</dh><br><do>"
              "- Да не боись ты, <<$name[2]>>! Это будет нашим маленьким секретом, больше никто не узнает! Клянусь!</do>";
    return str[id];
}

QString SisterSleep::act(int id)
{
    QString act[10];
    act[0] = "Отойти";
    act[1] = "Потрогать";
    act[2] = "Ласкать себя";
    act[3] = "Продолжить";
    act[4] = "Поцеловать Аню";
    act[5] = "Ласкать сестру";
    act[6] = "Убрать руку";
    act[7] = "Сосать страпон";
    return act[id];
}
