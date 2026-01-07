#include "gadukino_events.h"
#include <QDebug>
#include "../eventhandler.h"
#include "../../Functions.h"
#include "../../menu/qactbutton.h"

void GadukinoEvent::start(QString arg)
{
    if(arg == "gadsarai_check")
        gadsarai_check();
    if(arg == "walk")
        walk();
    if(arg == "mira_apologise")
        mira_apologise();
    if(arg == "gang_apologise")
        gang_apologise();
    if(arg == "gadrivergang")
        gadrivergang();
    if(arg == "gadukino_mitka")
        gadukino_mitka();
    if(arg == "gadukino_kolyamba")
        gadukino_kolyamba();
    if(arg == "gadukino_vasyan")
        gadukino_vasyan();
    if(arg == "gadukino_2boys")
        gadukino_2boys();
    if(arg == "mira_mitka")
        mira_mitka();
    if(arg == "mira_kolyamba")
        mira_kolyamba();
    if(arg == "mira_vasyan")
        mira_vasyan();
    if(arg == "mira_2boys")
        mira_2boys();
    if(arg == "mira_3boys")
        mira_3boys();
    if(arg == "go_home")
        go_home();
    if(arg == "go_home_ender")
        go_home_ender();
    if(arg == "to_gadukino")
        to_gadukino();
    if(arg == "collection_point")
        collection_point();
    if(arg == "gadukino_back")
        gadukino_back();
    if(arg == "gadukino_nude")
        gadukino_nude();
    if(arg == "gadukino_nude_end")
        gadukino_nude_end();
    if(arg == "gadriver_nude")
        gadriver_nude();
    if(arg == "gadriver_nude_end")
        gadriver_nude_end();
    if(arg == "onlooker")
        onlooker();
    if(arg == "gadukino_onlooker")
        gadukino_onlooker();
    if(arg == "gadukino_onlooker_woman")
        gadukino_onlooker_woman();
    if(arg == "gadukino_onlooker_man")
        gadukino_onlooker_man();
    if(arg == "gadukino_end")
        gadukino_end();
    if(arg == "pack_things")
        pack_things();
    if(arg == "punishment")
        punishment();
    if(arg == "absolution")
        absolution();
    if(arg == "offense")
        offense();
    if(arg == "clearing_basket")
        clearing_basket();
}

