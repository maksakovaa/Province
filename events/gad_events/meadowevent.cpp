#include "meadowevent.h"
#include "../../menu/buttons.h"
#include "../eventhandler.h"
#include "../../Functions.h"

MeadowEvent::MeadowEvent(EventHandler* ptr): root(ptr) {}

void MeadowEvent::start(QString arg)
{

}

void MeadowEvent::actionHandler(QString action)
{
    //funcs
    if(action == "mira_mitka") mira_mitka();
    if(action == "mira_gang") mira_gang();
    if(action == "miragopQW11") miragopQW11();
    if(action == "lesb_mira") lesb_mira();
    if(action == "mira_lesb") mira_lesb();
    if(action == "lesb_talk_mira1") lesb_talk_mira1();
    if(action == "lesb_talk_mira2") lesb_talk_mira2();
    if(action == "lesb_talk_mira3") lesb_talk_mira3();
    if(action == "mira_lesb_talk1") mira_lesb_talk1();
    if(action == "mira_lesb_talk2") mira_lesb_talk2();
    if(action == "mira_lesb_talk3") mira_lesb_talk3();
    if(action == "mira_lesb_talk4") mira_lesb_talk4();
    if(action == "mirameadow") mirameadow();

    if(action == "mira_mitka_1")
    {
        root->incTime(5);
        root->uVStatus(horny,25);
        root->setImage(media(1));
        root->setDesc(str(1));
        makeActBtn("mira_mitka_2",act(0));
    }
    if(action == "mira_mitka_2")
    {
        root->incTime(5);
        root->uVStatus(horny,25);
        if(root->gVQuest(miragopQW) == 2)
            root->sVQuest(miragopQW,3);
        root->uVEvent(mirasextimes,1);
        root->setImage(media(2));
        root->setDesc(str(2));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "mira_leab_decline")
    {
        root->incTime(5);
        root->uVStatus(horny,-5);
        root->uVQuest(miraQW,-1);
        root->setImage(media(21));
        root->setDesc(str(7));
        makeActBtn("back_to_loc",act(2));
    }

    if(action == "mira_lesb_talk1_lesb0")
    {
        root->incTime(5);
        root->uVStatus(horny,30);
        root->setImage(media(21));
        root->setDesc(str(16));
        makeActBtn("mira_lesb_talk1_lesb1",act(2));
    }
    if(action == "mira_lesb_talk1_lesb1")
    {
        root->incTime(5);
        root->uVStatus(horny,10);
        root->setImage(media(22));
        root->setDesc(str(17));
        makeActBtn("lickmira_start",act(2));
    }

    if(action == "mira_mastr1")
    {
        root->incTime(2);
        root->uVStatus(horny,5);
        root->setImage(media(24));
        root->setDesc(str(24));
        makeActBtn("mira_mastr2",act(0));
    }
    if(action == "mira_mastr2")
    {
        root->incTime(2);
        root->uVStatus(horny,5);
        root->setImage(media(25));
        root->setDesc(str(25));
        makeActBtn("mira_mastr3",act(0));
    }
    if(action == "mira_mastr3")
    {
        root->incTime(2);
        root->uVStatus(horny,5);
        root->setImage(media(26));
        root->setDesc(str(26));
        makeActBtn("mira_mastr4",act(0));
    }
    if(action == "mira_mastr4")
    {
        root->incTime(2);
        root->uVStatus(horny,10);
        root->setImage(media(27));
        root->setDesc(str(27));
        makeActBtn("mira_mastr5",act(0));
    }
    if(action == "mira_mastr5")
    {
        root->incTime(2);
        root->uVStatus(horny,10);
        root->setImage(media(28));
        root->setDesc(str(28));
        makeActBtn("mira_mastr6",act(0));
    }
    if(action == "mira_mastr6")
    {
        root->incTime(10);
        root->uVStatus(horny,20);
        root->setImage(media(29));
        root->setDesc(str(29));
        makeActBtn("gaddvor",act(1));
    }
    if(action == "mira_mastr8")
    {
        root->incTime(5);
        root->uVStatus(horny,10);
        root->setImage(media(31));
        root->setDesc(str(31));
        makeActBtn("mira_mastr9",act(0));
    }
    if(action == "mira_mastr9")
    {
        root->incTime(2);
        root->uVStatus(horny,5);
        root->setImage(media(32));
        root->setDesc(str(32));
        makeActBtn("mira_mastr10",act(0));
    }
    if(action == "mira_mastr10")
    {
        root->incTime(1);
        root->uVStatus(horny,5);
        root->setImage(media(33));
        root->setDesc(str(33));
        makeActBtn("mira_mastr11",act(0));
    }
    if(action == "mira_mastr11")
    {
        root->incTime(10);
        root->uVStatus(horny,20);
        root->setImage(media(34));
        root->setDesc(str(34));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "mira_mastr13")
    {
        root->incTime(2);
        root->uVStatus(horny,10);
        root->setImage(media(36));
        root->setDesc(str(36));
        makeActBtn("mira_mastr14",act(0));
    }
    if(action == "mira_mastr14")
    {
        root->incTime(5);
        root->uVStatus(horny,15);
        root->setImage(media(37));
        root->setDesc(str(37));
        makeActBtn("mira_mastr15",act(0));
    }
    if(action == "mira_mastr15")
    {
        root->incTime(1);
        root->uVStatus(horny,5);
        root->setImage(media(38));
        root->setDesc(str(38));
        makeActBtn("mira_mastr16",act(0));
    }
    if(action == "mira_meadow16")
    {
        root->incTime(10);
        root->uVStatus(horny,30);
        root->setImage(media(39));
        root->setDesc(str(39));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "miragop1.1")
    {
        root->incTime(5);
        root->uVStatus(horny,25);
        root->setImage(media(1));
        root->setDesc(str(41));
        makeActBtn("miragop1.2",act(0));
    }
    if(action == "miragop1.2")
    {
        root->incTime(5);
        root->uVStatus(horny,15);
        root->setImage(media(2));
        root->setDesc(str(42));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "miragop2.1")
    {
        root->incTime(5);
        root->uVStatus(horny,getRandInt(15,30));
        root->uVEvent(mirasextimes,1);
        root->setImage(media(42));
        root->setDesc(str(45));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "miragop3.1")
    {
        root->incTime(5);
        root->uVStatus(horny,getRandInt(15,30));
        root->uVEvent(mirasextimes,1);
        root->setImage(media(4));
        root->setDesc(str(47));
        makeActBtn("gaddvor",act(1));
    }

    if(action == "gaddvor")
        root->changeLoc(lgaddvor,30);
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "mirakiss")
        root->eventStart("mirasex","mirakiss");
    if(action == "foreplay")
        root->eventStart("mirasex","foreplay");
    if(action == "miralick_first")
        root->eventStart("mirasex","miralick_first");
    if(action == "lickmira_first")
        root->eventStart("mirasex","lickmira_first");
    if(action == "lickmira_start")
        root->eventStart("mirasex","lickmira_start");
}

