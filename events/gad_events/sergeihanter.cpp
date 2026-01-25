#include "sergeihanter.h"
#include "../../menu/buttons.h"
#include "../../game.h"
#include "../../Functions.h"

SergeiHanter::SergeiHanter(Game* ptr): root(ptr) {}

void SergeiHanter::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"SergeiHanter");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SergeiHanter::actionHandler);
    root->addActions(btn);
}

QString SergeiHanter::str(int id)
{
    QString str[26];
    str[0] = "Сергей";
    str[1] = "Сергей друг Андрея и Игоря, и один из знакомых вам охотников. Ему " + intQStr(boyAge) + " лет. Он женат и живет в Центре..";
    str[2] = "У вас с ним плохие отношения, похоже он затаил на вас какую-то обиду.";
    str[3] = "У вас с ним нормальные отношения.";
    str[4] = "У вас с ним дружеские отношения.";
    str[5] = "Похоже он вам симпотизирует.";
    str[6] = "Похоже он в вас влюблен.";
    str[7] = "Похоже он у вас с ним любовь.";
    str[8] = "У вас с ним любовь.";
    str[9] = "Вы с ним встречаетесь.";
    str[10] = "Вы весело поболтали с Сергеем, выслушивая разные интересные истории из его жизни, и рассказывая свои.";
    str[11] = "Вы разговариваете с Игорем. Он хмурится и ведет себя не очень дружелюбно, но все же поддерживает разговор.";
    str[12] = "Вы перекидываетесь с Сергеем игривыми взглядами и вовсю кокетничаете. Он рад вашей компании и пару раз вы замечаете на себе его блуждающий недвусмысленный взгляд.";
    str[13] = "Вы мило улыбаетесь Сергею и флиртуете с ним. Неожиданно он берет ваше лицо в ладони и приближает свои губы к вашим губам.";
    str[14] = "Ваши губы соприкасаются, у вас замирает сердце и дыхание. " + boy + " целует вас и вы ему отвечаете, сильнее прижимаясь к его губам.";
    str[15] = "<npc>- Светик, я хочу тебя,</npc> - прошептал вам на ухо " + boy + ", когда ваши губы наконец разомкнулись. Видя , что вы не против, " + boy + " нежно взял вас за руку и повел за собой.";
    str[16] = "<npc>- Это было здорово, Светик,</npc> - сказал вам " + boy + ", когда ваши губы наконец разомкнулись. Вы счастливы, видя его радостный взгляд и улыбку.";
    str[17] = "<hero>- Нет, " + boy + ", не нужно этого,</hero> - сказали вы, и стараясь не смотреть на парня, ушли.";
    str[18] = "Вы проводите с Сергеем вместе время, обнимаясь и целуясь. Он рад вашей компании, вы не можете не замечать его счастливый взгляд, и от этого вам самой очень радостно на душе.";
    str[19] = "Вы совсем уж внаглую подмигиваете Сергею, томно вздыхаете, проводя язычком по губам и " + boy + ", все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[20] = "Вы подошли к Сергею, чтобы провести время вместе, но вместо этого он страстно впивается в ваши губы."
              "<npc>- Света, я хочу тебя,</npc> - прошептал он после поцелуя.";
    str[21] = "Улыбнувшись вы подмигиваете Сергею. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[22] = "<hero>- Нет, " + boy + ", давай не сейчас,</hero> - сказали вы, и стараясь не смотреть на парня, ушли.";
    str[23] = "<hero>- " + boy + ", я решила, что у наших отношений нет будущего, и нам нужно расстаться,</hero> - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[24] = "Вы хотели поговорить с Сергеем, но он вас опередил, не дав сказать вам сказать нислова."
              "<npc>- Света, я понял, что у наших отношений нет будущего, и нам нужно расстаться,</npc> - сказали он, и стараясь не смотреть в вашу сторону, решительно ушел прочь."
              "<hero>- Ну , может оно и к лучшему,</hero> - подумали вы, уходя в другую сторону.";
    str[25] = "Вы хотели поговорить с Сергеем, но он вас опередил, не дав сказать вам сказать ни слова."
              "<npc>- Света, я понял, что у наших отношений нет будущего. Ты хорошая девушка, но я очень ценю свою семью, чтобы рисковать продолжая отношения с тобой,</npc> - сказали он, и стараясь не смотреть в вашу сторону, решительно ушел прочь."
              "<hero>- Ну как же так? Хотя может оно и к лучшему,</hero> - расстроенно подумали вы, уходя в другую сторону.";
    return str[id];
}

