#include "miroslava.h"
#include "../../Functions.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"
#include "../../common/bathroom.h"

Miroslava::Miroslava(EventHandler *ptr): root(ptr) {}

void Miroslava::start(QString arg)
{
    if(arg == "miraclothes")
    {
        miraclothes();
        return;
    }
    else if(arg == "mira_river")
    {
        mira_river();
        return;
    }
    else if(arg == "miratalk")
    {
        miratalk();
        return;
    }
    else
    {
        actionHandler("Miroslava");
    }
}

void Miroslava::actionHandler(QString action)
{
    root->clearActions();
    if(action == "Miroslava")
    {
        age = root->getAge();
        int mira_temp = getRandInt(0,20);
        if(root->gVEvent(mirainriver) == 1)
        {
            if(!root->isNude())
            {
                root->setImage(media(0));
                root->setDesc(str(0));
            }
            else
            {
                root->setImage(media(1));
                root->setDesc(str(1));
            }
        }
        else
        {
            int gopval = root->gVQuest(miragopQW);
            if(gopval == 0)
                root->setImage(media(2));
            else if(gopval > 0 && gopval < 4)
                root->setImage(media(3));
            else if(gopval >= 4 && gopval < 8)
                root->setImage(media(4));
            else if(gopval >= 8 && gopval < 12)
                root->setImage(media(5));
            else if(gopval >= 12 && gopval < 20)
                root->setImage(media(6));
            else if(gopval >= 20)
                root->setImage(media(7));
        }
        if(root->gVEvent(mirainmeadow) == 1)
            root->setDesc(str(2));
        if(root->gVEvent(mirainriver) == 1)
            root->addDesc(str(3));
        if(root->gVEvent(mirainmeadow) == 0 && root->gVEvent(mirainriver) == 0)
            root->setDesc(str(4));
        int relation = root->gVQuest(miraQW);
        if(relation < 5)
            root->addDesc(str(5));
        if(relation >= 5 && relation < 15)
            root->addDesc(str(6));
        if(relation >= 15 && relation < 30)
            root->addDesc(str(7));
        if(relation >= 30 && relation < 50)
            root->addDesc(str(8));
        if(relation >= 50)
            root->addDesc(str(9));
        if(root->vStatus(cumFace) > 0 && root->vStatus(cumFrot) == 0)
            root->addDesc(str(10));
        if(root->vStatus(cumFace) == 0 && root->vStatus(cumFrot) > 0)
            root->addDesc(str(11));
        if(root->vStatus(cumFace) > 0 && root->vStatus(cumFrot) > 0)
            root->addDesc(str(12));
        if(root->gVJob(graze_cow) == 0)
        {
            if(root->gVQuest(miragopQW) == 11)
                makeActBtn("miragopqw11",act(0));
            else if(root->gVQuest(miragopQW) >= 15 && root->gVEvent(mirasex) == 0 && root->gVEvent(mirainmeadow) == 1 && root->gVEvent(mitkasextimes) < 13)
                makeActBtn("lesb_talk_mira1",act(0));
            else if(root->gVQuest(miragopQW) >= 15 && root->gVEvent(mitkasextimes) >= 13 && root->gVEvent(mirasex) == 1 && root->gVEvent(miralick) == 0 && root->gVEvent(mirainmeadow) == 1 && root->vStatus(horny) >= 40)
                makeActBtn("lesb_talk_mira2",act(0));
            else
            {
                if(root->gVEvent(mirasex) == 1 && root->gVEvent(mitkasextimes) < 13 && root->gVEvent(miralick) > 0 && root->gVEvent(mirainmeadow) == 1 && root->vStatus(horny) >= 40)
                    makeActBtn("lesb_talk_mira3",act(1));
                if(root->gVEvent(mirasex) == 2 && root->gVEvent(mirainmeadow) == 1 && root->vStatus(horny) >= 40 && root->gVQuest(miraQW) >= 15)
                    makeActBtn("lesb_mira",act(2));
                makeActBtn("miratalk",act(3));
                if(root->getMonth() >= 4 && root->getMonth() <= 10)
                    makeActBtn("walk_together",act(4));
                if(root->gVEvent(meadow) == 1 && root->gVEvent(mirainforest) == 0)
                    makeActBtn("show_meadow",act(7));
                if(root->gVEvent(meadow) == 3 && root->getHour() >= 8 && root->getHour() < 19 && root->gVEvent(mirainmeadow) == 0 && root->gVEvent(mirainforest) == 0 && root->getSunWeather() >= 0 && root->getMonth() >= 4 && root->getMonth() <= 10)
                    makeActBtn("lets_go_meadow",act(9));
                if(root->gVQuest(miraQW) >= 15 && root->getHour() >= 20 && root->gVQuest(miragopQW) == 0 && root->getSunWeather() >= 0 && root->gVEvent(mirainforest) == 0)
                    makeActBtn("first_meet_gadguys",act(11));
                if(root->gVQuest(miraQW) >= 15 && root->getHour() >= 20 && root->gVQuest(miragopQW) > 0 && root->getSunWeather() >= 0 && root->gVEvent(mirainforest) == 0 && root->getMonth() >= 4 && root->getMonth() <= 10)
                    makeActBtn("meet_gadguys",act(12));
                if(root->gVQuest(miraQW) >= 20 && root->getWeekNum() == 6 && root->getHour() > 18 && root->getHour() < 22)
                    makeActBtn("go_bana",act(13));
                if(root->getSunWeather() >= 0 && root->getTemp() >= 20 && root->getMonth() >= 5 && root->getMonth() <= 9 && root->gVEvent(mirainriver) == 0)
                    makeActBtn("go_river",act(14));
                if(root->gVEvent(miratalkforest) == 0 && root->gVQuest(miraQW) >= 5)
                    makeActBtn("talk_forest",act(16));
                if(root->getSunWeather() >= 0 && root->getTemp() >= 20 && root->getMonth() >= 5 && root->getMonth() <= 9 && root->gVEvent(mirainforest) == 0 && root->gVEvent(miratalkforest) > 0 && root->gVQuest(miraQW) >= 5)
                    makeActBtn("go_forest",act(17));
                if(root->getSunWeather() >= 0 && root->getTemp() >= 20 && root->getMonth() >= 5 && root->getMonth() <= 9 && root->gVEvent(mirainforest) == 1 && ((root->gVEvent(miratalkforest) == 2 && root->vStatus(shamelessFlag) > 0) || root->gVEvent(miratalkforest) == 3) && !root->isNude() && root->gVEvent(forestpicnic) == 0)
                    makeActBtn("walk_forest_nude",act(19));
                if(root->gVQuest(miragopQW) == 30 && root->getHour() < 19 && root->getMonth() >= 5 && root->getMonth() <= 9 && root->gVEvent(mirainforest) == 0)
                    makeActBtn("make_third_wish",act(20));
                if(root->gVQuest(miraQW) >= 15 && root->gVEvent(mirainforest) == 0 && (root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1))
                {
                    if(root->gVEvent(mira_guest) == 0)
                        makeActBtn("go_guest",act(28));
                    if(root->gVEvent(mira_guest) == 1)
                        makeActBtn("watch_tv",act(30));
                    if(root->gVEvent(mira_guest) > 0)
                        makeActBtn("say_bye",act(31));
                }
            }
            makeActBtn("back_to_loc",act(5));
        }
        if(root->gVEvent(meadow) == 2)
        {
            root->incTime(2);
            root->uVQuest(miraQW,1);
            miraclothes();
            root->setDesc(str(50));
            makeActBtn("allow_mira_meadow",act(32));
        }
        if(root->gVJob(graze_cow) == 1)
            makeActBtn("talk_graze_cow",act(33));
        if((mira_temp == 0 && root->gVEvent(mira_go_blok) == 0 && root->gVEvent(meadow) > 2 && root->getCurLoc() != lmirahome) || (root->getHour() >= 22 && root->getCurLoc() != lmirahome))
        {
            root->incTime(5);
            root->sVEvent(mira_no_home,0);
            if(root->gVEvent(mirainriver) == 1)
            {
                if(root->isNude())
                    root->setImage(media(8));
                else
                    root->setImage(media(9));
            }
            else
                miraclothes();
            root->setDesc(str(53));
            makeActBtn("miragohome",act(10));
        }
        if(root->gVQuest(miraQW) >= 15 && root->gVEvent(Mira_no) == 0 && (root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1))
        {
            if(root->gVEvent(mira_guest) == 0 && mira_temp >= 1 && mira_temp <= 2 && root->gVEvent(mira_go_blok) == 0 && root->gVEvent(mirainforest) == 0)
            {
                root->clearActions();
                root->incTime(1);
                if(root->gVEvent(mirainriver) == 1)
                    mira_river();
                else
                    miraclothes();
                root->setDesc(str(54));
                makeActBtn("go_in_guest",act(35));
                makeActBtn("dontgo_guest",act(36));
            }
            if(root->gVEvent(mira_guest) == 1 && mira_temp >= 3 && mira_temp <= 4)
            {
                root->clearActions();
                root->incTime(1);
                miraclothes();
                root->setDesc(str(57));
                makeActBtn("agree_watch_tv",act(35));
                makeActBtn("disagree_watch_tv",act(36));
            }
        }
        if(root->gVEvent(mirainmeadow) == 0 && mira_temp == 5 && root->gVEvent(meadow) == 3 && root->gVEvent(mira_go_blok) == 0 && root->gVEvent(mirainforest) == 0 && root->getHour() < 19 && root->getSunWeather() >= 0 && root->getMonth() >= 4 && root->getMonth() <= 10)
        {
            root->clearActions();
            root->incTime(1);
            miraclothes();
            root->setDesc(str(59));
            makeActBtn("accept_go_meadow",act(35));
            makeActBtn("decline_go_mradow",act(36));
        }
        if(root->gVEvent(mirainriver) == 0 && mira_temp >= 6 && mira_temp <= 7 && root->getSunWeather() >= 0 && root->getTemp() >= 20 && root->gVEvent(mira_go_blok) == 0 && root->gVEvent(mirainforest) == 0 && root->getHour() < 18)
        {
            root->clearActions();
            root->incTime(1);
            miraclothes();
            root->setDesc(str(61));
            makeActBtn("accept_go_river",act(35));
            makeActBtn("decline_go_river",act(36));
        }
        if(root->getHour() >= 20 && mira_temp > 10 && root->getSunWeather() >= 0 && root->gVEvent(mira_go_blok) == 0 && root->gVQuest(miragopQW) > 0 && root->gVEvent(mirainforest) == 0 && root->getMonth() >= 4 && root->getMonth() <= 10)
        {
            root->clearActions();
            root->incTime(1);
            root->sVEvent(mira_go_blok,1);
            root->sVEvent(miraingop,1);
            root->sVEvent(mirainhome,0);
            root->sVEvent(mira_guest,0);
            root->sVEvent(mirainriver,0);
            root->sVEvent(mirainmeadow,0);
            root->sVStatus(inriver,0);
            if(!root->isCloth())
                root->redressOld();
            miraclothes();
            root->setDesc(str(63));
            if(root->gVEvent(mitkasextimes) > 15 && root->gVQuest(miragopQW) > 15)
                makeActBtn("accept_go_buh_group",act(35));
            else
                makeActBtn("accept_go_buh",act(35));
            makeActBtn("decline_go_buh",act(36));
        }
        if(mira_temp >= 8 && mira_temp <= 9)
        {
            root->clearActions();
            root->incTime(1);
            root->sVEvent(mira_go_blok,1);
            miraclothes();
            root->setDesc(str(64));
            makeActBtn("accept_talks",act(35));
            makeActBtn("decline_talks",act(36));
        }
        if(root->gVEvent(mirainriver) == 1 && mira_temp >= 8 && mira_temp <= 9 && root->getSunWeather() >= 0 && root->getTemp() >= 20)
        {
            root->clearActions();
            root->incTime(1);
            miraclothes();
            root->setDesc(str(66));
            makeActBtn("accept_in_river",act(35));
            makeActBtn("decline_in_river",act(36));
        }
    }
    if(action == "miragopqw11")
    {
        root->eventStart("Meadow_event","miragopqw11");
    }
    if(action == "lesb_talk_mira1")
    {
        root->eventStart("Meadow_event","lesb_talk_mira1");
    }
    if(action == "lesb_talk_mira2")
    {
        root->eventStart("Meadow_event","lesb_talk_mira2");
    }
    if(action == "lesb_talk_mira3")
    {
        root->eventStart("Meadow_event","lesb_talk_mira3");
    }
    if(action == "lesb_mira")
    {
        root->eventStart("Meadow_event","lesb_mira");
    }
    if(action == "miratalk")
        miratalk();
    if(action == "walk_together")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            if(root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1)
            {
                if(root->gVEvent(mirainforest) == 0)
                    root->incTime(40);
                if(root->gVEvent(mirainforest) == 1)
                    root->incTime(85);
                if(root->gVQuest(miraQW) < 15)
                    root->uVQuest(miraQW,1);
                root->sVEvent(mirainmeadow,0);
                root->sVEvent(mirainriver,0);
                root->sVEvent(mira_guest,0);
                root->sVStatus(inriver,0);
                root->sVEvent(mirainforest,0);
                root->sVEvent(mirainhome,0);
                root->uVStatus(mood,10);
                if(root->getClothGroup() < sundress)
                {
                    root->redressOld();
                    root->sVStatus(clothesforest, 0);
                    root->sVStatus(swamp_clothes, 0);
                }
                root->setImage(media(11));
                root->setDesc(str(13));
                if(root->gVEvent(mitkasextimes) > 15 && root->gVQuest(miragopQW) > 15 && root->gVEvent(gadriver_gang) < 3)
                {
                    int mitkarand = getRandInt(1,20);
                    if(mitkarand == 1 && root->getHour() >= 7 && root->getHour() <= 16 && root->getWeekNum() != 0 && root->getWeekNum() <= 5 && root->gVEvent(mitkaday) != root->vStatus(daystart))
                        root->eventStart("gadukino_event","mira_mitka");
                    else if(mitkarand == 2 && root->getHour() >= 7 && root->getHour() <= 16 && root->getWeekNum() != 0 && root->getWeekNum() <= 5 && root->gVEvent(kolyambaday) != root->vStatus(daystart))
                        root->eventStart("gadukino_event","mira_kolyamba");
                    else if(mitkarand == 3 && root->getHour() >= 7 && root->getHour() <= 16 && root->getWeekNum() != 0 && root->getWeekNum() <= 5 && root->gVEvent(vasyanday) != root->vStatus(daystart))
                        root->eventStart("gadukino_event","mira_vasyan");
                    else if(mitkarand == 4 && root->getHour() >= 17 && root->getHour() <= 19 && root->gVEvent(gadboyday) != root->vStatus(daystart) && root->getWeekNum() != 0 && root->getWeekNum() <= 5)
                        root->eventStart("gadukino_event","mira_2boys");
                    else if(mitkarand <= 5 && root->getHour() >= 7 && root->getHour() <= 19 && root->gVEvent(gadboyday) != root->vStatus(daystart) && (root->getWeekNum() == 0 || root->getWeekNum() > 5))
                        root->eventStart("gadukino_event","mira_3boys");
                    else
                        makeActBtn("exit",act(5));
                }
                else
                    makeActBtn("exit",act(6));
            }
            else
            {
                root->incTime(5);
                root->setImage(media(10));
                root->setDesc(str(14));
                makeActBtn("back_to_loc",act(5));
            }
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(15));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "exit")
    {
        root->sVEvent(mira_guest,0);
        root->changeLoc(lgadukino);
    }
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "show_meadow")
    {
        root->incTime(30);
        root->uVStatus(mood,10);
        root->uVQuest(miraQW,2);
        root->sVEvent(meadow,2);
        root->sVEvent(mirainmeadow,1);
        root->sVEvent(mirainforest,0);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainhome,0);
        if(root->getClothGroup() < sundress)
        {
            root->redressOld();
        }
        root->setImage(media(13));
        root->setDesc(str(16));
        makeActBtn("get_in_meadow",act(8));
    }
    if(action == "get_in_meadow")
    {
        root->changeLoc(lmeadow);
    }
    if(action == "lets_go_meadow")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            if(root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 5 || root->gVEvent(mirasex) > 1)
            {
                if(root->gVQuest(miraQW) < 50)
                    root->uVQuest(miraQW,1);
                root->uVStatus(mood,10);
                root->sVEvent(mirainmeadow,1);
                root->sVEvent(mirainriver,0);
                root->sVEvent(mira_guest,0);
                root->sVStatus(inriver,0);
                root->sVEvent(mirainforest,0);
                root->sVEvent(mirainhome,0);
                if(root->getClothGroup() < sundress)
                {
                    root->redressOld();
                }
                root->setImage(media(13));
                root->setDesc(str(17));
                makeActBtn("get_in_meadow",act(10));
            }
            else
            {
                root->incTime(5);
                root->setImage(media(10));
                root->setDesc(str(18));
                makeActBtn("back_to_loc",act(5));
            }
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(19));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "first_meet_gadguys")
    {
        root->incTime(2);
        root->uVQuest(miraQW,1);
        root->sVEvent(miraingop,1);
        root->sVQuest(miragopQW,1);
        root->sVEvent(mirainmeadow,1);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mira_guest,0);
        root->sVStatus(inriver,0);
        root->sVEvent(mirainhome,0);
        if(root->getClothGroup() < sundress)
        {
            root->redressOld();
        }
        miraclothes();
        root->setDesc(str(23));
        makeActBtn("first_mitkabuh",act(10));
    }
    if(action == "first_mitkabuh")
    {
        root->sVEvent(mira_guest,0);
        root->incTime(15);
        root->sVEvent(miralko,0);
        root->eventStart("mitkabuh");
    }
    if(action == "meet_gadguys")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            root->incTime(5);
            if(root->gVQuest(miraQW) < 20)
                root->uVQuest(miraQW,1);
            root->sVEvent(miraingop,1);
            if(root->getClothGroup() < sundress)
            {
                root->redressOld();
            }
            miraclothes();
            if(root->gVQuest(miragopQW) == 5)
                root->setDesc(str(20));
            else
                root->setDesc(str(21));
            root->sVEvent(mira_guest,0);
            root->sVEvent(mirainriver,0);
            root->sVEvent(mirainmeadow,0);
            root->incTime(15);
            root->sVEvent(miralko,0);
            makeActBtn("go_buh",act(10));
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(22));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "go_buh")
    {
        if(root->gVQuest(miragopQW) > 15 && root->gVEvent(mitkasextimes) > 15 && root->gVEvent(gadriver_gang) < 3)
            root->eventStart("mitkabuh_group");
        else
            root->eventStart("mitkabuh");
    }
    if(action == "go_bana")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            if(root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1)
            {
                root->incTime(10);
                root->uVStatus(mood,20);
                if(root->gVQuest(miraQW) < 50)
                    root->uVQuest(miraQW,1);
                root->sVEvent(mira_guest,0);
                root->sVEvent(mirainriver,0);
                root->sVEvent(mirainmeadow,0);
                root->sVEvent(mirainhome,0);
                if(root->getClothGroup() < sundress)
                {
                    root->redressOld();
                }
                miraclothes();
                root->setDesc(str(24));
                if(root->gVEvent(mirainforest) == 0)
                    makeActBtn("go_bana_from_gad",act(10));
                if(root->gVEvent(mirainforest) == 1)
                    makeActBtn("go_bana_from_gadforest",act(10));
            }
            else
            {
                root->incTime(5);
                root->setImage(media(10));
                root->setDesc(str(25));
                makeActBtn("back_to_loc",act(5));
            }
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(26));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "go_bana_from_gad")
    {
        root->sVEvent(mira,1);
        root->changeLoc(lgadbana,15);
    }
    if(action == "go_bana_from_gadforest")
    {
        root->sVEvent(mirainforest,0);
        root->sVEvent(mira,1);
        root->changeLoc(lgadbana,45);
    }

    if(action == "go_river")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            if(root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1)
            {
                root->incTime(2);
                if(root->gVQuest(miraQW) < 30)
                    root->uVQuest(miraQW,1);
                root->sVEvent(mira_guest,0);
                root->sVEvent(mirainmeadow,0);
                root->sVEvent(mirainhome,0);
                root->sVEvent(mirainriver,1);
                root->sVStatus(inriver,1);
                if(root->getClothGroup() < sundress)
                {
                    root->redressOld();
                    root->sVStatus(swamp_clothes,0);
                }
                miraclothes();
                root->setDesc(str(27));
                if(root->gVEvent(mirainforest) == 0)
                    makeActBtn("goriver_from_gad",act(15));
                if(root->gVEvent(mirainforest) == 1)
                    makeActBtn("goriver_from_gadforest",act(15));
            }
            else
            {
                root->incTime(5);
                root->setImage(media(10));
                root->setDesc(str(28));
                makeActBtn("back_to_loc",act(5));
            }
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(29));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "goriver_from_gad")
    {
        root->changeLoc(lgadbeach,15);
    }
    if(action == "goriver_from_gadforest")
    {
        root->sVEvent(mirainforest,0);
        root->changeLoc(lgadbeach,45);
    }
    if(action == "talk_forest")
    {
        root->incTime(15);
        root->uVQuest(miraQW,1);
        root->sVEvent(miratalkforest,1);
        root->uVEvent(goforest,1);
        miraclothes();
        root->setDesc(str(30));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "go_forest")
    {
        if(root->gVEvent(Mira_no) == 0)
        {
            if(root->gVEvent(mitkasextimes) < 13 || root->gVQuest(miragopQW) >= 10 || root->gVEvent(mirasex) > 1)
            {
                root->incTime(2);
                if(root->gVQuest(miraQW) < 30)
                    root->uVQuest(miraQW,1);
                root->sVEvent(mira_guest,0);
                root->sVEvent(mirainmeadow,0);
                root->sVEvent(mirainhome,0);
                root->sVEvent(mirainriver,0);
                root->sVEvent(mirainforest,1);
                if(root->getClothGroup() < sundress)
                {
                    root->redressOld();
                }
                miraclothes();
                root->setDesc(str(31));
                makeActBtn("gadforest",act(18));
            }
            else
            {
                root->incTime(5);
                root->setImage(media(10));
                root->setDesc(str(32));
                makeActBtn("back_to_loc",act(5));
            }
        }
        else
        {
            root->incTime(5);
            root->setImage(media(12));
            root->setDesc(str(33));
            makeActBtn("back_to_loc",act(5));
        }
    }
    if(action == "walk_forest_nude")
    {
        root->sVStatus(clothesforest,1);
        root->incTime(5);
        root->uVStatus(mood,5);
        root->redress(ClothType::Main,nullptr);
        root->setImage(media(15));
        root->setDesc(str(34));
        makeActBtn("gadforest",act(10));
    }
    if(action == "gadforest")
    {
        root->changeLoc(lgadforest,0,"1");
    }
    if(action == "make_third_wish")
    {
        root->incTime(2);
        root->uVStatus(mood,10);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,0);
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainhome,0);
        root->sVStatus(inriver,0);
        if(root->getClothGroup() < sundress)
        {
            root->redressOld();
        }
        miraclothes();
        root->setDesc(str(35));
        makeActBtn("third_wish_1",act(21));
        makeActBtn("third_wish_2",act(27));
    }
    if(action == "third_wish_1")
    {
        root->incTime(15);
        root->setImage(makeImage(media(16),root->isDay(),root->getMonth()));
        root->setDesc(str(36));
        makeActBtn("third_wish_1.1",act(22));
    }
    if(action == "third_wish_1.1")
    {
        root->incTime(2);
        root->setImage(media(17));
        root->setDesc(str(37));
        makeActBtn("third_wish_1.1.1",act(23));
        makeActBtn("third_wish_1.1.2",act(26));
    }
    if(action == "third_wish_1.1.1")
    {
        root->incTime(5);
        root->uVStatus(horny,getRandInt(5,10));
        root->setImage(media(18));
        root->setDesc(str(38));
        makeActBtn("third_wish_1.1.1.1",act(24));
    }
    if(action == "third_wish_1.1.1.1")
    {
        root->incTime(5);
        root->uVStatus(horny,getRandInt(5,10));
        root->setImage(media(19));
        root->setDesc(str(39));
        makeActBtn("third_wish_1.1.1.1.1",act(25));
    }
    if(action == "third_wish_1.1.1.1.1")
    {
        root->incTime(15);
        root->uVStatus(horny,getRandInt(5,10));
        root->uVEvent(Mira_no,getRandInt(10,30));
        root->sVEvent(miraday,root->vStatus(daystart));
        root->sVQuest(miragopQW,33);
        root->sVQuest(miraQW,1);
        root->setImage(media(20));
        root->setDesc(str(40));
        makeActBtn("third_wish_end",act(6));
    }
    if(action == "third_wish_end")
    {
        root->sVEvent(mira_guest,0);
        root->changeLoc(lgadukino);
    }
    if(action == "third_wish_1.1.2")
    {
        root->incTime(5);
        root->uVQuest(miraQW,5);
        root->sVQuest(miragopQW,31);
        root->setImage(media(21));
        root->setDesc(str(41));
        makeActBtn("third_wish_end",act(6));
    }
    if(action == "third_wish_2")
    {
        root->incTime(15);
        root->setImage(makeImage(media(22),root->isDay(),root->getMonth()));
        root->setDesc(str(42));
        makeActBtn("third_wish_2.1",act(22));
    }
    if(action == "third_wish_2.1")
    {
        root->incTime(2);
        root->setImage(media(17));
        root->setDesc(str(43));
        makeActBtn("third_wish_2.1.1",act(23));
        makeActBtn("third_wish_2.1.2",act(26));
    }
    if(action == "third_wish_2.1.1")
    {
        root->incTime(15);
        root->uVStatus(horny,getRandInt(5,10));
        root->setImage(media(23));
        root->setDesc(str(44));
        makeActBtn("third_wish_2.1.1.1",act(24));
    }
    if(action == "third_wish_2.1.1.1")
    {
        root->incTime(15);
        root->uVStatus(horny,getRandInt(5,10));
        root->setImage(media(24));
        root->setDesc(str(45));
        makeActBtn("third_wish_end",act(6));
    }
    if(action == "third_wish_2.1.2")
    {
        root->incTime(5);
        root->uVQuest(miraQW,2);
        root->sVQuest(miragopQW,31);
        root->setImage(media(21));
        root->setDesc(str(41));
        makeActBtn("third_wish_end",act(6));
    }
    if(action == "go_guest")
    {
        root->incTime(5);
        root->uVStatus(mood,5);
        root->sVEvent(mira_guest,1);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,0);
        root->sVStatus(inriver,0);
        root->sVEvent(mirainhome,0);
        if(root->gVQuest(miraQW) < 30)
            root->uVQuest(miraQW,1);
        miraclothes();
        root->setDesc(str(46));
        makeActBtn("go_guest1",act(29));
    }
    if(action == "go_guest1")
    {
        if(root->isCloth())
            root->changeLoc(lgadhouse,15);
        else
        {
            root->incTime(5);
            root->sVEvent(mira_guest,1);
            root->sVEvent(mirainriver,0);
            root->sVEvent(mirainmeadow,0);
            root->sVStatus(inriver,0);
            if(root->getClothGroup() <= swimsuit)
                root->redressOld();
            root->setImage(media(25));
            root->setDesc(str(47));
            makeActBtn("gadhouse",act(10));
        }
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse,15);
    }
    if(action == "gadhouse0")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "watch_tv")
    {
        root->incTime(60);
        if(root->gVQuest(miraQW) < 20)
            root->uVQuest(miraQW,1);
        root->uVStatus(mood,getRandInt(10,50));
        root->setImage(media(26));
        root->setDesc(str(48));
        makeActBtn("gadhouse0",act(10));
    }
    if(action == "say_bye")
    {
        root->incTime(5);
        root->sVEvent(mira_guest,0);
        miraclothes();
        root->setDesc(str(49));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "allow_mira_meadow")
    {
        root->sVEvent(meadow,3);
        root->incTime(2);
        root->uVQuest(miraQW,1);
        miraclothes();
        root->setDesc(str(51));
        makeActBtn("get_in_meadow",act(6));
    }
    if(action == "talk_graze_cow")
    {
        root->incTime(60);
        root->uVStatus(mood,10);
        if(root->gVQuest(miraQW) < 50)
            root->uVQuest(miraQW,1);
        root->setImage(media(27));
        root->setDesc(str(52));
        makeActBtn("back_to_loc",act(34));
    }
    if(action == "miragohome")
    {
        root->sVEvent(mira,0);
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,0);
        root->sVEvent(mirainforest,0);
        actionHandler("back_to_loc");
    }
    if(action == "go_in_guest")
    {
        if(root->isCloth())
        {
            root->sVEvent(mira_go_blok,1);
            root->sVEvent(mirainmeadow,0);
            root->sVEvent(mirainhome,0);
            root->sVStatus(inriver,0);
            root->sVEvent(mirainriver,0);
            root->sVEvent(mira_guest,1);
            root->uVQuest(miraQW,1);
            actionHandler("gadhouse");
        }
        else
        {
            root->uVQuest(miraQW,1);
            root->sVEvent(mira_go_blok,1);
            root->sVEvent(mira_guest,1);
            root->sVEvent(mirainriver,0);
            root->sVEvent(mirainmeadow,0);
            root->sVEvent(mirainhome,0);
            root->sVStatus(inriver,0);
            if(root->gVQuest(miraQW) < 30)
                root->uVQuest(miraQW,1);
            root->incTime(20);
            root->redressOld();
            root->setImage(media(25));
            root->setDesc(str(55));
            makeActBtn("gadhouse0",act(10));
        }
    }
    if(action == "dontgo_guest")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(56));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "agree_watch_tv")
    {
        root->incTime(60);
        if(root->gVQuest(miraQW) < 20)
            root->uVQuest(miraQW,1);
        root->uVStatus(mood,getRandInt(10,50));
        root->sVEvent(mira_go_blok,1);
        root->setImage(media(26));
        root->setDesc(str(48));
        makeActBtn("gadhouse0",act(10));
    }
    if(action == "disagree_watch_tv")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(58));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "accept_go_meadow")
    {
        root->incTime(15);
        root->uVStatus(mood,5);
        if(root->gVQuest(miraQW) < 50)
            root->uVQuest(miraQW,1);
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,1);
        root->sVStatus(inriver,0);
        root->sVEvent(mira_go_blok,1);
        root->sVEvent(mirainhome,0);
        if(root->getClothGroup() <= swimsuit)
            root->redressOld();
        root->setImage(media(13));
        root->setDesc(str(60));
        makeActBtn("get_in_meadow",act(10));
    }
    if(action == "decline_go_mradow")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(56));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "accept_go_river")
    {
        root->incTime(15);
        if(root->gVQuest(miraQW) < 30)
            root->uVQuest(miraQW,1);
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainriver,1);
        root->sVEvent(mirainmeadow,0);
        root->sVStatus(inriver,1);
        root->sVEvent(mira_go_blok,1);
        root->sVEvent(mirainhome,0);
        if(root->getClothGroup() <= swimsuit)
            root->redressOld();
        root->setImage(media(13));
        root->setDesc(str(62));
        makeActBtn("gadbeach",act(10));
    }
    if(action == "decline_go_river")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(56));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "accept_go_buh_group")
    {
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,0);
        root->sVStatus(inriver,0);
        root->sVEvent(miralko,0);
        root->incTime(15);
        root->eventStart("mitkabuh_group");
    }
    if(action == "accept_go_buh")
    {
        root->sVEvent(mira_guest,0);
        root->sVEvent(mirainriver,0);
        root->sVEvent(mirainmeadow,0);
        root->sVStatus(inriver,0);
        root->sVEvent(miralko,0);
        root->incTime(15);
        root->eventStart("mitkabuh");
    }
    if(action == "decline_go_buh")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(56));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "accept_talks")
    {
        root->clearActions();
        makeActBtn("miratalk",act(3));
    }
    if(action == "decline_talks")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(65));
        makeActBtn("back_to_loc",act(10));
    }
    if(action == "accept_in_river")
    {
        if(!root->isCloth())
        {
            root->incTime(60);
            ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
            root->uVStatus(mood,10);
            if(root->vSkill(strenght) < 20)
                root->uVSkill(strenght,1);
            if(root->getClothGroup() == swimsuit)
                root->setImage(media(28));
            else
                root->setImage(media(29));
            root->setDesc(str(67));
            makeActBtn("gadbeach",act(37));
        }
        else
        {
            root->incTime(5);
            root->sVStatus(inriver,1);
            root->redress(ClothType::Main, new ClothMain(2,swimsuit,"Купальник"));
            root->setImage(media(30));
            root->setDesc(str(68));
            makeActBtn("swim",act(38));
        }
    }
    if(action == "gadbeach")
    {
        root->changeLoc(lgadbeach);
    }
    if(action == "swim")
    {
        root->incTime(60);
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->uVStatus(mood,10);
        if(root->vSkill(strenght) < 20)
            root->uVSkill(strenght,1);
        root->setImage(media(28));
        root->setDesc(str(67));
        makeActBtn("gadbeach",act(37));
    }
    if(action == "decline_in_river")
    {
        root->incTime(1);
        root->uVQuest(miraQW,-1);
        root->setImage(media(14));
        root->setDesc(str(69));
        makeActBtn("gadbeach",act(10));
    }
    if(action == "ask_about_mitka")
    {
        root->incTime(2);
        root->uVStatus(horny,10);
        root->uVQuest(miraQW,1);
        root->sVQuest(miragopQW,2);
        root->uVStatus(mood,10);
        root->setImage(media(3));
        root->setDesc(str(73));
        makeActBtn("back_to_loc",act(6));
    }
    if(action == "say_you_saw")
    {
        root->incTime(2);
        root->uVStatus(horny,10);
        root->uVQuest(miraQW,-1);
        root->uVStatus(mood,10);
        root->setImage(media(3));
        root->setDesc(str(75));
        makeActBtn("do_anal_mitka",act(41));
    }
    if(action == "do_anal_mitka")
    {
        root->incTime(5);
        root->uVStatus(horny,10);
        root->uVStatus(mood,10);
        root->sVQuest(miragopQW,5);
        root->uVQuest(miraQW,-1);
        root->setImage(media(3));
        root->setDesc(str(76));
        makeActBtn("back_to_loc",act(5));
    }
    if(action == "first_wish_complete")
    {
        root->incTime(10);
        root->uVStatus(horny,15);
        root->sVQuest(miragopQW,7);
        root->uVStatus(mood,10);
        root->setImage(media(3));
        root->setDesc(str(80));
        makeActBtn("back_to_loc",act(5));
    }
}

