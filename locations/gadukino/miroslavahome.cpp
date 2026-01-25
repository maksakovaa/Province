#include "miroslavahome.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"
#include "../../game.h"

MiroslavaHome::MiroslavaHome(Game* ptr): root(ptr) {}

void MiroslavaHome::show(QString arg)
{
    actionHandler("MiroslavaHome");
}

LocId MiroslavaHome::getLocId()
{
    return lmirahome;
}

LocId MiroslavaHome::getLocIn()
{
    return lgadukino;
}

QString MiroslavaHome::getLocName()
{
    return "Двор Мирославы";
}

LocId MiroslavaHome::getParId()
{
    return lgadukino;
}

bool MiroslavaHome::isParent()
{
    return true;
}

void MiroslavaHome::actionHandler(QString action)
{
    root->clearActions();
    if(action == "MiroslavaHome")
    {
        root->incTime(5);
        mira_temp = getRandInt(0,15);
        grandpa_guest = 0;
        root->setImage(makeImage(media(1),root->isDay(),root->getMonth()));
        if(root->getHour() >= 7 && root->getHour() <= 22)
        {
            if(root->getMonth() > 5 && root->getMonth() < 9 && root->getSunWeather() >= 0 && root->getHour() > 13 && root->getHour() < 18 && root->vJob(graze_cow) == 0 && (root->getWeek() == 1 || root->getWeek() == 5))
            {
                grandpa_guest = 1;
                root->setText(str(0));
            }
            else
                root->setText(str(1));
            if(root->vEvent(mira_no_home) == 0)
                makeActBtn("call_mira",act(0));
        }
        else
        {
            root->setText(str(2));
        }
        makeActBtn("gadukino",act(2));
        if(root->vEvent(Mira_no) > 0 && root->vEvent(mirafathertalk) == 0 && root->vEvent(miraday) != root->vStatus(daystart))
        {
            root->incTime(10);
            root->vEvent(mirafathertalk) = 1;
            root->setImage(media(2));
            root->setText(str(3));
            makeActBtn("MiroslavaHome",act(2));
        }
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->vQuest(miragopQW) == 7 && root->getHour() >= 8 && root->getHour() <= 18)
        {
            root->setImage(media(3));
            root->setText(str(4));
            makeActBtn("get_close_mira",act(3));
        }
    }
    if(action == "gadukino")
    {
        root->changeLoc(lgadukino,5);
    }
    if(action == "call_mira")
    {
        if(mira_temp >= 10 && root->getSunWeather() >= 0 && root->getTemp() >= 20 && root->getHour() < 20 && root->vEvent(mirainhome) == 0 && root->vEvent(Mira_no) == 0)
        {
            root->incTime(2);
            root->vEvent(mirainriver) = 1;
            root->vEvent(mira_no_home) += getRandInt(1,4);
            root->setImage(media(2));
            root->setText(str(5));
            makeActBtn("MiroslavaHome",act(1));
        }
        else if(mira_temp >= 10 && root->getSunWeather() >= 0 && root->getHour() < 20 && root->vEvent(mirainhome) == 0 && root->vEvent(Mira_no) == 0)
        {
            root->incTime(2);
            root->vEvent(mira_no_home) += getRandInt(1,4);
            root->setImage(media(2));
            root->setText(str(6));
            makeActBtn("MiroslavaHome",act(1));
        }
        else
        {
            root->vEvent(mirainhome) = 1;
            root->vEvent(mirainriver) = 0;
            root->vEvent(mira_guest) = 0;
            root->vEvent(mirainmeadow) = 0;
            root->vEvent(mirainforest) = 0;
            root->startEvent(eMiroslava);
        }
    }
    if(action == "get_close_mira")
    {
        root->vQuest(miraQW) += 1;
        root->incTime(15);
        int gopqw = root->vQuest(miragopQW);
        if(gopqw == 0)
            root->setImage(media(4));
        else if(gopqw > 0 && gopqw < 4)
            root->setImage(media(5));
        else if(gopqw >= 4 && gopqw < 8)
            root->setImage(media(6));
        else if(gopqw >= 8 && gopqw < 12)
            root->setImage(media(7));
        else if(gopqw >= 12 && gopqw < 20)
            root->setImage(media(8));
        else if(gopqw >= 20)
            root->setImage(media(9));
        root->setText(str(7));
        makeActBtn("watch_mira_pussy",act(4));
    }
    if(action == "watch_mira_pussy")
    {
        root->incTime(2);
        root->vStatus(horny) += 15;
        root->setImage(media(10));
        root->setText(str(8));
        makeActBtn("mirawish2",act(5));
    }
    if(action == "mirawish2")
    {
        root->incTime(45);
        root->vQuest(miragopQW) = 8;
        root->setImage(media(11));
        root->setText(str(9));
        makeActBtn("gadukino",act(1));
    }
    //HREF LINKS
    if(action == "mirafather")
    {
        root->startEvent(eMiraFather);
    }
    if(action == "grandpa")
    {
        root->startEvent(eGrandPa);
    }
}

void MiroslavaHome::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "mirahome");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MiroslavaHome::actionHandler);
    root->addActions(btn);
}

