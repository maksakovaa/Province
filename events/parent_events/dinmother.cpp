#include "dinmother.h"
#include "../../menu/buttons.h"
#include "../../game.h"
#include "../../Functions.h"

DinMother::DinMother(Game* ptr): root(ptr) {}

void DinMother::start(QString arg)
{
    if(arg == "talk")
        talk();
    else if (arg == "check_talktime")
        check_talktime();
    else if(arg == "clothes")
        clothes();
    else if(arg == "piercing")
        piercing();
    else if(arg == "hair")
        hair();
    else if(arg == "virgin_check")
        virgin_check();
    else if(arg == "money_talk")
        money_talk();
    else if(arg == "cloth_talk")
        cloth_talk();
    else if(arg == "tampon_talk")
        tampon_talk();
    else if(arg == "cum_talk")
        cum_talk();
    else
        worry();
}

void DinMother::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"DinMother");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &DinMother::actionHandler);
    root->addActions(btn);
}

void DinMother::actionHandler(QString action)
{
    if(action == "momSorry")
    {
        root->vEvent(motherSorryDay) = root->getDay();
        root->gNPC(mother).talk_count += 1;
        root->incTime(getRandInt(10,15));
        root->changeRep('+',mother,10);
        if(root->gNPC(mother).relation <= 20)
            root->addText(str(91));
        else
            root->addText(str(92));
        makeActBtn("go_out",act(0));
    }
    if(action == "pirsANothing")
    {
        root->addText(str(9));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "showPirsA")
    {
        root->vEvent(pirsAmother) = 1;
        root->setImage(media(0));
        root->setText(str(10));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "pirsBlikeIt")
    {
        root->vEvent(pirsBmother) = 1;
        root->setImage(media(1));
        root->setText(str(12));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "virginGoGin")
    {
        root->incTime(getRandInt(20,40));
        root->setImage(media(11));
        root->setText(str(17));
        root->vEvent(Gspravka) = 7;
        if(root->vBody(vagina) > 0)
        {
            root->vEvent(GspravkaT) = 2;
            root->addText(str(18));
        }
        else
        {
            root->vEvent(GspravkaT) = 1;
            root->addText(str(19));
        }
        makeActBtn("back_to_loc",act(0));
    }

    if(action == "panhandle")
    {
        root->incTime(5);
        root->rendNpcProfile(mother);
        root->setText(str(26));
        if(root->repGet() == 4)
        {
            root->addText(str(27));
            makeActBtn("go_out",act(0));
            return;
        }
        int rel = root->gNPC(mother).relation - 1 / 20 - 1;
        int cash = rel * 100 - 50;
        if(cash < 0) cash = 0;
        if(root->vSchool(certificate) == 0)
        {
            if(root->vStatus(daystart) > 1 && root->vStatus(daystart) - root->vEvent(motherPayDay) < 7)
            {
                root->addText(str(74));
                root->changeRep('-',mother);
            }
            else
            {
                root->vEvent(motherPayDay) = root->vStatus(daystart);
                if(root->getMonth() >= 6 && root->getMonth() < 9)
                    root->addText(str(82));
            }

            if(rel > 0)
            {
                if(root->vSchool(progress) < 70)
                    cash = 0;
                else if(root->vSchool(progress) >= 90)
                    cash += 100;
                if(root->vSchool(progress) < 90)
                    root->changeRep('-',mother);
                if(root->vSchool(progress) < 70)
                    root->addText(str(72));
                else if(root->vSchool(progress) >= 70 && root->vSchool(progress) < 90)
                    root->addText(str(73));
                else
                    root->addText(str(74));
                root->vStatus(money) += cash;
            }
            else
            {
                root->changeRep('-',mother);
                if(root->vEvent(motherKnowWhore) == 0 && root->vEvent(motherKnowSpravka) == 0)
                    root->addText(str(28));
                if(root->vEvent(motherKnowWhore) >= 1 || root->vEvent(motherKnowSpravka) >=  1)
                    root->addText(str(29));
            }
            makeActBtn("go_out",act(0));
        }
        else
            root->addText(str(30));
        makeActBtn("go_out",act(0));
    }
    if(action == "panhandleNewCloth")
    {
        root->incTime(5);
        root->rendNpcProfile(mother);
        root->setText(str(31));
        if(root->repGet() == 4)
        {
            root->addText(str(32));
            makeActBtn("go_out",act(0));
            return;
        }
        if(root->vSchool(certificate) == 0)
        {
            if(root->gNPC(mother).relation >= 80)
            {
                if(root->vEvent(motherClotheMonth) != root->getMonth())
                {
                    root->vEvent(motherClotheMonth) = root->getMonth();
                    root->incTime(getRandInt(30,50));
                    root->addText(str(33));
                    makeActBtn("chooseCloth",act(8));
                }
                else
                    root->addText(str(34));
            }
            else
                root->addText(str(35));
        }
        else
            root->addText(str(36));
        makeActBtn("go_out",act(0));
    }
    if(action == "chooseCloth")
    {
        root->setImage(root->addRandCloth(skirt)->getClothImage());
        root->setText(str(75));
        makeActBtn("go_out",act(0));
    }
    if(action == "panhandleTampon")
    {
        root->addText(str(37));
        root->addItem(iTampon,3);
        root->incTime(3);
        makeActBtn("go_out",act(0));
    }

    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "bedrPar")
        root->changeLoc(lbedrpar);
    if(action == "go_out")
    {
        if(root->gNPC(mother).location == lkuhrpar) root->changeLoc(lkuhrpar);
        if(root->gNPC(mother).location == lsitrpar) root->changeLoc(lsitrpar);
        if(root->gNPC(mother).location == lshop) root->changeLoc(lgrinok,0,"main");
        if(root->gNPC(mother).location == lglake) root->changeLoc(lglake);
    }
}

