#include "gadfield.h"
#include "../Functions.h"
#include "../common/bathroom.h"
#include "../menu/buttons.h"
Gadfield::Gadfield(LocationHandler *ptr): Location(ptr) {}

void Gadfield::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("field");
    else
        actionHandler(arg);
}

LocId Gadfield::getLocId()
{
    return lgadfield;
}

LocId Gadfield::getParId()
{
    return lgadroad;
}

LocId Gadfield::getLocIn()
{
    return lgadukino;
}

QString Gadfield::getLocName()
{
    return "Поле";
}

bool Gadfield::isParent()
{
    return true;
}

void Gadfield::actionHandler(QString action)
{
    if(action == "field")
    {
        metka = action;
        setImage(makeImage(media(0), isDay(),getMonth()));
        setDesc(str(0));
        int month = getMonth();
        int h = getHour();
        int w = getWeekNum();

        if(month > 4 && month < 10)
        {
            if(h >= 9 && h <= 19 && w > 0 && w < 6)
                addText(str(1));
            if((h >= 9 && h <=19 && gVJob(graze_cow) == 0) || h >= 6 && h <= 20 && gVJob(graze_cow) == 1)
                addText(str(2));
            if(h >= 7 && h <= 20 && gVJob(haying_time) == 1)
            {
                addText(str(3));
                makeActBtn("haying",act(0));
            }
        }
        makeActBtn("exit",act(1));
    }
    if(action == "haying")
    {
        incTime(360);
        uVEvent(grandmahelp,1);
        uVQuest(grandpaQW,1);
        uVStatus(water,10);
        uVStatus(energy,10);
        sVJob(haying_time,0);
        if(gVQuest(miraQW) >= 15 && getRandInt(0,1) == 0)
        {
            uVQuest(miraQW,1);
            setImage(media(1));
            setDesc(str(4));
        }
        else
        {
            uVStatus(day_weight,-1);
            if(gVSkill(strenght) < 30)
                uVSkill(strenght,1);
            else
                uVSkill(strenght,getRandInt(0,1));
            if(gVSkill(agility) < 30)
                uVSkill(agility,1);
            else
                uVSkill(agility,getRandInt(0,1));
            if(gVSkill(endurance) < 30)
                uVSkill(endurance,1);
            else
                uVSkill(endurance,getRandInt(0,1));
            fnSport(3);
            setImage(media(2));
            setDesc(str(5));
        }
        makeActBtn("field",act(2));
    }
    if(action == "exit")
    {
        changeLoc(lgadroad,10);
    }
    if(action == "horse")
    {
        setImage(media(3));
        setDesc(str(5));
        if(getHour() == 19)
            makeActBtn("horse_to_home",act(4));
        makeActBtn("field",act(5));
    }
    if(action == "horse_to_home")
    {
        incTime(60);
        uVEvent(grandmahelp, getRandInt(0,1));
        uVQuest(grandpaQW, getRandInt(0,1));
        setImage(media(4));
        setDesc(str(6));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "gadsarai")
    {
        changeLoc(lgadsarai,0);
    }
    if(action == "graze_field")
    {
        metka = action;
        setImage(media(5));
        setDesc(str(7));
        if(getHour() == 19 && gVJob(graze_cow) == 0)
        {
            makeActBtn("take_cow_home",act(6));
        }
        if(gVJob(graze_cow) == 1)
        {
            if(getHour() < 10)
            {
                makeActBtn("field_wait_cows",act(7));
            }
            else if (getHour() >= 10 && getHour() < 13)
            {
                makeActBtn("graze_cow",act(7));
                if(getSunWeather() >= 0 && gVEvent(mira) == 0)
                {
                    if(gVEvent(daybegskver) != gVStatus(daystart))
                        makeActBtn("run_field",act(8));
                    if(getTemp() >= 20)
                        makeActBtn("sunbathe",act(9));
                    if(gVStatus(son) < 17)
                        makeActBtn("sleep",act(10));
                    makeActBtn("flowers",act(11));
                    //if reading['in_bag'] >= 0: act 'Читать '+func('zz_books','get_name',reading['in_bag']): gt 'zz_books', 'read_on_walk'
                    if(gVQuest(miraQW) >= 15 && gVEvent(mira) == 0 && getRandInt(1,5)==1 && gVEvent(Mira_no)==0 && (gVEvent(mitkasextimes) < 13 || gVQuest(miragopQW) >= 10 || gVEvent(mirasex) > 1) && gVEvent(miraday) != getDay())
                        gadfield_mira();
                }
            }
            else
            {
                uVEvent(grandmahelp,1);
                incTime(60);
                setImage(media(6));
                setDesc(str(10));
                makeActBtn("watering_place",act(2));
            }
        }
        else
            makeActBtn("field",act(5));
    }
    if(action == "watering_place")
    {
        metka = action;
        setImage(media(7));
        setDesc(str(11));
        if(getTemp() >= 20 && getSunWeather() >= 0)
            addText(str(12));

        if(gVJob(graze_cow) == 1)
        {
            if(getHour() < 16)
            {
                makeActBtn("graze_cow",act(7));
                if(getTemp() >= 20 && getSunWeather() >= 0 && gVEvent(mira) == 0)
                {
                    makeActBtn("swim",act(12));
                    makeActBtn("sunbathe",act(9));
                    if(gVStatus(son) < 17)
                        makeActBtn("sleep",act(10));
                    //if reading['in_bag'] >= 0: act 'Читать '+func('zz_books','get_name',reading['in_bag']): gt 'zz_books', 'read_on_walk'
                }
            }
            else
            {
                uVEvent(grandmahelp,1);
                incTime(60);
                setImage(media(8));
                setDesc(str(13));
                makeActBtn("forest_field",act(2));
            }
        }
    }
    if(action == "forest_field")
    {
        metka = action;
        setImage(media(9));
        setDesc(str(14));
        if(gVJob(graze_cow) == 1)
        {
            if(getHour() < 19)
            {
                makeActBtn("graze_cow",act(7));
                if(getSunWeather() >= 0 && gVEvent(mira) == 0)
                {
                    if(gVEvent(daybegskver) != gVStatus(daystart))
                        makeActBtn("run_field",act(8));
                    if(getTemp()>= 20)
                    {
                        makeActBtn("sunbathe",act(9));
                        if(gVStatus(son) < 17)
                            makeActBtn("sleep",act(10));
                        makeActBtn("flowers",act(11));
                        //if reading['in_bag'] >= 0: act 'Читать '+func('zz_books','get_name',reading['in_bag']): gt 'zz_books', 'read_on_walk'
                        if(gVQuest(miraQW) >= 15 && gVEvent(mira) == 0 && getRandInt(1,5)==1 && gVEvent(Mira_no)==0 && (gVEvent(mitkasextimes) < 13 || gVQuest(miragopQW) >= 10 || gVEvent(mirasex) > 1) && gVEvent(miraday) != getDay())
                            gadfield_mira();
                    }
                }
            }
            else
            {
                incTime(60);
                sVEvent(mira,0);
                sVJob(graze_cow,0);
                uVEvent(grandmahelp,1);
                uVQuest(grandpaQW,1);
                setImage(media(10));
                setDesc(str(15));
                makeActBtn("gadukino",act(2));
            }
        }
    }
    if(action == "Miroslava")
    {
        startEvent("Miroslava");
    }
    if(action == "take_cow_home")
    {
        incTime(60);
        uVEvent(grandmahelp, getRandInt(0,1));
        uVQuest(grandpaQW,getRandInt(0,1));
        setImage(media(11));
        setDesc(str(8));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "field_wait_cows")
    {
        incTime(120);
        //hour = 10
        setImage(media(12));
        setDesc(str(9));
        makeActBtn("graze_field",act(2));
    }
    if(action == "graze_cow")
    {
        incTime(60);
        sVJob(graze_cow_exp,1);
        uVEvent(grandmahelp,1);
        setImage(media(13));
        setDesc(str(16));
        makeActBtn("backtometka",act(2));
    }
    if (action == "run_field")
    {
        incTime(60);
        uVStatus(mood,15);
        uVStatus(day_weight,-1);
        uVSkill(runner, getRandInt(3,6));
        fnSport(2);
        if(gVSkill(speed) < 40)
            uVSkill(speed,1);
        else
            uVSkill(speed,getRandInt(0,1));
        if(gVSkill(endurance) < 20)
            uVSkill(endurance,1);
        sVEvent(daybegskver,gVStatus(daystart));
        setImage(media(14));
        setDesc(str(17));
        makeActBtn("backtometka",act(2));
    }
    if(action == "sunbathe")
    {
        incTime(30);
        uVStatus(mood,10);
        if(getSunWeather() <= 2)
        {
            if(getCloth(ClothType::Main) == nullptr)
                uVBody(skinTan,1);
            else
                uVBody(skinTan,getRandInt(0,1));
        }
        else
        {
            if(getCloth(ClothType::Main) == nullptr)
                uVBody(skinTan,2);
            else
                uVBody(skinTan,1);
        }
        sVBody(hairStatus,1);
        if(getTemp() > 22 && getTemp() < 30)
            uVStatus(sweat,1);
        else if(getTemp() >= 30)
            uVStatus(sweat,2);
        setImage(media(15));
        setDesc(str(18));
        makeActBtn("backtometka",act(2));
    }
    if(action == "sleep")
    {
        incTime(60);
        uVStatus(mood,10);
        uVStatus(son,4);
        setImage(media(16));
        setDesc(str(19));
        makeActBtn("backtometka",act(2));
    }
    if(action == "flowers")
    {
        incTime(60);
        uVStatus(mood,20);
        setImage(media(17));
        setDesc(str(20));
        makeActBtn("backtometka",act(2));
    }
    if(action == "swim")
    {
        incTime(30);
        ((BathRoom*)getLocPtr(lbathroom))->cleanMe();
        if(gVSkill(strenght) < 20)
            uVSkill(strenght,1);
        if(getTemp() <= 25)
            uVStatus(horny,-10);
        else
            uVStatus(horny,-5);
        uVStatus(mood,10);
        setImage(media(18));
        setDesc(str(21));
        makeActBtn("backtometka",act(2));
    }
    if(action == "backtometka")
    {
        actionHandler(metka);
    }
}

