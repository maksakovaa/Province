#include "gadfield.h"
#include "../../Functions.h"
#include "../common/bathroom.h"
#include "../../menu/buttons.h"
#include "../../game.h"

Gadfield::Gadfield(Game *ptr): root(ptr) {}

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
        root->setImage(makeImage(media(0), root->isDay(),root->getMonth()));
        root->setText(str(0));
        int month = root->getMonth();
        int h = root->getHour();
        int w = root->getWeek();

        if(month > 4 && month < 10)
        {
            if(h >= 9 && h <= 19 && w > 0 && w < 6)
                root->addText(str(1));
            if((h >= 9 && h <=19 && root->vJob(graze_cow) == 0) || h >= 6 && h <= 20 && root->vJob(graze_cow) == 1)
                root->addText(str(2));
            if(h >= 7 && h <= 20 && root->vJob(haying_time) == 1)
            {
                root->addText(str(3));
                makeActBtn("haying",act(0));
            }
        }
        makeActBtn("exit",act(1));
    }
    if(action == "haying")
    {
        root->incTime(360);
        root->vEvent(grandmahelp) += 1;
        root->vQuest(grandpaQW) += 1;
        root->vStatus(water) += 10;
        root->vStatus(energy) += 10;
        root->vJob(haying_time) = 0;
        if(root->vQuest(miraQW) >= 15 && getRandInt(0,1) == 0)
        {
            root->vQuest(miraQW) +=1;
            root->setImage(media(1));
            root->setText(str(4));
        }
        else
        {
            root->vStatus(day_weight) -= 1;
            if(root->vSkill(strenght) < 30)
                root->vSkill(strenght) += 1;
            else
                root->vSkill(strenght) += getRandInt(0,1);
            if(root->vSkill(agility) < 30)
                root->vSkill(agility) += 1;
            else
                root->vSkill(agility) += getRandInt(0,1);
            if(root->vSkill(endurance) < 30)
                root->vSkill(endurance) += 1;
            else
                root->vSkill(endurance) += getRandInt(0,1);
            root->fnSport(3);
            root->setImage(media(2));
            root->setText(str(5));
        }
        makeActBtn("field",act(2));
    }
    if(action == "exit")
    {
        root->changeLoc(lgadroad,10);
    }
    if(action == "horse")
    {
        root->setImage(media(3));
        root->setText(str(5));
        if(root->getHour() == 19)
            makeActBtn("horse_to_home",act(4));
        makeActBtn("field",act(5));
    }
    if(action == "horse_to_home")
    {
        root->incTime(60);
        root->vEvent(grandmahelp) += getRandInt(0,1);
        root->vQuest(grandpaQW) += getRandInt(0,1);
        root->setImage(media(4));
        root->setText(str(6));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "gadsarai")
    {
        root->changeLoc(lgadsarai,0);
    }
    if(action == "graze_field")
    {
        metka = action;
        root->setImage(media(5));
        root->setText(str(7));
        if(root->getHour() == 19 && root->vJob(graze_cow) == 0)
        {
            makeActBtn("take_cow_home",act(6));
        }
        if(root->vJob(graze_cow) == 1)
        {
            if(root->getHour() < 10)
            {
                makeActBtn("field_wait_cows",act(7));
            }
            else if (root->getHour() >= 10 && root->getHour() < 13)
            {
                makeActBtn("graze_cow",act(7));
                if(root->getSunWeather() >= 0 && root->vEvent(mira) == 0)
                {
                    if(root->vEvent(daybegskver) != root->vStatus(daystart))
                        makeActBtn("run_field",act(8));
                    if(root->getTemp() >= 20)
                        makeActBtn("sunbathe",act(9));
                    if(root->vStatus(son) < 17)
                        makeActBtn("sleep",act(10));
                    makeActBtn("flowers",act(11));
                    if(root->vEvent(book_in_bag) >= 0)
                        makeActBtn("read_book",act(13) + root->getBookName(root->vEvent(book_in_bag)));
                    if(root->vQuest(miraQW) >= 15 && root->vEvent(mira) == 0 && getRandInt(1,5)==1 && root->vEvent(Mira_no)==0 && (root->vEvent(mitkasextimes) < 13 || root->vQuest(miragopQW) >= 10 || root->vEvent(mirasex) > 1) && root->vEvent(miraday) != root->getDay())
                        gadfield_mira();
                }
            }
            else
            {
                root->vEvent(grandmahelp) += 1;
                root->incTime(60);
                root->setImage(media(6));
                root->setText(str(10));
                makeActBtn("watering_place",act(2));
            }
        }
        else
            makeActBtn("field",act(5));
    }
    if(action == "watering_place")
    {
        metka = action;
        root->setImage(media(7));
        root->setText(str(11));
        if(root->getTemp() >= 20 && root->getSunWeather() >= 0)
            root->addText(str(12));

        if(root->vJob(graze_cow) == 1)
        {
            if(root->getHour() < 16)
            {
                makeActBtn("graze_cow",act(7));
                if(root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->vEvent(mira) == 0)
                {
                    makeActBtn("swim",act(12));
                    makeActBtn("sunbathe",act(9));
                    if(root->vStatus(son) < 17)
                        makeActBtn("sleep",act(10));
                    if(root->vEvent(book_in_bag) >= 0)
                        makeActBtn("read_book",act(13) + root->getBookName(root->vEvent(book_in_bag)));
                }
            }
            else
            {
                root->vEvent(grandmahelp) += 1;
                root->incTime(60);
                root->setImage(media(8));
                root->setText(str(13));
                makeActBtn("forest_field",act(2));
            }
        }
    }
    if(action == "forest_field")
    {
        metka = action;
        root->setImage(media(9));
        root->setText(str(14));
        if(root->vJob(graze_cow) == 1)
        {
            if(root->getHour() < 19)
            {
                makeActBtn("graze_cow",act(7));
                if(root->getSunWeather() >= 0 && root->vEvent(mira) == 0)
                {
                    if(root->vEvent(daybegskver) != root->vStatus(daystart))
                        makeActBtn("run_field",act(8));
                    if(root->getTemp()>= 20)
                    {
                        makeActBtn("sunbathe",act(9));
                        if(root->vStatus(son) < 17)
                            makeActBtn("sleep",act(10));
                        makeActBtn("flowers",act(11));
                        if(root->vEvent(book_in_bag) >= 0)
                            makeActBtn("read_book",act(13) + root->getBookName(root->vEvent(book_in_bag)));
                    if(root->vQuest(miraQW) >= 15 && root->vEvent(mira) == 0 && getRandInt(1,5)==1 && root->vEvent(Mira_no)==0 && (root->vEvent(mitkasextimes) < 13 || root->vQuest(miragopQW) >= 10 || root->vEvent(mirasex) > 1) && root->vEvent(miraday) != root->getDay())
                            gadfield_mira();
                    }
                }
            }
            else
            {
                root->incTime(60);
                root->vEvent(mira) = 0;
                root->vJob(graze_cow) = 0;
                root->vEvent(grandmahelp) += 1;
                root->vQuest(grandpaQW) +=1;
                root->setImage(media(10));
                root->setText(str(15));
                makeActBtn("gadukino",act(2));
            }
        }
    }
    if(action == "Miroslava")
    {
        root->startEvent(eMiroslava);
    }
    if(action == "take_cow_home")
    {
        root->incTime(60);
        root->vEvent(grandmahelp) += getRandInt(0,1);
        root->vQuest(grandpaQW) += getRandInt(0,1);
        root->setImage(media(11));
        root->setText(str(8));
        makeActBtn("gadsarai",act(2));
    }
    if(action == "field_wait_cows")
    {
        root->incTime(120);
        //hour = 10
        root->setImage(media(12));
        root->setText(str(9));
        makeActBtn("graze_field",act(2));
    }
    if(action == "graze_cow")
    {
        root->incTime(60);
        root->vJob(graze_cow_exp) = 1;
        root->vEvent(grandmahelp) += 1;
        root->setImage(media(13));
        root->setText(str(16));
        makeActBtn("backtometka",act(2));
    }
    if (action == "run_field")
    {
        root->incTime(60);
        root->vStatus(mood) += 15;
        root->vStatus(day_weight) -= 1;
        root->vSkill(runner) += getRandInt(3,6);
        root->fnSport(2);
        if(root->vSkill(speed) < 40)
            root->vSkill(speed) += 1;
        else
            root->vSkill(speed) += getRandInt(0,1);
        if(root->vSkill(endurance) < 20)
            root->vSkill(endurance) += 1;
        root->vEvent(daybegskver) = root->vStatus(daystart);
        root->setImage(media(14));
        root->setText(str(17));
        makeActBtn("backtometka",act(2));
    }
    if(action == "sunbathe")
    {
        root->incTime(30);
        root->vStatus(mood) += 10;
        if(root->getSunWeather() <= 2)
        {
            if(root->getCloth(ClothType::Main) == nullptr)
                root->vBody(skinTan) += 1;
            else
                root->vBody(skinTan) += getRandInt(0,1);
        }
        else
        {
            if(root->getCloth(ClothType::Main) == nullptr)
                root->vBody(skinTan) += 2;
            else
                root->vBody(skinTan) +=1;
        }
        root->vBody(hairStatus) = 1;
        if(root->getTemp() > 22 && root->getTemp() < 30)
            root->vStatus(sweat) +=1;
        else if(root->getTemp() >= 30)
            root->vStatus(sweat) += 2;
        root->setImage(media(15));
        root->setText(str(18));
        makeActBtn("backtometka",act(2));
    }
    if(action == "sleep")
    {
        root->incTime(60);
        root->vStatus(mood) += 10;
        root->vStatus(son) += 4;
        root->setImage(media(16));
        root->setText(str(19));
        makeActBtn("backtometka",act(2));
    }
    if(action == "flowers")
    {
        root->incTime(60);
        root->vStatus(mood) += 20;
        root->setImage(media(17));
        root->setText(str(20));
        makeActBtn("backtometka",act(2));
    }
    if(action == "swim")
    {
        root->incTime(30);
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        if(root->vSkill(strenght) < 20)
            root->vSkill(strenght) +=1;
        if(root->getTemp() <= 25)
            root->vStatus(horny) -= 10;
        else
            root->vStatus(horny) -=5;
        root->vStatus(mood) += 10;
        root->setImage(media(18));
        root->setText(str(21));
        makeActBtn("backtometka",act(2));
    }
    if(action == "backtometka")
    {
        actionHandler(metka);
    }
    if(action == "read_book")
    {
        root->readOnWalk();
    }
}

