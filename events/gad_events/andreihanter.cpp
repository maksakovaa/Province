#include "andreihanter.h"
#include "../../menu/qactbutton.h"
#include "../eventhandler.h"
#include "../../Functions.h"

AndreiHanter::AndreiHanter(EventHandler* ptr): root(ptr) {}

void AndreiHanter::start(QString arg)
{
    if(arg.isEmpty())
        actionHandler("AndreiHanter");
    else
        actionHandler(arg);
}

void AndreiHanter::actionHandler(QString action)
{
    if(action == "AndreiHanter")
    {
        root->setBoyName(str(0));
        root->sVSex(dick,20);
        root->sVSex(silavag,0);
        root->sVSex(harakBoy,2);
        root->sVSex(boyage, root->getAge() + 21);
        root->setImage(media(0));
        root->setDesc(str(1));
        int rel = root->gVQuest(hantersAndreiQW);

        if(rel < 0)
            root->addDesc(str(2));
        if(rel >= 0 && rel < 10)
            root->addDesc(str(3));
        if(rel >= 10 && rel < 15)
            root->addDesc(str(4));
        if(rel >= 15 && rel < 25)
            root->addDesc(str(5));
        if(rel >= 25)
            root->addDesc(str(6));
        if(root->gVEvent(hantersAndreiLove) == 1)
            root->addDesc(str(7));
        makeActBtn("talk",act(0));
        if(rel >= 10)
        {
            if(root->gVEvent(hantersAndreiLove) == 0)
                makeActBtn("flirt",act(2));
            else
                makeActBtn("take_time",act(3));
        }
        if(root->gVEvent(hantersAndreiLove) > 0 && root->vStatus(horny) >= 60)
            makeActBtn("pester",act(9));
        if(root->gVEvent(hantersAndreiLove) > 0 && root->vStatus(horny) < 60 && root->gVQuest(hantersAndreiQW) >= 10 && root->gVEvent(hantersAndreisex) == 0)
        {
            root->incTime(5);
            root->uVStatus(horny,5);
            root->uVEvent(hantersAndreisex,getRandInt(6,24));
            root->setImage(media(1));
            root->setDesc(str(18));
            makeActBtn("go_with_a",act(10));
            makeActBtn("dont_go_with_a",act(11));
        }
        if(root->gVEvent(hantersAndreiLove) > 0)
            makeActBtn("break_up_the_guy",act(12));
        makeActBtn("back_to_loc",act(4));
        if(rel < 10 && root->gVEvent(hantersAndreiLove) > 0)
        {
            root->incTime(5);
            root->sVEvent(hantersAndreiLove,0);
            root->uVQuest(hantersAndreiQW,-10);
            root->setImage(media(2));
            root->setDesc(str(22));
            makeActBtn("back_to_loc",act(7));
        }
    }
    if(action == "talk")
    {
        root->incTime(60);
        if(root->gVQuest(hantersAndreiQW) < 10)
            root->uVQuest(hantersAndreiQW,1);
        root->setImage(media(3));
        if(root->gVQuest(hantersAndreiQW) >= 0)
            root->setDesc(str(8));
        if(root->gVQuest(hantersAndreiQW) < 0)
            root->setDesc(str(9));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "flirt")
    {
        root->incTime(120);
        root->uVStatus(horny,10);
        if(root->gVEvent(hantersKnowSlut) == 0)
        {
            if(root->gVQuest(hantersAndreiQW) <= 35)
                root->uVQuest(hantersAndreiQW,1);
            if(root->gVQuest(hantersSergeiQW) >= 10)
                root->uVQuest(hantersSergeiQW,-1);
            if(root->gVQuest(hantersIgorQW) >= 10)
                root->uVQuest(hantersIgorQW,-1);
        }
        root->setImage(media(4));
        root->setDesc(str(10));
        if(root->gVEvent(hantersAndreiLove) == 0 && root->gVQuest(hantersAndreiQW) >= 25 && root->gVEvent(hantersKnowSlut) == 0 && root->vStatus(vnesh) >= 20)
        {
            root->incTime(5);
            root->uVStatus(horny,5);
            root->setImage(media(5));
            root->setDesc(str(11));
            makeActBtn("answer_kiss",act(5));
            makeActBtn("dont_answer_kiss",act(6));
        }
        else
        {
            makeActBtn("back_to_loc",act(4));
        }
    }
    if(action == "answer_kiss")
    {
        root->incTime(5);
        root->uVStatus(horny,5);
        root->sVEvent(hantersAndreiLove,1);
        root->uVQuest(hantersAndreiQW,1);
        root->sVStatus(mood,100);
        root->setImage(media(6));
        root->setDesc(str(12));
        if(root->vStatus(horny) >= 40)
            makeActBtn("kiss_next1",act(1));
        else
            makeActBtn("kiss_next2",act(1));
    }
    if(action == "kiss_next1")
    {
        root->incTime(5);
        root->setImage(media(7));
        root->setDesc(str(13));
        makeActBtn("HanterLoveSex",act(7));
    }
    if(action == "kiss_next2")
    {
        root->incTime(5);
        root->setImage(media(7));
        root->setDesc(str(14));
        makeActBtn("back_to_loc",act(1));
    }
    if(action == "dont_answer_kiss")
    {
        root->incTime(5);
        root->uVEvent(hanterslut,1);
        root->uVQuest(hantersAndreiQW,-50);
        root->setImage(media(8));
        root->setDesc(str(15));
        makeActBtn("back_to_loc",act(8));
    }
    if(action == "take_time")
    {
        root->incTime(120);
        root->uVStatus(horny,10);
        root->uVQuest(hantersAndreiQW,1);
        if(root->gVEvent(hantersIgorLove) > 0 || root->gVEvent(hantersSergeiLove) > 0)
            root->uVEvent(hanterslut,1);
        if(root->gVEvent(hantersIgorLove) == 0 && root->gVEvent(hantersSergeiLove) == 0)
            root->uVEvent(hanterslut,-1);
        root->sVStatus(mood,100);
        root->setImage(media(9));
        root->setDesc(str(16));
        makeActBtn("back_to_loc",act(4));
    }
    if(action == "pester")
    {
        root->incTime(10);
        root->uVStatus(horny,5);
        root->uVQuest(hantersAndreiQW,1);
        root->uVEvent(hantersAndreisex,getRandInt(6,24));
        root->setImage(media(10));
        root->setDesc(str(17));
        makeActBtn("HanterLoveSex",act(7));
    }
    if(action == "HanterLoveSex")
    {
        root->eventStart("HanterLoveSex");
    }
    if(action == "go_with_a")
    {
        root->incTime(5);
        root->uVStatus(horny,5);
        root->uVQuest(hantersAndreiQW,1);
        root->setImage(media(11));
        root->setDesc(str(19));
        makeActBtn("HanterLoveSex",act(1));
    }
    if(action == "dont_go_with_a")
    {
        root->incTime(5);
        root->uVQuest(hantersAndreiQW,-1);
        root->setImage(media(8));
        root->setDesc(str(20));
        makeActBtn("back_to_loc",act(7));
    }
    if(action == "break_up_the_guy")
    {
        root->incTime(5);
        root->sVEvent(hantersAndreiLove,0);
        root->uVQuest(hantersAndreiQW,-100);
        root->setImage(media(12));
        root->setDesc(str(21));
        makeActBtn("back_to_loc",act(7));
    }
}