void Miroslava::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Miroslava::actionHandler);
    root->addActBtn(btn);
}

void Miroslava::miraclothes()
{
    int gopQuest = root->gVQuest(miragopQW);
    if(gopQuest == 0)
    {
        root->setImage(media(2));
    }
    else if(gopQuest > 0 && gopQuest < 4)
    {
        root->setImage(media(3));
    }
    else if(gopQuest >= 4 && gopQuest < 8)
    {
        root->setImage(media(31));
    }
    else if(gopQuest >= 8 && gopQuest < 12)
    {
        root->setImage(media(32));
    }
    else if(gopQuest >= 12 && gopQuest < 20)
    {
        root->setImage(media(33));
    }
    else if(gopQuest >= 20)
    {
        root->setImage(media(34));
    }
}

void Miroslava::mira_river()
{
    if(root->isCloth())
        root->setImage(media(35));
    if(root->getClothGroup() == swimsuit)
        root->setImage(media(36));
    if(root->isNude())
        root->setImage(media(37));
}

void Miroslava::miratalk()
{
    if(root->gVQuest(miragopQW) == 0)
    {
        root->incTime(10);
        root->uVStatus(mood,5);
        if(root->gVQuest(miraQW) < 10)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVEvent(mitkasextimes) < 13 || root->gVEvent(mirasex) > 1)
            root->setDesc(str(70));
        else
            root->setDesc(str(71));
        makeActBtn("back_to_loc",act(6));
    }
    else if(root->gVQuest(miragopQW) == 1)
    {
        root->incTime(10);
        root->uVStatus(mood,5);
        if(root->gVQuest(miraQW) < 20)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVEvent(mitkasextimes) < 13 || root->gVEvent(mirasex) > 1)
            root->setDesc(str(72));
        else
            root->setDesc(str(71));
        if(root->gVEvent(mirasextimes) > 3)
            makeActBtn("ask_about_mitka",act(39));
        makeActBtn("Miroslava",act(6));
    }
    else if(root->gVQuest(miragopQW) == 2 || root->gVQuest(miragopQW) == 3)
    {
        root->incTime(10);
        root->uVStatus(mood,5);
        if(root->gVQuest(miraQW) < 20)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVEvent(mitkasextimes) < 13 || root->gVEvent(mirasex) > 1)
        {
            root->setDesc(str(74));
            if(root->gVQuest(miragopQW) == 3 && root->gVEvent(mitkasextimes) < 13)
                makeActBtn("say_you_saw",act(40));
        }
        else
            root->setDesc(str(77));
        makeActBtn("Miroslava",act(6));
    }
    else if(root->gVQuest(miragopQW) >= 4 && root->gVQuest(miragopQW) < 7)
    {
        root->incTime(10);
        root->uVStatus(horny,10);
        root->uVStatus(mood,5);
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVEvent(mitkasextimes) < 13 || root->gVEvent(mirasex) > 1)
            root->setDesc(str(78));
        else
            root->setDesc(str(79));
        if(root->gVQuest(miragopQW) == 6)
            makeActBtn("first_wish_complete",act(42));
        makeActBtn("back_to_loc",act(6));
    }
    else if(root->gVQuest(miragopQW) >= 7 && root->gVQuest(miragopQW) < 12)
    {
        root->incTime(10);
        root->uVStatus(horny,10);
        root->uVStatus(mood,5);
        if(root->gVQuest(miraQW) < 10)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVEvent(mitkasextimes) < 13 || root->gVEvent(mirasex) > 1)
            root->setDesc(str(81));
        else
            root->setDesc(str(82));
        makeActBtn("back_to_loc",act(6));
    }
    if(root->gVQuest(miragopQW) >= 12)
    {
        root->incTime(10);
        root->uVStatus(mood,5);
        if(root->gVEvent(mitkasextimes) == 0 && root->gVQuest(miraQW) < 10)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mitkasextimes) > 0 && root->gVEvent(mitkasextimes) < 13 && root->gVQuest(miraQW) < 15)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(mitkasextimes) >= 13 && root->gVQuest(miraQW) < 30)
            root->uVQuest(miraQW,1);
        if(root->gVEvent(Mira_no) > 0 && root->gVEvent(miraday) != root->vStatus(daystart))
        {
            root->sVEvent(miraday,root->vStatus(daystart));
            root->uVEvent(Mira_no,-1);
        }
        if(root->gVEvent(mirainriver) == 0)
            miraclothes();
        if(root->gVEvent(mirainriver) == 1)
            mira_river();
        if(root->gVQuest(miragopQW) < 20 && root->gVEvent(mitkasextimes) < 13)
            root->setDesc(str(83));
        else if(root->gVQuest(miragopQW) >= 20 && root->gVQuest(miragopQW) < 30 && root->gVEvent(mitkasextimes) < 13)
            root->setDesc(str(84));
        else if(root->gVQuest(miragopQW) >= 30 && root->gVEvent(mitkasextimes) < 13)
            root->setDesc(str(85));
        else
            root->setDesc(str(86));
        makeActBtn("back_to_loc",act(6));
    }
}