void DinMother::check_talktime()
{
    i = 0;
    if(root->gNPC(mother).talk_count == root->gNPC(mother).talk_max_count)
    {
        root->gNPC(mother).talk_count += 1;
        root->addText(str(83));
        if(root->gNPC(mother).location == lsitrpar)
        {
            if(root->getHour() <= 17 && root->getSunWeather() >= 0)
                root->addText(str(84));
            else if(root->getHour() <= 17 && root->getSunWeather() < 0)
                root->addText(str(85));
            if(root->getHour() >= 18 && root->vSchool(vacation) == 0 && root->getDay() < 6)
                root->addText(str(86));
        }
        else if(root->gNPC(mother).location == lkuhrpar)
            root->addText(str(87));
        else if(root->gNPC(mother).location == lglake)
            root->addText(str(88));
        else
            root->addText(str(89));
        i = 1;
    }
    else if(root->gNPC(mother).talk_count > root->gNPC(mother).talk_max_count)
    {
        root->changeRep('-',mother);
        root->vStatus(mood) -= 5;
        root->gNPC(mother).talk_count = 100;
        root->addText(str(90));
        i = 1;
    }
}

void DinMother::talk()
{
    check_talktime();
    if(i == 0)
    {
        if(root->gNPC(mother).relation < 40)
        {
            if(root->vEvent(momSawYouPeeking) == 1)
            {
                root->addText(str(79));
                root->changeRep('-',mother,getRandInt(5,7));
                root->vEvent(momSawYouPeeking) = 0;
            }
            else
            {
                root->addText(str(getRandInt(44,45)));
                if(root->vEvent(motherSorryDay) != root->getDay())
                {
                    if(root->gNPC(mother).relation <= 20)
                        makeActBtn("momSorry",act(1));
                    else
                        makeActBtn("momSorry",act(2));
                }
            }
        }
        else
        {
            if(root->vEvent(momSawYouPeeking) == 1)
            {
                if(root->gNPC(mother).relation > 80)
                    root->addText(str(81));
                else
                    root->addText(str(80));
                root->vEvent(momSawYouPeeking) = 0;
            }
            else
            {
                if(root->gNPC(mother).relation > 80 && getRandInt(0,5) == 2)
                    root->addText(str(getRandInt(67,70)));
                else
                    root->addText(str(46) + str(getRandInt(47,66)));
            }
            root->incTime(getRandInt(10,15));
            root->gNPC(mother).talk_count += 1;
            root->changeRep('+',mother, getRandInt(3,5));
        }
        makeActBtn("go_out",act(0));
    }
}