void GadukinoEvent::actionHandler(QString action)
{
    root->clearActions();
    if(action == "go_meadow")
    {
        root->sVEvent(meadow,1);
        root->incTime(20);
        root->setImage(media(0));
        root->setDesc(str(1));
        makeActBtn("to_gaddvor", act(1));
    }
    if(action == "help_mira")
    {
        root->sVQuest(miraQW,1);
        root->incTime(15);
        root->setImage(media(1));
        root->setDesc(str(3));
        makeActBtn("to_gadukino",act(3));
    }
    if(action == "show_pussy")
    {
        root->incTime(5);
        i = getRandInt(0,30);
        root->uVSkill(domination,1);
        if(root->gVEvent(mirasextimes) < 50)
        {
            if(i < 5)
            {
                root->setImage(media(2));
                root->setDesc(str(5));
            }
            else if(i >= 5 && i < 10)
            {
                root->setImage(media(2));
                root->setDesc(str(6));
            }
            else if(i >= 10 && i < 25)
            {
                root->setImage(media(3));
                root->setDesc(str(7));
            }
            else
            {
                root->setImage(media(5));
                root->setDesc(str(8));
            }
        }
        else
        {
            if(i < 5)
            {
                root->setImage(media(4));
                root->setDesc(str(9));
            }
            else
            {
                root->setImage(media(4));
                root->setDesc(str(10));
            }
        }
        makeActBtn("gadukino",act(5));
    }
    if(action == "watch_mirasex")
    {
        root->uVStatus(horny,10);
        root->incTime(5);
        i = getRandInt(0,1);
        root->setImage(media(6));
        root->setDesc(str(14));
        makeActBtn("gadukino",act(5));
    }
    if(action == "mira_apologise_next")
    {
        root->incTime(5);
        root->eventStart("Miroslava", "miraclothes");
        root->setDesc(str(37));
        makeActBtn("agree_mira_apologize",act(9));
        makeActBtn("disagree_mira_apologize",act(10));
    }
    if(action == "agree_mira_apologize")
    {
        root->incTime(5);
        root->uVStatus(horny,5);
        root->sVEvent(mirasex,2);
        root->eventStart("Miroslava", "miraclothes");
        root->setDesc(str(29));
        makeActBtn("mirasex_lick",act(8));
    }
    if(action == "mirasex_lick")
    {
        root->eventStart("mirasex","miralick_first");
    }
    if(action == "disagree_mira_apologize")
    {
        root->incTime(30);
        root->sVEvent(mirasex,3);
        root->eventStart("Miroslava", "miraclothes");
        root->setDesc(str(30));
        makeActBtn("gadukino",act(5));
    }
    if(action == "mitka_apologise_next")
    {
        root->incTime(5);
        root->setImage(media(7));
        root->setDesc(str(32));
        if(root->gVQuest(miragopQW) >= 12)
            root->addDesc(str(33));
        else
            root->addDesc(str(34));
        makeActBtn("gadukino",act(5));
    }
    if(action == "wait_gang_apologize")
    {
        root->incTime(5);
        root->setImage(media(8));
        root->setDesc(str(36));
        makeActBtn("gang_apologize_par2",act(8));
    }
    if(action == "gang_apologize_par2")
    {
        root->incTime(5);
        root->setImage(media(9));
        root->setDesc(str(37));
        makeActBtn("take_money",act(12));
        makeActBtn("dont_take_money",act(10));
    }
    if(action == "take_money")
    {
        root->incTime(5);
        root->uVSkill(domination,-1);
        root->sVEvent(gadriver_gang,2);
        root->uVStatus(money,10000);
        root->setImage(media(10));
        root->setDesc(str(38));
        makeActBtn("gadukino",act(5));
    }
    if(action == "dont_take_money")
    {
        root->incTime(5);
        root->uVSkill(domination,1);
        root->sVEvent(gadriver_gang,3);
        root->setImage(media(11));
        root->setDesc(str(39));
        makeActBtn("gadukino",act(5));
    }
    if(action == "run_from_gang")
    {
        root->incTime(15);
        root->setImage(media(12));
        root->setDesc(str(40));
        makeActBtn("meadow",act(8));
    }
    if(action == "gang_act1")
    {
        root->incTime(5);
        root->redress(ClothType::Main,nullptr);
        root->setBoyName("Пьяный мужик");
        root->setImage(media(13));
        root->setDesc(str(42));
        root->sVSex(dick, getRandInt(12,20));
        root->blow_job();
        makeActBtn("gang_act2",act(15));
    }
    if(action == "gang_act2")
    {
        root->incTime(5);
        root->setBoyName("Какой-то деревенский парень");
        root->setImage(media(14));
        root->setDesc(str(43));
        root->sVSex(dick, getRandInt(12,20));
        root->blow_job();
        makeActBtn("gang_act3",act(8));
    }
    if(action == "gang_act3")
    {
        root->incTime(5);
        root->setImage(media(15));
        root->setDesc(str(44));
        makeActBtn("gang_act4",act(8));
    }
    if(action == "gang_act4")
    {
        root->incTime(5);
        root->cum("lip");
        root->cum("face");
        root->cum("belly");
        root->setImage(media(16));
        root->setDesc(str(45));
        makeActBtn("gang_act5",act(8));
    }
    if(action == "gang_act5")
    {
        root->incTime(5);
        root->setBoyName("какой-то деревенский мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,1);
        root->setImage(media(17));
        root->setDesc(str(46));
        root->vaginal(tDick);
        makeActBtn("gang_act6",act(8));
    }
    if(action == "gang_act6")
    {
        root->incTime(5);
        root->setBoyName("мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        int temp = getRandInt(1,2);
        root->sVSex(protect,getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,1);
        root->setImage(media(18));
        root->setDesc(str(47));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act7",act(8));
    }
    if(action == "gang_act7")
    {
        root->incTime(5);
        root->setBoyName("Пьяный Мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        int temp = getRandInt(1,2);
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->setImage(media(19));
        root->setDesc(str(48));
        root->anal(tDick);
        if(temp == 2)
            root->anal_cum();
        makeActBtn("gang_act8", act(8));
    }
    if(action == "gang_act8")
    {
        root->incTime(5);
        root->setBoyName("Митька");
        root->sVSex(silavag, 0);
        root->sVSex(dick, 16);
        int temp = getRandInt(1,2);
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        root->uVSC(blowJob,1);
        root->setImage(media(20));
        root->setDesc(str(49));
        root->anal(tDick);
        if(temp == 2)
            root->anal_cum();
        makeActBtn("gang_act9", act(8));
    }
    if(action == "gang_act9")
    {
        root->incTime(5);
        root->setBoyName("дядя Степа");
        root->sVSex(silavag, 2);
        root->sVSex(dick, 22);
        int temp = getRandInt(1,2);
        root->sVSex(protect, getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,0);
        root->setImage(media(21));
        root->setDesc(str(50));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act10", act(8));
    }
    if(action == "gang_act10")
    {
        root->incTime(5);
        root->setBoyName("деревенский мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        int temp = getRandInt(1,2);
        root->sVSex(protect, getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,0);
        root->setImage(media(22));
        root->setDesc(str(51));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act11", act(8));
    }
    if(action == "gang_act11")
    {
        root->incTime(5);
        root->setBoyName("Васян");
        root->sVSex(silavag, 0);
        root->sVSex(dick, 14);
        int temp = getRandInt(1,2);
        root->sVSex(protect, getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->sVSex(pose,0);
        root->setImage(media(23));
        root->setDesc(str(52));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act12", act(8));
    }
    if(action == "gang_act12")
    {
        root->incTime(5);
        if(root->vStatus(health) < 100)
            root->sVStatus(health,100);
        root->setBoyName("Незнакомый пьяный парень");
        root->setImage(media(24));
        root->setDesc(str(53));
        root->sVSex(dick, getRandInt(12,20));
        root->blow_job();
        makeActBtn("gang_act13", act(8));
    }
    if(action == "gang_act13")
    {
        root->incTime(5);
        root->sVSex(dick, getRandInt(12,20));
        root->cum("face");
        root->setImage(media(25));
        root->setDesc(str(54));
        root->blow_job();
        root->fnswallow();
        root->addDesc(str(55));
        makeActBtn("gang_act14", act(8));
    }
    if(action == "gang_act14")
    {
        root->incTime(5);
        root->setBoyName("мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,1);
        root->setImage(media(26));
        root->setDesc(str(56));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act15", act(8));
    }
    if(action == "gang_act15")
    {
        root->incTime(5);
        root->setBoyName("незнакомый парень");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,1);
        root->setImage(media(27));
        root->setDesc(str(57));
        int temp = getRandInt(1,2);
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act16", act(8));
    }
    if(action == "gang_act16")
    {
        root->incTime(5);
        root->setBoyName("Парень");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        int temp = getRandInt(1,2);
        root->setImage(media(28));
        root->setDesc(str(58));
        root->anal(tDick);
        if(temp == 2)
            root->anal_cum();
        makeActBtn("gang_act17", act(8));
    }
    if(action == "gang_act17")
    {
        root->incTime(5);
        root->setBoyName("Пьяный Мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->setImage(media(29));
        root->anal(tDick);
        if(temp == 2)
            root->anal_cum();
        makeActBtn("gang_act18", act(8));
    }
    if(action == "gang_act18")
    {
        root->incTime(5);
        if(root->gVEvent(hantersKnow) == 0)
            root->setBoyName("Незнакомый мужик");
        else
            root->setBoyName("Андрей");
        if(root->gVEvent(hanterandreisex) == 0)
        {
            root->sVEvent(hanterandreisex,1);
            root->uVSex(guy,1);
        }
        root->sVSex(silavag, 0);
        root->sVSex(dick,20);
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->setImage(media(30));
        if(root->gVEvent(hantersKnow) == 0)
            root->setDesc(str(59));
        else
            root->setDesc(str(60));
        root->anal(tDick);
        if(temp == 2)
            root->anal_cum();
        makeActBtn("gang_act19", act(8));
    }
    if(action == "gang_act19")
    {
        root->incTime(5);
        root->setBoyName("мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,1);
        root->setImage(media(31));
        root->setDesc(str(61));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act20", act(8));
    }
    if(action == "gang_act20")
    {
        root->incTime(5);
        if(root->vStatus(health) < 100)
            root->sVStatus(health,100);
        root->setBoyName("мужик");
        root->setImage(media(32));
        root->setDesc(str(62));
        root->sVSex(dick, getRandInt(12,20));
        root->blow_job();
        makeActBtn("gang_act21", act(8));
    }
    if(action == "gang_act21")
    {
        root->incTime(5);
        root->setBoyName("незнакомец");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,2);
        root->setImage(media(33));
        root->setDesc(str(63));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act22", act(8));
    }
    if(action == "gang_act22")
    {
        root->incTime(5);
        root->setBoyName("выпивший парень");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,2);
        root->setImage(media(34));
        root->setDesc(str(64));
        root->blow_job();
        root->sVSex(dick, getRandInt(12,20));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        makeActBtn("gang_act23", act(8));
    }
    if(action == "gang_act23")
    {
        root->incTime(5);
        root->setBoyName("мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        root->uVSC(blowJob,1);
        root->uVSex(guy,1);
        root->sVSex(pose,2);
        root->setImage(media(35));
        root->vaginal(tDick);
        if(temp == 1)
            root->sex_cum();
        root->setDesc(str(65));
        makeActBtn("gang_act24", act(8));
    }
    if(action == "gang_act24")
    {
        root->incTime(5);
        root->setBoyName("незнакомый мужик");
        root->setBoy2Name("Колямба");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(dick2, 15);
        root->sVSex(protect, getRandInt(0,1));
        int temp = getRandInt(1,2);
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        root->uVSC(blowJob,2);
        root->uVSex(guy,2);
        root->setImage(media(36));
        root->double_penetration();
        root->setDesc(str(66));
        makeActBtn("gang_act25", act(8));
    }
    if(action == "gang_act25")
    {
        root->incTime(5);
        root->setBoyName("первый мужик");
        root->setBoy2Name("второй мужик");
        root->sVSex(silavag, getRandInt(0,2));
        root->sVSex(dick, getRandInt(12,20));
        root->sVSex(dick2, getRandInt(12,20));
        root->sVSex(protect, getRandInt(0,1));
        if(root->vSex(lubonus) == 0)
            root->sVSex(lubonus,1);
        root->uVSC(blowJob,2);
        root->uVSex(guy,2);
        root->setImage(media(37));
        root->setDesc(str(67));
        root->double_penetration();
        makeActBtn("gang_act26", act(8));
    }
    if(action == "gang_act26")
    {
        root->incTime(5);
        if(root->vStatus(health) < 100)
            root->sVStatus(health,100);
        root->setImage(media(38));
        root->setDesc(str(68));
        makeActBtn("gang_act27", act(8));
    }
    if(action == "gang_act27")
    {
        root->incTime(5);
        root->cum("lip");
        root->cum("face");
        root->uVSC(swallow,3);
        root->setImage(media(39));
        root->setDesc(str(69));
        makeActBtn("gang_act28", act(8));
    }
    if(action == "gang_act28")
    {
        root->incTime(5);
        root->cum("lip");
        root->cum("face");
        root->uVSC(swallow,3);
        root->uVSC(gangBang,1);
        root->uVSC(blowJob,20);
        root->setImage(media(40));
        root->setDesc(str(70));
        makeActBtn("gadbeach", act(8));
    }
    if(action == "mitkagadsex11")
    {
        root->sVEvent(mitkagadsex,1);
        root->sVEvent(mitboyrand,1);
        root->eventStart("mitkasex");
    }
    if(action == "mitkagadsex12")
    {
        root->sVEvent(mitkagadsex,1);
        root->sVEvent(mitboyrand,2);
        root->eventStart("mitkasex");
    }
    if(action == "mitkagadsex13")
    {
        root->sVEvent(mitkagadsex,1);
        root->sVEvent(mitboyrand,3);
        root->eventStart("mitkasex");
    }
    if(action == "mitkagadsex2")
    {
        root->sVEvent(mitkagadsex,2);
        root->eventStart("mitkasex");
    }
    if(action == "mitkaforestsex11")
    {
        root->sVEvent(mitkaforestsex,1);
        root->sVEvent(mitboyrand,1);
        root->eventStart("mitkasex");
    }
    if(action == "mitkaforestsex12")
    {
        root->sVEvent(mitkaforestsex,1);
        root->sVEvent(mitboyrand,2);
        root->eventStart("mitkasex");
    }
    if(action == "mitkaforestsex13")
    {
        root->sVEvent(mitkaforestsex,1);
        root->sVEvent(mitboyrand,3);
        root->eventStart("mitkasex");
    }
    if(action == "mitkaforestsex2")
    {
        root->sVEvent(mitkaforestsex,2);
        root->eventStart("mitkasex");
    }
    if(action == "mitkaforestsex3")
    {
        root->sVEvent(mitkaforestsex,3);
        root->eventStart("mitkasex");
    }
    if(action == "to_gadhouse")
    {
        root->changeLoc(lgadhouse,0);
    }
    if(action == "go_home_ender")
    {
        go_home_ender();
    }
    if(action == "my_bedroom")
    {
        root->changeLoc(lbedrpar);
    }
    if(action == "store_boletus")
    {
        root->incTime(30);
        root->uVStatus(money,root->vStatus(boletus)*150);
        root->setImage(media(41));
        root->setDesc(str(88));
        root->sVStatus(boletus,0);
        makeActBtn("collection_point",act(8));
    }
    if(action == "store_bilberry")
    {
        root->incTime(30);
        root->uVStatus(money,root->vStatus(bilberry)*75);
        root->setImage(media(41));
        root->setDesc(str(89));
        root->sVStatus(bilberry,0);
        makeActBtn("collection_point",act(8));
    }
    if(action == "collection_point")
    {
        collection_point();
    }
    if(action == "to_gadukino")
    {
        root->changeLoc(lgadukino,5);
    }
    if(action == "to_gadgarden")
    {
        root->changeLoc(lgadgarden,0);
    }
    if(action == "to_gaddvor")
    {
        root->changeLoc(lgaddvor,0);
    }
    if(action == "go_nude")
    {
        int month = root->getMonth();
        int sunWe = root->getSunWeather();
        int hour = root->getHour();
        int week = root->getWeekNum();

        root->uVEvent(gopsawnaked,1);
        if(root->gVEvent(gopsawnaked) >= 10)
        {
            root->sVEvent(gopsawnaked,0);
            root->uVEvent(mitkasextimes,1);
        }
        if(month >= 4 && month <= 10 && sunWe >= 0 && ((hour > 14 && hour < 18 && week == 6) || (hour > 13 && hour < 18 && week == 0)))
        {
            root->setImage(media(42));
            root->setDesc(str(95));
            makeActBtn("noticed_grandma",act(8));
        }
        else
        {
            root->sVEvent(EventParams::gadukino_nude, 8-week);
            root->sVEvent(gad_woman_knownude,1);
            root->setImage(media(43));
            root->setDesc(str(96));
            makeActBtn("to_gaddvor",act(8));
        }
    }
    if(action == "noticed_grandma")
    {
        root->sVEvent(gadukino_go_nude,0);
        root->sVEvent(grandmaknownude,1);
        root->sVEvent(gad_woman_knownude,1);
        root->uVQuest(grandmaQW,-20);
        root->uVQuest(grandpaQW,-20);
        root->redressOld();
        root->sVStatus(clothesswamphouse,0);
        root->sVStatus(clothesbackwater,0);
        root->sVStatus(clothesforest,0);
        root->sVStatus(swamp_clothes,0);
        root->incTime(10);
        root->changeLoc(lgadhouse);
    }
    if(action == "gad_nude_end_next")
    {
        root->uVEvent(grandmaknownude,1);
        root->changeLoc(lgadhouse,0);
    }
    if(action == "gadukino_back")
    {
        gadukino_back();
    }
    if(action == "gadriver_nude_end_next")
    {
        root->uVEvent(grandpaknownude,1);
        actionHandler("to_gaddvor");
    }
    if(action == "back_to_lock")
    {
        root->changeLoc(root->getCurLoc());
    }
    if(action == "onlooker_woman_next")
    {
        root->sVEvent(grandma_know,1);
        root->sVEvent(grandpa_know,1);
        actionHandler("to_gadhouse");
    }
    if(action == "onlooker_man_next")
    {
        root->sVEvent(grandpa_know,1);
        actionHandler("to_gaddvor");
    }
    if(action == "pack_things")
    {
        pack_things();
    }
    if(action == "go_home_ender")
    {
        go_home_ender();
    }
    if(action == "punishment11")
    {
        root->incTime(5);
        root->uVSkill(domination,-5);
        root->setImage(media(44));
        root->setDesc(str(138));
        root->addDesc(str(136));
        makeActBtn("korrPar",act(28));
    }
    if(action == "punishment12")
    {
        root->sVEvent(mother_spanking,1);
        root->incTime(10);
        root->uVSkill(domination,5);
        root->uVSC(spankAss,1);
        root->uVSex(spanked,75);
        root->setImage(media(45));
        root->setDesc(str(139));
        root->addDesc(str(135));
        makeActBtn("bedrPar",act(28));
    }
    if(action == "korrPar")
    {
        root->changeLoc(lkorrpar);
    }
    if(action == "bedrPar")
    {
        root->changeLoc(lbedrpar);
    }
}

void GadukinoEvent::gadsarai_check()
{
    qDebug() << "GADSARAI_CHECK RUNNING!";
    if(root->getMonth() >= 5 && root->getMonth() <= 9 && root->getSunWeather() >= 0 && root->getHour() > 13 && root->getHour() < 18 && root->getWeekNum() < 6)
        root->sVEvent(grandma_ingadsarai,1);
    else
        root->sVEvent(grandma_ingadsarai,0);
    if(root->getMonth() > 5 && root->getMonth() < 9 && root->getSunWeather() >= 0 && root->getHour() > 7 && root->getHour() < 13 && (root->getWeekNum() == 2 || root->getWeekNum() == 4))
        root->sVEvent(grandpa_ingadsarai,1);
    else
        root->sVEvent(grandpa_ingadsarai,0);

    if(root->gVEvent(grandpa_ingadsarai) == 1 || root->gVEvent(grandma_ingadsarai) == 1)
        root->sVEvent(grandparents_ingadsarai,1);
    else
        root->sVEvent(grandparents_ingadsarai,0);
}

void GadukinoEvent::walk()
{
    root->incTime(15);
    i = getRandInt(0,100);
    if(root->gVEvent(meadow) == 0)
    {
        root->setImage(media(46));
        root->setDesc(str(0));
        makeActBtn("go_meadow",act(0));
    }
    else if(root->gVEvent(meadow) == 1 && root->gVQuest(miraQW) == 0)
    {
        root->setImage(media(47));
        root->setDesc(str(2));
        makeActBtn("help_mira",act(2));
    }
    else if(i < 10 && root->gVEvent(Mira_no) == 0)
    {
        if(root->gVQuest(miraQW) > 0 && i < 5)
        {
            if(root->gVQuest(miraQW) < 25)
                root->uVQuest(miraQW,1);
            root->incTime(10);
            QString add;
            if(root->gVQuest(miragopQW) == 0)
                root->setImage(media(48));
            else
                root->setImage(media(49));
            root->setDesc(str(4));
            if(root->gVQuest(miragopQW) >= 20)
            {
                makeActBtn("show_pussy",act(4));
            }
            else
                makeActBtn("to_gadukino",act(5));
        }
        else if(root->gVQuest(miraQW) > 0 && root->gVQuest(miragopQW) < 4 && i >5)
        {
            if(root->gVQuest(miraQW) < 25)
                root->uVQuest(miraQW,1);
            root->incTime(10);
            root->setImage(media(50));
            root->setDesc(str(11));
            makeActBtn("to_gadukino",act(3));
        }
        else if(root->gVQuest(miraQW) > 0 && root->gVQuest(miragopQW) >= 4 && root->gVEvent(mirasextimes) >= 10 && root->getTemp() >= 15 && root->getSunWeather() >= 0 && i < 5)
        {
            root->uVStatus(horny,20);
            i = getRandInt(0,1);
            root->incTime(5);
            root->uVSC(voyeurism,1);
            if(i == 1)
                root->setImage(media(51));
            else
                root->setImage(media(52));
            root->setDesc(str(12));
            makeActBtn("to_gadukino",act(5));
        }
        else if(root->gVQuest(miraQW) > 0 && root->gVQuest(miragopQW) >= 6 && root->gVEvent(mirasextimes) >= 10 && root->getTemp() >= 15 && root->getSunWeather() >= 0 && i >= 5)
        {
            root->uVStatus(horny,20);
            root->incTime(10);
            root->uVSC(voyeurism,1);
            root->setImage(media(53));
            root->setDesc(str(13));
            makeActBtn("watch_mirasex",act(6));
        }
        else
        {
            walki = getRandInt(1,25);
            while (walki == last_walk)
            {
                walki = getRandInt(1,25);
            }
            last_walk = walki;
            qDebug() << last_walk;
            root->setImage(media(54));
            root->setDesc(str(15));
            makeActBtn("to_gadukino",act(5));
        }
    }
    else if(root->gVQuest(miragopQW) >= 11 && i >= 10 && i < 15 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(15,30));
        root->uVSC(voyeurism,1);
        root->setImage(media(55));
        root->setDesc(str(16));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 11 && i >= 15 && i < 20 && root->getTemp() >= 25 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(15,30));
        root->uVSC(voyeurism,1);
        root->setImage(media(56));
        root->setDesc(str(16));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 11 && i >= 20 && i < 25 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(15,30));
        root->uVSC(voyeurism,1);
        root->setImage(media(57));
        root->setDesc(str(17));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 15 && i >= 25 && i < 30 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(20,40));
        root->uVSC(voyeurism,1);
        root->setImage(media(58));
        root->setDesc(str(18));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 20 && i >= 30 && i < 35 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(20,40));
        root->uVSC(voyeurism,1);
        root->setImage(media(62));
        root->setDesc(str(19));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 20 && i >= 35 && i < 40 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(25,50));
        root->uVSC(voyeurism,1);
        root->setImage(media(59));
        root->setDesc(str(20));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 30 && root->gVEvent(mirasextimes) > 50 && i >= 40 && i < 45 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(50,100));
        root->uVSC(voyeurism,1);
        root->setImage(media(60));
        root->setDesc(str(21));
        makeActBtn("to_gadukino",act(5));
    }
    else if(root->gVQuest(miragopQW) >= 20 && i >= 45 && i < 50 && root->getTemp() >= 20 && root->getSunWeather() >= 0 && root->gVEvent(Mira_no) == 0)
    {
        root->incTime(5);
        root->uVStatus(horny, getRandInt(25,40));
        root->uVSC(voyeurism,1);
        root->setImage(media(61));
        root->setDesc(str(22));
        makeActBtn("to_gadukino",act(5));
    }
    else if(i >= 50 && i < 55)
    {
        root->incTime(5);
        root->setImage(media(63));
        root->setDesc(str(23));
        makeActBtn("to_gadukino",act(5));
    }
    else if(i >= 55 && i < 60)
    {
        root->incTime(5);
        root->setImage(media(64));
        root->setDesc(str(24));
        makeActBtn("to_gadukino",act(5));
    }
    else if(i >= 60 && i < 70)
    {
        root->incTime(5);
        if(root->gVEvent(mitkasextimes) >= 13)
            root->uVSkill(domination,-1);
        QString add;
        if(root->getTemp() < 20)
            root->setImage(media(65));
        else
            root->setImage(media(66));
        root->setDesc(str(25));
        makeActBtn("to_gadukino",act(7));
    }
    else if(i >= 70 && i < 75 && root->getTemp() >= 20 && root->getSunWeather() >= 0)
    {
        root->incTime(5);
        root->setImage(media(67));
        root->setDesc(str(26));
        makeActBtn("to_gadukino",act(5));
    }
    else
    {
        walki = getRandInt(1,25);
        while (walki == last_walk)
        {
            walki = getRandInt(1,25);
        }
        last_walk = walki;
        qDebug() << last_walk << "second";
        root->setImage(media(54));
        root->setDesc(str(15));
        makeActBtn("to_gadukino",act(5));
    }
}

