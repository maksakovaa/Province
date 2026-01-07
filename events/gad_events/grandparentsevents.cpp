#include "grandparentsevents.h"
#include "../eventhandler.h"
#include "../../menu/qactbutton.h"

GrandparentsEvents::GrandparentsEvents(EventHandler* ptr): root(ptr) {}

void GrandparentsEvents::start(QString arg)
{
    actionHandler(arg);
}

void GrandparentsEvents::actionHandler(QString action)
{
    if (action == "dress_after_sauna")
    {
        root->redressOld();
        root->sVEvent(bana_redress,0);
        root->changeLoc(lgadbana,0);
    }
    if(action == "chickens")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(0));
        root->setDesc(str(0));
        if(root->gVJob(feed_chickens) == 1)
            makeActBtn("feed_chickens",act(0));
        makeActBtn("back_to_loc",act(2));
    }
    if(action == "feed_chickens")
    {
        root->clearActions();
        root->incTime(30);
        root->uVEvent(grandmahelp,1);
        root->uVQuest(grandmaQW,1);
        root->sVJob(feed_chickens,0);
        root->uVStatus(mood,10);
        root->setImage(media(1));
        root->setDesc(str(1));
        makeActBtn("gaddvor",act(1));
    }
    if(action == "boar")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(2));
        root->setDesc(str(2));
        if(root->gVJob(feed_boar) == 1)
            makeActBtn("feed_boar",act(3));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "feed_boar")
    {
        root->clearActions();
        root->incTime(30);
        root->uVEvent(grandmahelp,1);
        root->uVQuest(grandmaQW,1);
        root->sVJob(feed_boar,0);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(3));
        root->setDesc(str(3));
        makeActBtn("gaddvor",act(1));
    }
    if(action == "cow")
    {
        root->setImage(media(4));
        root->setDesc(str(4));
        if(root->gVJob(milk_cow) == 1)
            makeActBtn("milk_cow",act(4));
        if(root->gVJob(feed_cow) == 1)
            makeActBtn("feed_cow",act(5));
        if(root->gVJob(cow_field) == 1 || root->gVJob(graze_cow) == 1)
            makeActBtn("cow_field",act(6));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "milk_cow")
    {
        root->incTime(30);
        root->sVJob(milk_cow,0);
        root->uVEvent(grandmahelp,1);
        root->uVQuest(grandmaQW,1);
        root->setImage(media(5));
        root->setDesc(str(5));
        makeActBtn("gadsarai",act(1));
    }
    if(action == "feed_cow")
    {
        root->incTime(30);
        root->sVJob(feed_cow,0);
        root->uVQuest(grandpaQW,1);
        root->uVEvent(grandmahelp,1);
        root->setImage(media(6));
        root->setDesc(str(6));
        makeActBtn("gadsarai",act(1));
    }
    if(action == "cow_field")
    {
        root->incTime(60);
        root->sVJob(cow_field,0);
        root->uVEvent(grandpahelp,1);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(7));
        if(root->gVJob(graze_cow) == 1)
            root->setDesc(str(8));
        else
            root->setDesc(str(7));
        makeActBtn("graze_field",act(7));
    }
    if(action == "horse")
    {
        root->incTime(1);
        root->setImage(media(8));
        root->setDesc(str(9));
        if(root->gVJob(feed_horse) == 1)
            makeActBtn("feed_horse",act(8));
        if(root->gVJob(horse_field) == 1)
            makeActBtn("horse_field",act(9));
        if(root->gVJob(horse_river) == 1 && root->getSunWeather() >= 0 && root->getTemp() >= 20)
            makeActBtn("horse_river",act(10));
        if(root->gVJob(comb_horse) == 1)
            makeActBtn("comb_horse",act(11));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "feed_horse")
    {
        root->incTime(30);
        root->sVJob(feed_horse,0);
        root->uVQuest(grandpaQW,1);
        root->uVEvent(grandpahelp,1);
        root->setImage(media(9));
        root->setDesc(str(10));
        makeActBtn("gadsarai",act(1));
    }
    if(action == "horse_field")
    {
        root->incTime(60);
        root->sVJob(horse_field,0);
        root->uVEvent(grandpahelp,1);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(10));
        root->setDesc(str(11));
        makeActBtn("field",act(7));
    }
    if(action == "horse_river")
    {
        root->incTime(30);
        root->sVJob(horse_river,2);
        root->setImage(media(10));
        root->setDesc(str(12));
        makeActBtn("gadbeach",act(7));
    }
    if(action == "comb_horse")
    {
        root->incTime(60);
        root->sVJob(comb_horse,0);
        root->uVEvent(grandpahelp,1);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(11));
        root->setDesc(str(13));
        makeActBtn("gadsarai",act(7));
    }
    if(action == "mira_dog")
    {
        root->incTime(5);
        root->setImage(media(12));
        root->setDesc(str(14));
        makeActBtn("free_mira",act(12));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "free_mira")
    {
        root->incTime(5);
        root->sVEvent(mira_dog,0);
        root->setImage(media(13));
        root->setDesc(str(15));
        makeActBtn("gadsarai",act(7));
    }
    if(action == "mira_courtyard")
    {
        root->sVEvent(mira_guestday,root->vStatus(daystart));
        root->incTime(5);
        root->sVEvent(mira_guest,1);
        root->eventStart("Miroslava","miraclothes");
        root->setDesc(str(16));
        makeActBtn("gaddvor",act(7));
    }
    if(action == "mira_house")
    {
        root->sVEvent(mira_guestday,root->vStatus(daystart));
        root->incTime(5);
        root->sVEvent(mira_guest,1);
        root->eventStart("Miroslava","miraclothes");
        root->setDesc(str(17));
        makeActBtn("gadhouse",act(7));
    }
    if(action == "courtyard_nude")
    {
        root->incTime(5);
        if(root->isDay())
            root->setImage(media(14));
        else
            root->setImage(media(15));
        if(root->gVEvent(grandpa_ingaddvor) == 0)
        {
            root->setDesc(str(18));
            makeActBtn("gadhouse",act(13));
        }
        else
        {
            root->setDesc(str(19));
            makeActBtn("grandpa",act(7));
        }
    }
    if(action == "grandpa")
    {
        root->eventStart(action);
    }
    if(action == "garden_nude")
    {
        root->incTime(5);
        if(root->isDay())
            root->setImage(media(16));
        else
            root->setImage(media(17));
        if(root->gVEvent(grandma_ingadgarden) == 1 && root->gVEvent(grandpa_ingadgarden) == 1)
        {
            root->setDesc(str(20));
            makeActBtn("grandma",act(7));
        }
        else if(root->gVEvent(grandma_ingadgarden) == 1 && root->gVEvent(grandpa_ingadgarden) == 0)
        {
            root->setDesc(str(21));
            makeActBtn("grandma",act(7));
        }
        else
        {
            root->setDesc(str(22));
            makeActBtn("gaddvor",act(14));
        }
    }
    if(action == "grandma")
    {
        root->eventStart(action);
    }
    if(action == "market")
    {
        root->incTime(20);
        root->uVQuest(grandmaQW,1);
        //$inventory[7+'_count'] += 10
        root->setImage(media(18));
        root->setDesc(str(23));
        makeActBtn("gadmarket",act(7));
    }
    if(action == "villagecat")
    {
        root->incTime(5);
        root->setImage(media(19));
        root->setDesc(str(24));
        makeActBtn("pat",act(15));
        makeActBtn("gadhouse",act(2));
    }
    if(action == "pat")
    {
        root->incTime(5);
        root->setImage(media(20));
        root->setDesc(str(25));
        makeActBtn("gadhouse",act(2));
    }
    if(action == "talk_pay")
    {
        root->sVEvent(monthbabkapay,1);
        root->uVStatus(money,2000);
        root->incTime(10);
        root->sVEvent(monthgrandmahelp,root->getMonth());
        root->setImage(media(21));
        root->setDesc(str(26));
        makeActBtn("gadhouse",act(7));
    }
    if(action == "grandpa_boletus")
    {
        root->uVEvent(grandpahelp,1);
        root->uVStatus(boletus,-root->gVJob(grandpa_boletus));
        root->incTime(5);
        root->sVJob(go_in_boletus,0);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(22));
        root->setDesc(str(27));
        root->sVJob(grandpa_boletus,0);
        makeActBtn("gadhouse",act(7));
    }
    if(action == "grandpa_boletus_bilberry")
    {
        root->uVEvent(grandpahelp,1);
        root->uVStatus(boletus,-root->gVJob(grandpa_boletus));
        root->uVStatus(bilberry,-root->gVJob(grandpa_bilberry));
        root->incTime(5);
        root->sVJob(go_in_boletus_bilberry,0);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(22));
        root->setDesc(str(28));
        root->sVJob(grandpa_boletus,0);
        root->sVJob(grandpa_bilberry,0);
        makeActBtn("gadhouse",act(7));
    }
    if(action == "grandpa_bilberry")
    {
        root->uVEvent(grandpahelp,1);
        root->uVStatus(bilberry,-root->gVJob(grandpa_bilberry));
        root->incTime(5);
        root->sVJob(go_in_bilberry,0);
        root->uVQuest(grandpaQW,1);
        root->setImage(media(22));
        root->setDesc(str(29));
        root->sVJob(grandpa_bilberry,0);
        makeActBtn("gadhouse",act(7));
    }
    if(action == "talk_swamp")
    {
        root->incTime(5);
        root->sVEvent(forester,0);
        root->setImage(media(18));
        if(root->gVEvent(back_swamp) == 0)
        {
            root->sVEvent(back_swamp,1);
            root->uVQuest(grandmaQW,1);
            root->setDesc(str(30));
        }
        else
        {
            root->uVQuest(grandmaQW,-20);
            root->uVQuest(grandpaQW,-20);
            root->setDesc(str(31));
        }
        makeActBtn("gadhouse",act(7));
    }
    //Change location
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "gaddvor")
    {
        root->changeLoc(lgaddvor);
    }
    if(action == "gadsarai")
    {
        root->changeLoc(lgadsarai);
    }
    if(action == "graze_field")
    {
        root->changeLoc(lgadfield,0,"graze_field");
    }
    if(action == "gadbeach")
    {
        root->changeLoc(lgadbeach);
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse);
    }
    if(action == "gadmarket")
    {
        root->changeLoc(lgadmarket);
    }
}

