#include "gadbana.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadbana::Gadbana(Game *ptr): root(ptr) {}

void Gadbana::show(QString arg)
{
    actionHandler("bana");
}

LocId Gadbana::getLocId()
{
    return lgadbana;
}

LocId Gadbana::getParId()
{
    return lgaddvor;
}

LocId Gadbana::getLocIn()
{
    return lgadukino;
}

QString Gadbana::getLocName()
{
    return "Баня";
}

bool Gadbana::isParent()
{
    return true;
}

void Gadbana::actionHandler(QString action)
{
    root->clearActions();
    if(action == "bana")
    {
        root->rendImagePage(this);
        root->setImage(media(0));
        root->setText(str(0));
        if(root->vEvent(bana_redress) == 1)
        {
            root->addText(str(1));
            connect(root->getTextPtr(), &QLabel::linkActivated, this, &Gadbana::actionHandler);
        }
        if(root->vEvent(mira) == 0)
        {
            makeActBtn("goGadDvor", act(0));
            if(isCanPar() && root->getHour() <= 18)
                root->addText(str(3));
            if(isCanPar() && root->getHour() > 18 && root->getHour() < 22)
            {
                root->addText(str(4));
                if(root->vEvent(banaday) != root->vStatus(daystart))
                    makeActBtn("parInBan", act(2));
            }
            if(!isCanPar())
                makeActBtn("takeShower", act(3));
            if(root->getItmCount(iTampon) > 0 && root->vStatus(mesec) > 0 && root->vStatus(isprok) == 0 && !root->isAutoTampon())
                makeActBtn("chgTampon", act(5));
            if(root->vStatus(cumLips) > 0 || root->vStatus(cumFace) > 0 || root->vBody(makeup) != 1)
                makeActBtn("clearFace", act(7));
            if(root->vStatus(cumFrot) > 0)
                makeActBtn("cleanClothes", act(8));
            if(root->vBody(legHair) > 0 && root->getItmCount(iRazor) > 0)
                makeActBtn("shaveLegs", act(9));
            if(root->vBody(pubisHair) > 0 && root->getItmCount(iRazor) > 0)
                makeActBtn("shavePubis", act(11));
            if(root->vSex(analplugIN) == 1)
                makeActBtn("remAnalPlug", act(12));
            if(root->getItmCount(iAnalPlug) > 0 && root->vSex(analplugIN) == 0)
                makeActBtn("insAnalPlug", act(13));
            if(root->vSex(vibratorIN) == 1)
                makeActBtn("remVibrator", act(14));
            if(root->getItmCount(iVibrator) > 0 && root->vSex(vibratorIN) == 0)
                makeActBtn("insVibrator", act(15));
            if(root->getItmCount(iPregtest) > 0)
                makeActBtn("pregTest", act(16));
        }
        else
        {
            makeActBtn("undress", act(17));
        }
    }
    if(action == "goGadDvor")
    {
        if(root->isCloth() || (!root->isCloth() && root->vStatus(shamelessFlag) > 2))
        {
            root->changeLoc(lgaddvor,5);
        }
        else
        {
            root->setImage(media(1));
            root->setText(str(2));
            makeActBtn("bana", act(1));
        }
    }
    if(action == "parInBan")
    {
        root->vEvent(bana_redress) = 1;
        root->incTime(105);
        root->vEvent(banaday) = root->vStatus(daystart);
        cleanMe();
        root->updSkin('+', 5);
        root->vStatus(vidageday) +=1;
        root->vStatus(health) += 10;
        root->vStatus(mood) +=20;
        root->vStatus(day_weight) -= 1;
        undress();
        root->setImage(media(2));
        root->setText(str(5));
        makeActBtn("bana", act(4));
    }
    if(action == "takeShower")
    {
        cleanMe();
        root->incTime(15);
        root->vStatus(mood) += 10;
        root->vEvent(bana_redress) = 1;
        undress();
        root->setImage(media(3));
        root->setText(str(6));
        makeActBtn("bana", act(4));
    }
    if(action == "chgTampon")
    {
        root->useItem(iTampon,1);
        root->vStatus(isprok) = 1;
        root->incTime(5);
        root->vStatus(mood) -= 5;
        root->setImage(media(4));
        root->setText(str(7));
        makeActBtn("bana", act(6));
    }
    if(action == "clearFace")
    {
        root->vBody(makeup) = 1;
        root->vStatus(cumLips) = 0;
        root->vStatus(cumFace) = 0;
        root->vStatus(sweat) -= 1;
        root->incTime(5);
        root->setImage(media(5));
        root->setText(str(8));
        makeActBtn("bana", act(6));
    }
    if(action == "cleanClothes")
    {
        root->vStatus(cumFrot) = 0;
        root->incTime(15);
        root->setImage(media(6));
        root->setText(str(9));
        makeActBtn("bana", act(6));
    }
    if(action == "shaveLegs")
    {
        root->rendVideoPage(this);
        root->incTime(15);
        root->vBody(legHair) -= 5;
        root->vStatus(horny) += 5;
        root->useItem(iRazor,1);
        root->setVideo(media(7), 900, 508);
        root->setText(str(10));
        makeActBtn("bana", act(10));
    }
    if(action == "shavePubis")
    {
        root->rendVideoPage(this);
        root->incTime(15);
        root->vBody(pubisHair) -=5;
        root->vStatus(horny) += 5;
        root->useItem(iRazor,1);
        root->setVideo(media(8), 900, 448);
        root->setText(str(11));
        makeActBtn("bana", act(10));
    }
    if(action == "remAnalPlug")
    {
        root->incTime(1);
        root->vSex(analplugIN) = 0;
        root->setImage(media(9));
        if(root->vBody(anus) >= 5)
            root->setText(str(12));
        else
            root->setText(str(13));
        makeActBtn("bana", act(6));
    }
    if(action == "insAnalPlug")
    {
        root->incTime(5);
        if(root->sextToysBlock(2) == "")
        {
            root->vSex(analplugIN) = 1;
            if(root->vBody(anus) < 10)
                root->vBody(anus) += 1;
            root->vStatus(cumAnus) = 0;
            root->setImage(media(9));
            if(root->vBody(anus) >= 5)
                root->setText(str(14));
            else
                root->setText(str(15));
        }
        else
        {
            root->setImage("data/sex/toys/no_anus.jpg");
            root->setText(root->sextToysBlock(2));
        }
        makeActBtn("bana", act(6));
    }
    if(action == "remVibrator")
    {
        root->incTime(5);
        root->vSex(vibratorIN) =0;
        root->setImage(media(10));
        root->setText(str(17));
        makeActBtn("bana", act(6));
    }
    if(action == "insVibrator")
    {
        root->incTime(5);
        if(root->sextToysBlock(1) == "")
        {
            root->vSex(vibratorIN) = 1;
            if(root->vBody(vagina) < 6)
                root->vBody(vagina) += 1;
            root->setImage(media(10));
            root->setText(str(16));
        }
        else
        {
            root->setImage(media(11));
            root->setText(root->sextToysBlock(1));
        }
        makeActBtn("bana", act(6));
    }
    if(action == "pregTest")
    {
        root->useItem(iPregtest,1);
        if(root->vStatus(pregnancy) > 0)
        {
            root->vStatus(pregnancyKnow) = 1;
            root->addText(str(18));
        }
        else
            root->addText(str(19));
        makeActBtn("bana", act(6));
    }
    if(action == "undress")
    {
        root->vEvent(bana_redress) = 1;
        root->incTime(10);
        root->vStatus(horny) += 10;
        undress();
        root->setImage(media(12));
        root->setText(str(20));
        makeActBtn("watchMira", act(18));
    }
    if(action == "watchMira")
    {
        root->incTime(10);
        root->vStatus(horny) += 15;
        root->setImage(media(13));
        root->setText(str(21));
        makeActBtn("parMira", act(19));
    }
    if(action == "parMira")
    {
        root->incTime(105);
        cleanMe();
        root->vStatus(vidageday) += 1;
        root->vStatus(horny) += 20;
        root->vStatus(mood) += 20;
        root->vStatus(health) += 10;
        root->updSkin('+',5);
        root->setImage(media(14));
        root->setText(str(22));
        makeActBtn("endMira", act(6));
    }
    if(action == "endMira")
    {
        root->vEvent(mira) = 0;
        actionHandler("bana");
    }
    if(action == "dress_after_sauna")
    {
        root->redressOld();
        root->vEvent(bana_redress) = 0;
        actionHandler("bana");
    }
    root->updateParams();
}