void GadukinoEvent::mira_apologise()
{
    root->incTime(5);
    root->sVEvent(gadboyday, root->vStatus(daystart));
    root->setImage(media(68));
    root->setDesc(str(27));
    makeActBtn("mira_apologise_next",act(8));
}

void GadukinoEvent::mitka_apologise()
{
    root->incTime(5);
    root->sVEvent(gadboyday, root->vStatus(daystart));
    root->sVEvent(gadriver_gang,4);
    root->setImage(media(68));
    root->setDesc(str(31));
    makeActBtn("mitka_apologise_next",act(8));
}

void GadukinoEvent::gang_apologise()
{
    root->incTime(5);
    root->sVEvent(gadboyday, root->vStatus(daystart));
    root->setImage(media(68));
    root->setDesc(str(35));
    makeActBtn("wait_gang_apologize",act(11));
    makeActBtn("run_from_gang", act(13));
}

void GadukinoEvent::gadrivergang()
{
    root->incTime(5);
    root->sVEvent(gadriver_gang,1);
    root->sVEvent(gadboyday, root->vStatus(daystart));
    root->sVEvent(mitkasextimes,21);
    root->uVSkill(domination,-10);
    if(root->vStatus(health) <= 100)
        root->sVStatus(health,100);
    root->setImage(media(69));
    root->setDesc(str(41));
    makeActBtn("gang_act1",act(14));
}

void GadukinoEvent::gadukino_mitka()
{
    root->incTime(5);
    root->sVEvent(mitkaday,root->vStatus(daystart));
    root->setImage(media(7));
    root->setDesc(str(71));
    makeActBtn("mitkagadsex11",act(8));
}

void GadukinoEvent::gadukino_kolyamba()
{
    root->incTime(5);
    root->sVEvent(mitkaday,root->vStatus(daystart));
    root->setImage(media(70));
    root->setDesc(str(72));
    makeActBtn("mitkagadsex12",act(8));
}

void GadukinoEvent::gadukino_vasyan()
{
    root->incTime(5);
    root->sVEvent(mitkaday,root->vStatus(daystart));
    root->setImage(media(71));
    root->setDesc(str(73));
    makeActBtn("mitkagadsex13",act(8));
}

void GadukinoEvent::gadukino_2boys()
{
    root->incTime(5);
    root->sVEvent(gadboyday,root->vStatus(daystart));
    root->sVEvent(mitboyrand,getRandInt(1,3));
    if(root->getMonth() >= 6 && root->getMonth() <= 8)
        root->setImage(media(72));
    else
        root->setImage(media(73));
    switch (root->gVEvent(mitboyrand))
    {
    case 1:
        root->setDesc(str(74));
        break;
    case 2:
        root->setDesc(str(75));
        break;
    case 3:
        root->setDesc(str(76));
        break;
    default:
        break;
    }
    makeActBtn("mitkagadsex2",act(8));
}

void GadukinoEvent::mira_mitka()
{
    root->incTime(5);
    root->sVEvent(mitkaday, root->vStatus(daystart));
    root->setImage(media(7));
    root->setDesc(str(77));
    makeActBtn("mitkaforestsex11",act(8));
}

void GadukinoEvent::mira_kolyamba()
{
    root->incTime(5);
    root->sVEvent(kolyambaday, root->vStatus(daystart));
    root->setImage(media(70));
    root->setDesc(str(78));
    makeActBtn("mitkaforestsex12",act(8));
}

void GadukinoEvent::mira_vasyan()
{
    root->incTime(5);
    root->sVEvent(kolyambaday, root->vStatus(daystart));
    root->setImage(media(71));
    root->setDesc(str(79));
    makeActBtn("mitkaforestsex13",act(8));
}

void GadukinoEvent::mira_2boys()
{
    root->incTime(5);
    root->sVEvent(gadboyday,root->vStatus(daystart));
    root->sVEvent(mitboyrand,getRandInt(1,3));
    if(root->getMonth() >= 6 && root->getMonth() <= 8)
        root->setImage(media(72));
    else
        root->setImage(media(73));
    switch (root->gVEvent(mitboyrand))
    {
    case 1:
        root->setDesc(str(80));
        break;
    case 2:
        root->setDesc(str(81));
        break;
    case 3:
        root->setDesc(str(82));
        break;
    default:
        break;
    }
    makeActBtn("mitkaforestsex2",act(8));
}

void GadukinoEvent::mira_3boys()
{
    root->incTime(5);
    root->sVEvent(gadboyday,root->vStatus(daystart));
    if(root->getMonth() >= 6 && root->getMonth() <= 8)
        root->setImage(media(74));
    else
        root->setImage(media(75));
    root->setDesc(str(83));
    makeActBtn("mitkaforestsex3",act(8));
}

void GadukinoEvent::go_home()
{
    if(root->getWeekNum() == 0)
    {
        if(root->getHour() == 20 || root->getHour() == 21)
        {
            root->sVEvent(family_trip_month, root->getMonth());
            if(root->getMonth() >= 6 || root->getMonth() <= 8)
            {
                root->setDesc(str(84));
                makeActBtn("to_gadhouse",act(16));
                makeActBtn("go_home_ender",act(17));
            }
            else
            {
                go_home_ender();
            }
        }
        else if(root->getHour() > 21)
        {
            root->sVEvent(family_trip_month, root->getMonth());
        }
    }
}

void GadukinoEvent::go_home_ender()
{
    root->incTime(getRandInt(15,25));
    root->sVEvent(mira_guest,0);
    root->setDesc(str(85));
    clearing_basket();
    makeActBtn("my_bedroom",act(18));
}

