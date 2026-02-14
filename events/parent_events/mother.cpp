#include "mother.h"
#include "../../Functions.h"
#include "../../game.h"
#include "../../menu/buttons.h"

Mother::Mother(Game* ptr): root(ptr) {}

void Mother::start(QString arg)
{
    makeActBtn("back_to_loc",act(0));
    root->gNPC(mother).talk_max_count = root->gNPC(mother).relation / 20;
    age = root->getAge() + 19;
    if(root->vEvent(momslut) >= 2 && root->gNPC(mother).relation < 40)
        root->gNPC(mother).relation = 40;
    if((root->vEvent(motherKnowWhore) > 0 || root->vEvent(motherKnowSpravka) > 0) && root->vQuest(qwMother) == 0)
        root->vQuest(qwMother) = 1;
    root->rendNpcProfile(mother);
    if(!root->isCloth())
    {
        root->startEvent(eDinMother, "clothes");
        return;
    }
    if(root->vStatus(cumLips) + root->vStatus(cumFace) + root->vStatus(cumFrot) > 0)
    {
        root->startEvent(eDinMother,"cum_talk");
        return;
    }
    if(root->vAddict(alko) > 0)
    {
        root->startEvent(eDrunkReaction, "mother");
        return;
    }
    if(root->vEvent(motherPayDay) != root->vStatus(daystart))
        root->startEvent(eDinMother,"money_talk");
    if(root->isMesec())
        root->startEvent(eDinMother, "tampon_talk");
    if(root->getCurLoc() == lgkafe)
    {
        root->setText(str(0));
        makeActBtn("back_to_loc",act(0));
        return;
    }
    if(root->getCurLoc() == lgrinok)
    {
        root->startEvent(eDinMother, "cloth_talk");
        return;
    }
    if(root->getCurLoc() == lpark)
    {
        root->setImage(media(getRandInt(0,2)));
        if(root->gNPC(mother).talk_count < 100)
            makeActBtn("talk",act(1));
        makeActBtn("go_out",act(0));
        return;
    }
    if(root->getCurLoc() == lglake)
    {
        root->setImage(media(getRandInt(3,11)));
        if(root->gNPC(mother).talk_count < 100)
            makeActBtn("talk",act(1));
        makeActBtn("go_out",act(0));
        return;
    }
    if(root->getCurLoc() == lkuhrpar)
    {
        if(root->getHour() >= 7 && root->getHour() <= 20)
        {
            if(root->gNPC(mother).talk_count < 100)
                makeActBtn("talk",act(1));
            makeActBtn("helpMother",act(2));
            if(root->vStatus(pregnancy) > 0 && root->vEvent(pregTalkFamily) == 0 && root->vStatus(pregnancyKnow) == 1)
                makeActBtn("sayPregnant",act(3));
            if(root->vPreg(abortion) == 1 && root->vEvent(pregTalkFamily) == 1)
            {
                root->vEvent(pregTalkFamily) = 2;
                root->gNPC(mother).relation = 0;
                root->addText(str(10));
            }
            if(root->vEvent(momslut) == 1)
                makeActBtn("sayYouSaw",act(6));
        }
        if(root->vSchool(certificate) == 1 && root->vSchool(block) < 3 && root->vSchool(certificate_gift) == 0)
        {
            root->vSchool(certificate_gift) = 1;
            root->vStatus(money) += 20000;
            root->removeCloth(ClothGroup::schoolUniform);
            root->addText(str(13));
            return;
        }
        if(root->vQuest(qwMother) == 1 && root->gNPC(mother).relation < 40 && root->getCurLoc() == lkuhrpar)
            makeActBtn("tryMakePeace",act(4));
        if(root->getWeek() == 5 && root->vEvent(family_trip_month) != root->getMonth())
        {
            if(root->getHour() > 9)
                root->addText(str(16));
        }
        else if(root->getWeek() == 6 && root->vEvent(family_trip_month) != root->getMonth())
        {
            if(root->getHour() > 9 && root->getHour() < 12)
            {
                root->addText(str(17));
                makeActBtn("to_gadukino",act(5));
            }
        }
        if(root->vEvent(hColMotherRemember) != root->vBody(hairColor))
            root->startEvent(eDinMother, "hair");
        if(root->vEvent(motherPirsDay) != root->getDay())
            root->startEvent(eDinMother, "piercing");
        root->startEvent(eDinMother, "virgin_check");
    }
}