void Gadbana::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadbana");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadbana::actionHandler);
    root->addActions(btn);
}

void Gadbana::cleanMe()
{
    root->vStatus(cumPussy) = 0;
    root->vStatus(cumFrot) = 0;
    root->vStatus(cumBelly) = 0;
    root->vStatus(cumAss) = 0;
    root->vStatus(cumAnus) = 0;
    root->vStatus(cumLips) = 0;
    root->vStatus(cumFace) = 0;
    root->vStatus(sweat) = -3;
    root->vBody(makeup) = 1;
    root->vBody(hairStatus) = 0;
    root->vStatus(horny) -= root->vStatus(horny)/5;
    root->vStatus(vaginal_grease) -= root->vStatus(vaginal_grease)/2;
}

void Gadbana::undress()
{
    root->redress(ClothType::Main,nullptr);
}

QString Gadbana::str(int id)
{
    QString arr[23];
    arr[0] = "Небольшая баня с низкой печью, баками для воды из нержавейки, низким закопченым потолком, и почерневшим деревянным полком.<br>На полке лежит бабушкина клизма.";
    arr[1] = "На вешалке висит ваша <a href='dress_after_sauna'>одежда</a>";
    arr[2] = "Вы стесняетесь появиться в таком виде во дворе.";
    arr[3] = "Баня топится. Где-то часам к семи можно будет париться.";
    arr[4] = "В бане можно париться";
    arr[5] = "Вы быстренько разделись и парились в бане, после чего окатывались холодной водой и в конце помылись.<br><b>Вы чувствуете, что состояние вашей кожи гораздо улучшилось.</b>";
    arr[6] = "Вы быстренько разделись и начали намыливать свое тело мочалкой. После смыли мыло и помыли волосы шампунем. Смыв шампунь вы стали совершенно чистой.";
    arr[7] = "Вы поменяли тампон";
    arr[8] = "Вы тщательно умыли своё лицо.";
    arr[9] = "Вы замыли пятна спермы на своей одежде.";
    arr[10] = "Вы намылили свои ноги и взяли бритву. Ловкими движениями вы сбрили волосы на ногах и смыли пенку для бритья.";
    arr[11] = "Вы намылили лобок и взяв бритву ловкими движениями начали брить лобок, сбривая волоски вокруг киски. Наконец с бритьем было покончено и вы смыли пенку с киски.";
    arr[12] = "Вы наклонились и привычным движением вынули из себя анальную пробку.";
    arr[13] = "Вы поднатужились и, закусив губу, с громким чпоком вынули из ануса пробку.";
    arr[14] = "Вы наклонились и привычным движением вставили себе анальную пробку.";
    arr[15] = "Вы постарались как можно сильнее расслабить попу и стали вставлять себе пробку. Закусив губу от чувства, что ваша попа вот вот лопнет, вы аккуратно протолкнули толстую часть в свою попу, и наконец-то пробка встала на место.";
    arr[16] = "Вы наклонились и вставили себе вибратор в киску.";
    arr[17] = "Вы наклонились и вынули вибратор из влагалища.";
    arr[18] = "Тест показал две полоски. Вы беременны. Вы думаете, что отец <<$father>>.";
    arr[19] = "Тест показал одну полоску.";
    arr[20] = "Вы раздеваетесь, краем глаза наблюдая за снимающей трусики Мирославой.";
    arr[21] = "Вы, чувствуя, как горячий пар проникает в ваши поры, блаженно наблюдаете за намыливающейся Мирой. Она иногда бросает на вас короткие взгляды и нерешительно улыбается в ответ...";
    arr[22] = "Наконец Мира заканчивает мыться и за это дело принимаетесь вы. Вскоре вы присоединяетесь к разомлевшей подруге и все остальное время вы паритесь в бане, изредка перекидываясь ничего не значащими фразами...<br><b>Вы чувствуете, что состояние вашей кожи гораздо улучшилось.</b>";
    return arr[id];
}

