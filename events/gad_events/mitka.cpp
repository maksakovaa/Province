#include "mitka.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Mitka::Mitka(Game *ptr): root(ptr) {}

void Mitka::start(QString arg)
{
    actionHandler("mitka");
}

void Mitka::actionHandler(QString action)
{
    if(action == "mitka")
    {
        root->setImage(media(0));
        root->setText(str(0));
        if(root->vEvent(mitka) == 0)
        {
            root->vEvent(mitkaday) = root->vStatus(daystart);
            root->addText(str(1));
            root->vEvent(mitka) = 1;
        }
        else
        {
            root->vEvent(mitkaday) = root->vStatus(daystart);
            root->addText(str(2));
            makeActBtn("normalno",act(0));
            if(root->vEvent(mitkasextimes) == 0)
                makeActBtn("gadukino",act(3));
        }
        if(root->vEvent(mitkasextimes) == 0)
            makeActBtn("gadukino",act(3));
    }
    if(action == "normalno")
    {
        root->setImage(media(0));
        root->setText(str(3));
        root->addText(str(4));
        if(root->vEvent(mitkasextimes) > 0 || root->vSkill(domination) <= -25)
        {
            tmp = getRandInt(0,6);
            root->addText(str(5));
            if(tmp < 3)
                makeActBtn("go_fuck0",act(1));
            else if(tmp >= 3 && tmp <= 5)
                makeActBtn("go_fuck1",act(1));
            else if(tmp == 6)
                makeActBtn("go_fuck2",act(1));
            if(root->vEvent(mitkasextimes) < 11 && root->vAddict(alko) < 6 && root->vSkill(domination) > -25)
                makeActBtn("gadukino",act(2));
        }
        if(root->vEvent(mitkasextimes) == 0)
            makeActBtn("gadukino",act(3));
    }
    if(action == "go_fuck0")
    {
        root->incTime(15);
        if(root->vEvent(mitkasex) == 0)
        {
            root->vEvent(mitkasex) = 1;
            root->vSex(guy) += 1;
        }
        root->setBoyName("Митька");
        root->vSex(silavag) = 0;
        root->vSex(dick) = 16;
        root->vSex(pose) = 0;
        if(root->vBody(vagina) == 0)
            root->setImage(media(1));
        else
            root->setImage(media(2));
        root->setText(str(6));
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        root->addText(str(7));
        makeActBtn("gadukino",act(3));
    }
    if(action == "go_fuck1")
    {
        root->incTime(15);
        if(root->vEvent(mitkasex) == 0)
        {
            root->vEvent(mitkasex) = 1;
            root->vSex(guy) += 1;
        }
        root->setBoyName("Митька");
        root->vSex(silavag) = 0;
        root->vSex(dick) = 16;
        root->vSex(pose) = 0;
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(3));
        root->setText(str(8));
        root->blow_job();
        if(tmp == 3)
        {
            makeActBtn("cumlips",act(4));
        }
        else if(tmp == 4)
        {
            makeActBtn("cumface",act(4));
        }
        else if(tmp == 5)
        {
            makeActBtn("cumlips2",act(4));
        }
    }
    if(action == "cumlips")
    {
        root->setImage(media(4));
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->addText(str(9));
        root->vStatistics(swallow) += 1;
        root->vSkill(domination) -= 1;
        makeActBtn("gadukino",act(3));
    }
    if(action == "cumface")
    {
        root->setImage(media(5));
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->cum("face");
        root->addText(str(10));
        root->vSkill(domination) -= 1;
        makeActBtn("gadukino",act(3));
    }
    if(action == "cumlips2")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->cum("lip");
        if(root->vEvent(mitkasextimes) >= 14)
        {
            root->addText(str(11));
            root->setImage(media(7));
        }
        else
        {
            root->addText(str(12));
            root->setImage(media(6));
        }
        makeActBtn("gadukino",act(3));
    }
    if(action == "go_fuck2")
    {
        root->incTime(10);
        root->setBoyName("Митька");
        root->vSex(silavag) = 0;
        root->vSex(dick) = 16;
        root->vSex(pose) = 0;
        root->cum("anus");
        root->vBody(anus) +=1;
        if(root->vBody(anus) < 10)
            root->vSkill(domination) -= 1;
        if(root->vBody(anus) < 10)
            root->setImage(media(8));
        else if(root->vBody(anus) >= 10 && root->vBody(anus) < 25)
            root->setImage(media(10));
        else
            root->setImage(media(9));
        root->setText(str(13));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        makeActBtn("gadukino",act(3));
    }
    if(action == "gadukino")
    {
        root->changeLoc(lgadukino);
    }
}