void GadukinoEvent::to_gadukino()
{
    root->incTime(getRandInt(15,25));
    root->setDesc(str(86));
    makeActBtn("to_gadhouse",act(19));
}

void GadukinoEvent::collection_point()
{
    root->incTime(5);
    root->setImage(media(41));
    root->setDesc(str(87));
    if(root->vStatus(boletus) > 0)
        makeActBtn("store_boletus",act(20));
    if(root->vStatus(bilberry) > 0)
        makeActBtn("store_bilberry",act(21));
    makeActBtn("to_gadukino",act(5));
}

void GadukinoEvent::gadukino_back()
{
    root->incTime(30);
    if(root->getHour() >= 6 && root->getHour() <22)
        root->setImage(media(76));
    else
        root->setImage(media(77));
    root->setDesc(str(90));
    makeActBtn("to_gadgarden",act(8));
}

void GadukinoEvent::gadukino_nude()
{
    root->incTime(5);
    int tmp = getRandInt(1,5);
    int hour = root->getHour();
    int sunWe = root->getSunWeather();
    if(hour >=6 && hour <= 21 && ((sunWe >= 0 && tmp > 1) || (sunWe < 0 && tmp > 3)))
        root->sVEvent(gadukino_go_nude,1);
    QString add;
    if(hour < 6 || hour > 21)
        root->setImage(media(78));
    else if(sunWe < 0)
        root->setImage(media(79));
    else
        root->setImage(media(80));
    root->setDesc(str(91));
    if(hour < 6 || hour > 21)
        root->addDesc(str(92));
    if(hour >= 6 && hour <= 21 && sunWe < 0 && tmp < 4)
        root->addDesc(str(93));
    if(hour >= 6 && hour <= 21 && sunWe >= 0 && tmp == 1)
        root->addDesc(str(94));
    if(root->gVEvent(gadukino_go_nude) == 0)
        makeActBtn("to_gaddvor",act(8));
    else if (root->gVEvent(gadukino_go_nude) == 1)
    {
        makeActBtn("go_nude",act(8));
    }
}

void GadukinoEvent::gadukino_nude_end()
{
    root->incTime(30);
    root->sVEvent(EventParams::gadukino_nude,0);
    root->uVQuest(grandmaQW,-20);
    root->uVQuest(grandpaQW,-20);
    root->sVEvent(grandma_notalk,1);
    root->sVEvent(grandpa_notalk,1);
    root->setImage(media(81));
    root->setDesc(str(97));

    if(root->gVEvent(grandmaknownude) == 0)
    {
        root->setDesc(str(98));
    }
    else
    {
        root->setDesc(str(99));
    }
    makeActBtn("gad_nude_end_next",act(8));
}

void GadukinoEvent::gadriver_nude()
{
    root->incTime(20);
    if(root->gVEvent(fishers) == 1)
    {
        root->sVEvent(fishers_nude, 8 - root->getWeekNum());
        root->uVEvent(gopsawnaked,1);
        if(root->gVEvent(gopsawnaked) >= 10)
        {
            root->sVEvent(gopsawnaked,0);
            root->uVEvent(mitkasextimes,1);
        }
        QString add;
        if(root->getHour() < 6 || root->getHour() > 21)
            root->setImage(media(78));
        else if(root->gVEvent(fishers) != 0)
            root->setImage(media(82));
        else
            root->setImage(media(80));
        root->setDesc(str(100));
        if(root->getHour() < 6 || root->getHour() > 21)
            root->addDesc(str(101));
        if(root->gVEvent(fishers) == 0)
            root->addDesc(str(102));
        if(root->gVEvent(fishers) == 1)
            root->addDesc(str(103));
        makeActBtn("to_gadukino",act(22));
        makeActBtn("gadukino_back",act(23));
    }
}

void GadukinoEvent::gadriver_nude_end()
{
    root->incTime(10);
    root->sVEvent(fishers_nude,0);
    root->uVQuest(grandpaQW,-10);
    root->sVEvent(grandpa_notalk,1);
    root->setImage(media(83));
    root->setDesc(str(104));
    if(root->gVEvent(grandpaknownude) == 0)
        root->setDesc(str(105));
    else
        root->setDesc(str(106));
    makeActBtn("gadriver_nude_end_next",act(8));
}

void GadukinoEvent::onlooker()
{
    root->sVEvent(EventParams::onlooker,0);
    int temp = getRandInt(1,10);
    if(root->getWeekNum() < 6 && root->getWeekNum() > 0)
    {
        if(root->getHour() < 17 && temp == 1)
            root->sVEvent(EventParams::onlooker,1);
        if(root->getHour() >= 17 && temp < 3)
            root->sVEvent(EventParams::onlooker,1);
    }
    else
        if(temp < 4)
        root->sVEvent(EventParams::onlooker,1);
}

void GadukinoEvent::gadukino_onlooker()
{
    root->incTime(1);
    root->sVEvent(EventParams::gadukino_onlooker,getRandInt(1,2));
    if(root->gVEvent(EventParams::gadukino_onlooker) == 1)
    {
        root->sVEvent(onlooker_woman,1);
        root->sVEvent(gad_woman_knowsex,1);
        root->setImage(media(84));
        root->setDesc(str(107));
    }
    else
    {
        root->sVEvent(onlooker_man,1);
        root->setImage(media(84));
        root->setDesc(str(108));
    }
    makeActBtn("back_to_lock",act(5));
}

void GadukinoEvent::gadukino_onlooker_woman()
{
    root->incTime(30);
    root->sVEvent(onlooker_woman,0);
    root->uVQuest(grandmaQW,-20);
    root->uVQuest(grandpaQW,-20);
    root->sVEvent(grandma_notalk,1);
    root->sVEvent(grandpa_notalk,1);
    root->setImage(media(81));
    root->setDesc(str(109));
    if(root->gVQuest(grandmaQW) < 40)
    {
        if(root->gVEvent(grandma_know) == 0)
            root->setDesc(str(110));
        if(root->gVEvent(grandma_know) == 1)
            root->setDesc(str(111));
    }
    else
    {
        if(root->gVEvent(grandma_know) == 0)
            root->setDesc(str(112));
        if(root->gVEvent(grandma_know) == 1)
            root->setDesc(str(113));
    }
    makeActBtn("onlooker_woman_next",act(8));
}

void GadukinoEvent::gadukino_onlooker_man()
{
    root->incTime(30);
    root->sVEvent(onlooker_man,0);
    root->uVQuest(grandpaQW,-20);
    root->sVEvent(grandpa_notalk,1);
    root->setImage(media(83));
    root->setDesc(str(114));
    if(root->gVQuest(grandpaQW) < 40)
    {
        root->addDesc(str(115));
        if(root->gVEvent(grandpa_know) == 0)
            root->addDesc(str(116));
        if(root->gVEvent(grandpa_know) == 1)
            root->addDesc(str(117));
    }
    else
    {
        if(root->gVEvent(grandpa_know) == 0)
            root->addDesc(str(118));
        if(root->gVEvent(grandpa_know) == 1)
            root->addDesc(str(119));
    }
    makeActBtn("onlooker_man_next",act(8));
}

void GadukinoEvent::gadukino_end()
{
    root->incTime(10);
    root->sVEvent(grandma_notalk,1);
    root->sVEvent(grandpa_notalk,1);
    QString img;
    if(root->gVQuest(grandpaQW) > root->gVQuest(grandmaQW))
        root->setImage(media(83));
    else
        root->setImage(media(81));
    root->setDesc(str(120));
    if(root->gVQuest(grandpaQW) > root->gVQuest(grandmaQW))
    {
        root->addDesc(str(121));
        if(root->gVEvent(gad_woman_knowsex) > 0 && root->gVEvent(gad_woman_knownude) > 0)
            root->addDesc(str(122));
        if(root->gVEvent(gad_woman_knowsex) > 0 && root->gVEvent(gad_woman_knownude) == 0)
            root->addDesc(str(123));
        if(root->gVEvent(gad_woman_knowsex) == 0 && root->gVEvent(gad_woman_knownude) > 0)
            root->addDesc(str(124));
        if(root->gVEvent(gad_woman_knowsex) == 0 && root->gVEvent(gad_woman_knownude) == 0)
            root->addDesc(str(125));
    }
    else
    {
        root->addDesc(str(126));
        if(root->gVEvent(gad_woman_knowsex) > 0 && root->gVEvent(gad_woman_knownude) > 0)
            root->addDesc(str(127));
        if(root->gVEvent(gad_woman_knowsex) > 0 && root->gVEvent(gad_woman_knownude) == 0)
            root->addDesc(str(128));
        if(root->gVEvent(gad_woman_knowsex) == 0 && root->gVEvent(gad_woman_knownude) > 0)
            root->addDesc(str(129));
        if(root->gVEvent(gad_woman_knowsex) == 0 && root->gVEvent(gad_woman_knownude) == 0)
            root->addDesc(str(130));
    }
    makeActBtn("pack_things",act(24));
}

void GadukinoEvent::pack_things()
{
    root->incTime(60);
    root->sVEvent(gad_punishment,1);
    //mother = 0
    //father['relation'] = 0
    if(root->gVEvent(gad_woman_knowsex) > 0)
    {
        root->sVEvent(motherKnowSpravka,1);
        root->sVEvent(motherKnowWhore,1);
    }
    root->sVEvent(gadukino_blok,1);
    //gs 'npc_editor','get_npc_profile',37
    root->addDesc(str(131));
    makeActBtn("go_home_ender",act(25));
}

void GadukinoEvent::punishment()
{
    root->sVStatus(mood,0);
    root->sVEvent(gad_punishment,0);
    //gs 'npc_editor','get_npc_profile',37
    root->setDesc(str(132));
    if(root->gVEvent(gad_woman_knowsex) > 0)
    {
        root->gNPC(37).relation = 0;
        root->gNPC(35).relation = 0;
        root->sVEvent(mother_punishment,1);
        root->addDesc(str(133));
    }
    else if (root->gVEvent(gad_woman_knowsex) == 0 && root->gVEvent(gad_woman_knownude) > 0)
    {
        root->addDesc(str(134));
        if(root->gVEvent(mother_spanking) > 0 && root->gVEvent(momslut) < 2)
        {
            root->addDesc(str(135));
            root->sVEvent(mother_punishment,1);
            root->gNPC(37).relation = 10;
            root->gNPC(35).relation = 10;
        }
        if(root->gVEvent(mother_spanking) == 0 && root->gVEvent(momslut) >= 2)
        {
            root->addDesc(str(136));
            root->sVEvent(mother_punishment,2);
            root->gNPC(37).relation = 20;
            root->gNPC(35).relation = 20;
        }
    }
    else
    {
        root->addDesc(str(137));
        if(root->gVEvent(mother_spanking) > 0)
        {
            root->addDesc(str(135));
            root->sVEvent(mother_punishment,1);
            root->gNPC(37).relation = 20;
            root->gNPC(35).relation = 20;
        }
        if(root->gVEvent(mother_spanking) == 0)
        {
            root->addDesc(str(136));
            root->sVEvent(mother_punishment,2);
            root->gNPC(37).relation = 30;
            root->gNPC(35).relation = 30;
        }
    }
    if(root->gVEvent(mother_punishment) == 1)
    {
        makeActBtn("punishment11",act(26));
        makeActBtn("punishment12",act(27));
    }
    else
        makeActBtn("korrPar",act(5));
}

