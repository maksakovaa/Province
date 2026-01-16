#include "mirasex.h"
#include "../eventhandler.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
MiraSex::MiraSex(EventHandler* ptr): root(ptr) {
    you_orgasm = 0;
}

void MiraSex::start(QString arg)
{

}

void MiraSex::actionHandler(QString action)
{
    if(action == "miralick_first") miralick_first();
    if(action == "mirakiss") mirakiss();
    if(action == "foreplay") foreplay();
    if(action == "miralick_start") miralick_start();
    if(action == "lickmira_first") lickmira_first();
    if(action == "lickmira_start") lickmira_start();
    if(action == "horny_talk") horny_talk();
    if(action == "miralick_orgasm") miralick_orgasm();
    if(action == "lickmira_mis1") lickmira_mis1();
    if(action == "lickmira_mis2") lickmira_mis2();
    if(action == "pose69_1") pose69_1();
    if(action == "pose69_2") pose69_2();
    if(action == "miralick_stand1") miralick_stand1();
    if(action == "miralick_stand2") miralick_stand2();
    if(action == "miralick_dog") miralick_dog();
    if(action == "mirafinger") mirafinger();
    if(action == "mirafinger_dog") mirafinger_dog();
    if(action == "dog_random")
    {
        if(getRandInt(1,2) == 1)
            miralick_dog();
        else
            mirafinger_dog();
    }
    if(action == "end") end();
}

void MiraSex::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MiraSex::actionHandler);
    root->addActBtn(btn);
}