void MeadowEvent::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MeadowEvent::actionHandler);
    root->addActBtn(btn);
}

QString MeadowEvent::str(int id)
{
    QString str[60];
    str[0] = "Выйдя на поляну вы вдруг замечаете Миру с Митькой. Они болтают между собой, попутно раздеваясь, но о чем именно они говорят, вам не удается услышать из-за растояния.";
    str[1] = "Через пару минут Мирослава ложится перед Митькой на покрывало и призывно расставляет перед ним ноги. Тот, не заставляя себя ждать, тут же пристраивается у нее между ног и начинает грубо и сильно вколачивать в нее свой член, отчего она начинает громко и охать и подвизгивать.";
    str[2] = "Минуть через пятнадцать Митька наконец кончает Мирославе на живот и еще немного полежав, они начинают собираться...";
    str[3] = "Миры за ихними телами почти не видно, только кусок голого зада да покачивающиеся в кроссовках ноги. Вы с полчаса наблюдаете за тем, как мужики по очереди ебут безвольную и уставшую Мирославу, но потом вам надоедает и вы решаете уйти...";
    str[4] = "Вы долго молчите, не зная с чего начать, а Мирослава все это время смотрит себе под ноги и усиленно краснеет. Наконец вы решаетесь заговорить и Мира, запинаясь и по-прежнему не смотря вам в глаза, говорит, что сама не знает, что на нее тогда нашло, но она себя не контролировала. То ли это она напилась до такой, то ли еще чего, но она теперь сквозь землю готова провалиться со стыда. Вы кое-как успокаиваете ее и говорите, что всякое в жизни бывает, надо просто переступить и жить дальше. Мира искренне благодарит вас за поддержку, но в глаза все равно не смотрит...";
    str[5] = "На поляне вы разу подошли к Мире."
             "<hero>- Мир, я хочу тебя,</hero> - прошептали вы ей на ухо и страстно поцеловали её в губы.";
    str[6] = "На поляне к вам подошла Мира, озорно улыбаясь."
             "<npc>- Светуля, пошалим?</npc> - шепнула она вам на ухо и прижав вас к дереву, впилась в губы страстным поцелуем.";
    str[7] = "Вам пришлось приложитить немало сил, чтобы вырваться из её объятий."
             "<hero>- Мир, давай не сейчас,</hero> - сказали вы, видя немой вопрос в её глазах. <hero>- Настроения нет совсем.</hero>"
             "<npc>- Ну ты и бяка,</npc> - надула она обиженно губки в ответ.";
    str[8] = "Вы долго молчите, глядя на Миру, не зная как начать разговор. Но потом все таки решаетесь."
             "<hero>- Мира, ты ведь уже всем пацанам в нашей компашке дала,</hero> - начали вы. <hero>- Так?</hero>"
             "<npc>- Угу,</npc> - немного смутившись ответила Мирослава и с подозрением уставилась на вас. <npc>- А что?</npc>"
             "<hero>- Да я тут подумала просто, всем дала, всех обслужила, а подругу забыла,</hero> - с укором в голосе произнесли вы."
             "<npc>- Так ты же не парень, как тебя обслужить то?</npc> - удивилась Мира."
             "<hero>- А то ты маленькая и не знаешь, как это девочки девочкам доставляют удовольствие,</npc> - ответили вы ей."
             "<npc>- Но я же не такая, не эта... эээ... не лесбиянка,</npc> - округлила глаза Мира. Но по раскрасневшимся щекам и блеску в глазах, вы поняли, что сама мысль, что она будет отлизывать девочке очень её возбудила."
             "<hero>- Не ломайся Мирка, тебе это не идет,</hero> - продолжили вы давить на неё. <hero>- Короче, или ты сейчас мне делаешь приятно, или я ухожу. Но тогда тебе останется общаться только с хуями деревенских мужиков, про меня можешь забыть.</hero>"
             "Мира задумалась, смешно нахмурив лоб. Но это длилось не долго, возбуждение и перспектива потерять подругу сделали свое дело."
             "<npc>- Хорошо Света, я сделаю это,</npc> - сказала она опускаясь на колени.";
    str[9] = "Вы долго разглядываете Миру с ехидной улыбкой на губах, потом начинаете разговор."
             "<hero>- Ну что, Мирка, поздравляю,</hero> - сказали вы. <hero>- Ты теперь такая же шлюха, как и я. Всем пацанам дала. Так?</hero>"
             "Она попыталась отмолчаться, но вас это не устроило."
             "<hero>- Так или нет?</hero> - продолжили вы настаивать на ответе."
             "<npc>- Ну так,</npc> - не хотя признала она."
             "<hero> - А ты догадываешься, что это значит?</hero> - продолжили вы вкрадчивым голосом."
             "<npc>- Что?</npc> - жутко краснея спросила Мира, хотя явно уже догадывалась куда вы клоните."
             "<hero>- Пора должок возвращать,</hero> - торжествующим тоном ответили вы и оперевшись на дерево, поманили её пальцем. <hero>- Можешь приступать.</hero>"
             "Мира колебалась еще пару мгновений, будто обдумывая что-то, а потом опустилась перед вами на колени.";
    str[10] = "Вы облокотились на дерево и поманили Миру пальцем."
              "<hero>- Нужно поработать язычком Мира,</hero> - сказали вы. <hero>- Приступай.</hero>"
              "Она сразу, уже привычно, опустилась перед вами на колени.";
    str[11] = "На поляне вы встретили Миру. Увидев вас, она тут же подошла с хитрой улыбкой на губах.";
    str[12] = "Когда вы пришли на поляну, Мира тут же подошла к вам с хитрой улыбкой на губах.";
    str[13] = "<npc>- Света, ты ведь уже всем пацанам в нашей компашке дала,</npc> - начала она. <npc>- Так?</npc>"
              "Вы попытались отмолчаться, но это не устроило Миру."
              "<npc>- Так или нет?</npc> - продолжала настаивать она на ответе."
              "<hero>- Ну так, - не хотя признали вы."
              "<npc>- Да я тут подумала просто, всем дала, всех обслужила, а подругу забыла,</npc> - продолжила Мира глядя вам в глаза.";
    str[14] = "<hero>- Так ты же не парень, как тебя обслужить то?</hero> - удивилась вы."
              "<npc>- А то ты маленькая и не знаешь, как это девочки девочкам доставляют удовольствие,</npc> - ответили она вам.";
    str[15] = "Вы, хотя уже догадывались куда она клонит, но все равно медлили с ответом."
              "<npc>- Да ладно, не ломайся Светик, тебе это не идет,</npc> - продолжила она давить устраиваться поудобнее на ближайшем камне."
              "<hero>- Хорошо Мира, я сделаю это,</hero> - сказали вы опускаясь на колени."
              "<hero>- В конце концов почему бы не сделать подруге приятно?<hero> - подумали вы про себя.";
    str[16] = "От этих слов вы ошарашено уставились на Миру."
              "<hero>- Но я же не такая, не эта... эээ... не лесбиянка,</hero> - попытались отнекиваться вы. Но сама мысль, что вы будете отлизывать девочке, прямо здесь, посреди поляны, заставляла вашу писю предательски зазудеть.";
    str[17] = "Вы еще надеялись, глядя на Миру, что она передумает."
              "<npc>- Да ладно, не ломайся Светик,</npc> - сказала Мира, взяв вас за майку и потянув за собой к ближайшему камню. <npc>- Маленькие шлюшки должны всегда доставлять радость своим подругам.</npc>"
              "Устроившись по удобнее она нетерпеливо посмотрела на вас:"
              "<npc>- Ну что ты медлишь, я жду.</npc>"
              "<hero>- Хорошо Мира, я сделаю это,</hero> - сдались наконец вы, опускаясь на колени."
              "<hero>- В конце концов почему бы не сделать подруге приятно?<hero> - думая про себя.";
    str[18] = "Когда вы пришли на поляну, Мира тут же подошла к вам с хитрой улыбкой на губах."
              "<npc>- Ну что, Светик, поздравляю,</npc> - сказала она. <npc>- Ты теперь такая же шлюха, как и я. Всем пацанам дала. Так?</npc>"
              "Вы попытались отмолчаться, но это не устроило Миру."
              "<npc>- Так или нет?</npc> - продолжала настаивать она на ответе."
              "<hero>- Ну так,</hero> - не хотя признали вы."
              "<npc>- А ты догадываешься, что это значит?</npc> - продолжила Мира вкрадчивым голосом."
              "<hero> - Что?</hero> - спросили вы, хотя уже догадывались куда она клонит."
              "<npc>- Пора должок возвращать,</npc> - торжествующим тоном ответила Мира и стала устраиваться поудобнее на ближайшем камне. <npc>- Можешь приступать.</npc>"
              "<hero>- Ну что же, все логично,</hero> - подумали вы опускаясь перед ней на колени.";
    str[19] = "На поляне вы встретили Миру. Увидев вас, она тут же подошла к вам с возбужденным лицом."
              "<npc>- А вот ты где Светик, а я тебя ищу, ищу,</npc> - сказала она. <npc>- Нужно поработать язычком.</npc>"
              "И начала устраиваться поудобнее.";
    str[20] = "Когда вы пришли на поляну, Мира тут же повернулась к вам с возбужденным лицом."
              "<npc>- Нужно поработать язычком Светик,</npc> - сказала она и начала устраиваться поудобнее. <npc>- Приступай.</npc>";
    str[21] = "Вы уже привычно опустились перед ней на колени.";
    str[22] = "Идя по деревне вы встретили Миру. Увидев вас, она тут же подошла к вам с возбужденным лицом."
              "<npc>- А вот ты где Светик, а я тебя ищу, ищу,</npc> - сказала она. <npc>- Пошли-ка прогуляемся на нашу поляну.</npc>"
              "И схватив вас за руку, буквально поволокла за собой. Вы шли вслед за Мирой, слыша впереди её возбужденное сопение, прекрасно понимая, зачем она вас туда ведет. Придя на поляну Мира тут же повернулась к вам с возбужденным лицом."
              "<npc>- Нужно поработать язычком Светик,</npc> - сказала она и начала устраиваться поудобнее. <npc>- Приступай.</npc>"
              "Вы уже привычно опустились перед ней на колени.";
    str[23] = "Вы уже собрались было к ней подойти, но тут с удивлением замечаете, как она расстегивает штаны... Вы, повинуясь извечному женскому любопытству, решаете понаблюдать за ней...";
    str[24] = "Мирослава, с силой приподнимая трусики так, что они врезаются ей между половых губ, воровато оглядывается по сторонам, но вас, конечно же, из-за густых зарослей не замечает, а потому продолжает...";
    str[25] = "Она пару секунд медленно гладит рукой себя по животе, а после, уставившись взглядом куда-то в пустоту, так же неспешно ныряет ею себе в трусы, начиная поглаживать промежность.";
    str[26] = "Внезапно она вытягивает из промежности руку и заглядываете себе в трусы, что-то там высматривая.";
    str[27] = "Но вскоре ей это надоедает и она снимает с себя куртку, а за ней и кофточку, обнажая вам свои небольшие упругие грудки.";
    str[28] = "Сняв кофту, она зачем-то снова надевает на себя куртку и запустив одну руку себе в трусики, другой начинает ласкать грудь.";
    str[29] = "Через минуту она приваливается спиной к ближайшему дереву, ее штаны спадают до колен и она, продолжая одной рукой мять и тискать свою грудь, другой доводит себя до оргазма. Вы смотрите еще пару минут в надежде на продолжение, но Мира уже приходит в себя и начинает одеваться, поэтому вы решаете поспешно ретироваться...";
    str[30] = "Мира стоит, прислонившись спиной к дереву и ласкает себя.";
    str[31] = "Она несколько минут продолжает играть с собой, а потом прекращает и пару мгновений задумчиво смотрит на валяющееся рядом бревно...";
    str[32] = "Наконец, приняв решение, она подходит к нему и начинает снимать с себя трусики.";
    str[33] = "Сняв трусы, она осторожно присаживается на бревно и пробует на нем немного покачаться, проверяя, видать, на прочность...";
    str[34] = "Удостоверившись, что нечаянно не свалится с него, Мира начинает ласкать себя, при этом не забывая оглядываться по сторонам, пока, наконец, не доводит себя до оргазма... Вы смотрите еще пару минут в надежде на продолжение, но Мира уже приходит в себя и начинает одеваться, поэтому вы решаете поспешно ретироваться...";
    str[35] = "Вы успеваете как раз на самое интересное. Мира стоит на пеньке, возле которого валяется растеленное покрывало, и задрав повыше блузку, наслаждается прохладным ветерком, поглаживая рукой себе промежность.";
    str[36] = "Но ей это вскоре надоедает и она, словно нарочно, повернувшись к вам попкой, стаскивает с себя юбку.";
    str[37] = "Сделав это, она присаживается на пенек и продолжает себя ласкать, но через пару минут и этого ей оказывается мало...";
    str[38] = "Пройдясь от пня до покрывала, Мира снимает с себя кофточку и остается только в одних трусиках.";
    str[39] = "Которые сразу же снимает вслед за блузкой и оставшись в чем мать родила, на корточках доводит себя до оргазма. Вы смотрите еще пару минут в надежде на продолжение, но Мира уже приходит в себя и начинает одеваться, поэтому вы решаете поспешно ретироваться...";
    str[40] = "Они болтают между собой, попутно раздеваясь, но о чем именно они говорят, вам не удается услышать из-за растояния.";
    str[41] = "Через пару минут Мирослава ложится перед Митькой на покрывало и призывно расставляет перед ним ноги. Тот, не заставляя себя ждать, тут же пристраивается у нее между ног и начинает грубо и сильно вколачивать в нее свой член, отчего она начинает громко и охать и подвизгивать.";
    str[42] = "Минуть через пятнадцать Митька наконец кончает Мирославе на живот и еще немного полежав, они начинают собираться...";
    str[43] = "Мирка прыгает задницей на митькином члене, каждый раз шлепаясь ягодицами о его бедра, и громко постанывает.";
    str[44] = "Мирка, раздвинув руками ягодицы, стоит на четвереньках и громко охает, когда Митька, полностью вынимая, вгоняет в ее распахнутую задницу свой член.";
    str[45] = "Через пару минут Митька сильно шлепает ее по заднице и Мира быстро разворачивается, встает перед ним на колени и далеко высунув язык, принимает на свое лицо его теплую сперму...";
    str[46] = "Она с увлечением сосет его член и видит ямки на ее щеках, когда она всасывает его в свою глотку...";
    str[47] = "Но, видимо, вы немного опоздали, потому что уже через пару минут Колямба кладет руку Мирославе на затылок и одним резком рывком насаживает на себя. Она сначала давится и кашляет отнеожиданности, но потом все же справляется с рвотными позывами и высунув немного язык, послушно глотает его сперму...";
    str[48] = "Она в одних шлепанцах стоит раком, оттопырив как раз в вашу сторону свою задницу, и громко охает, когда Колямба шлепает ее по промежности своими яйцами, вгоняя в ее влагалище свой член. Мирослава скребет руками по земле и выгибается как кошка, при этом что-то в перерывах между оханьями говоря Колямбе. Но тот, кажется. не обращает на это совершенно никакого внимания, продолжая долбить ее в киску, и вскоре доводит девушку до оргазма, а через минуту кончает и сам...";
    str[49] = "Васян с энтузиазмом вгоняет член в рот привязанной к дереву Мирославы. Та давится и кашляет, но в то же время сама двигает головой навстречу члену. Через пару минут Васян откидывает назад голову и с блаженным рыком кончает ей в рот...";
    str[50] = "Полностью голая Мирослава, согнувшись, стоит перед Васяном и усиленно подставляет ему попку, в которую он и вгоняет свой член. Судя по ее похотливым стонам, ей вполне нравится, что ее имеют в задницу, но уже через пару минут Васян вынимает из нее свой член и спускает ей на ягодицы...";
    str[51] = "Они оба совершенно голые и Мира, далеко оттопырив попку, с чувством отсасывает кайфующему Васяну. Через пару минуту вы видите, как Мирослава насаживается головой на его член и затихает, глотая сперму...";
    str[52] = "Они оба совершенно голые и Мира с похотливыми визгами, словно бешеная, скачет на Васькином члене. Тот долго такого темпа не выдерживает и бесцеремонно сбросив с себя наездницу, кончает ей на ягодицы...";
    str[53] = "Мира на коленях стоит между тремя дружками и с удовольствием отсасывает их члены. Вы наблюдаете, как они по очереди спукают ей кто в рот, кто на грудь, а кто просто на лицо...";
    str[54] = "Мира на корточках сидит между тремя дружками и с удовольствием чавкает их членами. Вы наблюдаете, как они по очереди спукают ей кто в рот, а кто просто на лицо...";
    str[55] = "Мира на корточках сидит перед одним из пацанов и как раз принимает себе в рот его сперму. Облизав и спрятав в штаны его член, она то же самое прожелывает с другим...";
    str[56] = "Пацаны, вдвоем трахая Миру в рот и в киску, о чем-то со смехом разговаривают между собой. Мирослава же вторит им своими стонами и плямканьями... Минут через пятнадцать они заканчивают и начинают собираться...";
    str[57] = "Все трое почти голые и одному из них Мира как раз отсасывает, а второй, судя по всему, уже кончил, а потому просто лапает ее грудь и шебуршит рукой у нее между похотливо рассталвенных ног...";
    str[58] = "Миры за ихними телами почти не видно, только кусок голого зада да покачивающиеся в кроссовках ноги. Вы с полчаса наблюдаете за тем, как мужики по очереди ебут безвольную и уставшую Мирославу, но потом вам надоедает и вы решаете уйти...";
    str[59] = "Она стоит на четвереньках к вам спиной и болезненно, но довольно постанывая, дрочит свою попку кочаном кукурузы.";
    return str[id];
}