void GadukinoEvent::absolution()
{
    root->incTime(5);
    root->sVEvent(gadukino_blok,0);
    //gs 'npc_editor','get_npc_profile',37
    root->setDesc(str(140));
    makeActBtn("back_to_lock",act(28));
}

void GadukinoEvent::offense()
{
    root->incTime(5);
    //	gs 'npc_editor','change_rep','-', 37, 10
    root->sVEvent(gad_offense,0);
    //gs 'npc_editor','get_npc_profile',37
    root->setDesc(str(141));
    makeActBtn("back_to_lock",act(28));
}

void GadukinoEvent::clearing_basket()
{
    root->sVStatus(boletus,0);
    root->sVStatus(bilberry,0);
}

QString GadukinoEvent::str(int id)
{
    QString str[142];
    str[0] = "Гуляя по деревне, вы замечаете между двумя соседскими домами небольшую тропинку, "
             "ведущую между огородами куда-то в заросли...";
    str[1] = "Вы решаете пойти по ней, но спустя десять минут разочарованно упираетесь в густые заросли. "
             "Вы уже собрались было уходить, но тут замечаете едва заметную, явно проложенную какой-то живностью тропку. "
             "Пробравшись по ней сквозь заросли, вы видите давно заросший не плодоносящими деревьями сад, который когда-то, "
             "наверное, принадлежал местному колхозу, пока он не распался. Пройдя еще немного, вы видите и давно заросшую"
             " грунтовую дорогу - судя по траве на ней, ею уже давно никто не пользуется. Побродив еще минут двадцать,"
             " вы убеждаетесь в том, что местные сюда не ходят, а если и ходят, то очень редко. Вы решаете вернуться"
             " назад и, к огромному вашем удивлению, выходите прямо у себя во дворе...";
    str[2] = "Прогуливаясь, вы замечаете молодую незнакомую вам девушку, которая за ошейник пытается куда-то тащить теленка."
             " Тот недовольно мычит, трясет вислоухой головой и вместо того, чтобы идти, стоит, как вкопанный, на месте.";
    str[3] = "Вы решаете помочь девчонке, а заодно из любопытства и узнать что-то о ней, так как в Гадюкино незнакомые "
             "люди - большая редкость, даже скорее фантастика. Вы подходите к ней и легонько шлепаете теленка по "
             "заднице, после чего тот сразу же начинает идти вперед. Незнакомка благодарит вас и между вами сам "
             "собой завязывается разговор на протяжении того времени, пока вы за компанию решаете помочь отогнать"
             " ей животное домой. Мирослава оказывается довольно общительной девушкой и с разговора вы быстро узнаете,"
             " что они совсем недавно вынуждены были переехать в деревню. Из-за огромных долгов отца им пришлось продать"
             " все имущество, в том числе и квартиру в центре города, а на те деньги, что у них остались, они смогли"
             " позволить себе купить дом только в такой вот захудалой деревне... Вы доходите до ее дома и она приглашает"
             " вас приходить к ней в гости в любое время, а то в деревне после города скукотища ужасная.";
    str[4] = "Вы встречаете Мирославу, которая как раз идет по воду, и она охотно останавливается с вами немного поболтать.";

    str[5] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай, присаживается"
              " на заборчик и, оглянувшись, с озорной улыбкой оттягивает в сторону трусики...";
    str[6] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай, опирается руками"
              " о лавочку, предоставляя вам вид своей голой киски.";
    str[7] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай, "
              "присаживается на заборчик и немного разведя ноги, показывает вам свою голую писечку.";
    str[8] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай, "
              "присаживается на попавшуюся рядом лавочку и, быстро оглянувшись по сторонам, поворачивается на бок"
              " и прогнувшись, показывает вам свой голый пельмень...";
    str[9] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай, "
              "присаживается на заборчик и, оглянувшись по сторонам разводит ноги... Вы с удивлением видите, "
              "как из ее растраханной киски сочится сперма.<br> - Кто это тебя так? - с интересом "
              "спрашиваете вы Миру, но та с кокетливой улыбкой отвечает вам, что это секрет.";
    str[10] = "Вы говорите Мире, чтобы посветила немного своей мандой и та непринужденно, словно бы невзначай,"
              " присаживается на корточки... Вы замечаете, как сильно раздолбанно ее влагалище и сморщенным "
              "бугорком выпирает рабочий анус...";
    str[11] = "Вы встречаете Мирославу c теленком и вы тут же, весело хохоча, вспоминаете ваше знакомство.";
    str[12] = "Гуляя по деревне, вы случайно замечаете Миру, отсасывающую Митьке на заднем дворе. Она чавкает "
              "губами, почти полностью вбирая член себе в рот, и иногда поглядывает по сторонам.";
    if(i == 0)
        str[12] += "Пока наконец не замечает вас. Она тут же стремительно краснеет, но не прекращает сосать, "
                   "лишь изредка косится глазами в вашу сторону. Поняв, что она заметила вас, вы, словно не "
                   "увидев ничего необычного, с максимально спокойным видом уходите прочь...";
    else
        str[12] += "Пару раз вам кажется, что она вот-вот заметит вас, но она так и не замечает, продолжая "
                   "ублажать Митьку. Тот вскоре закидывает голову назад и Мира, быстро надрачивая член рукой,"
                   " направляет его себе в рот, принимая в него Митькину сперму. Проглотив ее, она вылизывает "
                   "Митькин член и заправив его ему в штаны, поднимается с колен, а вы, не желая быть "
                   "обнаруженной, поспешно удаляетесь.";
    str[13] = "Гуляя по деревне, вы случайно замечаете Миру, трахающуюся с Митькой. Она, широко раскинув ноги,"
              " протяжно стонет под митькиными толчками, надрачивая себе клитор, а тот, грубо вколачивая в нее"
              " свой член, одной рукой бесцеремонно мнет ей грудь.";
    str[14] = "Они так увлечены друг другом, что не замечают ничего вокруг";
    if(i == 0)
        str[14] += " а потому вы спокойно продолжаете наблюдать, как вскоре Митька вгоняет в Миру свой член до"
                   " упора и начинает кончать. Через пару минут, немного отдышавшись, они начинают приводить"
                   " себя в порядок и вы решаете уйти.";
    else
        str[14] += ". Вы присматриваетесь получше и понимаете, что Митька трахает ее в задницу, при этом без "
                   "презерватива, поэтому она, наверное, так под ним извивается. Через некоторое время Митька"
                   " одним рывком вгоняет в ее зад свой член до упора и рыча, начинает кончать...";
    str[15] = "Вы убиваете время, гуляя по деревне.";
    str[16] = "Гуляя по деревне, вы замечаете за сараями Васяна с Мирой. Та со стонами скачет у него на члене "
              "и, кажется, не замечает ничего вокруг, чего не скажешь о самом Васяне... Вы решаете не рисковать"
              " и оставить парочку наедине.";
    str[17] = "Гуляя по деревне, вы замечаете за кустами Колямбу с Мирой. Та, присев на корточки, страстно "
              "чмокает губами на его члене...";
    str[18] = "Гуляя по деревне, вы замечаете за кустами Колямбу с Васяном и Мирой. Та стоит к вам голым задом "
              "на четвереньках и по очереди отсасывает пацанам члены...";
    str[19] = "Гуляя по деревне, вы видите Миру. Та сидит на заборе и постоянно оглядываясь усиленно натирает"
              " себе киску, когда никто не видит...";
    str[20] = "Гуляя по деревне, вы замечаете за заборами Миру с Колямбой. Та кривится и стонет, но покорно "
              "подставляет свою голую задницу Колямбе, который пытается запихнуть в нее бутылку...";
    str[21] = "Гуляя по деревне, вы видите Миру, которая стоит перед Митькой со спущенными штанами"
              " и засунув пальцы себе в анус, показывает ему выпавшую задницу...";
    str[22] = "Гуляя по деревне, вы встречаете Миру, которая поправляет обувь. При этом она без трусов "
              "и с ее киски торчит белая ниточка тампона...";
    str[23] = "Гуляя по деревне, вы видите двух бабулек, пилящих доски...";
    str[24] = "Гуляя по деревне, вы видите двух вороватых бабулек, несущих доски с полуразваленной фермы...";
    if(root->gVEvent(mitkasextimes) < 13)
    {
        str[25] = "Гуляя по деревне, вы видите местную элиту. Они, как по команде, все вместе затихают и"
                  " усиленно начинают смотреть куда-то в сторону, как только вы приближаетесь к ним";
        if(root->gVEvent(gad_woman_knownude) == 1)
            str[25] += ", а едва вы оказываетесь позади, как слышите негодующие голоса:"
                       "<br>- Экая лахудра! Этож надо такое удумать - голяком по деревне ходить и мандищей своей светить!"
                       "<br>- А с виду так приличная девочка!<br>- Где же приличная? Сразу видно праститутка!";
        else
            str[25] += "...";
    }
    else
    {
        if(root->gVEvent(gad_woman_knownude) == 1)
            str[25] = "Гуляя по деревне, вы видите местную элиту. Они приветливо улыбаются вам в лицо, "
                      "а как только вы проходите мимо, как слышите старушечье:<br>- О, глядите-ка, "
                      "девоньки, проститутка пошла. Уж как ее Митька Фроськин со своей бандой не вертели,"
                      " а она ходит тут как ни в чем не бывало...<br>- Ну да ничего, Бог на том свете всех"
                      " рассудит, я вам говорю, девоньки, там свете все по местам станет...<br>- У-у-у, "
                      "праститу-у-у-тка, прости Госпади!";
        else
            str[25] = "Гуляя по деревне, вы видите местную элиту. Они приветливо улыбаются вам в лицо, а "
                      "как только вы проходите мимо, тут же начинают шушукаться между собой...";
    }
    str[26] = "Гуляя по деревне, вы видите подрастающее поколение. Те радостно улыбают вам зубы и пялятся во все глаза...";
    str[27] = "Идя по деревне вы услышали, что вас кто-то догоняет. Оглянувшись, вы увидели Миру.";
    str[28] = "Мира подбежала к вам и сходу затараторила.<br>- Светик, я слышала, что произошло, - сбиваясь начала она. "
              "- Митьку с Колямбой подслушала."
        "Вы стояли молча и ждали, что она еще скажет."
        "- Света, прости меня дуру, за то как я с тобой обращалась, - продолжила она. - Я вдруг поняла, что ты у меня "
              "тут единственная подруга."
        "- И что теперь?// - спросили вы глядя на неё."
        "- Ну хочешь, я в знак примирения тебе тоже сделаю приятно? - смущаясь ответила она."
              "Пока вы обдумывали, что ответить, Мира непрестанно следила за вами, покусывая губы от нетерпения.";
    str[29] = "Вы, наконец приняв решение, повернулись к Мире."
        "- Хорошо, Мир, я согласна, - сказали вы ей с улыбкой, уловив во взгляде неподдельную радость. - Ты прощена."
        "- И? - вопросительно подняла она бровь."
        "Вместо ответа вы схватили её за руку и потащили на поляну.";
    str[30] = "Вы, наконец приняв решение, повернулись к Мире."
        "- Хорошо, Мир, я согласна, - сказали вы ей с улыбкой, уловив во взгляде неподдельную радость. - Ты прощена."
        "- И? - вопросительно подняла она бровь."
        "- Нет, Мир, взамен ничего не нужно, - ответили вы. - Знаешь, я лишний раз убедилась, что девочки мне"
              " неинтересны в плане секса."
        "- Ну как знаешь, - немного разочарованным голосом сказала Мира. Ну пошли хоть по деревне погуляем."
        "И в течение часа вы спокойно гуляли по деревне, весело разговаривая.";
    str[31] = "Идя по деревне вы услышали, что вас кто-то догоняет. Оглянувшись, вы увидели спешащего к вам Митьку."
              " Зная по собственному опыту, что убежать все равно не выйдет, вы остановились, поджидая его.";
    str[32] = "Митька подошел к вам и с ходу начал разговор."
        "- Вот что, Светик. Ко мне тут наши мужики подваливали, - сказал он с ухмылкой, видя испуг на вашем лице."
        " - Сказали не трогать тебя больше, а то еще в мусарню заявишь."
        "Вы стояли молча и ждали, что он еще скажет."
        "- Короче, помнишь как в детстве, мир-дружба-жвачка, - сказал он с ухмылкой. - Лады?";
    str[33] = "- А к Мирке тоже не будете приставать? - спросили вы с облегчением."
        "- А Мирка не против, гы гы гы, - заржал Митька."
        "- И ко мне совсем-совсем приставать не будете? - вы с недоверием посмотрели на Митьку."
        "- Ну если сама не попросишь, - снова заржал он. - Ну все, с тобой думаю мы все порешали, пойду я... Мирку поищу что ли, а то стояк заёб."
        "И гогоча пошел в сторону дома Колямбы. Вы еще пару мгновений смотрели ему в след, потом отправились дальше по своим делам";
    str[34] = "- И ко мне совсем-совсем приставать не будете? - вы с недоверием посмотрели на Митьку."
        "- Ну если сама не попросишь, - заржал он. - Ну все, с тобой думаю мы все порешали, пойду я..."
        "И гогоча пошел в сторону дома Колямбы. Вы еще пару мгновений смотрели ему в след, потом отправились дальше по своим делам";
    str[35] = "Идя по деревне вы вдруг услышали, что вас кто-то зовет по имени. Оглянувшись, вы увидели, что это дядя Степа, "
        "направляющийся в вашу сторону. Вы, помня о недавних событиях, ускорили шаг, не желая их повторения."
        "- Света, постой, мне поговорить с тобой нужно, - крикнул издали он, видя, что вы готовы уже перейти на бег.";
    str[36] = "Вы остановились в нерешительности, гадая, что же хочет от вас дядя Степа. Пока вы раздумывали, "
        "удрать все-таки или остаться, он подошел к вам и остановился, растерянно переминаясь с ноги на ногу, "
        "явно не зная, как начать разговор. Вы вопросительно глянули на него из-под лобья, как бы подталкивая его , и он наконец решился."
        "- Света, кх-ммм, - начал он, но сразу запнулся. - Короче, извини нас за вчерашнее... Незнаю, что на "
        "нас нашло, как будто бес вселился, после пьяных рассказов Митьки и его дружков."
        "Удивленно подняв брови, вы уставились на него. Такого поворота событий вы явно не ожидали."
        "- Мы тут с мужиками покумекали с утра, и, ээээ, - опять сбился дядя Степа. - Ну короче мы тут "
        "с мужиками решили поговорить с тобой. Принести извинения и попросить сделать вид, что ничего "
        "вчера не было как бы... И еще мы тут денежку собрали тебе, так сказать в виде морального ущерба."
        "Вы недоверчиво посмотрели на дядю Степу, не понимая, шутит он или нет.";
    str[37] = "Видя ваш недоверчивый взгляд, дядя Степа полез в карман спортивных штанов и достав оттуда сверток, начал его быстро разворачивать."
        "- Вот, - показал он деньги в руке. - Здесь десять тысяч."
        "- И что мне с ними делать? - неуверенно спросили вы."
        "- Ну я не знаю, дело твое, - ответил дядя Степа. - Может на лечение какое потратить, или купи себе "
              "что-нибудь в качестве моральной компенсации."
        "Вы задумались, не зная какое принять решение, глядя то на деньги, то на дядю Степу.";
    str[38] = "- Ладно, хорошо, - наконец приняли решение вы. - Давайте будем считать, что ничего не было."
        "И протянув руку, забрали деньги у дяди Степы."
        "- Ну вот и ладненько, - сказал облегченно дядя Степа. - Пойду я тогда."
        "Вы уже собрались развернуться и уйти, когда дядя Степа добавил:"
        "- И это... Света, никто из мужиков к тебе приставать больше не будет просто так, так что не бойся."
        "- Хорошо, я поняла, - ответили вы и развернувшись отправились по своим делам.";
    str[39] = "- Не нужны мне ваши деньги, я не проститутка какая-нибудь, - сказали вы твердым голосом, "
        "глядя в глаза дяде Степе. - Будем считать, что ничего не было, а деньги можете себе оставить."
        "Вы заметили как блеснули глаза дяди Степы при вашей последней фразе. Деньги отдавать мужикам он"
        " явно не собирался. \"Ну и бог с ним, это его дело\" - подумали вы про себя."
        "- Ну вот и ладненько, - сказал облегченно дядя Степа. - Пойду я тогда."
        "Вы уже собрались развернуться и уйти, когда дядя Степа добавил:"
        "- И это ... Света. Никто в деревне ничего не узнает, и из мужиков никто к тебе приставать "
        "больше не будет. Митьку с бандой тоже предупредим, так что на пушечный выстрел не подойдут."
        " А ежели что, ты мне скажи, я все улажу."
        "- Хорошо, я поняла, - ответили вы и развернувшись отправились по своим делам.";
    str[40] = "Вы кинулись на утек, не разбирая дороги, и остановились только на поляне за деревней."
        "\"Пронесло, слава богу\" - подумали вы и осмотрелись.";
    str[41] = "Вы шли по тропинке, полностью погрузившись в свои мысли, поэтому не сразу заметили"
              " толпу пьяных деревенских мужиков. Тут было практически все взрослое мужское население "
              "деревни, возможно не только этой. Подхватив вас под руки, они отвели вас в сторону, "
              "чтобы не было видно с деревни и раздев до гола, обступили со всех сторон, вывалив "
              "свои члены перед вашим лицом. Сопротивляться, учитывая вашу репутацию в деревне, вы"
              " посчитали делом смешным, а учитываю количество мужиков , к томуже и бесполезным, "
              "поэтому покорно опустились на колени.";
    str[42] = "Вы взяли первый попавшийся вам под руку член и подрочив немного поднесли к своим губам...";
    str[43] = "Потом перевал вашим лицом оказался следующий член...";
    str[44] = "Потом еще один, и еще. Члены менялись у вас во рту один за другим по одному, иногда даже по "
              "два сразу. И вы каждый из них сосали, обхватывая своими " + root->getLipTalk() + " губами, "
              "вбирая с каждым движением до самого горла. ";
    str[45] = "Наконец появились и первые финишеры. Они подходили и не церемонясь кончали вам в рот,"
              " на лицо, на грудь. А действие тем временем продолжалось дальше...";
    str[46] = "Вы и сами не поняли, в какой момент вдруг оказались стоящей раком. Ваш рот все так же был"
              " занят членом, вы просто почувствовали, что в вашу " + root->getVaginaTipe2() + " вагину уперся чей-то член.";
    str[47] = "Через некоторое время его сменил другой.";
    str[48] = "Следующий не торопился занять место в вашей вагине, вместо этого вы почувствовали как чьи-то пальцы изучают"
              " ваш " + root->getAnusTipe() + " анус.";
    if(root->vBody(anus) <= 5)
        str[48] += "<br>- А жопа то не разработана совсем, - услышали вы мужской голос. - Ничего, сейчас исправим.";
    else
        str[48] += "<br>Вы лишь могли мычать протестуя, так как ваш ротик был занят очередным членом.";
    str[49] = "Видимо эта идея пришлась по душе еще кому-то, так как следующий член парень начал пристраиваться"
              " к той же дырочке. Оглянувшись, вы узнали Митьку....";
    str[50] = "Вас положили на спину и вы увидели перед собой дядю Степу, рыбака, который устраивался между ваших"
              " раздвинутых ног. \"Ужас, и он тут\", - только и успели подумать вы.";
    str[51] = "Потом между ног пристроился очередной ваш \"поклонник\".";
    str[52] = "Потом опять знакомое лицо - Васян. Значит и Колямба где-то рядом, - подумали вы безразлично.";
    str[53] = "Тут для ваших дырочек наступила передышка, в виде очередных финишеров. Вас поставили на колени и "
              "вложив в ваши ладошки члены, приказали сосать.";
    str[54] = "Развязку долго ждать не пришлось.";
    str[55] = "Они кончили и отошли в сторону.";
    str[56] = "Вы опять оказались в положении раком, и очередной член начал прокладывать дорогу в вашу "
              "многострадальную, " + root->getVaginaTipe2() + ", киску.";
    str[57] = "Потом пристроился следующий.";
    str[58] = "Затем опять наступила очередь попки.";
    str[59] = "Скосив немного взгляд и продолжая сосать чей-то член, вы увидели очередного деревенского мужика, "
              "пристраивающегося к вашей попке.";
    str[60] = "Когда очередной мужик пристраивался к вашей попке, вы скосив на него глаза, к своему ужасу узнали Андрея."
              " То, что теперь и Игорь с Сергеем обо всем узнают, сомневаться не приходилось.";
    str[61] = "Вы продолжали стоять раком, когда следующий мужик решил воспользоваться вашей киской. Краем глаза, вы "
              "замечаете в толпе Колямбу, ждущего с нетерпением своей очереди.";
    str[62] = "Вы вдруг с удивлением обнаружили, что к вашей киске и попке больше никто не пристраивается. \"Неужели все?\""
              " - с надеждой подумали вы. "
              "Но передышки не получилось. Вас поставили на колени и тут же у вашего лица очутился очередной член.";
    str[63] = "- А теперь, пусть шлюшка сама поработает своей пиздёнкой,/// - услышали вы. Повернув голову вы увидели, "
              "разлегшегося на земле, голого мужика. И вам ничего другого не оставалось, как залезть на него сверху.";
    str[64] = "На следующего парня, тоже лежащего на земле, вы залезли уже сами, без подсказки. В лицо вам сразу "
              "уткнулся очередной член, который вы тут же принялись сосать.";
    str[65] = "Скача на члене очередного парня вы вдруг услышали голос Колямбы. - Да, бля, заебался я ждать уже, - "
              "и тут же в ваш " + root->getAnusTipe() + " анус уперся его член.";
    str[66] = "- Ух ты, бутерброд прямо, - услышали вы чей-то пьяный смех как в тумане.";
    str[67] = "Эта шутка так понравилась следующим мужикам, что они решили повторить.";
    str[68] = "Наконец, вас совсем обессиленную, поставили на колени перед оставшимися мужиками и вы желая завершения"
              " всего этого кошмара принялись с усердием отсасывать, стараясь чтобы они кончили побыстрее.";
    str[69] = "Ваши старания вскоре увенчались успехом, и парни как по команде стали кончать, кто в рот, кто на лицо."
              " Впрочем на грудь и живот тоже немало попало.";
    str[70] = "Когда последние мужики удачно отстрелялись, толпа начала рассасываться, оставив вас одну, обтекать "
              "на драном покрывале. Они расходились весело переговариваясь и делясь впечатлениями от своей пьяной выходки.";
    str[71] = "Идя по деревне вы встретили Митьку. Увидев вас он почесал яйца и сказал с ухмылкой:"
            "- Ну чо, Светик, пойдем поебемся, а то стояк заеб.";
    str[72] = "Идя по деревне вы встретили Колямбу. Увидев вас он почесал яйца и поволок ближайшие в кусты.";
    str[73] = "Идя по деревне вы встретили Васяна. Увидев вас он усмехнулся и поволок ближайшие в кусты.";
    str[74] = "Идя по деревне вы встретили Митьку и Колямбу. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[75] = "Идя по деревне вы встретили Митьку и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[76] = "Идя по деревне вы встретили Колямбу и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[77] = "Гуляя с Мирой по деревне вы встретили Митьку. Увидев вас он почесал яйца и сказал с ухмылкой:"
            "- Ну чо, девчонки, пойдем поебемся, а то стояк заеб.";
    str[78] = "Гуляя с Мирой по деревне вы встретили Колямбу. Увидев вас он почесал яйца и поволок ближайшие в кусты.";
    str[79] = "Гуляя с Мирой по деревне вы встретили Васяна. Увидев вас он усмехнулся и поволок ближайшие в кусты.";
    str[80] = "Гуляя с Мирой по деревне вы встретили Митьку и Колямбу. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[81] = "Гуляя с Мирой по деревне вы встретили Митьку и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[82] = "Гуляя с Мирой по деревне вы встретили Колямбу и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[83] = "Гуляя с Мирой по деревне вы встретили Митьку, Колямбу и Васяна. Увидев вас они усмехнулись и поволокли ближайшие в кусты.";
    str[84] = "Мама спрашивает у вас: - Ну что, Света, поедешь с нами или останешься пока в деревне?";
    str[85] = "Вы сели в Волгу вместе с семьей и вскоре добрались в Павлово.";
    str[86] = "Вы сели в Волгу и за быстро добрались до деревушки Гадюкино, в которой живут ваши бабушка и дедушка.";
    str[87] = "Передвижной заготовительный пункт грибов и ягод.";
    str[88] = "Вы сдали грибы на <b>" + intQStr(root->vStatus(boletus) * 150) + "</b> рублей.";
    str[89] = "Вы сдали ягоды на <b>" + intQStr(root->vStatus(bilberry) * 75) + "</b> рублей.";
    str[90] = "Вы решили, осторожно, избегая посторонних глаз, пробраться к дому огородами...";
    str[91] = "Несмотря, на то что на вас нет одежды, вы решили пройти домой через деревню.";
    str[92] = "На дворе ночь и поэтому вам повезло проскочить незамеченной.";
    str[93] = "На улице дождь, все сидят по домам, поэтому вам повезло проскочить незамеченной.";
    str[94] = "Вам повезло, вы никого не встретили по дороге, и добрались до дома незамеченной.";
    str[95] = "Но вам не повезло. Не успев войти в деревню, вы тут же наткнулись на бабушку, сидящую на лавке с подругами."
                "- Света ты что сдесь делаешь в таком виде? - округлила она глаза. - А ну марш домой одеваться! Бегом, пока дубца не получила!!!"
                "Вы со всех ног бросились в избу одеваться, слыша за спиной негодующие возгласы бабушкиных подруг.";
    str[96] = "Но вам не повезло. Не успев войти в деревню, вы тут же наткнулись на бабушкиных подруг, сидящих на лавочке."
            " Они выпучив глаза уставились на вас и тут же начали шептаться."
            "\"Теперь бабушка точно обо всем узнает\" - подумалось вам.";
    str[97] = "Не успели вы войти в избу, как на вас накинулась бабушка.";
    str[98] = "- Света, как ты могла голая по деревне разгуливать? Думала я не узнаю? Как тебе вообще такое в голову могло"
               " прийти, бесстыдница? Ты хоть представляешь какой позор мне пришлось пережить!!!"
               "Вы пытались, что-либо сказать в свое оправдание, но это было бесполезно. Через полчаса часа устав на вас кричать,"
               " она более или менее успокоилась. - Света, неужели тебе самой не важна твоя репутация? - спросила она переводя дух."
               " - Иди и хорошенько подумай над этим.";
    str[99] = "- Вышла я с подругами перемолвится словечком и что я узнаю? Наша Света опять голая по деревне шастает, светит "
               "своими прелестями на всю округу. Ты хоть представляешь какой позор мне пришлось пережить, бесстыдница ты этакая!!!"
               "Вы уже и не пытались, что-либо говорить в свое оправдание, просто молча стояли, потупив взгляд... Через полчаса"
               "устав на вас кричать, она более или менее успокоилась. - Смотри Света, доиграешься, - сказала она переводя дух."
               " - Отправлю тебя назад к матери. Да и Володе позвоню, чтобы он ремня тебе как следует всыпал, выбил из тебя эту дурь.";
    str[100] = "Вы вышли к речке Змеявке, что находится около Гадюкино и двинулись в сторону деревни.";
    str[101] = "На дворе ночь и поэтому тут пустынно, и никого нет. Это хорошо, учитывая, что вы совершенно голая.";
    str[102] = "Слава богу тут никого нет, поэтому вам повезло проскочить незамеченной.";
    str[103] = "Как назло на берегу вы заметили местных рыбаков. Судя по их округлившимся глазам, они вас тоже заметили. \"Ну всё\", - подумалось вам. \"Теперь дед точно обо всем узнает.\"";

    str[104] = "Не успели вы появится во дворе, как вам на встречу шагнул дед.";
    str[105] = "- Света, поди сюда, разговор есть, - сказал он задумчиво. - Мне тут с утра мужики говорили, что видели, как ты голая расхаживала вдоль речки. Правда это, али брешут по пьяни?"
                "Вы начали сбивчиво дедушке объяснять, как это произошло, но он вас перебил на полуслове."
                "- Значит правда, - перебил он вас на полуслове. - Света, не думаешь про нашу с бабкой репутацию, хоть про свою подумай."
               " Мы то уже старые, а тебе с ней еще всю жизнь жить. Ладно, иди. Бабке я ничего не скажу, так уж и быть, не хочу чтобы расстраивалась.";
    str[106] = "- Света, поди сюда, разговор есть, - сказал он хмурясь. - Мужики опять говорят, что тебя голую видели. Совсем совесть потеряла?"
                "Вы попытались оправдаться, но он опять вас перебил на полуслове."
                "- Доиграешься, Света, ты у меня, - перебил он вас на полуслове. - Вот сниму ремень и отхожу по твоей заднице вдоль и поперек,"
               " как когда-то твоей ма... Кхе-кхе-кхе... Короче мало не покажется. Дуй отсюда, пока я добрый.";
    str[107] = "Одеваясь и поправляя одежду, вы вдруг увидели одну из бабушкиных подруг. Судя по красноречивому взгляду она все видела.";
    str[108] = "Одеваясь и поправляя одежду, вы вдруг увидели одного из деревенских жителей. Судя по красноречивому взгляду он все видел.";
    str[109] = "Не успели вы войти в избу, как на вас накинулась бабушка.";
    str[110] = "- Света, это как понимать? Я думаю, что у меня внучка приличная, а мне рассказывают, что она ебется непонятно с кем. Пошла прочь отсюда, чтобы я тебя не видела!";
    str[111] = "- Опять трахалась у всех на виду, шлюха малолетняя? Мне уже на улицу выходить стыдно из-за тебя! Пошла отсюда, не попадайся мне на глаза!";
    str[112] = "- Светуля, внучка, что ты такое вытворяешь? Я то думаю, что у меня внучка приличная, а мне тут рассказывают, как она по кустам трахается. Господи, за что ты меня так наказал!";
    str[113] = "- Света, опять ты за своё? Трахаешься у всех на виду, хоть бы постеснялась людей. Ой, позор на мою голову!";
    str[114] = "Не успели вы появится во дворе, как вам на встречу шагнул хмурый дед.";
    str[115] = "Дед посмотрел на вас гневным взглядом.";
    str[116] = "- Света, это как понимать? Я думаю, что у меня внучка приличная, а мне мужики тут докладывают, что она ебется на виду у всей деревни. Пошла отсюда, глаза б мои тебя не видели!";
    str[117] = "- Опять ебалась с кем не попадя, блядища малолетняя! Вся деревня скоро будет знать, что ты шлюха... Пошла отсюда, глаза б мои тебя не видели!";
    str[118] = "- Света, внучка, это как понимать? Мне мужики тут рассказывают про тебя нехорошие вещи. Я понимаю, дело молодое, но не на виду же у всей деревни. Не позорь нас с бабкой на старости лет.";
    str[119] = "Он хотел что-то сказать, но лишь махнул рукой, и еще больше нахмурившись, зашагал прочь.";
    str[120] = "Не успели вы появится в избе, как вам на встречу ";
    if(root->gVQuest(grandpaQW) > root->gVQuest(grandmaQW))
        str[120] += "шагнул хмурый дед";
    else
        str[120] += "вышла хмурая бабушка";
    str[120] += ".";
    str[121] = "- Света, собирай свои вещи, - сказал он. - Ты едешь домой. Мать, звони Наташе, пусть приезжает за своей непутевой дочкой. - Деда... - начали вы.";
    str[122] = "- Что, деда? - грубо перебил он вас. - Раньше думать нужно было, когда голая бегала по деревне, и сношалась с кем не попадя, как сучка течная. Опозорила нас на всю деревню, на старости лет.";
    str[123] = "- Что, деда? - грубо перебил он вас. - Раньше думать нужно было, когда голая бегала по деревне и светила своей мандой всем встречным. Опозорила нас на всю деревню.";
    str[124] = "- Что, деда? - грубо перебил он вас. - Раньше думать нужно было, когда сношалась с кем не попадя, как сучка течная. Опозорила нас на всю деревню, на старости лет.";
    str[125] = "- Что, деда? - грубо перебил он вас. - Нужно было следить за своим поведением. Хорошо, что хоть на всю деревню нас не опозорила.";
    str[126] = "- Света, собирай свои вещи, - сказал она. - Ты едешь домой. Сейчас позвоню Наташе, пусть приезжает за своей непутевой дочкой."
               "- Бабуль... - начали вы.";
    str[127] = "- Что, бабуль? - перебила она вас. - Раньше думать нужно было, когда голая бегала по деревне, и сношалась с кем не попадя, как сучка течная. Опозорила нас на всю деревню, на старости лет.";
    str[128] = "- Что, бабуль? - перебила она вас. - Раньше думать нужно было, когда голая бегала по деревне и светила своими прелестями каждому. Опозорила нас на всю деревню.";
    str[129] = "- Что, бабуль? - перебила она вас. - Раньше думать нужно было, когда сношалась с кем не попадя, как сучка течная. Опозорила нас на всю деревню, на старости лет.";
    str[130] = "- Что, бабуль? - перебила она вас. - Нужно было вести себя лучше. Хорошо, хоть в деревне ничего не знают.";
    str[131] = "Пока вы рыдая собирали свои вещи, приехала мама с отчимом, и сразу же ушли на кухню, разговаривать с дедом и бабкой."
               "- Иди в машину, дома поговорим, - бросила вам мать, но по её виду вы поняли, что ничего хорошего вас там не ждет.";
    str[132] = "<br>В коридоре вас поджидала грозная мама.";
    str[133] = "- Ну что, Света, думаю пора заняться твоим воспитанием, - с ходу начала она. ";
    if(root->gVEvent(mother_spanking) == 0)
        str[133] += "Я тебя никогда не порола... и видимо зря";
    else
        str[133] += "Я смотрю предыдущая порка тебя ничему не научила";
    str[133] += ". Наверное нужно преподать тебе";
    if(root->gVEvent(mother_spanking) == 0)
        str[133] += "урок.";
    else
        str[133] += "новый урок.";

    str[134] = "- Ну ты и учудила, Света, - сказала она, сурово глядя на вас. - Голяком по деревне бегать, это же надо додуматься!";
    if(root->gVEvent(momslut) < 2)
        str[134] += "Что о нас теперь в деревне думать будут?";
    else
        str[134] += "Даже я в твоём возрасте такого не выкидывала!";
    str[134] += "Вы виновато уставились в пол.";
    str[135] = "- Думаю нужно продолжить твое воспитание, - продолжила мать. - Я смотрю предыдущая порка тебя ничему не научила. Наверное нужно преподать тебе новый урок.";
    str[136] = "- Глаза б мои тебя не видели... - горько вздохнула мать, собираясь уходить. - Горе луковое... Не вздумай теперь в деревню соваться: старики не пустят даже в сарай. И на улице в деревне не смей появляться - не позорь нас с отцом! Деды простят со временем, конечно - они любят тебя, дурочку. Но для этого надо будет паинькой быть, и со мной отличные отношения иметь!/";
    str[137] = "- Света, это что за поведение? - сказала она, сурово глядя на вас. - Почему бабушка с дедушкой на тебя жалуются?"
               "- А что я такого сделала? - непонимающе уставились вы на мать."
               "- Не хватало, чтобы ты еще что-нибудь сделала! - воскликнула она. - Они мне ничего конкретного не рассказывали, но видимо твое постоянное непослушание им надоело."
               "Вы виновато уставились в пол.";

    str[138] = "- Мамочка! Прости! Это никогда не повторится!// - разревелись вы, опускаясь на колени. \\- Я больше никогда, никогда так не буду... Мать смотрит на вас, качает головой, и отворачивается.";

    str[139] = "Вы стоите уставившись в пол. А что тут можно сказать? Мать берет вас за руку и ведет в комнату:"
               "- Снимай трусы и нагнись! - слышите вы её голос и отрицательно качаете головой."
               "Тогда мать хватает вас и переборов короткое сопротивление, укладывает к себе на колени. Она стягивает с вас нижнее белье берет ремень и начинает пороть вас."
               "Сжав зубы вы выдерживаете экзекуцию не проронив ни слова. Подняв голову вы видите, как через незакрытую дверь, за всем этим наблюдают ваши брат и сестра.";
    str[140] = "В коридоре вы встретили маму."
                "- О, Светуля, на ловца и зверь бежит, - с улыбкой сказала она. - Звонила бабушка. Они с дедом отошли и простили тебя. Говорят, даже соскучились. Так что можешь приезжать к ним в Гадюкино когда захочешь.";
    str[141] = "В коридоре вы встретили мать."
                "- Света, почему тебя видели в деревне? - спросила она нахмурившись. - Я тебе что говорила? Чтобы ноги твоей в Гадюкино не было. Придет время, дедушка с бабушкой сами тебя простят. А до этого даже думать не смей там появляться, если не хочешь портить отношения со мной.";
    return str[id];
}

