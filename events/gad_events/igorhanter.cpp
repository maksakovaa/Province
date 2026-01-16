#include "igorhanter.h"
#include "../../Functions.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"

IgorHanter::IgorHanter(EventHandler* ptr): root(ptr)
{
    boypic = 31;
    dick = 16;
    silaVag = 2;
    finance = 1;
    vneshBoy = 8;
    figurBoy = 1;
    titBoy = 1;
    haerBoy = 3;
    harakBoy = 1;
    izvrat = 0;
}

void IgorHanter::start(QString arg)
{
    root->rendImagePage();
    boyage = root->getAge()+8;
    root->setImage(media(0));
    root->setDesc(str(5));

    int rel = root->gVQuest(hantersIgorQW);
    if(rel < 0) root->addDesc(str(6));
    if(rel >= 0 && rel < 10) root->addDesc(str(7));
    if(rel >= 10 && rel < 20) root->addDesc(str(8));
    if(rel >= 20 && rel < 25) root->addDesc(str(9));
    if(rel >= 25 && rel < 30) root->addDesc(str(10));
    if(rel >= 30 && rel < 35) root->addDesc(str(11));
    if(rel > 35) root->addDesc(str(12));

    int love = root->gVEvent(hantersIgorLove);
    if(love == 1) root->addDesc(str(13));
    if(love == 2) root->addDesc(str(14));
    if(love == 3) root->addDesc(str(15));

    makeActBtn("talk",act(1));
    if(rel >= 10)
    {
        if(love == 0)
            makeActBtn("flirt.1",act(2));
        else
            makeActBtn("take_time",act(3));
    }
    if(love > 0 && root->vStatus(horny) >= 60)
        makeActBtn("harass",act(4));
    int tmp = getRandInt(1,5);
    if(love > 0 && root->vStatus(horny) <= 60 && rel >= 10 && tmp == 1 && root->gVEvent(hantersIgorsex) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny,5);
        root->uVEvent(hantersIgorsex,getRandInt(12,36));
        root->setImage(media(1));
        root->setDesc(str(16));
        makeActBtn("accept_sex",act(5));
        makeActBtn("decline_sex",act(6));
    }
    if(love > 0)
        makeActBtn("dump_guy",act(7));
    makeActBtn("back_to_loc",act(8));
    if(rel < 10 && love > 0)
    {
        root->incTime(5);
        root->sVEvent(hantersIgorLove,0);
        //if(love == 2) bFa = 0;
        root->uVQuest(hantersIgorQW,-10);
        root->setImage(media(2));
        root->setDesc(str(17));
        makeActBtn("back_to_loc",act(9));
    }
    if(love < 2 && rel >= 35 && root->gVEvent(hantersKnowSlut) == 0 /* && bFa < 1*/ && root->getHour() >= 8 && root->getHour() < 20 && root->vStatus(vnesh) >= 40)
    {
        root->incTime(1);
        root->setImage(media(4));
        root->setDesc(str(18));
        makeActBtn("accept_kiss",act(10));
        makeActBtn("decline_kiss",act(11));
    }
}