QString MeadowEvent::act(int id)
{
    QString act[5];
    act[0] = "Смотреть";
    act[1] = "Уйти";
    act[2] = "Далее";
    act[3] = "Согласиться";
    act[4] = "Отказаться";
    return act[id];
}

QString MeadowEvent::media(int id)
{
    QString med[44];
    if(id < 21)
    {
        med[0] = "data/sex/mira/MiraMeadowSex.jpg";
        med[1] = "data/sex/mira/MiraMeadowSex1.jpg";
        med[2] = "data/sex/mira/MiraMeadowSex2.jpg";
        med[3] = "data/sex/mira/MiraMeadowBJ.jpg";
        med[4] = "data/sex/mira/MiraMeadowBJ1.jpg";
        med[5] = "data/sex/mira/MiraMeadowBJ2.jpg";
        med[6] = "data/sex/mira/MiraMeadowBJ3.jpg";
        med[7] = "data/sex/mira/MiraMeadowBJ4.jpg";
        med[8] = "data/sex/mira/MiraMeadowBJ5.jpg";
        med[9] = "data/sex/mira/MiraMeadowBJ6.jpg";
        med[10] = "data/sex/mira/MiraMeadowBJ7.jpg";
        med[11] = "data/sex/mira/MiraMeadowBJ8.jpg";
        med[12] = "data/sex/mira/MiraMeadowBJ9.jpg";
        med[13] = "data/sex/mira/MiraMeadowBJ10.jpg";
        med[14] = "data/sex/mira/MiraMeadowBJ11.jpg";
        med[15] = "data/sex/mira/MiraMeadowBJ12.jpg";
        med[16] = "data/sex/mira/mirakiss1.jpg";
        med[17] = "data/sex/mira/mirakiss2.jpg";
        med[18] = "data/sex/mira/mirakiss3.jpg";
        med[19] = "data/sex/mira/mirakiss4.jpg";
        med[20] = "data/sex/mira/mira_lesb_talk.jpg";
    }
    if(id > 20 && id < 41)
    {
        med[21] = "data/sex/mira/mira_lesb_talk2.jpg";
        med[22] = "data/sex/mira/mira_lesb_talk3.jpg";
        med[23] = "data/sex/mira/MiraMeadowMastr.jpg";
        med[24] = "data/sex/mira/MiraMeadowMastr1.jpg";
        med[25] = "data/sex/mira/MiraMeadowMastr2.jpg";
        med[26] = "data/sex/mira/MiraMeadowMastr3.jpg";
        med[27] = "data/sex/mira/MiraMeadowMastr4.jpg";
        med[28] = "data/sex/mira/MiraMeadowMastr5.jpg";
        med[29] = "data/sex/mira/MiraMeadowMastr6.jpg";
        med[30] = "data/sex/mira/MiraMeadowMastr7.jpg";
        med[31] = "data/sex/mira/MiraMeadowMastr8.jpg";
        med[32] = "data/sex/mira/MiraMeadowMastr9.jpg";
        med[33] = "data/sex/mira/MiraMeadowMastr10.jpg";
        med[34] = "data/sex/mira/MiraMeadowMastr11.jpg";
        med[35] = "data/sex/mira/MiraMeadowMastr12.jpg";
        med[36] = "data/sex/mira/MiraMeadowMastr13.jpg";
        med[37] = "data/sex/mira/MiraMeadowMastr14.jpg";
        med[38] = "data/sex/mira/MiraMeadowMastr15.jpg";
        med[39] = "data/sex/mira/MiraMeadowMastr16.jpg";
        med[40] = "data/sex/mira/MiraMeadowAnal.jpg";
    }
    if(id > 40)
    {
        med[41] = "data/sex/mira/MiraMeadowAnal1.jpg";
        med[42] = "data/sex/mira/MiraMeadowAnal2.jpg";
        med[43] = "data/sex/mira/MiraMeadowS.jpg";
    }
    return med[id];
}

