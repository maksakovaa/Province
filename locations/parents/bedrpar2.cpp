#include "bedrpar2.h"
#include "../../menu/buttons.h"
#include "../locationhandler.h"
#include "../../Functions.h"

BedrPar2::BedrPar2(LocationHandler* ptr): Location(ptr) {}

void BedrPar2::show(QString arg)
{
    if(arg.isEmpty())
        actionHandler("main");
    else
        actionHandler(arg);
}

LocId BedrPar2::getLocId()
{
    return lbedrpar2;
}

LocId BedrPar2::getParId()
{
    return lkorrpar;
}

LocId BedrPar2::getLocIn()
{
    return lgorodok;
}

QString BedrPar2::getLocName()
{
    return act(1);
}

bool BedrPar2::isParent()
{
    return true;
}

void BedrPar2::makeActBtn(QString act, QString actName)
{
    QActButton* btn = new QActButton(act, "BedrPar2");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &BedrPar2::actionHandler);
    addActBtn(btn);
}

void BedrPar2::actionHandler(QString action)
{
    if(action == "main")
        main();
    if(action == "kamasutra")
        kamasutra();
    if(action == "momtoy_play")
        momtoy_play();
    if(action == "xgb_album")
        xgb_album();
    if(action == "read_book")
        read_book();
    if(action == "parents_wardrobe")
        parents_wardrobe();
    if(action == "wardrobe_search")
        wardrobe_search();
    if(action == "kamasutra_page_back")
    {
        uVSex(kamasutra_page,-1);
        read_book();
    }
    if(action == "kamasutra_page_next")
    {
        uVSex(kamasutra_page,1);
        read_book();
    }
    if(action == "korrPar")
        changeLoc(lkorrpar,0);
    if(action == "bedrPar2")
        changeLoc(lbedrpar2,0);
    if(action == "selfplay")
        startSelfPlay();
    if(action == "still_condoms")
    {
        incTime(getRandInt(5,7));
        addItem(iCondoms,getRandInt(1,3));
        sVSex(condomday,getDay());
        sVSex(condomProver,0);
        setImage(media(getRandInt(3,4)));
        setDesc(str(5));
        if(getRandInt(1,7) != 1)
            makeActBtn("korrPar",act(17));
        else
            makeActBtn("father_notations",act(18));
    }
    if(action == "father_notations")
    {
        setImage(media(5));
        setDesc(str(32));
        incTime(getRandInt(10,20));
        makeActBtn("father_notations_end",act(0));
    }
    if(action == "father_notations_end")
    {
        changeLoc(lkorrpar,getRandInt(10,20));
    }
    if(action == "open_album")
    {
        i = 0;
        uVSex(xgb_viewalbum,1);
        view_album();
    }
    if(action == "view_album_next")
    {
        i++;
        view_album();
    }
}