void DinMother::clothes()
{
    if(!root->isCloth())
    {
        makeActBtn("bedrPar",act(0));
        if(root->vEvent(motherKnowWhore) == 0 && root->vEvent(motherKnowSpravka) == 0 && root->vQuest(qwMother) == 0)
        {
            if(root->vEvent(momslut) < 2)
                root->addText(str(1));
            else
                root->addText(str(2));
        }
        else if((root->vEvent(motherKnowWhore) + root->vEvent(motherKnowSpravka) > 0) && root->vQuest(qwMother) == 1)
        {
            if(root->vEvent(momslut) < 2)
                root->addText(str(3));
            else
                root->addText(str(4));
        }
        else if(root->vQuest(qwMother) >= 2)
            root->addText(str(5));
    }
    if(root->isGlamour() && root->getHour() > 9)
        root->addText(str(6));
    if(root->vEvent(pregTalkFamily) == 0 && root->vEvent(pregTalkMom) == 0)
    {
        if(root->PregVisibility())
        {
            root->addText(str(7));
            root->vEvent(pregTalkFamily) = 1;
            root->vEvent(pregTalkMom) = 1;
            makeActBtn("back_to_loc",act(0));
        }
    }
}

void DinMother::piercing()
{
    root->vEvent(motherPirsDay) = root->getDay();
    if(root->vBody(piercingA) >= 1 && root->vEvent(pirsAmother) == 0)
    {
        if(getRandInt(1,100) >= 75)
        {
            root->addText(str(8));
            makeActBtn("pirsANothing",act(3));
            makeActBtn("showPirsA",act(11));
        }
    }
    if(root->vBody(piercingB) == 1 && root->vEvent(pirsBmother) == 0)
    {
        root->addText(str(11));
        makeActBtn("pirsBlikeIt",act(4));
    }
    if(root->vBody(piercingC) == 1 && root->vEvent(pirsCmother) == 0)
    {
        root->vEvent(pirsCmother) = 1;
        root->addText(str(13));
    }
    if(root->vBody(piercingD) == 1 && root->vEvent(pirsDmother) == 0)
    {
        root->vEvent(pirsDmother) = 1;
        root->addText(str(14));
    }
    if(root->vBody(piercingE) == 1 && root->vEvent(pirsEmother) == 0)
    {
        root->vEvent(pirsEmother) = 1;
        root->addText(str(15));
    }
}

void DinMother::hair()
{
    root->addText(str(71));
    root->vEvent(hColMotherRemember) = root->vBody(hairColor);
}

void DinMother::virgin_check()
{
    if(root->vSchool(certificate) == 0)
    {
        if(root->vEvent(GspravkaT) == 0 && root->vEvent(GspravkaTimes) >= 3 && root->vEvent(motherKnowSpravka) == 0)
        {
            if(root->getHour() >= 7 && root->getHour() <= 17)
            {
                root->changeRep('-',mother);
                root->addText(str(16));
                makeActBtn("virginGoGin",act(5));
            }
            else
            {
                root->addText(str(20));
                makeActBtn("go_out",act(0));
            }
        }
        else if(root->vEvent(GspravkaT) == 0 && root->vEvent(GspravkaTimes) < 3 && root->vEvent(motherKnowSpravka) == 0 && root->vSchool(certificate) == 0)
        {
            root->vEvent(GspravkaTimes) += 1;
            root->addText(str(21));
        }
        else if(root->vEvent(GspravkaT) == 2 && root->vEvent(motherKnowSpravka) == 0)
        {
            if(root->vEvent(motherKnowWhore) == 0)
            {
                root->gNPC(mother).relation = 0;
                root->vEvent(motherKnowSpravka) = 1;
                if(root->vEvent(momslut) < 2)
                    root->addText(str(22));
                else
                    root->addText(str(23));
            }
            else if(root->vEvent(motherKnowWhore) > 0  && root->vQuest(qwMother) < 2)
            {
                root->changeRep('-',mother,10);
                root->vEvent(motherKnowSpravka) = 1;
                root->addText(str(24));
            }
            else if(root->vQuest(qwMother) >= 2)
            {
                root->vEvent(motherKnowSpravka) = 2;
                root->addText(str(25));
            }
            makeActBtn("go_out",act(0));
        }
    }
}

void DinMother::money_talk()
{
    makeActBtn("panhandle",act(6));
}

void DinMother::cloth_talk()
{
    makeActBtn("panhandleNewCloth",act(7));
}