void Mother::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Mother");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Mother::actionHandler);
    root->addActions(btn);
}

void Mother::actionHandler(QString action)
{
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "talk")
        root->startEvent(eDinSister, "talk");
    if(action == "go_out")
        root->startEvent(eDinSister, "go_out");
    if(action == "helpMother")
    {
        root->incTime(30);
        root->changeRep('+',mother,5);
        root->vStatus(mood) -= 10;
        root->setImage(media(root->vEvent(momHelp) + 12));
        root->setText(str(18) + "<br>" + str(1) + str(root->vEvent(momHelp) + 2));
        root->vEvent(momHelp) += 1;
        if(root->vEvent(momHelp) == 7)
        {
            root->vEvent(momHelp) = 0;
            root->vStatus(money) += getRandInt(1,8) * 50;
        }
        if(getRandInt(0,2) < 2)
            root->repEdit(0,lgorodok);
        else
            root->repEdit(getRandInt(1,3),lgorodok);
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "sayPregnant")
    {
        root->incTime(5);
        root->gNPC(mother).relation = 20;
        root->vEvent(pregTalkFamily) = 1;
        root->rendNpcProfile(mother);
        root->setText(str(9));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "sayYouSaw")
    {
        root->incTime(5);
        root->vEvent(momslut) = 2;
        root->rendNpcProfile(mother);
        root->setText(str(12));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "tryMakePeace")
    {
        root->rendNpcProfile(mother);
        int i = getRandInt(1,10);
        makeActBtn("back_to_loc",act(0));
        if(i <= 2)
        {
            root->changeRep('-',mother);
            root->incTime(getRandInt(5,15));
            root->setText(str(14));
        }
        else
        {
            root->changeRep('+',mother,10);
            root->incTime(getRandInt(25,30));
            root->setText(str(15));
        }
    }
    if(action == "to_gadukino")
        root->startEvent(eGadukinoEvents, "to_gadukino");
}

QString Mother::media(int id)
{
    QString med[19];
    med[0] = "data/npc/pavlovo/mother/park1.jpg";
    med[1] = "data/npc/pavlovo/mother/park2.jpg";
    med[2] = "data/npc/pavlovo/mother/park3.jpg";
    med[3] = "data/npc/pavlovo/mother/beach1.jpg";
    med[4] = "data/npc/pavlovo/mother/beach2.jpg";
    med[5] = "data/npc/pavlovo/mother/beach3.jpg";
    med[6] = "data/npc/pavlovo/mother/beach4.jpg";
    med[7] = "data/npc/pavlovo/mother/beach5.jpg";
    med[8] = "data/npc/pavlovo/mother/beach6.jpg";
    med[9] = "data/npc/pavlovo/mother/beach7.jpg";
    med[10] = "data/npc/pavlovo/mother/beach8.jpg";
    med[11] = "data/npc/pavlovo/mother/beach9.jpg";
    med[12] = "data/npc/pavlovo/mother/motherhelp1.jpg";
    med[13] = "data/npc/pavlovo/mother/motherhelp2.jpg";
    med[14] = "data/npc/pavlovo/mother/motherhelp3.jpg";
    med[15] = "data/npc/pavlovo/mother/motherhelp4.jpg";
    med[16] = "data/npc/pavlovo/mother/motherhelp5.jpg";
    med[17] = "data/npc/pavlovo/mother/motherhelp6.jpg";
    med[18] = "data/npc/pavlovo/mother/motherhelp7.jpg";
    return med[id];
}