QString BedrPar2::str(int id)
{
    QString str[40];
    str[1] = "На кровати спят мать и отчим.";
    str[2] = "На кровати спит ваша мать.";
    str[3] = "Комната, в которой живут родители. В центре стоит двухспальная кровать и ";
    if((getHour() > 8 && getHour() < 16) || (gVEvent(family_trip_month) != getMonth() && (getWeekNum() == 6 || getWeekNum() == 0)))
        str[3] += "<a href='parents_wardrobe'>большой шкаф</a>";
    else
        str[3] += "большой шкаф";
    str[3] += " у стены.";
    str[4] = "На кровати лежит какая-то <a href='kamasutra'>книга</a>";
    str[5] = "Вы незаметно достаёте из родительского схрона несколько презервативов. Теперь их у вас " + intQStr(getItemCount(iCondoms)) + " штук.";
    str[6] = "Вы недавно уже брали презервативы из родительского схрона. Если их часто таскать, то родители могут что-то заподозрить.";
    str[7] = "На обложке написано \"Камасутра\"";
    str[8] = "Пора валить, а то родители застукают...";
    if(gVSex(kamasutra_page) < 1)
        str[9] = "<center>";
    else
        str[9] = "<center><a href=kamasutra_page_back>Предыдущая страница</a>";
    if(gVSex(kamasutra_page) > 45)
        str[9] += "</center>";
    else
        str[9] += "<a href=kamasutra_page_next'>Следующая страница</a></center>";
    str[10] = "Старый советский шкаф";
    str[11] = "Вам не удалось найти ничего интересного";
    str[12] = "Здесь одна одежда и нижнее бельё";
    str[13] = "Вы покопались в шкафу, но ничего кроме нижнего белья матери не нашли";
    str[14] = "Копаясь в шкафу, вы неожиданно нашли небольшой <a href='momtoy_play'>дилдо</a>";
    str[15] = "В ящике с нижним бельём матери находится вдруг упрятанный под лифчиками и трусами маленький <a href='momtoy_play'>дилдо</a>"
              "<br>\"Однако!\" - думаете вы про себя. - \"Запомним!\"";
    str[16] = "Вы нашли мамину <a href='momtoy_play'>игрушку</a>";
    str[17] = "Проходя мимо комнаты родителей, вы вдруг слышите оттуда странные звуки.";
    str[18] = "Вы, конечно, догадываетесь, что может происходить за дверью - вы же взрослая девочка, но вас смутил тот факт, что отчим "
              "обычно по понедельникам на складе в городе затаривается, возя оттуда на своей \"Газельке\" в Павлово что закажут, и домой"
              " возвращается обычно к полуночи и замотанный.";
    str[19] = "Поддавшись соблазну любознательности, вы решили посмотреть, что происходит за дверью.";
    str[20] = "Подкравшись на цыпочках, вы тихонько поворачиваете дверную ручку, и приоткрыв дверь, приникаете глазом к щёлке.";
    str[21] = ", и замираете от увиденного: ваша мама, раскинувшись на кровати абсолютно голой, яростно сношает себя фаллоимитатором,"
              " закатывая глаза от наслаждения и тихо постанывая.";
    str[22] = ". \"Папочка из дому - мама в рукопашную\" - иронически усмехаетесь вы про себя, наблюдая, как мама яростно яростно "
              "самозабвенно вгоняет в себя силиконовый \"заменитель мужика\", охая и тяжело дыша.";
    str[23] = "В дальнем углу, на самом дне вы видите <a href='xgb_album'>корешок какой-то кожаной книги</a>";
    str[24] = "В дальнем углу, на самом дне вы видите <a href='xgb_album'>мамин фотоальбом</a>";
    str[25] = "Дорогой кожаный фотоальбом. Что такого дорогого и запретного хранит в нём мама?";
    str[26] = "<hero>Разное думала… Но чтоб такое!!!</hero>";
    str[27] = "<hero>Кошмар!!! Моя мама… падшая женщина!!!</hero>";
    str[28] = "<hero>Хм… А мамуля-то затейница!!!</hero>";
    str[29] = "<hero>Это её отчим фотал?! Прикольно!</hero>";
    str[30] = "<hero>Я тоже так хочу!!!</hero>";
    str[31] = "<hero>Хмм, занимательнаю игрушечку я у мамы раздобыла!</hero>";
    str[32] = "<hero>Слушать нотации отца...(Нужен текст)</hero>";
    return str[id];
}

QString BedrPar2::act(int id)
{
    QString act[19];
    act[0] = "Кивнуть и выйти";
    act[1] = "Спальня родителей";
    act[2] = "Смотреть";
    act[3] = "Отойти";
    act[4] = "Стащить у родителей презервативы";
    act[5] = "Выйти из комнаты";
    act[6] = "Мастурбировать";
    act[7] = "Рыться в вещах";
    act[8] = "Отойти";
    act[9] = "Закрыть шкаф";
    act[10] = "Отойти";
    act[11] = "Закрыть дверь";
    act[12] = "Поиграться";
    act[13] = "Закрыть";
    act[14] = "Положить на место";
    act[15] = "Посмотреть!";
    act[16] = "Смотреть еще";
    act[17] = "Тихонько выйти из комнаты";
    act[18] = "Слушать нотации отца";
    return act[id];
}