void Mitka::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"mitka");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Mitka::actionHandler);
    root->addActions(btn);
}

QString Mitka::str(int id)
{
    QString str[14];
    str[0] = "Деревенский парень едва старше вас, вы его знаете с детства и будучи еще детьми вместе купались на реке.";
    str[1] = "- Ну чо, Светик, если хорошая погода, заходи в восемь вечера, бухнем самогонки, попиздим за жизнь.";
    str[2] = "- Привет Светик. Как житуха?";
    str[3] = "Вы ответили что у вас все нормально и Митька улыбнувшись предложил:";
    str[4] = "- Ну чо, Светик, заходи в восемь вечера, бухнем самогонки, попиздим за жизнь.";
    str[5] = "Тут он почесал яйца и добавил с ухмылкой:"
             "- Светик, а пойдем сейчас поебемся, а то стояк заеб.";
    str[6] = "Митька отвел вас к своему дому и привел на веранду, там он уложил вас на диване и стал бесцеремонно раздевать.";
    str[7] = "Митяй лег на бок и закурил: - Охуенно!";
    str[8] = "Митька отвел вас к своему дому, где требовательно начал давить вам на плечи, опуская на колени...";
    str[9] = "Митька крепко хватает руками вас за голову и с силой начинает долбить вас в глотку, пока, наконец, не начинает кончать.";
    str[10] = "Митька берет член рукой и начинает яростно надрачивать его прямо перед вашим лицом, пока, наконец не покрывает своей липкой теплой спермой.";
    str[11] = "Вы засовываете пальцы себе в рот и растягивая ими губы, с силой насаживаетесь головой на кончающий Митькин член.";
    str[12] = "Вы сильнее насаживаетесь головой на Митькин член, а спустя пару мгновений чувствуете, как вам в рот ударяет горячая струя его терпкой спермы.";
    str[13] = "Митька отвел вас к своему дому, где, ничуть не церемонясь, начал быстро вас раздевать.";
    return str[id];
}

QString Mitka::act(int id)
{
    QString str[5];
    str[0] = "Нормально";
    str[1] = "Пойдём";
    str[2] = "Отказаться";
    str[3] = "Уйти";
    str[4] = "Глотать";
    return str[id];
}

QString Mitka::media(int id)
{
    QString med[11];
    med[0] = "data/npc/gadukino/mitka/mitka.jpg";
    med[1] = "data/sex/mitkasex2/mitkafirst.jpg";
    med[2] = "data/sex/mitkasex2/mitkasex2.jpg";
    med[3] = "data/sex/mitkasex2/MitkaBjHome.jpg";
    med[4] = "data/sex/mitkasex2/MitkaBjHomeCum1.jpg";
    med[5] = "data/sex/mitkasex2/MitkaBjHomeCum2.jpg";
    med[6] = "data/sex/mitkasex2/MitkaBjHomeCum3.jpg";
    med[7] = "data/sex/mitkasex2/MitkaBjHomeCum4.jpg";
    med[8] = "data/sex/mitkasex2/MitkaAnalHome.jpg";
    med[9] = "data/sex/mitkasex2/MitkaAnalHome2.jpg";
    med[10] = "data/sex/mitkasex2/MitkaAnalHome3.jpg";
    return med[id];
}