void IgorHanter::actionHandler(QString action)
{
    if(action == "talk")
    {
        root->incTime(60);
        if(root->gVQuest(hantersIgorQW) < 10)
            root->uVQuest(hantersIgorQW,1);
        root->setImage(media(getRandInt(7,9)));
        if(root->gVQuest(hantersIgorQW) >= 0) root->setDesc(str(19));
        if(root->gVQuest(hantersIgorQW) < 0) root->setDesc(str(20));
        makeActBtn("back_to_loc",act(0));
    }

    if(action == "flirt.1")
    {
        root->incTime(120);
        root->uVStatus(horny,10);
        if(root->gVEvent(hantersKnowSlut) == 0)
        {
            if(root->gVQuest(hantersIgorQW) <= 35)
                root->uVQuest(hantersIgorQW,1);
            if(root->gVQuest(hantersAndreiQW) >= 10)
                root->uVQuest(hantersAndreiQW,-1);
            if(root->gVQuest(hantersSergeiQW) >= 10)
                root->uVQuest(hantersSergeiQW,-1);
        }
        root->setImage(media(getRandInt(10,12)));
        root->setDesc(str(21));
        if(root->gVEvent(hantersIgorLove) == 0 && root->gVQuest(hantersIgorQW) >= 35 && root->gVEvent(hantersKnowSlut) == 0 /*&& bFa == 1 */ && root->vStatus(vnesh) >= 40)
        {
            root->incTime(5);
            root->uVStatus(horny,5);
            root->setImage(media(4));
            root->setDesc(str(22));
            makeActBtn("flirt.1.1",act(10));
            makeActBtn("flirt.1.2",act(11));
        }
        else
            makeActBtn("back_to_loc",act(8));
    }
    if(action == "flirt.1.1")
    {
        root->incTime(5);
        root->uVStatus(horny,5);
        root->sVStatus(mood,100);
        root->sVEvent(hantersIgorLove,1);
        root->uVQuest(hantersIgorQW,1);
        root->setImage(media(5));
        root->setDesc(str(23));
        if(root->vStatus(horny) >= 40)
            makeActBtn("flirt.1.1.1",act(0));
        else
            makeActBtn("flirt.1.1.2",act(0));
    }
    if(action == "flirt.1.1.1")
    {
        root->incTime(5);
        root->setImage(media(6));
        root->setDesc(str(24));
        makeActBtn("HanterLoveSex",act(9));
    }
    if(action == "flirt.1.1.2")
    {
        root->incTime(5);
        root->setImage(media(6));
        root->setDesc(str(25));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "flirt.1.2")
    {
        root->incTime(5);
        root->uVQuest(hantersIgorQW,-50);
        root->setImage(media(13));
        root->setDesc(str(26));
        makeActBtn("back_to_loc",act(12));
    }

    if(action == "take_time")
    {
        root->incTime(120);
        root->uVStatus(horny,10);
        root->sVStatus(mood,100);
        root->uVQuest(hantersIgorQW,1);
        if(root->gVEvent(hantersSergeiLove) > 0 || root->gVEvent(hantersAndreiLove) > 0)
            root->uVEvent(hanterslut,1);
        if(root->gVEvent(hantersSergeiLove) == 0 && root->gVEvent(hantersAndreiLove) == 0)
            root->uVEvent(hanterslut,-1);
//        if(root->gVEvent(hantersIgorLove) == 2) bFa += 1;
        root->setImage(media(getRandInt(14,17)));
        root->setDesc(str(27));
        makeActBtn("back_to_loc",act(8));
    }

    if(action == "harass")
    {
        root->incTime(10);
        root->uVStatus(horny,5);
        root->uVQuest(hantersIgorQW,1);
        root->uVEvent(hantersIgorsex,getRandInt(12,36));
        root->setImage(media(getRandInt(19,23)));
        root->setDesc(str(28));
        makeActBtn("HanterLoveSex",act(9));
    }

    if(action == "accept_sex")
    {
        root->incTime(5);
        root->uVQuest(hantersIgorQW,1);
        root->setImage(media(getRandInt(21,23)));
        root->setDesc(str(31));
        makeActBtn("HanterLoveSex",act(9));
    }
    if(action == "decline_sex")
    {
        root->incTime(5);
        root->uVQuest(hantersIgorQW,-1);
        root->setImage(media(13));
        root->setDesc(str(30));
        makeActBtn("back_to_loc",act(9));
    }
    if(action == "dump_guy")
    {
        root->incTime(5);
        // if(root->gVEvent(hantersIgorLove) == 2)
        //     bFa = 0;
        root->sVEvent(hantersIgorLove,0);
        root->setImage(media(3));
        root->setDesc(str(29));
        makeActBtn("back_to_loc",act(9));
    }
    if(action == "accept_kiss")
    {
        root->incTime(5);
        /*
            $boyA = $boy
            $boybodyA = $boybody
            $boybodA = $boybod
            $boyfaceA = $boyface
            dickA = dick
            silaVagA = silaVag
            financeA = finance
            vneshBoyA = vneshBoy
            $boyCloA = $boyClo
            figurBoyA = figurBoy
            titBoyA = titBoy
            haerBoyA = haerBoy
            harakBoyA = harakBoy
            boyageA = boyage
            boydayA = day
            bfA = 1
            daya = 0
            boyonceA = 0
            izvratA = izvrat
            giftDayA = 0
            giftNumA = 0
            love = 0
            boypicA = boypic
        */
        root->sVEvent(hantersIgorLove,2);
        root->sVStatus(mood,100);
        root->setImage(media(5));
        root->setDesc(str(23));
        if(root->vStatus(horny) >= 40)
            makeActBtn("flirt.1.1.1",act(0));
        else
            makeActBtn("flirt.1.1.2",act(0));
    }
    if(action == "decline_kiss")
    {
        root->incTime(5);
        root->uVQuest(hantersIgorQW,-50);
        root->setImage(media(13));
        root->setDesc(str(26));
        makeActBtn("back_to_loc",act(12));
    }

    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "HanterLoveSex")
        root->eventStart("HanterLoveSex");
}