void MeadowEvent::mira_mitka()
{
    root->incTime(5);
    root->uVStatus(horny,15);
    root->uVSC(voyeurism,1);
    root->setImage(media(0));
    root->setDesc(str(0));
    makeActBtn("mira_mitka_1",act(0));
}

void MeadowEvent::mira_gang()
{
    root->incTime(30);
    root->uVStatus(horny,25);
    root->uVQuest(miragopQW,1);
    root->uVEvent(mirasextimes,1);
    root->uVSC(voyeurism,1);
    root->setImage(media(15));
    root->setDesc(str(3));
    makeActBtn("gaddvor",act(1));
}

void MeadowEvent::miragopQW11()
{
    root->incTime(5);
    root->uVStatus(horny,10);
    root->sVQuest(miragopQW,12);
    root->eventStart("Miroslava","miraclothes");
    root->setDesc(str(4));
    makeActBtn("back_to_loc",act(1));
}

void MeadowEvent::lesb_mira()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->sVEvent(miraday,root->getDay());
    root->sVEvent(mirahorny,getRandInt(0,80));
    root->setImage(media(16));
    root->setDesc(str(5));
    if(root->gVEvent(mirahorny) < 20) makeActBtn("mirakiss",act(2));
    if(root->gVEvent(mirahorny) >= 20) makeActBtn("foreplay",act(2));
}