QString MiraSex::str(int id)
{
    QString str[76];
//textstand
    str[0] = "Стоя, облокотившись на дерево, вы чувствуете жаркое дыхание Миры у себя между ног и возбуждающие прикосновения её языка. ";
    str[1] = "Закрыв глаза и облокотившись на дерево, вы ощущаете легкие прикосновения языка Миры к вашей вагине. ";
    str[2] = "Облокотившись на дерево, вы ощущаете жаркое дыхание Миры у себя между ног и легкие прикосновения её языка к вашей вагине. ";
//textdog
    str[3] = "Стоя раком, вы чувствуете жаркое дыхание Миры у себя на попе и возбуждающие прикосновения её языка к вашей киске. ";
    str[4] = "Закрыв глаза и оттопырив попу перед Мирой, вы ощущаете легкие прикосновения её языка к вашей вагине. ";
    str[5] = "Стоя раком перед Мирой, вы ощущаете жаркое дыхание у себя между ног, чувствуете возбуждающие прикосновения её языка и пальчиков к вашей вагине. ";
    str[6] = "Стоя раком перед Мирой, вы ощущаете возбуждающие прикосновения её рук к вашей возбужденной киске. ";
//textmis
    str[7] = "Мира сидит на камне перед вами, широко раздвинув свои ноги и наблюдает за процессом. ";
    str[8] = "Сидя на камне с широко раздвинутыми ногами, Мира наслаждается лаской ваших губ и язычка. ";
    str[9] = "Широко раздвинув ноги, Мира наслаждается, ощущая ваше жаркое дыхание на своей промежности и чувствуя возбуждающие прикосновения язычка к вагине. ";
//text69
    str[10] = "Вы с Мирой лежите в позе \"69\", и жадно вылизываете друг друга. ";
    str[11] = "Вы лежите на земле и видите перед глазами, истекающую соками Мирину киску. ";
    str[12] = "Широко раздвинув ноги, Мира нависла своей киской над вами и наслаждается, ощущая ваше жаркое дыхание на своей промежности и чувствуя"
              " возбуждающие прикосновения язычка к вагине. ";
    str[13] = "Вы ложитесь на землю, Мира, перекинув ногу через вас, занимает позицию сверху. Вы чувствуете жаркое дыхание Миры у себя между ног и возбуждающие"
              " прикосновения её языка. ";
    str[14] = "Вылизывая Миру вы ощущаете жаркое дыхание у себя между ног и возбуждающие прикосновения её языка. ";
//textlick
    str[15] = "Раздвинув пальцами половые губки, она неумело лижет, проводя неопытным язычком по всей длине вашей писи, ";
    str[16] = "Она несмело цeлует вашу писeчку, пoсaсывaя ee губки, иногда задевая неопытным язычкoм ваш клитoр, ";
    str[17] = "Она осторожно водит неопытным язычком сверху вниз, по всей длине вашей писи, иногда нежно касаясь клитoра, ";
    str[18] = "Раздвинув пальцами половые губки, она умело лижет, проводя язычком по всей длине вашей писи и щекоча ваш клиторок, ";
    str[19] = "Она цeлует вашу писeчку, пoсaсывaя ee губки, иногда пытаясь проникнуть шаловливым язычкoм в вашу " + root->getVaginaTipe2() + " вагину, ";
    str[20] = "Она быстро водит умелым язычком сверху вниз, по всей длине вашей писи, иногда делая круговые движения, и нежно касаясь клитoра, ";
    str[21] = "Уткнувшись лицом между её ног, вы неумело лижете, проводя неопытным язычком по всей длине писи, ";
    str[22] = "Вы несмело цeлуете её писeчку, пoсaсывaя половые губки, иногда задевая неопытным язычкoм её клитoр, ";
    str[23] = "Вы осторожно водите неопытным язычком сверху вниз, по всей длине её писи, иногда осторожно касаясь клитoра, ";
    str[24] = "Уткнувшись лицом между её ног, вы бойко лижете, проводя язычком по всей длине её писи, не забывая про клитор, ";
    str[25] = "Вы цeлуете её киску, лаская половые губки, иногда проникая своим язычком между ними, касаетесь клитора, ";
    str[26] = "Вы быстро водите умелым язычком сверху вниз, скользя вдоль всей её промежности, проникая в вагину и лаская её клитор, ";
//textfinger
    str[27] = "Вы чувствуете быстрые движения её пальцев, снующих туда-сюда в вашей писе, ";
    str[28] = "Она трахает двумя пальцами вашу " + root->getVaginaTipe2() + " вагину, ";
    str[29] = "Она вводит пальцы на всю длинну в вашу " + root->getVaginaTipe2() + ", делая поступательные движения, ";
//text_emotions
    str[30] = "вызывая бурю эмоций внизу живота.";
    str[31] = "вызывая у вас стоны наслаждения.";
    str[32] = "срывая с ваших губ стоны наслаждения и заставляя двигаться бедрами навстречу.";
    str[33] = "срывая с ваших губ стоны наслаждения и заставляя подмахивать попой.";
    str[34] = "заставляя вздрагивать всем телом, при каждом прикосновении.";
    str[35] = "срывая с её губ стоны наслаждения.";
    str[36] = "заставляя выгибаться всем телом и сильнее прижимать вашу голуву к своей промежности.";
//text_cum
    str[37] = "Постепенно приятное тепло и пульсация нарастают внизу живота, потом ощущения обрушиваются на вас и все ваше тело охватывают горячие волны "
              "оргазма. Вы невольно кричите от удовольствия извиваясь и вздрагивая всем телом.";
    str[38] = "Через некоторое время Мира задрожала и ее киска начала ритмично пульсировать перед вашим лицом. Она выгнулась в оргазме и уже не сдерживаясь"
              " стонала во весь голос, сжав вашу голову ногами и заливая лицо своими соками.";
    str[39] = "Постепенно приятное тепло и пульсация нарастают внизу живота, потом ощущения обрушиваются на вас и все ваше тело охватывают горячие волны "
              "оргазма. Одновременно вы замечаете, что Мира задрожала всем телом и ее киска начала ритмично пульсировать. Она выгнулась в оргазме и уже "
              "не сдерживаясь стонала во весь голос, сжав вашу голову ногами и заливая лицо своими соками.";

    str[40] = "Вы страстно впиваетесь губами в сочные губы Миры. Она отвечает на ваш поцелуй не менее страстно, вызвав у вас стон наслождения.";
    str[41] = "Вы целуетесь с Мирой ощущая ее мягкие губы на своих губах и ее тонкий ловкий язычок проникающий в ваш рот.";
    str[42] = "Мирослава нежно целует вас в " + root->getLipTalk3() + " и вы чуствуете как возбуждение от ее поцелуя охватывает вас.";
    str[43] = "Мира страстно целует ваши " + root->getLipTalk3() + " и вы отвечаете взаимностью на этот поцелуй, чувствуя как возбуждение охватывает "
              "каждую частичку вашего тела.";
    str[44] = "Опустившись на колени, Мира несмело потянулась к вашим трусам, глядя вам в глаза и робко улыбаясь. Вы, облокотившись на дерево и прикрыв "
              "глаза, стали ждать продолжения...";
    str[45] = "Опустившись на колени и не обнаружив на вас трусов, Мира несмело коснулась языком вашей вагине, как будто пробовала на вкус, вызвав у вас "
              "непроизвольный стон наслаждения. Вы, облокотившись на дерево и прикрыв глаза, стали ждать продолжения...";
    str[46] = "Вы страстно целуетесь с Мирой, поглаживая лодошкой её промежность и возбуждая еще сильнее.";
    str[47] = "Вы целуете Миру в губы нежным поцелуем, поглаживая при этом её писю, через трусики, своей рукой..";
    str[48] = "Вы целуетесь с Мирославой, ваши " + root->getLipTalk3() + " соприкасаются с её губами в жарком поцелуе, а ваша ладонь на промежности "
              "заставляет её возбужденно постанывать.";
    str[49] = "Мира ласкает ваши груди " + intQStr(root->vBody(breastsSize)) + " размера, нежно сжимая их в руках и покрывая поцелуями.";
    str[50] = "Вы чувствуете жаркое дыхание у себя на груди и ловкий язычок Миры, неустаноо ласкающий ваши соски и доставляющий вам огромное наслаждение.";
    str[51] = "Мира ласкает ваши груди, нежно сжимая их в руках, покрырывая поцелуями и играя с сосочками кончиком языка.";
    str[52] = "Опустившись на колени, Мира потянулась к вашим трусам с улыбкой на лице, заглядывая вам в глаза. Вы, облокотившись на дерево и прикрыв глаза,"
              " стали ждать продолжения...";
    str[53] = "Опустившись на колени и не обнаружив на вас трусов, Мира лизнула языком вашу " + root->getVaginaTipe2() + " вагину, пробуя её вкус, вызвав у"
            " вас непроизвольный стон наслаждения. Вы, облокотившись на дерево и прикрыв глаза, стали ждать продолжения...";
    str[54] = "Опустившись на колени, вы осторожно прикоснулись к трусам Миры и принялись неловко их стягивать с неё. Она, сгорая от возбуждения, приподняла "
              "попку с камня, решив помочь вам и убыстряя процесс...";
    str[55] = "Опустившись на колени, вы потянулись к трусам Миры и принялись привычным движением их стягивать с неё. Она, сгорая от возбуждения, приподняла"
              " попку с камня, решив помочь вам и убыстряя процесс...";
    str[56] = "Мира поймав ваш взгляд усмехнулась. Подойдя к вам в плотную, она развернула вас спиной к себе и занув руку в ваши трусики воскликнула:";
    str[57] = "<npc>- О, да тут целый водопад!</npc>";
    str[58] = "<npc>- Смотри ты, сучка потекла!</npc>";
    str[59] = "Поелозив в ваших трусах еще пару мгновений, Мира сказала:";
    str[60] = "<npc>- Всё, вали отсюда, шлюшка, некогда мне с тобой заниматься.</npc>"
              "И напевая под какую-то песенку отправилась домой. Вы посмотрев ей в след пару мгновений, тоже пошли в сторону своего дома.";
    str[61] = "<npc>- Ладно, становись раком, помогу своей шлюшке.</npc>"
              "Вы с готовностью стянули свои трусики и бухнулись на колени, становясь перед ней раком.";
    str[62] = "Неожиданно для вас отлизывая Мире вы начали кончать сами. Между ног полыхал пожар и волны удовольствия охватывали тело, вы стонали, но лизать"
              " не прекращали.";
    str[63] = "Отойдя от оргазма, Мира разжала свои ноги, выпустив вашу голову из плена. Стерев её соки со своего лица и приведя себя себя в порядок, вы "
              "отправились домой.";
    str[64] = "Отойдя от оргазма, Мира разжала свои ноги, выпустив вашу голову из плена. Стерев её соки со своего лица и приведя себя себя в порядок, вы "
              "посмотрели на Миру.";
    str[65] = "Отойдя от оргазма, Мира разжала свои ноги, выпустив вашу голову из плена. Через некоторое время, отойдя от оргазма, вы продолжили с Мирой...";
    str[66] = "Отойдя от оргазма, Мира разжала свои ноги, выпустив вашу голову из плена. Стерев её соки со своего лица и приведя себя себя в порядок, вы "
              "с Мирой отправились домой.";
    str[67] = "Отойдя от оргазма, Мира разжала свои ноги, выпустив вашу голову из плена.";
    str[68] = "Через некоторое время, отойдя от оргазма, вы улыбнулись Мире и продолжили...";
    str[69] = "Через некоторое время, отойдя от оргазма, вы с Мирой привели себя в проядок и счастливые отправились домой...";
    str[70] = "Ноги вас не держат и вы сползаете вниз, не в состоянии шевельнуться. Через некоторое время, отойдя от оргазма, вы привели себя в порядок "
              "и отправились домой.";
    str[71] = "Ноги вас не держат и вы сползаете вниз, не в состоянии шевельнуться. Через некоторое время, отойдя от оргазма, вы продолжили с Мирой...";
    str[72] = "Ноги вас не держат и вы сползаете вниз, не в состоянии шевельнуться. Через некоторое время, отойдя от оргазма, вы с Мирой привели себя в "
              "порядок и отправились домой.";
    str[73] = "Тело вас не слушается и вы плюхаетесь на живот, не в состоянии пошевелиться. Через некоторое время, отойдя от оргазма, вы продолжили с Мирой.";
    str[74] = "Тело вас не слушается и вы плюхаетесь на живот, не в состоянии пошевелиться. Через некоторое время, отойдя от оргазма, вы с Мирой привели "
              "себя в порядок и отправились домой.";
    str[75] = "Тело вас не слушается и вы плюхаетесь на живот, не в состоянии пошевелиться. Мира ехидно взглянула на вас и дав облизать свои пальцы, "
              "чтобы очистить их от ваших же выделений, пошла в сторону дома. Через некоторое время, отойдя от оргазма, вы привели себя в порядок и "
              "отправились домой.";
    return str[id];
}
QString MiraSex::act(int id)
{
    QString act[13];
    act[0] = "Далее";
    act[1] = "Целоваться дальше";
    act[2] = "Стонать";
    act[3] = "Продолжать ласки";
    act[4] = "Стать раком";
    act[5] = "Стоять на ногах";
    act[6] = "Лизать";
    act[7] = "Лизать дальше";
    act[8] = "Лечь на землю";
    act[9] = "Встать на ноги";
    act[10] = "Встать на колени";
    act[11] = "Стоять дальше";
    act[12] = "Стоять раком дальше";
    return act[id];
}
QString MiraSex::media(int id)
{
    QString med[35];
    med[0] = "data/qwest/mira/mirakiss1.jpg";
    med[1] = "data/qwest/mira/mirakiss2.jpg";
    med[2] = "data/qwest/mira/mirakiss3.jpg";
    med[3] = "data/qwest/mira/mirakiss4.jpg";
    med[4] = "data/qwest/mira/mira_start_tanga0.jpg";
    med[5] = "data/qwest/mira/mira_start_tanga1.jpg";
    med[6] = "data/qwest/mira/miraforeplay1.jpg";
    med[7] = "data/qwest/mira/miraforeplay2.jpg";
    med[8] = "data/qwest/mira/miraforeplay3.jpg";
    med[9] = "data/qwest/mira/miraforeplay4.jpg";
    med[10] = "data/qwest/mira/miraforeplay5.jpg";
    med[11] = "data/qwest/mira/miraforeplay6.jpg";
    med[12] = "data/qwest/mira/miraforeplay7.jpg";
    med[13] = "data/qwest/mira/lickmira_start.jpg";
    med[14] = "data/qwest/mira/horny_talk.jpg";
    med[15] = "data/qwest/mira/lickmira_mis1.jpg";
    med[16] = "data/qwest/mira/lickmira_mis2.jpg";
    med[17] = "data/qwest/mira/lickmira_mis3.jpg";
    med[18] = "data/qwest/mira/lickmira_mis_cum.jpg";
    med[19] = "data/qwest/mira/lickmira_69_1.jpg";
    med[20] = "data/qwest/mira/lickmira_69_2.jpg";
    med[21] = "data/qwest/mira/lickmira_69_3.jpg";
    med[22] = "data/qwest/mira/lickmira_69_cum1.jpg";
    med[23] = "data/qwest/mira/lickmira_69_cum2.jpg";
    med[24] = "data/qwest/mira/miralick_stand_cum.jpg";
    med[25] = "data/qwest/mira/miralick_stand1.jpg";
    med[26] = "data/qwest/mira/miralick_stand2.jpg";
    med[27] = "data/qwest/mira/miralick_dog1.jpg";
    med[28] = "data/qwest/mira/miralick_dog2.jpg";
    med[29] = "data/qwest/mira/miralick_dog_cum.jpg";
    med[30] = "data/qwest/mira/mirafinger_dog1.jpg";
    med[31] = "data/qwest/mira/mirafinger_dog2.jpg";
    med[32] = "data/qwest/mira/mirafinger_dog3.jpg";
    med[33] = "data/qwest/mira/mirafinger_dog4.jpg";
    med[34] = "data/qwest/mira/mirafinger_dog_cum.jpg";
    return med[id];
}

