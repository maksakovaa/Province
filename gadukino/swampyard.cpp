#include "swampyard.h"
#include "../Functions.h"
#include "../menu/buttons.h"

SwampYard::SwampYard(LocationHandler* ptr): Location(ptr) {}

void SwampYard::show(QString arg)
{
    actionHandler("swamp_yard");
}

LocId SwampYard::getLocId()
{
    return lswampyard;
}

LocId SwampYard::getLocIn()
{
    return lgadukino;
}

QString SwampYard::getLocName()
{
    return "Поляна с избушкой";
}

LocId SwampYard::getParId()
{
    return lswamp;
}

bool SwampYard::isParent()
{
    return true;
}

void SwampYard::actionHandler(QString action)
{
    if(action == "swamp_yard")
    {
        if(getWeekNum() == 6 || getWeekNum() == 0)
            sVEvent(hantersrand,getRandInt(1,3));
        if(getWeekNum() > 0 && getWeekNum() < 6)
            sVEvent(hantersrand, getRandInt(1,5));
        if(gVEvent(hantersrand) == 1)
            sVEvent(hanters,1);
        sVEvent(hantslutsexrand, getRandInt(1,3));

        if(gVEvent(lost_girl) == 0)
            sVEvent(lost_girl, getRandInt(40,60));

        setImage(makeImage(media(0),isDay(),getMonth()));
        setDesc(str(0));

        if(gVEvent(findvel) == 3)
            addText(str(1));

        if(gVStatus(clearClothes) > 0 && gVStatus(clearclothesH) == 0)
            addText(str(2));

        if(gVEvent(hanters) > 0 && gVEvent(hantersKnow) == 0)
            addText(str(3));
        if(gVEvent(hanters) > 0 && gVEvent(hantersKnow) > 0 && getHour() >= 8 && getHour() < 20)
            addText(str(4));

        makeActBtn("swamphouse",act(0));

        if(gVEvent(dirty_swamp_yard) > 10)
            makeActBtn("clearswampyard",act(1));

        makeActBtn("go_swamp",act(2));
        //Охотники спасли ГГ из болота
        if(gVEvent(hantershelp) == 1)
        {
            incTime(5);
            if(!isNude())
                setImage(media(1));
            else
                setImage(media(2));
            if(isNude())
            {
                if(gVEvent(hantersKnow) == 0)
                    addText(str(5));
                if(gVEvent(hantersKnow) == 1 && gVEvent(hantersKnowSlut) == 0)
                    addText(str(6));
                if(gVEvent(hantersKnow) == 1 && gVEvent(hantersKnowSlut) == 1)
                    addText((str(7)));
            }
            if(gVEvent(hantersKnow) == 0)
            {
                addText(str(8));
                makeActBtn("watch_around",act(3));
            }
            if(gVEvent(hantersKnow) == 1)
            {
                addText(str(9));
                makeActBtn("next",act(4));
            }
        }

        if(gVEvent(hantershelp) == 2 && gVEvent(hantersKnow) == 0)
        {
            incTime(5);
            sVEvent(hantersKnow,1);
            uVQuest(hantersAndreiQW,1);
            uVQuest(hantersIgorQW,1);
            uVQuest(hantersSergeiQW,1);
            if(isCloth())
            {
                setImage(media(3));
                setDesc(str(12));
                if(gVStatus(vnesh) >= 40)
                    addText(str(13));
                if(gVStatus(vnesh) < 40)
                    addText(str(14));
                addText(str(15));
                if(gVEvent(gadriver_gang) == 0)
                {
                    addText(str(16));
                    if(gVStatus(sweat) > 0 || gVStatus(dirtyClothes) > 0)
                    {
                        addText(str(17));
                    }
                    else
                        addText(str(18));
                }
                else
                {
                    addText(str(19));
                    if(gVStatus(sweat) > 3 || gVStatus(dirtyClothes) == 1)
                    {
                        sVEvent(hantersKnowSlut,1);
                        sVEvent(hantersRape,1);
                        addText(str(20));
                    }
                    else
                    {
                        sVEvent(hantersKnowSlut,1);
                        sVEvent(hantersRape,1);
                        addText(str(21));
                    }
                }
            }
            else
            {
                setImage(media(4));
                setDesc(str(22));
                if(gVEvent(gadriver_gang) == 0)
                {
                    addText(str(23));
                    if(gVStatus(sweat) > 0)
                        addText(str(24));
                    else
                        addText(str(25));
                }
                else
                {
                    addText(str(19));
                    if(gVStatus(sweat) > 0)
                    {
                        sVEvent(hantersKnowSlut,1);
                        sVEvent(hantersRape,1);
                        addText(str(26));
                    }
                    else
                    {
                        sVEvent(hantersKnowSlut,1);
                        sVEvent(hantersRape,1);
                        addText(str(27));
                    }
                }
            }
            if(isNude() && gVEvent(hantersKnowSlut) == 0)
            {
                makeActBtn("get_out1",act(7));
                makeActBtn("sit_down1",act(8));
            }
            else
            {
                makeActBtn("get_out2",act(7));
                makeActBtn("sit_down2",act(8));
            }

        }
        tmp = getRandInt(1,10);
        //просьба охотников по уборке в доме
        if(gVEvent(hanters) > 0 && gVEvent(hantersKnow) == 1 && getHour() >= 8 && getHour() < 20 && gVEvent(dirty_swamphouse) > 5 && tmp == 2)
        {
            tmp = getRandInt(1,3);
            incTime(5);

            if(tmp == 1)
            {
                boy = act(9);
                setImage(media(5));
            }
            if(tmp == 2)
            {
                boy = act(10);
                setImage(media(6));
            }
            if(tmp == 3)
            {
                boy = act(11);
                setImage(media(7));
            }
            setDesc(str(28) + boy);
            if(gVEvent(hantersKnowSlut) == 0)
                addText(str(29));
            if(gVEvent(hantersKnowSlut) == 1)
                addText(str(30));
            makeActBtn("clean_house",act(12));
            if(gVEvent(hantersKnowSlut) == 0)
                makeActBtn("discard",act(13));
        }
        //просьба охотников по уборке во дворе
        if(gVEvent(hanters) > 0 && gVEvent(hantersKnow) == 1 && getHour() >= 8 && getHour() < 20 && gVEvent(dirty_swamp_yard) > 5 && tmp == 3)
        {
            tmp = getRandInt(1,3);
            incTime(5);

            if(tmp == 1)
            {
                boy = act(9);
                setImage(media(5));
            }
            if(tmp == 2)
            {
                boy = act(10);
                setImage(media(6));
            }
            if(tmp == 3)
            {
                boy = act(11);
                setImage(media(7));
            }
            setDesc(str(28) + boy);
            if(gVEvent(hantersKnowSlut) == 0)
                addText(str(31));
            if(gVEvent(hantersKnowSlut) == 1)
                addText(str(32));
            makeActBtn("clearswampyard",act(14));
            if(gVEvent(hantersKnowSlut) == 0)
                makeActBtn("discard",act(13));
        }
        //разговор охотников, если ГГ снималась в порно, в фотостудии, танцевала стриптиз или шлюха в Гадюкино
        if(gVEvent(hanters) > 0 && gVEvent(hantersKnowSlut) == 0 && gVEvent(hantersKnow) == 1 && gVEvent(hanters_check) == 0 && getHour() >= 8 && getHour() < 20)
        {
            if(gVSC(modelfoto) > 0 && gVEvent(hantersknowfoto) == 0 && gVEvent(hantersIgorLove) == 0)
            {
                incTime(5);
                uVEvent(hanterslut,5);
                sVEvent(hanters_check,1);
                sVEvent(hantersknowfoto,1);
                setImage(media(8));
                setDesc(str(35));
                makeActBtn("swamp_yard",act(4));
            }
            else if(gVSC(stripDanceSum) > 0 && gVEvent(hantersknowstrip) == 0 && gVEvent(hantersSergeiLove) == 0)
            {
                incTime(5);
                uVEvent(hanterslut,10);
                sVEvent(hanters_check,1);
                sVEvent(hantersknowstrip,1);
                setImage(media(8));
                setDesc(str(36));
                makeActBtn("swamp_yard",act(4));
            }
            else if(gVSC(film) > 0 && gVEvent(hantersknowfilm) == 0 && gVEvent(hantersAndreiLove) == 0)
            {
                incTime(5);
                uVEvent(hanterslut,15);
                sVEvent(hanters_check,1);
                sVEvent(hantersknowstrip,1);
                setImage(media(8));
                setDesc(str(37));
                makeActBtn("swamp_yard",act(4));
            }
            else if(gVEvent(gadriver_gang) > 0)
            {
                incTime(5);
                sVEvent(hanters_check,1);
                sVEvent(hantersRape,1);
                setImage(media(8));
                setDesc(str(38));
                makeActBtn("swamp_yard",act(4));
            }
        }
        //если ГГ голая и на поляне есть охотники
        if(isNude() && gVEvent(hantershelp) == 0 && gVEvent(hanters) == 1 && getHour() >= 8 && getHour() < 20 && gVEvent(hanterknowday) != getDay())
        {
            if(gVEvent(hantersKnowSlut) == 0)
            {
                setImage(media(9));
                setDesc(str(39));
                if(gVStatus(clothesswamphouse) == 1 && gVStatus(clearClothes) == 0)
                    makeActBtn("dress1",act(15));
                else
                    makeActBtn("dress2",act(15));
                makeActBtn("stay_nude",act(16));

            }
            if(gVEvent(hantersKnowSlut) > 0)
            {
                if(gVEvent(hantslutsex) == 0)
                {
                    setImage(media(10));
                    setDesc(str(43));
                    makeActBtn("hantersSexNude",act(4));
                }
                else
                {
                    sVEvent(hanterknowday, getDay());
                    setImage(media(10));
                    setDesc(str(44));
                    makeActBtn("swamp_yard",act(4));
                }
            }
        }
        //разговор после пьяного стриптиза и траха ГГ с охотниками
        if(gVEvent(hantdanceslut) == 1 && getHour() >= 8 && getHour() < 20)
        {
            incTime(5);
            setImage(media(5));
            setDesc(str(45));
            makeActBtn("agree",act(17));
            if(gVSkill(domination) > 0 && gVAddict(alko) < 8)
                makeActBtn("disagree",act(13));
        }
        //разговор после изнасилования ГГ охотниками
        if(gVEvent(hantersRape) == 4 && getHour() >= 8 && getHour() < 20)
        {
            incTime(5);
            sVEvent(hantersKnowSlut,2);
            sVEvent(hantersRape,5);
            setImage(media(5));
            setDesc(str(46));
            makeActBtn("swamp_yard",act(7));
        }
        if(gVEvent(hanters) > 0 && getHour() >= 8 && getHour() < 20)
        {
            //признание в любви Игоря
            if(gVEvent(hantersIgorLove) == 0 && gVQuest(hantersIgorQW) >= 35 && gVEvent(hantersKnowSlut) == 0 /*&& bfA < 1 */ && gVStatus(vnesh) >= 40)
            {
                incTime(10);
                setImage(media(7));
                setDesc(str(47));
                makeActBtn("IgorHanter",act(4));
            }
            //секс с Игорем
            if(gVEvent(hantersIgorLove) > 0 && gVQuest(hantersIgorQW) >= 10 && tmp == 4 && gVEvent(hantersIgorsex) == 0)
            {
                incTime(5);
                sVEvent(hantersIgorsex, getRandInt(12,36));
                setImage(media(11));
                setDesc(str(48));
                makeActBtn("igor_agree_sex",act(17));
                makeActBtn("igor_disagree_sex",act(13));
            }
            //цветы от Игоря
            if(gVEvent(hantersKnowSlut) == 0 && isCloth() && gVQuest(hantersIgorQW) >= 20 && tmp == 5 && gVEvent(flowersday) != getDay())
            {
                incTime(5);
                uVStatus(horny,5);
                sVEvent(flowersday,getDay());
                setImage(media(12));
                setDesc(str(51));
                makeActBtn("accept_igorflowers",act(19));
                makeActBtn("decline_igorflowers",act(13));
            }
            //общение с Сергеем
            if(gVEvent(hantersKnowSlut) == 0 && isCloth() && gVQuest(hantersSergeiQW) >= 15 && tmp == 6 && gVEvent(hantersSergeiday) != getDay())
            {
                incTime(5);
                sVEvent(hantersSergeiday,getDay());
                setImage(media(6));
                setDesc(str(56));
                makeActBtn("talk_sergei",act(17));
                makeActBtn("donttalk_sergei",act(13));
            }
            //секс с Сергеем
            if(gVEvent(hantersSergeiLove) > 0 && gVQuest(hantersSergeiQW) >= 10 && tmp == 7 && gVEvent(hantersSergeisex) == 0)
            {
                incTime(5);
                sVEvent(hantersSergeisex,getRandInt(9,30));
                setImage(media(11));
                setDesc(str(59));
                makeActBtn("segrei_agree_sex",act(17));
                makeActBtn("sergei_disagree_sex",act(13));
            }
            //секс с Андреем
            if(gVEvent(hantersAndreiLove) > 0 && gVQuest(hantersAndreiQW) >= 10 && tmp == 8 && gVEvent(hantersAndreisex) == 0)
            {
                incTime(5);
                sVEvent(hantersAndreisex,getRandInt(6,24));
                setImage(media(11));
                setDesc(str(62));
                makeActBtn("andrei_agree_sex",act(20));
                makeActBtn("andrei_disagree_sex",act(13));
            }
            //секс если ГГ шлюха
            if(gVEvent(hantersRape) == 5 && gVEvent(hantslutsexrand) == 1 && gVEvent(hantslutsex) == 0)
            {
                incTime(5);
                sVEvent(temphant,getRandInt(1,3));
                sVEvent(slutgosex,1);
                if(gVEvent(temphant) == 1)
                {
                    setImage(media(5));
                    setDesc(str(65));
                }
                else if(gVEvent(temphant) == 2)
                {
                    setImage(media(6));
                    setDesc(str(66));
                }
                else if(gVEvent(temphant) == 3)
                {
                    setImage(media(7));
                    setDesc(str(67));
                }
                if(gVStatus(horny) < 40)
                    addText(str(68));
                else if(gVStatus(horny) >= 40 && gVStatus(horny) < 70)
                    addText(str(69));
                else if(gVStatus(horny) >= 70)
                    addText(str(70));
                makeActBtn("hanters",act(18));
            }
            //выбор межды любовниками
            if(gVEvent(hantersAndreiLove) > 0 && gVEvent(hantersSergeiLove) > 0 && tmp == 1)
            {
                setImage(media(13));
                setDesc(str(71));
                if(gVEvent(hanterslut) >= 10)
                    addText(str(72));
                addText(str(73));
                makeActBtn("chooseSergei1",act(21));
                makeActBtn("chooseAndrei1",act(22));
                if(gVEvent(hanterslut) >= 10)
                    makeActBtn("chooseBothAS1",act(23));
                makeActBtn("chooseNoOne1",act(24));
            }
            if(gVEvent(hantersAndreiLove) > 0 && gVEvent(hantersIgorLove) > 0 && tmp == 1)
            {
                setImage(media(13));
                setDesc(str(78));
                if(gVEvent(hanterslut) >= 10)
                    addText(str(72));
                addText(str(73));
                makeActBtn("chooseIgor1",act(25));
                makeActBtn("chooseAndrei2",act(22));
                if(gVEvent(hanterslut) >= 10)
                    makeActBtn("chooseBothAS2",act(23));
                makeActBtn("chooseNoOne2",act(24));
            }
            if(gVEvent(hantersSergeiLove) > 0 && gVEvent(hantersIgorLove) > 0 && tmp == 1)
            {
                incTime(15);
                setImage(media(13));
                setDesc(str(83));
                makeActBtn("chooseSergei2",act(21));
                makeActBtn("chooseIgor2",act(25));
                makeActBtn("chooseNoOne3",act(24));
            }
            //трио ГГ, Андрей и Сергей, если любовь
            if(gVEvent(doublehanterlove) == 1 && (gVEvent(hantersAndreisex) == 0 || gVEvent(hantersSergeisex) == 0))
            {
                incTime(5);
                sVEvent(hantersAndreisex,getRandInt(6,24));
                sVEvent(hantersSergeisex,getRandInt(9,30));
                setImage(media(13));
                setDesc(str(87));
                makeActBtn("go_with_AS",act(26));
                makeActBtn("decline_go_with_AS",act(13));
            }
            int skirtsrand = getRandInt(1,10);
            if(gVEvent(hantersKnow) > 0 && isSkirt() && !isPanties() && skirtsrand == 1)
            {
                incTime(15);
                uVEvent(hanterslut,1);
                setImage(media(14));
                setDesc(str(89));
                makeActBtn("swamp_yard",act(4));
            }
            //трио если ГГ шлюха
            if(gVEvent(hantersRape) == 5 && gVEvent(hantslutsexrand) == 2 && gVEvent(hantslutsex) == 0)
            {
                incTime(5);
                sVEvent(temphant,getRandInt(1,3));
                sVEvent(slutgosex,2);
                setImage(media(13));
                setDesc(str(90));
                if(gVEvent(temphant) == 1)
                    addText(str(91));
                if(gVEvent(temphant) == 2)
                    addText(str(92));
                if(gVEvent(temphant) == 3)
                    addText(str(93));
                if(gVStatus(horny) < 40)
                    addText(str(68));
                else if(gVStatus(horny) >= 40 && gVStatus(horny) < 70)
                    addText(str(69));
                else if(gVStatus(horny) >= 70)
                    addText(str(70));
                makeActBtn("go_with_guys",act(26));
            }
        }
        if(gVEvent(lost_girl) < 10)
        {
            incTime(150);
            sVEvent(lost_girl,0);
            sVEvent(hanters,0);
            sVEvent(goswamp,1);
            sVEvent(forester,1);
            setImage(media(15));
            setDesc(str(95));
            makeActBtn("gadhouse",act(4));
        }
    }
    if(action == "swamphouse")
    {
        changeLoc(lswamphouse,5);
    }
    if(action == "clearswampyard")
    {
        uVEvent(hanterslut,-1);
        int dirty = gVEvent(dirty_swamp_yard);
        if(dirty < 10)
        {
            incTime(60);
            uVStatus(sweat,1);
        }
        else if(dirty >= 10 && dirty < 20)
        {
            incTime(120);
            uVStatus(sweat,2);
        }
        else if(dirty >= 20)
        {
            incTime(180);
            uVStatus(sweat,3);
        }
        if(gVQuest(hantersAndreiQW) < 15)
            uVQuest(hantersAndreiQW,1);
        if(gVQuest(hantersIgorQW) < 15)
            uVQuest(hantersIgorQW,1);
        if(gVQuest(hantersSergeiQW) < 15)
            uVQuest(hantersSergeiQW,1);
        setImage(media(16));
        setDesc(str(10));
        sVEvent(dirty_swamp_yard,0);
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "go_swamp")
    {
        if(gVEvent(hanters) == 1)
        {
            if(getHour() >= getSunrise() && getHour() < getSunset())
            {
                changeLoc(lswamp,5);
            }
            else
            {
                setImage(media(7));
                setDesc(str(11));
                makeActBtn("swamp_yard",act(5));
                makeActBtn("swamp",act(6));
            }
        }
        else
            actionHandler("swamp");
    }
    if(action == "swamp")
    {
        changeLoc(lswamp,5);
    }
    if(action == "watch_around")
    {
        sVEvent(hantershelp,2);
        actionHandler("swamp_yard");
    }
    if(action == "next")
    {
        sVEvent(hantershelp,0);
        actionHandler("swamp_yard");
    }

    if(action == "clean_house")
    {
        getLocPtr(lswamphouse)->show("dirty_swamphouse");
    }
    if(action == "discard")
    {
        incTime(5);
        uVEvent(hanterslut,1);
        uVSkill(domination,1);
        if(tmp == 1)
            uVQuest(hantersAndreiQW,-1);
        if(tmp == 2)
            uVQuest(hantersSergeiQW,-1);
        if(tmp == 3)
            uVQuest(hantersIgorQW,-1);
        setImage(media(17));
        setDesc(str(33) + boy + str(34));
        makeActBtn("swamp_yard",act(4));
    }

    if(action == "dress1")
    {
        sVStatus(clothesswamphouse,0);
        incTime(5);
        getLocPtr(lswamphouse)->show("wearCloth");
        setImage(media(18));
        setDesc(str(40));
        makeActBtn("swamphouse",act(4));
    }
    if(action == "dress2")
    {
        incTime(5);
        sVStatus(swamp_clothes,1);
        getLocPtr(lswamphouse)->show("wearCloth");
        setImage(media(19));
        setDesc(str(41));
        makeActBtn("swamphouse",act(4));
    }
    if(action == "stay_nude")
    {
        uVEvent(hanterslut,1);
        sVEvent(hanterknowday,getDay());
        setImage(media(10));
        setDesc(str(42));
        makeActBtn("swamp_yard",act(4));
    }

    if(action == "hantersSexNude")
    {
        sVEvent(hantersexnude,1);
        startEvent("hanters");
    }
    if(action == "agree")
    {
        sVEvent(hantdanceslut,2);
        startEvent("hanters");
    }
    if(action == "disagree")
    {
        sVEvent(hantdanceslut,3);
        startEvent("hanters");
    }

    if(action == "igor_agree_sex")
    {
        incTime(5);
        uVQuest(hantersIgorQW,1);
        uVStatus(horny,5);
        setImage(media(20));
        setDesc(str(49));
        makeActBtn("HanterLoveSex",act(18));
    }
    if(action == "igor_disagree_sex")
    {
        incTime(5);
        uVQuest(hantersIgorQW,-1);
        setImage(media(17));
        setDesc(str(50));
        makeActBtn("swamp_yard",act(18));
    }
    if(action == "accept_igorflowers")
    {
        incTime(5);
        uVEvent(hanterslut,-1);
        uVQuest(hantersIgorQW,1);
        if(gVQuest(hantersAndreiQW) >= 10 && gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersAndreiQW,-2);
        if(gVQuest(hantersSergeiQW) >= 10 && gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersSergeiQW,-2);
        sVStatus(mood,100);
        if(gVEvent(hantersIgorLove) == 0 && gVQuest(hantersIgorQW) >= 20 && gVQuest(hantersIgorQW) < 25)
        {
            if(isSkirt())
                setImage(media(21));
            if(!isSkirt())
                setImage(media(22));
            setDesc(str(52));
        }
        if((gVEvent(hantersIgorLove) == 0 && gVQuest(hantersIgorQW) >= 25) || gVEvent(hantersIgorLove) > 0)
        {
            if(isSkirt())
                setImage(media(23));
            if(!isSkirt())
                setImage(media(24));
            setDesc(str(53));
        }
        if(gVEvent(hantersIgorLove) == 0 && gVQuest(hantersIgorQW) >= 30)
        {
            setImage(media(25));
            setDesc(str(54));
        }
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "decline_igorflowers")
    {
        incTime(5);
        uVQuest(hantersIgorQW,-2);
        setImage(media(17));
        setDesc(str(55));
        makeActBtn("swamp_yard",act(4));
    }

    if(action == "talk_sergei")
    {
        incTime(120);
        uVEvent(hanterslut,-1);
        uVQuest(hantersSergeiQW,1);
        if(gVQuest(hantersIgorQW) >= 10 && gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersIgorQW,-2);
        if(gVQuest(hantersAndreiQW) >= 10 && gVEvent(hantersKnowSlut) == 0)
            uVQuest(hantersAndreiQW,-2);
        sVStatus(mood,100);
        setImage(media(26));
        setDesc(str(57));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "donttalk_sergei")
    {
        incTime(5);
        uVQuest(hantersSergeiQW,-2);
        setImage(media(17));
        setDesc(str(58));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "segrei_agree_sex")
    {
        incTime(5);
        uVStatus(horny,5);
        uVQuest(hantersSergeiQW,1);
        setImage(media(20));
        setDesc(str(60));
        makeActBtn("HanterLoveSex",act(18));
    }
    if(action == "sergei_disagree_sex")
    {
        incTime(5);
        uVQuest(hantersSergeiQW,-1);
        setImage(media(17));
        setDesc(str(61));
        makeActBtn("swamp_yard",act(18));
    }

    if(action == "andrei_agree_sex")
    {
        incTime(5);
        uVStatus(horny,5);
        uVQuest(hantersAndreiQW,1);
        setImage(media(27));
        setDesc(str(63));
        makeActBtn("HantersLoveSex",act(4));
    }
    if(action == "andrei_disagree_sex")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,-1);
        setImage(media(17));
        setDesc(str(64));
        makeActBtn("swamp_yard",act(18));
    }

    if(action == "chooseSergei1")
    {
        incTime(5);
        sVEvent(hantersAndreiLove,0);
        sVQuest(hantersAndreiQW,-100);
        sVEvent(hanterslut,-1);
        setImage(media(6));
        setDesc(str(76));
        makeActBtn("swamp_yard", act(4));
    }
    if(action == "chooseAndrei1")
    {
        incTime(5);
        sVEvent(hantersSergeiLove,0);
        sVQuest(hantersSergeiQW,-100);
        sVEvent(hanterslut,-1);
        setImage(media(5));
        setDesc(str(77));
        makeActBtn("swamp_yard", act(4));
    }
    if(action == "chooseBothAS1")
    {
        incTime(5);
        uVEvent(hanterslut,10);
        sVEvent(doublehanterlove,1);
        setImage(media(28));
        setDesc(str(75));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "chooseNoOne1")
    {
        incTime(5);
        sVEvent(hantersAndreiLove,0);
        uVQuest(hantersAndreiQW,-50);
        sVEvent(hantersSergeiLove,0);
        uVQuest(hantersSergeiQW,-50);
        uVEvent(hanterslut,-1);
        setImage(media(29));
        setDesc(str(74));
        makeActBtn("swamp_yard",act(4));
    }

    if(action == "chooseIgor1")
    {
        incTime(5);
        sVEvent(hantersAndreiLove,0);
        sVQuest(hantersAndreiQW,-100);
        sVEvent(hanterslut,-1);
        setImage(media(7));
        setDesc(str(79));
        makeActBtn("swamp_yard", act(4));
    }
    if(action == "chooseAndrei2")
    {
        incTime(5);
        sVEvent(hantersIgorLove,0);
        sVQuest(hantersIgorQW,-100);
        sVEvent(hanterslut,-1);
        setImage(media(5));
        setDesc(str(80));
        makeActBtn("swamp_yard", act(4));
    }
    if(action == "chooseBothAS2")
    {
        incTime(5);
        sVEvent(hantersIgorLove,0);
        uVQuest(hantersIgorQW,-100);
        uVEvent(hanterslut,1);
        setImage(media(28));
        setDesc(str(81));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "chooseNoOne2")
    {
        incTime(5);
        sVEvent(hantersAndreiLove,0);
        uVQuest(hantersAndreiQW,-50);
        sVEvent(hantersIgorLove,0);
        uVQuest(hantersIgorQW,-50);
        uVEvent(hanterslut,-1);
        setImage(media(29));
        setDesc(str(82));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "chooseSergei2")
    {
        incTime(5);
        sVEvent(hantersIgorLove,0);
        sVQuest(hantersIgorQW,-100);
        uVEvent(hanterslut,-1);
        setImage(media(6));
        setDesc(str(84));
        makeActBtn("swamp_yard", act(4));
    }
    if(action == "chooseIgor2")
    {
        incTime(5);
        sVEvent(hantersSergeiLove,0);
        sVQuest(hantersSergeiQW,-100);
        sVEvent(hanterslut,-1);
        setImage(media(7));
        setDesc(str(85));
        makeActBtn("swamp_yard",act(4));
    }
    if(action == "chooseNoOne3")
    {
        incTime(5);
        sVEvent(hantersSergeiLove,0);
        uVQuest(hantersSergeiQW,-50);
        sVEvent(hantersIgorLove,0);
        uVQuest(hantersIgorQW,-50);
        uVEvent(hanterslut,-1);
        setImage(media(29));
        setDesc(str(86));
        makeActBtn("swamp_yard",act(4));
    }

    if(action == "go_with_AS")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,1);
        uVQuest(hantersSergeiQW,1);
        uVStatus(horny,5);
        sVEvent(doublelovesex,1);
        uVEvent(hanterslut,1);
        sVEvent(temphant,1);
        setImage(media(30));
        makeActBtn("hantersex",act(4));
    }
    if(action == "decline_go_with_AS")
    {
        incTime(5);
        uVQuest(hantersAndreiQW,-1);
        uVQuest(hantersSergeiQW,-1);
        setImage(media(17));
        setDesc(str(88));
        makeActBtn("swamp_yard", act(18));
    }

    if(action == "go_with_guys")
    {
        incTime(5);
        uVStatus(horny,5);
        setImage(media(30));
        setDesc(str(94));
        makeActBtn("hantersex",act(4));
    }
    //A HREF LINKS
    if(action == "swampspring")
    {
        changeLoc(lswampspring,5);
    }
    if(action == "backwater")
    {
        changeLoc(lbackwater,5);
    }
    if(action == "bicycle")
    {
        startEvent("bicycle", "swamp");
    }
    if(action == "hanters")
    {
        startEvent("hanters");
    }
    if(action == "IgorHanter")
    {
        startEvent("IgorHanter");
    }
    if(action == "HanterLoveSex")
    {
        startEvent("HanterLoveSex");
    }
    if(action == "hantersex")
    {
        startEvent("hantersex");
    }
}