void AndreiHanter::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &AndreiHanter::actionHandler);
    root->addActBtn(btn);
}

QString AndreiHanter::str(int id)
{
    QString str[23];
    str[0] = "Андрей";
    str[1] = "Андрей один из знакомых вам охотников. Ему " + intQStr(root->vSex(boyage)) + " лет. Он разведен и живет в Гадюкино один.";
    str[2] = "У вас с ним плохие отношения, похоже он затаил на вас какую-то обиду.";
    str[3] = "У вас с ним нормальные отношения.";
    str[4] = "У вас с ним дружеские отношения.";
    str[5] = "Похоже он вам симпотизирует.";
    str[6] = "У вас с ним любовь.";
    str[7] = "Вы с ним встречаетесь.";
    str[8] = "Вы поболтали с Андреем, выслушивая разные интересные истории из его жизни, и рассказывая свои.";
    str[9] = "Вы разговариваете с Андреем. Он хмурится и ведет себя не очень дружелюбно, но все же поддерживает разговор.";
    str[10] = "Вы вовсю кокетничаете с Андреем. Он рад вашей компании и пару раз вы замечаете на себе его блуждающий недвусмысленный взгляд.";
    str[11] = "Вы мило улыбаетесь Андрею и флиртуете с ним. Неожиданно он приближает к вам свое лицо и впивается в ваши губы страстным, долгим поцелуем...";
    str[12] = "Ваши губы соприкасаются, у вас замирает сердце и дыхание. " + root->getBoyName() + " страстно целует вас и вы ему отвечаете, сильнее прижимаясь к его губам.";
    str[13] = "- Светик, я хочу тебя, - прошептал вам на ухо " + root->getBoyName() + ", когда ваши губы наконец разомкнулись. Видя , что вы не против, " + root->getBoyName() + " нежно взял вас за руку и повел за собой.";
    str[14] = "- Это было круто, Светик, - сказал вам на " + root->getBoyName() + ", когда ваши губы наконец разомкнулись.";
    str[15] = "- Нет, " + root->getBoyName() + ", не нужно этого, - сказали вы, и стараясь не смотреть на Андрея ушли.";
    str[16] = "Вы проводите с Андреем вместе время нежно воркуя, обнимаясь и целуясь. Он рад вашей компании, вы не можете не замечать его полный счастья взгляд, и от этого вам хочется петь и летать.";
    str[17] = "Вы совсем уж внаглую подмигиваете Андрею, томно вздыхаете, проводя язычком по губам и Андрей, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[18] = "Вы подошли к Андрею, чтобы провести время вместе, но он неожиданно впился в ваши губы страстным поцелуем и ни слова не говоря потянул вас за собой.";
    str[19] = "Вы идете с Андреем держась за руки, прекрасно понимая, куда и зачем он вас ведет. И вы совсем даже не против.";
    str[20] = "- Нет, " + root->getBoyName() + ", давай не сейчас, - сказали вы, и стараясь не смотреть на него ушли.";
    str[21] = "- " + root->getBoyName() + ", я решила, что у наших отношений нет будущего, и нам нужно расстаться, - сказали вы, и стараясь не смотреть на Андрея, ушли.";
    str[22] = "Вы хотели поговорить с Андреем, но он вас опередил, не дав сказать вам сказать нислова."
            "- Света, между нами ничего не получится, так что лучше нам расстаться, - сказали он и решительно ушел прочь."
            "- Ну , может оно и к лучшему, - подумали вы, уходя в другую сторону.";
    return str[id];
}