QString SergeiHanter::act(int id)
{
    QString act[13];
    act[0] = "Далее";
    act[1] = "Поболтать";
    act[2] = "Флиртовать";
    act[3] = "Проводить вместе время";
    act[4] = "Ответить на поцелуй";
    act[5] = "Убрать лицо";
    act[6] = "Идти";
    act[7] = "Уйти";
    act[8] = "Отойти";
    act[9] = "Приставать";
    act[10] = "Согласиться";
    act[11] = "Отказаься";
    act[12] = "Расстаться с парнем";
    return act[id];
}

QString SergeiHanter::media(int id)
{
    QString med[23];
    med[0] = "data/npc/gadukino/swamp/SergeiHanter.jpg";
    med[1] = "data/actions/backwater/talk1.1.jpg";
    med[2] = "data/actions/backwater/talk1.2.jpg";
    med[3] = "data/actions/backwater/talk1.3.jpg";
    med[4] = "data/actions/backwater/hanterflirt1.1.jpg";
    med[5] = "data/actions/backwater/hanterflirt1.2.jpg";
    med[6] = "data/actions/backwater/hanterflirt1.3.jpg";
    med[7] = "data/actions/backwater/hanterkiss1.jpg";
    med[8] = "data/actions/backwater/hanterkiss2.jpg";
    med[9] = "data/actions/backwater/hanterkiss3.jpg";
    med[10] = "data/qwest/gadukino/otel4.jpg";
    med[11] = "data/actions/backwater/hanterlove1.1.jpg";
    med[12] = "data/actions/backwater/hanterlove1.2.jpg";
    med[13] = "data/actions/backwater/hanterlove1.3.jpg";
    med[14] = "data/actions/backwater/hanterlove1.4.jpg";
    med[15] = "data/actions/backwater/hanterflirt2.1.jpg";
    med[16] = "data/actions/backwater/hanterflirt2.2.jpg";
    med[17] = "data/actions/backwater/hanterflirt2.3.jpg";
    med[18] = "data/actions/backwater/hanterflirt2.4.jpg";
    med[19] = "data/actions/backwater/hanterflirt2.5.jpg";
    med[20] = "data/actions/backwater/hanterflirt2.6.jpg";
    med[21] = "data/actions/backwater/brosil.jpg";
    med[22] = "data/actions/backwater/brosila.jpg";
    return med[id];
}

void SergeiHanter::start(QString arg)
{
    boy = str(0);
    dicksize = 18;
    sexskill = 1;
    harakBoy = 1;
    boyAge = root->getAge() + 15;
    root->setImage(media(0));
    root->setText(str(1));
    int rel = root->vQuest(hantersSergeiQW);
    int love = root->vEvent(hantersSergeiLove);
    if(rel < 0) root->addText(str(2));
    if(rel >= 0 && rel < 10) root->addText(str(3));
    if(rel >= 10 && rel < 20) root->addText(str(4));
    if(rel >= 20 && rel < 25) root->addText(str(5));
    if(rel >= 25 && rel < 30) root->addText(str(6));
    if(rel >= 30 && rel < 35) root->addText(str(7));
    if(rel >= 35) root->addText(str(8));
    if(love == 1) root->addText(str(9));
    makeActBtn("talk",act(1));
    if(rel >= 10)
    {
        if(love == 0)
            makeActBtn("flirt",act(2));
        else
            makeActBtn("takeTime",act(3));
    }
    if(love > 0 && root->vStatus(horny) >= 60)
        makeActBtn("harras",act(9));
    if(love > 0 && root->vStatus(horny) <= 60 && rel >= 10 && root->vEvent(hantersSergeisex) == 0)
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->vEvent(hantersSergeisex) += getRandInt(9,30);
        root->setImage(media(14));
        root->setText(str(20));
        makeActBtn("acceptSex",act(10));
        makeActBtn("declineSex",act(11));
    }
    if(love > 0)
        makeActBtn("dropGuy",act(12));
    makeActBtn("back_to_loc",act(8));
    if(rel < 10 && love > 0)
    {
        root->incTime(5);
        root->vEvent(hantersSergeiLove) = 0;
        root->vQuest(hantersSergeiQW) -= 10;
        root->setImage(media(21));
        root->setText(str(24));
        makeActBtn("back_to_loc",act(6));
    }
    if(rel > 50 && love > 0)
    {
        root->incTime(5);
        root->vEvent(hantersSergeiLove) = 0;
        root->vQuest(hantersSergeiQW) -= 50;
        root->setImage(media(21));
        root->setText(str(25));
        makeActBtn("back_to_loc",act(6));
    }
}

