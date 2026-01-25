#include "mirafather.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

MiraFather::MiraFather(Game* ptr): root(ptr){}

void MiraFather::start(QString arg)
{
    if(root->vStatus(cumFace) > 0 || root->vStatus(cumFrot) > 0)
        root->vQuest(MiraFatherQW) -= 1;
    if(root->vQuest(MiraFatherQW) < 0)
        root->vQuest(MiraFatherQW) = 0;
    root->setImage(media(0));
    root->setText(str(0));
    if(root->vStatus(cumFace) > 0) root->addText(str(1));
    if(root->vStatus(cumFrot) > 0) root->addText(str(2));
    if(root->vEvent(mirafatherday) != root->vStatus(daystart))
    {
        root->vEvent(mirafatherday) = root->vStatus(daystart);
        makeActBtn("welcome",act(0));
    }
    makeActBtn("miroslavahome",act(1));
}

void MiraFather::actionHandler(QString action)
{
    if(action == "welcome")
    {
        if(root->vQuest(MiraFatherQW) < 10)
            root->vQuest(MiraFatherQW) += 1;
        root->incTime(2);
        makeActBtn("miroslavahome",act(1));
        root->setImage(media(0));
        root->setText(str(3));
        if(root->vQuest(MiraFatherQW) >= 10)
            makeActBtn("talk",act(2));
        if(root->vQuest(MiraFatherQW) >= 20 && root->vEvent(grandpa_mira_guest) == 0)
            makeActBtn("flirt",act(3));
    }
    if(action == "talk")
    {
        if(root->vQuest(MiraFatherQW) < 20)
            root->vQuest(MiraFatherQW) += 1;
        root->incTime(5);
        root->setImage(media(0));
        root->setText(str(4));
        makeActBtn("miroslavahome",act(1));
    }
    if(action == "flirt")
    {
        if(root->vQuest(MiraFatherQW) < 30)
            root->vQuest(MiraFatherQW) += 1;
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->setImage(media(0));
        root->setText(str(5));
        if(root->vQuest(MiraFatherQW) == 30)
            makeActBtn("seduce",act(4));
        if(root->vQuest(MiraFatherQW) > 30)
            makeActBtn("wink",act(6));
    }

    if(action == "seduce")
    {
        root->vQuest(MiraFatherQW) = 31;
        root->incTime(10);
        root->vStatus(horny) += 30;
        root->setImage(media(0));
        root->setText(str(6));
        makeActBtn("enjoy",act(5));
    }

    if(action == "enjoy")
    {
        root->incTime(10);
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatistics(getKuni) += 1;
        root->vSex(guy) += 1;
        root->vStatistics(orgasm) += 1;
        root->setImage(media(1));
        root->setText(str(7));
        makeActBtn("give",act(7));
    }

    if(action == "give")
    {
        root->setBoyName(boy);
        root->vSex(silavag) = sexSkill;
        root->vSex(dick) = dickSize;
        root->vSex(pose) = 0;
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->setImage(media(2));
        if(!root->isMesec() || root->vBody(vagina) > 0)
        {
            root->vSex(protect) = 1;
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("miroslavahome",act(1));
    }
    if(action == "wink")
    {
        root->setBoyName(boy);
        root->vSex(silavag) = sexSkill;
        root->vSex(dick) = dickSize;
        root->vSex(pose) = 0;
        root->incTime(5);
        root->vStatus(horny) += 10;
        int tmp = getRandInt(0,5);
        root->setImage(media(0));
        if(tmp < 5)
        {
            root->setText(str(8));
            makeActBtn("seduce2",act(8));
        }
        else
        {
            root->setText(str(9));
            makeActBtn("miroslavahome",act(1));
        }
    }
    if(action == "seduce2")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        int tmp = getRandInt(0,9);
        if(tmp == 0) root->setImage(media(2));
        if(tmp == 1) root->setImage(media(3));
        if(tmp == 2) root->setImage(media(4));
        if(tmp == 3) root->setImage(media(5));
        if(tmp == 4) root->setImage(media(6));
        if(tmp == 5) root->setImage(media(7));
        if(tmp == 6) root->setImage(media(8));
        if(tmp == 7) root->setImage(media(9));
        if(tmp == 8) root->setImage(media(10));
        if(tmp == 9) root->setImage(media(10));
        if(tmp < 5)
        {
            root->incTime(10);
            root->vStatus(horny) += 10;
            if(!root->isMesec() || root->vBody(vagina) > 0)
            {
                root->vSex(protect) = 1;
                root->sexStart();
                root->vaginal(tDick);
                root->sex_cum();
            }
            else
            {
                root->vSex(protect) = 1;
                root->analStart(tDick);
                root->anal(tDick);
                root->anal_cum();
            }
            makeActBtn("miroslavahome",act(1));
        }
        else
        {
            root->incTime(10);
            root->vStatus(horny) += 10;
            makeActBtn("seduce2.1",act(8));
        }
    }
    if(action == "seduce2.1")
    {
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->cum("lip");
        root->cum("belly");
        root->setImage(media(11));
        root->setText(str(10));
        makeActBtn("miroslavahome",act(1));
    }
}
void MiraFather::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"MiraFather");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MiraFather::actionHandler);
    root->addActions(btn);
}

