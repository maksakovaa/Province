#include "beach.h"
#include "../../game.h"
#include "../../Functions.h"
#include "bathroom.h"
#include "../../menu/buttons.h"

Beach::Beach(Game *ptr): root(ptr) {}

void Beach::check_people()
{
    root->vEvent(lake_people) = 0;
    int month = root->getMonth();
    int SunWeather = root->getSunWeather();
    bool isday = root->isDay();
    int temp = root->getTemp();
    int week = root->getWeek();
    int hour = root->getHour();

    if(month > 4 && month < 10 && SunWeather >= 2 && isday)
    {
        if(temp < 20)
            root->vEvent(lake_people) = 1;
        else if(week >= 1 && week <= 5)
        {
            if(root->getHour() < 17)
                root->vEvent(lake_people) = 2;
            else
                root->vEvent(lake_people) = 3;
        }
        else
        {
            if(temp <= 25)
                root->vEvent(lake_people) = 3;
            else
                root->vEvent(lake_people) = 4;
        }
    }

    if(root->vEvent(lake_people) > 2 && (hour == root->getSunrise() || hour == root->getSunrise() + 1 || hour == root->getSunset() || hour == root->getSunrise() - 1))
        root->vEvent(lake_people) -= 1;
}

void Beach::walk()
{
    root->incTime(30);
    root->vStatus(mood) += 5;
    ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
    QString ext = "";
    if(ptr != nullptr && ptr->getClothGroup() > swimsuit)
        ext = ".jpg";
    if(ptr != nullptr && ptr->getClothGroup() == swimsuit)
        ext = "_swim.jpg";
    else
        ext = "_nude.jpg";
    QString add;
    if(root->getCurLoc() == llake)
        add = "lake";
    if(root->getCurLoc() == lglake)
        add = "glake";
    root->setImage("data/locations/common/beach/walk_" + add + ext);
    root->setText(str(0));
    makeActBtn("back_to_loc",act(0));
    if(root->getCurLoc() == llake && getRandInt(0,10) == 0)
    {
        //gt'lake_event','walklake'
    }
}

void Beach::undress(int arg)
{
    if(arg == 1)
    {
        if(root->vStatus(shamelessFlag) >= 1 || root->vEvent(lake_people) < 2)
        {
            if(root->vStatus(horny) >= 90)
            {
                if(root->vStatus(shamelessFlag) > 1  /*||  func('zz_reputation','get')|| */ || root->vEvent(lake_people) < 3)
                {
                    nude();
                }
                else
                {
                    QString i;
                    if(root->getCloth(ClothType::Panties) == nullptr) i = "0.jpg";
                    else i = "1.jpg";
                    root->setImage("data/locations/common/beach/wetpussy" + i);
                    root->setText(str(1));
                    makeActBtn("back_to_loc",act(0));
                }
            }
            else nude();
        }
        else
        {
            root->setImage("data/locations/common/beach/shyness.jpg");
            root->setText(str(2));
            makeActBtn("back_to_loc",act(0));
        }
    }
    else
    {
        if(root->vStatus(horny) >= 90)
        {
            if(root->vStatus(shamelessFlag) > 1 /*||  func('zz_reputation','get')|| */ || root->vEvent(lake_people) < 3)
                wearswimsuit();
            else
            {
                root->setImage("data/locations/common/beach/wetpussypants.jpg");
                root->setText(str(3));
                makeActBtn("back_to_loc",act(0));
            }
        }
        else
            wearswimsuit();
    }
}

void Beach::wearswimsuit()
{
    root->incTime(5);
    storeClothes();
    root->redress(ClothType::Main,new ClothMain(2,swimsuit,"Купальник"));
    if(root->getCurLoc() == lgadbeach)
    {
        root->vStatus(inriver) = 1;
        root->setImage("data/locations/common/beach/swimsuit_gadbeach.jpg");
        root->setText(str(4));
    }
    else
    {
        QString add = "",loc = "";
        if(root->vStatus(shamelessFlag) < 2)
            add = intQStr(root->vStatus(shamelessFlag)) + ".jpg";
        else
            add = "2.jpg";
        if(root->getCurLoc() == llake)
            loc = "lake";
        else if(root->getCurLoc() == lnudelake)
            loc = "nudelake";
        else if(root->getCurLoc() == lglake)
            loc = "glake";
        else if(root->getCurLoc() == lglakenude)
            loc = "glakenude";
        root->setImage("data/locations/common/beach/swimsuit_" + loc + add);
        root->setText(str(5));
    }
    makeActBtn("back_to_loc",act(0));
}