void Gadfield::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadfield::actionHandler);
    addActBtn(btn);
}

void Gadfield::gadfield_mira()
{
    incTime(5);
    uVQuest(miraQW,1);
    sVEvent(mira,1);
    sVEvent(miraday,getDay());
    setImage(media(19));
    setDesc(str(22));
    makeActBtn("backtometka",act(2));
}

QString Gadfield::str(int id)
{
    QString add;
    if(gVJob(graze_cow)==0)
        add = "graze_field";
    else
    {
        if(getHour() < 13)
            add= "graze_field";
        else if(getHour() < 16)
            add = "watering_place";
        else
            add = "forest_field";
    }
    QString str[23];
    str[0] = "Поле за деревней.";
    str[1] = "На поле пасется дедушкин конь <a href='horse'>Буян</a>.";
    str[2] = "На поле вы видите <a href='" + add + "'>стадо коров</a>.";
    str[3] = "На поле вы видите толпу местных жителей.";
    str[4] = "На сенокос собралася практически вся деревня, и вы тоже приняли посильное участие в работе. "
             "В принципе было весело, особенно учитывая, что большую часть времени вы проболтали с Мирой, валяясь на свежем сене.";
    str[5] = "Дедушкин конь Буян.";
    str[6] = "Увидев коня в поле, вы решили помочь дедушке, и отвести Буяна домой. Взяв коня под уздцы, вы отправились с ним в сторону деревни.";
    str[7] = "Стадо деревенских коров стоит посреди поля.";
    if(gVEvent(mira) == 1)
        str[7] += "<br>Рядом с вами сидит <a href='Miroslava'>Мира</a>.";
    str[8] = "Увидев стадо в поле, вы решили помочь дедушке, и отвести Зорьку домой..";
    str[9] = "В течение некоторого времени вы ждете, пока все местные пригонят своих коров";
    if(gVJob(graze_cow_exp) != 0)
        str[9] += " и придет дед с Зорькой.";
    str[10] = "Посмотрев на часы, дедушка казал, что уже обед и пора гнать стадо на водопой. Вместе вы принялись поднимать лежащих коров, направляя их в сторону реки.";
    str[11] = "Стадо деревенских коров стоит у реки.";
    if(gVEvent(mira) == 1)
        str[11] += "<br>Рядом с вами сидит <a href='Miroslava'>Мира</a>.";
    str[12] = "<br>- Можешь искупнуться внучка, пока есть время. Я пригляжу за стадом, - сказал вам дедушка.";
    str[13] = "Посмотрев на часы, дедушка казал, что пора гнать стадо обратно на поле, но теперь ближе к лесу. Вместе вы принялись собирать разбредшихся и стоящих в воде коров и направлять в сторону леса.";
    str[14] = "Стадо деревенских коров стоит на поле возле леса.";
    if(gVEvent(mira) == 1)
        str[14] += "<br>Рядом с вами сидит <a href='Miroslava'>Мира</a>.";
    str[15] = "Посмотрев на часы, дедушка казал, что уже поздно и пора гнать стадо домой. Коров дважды упрашивать не пришлось, они сами ломанулись в сторону деревни, а вы еле поспевали за ними.";
    str[16] = "Вы в течение часа пасли деревенских коров. Вернее пас их дед, вы по большей части развлекались, ловя бабочек и валяясь в стогу сена.";
    str[17] = "Вы, в течение часа, от нечего делать, носились по полю.";
    str[18] = "В течение часа, бросив все, вы загорали.";
    str[19] = "Вы легли на траву и сами не заметили как задремали, проспав в течение часа.";
    str[20] = "Вы в течение часа бродили по полю и собирали цветы.";
    str[21] = "Вы быстро искупнулись в речушке, пока есть время.";
    str[22] = "Оторвавшись от созерцания коров, вы заметили приближающуюся к вам Миру. Вы радостно поднялись ей на встречу."
              "<br>- Привет,Света. А я вот решила тебя навестить и попить принести, - сказала она подойдя к вам. - Скучаешь небось?";
    return str[id];
}

