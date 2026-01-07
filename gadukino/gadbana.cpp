#include "gadbana.h"
#include "../Functions.h"
#include "../menu/buttons.h"
Gadbana::Gadbana(LocationHandler *ptr): Location(ptr) {}

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
    clearActions();
    if(action == "bana")
    {
        rendImagePage();
        setImage(media(0));
        setDesc(str(0));
        if(gVEvent(bana_redress) == 1)
        {
            addText(str(1));
            connect(getTextPtr(), &QLabel::linkActivated, this, &Gadbana::actionHandler);
        }
        if(gVEvent(mira) == 0)
        {
            makeActBtn("goGadDvor", act(0));
            if(isCanPar() && getHour() <= 18)
                addText(str(3));
            if(isCanPar() && getHour() > 18 && getHour() < 22)
            {
                addText(str(4));
                if(gVEvent(banaday) != gVStatus(daystart))
                    makeActBtn("parInBan", act(2));
            }
            if(!isCanPar())
                makeActBtn("takeShower", act(3));
            if(getItemCount(iTampon) > 0 && gVStatus(mesec) > 0 && gVStatus(isprok) == 0 && !isAutoTampon())
                makeActBtn("chgTampon", act(5));
            if(gVStatus(cumLips) > 0 || gVStatus(cumFace) > 0 || gVBody(makeup) != 1)
                makeActBtn("clearFace", act(7));
            if(gVStatus(cumFrot) > 0)
                makeActBtn("cleanClothes", act(8));
            if(gVBody(legHair) > 0 && getItemCount(iRazor) > 0)
                makeActBtn("shaveLegs", act(9));
            if(gVBody(pubisHair) > 0 && getItemCount(iRazor) > 0)
                makeActBtn("shavePubis", act(11));
            if(gVSex(analplugIN) == 1)
                makeActBtn("remAnalPlug", act(12));
            if(getItemCount(iAnalPlug) > 0 && gVSex(analplugIN) == 0)
                makeActBtn("insAnalPlug", act(13));
            if(gVSex(vibratorIN) == 1)
                makeActBtn("remVibrator", act(14));
            if(getItemCount(iVibrator) > 0 && gVSex(vibratorIN) == 0)
                makeActBtn("insVibrator", act(15));
            if(getItemCount(iPregtest) > 0)
                makeActBtn("pregTest", act(16));
        }
        else
        {
            makeActBtn("undress", act(17));
        }
    }
    if(action == "goGadDvor")
    {
        if(isCloth() || (!isCloth() && gVStatus(shamelessFlag) > 2))
        {
            changeLoc(lgaddvor,5);
        }
        else
        {
            setImage(media(1));
            setDesc(str(2));
            makeActBtn("bana", act(1));
        }
    }
    if(action == "parInBan")
    {
        sVEvent(bana_redress, 1);
        incTime(105);
        sVEvent(banaday, gVStatus(daystart));
        cleanMe();
        updSkin('+', 5);
        uVStatus(vidageday,1);
        uVStatus(health, 10);
        uVStatus(mood,20);
        uVStatus(day_weight,-1);
        undress();
        setImage(media(2));
        setDesc(str(5));
        makeActBtn("bana", act(4));
    }
    if(action == "takeShower")
    {
        cleanMe();
        incTime(15);
        uVStatus(mood,10);
        sVEvent(bana_redress, 1);
        undress();
        setImage(media(3));
        setDesc(str(6));
        makeActBtn("bana", act(4));
    }
    if(action == "chgTampon")
    {
        useItem(iTampon,1);
        sVStatus(isprok,1);
        incTime(5);
        uVStatus(mood,-5);
        setImage(media(4));
        setDesc(str(7));
        makeActBtn("bana", act(6));
    }
    if(action == "clearFace")
    {
        sVBody(makeup,1);
        sVStatus(cumLips,0);
        sVStatus(cumFace,0);
        uVStatus(sweat,-1);
        incTime(5);
        setImage(media(5));
        setDesc(str(8));
        makeActBtn("bana", act(6));
    }
    if(action == "cleanClothes")
    {
        sVStatus(cumFrot,0);
        incTime(15);
        setImage(media(6));
        setDesc(str(9));
        makeActBtn("bana", act(6));
    }
    if(action == "shaveLegs")
    {
        rendVideoPage();
        incTime(15);
        uVBody(legHair, -5);
        uVStatus(horny,5);
        useItem(iRazor,1);
        setVideo(media(7), 900, 508);
        setDesc(str(10));
        makeActBtn("bana", act(10));
    }
    if(action == "shavePubis")
    {
        rendVideoPage();
        incTime(15);
        uVBody(pubisHair, -5);
        uVStatus(horny,5);
        useItem(iRazor,1);
        setVideo(media(8), 900, 448);
        setDesc(str(11));
        makeActBtn("bana", act(10));
    }
    if(action == "remAnalPlug")
    {
        incTime(1);
        sVSex(analplugIN,0);
        setImage(media(9));
        if(gVBody(anus) >= 5)
            setDesc(str(12));
        else
            setDesc(str(13));
        makeActBtn("bana", act(6));
    }
    if(action == "insAnalPlug")
    {
        incTime(5);
        if(sextToysBlock(2) == "")
        {
            sVSex(analplugIN,1);
            if(gVBody(anus) < 10)
                uVBody(anus,1);
            sVStatus(cumAnus,0);
            setImage(media(9));
            if(gVBody(anus) >= 5)
                setDesc(str(14));
            else
                setDesc(str(15));
        }
        else
        {
            setImage("data/actions/analplug/no_anus.jpg");
            setDesc(sextToysBlock(2));
        }
        makeActBtn("bana", act(6));
    }
    if(action == "remVibrator")
    {
        incTime(5);
        sVSex(vibratorIN,0);
        setImage(media(10));
        setDesc(str(17));
        makeActBtn("bana", act(6));
    }
    if(action == "insVibrator")
    {
        incTime(5);
        if(sextToysBlock(1) == "")
        {
            sVSex(vibratorIN,1);
            if(gVBody(vagina) < 6)
                uVBody(vagina,1);
            setImage(media(10));
            setDesc(str(16));
        }
        else
        {
            setImage(media(11));
            setDesc(sextToysBlock(1));
        }
        makeActBtn("bana", act(6));
    }
    if(action == "pregTest")
    {
        useItem(iPregtest,1);
        if(gVStatus(pregnancy) > 0)
        {
            sVStatus(pregnancyKnow,1);
            addText(str(18));
        }
        else
            addText(str(19));
        makeActBtn("bana", act(6));
    }
    if(action == "undress")
    {
        sVEvent(bana_redress, 1);
        incTime(10);
        uVStatus(horny,10);
        undress();
        setImage(media(12));
        setDesc(str(20));
        makeActBtn("watchMira", act(18));
    }
    if(action == "watchMira")
    {
        incTime(10);
        uVStatus(horny,15);
        setImage(media(13));
        setDesc(str(21));
        makeActBtn("parMira", act(19));
    }
    if(action == "parMira")
    {
        incTime(105);
        cleanMe();
        uVStatus(vidageday,1);
        uVStatus(horny,20);
        uVStatus(mood,20);
        uVStatus(health,10);
        updSkin('+',5);
        setImage(media(14));
        setDesc(str(22));
        makeActBtn("endMira", act(6));
    }
    if(action == "endMira")
    {
        sVEvent(mira, 0);
        actionHandler("bana");
    }
    if(action == "dress_after_sauna")
    {
        redressOld();
        sVEvent(bana_redress, 0);
        actionHandler("bana");
    }
    updateParams();
}