void SergeiHanter::actionHandler(QString action)
{
    if(action == "dropGuy")
    {
        root->incTime(5);
        root->vEvent(hantersSergeiLove) = 0;
        root->vQuest(hantersSergeiQW) -= 100;
        root->setImage(media(22));
        root->setText(str(23));
        makeActBtn("back_to_loc",act(6));
    }

    if(action == "talk")
    {
        root->incTime(60);
        if(root->vQuest(hantersSergeiQW) < 10)
            root->vQuest(hantersSergeiQW) += 1;
        root->setImage(media(getRandInt(1,3)));
        if(root->vQuest(hantersIgorQW) >= 0) root->setText(str(10));
        else root->setText(str(11));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "flirt")
    {
        root->incTime(120);
        root->vStatus(horny) += 10;
        if(root->vEvent(hantersKnowSlut) == 0)
        {
            if(root->vQuest(hantersSergeiQW) <= 35)
                root->vQuest(hantersSergeiQW) += 1;
            if(root->vQuest(hantersIgorQW) >= 10)
                root->vQuest(hantersIgorQW)-=1;
            if(root->vQuest(hantersAndreiQW) >= 10)
                root->vQuest(hantersAndreiQW)-=1;
        }
        root->setImage(media(getRandInt(4,6)));
        root->setText(str(12));
        if(root->vEvent(hantersSergeiLove) == 0 && root->vQuest(hantersSergeiQW) >= 30 && root->vEvent(hantersKnowSlut) == 0 && root->vStatus(vnesh) >= 40)
        {
            root->incTime(5);
            root->vStatus(horny) += 5;
            root->setImage(media(7));
            root->setText(str(13));
            makeActBtn("acceptKiss",act(4));
            makeActBtn("declineKiss",act(5));
        }
        else
            makeActBtn("back_to_loc",act(8));
    }

    if(action == "acceptKiss")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->vEvent(hantersSergeiLove) = 1;
        root->vQuest(hantersSergeiQW) += 1;
        root->vStatus(mood) = 100;
        root->setImage(media(8));
        root->setText(str(14));
        if(root->vStatus(horny) >= 40)
            makeActBtn("kiss1",act(0));
        else
            makeActBtn("kiss2",act(0));
    }
    if(action == "kiss1")
    {
        root->incTime(5);
        root->setImage(media(9));
        root->setText(str(15));
        makeActBtn("HanterLoveSex",act(6));
    }
    if(action == "kiss2")
    {
        root->incTime(5);
        root->setImage(media(9));
        root->setText(str(16));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "declineKiss")
    {
        root->incTime(5);
        root->vQuest(hantersSergeiQW) -= 50;
        root->setImage(media(10));
        root->setText(str(17));
        makeActBtn("back_to_loc",act(7));
    }

    if(action == "takeTime")
    {
        root->incTime(120);
        root->vStatus(horny) += 10;
        root->vQuest(hantersSergeiQW) += 1;
        if(root->vEvent(hantersIgorLove) > 0 || root->vEvent(hantersAndreiLove) > 0)
            root->vEvent(hanterslut) += 1;
        if(root->vEvent(hantersIgorLove) == 0 && root->vEvent(hantersAndreiLove) == 0)
            root->vEvent(hanterslut) -= 1;
        root->vStatus(mood) = 100;
        root->setImage(media(getRandInt(11,14)));
        root->setText(str(18));
        makeActBtn("back_to_loc",act(8));
    }
    if(action == "harras")
    {
        root->incTime(10);
        root->vStatus(horny) += 5;
        root->vQuest(hantersSergeiQW) += 1;
        root->vEvent(hantersSergeisex) += getRandInt(9,30);
        root->setImage(media(getRandInt(15,20)));
        root->setText(str(19));
        makeActBtn("HanterLoveSex",act(6));
    }

    if(action == "acceptSex")
    {
        root->incTime(5);
        root->vQuest(hantersSergeiQW) += 1;
        root->setImage(media(getRandInt(18,20)));
        root->setText(str(21));
        makeActBtn("HanterLoveSex",act(6));
    }
    if(action == "declineSex")
    {
        root->incTime(5);
        root->vQuest(hantersSergeiQW) -= 1;
        root->setImage(media(10));
        root->setText(str(22));
        makeActBtn("back_to_loc",act(6));
    }

    ///////////////////////
    if(action == "HanterLoveSex")
        root->startEvent(eHantersLoveSex);
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
}