QString Gadfield::act(int id)
{
    QString str[13];
    str[0] = "Отправиться на сенокос";
    str[1] = "Уйти";
    str[2] = "Далее";
    str[3] = "Вернуться на дорогу";
    str[4] = "Отвести коня домой";
    str[5] = "Назад";
    str[6] = "Отвести корову домой";
    str[7] = "Пасти коров с дедом";
    str[8] = "Бегать по полю";
    str[9] = "Загорать";
    str[10] = "Вздремнуть на траве";
    str[11] = "Собирать цветы";
    str[12] = "Купаться";
    return str[id];
}

QString Gadfield::media(int id)
{
    QString med[20];
    med[0] = "data/locations/gadukino/gadfield/gadfield.jpg";
    med[1] = "data/locations/gadukino/gadfield/haying_time_mira.jpg";
    med[2] = "data/locations/gadukino/gadfield/haying_time.jpg";
    med[3] = "data/locations/gadukino/horse/field.jpg";
    med[4] = "data/locations/gadukino/horse/lead.jpg";
    med[5] = "data/locations/gadukino/gadfield/cow.jpg";
    med[6] = "data/locations/gadukino/gadfield/cow_go.jpg";
    med[7] = "data/locations/gadukino/gadfield/cow_river.jpg";
    med[8] = "data/locations/gadukino/gadfield/cow_go.jpg";
    med[9] = "data/locations/gadukino/gadfield/cow_forest.jpg";
    med[10] = "data/locations/gadukino/gadfield/cow_go_home.jpg";
    med[11] = "data/locations/gadukino/gadfield/cow_field.jpg";
    med[12] = "data/locations/gadukino/gadfield/graze_cow_wait.jpg";
    med[13] = "data/locations/gadukino/gadfield/graze_cow" + intQStr(getRandInt(1,4)) + ".jpg";
    med[14] = "data/locations/gadukino/gadfield/graze_cow_run";
    if(gVEvent(mira) == 1)
        med[14] += "_mira";
    med[14] += ".jpg";
    med[15] = "data/locations/gadukino/gadfield/graze_cow_sun";
    if(gVEvent(mira) == 1)
        med[15] += "_mira2";
    med[15] += ".jpg";
    med[16] = "data/locations/gadukino/gadfield/graze_cow_lying.jpg";
    med[17] = "data/locations/gadukino/gadfield/graze_cow_flowers.jpg";
    med[18] = "data/locations/gadukino/gadfield/graze_cow_river";
    if(gVEvent(mira) == 1)
        med[18] += "_mira";
    med[18] += ".jpg";
    med[19] = "data/sex/mira/Mira2.jpg";
    return med[id];
}