QString Miroslava::str(int id)
{
    QString str[150];
    str[0] = "Мира лежит на пляже, млея на солнце.";
    str[1] = "Голенькая Мира лежит на пляже, млея на солнце.";
    str[2] = "<npc>- Чудесное место, здесь так уютно и солнечно!</npc> - восклицает Мира, с восторгом кружась по поляне.";
    str[3] = "Она общительная девушка. Мирослава с отцом совсем недавно вынуждена была перехать сюда. Из-за огромных долгов"
             " отца им пришлось продать всё имущество, в том числе и квартиру в центре города, а на те деньги, что у них "
             "остались, они смогли позволить себе купить дом только в такой вот захудалой деревне.";
    str[4] = "Мирослава общительная девушка. Ей " + intQStr(age) + " лет. Она с отцом совсем недавно вынуждена была перехать"
            " в сюда. Из-за огромных долгов отца им пришлось продать все имущество, в том числе и квартиру в центре города, а"
            " на те деньги, что у них остались, они смогли позволить себе купить дом только в такой вот захудалой деревне.";
    str[5] = "У вас с ней прохладные отношения.";
    str[6] = "У вас с ней нормальные отношения.";
    str[7] = "У вас с ней хорошие отношения.";
    str[8] = "У вас с ней отличные отношения.";
    str[9] = "У вас с ней превосходные отношения.";
    str[10] = "Мира хихикает, видя сперму на вашем лице.";
    str[11] = "Мира хихикает, видя пятна спермы на вашей одежде.";
    str[12] = "Мира хихикает, видя сперму на вашем лице и одежде.";
    str[13] = "Вы предлагаете ей вместе побродить по деревне и она с радостью соглашается. Вы вместе гуляете по небольшой деревеньке,"
              " рассказывая другу другу разные истории из жизни.";
    str[14] = "Вы предлагаете Мире вместе погулять, но та отвечает, что не хочет, чтобы люди видели, как вы вместе гуляете, а то "
              "подумают, будто и она тоже такая же шлюха...";
    str[15] = "Вы предлагаете Мире вместе погулять, но Мира лишь отрицательно мотает головой, говоря, что после такого позора она"
              " никуда из дома не выйдет.";
    str[16] = "Вы ведёте Миру сквозь густые заросли к скрытой поляне и всю дорогу она не умолкает, весело щебеча и рассказывая истории"
              " из своей прошлой городской жизни.";
    str[17] = "Вы предлагаете Мирославе прогуляться в ваше тайное место и она охотно соглашается. По дороге вы с удовольствием "
              "рассказываете друг другу разные истории.";
    str[18] = "Вы предлагаете Мире прогуляться за деревней, но та говорит, что не хочет с вами тащиться куда ни попадя.";
    str[19] = "Вы предлагаете Мире прогуляться за деревней, но Мира лишь отрицательно мотает головой, говоря, что после такого "
              "позора она никуда из дома не выйдет.";
    str[20] = "Вы предлагаете Мирославе побухать с деревенскими и она уныло соглашается, шепотом сообщая вам, чтобы вы дождались,"
              " когда они с Митькой уйдут, а потом шли к Митькиному дому.";
    str[21] = "Вы предлагаете Мирославе побухать с деревенскими и она охотно соглашается, после чего просит вас подождать пару минут,"
              " пока она переоденется. Когда она выходит - вы вместе направляетесь к бухающей возле вашего дома компашке.";
    str[22] = "Вы предлагаете Мире побухать с деревенскими, но Мира лишь отрицательно мотает головой, говоря, что после такого позора"
              " она никуда из дома не выйдет.";
    str[23] = "Вы спрашиваете Мирославу - со всеми ли она уже в деревне познакомилась, а когда она отвечает, что нет - предлагаете "
              "познакомить её с местными парнями и она охотно соглашается, и попросив вас пару минут подождать, пока она переоденется,"
              " быстро скрывается в избёнке. Когда она выходит, вы вместе идете к бухающей возле вашего дома компашке...";
    str[24] = "Вы предлагаете Мирославе вместе попариться у вас в бане. Она долго медлит, но потом всё-же соглашается и вы идёте к вам"
              " во двор...";
    str[25] = "Вы предлагаете Мире вместе попариться у вас в бане, но та грубо отвечает, что ни за что не пойдёт с такой шлюхой, как"
              " вы, в одну баню.";
    str[26] = "Вы предлагаете Мире попариться у вас в бане, но Мира лишь отрицательно мотает головой, говоря, что после такого позора"
              " она никуда из дома не выйдет.";
    str[27] = "Вы предлагаете ей сходить на речку покупаться-позагорать и она охотно соглашается.";
    str[28] = "Вы предлагаете Мире вместе сходить на речку, но та презрительно хмыкает в ответ, что никуда не пойдёт с такой шалавой,"
              " как вы.";
    str[29] = "Вы предлагаете Мире вместе сходить на речку, но Мира лишь отрицательно мотает головой, говоря, что после такого "
              "унижения она никуда из дома не выйдет.";
    str[30] = "<hero>- Мир, а ты была в лесу за деревней?</hero> - решили поинтересоваться вы."
                "<npc>- Не, ты что, я боюсь одна туда ходить!</npc> - мотает Мира головой."
                "<hero>- А почему? - продолжили интересоваться вы у Мирославы.</hero>"
                "<npc>- Ой, да говорят там заблудиться легко, если леса не знаешь. А ещё говорят - там волки есть.</npc>"
                "<hero>- Кто говорит?</hero> - спросили вы недоверчиво.<hero>- Прямо настоящие волки?</hero>"
                "<npc>- Да местные говорят. Всякие страшные истории рассказывают.</npc>"
                "<hero>- Ой, да небось заливают,</hero> - хмыкаете вы. <hero>- Ездят по ушам таким как мы, чтобы в лес не ходили. Им грибов и ягод больше достанется!</hero>"
                "<npc>- Не, не, Свет!</npc> - серьёзно ответила она. <npc>- Рассказывали, что прошлым летом волки девочку из соседней деревни насмерть задрали. "
                "Она по грибы пошла, но время не расчитала и задержалась дотемна. Утром её искать пошли - так только разодраный сарафанчик в крови нашли, да корзинку.</npc>"
                "<hero>- Ужас какой!</hero> - поёжились вы. <hero>- А более интересного ничего не рассказывали?</hero>"
                "<npc>- А как же,</npc> - захихикала Мирослава, перейдя на заговорщицкий шепот. <npc>- Подслушала недавно разговор двух тёток в деревне."
                " Они говорили, что если по лесу голышом ходить, то здоровье прибавляется и настроение улучшается. Воздух типа так свежий влияет.</npc>"
                "Мирослава задумалась на минуту, а потом продолжила."
                "<npc>- Уж не знаю про здоровье, но там зудеть точно больше начинает,</npc> - Мирослава выразительно зыркает себе между ног."
                "<hero>- Подожди,</hero> - прервали вы её. <hero>- Ты же говорила, что боишься в лес ходить одна?!</hero>"
                "<npc>- Ой, да это всего разок и было,</npc> - краснеет Мира. <npc>- Проверить, правду ли те тётки сказали?</npc>"
                "<hero>- Ладно, ладно, не оправдывайся,</hero> - хихикнули вы, глядя на смущенную Миру. <hero>- А давай как-нибудь вместе сходим?</hero>"
                "<npc>- Ну не знаю Свет,</npc> - замялась она. <npc>- Если будет тепло и хорошая погода, то можно как-нибудь и сходить.</npc>"
                "<npc>- Но вглубь леса не пойдём, только на опушку!</npc> - тут же быстро добавила она."
                "<hero>- Хорошо, хорошо, по окраине погуляем,</hero> - согласились вы.";
    str[31] = "Вы предлагаете ей сходить в лес за грибами и ягодами и она охотно соглашается.";
    str[32] = "Вы предлагаете Мире вместе сходить в лес за грибами и ягодами, но та презрительно хмыкает в ответ и говорит, что никуда не пойдет с такой шалавой.";
    str[33] = "Вы предлагаете Мире вместе сходить в лес за грибами и ягодами, но Мира лишь отрицательно мотает головой, говоря, что после такого унижения она никуда из дома не выйдет.";
    str[34] = "Вы предложили Мире погулять по лесу голенькими и она сразу же согласилась.";
    str[35] = "Вы напоминаете Мире о третьем желании и она неохотно кивает вам головой, подтверждая, что помнит о нём. Вы, загадочно улыбаясь, приказываете ей следовать за вами...";
    str[36] = "Вы ведете Миру по деревенской улице. Мира молча смотрит себе под ноги, иногда кидая на вас настороженные взгляды...";
    str[37] = "Выйдя на середину деревни, вы уверенным требовательным голосом приказываете Мирославе раздеться, добавив, что это и есть ваше последнее желание, после которого вы простите ей её предательство. У неё медленно отвисает челюсть и она смотрит на вас как на умалишённую."
            "<hero>- Да ладно, что ты как девочка,</hero> - презрительно фыркаете вы, <hero>- мы ведь обе знаем, что ты та ещё шлюха и жить не можешь без членов. А тут такая реклама, и, заметь, совсем бесплатно."
            "Мира молча смотрит то на вас, то оглядывается на деревенскую улицу, по которой ходят люди."
            "<npc>- Светик, может не надо?</npc> - жалобно с надеждой спрашивает она.";
    str[38] = "<hero>- Нет уж Мира, тебя за язык никто не тянул, теперь уж будь добра выполняй обещание,</hero> - непреклонным тоном ответили вы."
              "Девушка ещё минуту нерешительно мнётся с ноги на ногу, после чего наконец решается и быстро сбрасывает всю одежду."
              "<hero>- Ну вот, теперь доберёшься до конца деревни - и считай себя прощённой!</hero> - с ехидной усмешкой звонко хлопаете вы ладонью Миру по заду для придания стартового импульса.";
    str[39] = "Мира нерешительно начинает двигаться по деревенской улице. Вы с интересом наблюдаете за ней и реакцией прохожих.";
    str[40] = "Наконец раскрасневшаяся Мира добирается до конца деревни и подбегает к вам."
               "<npc>- Светик, мы в расчёте?</npc> - спрашивает она с надеждой."
               "Вы, утвердительно кивнув головой, отдаёте ей одежду и понаблюдав ещё пару минут как Мира под улюлюканье случайных свидетелей бежит к своему дому, разворачиваетесь и идёте по своим делам.";
    str[41] = "<hero>- Ладно, чёрт с тобой, добрая я сегодня. Можешь считать себя прощённой,</hero> - отвечаете вы после небольшой паузы."
              "Девушка ещё пару мгновений нерешительно мнётся с ноги на ногу, не веря ушам, после чего подскакивает к вам и чмокает в щёку."
              "<npc>- Спасибо Светик, я... я... </npc>- и не договорив и разревевшись, она убегает домой.";
    str[42] = "Вы ведёте Миру к своему сараю, где стоит пустующая будка Пирата. Мира непонимающе смотрит на вас, ожидая продолжения.";
    str[43] = "Окинув Миру и будку оценивающим взглядом, вы увереннным требовательным голосом приказываете Мирославе раздеться и лезть в будку, добавив, что это и есть ваше последнее желание, после которого вы простите ей её предательство. У нее медленно отвисает челюсть и она смотрит на вас как на умалишённую."
              "<hero>- Да ладно, что ты как девочка,</hero> - презрительно фыркаете вы, <hero>- мы ведь обе знаем, что ты та ещё шлюха и жить не можешь без членов. А тут всего лишь требуется посидеть в будке и поизображать Пирата.</hero>"
              "Мира молча смотрит то на вас, то на будку, от которой ещё несет псиной."
              "<npc>- Светик, может не надо, вдруг увидит кто?</npc> - жалобно с надеждой спрашивает она.";
    str[44] = "<hero>- Нет уж Мира, - тебя за язык никто не тянул, теперь уж будь добра: - выполняй обещание,</hero> - непреклонны вы."
              "Девушка еще минуту нерешительно мнётся с ноги на ногу, после чего наконец решается и раздевается догола. Окинув будку унылым взглядом в последний раз, она становится на карачки и неловко пытается забраться в тесную будку."
              "<hero>- Ну вот, теперь посидишь пару-тройку часиков и свободна,</hero> - хлопаете с ехидной улыбкой вы Миру по заду для придания скорости, и устроившись поудобнее поотдаль, с интересом наблюдаете за ней.";
    str[45] = "Понаблюдав за Мирой некоторое время, вы пошли по своим делам."
              "<hero>- Отвяжешься сама, если не приду,</hero> - бросили вы ей напоследок.<br><b>(Пока это конец ивента, продолжение следует...)</b>";
    str[46] = "Вам надоело торчать на улице и вы решили пригласить Миру к себе в гости.";
    str[47] = "Вы переоделись в свою одежду и пошли домой с Мирой.";
    str[48] = "Вы с Мирой целый час убиваете за просмотром телевизора.";
    str[49] = "Вы попрощались с Мирой, сославшись на неотложные дела, и она ушла домой.";
    str[50] = "<npc>- А я ведь, хоть и недолго здесь, но об этом месте так и не знала!</npc> - весело сообщает вам Мирослава. <npc>- Теперь буду знать, где уединиться,"
              " когда захочется побыть наедине, ты ведь не возражаешь, правда?</npc>";
    str[51] = "Вы отвечаете, что не против и она может приходить сюда когда ей заблагорассудится, но требуете с неё слово, чтобы она никому не рассказывала об этом месте. "
              "Мирослава, довольная как слон, активно кивает головой и говорит, что заберёт этот секрет с собой в могилу, а если нет - то тогда как джинн исполнит три любых "
              "ваших желания..."
              "Она выглядит очень довольной, и спустя какое-то время решает рассказать вам очень страшный-страшный секрет..."
              "Вы заинтригованно соглашаетесь в ожидании, чего же такого сможет поведать вам Мирка, и та вскоре рассказывает вам, что видела, как её отец мастурбирует..."
              " Оказывается, после того, как умерла его жена - Миркина мама - у него не было ни одной женщины, вот он и... В общем, Мирке одновременно и жаль отца, но и"
              " помочь она ему ничем не может, хоть и очень сильно любит. Вы ожидали чего-то большего, а потому, услышав такую ерунду, конечно же сказали, что это не секрет,"
              " а глупость какая-то. Мирка обиженно надулась, всем своим видом демонстрируя оскорблённую невинность. А через пару минут, к своему удивлению, вы почувствовали,"
              " как неожиданно приятно зудит и влажнеет у вас в промежности от мысли об Мирославином отце...";
    str[52] = "В течение часа вы весело болтали с Мирославой. Ваши отношения улучшились.";
    str[53] = "<npc>- Светик, c тобой весело, но мне пора домой,</npc> - сказала вам Мира.";
    str[54] = "<npc>- Светик, что-то скучно тут, а давай к тебе домой пойдём?</npc> - предлагает Мира.";
    str[55] = "Вы переоделись и отправились с Мирой к вам домой.";
    str[56] = "Вы отказали Мире, сославшись на то, что там вам будет скучно.";
    str[57] = "<npc>- Светик, давай телек посмотрим, а то что-то скучно,</npc> - предлагает Мира.";
    str[58] = "Вы отказали Мире, сославшись на то, что вам это не интересно.";
    str[59] = "<npc>- Светик, может сходим на нашу поляну?</npc> - спрашивает Мира. <npc>- Прогуляемся, воздухом подышим.</npc>";
    str[60] = "Вы идёте с Мирой сквозь густые заросли к скрытой поляне и всю дорогу она не умолкает, весело щебеча и рассказывая истории из своей прошлой городской жизни.";
    str[61] = "<npc>- Светик, может сходим на речку?</npc> - спрашивает Мира. <npc>- Искупаемся, позагораем.</npc>";
    str[62] = "Вы решили сходить с Мирой на деревенский пляж и всю дорогу она не умолкает, весело щебеча и рассказывая разные истории.";
    str[63] = "<npc>- Светик, может сходим с местными побухаем?</npc> - предлагает Мира. <npc>- Скучно, развеяться хочется.</npc>";
    str[64] = "Мира хочет с вами поболтать."
              "<npc>- Светик, ты не против?</npc> - спросила у вас Мира.";
    str[65] = "<hero>- Не, Мир, давай не сейчас. Нет настроения сейчас разговаривать.</hero>";
    str[66] = "<npc>- Светик, чего ты на берегу киснешь? Айда купаться!</npc> - кричит вам Мира и кидается в речку.";
    str[67] = "Вы искупнулись в речушке, весело брызгаясь с Мирой друг на дружку водой.";
    str[68] = "<hero>- Сейчас, Мирка, только купальник надену!</hero> - крикнули вы в ответ, хотя вряд ли она вас услышала, плескаясь уже вовсю в речке."
              "Вы переодеваетесь в купальник и кидаетесь в воду вслед за Мирой.";
    str[69] = "<hero>- Не, Мир, неохота,</hero> - ответили вы ей. <hero>- Я на берегу лучше побуду.</hero>";
    str[70] = "Вы десять минут весело болтаете о всяких пустяках.";
    str[71] = "Вы некоторое время пытаетесь разговорить Миру, но та отмалчивается, иногда кидая на вас презрительные взгляды.";
    str[72] = "Вы десять минут весело болтаете о всяких пустяках, иногда вспоминая, как вы напились с деревенскими парнягами...";
    str[73] = "Вы спрашиваете Миру, есть ли что-то между ней и Митькой и она, немного помявшись, отвечает, что да, есть. На все дальнейшие расспросы она или отмалчивается или увиливает, поэтому вы решаете оставить это до более подходящих времен...";
    str[74] = "Вы десять минут весело болтаете о всяких пустяках, а Мира иногда заливается румянцем, что-то вспоминая...";
    str[75] = "Вы холодно говорите Мирославе, что видели, как она раздвигала ноги перед Митькой на вашей поляне и цитируете её слова о том, как она клялась никому не рассказывать о вашем тайном месте. Мира краснеет и потупливает взор, бормоча, что ей очень жаль, что так получилось, а потом спрашивает, есть ли что-то, что она может сделать для вас, чтобы загладить свою вину. Вы ей тут же напоминаете про три желания, которые она обещала исполнить, если кому-то расскажет, и она подобострастно кивает вам головой, что, мол, да, она помнит и готова искупить вину.";
    str[76] = "Вы говорите, что хотите посмотреть, как Митька отдерёт её в задницу за то, что она разболтала ваш секрет. Мира "
              "опешивает от таких слов и тупо смотрит на вас, но вы не даёте ей опомниться и продолжаете напирать дальше, "
              "напоминая, что уговор есть уговор, и если она и это своё слово не сдержит, то на этом ваша дружба и закончится."
              " Мирослава густо краснеет и нерешительно переминается с ноги на ногу, и вы, решив идти ва-банк, разворачиваетесь, собираясь уходить..."
              "<npc>- Постой, </npc>- негромко кричит вам в спину Мирослава, но вы делаете вид, что не замечаете и идете дальше."
              "<npc>- Хорошо, Света,</npc> - спустя долгих пару секунд доносится до вас истеричный крик Мирославы, <npc>- я что-нибудь придумаю!</npc>";
    str[77] = "Вы некоторое время пытаетесь разговорить Миру, но та отмалчивается, иногда кидая на вас презрительные взгляды.";
    str[78] = "Вы десять минут болтаете о разных пустяках, при этом Мира иногда, краснея, рассказывает вам некоторые интимные подробности её отношений с Митькой.";
    str[79] = "Вы некоторое время пытаетесь разговорить Миру, но та отмалчивается, иногда кидая на вас презрительные взгляды.";
    str[80] = "Вы говорите Мирославе, что видели, как Митька драл её в задницу и ехидно спрашиваете, понравилось ли ей. К вашему удивлению, она, краснея и смущаясь, говорит, что немного... Вы разочарованно хмыкнув, напоминаете ей, что осталось ещё два желания, по исполнении которых вы сможете забыть о её предательстве. Мира подобострастно кивает и говорит, что готова искупить свою вину. Вы отвечаете, что пока подумаете над вторым желанием, и развернувшись, уходите...";
    str[81] = "Вы десять минут вяло болтаете о разных пустяках, при этом Мира старается не встречаться с вами взглядом.";
    str[82] = "Вы десять минут болтаете о разных пустяках, при этом Мира иногда, краснея, рассказывает вам некоторые интимные подробности её отношений с Митькой.";
    str[83] = "Вы десять минут вяло болтаете о разных пустяках, при этом вы часто зовёте её не по имени, а называете просто шлюхой, на что она делает вид, будто ничего не замечает.";
    str[84] = "Вы десять минут вяло болтаете о разных пустяках, при этом Мира вообще не смотрит вам в глаза и со всем с вами соглашается, думая о чём-то своём.";
    str[85] = "Вы десять минут вяло болтаете о разных пустяках, но Мира вообще вас не слушает, все её разговоры сводятся к сексу.";
    str[86] = "Вы десять минут весело болтаете о всяких пустяках.";
    return str[id];
}