QString GadukinoEvent::act(int id)
{
    QString act[29];
    act[0] = "Пойти по ней";
    act[1] = "Отлично";
    act[2] = "Помочь";
    act[3] = "Закончить";
    act[4] = "Пусть посветит мандой";
    act[5] = "Уйти";
    act[6] = "Смотреть дальше";
    act[7] = "Пройти мимо";
    act[8] = "Далее";
    act[9] = "Согласиться";
    act[10] = "Отказаться";
    act[11] = "Подождать";
    act[12] = "Взять деньги";
    act[13] = "Убежать";
    act[14] = "Сосать";
    act[15] = "Сосать дальше";
    act[16] = "Остаться";
    act[17] = "Ехать домой";
    act[18] = "В свою комнату";
    act[19] = "Идти в избу";
    act[20] = "Сдать грибы";
    act[21] = "Сдать ягоды";
    act[22] = "Идти в деревню";
    act[23] = "Пробраться в деревню огородами";
    act[24] = "Идти собирать вещи";
    act[25] = "Ехать в домой";
    act[26] = "Умолять ничего не делать";
    act[27] = "Молчать";
    act[28] = "Отойти";

    return act[id];
}

QString GadukinoEvent::media(int id)
{
    QString med[85];
    med[0] = "data/locations/gadukino/gaddvor/meadow.jpg";
    med[1] = "data/npc/gadukino/miroslava/Mira.jpg";
    med[2] = "data/qwest/mira/MiraSP2.jpg";
    med[3] = "data/qwest/mira/MiraSP1.jpg";
    med[4] = "data/qwest/mira/MiraSP3.jpg";
    med[5] = "data/qwest/mira/MiraSP5.jpg";
    med[6] = "data/qwest/mira/MiraSexGad3.jpg";
    med[7] = "data/npc/gadukino/mitka/mitka.jpg";
    med[8] = "data/npc/gadukino/uncle_Stepan.jpg";
    med[9] = "data/qwest/gadukino/10000.jpg";
    med[10] = "data/qwest/gadukino/take_money.jpg";
    med[11] = "data/qwest/gadukino/otel4.jpg";
    med[12] = "data/qwest/gadukino/girl_escapes.jpg";
    med[13] = "data/qwest/gadriver_gang/gadriver_gang_oral1.jpg";
    med[14] = "data/qwest/gadriver_gang/gadriver_gang_oral2.jpg";
    med[15] = "data/qwest/gadriver_gang/gadriver_gang_oral3.jpg";
    med[16] = "data/qwest/gadriver_gang/gadriver_gang_cum1.jpg";
    med[17] = "data/qwest/gadriver_gang/gadriver_gang_dog1.jpg";
    med[18] = "data/qwest/gadriver_gang/gadriver_gang_dog2.jpg";
    med[19] = "data/qwest/gadriver_gang/gadriver_gang_dog3.jpg";
    med[20] = "data/qwest/gadriver_gang/gadriver_gang_dog2.jpg";
    med[21] = "data/qwest/gadriver_gang/gadriver_gang_mis1.jpg";
    med[22] = "data/qwest/gadriver_gang/gadriver_gang_mis2.jpg";
    med[23] = "data/qwest/gadriver_gang/gadriver_gang_mis3.jpg";
    med[24] = "data/qwest/gadriver_gang/gadriver_gang_oral4.jpg";
    med[25] = "data/qwest/gadriver_gang/gadriver_gang_cum2.jpg";
    med[26] = "data/qwest/gadriver_gang/gadriver_gang_dog5.jpg";
    med[27] = "data/qwest/gadriver_gang/gadriver_gang_dog6.jpg";
    med[28] = "data/qwest/gadriver_gang/gadriver_gang_dog7.jpg";
    med[29] = "data/qwest/gadriver_gang/gadriver_gang_dog8.jpg";
    med[30] = "data/qwest/gadriver_gang/gadriver_gang_dog9.jpg";
    med[31] = "data/qwest/gadriver_gang/gadriver_gang_dog10.jpg";
    med[32] = "data/qwest/gadriver_gang/gadriver_gang_oral5.jpg";
    med[33] = "data/qwest/gadriver_gang/gadriver_gang_cow1.jpg";
    med[34] = "data/qwest/gadriver_gang/gadriver_gang_cow2.jpg";
    med[35] = "data/qwest/gadriver_gang/gadriver_gang_cow3.jpg";
    med[36] = "data/qwest/gadriver_gang/gadriver_gang_DP1.jpg";
    med[37] = "data/qwest/gadriver_gang/gadriver_gang_DP2.jpg";
    med[38] = "data/qwest/gadriver_gang/gadriver_gang_oral6.jpg";
    med[39] = "data/qwest/gadriver_gang/gadriver_gang_cum3.jpg";
    med[40] = "data/qwest/gadriver_gang/gadriver_gang_cum4.jpg";
    med[41] = "data/locations/gadukino/collection_point.jpg";
    med[42] = "data/npc/gadukino/grandma/grandma_gadukino.jpg";
    med[43] = "data/npc/gadukino/old_woman/gadukino_old_woman.jpg";
    med[44] = "data/actions/spank/nospanking.jpg";
    med[45] = "data/actions/spank/spanking.jpg";
    med[46] = "data/locations/gadukino/gaddvor/trail_meadow.jpg";
    med[47] = "data/qwest/mira/Miroslava.jpg";
    med[48] = "data/npc/gadukino/miroslava/Mira1.jpg";
    med[49] = "data/npc/gadukino/miroslava/Mira4.jpg";
    med[50] = "data/qwest/mira/Mira2.jpg";
    med[51] = "data/qwest/mira/MiraSexGad1.jpg";
    med[52] = "data/qwest/mira/MiraSexGad.jpg";
    med[53] = "data/qwest/mira/MiraSexGad2.jpg";
    med[54] = "data/actions/gad_walk_rand/walk" + intQStr(walki) + ".jpg";
    med[55] = "data/qwest/mira/MiraSexGad5.jpg";
    med[56] = "data/qwest/mira/MiraSexGad6.jpg";
    med[57] = "data/qwest/mira/MiraSexGad7.jpg";
    med[58] = "data/qwest/mira/MiraSexGad8.jpg";
    med[59] = "data/qwest/mira/MiraSexGad9.jpg";
    med[60] = "data/qwest/mira/MiraSexGad10.jpg";
    med[61] = "data/qwest/mira/MiraSexGad11.jpg";
    med[62] = "data/qwest/mira/MiraHorny.jpg";
    med[63] = "data/actions/gad_walk_rand/GadLol.jpg";
    med[64] = "data/actions/gad_walk_rand/GadLol1.jpg";
    med[65] = "data/actions/gad_walk_rand/GadLol2.jpg";
    med[66] = "data/actions/gad_walk_rand/GadLol3.jpg";
    med[67] = "data/actions/gad_walk_rand/GadLol4.jpg";
    med[68] = "data/qwest/gadukino/turn_back.jpg";
    med[69] = "data/qwest/gadriver_gang/gadriver_gang.jpg";
    med[70] = "data/npc/gadukino/mitka/kolyamba.jpg";
    med[71] = "data/npc/gadukino/mitka/vasyan.jpg";
    med[72] = "data/npc/gadukino/mitka/2boys.1.jpg";
    med[73] = "data/npc/gadukino/mitka/2boys.2.jpg";
    med[74] = "data/npc/gadukino/mitka/3boys.1.jpg";
    med[75] = "data/npc/gadukino/mitka/3boys.2.jpg";
    med[76] = "data/qwest/gadukino_nude/gadukino_back.jpg";
    med[77] = "data/qwest/gadukino_nude/gadukino_back_night.jpg";
    med[78] = "data/qwest/gadukino_nude/gadukino_nude_night.jpg";
    med[79] = "data/qwest/gadukino_nude/gadukino_nude_rain.jpg";
    med[80] = "data/qwest/gadukino_nude/gadukino_nude.jpg";
    med[81] = "data/qwest/gadukino/grandma.jpg";
    med[82] = "data/qwest/gadukino_nude/gadukino_nude_fishers.jpg";
    med[83] = "data/qwest/gadukino/grandpa.jpg";
    med[84] = "data/qwest/gadukino/gadukino_old_woman" + intQStr(getRandInt(1,5)) + ".jpg";
    return med[id];
}

void GadukinoEvent::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &GadukinoEvent::actionHandler);
    root->addActBtn(btn);
}