void Beach::nude()
{
    if(root->getCurLoc() == lgadbeach)
        root->vStatus(inriver) = 1;
    root->incTime(5);
    root->redress(ClothType::Main,nullptr);
    QString loc;
    if(root->getCurLoc() == lnudelake)
        loc = "nudelake";
    else if(root->getCurLoc() == lglakenude)
        loc = "glakenude";
    else if(root->getCurLoc() == lgadbeach)
        loc = "gadbeach";
    root->setImage("data/locations/common/beach/undress_" + loc + ".jpg");
    root->setText(str(6));
    makeActBtn("back_to_loc", act(0));
}

void Beach::getDressed(int arg)
{
    root->incTime(5);
    root->redressOld();
    if(root->getCurLoc() == lgadbeach)
    {
        QString add;
        if(arg == 1)
            add = "dress_";
        else
            add = "swimsuit_";
        root->setImage("data/locations/common/beach/" + add + "gadbeach.jpg");
        root->setText(str(7));
    }
    else
    {
        if(arg == 1)
        {
            QString loc;
            if(root->getCurLoc() == lglakenude)
                loc = "glakenude";
            if(root->getCurLoc() == lnudelake)
                loc = "nudelake";
            root->setImage("data/locations/common/beach/dress_" + loc + ".jpg");
        }
        else
        {
            QString loc;
            if(root->getCurLoc() == lglake)
                loc = "glake";
            if(root->getCurLoc() == lglakenude)
                loc = "glakenude";
            if(root->getCurLoc() == llake)
                loc = "lake";
            if(root->getCurLoc() == lnudelake)
                loc = "nudelake";

            if(root->vStatus(shamelessFlag) < 2)
                root->setImage("data/locations/common/beach/swimsuit_" + loc + intQStr(root->vStatus(shamelessFlag)) + ".jpg");
            else
                root->setImage("data/locations/common/beach/swimsuit_" + loc + intQStr(2) + ".jpg");
        }
        root->setText(str(8));
    }
    makeActBtn("back_to_loc",act(0));
}

void Beach::swim()
{
    if(root->vEvent(lake_people) < 2 && root->vAddict(alko) >= 10)
    {
        root->startEvent(eGameOver, "4");
    }
    root->incTime(30);
    ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
    if(root->vSkill(strenght) < 20)
        root->vSkill(strenght) += 1;
    if(root->getTemp() <= 25)
        root->vStatus(horny) -= 10;
    else
        root->vStatus(horny) -= 5;
    root->vStatus(mood) += 10;
    if(root->getCurLoc() == lgadbeach && root->vEvent(mirainriver) == 1)
    {
        if(root->getCloth(ClothType::Main) == nullptr)
            root->setImage("data/locations/common/beach/swim_mira_nude" + intQStr(getRandInt(1,3)) + ".jpg");
        else
            root->setImage("data/locations/common/beach/swim_mira" + intQStr(getRandInt(1,3)) + ".jpg");
        root->setText(str(9));
    }
    else
    {
        QString loc = getLocIdStr(root->getCurLoc());
        // if(root->getCurLoc() == lglake)
        //     loc = "glake";
        // if(root->getCurLoc() == lglakenude)
        //     loc = "glakenude";
        // if(root->getCurLoc() == llake)
        //     loc = "lake";
        // if(root->getCurLoc() == lnudelake)
        //     loc = "nudelake";
        if(root->getCloth(ClothType::Main) == nullptr)
            root->setImage("data/locations/common/beach/swim_" + loc + "_nude" + intQStr(getRandInt(1,3)) + ".jpg");
        else
            root->setImage("data/locations/common/beach/swim_" + loc + intQStr(getRandInt(1,3)) + ".jpg");
        root->setText(str(10));
    }
    if(root->getCurLoc() == lglake && root->getCloth(ClothType::Main) == nullptr)
    {
        root->vStatus(mood) -= 10;
        root->addText(str(11));
        //gs 'zz_reputation','edit', rand(-1,0)
    }
    ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
    if(root->getCurLoc() == lglakenude && root->vEvent(lake_people) > 1 &&  ptr != nullptr && ptr->getClothGroup() == swimsuit && root->vStatus(shamelessFlag) < 3)
    {
        root->vStatus(mood) -= 10;
        root->addText(str(12));
    }
    makeActBtn("check_n_back",act(1));
}

