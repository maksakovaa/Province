#include "fathersex.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

FatherSex::FatherSex(Game* ptr): root(ptr) {}

void FatherSex::start(QString arg)
{
    actionHandler(arg);
}

void FatherSex::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"FatherSex");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &FatherSex::actionHandler);
    root->addActions(btn);
}

void FatherSex::actionHandler(QString action)
{
//////CUM
    if(action.startsWith("father_cum."))
    {
        int arg = action.split(".")[1].toInt();
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        if(arg == 0)
            makeActBtn("cumInAss",act(0));
        if(arg == 1)
            makeActBtn("cumOnAss",act(1));
        if(arg == 2)
            makeActBtn("cumOnFace",act(2));
        if(arg == 3)
            makeActBtn("cumTogether",act(3));
        if(arg == 4)
            makeActBtn("cumOnTheSofa",act(4));
        if(arg == 5)
            makeActBtn("cumInMouth",act(5));
    }
    if(action == "cumInAss")
    {
        root->vStatus(cumAnus) = 1;
        root->vEvent(father_horny) = 0;
        root->setImage(media(10));
        root->setText(str(1));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "cumOnAss")
    {
        root->vStatus(cumAss) = 1;
        root->vEvent(father_horny) = 0;
        root->setImage(media(61));
        root->setText(str(2));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "cumOnFace")
    {
        root->vEvent(father_horny) = 0;
        root->cum("face");
        root->setImage(media(11));
        root->setText(str(3));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "cumTogether")
    {
        root->vEvent(father_horny) = 0;
        root->cum("face");
        if(root->vStatus(horny) >= 100)
        {
            root->addText(str(4));
            makeActBtn("moveOverLips",act(7));
        }
        else
        {
            root->setImage(media(62));
            root->addText(str(7));
            makeActBtn("back_to_loc",act(6));
        }
    }
    if(action == "moveOverLips")
    {
        root->setImage(media(45));
        root->setText(str(5));
        makeActBtn("suckDick",act(8));
    }
    if(action == "suckDick")
    {
        root->setImage(media(47));
        root->setText(str(6));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "cumOnTheSofa")
    {
        root->vEvent(father_horny) = 0;
        root->cum("face");
        root->setImage(media(63));
        root->setText(str(8));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "cumInMouth")
    {
        root->vStatistics(swallow) += 1;
        root->vStatus(cumLips) += 1;
        root->vEvent(father_horny) = 0;
        root->setImage(media(13));
        makeActBtn("back_to_loc",act(6));
    }
//////BLOWJOB
    if(action.startsWith("father_blow."))
    {
        root->vStatistics(blowJob) += 1;
        int arg = action.split(".")[1].toInt();
        if(arg == 0)
            makeActBtn("bj1",act(9));
        if(arg == 1)
            makeActBtn("bj2",act(10));
        if(arg == 2)
        {
            root->setImage(media(40));
            root->setText(str(12));
            actionHandler("father_sex.0");
            actionHandler("father_sex.1");
            actionHandler("father_blow.1");
        }
    }
    if(action == "bj1")
    {
        root->setImage(media(40));
        root->setText(str(10));
        actionHandler("father_sex.0");
        actionHandler("father_sex.1");
    }
    if(action == "bj2")
    {
        root->setImage(media(12));
        root->setText(str(11));
        actionHandler("father_cum.5");
    }
//////BEND OVER
    if(action.startsWith("father_bend"))
    {
        if(root->gNPC(father).sex == 0)
        {
            root->gNPC(father).sex = 1;
            root->vSex(guy) += 1;
        }
        int arg = action.split(".")[1].toInt();
        if(arg == 0)
        {
            root->setImage(media(18));
            root->setText(str(13));
            actionHandler("father_other.0");
        }
        if(arg == 1)
        {
            root->setImage(media(29));
            root->setText(str(14));
            actionHandler("father_blow.0");
        }

        if(arg == 2)
        {
            root->addText(str(15));
            actionHandler("father_blow.0");
        }
    }
//////OTHER
    if(action.startsWith("father_other."))
    {
        int arg = action.split(".")[1].toInt();
        if(arg == 0)
            makeActBtn("toBedroom",act(11));
        if(arg == 1)
            makeActBtn("push",act(12));
        if(arg == 2)
            makeActBtn("help",act(13));
    }
    if(action == "toBedroom")
    {
        root->setImage(media(9));
        root->setText(str(16));
        actionHandler("father_other.1");
    }
    if(action == "push")
    {
        root->setImage(media(64));
        root->setText(str(17));
        actionHandler("father_other.2");
    }
    if(action == "help")
    {
        if(root->vBody(anus) < 10)
            root->vBody(anus) += 1;
        root->addText(str(18));
        actionHandler("father_cum.0");
        actionHandler("father_cum.1");
        actionHandler("father_cum.2");
    }
//////SEX
    if(action.startsWith("father_sex."))
    {
        int arg = action.split(".")[1].toInt();
        if(arg == 0)
            makeActBtn("goToBed",act(14));
        if(arg == 1)
            makeActBtn("stayHere",act(15));
    }
    if(action == "goToBed")
    {
        if(root->vBody(anus) < 10)
            root->vBody(anus) += 1;
        root->vStatistics(analSex) += 1;
        root->addText(str(19));
        if(getRandInt(1,2) == 1)
        {
            root->vStatus(cumAnus) += 1;
            root->addText(str(20));
            makeActBtn("back_to_loc",act(6));
        }
        else
        {
            root->addText(str(21));
            actionHandler("father_cum.3");
        }
    }
    if(action == "stayHere")
    {
        root->incTime(10);
        if(root->vBody(anus) < 10)
            root->vBody(anus) += 1;
        root->vStatistics(analSex) += 1;
        root->setImage(media(61));
        makeActBtn("stayHereNex",act(16));
    }
    if(action == "stayHereNex")
    {
        root->addText(str(23));
        if(getRandInt(1,2) == 1)
        {
            root->vStatus(cumAnus) += 1;
            root->addText(str(24));
            makeActBtn("showAss",act(17));
        }
        else
        {
            root->addText(str(26));
            actionHandler("father_cum.4");
        }
    }
    if(action == "showAss")
    {
        root->addText(str(25));
        makeActBtn("back_to_loc",act(6));
    }
}