QString Mother::str(int id)
{
    QString str[19];
    str[0] = "Мать, увидев вас, нахмурила брови: <npc>- Чего пришла? Я сколько раз говорила - не ходи ко мне на работу. Нечего тут молодой девчонке делать!</npc>";
    str[1] = "Мама попросила вас ";
    str[2] = "помыть посуду и подмести на кухне. В течение получаса вы мыли посуду на кухне и убирались.";
    str[3] = "почистить и нарезать овощи. Вы в течение получаса помогали маме на кухне с готовкой.";
    str[4] = "помыть пол. Вы в течение получаса мыли полы в квартире.";
    str[5] = "постирать бельё. Вы в течение получаса стирали бельё в ванной.";
    str[6] = "погладить белье. Вы в течение получаса гладили бельё в зале.";
    str[7] = "сбегать в магазин за продуктами. В течение получаса вы ходили за продуктами в супермаркет. Мелочь мама разрешила оставить себе.";
    str[8] = "сбегать в аптеку за лекарствами. Там работает мамина сестра Людмила и она даст лекарства бесплатно, мама потом сама сочтётся с ней. Мама написала вам небольшой список и вы пошли в аптеку. Там как всегда за прилавком сидит тётя Люда: <npc>- Привет, Светуля. Как жизнь? Как настроение?</npc> Вы поприветствовали тётю и подали ей бумажку, в которой мать написала - что нужно. Тётя Люда быстро собрала необходимое. Вернувшись домой, вы передали всё маме.";
    str[9] = "Вы сказали матери, что беременны. Мать с округлившимися глазами обессиленно села на табуретку. Она грустно сказала: <npc>- Ну что же. Я этого и боялась. Теперь не вздумай делать аборт, если ты сделаешь аборт, то в будущем вряд ли сумеешь иметь детей. Придется тебе рожать ребенка.</npc>";
    str[10] = "Мать грустно посмотрела на вас: <npc>Какая же ты все-таки дура! Сделала аборт, а если теперь у тебя не будет детей? Что, думаешь, будешь вечно молодая и вся жизнь пройдет в веселье?</npc>";
    str[11] = "Сказать, что вы видели, как мать трахалась с хозяином кафе";
    str[12] = "Вы сказали матери, что вы видели ее на складе кафе с хозяином кафе.**Мать заметно побледнела и села на табурет: <npc>- И что ты видела?</npc>.<br>Вы ответили ей, что видели, как она сосала у хозяина кафе, а потом он ее трахнул раком. Мать потупила глаза: <npc>- Ну да, я сплю со Славой. Но хочу тебя сразу предупредить, шантажировать меня у тебя не получится.</npc>**Мать посмотрела вам в глаза: <npc>- Все, чего ты можешь добиться, это разрушить семью.</npc>";
    str[13] = "Мама обрадовалась:<br><npc>- Теперь ты закончила школу и я хочу подарить тебе двадцать тысяч рублей. Можешь купить себе подарок.</npc>";
    str[14] = "Вы попытались поговорить со своей матерью и помириться. Но то ли вы слишком агрессивны, то ли у нее плохое настроение, но итогом \"примирения\" становится очередной скандал.";
    str[15] = "Вы попытались поговорить со своей матерью и помириться. Несмотря на то, что весь получасовой разговор в основном представлял из себя довольно агрессивный монолог вашей матери о морали, болезнях и о том, что вас ждет в будущем, если вы не возьметесь за ум, определенные подвижки в отношениях все же есть.";
    str[16] = "Мама, продолжая заниматься своими делами, говорит вам: <npc>- Света, мы завтра поедем в деревню, в 12 часов. Если хочешь с нами - то подойди ко мне до двенадцати дня.</npc>";
    str[17] = "Мама спрашивает у вас: <npc>- Света, ну что? Поедешь с нами в деревню?</npc>";
    str[18] = "Вы предложили помочь матери по хозяйству.";
    return str[id];
}

QString Mother::act(int id)
{
    QString act[7];
    act[0] = "Отойти";
    act[1] = "Болтать";
    act[2] = "Предложить помочь";
    act[3] = "Сказать матери, что вы беременны";
    act[4] = "Попробовать помириться";
    act[5] = "Ехать в деревню";
    act[6] = "Сказать, что вы видели, как мать трахалась с хозяином кафе";
    return act[id];
}