void IgorHanter::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &IgorHanter::actionHandler);
    root->addActBtn(btn);
}

QString IgorHanter::str(int id)
{
    QString str[32];
    if(id < 21)
    {
        str[0] = "Игорь";
        str[1] = "высокий";
        str[2] = "атлетичный";
        str[3] = "брюнет";
        str[4] = "одет в джинсы и свитер.";
        str[5] = "Игорь один из знакомых вам охотников, он приезжает в гости к Андрею поохотится. Ему " + intQStr(boyage) + " лет. Он не женат и живет в Центре..";
        str[6] = "У вас с ним плохие отношения, похоже он затаил на вас какую-то обиду.";
        str[7] = "У вас с ним нормальные отношения.";
        str[8] = "У вас с ним дружеские отношения.";
        str[9] = "Похоже он вам симпотизирует.";
        str[10] = "Похоже он в вас влюблен.";
        str[11] = "Похоже у вас с ним любовь.";
        str[12] = "У вас с ним любовь.";
        str[13] = "Вы с ним встречаетесь.";
        str[14] = str[0] + " ваш парень.";
        str[15] = str[0] + " ваш муж.";
        str[16] = "Вы подошли к Игорю, чтобы провести время вместе, но он неожиданно впился в ваши губы страстным поцелуем и прошептал:"
                  "<npc>- Света, я хочу тебя.</npc>";
        str[17] = "Вы хотели поговорить с Игорем, но он вас опередил, не дав сказать вам сказать нислова."
                  "<npc>- Света, я понял, что у наших отношений нет будущего, и нам нужно расстаться,</npc> - сказал он, и стараясь не смотреть в вашу сторону, решительно ушел прочь."
                  "<hero>- Ну , может оно и к лучшему,</hero> - подумали вы, уходя в другую сторону.";
        str[18] = "Неожиданно Игорь приблизил к вам свое лицо, вы почувствовали его дыхание на своей коже, еле уловимый аромат его тела, который нежными нотками доносится до вас. Медленно, боясь вас спугнуть, Игорь прикоснулся пальцами к вашей щеке и вы с замиранием сердца почувствовали его губы на своих губах...";
        str[19] = "Вы весело поболтали с Игорем, выслушивая разные интересные истории из его жизни, и рассказывая свои.";
        str[20] = "Вы разговариваете с Игорем. Он хмурится и ведет себя не очень дружелюбно, но все же поддерживает разговор.";
    }
    if(id > 20)
    {
        str[21] = "Вы перекидываетесь с Игорем игривыми взглядами и вовсю кокетничаете. Он рад вашей компании и пару раз вы замечаете на себе его блуждающий недвусмысленный взгляд.";
        str[22] = "Вы мило улыбаетесь Игорю и флиртуете с ним. Неожиданно Игорь приближает к вам свое лицо, вы чувствуете его дыхание на своей коже, чувствуете аромат его тела, который нежными нотками доносится до вас. Медленно, боясь вас спугнуть, Игорь касается пальцами вашей щеки и вы с замиранием сердца наблюдаете как его губы приближаются к вашим...";
        str[23] = "Ваши губы соприкасаются, у вас замирает сердце и дыхание. Игорь нежно целует вас и вы ему отвечаете, сильнее прижимаясь к его губам.";
        str[24] = "<npc>- Светик, я хочу тебя,</npc> - прошептал вам на ухо Игорь, когда ваши губы наконец разомкнулись. Видя , что вы не против, Игорь нежно взял вас за руку и повел за собой.";
        str[25] = "<npc>- Это было восхитительно, Светик,</npc> - прошептал вам на ухо <<$boy>>, когда ваши губы наконец разомкнулись. Вы таете у него в руках, видя его счастливый взгляд и улыбку.";
        str[26] = "<hero>- Нет, Игорь, не нужно этого,<hero> - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
        str[27] = "Вы проводите с Игорем вместе время нежно воркуя, обнимаясь и целуясь. Он рад вашей компании, вы не можете не замечать его полный счастья взгляд, и от этого вам хочется петь и летать.";
        str[28] = "Вы совсем уж внаглую подмигиваете Игорю, томно вздыхаете, проводя язычком по губам и Игорь, все прекрасно понимая, берет вас за руку и ведет за собой.";
        str[29] = "<hero>- Игорь, я решила, что у наших отношений нет будущего, и нам нужно расстаться,</npc> - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
        str[30] = "<hero>- Нет, Игорь, давай не сейчас,<hero> - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
        str[31] = "Улыбнувшись вы подмигиваете Игорю. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    }
    return str[id];
}

QString IgorHanter::act(int id)
{
    QString act[13];
    act[0] = "Далее";
    act[1] = "Поболтать";
    act[2] = "Флиртовать";
    act[3] = "Проводить вместе время";
    act[4] = "Приставать";
    act[5] = "Согласиться";
    act[6] = "Отказаться";
    act[7] = "Расстаться с парнем";
    act[8] = "Отойти";
    act[9] = "Идти";
    act[10] = "Ответить на поцелуй";
    act[11] = "Убрать лицо";
    act[12] = "Уйти";
    return act[id];
}

QString IgorHanter::media(int id)
{
    QString med[24];
    med[0] = "data/npc/gadukino/swamp/IgorHanter.jpg";
    med[1] = "data/actions/backwater/hanterlove1.4.jpg";
    med[2] = "data/actions/backwater/brosil.jpg";
    med[3] = "data/actions/backwater/brosila.jpg";
    med[4] = "data/actions/backwater/hanterkiss1.jpg";
    med[5] = "data/actions/backwater/hanterkiss2.jpg";
    med[6] = "data/actions/backwater/hanterkiss3.jpg";
    med[7] = "data/actions/backwater/talk1.1.jpg";
    med[8] = "data/actions/backwater/talk1.2.jpg";
    med[9] = "data/actions/backwater/talk1.3.jpg";
    med[10] = "data/actions/backwater/hanterflirt1.1.jpg";
    med[11] = "data/actions/backwater/hanterflirt1.2.jpg";
    med[12] = "data/actions/backwater/hanterflirt1.3.jpg";
    med[13] = "data/qwest/gadukino/otel4.jpg";
    med[14] = "data/actions/backwater/hanterlove1.1.jpg";
    med[15] = "data/actions/backwater/hanterlove1.2.jpg";
    med[16] = "data/actions/backwater/hanterlove1.3.jpg";
    med[17] = "data/actions/backwater/hanterlove1.4.jpg";
    med[18] = "data/actions/backwater/hanterflirt2.1.jpg";
    med[19] = "data/actions/backwater/hanterflirt2.2.jpg";
    med[20] = "data/actions/backwater/hanterflirt2.3.jpg";
    med[21] = "data/actions/backwater/hanterflirt2.4.jpg";
    med[22] = "data/actions/backwater/hanterflirt2.5.jpg";
    med[23] = "data/actions/backwater/hanterflirt2.6.jpg";
    return med[id];
}