void GrandparentsEvents::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GrandparentsEvents::actionHandler);
    root->addActBtn(btn);
}

QString GrandparentsEvents::str(int id)
{
    QString str[32];
    str[0] = "Обычные деревенские куры.";
    str[1] = "Вы насыпали птицам зерна и они тут же бросились его клевать. Посмотрев на них немного вы отправились по своим делам.";
    str[2] = "Гордость дедушки и бабушки - Кабан Пятак.";
    str[3] = "Вы покормили Пятака и отправились по своим делам.";
    str[4] = "Бабушкина любимица - корова Зорька.";
    str[5] = "Вы, в течение часа доили, буренку и с каждым разом у вас получается все лучше и лучше.";
    str[6] = "Вы покормили Зорьку и отправились по своим делам.";
    str[7] = "Взяв корову вы отправились на поле, где отдали её пастухам.";
    str[8] = "Взяв корову вы отправились на поле, где вас уже ждал дед и стадо коров.";
    str[9] = "Дедушкин помощник - конь Буян.";
    str[10] = "Вы покормили коня и отправились по своим делам.";
    str[11] = "Вы взяли коня под уздцы и отправились с ним на поле. Там, привязав его к штырю, отправились по своим делам.";
    str[12] = "Вы взяли коня под уздцы и отправились с ним к реке.";
    str[13] = "В течение часа вы расчесывали Буяна. В итоге, закончив, вы, довольная результатом, отправились по своим делам.";
    str[14] = "Около будки Пирата на цепи сидит голая Мира и изображает собачку.";
    str[15] = "Сжалившись, вы решаете отпустить Миру раньше срока."
              "<hero>- Ладно Мира, добрая я сегодня. Можешь считать себя прощенной,</hero> - сказали вы, снимая с Миры ошейник."
              "Девушка еще пару мгновений смотрит на вас, потом быстро одевается и убегает домой.";
    str[16] = "Вы вышли во двор и заметили идущую на встречу Мирославу.<br><npc>- О, Света привет, а я к тебе в гости. Заскучала"
              " совсем одна дома,</npc> - сказала она улыбаясь.";
    str[17] = "Вы были в избе, когда заметили входящую Мирославу.<br><npc>- Тук-тук, Света привет, я к тебе в гости. А то"
              " заскучала совсем одна дома,</npc> - сказала она улыбаясь.";
    str[18] = "Вы зашли во двор и никого не встретив отправились в избу.";
    str[19] = "Вы вышли во двор и сразу наткнулись на дедушку...";
    str[20] = "Зайдя на на огород вы сразу же столкнулись с бабушкой и дедушкой. Дедушка округлив в удивлении глаза, а бабушка тут же кинулась к вам..";
    str[21] = "Зайдя на на огород вы сразу же наткнулись на бабушку...";
    str[22] = "Вы прошли по огороду, никого не встретив, и отправились во двор.";
    str[23] = "Вы зашли в магазин и увидели свою бабулю. Заметив вас, она улыбнулась.<br><npc>- Светуля, хорошо, что ты зашла."
              " Иди, я тебе гостинца куплю,</npc> - сказала она, и купив упаковку печенья, протянула вам.<br><hero>- Спасибо, бабуль,</hero>"
              " - ответили вы, и поцеловав бабушку в щёку, отошли.";
    str[24] = "Упитанный котяра даже не смотрит на вас, хотя знает, что вы рядом.";
    str[25] = "Вы нежно ерошите кота за ушами, на что тот довольно мурлычит, но сразу же прекращает, едва вы перестаете.";
    str[26] = "Войдя в избу, вы видите вашу любимую бабулю и с визгом бросаетесь ей на шею. Наконец наобнимавшись вы отрываетесь от неё."
              " Бабушка осмотрев вас со всех сторон (естественно заметив, что у вас только кожа да кости), начала разговор.<br><npc>- "
              "Как ты выросла внучка. Взрослая уже почти. А мы с дедом все стареем и стареем, помогать нам уже нужно, сами почти ничего"
              " и не можем. Давай Светуля договоримся так: ты нам будешь помогать по хозяйству по мере сил и возможностей, а мы с дедом"
              " будем тебе денюжку платить какую-никакую. И ты к работе и взрослой жизни привыкать будешь и нам помощь. Согласна?</npc>"
              "<br><hero>- Конечно буду помогать бабуль,</hero> - с готовновностью ответили вы.<br><npc>- Ну вот и хорошо Светик, а для"
              " начала мы тебе немного авансом дадим,</npc> - сказала бабушка и протянула две тысячи.<br>Поблагодарив и чмокнув бабушку"
              " в щеку вы отправились по своим делам.";
    str[27] = "Войдя в избу, вы сразу подходите к дедушке:<br><hero>- Деда, вот грибы!</hero><br><npc>- Ой, спасибо внучка, порадовала "
              "старика,</npc> - ответил дедушка. <npc>- Нам то с бабкой до леса трудновато дойти, а грибочков иногда хочется.</npc>"
              "<br><hero>- Ну, если нужно, я еще могу сбегать,</hero> - с готовностью сказали вы.<br><npc>- Сейчас не нужно, Светуля,</npc>"
              " - улыбнулся дед. <npc>- Но если что, я буду иметь ввиду.</npc><br>Чмокнув деда в щеку, вы отправились по своим делам.";
    str[28] = "Войдя в избу, вы сразу подходите к дедушке:<br><hero>- Деда, вот грибы и ягоды!</hero><br><npc>- Ой, спасибо внучка, порадовала "
              "старика,</npc> - ответил дедушка.<br><hero>- Ну, если нужно, я еще могу сбегать,</hero> - с готовностью сказали вы.<br><npc>"
              "- Сейчас не нужно, Светуля,</npc> - улыбнулся дед. <npc>- Но если что, я буду иметь ввиду.</npc><br>Чмокнув деда в щеку, "
              "вы отправились по своим делам.";
    str[29] = "Войдя в избу, вы сразу подходите к дедушке.<br><hero>- Деда, вот ягоды!</hero><br><npc>- Ой, спасибо внучка, порадовала старика,"
                "</npc> - ответил дедушка. <npc>- Нам то с бабкой трудно за ягодами ходить, а варенье на зиму варить нужно.</npc><br><hero>"
                "- Ну, если нужно, я еще могу сбегать,</hero> - с готовностью сказали вы.<br><npc>- Сейчас не нужно, Светуля,</npc> - улыбнулся"
                " дед. <npc>- Но если что, я буду иметь ввиду.</npc><br>Чмокнув деда в щеку, вы отправились по своим делам.";
    str[30] = "В избе вас уже ждала бабушка, с опухшими от слез глазами.<br><npc>- Светуля ты где пропадала?</npc> - кинулась она к вам. <npc>"
              "- Мы с дедом с ног сбились, разыскивая тебя. Уже не знали, что и подумать...</npc><br><hero>- Ба, ээээ... ну так вышло,</hero>"
              " - начали мямлить вы, пытаясь как-то сгладить свой безответственный поступок. <hero>- Я в лесу была... потом на болото попала..."
              " ну и задержалась немного у охотников в избушке.</hero><br><npc>- Совести у тебя нету Света,</npc> - сказала бабушка, все еще "
              "тиская и ощупывая вас, как будто проверяла, все ли части тела на месте. <npc>- Вот если бы с тобой что-нибудь случилось, чтобы "
              "мы с дедом делали? Чтобы матери твоей сказали? Ты о нас с ней хоть подумала?</npc><br><hero>- Бабуль, ну не плачь,</hero>"
              " - обняли в ответ вы бабушку, чувствуя, что глаза самопроизвольно начинают наполняться слезами. <hero>- Я больше так не буду..."
              " честно-честно.</hero><br>Проплакав и пообнимавшись еще какое-то время вы наконец с бабушкой разошлись.";
    str[31] = "В избе вас уже ждала бабушка, глядя на вас с укоризной.<br><npc>- Света ты же обещала...</npc> - только и произнесла она.<br>"
              "<hero>- Бабуль...</hero> - начали вы, но она уже отвернулась и занялась своими делами.";
    return str[id];
}