QString MiroslavaHome::str(int id)
{
    QString ded, mfather, nottime;
    if(root->vEvent(grandpa_notalk) == 0)
        ded = "<a href='grandpa'>дедушка</a>";
    else
        ded = "дедушка";
    if(root->vQuest(MiraFatherQW) < 10)
        mfather = "отец Миры";
    else
        mfather = "Афанасий";

    if(root->getHour() > 3 && root->getHour() < 7)
        nottime = "рано";
    else
        nottime = "поздно";
    QString str[10];
    str[0] = "Во дворе, возле дома ,беседуют ваш " + ded + " и <a href='mirafather'>" + mfather + "</a>.";
    str[1] = "Возле дома занимается хозяйственными делами <a href='mirafather'>" + mfather + "</a>.";
    str[2] = "Слишком " + nottime + ", семья Мирославы спит, незачем будить людей понапрасну.";
    str[3] = "Увидя вас во дворе, отец Миры направился в вашу сторону.<br>- Света, постой. Поговорить нужно, - сказал он"
             " подойдя к вам поближе.<br>Вы остановились и посмотрели на него с испугом.<br>\"Неужели Мира ему все расказала?"
             "\" - метались в вашей голове панические мысли.<br>- Света, ты не знаешь, что с Мирой происходит? - спросил Афанасий"
             " глядя вам в глаза.<br>- Н-нет, а что с ней? - растерянно спросили вы, ожидая услышать поток брани в вашу сторону.<br>"
             "- Да вот не знаю. Сидит все время дома, со двора совсем не выходит, мне ничего не расказывает, - ответил отец Миры.<br>"
             "- Ой, даже не знаю, - сказали вы, стараясь, чтобы это прозвучало как можно больше правдоподобно и сделав честные глаза."
             " - Может обидел кто из местных, или поругалась с кем...<br>- Ладно, думаю это пройдет скоро. Но ты, Света, заходи к нам"
             " в гости, думаю в твоей компании Мире лучше будет, чем одной. Может отойдет быстрее, - сказал отец Миры на прощание и "
             "ушел заниматься прерванной работой.<br>\"Пронесло,\" - подумали вы глядя ему в след и облегченно выдыхая.";
    str[4] = "Зайдя во двор, вы замечаете Мирославу, копающуюся у себя на огороде. Она стоит раком и, к вашему изумлению, светит голой"
             " промежностью...";
    str[5] = "Отец Миры сказал вам, что её нет дома, она ушла на речку.";
    str[6] = "Отец Миры сказал вам, что её нет дома.";
    str[7] = "Вы тихонько подкрадываетесь к ней, но она вас замечает и оборачивается, тут же стремительно краснея. Вы пару секунд "
             "молча смотрите на нее, а потом бесцеремонно спрашиваете, почему она без трусов. Мирослава, отведя глаза, мнется с "
             "ноги и на ногу, объясняя, что так получилось, жарко очень, вот она и... Вы тут же напоминаете ей о втором желании и"
             " просите присесть. Мирослава неохотно соглашается, а когда садится, вы тут же приказываете ей, чтобы она опять "
             "показала вам промежность, а то вы плохо рассмотрели. Девушка мямлит что-то невнятное, но потом все же на полминуты"
             " задирает юбку и дает вам хорошенько рассмотреть свою промежность.";
    str[8] = "Вы наслаждаетесь открывшимся видом, после чего вам в голову приходит безумная идея и вы решаете загадать второе "
             "желание. Мира уныло говорит, что думала, будто это и было второе желание, но вы отвечаете, что просто не удержались,"
             " после чего гворите ей, чтобы шла за вами.";
    str[9] = "Выйдя на дорогу вы говорите Мирославе, чтобы она изобразила из себя проститутку, это и будет вторым желанием. Мира"
             " уныло кивает головой, оглядывается по сторонам и видя, что улица безлюдна, выполняет ваше желание...";
    return str[id];
}

QString MiroslavaHome::act(int id)
{
    QString str[6];
    str[0] = "Позвать Мирославу";
    str[1] = "Уйти";
    str[2] = "Далее";
    str[3] = "Подойти к ней";
    str[4] = "Смотреть";
    str[5] = "Выйти на дорогу";
    return str[id];
}

QString MiroslavaHome::media(int id)
{
    QString med[20];
    med[0] = "data/locations/gadukino/gaddvor/meadow.jpg";
    med[1] = "data/locations/gadukino/mira_home/MiraHome.jpg";
    med[2] = "data/npc/gadukino/MiraFather.jpg";
    med[3] = "data/sex/mira/MiraQW7.jpg";
    med[4] = "data/sex/mira/Mira.jpg";
    med[5] = "data/sex/mira/Mira3.jpg";
    med[6] = "data/sex/mira/mira0." + intQStr(getRandInt(0,5)) + ".jpg";
    med[7] = "data/sex/mira/mira1." + intQStr(getRandInt(0,2)) + ".jpg";
    med[8] = "data/sex/mira/mira2." + intQStr(getRandInt(0,5)) + ".jpg";
    med[9] = "data/sex/mira/mira3." + intQStr(getRandInt(0,3)) + ".jpg";
    med[10] = "data/qwest/mira_wish/Mirawish2.jpg";
    med[11] = "data/qwest/mira_wish/Mirawish2_1.jpg";
    return med[id];
}