QString Miroslava::act(int id)
{
    QString str[50];
    str[0] = "Поговорить";
    str[1] = "Приказать полизать";
    str[2] = "Приставать";
    str[3] = "Поболтать";
    str[4] = "Предложить вместе погулять";
    str[5] = "Уйти";
    str[6] = "Закончить";
    str[7] = "Показать ей ваше тайное место";
    str[8] = "Пришли";
    str[9] = "Предложить сходить на Поляну";
    str[10] = "Далее";
    str[11] = "Спросить, знакома ли она уже с деревенскими";
    str[12] = "Предложить побухать с деревенскими";
    str[13] = "Предложить попариться в бане";
    str[14] = "Предложить сходить на речку";
    str[15] = "Идти на речку";
    str[16] = "Спросить про лес";
    str[17] = "Предложить сходить в лес";
    str[18] = "Идти в лес";
    str[19] = "Предложить погулять голышом";
    str[20] = "Загадать третье желание";
    str[21] = "Идти на улицу";
    str[22] = "Приказать ей раздеться";
    str[23] = "Подтвердить свои слова";
    str[24] = "Смотреть";
    str[25] = "Смотреть дальше";
    str[26] = "Простить";
    str[27] = "Идти к своему сараю";
    str[28] = "Пригласить в гости";
    str[29] = "Идти домой";
    str[30] = "Смотреть телевизор";
    str[31] = "Попрощаться";
    str[32] = "Разрешить ей приходить сюда самой";
    str[33] = "Болтать с Мирой";
    str[34] = "Отойти";
    str[35] = "Согласиться";
    str[36] = "Отказаться";
    str[37] = "Выйти из воды";
    str[38] = "Купаться";
    str[39] = "Спросить про неё и Митьку";
    str[40] = "Сказать, что видели, как она трахалась с Митькой на поляне";
    str[41] = "Сказать, что вы хотите посмотреть, как Митька будет драть ее в задницу";
    str[42] = "Сказать, что первое желание выполнено";
    return str[id];
}