void DinMother::tampon_talk()
{
    if(root->gNPC(mother).relation >= 40 && root->isMesec() && root->vStatus(pregnancy) == 0 && root->getItmCount(iTampon) == 0)
        makeActBtn("panhandleTampon",act(9));
}

void DinMother::cum_talk()
{
    makeActBtn("go_out",act(0));
    if(root->vEvent(motherKnowWhore) == 0 && root->vEvent(motherKnowSpravka) == 0 && root->vQuest(qwMother) == 0)
    {
        root->gNPC(mother).relation = 0;
        root->vEvent(motherKnowWhore) = 1;
        if(root->vEvent(momslut) < 2)
            root->addText(str(38));
        else
            root->addText(str(39));
    }
    else if((root->vEvent(motherKnowWhore) > 0 || root->vEvent(motherKnowSpravka) > 0) && root->vQuest(qwMother) == 1)
    {
        if(root->vEvent(whoremday) != root->getDay())
            root->changeRep('-',mother,20);
        if(root->vEvent(motherKnowWhore) == 0)
            root->vEvent(motherKnowWhore) = 1;
        if(root->vEvent(momslut) < 2)
            root->addText(str(40));
        else
            root->addText(str(41));
    }
    else if(root->vQuest(qwMother) >= 2)
    {
        if(root->vEvent(whoremday) != root->getDay())
            root->changeRep('+',mother,10);
        if(root->vEvent(motherKnowWhore) == 0)
            root->vEvent(motherKnowWhore) = 1;
        root->addText(str(42));
    }
    root->vEvent(whoremday) = root->getDay();
}

void DinMother::worry()
{
    root->vEvent(worry_check) = 0;
    root->changeRep('-',mother);
    root->rendNpcProfile(mother);
    root->setText(str(43));
    makeActBtn("bedrPar",act(10));
}



QString DinMother::media(int id)
{
    QString med[12];
    med[0] = "data/img/body/piercing/pirsA.jpg";
    med[1] = "data/img/body/piercing/pirsB.jpg";
    med[2] = "data/img/body/piercing/pirsC.jpg";
    med[3] = "data/img/body/piercing/pirsCli.jpg";
    med[4] = "data/img/body/piercing/pirscligub.jpg";
    med[5] = "data/img/body/piercing/pirsD.jpg";
    med[6] = "data/img/body/piercing/pirsE.jpg";
    med[7] = "data/img/body/piercing/pirsF.jpg";
    med[8] = "data/img/body/piercing/pirsG.jpg";
    med[9] = "data/img/body/piercing/pirsGLob.jpg";
    med[10] = "data/img/body/piercing/pirsN.jpg";
    med[11] = "data/npc/pavlovo/mother/ginekolog.jpg";
    return med[id];
}