void MiraSex::miralick_first()
{
    root->incTime(5);
    if(root->vStatus(horny) < 60)
        root->sVStatus(horny,60);
    else
        root->uVStatus(horny,10);
    root->uVEvent(miralick,1);
    checkMiraSex();
    root->uVSC(lesbianSex,1);
    if(root->isPanties())
    {
        root->setImage(media(5));
        root->setDesc(str(44));
    }
    else
    {
        root->setImage(media(4));
        root->setDesc(str(45));
    }
    makeActBtn("miralick_stand1",act(2));
}
void MiraSex::mirakiss()
{
    root->incTime(5);
    if(root->vStatus(horny) < 60)
        root->uVStatus(horny,5);
    if(root->gVEvent(mirahorny) < 60)
        root->uVEvent(mirahorny,5);
    root->setImage(media(getRandInt(0,3)));
    root->setDesc(str(getRandInt(40,43)));
    if(root->vStatus(horny) < 20 || root->gVEvent(mirahorny) < 20)
        makeActBtn("mirakiss",act(1));
    else
        makeActBtn("foreplay",act(0));
}
void MiraSex::foreplay()
{
    root->incTime(5);
    if(root->vStatus(horny) >= root->gVEvent(mirahorny))
    {
        root->setImage(media(getRandInt(6,9)));
        if(root->vStatus(horny) < 60)
            root->uVStatus(horny,getRandInt(0,5));
        root->uVEvent(mirahorny,10);
        root->setDesc(str(getRandInt(46,48)));
    }
    else
    {
        root->setImage(media(getRandInt(10,12)));
        root->uVStatus(horny,10);
        root->setDesc(str(getRandInt(49,51)));
    }
    if(root->vStatus(horny) < 40 || root->gVEvent(mirahorny) < 40)
        makeActBtn("foreplay",act(3));
    else
    {
        if(root->vStatus(horny) >= root->gVEvent(mirahorny))
            makeActBtn("lickmira_start",act(0));
        else
            makeActBtn("miralick_start",act(0));
    }
}
void MiraSex::miralick_start()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(0,5));
    root->uVEvent(miralick,1);
    root->uVSC(lesbianSex,1);
    if(root->isPanties())
    {
        root->setImage(media(5));
        root->setDesc(str(52));
        makeActBtn("miralick_stand2",act(5));
        makeActBtn("dog_random",act(4));
    }
    else
    {
        root->setImage(media(4));
        root->setDesc(str(53));
        makeActBtn("miralick_stand2",act(2));
    }
}
void MiraSex::lickmira_first()
{
    root->incTime(5);
    root->uVEvent(mirahorny,getRandInt(0,5));
    checkMiraSex();
    root->uVEvent(lickmira,1);
    root->uVSC(lesbianSex,1);
    root->setImage(media(13));
    if(root->vSC(lesbianSex) < 10)
        root->setDesc(str(54));
    else
        root->setDesc(str(55));
    makeActBtn("lickmira_mis1",act(6));
}
void MiraSex::lickmira_start()
{
    root->incTime(5);
    root->uVEvent(mirahorny,getRandInt(0,5));
    checkMiraSex();
    root->uVSC(lesbianSex,1);
    root->setImage(media(13));
    if(root->vSC(lesbianSex) < 10)
        root->setDesc(str(54));
    else
        root->setDesc(str(55));
    makeActBtn("lickmira_mis2",act(6));
}
void MiraSex::horny_talk()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->setImage(media(14));
    root->setDesc(str(56));
    if(root->vStatus(horny) >= 80)
        root->addDesc(str(57));
    else
        root->addDesc(str(58));
    root->addDesc(str(59));
    if(root->gVQuest(miraQW) < 15)
        root->addDesc(str(60));
    else
        root->addDesc(str(61));
    if(root->gVQuest(miraQW) < 15)
        makeActBtn("end",act(0));
    else
        makeActBtn("mirafinger",act(2));
}
void MiraSex::miralick_orgasm()
{
    if(root->vStatus(horny) == 100)
    {
        root->uVSC(orgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
        you_orgasm += 1;
        root->setDesc(str(62));
    }
}
void MiraSex::lickmira_mis1()
{
    root->incTime(5);
    if(root->vSC(lesbianSex) < 10)
    {
        root->uVEvent(mirahorny,10);
        root->uVStatus(horny,getRandInt(0,5));
    }
    else
    {
        root->uVEvent(mirahorny,20);
        root->uVStatus(horny,getRandInt(3,7));
    }
    if(root->gVEvent(mirahorny) < 100)
    {
        root->setImage(media(getRandInt(15,17)));
        QString result = str(getRandInt(7,9));
        if(root->vSC(lesbianSex) < 10)
           result += str(getRandInt(21,23));
        else
            result += str(getRandInt(24,26));
        if(root->vStatus(horny) < 60)
            result += str(34);
        else if(root->vStatus(horny) < 80)
            result += str(35);
        else
            result +=str(36);
        root->setDesc(result);
        miralick_orgasm();
    }
    else
    {
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(18));
        QString result = str(getRandInt(7,9));
        if(root->vSC(lesbianSex) < 10)
            result += str(getRandInt(21,23));
        else
            result += str(getRandInt(24,26));
        result += str(36) + str(38);
        miralick_orgasm();
        if(root->vStatus(horny) < 60)
            root->addDesc(str(63));
        else
            root->addDesc(str(64));
    }
    if(root->gVEvent(miraorgasm) == 0)
        makeActBtn("lickmira_mis1",act(7));
    else
    {
        if(root->vStatus(horny) < 60)
            makeActBtn("end",act(0));
        if(root->vStatus(horny) >= 60)
            makeActBtn("horny_talk",act(0));
    }
}
void MiraSex::lickmira_mis2()
{
    root->incTime(5);
    if(root->vSC(lesbianSex) < 10)
    {
        root->uVEvent(mirahorny,10);
        root->uVStatus(horny,getRandInt(0,5));
    }
    else
    {
        root->uVEvent(mirahorny,20);
        root->uVStatus(horny,getRandInt(3,7));
    }
    if(root->gVEvent(mirahorny) < 100)
    {
        root->setImage(media(getRandInt(15,17)));
        QString result = str(getRandInt(7,9));
        if(root->vSC(lesbianSex) < 10)
            result += str(getRandInt(21,23));
        else
            result += str(getRandInt(24,26));
        if(root->vStatus(horny) < 60)
            result += str(34);
        else if(root->vStatus(horny) < 80)
            result += str(35);
        else
            result +=str(36);
        root->setDesc(result);
        miralick_orgasm();
    }
    else
    {
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(18));
        QString result = str(getRandInt(7,9));
        if(root->vSC(lesbianSex) < 10)
            result += str(getRandInt(21,23));
        else
            result += str(getRandInt(24,26));
        result += str(36) + str(38);
        miralick_orgasm();
        if(root->vStatus(horny) < 60)
            root->addDesc(str(65));
        else
            root->addDesc(str(66));
    }
    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->vStatus(horny) >= root->gVEvent(mirahorny))
        {
            if(getRandInt(1,2) == 1)
                makeActBtn("pose69_2",act(8));
            else
                makeActBtn("lickmira_mis2",act(7));
        }
        else
        {
            makeActBtn("pose69_2",act(8));
            makeActBtn("miralick_stand2",act(9));
            makeActBtn("dog_random",act(4));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("miralick_stand2",act(9));
        makeActBtn("dog_random",act(4));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(7));
    else
        makeActBtn("end",act(0));
}
void MiraSex::pose69_1()
{
    root->incTime(5);
    if(root->vSC(lesbianSex) < 10) root->uVEvent(mirahorny,10);
    if(root->vSC(lesbianSex) >= 10) root->uVEvent(mirahorny,20);
    if(root->gVEvent(miralick) < 10) root->uVStatus(horny,10);
    if(root->gVEvent(miralick) >= 10) root->uVStatus(horny,20);

    QString result = str(13);
    if(root->vSC(lesbianSex) < 10)
        result += str(getRandInt(21,23));
    else
        result += str(getRandInt(24,26));
    if(root->vStatus(horny) < 60)
        result += str(34);
    else if(root->vStatus(horny) < 80)
        result += str(35);
    else
        result += str(36);
    result += str(14);
    if(root->gVEvent(miralick) < 10)
        result += str(getRandInt(15,17));
    else
        result += str(getRandInt(18,20));
    if(root->vStatus(horny) < 60)
        result += str(30);
    else if(root->vStatus(horny) < 80)
        result += str(31);
    else
        result += str(32);
    if(root->gVEvent(mirahorny) < 100 && root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(19,21)));
        root->setDesc(result);
    }
    else if(root->gVEvent(mirahorny) >= 100 && root->vStatus(horny) < 100)
    {
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(23));
        root->setDesc(result + str(38));
        root->addDesc(str(67));
    }
    else if(root->gVEvent(mirahorny) < 100 && root->vStatus(horny) >= 100)
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(22));
        root->setDesc(result + str(37));
        root->addDesc(str(68));
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(getRandInt(37,38)));
        root->setDesc(result + str(39));
        root->addDesc(str(69));
    }
    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->gVEvent(mirahorny) <= root->vStatus(horny))
        {
            if(getRandInt(1,2) == 1)
                makeActBtn("pose69_2",act(7));
            else
                makeActBtn("lickmira_mis2",act(10));
        }
        else
        {
            makeActBtn("pose69_2",act(7));
            makeActBtn("miralick_stand2",act(9));
            makeActBtn("dog_random",act(4));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("miralick_stand2",act(9));
        makeActBtn("dog_random",act(4));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(10));
    else
        makeActBtn("end",act(0));
}
void MiraSex::pose69_2()
{
    root->incTime(5);
    if(root->vSC(lesbianSex) < 10) root->uVEvent(mirahorny,10);
    if(root->vSC(lesbianSex) >= 10) root->uVEvent(mirahorny,20);
    if(root->gVEvent(miralick) < 10) root->uVStatus(horny,10);
    if(root->gVEvent(miralick) >= 10) root->uVStatus(horny,20);

    QString result = str(getRandInt(10,12));
    if(root->vSC(lesbianSex) < 10)
        result += str(getRandInt(21,23));
    else
        result += str(getRandInt(24,26));
    if(root->vStatus(horny) < 60)
        result += str(34);
    else if(root->vStatus(horny) < 80)
        result += str(35);
    else
        result += str(36);
    result += str(14);
    if(root->gVEvent(miralick) < 10)
        result += str(getRandInt(15,17));
    else
        result += str(getRandInt(18,20));
    if(root->vStatus(horny) < 60)
        result += str(30);
    else if(root->vStatus(horny) < 80)
        result += str(31);
    else
        result += str(32);
    if(root->gVEvent(mirahorny) < 100 && root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(19,21)));
        root->setDesc(result);
    }
    else if(root->gVEvent(mirahorny) >= 100 && root->vStatus(horny) < 100)
    {
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(23));
        root->setDesc(result + str(38));
        root->addDesc(str(67));
    }
    else if(root->gVEvent(mirahorny) < 100 && root->vStatus(horny) >= 100)
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(22));
        root->setDesc(result + str(37));
        root->addDesc(str(68));
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->sVEvent(miraorgasm,1);
        root->sVEvent(mirahorny,0);
        root->setImage(media(getRandInt(37,38)));
        root->setDesc(result + str(39));
        root->addDesc(str(69));
    }
    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->gVEvent(mirahorny) <= root->vStatus(horny))
        {
            if(getRandInt(1,2) == 1)
                makeActBtn("pose69_2",act(7));
            else
                makeActBtn("lickmira_mis2",act(10));
        }
        else
        {
            makeActBtn("pose69_2",act(7));
            makeActBtn("miralick_stand2",act(9));
            makeActBtn("dog_random",act(4));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("miralick_stand2",act(9));
        makeActBtn("dog_random",act(4));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(10));
    else
        makeActBtn("end",act(0));
}
void MiraSex::miralick_stand1()
{
    root->incTime(5);
    if(root->gVEvent(miralick) < 10) root->uVStatus(horny,10);
    if(root->gVEvent(miralick) >= 10)
    {
        root->uVStatus(horny,20);
        root->uVEvent(mirahorny,getRandInt(0,9));
    }
    QString result = str(getRandInt(0,1));
    if(root->gVEvent(miralick) < 10)
        result += str(getRandInt(15,17));
    else
        result += str(getRandInt(18,20));
    if(root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(25,26)));
        if(root->vStatus(horny) < 60)
            result += str(30);
        else if(root->vStatus(horny) < 80)
            result += str(31);
        else
            result += str(32);
        root->setDesc(result);
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(24));
        root->setDesc(result + str(37));
        root->addDesc(str(70));
    }

    if(you_orgasm == 0)
        makeActBtn("miralick_stand1",act(2));
    else
        makeActBtn("end",act(0));
}
void MiraSex::miralick_stand2()
{
    root->incTime(5);
    if(root->gVEvent(miralick) < 10)
        root->uVStatus(horny,10);
    if(root->gVEvent(miralick) >= 10)
    {
        root->uVStatus(horny,20);
        root->uVEvent(mirahorny,getRandInt(0,5));
    }
    QString result = str(getRandInt(0,1));
    if(root->gVEvent(miralick) < 10)
        result += str(getRandInt(15,17));
    else
        result += str(getRandInt(18,20));
    if(root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(25,26)));
        if(root->vStatus(horny) < 60)
            result += str(30);
        else if(root->vStatus(horny) < 80)
            result += str(31);
        else
            result += str(32);
        root->setDesc(result);
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(24));
        root->setDesc(result + str(32) + str(37));
        if(root->gVEvent(miraorgasm) == 0) root->addDesc(str(71));
        if(root->gVEvent(miraorgasm) == 1) root->addDesc(str(72));
    }

    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->gVEvent(mirahorny) <= root->vStatus(horny))
        {
            if(getRandInt(1,2) == 1)
                makeActBtn("pose69_2",act(8));
            else
                makeActBtn("lickmira_mis2",act(10));
        }
        else
        {
            makeActBtn("miralick_stand2",act(11));
            makeActBtn("pose69_2",act(8));
            makeActBtn("dog_random",act(4));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("miralick_stand2",act(11));
        makeActBtn("dog_random",act(4));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(10));
    else
        makeActBtn("end",act(0));
}
void MiraSex::miralick_dog()
{
    root->incTime(5);
    if(root->gVEvent(miralick) < 10)
        root->uVStatus(horny,10);
    if(root->gVEvent(miralick) >= 10)
    {
        root->uVStatus(horny,20);
        root->uVEvent(mirahorny,getRandInt(0,5));
    }

    QString result = str(getRandInt(3,5));
    if(root->gVEvent(miralick) < 10)
        result += str(getRandInt(15,17));
    else
        result += str(getRandInt(18,20));

    if(root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(27,28)));
        if(root->vStatus(horny) < 60)
            result += str(30);
        else if(root->vStatus(horny) < 80)
            result += str(31);
        else
            result += str(33);
        root->setDesc(result);
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(29));
        root->setDesc(result + str(33) + str(37));
        if(root->gVEvent(miraorgasm) == 0) root->addDesc(str(73));
        if(root->gVEvent(miraorgasm) == 1) root->addDesc(str(74));
    }

    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->gVEvent(mirahorny) <= root->vStatus(horny))
        {
            if(getRandInt(1,2) == 1)
                makeActBtn("pose69_2",act(8));
            else
                makeActBtn("lickmira_mis2",act(10));
        }
        else
        {
            makeActBtn("dog_random",act(12));
            makeActBtn("miralick_stand2",act(9));
            makeActBtn("pose69_2",act(8));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("dog_random",act(12));
        makeActBtn("miralick_stand2",act(9));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(10));
    else
        makeActBtn("end",act(0));
}
void MiraSex::mirafinger()
{
    root->incTime(5);
    root->uVStatus(horny,15);
    root->uVEvent(mirahorny,getRandInt(0,5));
    QString result = str(6) + str(getRandInt(27,29));
    if(root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(30,31)));
        if(root->vStatus(horny) < 60)
            result += str(30);
        else if(root->vStatus(horny) < 80)
            result += str(31);
        else
            result += str(33);
        root->setDesc(result);
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(34));
        root->setDesc(result + str(33) + str(37));
        root->addDesc(str(75));
    }
    if(you_orgasm == 0)
        makeActBtn("mirafinger",act(12));
    else
        makeActBtn("end",act(0));
}
void MiraSex::mirafinger_dog()
{
    root->incTime(5);
    root->uVStatus(horny,15);
    root->uVEvent(mirahorny,getRandInt(0,5));
    QString result = str(getRandInt(3,5)) + str(getRandInt(27,29));
    if(root->vStatus(horny) < 100)
    {
        root->setImage(media(getRandInt(30,33)));
        if(root->vStatus(horny) < 60)
            result += str(30);
        else if(root->vStatus(horny) < 80)
            result += str(31);
        else
            result += str(33);
        root->setDesc(result);
    }
    else
    {
        root->uVSC(orgasm,1);
        you_orgasm = 1;
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->setImage(media(34));
        root->setDesc(result + str(33) + str(37));
        if(root->gVEvent(miraorgasm) == 0) root->addDesc(str(73));
        if(root->gVEvent(miraorgasm) == 1) root->addDesc(str(74));
    }
    if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 0)
    {
        if(root->vStatus(horny) >= root->gVEvent(mirahorny))
        {
            if(getRandInt(1,2) == 1) makeActBtn("pose69_2",act(8));
            else makeActBtn("lickmira_mis2",act(10));
        }
        else
        {
            makeActBtn("dog_random",act(12));
            makeActBtn("miralick_stand2",act(9));
            makeActBtn("pose69_2",act(8));
        }
    }
    else if(root->gVEvent(miraorgasm) == 1 && you_orgasm == 0)
    {
        makeActBtn("dog_random",act(12));
        makeActBtn("miralick_stand2",act(9));
    }
    else if(root->gVEvent(miraorgasm) == 0 && you_orgasm == 1)
        makeActBtn("lickmira_mis2",act(10));
    else
        makeActBtn("end",act(0));
}
void MiraSex::end()
{
    root->sVEvent(mirainmeadow,0);
    you_orgasm = 0;
    root->sVEvent(miraorgasm,0);
    root->incTime(20);
    root->changeLoc(lgaddvor);
}
void MiraSex::checkMiraSex()
{
    if(root->gVEvent(mirasex) == 0)
    {
        root->sVEvent(mirasex,1);
        root->uVSex(girl,1);
    }
}