QString FatherSex::media(int id)
{
    QString med[65];
    med[0] = "data/sex/fatherSex/bath_voyer_0.webm";
    med[1] = "data/sex/fatherSex/bath_voyer_1.jpg";
    med[2] = "data/sex/fatherSex/bath_voyer_2.webm";
    med[3] = "data/sex/fatherSex/bath_voyer_3.jpg";
    med[4] = "data/sex/fatherSex/bath_voyer_4.jpg";
    med[5] = "data/sex/fatherSex/bath_voyer_5.jpg";
    med[6] = "data/sex/fatherSex/bath_voyer_6.gif";
    med[7] = "data/sex/fatherSex/bath_voyer_7.gif";
    med[8] = "data/sex/fatherSex/bath_voyer_8.gif";
    med[9] = "data/sex/fatherSex/fahterim3.gif";
    med[10] = "data/sex/fatherSex/fatherim11.jpg";
    med[11] = "data/sex/fatherSex/fatherim12.jpg";
    med[12] = "data/sex/fatherSex/fatherim14.jpg";
    med[13] = "data/sex/fatherSex/fatherim15.jpg";
    med[14] = "data/sex/fatherSex/fatherim16.jpg";
    med[15] = "data/sex/fatherSex/fatherim17.jpg";
    med[16] = "data/sex/fatherSex/fatherim18.jpg";
    med[17] = "data/sex/fatherSex/fatherim19.jpg";
    med[18] = "data/sex/fatherSex/fatherim1.jpg";
    med[19] = "data/sex/fatherSex/fatherim20.jpg";
    med[20] = "data/sex/fatherSex/fatherim2_1.gif";
    med[21] = "data/sex/fatherSex/fatherim21.jpg";
    med[22] = "data/sex/fatherSex/fatherim22.jpg";
    med[23] = "data/sex/fatherSex/fatherim24.jpg";
    med[24] = "data/sex/fatherSex/fatherim25.jpg";
    med[25] = "data/sex/fatherSex/fatherim26.jpg";
    med[26] = "data/sex/fatherSex/fatherim27.jpg";
    med[27] = "data/sex/fatherSex/fatherim28.jpg";
    med[28] = "data/sex/fatherSex/fatherim29.jpg";
    med[29] = "data/sex/fatherSex/fatherim2.jpg";
    med[30] = "data/sex/fatherSex/fatherim30.jpg";
    med[31] = "data/sex/fatherSex/fatherim31.jpg";
    med[32] = "data/sex/fatherSex/fatherim32.jpg";
    med[33] = "data/sex/fatherSex/fatherim33.jpg";
    med[34] = "data/sex/fatherSex/fatherim34.jpg";
    med[35] = "data/sex/fatherSex/fatherim35.jpg";
    med[36] = "data/sex/fatherSex/fatherim36.jpg";
    med[37] = "data/sex/fatherSex/fatherim37.jpg";
    med[38] = "data/sex/fatherSex/fatherim38.jpg";
    med[39] = "data/sex/fatherSex/fatherim39.jpg";
    med[40] = "data/sex/fatherSex/fatherim3.jpg";
    med[41] = "data/sex/fatherSex/fatherim3.png";
    med[42] = "data/sex/fatherSex/fatherim40.jpg";
    med[43] = "data/sex/fatherSex/fatherim4_1.gif";
    med[44] = "data/sex/fatherSex/fatherim41.jpg";
    med[45] = "data/sex/fatherSex/fatherim4_2.gif";
    med[46] = "data/sex/fatherSex/fatherim42.jpg";
    med[47] = "data/sex/fatherSex/fatherim4_3.gif";
    med[48] = "data/sex/fatherSex/fatherim43.jpg";
    med[49] = "data/sex/fatherSex/fatherim44.jpg";
    med[50] = "data/sex/fatherSex/fatherim45.jpg";
    med[51] = "data/sex/fatherSex/fatherim46.jpg";
    med[52] = "data/sex/fatherSex/fatherim47.jpg";
    med[53] = "data/sex/fatherSex/fatherim48.jpg";
    med[54] = "data/sex/fatherSex/fatherim49.jpg";
    med[55] = "data/sex/fatherSex/fatherim4.jpg";
    med[56] = "data/sex/fatherSex/fatherim50.jpg";
    med[57] = "data/sex/fatherSex/fatherim51.gif";
    med[58] = "data/sex/fatherSex/fatherim5_2.jpg";
    med[59] = "data/sex/fatherSex/fatherim52.jpg";
    med[60] = "data/sex/fatherSex/fatherim5.gif";
    med[61] = "data/sex/fatherSex/fatherim5.jpg";
    med[62] = "data/sex/fatherSex/fatherim6.gif";
    med[63] = "data/sex/fatherSex/fatherim7.jpg";
    med[64] = "data/sex/fatherSex/fatherim9.jpg";
    return med[id];
}