QString AndreiHanter::act(int id)
{
    QString act[13];
    act[0] = "Поболтать";
    act[1] = "Далее";
    act[2] = "Флиртовать";
    act[3] = "Проводить вместе время";
    act[4] = "Отойти";
    act[5] = "Ответить на поцелуй";
    act[6] = "Убрать лицо";
    act[7] = "Идти";
    act[8] = "Уйти";
    act[9] = "Приставать";
    act[10] = "Идти с Андреем";
    act[11] = "Отказаться";
    act[12] = "Расстаться с парнем";
    return act[id];
}

QString AndreiHanter::media(int id)
{
    QString med[20];
    med[0] = "data/npc/gadukino/swamp/AndreiHanter.jpg";
    med[1] = "data/actions/backwater/hanterlove1.4.jpg";
    med[2] = "data/actions/backwater/brosil.jpg";
    med[3] = "data/actions/backwater/talk1." + intQStr(getRandInt(1,3)) + ".jpg";
    med[4] = "data/actions/backwater/hanterflirt1." + intQStr(getRandInt(1,3)) + ".jpg";
    med[5] = "data/actions/backwater/hanterkiss1.jpg";
    med[6] = "data/actions/backwater/hanterkiss2.jpg";
    med[7] = "data/actions/backwater/hanterkiss3.jpg";
    med[8] = "data/qwest/gadukino/otel4.jpg";
    med[9] = "data/actions/backwater/hanterlove1." + intQStr(getRandInt(1,4)) + ".jpg";
    med[10] = "data/actions/backwater/hanterflirt2." + intQStr(getRandInt(1,6)) + ".jpg";
    med[11] = "data/actions/backwater/hanterhands.jpg";
    med[12] = "data/actions/backwater/brosila.jpg";
    return med[id];
}