QString Miroslava::media(int id)
{
    QString med[38];
    med[0] = "data/locations/gadukino/river/events/MiraBeach.jpg";
    med[1] = "data/locations/gadukino/river/events/MiraBeachNude.jpg";
    med[2] = "data/npc/gadukino/miroslava/Mira.jpg";
    med[3] = "data/npc/gadukino/miroslava/Mira3.jpg";
    med[4] = "data/npc/gadukino/miroslava/mira0," + intQStr(getRandInt(0,5)) + ".jpg";
    med[5] = "data/npc/gadukino/miroslava/mira1," + intQStr(getRandInt(0,5)) + ".jpg";
    med[6] = "data/npc/gadukino/miroslava/mira2," + intQStr(getRandInt(0,5)) + ".jpg";
    med[7] = "data/npc/gadukino/miroslava/mira3," + intQStr(getRandInt(0,5)) + ".jpg";
    med[8] = "data/locations/gadukino/river/events/mira_go_home_nude.jpg";
    med[9] = "data/locations/gadukino/river/events/mira_go_home.jpg";
    med[10] = "data/qwest/mira/Mira_said_no.jpg";
    med[11] = "data/actions/girls_walking/girls_walking" + intQStr(getRandInt(1,3)) + ".jpg";
    med[12] = "data/qwest/mira/Mira_shy.jpg";
    med[13] = "data/actions/girls_walking/girls_go.jpg";
    med[14] = "data/qwest/gadukino/otel4.jpg";
    med[15] = "data/locations/gadukino/forest/miraforest6.jpg";
    med[16] = "data/locations/gadukino/street.jpg";
    med[17] = "data/qwest/mira/Mira_looks.jpg";
    med[18] = "data/qwest/mira/Mira_nude1.jpg";
    med[19] = "data/qwest/mira/Mira_nude2.jpg";
    med[20] = "data/qwest/mira/Mira_nude3.jpg";
    med[21] = "data/qwest/mira/Mira_leaves.jpg";
    med[22] = "data/locations/gadukino/gaddvor/sarai.jpg";
    med[23] = "data/qwest/mira/Mira_kennel1.JPG";
    med[24] = "data/qwest/mira/Mira_kennel2.JPG";
    med[25] = "data/locations/gadukino/river/events/dressbch.jpg";
    med[26] = "data/qwest/mira/Mira_TV.jpg";
    med[27] = "data/locations/gadukino/gadfield/graze_cow_mira.jpg";
    med[28] = "data/locations/gadukino/river/events/RiverTwoGirls.jpg";
    med[29] = "data/locations/gadukino/river/events/RiverTwoGirlsNude.jpg";
    med[30] = "data/locations/gadukino/river/events/undressbch.JPG";
    med[31] = "data/npc/gadukino/miroslava/mira0" + intQStr(getRandInt(0,5)) + ".jpg";
    med[32] = "data/npc/gadukino/miroslava/mira1" + intQStr(getRandInt(0,2)) + ".jpg";
    med[33] = "data/npc/gadukino/miroslava/mira2" + intQStr(getRandInt(0,5)) + ".jpg";
    med[34] = "data/npc/gadukino/miroslava/mira3" + intQStr(getRandInt(0,3)) + ".jpg";
    med[35] = "data/locations/gadukino/river/events/MiraRiverTalk.jpg";
    med[36] = "data/locations/gadukino/river/events/MiraRiverTalkBikini.jpg";
    med[37] = "data/locations/gadukino/river/events/MiraRiverNudeTalk.jpg";
    return med[id];
}