void MeadowEvent::mira_lesb()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->sVEvent(miraday,root->getDay());
    root->sVEvent(mirahorny,getRandInt(40,80));
    root->setImage(media(19));
    root->setDesc(str(6));
    if(root->vStatus(horny) < 20) makeActBtn("mirakiss",act(3));
    if(root->vStatus(horny) >= 20) makeActBtn("foreplay",act(3));
    if(root->vStatus(horny) < 40) makeActBtn("mira_leab_decline",act(4));
}

void MeadowEvent::lesb_talk_mira1()
{
    root->incTime(5);
    if(root->vStatus(horny) < 40)
        root->sVStatus(horny,40);
    else
        root->uVStatus(horny,5);
    root->uVSkill(domination,1);
    root->eventStart("Miroslava","miraclothes");
    root->setDesc(str(8));
    makeActBtn("miralick_first",act(2));
}

void MeadowEvent::lesb_talk_mira2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->sVEvent(mirasex,2);
    root->eventStart("Miroslava","miraclothes");
    root->addDesc(str(9));
    makeActBtn("miralick_first",act(2));
}

void MeadowEvent::lesb_talk_mira3()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->uVSkill(domination,1);
    root->eventStart("Miroslava","miraclothes");
    root->setDesc(str(10));
    makeActBtn("miralick_first",act(2));
}