QString Gadbana::act(int id)
{
    QString arr[20];
    arr[0] = "Выйти во двор";
    arr[1] = "Назад";
    arr[2] = "Париться в бане";
    arr[3] = "Мыться";
    arr[4] = "Далее";
    arr[5] = "Поменять тампон";
    arr[6] = "Закончить";
    arr[7] = "Умыться";
    arr[8] = "Оттирать сперму с одежды";
    arr[9] = "Брить ноги 15 мин";
    arr[10] = "Отложить станок";
    arr[11] = "Брить лобок 15 мин";
    arr[12] = "Вынуть анальную пробку (1 мин)";
    arr[13] = "Вставить анальную пробку (5 мин)";
    arr[14] = "Вынуть вибратор 5 мин";
    arr[15] = "Вставить вибратор 5 мин";
    arr[16] = "Сделать тест на беременность";
    arr[17] = "Раздеться";
    arr[18] = "Смотреть, как моется Мирослава";
    arr[19] = "Париться";
    return arr[id];
}

QString Gadbana::media(int id)
{
    QString media[15];
    media[0] = "data/locations/gadukino/gaddvor/bana.jpg";
    media[1] = "data/img/clothing/0/noundress.jpg";
    media[2] = "data/actions/gadbana/par.jpg";
    media[3] = "data/actions/gadbana/mit.jpg";
    media[4] = "data/actions/gadbana/tampon.jpg";
    media[5] = "data/actions/bathroom/facesp.jpg";
    media[6] = "data/actions/bathroom/frotsp.jpg";
    media[7] = "data/actions/bathroom/legs.webm";
    media[8] = "data/actions/bathroom/pubic.webm";
    media[9] = "data/sex/toys/analplug.jpg";
    media[10] = "data/sex/toys/vibrator" + intQStr(getRandInt(0,1)) + ".jpg";
    media[11] = "data/sex/toys/no_pussy.jpg";
    media[12] = "data/sex/mira/MiraBan.jpg";
    media[13] = "data/sex/mira/MiraBan1.jpg";
    media[14] = "data/sex/mira/MiraBan2.jpg";
    return media[id];
}

bool Gadbana::isCanPar()
{
    int week = root->getWeek();
    int h = root->getHour();
    return (week == 7 && h >= 12 && h < 22);
}