QString BedrPar2::media(int id)
{
    QString med[50];
    med[0] = "data/npc/pavlovo/parents/parents_sleep.jpg";
    med[1] = "data/npc/pavlovo/parents/mother_sleep.jpg";
    med[2] = "data/locations/pavlovo/parents_home/bedr_par.jpg";
    med[3] = "data/img/items/bedrPar2/hand_gandon0.jpg";
    med[4] = "data/img/items/bedrPar2/hand_gandon1.jpg";
    med[5] = "data/npc/pavlovo/parents/vernost-otcu.jpg";
    med[6] = "data/img/items/bedrPar2/book.jpg";
    med[7] = "data/img/items/kamasutra/ik";
    med[8] = "data/img/items/bedrPar2/wardrobe.jpg";
    med[9] = "data/img/items/bedrPar2/wardrobesearch1.jpg";
    med[10] = "data/img/items/bedrPar2/wardrobesearch2.JPG";
    med[11] = "data/img/items/bedrPar2/wardrobesearch3.JPG";
    med[12] = "data/img/items/bedrPar2/wardrobesearch4.JPG";
    med[13] = "data/img/items/bedrPar2/wardrobetoy.jpg";
    med[14] = "data/sex/mother_selfplay/selfplay0.webm";
    med[15] = "data/sex/mother_selfplay/selfplay1.webm";
    med[16] = "data/sex/mother_selfplay/selfplay2.webm";
    med[17] = "data/sex/mother_selfplay/selfplay3.webm";
    med[18] = "data/sex/mother_selfplay/selfplay4.webm";
    med[19] = "data/img/items/xgb_album/album.jpg";
    med[20] = "data/img/items/xgb_album/";
    med[21] = "data/img/items/xgb_album/wow.jpg";
    med[22] = "data/img/items/xgb_album/reaction0.jpg";
    med[23] = "data/img/items/xgb_album/reaction1.jpg";
    med[24] = "data/img/items/xgb_album/reaction2.jpg";
    med[25] = "data/img/items/xgb_album/reaction3.jpg";
    return med[id];
}

void BedrPar2::main()
{
    makeActBtn("korrPar",act(5));
    int hour = getHour();
    if(hour == 21 && gVEvent(father_horny) >= 70 && gVEvent(family_trip) == 0)
        startEvent(eSeeParentSex);
    incTime(1);
    if((hour >= 21 || hour < 6) && gVEvent(family_trip) == 0)
    {
        int week = getWeekNum();
        if(week != 1)
        {
            setImage(media(0));
            setDesc(str(1));
        }
        else
        {
            if(gVEvent(parentSexDay) == getDay())
            {
                setImage(media(1));
                setDesc(str(2));
            }
            else
                mom_selfplay();
        }
    }
    else
    {
        setImage(media(2));
        setDesc(str(3));
    }
    startEvent(eFamily, "mother_sheduler");
    if(gNPC(NatalyaLebedeva).location == lbedrpar2 && (getClothGroup() <= swimsuit || gVAddict(alko) >= 6))
    {
        startEvent(eMother);
        return;
    }
    if(hour > 7 && hour < 21 && gNPC(NatalyaLebedeva).location != lbedrpar2)
    {
        if(gVSex(kamasutra_day) != getDay())
            addText(str(4));
        if(gVSex(condomday) != getDay())
        {
            if(gVSex(condomProver) >= 3)
            {
                sVSex(condomday, getDay() - 4);
                makeActBtn("still_condoms",act(4));
            }
            else
                addText(str(6));
        }
    }
}