void Gadbana::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadbana::actionHandler);
    addActBtn(btn);
}

void Gadbana::cleanMe()
{
    sVStatus(cumPussy,0);
    sVStatus(cumFrot,0);
    sVStatus(cumBelly,0);
    sVStatus(cumAss,0);
    sVStatus(cumAnus,0);
    sVStatus(cumLips,0);
    sVStatus(cumFace,0);
    sVStatus(sweat, -3);
    sVBody(makeup,1);
    sVBody(hairStatus,0);
    uVStatus(horny, -gVStatus(horny)/5);
    uVStatus(vaginal_grease, -gVStatus(vaginal_grease)/2);
}

void Gadbana::undress()
{
    redress(ClothType::Main,nullptr);
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
    media[7] = "data/actions/shave/legs.webm";
    media[8] = "data/actions/shave/pubic.webm";
    media[9] = "data/actions/analplug/analplug.jpg";
    media[10] = "data/actions/vibrator/vibrator" + intQStr(getRandInt(0,1)) + ".jpg";
    media[11] = "data/actions/vibrator/no_pussy.jpg";
    media[12] = "data/qwest/mira/MiraBan.jpg";
    media[13] = "data/qwest/mira/MiraBan1.jpg";
    media[14] = "data/qwest/mira/MiraBan2.jpg";
    return media[id];
}

bool Gadbana::isCanPar()
{
    int week = getWeekNum();
    int h = getHour();
    return (week == 7 && h >= 12 && h < 22);
}