void SwampYard::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SwampYard::actionHandler);
    addActBtn(btn);
}

QString SwampYard::str(int id)
{
    QString str[96];
    str[0] = "Поляна с избушкой посреди болота.<br>За избушкой есть <a href='swampspring'>родник</a>, а немного дальше есть небольшая"
             " <a href='backwater'>заводь</a> с относительно чистой водой.";
    str[1] = "Возле избушки стоит старый <a href='bicycle'>велосипед</a>.";
    str[2] = "На поляне сушится ваша одежда.";
    str[3] = "На поляне вы видите незнакомых <a href='hanters'>людей</a>.";
    str[4] = "На поляне вы видите знакомых <a href='hanters'>охотников</a>.";
    str[5] = "- Ну нифига себе мы русалку выловили! - услышали вы чей-то удивлённый голос.";
    str[6] = "- Света, опять ты голышом бегаешь по лесу! - покачал головой Андрей.";
    str[7] = "- О! Опять наша шлюшка в сети попалась, и в самом потребном виде! - заржал Андрей.";
    str[8] = "Вас отволокли на сухое место. Какое-то время вы ничего не соображали, просто тупо смотрели перед собой и пытались отдышаться."
             " Немного отдохнув вы решаете все таки узнать куда вы попали и кто вас спас.";
    str[9] = "Вас отволокли на сухое место. Какое-то время вы ничего не соображали, просто тупо смотрели перед собой и пытались отдышаться."
             " Немного отдохнув вы отправились на поляну перед избушкой.";
    str[10] = "Выйдя в очередной раз на поляну перед избушкой, вы заметили, сколько там накопилось разного мусора и грязи.<br>\"С этим "
              "нужно что-то делать\", - подумали вы и принялись за уборку двора. Через некоторое врямя двор сиял первозданной чистотой.";
    str[11] = "Вы собрались идти в лес, когда вас окликнул Игорь.<br>- Света, это не самое лучшее время чтобы ходить по лесу, переночуй лучше тут.";
    str[12] = "Вы увидели трех мужчин, которые переговаривались между собой. Увидев, что вы более или менее пришли в себя, они подошли к вам поближе.";
    str[13] = "- Ну что, оклемалась чутка? Как звать-величать то тебя, красавица? - спросил один из них.";
    str[14] = "- Ну что, оклемалась чутка? Как звать-величать то тебя? - спросил один из них.";
    str[15] = "- Света, - ответили вы.";
    str[16] = "- А я Андрей, - ответил ответил мужчина постарше, - а это друзья мои из центра, Игорь и Сергей."
            "- А твоя фамилия не Лебедева случайно? - спросил он. Вы удивленно посмотрели на него и кивнули."
            "- Не удивляйся Света, ты очень похожа на маму в молодости. А я её ... Хммм... очень хорошо знал когда-то, я ведь тоже из Гадюкино. - сказал Андрей.";
    str[17] = "- Ты иди пока помойся и постирай одежку, а то грязная совсем, - продолжил Андрей."
                "- А где?"
                "- Ну летом, пока тепло помыться можно и в затоне, что за избушкой, а можно и в ней самой. Тазик там есть, воду возьмешь в "
              "роднике и нагреешь на печке, - ответил Андрей. - А вот в холода только в избушке и можно."
                "- Постираться можно в избушке. Опять же, вода в роднике, греешь на печке и стираешь, - продолжил он, - Можно конечно и в заводи,"
              " но там только слегка отчиститься получится.";
    str[18] = "- Да ты не стесняйся, присаживайся, в ногах правды нет, - сказал Сергей, освобождая для вас место.";
    str[19] = "- Ба, кого к нам занесло, - удивлённо протянул мужчина постарше, - это же Света Лебедева, местная шлюшка."
              "Вы удивленно посмотрели на него."
            "- Не удивляйся, я ведь тоже из Гадюкино, а ты очень похожа на маму в молодости, и судя по всему такая же блядоватая, - сказал он."
            "- Я Андрей, - добавил он дальше, - а это друзья мои из центра, Игорь и Сергей.";
    str[20] = "- Ты иди пока помойся и постирай одежку, а то грязная совсем, как кикимора болотная... смотреть противно, - продолжил Андрей. - А мы пока подумаем,"
              " как с тобой быть."
                "- А где?"
                "- Ну летом, пока тепло помыться можно и в затоне, что за избушкой, а можно и в ней самой. Тазик там есть, воду возьмешь в роднике и нагреешь на печке,"
              " - ответил Андрей. - А вот в холода только в избушке и можно."
                "- Постираться можно в избушке. Опять же, вода в роднике, греешь на печке и стираешь, - продолжил он, - Можно конечно и в заводи, но там только слегка"
              " отчиститься получится.";
    str[21] = "- Да ты не стесняйся, присаживайся, в ногах правды нет, - сказал Сергей, с ехидной улыбкой освобождая для вас место.";
    str[22] = "Вы увидели трех мужчин, которые переговаривались между собой. Увидев, что вы более или менее пришли в себя, они направились в вашу сторону. Вы сообразив,"
              " что находитесь совершенно голая перед тремя незнакомыми мужчинами тихонько ойкнув начали прикрываться руками, незная куда деваться от стыда."
            "- Очухалась? - спросил один из них и протянул вам кусок какой-то ткани. - На вот прикройся, нечего нас смущать своими прелестями."
            "- Как звать-величать тебя, красавица? - спросил другой."
            "- Света, - ответили вы.";
    str[23] = "- А я Андрей, - ответил ответил мужчина постарше, - а это друзья мои из центра, Игорь и Сергей."
            "- А твоя фамилия не Лебедева случайно? - спросил он. Вы удивленно посмотрели на него и кивнули."
              "- Не удивляйся Света, ты очень похожа на маму в молодости. А я её... Хммм... очень хорошо знал когда-то, я ведь тоже из Гадюкино, - сказал Андрей.";
    str[24] = "- Ты иди пока помойся, а мы тебе пока одежку какую подыщем, - продолжил Андрей."
                "- А где?"
                "- Ну летом, пока тепло можно и в затоне, что за избушкой, а можно и в ней самой. Тазик там есть, воду возьмешь в роднике и нагреешь на печке,"
              " - продолжил Андрей, - А вот в холода только в избушке и можно.";
    str[25] = "- Да ты не стесняйся, присаживайся,в ногах правды нет, - сказал Сергей, освобождая для вас место. - А мы тебе пока одежку какую подыщем.";
    str[26] = "- Ты иди пока помойся, нечего тут на всю поляну вонять, - продолжил Андрей, - А мы пока подумаем, как с тобой быть."
                "- А где?"
                "- Ну летом, пока тепло можно и в затоне, что за избушкой, а можно и в ней самой. Тазик там есть, воду возьмешь в роднике и нагреешь на печке,"
              " - продолжил Андрей, - А вот в холода только в избушке и можно.";
    str[27] = "- Да ты не стесняйся, присаживайся,в ногах правды нет, - сказал Сергей, освобождая для вас место, - Подумаем, как с тобой быть.";
    str[28] = "Вы шли по своим делам, когда к вам подошел ";
    str[29] = "- Светик, - сказал он. - В доме такой бардак, может уберешься? А то нам с парнями все некогда.";
    str[30] = "- Света, - сказал он. - В доме такой бардак, иди-ка наведи там марафет.";
    str[31] = "- Светик, - сказал он. - Во дворе такой бардак, может наведешь порядок? А то нам с парнями все некогда.";
    str[32] = "- Света, - сказал он. - Во дворе такой бардак, иди-ка убери мусор.";
    str[33] = "Не, ";
    str[34] = ", мне некогда, - ответили вы ему. - И вообще, сами намусорили, сами и убирайте.";
    str[35] = "Появившись на поляне вы увидели парней, что-то возбужденно обсуждавших."
            "- Я её фотки видел в мужском журнале, точно вам говорю, - услышали вы возбужденный голос Игоря. Потом, заметив вас, парни замолчали и перевели "
              "разговор на другую тему.";
    str[36] = "Появившись на поляне вы увидели парней, что-то возбужденно обсуждавших."
            "- Я её видел, точно вам говорю, - услышали вы возбужденный голос Сергея, - она там на сцене танцевала."
            "Потом, заметив вас, парни замолчали и перевели разговор на другую тему.";
    str[37] = "Появившись на поляне вы увидели парней, что-то возбужденно обсуждавших."
            "- Я недавно порнуху скачал, она там снималась, точно вам говорю, это " + getPFName() + ", - услышали вы возбужденный голос Андрея. Потом, "
                              "заметив вас, парни замолчали и перевели разговор на другую тему.";
    str[38] = "Появившись на поляне вы увидели парней, что-то возбужденно обсуждавших."
            "- Я точно вам говорю, она всем в Гадюкино дает, сам недавно её \"тестировал\", - услышали вы возбужденный голос Андрея. Потом, заметив вас,"
              " парни замолчали и перевели разговор на другую тему.";
    str[39] = "Увидев во дворе мужчин, вы ойкнув, принялись прикрываться руками...";
    str[40] = "И, сломя голову, кинулись в избушку одеваться.";
    str[41] = "И быстро кинулись в избушку и прикрылись куском мешковины... Ну хоть что-то.";
    str[42] = "Но потом решили пощекотать себе нервы и оставили все как есть. Мужчины старательно отводят глаза от вашего обнаженного тела.<br>";
    if(gVEvent(hantersKnow) == 1)
        str[42] += "- Ну ты, Светик, блин даешь, - услышали вы только фразу Андрея.";
    else
        str[42] += "- Ни фига себе картина!, - услышали вы только удивлённый возглас.";
    str[43] = "Увидев вас голую, парни возбудились..."
            "- Ну все Светик, допрыгалась, подойди-ка к нам, - позвал вас один из парней.";
    str[44] = "Увидев вас голую, парни только покачали головами..."
            "- Смотри Светик, допрыгаешься у нас, если будешь прелестями тут светить, - шутливо сказал кто-то из парней.";
    str[45] = "Как только вы появились во дворе, к вам тут же направился Андрей."
            "- Света, есть разговор, - сказал он. - Ты помнишь, что ночью произошло?"
            "- Ну... эээ... да, - ответили вы покраснев и опустив глаза."
            "- Я раньше говорил, что ты очень похожа на свою мать, - Андрей пристально посмотрел на вас. - Так вот , как оказалось, похожа ты не только внешне."
            "Андрей немного помолчал глядя на вас, а вы пытались собраться с мыслями и понять к чему он клонит."
            "- Короче, ты такая же шлюшка, как и твоя мать в молодости, яблоко от яблони как говорится... - усмехнулся он. - Прими это как данность."
            "Вы ошарашено посмотрели на Андрея."
            "- А призвание шлюшек это что? - продолжил он. - Правильно, обслуживать мужиков. Согласна?";
    str[46] = "Как только вы появились во дворе, к вам тут же направился Андрей."
            "- Светик, есть разговор, - сказал он. - Ты понимаешь, что произошло и как теперь себя вести нужно?"
            "Вы невольно кивнули головой."
            "- В том что случилось ты сама виновата, нефиг было выёбываться, - Андрей внимательно посмотрел на вас. - Смотри, не делай глупостей больше."
            "- И в милицию тебе идти не советую, - добавил он. - У Сергея там подвязки. Мы то отмажемся, а тебе потом пиздец будет. Усекла?"
            "Вы испугано посмотрели на Андрея и закивали головой."
            "- Ну вот и молодец, - сказал он и отошел в сторону.";
    str[47] = "Выйдя на поляну перед избушкой вы замечаете Игоря. Он дожидался явно вас."
            "- Светик, я хотел с тобой поговорить... - немного смущаясь начал говорить он. Вы с интересом взглянули на него, дожидаясь продолжения...";
    str[48] = "Появившись на поляне вы увидели Игоря. Он с улыбкой подошел и впился в ваши губы страстным поцелуем."
            "- Света, я хочу тебя, - прошептал он, прервав поцелуй.";
    str[49] = "Улыбнувшись вы подмигиваете Игорю. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[50] = "- Нет, Игорь, давай не сейчас, - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[51] = "Появившись на поляне вы увидели Игоря. Он с загадочной улыбкой подошел к вам держа руки за спиной."
            "- Света, это тебе, - немного смущаясь сказал он, протянув вам букет полевых цветов.";
    str[52] = "Улыбнувшись вы берете букет из его руки и уходите с задумчивым видом.";
    str[53] = "Улыбнувшись вы берете букет из его рук и уходите со счастливым видом.";
    str[54] = "Улыбнувшись вы берете букет из его рук, целуете его в щечку и смутившись убегаете.";
    str[55] = "- Нет, Игорь, не нужно этого, - сказали вы, и не взяв цветы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[56] = "Появившись на поляне вы увидели Сергея, который улыбкой направлялся в вашу сторону."
              "- Света, давай посидим, пообщаемся, ты не против? - немного смущаясь спросил он.";
    str[57] = "Улыбнувшись вы соглашаетесь и следующие два часа вы проводите вместе с Сергеем за разговорами...";
    str[58] = "- Нет, Сергей, не хочу, - сказали вы, и стараясь не смотреть на парня ушли.";
    str[59] = "Появившись на поляне вы увидели Сергея. Он с улыбкой подошел и впился в ваши губы долгим поцелуем."
            "- Света, я хочу тебя, - сказал он, прервав поцелуй.";
    str[60] = "Улыбнувшись вы подмигиваете Сергею. Он, все прекрасно понимая, берет вас за руку и ведет за собой.";
    str[61] = "- Нет, Сергей, давай не сейчас, - сказали вы, и стараясь не смотреть на расстерявшегося парня ушли.";
    str[62] = "Появившись на поляне вы увидели Андрея. Неожиданно он впился в ваши губы страстным поцелуем и ни слова не говоря потянул вас за собой.";
    str[63] = "Вы идете с Андреем держась за руки, прекрасно понимая, куда и зачем он вас ведет. И вы совсем даже не против.";
    str[64] = "- Нет, Андрей, давай не сейчас,// - сказали вы, и стараясь не смотреть на него ушли.";

    str[65] = "Появившись на поляне вы увидели Андрея направляющегося в вашу сторону.<br>- Пошли Светик, - сказал он и больше ни слова не говоря потянул вас за собой, в сторону ближайших деревьев.";
    str[66] = "Появившись на поляне вы увидели Сергея. Заметив вас он направился в вашу сторону.<br>- Пошли отойдем Светик, что-то приспичило, - сказал он и потянул вас за собой в сторону ближайших зарослей.";
    str[67] = "Появившись на поляне вы увидели Игоря. Заметив вас он улыбнуся и подошел.<br>- Светик, мне нужно напряжение скинуть, давай отойдем, - сказал он улыбаясь и повел вас за собой.";

    str[68] = "Вы покорно пошли следом, прекрасно понимая куда и зачем вас ведут.";
    str[69] = "- Надо, так надо, - подумали вы и пошли с парнем, прекрасно понимая куда и зачем вас ведут.";
    str[70] = "- Отлично, то что нужно, главное вовремя, - подумали вы, чувствуя как ваша киска изнывает от желания. Вы пошли с парнем, чуть ли не обгоняя его, и уже не ясно было, кто кого ведет.";
    str[71] = "К вам подошли Андрей и Сергей. Лица их были серьезны и вы поняли, что вам предстоит тяжелый разговор."
              "- Светуля, мы не мальчики, чтобы с нами в игрушки играть, и крутить любовь с обоими, - начал разговор Сергей. - Ты должна выбрать кого-то одного из нас.";
    str[72] = "- Ну, я вообще-то и против тройничка был бы не против, - усмехнулся Андрей, пристально смотря вам в глаза. - Выбор за тобой Светик.";
    str[73] = "Вы задумались на на некоторое время, потом решили...";
    str[74] = "- Да пошли вы со своим выбором, - в сердцах крикнули вы и показав им на прощание средний палец пошли прочь. - Вот вам мой выбор!"
            "- Охренеть, - только и смог произнести ошарашеный Сергей."
            "- Ахахах, - неожиданно расмеялся Сергей. - Ну что же, все по честному, это твой выбор.";
    str[75] = "- Знаете, я бы попробовала любовь втроем, - опустив глаза сказали вы."
            "- Хороший выбор Светик, - усмехнулся Сергей. - я примерно так и предпологал. Ну что Андрей, ты не против?"
            "- Ну почему бы и нет, в конце концов это её выбор, - сказал Андрей, посмотрев на вас как-то совсем по другому.";
    str[76] = "После раздумий вы решили выбрать Сергея. Он просиял от радости и тут же поцеловал вас в губы."
            "- Ну что же, все по честному, это твой выбор, - сказал расстроеный Андрей и отошел в сторону.";
    str[77] = "После раздумий вы решили выбрать Андрея."
            "- Ну вот и разобрались, - сказал Андрей заметно повеселев. - Иди ко мне Светуля."
            "- Ну что же, все по честному, это твой выбор, - сказал расстроеный Сергей и отошел в сторону.";
    str[78] = "К вам подошли Андрей и Игорь. Лица их были серьезны и вы поняли, что вам предстоит тяжелый разговор."
            "- Света, мы не мальчики, чтобы с нами в игрушки играть, и крутить любовь с обоими, - начал разговор Игорь. - Ты должна выбрать кого-то одного из нас.";
    str[79] = "После раздумий вы решили выбрать Игоря. Он просиял от радости."
            "- Я верил, что ты выберешь меня Света, - сказал Игорь и нежно поцеловал вас в губы."
            "- Ну что же, все по честному, это твой выбор, - сказал расстроеный Андрей и отошел в сторону.";
    str[80] = "После раздумий вы решили выбрать Андрея."
            "- Ну вот и разобрались, - сказал Андрей заметно повеселев. - Иди ко мне Светуля."
            "Расстроеный Игорь молча отошел в сторону стараясь не смотреть на вас.";
    str[81] = "- Знаете, я бы попробовала любовь втроем, - опустив глаза сказали вы."
            "- Хороший выбор Светик, - усмехнулся Андрей. - Я примерно так и предпологал. Ну что Игорь, ты не против?"
            "- Нет, Андрей, меня это не устраивает, - сказал Игорь, посмотрев на вас как-то совсем по другому. - Пожалуй я лучше пойду."
              "Расстроеный Игорь ушел стараясь не смотреть на вас.";
    str[82] = "- Да пошли вы со своим выбором, - в сердцах крикнули вы и показав им на прщание средний палец пошли прочь. - Вот вам мой выбор!"
              "Ошарашеный Игорь в изумлении посмотрел на вас."
              "- Ахахах, - неожиданно расмеялся Андрей. - Ну что же, все по честному, это твой выбор.";
    str[83] = "К вам подошли Игорь и Сергей. Лица их были серьезны и вы поняли, что вам предстоит тяжелый разговор."
            "- Светуля, мы не мальчики, чтобы с нами в игрушки играть, и крутить любовь с обоими, - начал разговор Сергей. - Ты должна выбрать кого-то одного из нас."
            "Игорь молча кивнул."
            "Вы задумались на на некоторое время, потом решили...";
    str[84] = "После раздумий вы решили выбрать Сергея. Он просиял от радости и тут же поцеловал вас в губы."
            "- Не ожидал Света, но это твой выбор, - сказал расстроеный Игорь и отошел в сторону.";
    str[85] = "После раздумий вы решили выбрать Игоря. Он просиял от радости."
            "- Я верил, что ты выберешь меня Света, - сказал Игорь и нежно поцеловал вас в губы."
            "- Ну что же, все по честному, это твой выбор, - сказал расстроеный Андрей и отошел в сторону.";
    str[86] = "- Да пошли вы со своим выбором, - в сердцах крикнули вы и показав им на прщание средний палец пошли прочь. - Вот вам мой выбор!"
            "Ошарашеный Игорь в изумлении посмотрел на вас."
            "- Охренеть, - только и смог произнести Сергей.";
    str[87] = "На поляне вы увидели Андрея с Сергеем."
            "- Пора, так сказать, исполнять супружеский долг, - сказал Андрей шутливым тоном. - Готовь Светик попу."
            "- В кусты нужно поглубже забраться только, - добавил Сергей. - А то Игорь у нас сильно правильный, не поймет.";
    str[88] = "- Нет, ребята, что-то я не хочу, - сказали вы, и не глядя на них ушли.";
    str[89] = "Вы шли по поляне, когда внезапно налетевший ветерок задрал вам юбку."
            "- Блин, трусики... - запоздало опомнились вы, сверкнув уже голой писькой на всю округу."
            "Совладав наконец с юбкой вы осмотрелись, не заметил ли кто пикантные подробности вашего гардероба. Парни вроде как всегда занимались"
              " своими делами, однако по покрасневшему Игорю и довольно улыбающемуся Андрею, вы поняли, что ваша случайная демонстрация не прошла незамечаной.";
    str[90] = "На поляне вы увидели Андрея с Сергеем.";
    str[91] = "Идя по поляне вы увидели Андрея и Сергея идущих в вашу сторону.<br>- Пошли Светик, - сказал Андрей и больше ни слова не говоря потянул вас за собой, в сторону ближайших деревьев. Сергей двинулся следом";
    str[92] = "Вы шли по поляне, когда увидели Андрея и Игоря. Заметив вас они направились в вашу сторону.<br>- Пошли отойдем Светик, что-то приспичило, - сказал Андрей и потянул вас за собой в сторону ближайших зарослей. Игорь пошел следом за вами.";
    str[93] = "Появившись на поляне вы увидели Игоря и Сергея. Заметив вас Игорь улыбнуся и подошел.<br>- Светик, нам напряжение нужно скинуть, давай отойдем, - сказал он улыбаясь и повел вас за собой. Следом двинулся и Сергей.";
    str[94] = "Вы идете с парнями держась за руки, прекрасно понимая, куда и зачем они вас ведут. И вы совсем даже не против.";
    str[95] = "Вы шли по поляне, когда увидели человека в форме лесника."
            "- А вот и наша пропажа, - устало сказал он. - Твои дед и бабка уже с ног сбились в поисках тебя. Меня вот попросили помочь. Собирайся, домой отведу."
            "\"Ой, как стыдно\" - подумали вы. - \"Бедные дедушка с бабушкой. Ну как я могла о них забыть.\""
            "Быстро собравшись, вы пошли под присмотром лесника домой.";
    return str[id];
}