QString MiraFather::str(int id)
{
    QString str[11];
    str[0] = "Отец Миры. После смерти жены он сильно сдал и заметно постарел, хоть все еще и выглядит довольно сносно для своего возраста.";
    QString appeal;
    if(root->vQuest(MiraFatherQW) < 10)
        appeal = "отец Миры";
    else
        appeal = "Афанасий";
    str[1] = appeal + "отводит взгляд и хмурится. Видимо заметил сперму на вашем лице.";
    str[2] = appeal + "отводит взгляд и хмурится. Видимо заметил пятна спермы на вашей одежде.";
    str[3] = "Вы здороваетесь с Мириным отцом и вежливо интересуетесь о его самочувствии. Он приветливо улыбается вам в ответ и говорит, что все хорошо.";
    str[4] = "Вы пару минут болтаете с Миркиным отцом о погоде и прочей ерунде.";
    str[5] = "Вы пару минут перекидываетесь с Афанасием игривыми гляделками и двусмысленностями. Он рад компании молодой девушки и пару раз вы замечаете на себе его блуждающий недвусмысленный взгляд.";
    str[6] = "Вы совсем уж внаглую то поглаживаете себя по бедру, то по груди, то просто томно вздыхаете, проводя язычком по губам и уже через пару минут Афанасий, будучи опытным мужчиной, все прекрасно понимает и ведет вас за руку к себе в дом, а потом и в собственную комнату.";
    str[7] = "Афанасий быстро, но нежно раздевает вас и припадает губами к вашей изнывающей киске и умело вылизывает ее до тех пор, пока не доводит вас до мощного оргазма.";
    str[8] = "Вы недвусмысленно подмигиваете Афанасию и тот, прекрасно все понимая, жестом приглашает вас в дом.";
    str[9] = "Вы недвусмысленно подмигиваете Афанасию, но тот только улыбается в ответ и говорит, что как-нибудь в следующий раз.";
    str[10] = "Афанасий наконец мягко отстраняется от вас и остави пару капель спермы у вас во рту, начинает кончать вам на грудь и живот.";
    return str[id];
}

QString MiraFather::act(int id)
{
    QString act[9];
    act[0] = "Поздороваться";
    act[1] = "Уйти";
    act[2] = "Поболтать";
    act[3] = "Флиртовать";
    act[4] = "Соблазнить";
    act[5] = "Наслаждаться";
    act[6] = "Подмигнуть";
    act[7] = "Дать";
    act[8] = "Далее";
    return act[id];
}

QString MiraFather::media(int id)
{
    QString med[12];
    med[0] = "data/npc/gadukino/MiraFather.jpg";
    med[1] = "data/sex/MiraFather/MiraFatherSexKuni.jpg";
    med[2] = "data/sex/MiraFather/MiraFatherSex.jpg";
    med[3] = "data/sex/MiraFather/MiraFatherSex1.jpg";
    med[4] = "data/sex/MiraFather/MiraFatherSex2.jpg";
    med[5] = "data/sex/MiraFather/MiraFatherSex3.jpg";
    med[6] = "data/sex/MiraFather/MiraFatherSex4.jpg";
    med[7] = "data/sex/MiraFather/MiraFatherBj1.jpg";
    med[8] = "data/sex/MiraFather/MiraFatherBj2.jpg";
    med[9] = "data/sex/MiraFather/MiraFatherBj3.jpg";
    med[10] = "data/sex/MiraFather/MiraFatherBj4.jpg";
    med[11] = "data/sex/MiraFather/MiraFatherCum.jpg";
    return med[id];
}
