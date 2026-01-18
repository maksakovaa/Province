#include "gadukino.h"
#include "../nav/locationhandler.h"
#include "../Functions.h"
#include "../menu/buttons.h"
Gadukino::Gadukino(LocationHandler *ptr): Location(ptr){}

void Gadukino::show(QString arg)
{
    actionHandler("gadukino");
}

LocId Gadukino::getLocId()
{
    return lgadukino;
}

LocId Gadukino::getParId()
{
    return lgadukino;
}

LocId Gadukino::getLocIn()
{
    return lgadukino;
}

QString Gadukino::getLocName()
{
    return "Гадюкино";
}

bool Gadukino::isParent()
{
    return false;
}

void Gadukino::actionHandler(QString action)
{
    clearActions();
    if(action == "gadukino")
    {
        int month = getMonth();
        int hour = getHour();
        int week = getWeekNum();
        if(gVEvent(gadukino_blok) == 1) sVEvent(gad_offense,1);
        setImage(makeImage(media(0), isDay(), getMonth()));
        setDesc(str(0));
        if(getHour() >= 17 && getHour() < 20 && gVEvent(mitkaday) != gVStatus(daystart))
            addText(str(1));
        if(getSunWeather() >= 0)
        {
            if(month >= 4 && month <= 10 && hour >= 20)
                addText(str(2));
            if(month >= 5 && month <= 9 && hour > 14 && hour < 18 && (week == 6 || week == 0))
                addText(str(3));
            if(month >= 6 && month <= 8 && hour > 7 && hour < 13 && gVJob(graze_cow) == 0 && week == 0)
                addText(str(4));
            if(month >= 5 && month <= 9 && hour > 13 && hour < 18 && gVJob(graze_cow) == 0 && week == 6)
                addText(str(5));
        }
//gs 'car', 'check'
//if _taxi_time >= 0: gs 'taxi', 'check'
        if(hour >= 8 && hour < 18)
            makeActBtn("gadmarket", act(0));
        if(isDay() && getSunWeather() >= 0 && getSnow() <= 0)
            makeActBtn("gadevent_walk",act(1));
        makeActBtn("Gadriver",act(2));
        makeActBtn("gadroad",act(3));
        makeActBtn("road_main_2",act(4));

        if(gVEvent(onlooker) == 1)
        {
            sVEvent(onlooker,0);
            startEvent(eGadukinoEvents,"gadukino_onlooker");
        }

        if(getCloth(ClothType::Main) == nullptr)
        {
            startEvent(eGadukinoEvents, "gadukino_nude");
        }

        if((gVEvent(mitka) == 0 && hour >= 7 && hour < 20) || (gVEvent(mitka) == 1 && hour >= 17 && hour < 20 && getRandInt(1,3) == 1 && gVEvent(mitkaday) != gVStatus(daystart) && gVEvent(mitkasextimes) < 13))
        {
            clearActions();
            incTime(5);
            setImage(media(1));
            setDesc(str(6));
            makeActBtn("mitka",act(5));
        }
        int mitkarand = getRandInt(1,20);
        if(gVEvent(gadriver_gang) < 3 && month >= 4 && month <= 10)
        {
            if(gVEvent(mitkasextimes) > 13 && hour >= 7 && hour <= 16)
            {
                if(mitkarand == 1 && gVEvent(mitkaday) != gVStatus(daystart))
                {
                    startEvent(eGadukinoEvents, "gadukino_mitka");
                }
                if(mitkarand == 2 && gVEvent(kolyambaday) != gVStatus(daystart))
                {
                    startEvent(eGadukinoEvents, "gadukino_kolyamba");
                }
                if(mitkarand == 3 && gVEvent(vasyanday) != gVStatus(daystart))
                {
                    startEvent(eGadukinoEvents, "gadukino_vasyan");
                }
            }
            if(mitkarand == 4 && gVEvent(mitkasextimes) > 15 && hour >= 17 && hour <= 19 && gVEvent(gadboyday) != gVStatus(daystart) && week > 0 && week <= 5)
            {
                startEvent(eGadukinoEvents, "gadukino_2boys");
            }
            if(mitkarand <= 5 && gVEvent(mitkasextimes) > 15 && hour >= 7 && hour <= 19 && gVEvent(gadboyday) != gVStatus(daystart) && (week == 0 || week == 6))
            {
                startEvent(eGadukinoEvents, "gadukino_2boys");
            }
        }
        if(gVEvent(gadriver_gang) == 1 && hour >= 6 && hour <= 21 && gVEvent(gadboyday) != gVStatus(daystart))
        {
            startEvent(eGadukinoEvents, "gang_apologise");
        }
        if(gVEvent(gadriver_gang) == 3 && hour >= 6 && hour <= 21 && gVEvent(gadboyday) != gVStatus(daystart))
        {
            startEvent(eGadukinoEvents, "mitka_apologise");
        }
        if(gVEvent(gadriver_gang) == 4 && gVEvent(mirasex) == 1 && gVEvent(miralick) == 0 && hour >= 8 && hour <= 20 && gVEvent(gadboyday) != gVStatus(daystart))
        {
            startEvent(eGadukinoEvents, "mira_apologise");
        }
        if(gVEvent(mitkasextimes) > 13 && gVEvent(mirasex) == 1 && gVQuest(miragopQW) < 11 && mitkarand >= 15 && gVEvent(miraday) != getDay())
        {
            startEvent(eMeadowEvent, "mira_lesb_talk4");
        }

        //Логистика
        //if logist = 251 and logist_qf > 0 and hour >= 12: gt 'logist_events'
    }
    if(action == "Gaddvor")
    {
        changeLoc(lgaddvor,5);
    }
    if(action == "MiroslavaHome")
    {
        changeLoc(lmirahome,5);
    }
    if(action == "gadevent_collection_point")
    {
        startEvent(eGadukinoEvents, "collection_point");
    }
    if(action == "mitka")
    {
        startEvent(eMitka);
    }
    if(action == "mitkabuh")
    {
        sVEvent(miraingop,0);
        startEvent(eMitkaBuh);
    }
    if(action == "grandma")
    {
        startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        startEvent(eGrandPa);
    }
    if(action == "gadmarket")
    {
        changeLoc(lgadmarket,5);
    }
    if(action == "gadevent_walk")
    {
        startEvent(eGadukinoEvents, "walk");
    }
    if(action == "Gadriver")
    {
        changeLoc(lgadriver,20);
    }
    if(action == "gadroad")
    {
        changeLoc(lgadroad,20);
    }
    if(action == "road_main_2")
    {

    }
}

