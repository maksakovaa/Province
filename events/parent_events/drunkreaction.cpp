#include "drunkreaction.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

DrunkReaction::DrunkReaction(Game* ptr): root(ptr) {}

void DrunkReaction::start(QString arg)
{
    actionHandler(arg);
}

void DrunkReaction::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"DrunkReaction");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &DrunkReaction::actionHandler);
    root->addActions(btn);
}

void DrunkReaction::actionHandler(QString action)
{
    if(action == "mother")
    {
        LocId momLoc = root->gNPC(mother).location;
        if(momLoc == lpark || momLoc == lglake || momLoc == lshop || momLoc == lgrinok || momLoc == lgkafe)
        {
            root->incTime(20);
            root->changeRep('-',mother,10);
        }
        root->vEvent(momDrunkReact) += 1;
        if(root->vEvent(momDrunkReact) > 1)
        {
            root->setImage(media(0));
            root->setText(str(6));
            root->gNPC(mother).relation -= root->vEvent(momDrunkReact);
            if(root->gNPC(mother).relation < 0)
                root->gNPC(mother).relation = 0;
            makeActBtn("finish.bedrPar",act(0));
            return;
        }
        if(root->vAddict(alko) < 3)
        {
            root->setImage(media(0));
            root->setText(str(0));
            if(root->gNPC(mother).relation > 3)
                root->gNPC(mother).relation = 0;
            makeActBtn("finish.korrPar",act(1));
            return;
        }
        else if(root->vAddict(alko) >= 3 && root->vAddict(alko) < 6)
        {
            root->setImage(media(0));
            if(root->gNPC(mother).relation < 40)
                root->setText(str(2));
            else
                root->setText(str(1));
            root->changeRep('-',mother,10);
            makeActBtn("finish",act(1));
            return;
        }
        else
        {
            int rel = root->gNPC(mother).relation;
            root->setImage(media(0));
            if(rel < 40)
                root->setText(str(5));
            else if(rel >= 40 && rel < 80)
                root->setText(str(4));
            else
                root->setText(str(8));
            root->vStatus(cumLips) = 0;
            root->vStatus(cumFace) = 0;
            root->vBody(makeup) = 1;
            root->incTime(10);
            root->changeRep('-',mother,10);
            makeActBtn("finish",act(2));
            return;
        }
    }

    if(action == "father")
    {
        root->vEvent(fatherDrunkReact) += 1;
        if(root->vEvent(fatherDrunkReact) > 1)
        {
            root->addText(str(24));
            root->changeRep('-',father, root->vEvent(fatherDrunkReact));
            if(root->gNPC(father).relation < 0)
                root->gNPC(father).relation = 0;
            makeActBtn("finish",act(0));
            return;
        }
        if(root->getCurLoc() == lgargazel)
        {
            root->addText(str(25));
            root->changeRep('-',father);
            makeActBtn("finish.gorodok",act(2));
            return;
        }
        if(root->vAddict(alko) < 3)
        {
            if(root->gNPC(father).relation >= 60)
                root->addText(str(9));
            else
                root->addText(str(10));
            root->changeRep('-',father);
            makeActBtn("finish.korrPar",act(1));
            return;
        }
        if(root->vAddict(alko) >= 3 && root->vAddict(alko) < 6)
        {
            if(root->gNPC(father).relation < 80)
            {
                if(root->gNPC(father).relation < 40)
                    root->addText(str(11));
                else
                    root->addText(str(12));
                root->changeRep('-',father);
                makeActBtn("finish",act(1));
            }
            else
            {
                root->vStatus(cumLips) = 0;
                root->vStatus(cumFace) = 0;
                root->vBody(makeup) = 1;
                root->incTime(10);
                root->addText(str(19));
                if(root->vSkill(domination) < 30)
                    makeActBtn("giveWashMe",act(3));
                else
                    makeActBtn("washYourself",act(4));
            }
        }
        else
        {
            if(root->gNPC(father).relation < 80)
            {
                if(root->gNPC(father).relation < 40)
                    root->addText(str(20));
                else
                    root->addText(str(21));
                root->changeRep('-',father);
                makeActBtn("finish.sleep",act(2));
            }
            else
            {
                root->vStatus(cumLips) = 0;
                root->vStatus(cumFace) = 0;
                root->vBody(makeup) = 1;
                root->incTime(10);
                //zz_funcs wanted
                root->setText(str(19));
                if(root->vStatus(horny) >= 80)
                {
                    makeActBtn("harras2",act(5));
                }
                makeActBtn("finish.sleep",act(2));
            }
        }
    }

    if(action == "sister")
    {
        if(root->vAddict(alko) >= 3 && root->vAddict(alko) < 6)
            root->addText(str(26));
        else
            root->addText(str(27));
        makeActBtn("finish",act(2));
    }

    if(action == "brother")
    {
        if(root->vAddict(alko) < 3)
        {
            root->incTime(2);
            if(root->gNPC(brother).relation < 40)
                root->addText(str(28));
            else
                root->addText(str(29));
            makeActBtn("finish.curloc",act(0));
        }
        else
        {
            root->incTime(2);
            if(root->gNPC(brother).relation < 40)
                root->addText(str(28));
            else
                root->addText(str(30));
            makeActBtn("finish.curloc",act(0));
            if(root->gNPC(brother).relation >= 40)
            {
                if(root->getHour() == 21 || root->getHour() == 22)
                    makeActBtn("drunkTalk",act(6));
            }
        }
    }

    if(action == "drunkTalk")
    {
        root->incTime(30);
        root->addText(str(31));
        if(root->vQuest(qwBrotherNude) >= 1 || root->vQuest(qwPornoFootball) > 5)
        {
            root->addText(str(32));
            makeActBtn("ignore",act(7));
            if(root->vSkill(domination) > -10)
                makeActBtn("indignant",act(8));
        }
    }

    if(action == "ignore")
    {
        root->vStatus(horny) += 10;
        root->changeRep('+',brother);
        root->addText(str(33));
        if(root->vStatus(horny) < 70)
        {
            root->addText(str(35));
            makeActBtn("finish.curloc",act(0));
        }
        else
        {
            root->addText(str(36));
            makeActBtn("giveIntToExitement",act(9));
            makeActBtn("runOut",act(10));
        }
    }

    if(action == "giveIntToExitement")
    {
        if(root->gNPC(brother).sex >= 1 || root->vQuest(qwPornoFootball) >= 16)
        {
            if(root->gNPC(brother).sex < 5)
                root->gNPC(brother).sex = 5;
            root->setImage(media(1));
            root->addText(str(39));
            root->addText(str(40));
            if(root->vSkill(domination) > -30)
                makeActBtn("runOut2",act(10));
            makeActBtn("suckBroDick",act(11));
        }
        else
        {
            root->addText(str(37));
            root->changeRep('+',brother,10);
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            makeActBtn("finish.curloc",act(2));
        }
    }
    if(action == "runOut2")
    {
        root->vStatus(horny) -= 30;
        root->vStatus(mood) -= 30;
        root->addText(str(41));
        makeActBtn("finish",act(2));
    }
    if(action == "suckBroDick")
    {
        root->changeRep('+',brother,10);
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatistics(blowJob) += 1;
        root->cum("lip");
        root->vStatistics(swallow) += 1;
        root->incTime(10);
        root->setImage(media(2));
        root->setText(str(42));
        makeActBtn("finish.curloc",act(2));
    }
    if(action == "runOut")
    {
        root->changeRep('+',brother);
        root->addText(str(38));
        makeActBtn("finish",act(2));
    }

    if(action == "indignant")
    {
        root->addText(str(34));
        root->changeRep('-',brother);
        makeActBtn("finish.curloc",act(0));
    }

    if(action == "harras2")
    {
        if(root->vEvent(fatherTouched) == 1)
            root->addText(str(23));
        else
            root->addText(str(22));
        if(root->vEvent(fatherTouched) == 1)
            root->vEvent(father_horny) += getRandInt(1,10);
        makeActBtn("finish.sleep",act(2));
    }
    if(action == "giveWashMe")
    {
        root->addText(str(15));
        if(root->vStatus(horny) >= 80)
            makeActBtn("harras",act(5));
        else
        {
            root->changeRep('-',father);
            root->addText(str(16));
        }
        makeActBtn("finish",act(1));
    }
    if(action == "harras")
    {
        if(root->vEvent(fatherTouched) == 1)
            root->addText(str(18));
        else
            root->addText(str(17));
        if(root->vEvent(fatherTouched) == 1)
            root->vEvent(father_horny) += getRandInt(1,10);
        makeActBtn("finish",act(1));
    }
    if(action == "washYourself")
    {
        root->changeRep('-',father);
        root->addText(str(14));
        makeActBtn("finish",act(1));
    }

    if(action == "finish")
    {
        if(root->vAddict(alko) > 5)
            root->vAddict(alko) = 5;
        else
            root->vAddict(alko) -= 1;
        root->changeLoc(lbedrpar);
    }
    if(action == "finish.bedrPar")
        root->changeLoc(lbedrpar);
    if(action == "finish.korrPar")
        root->changeLoc(lkorrpar);
    if(action == "finish.gorodok")
        root->changeLoc(lgorodok);
    if(action == "finish.curloc")
        root->changeLoc(root->getCurLoc());
}