QString GrandparentsEvents::act(int id)
{
    QString act[16];
    act[0] = "Покормить кур";
    act[1] = "Закончить";
    act[2] = "Уйти";
    act[3] = "Покормить кабана";
    act[4] = "Подоить корову";
    act[5] = "Покормить корову";
    act[6] = "Отвести корову к стаду";
    act[7] = "Далее";
    act[8] = "Покормить коня";
    act[9] = "Отвести коня на поле";
    act[10] = "Отвести коня на реку";
    act[11] = "Расчесать коня";
    act[12] = "Отпустить";
    act[13] = "Идти в избу";
    act[14] = "Выйти во двор";
    act[15] = "Погладить";
    return act[id];
}

QString GrandparentsEvents::media(int id)
{
    QString med[23];
    med[0] = "data/actions/gad_animals/chickens1.jpg";
    med[1] = "data/actions/gad_animals/chickens2.jpg";
    med[2] = "data/actions/gad_animals/boar.jpg";
    med[3] = "data/actions/gad_animals/feed_boar.jpg";
    med[4] = "data/actions/gad_animals/cow.jpg";
    med[5] = "data/actions/gad_animals/milk_cow.jpg";
    med[6] = "data/actions/gad_animals/feed_cow.jpg";
    med[7] = "data/actions/gad_animals/cow_field.jpg";
    med[8] = "data/npc/horse/horse.jpg";
    med[9] = "data/actions/gad_animals/feed_horse.jpg";
    med[10] = "data/npc/horse/lead.jpg";
    med[11] = "data/actions/gad_animals/comb_horse.jpg";
    med[12] = "data/qwest/mira/Mira_kennel2.jpg";
    med[13] = "data/qwest/mira/Mira_kennel3.jpg";
    med[14] = "data/qwest/gadukino_nude/gaddvor_nude.jpg";
    med[15] = "data/qwest/gadukino_nude/gadukino_back_night.jpg";
    med[16] = "data/qwest/gadukino_nude/gadgarden_nude.jpg";
    med[17] = "data/qwest/gadukino_nude/gadukino_back_night.jpg";
    med[18] = "data/qwest/gadukino/grandma.jpg";
    med[19] = "data/npc/gadukino/cat/cat.jpg";
    med[20] = "data/npc/gadukino/cat/pat.jpg";
    med[21] = "data/npc/gadukino/grandma/grandmahelp.jpg";
    med[22] = "data/qwest/gadukino/grandpa1.jpg";
    return med[id];
}