QString SwampYard::act(int id)
{
    QString act[27];
    act[0] = "Идти в избу";
    act[1] = "Убираться во дворе";
    act[2] = "Идти на болото";
    act[3] = "Осмотреться";
    act[4] = "Далее";
    act[5] = "Остаться";
    act[6] = "Да ладно, дойду как-нибудь";
    act[7] = "Уйти";
    act[8] = "Присесть";
    act[9] = "Андрей";
    act[10] = "Сергей";
    act[11] = "Игорь";
    act[12] = "Убираться в избушке";
    act[13] = "Отказатсья";
    act[14] = "Убираться на поляне";
    act[15] = "Одеться";
    act[16] = "Остаться голышом";
    act[17] = "Согласиться";
    act[18] = "Идти";
    act[19] = "Принять";
    act[20] = "Идти с Андреем";
    act[21] = "Выбрать Сергея";
    act[22] = "Выбрать Андрея";
    act[23] = "Встречаться с обоими";
    act[24] = "Расстаться с обоими";
    act[25] = "Выбрать Игоря";
    act[26] = "Идти с парнями";
    return act[id];
}

QString SwampYard::media(int id)
{
    QString med[31];
    med[0] = "data/locations/gadukino/swamp/swamp_yard.jpg";
    med[1] = "data/actions/backwater/hanterhelp.jpg";
    med[2] = "data/actions/backwater/hanterhelp1.jpg";
    med[3] = "data/actions/backwater/hanterhelp2.jpg";
    med[4] = "data/actions/backwater/hanterhelp3.jpg";
    med[5] = "data/npc/gadukino/swamp/AndreiHanter.jpg";
    med[6] = "data/npc/gadukino/swamp/SergeiHanter.jpg";
    med[7] = "data/npc/gadukino/swamp/IgorHanter.jpg";
    med[8] = "data/locations/gadukino/swamp/hanterstalk.jpg";
    med[9] = "data/locations/gadukino/swamp/swampdvornude.jpg";
    med[10] = "data/locations/gadukino/swamp/swampdvornude2.jpg";
    med[11] = "data/actions/backwater/hanterlove1.4.jpg";
    med[12] = "data/actions/backwater/hanterflowers1.jpg";
    med[13] = "data/actions/backwater/hanterswork1.2.jpg";
    med[14] = "data/locations/gadukino/swamp/no_tanga.jpg";
    med[15] = "data/locations/gadukino/swamp/forester.jpg";
    med[16] = "data/locations/gadukino/swamp/dirty_swamp_yard.jpg";
    med[17] = "data/qwest/gadukino/otel4.jpg";
    med[18] = "data/locations/gadukino/swamp/swampdvornude1.jpg";
    med[19] = "data/locations/gadukino/swamp/tkan_cloth.jpg";
    med[20] = "data/actions/backwater/hanterflirt2."+intQStr(getRandInt(4,6))+".jpg";
    med[21] = "data/actions/backwater/hanterflowers2_ski.jpg";
    med[22] = "data/actions/backwater/hanterflowers2.jpg";
    med[23] = "data/actions/backwater/hanterflowers3_ski.jpg";
    med[24] = "data/actions/backwater/hanterflowers3.jpg";
    med[25] = "data/actions/backwater/hanterflowerskiss.jpg";
    med[26] = "data/actions/backwater/hanterlove2.jpg";
    med[27] = "data/actions/backwater/hanterhands.jpg";
    med[28] = "data/actions/backwater/hanterswork1.7.jpg";
    med[29] = "data/sex/hantersex/fuck.jpg";
    med[30] = "data/locations/gadukino/swamp/doublehanterlove.jpg";
    return med[id];
}