QString FatherSex::str(int id)
{
    QString str[27];
    str[1] = "Отчим зарычал, как раненый медведь, и с громким стоном начал извергаться где-то в вашей прямой кишке. Спустя полминуты вы почувствовали, как его увядший член мягко выскользнул из вашей попки, увлекая за собой теплую вязкую сперму...";
    str[2] = "Уважая ваше желание, отчим вынимает член из вашего ануса и начинает извергаться вам на попку...";
    str[3] = "Ваша просьба, судя по всему, еще больше усилила его возбуждение, а потому он начал кончать еще тогда, когда вы, соскочив с его члена, только ложились на кровать. Но несмотря на это, большая часть спермы всё равно попала вам на лицо...";
    str[4] = "Вы так возбуждены, и отчим так умело отрахал вашу попку, что вам захотелось сделать ему что-нибудь приятное.<br>Выскочив из под него, вы бухнулись на коленки рядом с кроватью, просительно подставив ему лицо и высунув язык. Похоже эта идея пришлась ему по душе: схватив свой член, отчим принялся надрачивать, направляя свой агрегат в ваше милое личико. Долго не выдержав такой картины, он стал обильно кончать, заливая вашу мордашку своим семенем. Первая струя спермы послужила спусковым крючком и для вашего оргазма: прикрыв глаза и наслаждаясь моментом, вы ловили личиком то, что еще выпускал отчим из своего пульсирующего органа.";
    str[5] = "Вы с трудом сдерживая себя, схватили член отчима и стали водить им по своим губкам. Наслаждаясь чувством скользящей по ротику головки.";
    str[6] = "Это было так приятно, что вы с нежностью стали обсасывать кончик члена любимого отчима, глядя при этом ему в глаза. Ошарашенный вашим поступком, он хекнул:\"Светуляунь, ты прям в ударе сегодня\".";
    str[7] = "Вы рывком соскакиваете с его члена и поворачиваетесь к нему лицом, хватая его член своей ладошкой, другую при этом запустив себе в промежность. В то время, когда вы надрачиваете отчиму рукой, попутно лаская язычком его головку, внутри вашего живота стремительно нарастает сладостное давление, и едва первые капли спермы тёплой струей ударяют вам в лицо, тело взрывается вспышкой сильного оргазма - вы кончили одновременно.";
    str[8] = "Вы рывком соскакиваете с его члена и поворачиваетесь к нему лицом, хватая его член своей ладошкой, другую при этом запустив себе в промежность. В то время, когда вы надрачиваете отчиму рукой, попутно лаская язычком его головку, внутри вашего живота стремительно нарастает сладостное давление, и едва первые капли спермы тёплой струей ударяют вам в лицо, тело взрывается вспышкой сильного оргазма - вы кончили одновременно.";
    str[9] = "Он грубо трахает ваш ротик, пока его член не начинает пульсировать у вас рту и извергаться горячей спермой.";
    str[10] = "Еще немного поигравшись с вашим анусом, отчим внезапно отстраняется от вас, и, раздевшись, присаживается в кресло, взглядом показывая на свой член. Не дожидаясь повторного приглашения, вы опускаетесь перед ними на колени и одним жадным движением заглатываете большую часть его горячего члена. Отчим со вздохом наслаждения откидывает голову назад, при этом неразборчиво советуя вам хорошенько смазать его член своей слюной, потому что через пару минут он окажется в вашей попе. Вы, понимая, что это в ваших же интересах, старательно елозите влажными губами по его горячей плоти...";
    str[11] = "Увлечённо и с большим наслаждением вы обсасываете горячий и твердый член отчима. С каждым разом он проникает всё глубже и глубже вам в горло, пока у вас не получается принять его полностью. С утробным рыком отчим грубо хватает вас за волосы и насаживает вашу голову на свой член так сильно, что вы упираетесь носом ему в лобок.";
    str[12] = "Не дожидаясь повторного приглашения, вы опускаетесь перед ними на колени и одним жадным движением заглатываете большую часть его горячего члена. Вы старательно елозите влажными губами по его горячей плоти, облизывая и играясь язычком с головкой.";
    str[13] = "Отчим негромко хмыкает, видя анальную пробку в вашей попе: - Ох, Светик, ну и ты развратница, однако... - Вы чувствуете, как он, схватив пальцами пробку, начинает её двигать во все стороны, иногда пытаясь вытащить. Но та сидит крепко, к тому же поза мешает вам расслабиться и каждый раз ваш анус непроизвольно сжимается, не давая ей выскользнуть.";
    str[14] = "Отчим одобрительно хмыкает, когда вы нагибаетесь вперед и быстрым ловким движением приспускаете с себя трусики, предоставляя ему чудесный вид своей голой промежности. Спустя мгновение вы чувствуете на своем анусе его шершавый мозолистый палец, который легонько царапает вам кожу, но вам это даже нравится.";
    str[15] = "Отчим одобрительно хмыкает, когда вы нагибаетесь вперед, поднимая юбку, предоставляя ему чудесный вид своей голой промежности.<br>- Ого, Света, а трусики ты уже не носишь? - Не успев придумать, что ответить, вы чувствуете на своем анусе его шершавый мозолистый палец, который легонько царапает вам кожу, но вам это даже нравится.";
    str[16] = "Там вы взбираетесь на кровать и становитесь на четвереньки, старательно оттопыривая попку. Отчим довольно улыбается и нетерпеливо возобновляет свои игры с пробкой, двигая ее во все стороны в попытках вытащить. Вам это тоже надоело и вы решаете ему помочь...";
    str[17] = "- Охх, Света, ну и дырка там сейчас у тебя после пробки! - выдает неожиданное отчим после того, как пробка с громким чпоком покидает вашу попку. Вы густо краснеете от этих слов, а отчим уже позабыв о них, тем временем начинает пристраиваться к вашей попке.";
    str[18] = "Ваше возбуждение настолько велико, что вы не в силах больше ждать его неспешные действия, даже несмотря на краску стыда на вашем лице, а потому решаете взять инициативу в свои руки. Едва головка его члена начала входить в ваш анус, как вы, руками как можно шире раздвигая ягодицы, рывком подаетесь назад, до упора насаживаясь попкой на желанный отцовский член. Легкая боль пронзает колечко ануса, а потому вы тут же немного подаетесь вперед, чувствуя, как оно скользит по влажному члену.<br>Отчим, похоже, тоже решил отдать всю инициативу в ваши руки, а потому теперь молчаливо наблюдал, как вы, наращивая темп, плавно скользите попкой по его твердому возбужденному члену. После пробки у вас там было довольно широко, а потому вы особо не церемонились - через полминуты уже вовсю скакали на члене своего отчима, погружая его в свою податливую плоть до самых яиц. Но долго в таком темпе стареющий отчим выдержать не смог и скоро с запинками сообщил вам, что вот-вот кончит...";
    str[19] = "Но едва вы вошли во вкус, как отчим мягко, но уверенно отстраняет руками вашу голову от своего члена и громким шлепком по заднице подталкивает вас в сторону двери. Вы со смешливым визгом вприпрыжку следуете в спальню родителей, где с разгону бухаетесь животом на кровать. Отчим появляется сразу за вами и не церемонясь сразу же взбирается на вас.<br>Вы, прекрасно понимая, что от вас требуется, как можно шире разводите руками ягодицы и через миг чувствуете на своем анусе влажную от вашей слюны головку члена - она медленно, но уверенно вдавливается в вашу упругую плоть и через некоторое время буквально ныряет в вашу кишку. От этого ваш анус непроизвольно сжимается, крепко обхватывая отцовский член у основания головки, но потом вам удается сосредоточиться и расслабиться, после чего отчим медленно начинает продвигаться внутрь.<br>Вам слегка больно, но вы понимаете, что очень скоро это ощущение пройдёт, а потому, сцепив зубы, покорно терпите. Тем временем движения отчима становятся все быстрее и размашистее и через минуту он уже на всю длину члена вгоняется в вашу прямую кишку, добавляя к мерному поскрипыванию кровати громкие шлепки соприкасающейся плоти. Вы чувствуете, как его яйца шлепаются о вашу вагину, усиливая похоть и доставляя вам наслаждение.";
    str[20] = "Фрикции отчима становятся все быстрее, а через мгновение вы чувствуете, как его член внутри вас начинает судорожно сжиматься и пульсировать, а через мгновение в вашей попе разливается приятное тепло - он кончил.";
    str[21] = "Фрикции отчима становятся все быстрее и скоро он говорит вам, что сейчас кончит.";
    str[22] = "Едва вы вошли во вкус, как отчим мягко, но уверенно отстраняет руками вашу голову от своего члена и громким шлепком по заднице подталкивает вас в сторону двери. Вы ойкаете и решаете немного взбунтоваться, а потому, игнорируя явное желание отчима, застываете на полпути и ложитесь на пол, оттопырив попку и раздвинув свои булочки обхватив их руками, приглашаете отчима трахнуть вашу попку.";
    str[23] = "Отчим бурчит что-то себе под нос, но принимает ваше желание заняться сексом здесь.<br>Сквозь собственные расставленные ноги вы видите, как он вразвалку приближается к вам, а через мгновение чувствуете на своем анусе его шершавый палец - он круговыми движениями массирует ваше колечко, кончиком ногтя иногда проникая внутрь. Раздается характерный плевок и вам становится немножко щекотно - отчим плюнул вам на анус, используя слюну вместо смазки. Его палец проникает внутрь попы и начинает двигаться туда-сюда, имитируя половой акт. Боли нет, только немного неприятно.<br>Поиграв ещё немного, отчим наконец приставляет головку своего члена к вашему анусу и начинает медленно давить. Вы, стараясь облегчить ему процесс, расслабляете попу и через миг понимаете, что его член уже в вас. Отчим не спешит двигаться, боясь причинить вам боль, поэтому вы сами медленно насаживаетесь попкой на его член почти до упора, после чего он осмелевает - начинает иметь вас в прямую кишку, с каждым мигом наращивая темп.";
    str[24] = "Сосредоточившись на своих ощущениях, вы внезапно чувствуете, как где-то глубоко внутри вашей прямой кишки разливается что-то теплое - оказывается, вы и не заметили, как отчим приблизился к оргазму и теперь кончал вам прямо внутрь. Вам теперь ничего не оставалось, как молча терпеть...";
    str[25] = "Взявшись за попку, вы разводите её в стороны, обнажая свои дырочки. Отчим заворожено смотрит на то, как из вашей попки вытекает его сперма.<br>- Светик, ты моя маленькая потаскушка.- Говорит он, хриплым голосом.";
    str[26] = "Фрикции отчима становятся всё быстрее и скоро он говорит вам, что сейчас кончит.";
    return str[id];
}

QString FatherSex::act(int id)
{
    QString act[20];
    act[0] = "Кончай в попку";
    act[1] = "Кончи мне на попку";
    act[2] = "Обкончай мне лицо";
    act[3] = "Кончить вместе";
    act[4] = "Упасть на диван";
    act[5] = "Дать ему кончить в рот";
    act[6] = "Отойти";
    act[7] = "Провести по губам";
    act[8] = "Обсосать член";
    act[9] = "Сосать";
    act[10] = "Продолжить сосать";
    act[11] = "Идти в спальню";
    act[12] = "Тужиться";
    act[13] = "Помочь";
    act[14] = "На кровать";
    act[15] = "Остаться";
    act[16] = "Стонать";
    act[17] = "Показать попу";
    return act[id];
}