void Gadfield::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "gadfield");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Gadfield::actionHandler);
    root->addActions(btn);
}

void Gadfield::gadfield_mira()
{
    root->incTime(5);
    root->vQuest(miraQW) += 1;
    root->vEvent(mira) = 1;
    root->vEvent(miraday) = root->getDay();
    root->setImage(media(19));
    root->setText(str(22));
    makeActBtn("backtometka",act(2));
}

QString Gadfield::str(int id)
{
    QString add;
    if(root->vJob(graze_cow)==0)
        add = "graze_field";
    else
    {
        if(root->getHour() < 13)
            add= "graze_field";
        else if(root->getHour() < 16)
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
    if(root->vEvent(mira) == 1)
        str[7] += "<br>Рядом с вами сидит <a href='Miroslava'>Мира</a>.";
    str[8] = "Увидев стадо в поле, вы решили помочь дедушке, и отвести Зорьку домой..";
    str[9] = "В течение некоторого времени вы ждете, пока все местные пригонят своих коров";
    if(root->vJob(graze_cow_exp) != 0)
        str[9] += " и придет дед с Зорькой.";
    str[10] = "Посмотрев на часы, дедушка казал, что уже обед и пора гнать стадо на водопой. Вместе вы принялись поднимать лежащих коров, направляя их в сторону реки.";
    str[11] = "Стадо деревенских коров стоит у реки.";
    if(root->vEvent(mira) == 1)
        str[11] += "<br>Рядом с вами сидит <a href='Miroslava'>Мира</a>.";
    str[12] = "<br>- Можешь искупнуться внучка, пока есть время. Я пригляжу за стадом, - сказал вам дедушка.";
    str[13] = "Посмотрев на часы, дедушка казал, что пора гнать стадо обратно на поле, но теперь ближе к лесу. Вместе вы принялись собирать разбредшихся и стоящих в воде коров и направлять в сторону леса.";
    str[14] = "Стадо деревенских коров стоит на поле возле леса.";
    if(root->vEvent(mira) == 1)
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
    QString str[14];
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
    str[13] = "Читать ";
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
    if(root->vEvent(mira) == 1)
        med[14] += "_mira";
    med[14] += ".jpg";
    med[15] = "data/locations/gadukino/gadfield/graze_cow_sun";
    if(root->vEvent(mira) == 1)
        med[15] += "_mira2";
    med[15] += ".jpg";
    med[16] = "data/locations/gadukino/gadfield/graze_cow_lying.jpg";
    med[17] = "data/locations/gadukino/gadfield/graze_cow_flowers.jpg";
    med[18] = "data/locations/gadukino/gadfield/graze_cow_river";
    if(root->vEvent(mira) == 1)
        med[18] += "_mira";
    med[18] += ".jpg";
    med[19] = "data/sex/mira/Mira2.jpg";
    return med[id];
}