void Gadukino::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "gadukino");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadukino::actionHandler);
    addActBtn(btn);
}

QString Gadukino::str(int id)
{
    QString add1, add2,add3, bab, ded;
    if(gVEvent(gadukino_blok) == 0)
        add1 = "<a href='Gaddvor'>дедушка и бабушка</a>";
    else
        add1 = "дедушка и бабушка";
    if(gVQuest(miraQW) > 0)
        add2 = "<br>Через тройку домов находится дом <a href='MiroslavaHome'>Мирославы</a>.";
    if(getHour() >= 9 && getHour() <= 11 && getMonth() >= 6 && getMonth() <= 9)
        add3 = "<a href='gadevent_collection_point'>пункт</a>";
    else
        add3 = "пункт";
    if(gVEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";

    if(gVEvent(grandpa_notalk) == 0)
        ded = "<a href='grandpa'>дедушка</a>";
    else
        ded = "дедушка";

    QString str[20];
    str[0] = "Маленькая деревушка с покосившимися деревянными избами.<br>В одной из изб живут ваши " + add1 + add2 + "<br>В сезон в деревню приезжает передвижной " + add3 + " заготовки грибов и ягод.";
    str[1] = "Не далеко от избы шарахается <a href='mitka'>Митька Шкворень</a>";
    str[2] = "Не далеко от избы сидит компашка деревенской <a href='mitkabuh'>молодежи</a>";
    str[3] = "На лавочке, возле дома, сидит ваша " + bab + " и сплетничает с подругами.";
    str[4] = "Ваш " + ded + " с мужиками собрались возде магазина магазина и явно что-то замышляют.";
    str[5] = "Ваш " + ded + " с компанией сидят на лавке и что-то обсуждают.";
    str[6] = "В деревне к вам подошел ваш давний знакомый Митька.";
    return str[id];
}

QString Gadukino::act(int id)
{
    QString act[20];
    act[0] = "Идти в магазин";
    act[1] = "Гулять по деревне";
    act[2] = "Идти на речку";
    act[3] = "Идти за деревню";
    act[4] = "Выйти на шоссе";
    act[5] = "Далее";
    return act[id];
}

QString Gadukino::media(int id)
{
    QString med[2];
    med[0] = "data/locations/gadukino/street.jpg";
    med[1] = "data/npc/gadukino/mitka/mitka.jpg";
    return med[id];
}