QString DrunkReaction::media(int id)
{
    QString med[3];
    med[0] = "/home/maks/Документы/Province-lin/data/npc/pavlovo/mother/prost5.jpg";
    med[1] = "/home/maks/Документы/Province-lin/data/sex/misc/bro_dick.jpg";
    med[2] = "/home/maks/Документы/Province-lin/data/sex/cocksucker/cocksucker.jpg";
    return med[id];
}

QString DrunkReaction::str(int id)
{
    QString str[43];
    //mom
    str[0] = "Мама принюхалась: <npc>\"Света, от тебя спиртным пахнет! Что за безобразие? Ты еще слишком молода, чтобы пить! Иди, приведи себя в порядок.\"</npc>";
    str[1] = "Мама внимательно посмотрела на вас: <npc>“Господи, Света, ты пьяная? Как тебе не стыдно! Иди, приведи себя в порядок, сейчас же!”</npc>";
    str[2] = "Мать грозно посмотрела на вас: <npc>“Ты что, напилась? Совсем стыд потеряла! Уйди с глаз моих!”</npc>";
    str[3] = "Мама что-то говорит и причитает, но вы слабо понимаете, что она говорит и делает. Спустя пять минут причитаний, она обняла вас за плечи и подвела к раковине, где хорошенько умыла вас. После мама отвела вас в свою комнату и уложила в кровать.";
    str[4] = "Мама что-то говорит и причитает, но вы слабо понимаете, что она говорит. Она взяла вас за руку и отвела в ванну, где хорошенько окатила вас водой. Смягчившись, она отвела вас в вашу комнату и уложила в койку.";
    str[5] = "Увидев вас, мать начала кричать на вас. В пьяном бреду вы не особо понимаете, что она говорит, но пара тумаков ясно дали понять о её настроении. Не переставая ругаться, она за шкирку потащила вас в ванную. Там она посадила вас в ванну и окатила из душа ледяной водой. Ругнувшись еще разок, она смягчилась и укутала вас в полотенце, после чего увела в вашу комнату.";
    str[6] = "<npc>Я что тебе сказала? Быстро к себе в комнату - и чтобы я тебя больше сегодня не видела!</npc> - прокричала на вас мать, и вы, решив не нарываться ещё сильнее, быстренько скрылись в свою комнату.";
    str[7] = "Мать грозно посмотрела на вас: <npc>“Ты что, напилась? Совсем стыд потеряла! А ну быстро домой - приводить себя в порядок!”</npc>";
    str[8] = "Увидев вас, мать начала кричать на вас. В пьяном бреду вы не особо понимаете, что она говорит, но пара тумаков тут же разъяснили её настрой. Наругавшись, она за шкирку потащила вас домой, тихонько причитая.";
    //father
    str[9] = "Отчим принюхался: <npc>- Света, ты пила? Иди, приведи себя в порядок, и матери не показывайся, нечего её лишний раз расстраивать.</npc>";
    str[10] = "Отчим принюхался: <npc>- Света, ты пила? Хорошо хоть время провела? Ладно, держи жвачку и умойся иди. Только матери не показывайся - расстроится.</npc>";
    str[11] = "<npc>Совсем уже распустилась, в твоем возрасте квасить? Живо приведи себя в порядок!</npc>";
    str[12] = "Отчим нахмурил брови: <npc>- Ты где напилась? Совсем уже молодёжь стыд потеряла. Иди умойся и проспись. И не вздумай матери показываться.</npc>";
    str[13] = "Отчим приподнял бровь, глядя на вас: <npc>- Света, ты где так наклюкаться успела? Идем-ка я тебя умою, пока мать не увидела.</npc><br>Отчим провел вас в ванну.";
    str[14] = "Когда вы сказали, что можете сами, он хмыкнул и встал у двери, карауля мать. Когда вы закончили водные процедуры, отчим дал вам жвачку и похлопал по плечу, наказав больше так не напиваться.";
    str[15] = "Вы послушно подчинились и только пофыркивали, когда отчим умывал вас.";
    str[16] = "У вас разыгралась пьяная фантазия и, чистенькая и умытая, вы попытались состроить милую гримасу и поблагодарить его, от чего отчим засмеялся. Погладив вас по голове и дав жевательную резинку, он отправил вас к себе в комнату, наказав больше так на напиваться.";
    str[17] = "У вас разыгралась пьяная фантазия и вы попытались потерется о него бёдрами. Заметив ваши действия, отчим окатил вас ледяной водой и сказал, чтобы вы не выпендривались. Закончив с водными процедурами, он отправил вас в свою комнату, наказав больше так на напиваться.";
    str[18] = "У вас разыгралась пьяная фантазия и вы попытались потерется о него бедрами и ухватится за его член. Заметив ваши действия, он ощутимо шлепнул вас по заднице и сказал, чтобы вы не выпендривались. Закончив с водными процедурами, отчим опять хлопнул вас по попе и отправил в свою комнату.";
    str[19] = "Вы слабо понимаете, что происходит. Отчим, когда увидел ваше состояние, глубоко вздохнул и начал что-то говорить. Он поднял вас на руки и отнёс в ванну, где хорошенько умыл. Закончив с водными процедурами, отчим понёс вас в комнату укладывать спать.";
    str[20] = "Увидев вас, отчим начал что-то говорить и активно жестикулировать руками. Вы его не понимаете, да и не хотите понимать, но он не успокоился и, ругаясь, потащил вас за руку в ванну. Хорошенько умыв, он увёл вас в комнату и уложил спать.";
    str[21] = "Отчим, увидев ваше состояние, что-то буркнул себе под нос, и потащил вас за руку в ванну. Хорошенько умыв, он увёл вас в комнату и уложил спать.";
    str[22] = "Пока отчим нёс вас в вашу комнату, вы, в пьяном бреду, полезли к нему целоваться. Он отворачивается и пытается увильнуть от поцелуя, ворчливо комментируя происходящее. Вы так и не смоги осуществить свою идею, заснув у него на руках.";
    str[23] = "Пока отчим нёс вас в вашу комнату, вы, в пьяном бреду, полезли к нему целоваться, начали прижиматься грудью и пытаться залезть в штаны. Отчим чуть не упал, но вовремя облокотился о стену и устоял. Притворно плюнув, он закинул вас на плечо и, придерживая за попку, унёс в вашу комнату, где вы моментально уснули.";
    str[24] = "<npc>Я что тебе сказал? Быстро к себе в комнату - и чтобы я тебя больше сегодня не видел!</npc> - гаркнул на вас отец. Вы решили не искушать судьбу и ушли к себе.";
    str[25] = "Отчим нахмурил брови: <npc>- Ты чего в таком виде сюда приперлась? Брысь отсюда, а то ещё влезешь куда или разобьёшь чего!</npc>";
    //sister
    str[26] = "Сестра посмотрела на вас и скептически хмыкнула: <npc>- Света, может, на сегодня хватит?";
    str[27] = "Вы завалились в свою комнату в полусознательном состоянии. Сидевшая у себя на кровати сестра что-то говорит, но вам плевать. Дошатавшись до своей койки, вы рухнули на неё и провалились в долгожданные объятья Морфея…";
    //brother
    str[28] = "<npc>- Отвали от меня, пьянь подзаборная, а то матери все расскажу!</npc>";
    str[29] = "<npc>- Следующий раз со мной поделишься?</npc> - спросил Колька, явно намекая на исходящий от вас запах алкоголя.";
    str[30] = "<npc>- Света, наклюкалась?</npc> – брат засмеялся при виде вас – <npc>по парням шастала? Расскажи-ка о похождениях!</npc>";
    str[31] = "Вы решили поговорить с братом, и он весело поддерживает ваш пьяный разговор, постоянно подкалывая вас.";
    str[32] = "Внезапно вы ощутили руку брата на своей талии.";
    str[33] = "Вы не придали особого значения телодвижениям братца и полчаса рассказывали пьяные истории, пока он обследовал ваши округлости.";
    str[34] = "Несмотря на состояние, вы всполошились и обругали брата. Сквозь ваше подвыпившее сознание к вам пришла мысль, что лучше не кричать, а то мама услышит и надаёт вам обоим, поэтому, стукнув напоследок, вы отошли от брата.";
    str[35] = "Наконец вас утомил этот диалог, вы поднялись и отправились по своим делам.";
    str[36] = "Алкоголь стёр запреты, а возбуждение дало толчок, и вот вы уже, раскрасневшись, начали елозить на руке брата, невпопад и сбиваясь рассказывая о каком-то событии. Брат явно не ожидал такого развития событий, но не растерялся и начал гладить ваше бедро, не забывая отвлекать вас вопросами.";
    str[37] = "В конечном счёте вы умолкли. Ощущая скорое наступление оргазма, вы, забыв о любой осторожности, медленно пододвинули руку брата к своей промежности. Брат мгновенно воспользовался ситуацией, но вы уже были на пределе и бурно кончили, с трудом сдержавшись от крика удовольствия, после чего, немного придя в себя, ушли.'";
    str[38] = "Через полчаса, вспомнив о том, что он ваш брат, вы поднялись и пробубнив что-то под нос, ушли - вам надо было умыться и забыть о случившемся.";
    str[39] = "Вскоре вы перестали рассказывать свои глупости и полностью отдались в руки похоти. Брат мял вашу грудь, и целовал шею. Рука брата опять начала двигаться к вашей промежности, остановившись в считаных сантиметрах от разгорячённой киски.'";
    str[40] = "Брат посчитал что вы дошли до требуемой кондиции и убрал руки. После этого он поднялся и встал перед вами. Сквозь пелену перед глазами, вызванной близким оргазмом, вы внезапно заметили член перед своим лицом.<br><npc>- Если хочешь продолжения, то и про меня не забывай</npc>, - сказал он и начал медленно притягивать вашу голову к своему члену.";
    str[41] = "Окончательно собравшись с мыслями вы резко поднялись и попытались выбежать из комнаты, на тело вас подвело – от резкого движения у вас закружилась голова, вы запнулись и упали. Брат хотел подойти к вам, но вы быстро поднялись и, ведомые стыдом, сбежали из зала.";
    str[42] = "Брат коснулся кончиком своего члена ваших губ, и вы окончательно сдались и принялись самозабвенно сосать его вздыбленный орган. Спустя пару минут вы дотронулись рукой своей промежности и это стало последней каплей. С членом во рту вы начали извиваться, сотрясаемые оргазмом, стараясь не откусить случайно братово хозяйство, от чего брат незамедлительно тоже бурно излился вам в рот. Вы встали и на подкашивающихся ногах направились прочь из зала.";
    return str[id];
}

QString DrunkReaction::act(int id)
{
    QString act[12];
    act[0] = "Уйти";
    act[1] = "Отойти";
    act[2] = "...";
    act[3] = "Дать себя умыть";
    act[4] = "Умыться самой";
    act[5] = "Приставать";
    act[6] = "Поболтать";
    act[7] = "Не обращать внимания";
    act[8] = "Возмутиться";
    act[9] = "Поддаться возбуждению";
    act[10] = "Сбежать";
    act[11] = "Сосать";
    return act[id];
}