void BedrPar2::kamasutra()
{
    incTime(1);
    sVSex(kamasutra_day,getDay());
    sVSex(kamasutra_page,0);
    setImage(media(6));
    setDesc(str(7));
    makeActBtn("read_book",act(2));
    makeActBtn("bedrPar2",act(3));
}

void BedrPar2::momtoy_play()
{
    sVSex(dildoHand,10);
    sVSex(selfmomtoyplay,1);
    setImage(media(13));
    setDesc(str(31));
    if(gVStatus(horny) >= 70)
        makeActBtn("selfplay",act(12));
    makeActBtn("bedrPar2",act(10));
}

void BedrPar2::xgb_album()
{
    setImage(media(19));
    setDesc(str(25));
    makeActBtn("open_album",act(15));
    makeActBtn("bedrPar2",act(14));
}

void BedrPar2::view_album()
{
    if(i == 0)
    {
        QString place[6] {"kitchen1_","kitchen2_","kitchen3_","park1_","park2_","park3_"};
        int num[6] {37,44,49,32,17,16};
        int n = getRandInt(0,5);
        string = place[n];
        maxval = num[n] - 1;
        i = getRandInt(0, maxval);
    }
    setImage(media(20) + string + intQStr(i) + ",jpg");
    incTime(1);
    uVStatus(horny,getRandInt(1,3));
    if(i < maxval)
        makeActBtn("view_album_next",act(16));
    makeActBtn("view_album_end",act(14));
}

void BedrPar2::view_album_end()
{
    i = 0;
    string = "";
    maxval = 0;
    if(gVSex(xgb_viewalbum) == 1)
    {
        setImage(media(21));
        setDesc(str(26));
    }
    else
    {
        setImage(media(22 + gVStatus(shamelessFlag)));
        setDesc(str(27 + gVStatus(shamelessFlag)));
    }
    makeActBtn("bedrPar2",act(3));
}

void BedrPar2::read_book()
{
    uVStatus(horny,2);
    incTime(3);
    setImage(media(7) + intQStr(gVSex(kamasutra_page)) + ".jpg");
    if((getHour() == 20 && getMin() > 50) || getHour() == 21)
        setDesc(str(8));
    else
    {
        setDesc(str(9));
        if(gVStatus(horny) >= 60 && getWeekNum() == 6 && gVEvent(family_trip) == 1)
            makeActBtn("selfplay",act(6));
    }
    makeActBtn("bedrPar2",act(13));
}

void BedrPar2::mom_selfplay()
{
    rendVideoPage();
    setVideo(media(getRandInt(14,18)),960,540);
    setDesc(str(17));
    if(gVSC(voyeurism) > 0)
        addText(str(18));
    else
        addText(str(19));
    addText(str(20));
    if(gVSex(momSelfplay) == 0)
        addText(str(21));
    else
        addText(str(22));
    sVSex(momSelfplay,1);
    sVEvent(parentSexDay,getDay());
    uVStatus(horny,getRandInt(10,20));
    incTime(getRandInt(2,5));
    makeActBtn("korrPar",act(11));
}

void BedrPar2::parents_wardrobe()
{
    setImage(media(8));
    setDesc(str(10));
    makeActBtn("wardrobe_search",act(7));
    makeActBtn("bedrPar2",act(8));
}

void BedrPar2::wardrobe_search()
{
    if(getRandInt(1,100) > 75)
    {
        setImage(media(getRandInt(9,12)));
        setDesc(str(getRandInt(11,13)));
    }
    else
    {
        setImage(media(13));
        setDesc(str(getRandInt(14,16)));
        if(gVEvent(xgb_findalbum) == 0)
        {
            sVEvent(xgb_findalbum,1);
            addText(str(23));
        }
        else
            addText(str(24));
    }
    makeActBtn("bedrPar2",act(9));
}