void Beach::sunbathe(int isCream)
{
    ClothMain* clothPtr = (ClothMain*)root->getCloth(ClothType::Main);
    root->incTime(30);
    if(clothPtr == nullptr)
        root->vStatus(mood) += 10;
    else
        root->vStatus(mood) += 5;
    if(root->getTemp() > 22 && root->getTemp() < 30)
        root->vStatus(sweat) += 1;
    if(root->getTemp() >= 30)
        root->vStatus(sweat) += 2;
    root->vBody(hairStatus) = 1;
    int tanInc = 0;
    if(root->getSunWeather() < 2)
    {
        if(clothPtr != nullptr)
        {
            if(isCream == 1)
                tanInc = 1;
            else
                tanInc = getRandInt(0,1);
        }
        else
        {
            if(isCream == 1)
                tanInc = 2;
            else
                tanInc = 1;
        }
    }
    else
    {
        if(clothPtr != nullptr)
        {
            if(isCream == 1)
                tanInc = 2;
            else
                tanInc = 1;
        }
        else
        {
            if(isCream == 1)
                tanInc = 4;
            else
                tanInc =3;
        }
    }
    root->vBody(skinTan) += tanInc;
    int var{0};
    if(isCream == 1)
        var = getRandInt(4,6);
    else
        var = getRandInt(1,3);

    QString add;
    if(clothPtr == nullptr)
        add = "_nude";
    QString loc;
    if(root->getCurLoc() == lgadbeach)
        loc = "gadbeach";
    if(root->getCurLoc() == lglake)
        loc = "glake";
    if(root->getCurLoc() == lglakenude)
        loc = "glakenude";
    if(root->getCurLoc() == llake)
        loc = "lake";
    if(root->getCurLoc() == lnudelake)
        loc = "nudelake";
    if(root->getCurLoc() == lgadbeach && root->vEvent(mirainriver) == 1)
    {
        root->setImage("data/locations/common/beach/sunbathe_mira" + add + intQStr(getRandInt(1,3)) + ".jpg");
        root->setText(str(13));
    }
    else
    {
        root->setImage("data/locations/common/beach/sunbathe_" + loc + add + intQStr(var) + ".jpg");
        root->setText(str(14));
    }
    if(root->getCurLoc() == lglake && clothPtr == nullptr)
    {
        root->vStatus(mood) -= 10;
        root->addText(str(11));
        //gs 'zz_reputation','edit', rand(-1,0)
    }

    if(root->getCurLoc() == lglakenude && root->vEvent(lake_people) > 1 && clothPtr != nullptr && clothPtr->getClothGroup() == swimsuit)
    {
        root->vStatus(mood) -= 10;
        root->addText(str(12));
    }

    if(root->getCurLoc() == lglakenude && root->vEvent(lake_people) > 1)
    {
        //gs'glake_events','voyeurism_start'
    }

    makeActBtn("checkAndGo",act(2));
}

void Beach::cream()
{
    LocId loc = root->getCurLoc();
    root->incTime(5);
    root->useItem(iSunscreen,1);
    if(root->getCloth(ClothType::Main) == nullptr)
        root->vStatus(horny) += 10;
    else
        root->vStatus(horny) += 5;
    QString image = "data/locations/common/beach/cream";
    if(root->getCloth(ClothType::Main) == nullptr)
    {
        image += "_nude";
        if(root->vEvent(lake_people) <= 2 || loc == lgadbeach)
            image += "1";
        else
        {
            if(root->vEvent(lake_people) == 3)
                image += "2";
            else
                image += "3";
        }
    }
    else
        image += intQStr(getRandInt(1,3));
    image += ".jpg";
    root->setImage(image);
    root->setText(str(15));
    makeActBtn("sunbathe+cream",act(3));
}

void Beach::actionHandler(QString action)
{
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc(),0);
    }
    if(action == "check_n_back")
    {
        if(root->getCurLoc() == lgadbeach)
        {
            root->startEvent(eRiverEvents,"swim_guys");
        }
        root->changeLoc(root->getCurLoc(),0);
    }
    if(action == "checkAndGo")
    {
        LocId loc = root->getCurLoc();
        if(loc == llake)
        {
            // gs'lake_event','din_lake_adventure'
        }
        if(loc == lnudelake)
        {
            //gs'lake_event','din_nudelake_adventure'
        }
        if(loc == lglake)
        {
            //gs'glake_events','din_beach_adventure'
        }
        if(loc == lgadbeach)
        {
            root->startEvent(eRiverEvents,"sunbathe_guys");
        }
        actionHandler("back_to_loc");
    }
    if(action == "sunbathe+cream")
    {
        sunbathe(1);
    }
}

void Beach::storeClothes()
{
    ClothMain* mainCloth = (ClothMain*)root->getCloth(ClothType::Main);
    if(mainCloth != nullptr && mainCloth->getClothGroup() > swimsuit)
        cloth = mainCloth;
    if(root->getCloth(ClothType::Panties) != nullptr)
        panties = root->getCloth(ClothType::Panties);
    if(root->getCloth(ClothType::Stockings) != nullptr)
        stock = root->getCloth(ClothType::Stockings);
}

