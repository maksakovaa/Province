#include "gadukino.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"
Gadukino::Gadukino(Game *ptr): root(ptr){}

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
    root->clearActions();
    if(action == "gadukino")
    {
        int month = root->getMonth();
        int hour = root->getHour();
        int week = root->getWeek();
        if(root->vEvent(gadukino_blok) == 1) root->vEvent(gad_offense) = 1;
        root->setImage(makeImage(media(0), root->isDay(), root->getMonth()));
        root->setText(str(0));
        if(root->getHour() >= 17 && root->getHour() < 20 && root->vEvent(mitkaday) != root->vStatus(daystart))
            root->addText(str(1));
        if(root->getSunWeather() >= 0)
        {
            if(month >= 4 && month <= 10 && hour >= 20)
                root->addText(str(2));
            if(month >= 5 && month <= 9 && hour > 14 && hour < 18 && (week == 6 || week == 0))
                root->addText(str(3));
            if(month >= 6 && month <= 8 && hour > 7 && hour < 13 && root->vJob(graze_cow) == 0 && week == 0)
                root->addText(str(4));
            if(month >= 5 && month <= 9 && hour > 13 && hour < 18 && root->vJob(graze_cow) == 0 && week == 6)
                root->addText(str(5));
        }
//gs 'car', 'check'
//if _taxi_time >= 0: gs 'taxi', 'check'
        if(hour >= 8 && hour < 18)
            makeActBtn("gadmarket", act(0));
        if(root->isDay() && root->getSunWeather() >= 0 && root->getSnow() <= 0)
            makeActBtn("gadevent_walk",act(1));
        makeActBtn("Gadriver",act(2));
        makeActBtn("gadroad",act(3));
        makeActBtn("road_main_2",act(4));

        if(root->vEvent(onlooker) == 1)
        {
            root->vEvent(onlooker) = 0;
            root->startEvent(eGadukinoEvents,"gadukino_onlooker");
        }

        if(root->getCloth(ClothType::Main) == nullptr)
        {
            root->startEvent(eGadukinoEvents, "gadukino_nude");
        }

        if((root->vEvent(mitka) == 0 && hour >= 7 && hour < 20) || (root->vEvent(mitka) == 1 && hour >= 17 && hour < 20 && getRandInt(1,3) == 1 && root->vEvent(mitkaday) != root->vStatus(daystart) && root->vEvent(mitkasextimes) < 13))
        {
            root->clearActions();
            root->incTime(5);
            root->setImage(media(1));
            root->setText(str(6));
            makeActBtn("mitka",act(5));
        }
        int mitkarand = getRandInt(1,20);
        if(root->vEvent(gadriver_gang) < 3 && month >= 4 && month <= 10)
        {
            if(root->vEvent(mitkasextimes) > 13 && hour >= 7 && hour <= 16)
            {
                if(mitkarand == 1 && root->vEvent(mitkaday) != root->vStatus(daystart))
                {
                    root->startEvent(eGadukinoEvents, "gadukino_mitka");
                }
                if(mitkarand == 2 && root->vEvent(kolyambaday) != root->vStatus(daystart))
                {
                    root->startEvent(eGadukinoEvents, "gadukino_kolyamba");
                }
                if(mitkarand == 3 && root->vEvent(vasyanday) != root->vStatus(daystart))
                {
                    root->startEvent(eGadukinoEvents, "gadukino_vasyan");
                }
            }
            if(mitkarand == 4 && root->vEvent(mitkasextimes) > 15 && hour >= 17 && hour <= 19 && root->vEvent(gadboyday) != root->vStatus(daystart) && week > 0 && week <= 5)
            {
                root->startEvent(eGadukinoEvents, "gadukino_2boys");
            }
            if(mitkarand <= 5 && root->vEvent(mitkasextimes) > 15 && hour >= 7 && hour <= 19 && root->vEvent(gadboyday) != root->vStatus(daystart) && (week == 0 || week == 6))
            {
                root->startEvent(eGadukinoEvents, "gadukino_2boys");
            }
        }
        if(root->vEvent(gadriver_gang) == 1 && hour >= 6 && hour <= 21 && root->vEvent(gadboyday) != root->vStatus(daystart))
        {
            root->startEvent(eGadukinoEvents, "gang_apologise");
        }
        if(root->vEvent(gadriver_gang) == 3 && hour >= 6 && hour <= 21 && root->vEvent(gadboyday) != root->vStatus(daystart))
        {
            root->startEvent(eGadukinoEvents, "mitka_apologise");
        }
        if(root->vEvent(gadriver_gang) == 4 && root->vEvent(mirasex) == 1 && root->vEvent(miralick) == 0 && hour >= 8 && hour <= 20 && root->vEvent(gadboyday) != root->vStatus(daystart))
        {
            root->startEvent(eGadukinoEvents, "mira_apologise");
        }
        if(root->vEvent(mitkasextimes) > 13 && root->vEvent(mirasex) == 1 && root->vQuest(miragopQW) < 11 && mitkarand >= 15 && root->vEvent(miraday) != root->getDay())
        {
            root->startEvent(eMeadowEvent, "mira_lesb_talk4");
        }

        //Логистика
        //if logist = 251 and logist_qf > 0 and hour >= 12: gt 'logist_events'
    }
    if(action == "Gaddvor")
    {
        root->changeLoc(lgaddvor,5);
    }
    if(action == "MiroslavaHome")
    {
        root->changeLoc(lmirahome,5);
    }
    if(action == "gadevent_collection_point")
    {
        root->startEvent(eGadukinoEvents, "collection_point");
    }
    if(action == "mitka")
    {
        root->startEvent(eMitka);
    }
    if(action == "mitkabuh")
    {
        root->vEvent(miraingop) = 0;
        root->startEvent(eMitkaBuh);
    }
    if(action == "grandma")
    {
        root->startEvent(eGrandMa);
    }
    if(action == "grandpa")
    {
        root->startEvent(eGrandPa);
    }
    if(action == "gadmarket")
    {
        root->changeLoc(lgadmarket,5);
    }
    if(action == "gadevent_walk")
    {
        root->startEvent(eGadukinoEvents, "walk");
    }
    if(action == "Gadriver")
    {
        root->changeLoc(lgadriver,20);
    }
    if(action == "gadroad")
    {
        root->changeLoc(lgadroad,20);
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
    root->addActions(btn);
}

QString Gadukino::str(int id)
{
    QString add1, add2,add3, bab, ded;
    if(root->vEvent(gadukino_blok) == 0)
        add1 = "<a href='Gaddvor'>дедушка и бабушка</a>";
    else
        add1 = "дедушка и бабушка";
    if(root->vQuest(miraQW) > 0)
        add2 = "<br>Через тройку домов находится дом <a href='MiroslavaHome'>Мирославы</a>.";
    if(root->getHour() >= 9 && root->getHour() <= 11 && root->getMonth() >= 6 && root->getMonth() <= 9)
        add3 = "<a href='gadevent_collection_point'>пункт</a>";
    else
        add3 = "пункт";
    if(root->vEvent(grandma_notalk) == 0)
        bab = "<a href='grandma'>бабушка</a>";
    else
        bab = "сердитая бабушка";

    if(root->vEvent(grandpa_notalk) == 0)
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
