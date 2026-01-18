#include "riverevents.h"
#include "../../Functions.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"

#include "../../common/bathroom.h"

RiverEvents::RiverEvents(EventHandler *ptr): root(ptr) {}

void RiverEvents::start(QString arg)
{
    actionHandler(arg);
}

void RiverEvents::actionHandler(QString action)
{
    qDebug() << action;
    if(action == "mira_in_river")
        mira_in_river();
    if(action == "mira_punish")
        mira_punish();
    if(action == "swim_guys")
        swim_guys();
    if(action == "sunbathe_guys")
        sunbathe_guys();
    if(action == "guys_river")
        guys_river();
    if(action == "guys_beach")
        guys_beach();
    if(action == "horse_river")
        horse_river();
    if(action == "fishers")
        fishers();
    if(action == "fishing")
        fishing();
    if(action == "fishing_end")
        fishing_end();

    if(action == "gadbeach")
    {
        root->changeLoc(lgadbeach,5);
    }
    if(action == "stand_in_pose")
    {
        root->incTime(5);
        root->uVSkill(domination,-1);
        g = getRandInt(4,5);
        root->setImage(media(0));
        if(g == 5)
        {
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("gadbeach",act(1));
    }
    if(action == "swim_guys0")
    {
        root->incTime(5);
        root->setBoyName("Васян");
        root->sVSex(dick,14);
        g = getRandInt(5,14);
        if (g == 8)
            root->sVSex(pose,2);
        else if(g < 8 || g > 11)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 10)
        {
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("swim_guys1",act(0));
    }
    if(action == "swim_guys1")
    {
        root->incTime(5);
        root->setBoyName("Колямба");
        root->sVSex(dick,15);
        g = getRandInt(5,14);
        if (g == 8)
            root->sVSex(pose,2);
        else if(g < 8 || g > 11)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 10)
        {
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("gabeach",act(1));
    }
    if(action == "sunbathe_guys0")
    {
        root->incTime(5);
        root->setBoyName("Васян");
        root->sVSex(dick,14);
        g = getRandInt(5,14);
        if (g == 8)
            root->sVSex(pose,2);
        else if(g < 8 || g > 11)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 10)
        {
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("sunbathe_guys1",act(0));
    }
    if(action == "sunbathe_guys1")
    {
        root->incTime(5);
        root->setBoyName("Митька");
        root->sVSex(dick, 16);
        g = getRandInt(5,14);
        if (g == 8)
            root->sVSex(pose,2);
        else if(g < 8 || g > 11)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 10)
        {
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("gadbeach",act(1));
    }
    if(action == "guys_river0")
    {
        root->incTime(5);
        root->setBoyName("Васян");
        root->sVSex(dick,14);
        root->sVSex(silavag,0);
        root->uVSkill(domination,-1);

        g = getRandInt(17,24);
        if (g < 19 || g > 22)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        root->setDesc(str(13));
        if(g < 21)
        {
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("guys_river1",act(5));
    }
    if(action == "guys_river1")
    {
        root->incTime(5);
        root->setBoyName("Митяй");
        root->sVSex(dick,16);
        g = getRandInt(17,24);
        if (g < 19 || g > 22)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 21)
        {
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("guys_river2",act(0));
    }
    if(action == "guys_river2")
    {
        root->incTime(5);
        root->setBoyName("Колямба");
        root->sVSex(dick,15);
        g = getRandInt(17,24);
        if (g < 19 || g > 22)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 21)
        {
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("gadukino",act(1));
    }
    if(action == "gadukino")
    {
        root->changeLoc(lgadukino,10);
    }
    if(action == "guy_river0")
    {
        root->incTime(15);
        QString boys[] {"Митька", "Колямба", "Васян"};
        int dicks[] {16,15,14};
        root->setBoyName(boys[i]);
        root->sVSex(dick,dicks[i]);
        root->sVSex(silavag,0);
        if(root->vBody(makeup) > 1)
        {
            root->sVBody(makeup,0);
            root->uVStatus(vidageday,-1);
        }
        if(root->vBody(throat) < root->vSex(dick))
            root->uVBody(throat,1);
        root->setImage(media(1));
        root->setDesc(str(14));
        makeActBtn("guy_river1",act(0));
    }
    if(action == "guy_river1")
    {
        root->incTime(5);
        g = getRandInt(17,24);
        if (g < 19 || g > 22)
            root->sVSex(pose,1);
        else
            root->sVSex(pose,0);
        root->setImage(media(0));
        if(g < 21)
        {
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else
        {
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("gadukino",act(1));
    }
    if(action == "exit")
    {
        root->changeLoc(lgadbeach,0);
    }
    if(action == "guys_beach0")
    {
        root->setBoyName("Колямба");
        root->sVSex(silavag,0);
        root->sVSex(pose,2);
        root->sVSex(dick,15);
        root->incTime(5);
        root->uVStatus(horny,10);
        g = getRandInt(0,2);
        root->setImage(media(2));
        root->setDesc(str(19));
        root->sVSex(protect,1);
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("guys_beach01",act(8));
    }
    if(action == "guys_beach01")
    {
        root->setBoyName("Васян");
        root->sVSex(silavag,0);
        root->sVSex(dick,14);
        root->incTime(5);
        root->uVStatus(horny,10);
        if(i == 0)
        {
            root->sVSex(pose,0);
            root->setImage(media(3));
            root->setDesc(str(20));
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else if(i == 1)
        {
            root->uVSC(blowJob,1);
            root->setImage(media(4));
            root->setDesc(str(21));
            root->blow_job();
            root->fnswallow();
        }
        else
        {
            root->sVSex(pose,1);
            root->setImage(media(5));
            root->setDesc(str(22));
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("exit",act(6));
    }
    if(action == "guys_beach1")
    {
        root->setBoyName("Колямба");
        root->uVStatus(horny,10);
        root->incTime(5);
        root->sVSex(dick,15);
        root->uVSC(blowJob,1);
        root->setImage(media(6));
        root->setDesc(str(23));
        root->blow_job();
        root->fnswallow();
        makeActBtn("guys_beach11",act(8));
    }
    if(action == "guys_beach11")
    {
        root->setBoyName("Васян");
        root->sVSex(dick,14);
        root->sVSex(silavag,0);
        root->incTime(5);
        root->uVStatus(horny,10);
        i = getRandInt(0,2);
        if(i == 0)
        {
            root->setImage(media(3));
            root->setDesc(str(24));
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else if(i == 1)
        {
            root->uVSC(blowJob,1);
            root->setImage(media(4));
            root->setDesc(str(25));
            root->blow_job();
            root->fnswallow();

        }
        else
        {
            root->sVSex(pose,1);
            root->setImage(media(7));
            root->setDesc(str(26));
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("exit",act(6));
    }
    if(action == "guys_beach2")
    {
        root->setBoyName("Колямба");
        root->uVStatus(horny,10);
        root->incTime(5);
        root->sVSex(dick,15);
        root->sVSex(pose,1);
        root->setImage(media(8));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        makeActBtn("guys_beach21",act(8));
    }
    if(action == "guys_beach21")
    {
        root->setBoyName("Васян");
        root->sVSex(dick,14);
        root->sVSex(silavag,0);
        root->incTime(5);
        root->uVStatus(horny,10);
        i = getRandInt(0,2);
        if(i == 0)
        {
            root->sVSex(pose,0);
            root->setImage(media(3));
            root->setDesc(str(24));
            root->sVSex(protect,1);
            root->sexStart();
            root->vaginal(tDick);
            root->sex_cum();
        }
        else if(i == 1)
        {
            root->uVSC(blowJob,1);
            root->setImage(media(4));
            root->setDesc(str(25));
            root->blow_job();
            root->fnswallow();
        }
        else
        {
            root->sVSex(pose,1);
            root->setImage(media(5));
            root->setDesc(str(26));
            root->analStart(tDick);
            root->anal(tDick);
            root->anal_cum();
        }
        makeActBtn("exit",act(6));
    }

    if(action == "wash_horse")
    {
        root->incTime(30);
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->uVStatus(mood,5);
        root->sVJob(JobStatus::horse_river,3);
        root->uVStatus(horny,getRandInt(5,15));
        QString txt;
        if(root->gVEvent(mirainriver) == 1)
            txt = str(29);
        if(root->getClothGroup() == swimsuit)
        {
            root->setImage(media(10));
            root->setDesc(str(28) + txt + str(30));
        }
        else if(root->isNude())
        {
            root->setImage(media(11));
            root->setDesc(str(28) + txt + str(31));
        }
        else
        {
            root->setImage(media(9));
            root->setDesc(str(32));
            root->decCondition(1);
        }
        makeActBtn("gadbeach",act(1));
    }
    if(action == "horse_home")
    {
        if(root->isCloth() || (root->getClothGroup() > 0 && root->vSC(exhibi) > 0))
        {
            root->incTime(30);
            root->sVJob(JobStatus::horse_river,0);
            root->sVEvent(mirainriver,0);
            root->uVEvent(grandmahelp,1);
            root->uVQuest(grandpaQW,1);
            root->sVStatus(inriver,0);
            root->setImage(media(12));
            root->setDesc(str(33));
            makeActBtn("gadsarai",act(0));
        }
        else
        {
            root->setImage(media(12));
            root->setDesc(str(34));
            makeActBtn("horse_river",act(0));
        }

    }

    if(action == "fishers_hello")
    {
        root->sVEvent(fishersday, root->vStatus(daystart));
        root->incTime(5);
        if(root->gVQuest(fishersQW) < 3)
            root->uVQuest(fishersQW,1);
        root->setImage(media(13));
        if(root->gVQuest(fishersQW) >= 3)
            makeActBtn("talk_fishers",act(12));
        if(root->gVQuest(fishersQW) == 4)
            makeActBtn("fish_please",act(13));
        if(root->gVQuest(fishersQW) == 5)
            makeActBtn("fishing_with_fishers",act(14));
        makeActBtn("gadriver",act(6));
    }
    if(action == "talk_fishers")
    {
        root->incTime(30);
        if(root->gVQuest(fishersQW) == 3)
            root->sVQuest(fishersQW,4);
        root->setImage(media(14));
        root->setDesc(str(35));
        makeActBtn("gadriver",act(6));
    }
    if(action == "fish_please")
    {
        root->incTime(5);
        root->sVQuest(fishersQW,5);
        root->setImage(media(14));
        root->setDesc(str(36));
        makeActBtn("fishing",act(15));
    }
    if(action == "fishing_with_fishers")
    {
        root->incTime(5);
        root->setImage(media(14));
        root->setDesc(str(37));
        makeActBtn("fishing",act(15));
    }
    if(action == "gadriver")
    {
        root->changeLoc(lgadriver,5);
    }
    if(action == "Cast_a_fishing_rod")
    {
        int f = 0;
        root->incTime(10);
        if(root->getHour() < 10)
            f = getRandInt(10,20);
        else if(root->getHour() >= 12 && root->getHour() < 18)
            f = getRandInt(0,20);
        else
            f = getRandInt(5,20);

        root->setImage(media(15));
        root->setDesc(str(40));
        if(f > 15)
        {
            root->incTime(1);
            root->addDesc(str(41));
            makeActBtn("pull_rod",act(17));
        }
        else
        {
            root->addDesc(str(42));
            makeActBtn("fishing",act(18));
        }
    }
    if(action == "pull_rod")
    {
        root->incTime(1);
        f = getRandInt(0,120);
        if(getRandInt(0,100) < 30)
            root->uVSkill(react,1);
        if(root->vSkill(react) > f)
        {
            root->uVStatus(mood,20);
            root->uVSkill(react,1);
            root->uVStatus(fish,1);
            root->setImage(media(16));
            root->setDesc(str(43));
        }
        else
        {
            root->uVStatus(mood,-10);
            root->setImage(makeImage(media(17),root->isDay(),root->getMonth()));
            root->setDesc(str(44));
        }
        makeActBtn("fishing",act(18));
    }
    if(action == "finish_fish")
    {
        root->incTime(5);
        root->setImage(media(14));
        root->setDesc(str(45));
        if(root->vStatus(fish) > 0)
            root->startEvent(eRiverEvents,"fishing_end");
        else
            makeActBtn("gadriver",act(6));
    }
    if(action == "free_fish")
    {
        root->incTime(5);
        root->sVStatus(fish,0);
        root->sVStatus(mood,100);
        root->setImage(media(14));
        root->setDesc(str(46));
        makeActBtn("gadriver",act(6));
    }
    if(action == "give_fish_fishers")
    {
        root->incTime(5);
        root->sVStatus(fish,0);
        root->setImage(media(14));
        root->setDesc(str(47));
        makeActBtn("gadriver",act(6));
    }
    if(action == "take_for_cat")
    {
        root->incTime(25);
        root->uVStatus(fish,-1);
        root->uVStatus(mood,20);
        root->setImage(media(18));
        root->setDesc(str(48));
        root->uVEvent(grandmahelp,root->vStatus(fish));
        root->sVStatus(fish,0);
        makeActBtn("gadhouse",act(1));
    }
    if(action == "gadhouse")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "savefish_for_myself")
    {
        root->incTime(5);
        root->uVStatus(eda,root->vStatus(fish));
        root->setImage(media(19));
        root->setDesc(str(49));
        root->sVStatus(fish,0);
        makeActBtn("gadriver",act(1));
    }
}

void RiverEvents::mira_in_river()
{
    int m = getRandInt(1,10);
    int hour = root->getHour();
    int mira_in_river = root->gVEvent(mirainriver);
    int quest_mira = root->gVQuest(miraQW);
    int temper = root->getTemp();
    int no_mira = root->gVEvent(Mira_no);
    int sunWeather = root->getSunWeather();
    if(root->gVEvent(mira_go_blok) == 0 && mira_in_river == 1 && (m == 5 || hour == 20))
    {
        root->clearActions();
        root->sVEvent(mirainriver,2);
        root->incTime(5);
        root->sVEvent(mira_go_blok,2);
        root->sVEvent(mira_no_home,0);
        root->setImage(media(20));
        root->setDesc(str(0));
        makeActBtn("gadbeach",act(0));
    }
    if(quest_mira > 0 && root->vStatus(inriver) == 1 && no_mira == 0 && mira_in_river == 0 && m > 7 && hour > 8 && hour < 20 && sunWeather >= 0 && temper >= 20)
    {
        root->clearActions();
        root->sVEvent(mirainriver,1);
        root->sVEvent(mira_go_river,1);
        root->incTime(5);
        root->sVEvent(mira_go_blok,2);
        root->setImage(media(21));
        root->setDesc(str(1));
        if(root->isNude() && root->gVEvent(miratalkforest) < 3 && root->vStatus(shamelessFlag) == 0)
            root->redress(ClothType::Main,new ClothMain(2,swimsuit,"Купальник"));
        makeActBtn("gadbeach",act(0));
    }
    if(quest_mira > 0 && root->vStatus(inriver) == 0 && no_mira == 0 && mira_in_river == 0 && m < 3 && hour > 8 && hour < 20 && sunWeather >= 0 && temper >= 20)
    {
        root->clearActions();
        root->sVEvent(mirainriver,1);
        root->incTime(5);
        root->sVEvent(mira_go_blok,2);
        root->setImage(media(22));
        root->setDesc(str(2));
        makeActBtn("gadbeach",act(0));
    }
}

void RiverEvents::mira_punish()
{
    root->clearActions();
    root->incTime(10);
    root->uVStatus(horny,getRandInt(25,75));
    root->setImage(media(23));
    root->setDesc(str(3));
    makeActBtn("gadbeach",act(0));
}

void RiverEvents::swim_guys()
{
    g = getRandInt(0,15);
    if(root->gVEvent(guysriver) != root->getDay())
    {
        root->sVEvent(guysriver,root->getDay());
        int mira_in_river = root->gVEvent(mirainriver);
        int mitka_sex_times = root->gVEvent(mitkasextimes);
        int hour = root->getHour();
        if(root->getClothGroup() == swimsuit)
        {
            if(mira_in_river == 0 && mitka_sex_times >= 13 && hour >= 8 && hour < 20)
            {
                root->incTime(10);
                root->uVSkill(domination,-1);
                root->cum("lip");
                root->cum("face");
                root->uVSC(gangBang,1);
                root->uVSC(blowJob,1);
                root->uVSC(swallow, getRandInt(1,3));
                root->setImage(media(24));
                root->setDesc(str(4));
                makeActBtn("gadbeach", act(1));
            }
            else if(mira_in_river == 0 && mitka_sex_times >= 13 && hour >= 8 && hour < 20 && root->vSkill(domination) < 0)
            {
                i = getRandInt(0,2);
                QString boys[] {"Митька", "Колямба", "Васян"};
                QString boys2[] {"Митьку", "Колямбу", "Васяна"};
                int dicks[] {16,15,14};

                root->setBoyName(boys[i]);
                root->sVSex(dick, dicks[i]);
                root->sVSex(silavag,0);
                root->sVSex(pose,1);
                if(i == 0)
                    root->setImage(media(26));
                else if(i == 1)
                    root->setImage(media(27));
                else if(i == 2)
                    root->setImage(media(28));
                root->setDesc(str(5));
                root->addDesc(boys2[i]);
                root->addDesc(str(6));
                makeActBtn("stand_in_pose", act(2));
            }
        }
        else
        {
            if(mira_in_river == 0 && mitka_sex_times >= 13 && hour >= 8 && hour < 20)
            {
                root->incTime(5);
                root->setBoyName("Митька");
                root->sVSex(dick, 16);
                root->sVSex(silavag,0);
                root->uVSC(gangBang,1);
                root->uVSkill(domination,-1);
                g = getRandInt(5,14);
                if (g == 8)
                    root->sVSex(pose,2);
                else if(g < 8 || g > 11)
                    root->sVSex(pose,1);
                else
                    root->sVSex(pose,0);
                root->setImage(media(0));
                root->setDesc(str(7));
                if(g < 10)
                {
                    root->vaginal(tDick);
                    root->sex_cum();
                }
                else
                {
                    root->anal(tDick);
                    root->anal_cum();
                }
                makeActBtn("swim_guys0",act(0));
            }
        }
    }
}

void RiverEvents::sunbathe_guys()
{
    g = getRandInt(0,15);
    if(root->gVEvent(guysriver) != root->getDay())
    {
        root->sVEvent(guysriver,root->getDay());
        int mira_in_river = root->gVEvent(mirainriver);
        int mitka_sex_times = root->gVEvent(mitkasextimes);
        int hour = root->getHour();
        ClothMain* ptr = (ClothMain*)root->getCloth(ClothType::Main);
        if(mira_in_river == 0 && mitka_sex_times >= 13 && g == 0 && hour >= 8 && hour < 20)
        {
            root->incTime(5);
            root->setBoyName("Колямба");
            root->sVSex(silavag,0);
            root->sVSex(dick,15);
            root->uVSkill(domination,-1);
            root->uVSC(gangBang,1);
            g = getRandInt(5,14);
            if (g == 8)
                root->sVSex(pose,2);
            else if(g < 8 || g > 11)
                root->sVSex(pose,1);
            else
                root->sVSex(pose,0);
            root->setImage(media(0));
            root->setDesc(str(8));
            if(g < 10)
            {
                root->vaginal(tDick);
                root->sex_cum();
            }
            else
            {
                root->anal(tDick);
                root->anal_cum();
            }
            makeActBtn("sunbathe_guys0",act(0));
        }
        else if(mira_in_river == 1 && ptr->getClothGroup() == swimsuit && root->gVQuest(miragopQW) >= 15 && g == 1 && hour >= 8 && hour < 20)
        {
            root->incTime(15);
            root->uVStatus(horny,20);
            root->uVSkill(domination,5);
            root->setImage(media(25));
            root->setDesc(str(9));
            makeActBtn("gadbeach",act(1));
        }
    }

}

void RiverEvents::guys_river()
{
    root->sVEvent(guysriver,root->getDay());
    root->incTime(10);
    root->uVStatus(horny,10);
    root->uVSkill(domination,-1);
    i = getRandInt(1,2);
    if(i == 1)
    {
        root->setImage(media(29));
        root->setDesc(str(10));
        makeActBtn("guys_river0",act(3));
    }
    else
    {
        i = getRandInt(0,2);
        QString boys2[] {"Митьку", "Колямбу", "Васяна"};
        if(i == 0)
            root->setImage(media(26));
        else if(i == 1)
            root->setImage(media(27));
        else if(i == 2)
            root->setImage(media(28));
        root->setDesc(str(11));
        root->addDesc(boys2[i]);
        root->addDesc(str(12));
        makeActBtn("guy_river0",act(4));
    }
    if(root->vSkill(domination) > 0)
        makeActBtn("exit",act(6));
}

void RiverEvents::guys_beach()
{
    root->sVEvent(guysriver,root->getDay());
    root->incTime(5);
    root->uVStatus(horny,10);
    g = getRandInt(1,3);
    root->setImage(media(30));
    root->setDesc(str(15));
    if(g == 1)
    {
        root->addDesc(str(16));
        makeActBtn("guys_beach0",act(7));
    }
    else if(g == 2)
    {
        root->addDesc(str(17));
        makeActBtn("guys_beach1",act(7));
    }
    else
    {
        root->addDesc(str(18));
        makeActBtn("guys_beach2",act(7));
    }
    if(root->vSkill(domination) > 0)
        makeActBtn("exit",act(6));
}

void RiverEvents::horse_river()
{
    root->incTime(5);
    root->sVStatus(inriver,1);
    root->setImage(media(31));
    root->setDesc(str(27));
    if(root->gVJob(JobStatus::horse_river) == 2)
        makeActBtn("wash_horse",act(9));
    if(root->gVJob(JobStatus::horse_river) == 3)
        makeActBtn("horse_home",act(10));
    makeActBtn("gadbeach",act(6));
}

void RiverEvents::fishers()
{
    root->clearActions();
    root->incTime(5);
    root->setImage(media(32));
    if(root->gVEvent(fishersday) != root->vStatus(daystart) || root->vStatus(daystart) == 0)
        makeActBtn("fishers_hello",act(11));
    makeActBtn("gadriver",act(6));
}

void RiverEvents::fishing()
{
    root->setImage(makeImage(media(17),root->isDay(),root->getMonth()));
    root->setDesc(str(38));
    if(root->getHour() < root->getSunset())
    {
        makeActBtn("Cast_a_fishing_rod",act(16));
        makeActBtn("finish_fish",act(1));
    }
    else
    {
        root->incTime(5);
        root->uVStatus(mood,-10);
        root->setImage(media(14));
        root->setDesc(str(39));
        if(root->vStatus(fish) > 0)
            root->startEvent(eRiverEvents,"fishing_end");
        else
            makeActBtn("gadriver",act(6));
    }
}

void RiverEvents::fishing_end()
{
    makeActBtn("free_fish",act(19));
    makeActBtn("give_fish_fishers",act(20));
    makeActBtn("take_for_cat",act(21));
    makeActBtn("savefish_for_myself",act(22));
}

void RiverEvents::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"riverevents");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &RiverEvents::actionHandler);
    root->addActBtn(btn);
}

QString RiverEvents::str(int id)
{
    QString str[50];
    str[0] = "- Светик, мне пора домой, - сказала вам Мира и стала собираться.";
    str[1] = "Вы загорали, когда на речке появилась Мира.";
    if(root->getCloth(ClothType::Main) == nullptr && root->gVEvent(miratalkforest) < 3 && root->vStatus(shamelessFlag) == 0)
        str[1] += " Покраснев, вы быстренько натянули свой купальник, и улеглись загорать дальше.";
    str[1] += "Улыбнувшись вам, она разделась и принялась растилать свое покрывало рядом с вашим.";
    str[2] = "Придя на пляж, вы увидели загорающую на покрывале Мирославу.";
    str[3] = "Вы подходите к ней поближе и Мирослава радостно вам улыбается, прося освободить ее. Пока вы развязываете"
             " ее, она вам рассказывает, что это ее так Колямба наказал за то, что она слегка укусила его за член, когда "
             "сосала ему...<br>- Слава богу, - со вздохом облегчения добавляет она к своему рассказу. - Хорошо, что это ты"
             " мне попалась, а не кто-нибудь другой. Представляешь, какая бы картина была, - голая Мирка, распятая между "
             "деревьями, - подходи и делай, что хочешь, хоть трахай, хоть бей, убивай... Ну да пронесло, спасибо тебе, "
             "Светик, ты меня здорово выручила!";
    str[4] = "Едва вы собрались вылезать из воды, как услышали на берегу громкий мужской гогот, а через пару мгновений "
             "у воды уже стояли деревенские пацаны с ухмыляющимся Митькой во главе. Они быстро вошли в воду и без "
             "предисловий начали по очереди трахать вас в рот. Кончив, они двинулись своей дорогой дальше, оставив "
             "вас на пляже с обконченым лицом и полным ртом спермы.";
    str[5] = "Едва вы вылезли из воды, как наткнулись на ухмыляющегося ";
    str[6] = ". Тот не терпящим возражений тоном потребовал, чтобы вы разделись и встали в позу...";
    str[7] = "Едва вы вылезли из воды, как наткнулись на пацанов, которые как раз шли куда-то на рыбалку. Увидев, что "
             "вы купаетесь голышом, они тут же не преминули вами попользоваться, совершенно не интересуясь вашим мнением.";
    str[8] = "Через некоторое время вы слышите мужские голоса, которые стремительно приближаются, а уже через пару минут "
             "перед вами появляются деревенские пацаны. Увидев вас, они заметно оживляются и через пару минут, несмотря "
             "на все ваши вялые протесты, начинают иметь вас во все дыры...";
    str[9] = "Через некоторое время вы слышите мужские голоса, которые стремительно приближаются, а уже через пару минут "
             "перед вами появляются деревенские пацаны. Увидев Мирославу, они тут же начинают похабно улыбаться, а через"
             " пару минут, ничуть вас не стесняясь, раскладывают ее на песке и начинают сношать во все щели...";
    str[10] = "По дороге вы встречаете деревенских пацанов и те настойчиво приглашают вас пройтись с ними.";
    str[11] = "По дороге вы встречаете ";
    str[12] = " и тот требовательно приглашает вас к себе домой...";
    str[13] = "Пацаны приводят вас к Васяну домой, где, не церемонясь, по очереди, начинают сношать.";
    str[14] = "Вы пришли к парню домой, где он тут же поставил вас на колени. Его член уперся вам в ваши " +
             root->getLipTalk3() + " вы приоткрыли их и впустили его в свой рот. Твердый член заполнял весь ваш "
             "рот, обхватывая его губами вы каждым движением его вбирали до горла. " + root->getBoyName() + " взял вас за волосы и "
             "стал трахать вас в рот, от ударов члена в горло у вас потекли слезы из глаз.";
    str[15] = "- О, Светик, нам-то как раз тебя и не хватало, - заулыбался Колямба, увидев вас на пляже.";
    str[16] = "- Вроде вокруг никого, а ебаться хочется, так что давай, раздвигай ножки, поработай своей пизденкой...";
    str[17] = "- Пососи нам, а? А мы тебе век благодарны будем, ха-ха!";
    str[18] = "- Подставляй свою жопку, а то мне ох как охота кончить в нее...";
    QString add;
    if(root->getCloth(ClothType::Panties) != nullptr)
        add = "сняли трусы и ";
    str[19] = "Вы быстро " + add + "залезли на умостившегося Колямбу, рукой нащупывая его член.";
    str[20] = "Вы перевернулись на спину и призывно распахнули Васяну ноги.";
    str[21] = "Васян подходит к вам и бесцеремонно вываливает перед вашим лицом свой член.";
    str[22] = "Васян ставит вас раком и пристраивается к вашему анусу.";
    str[23] = "Вы сгибаетесь возле развалившегося Колямбы и подносите его член к своим губам...";
    str[24] = "Вы перевернулись на спину и призывно распахнули Васну ноги.";
    str[25] = "Васян подходит к вам и бесцеремонно вываливает перед вашим лицом свой член.";
    str[26] = "Васян ставит вас раком и пристраивается к вашему анусу.";
    str[27] = "Дедушкин помощник - конь Буян.";
    str[28] = "Вы в течение часа мыли и отскребали ";
    str[29] = "с Мирой ";
    str[30] = "коня Буяна.";
    str[31] = "коня Буяна. И были при этом совершенно голенькие.";
    str[32] = "Вы в течение часа мыли и отскребали коня Буяна прямо в одежде.";
    str[33] = "Вы взяли коня под уздцы и отправились с ним домой.";
    str[34] = "<b>Вы не можете появиться в таком виде в деревне.</b>";
    str[35] = "Подойдя к рыбакам вы весело спрашиваете у них как поклевка. Один из них, в этот раз с явной охотой,"
              " оборачивается к вам и вы минут десять болтаете о рыбе и особенностях местной рыбалки.";
    str[36] = "Вы решаете тоже попробовать порыбачить и спрашиваете у рыбаков, не одолжат ли они вам удочку. Уже знакомый"
              " вам Дядя Степа с охотой протягивает вам одну из своих удочек.";
    str[37] = "Вы решаете присоединиться к своим знакомым и дядя Степа охотно дает вам одну из своих удочек, при этом масляными"
              " глазками не забывая пройтись вдоль вашего тела.";
    str[38] = "Небольшая речка тихо плещет свои неглубокие воды, приятно щекоча слух деревенским умиротворением и спокойствием."
              "<br>Вы поймали " + intQStr(root->vStatus(fish)) + " рыб";
    if(root->vStatus(fish) == 1)
        str[38] += "у";
    else if(root->vStatus(fish) < 5)
        str[38] += "ы";
    str[38] += ".";

    str[39] = "Дядя Степа говорит, что уже собирается домой, поэтому вы с расстроенным видом отдаете ему удочку, понимая, что на сегодня все.";
    str[40] = "Вы ловите рыбку, внимательно наблюдая за поплавком.";
    str[41] = "Внезапно поплавок резко ныряет под воду.";
    str[42] = "Но тот остается совершенно неподвижным и вы решаете сменить наживку.";
    str[43] = "Вы ловко подсекаете, чувствуя, как напрягается удилище, и через секунду азартно вытаскиваете небольшую рыбёшку.";
    str[44] = "Вы подсекаете, но слишком поздно, рыбы на крючке уже нет.";
    str[45] = "Вам надоедает и вы отдаете дяде Степе его удочку.";
    str[46] = "Вы решаете выпустить всю наловленную рыбу, на что мужики только неодобрительно покачивают головой, кидая косые взгляды"
              " на улепетывающую на глубину рыбешку.";
    str[47] = "Вы отдаете всю наловленную рыбу дяде Степе и тот с напускной неохотой принимает ее, хотя по всему его виду видно, что он "
              "вполне доволен таким раскладом.";
    str[48] = "Едва вы входите в дом, как пушистая зверюга тут же оказывается у вас под ногами, чувствуя запах свежей рыбы. Вы угощаете"
              " Бонифация одной рыбкой и тот довольно урчит, хрустя косточками.";
    if(root->vStatus(fish) > 0)
        str[48] += "Остальную рыбу вы отдаёте бабушке, и та благодарно вам улыбнулась.";
    str[49] = "Вы кладёте " + intQStr(root->vStatus(fish)) + " рыбин";
    if(root->vStatus(fish) == 1)
        str[49] += "у";
    else if(root->vStatus(fish) < 5)
        str[49] += "ы";
    str[49] = " в пакетик и прощаетесь с рыбаками.";
    return str[id];
}

QString RiverEvents::act(int id)
{
    QString str[23];
    str[0] = "Далее";
    str[1] = "Закончить";
    str[2] = "Нагнуться";
    str[3] = "Идти с ними";
    str[4] = "Идти с ним";
    str[5] = "Дать Митяю";
    str[6] = "Уйти";
    str[7] = "Обслужить Колямбу";
    str[8] = "Обслужить Васяна";
    str[9] = "Вымыть коня";
    str[10] = "Отвести коня домой";

    str[11] = "Поздороваться";
    str[12] = "Поболтать";
    str[13] = "Попроситься к ним";
    str[14] = "Порыбачить с ними";
    str[15] = "Рыбачить";
    str[16] = "Забросить удочку";
    str[17] = "Тянуть";
    str[18] = "Надеть наживку";
    str[19] = "Выпустить рыбу";
    str[20] = "Отдать рыбакам";
    str[21] = "Отнести Бонифацию";
    str[22] = "Оставить себе(продукты)";
    return str[id];
}

QString RiverEvents::media(int id)
{
    QString med[33];
    med[0] = "data/sex/gadriver/" + intQStr(g) + ".gif";
    med[1] = "data/sex/gadriver/25.gif";
    med[2] = "data/sex/gadriver/8.gif";
    med[3] = "data/sex/gadriver/9.gif";
    med[4] = "data/sex/gadriver/26.gif";
    med[5] = "data/sex/gadriver/13.gif";
    med[6] = "data/sex/gadriver/27.gif";
    med[7] = "data/sex/gadriver/14.gif";
    med[8] = "data/sex/gadriver/12.gif";
    med[9] = "data/npc/horse/wash.jpg";
    QString add;
    if(root->gVEvent(mirainriver) == 1)
        add = "_mira";
    med[10] = "data/npc/horse/wash_swim" + add + ".jpg";
    med[11] = "data/npc/horse/wash_nude" + add + ".jpg";
    if(root->isNude())
        add = "_nude";
    else if(root->getClothGroup() == swimsuit)
        add = "_swim";
    med[12] = "data/npc/horse/lead" + add + ".jpg";
    med[13] = "data/locations/gadukino/river/fishers/say_hello.jpg";
    med[14] = "data/locations/gadukino/river/fishers/talk.jpg";
    med[15] = "data/locations/gadukino/river/fishers/fishing.jpg";
    med[16] = "data/locations/gadukino/river/fishers/fish.jpg";
    med[17] = "data/locations/gadukino/river/gadriver.jpg";
    med[18] = "data/npc/cat/feed.jpg";
    if(root->vStatus(fish) <= 7)
        add = intQStr(root->vStatus(fish));
    else if(root->vStatus(fish) <= 10)
        add = intQStr(8);
    else if(root->vStatus(fish) <= 20)
        add = intQStr(9);
    else
        add = intQStr(10);
    med[19] = "data/locations/gadukino/river/fish" + add + ".jpg";
    if(root->isNude())
        add = "_nude";
    med[20] = "data/locations/gadukino/river/events/mira_go_home" + add + ".jpg";
    med[21] = "data/locations/gadukino/river/events/mira_go_river" + add + ".jpg";
    med[22] = "data/locations/gadukino/river/events/mira_in_river.jpg";
    med[23] = "data/locations/gadukino/river/events/mira_punish.jpg";
    med[24] = "data/sex/gadriver/" + intQStr(getRandInt(1,3)) + ".jpg";
    med[25] = "data/sex/gadriver/" + intQStr(getRandInt(15,16)) + ".jpg";
    med[26] = "data/npc/gadukino/mitka/mitka.jpg";
    med[27] = "data/npc/gadukino/mitka/kolyamba.jpg";
    med[28] = "data/npc/gadukino/mitka/vasyan.jpg";
    med[29] = "data/npc/gadukino/mitka/3boys.1.jpg";
    med[30] = "data/locations/gadukino/river/events/gays_river.jpg";
    med[31] = "data/npc/horse/river.jpg";
    med[32] = "data/locations/gadukino/river/fishers/fishers.jpg";

    return med[id];
}