void MeadowEvent::mira_lesb_talk1()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->uVSkill(domination,-1);
    root->sVEvent(mirahorny,getRandInt(0,80));
    root->setImage(media(20));
    if(root->gVEvent(mirainmeadow) == 0)
        root->setDesc(str(11));
    if(root->gVEvent(mirainmeadow) == 1)
        root->setDesc(str(12));
    root->addDesc(str(13));
    if(root->vSC(lesbianSex) == 0)
    {
        root->addDesc(str(14));
        makeActBtn("mira_lesb_talk1_lesb0",act(2));
    }
    else
    {
        root->addDesc(str(15));
        makeActBtn("lickmira_first",act(2));
    }
}

void MeadowEvent::mira_lesb_talk2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->sVEvent(mirasex,2);
    root->sVEvent(mirahorny,getRandInt(0,80));
    root->setImage(media(20));
    root->setDesc(str(18));
    makeActBtn("lickmira_first",act(2));
}

void MeadowEvent::mira_lesb_talk3()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->uVSkill(domination,-1);
    root->sVEvent(mirahorny,getRandInt(40,80));
    root->sVEvent(miraday,root->getDay());
    root->setImage(media(22));
    if(root->gVEvent(mirainmeadow) == 0)
        root->setDesc(str(19));
    else
        root->setDesc(str(20));
    root->addDesc(str(21));
    makeActBtn("lickmira_first",act(2));
}