void Beach::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action, "beach");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Beach::actionHandler);
    root->addActions(btn);
}

QString Beach::str(int id)
{
    QString str[20];
    str[0] = "Вы гуляете по берегу, наслаждаясь свежим воздухом.";
    str[1] = "Вы хотите полностью раздеться, но понимаете, что все увидят влагу, сочащуюся из вашей писечки. От мысли, что всем это будет хорошо видно, вам становится не по себе и вы отказываетесь от этой идеи.<br><dh>— Наверное стоит как-нибудь снять напряжение</dh>, — думаете вы.";
    str[2] = "У вас появляется желание раздеться полностью, но вы не можете побороть свою стеснительность.";
    str[3] = "Вы хотите переодеться в купальник, но понимаете, что ваша сочащаяся писечка тут же его намочит. От мысли, что люди могут это заметить, вам становится не по себе и вы отказываетесь от этой идеи.<br><dh>— Наверное стоит как-нибудь снять напряжение</dh>, — думаете вы.";
    str[4] = "Вы снимаете свою одежду, и надеваете купальник. Теперь можно спокойно идти купаться и загорать.";
    if(root->vStatus(shamelessFlag) == 0)
    {
        str[5] = "Вы заходите в ";
        if(root->getCurLoc() == llake)
            str[5] += "пляжную кабинку";
        else
            str[5] += "ближайшие кустики";
        str[5] += "и переодеваетесь в купальник";
    }
    else if(root->vStatus(shamelessFlag) == 1)
    {
        str[5] = "Убедившись, что на вас никто не смотрит, вы быстренько переодеваетесь в купальник";
    }
    else
    {
        str[5] = "Не обращая ни на кого внимания, на виду у всех";
        if(root->getCurLoc() == llake)
            str[5] += "прикрывшись только полотенцем,";
        str[5] += "вы переодеваетесь в купальник";
    }
    str[5] += "<br>Теперь можно спокойно идти купаться и загорать.";
    str[6] = "Вы не стесняясь раздеваетесь, оставшись в чем мать родила.";
    if(root->vStatus(horny) >= 90 && root->vEvent(lake_people) > 2)
        str[6] += "Проходящие мимо мужчины заинтересовано рассматривают вашу сочащуюся вагину. Но вам уже наплевать на то, что скажут или подумают о вас люди.";
    str[7] = "Вы сняли купальник, и переодеваетесь в свою одежду.";
    if(root->vStatus(shamelessFlag) == 0)
    {
        str[8] = "Вы заходите в ";
        if(root->getCurLoc() == llake)
            str[8] += "пляжную кабинку";
        else
            str[8] += "ближайшие кустики";
        str[8] += "и переодеваетесь в свою одежду.";
    }
    else if (root->vStatus(shamelessFlag) == 1)
    {
        str[8] = "Убедившись, что на вас никто не смотрит, вы быстренько переодеваетесь в свою одежду";
    }
    else
    {
        str[8] = "Не обращая ни на кого внимания, на виду у всех";
        if(root->getCurLoc() == llake)
            str[8] += "прикрывшись только полотенцем,";
        str[8] += " вы переодеваетесь в свою одежду.";
    }
    str[9] = "Вы искупнулись в речушке, весело брызгаясь с Мирой, друг на дружку, водой.";
    str[10] = "Вы искупнулись в озере, вода освежает и бодрит.";
    str[11] = "Вы слышите как женщины вокруг вас шушукаются, что мол вон, гляди какая бестыжая Лебедева, совсем совесть потеряла, а мужики пристально разглядывают ваше обнаженное тело.";
    str[12] = "<b>Вы чувствуете себя неловко, будучи в купальнике, в окружении совершенно обнажённых людей.</b>";
    str[13] = "Вы лежите рядом с Мирой на песке и болтая о пустяках, ";
    if(root->getSunWeather() >= 2)
        str[13] += "млеете на солнце.";
    else
        str[13] += "загораете. На небе облачно, поэтому загар не очень.";
    str[14] = "Вы загораете на пляже";
    if(root->getSunWeather() >= 2)
        str[13] += ", нежась в лучах солнца.";
    else
        str[13] += ". На небе облачно, поэтому загар не очень.";
    str[15] = "Вы намазали тело кремом для загара.";
    return str[id];
}

QString Beach::act(int id)
{
    QString act[4];
    act[0] = "Назад";
    act[1] = "Выйти из воды";
    act[2] = "Далее";
    act[3] = "Загорать полчаса";
    return act[id];
}