QString DinMother::str(int id)
{
    QString str[93];
    str[1] = "Мать посмотрела на вас гневным взглядом:<br><npc>- Света, как тебе не стыдно ходить в таком виде по дому? А ну бегом оделась!</npc>";
    str[2] = "Мать грустно покачала головой:<br><npc>- Ты бы дома хоть прикрылась, а то ещё и в семье все будут знать, что ты шлюха...</npc>";
    str[3] = "Мать посмотрела на вас гневным взглядом:<br><npc>- Даже дома своей голой жопой светишь, шлюха малолетняя! Пошла и оделась быстро! И не попадайся мне на глаза в таком виде!</npc>";
    str[4] = "Мать грустно покачала головой:<br><npc>- Ты бы дома хоть одевалась прилично, а то ещё и в семье все будут знать, что ты шлюха...</npc>";
    str[5] = "Мать строго посмотрела на вас:<br><npc>- Света, я, конечно, всё понимаю, но не могла бы ты хотя бы дома одеваться не так, как ты привыкла у своих хахалей расхаживать? У тебя всё видно!</npc>";
    str[6] = "Мама посмотрела на вас: <npc>- Ты куда это так нарядилась?</npc>";
    str[7] = "Мать смотрит на ваш явно выступающий под одеждой живот: <npc>- Светик, залетела всё-таки, горе ты моё. Смотри, не вздумай аборт делать!.<npc><br>Мать смотрит на ваш животик: <npc>- Светик, залетела всё-таки, горе ты моё. Смотри, не вздумай аборт делать!.</npc>";
    str[8] = "Мать заглядывает вам в рот: <npc>- Света, а что у тебя там на языке блестит?</npc>";
    str[8] = "Вы отрицательно качаете головой: \"Ничего...\" - и тут же отворачиваетесь, чтобы мать не заметила пирсинг языка.";
    str[10] = "Вы открываете рот и высовываете язык, показывая матери пирсинг языка.<br>Мать качает головой: <npc>- Света, пирсинг языка делают распутные женщины, обслуживающие мужчин ртом.</npc>";
    str[11] = "Мать смотрит на ваши губы, в которых появился пирсинг: <npc>- А это ещё зачем?</npc>";
    str[12] = "Вы пожимаете плечами и говорите, что просто вам понравилось, вот вы и решили сделать себе пирсинг губ.";
    str[13] = "Мать смотрит на ваши уши, замечая сережки: <npc>- Я гляжу - ты решила носить сережки? Очень мило, тебе идёт.</npc>";
    str[14] = "Мать смотрит немного шокированно на ваше кольцо в носу: <npc>- Господи, Света, а это то ещё зачем? Я понимаю, быкам кольцо в нос вставляют, чтобы их за это кольцо таскать, но тебе-то зачем?</npc>";
    str[15] = "Мать качает головой, смотря на ваш пирсинг брови: <npc> - Света, ну зачем тебе эта ерунда в брови?<npc>, - после чего сокрушённо качает головой - <npc>Эх молодёжь, молодёжь...</npc>";
    str[16] = "Мать нахмурилась: <npc>\"Сколько можно тянуть со справкой? Придётся тебя самой к гинекологу вести!\"</npc><br>Мать взяла вас за руку и повела в поликлинику, к гинекологу.";
    str[17] = "Вы легли на гинекологическое кресло и раздвинули ноги. Гинеколог стала осматривать вашу вагину.";
    str[18] = "Гинеколог написала в справке, что вы не девственница.";
    str[19] = "Гинеколог написала в справке, что вы девственница.";
    str[20] = "Мать нахмурилась: <npc>Сколько можно тянуть со справкой? Мне что, тебя самой к гинекологу вести?!</npc>";
    str[21] = "<npc>Тебе нужно сходить в поликлинику. К гинекологу, за справкой для школы.</npc>";
    str[22] = "Мать схватила вас за ухо: <npc>- Ах ты блядища! Мы с отцом надрываемся, чтобы из вас путных людей сделать, чтобы вы достойных мужей себе нашли, а ты, шлюха, уже успела манду кому-то подвернуть! Убирайся с глаз моих!</npc>";
    str[23] = "Мать, грустно улыбнувшись, покачала головой: <npc>- Ну вот ты и стала взрослой. Смотри не залети, доча.</npc>";
    str[24] = "Мать посмотрела в справку: <npc>- Даже и не удивительно. Трахаешься с кем-то в подворотне, да еще и домой во всех хахальских \"подарках\" приходишь. Глаза б мои тебя не видели...</npc>";
    str[25] = "<npc>- И чего ты мне её принесла? Можешь хоть ксерокопии сделать и носить их в школу. Сомневаюсь, что у тебя там что-то изменится</npc>, - с ехидством заметила ваша мать.";
    str[26] = "Вы попросили у мамы денег.";
    str[27] = "Мать возмутилась: <npc>- Света, и не стыдно тебе у матери деньги просить? Ты больше меня зарабатываешь! Иди обслужи парочку клиентов.</npc>";
    str[28] = "Мать нахмурилась: <npc>- Не заслужила ты денег!</npc>";
    str[29] = "<npc>- Ты ещё денег просишь, шлюха? Иди отсюда, катись к своим ёбарям деньги клянчить!</npc>";
    str[30] = "<npc>- Ты уже достаточно взрослая, зарабатывай сама.</npc>";
    str[31] = "Вы попросили купить новую одежду.";
    str[32] = "Мать возмутилась:<br><npc>- Светик, у тебя от клиентов отбоя нет - и ты ещё у меня одежду просишь? Это я у тебя просить должна! Покупай сама.</npc>";
    str[33] = "Мама тяжело вздохнула: <npc>- Ну вот опять... Ты же меня по миру пустишь! Ладно, пойдем, горе луковое.</npc><br>Вы вместе с мамой начали выбирать одежду. С мамой ходить за покупками совершенно не интересное занятие: она никогда не даст вам выбрать самостоятельно, и обязательно купит одежду на свой вкус.";
    str[34] = "Мама покачала головой:<br><npc>- Дочура, у нас бюджет не резиновый, в этом месяце мы уже покупали тебе одежду. Теперь жди следующего месяца.</npc>";
    str[35] = "Мама покачала головой:<br><npc>- Нет денег.</npc>";
    str[36] = "Мама покачала головой:<br><npc>- Ты уже взрослая, пора бы зарабатывать самой.</npc>";
    str[37] = "Вы рассказываете матери о том, что у вас начались месячные и закончились тампоны. Она понимающе смотрит на вас, приносит несколько своих и рекомендует вам в следующий раз позаботиться об этом заранее.";
    str[38] = "Мать посмотрела на вас, выпучила глаза и покраснела. На вас заметна сперма.<br><npc>- Ах ты, шлюха малолетняя, это что такое на тебе? Всем говорю что дочь приличная, а она ебётся где-то. Блядина! Пошла отсюда, и не попадайся мне на глаза!</npc>";
    str[39] = "Мать грустно покачала головой: <npc>- Ты бы сперму то вытерла, а то весь город будет знать, что ты шлюха.</npc>";
    str[40] = "Мать посмотрела на вас гневным взглядом. На вас заметна сперма.<br><npc>- Опять где-то трахалась, шлюха малолетняя? Мне уже перед знакомыми стыдно за тебя! Пошла отсюда, не попадайся мне на глаза!</npc>";
    str[41] = "Мать грустно покачала головой: <npc>- Ты бы \"майонез\"-то вытерла, а то весь город будет знать, что ты шлюха.</npc>";
    str[42] = "Мать строго посмотрела на вас. На вас заметна сперма.<br><npc>- Света, я конечно все понимаю, но не могла бы ты убирать художества своих хахалей? Быстро приведи себя в порядок, пока ещё кто-нибудь не увидел!</npc>";
    str[43] = "Мать не спит и стоит в коридоре, ожидая вас: <npc>- Ты где шляешься?! Ты знаешь, какой час на дворе?!</npc>";
    str[44] = "Вы пытаетесь поговорить с мамой, но она отказывается с вами говорить.";
    str[45] = "Вы пытаетесь поговорить с мамой, но она разговаривает с вами сухо.";
    str[46] = "Вы болтаете с мамой, она рассказывает вам, ";
    str[47] = "как в юности они с друзьями прикалывались над учителями в школе.";
    str[48] = "как правильно краситься и ухаживать за кожей.";
    str[49] = "как она любит ездить в деревню, на природу.";
    str[50] = "что на рынке можно найти много дешёвых и полезных вещей.";
    str[51] = "что раньше работала продавщицей на рынке, но из-за маленького заработка и постоянных приставаний кавказцев пришлось уволиться.";
    str[52] = "как скучает по своей молодости.";
    str[53] = "как она была зла на Аню, когда та не поступила в институт.";
    str[54] = "как важно получить образование.";
    str[55] = "что ваш отчим очень предсказуем - работа, телевизор, гараж. Никакой изюминки, но зато надёжен.";
    str[56] = "что постоянные пьянки отчима с дядей Мишей по вечерам в гараже ни к чему хорошему не приведут.";
    str[57] = "что любит по выходным гулять в парке или загорать на пляже.";
    str[58] = "что вопреки всеобщему мнению - её босс - очень чуткий и отзывчивый человек, и именно о таком она когда-то в юности мечтала.";
    str[59] = "жалуясь, что отчим в последнее время сбегает в гараж, как только она приходит с работы.";
    str[60] = "что за работой у неё совсем нет времени ходить по магазинам и рынкам, так что приходится тратить время по выходным.";
    str[61] = "вспоминая, что как-то застала Кольку, когда тот подглядывал за Аней в душе - он тогда несколько дней на задницу сесть не мог.";
    str[62] = "довольно улыбаясь, что как-то на пляже видела, как Аня целовалась со своим парнем - стройным, симпатичным, рыжоволосым. Совсем, мол, выросла, скоро замуж пойдет.";
    str[63] = "жалуясь, что у Ани вошло в привычку каждую пятницу напиваться до чертиков и никакие профилактические беседы не помогают.";
    str[64] = "жалуясь, что Кольке, кроме футбола, пора б уже и на девочек обратить внимание.";
    str[65] = "жалуясь, что у Кольки с учебой большие проблемы и старшим сестрицам не мешало бы ему помогать.";
    str[66] = "что по понедельникам отчим ездит на газели за товарами на склады в город, и обычно возвращается поздно ночью.";
    str[67] = "<npc>- Я выросла в деревне, в Гадюкино нашем</npc> - пускается мать в воспоминания. <npc>- Здорово там в детстве было! Ни забот, ни хлопот! С речки летом не вылезала целыми днями, лес вдоль и поперёк излазила. И как только волки не сожрали?</npc> - искренне недоумевает она.<br><npc>- Когда я была в твоём возрасте, даже помоложе на пару годков, - увивались там за мной</npc> - тут мама чуть запнулась <npc>- один... парень.</npc><br><hero>- Иии?</hero> - навострили уши вы.<br><npc>- Да ничего не получилось</npc> - вздыхает мама. <npc>- Я после девятого класса поехала в Павлово, поступать на кулинара учиться. Познакомились с Мишкой. Так в Павлово и осталась. А Андрей служить ушёл, вот и разошлись дорожки.</npc>";
    str[68] = "<hero>- Ма, а как вы с нашим с Анькой отцом познакомились?</hero><br><npc>- Да ничего особенного, доча</npc> - с лёгкой грустью улыбается мать. <npc>- На дискотеке мы с ним познакомились. Он потанцевать пригласил. Ну а дальше цветочки-конфетки-посиделки при Луне... А как выяснилось, что у меня после таких \"посиделок\" ребёнок будет - Мишка замуж предложил. А я и согласилась. А через пару лет и ты появилась.</npc>";
    str[69] = "<hero>- Мам, а почему вы с нашим с Анькой отцом разошлись?</hero><br>Мать призадумалась:<br><npc>- Так вот сразу и не объяснишь... Любовь-морковь? Так, химия одна. Была ли та любовь или просто гормоны играли? Не знаю. Мишка как узнал, что я беременна, тут же замуж предложил за него выйти. Свадьбу отгуляли, начали жить. Квартирку-однушку родители нам спроворили - не пришлось по съёмным углам мыкаться, да ещё и с дитём малым на руках. И началось как в сказке после слов \"И я там был, мёд-пиво пил\". Сказка кончилась, начались будни. Мишка в автобазу устроился водилой: была тут у нас, да загнулась давно, - а я сперва дома с Анькой сидела. Ох, и крикливая ж она была - плакса страсть! Орать часами могла. Что такое \"спать\" я на несколько лет позабыла. Все соседи меня возненавидели из за её воплей постоянных. Мишка, чую, потому в дальнобойщики и перевёлся - чтобы хоть в рейсах от Анькиного рёва отдыхать. А мне-то от неё никуда не деться! С недосыпа лютого злющая стала как собака, сварливая, мужа пилила постоянно. За собой следить перестала: в такую лахудру превратилась, жопу отъела с автобус - аж вспоминать стыдно...<br>А Мишка, видать, в рейсах погуливать на сторону начал. Женщины такие вещи замечают. В общем, склочиться начали мы с ним что ни день, как он не в рейсе. Чуть не до драк доходило. Мирились, правда, тоже бурно! - хихикает мать вдруг. - Вот после одного из таких замирений ты и появилась!<br>Мишка тут не выдержал. Сперва начал у друзей всяких ночевать оставаться, а там и к бутылочке прикладываться. Скандалили мы страшно. А как-то уехал он в рейс - и домой не вернулся. Сообщил, что подаёт на развод, но дочек, вас, бишь, содержать будет. А там с Вовкой, отчимом твоим, познакомились. Он вас как родных принял. Дочами всегда считал своими, нянькался с вами. Он вам с Анькой куда больше папа, чем Миша, который вас мне заделал. Ваш отчим вас обеих вырастил. А о Мишке я даже и вспоминать не хочу.</npc>";
    str[70] = "<npc>- Ездили мы в свадебное путешествие с Вовкой в Петербург по турпутёвке - нам её на свадьбу подарили. Красотища! Каналы ихние, Эрмитаж, Медный всадник, этот, как его, Петергоф... Вот только, за всю поездку, за двенадцать дней, всего четыре ясных дня было. Мы, правда, не столько по экскурсиям ходили, сколько по Апрашке да Уделке бегали - рынки это такие в Питере. Но и по экскурсиям тоже.</npc>";
    str[71] = "Мать с интересом посмотрелa на ваши волосы: <npc> - Ух-ты, перекрасилась! ";
//    + func('barbershop','change_haircolor')
    str[71] += "</npc>";
    str[72] = "Мать нахмурилась: <npc>- Будешь лучше учиться - будут тебе деньги, а пока ты заслужила только ремня, а не денег!</npc>";
    str[73] = "Мать нахмурившись дала вам <<zz_money>> рублей: <npc>- Будешь лучше учиться, буду давать больше. А пока, это всё, что ты заслужила!</npc>";
    str[74] = "Мать улыбнулась и дала вам <<zz_money>> рублей: <npc>- Ладно, держи.</npc>";
    str[75] = "Мама купила вам одежду. Опять на свой вкус.";
    str[76] = "Мать нахмурилась: <npc>- Вот же ты липучка. Ничего не получишь!</npc>";
    str[77] = "Мать нахмурилась: <npc>Нет доча. Я тебе уже давала деньги на этой неделе. Хватит!</npc>";
    str[78] = "Мать нахмурилась: <npc>Дочура, я же тебе уже дала денег!</npc>";
    str[79] = "Мать посмотрела на вас гневным взглядом:<br><npc>- Света, не стыдно тебе подглядывать за взрослыми? Ты еще в сортире за мной понаблюдай! Еще раз увижу тебя в нашей спальне, собственноручно выпорю!</npc>";
    str[80] = "Мать посмотрела на вас немного смущаясь:<br><npc>- Света, ты в следующий раз стучись что-ли!</npc><br><hero>Конечно, мам!</hero> - отвечаете вы, и неожидано продолжаете <hero> У кого же мне еще учиться, как не у собственной матери!<br></hero><npc> Действительно</npc> - немного подумав, отвечает вам мама.";
    str[81] = "Вы с улыбкой говорите маме: <br><hero> - Я смотрю, вы с папкой вчера явно не скучали?</hero><br><npc>- Да, он скучать не дает. Тебе, я вижу, тоже понравилось наблюдать?</npc><br><hero> - Было очень поучительно</hero>, - отвечаете вы маме и обе прыскаете от смеха.";
    str[82] = "<npc>Света! Ну мы же с тобой договаривались - летом я даю тебе немного денег, если ты постоянно помогаешь мне по дому!</npc>";
    str[83] = "<npc>- Ну ты, Света, и болтушка!</npc>";
    str[84] = "<npc>- Сходи на улицу, погуляй, погодка-то прекрасная.</npc>";
    str[85] = "<npc>- Может, поможешь мне по дому?<npc>";
    str[86] = "<npc>- Помоги лучше Кольке с уроками.</npc>";
    str[87] = "<npc>- Лучше Помоги мне с посудой<npc>";
    str[88] = "<npc>- Ложись уже, всё солнце мне загородила<npc>";
    str[89] = "<npc> - Давай позже поболтаем - сейчас я немного занята.</npc></npc>";
    str[90] = "<npc>Света, ну хватит уже разговоров! Сама ничерта не делаешь, еще и меня отвлекаешь</npc> - прикрикнула на вас мама.";
    str[91] = "Вы извиняетесь перед мамой и она, кажется, вас прощает.";
    str[92] = "Вы подлизываетесь к маме и она, кажется, начинает к вам лучше относится.";
    return str[id];
}

QString DinMother::act(int id)
{
    QString act[12];
    act[0] = "Отойти";
    act[1] = "Просить прощения";
    act[2] = "Пытаться сгладить отношения";
    act[3] = "Ничего";
    act[4] = "Мне понравилось";
    act[5] = "Идти к гинекологу за справкой";
    act[6] = "Просить денег";
    act[7] = "Просить новую одежду";
    act[8] = "Выбрать одежду";
    act[9] = "Попросить тампон";
    act[10] = "В свою комнату";
    act[11] = "Показать пирсинг языка";
    return act[id];
}