void MeadowEvent::mira_lesb_talk4()
{
    root->incTime(20);
    root->uVStatus(horny,5);
    root->sVEvent(mirahorny,getRandInt(40,80));
    root->sVEvent(miraday,root->getDay());
    root->uVSkill(domination,-1);
    root->eventStart("Miroslava","miraclothes");
    root->setDesc(str(22));
    makeActBtn("lickmira_first",act(2));
}

void MeadowEvent::mirameadow()
{
    root->incTime(2);
    root->uVSC(voyeurism,1);
    int temp = getRandInt(0,9);
    if(root->gVEvent(meadow) == 3 && root->gVEvent(mirainmeadow) == 0 && root->getSunWeather() >= 0)
    {
        if(root->gVEvent(mirasextimes) < 15 && temp == 0)
        {
            if(root->getTemp() >= 15 && root->getTemp() < 25)
            {
                root->incTime(2);
                root->setImage(media(23));
                root->setDesc(str(23));
                makeActBtn("mira_mastr1",act(0));
            }
            else if(root->getTemp() >= 25 && root->getTemp() < 30)
            {
                root->incTime(2);
                root->uVStatus(horny,10);
                root->setImage(media(30));
                root->setDesc(str(30));
                makeActBtn("mira_mastr8",act(0));
            }
            else if(root->getTemp() >= 30)
            {
                root->incTime(2);
                root->setImage(media(35));
                root->setDesc(str(35));
                makeActBtn("mira_mastr13",act(0));
            }
        }
        if(root->getTemp() >= 20)
        {
            if(root->gVQuest(miragopQW) >= 2 && temp == 1)
            {
                root->incTime(2);
                root->uVStatus(horny,15);
                root->setImage(media(0));
                root->setDesc(str(40));
                makeActBtn("miragop1.1",act(0));
            }
            else if(root->gVQuest(miragopQW) >= 8 && temp == 2)
            {
                root->incTime(2);
                root->uVStatus(horny,getRandInt(15,30));
                if(getRandInt(0,1) == 0)
                {
                    root->setImage(media(40));
                    root->setDesc(str(43));
                }
                else
                {
                    root->setImage(media(42));
                    root->setDesc(str(44));
                }
                makeActBtn("miragop2.1",act(0));
            }
            else if(root->gVQuest(miragopQW) >= 11 && temp == 3)
            {
                root->incTime(2);
                root->uVStatus(horny,15);
                if(root->getTemp() < 20)
                {
                    root->setImage(media(3));
                    root->setDesc(str(46));
                    makeActBtn("miragop3.1",act(0));
                }
                else
                {
                    root->incTime(5);
                    root->uVStatus(horny,30);
                    root->uVEvent(mirasextimes,1);
                    root->setImage(media(5));
                    root->setDesc(str(48));
                    makeActBtn("gaddvor",act(1));
                }
            }
            else if(root->gVQuest(miragopQW) >= 11 && temp == 4)
            {
                root->incTime(5);
                root->uVStatus(horny,10);
                if(root->getTemp() < 25)
                {
                    root->incTime(5);
                    root->uVStatus(horny,50);
                    root->uVEvent(mirasextimes,1);
                    root->setImage(media(8));
                    root->setDesc(str(49));
                    makeActBtn("gaddvor",act(1));
                }
                else
                {
                    root->incTime(5);
                    root->uVStatus(horny,40);
                    root->uVEvent(mirasextimes,1);
                    root->setImage(media(9));
                    root->setDesc(str(50));
                    makeActBtn("gaddvor",act(1));
                }
            }
            else if(root->gVQuest(miragopQW) >= 11 && temp == 5)
            {
                root->incTime(5);
                root->uVStatus(horny,20);
                if(root->getTemp() < 25)
                {
                    root->incTime(5);
                    root->uVStatus(horny,40);
                    root->uVEvent(mirasextimes,1);
                    root->setImage(media(6));
                    root->setDesc(str(51));
                    makeActBtn("gaddvor",act(1));
                }
                else
                {
                    root->incTime(5);
                    root->uVStatus(horny,30);
                    root->setImage(media(7));
                    root->setDesc(str(52));
                    makeActBtn("gaddvor",act(1));
                }
            }
            else if(root->gVQuest(miragopQW) >= 11 && temp == 6)
            {
                root->incTime(5);
                root->uVStatus(horny,40);
                root->uVEvent(mirasextimes,1);
                if(root->getTemp() < 25)
                {
                    root->setImage(media(10));
                    root->setDesc(str(53));
                }
                else
                {
                    root->setImage(media(11));
                    root->setDesc(str(54));
                }
                makeActBtn("gaddvor",act(1));
            }
            else if(root->gVQuest(miragopQW) >= 11 && temp == 7)
            {
                root->incTime(5);
                root->uVStatus(horny,25);
                if(root->gVQuest(miragopQW) < 20)
                    root->uVQuest(miragopQW,1);
                if(root->getTemp() < 25)
                {
                    root->setImage(media(14));
                    root->setDesc(str(55));
                }
                else if(root->getTemp() >=25 && root->getTemp() < 30)
                {
                    root->setImage(media(13));
                    root->setDesc(str(56));
                }
                else
                {
                    root->setImage(media(12));
                    root->setDesc(str(57));
                }
                makeActBtn("gaddvor",act(1));
            }
            else if(root->gVQuest(miragopQW) > 33 && temp == 8)
            {
                root->incTime(5);
                root->uVStatus(horny,25);
                root->uVQuest(miragopQW,1);
                root->uVEvent(mirasextimes,1);
                root->setImage(media(15));
                root->setDesc(str(58));
                makeActBtn("gaddvor",act(1));
            }
            else if(root->gVQuest(miragopQW) >= 20 && temp == 9)
            {
                root->incTime(10);
                root->uVStatus(horny,25);
                root->setImage(media(43));
                root->setDesc(str(59));
                makeActBtn("gaddvor",act(1));
            }
        }
    }
}
