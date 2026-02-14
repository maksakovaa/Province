#include "sisterqw.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

SisterQW::SisterQW(Game* ptr): root(ptr) {}

void SisterQW::start(QString arg)
{
    if(arg == "sisboyQW_caress")
        sisboyQW_caress();
    if(arg == "sisboytrio_prepeare")
        sisboytrio_prepeare();
    if(arg == "sisboytrio_sex")
        sisboytrio_sex();
    if(arg == "sisboytrio_suck")
        sisboytrio_suck();
    if(arg == "sisboytrioQW_bedroom")
        sisboytrioQW_bedroom();
    if(arg == "incest_event1")
        incest_event1();
    if(arg == "incest_event2")
        incest_event2();
    if(arg == "incest_event3")
        incest_event3();
    if(arg == "incest_event3sub")
        incest_event3sub();
    if(arg == "incest_event4")
        incest_event4();
    if(arg == "incest_event5")
        incest_event5();
    if(arg == "incest_event5sub")
        incest_event5sub();
    if(arg == "incest_event6shop")
        incest_event6shop();
    if(arg == "incest_event6")
        incest_event6();
    if(arg == "incest_event6sub")
        incest_event6sub();
    if(arg == "incest_event7")
        incest_event7();
    if(arg == "incest_event8")
        incest_event8();
    if(arg == "incest_event8sub")
        incest_event8sub();
    if(arg == "incest_event9")
        incest_event9();
    if(arg == "incest_event10")
        incest_event10();
    if(arg == "incest_event10sub")
        incest_event10sub();
    if(arg == "incest_event11")
        incest_event11();
    if(arg == "incest_mini1")
        incest_mini1();
    if(arg == "incest_mini2")
        incest_mini2();
    if(arg == "incest_dialog1")
        incest_dialog1();
    if(arg == "incest_dialog2")
        incest_dialog2();
    if(arg == "incest_dialog3")
        incest_dialog3();
    if(arg == "incest_event12sub")
        incest_event12sub();
    if(arg == "incest_event12")
        incest_event12();
    if(arg == "incest_event14")
        incest_event14();
}

void SisterQW::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Sister");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &SisterQW::actionHandler);
    root->addActions(btn);
}

void SisterQW::actionHandler(QString action)
{
    if(action == "incest_event12")
        incest_event12();
    if(action == "gorodok")
        root->changeLoc(lgorodok);
    if(action == "kuhrPar")
        root->changeLoc(lkuhrpar);
    if(action == "bathroom")
    {
        root->setCurLoc(lkorrpar);
        root->changeLoc(lbathroom);
    }
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "korrPar")
        root->changeLoc(lkorrpar);
    if(action == "bedrPar")
        root->changeLoc(lbedrpar);
    if(action == "bedrPar15")
    {
        root->changeLoc(lbedrpar,15);
    }
    if(action == "sisboyQW_caress")
        sisboyQW_caress();
    if(action == "sisboyQW_party")
        sisboyQW_party();
    if(action == "sisboytrio_prepeare")
        sisboytrio_prepeare();
    if(action == "sisboytrio_suck")
        sisboytrio_suck();
    if(action == "sisboytrio_sex")
        sisboytrio_sex();
    if(action == "sisboytrio_end")
        sisboytrio_end();
    if(action == "bedroomWatch.1")
    {
        root->incTime(5);
        root->vStatus(horny) = 90;
        root->setImage(media(13));
        root->setText(str(10));
        makeActBtn("bedroomWatch.2",act(1));
        makeActBtn("sisboyQW_caress",act(2));
        makeActBtn("korrPar",act(0));
    }
    if(action == "bedroomWatch.2")
    {
        root->incTime(5);
        root->vStatus(horny) = 95;
        root->setImage(media(14));
        root->setText(str(11));
        makeActBtn("bedroomWatch.3",act(1));
        makeActBtn("sisboyQW_caress",act(2));
        makeActBtn("korrPar",act(0));
    }
    if(action == "bedroomWatch.3")
    {
        root->incTime(5);
        root->vStatus(horny) = 100;
        if(root->vQuest(qwSisterBoy) == 7)
        {
            root->vQuest(qwSisterBoy) = 8;
            root->vQuest(qwSisterLesbi) = 0;
        }
        root->setImage(media(15));
        root->setText(str(12));
        makeActBtn("sisboyQW_caress",act(2));
    }
    if(action == "sisboytrioQW_bedroom.run")
    {
        root->vQuest(qwSisterTrio) -= 1;
        root->vEvent(sisBoyTrioDayOtkaz) = root->vStatus(daystart) + 3;
        root->incTime(5);
        root->changeRep('-',sister,20);
        root->vQuest(qwSisterBoy) = 2;
        root->vEvent(sisThank) = 0;
        root->setImage(media(40));
        root->setText(str(24));
        makeActBtn("korrPar",act(5));
    }
    if(action == "sisboy_dance")
        sisboy_dance();
    if(action == "sisboy_drink")
        sisboy_drink();
    if(action == "sisboy_sit")
        sisboy_sit();
    if(action == "sisboyQW_party.drinkAlko")
    {
        root->fnAlko(3);
        root->setImage(media(94));
        root->setText(str(66));
        makeActBtn("sisboy_dance",act(6));
        makeActBtn("sisboy_drink",act(13));
        makeActBtn("sisboy_sit",act(14));
    }
    if(action == "sisboyQW_party.discardAlko")
    {
        root->fnAlko(3);
        root->setImage(media(94));
        root->setText(str(67));
        makeActBtn("sisboy_dance",act(6));
        makeActBtn("sisboy_drink",act(13));
        makeActBtn("sisboy_sit",act(14));
    }
    if(action == "sisboyQW_party.standDance")
    {
        root->fnAlko(3);
        root->setImage(media(94));
        root->setText(str(68));
        makeActBtn("sisboy_dance",act(6));
        makeActBtn("sisboy_drink",act(13));
        makeActBtn("sisboy_sit",act(14));
    }
    if(action == "sisboy_dance.dance")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->setImage(media(69));
        root->setText(str(63));
        makeActBtn("sisboy_twoboy",act(9));
        makeActBtn("sisboy_annaFind",act(15));
        makeActBtn("sisboy_reks",act(16));
    }
    if(action == "sisboy_dance.drink")
    {
        root->fnAlko(3);
        root->vStatus(horny) += 10;
        root->setImage(media(64));
        root->setText(str(62));
        makeActBtn("sisboy_twoboy",act(9));
    }
    if(action == "sisboy_twoboy.go")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(66));
        root->setText(str(59));
        makeActBtn("sisboy_twoboy.standDoggy",act(18));
    }
    if(action == "sisboy_twoboy.standDoggy")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->vStatistics(gangBang) += 1;
        root->vSex(guy) += 2;
        root->vStatistics(blowJob) += 1;
        root->vStatistics(vaginalSex) += 1;
        root->setImage(media(67));
        root->setText(str(60));
        makeActBtn("sisboy_twoboy.swap",act(19));
    }
    if(action == "sisboy_twoboy.swap")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->vStatistics(blowJob) += 1;
        root->vStatistics(vaginalSex) += 1;
        root->cum("lip");
        root->cum("face");
        root->vStatistics(swallow) += 1;
        root->cum("ass");
        root->setImage(media(68));
        root->setText(str(61));
        makeActBtn("sisboy_annaFind",act(15));
    }

    if(action == "sisboy_reks")
        sisboy_reks();
    if(action == "sisboy_annaFind")
        sisboy_annaFind();
    if(action == "sisboy_twoboy")
        sisboy_twoboy();
    if(action == "sisboy_Annakuch.turnBack")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(77));
        root->setText(str(49));
        makeActBtn("sisboy_Annakuch.followAnya",act(24));
    }
    if(action == "sisboy_Annakuch.followAnya")
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(78));
        root->setText(str(50));
        makeActBtn("sisboy_Annakuch.wait",act(25));
        makeActBtn("sisboy_Annakuch.join",act(26));
    }
    if(action == "sisboy_Annakuch.wait")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->setImage(media(79));
        root->setText(str(51));
        if(root->getHour() < 22)
        {
            root->setTime(22,0);
            makeActBtn("bedrPar",act(0));
        }
        else
            makeActBtn("bedrPar15",act(0));
    }
    if(action == "sisboy_Annakuch.join")
    {
        root->vEvent(sisterKnowSlut) = 2;
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(gangBang) += 1;
        root->vStatistics(vaginalSex) += 1;
        root->vSex(guy) += 1;
        root->cum("lip");
        root->setImage(media(80));
        root->setText(str(52));
        if(root->getHour() < 22)
        {
            root->setTime(22,0);
            makeActBtn("bedrPar",act(0));
        }
        else
            makeActBtn("bedrPar15",act(0));
    }
    if(action == "sisboy_reks.goToilet")
    {
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->vEvent(toiletRexSex) = 1;
        root->setImage(media(72));
        root->setText(str(56));
        makeActBtn("sisboy_reks.standDoggy",act(18));
    }
    if(action == "sisboy_reks.standDoggy")
    {
        root->incTime(5);
        root->vStatus(horny) += 10;
        root->vStatistics(vaginalSex) += 1;
        root->vSex(guy) += 1;
        root->vEvent(reksSex) = 1;
        root->setImage(media(73));
        root->setText(str(57));
        root->cum("pussy");
        makeActBtn("sisboy_annaFind",act(15));
    }

    if(action == "party_pre_conditions")
        party_pre_conditions();
    if(action == "sbReksHome.party")
    {

    }
    if(action == "sbReksHome.cancel")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(95));
        root->setText(str(70));
        makeActBtn("back_to_loc",act(29));
    }
    if(action == "sbReksHome.cancel2")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(96));
        root->setText(str(76));
        makeActBtn("back_to_loc",act(29));
    }

    if(action == "meet_sister.drinkBeer")
    {
        root->clearActions();
        if(root->vEvent(AniaFriends) == 1)
        {
            if(getRandInt(0,1) == 0 && root->vQuest(qwSisterTrio) > 0)
                root->startEvent(eDinSister, "beach_events");
            else
                root->startEvent(eAnnaFriends);
        }
        else
        {
            root->vEvent(AniaFriends) = 1;
            root->incTime(40);
            root->changeRep('+',sister);
            root->fnAlko(3);
            if(root->gNPC(sister).location == lgdk)
                root->setImage(media(98));
            else if(root->gNPC(sister).location == lglake)
                root->setImage(media(99));
            else if(root->gNPC(sister).location == lcafeparco)
                root->setImage(media(97));
            root->setText(str(84));
        }
        makeActBtn("back_to_loc",act(29));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 1
    /////////////////////////////////////////////////////////////

    if(action == "incest_event1.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(101));
        root->setText(str(86));
        makeActBtn("incest_event1.2",act(32));
    }
    if(action == "incest_event1.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(102));
        root->setText(str(87));
        makeActBtn("incest_event1.3",act(32));
    }
    if(action == "incest_event1.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(103));
        root->setText(str(88));
        makeActBtn("incest_event1.4",act(32));
    }
    if(action == "incest_event1.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(104));
        root->setText(str(89));
        makeActBtn("incest_event1.5",act(32));
    }
    if(action == "incest_event1.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(105));
        root->setText(str(90));
        makeActBtn("incest_event1.getOut",act(33));
        makeActBtn("incest_event1.beQuiet",act(34));
    }
    if(action == "incest_event1.getOut")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(105));
        root->setText(str(91));
        makeActBtn("bed.sleep",act(35));
    }
    if(action == "bed.sleep")
    {

    }
    if(action == "incest_event1.beQuiet")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(106));
        root->setText(str(92));
        makeActBtn("incest_event1.beQuiet.2",act(32));
    }
    if(action == "incest_event1.beQuiet.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(107));
        root->setText(str(93));
        makeActBtn("incest_event1.beQuiet.3",act(32));
    }
    if(action == "incest_event1.beQuiet.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(108));
        root->setText(str(94));
        makeActBtn("incest_event1.beQuiet.4",act(32));
    }
    if(action == "incest_event1.beQuiet.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(109));
        root->setText(str(95));
        makeActBtn("incest_event1.beQuiet.5",act(32));
    }
    if(action == "incest_event1.beQuiet.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(110));
        root->setText(str(96));
        makeActBtn("incest_event1.beQuiet.6",act(32));
    }
    if(action == "incest_event1.beQuiet.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(111));
        root->setText(str(97));
        makeActBtn("incest_event1.beQuiet.7",act(32));
    }
    if(action == "incest_event1.beQuiet.7")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(112));
        root->setText(str(98));
        makeActBtn("incest_event1.beQuiet.8",act(32));
    }
    if(action == "incest_event1.beQuiet.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(113));
        root->setText(str(99));
        makeActBtn("incest_event1.beQuiet.9",act(32));
    }
    if(action == "incest_event1.beQuiet.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(114));
        root->setText(str(100));
        makeActBtn("incest_event1.beQuiet.10",act(32));
    }
    if(action == "incest_event1.beQuiet.10")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(115));
        root->setText(str(101));
        makeActBtn("incest_event1.beQuiet.11",act(32));
    }
    if(action == "incest_event1.beQuiet.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(116));
        root->setText(str(102));
        makeActBtn("incest_event1.beQuiet.12",act(32));
    }
    if(action == "incest_event1.beQuiet.12")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 25;
        root->setImage(media(117));
        root->setText(str(103));
        makeActBtn("incest_event1.beQuiet.13",act(32));
    }
    if(action == "incest_event1.beQuiet.13")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(118));
        root->setText(str(104));
        if(root->vStatus(horny) >= 90 && root->vEvent(Kolkawin) == 1)
        {
            makeActBtn("incest_event1.beQuiet.cumLoud",act(3));
        }
        else
        {
            makeActBtn("incest_event1.beQuiet.cumSlow",act(36));
        }
    }
    if(action == "incest_event1.beQuiet.cumLoud")
    {
        root->clearActions();
        root->vQuest(qwKolka) = 1;
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(124));
        root->setText(str(105));
        makeActBtn("incest_event1.beQuiet.cumLoud.1",act(32));
    }
    if(action == "incest_event1.beQuiet.cumLoud.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(125));
        root->setText(str(106));
        makeActBtn("incest_event1.beQuiet.cumLoud.2",act(32));
    }
    if(action == "incest_event1.beQuiet.cumLoud.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(126));
        root->setText(str(107));
        makeActBtn("bed.sleep",act(35));
    }
    if(action == "incest_event1.beQuiet.cumSlow")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 75;
        root->setImage(media(119));
        root->setText(str(108));
        makeActBtn("incest_event1.beQuiet.cumSlow.1",act(32));
    }
    if(action == "incest_event1.beQuiet.cumSlow.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(120));
        root->setText(str(109));
        makeActBtn("incest_event1.beQuiet.cumSlow.2",act(32));
    }
    if(action == "incest_event1.beQuiet.cumSlow.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(121));
        root->setText(str(110));
        makeActBtn("incest_event1.beQuiet.cumSlow.3",act(32));
    }
    if(action == "incest_event1.beQuiet.cumSlow.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(122));
        root->setText(str(111));
        makeActBtn("incest_event1.beQuiet.cumSlow.4",act(32));
    }
    if(action == "incest_event1.beQuiet.cumSlow.4")
    {
        root->clearActions();
        root->incTime(1);
        root->vEvent(Kolkawin) = 1;
        root->setImage(media(123));
        root->setText(str(112));
        makeActBtn("bed.sleep",act(35));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 2
    /////////////////////////////////////////////////////////////

    if(action == "incest_event2.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(128));
        root->setText(str(114));
        makeActBtn("incest_event2.2",act(32));
    }
    if(action == "incest_event2.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(129));
        root->setText(str(115));
        makeActBtn("incest_event2.3",act(32));
    }
    if(action == "incest_event2.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(130));
        root->setText(str(116));
        makeActBtn("incest_event2.4",act(32));
    }
    if(action == "incest_event2.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(131));
        root->setText(str(117));
        makeActBtn("incest_event2.5",act(32));
    }
    if(action == "incest_event2.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(132));
        root->setText(str(118));
        makeActBtn("incest_event2.6",act(32));
    }
    if(action == "incest_event2.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(133));
        root->setText(str(119));
        makeActBtn("incest_event2.7",act(32));
    }
    if(action == "incest_event2.7")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(134));
        root->setText(str(120));
        makeActBtn("incest_event2.8",act(32));
    }
    if(action == "incest_event2.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(135));
        root->setText(str(121));
        makeActBtn("incest_event2.9",act(32));
    }
    if(action == "incest_event2.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(136));
        root->setText(str(122));
        makeActBtn("incest_event2.10",act(32));
    }
    if(action == "incest_event2.10")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(137));
        root->setText(str(123));
        root->vStatus(horny) += 20;
        makeActBtn("incest_event2.11",act(32));
    }
    if(action == "incest_event2.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(138));
        root->setText(str(124));
        makeActBtn("incest_event2.12",act(32));
    }
    if(action == "incest_event2.12")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(139));
        root->setText(str(125));
        root->vStatus(horny) += 10;
        makeActBtn("incest_event2.13",act(32));
    }
    if(action == "incest_event2.13")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(140));
        root->setText(str(126));
        root->vStatus(horny) = 95;
        makeActBtn("incest_event2.14",act(32));
    }
    if(action == "incest_event2.14")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(141));
        root->setText(str(127));
        makeActBtn("incest_event2.15",act(32));
    }
    if(action == "incest_event2.15")
    {
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwKolka) = 2;
        root->cum("face");
        root->setImage(media(142));
        root->setText(str(128));
        makeActBtn("bathroom",act(37));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 3
    /////////////////////////////////////////////////////////////

    if(action == "incest_event3.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(144));
        root->setText(str(130));
        makeActBtn("incest_event3.2",act(32));
    }
    if(action == "incest_event3.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(145));
        root->setText(str(131));
        makeActBtn("incest_event3.3",act(32));
    }
    if(action == "incest_event3.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(146));
        root->setText(str(132));
        makeActBtn("incest_event3.4",act(32));
    }
    if(action == "incest_event3.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(147));
        root->setText(str(133));
        makeActBtn("incest_event3.stop",act(38));
        makeActBtn("incest_event3.5",act(39));
    }
    if(action == "incest_event3.stop")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(147));
        root->setText(str(134));
        makeActBtn("korrPar",act(32));
    }
    if(action == "incest_event3.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(148));
        root->setText(str(135));
        makeActBtn("incest_event3.6",act(32));
    }
    if(action == "incest_event3.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(149));
        root->setText(str(136));
        makeActBtn("incest_event3.7",act(32));
    }
    if(action == "incest_event3.7")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(150));
        root->setText(str(137));
        makeActBtn("incest_event3.8",act(32));
    }
    if(action == "incest_event3.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(151));
        root->setText(str(138));
        makeActBtn("incest_event3.9",act(32));
    }
    if(action == "incest_event3.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(152));
        root->setText(str(139));
        makeActBtn("incest_event3.10",act(32));
    }
    if(action == "incest_event3.10")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(153));
        root->setText(str(140));
        makeActBtn("incest_event3.11",act(32));
    }
    if(action == "incest_event3.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(154));
        root->setText(str(141));
        root->vStatus(horny) += 20;
        makeActBtn("incest_event3.12",act(32));
    }
    if(action == "incest_event3.12")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(155));
        root->setText(str(142));
        makeActBtn("incest_event3.13",act(32));
    }
    if(action == "incest_event3.13")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(156));
        root->setText(str(143));
        root->vStatus(horny) = 98;
        makeActBtn("incest_event3.14",act(32));
    }
    if(action == "incest_event3.14")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(157));
        root->setText(str(144));
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(horny) = 70;
        makeActBtn("incest_event3.15",act(32));
    }
    if(action == "incest_event3.15")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(158));
        root->setText(str(145));
        makeActBtn("incest_event3.16",act(32));
    }
    if(action == "incest_event3.16")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(159));
        root->setText(str(146));
        makeActBtn("incest_event3.17",act(32));
    }
    if(action == "incest_event3.17")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(160));
        root->setText(str(147));
        makeActBtn("incest_event3.18",act(32));
    }
    if(action == "incest_event3.18")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(161));
        root->setText(str(148));
        root->vStatus(horny) += 20;
        makeActBtn("incest_event3.19",act(32));
    }
    if(action == "incest_event3.19")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(162));
        root->setText(str(149));
        makeActBtn("incest_event3.20",act(32));
    }
    if(action == "incest_event3.20")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(vaginalOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(163));
        root->setText(str(150));
        makeActBtn("incest_event3.21",act(32));
    }
    if(action == "incest_event3.21")
    {
        root->clearActions();
        root->incTime(1);
        root->cum("face");
        root->setImage(media(164));
        root->setText(str(151));
        makeActBtn("incest_event3.22",act(32));
    }
    if(action == "incest_event3.22")
    {
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwKolka) = 3;
        root->cum("belly");
        root->setImage(media(165));
        root->setText(str(152));
        makeActBtn("bathroom",act(37));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 3 SUB
    /////////////////////////////////////////////////////////////

    if(action == "incest_event3sub.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(167));
        root->setText(str(154));
        makeActBtn("incest_event3sub.2",act(32));
    }
    if(action == "incest_event3sub.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(168));
        root->setText(str(155));
        makeActBtn("incest_event3sub.3",act(32));
    }
    if(action == "incest_event3sub.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(169));
        root->setText(str(156));
        makeActBtn("incest_event3sub.4",act(32));
    }
    if(action == "incest_event3sub.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(170));
        root->setText(str(157));
        makeActBtn("incest_event3sub.5",act(32));
    }
    if(action == "incest_event3sub.5")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->setImage(media(171));
        root->setText(str(158));
        makeActBtn("incest_event3sub.6",act(32));
    }
    if(action == "incest_event3sub.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(172,173)));
        root->setText(str(159));
        makeActBtn("incest_event3sub.7",act(32));
    }
    if(action == "incest_event3sub.7")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(174,176)));
        root->setText(str(160));
        makeActBtn("incest_event3sub.8",act(32));
    }
    if(action == "incest_event3sub.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(177,178)));
        root->setText(str(161));
        makeActBtn("incest_event3sub.9",act(32));
    }
    if(action == "incest_event3sub.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(179));
        root->setText(str(162));
        makeActBtn("incest_event3sub.10",act(32));
    }
    if(action == "incest_event3sub.10")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(180,181)));
        root->setText(str(163));
        makeActBtn("incest_event3sub.11",act(32));
    }
    if(action == "incest_event3sub.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(182,183)));
        root->setText(str(164));
        makeActBtn("incest_event3sub.12",act(32));
    }
    if(action == "incest_event3sub.12")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(getRandInt(184,185)));
        root->setText(str(165));
        makeActBtn("incest_event3sub.13",act(32));
    }
    if(action == "incest_event3sub.13")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(186,187)));
        root->setText(str(166));
        makeActBtn("incest_event3sub.14",act(32));
    }
    if(action == "incest_event3sub.14")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(188,189)));
        root->setText(str(167));
        makeActBtn("incest_event3sub.15",act(32));
    }
    if(action == "incest_event3sub.15")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(getRandInt(190,194)));
        root->setText(str(168));
        makeActBtn("incest_event3sub.16",act(32));
    }
    if(action == "incest_event3sub.16")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(getRandInt(195,198)));
        root->setText(str(169));
        makeActBtn("incest_event3sub.17",act(32));
    }
    if(action == "incest_event3sub.17")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(199));
        root->setText(str(170));
        makeActBtn("incest_event3sub.18",act(32));
    }
    if(action == "incest_event3sub.18")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(200,201)));
        root->setText(str(171));
        makeActBtn("incest_event3sub.19",act(32));
    }
    if(action == "incest_event3sub.19")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(202,203)));
        root->setText(str(172));
        makeActBtn("incest_event3sub.20",act(32));
    }
    if(action == "incest_event3sub.20")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(204,206)));
        root->setText(str(173));
        makeActBtn("bathroom",act(37));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 4
    /////////////////////////////////////////////////////////////
    if(action == "incest_event4.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(208));
        root->setText(str(175));
        makeActBtn("incest_event4.2",act(32));
    }
    if(action == "incest_event4.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(209));
        root->setText(str(176));
        makeActBtn("incest_event4.3",act(32));
    }
    if(action == "incest_event4.3")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->setImage(media(210));
        root->setText(str(177));
        makeActBtn("incest_event4.4",act(32));
    }
    if(action == "incest_event4.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(211));
        root->setText(str(178));
        makeActBtn("incest_event4.5",act(32));
    }
    if(action == "incest_event4.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(212));
        root->setText(str(179));
        makeActBtn("incest_event4.6",act(32));
    }
    if(action == "incest_event4.6")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(213));
        root->setText(str(180));
        makeActBtn("incest_event4.7",act(32));
    }
    if(action == "incest_event4.7")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 80;
        root->setImage(media(214));
        root->setText(str(181));
        makeActBtn("incest_event4.8",act(32));
    }
    if(action == "incest_event4.8")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(215));
        root->setText(str(182));
        makeActBtn("incest_event4.9",act(32));
    }
    if(action == "incest_event4.9")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(energy) += 5;
        root->vQuest(qwKolka) = 4;
        root->setImage(media(216));
        root->setText(str(183));
        makeActBtn("kuhrPar",act(40));
    }
    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 5
    /////////////////////////////////////////////////////////////
    if(action == "incest_event5.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(218));
        root->setText(str(185));
        makeActBtn("incest_event5.2",act(32));
    }
    if(action == "incest_event5.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(219));
        root->setText(str(186));
        makeActBtn("incest_event5.3",act(32));
    }
    if(action == "incest_event5.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(220));
        root->setText(str(187));
        makeActBtn("incest_event5.4",act(32));
    }
    if(action == "incest_event5.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(221));
        root->setText(str(188));
        makeActBtn("incest_event5.stop",act(41));
        makeActBtn("incest_event5.5",act(42));
    }
    if(action == "incest_event5.stop")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(221));
        root->setText(str(189));
        makeActBtn("kuhrPar",act(32));
    }
    if(action == "incest_event5.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(222));
        root->setText(str(190));
        makeActBtn("incest_event5.6",act(32));
    }
    if(action == "incest_event5.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(223));
        root->setText(str(191));
        makeActBtn("incest_event5.7",act(32));
    }
    if(action == "incest_event5.7")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 25;
        root->setImage(media(224));
        root->setText(str(192));
        makeActBtn("incest_event5.8",act(32));
    }
    if(action == "incest_event5.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(225));
        root->setText(str(193));
        makeActBtn("incest_event5.9",act(32));
    }
    if(action == "incest_event5.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(226));
        root->setText(str(194));
        makeActBtn("incest_event5.10",act(32));
    }
    if(action == "incest_event5.10")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(227));
        root->setText(str(195));
        makeActBtn("incest_event5.11",act(32));
    }
    if(action == "incest_event5.11")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(horny) = 0;
        root->vStatus(lust) = 0;
        root->setImage(media(228));
        root->setText(str(196));
        makeActBtn("incest_event5.12",act(32));
    }
    if(action == "incest_event5.12")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(229));
        root->setText(str(197));
        makeActBtn("incest_event5.13",act(32));
    }
    if(action == "incest_event5.13")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(230));
        root->setText(str(198));
        makeActBtn("incest_event5.14",act(32));
    }
    if(action == "incest_event5.14")
    {
        root->clearActions();
        root->incTime(1);
        root->cum("ass");
        root->setImage(media(231));
        root->setText(str(199));
        makeActBtn("incest_event5.15",act(32));
    }
    if(action == "incest_event5.15")
    {
        root->clearActions();
        root->incTime(1);
        root->cum("anus");
        root->setImage(media(232));
        root->setText(str(200));
        makeActBtn("kuhrPar",act(43));
    }
    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 5 SUB
    /////////////////////////////////////////////////////////////
    if(action == "incest_event5sub.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(234));
        root->setText(str(202));
        makeActBtn("incest_event5sub.2",act(32));
    }
    if(action == "incest_event5sub.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(235));
        root->setText(str(203));
        makeActBtn("incest_event5sub.3",act(32));
    }
    if(action == "incest_event5sub.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(236,237)));
        root->setText(str(204));
        makeActBtn("incest_event5sub.4",act(32));
    }
    if(action == "incest_event5sub.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(238,239)));
        root->setText(str(205));
        makeActBtn("incest_event5sub.5",act(32));
    }
    if(action == "incest_event5sub.5")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(getRandInt(240,242)));
        root->setText(str(206));
        makeActBtn("incest_event5sub.6",act(32));
    }
    if(action == "incest_event5sub.6")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(getRandInt(243,244)));
        root->setText(str(207));
        makeActBtn("incest_event5sub.7",act(32));
    }
    if(action == "incest_event5sub.7")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(245,246)));
        root->setText(str(208));
        makeActBtn("incest_event5sub.8",act(32));
    }
    if(action == "incest_event5sub.8")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(getRandInt(247,249)));
        root->setText(str(209));
        makeActBtn("incest_event5sub.9",act(32));
    }
    if(action == "incest_event5sub.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(250,251)));
        root->setText(str(210));
        makeActBtn("incest_event5sub.10",act(32));
    }
    if(action == "incest_event5sub.10")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(getRandInt(252,254)));
        root->setText(str(211));
        makeActBtn("incest_event5sub.11",act(32));
    }
    if(action == "incest_event5sub.11")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->redress(ClothType::Main, nullptr);
        ((BathRoom*)root->getLocPtr(lbathroom))->cleanMe();
        root->setImage(media(getRandInt(255,258)));
        root->setText(str(212));
        makeActBtn("bathroom",act(44));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 6
    /////////////////////////////////////////////////////////////

    if(action == "incest_event6.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(261));
        root->setText(str(214));
        makeActBtn("incest_event6.2",act(32));
    }
    if(action == "incest_event6.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(262));
        root->setText(str(215));
        makeActBtn("incest_event6.3",act(32));
    }
    if(action == "incest_event6.3")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(263));
        root->setText(str(216));
        makeActBtn("incest_event6.4",act(32));
    }
    if(action == "incest_event6.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(264));
        root->setText(str(217));
        makeActBtn("incest_event6.5",act(32));
    }
    if(action == "incest_event6.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(265));
        root->setText(str(218));
        makeActBtn("incest_event6.6",act(32));
    }
    if(action == "incest_event6.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(266));
        root->setText(str(219));
        makeActBtn("incest_event6.7",act(32));
    }
    if(action == "incest_event6.7")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->setImage(media(267));
        root->setText(str(220));
        makeActBtn("incest_event6.8",act(32));
    }
    if(action == "incest_event6.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(268));
        root->setText(str(221));
        makeActBtn("incest_event6.9",act(32));
    }
    if(action == "incest_event6.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(269));
        root->setText(str(222));
        makeActBtn("incest_event6.10",act(32));
    }
    if(action == "incest_event6.10")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(270));
        root->setText(str(223));
        makeActBtn("incest_event6.11",act(32));
    }
    if(action == "incest_event6.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(271));
        root->setText(str(224));
        makeActBtn("incest_event6.12",act(32));
    }
    if(action == "incest_event6.12")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(272));
        root->setText(str(225));
        makeActBtn("incest_event6.13",act(32));
    }
    if(action == "incest_event6.13")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 15;
        root->setImage(media(273));
        root->setText(str(226));
        makeActBtn("incest_event6.14",act(32));
    }
    if(action == "incest_event6.14")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(274));
        root->setText(str(227));
        makeActBtn("incest_event6.15",act(32));
    }
    if(action == "incest_event6.15")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(275));
        root->setText(str(228));
        makeActBtn("incest_event6.16",act(32));
    }
    if(action == "incest_event6.16")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(276));
        root->setText(str(229));
        makeActBtn("incest_event6.17",act(32));
    }
    if(action == "incest_event6.17")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(277));
        root->setText(str(230));
        makeActBtn("incest_event6.18",act(32));
    }
    if(action == "incest_event6.18")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(278));
        root->setText(str(231));
        makeActBtn("incest_event6.19",act(32));
    }
    if(action == "incest_event6.19")
    {
        root->clearActions();
        root->incTime(1);
        root->cum("pussy");
        root->setImage(media(279));
        root->setText(str(232));
        makeActBtn("incest_event6.20",act(32));
    }
    if(action == "incest_event6.20")
    {
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwKolka) = 6;
        root->setImage(media(280));
        root->setText(str(233));
        makeActBtn("bed.sleep",act(35));
    }
    if(action == "incest_event6shop.1")
    {
        root->clearActions();
        root->incTime(120);
        root->vStatus(money) -= 10000;
        root->setImage(media(259));
        root->setText(str(235));
        makeActBtn("bedrPar",act(46));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 6 SUB
    /////////////////////////////////////////////////////////////

    if(action == "incest_event6sub.1")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 5;
        root->setImage(media(283));
        root->setText(str(237));
        makeActBtn("incest_event6sub.2",act(32));
    }
    if(action == "incest_event6sub.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(284));
        root->setText(str(238));
        makeActBtn("incest_event6sub.3",act(32));
    }
    if(action == "incest_event6sub.3")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(285));
        root->setText(str(239));
        makeActBtn("incest_event6sub.4",act(32));
    }
    if(action == "incest_event6sub.4")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(286));
        root->setText(str(240));
        makeActBtn("incest_event6sub.5",act(32));
    }
    if(action == "incest_event6sub.5")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(287,288)));
        root->setText(str(241));
        makeActBtn("incest_event6sub.6",act(32));
    }
    if(action == "incest_event6sub.6")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(289,290)));
        root->setText(str(242));
        makeActBtn("incest_event6sub.7",act(32));
    }
    if(action == "incest_event6sub.7")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(291));
        root->setText(str(243));
        makeActBtn("incest_event6sub.8",act(32));
    }
    if(action == "incest_event6sub.8")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(292));
        root->setText(str(244));
        makeActBtn("incest_event6sub.9",act(32));
    }
    if(action == "incest_event6sub.9")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(293));
        root->setText(str(245));
        makeActBtn("incest_event6sub.10",act(32));
    }
    if(action == "incest_event6sub.10")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(294));
        root->setText(str(246));
        makeActBtn("incest_event6sub.11",act(32));
    }
    if(action == "incest_event6sub.11")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(295));
        root->setText(str(247));
        makeActBtn("incest_event6sub.12",act(32));
    }
    if(action == "incest_event6sub.12")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(296,297)));
        root->setText(str(248));
        makeActBtn("incest_event6sub.13",act(32));
    }
    if(action == "incest_event6sub.13")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 75;
        root->setImage(media(getRandInt(298,299)));
        root->setText(str(249));
        makeActBtn("incest_event6sub.14",act(32));
    }
    if(action == "incest_event6sub.14")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(300));
        root->setText(str(250));
        makeActBtn("incest_event6sub.15",act(32));
    }
    if(action == "incest_event6sub.15")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(301));
        root->setText(str(251));
        makeActBtn("incest_event6sub.16",act(32));
    }
    if(action == "incest_event6sub.16")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(302));
        root->setText(str(252));
        makeActBtn("incest_event6sub.17",act(32));
    }
    if(action == "incest_event6sub.17")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(getRandInt(303,304)));
        root->setText(str(253));
        makeActBtn("incest_event6sub.18",act(32));
    }
    if(action == "incest_event6sub.18")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(getRandInt(305,306)));
        root->setText(str(254));
        makeActBtn("incest_event6sub.19",act(32));
    }
    if(action == "incest_event6sub.19")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(getRandInt(307,311)));
        root->setText(str(255));
        makeActBtn("incest_event6sub.20",act(32));
    }
    if(action == "incest_event6sub.20")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(312));
        root->setText(str(256));
        makeActBtn("bed.sleep",act(35));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 7
    /////////////////////////////////////////////////////////////

    if(action == "incest_event7.1")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(314));
        root->setText(str(258));
        makeActBtn("incest_event7.2",act(32));
    }
    if(action == "incest_event7.2")
    {
        root->clearActions();
        root->incTime(1);
        root->setImage(media(315));
        root->setText(str(259));
        makeActBtn("incest_event7.3",act(32));
    }
    if(action == "incest_event7.3")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(316));
        root->setText(str(260));
        makeActBtn("incest_event7.4",act(32));
    }
    if(action == "incest_event7.4")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(317));
        root->setText(str(261));
        makeActBtn("incest_event7.5",act(32));
    }
    if(action == "incest_event7.5")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(318));
        root->setText(str(262));
        makeActBtn("incest_event7.6",act(32));
    }
    if(action == "incest_event7.6")
    {
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vQuest(qwKolka) = 7;
        root->setImage(media(319));
        root->setText(str(263));
        makeActBtn("sitrPar",act(47));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 8
    /////////////////////////////////////////////////////////////

    if(action == "incest_event8.1")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(322));
        root->setText(str(265));
        makeActBtn("incest_event8.2",act(32));
    }
    if(action == "incest_event8.2")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(323));
        root->setText(str(266));
        makeActBtn("incest_event8.3",act(32));
    }
    if(action == "incest_event8.3")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += 25;
        root->setImage(media(324));
        root->setText(str(267));
        makeActBtn("incest_event8.4",act(32));
    }
    if(action == "incest_event8.4")
    {
        root->clearActions();
        root->incTime(5);
        root->setImage(media(325));
        root->setText(str(268));
        makeActBtn("incest_event8.5",act(32));
    }
    if(action == "incest_event8.5")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) = 95;
        root->setImage(media(326));
        root->setText(str(269));
        makeActBtn("incest_event8.6",act(32));
    }
    if(action == "incest_event8.6")
    {
        root->clearActions();
        root->incTime(5);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(327));
        root->setText(str(270));
        makeActBtn("incest_event8.7",act(32));
    }
    if(action == "incest_event8.7")
    {
        root->clearActions();
        root->incTime(5);
        root->cum("face");
        root->cum("belly");
        root->vQuest(qwKolka) = 8;
        root->setImage(media(328));
        root->setText(str(271));
        makeActBtn("bathroom",act(0));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 8 SUB
    /////////////////////////////////////////////////////////////

    if(action == "incest_event8sub.1")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(330),900,600);
        root->setText(str(273));
        makeActBtn("incest_event8sub.2",act(32));
    }
    if(action == "incest_event8sub.2")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(331),900,600);
        root->setText(str(274));
        makeActBtn("incest_event8sub.3",act(32));
    }
    if(action == "incest_event8sub.3")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(332),900,600);
        root->setText(str(275));
        makeActBtn("incest_event8sub.4",act(32));
    }
    if(action == "incest_event8sub.4")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(getRandInt(333,334)),900,600);
        root->setText(str(276));
        makeActBtn("incest_event8sub.5",act(32));
    }
    if(action == "incest_event8sub.5")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(getRandInt(335,336)),900,600);
        root->setText(str(277));
        makeActBtn("incest_event8sub.6",act(32));
    }
    if(action == "incest_event8sub.6")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) += 5;
        root->setVideo(media(getRandInt(336,337)),900,600);
        root->setText(str(278));
        makeActBtn("incest_event8sub.7",act(32));
    }
    if(action == "incest_event8sub.7")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) += 5;
        root->setVideo(media(337),900,600);
        root->setText(str(279));
        makeActBtn("incest_event8sub.8",act(32));
    }
    if(action == "incest_event8sub.8")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) += 10;
        root->setVideo(media(338),900,600);
        root->setText(str(280));
        makeActBtn("incest_event8sub.9",act(32));
    }
    if(action == "incest_event8sub.9")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) = 70;
        root->setVideo(media(getRandInt(339,340)),900,600);
        root->setText(str(281));
        makeActBtn("incest_event8sub.10",act(32));
    }
    if(action == "incest_event8sub.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) = 90;
        root->setImage(media(getRandInt(341,342)));
        root->setText(str(282));
        makeActBtn("incest_event8sub.11",act(32));
    }
    if(action == "incest_event8sub.11")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(vaginalOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->dd_vagina(root->gNPC(brother).dick,root->gNPC(father).dick,root->gNPC(brother).nickname,root->gNPC(father).nickname,1);
        root->setVideo(media(getRandInt(343,348)),900,600);
        root->setText(str(283));
        makeActBtn("incest_event8sub.12",act(32));
    }
    if(action == "incest_event8sub.12")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->setVideo(media(349),900,600);
        root->setText(str(284));
        makeActBtn("incest_event8sub.13",act(32));
    }
    if(action == "incest_event8sub.13")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) += 30;
        root->setVideo(media(350),900,600);
        root->setText(str(285));
        root->setBoyName(root->gNPC(brother).nickname);
        root->vSex(dick) = root->gNPC(brother).dick;
        root->vSex(silavag) = root->gNPC(brother).silavag;
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("incest_event8sub.14",act(32));
    }
    if(action == "incest_event8sub.14")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) = 65;
        root->setVideo(media(getRandInt(351,354)),900,600);
        root->setText(str(286));
        root->setBoyName(root->gNPC(father).nickname);
        root->vSex(dick) = root->gNPC(father).dick;
        root->vSex(silavag) = root->gNPC(father).silavag;
        root->dp_start();
        root->double_penetration();
        root->dp_cum();
        makeActBtn("incest_event8sub.15",act(32));
    }
    if(action == "incest_event8sub.15")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatus(horny) = 80;
        root->setVideo(media(355),900,600);
        root->setText(str(287));
        makeActBtn("incest_event8sub.16",act(32));
    }
    if(action == "incest_event8sub.16")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setVideo(media(getRandInt(356,359)),900,600);
        root->setText(str(288));
        root->dd_anus(root->gNPC(brother).dick, root->gNPC(father).dick, root->gNPC(brother).nickname,root->gNPC(father).nickname, 0);
        makeActBtn("incest_event8sub.17",act(32));
    }
    if(action == "incest_event8sub.17")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(3);
        root->rand_cum(0);
        root->rand_cum(0);
        root->rand_cum(0);
        root->setVideo(media(getRandInt(360,363)),900,600);
        root->setText(str(289));
        makeActBtn("incest_event8sub.18",act(32));
    }
    if(action == "incest_event8sub.18")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(3);
        root->setImage(media(364));
        root->setText(str(290));
        makeActBtn("bathroom",act(0));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 9
    /////////////////////////////////////////////////////////////

    if(action == "incest_event9.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(367));
        root->setText(str(292));
        makeActBtn("incest_event9.2",act(32));
    }
    if(action == "incest_event9.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(368));
        root->setText(str(293));
        makeActBtn("incest_event9.3",act(32));
    }
    if(action == "incest_event9.3")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(369));
        root->setText(str(294));
        makeActBtn("incest_event9.4",act(32));
    }
    if(action == "incest_event9.4")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(370));
        root->setText(str(295));
        makeActBtn("incest_event9.5",act(32));
    }
    if(action == "incest_event9.5")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(371));
        root->setText(str(296));
        makeActBtn("incest_event9.6",act(32));
    }
    if(action == "incest_event9.6")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(372));
        root->setText(str(297));
        makeActBtn("incest_event9.7",act(32));
    }
    if(action == "incest_event9.7")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(373));
        root->setText(str(298));
        makeActBtn("incest_event9.8",act(32));
    }
    if(action == "incest_event9.8")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(374));
        root->setText(str(299));
        makeActBtn("incest_event9.9",act(32));
    }
    if(action == "incest_event9.9")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(375));
        root->setText(str(300));
        makeActBtn("incest_event9.10",act(32));
    }
    if(action == "incest_event9.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(376));
        root->setText(str(301));
        makeActBtn("incest_event9.11",act(32));
    }
    if(action == "incest_event9.11")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(377));
        root->setText(str(302));
        makeActBtn("incest_event9.12",act(32));
    }
    if(action == "incest_event9.12")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(378));
        root->setText(str(303));
        makeActBtn("incest_event9.13",act(32));
    }
    if(action == "incest_event9.13")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(379));
        root->setText(str(304));
        makeActBtn("incest_event9.14",act(32));
    }
    if(action == "incest_event9.14")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(380));
        root->setText(str(305));
        makeActBtn("incest_event9.15",act(32));
    }
    if(action == "incest_event9.15")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(381));
        root->setText(str(306));
        makeActBtn("incest_event9.16",act(32));
    }
    if(action == "incest_event9.16")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(382));
        root->setText(str(307));
        makeActBtn("incest_event9.17",act(32));
    }
    if(action == "incest_event9.17")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(383));
        root->setText(str(308));
        makeActBtn("incest_event9.18",act(32));
    }
    if(action == "incest_event9.18")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(384));
        root->setText(str(309));
        makeActBtn("incest_event9.19",act(32));
    }
    if(action == "incest_event9.19")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(385));
        root->setText(str(310));
        makeActBtn("incest_event9.20",act(32));
    }
    if(action == "incest_event9.20")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(386));
        root->setText(str(311));
        makeActBtn("incest_event9.21",act(32));
    }
    if(action == "incest_event9.21")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwKolka) = 9;
        root->setImage(media(387));
        root->setText(str(312));
        makeActBtn("bed.sleep",act(35));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 10
    /////////////////////////////////////////////////////////////

    if(action == "incest_event10.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(388));
        root->setText(str(314));
        makeActBtn("incest_event10.2",act(32));
    }
    if(action == "incest_event10.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(389));
        root->setText(str(315));
        makeActBtn("incest_event10.3",act(32));
    }
    if(action == "incest_event10.3")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(390));
        root->setText(str(316));
        makeActBtn("incest_event10.4",act(32));
    }
    if(action == "incest_event10.4")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 10;
        root->setImage(media(391));
        root->setText(str(317));
        makeActBtn("incest_event10.5",act(32));
    }
    if(action == "incest_event10.5")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(392));
        root->setText(str(318));
        makeActBtn("incest_event10.6",act(32));
    }
    if(action == "incest_event10.6")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) += 20;
        root->setImage(media(393));
        root->setText(str(319));
        makeActBtn("incest_event10.7",act(32));
    }
    if(action == "incest_event10.7")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(394));
        root->setText(str(320));
        makeActBtn("incest_event10.8",act(32));
    }
    if(action == "incest_event10.8")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(395));
        root->setText(str(321));
        makeActBtn("incest_event10.9",act(32));
    }
    if(action == "incest_event10.9")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(396));
        root->setText(str(322));
        makeActBtn("incest_event10.10",act(32));
    }
    if(action == "incest_event10.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(397));
        root->setText(str(323));
        makeActBtn("incest_event10.11",act(32));
    }
    if(action == "incest_event10.11")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatus(horny) = 95;
        root->setImage(media(398));
        root->setText(str(324));
        makeActBtn("incest_event10.12",act(32));
    }
    if(action == "incest_event10.12")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(399));
        root->setText(str(325));
        makeActBtn("incest_event10.13",act(32));
    }
    if(action == "incest_event10.13")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(400));
        root->setText(str(326));
        makeActBtn("incest_event10.14",act(32));
    }
    if(action == "incest_event10.14")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(401));
        root->setText(str(327));
        makeActBtn("incest_event10.15",act(32));
    }
    if(action == "incest_event10.15")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(402));
        root->setText(str(328));
        makeActBtn("incest_event10.16",act(32));
    }
    if(action == "incest_event10.16")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(403));
        root->setText(str(329));
        makeActBtn("incest_event10.17",act(32));
    }
    if(action == "incest_event10.17")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->setImage(media(404));
        root->setText(str(330));
        makeActBtn("incest_event10.18",act(32));
    }
    if(action == "incest_event10.18")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(1);
        root->vQuest(qwKolka) = 10;
        root->cum("lip");
        root->setImage(media(405));
        root->setText(str(331));
        makeActBtn("korrPar",act(0));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 11
    /////////////////////////////////////////////////////////////

    if(action == "incest_event11.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->fnAlko(1);
        root->setImage(media(406));
        root->setText(str(333));
        makeActBtn("incest_event11_1.0",act(51));
        makeActBtn("incest_event11_2.0",act(52));
    }

    if(action == "incest_event11_1.0")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(407));
        root->setText(str(334));
        makeActBtn("incest_event11_1.1",act(32));
    }
    if(action == "incest_event11_1.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(409));
        root->setText(str(335));
        makeActBtn("incest_event11_1.2",act(32));
    }
    if(action == "incest_event11_1.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(410));
        root->setText(str(336));
        makeActBtn("incest_event11_1.3",act(32));
    }
    if(action == "incest_event11_1.3")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(411));
        root->setText(str(337));
        makeActBtn("incest_event11_1.4",act(32));
    }
    if(action == "incest_event11_1.4")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 15;
        root->setImage(media(412));
        root->setText(str(338));
        makeActBtn("incest_event11_1.5",act(32));
    }
    if(action == "incest_event11_1.5")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 20;
        root->setImage(media(413));
        root->setText(str(339));
        makeActBtn("incest_event11_1.6",act(32));
    }
    if(action == "incest_event11_1.6")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(414));
        root->setText(str(340));
        makeActBtn("incest_event11_1.7",act(32));
    }
    if(action == "incest_event11_1.7")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 20;
        root->setImage(media(415));
        root->setText(str(341));
        makeActBtn("incest_event11_1.8",act(32));
    }
    if(action == "incest_event11_1.8")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(416));
        root->setText(str(342));
        makeActBtn("incest_event11_1.9",act(32));
    }
    if(action == "incest_event11_1.9")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) = 70;
        root->setImage(media(417));
        root->setText(str(343));
        makeActBtn("incest_event11_1.10",act(32));
    }
    if(action == "incest_event11_1.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) = 85;
        root->setImage(media(418));
        root->setText(str(344));
        makeActBtn("incest_event11_1.11",act(32));
    }
    if(action == "incest_event11_1.11")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(419));
        root->setText(str(345));
        makeActBtn("incest_event11_1.12",act(32));
    }
    if(action == "incest_event11_1.12")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(420));
        root->setText(str(346));
        makeActBtn("incest_event11_1.13",act(32));
    }
    if(action == "incest_event11_1.13")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(421));
        root->setText(str(347));
        makeActBtn("incest_event11_1.14",act(32));
    }
    if(action == "incest_event11_1.14")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) = 90;
        root->setImage(media(422));
        root->setText(str(348));
        makeActBtn("incest_event11_1.15",act(32));
    }
    if(action == "incest_event11_1.15")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(423));
        root->setText(str(349));
        makeActBtn("incest_event11_1.16",act(32));
    }
    if(action == "incest_event11_1.16")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(424));
        root->setText(str(350));
        makeActBtn("incest_event11_1.17",act(32));
    }
    if(action == "incest_event11_1.17")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(425));
        root->setText(str(351));
        makeActBtn("incest_event11_1.18",act(32));
    }
    if(action == "incest_event11_1.18")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(426));
        root->setText(str(352));
        makeActBtn("incest_event11_1.19",act(32));
    }
    if(action == "incest_event11_1.19")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vQuest(wedding) = 1;
        root->setImage(media(427));
        root->setText(str(353));
        makeActBtn("korrPar",act(50));
    }

    if(action == "incest_event11_2.0")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(408));
        root->setText(str(354));
        makeActBtn("incest_event11_2.1",act(32));
    }
    if(action == "incest_event11_2.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(428));
        root->setText(str(355));
        makeActBtn("incest_event11_2.2",act(32));
    }
    if(action == "incest_event11_2.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 10;
        root->setImage(media(429));
        root->setText(str(356));
        makeActBtn("incest_event11_2.3",act(32));
    }
    if(action == "incest_event11_2.3")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(430));
        root->setText(str(357));
        makeActBtn("incest_event11_2.4",act(32));
    }
    if(action == "incest_event11_2.4")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(431));
        root->setText(str(358));
        makeActBtn("incest_event11_2.5",act(32));
    }
    if(action == "incest_event11_2.5")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 20;
        root->setImage(media(432));
        root->setText(str(359));
        makeActBtn("incest_event11_2.6",act(32));
    }
    if(action == "incest_event11_2.6")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(433));
        root->setText(str(360));
        makeActBtn("incest_event11_2.7",act(32));
    }
    if(action == "incest_event11_2.7")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 20;
        root->setImage(media(434));
        root->setText(str(361));
        makeActBtn("incest_event11_2.8",act(32));
    }
    if(action == "incest_event11_2.8")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) = 70;
        root->setImage(media(435));
        root->setText(str(362));
        makeActBtn("incest_event11_2.9",act(32));
    }
    if(action == "incest_event11_2.9")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) = 85;
        root->setImage(media(436));
        root->setText(str(363));
        makeActBtn("incest_event11_2.10",act(32));
    }
    if(action == "incest_event11_2.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(analOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setImage(media(437));
        root->setText(str(364));
        makeActBtn("incest_event11_2.11",act(32));
    }
    if(action == "incest_event11_2.11")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(438));
        root->setText(str(365));
        makeActBtn("incest_event11_2.12",act(32));
    }
    if(action == "incest_event11_2.12")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(439));
        root->setText(str(366));
        makeActBtn("incest_event11_2.13",act(32));
    }
    if(action == "incest_event11_2.13")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 20;
        root->setImage(media(440));
        root->setText(str(367));
        makeActBtn("incest_event11_2.14",act(32));
    }
    if(action == "incest_event11_2.14")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->vStatus(horny) += 5;
        root->setImage(media(441));
        root->setText(str(368));
        makeActBtn("incest_event11_2.15",act(32));
    }
    if(action == "incest_event11_2.15")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(442));
        root->setText(str(369));
        makeActBtn("incest_event11_2.16",act(32));
    }
    if(action == "incest_event11_2.16")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        if(root->getItmCount(iLubri) > 0)
            root->setGape(anus,10,29,2);
        else
            root->setGape(anus,0,29,2);
        root->vBody(anus) += 1;
        root->vQuest(anayslut) = 1;
        root->cum("face");
        root->cum("anus");
        root->setImage(media(443));
        root->setText(str(370));
        makeActBtn("korrPar",act(50));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 12
    /////////////////////////////////////////////////////////////

    if(action == "incest_event12.1")
    {
        root->rendVideoPage(this);
        root->incTime(5);
        root->setVideo(media(461),900,600);
        root->setText(str(379));
        makeActBtn("incest_event12_1",act(54));
        makeActBtn("incest_event12_2",act(55));
    }
    if(action == "incest_event12_1")
    {
        root->rendVideoPage(this);
        root->incTime(50);
        root->setVideo(media(463),900,600);
        root->setText(str(380));
        makeActBtn("korrPar",act(50));
    }
    if(action == "incest_event12_2")
    {
        root->rendImagePage(this);
        root->incTime(5);
        root->setImage(media(462));
        root->setText(str(381));
        makeActBtn("incest_event12_2.1",act(32));
    }
    if(action == "incest_event12_2.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(464));
        root->setText(str(382));
        makeActBtn("incest_event12_2.2",act(32));
    }
    if(action == "incest_event12_2.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(465));
        root->setText(str(383));
        makeActBtn("incest_event12_2.3",act(32));
    }
    if(action == "incest_event12_2.3")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(466,467)),900,600);
        root->setText(str(384));
        makeActBtn("incest_event12_2.4",act(32));
    }
    if(action == "incest_event12_2.4")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(468,471)),900,600);
        root->setText(str(385));
        makeActBtn("incest_event12_2.5",act(32));
    }
    if(action == "incest_event12_2.5")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += 15;
        root->setVideo(media(getRandInt(472,474)),900,600);
        root->setText(str(386));
        makeActBtn("incest_event12_2.6",act(32));
    }
    if(action == "incest_event12_2.6")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(475,477)),900,600);
        root->setText(str(387));
        makeActBtn("incest_event12_2.7",act(32));
    }
    if(action == "incest_event12_2.7")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += 25;
        root->setVideo(media(getRandInt(478,479)),900,600);
        root->setText(str(388));
        makeActBtn("incest_event12_2.8",act(32));
    }
    if(action == "incest_event12_2.8")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) = 95;
        root->setVideo(media(getRandInt(480,485)),900,600);
        root->setText(str(389));
        makeActBtn("incest_event12_2.9",act(32));
    }
    if(action == "incest_event12_2.9")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->vStatistics(orgasm) += 1;
        root->vStatistics(DualPenetrationOrgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->setVideo(media(getRandInt(486,488)),900,600);
        root->setText(str(390));
        makeActBtn("incest_event12_2.10",act(32));
    }
    if(action == "incest_event12_2.10")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->vStatus(horny) += 25;
        root->setVideo(media(getRandInt(489,494)),900,600);
        root->setText(str(391));
        makeActBtn("incest_event12_2.11",act(32));
    }
    if(action == "incest_event12_2.11")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(495,499)),900,600);
        root->setText(str(392));
        makeActBtn("incest_event12_2.12",act(32));
    }
    if(action == "incest_event12_2.12")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(500),900,600);
        root->setText(str(393));
        makeActBtn("incest_event12_2.13",act(32));
    }
    if(action == "incest_event12_2.13")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(501,502)),900,600);
        root->setText(str(394));
        makeActBtn("incest_event12_2.14",act(32));
    }
    if(action == "incest_event12_2.14")
    {
        root->rendVideoPage(this);
        root->clearActions();
        root->incTime(5);
        root->setVideo(media(getRandInt(505,506)),900,600);
        root->setText(str(395));
        makeActBtn("incest_event12_2.15",act(32));
    }
    if(action == "incest_event12_2.15")
    {
        root->clearActions();
        root->rendVideoPage(this);
        root->incTime(5);
        root->setVideo(media(getRandInt(507,508)),900,600);
        root->setText(str(396));
        if(root->vQuest(qwPool) == 1)
            makeActBtn("incest_event12_2_1",act(32));
        else
            makeActBtn("incest_event12_2_2",act(32));
    }
    if(action == "incest_event12_2_1")
    {
        root->clearActions();
        root->rendImagePage(this);
        root->incTime(5);
        root->setImage(media(503));
        root->setText(str(397));
        makeActBtn("korrPar",act(50));
    }
    if(action == "incest_event12_2_2")
    {
        root->clearActions();
        root->rendImagePage(this);
        root->incTime(5);
        root->setImage(media(503));
        root->setText(str(398));
        makeActBtn("incest_event12_2_2.1",act(32));
    }
    if(action == "incest_event12_2_2.1")
    {
        root->clearActions();
        root->rendImagePage(this);
        root->incTime(5);
        root->vQuest(qwPool) = 1;
        root->setImage(media(504));
        root->setText(str(399));
        makeActBtn("korrPar",act(50));
    }

    //////////////////////////////////////////////////////////////
    /// INCEST EVENT 14
    /////////////////////////////////////////////////////////////

    if(action == "incest_event14.1")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(60);
        root->setImage(media(509));
        root->setText(str(401));
        makeActBtn("incest_event14.2",act(32));
    }
    if(action == "incest_event14.2")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(120);
        root->setImage(media(510));
        root->setText(str(402));
        makeActBtn("incest_event14.3",act(32));
    }
    if(action == "incest_event14.3")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(60);
        root->setImage(media(511));
        root->setText(str(403));
        makeActBtn("incest_event14.4",act(32));
    }
    if(action == "incest_event14.4")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(512));
        root->setText(str(404));
        makeActBtn("incest_event14.5",act(32));
    }
    if(action == "incest_event14.5")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(513));
        root->setText(str(405));
        makeActBtn("incest_event14.6",act(32));
    }
    if(action == "incest_event14.6")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(514));
        root->setText(str(406));
        makeActBtn("incest_event14.7",act(32));
    }
    if(action == "incest_event14.7")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(515));
        root->setText(str(407));
        makeActBtn("incest_event14.8",act(32));
    }
    if(action == "incest_event14.8")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(516));
        root->setText(str(408));
        makeActBtn("incest_event14.9",act(32));
    }
    if(action == "incest_event14.9")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(517));
        root->setText(str(409));
        makeActBtn("incest_event14.10",act(32));
    }
    if(action == "incest_event14.10")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(518));
        root->setText(str(410));
        makeActBtn("incest_event14.11",act(32));
    }
    if(action == "incest_event14.11")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(519));
        root->setText(str(411));
        makeActBtn("incest_event14.12",act(32));
    }
    if(action == "incest_event14.12")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(520));
        root->setText(str(412));
        makeActBtn("incest_event14.13",act(32));
    }
    if(action == "incest_event14.13")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(521));
        root->setText(str(413));
        makeActBtn("incest_event14.14",act(32));
    }
    if(action == "incest_event14.14")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(522));
        root->setText(str(414));
        makeActBtn("incest_event14.15",act(32));
    }
    if(action == "incest_event14.15")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(30);
        root->setImage(media(523));
        root->setText(str(415));
        makeActBtn("incest_event14.16",act(32));
    }
    if(action == "incest_event14.16")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(524));
        root->setText(str(416));
        makeActBtn("incest_event14.17",act(32));
    }
    if(action == "incest_event14.17")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(5);
        root->setImage(media(525));
        root->setText(str(417));
        makeActBtn("incest_event14.18",act(32));
    }
    if(action == "incest_event14.18")
    {
        root->rendImagePage(this);
        root->clearActions();
        root->incTime(20);
        root->vEvent(EventParams::incest_event14) = 1;
        root->setImage(media(526));
        root->setText(str(418));
        makeActBtn("gorodok",act(0));
    }

}

void SisterQW::sisboyQW_caress()
{
    root->incTime(5);
    root->vStatus(lust) = 0;
    root->vStatus(horny) = 0;
    root->vStatistics(masturbation) += 1;
    root->vStatistics(orgasm) += 1;
    root->setImage(media(12));
    root->setText(str(1));
    makeActBtn("korrPar",act(0));
}
void SisterQW::sisboyQWsee()
{
    int i = getRandInt(0,4);
    root->setImage(media(25 + i));
    root->setText(str(2 + i));
    makeActBtn("sisboyQW_caress",act(2));
    makeActBtn("korrPar",act(0));
}
void SisterQW::sisboyQW_bedroom()
{
    if(root->vQuest(qwSisterBoy) == 3 || root->vQuest(qwSisterBoy) == 5 || root->vQuest(qwSisterBoy) == 7 || root->vQuest(qwSisterBoy) == 9)
    {
        if(root->vStatus(horny) >= 60 && root->gNPC(sister).relation >= 80 && root->vQuest(qwSisterBoy) == 3)
        {
            root->incTime(5);
            root->vStatus(horny) += 10;
            root->vStatistics(voyeurism) += 1;
            if(root->vQuest(qwSisterBoy) == 3)
                root->vQuest(qwSisterBoy) = 4;
            root->vEvent(blockBedrPar) = 1;
            root->setImage(media(8));
            root->setText(str(7));
            makeActBtn("korrPar",act(0));
        }
        else if(root->vStatus(horny) >= 60 && root->gNPC(sister).relation >= 80 && root->vQuest(qwSisterBoy) == 5)
        {
            root->rendVideoPage(this);
            root->incTime(5);
            root->vStatus(horny) += 10;
            root->vStatistics(voyeurism) += 1;
            root->vQuest(qwSisterBoy) = 6;
            root->vEvent(blockBedrPar) = 1;
            root->setVideo(media(10),960,540);
            root->setText(str(8));
            makeActBtn("korrPar",act(0));
        }
        else if(root->vStatus(horny) >= 60 && root->gNPC(sister).relation >= 80 && root->vQuest(qwSisterBoy) == 7)
        {
            root->incTime(5);
            if(root->vStatus(horny) < 85)
                root->vStatus(horny) = 85;
            root->vStatistics(voyeurism) += 1;
            root->vEvent(blockBedrPar) = 1;
            root->setImage(media(11));
            root->setText(str(9));
            makeActBtn("bedroomWatch.1",act(1));
            makeActBtn("sisboyQW_caress",act(2));
        }
        else if(root->vStatus(horny) >= 60 && root->gNPC(sister).relation >= 80 && root->vQuest(qwSisterBoy) == 9)
        {
            root->incTime(5);
            root->vStatus(horny) += 10;
            root->vEvent(blockBedrPar) = 1;
            sisboyQWsee();
        }
        else if(root->vStatus(horny) >= 60 && root->gNPC(sister).relation < 80)
        {
            root->incTime(2);
            if(root->vStatus(horny) <= 85)
                root->vStatus(horny) += 5;
            root->vEvent(blockBedrPar) = 1;
            root->setImage(media(7));
            root->setText(str(13));
            makeActBtn("korrPar",act(0));
        }
        else
        {
            root->incTime(1);
            root->vEvent(blockBedrPar) = 1;
            if(root->vQuest(qwSisterBoy) == 5 || root->vQuest(qwSisterBoy) == 3)
                root->vQuest(qwSisterBoy) -= 1;
            root->setImage(media(6));
            root->setText(str(14));
            makeActBtn("korrPar",act(0));
        }
    }
    else
    {
        root->incTime(1);
        root->vEvent(blockBedrPar) = 1;
        if(root->vQuest(qwSisterBoy) == 5 || root->vQuest(qwSisterBoy) == 3)
            root->vQuest(qwSisterBoy) -= 1;
        root->setImage(media(6));
        root->setText(str(14));
        makeActBtn("korrPar",act(0));
    }
}
void SisterQW::sisboyQW_expel()
{
    root->incTime(1);
    root->setImage(media(7));
    if(root->vQuest(qwSisterTrio) != 1)
        root->setText(str(16));
    else
        root->setText(str(17));
    makeActBtn("korrPar",act(0));
}
void SisterQW::sisboytrio_prepeare()
{
    if(root->vEvent(sisBoyTrio) == 1)
    {
        root->setImage(media(41));
        root->setText(str(20));
    }
    else if(root->vEvent(sisBoyTrio) == 2)
    {
        root->setImage(media(45));
        root->setText(str(25));
    }
    else if(root->vEvent(sisBoyTrio) == 3)
    {
        root->setImage(media(49));
        root->setText(str(31));
    }
    else if(root->vEvent(sisBoyTrio) == 4)
    {
        root->setImage(media(53));
        root->setText(str(35));
    }
    else
    {
        root->setImage(media(57));
        root->setText(str(41));
    }
    root->incTime(5);
    root->vStatus(horny) += 5;

    makeActBtn("sisboytrio_suck",act(49));
    makeActBtn("sisboytrio_sex",act(48));
}
void SisterQW::sisboytrio_suck()
{
    if(root->vEvent(sisBoyTrio) == 1)
    {
        root->setImage(media(42));
        root->setText(str(23));
    }
    else if(root->vEvent(sisBoyTrio) == 2)
    {
        root->setImage(media(46));
        root->setText(str(30));
    }
    else if(root->vEvent(sisBoyTrio) == 3)
    {
        root->setImage(media(50));
        root->setText(str(34));
    }
    else if(root->vEvent(sisBoyTrio) == 4)
    {
        root->setImage(media(55));
        root->setText(str(40));
    }
    else
    {
        root->setImage(media(58));
        root->setText(str(44));
    }
    root->incTime(5);
    root->vStatus(horny) += 5;
    root->vStatistics(blowJob) += 1;
    if((root->vEvent(sisBoyTrio) == 4 || root->vEvent(sisBoyTrio) == 5) && root->vBody(throat) < 10)
        root->vBody(throat) += 1;
    root->cum("lip");
    makeActBtn("sisboytrio_sex",act(48));
    makeActBtn("sisboytrio_end",act(3));
}
void SisterQW::sisboytrio_sex()
{
    if(root->vEvent(sisBoyTrio) == 1)
    {
        root->setImage(media(43));
        root->setText(str(22));
    }
    else if(root->vEvent(sisBoyTrio) == 2)
    {
        root->setImage(media(47));
        root->setText(str(27));
        if(root->vBody(vagina) == 0)
            root->addText(str(28));
        else
            root->addText(str(29));
    }
    else if(root->vEvent(sisBoyTrio) == 3)
    {
        root->setImage(media(51));
        root->setText(str(33));
    }
    else if(root->vEvent(sisBoyTrio) == 4)
    {
        root->setImage(media(55));
        root->setText(str(37));
        if(root->vBody(vagina) == 0)
            root->addText(str(28));
        else
            root->addText(str(39));
    }
    else
    {
        root->setImage(media(59));
        root->setText(str(43));
    }
    if(root->vEvent(sisBoyTrio) == 2 || root->vEvent(sisBoyTrio) == 4 || root->vEvent(sisBoyTrio) == 5)
    {
        root->vStatistics(vaginalSex) += 1;
        root->setGape(vagina,root->vStatus(horny),15,1);
    }
    root->incTime(getRandInt(5,15));
    root->vStatus(horny) += getRandInt(10,20);
    makeActBtn("sisboytrio_end",act(3));
}
void SisterQW::sisboytrio_end()
{
    if(root->vEvent(sisBoyTrio) == 1)
    {
        root->setImage(media(44));
        root->setText(str(21));
        root->vSex(guy) += 1;
        root->cum("face");
    }
    else if(root->vEvent(sisBoyTrio) == 2)
    {
        root->setImage(media(48));
        root->setText(str(26));
        root->cum("face");
    }
    else if(root->vEvent(sisBoyTrio) == 3)
    {
        root->setImage(media(52));
        root->setText(str(32));
        root->cum("face");
        root->cum("lip");
    }
    else if(root->vEvent(sisBoyTrio) == 4)
    {
        root->setImage(media(56));
        root->setText(str(36));
        root->cum("belly");
    }
    else
    {
        root->setImage(media(60));
        root->setText(str(42));
        root->cum("face");
        root->cum("lip");
    }
    root->incTime(5);
    root->vStatus(lust) = 0;
    root->vStatus(horny) = 0;
    root->vStatistics(orgasm) += 1;
    root->vStatistics(gangBang) += 1;
    makeActBtn("korrPar",act(0));
}
void SisterQW::sisboytrioQW_bedroom()
{
    root->vEvent(blockBedrPar) = 1;
    if(root->getMin() > 30)
    {
        root->incTime(1);
        root->changeRep('-',sister,10);
        root->vQuest(qwSisterTrio) = 0;
        root->vEvent(sisBoyDay) = 0;
        root->vEvent(sisThank) = 0;
        root->vQuest(qwSisterBoy) -= 1;
        root->setImage(media(38));
        root->setText(str(18));
        makeActBtn("korrPar",act(0));
        return;
    }
    root->vEvent(sisBoyTrio) += 1;
    if(root->vEvent(sisBoyTrio) == 1)
    {
        root->incTime(5);
        root->vStatus(horny) += 5;
        root->setImage(media(39));
        root->setText(str(19));
        makeActBtn("sisboytrio_prepeare",act(4));
        makeActBtn("sisboytrioQW_bedroom.run",act(5));
    }
    else
        root->startEvent(eSisterQW, "sisboytrio_prepeare");
}
void SisterQW::sisboyQW_party()
{
    if(root->vQuest(qwSisBoyParty) == 1)
    {
        root->vEvent(sisBoyParty) = 1;
        root->vQuest(qwSisBoyParty) = 2;
        root->incTime(15);
        root->setImage(media(93));
        root->setText(str(45));
        makeActBtn("sisboyQW_party.drinkAlko",act(10));
        makeActBtn("sisboyQW_party.discardAlko",act(11));
        makeActBtn("sisboyQW_party.standDance",act(12));
    }
}
void SisterQW::sisboy_dance()
{
    root->incTime(15);
    root->vStatus(horny) += 10;
    root->setImage(media(61));
    root->setText(str(46));
    makeActBtn("sisboy_dance.drink",act(7));
    makeActBtn("sisboy_dance.dance",act(8));
    makeActBtn("sisboy_reks",act(16));
}
void SisterQW::sisboy_drink()
{
    root->fnAlko(2);
    root->setImage(media(62));
    root->setText(str(64));
    makeActBtn("sisboy_dance",act(6));
}
void SisterQW::sisboy_sit()
{
    root->incTime(10);
    root->setImage(media(63));
    root->setText(str(65));
    makeActBtn("sisboy_dance",act(6));
}
void SisterQW::sisboy_twoboy()
{
    root->incTime(10);
    root->vStatus(horny) += 10;
    root->setImage(media(65));
    root->setText(str(58));
    makeActBtn("sisboy_twoboy.go",act(17));
}
void SisterQW::sisboy_annaFind()
{
    root->incTime(5);
    root->addText(str(47));
    makeActBtn("sisboy_Annatoilet",act(21));
    makeActBtn("sisboy_Annakuch",act(20));
    makeActBtn("sisboy_Annakom",act(22));
}
void SisterQW::sisboy_reks()
{
    root->fnAlko(0);
    root->setImage(media(70));
    root->setText(str(55));
    makeActBtn("sisboy_annaFind",act(15));
    makeActBtn("sisboy_reks.goToilet",act(27));
}
void SisterQW::sisboy_Annakuch()
{
    root->incTime(5);
    root->vStatus(horny) += 5;
    root->setImage(media(76));
    root->setText(str(48));
    makeActBtn("sisboy_Annakuch.turnBack",act(23));
}
void SisterQW::sisboy_Annatoilet()
{
    root->incTime(5);
    root->setImage(media(74));
    root->setText(str(53));
    makeActBtn("sisboy_Annakuch",act(20));
    makeActBtn("sisboy_Annakom",act(22));
}
void SisterQW::sisboy_Annakom()
{
    root->incTime(5);
    root->vStatus(horny) += 5;
    root->setImage(media(75));
    root->setText(str(54));
    makeActBtn("sisboy_Annakuch",act(20));
    makeActBtn("sisboy_Annatoilet",act(21));
}
void SisterQW::party_pre_conditions()
{
    root->incTime(5);
    if(root->gNPC(AleksLobov).relation <= 80)
    {
        root->setImage(media(95));
        if(root->repGet() < 2 && !root->isMesec() && root->vStatus(mood) >= 60 && root->vAddict(alko) < 3 && (root->vStatus(cumLips) + root->vStatus(cumFrot) + root->vStatus(cumFace) == 0))
        {
            root->setText(str(69));
            makeActBtn("sbReksHome.party",act(17));
            makeActBtn("sbReksHome.cancel",act(28));
        }
        else if(root->repGet() >= 2)
        {
            root->setText(str(71));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->isMesec() || root->vStatus(mood) < 60)
        {
            root->setText(str(72));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->vAddict(alko) >= 3)
        {
            root->setText(str(73));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->vStatus(cumFrot) + root->vStatus(cumLips) + root->vStatus(cumFace) > 0)
        {
            root->setText(str(74));
            makeActBtn("back_to_loc",act(29));
        }
    }
    else
    {
        root->setImage(media(96));
        if(root->repGet() < 2 && !root->isMesec() && root->vStatus(mood) >= 60 && root->vAddict(alko) < 3 && (root->vStatus(cumFrot) + root->vStatus(cumLips) + root->vStatus(cumFace) == 0))
        {
            root->setText(str(75));
            makeActBtn("sbReksHome.party",act(17));
            makeActBtn("sbReksHome.cancel2",act(28));
        }
        else if(root->repGet() >= 2)
        {
            root->setText(str(77));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->isMesec() || root->vStatus(mood) < 60)
        {
            root->setText(str(78));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->vAddict(alko) >= 3)
        {
            root->setText(str(79));
            makeActBtn("back_to_loc",act(29));
        }
        else if(root->vStatus(cumLips) + root->vStatus(cumFrot) + root->vStatus(cumFace) > 0)
        {
            root->setText(str(80));
            makeActBtn("back_to_loc",act(29));
        }
    }
}

void SisterQW::meet_sister()
{
    if(root->getWeek() == 5 && root->getHour() == 16 && root->vEvent(sisBoyParty) == 2)
    {
        if(root->vQuest(qwSisBoyParty) < 2)
        {
            makeActBtn("sisboyQW_party",act(30));
        }
        else
        {
            root->addText(str(81));
            makeActBtn("party_pre_conditions",act(30));
        }
    }
    if(root->gNPC(sister).location == lgdk || root->gNPC(sister).location == lglake || root->gNPC(sister).location == lcafeparco)
    {
        if(root->gNPC(sister).relation < 40)
            root->addText(str(82));
        else
        {
            root->addText(str(83));
            makeActBtn("meet_sister.drinkBeer",act(31));
        }
        makeActBtn("back_to_loc",act(29));
    }
}

void SisterQW::incest_event1()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(100));
    root->setText(str(85));
    makeActBtn("incest_event1.1",act(32));
}
void SisterQW::incest_event2()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(127));
    root->setText(str(113));
    makeActBtn("incest_event2.1",act(32));
}
void SisterQW::incest_event3()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(143));
    root->setText(str(129));
    makeActBtn("incest_event3.1",act(32));
}
void SisterQW::incest_event3sub()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(166));
    root->setText(str(153));
    makeActBtn("incest_event3sub.1",act(32));
}
void SisterQW::incest_event4()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(207));
    root->setText(str(174));
    makeActBtn("incest_event4.1",act(32));
}
void SisterQW::incest_event5()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(217));
    root->setText(str(184));
    makeActBtn("incest_event5.1",act(32));
}
void SisterQW::incest_event5sub()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(233));
    root->setText(str(201));
    makeActBtn("incest_event5sub.1",act(32));
}
void SisterQW::incest_event6()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(275));
    root->setText(str(228));
    makeActBtn("incest_event6.16",act(32));
}
void SisterQW::incest_event6shop()
{
    root->clearActions();
    root->incTime(30);
    root->rendNpcProfile(sister);
    root->setText(str(234));
    makeActBtn("incest_event6shop.1",act(45));
}
void SisterQW::incest_event6sub()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(getRandInt(281,282)));
    root->setText(str(236));
    makeActBtn("incest_event6sub.1",act(32));
}
void SisterQW::incest_event7()
{
    root->clearActions();
    root->incTime(1);
    root->setImage(media(313));
    root->setText(str(257));
    makeActBtn("incest_event7.1",act(32));
}
void SisterQW::incest_event8()
{
    root->clearActions();
    root->incTime(5);
    root->useItem(iLubri,1);
    root->setImage(media(321));
    root->setText(str(264));
    makeActBtn("incest_event8.1",act(32));
}
void SisterQW::incest_event8sub()
{
    root->rendVideoPage(this);
    root->clearActions();
    root->incTime(3);
    root->setVideo(media(329),900,600);
    root->setText(str(272));
    makeActBtn("incest_event8sub.1",act(32));
}
void SisterQW::incest_event9()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(15);
    root->setImage(media(366));
    root->setText(str(291));
    makeActBtn("incest_event9.1",act(32));
}
void SisterQW::incest_event10()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(1);
    root->setImage(media(387));
    root->setText(str(313));
    makeActBtn("incest_event10.1",act(32));
}
void SisterQW::incest_event10sub()
{
    root->clearActions();
    root->incTime(1);
    root->vQuest(qwMisha) = 1;
    root->setText(str(0));
    makeActBtn("bedrPar",act(29));
}
void SisterQW::incest_event11()
{
    root->clearActions();
    root->incTime(30);
    root->setText(str(332));
    makeActBtn("incest_event11.1",act(32));
}

void SisterQW::incest_mini1()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(10);
    root->vStatus(horny) += 10;
    root->setImage(media(getRandInt(444,450)));
    root->setText(str(371));
    makeActBtn("korrPar",act(0));
}

void SisterQW::incest_mini2()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(10);
    root->vStatus(horny) += 15;
    root->setImage(media(getRandInt(451,456)));
    root->setText(str(372));
    makeActBtn("korrPar",act(0));
}

void SisterQW::incest_dialog1()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(10);
    root->vQuest(wedding) = 2;
    root->vEvent(sisInitRelocDay) = root->vStatus(daystart) + 90;
    root->setText(str(373));
    makeActBtn("back_to_loc",act(29));
}

void SisterQW::incest_dialog2()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(10);
    root->vQuest(wedding) = 2;
    root->setText(str(374));
    makeActBtn("back_to_loc",act(29));
}

void SisterQW::incest_dialog3()
{
    root->rendImagePage(this);
    root->clearActions();
    root->incTime(10);
    root->vQuest(wedding) = 3;
    root->setText(str(375));
    makeActBtn("back_to_loc",act(29));
}

void SisterQW::incest_event12sub()
{
    if(root->vQuest(wedding) == 2)
    {
        root->clearActions();
        root->incTime(5);
        root->setText(str(376));
        makeActBtn("incest_event12",act(53));
    }
    else if(root->vQuest(wedding) > 2)
    {
        root->clearActions();
        root->incTime(5);
        root->setText(str(377));
        makeActBtn("incest_event12",act(53));
    }
}

void SisterQW::incest_event12()
{
    root->clearActions();
    root->incTime(5);
    root->setText(str(378));
    makeActBtn("incest_event12.1",act(32));
}

void SisterQW::incest_event14()
{
    root->clearActions();
    root->incTime(60);
    root->setText(str(400));
    makeActBtn("incest_event14.1",act(32));
}

QString SisterQW::media(int id)
{
    QString med[61];
    if(id < 60)
    {
        med[0] = "data/sex/sisBoyQW/sisboyQW_00.jpg";
        med[1] = "data/sex/sisBoyQW/sisboyQW_01.jpg";
        med[2] = "data/sex/sisBoyQW/sisboyQW_02.jpg";
        med[3] = "data/sex/sisBoyQW/sisboyQW_03.jpg";
        med[4] = "data/sex/sisBoyQW/sisboyQW_04.jpg";
        med[5] = "data/sex/sisBoyQW/sisboyQW_05.jpg";
        med[6] = "data/sex/sisBoyQW/sisboyQW_06.jpg";
        med[7] = "data/sex/sisBoyQW/sisboyQW_07.jpg";
        med[8] = "data/sex/sisBoyQW/sisboyQW_08.jpg";
        med[9] = "data/sex/sisBoyQW/sisboyQW_09.jpg";
        med[10] = "data/sex/sisBoyQW/sisboyQW_10.webm";
        med[11] = "data/sex/sisBoyQW/sisboyQW_11.jpg";
        med[12] = "data/sex/sisBoyQW/sisboyQW_12.jpg";
        med[13] = "data/sex/sisBoyQW/sisboyQW_13.jpg";
        med[14] = "data/sex/sisBoyQW/sisboyQW_14.jpg";
        med[15] = "data/sex/sisBoyQW/sisboyQW_15.jpg";
        med[16] = "data/sex/sisBoyQW/sisboyQW_16.jpg";
        med[17] = "data/sex/sisBoyQW/sisboyQW_17.jpg";
        med[18] = "data/sex/sisBoyQW/sisboyQW_18.jpg";
        med[19] = "data/sex/sisBoyQW/sisboyQW_19.jpg";
        med[20] = "data/sex/sisBoyQW/sisboyQW_20.jpg";
        med[21] = "data/sex/sisBoyQW/sisboyQW_21.jpg";
        med[22] = "data/sex/sisBoyQW/sisboyQW_22.jpg";
        med[23] = "data/sex/sisBoyQW/sisboyQW_23.jpg";
        med[24] = "data/sex/sisBoyQW/sisboyQW_24.jpg";
        med[25] = "data/sex/sisBoyQW/sisboyQW_25.jpg";
        med[26] = "data/sex/sisBoyQW/sisboyQW_26.jpg";
        med[27] = "data/sex/sisBoyQW/sisboyQW_27.jpg";
        med[28] = "data/sex/sisBoyQW/sisboyQW_28.jpg";
        med[29] = "data/sex/sisBoyQW/sisboyQW_29.jpg";
        med[30] = "data/sex/sisBoyQW/sisboyQW_30.jpg";
        med[31] = "data/sex/sisBoyQW/sisboyQW_31.jpg";
        med[32] = "data/sex/sisBoyQW/sisboyQW_32.jpg";
        med[33] = "data/sex/sisBoyQW/sisboyQW_33.jpg";
        med[34] = "data/sex/sisBoyQW/sisboyQW_34.jpg";
        med[35] = "data/sex/sisBoyQW/sisboyQW_35.jpg";
        med[36] = "data/sex/sisBoyQW/sisboyQW_36.jpg";
        med[37] = "data/sex/sisBoyQW/sisboyQW_37.jpg";
        med[38] = "data/sex/sisBoyQW/sisboyQW_38.jpg";
        med[39] = "data/sex/sisBoyQW/sisboyQW_39.jpg";
        med[40] = "data/sex/sisBoyQW/sisboyQW_40.jpg";
        med[41] = "data/sex/sisBoyQW/sisboyQW_41.jpg";
        med[42] = "data/sex/sisBoyQW/sisboyQW_42.jpg";
        med[43] = "data/sex/sisBoyQW/sisboyQW_43.jpg";
        med[44] = "data/sex/sisBoyQW/sisboyQW_44.jpg";
        med[45] = "data/sex/sisBoyQW/sisboyQW_45.jpg";
        med[46] = "data/sex/sisBoyQW/sisboyQW_46.jpg";
        med[47] = "data/sex/sisBoyQW/sisboyQW_47.jpg";
        med[48] = "data/sex/sisBoyQW/sisboyQW_48.jpg";
        med[49] = "data/sex/sisBoyQW/sisboyQW_49.jpg";
        med[50] = "data/sex/sisBoyQW/sisboyQW_50.jpg";
        med[51] = "data/sex/sisBoyQW/sisboyQW_51.jpg";
        med[52] = "data/sex/sisBoyQW/sisboyQW_52.jpg";
        med[53] = "data/sex/sisBoyQW/sisboyQW_53.jpg";
        med[54] = "data/sex/sisBoyQW/sisboyQW_54.jpg";
        med[55] = "data/sex/sisBoyQW/sisboyQW_55.jpg";
        med[56] = "data/sex/sisBoyQW/sisboyQW_56.jpg";
        med[57] = "data/sex/sisBoyQW/sisboyQW_57.jpg";
        med[58] = "data/sex/sisBoyQW/sisboyQW_58.jpg";
        med[59] = "data/sex/sisBoyQW/sisboyQW_59.jpg";
        med[60] = "data/sex/sisBoyQW/sisboyQW_60.jpg";
        return med[id];
    }
    else if(id >= 61 && id <= 96)
    {
        med[0] = "data/sex/sisPartyQW/sisboyQWParty_10.jpg";
        med[1] = "data/sex/sisPartyQW/sisboyQWParty_11.jpg";
        med[2] = "data/sex/sisPartyQW/sisboyQWParty_12.jpg";
        med[3] = "data/sex/sisPartyQW/sisboyQWParty_13.jpg";
        med[4] = "data/sex/sisPartyQW/sisboyQWParty_14.gif";
        med[5] = "data/sex/sisPartyQW/sisboyQWParty_15.jpg";
        med[6] = "data/sex/sisPartyQW/sisboyQWParty_16.jpg";
        med[7] = "data/sex/sisPartyQW/sisboyQWParty_17.jpg";
        med[8] = "data/sex/sisPartyQW/sisboyQWParty_18.gif";
        med[9] = "data/sex/sisPartyQW/sisboyQWParty_19.jpg";
        med[10] = "data/sex/sisPartyQW/sisboyQWParty_1.jpg";
        med[11] = "data/sex/sisPartyQW/sisboyQWParty_20.jpg";
        med[12] = "data/sex/sisPartyQW/sisboyQWParty_21.gif";
        med[13] = "data/sex/sisPartyQW/sisboyQWParty_22.jpg";
        med[14] = "data/sex/sisPartyQW/sisboyQWParty_23.jpg";
        med[15] = "data/sex/sisPartyQW/sisboyQWParty_24.jpg";
        med[16] = "data/sex/sisPartyQW/sisboyQWParty_25.jpg";
        med[17] = "data/sex/sisPartyQW/sisboyQWParty_26.jpg";
        med[18] = "data/sex/sisPartyQW/sisboyQWParty_27.jpg";
        med[19] = "data/sex/sisPartyQW/sisboyQWParty_28.jpg";
        med[20] = "data/sex/sisPartyQW/sisboyQWParty_2.jpg";
        med[21] = "data/sex/sisPartyQW/sisboyQWParty_3.jpg";
        med[22] = "data/sex/sisPartyQW/sisboyQWParty_4.jpg";
        med[23] = "data/sex/sisPartyQW/sisboyQWParty_5.jpg";
        med[24] = "data/sex/sisPartyQW/sisboyQWParty_6_1.jpg";
        med[25] = "data/sex/sisPartyQW/sisboyQWParty_6_2.jpg";
        med[26] = "data/sex/sisPartyQW/sisboyQWParty_6_3.jpg";
        med[27] = "data/sex/sisPartyQW/sisboyQWParty_6_4.jpg";
        med[28] = "data/sex/sisPartyQW/sisboyQWParty_6_5.jpg";
        med[29] = "data/sex/sisPartyQW/sisboyQWParty_6_6.jpg";
        med[30] = "data/sex/sisPartyQW/sisboyQWParty_6_7.jpg";
        med[31] = "data/sex/sisPartyQW/sisboyQWParty_7.jpg";
        med[32] = "data/sex/sisPartyQW/sisboyQWParty_8.jpg";
        med[33] = "data/sex/sisPartyQW/sisboyQWParty_9.jpg";

        med[34] = "data/sex/ReksHome/Party_sister_1.jpg";
        med[35] = "data/sex/ReksHome/Reks.jpg";
        return med[id - 61];
    }
    else if(id >= 97 && id <= 99)
    {
        med[0] = "data/npc/pavlovo/sister/friends/cafe_parco_4.jpg";
        med[1] = "data/npc/pavlovo/sister/friends/gdk_4.jpg";
        med[2] = "data/npc/pavlovo/sister/friends/glake_4.jpg";
        return med[id - 97];
    }
    else if(id >= 100 && id <= 126)
    {
        med[0] = "data/sex/incest/event1/01.jpg";
        med[1] = "data/sex/incest/event1/02.jpg";
        med[2] = "data/sex/incest/event1/03.jpg";
        med[3] = "data/sex/incest/event1/04.jpg";
        med[4] = "data/sex/incest/event1/05.jpg";
        med[5] = "data/sex/incest/event1/06.jpg";
        med[6] = "data/sex/incest/event1/07.jpg";
        med[7] = "data/sex/incest/event1/08.jpg";
        med[8] = "data/sex/incest/event1/09.jpg";
        med[9] = "data/sex/incest/event1/10.jpg";
        med[10] = "data/sex/incest/event1/11.jpg";
        med[11] = "data/sex/incest/event1/12.jpg";
        med[12] = "data/sex/incest/event1/13.jpg";
        med[13] = "data/sex/incest/event1/14.jpg";
        med[14] = "data/sex/incest/event1/15.jpg";
        med[15] = "data/sex/incest/event1/16.jpg";
        med[16] = "data/sex/incest/event1/17.jpg";
        med[17] = "data/sex/incest/event1/18.jpg";
        med[18] = "data/sex/incest/event1/19.jpg";
        med[19] = "data/sex/incest/event1/20.jpg";
        med[20] = "data/sex/incest/event1/21.jpg";
        med[21] = "data/sex/incest/event1/22.jpg";
        med[22] = "data/sex/incest/event1/23.jpg";
        med[23] = "data/sex/incest/event1/24.jpg";
        med[24] = "data/sex/incest/event1/25.jpg";
        med[25] = "data/sex/incest/event1/26.jpg";
        med[26] = "data/sex/incest/event1/27.jpg";
        return med[id - 100];
    }
    else if(id >= 127 && id <= 142)
    {
        med[0] = "data/sex/incest/event2/01.jpg";
        med[1] = "data/sex/incest/event2/02.jpg";
        med[2] = "data/sex/incest/event2/03.jpg";
        med[3] = "data/sex/incest/event2/04.jpg";
        med[4] = "data/sex/incest/event2/05.jpg";
        med[5] = "data/sex/incest/event2/06.jpg";
        med[6] = "data/sex/incest/event2/07.jpg";
        med[7] = "data/sex/incest/event2/08.jpg";
        med[8] = "data/sex/incest/event2/09.jpg";
        med[9] = "data/sex/incest/event2/10.jpg";
        med[10] = "data/sex/incest/event2/11.jpg";
        med[11] = "data/sex/incest/event2/12.jpg";
        med[12] = "data/sex/incest/event2/13.jpg";
        med[13] = "data/sex/incest/event2/14.jpg";
        med[14] = "data/sex/incest/event2/15.jpg";
        med[15] = "data/sex/incest/event2/16.jpg";
        return med[id - 127];
    }
    else if(id >= 143 && id <= 165)
    {
        med[0] = "data/sex/incest/event3/01.jpg";
        med[1] = "data/sex/incest/event3/02.jpg";
        med[2] = "data/sex/incest/event3/03.jpg";
        med[3] = "data/sex/incest/event3/04.jpg";
        med[4] = "data/sex/incest/event3/05.jpg";
        med[5] = "data/sex/incest/event3/06.jpg";
        med[6] = "data/sex/incest/event3/07.jpg";
        med[7] = "data/sex/incest/event3/08.jpg";
        med[8] = "data/sex/incest/event3/09.jpg";
        med[9] = "data/sex/incest/event3/10.jpg";
        med[10] = "data/sex/incest/event3/11.jpg";
        med[11] = "data/sex/incest/event3/12.jpg";
        med[12] = "data/sex/incest/event3/13.jpg";
        med[13] = "data/sex/incest/event3/14.jpg";
        med[14] = "data/sex/incest/event3/15.jpg";
        med[15] = "data/sex/incest/event3/16.jpg";
        med[16] = "data/sex/incest/event3/17.jpg";
        med[17] = "data/sex/incest/event3/18.jpg";
        med[18] = "data/sex/incest/event3/19.jpg";
        med[19] = "data/sex/incest/event3/20.jpg";
        med[20] = "data/sex/incest/event3/21.jpg";
        med[21] = "data/sex/incest/event3/22.jpg";
        med[22] = "data/sex/incest/event3/23.jpg";
        return med[id - 143];
    }
    else if(id >= 166 && id <= 206)
    {
        med[0] = "data/sex/incest/event3sub/01.jpg";
        med[1] = "data/sex/incest/event3sub/02.jpg";
        med[2] = "data/sex/incest/event3sub/03.jpg";
        med[3] = "data/sex/incest/event3sub/04.jpg";
        med[4] = "data/sex/incest/event3sub/05.jpg";
        med[5] = "data/sex/incest/event3sub/06.jpg";
        med[6] = "data/sex/incest/event3sub/07.jpg";
        med[7] = "data/sex/incest/event3sub/08.jpg";
        med[8] = "data/sex/incest/event3sub/09.jpg";
        med[9] = "data/sex/incest/event3sub/10.jpg";
        med[10] = "data/sex/incest/event3sub/11.jpg";
        med[11] = "data/sex/incest/event3sub/12.jpg";
        med[12] = "data/sex/incest/event3sub/13.jpg";
        med[13] = "data/sex/incest/event3sub/14.jpg";
        med[14] = "data/sex/incest/event3sub/15.jpg";
        med[15] = "data/sex/incest/event3sub/16.jpg";
        med[16] = "data/sex/incest/event3sub/17.jpg";
        med[17] = "data/sex/incest/event3sub/18.jpg";
        med[18] = "data/sex/incest/event3sub/19.jpg";
        med[19] = "data/sex/incest/event3sub/20.jpg";
        med[20] = "data/sex/incest/event3sub/21.jpg";
        med[21] = "data/sex/incest/event3sub/22.jpg";
        med[22] = "data/sex/incest/event3sub/23.jpg";
        med[23] = "data/sex/incest/event3sub/24.jpg";
        med[24] = "data/sex/incest/event3sub/25.jpg";
        med[25] = "data/sex/incest/event3sub/26.jpg";
        med[26] = "data/sex/incest/event3sub/27.jpg";
        med[27] = "data/sex/incest/event3sub/28.jpg";
        med[28] = "data/sex/incest/event3sub/29.jpg";
        med[29] = "data/sex/incest/event3sub/30.jpg";
        med[30] = "data/sex/incest/event3sub/31.jpg";
        med[31] = "data/sex/incest/event3sub/32.jpg";
        med[32] = "data/sex/incest/event3sub/33.jpg";
        med[33] = "data/sex/incest/event3sub/34.jpg";
        med[34] = "data/sex/incest/event3sub/35.jpg";
        med[35] = "data/sex/incest/event3sub/36.jpg";
        med[36] = "data/sex/incest/event3sub/37.jpg";
        med[37] = "data/sex/incest/event3sub/38.jpg";
        med[38] = "data/sex/incest/event3sub/39.jpg";
        med[39] = "data/sex/incest/event3sub/40.jpg";
        med[40] = "data/sex/incest/event3sub/41.jpg";
        return med[id - 166];
    }
    else if(id >= 207 && id <= 216)
    {
        med[0] = "data/sex/incest/event4/01.jpg";
        med[1] = "data/sex/incest/event4/02.jpg";
        med[2] = "data/sex/incest/event4/03.jpg";
        med[3] = "data/sex/incest/event4/04.jpg";
        med[4] = "data/sex/incest/event4/05.jpg";
        med[5] = "data/sex/incest/event4/06.jpg";
        med[6] = "data/sex/incest/event4/07.jpg";
        med[7] = "data/sex/incest/event4/08.jpg";
        med[8] = "data/sex/incest/event4/09.jpg";
        med[9] = "data/sex/incest/event4/10.jpg";
        return med[id - 207];
    }
    else if(id >= 217 && id <= 232)
    {
        med[0] = "data/sex/incest/event5/01.jpg";
        med[1] = "data/sex/incest/event5/02.jpg";
        med[2] = "data/sex/incest/event5/03.jpg";
        med[3] = "data/sex/incest/event5/04.jpg";
        med[4] = "data/sex/incest/event5/05.jpg";
        med[5] = "data/sex/incest/event5/06.jpg";
        med[6] = "data/sex/incest/event5/07.jpg";
        med[7] = "data/sex/incest/event5/08.jpg";
        med[8] = "data/sex/incest/event5/09.jpg";
        med[9] = "data/sex/incest/event5/10.jpg";
        med[10] = "data/sex/incest/event5/11.jpg";
        med[11] = "data/sex/incest/event5/12.jpg";
        med[12] = "data/sex/incest/event5/13.jpg";
        med[13] = "data/sex/incest/event5/14.jpg";
        med[14] = "data/sex/incest/event5/15.jpg";
        med[15] = "data/sex/incest/event5/16.jpg";
        return med[id - 217];
    }
    else if(id >= 233 && id <= 258)
    {
        med[0] = "data/sex/incest/event5sub/01.jpg";
        med[1] = "data/sex/incest/event5sub/02.jpg";
        med[2] = "data/sex/incest/event5sub/03.jpg";
        med[3] = "data/sex/incest/event5sub/04.jpg";
        med[4] = "data/sex/incest/event5sub/05.jpg";
        med[5] = "data/sex/incest/event5sub/06.jpg";
        med[6] = "data/sex/incest/event5sub/07.jpg";
        med[7] = "data/sex/incest/event5sub/08.jpg";
        med[8] = "data/sex/incest/event5sub/09.jpg";
        med[9] = "data/sex/incest/event5sub/10.jpg";
        med[10] = "data/sex/incest/event5sub/11.jpg";
        med[11] = "data/sex/incest/event5sub/12.jpg";
        med[12] = "data/sex/incest/event5sub/13.jpg";
        med[13] = "data/sex/incest/event5sub/14.jpg";
        med[14] = "data/sex/incest/event5sub/15.jpg";
        med[15] = "data/sex/incest/event5sub/16.jpg";
        med[16] = "data/sex/incest/event5sub/17.jpg";
        med[17] = "data/sex/incest/event5sub/18.jpg";
        med[18] = "data/sex/incest/event5sub/19.jpg";
        med[19] = "data/sex/incest/event5sub/20.jpg";
        med[20] = "data/sex/incest/event5sub/21.jpg";
        med[21] = "data/sex/incest/event5sub/22.jpg";
        med[22] = "data/sex/incest/event5sub/23.jpg";
        med[23] = "data/sex/incest/event5sub/24.jpg";
        med[24] = "data/sex/incest/event5sub/25.jpg";
        med[25] = "data/sex/incest/event5sub/26.jpg";
        return med[id - 233];
    }
    else if(id >= 259 && id <= 280)
    {
        med[0] = "data/sex/incest/event6/01.jpg";
        med[1] = "data/sex/incest/event6/02.jpg";
        med[2] = "data/sex/incest/event6/03.jpg";
        med[3] = "data/sex/incest/event6/04.jpg";
        med[4] = "data/sex/incest/event6/05.jpg";
        med[5] = "data/sex/incest/event6/06.jpg";
        med[6] = "data/sex/incest/event6/07.jpg";
        med[7] = "data/sex/incest/event6/08.jpg";
        med[8] = "data/sex/incest/event6/09.jpg";
        med[9] = "data/sex/incest/event6/10.jpg";
        med[10] = "data/sex/incest/event6/11.jpg";
        med[11] = "data/sex/incest/event6/12.jpg";
        med[12] = "data/sex/incest/event6/13.jpg";
        med[13] = "data/sex/incest/event6/14.jpg";
        med[14] = "data/sex/incest/event6/15.jpg";
        med[15] = "data/sex/incest/event6/16.jpg";
        med[16] = "data/sex/incest/event6/17.jpg";
        med[17] = "data/sex/incest/event6/18.jpg";
        med[18] = "data/sex/incest/event6/19.jpg";
        med[19] = "data/sex/incest/event6/20.jpg";
        med[20] = "data/sex/incest/event6/21.jpg";
        med[21] = "data/sex/incest/event6/22.jpg";
        return med[id - 259];
    }
    else if(id >= 281 && id <= 312)
    {
        med[0] = "data/sex/incest/event6sub/01.jpg";
        med[1] = "data/sex/incest/event6sub/02.jpg";
        med[2] = "data/sex/incest/event6sub/03.jpg";
        med[3] = "data/sex/incest/event6sub/04.jpg";
        med[4] = "data/sex/incest/event6sub/05.jpg";
        med[5] = "data/sex/incest/event6sub/06.jpg";
        med[6] = "data/sex/incest/event6sub/07.jpg";
        med[7] = "data/sex/incest/event6sub/08.jpg";
        med[8] = "data/sex/incest/event6sub/09.jpg";
        med[9] = "data/sex/incest/event6sub/10.jpg";
        med[10] = "data/sex/incest/event6sub/11.jpg";
        med[11] = "data/sex/incest/event6sub/12.jpg";
        med[12] = "data/sex/incest/event6sub/13.jpg";
        med[13] = "data/sex/incest/event6sub/14.jpg";
        med[14] = "data/sex/incest/event6sub/15.jpg";
        med[15] = "data/sex/incest/event6sub/16.jpg";
        med[16] = "data/sex/incest/event6sub/17.jpg";
        med[17] = "data/sex/incest/event6sub/18.jpg";
        med[18] = "data/sex/incest/event6sub/19.jpg";
        med[19] = "data/sex/incest/event6sub/20.jpg";
        med[20] = "data/sex/incest/event6sub/21.jpg";
        med[21] = "data/sex/incest/event6sub/22.jpg";
        med[22] = "data/sex/incest/event6sub/23.jpg";
        med[23] = "data/sex/incest/event6sub/24.jpg";
        med[24] = "data/sex/incest/event6sub/25.jpg";
        med[25] = "data/sex/incest/event6sub/26.jpg";
        med[26] = "data/sex/incest/event6sub/27.jpg";
        med[27] = "data/sex/incest/event6sub/28.jpg";
        med[28] = "data/sex/incest/event6sub/29.jpg";
        med[29] = "data/sex/incest/event6sub/30.jpg";
        med[30] = "data/sex/incest/event6sub/31.jpg";
        med[31] = "data/sex/incest/event6sub/32.jpg";
        return med[id -281];
    }
    else if(id >= 313 && id <= 320)
    {
        med[0] = "data/sex/incest/event7/01.jpg";
        med[1] = "data/sex/incest/event7/02.jpg";
        med[2] = "data/sex/incest/event7/03.jpg";
        med[3] = "data/sex/incest/event7/04.jpg";
        med[4] = "data/sex/incest/event7/05.jpg";
        med[5] = "data/sex/incest/event7/06.jpg";
        med[6] = "data/sex/incest/event7/07.jpg";
        med[7] = "data/sex/incest/event7/08.jpg";
        return med[id - 313];
    }
    else if(id >= 321 && id <= 328)
    {
        med[0] = "data/sex/incest/event8/01.jpg";
        med[1] = "data/sex/incest/event8/02.jpg";
        med[2] = "data/sex/incest/event8/03.jpg";
        med[3] = "data/sex/incest/event8/04.jpg";
        med[4] = "data/sex/incest/event8/05.jpg";
        med[5] = "data/sex/incest/event8/06.jpg";
        med[6] = "data/sex/incest/event8/07.jpg";
        med[7] = "data/sex/incest/event8/08.jpg";
        return med[id - 321];
    }
    else if(id >= 329 && id <= 364)
    {
        med[0] = "data/sex/incest/event8sub/01.webm";
        med[1] = "data/sex/incest/event8sub/02.webm";
        med[2] = "data/sex/incest/event8sub/03.webm";
        med[3] = "data/sex/incest/event8sub/04.webm";
        med[4] = "data/sex/incest/event8sub/05.webm";
        med[5] = "data/sex/incest/event8sub/06.webm";
        med[6] = "data/sex/incest/event8sub/07.webm";
        med[7] = "data/sex/incest/event8sub/08.webm";
        med[8] = "data/sex/incest/event8sub/09.webm";
        med[9] = "data/sex/incest/event8sub/10.webm";
        med[10] = "data/sex/incest/event8sub/11.webm";
        med[11] = "data/sex/incest/event8sub/12.webm";
        med[12] = "data/sex/incest/event8sub/13.jpg";
        med[13] = "data/sex/incest/event8sub/14.jpg";
        med[14] = "data/sex/incest/event8sub/15.webm";
        med[15] = "data/sex/incest/event8sub/16.webm";
        med[16] = "data/sex/incest/event8sub/17.webm";
        med[17] = "data/sex/incest/event8sub/18.webm";
        med[18] = "data/sex/incest/event8sub/19.webm";
        med[19] = "data/sex/incest/event8sub/20.webm";
        med[20] = "data/sex/incest/event8sub/21.webm";
        med[21] = "data/sex/incest/event8sub/22.webm";
        med[22] = "data/sex/incest/event8sub/23.webm";
        med[23] = "data/sex/incest/event8sub/24.webm";
        med[24] = "data/sex/incest/event8sub/25.webm";
        med[25] = "data/sex/incest/event8sub/26.webm";
        med[26] = "data/sex/incest/event8sub/27.webm";
        med[27] = "data/sex/incest/event8sub/28.webm";
        med[28] = "data/sex/incest/event8sub/29.webm";
        med[29] = "data/sex/incest/event8sub/30.webm";
        med[30] = "data/sex/incest/event8sub/31.webm";
        med[31] = "data/sex/incest/event8sub/32.webm";
        med[32] = "data/sex/incest/event8sub/33.webm";
        med[33] = "data/sex/incest/event8sub/34.webm";
        med[34] = "data/sex/incest/event8sub/35.webm";
        med[35] = "data/sex/incest/event8sub/36.jpg";
        return med[id - 329];
    }
    else if(id >= 365 && id <= 387)
    {
        med[0] = "data/sex/incest/event9/01.jpg";
        med[1] = "data/sex/incest/event9/02.jpg";
        med[2] = "data/sex/incest/event9/03.jpg";
        med[3] = "data/sex/incest/event9/04.jpg";
        med[4] = "data/sex/incest/event9/05.jpg";
        med[5] = "data/sex/incest/event9/06.jpg";
        med[6] = "data/sex/incest/event9/07.jpg";
        med[7] = "data/sex/incest/event9/08.jpg";
        med[8] = "data/sex/incest/event9/09.jpg";
        med[9] = "data/sex/incest/event9/10.jpg";
        med[10] = "data/sex/incest/event9/11.jpg";
        med[11] = "data/sex/incest/event9/12.jpg";
        med[12] = "data/sex/incest/event9/13.jpg";
        med[13] = "data/sex/incest/event9/14.jpg";
        med[14] = "data/sex/incest/event9/15.jpg";
        med[15] = "data/sex/incest/event9/16.jpg";
        med[16] = "data/sex/incest/event9/17.jpg";
        med[17] = "data/sex/incest/event9/18.jpg";
        med[18] = "data/sex/incest/event9/19.jpg";
        med[19] = "data/sex/incest/event9/20.jpg";
        med[20] = "data/sex/incest/event9/21.jpg";
        med[21] = "data/sex/incest/event9/22.jpg";
        med[22] = "data/sex/incest/event9/23.jpg";
        return med[id - 365];
    }
    else if(id >= 387 && id <= 405)
    {
        med[0] = "data/sex/incest/event10/01.jpg";
        med[1] = "data/sex/incest/event10/02.jpg";
        med[2] = "data/sex/incest/event10/03.jpg";
        med[3] = "data/sex/incest/event10/04.jpg";
        med[4] = "data/sex/incest/event10/05.jpg";
        med[5] = "data/sex/incest/event10/06.jpg";
        med[6] = "data/sex/incest/event10/07.jpg";
        med[7] = "data/sex/incest/event10/08.jpg";
        med[8] = "data/sex/incest/event10/09.jpg";
        med[9] = "data/sex/incest/event10/10.jpg";
        med[10] = "data/sex/incest/event10/11.jpg";
        med[11] = "data/sex/incest/event10/12.jpg";
        med[12] = "data/sex/incest/event10/13.jpg";
        med[13] = "data/sex/incest/event10/14.jpg";
        med[14] = "data/sex/incest/event10/15.jpg";
        med[15] = "data/sex/incest/event10/16.jpg";
        med[16] = "data/sex/incest/event10/17.jpg";
        med[17] = "data/sex/incest/event10/18.jpg";
        med[18] = "data/sex/incest/event10/19.jpg";
        return med[id - 387];
    }
    else if(id >= 406 && id <= 443)
    {
        med[0] = "data/sex/incest/event11/01.jpg";
        med[1] = "data/sex/incest/event11/02.jpg";
        med[2] = "data/sex/incest/event11/03.jpg";
        med[3] = "data/sex/incest/event11/04.jpg";
        med[4] = "data/sex/incest/event11/05.jpg";
        med[5] = "data/sex/incest/event11/06.jpg";
        med[6] = "data/sex/incest/event11/07.jpg";
        med[7] = "data/sex/incest/event11/08.jpg";
        med[8] = "data/sex/incest/event11/09.jpg";
        med[9] = "data/sex/incest/event11/10.jpg";
        med[10] = "data/sex/incest/event11/11.jpg";
        med[11] = "data/sex/incest/event11/12.jpg";
        med[12] = "data/sex/incest/event11/13.jpg";
        med[13] = "data/sex/incest/event11/14.jpg";
        med[14] = "data/sex/incest/event11/15.jpg";
        med[15] = "data/sex/incest/event11/16.jpg";
        med[16] = "data/sex/incest/event11/17.jpg";
        med[17] = "data/sex/incest/event11/18.jpg";
        med[18] = "data/sex/incest/event11/19.jpg";
        med[19] = "data/sex/incest/event11/20.jpg";
        med[20] = "data/sex/incest/event11/21.jpg";
        med[21] = "data/sex/incest/event11/22.jpg";
        med[22] = "data/sex/incest/event11/23.jpg";
        med[23] = "data/sex/incest/event11/24.jpg";
        med[24] = "data/sex/incest/event11/25.jpg";
        med[25] = "data/sex/incest/event11/26.jpg";
        med[26] = "data/sex/incest/event11/27.jpg";
        med[27] = "data/sex/incest/event11/28.jpg";
        med[28] = "data/sex/incest/event11/29.jpg";
        med[29] = "data/sex/incest/event11/30.jpg";
        med[30] = "data/sex/incest/event11/31.jpg";
        med[31] = "data/sex/incest/event11/32.jpg";
        med[32] = "data/sex/incest/event11/33.jpg";
        med[33] = "data/sex/incest/event11/34.jpg";
        med[34] = "data/sex/incest/event11/35.jpg";
        med[35] = "data/sex/incest/event11/36.jpg";
        med[36] = "data/sex/incest/event11/37.jpg";
        med[37] = "data/sex/incest/event11/38.jpg";
        return med[id - 406];
    }
    else if(id >= 444 && id <= 460)
    {
        med[0] = "data/sex/incest/mini/01.jpg";
        med[1] = "data/sex/incest/mini/02.jpg";
        med[2] = "data/sex/incest/mini/03.jpg";
        med[3] = "data/sex/incest/mini/04.jpg";
        med[4] = "data/sex/incest/mini/05.jpg";
        med[5] = "data/sex/incest/mini/06.jpg";
        med[6] = "data/sex/incest/mini/07.jpg";
        med[7] = "data/sex/incest/mini/08.jpg";
        med[8] = "data/sex/incest/mini/09.jpg";
        med[9] = "data/sex/incest/mini/10.jpg";
        med[10] = "data/sex/incest/mini/11.jpg";
        med[11] = "data/sex/incest/mini/12.jpg";
        med[12] = "data/sex/incest/mini/13.jpg";
        med[13] = "data/sex/incest/mini/14.jpg";
        med[14] = "data/sex/incest/mini/15.jpg";
        med[15] = "data/sex/incest/mini/16.jpg";
        med[16] = "data/sex/incest/mini/17.jpg";
        return med[id - 444];
    }
    else if(id >= 461 && id <= 508)
    {
        med[0] = "data/sex/incest/event12/01.webm";
        med[1] = "data/sex/incest/event12/02.jpg";
        med[2] = "data/sex/incest/event12/02.webm";
        med[3] = "data/sex/incest/event12/03.jpg";
        med[4] = "data/sex/incest/event12/04.jpg";
        med[5] = "data/sex/incest/event12/05.webm";
        med[6] = "data/sex/incest/event12/06.webm";
        med[7] = "data/sex/incest/event12/07.webm";
        med[8] = "data/sex/incest/event12/08.webm";
        med[9] = "data/sex/incest/event12/09.webm";
        med[10] = "data/sex/incest/event12/10.webm";
        med[11] = "data/sex/incest/event12/11.webm";
        med[12] = "data/sex/incest/event12/12.webm";
        med[13] = "data/sex/incest/event12/13.webm";
        med[14] = "data/sex/incest/event12/14.webm";
        med[15] = "data/sex/incest/event12/15.webm";
        med[16] = "data/sex/incest/event12/16.webm";
        med[17] = "data/sex/incest/event12/17.webm";
        med[18] = "data/sex/incest/event12/18.webm";
        med[19] = "data/sex/incest/event12/19.webm";
        med[20] = "data/sex/incest/event12/20.webm";
        med[21] = "data/sex/incest/event12/21.webm";
        med[22] = "data/sex/incest/event12/22.webm";
        med[23] = "data/sex/incest/event12/23.webm";
        med[24] = "data/sex/incest/event12/24.webm";
        med[25] = "data/sex/incest/event12/25.webm";
        med[26] = "data/sex/incest/event12/26.webm";
        med[27] = "data/sex/incest/event12/27.webm";
        med[28] = "data/sex/incest/event12/28.webm";
        med[29] = "data/sex/incest/event12/29.webm";
        med[30] = "data/sex/incest/event12/30.webm";
        med[31] = "data/sex/incest/event12/31.webm";
        med[32] = "data/sex/incest/event12/32.webm";
        med[33] = "data/sex/incest/event12/33.webm";
        med[34] = "data/sex/incest/event12/34.webm";
        med[35] = "data/sex/incest/event12/35.webm";
        med[36] = "data/sex/incest/event12/36.webm";
        med[37] = "data/sex/incest/event12/37.webm";
        med[38] = "data/sex/incest/event12/38.webm";
        med[39] = "data/sex/incest/event12/39.webm";
        med[40] = "data/sex/incest/event12/40.webm";
        med[41] = "data/sex/incest/event12/41.webm";
        med[42] = "data/sex/incest/event12/41.jpg";
        med[43] = "data/sex/incest/event12/42.jpg";
        med[44] = "data/sex/incest/event12/42.webm";
        med[45] = "data/sex/incest/event12/43.webm";
        med[46] = "data/sex/incest/event12/44.webm";
        med[47] = "data/sex/incest/event12/45.webm";
        return med[id - 461];
    }
    else if(id >= 509 && id <= 526)
    {
        med[0] = "data/sex/incest/event14/01.jpg";
        med[1] = "data/sex/incest/event14/02.jpg";
        med[2] = "data/sex/incest/event14/03.jpg";
        med[3] = "data/sex/incest/event14/04.jpg";
        med[4] = "data/sex/incest/event14/05.jpg";
        med[5] = "data/sex/incest/event14/06.jpg";
        med[6] = "data/sex/incest/event14/07.jpg";
        med[7] = "data/sex/incest/event14/08.jpg";
        med[8] = "data/sex/incest/event14/09.jpg";
        med[9] = "data/sex/incest/event14/10.jpg";
        med[10] = "data/sex/incest/event14/11.jpg";
        med[11] = "data/sex/incest/event14/12.jpg";
        med[12] = "data/sex/incest/event14/13.jpg";
        med[13] = "data/sex/incest/event14/14.jpg";
        med[14] = "data/sex/incest/event14/15.jpg";
        med[15] = "data/sex/incest/event14/16.jpg";
        med[16] = "data/sex/incest/event14/17.jpg";
        med[17] = "data/sex/incest/event14/18.jpg";
        return med[id - 509];
    }
    else
        return QString();
}

QString SisterQW::str(int id)
{
    QString str[85];
    if(id <= 84)
    {
        str[0] = "<hero>- А чей-то ты тут с Мишкой секретничаешь?</hero>- спрашиваете вы, немного ревниво.<npc>- Ну я...мы...нравится он"
                 " мне,</npc>- слегка мнясь, сообщает Аня,<npc>- Или ты против?</npc><br><hero>- Ха-ха, да ни разу! Он, конечно, крутой "
                 "трахарь, но у меня другие интересы. Шире, бггг!</hero><npc>- Он меня на свидание пригласил,</npc>- гордо сообщает Аня,"
                 "<npc>- но мы, конечно, будем и с вам тоже...с Колей, с тобой...это мне понравилось.</npc><hero>- Давай дерзай,</hero>- "
                 "подбадриваете вы сестру,<hero>- Уверена, все получится.</hero>";
        str[1] = "Вы не в силах сдержаться от сильного возбуждения отвернулись и уперлись спиной об стену.<br>Спустили свои трусики вниз"
                 " и коснулись пальчиком своей влажной пылающей писе.<br>Облизнули свой пальчик и начали ритмично ласкать свой набухший"
                 " клитор, поглаживая и другой рукой грудь, и наслаждаясь этим моментом забыв обо всем<br>От всего происходящего с вами "
                 "вы быстро кончили прямо перед дверью, еле сдерживая свои стоны.";
        str[2] = "Приоткрыв дверь, ваш слух наглухо пронзили дикие звуки страсти сестры и Ромы.<br>Аня нагнулась, выпячив свою попку"
                 " и отдав её во власть парня, и Рома не мешкая, смело и уверенно драл попку Ани, крепко сжав ягодицы.<br>Его движения"
                 " были быстрее и быстрее, и их тела качались в едином порыве, Аня кричала - <npc>\"..еще, еще\"</npc>.<br>Кажется они"
                 " так увлеклись друг другом, что и не заметили вас, так что пора быстро покинуть горячую парочку.";
        str[3] = "Заглянув в комнату, вы увидели, как вашу сестру грубо имеют раком.<br>Рома почти на грани, вдруг на минутку замер и"
                 " упал на спину сестры глухо застонав.<br><npc>\"..Ты что, снова кончил внутрь?... придурок, слезай с меня, сколько "
                 "можно говорить...\"</npc><br>Похоже им нужно поговорить, а вам пора убегать, пока вас не заметили.";
        str[4] = "Только чуть отодвинув дверь, вы услышали причмокивающие звуки, Аня с удовольствием посасывала у Ромы.<br>Парень лежал"
                 " расслабленным, будто заснувшим, но самое главное в Роме сестренка разбудила и продолжала играть с ним.<br>Анька так"
                 " умело обращается с членом, что вас сильно поразило, может она преподаст вам пару уроков когда-нибудь?<br>Немного"
                 " увлекшись, вы всё же отходите от двери, чтобы не быть обнаруженной.";
        str[5] = "Подбежав в нетерпении к двери, вы ее тихонько отворили, начиная наслаждаться вашей сосущей сестрой.<br>Аня смачно"
                 " заглатывала член до яичек и вынимая его изо рта, тяжело всхлипывала, обмазав все вокруг своей слюной.<br>Ей было "
                 "тяжело делать горловой минет, в слезах и с потекшей тушью, но Рома заставлял и прижимал руками её голову.<br"
                 "Проказница сестренка терпела, лишь бы угодить своему парню.<br>Вы хотели досмотреть до конца, но нужно убегать "
                 "пока вас не заметили.";
        str[6] = "Дверь была приоткрыта, похоже парочка была слишком возбуждена, чтобы её запереть.<br>Они лежали на кровати и страстно "
                 "целовались, прижавшись друг к другу горячими телами.<br>Рома обняв сестру сзади, медленно вошел в её киску, не выпуская"
                 " её губ,и нежно поглаживал её клитор.<br>Анька извивалась всем телом, прислоняясь бедрами к паху парня и постанывала "
                 "едва слышно.<br>В эту секунду вам хотелось только одного - быть на месте сестренки, но вы были у двери и вам пора бежать.";
        str[7] = "Вас все время не покидала и возбуждала мысль, о том чтобы подсмотреть за Аней и ее парнем.<br>И не найдя сил перебороть"
                 " этот соблазн, вы подошла к двери вашей комнаты и медленно дотронулась до ручки.<br>Она чуть приоткрылась, и твоему взору"
                 " представилась откровенная сцена.<br>Аня сидела на коленках перед Ромой, нежно и чувственно целовала его головку, а "
                 "Рома расслабившись лежал на спине, и одаривал сестру комплиментами.<br>Вы сильно возбудилась, но от страха оказаться"
                 " обнаруженной, прикрыли дверь.";
        str[8] = "Вы целый день были слишком возбуждены и снова захотелось подсмотреть за Аней и ее парнем.<br>Дверь на удивление легко "
                 "приоткрылось, и вы застыли от увиденной картины.<br>Рома крепко схватившись за волосы сестры, жестко трахал её в "
                 "ротик.<br>Аня держалась за бедра парня, чтоб не упасть от сильного напора, томно стонала и всхлипывала.";
        str[9] = "Вам очень понравилось наблюдать за сестрой и Ромой и вы снова решили с этим не мешкать и подсмотреть за ними.<br>"
                 "Дверь была чуть приоткрыта, кажется они совсем забыли о мерах предосторожности, а может Аня догадалась и специально "
                 "не закрывает двери.?<br>Аня смачно сосала член Ромы, и страстно с дикими глазами смотрела на него, на минете они "
                 "останавливаться точно не собираются.<br>Вы были и так возбуждены, но увиденное завело вас еще сильнее.";
        str[10] = "Вам стало любопытно и решила побороть свое сильное возбуждение, чтоб подсмотреть ещё немного.<br>Заведенный Рома "
                  "грубо развернул Аню, и впился губами между её ножек, Аня начала слегка извиваться и постанывать.<br>Но парень "
                  "продолжал, сильно сжав попу сестры, время от времени подсматривая на неё снизу.<br><hero>\"Как же ей хорошо, "
                  "хотела бы я быть на её месте\"</hero> - подумали вы про себя, наслаждаясь картиной.";
        str[11] = "Вас полностью поглотило происходящее, ты не отрывала взгляда от двух молодых возбужденных тел вашей сестры и ее "
                  "парня.<br>Рома оторвался от сладкой писечки сестры, Аня с легким сожалением посмотрела на него и улыбнулась.<br>"
                  "Он улыбнулся ей в ответ, развернул Аню на животик и резко вошел, начиная двигаться быстрее.<br>Аня громко вскрикнула,"
                  " но потом вспомнила, что в доме они не одни, и едва сдерживая свои животные крики, покачивалась и двигала попкой в такт"
                  " движениям Ромы.<br><npc>- Да, да, еби меня пупсик, вырывалось из томное мычанье сестренки.</npc>";
        str[12] = "Вы совсем потеряли ясный ум и сознание, и как загипнотизированная продолжали наблюдать за страстными любовниками."
                  "<br>Теперь Ромка развернул твою сестру на спинку, Аня расставила ножки пошире, и они продолжили вожделенное соитие."
                  "<br>Парень двигался все быстрее и быстрее, начиная тяжело дышать и глухо стонать.<br>Анька была вся красной и вспотевшей,"
                  " расслабившись лежала под Ромой и ловила кайф.<br>Тут Рома предупредил, что скоро кончит, и Аня вскрикнула:<br>"
                  "<npc>- Только не внутрь зая,прощу только не внутрь,</npc> и Рома спешно вытащил хуй и мгновенно кончил на животик сестры.";
        str[13] = "Аня возбужденная и растрепанная открывает вам дверь:<br><npc>- Ну, Светик, ты же обещала, иди ещё погуляй немного,"
                  " мы тут еще не закончили.</npc><br>Она быстро захлопнула дверь и повернула ключ, слышно было только её хихиканье.";
        str[14] = "Вы хотели зайти к себе в комнату, но вспомнили данное сестре обещание и решили не беспокоить ее.";
        str[16] = "Сестра напомнила вам, что они с Ромой хотели провести время наедине и просит вас уйти из комнаты.";
        str[17] = "Сестра попросила вас ненадолго уйти из комнаты.";
        str[18] = "Грустная Аня открывает вам дверь:<br><npc>- Ты же обещала прийти, что случилось? Ладно может в следующий раз...</npc>";
        str[19] = "Вы вошли в комнату, сладкая парочка уже кувыркалась в постели.<br>Анька заметила вас, освободилась от объятий парня "
                  "и подошла к вам начиная медленно целовать и раздевать.";
        str[20] = "Вы с легкостью поддались искушению и поцеловали Аньку в ответ.<br>Её руки блуждали по вашему телу, медленно разогревая"
                  " и раздевая вас.<br>Вы были полностью во власть сестры наслаждаясь ласками, и не заметили как оказались голой перед "
                  "Ромой, совсем забыв о нем.<br>Аня приказала ему сидеть, и ваши лица очутились у ширинки парня.";
        str[21] = "Все вы не на шутку завелись. Аня прыгала и двигалась на члене быстрее и быстрее находясь на грани оргазма.<br>Вы"
                  " закрыв глаза скользили истекающей соком писей по лицу Рому, находясь на седьмом небе.<br>И внезапно вы вместе"
                  " начали кончать, обкончав бедного парня, но сам он ещё не кончил.<br>Положив ваши лица рядом, и едва коснувшись"
                  " члена, излил на вас горячую струю.<br>Вы блаженно лежали с сестрой целуясь и наслаждаясь вкусом спермы";
        str[22] = "Аня повела вас к своему парню. Все вы были словно в оторопелом состоянии.<br>И Аня приказала Роме:<br><npc>- "
                  "Поработай над ней.</npc><br>И помогла вам сесть ему на лицо, так что ваша киска оказалась у него перед носом."
                  "<br>Он не долго думая начал вылизывать ее. Ромин член немного опал, поэтому Аня еще немного его пососала, и как "
                  "только он пришел в боевое состояние села на него.<br>Она медленно опускалась, пока член не погрузился в нее"
                  " полностью. Ее киска была мокрая и узенькая.<br>Постепенно увеличивая темп, она скакала на члене, а Рома вылизывал"
                  " вашу обильно текшую киску.";
        str[23] = "Вы начали медленно водить языком вверх-вниз по стволу. И почувствовали как Рома чуть не дрожал от возбуждения.<br>"
                  "Если бы Аня не держала член рукой, Рома бы наверняка вогнал бы его в ваш рот по самые яйца, так сильно вы его "
                  "завели.<br>Позже вы поделились с сестрой. Сосала она медленно и со вкусом. То заглатывала член наполовину, "
                  "облизывая его язычком по всей длине. Рома лежал и балдел.";
        str[24] = "<hero>- Да ну нафиг, к черту все это!</hero><br>В последний момент вы решили удрать от этих извращенцев.";
        str[25] = "Вы вошли в комнату, сладкая парочка уже кувыркалась в постели.<br>На этот раз не было ни грамма смущения. Ваши"
                  " глаза как-то странно заблестели. Аня медленно подошла к вам и поцеловала взасос. И вы ответили ей нежным "
                  "поцелуем.<br>Аня начала мять вашу грудь сквозь одежду, потом скинула с плеч лямки лифчика, и позже трусики "
                  "упали вниз, и на вас ничего не осталось.";
        str[26] = "Вы запыхавшись лежали лицом к лицу. Рома пристроился между вами и начал яростно надрачивать на ваши лица.<br>"
                  "Вскоре он кончил, тяжело дыша, оттряхивал на вас последние капли.<br>Вы расслабленно лежали и целовались обмениваясь"
                  " сладким нектаром.";
        str[27] = "<npc>- Вы когда-нибудь делали друг другу куннилингус?</npc> - спросил парень, вставая. Вы только оглянулись и игриво"
                  " улыбнулись.<br>Аня легла, а вы сели на нее. И начали вылизывать друг друга. Полюбовавшись на вас с полминуты Рома"
                  " подошел к вам.<br>Ваша попка была призывно выставлена в его сторону, и он медленно ввел свой член в вашу киску.";
        str[28] = "Вы закусили губу от боли и из глаз брызнули слезы когда Рома вошел в вас, разорвав вашу девственную плеву.<br><npc>"
                  "- Вот это номер!</npc> - удивленно воскликнула Аня, когда капли крови попали на её лицо.<br><npc>- Ромка, прикинь,"
                  " ты у Светы первый мужчина...</npc><br>Ромка растерянно переводил взгляд с своего окровавленного члена на Аньку,"
                  " не зная, что делать дальше.<br><npc>- Ладно, продолжим как-нибудь по другому</npc>, - сказала Аня, видя боль в"
                  " ваших глазах.";
        str[29] = "Он вгонял член на всю длину, иногда его задевал Анин язычок, который вылизывал ваш клитор и его яйца. Через пару "
                  "минут Рома почувствовал, что кончает...";
        str[30] = "Вместе с Анькой вы взялись за слегка обмякший член, и без дальнейших разговоров принялись за дело.<br>И опять "
                  "Рома лежал, а вы ему отсасывали. Анька сосала она знатно. Вы даже не думали, что она так умеет. Как говорится, в"
                  " тихом омуте...<br>Она заглатывала член почти полностью, активно обрабатывая головку языком. Вы менялись, словно "
                  "соревнуясь кто лучше сосет.<br>Через несколько минут Рома был готов...";
        str[31] = "Вы вошли в комнату, сладкая парочка уже кувыркалась в постели.<br>Аня увидала вас, но только помахала, продолжая "
                  "принимать ласки. Быстро раздевшись, и от возбуждения вы были в нетерпении уже к ним присоединиться.";
        str[32] = "Положив ваши лица рядом, и едва коснувшись члена, излил на вас горячую струю.<br>Вы блаженно лежали с сестрой целуясь"
                  " и наслаждаясь вкусом спермы. Рома лег на кровать, еле приходя в себя, а вы вместе с Аней полежав немного, пошли в душ.";
        str[33] = "<npc>- Хочу новых ощущений</npc> – Аня помахала вам тюбиком с кремом.<br>Аня завелась не на шутку, и решилась попробовать"
                  " в попку. Она встала на кровати на четвереньки, и вы, смазав кремом ее анус, стала медленно вводить свой пальчик ей"
                  " в попку.<br>Аня немного дергалась и постанывала, но вот ваш палец уже легко входил, и вы ввели второй. Аня застонала"
                  " громче.<br>Через пару минут уже оба пальчика спокойно помещались в ее попке. Не вытаскивая пальцев из ануса сестренки,"
                  " второй рукой направили член к себе в рот. Через минут боец был готов.<br>Вы смазали головку кремом, и Рома начал "
                  "медленно входить Анину дырочку. Головка входила очень туго. Аня вскрикивала, но головка уже погрузилась в нее.<br>"
                  "Рома начал медленно двигаться туда-обратно, постепенно наращивая темп. Через несколько минут она прогнулась, застонала,"
                  " и вы почувствовали, что она кончает...";
        str[34] = "Рома посадил вас обоих на колени, ну а дальше что делать вам указывать не нужно было.<br>Вы с увлеченностью сосали "
                  "член, меняясь с любимой сестренкой, посасывая по очереди то головку, то облизывая яйца.<br>На мгновения вы забывали "
                  "о члене и начинали целоваться, и Рома наслаждался этой картиной но быстро подсовывал свой агрегат вам обратно.<br>"
                  "Вам надоело сидеть на коленках и дальше захотелось... ";
        str[35] = "Вы вошли в комнату, сладкая парочка уже кувыркалась в постели.<br>Бросив Аню на кровати, Рома набросился на вас бурно "
                  "целуя и лапая ваше сексуальное тело. За пару мгновений вы и не заметили как оказались голой и сильно заведенной.";
        str[36] = "Рома едва успевает вытащить член из вашей киски и резко кончает прямо на неё.<br>Анька недоуменно смотрит на него:"
                  "<br><npc>- Ты что творишь? Хочешь, чтобы она залетела? Тогда придется жениться на ней, а не на мне.</npc><br>"
                  "<hero>- Да все нормально, я же внутрь не попал</hero>, - запыхавшись отнекивался Рома.<br>А вы лежали в экстазе, "
                  "и не совсем понимали, что вокруг творится.";
        str[37] = "На этот раз Рома хотел только вас. Он поставил вас раком, а Аня легла перед вами, широко раздвинув ножки. Немного "
                  "помедлив, Рома бесцеремонно вогнал, в вашу " + root->getVaginaTipe2() + " киску, член по самые помидоры, и начал"
                  " яростно двигаться внутри.";
        str[39] = "Аня тем временем прижала ваше милое лицо к своей писе. Вы едва отдышавшись от бурных действий Ромы, снова, и снова"
                  " погружались в сладкую киску сестренки, пытаясь доставлять ей удовольствие. А она, тем временем, лежала, и получала"
                  " удовольствие от вашего язычка, и ревностно смотрела в глаза Ромы, который был уже на грани...";
        str[40] = "Ромка сказал, что любит глубокий минет, вы все поняли у уговаривать вас не нужно было.<br>И по очереди вы начали"
                  " заглатывать большой член, но у вас явно получалось гораздо хуже чем у сестры. Она заглатывала так, аж дух"
                  " захватывало. При этом одной рукой ласкала яйца, а другой гладила по животу, доставляя своему парню неимоверное"
                  " удовольствие.<br>Вы так завели парня, что он разгоряченный не в силах был уже терпеть...";
        str[41] = "Вы вошли в комнату, сладкая парочка уже кувыркалась в постели.<br>На ходу срывая с себя всю одежду, вы набросились"
                  " к паре на кровать";
        str[42] = "Усадив вас перед собой, Аня взяла в руки член и стала надрачивать вам в рот:<br><npc>- Соси, хочешь все проглотить?"
                  "</npc><br>Парень от такого напора долго не удержался и кончил вам в рот, вздрагивая и заполняя вас. Вы не успевали"
                  " все глотать, струйка потекла по подбородку, а Аня все надаивала да последней капли...";
        str[43] = "Вы с Аней так увлеклись, что начали использовать бедного парня как секс игрушку.<br>Аня села писей на лицо Роме "
                  "и каталась на нем, получая неимоверное удовольствие. Вы уселись спиной к ним, полностью подчиняя себе Ромин член "
                  "начали безумно скакать и кричать.<br>Роме оставалось только безвольно мычать и глухо стонать под двумя красавицами"
                  " пока на него не нахлынула волна блаженства...";
        str[44] = "Вам нравилось сосать этот упругий, толстый стержень. Его шляпа с трудом заходила вам в рот, и вы очень старалась "
                  "делать хороший отсос.<br>Этот чупа чупс обещал быть долгоиграющим, так и не хотел кончать. Вы засовывали его кувалду"
                  " до конца, касаясь губами ароматного волосатого лобка.<br>От него охуенно пахло. По очереди с Анькой вы облизывали"
                  " и покусывала шляпу, играя языком с уздечкой. Ваши язычки скользили по стволу к яичкам...";
        str[45] = "Как только вы ввалились в дом Рекса, моментально включилась громкая музыка.<br>Вы с девченками стали помогать парням "
                  "накрывать стол, они несли выпивку, вы закуску, но бухла было столько, что еде не куда было ставить.<br>Все начали"
                  " дружно бухать, общаясь, смеясь, рассказывая веселые истории...<br>И к вам обратилась веселая Анька:<br>"
                  "<npc>- Ты че скучаешь сестренка, а ну-ка веселей, пока не опустошишь этот стакан, я тебя не оставлю..</npc><br>"
                  "Свободных стаканчиков не оказалось, и она вам дала бутылку с бухлом в руки.";
        str[46] = "Все навеселе разделись до пояса и пошли в зал танцевать.<br>Вас уже не нужно было уговаривать, вы были на одной"
                  " волне со всеми и тоже разделись, оставшись в одном лифчике.<br>Парни бесились и прыгали, хоть вы и полуголая,"
                  " но кажется и не обращали на вас никакого внимания.<br>К вам подошла Аня:<br><npc>- Светик, давай веселей,</npc>"
                  " - и вы проникли в центр веселясь и вытворяя в танце весьма соблазнительные вещи.";
        str[47] = "Вы ищите свою сестру, но никак не можете найти. <hero>- Черт, где же она запропастилась?</hero><br>Нужно везде "
                  "посмотреть, мне нужно её найти.";
        str[48] = "Ворвавшись в кухню, вы оглядываетесь и ищете взглядом сестру. И замечаете как у углу Ромка развлекается с двумя"
                  " пьяными телками...<br>Но ни в одной из них вы не узнаете сестру Аню... Как вдруг за спиной слышите чье-то сопение...";
        str[49] = "Повернувшись вы обнаружили голую выпивающую Аню, на её глазах были видны слезы.<br><npc>- Ну что ж Ромка, вижу "
                  "между нами все кончено, вали к чертям, кобель.</npc> - Рома ничего не смог сказать в ответ.<br>И Аня убежала прочь."
                  " Поругав Рому несколько минут, вы ринулись прочь за сестрой...";
        str[50] = "Едва успев за Аней, вы нашли её сидящую на коленях перед двумя незнакомыми парнями.<br><hero>- Что ты делаешь, "
                  "прекрати, не стоит сразу бросаться во все тяжкие.</hero><br>Пьяная Ани вряд ли как-то воспринимала ваши слова, "
                  "продолжая отсасывать.<br><npc>- Эй ты, давай присоединяйся, или вали нахрен и не мешай нам.</npc>";
        str[51] = "Вы решили не спорить с сильными парнями и подождать.<br>Парни перевернули Аню на живот, и начали трахать её в два"
                  " члена.<br><npc>- Давай в очко её, все равно бухая, хрен че почувствует.</npc><br>И по очереди трахали её, пока "
                  "не обканчали очко.";
        str[52] = "<npc>- Ладно мальчики, я тоже хочу, кто меня выебет?</npc><br>Оживленные парни разобрали вас, и в комнате воцарилась"
                  " дикая оргия.<br><npc>- О да, иметь свою личную шлюху гораздо лучше,</npc> - довольные, трахали вас во все щели."
                  "<br>Обслужив парней и едва собравшись с мыслями, вы направились домой.";
        str[53] = "Зайдя в туалет вы обнаружили как парни приводят в чувство одну из девушек.<br>Присмотревшись, к счастью это"
                  " оказалось не она";
        str[54] = "В комнате вы увидели как две парней наяривают в два ствола бедную бессознательную девушку.<br><npc>- Давай еби,"
                  " пока не очнулась, я не хочу иметь дело с её бывшим парнем боксером.</npc>";
        str[55] = "Вы подошли к имениннику, чтобы лично поздравить, хотя вы мало знакомы.<br>Он в этот вечер был явно веселее всех,"
                  " и на ваше удивление все еще был живчиком.<br><npc>- О привет, чикуля, ты же эта... вот черт.. ах да, Анина "
                  "сестренка, я знаю, знаю... Чет я не видел, чтобы ты сегодня пила за меня, во шампусик, давай, давай пей до дна.."
                  "</npc><br>С этими словами вы выпили сладкое шампанское, но пьяный Рекс затолкал бутылку так сильно, что пришлось"
                  " поглотить в ротик пол горлышка...<br>Позже Рекс оставил вас и куда-то ушел...";
        str[56] = "Оказалось туалет открыт, и вы тут обнаружили Рекса, приходящего в себя от выпивки.<br><npc>- О, Света, снова ты?"
                  " Я тут уже выхожу, чет перебрал сегодня немног...</npc><br>Остановив его на полуслове, толкнули его на унитаз и"
                  " сели на него сверху, впившись губами в поцелуе.<br><hero>- Вот мой тебе и подарочек,</hero> - промолвили вы с "
                  "игривой улыбкой.<br><npc>- Черт, охренительно...,</npc> - промычал Рекс. Тем временем вы почувствовали как вам "
                  "в промежность упирается возбужденный Рексик.";
        str[57] = "Рекс приказал вам нагнуться, и резко вогнал в вас свой разгоряченный член.<br><hero>- Не так быстро, не так "
                  "глубоко,</hero> - молили вы, но постепенно боль рассосалась и вы начали ерзать на члене и получать удовольствие."
                  "<br>Парень в этот момент точно не думал, чтобы удовлетворить вас, все быстрее и быстрее вгоняя член он кончил "
                  "вам в киску.<br><npc>- Ух Светик, да ты горячее своей сестры, с этими словами он вышел..</npc><br>Вы тоже привели"
                  " себя немного в порядок, и пошли...";
        str[58] = "Они лапали ваше тело, касались сисек, прижимали к себе.<br>Под действием алкоголя вам очень это нравилось, и просто"
                  " наслаждались моментом.<br>Увидев, что вы вовсе не сопротивляйтесь они потащили вас в соседнюю комнату.";
        str[59] = "Зайдя в комнату вас повалили на кровать,и вывалили перед лицом два члена на обслуживание.<br>В пьяном тумане "
                  "вы пытались схватиться то за один, то за другой, но все валилось из рук.<br>Один из парней облизав вам писю, и"
                  " убедившись, что вы вся течете от желания, поставил вас раком перед другим.";
        str[60] = "Вас поставили раком, и начали ебать в два ствола, пронзая одновременно спереди и сзади.<br>Парни явно были довольны"
                  " и шутили переговариваясь друг с другом:<br><npc>- А ты говорил, что она еще маленькая, да она своей сестре Ане "
                  "фору даст.</npc><br><hero>- Да, ты прав, отличная молоденькая штучка, давно я школьниц не ебал, эй давай меняться,"
                  " одним минетом сыт не будешь...</hero>";
        str[61] = "Парни поменялись местами и продолжили ритмично вас трахать.<br>Через некоторое время ебли, вы немного пришли в себя:"
                  "<br><npc>- О да, очнулась сучка, давай соси усердней твою мать, он уже совсем вялый..</npc><br>И начали упорно сосать,"
                  " пока тот не кончил вам в ротик, обрызгав все лицо. Второй тоже не мешкая, вытащил хуй и кончил вам на попу.<br>"
                  "Немного прийдя в себя, вам захотелось найти сестру.";
        str[62] = "Вам захотелось выпить еще и еще, парни быстро дали вам в руки две бутылки вискаря и не раздумывая вы начали все "
                  "выливать на себя.<br>Вся ваша одежда была мокрая, и через мокрый лифчик виднелись выпирающие соски.<br>Два парня "
                  "вокруг вас обезумели, стали танцевать вокруг вас, все настойчивее лапая ваше тело.";
        str[63] = "Вы пьяны, но в состоянии еще себя контролировать, вам захотелось продолжить танец.<br>Своими эротичными движениями"
                  " вы привлекли внимание многих парней, и к вам подошли двое.";
        str[64] = "Все навеселе разделись до пояса и пошли в зал танцевать.<br><npc>- Идем танцевать, Светик, что ты тут осталась одна,"
                  " там веселее.</npc><br><hero>- Сейчас Анька, только настроение нужно мне поднять ещё выше, иначе мне будет скучно.</hero>";
        str[65] = "После выпитого у вас немного закружилась голова, и вы предпочли немного посидеть.<br>Тут к вам подошла Аня с "
                  "подружками:<br><npc>- Светик че ты тут киснешь, не на похоронах же, ай да вместе тусить...</npc><br>От уговоров "
                  "сестренки нет покоя, и вы знаете, вам лучше согласиться, иначе она не отстанет.";
        str[66] = "Вы взяли бутылку из рук Ани.<br><hero>- Что ж, гулять так гулять по полной,</hero> - и глотнули с горла крепкий "
                  "горячительный напиток, под шум и гоготы компании.<br><npc>- Смотри, баба пьет больше тебя,</npc> - с этими словами"
                  " все начали поить Рекса..";
        str[67] = "Вы дружелюбно попытались отказаться пить.<br>Но все заметив это хором начали кричать: <npc>\"Пей, пей, пей, пей, "
                  "пей,пей....\"</npc><br>Поняв, что уже немного рагоряченая компания просто так вас не оставит..<br>Вы взяли бутылку"
                  " из рук Ани, и глотнули с горла крепкий горячительный напиток, под шум и гоготы компании.";
        str[68] = "Встав, вы попытались выйти изо стола, чтобы пойти потанцевать, но там никого не было, все сидели и пили.<br>Увидав,"
                  " что вы встали и хотите покинуть стол, Рекс вас остановил:<br><npc>- Куда же ты, все только начинается, держи бутылку,"
                  " и давай выпьем, иначе я обижусь.</npc><br>Вы не могли отказать имениннику, взяли бутылку из его рук, и глотнули с "
                  "горла крепкий горячительный напиток, под шум и гоготы компании.";
        str[69] = "<npc>- Привет Света, мы сегодня идем на вечеринку к Рексу, ты с нами?</npc>";
        str[70] = "<hero>- Я бы с радостью, но у меня куча дел, извини.</hero><br><npc>- Ничего, может в другой раз получится, а мы пошли,"
                  " пока.</npc>";
        str[71] = "<npc>- Света, в городке ходят всякие слухи, и тут парни все слышали, так что на вечеринку лучше не приходи, иначе "
                  "непоздоровится.</npc>";
        str[72] = "<npc>- Привет Света, мы сегодня идем на вечеринку к Рексу, ты с нами?</npc><br><hero>- Извини Аня, чет я сегодня не"
                  " в настроении, так что сегодня без меня.</hero>";
        str[73] = "<npc>- Света, ты где уже успела так надраться. Хотела тебя позвать на вечеринку, но ладно иди домой, приходи в себя.</npc>";
        str[74] = "<npc>- Сестренка, посмотри на себя, в каком ты виде, боже ты мой, иди быстро домой и умойся.</npc><br>Вам стало немного"
                  " стыдно перед сестрой за свой неопрятный внешний вид.";
        str[75] = "<npc>- Детка, идем ко мне, я сегодня снова организовал у себя классную тусу.</npc>";
        str[76] = "<hero>- Извини Рексик, у меня сейчас куча дел, я бы с радостью но..</hero><br><npc>- Ну ладно, иди по своим дела, но"
                  " в следующий раз обязательно, окей?</npc>";
        str[77] = "<npc>- Бля, Света везде говорят, что ты долбанная шлюха. Что за херня, Света, я думал мы мутим, и у нас все серьезно,"
                  " а ты трахаешься с кем попало?</npc><br><hero>- Не знаю что на меня тогда нашло, прости меня, если сможешь.</hero>"
                  "<br><npc>- Слушай, все классно, но давай останемся друзьями, забудем всё что у нас было. Ладно?</npc><br>"
                  "<hero>- Ладно...</hero>";
        str[78] = "<hero>- Извини Рексик, чет я сегодня не в настроении, так что сегодня без меня.</hero><br><npc>- Блин, не хочется"
                  " оставлять тебя одну, но мне нужно пойти с ребятами, не обижайся, и не скучай, целую.</npc>";
        str[79] = "<npc>- Света, ты где уже успела так надраться. Хотел тебя позвать на вечеринку, но ладно иди домой, приходи в себя.</npc>";
        str[80] = "<npc>- Бля, Света ты вся в сперме. Что за херня, Света, я думал мы мутим, и у нас все серьезно, а ты трахаешься"
                  " с кем попало?</npc><br><hero>- Не знаю что на меня тогда нашло, прости меня, если сможешь.</hero><br><npc>- Слушай,"
                  " все классно, но давай останемся друзьями, забудем всё что у нас было. Ладно?</npc><br><hero>- Ладно...</hero>";
        str[81] = "Веселая компания Анькиных друзей уже собралась на очередную пьянку у Рекса";
        str[82] = "<npc>- Чего тебе надо? Вали давай!</npc> - сказала вам Аня под смешки ее друзей.";
        str[83] = "Аня сидит с компанией девчонок и парней, пьющих пиво: <npc>- Привет, сестренка,</npc> - сказала вам Аня, улыбнувшись."
                  " <npc>- Хочешь пиваса?</npc>";
        str[84] = "Вы познакомились с друзьями Ани. Они все бывшие одноклассники. Маленькая и подвижная Лена, постоянно смущающаяся Ира,"
                  " высокий атлетичный парень, которого все зовут Рекс, и рыжеволосый худощавый парень по имени Рома. После знакомства вы "
                  "сидели пили пиво и общались с приятелями Ани.";
        return str[id];
    }
    else if(id >= 85 && id <= 112)
    {
        str[0] = "Вы лежите на кровати и читаете Анькин женский журнал, сама она после вечеринки как обычно завалилась спать пораньше, в стельку бухая."
                 " Читая журнал, вы натыкаетесь на эротические рассказы. Они вас немного возбуждают, а ваша рука сама тянется к груди. ";
        str[1] = "Решив, что Аня спит крепко, вы обнажили грудь, руку запустили в трусики и начали поглаживать лобок, при этом продолжая читать журнал.";
        str[2] = "Затем быстро избавились от трусиков и начали играться со своими дырочками, время от времени бросая взгляд на картинку в журнале.";
        str[3] = "Почувствовав, что пальцев вам будет недостаточно, вы вытащили из-под кровати дилдо и легли поудобнее.";
        str[4] = "Вставив фаллоимитатор в свою киску, вы закрыли глаза и начали медленно двигать его внутри, погружаясь в свои фантазии. Вам неистово"
                 " захотелось, чтобы на его месте оказался настоящий мужской член.<br><hero>- Ох да, еще, еще... трахай мою мокрую пизденку, братец!"
                 "</hero> - стали тихо шептать вы, возбуждаясь еще сильнее.";
        str[5] = "Внезапно ощутив на себе посторонний взгляд, вы открыли глаза. К вашему удивлению, там стоял Николай, который, вероятно, уже какое то "
                 "время наблюдал за вами и все слышал.<br><hero>- Коля, какого ху… ты тут делаешь?</hero><br><npc>- Да вот, решил пока все спят с любимой"
                 " сестренкой покувыркатся.</npc>";
        str[6] = "<hero>- Ты что головой стукнулся, вали к себе немедленно, не то останешься без сладкого на пару месяцев!</hero><br><npc>- Ладно, ладно "
                 "уже ухожу только не злись.</npc>";
        str[7] = "Вы находились в позе, открывавшей Кольке великолепный вид на все ваши прелести:<br><hero>- Коля, иди сюда твоя сестренка уже разогрелась,"
                 " дальше твоя очередь.</hero><br><npc>- Ого, какой у тебя членозаменитель, даже не встречал подобного. Можно я им с тобой поиграю для"
                 " начала?</npc><br><hero>- Держи, только осторожнее,</hero>- предупредили вы, вручая дилдо брату.";
        str[8] = "Колька взял дилдо и начал медленно и аккуратно вводить его вам в зад, постоянно спрашивая все ли у вас нормально.";
        str[9] = "Слегка приноровившись, брат стал более уверенно двигать игрушку, вы блаженно заулыбались:<br><hero>- Да-да, вот так очень хорошо. А теперь"
                 " поработай над главной гордостью девушки.</hero>";
        str[10] = "Коля медленно вынул дилдо из вашей попки и также медленно и аккуратно вошел им в вашу киску. Затем начал двигать, наращивая темп. Вы "
                  "застонали.<br><hero>- Оооо, здорово, то, что и было надо! Теперь дай я попробую на вкус свои соки,</hero> - как можно распутнее прошептали вы.";
        str[11] = "Коля поднес влажный фаллоимитатор к вашему рту, вы высунули язычек и начали облизывать его:<br><hero>- А я весьма приятная на вкус, ты так"
                  " не считаешь?</hero><br><npc>- Ага, может, уже пора тебе попробовать мой сегодняшний вкус?</npc>";
        str[12] = "Вы улыбнулись, стянули с Кольки джинсы и начали обрабатывать его инструмент.";
        str[13] = "Посчитав, что он уже готов, вы стащили юбочку и запрыгнули сверху на член брата.<br><hero>- И все же никакое дилдо не заменит настоящий"
                  " член,</hero> - простонали вы, играя руками с напряженными сисечками.";
        str[14] = "Колька прижал вас к себе и стал наращивать темп:<br><npc>- Света, ты так намекаешь, что нам почаще надо этим заниматься?</npc><br>Вас "
                  "охватил легкий стыд, вы смущенно подумали: “А не прекратить ли?”. Но остановиться было просто невозможно.";
        str[15] = "А Колька тем временем не унимался он повернул вас на бок и стал двигаться еще активнее.<br><npc>- Света, я не слышу твоего ответа? "
                  "С тобой все в порядке?</npc><br><hero>- Ахх… боже … я не знаю..</hero>- от наслаждения ваша рука сама потянулась к клитору и начала его"
                  " теребить, вдруг до вас дошло что это и был ответ вашего тела на вопрос который так вас смутил.";
        str[16] = "Вы больше не колебались, взяв инициативу в свои руки: встали на колени и подставили Кольке ваш зад, он вошел в вас неуверенно.<br>"
                  "<hero>- Коля прости. Я… Я… дура… Пожалуйста, трахай свою глупую сестренку при первом удобном случае.</hero><br><npc>- Светуля, ты чего? "
                  "Я все понимаю, я тоже много думал об этом…</npc><br><hero>- Коля замолчи! Мы больше никогда не будем говорить на эту! Ты меня понял? "
                  "А сейчас я хочу чтобы ты уделил внимание моей попке, она очень этого хочет.</hero>";
        str[17] = "Колька ничего не стал отвечать, а решил дать ответ своими действиями, и сменил свое место дислокации. Ощутив как Колька входит в ваш зад,"
                  " вы вдруг почувствовали надвигающуюся на вас очередную волну возбуждения улыбка появилась на вашем лице и похоть затмила все остальные "
                  "ваши чувства:<br><hero>- Ох да, как же хорошо разве можно от такого отказываться,</hero> - в полный голос произнесли вы, не заботясь о"
                  " том что вас могут услышать.<br><npc>- Тише, тише…</npc>- прошептал Колька и видя, что вы на это не реагируете, сменил позу, дабы дать"
                  " вам перевести дух.";
        str[18] = "Но вы уже завелись и через минуту вопили еще громче.<br><npc>- Света, тише ты же Аньку разбудишь!</npc><br><hero>- Нет, все нормально,"
                  " трахай меня посильнее!</hero><br><npc>- Одумайся, ты хочешь чтобы нас застукали?</npc><br><hero>- Не хочешь меня трахать? Тогда я сама"
                  " тебя трахну!</hero>";
        str[19] = "Оседлав Кольку, вы начали прыгать на нем, вопя все громче и громче.";
        str[20] = "Бурно кончая вы завизжали так, что вас, наверно, услышали ближайшие несколько этажей, от такого ору Аня проснулась, с просони не совсем "
                  "понимая, что случилось.<br><npc>- Что тут происходит, что за крики?</npc> - Аня, протирая глаза, уставилась на соседнюю кровать.<br><npc>"
                  "- Светик, нахера ты ебаря к нам в комнату притащила родители узнают даже не знаю, что с тобой сделают!<npc> - сказала Аня и начала "
                  "подниматься с кровати, чтобы разобраться с вашим блядством.";
        str[21] = "<npc>- Колька, паразит, ты что ли?!</npc>- с изумлением воскликнула Аня, подходя поближе.<br><hero>- Аня, успокойся, мы тебе все объясним,"
                  "</herO> - неуверенно пролепетали вы.<br><npc>- Успокоится?! Вы что, в конец ебанулись?! Если родители слышали твой вопль - они же тебя из "
                  "дома выкинут.</npc><br><hero>- Если бы слышали - уже были тут. Колька, вали к себе, я тут сама все улажу.</hero><br>Колька быстро натянул "
                  "штаны и выбежал из комнаты";
        str[22] = "Аня, кипя от злости, проводила Кольку взглядом и села рядом с вами.<br><npc>- Света, он же наш брат, как ты вообще до такого додумалась?"
                  "</npc> - с гневом произнесла Аня.<br><hero>- Ну отцы-то у нас разные… Все само как-то получилось… Да и в кровати он весьма хорош, попробовав"
                  " однажды удержаться очень трудно… Я прошу только родителям не рассказывай!!!</hero><br><npc>- Я что, дура что ли, мне за такое наверняка "
                  "тоже достанется! Но я все равно не понимаю тебя, что школьных парней мало, зачем ты с братом спать начала?</npc><br><hero>- Ну ты же"
                  " понимаешь, что я не могу привести парня домой: родители увидят - убьют, а Колька он всегда тут: трахнул по-быстренькому и никто ничего "
                  "не заметит. К тому же ты не шибко возражала когда мы с тобой развлекались!</hero><br><npc>- Света, там совсем другое!!</npc><br><hero>"
                  "- Значит, по-твоему с родной сестрой трахатся нормально, а со сводным братом нет?</hero> - возмущаясь спросили вы.<br><npc>- Ну… ладно…"
                  " но все равно оно как то неправильно, да и подумай что будет если родители узнают…</npc><br><hero>- Анька, поверь награда оправдывает любой"
                  " риск!!!</hero><br>Аня покраснела, видимо, представляя себя на вашем месте.<br><npc>- Света, будь осторожнее родители узнаю мне тоже "
                  "достанется, а теперь пора спать. Надеюсь, нам больше не придется такое обсуждать… Блин, из-за вас придурков только возбудилась!</npc><br>"
                  "<hero>- Ооо, вот это правильно,</hero> - рассмеялись вы, полностью отойдя от испуга.<br><b>Надо бы утром пока родители спят с Колей "
                  "переговорить</b>- подумали вы и легли спать";
        str[23] = "Взяв себя в руки, вы слегка притормозили и сменили позу, давая отдохнуть своей заднице.<br><hero>- Ух, пронесло…</hero> - прошептали вы."
                  "<br><npc>- Света, ты чуть нас не спалила!</npc><br><hero>- Прости, Коль, потеряла над собой контроль.</hero>";
        str[24] = "Переведя дух, вы решили продолжить, и вставили колькин член обратно в попку.<br><hero>- Коля, если меня снова понесет останови меня, а то"
                  " Анька проснется,</hero> - нежно прошептали вы ему на ушко и начали ерзать на его члене.";
        str[25] = "На этот раз Колька был уже намного осторожнее и при первых же признаках того, что вы заводитесь сразу сменил позу:<br><npc>- Света ты как"
                  " готова к финальному броску? Я уже вот-вот кончу!</npc><br><hero>- Хорошо, можешь кончить куда захочешь только смотри чтобы я не залетела,"
                  "</hero> - улыбаясь, сказали вы";
        str[26] = "Колька спустил вам прямо в попку, почувствовав горящее семя у себя в заднице вы жалели только об одном: вам сегодня так и не удалось самой"
                  " кончить, но, понимая что это могло опасно закончится, вы смирились.";
        str[27] = "Вы слегка приподняли рукой попку, чтобы Колька видел вытекающую сперму и пробормотали:<br><hero>- Надо завязывать с такими встречами, а то"
                  " они могут плохо закончиться…</hero><br><npc>- Как устоять, когда видишь сестренку с торчащим из киски дилдо?</npc> - хмыкнул Колька,<npc>"
                  "- Ну ладно я пошел да и тебе пора спать.</npc><br><hero>- Сладких снов,</hero> - с этими словами вы нежно поцеловали Кольку и улеглись"
                  " спать.";
        return str[id - 85];
    }
    else if(id >= 113 && id <= 128)
    {
        str[0] = "<hero>- Коля, а кому это ты с утра смс-ки строчишь? Дай-ка я посмотрю!</hero> - вы выхватываете телефон у замешкавшегося брата.";
        str[1] = "Вы взяли мобильник и начали читать вслух:<br>“Мишаня, спорим я уговорю Светку, чтобы она тебе тоже дала?” - прочитав это, вы повернулись.";
        str[2] = "<npc>- Свет, верни мобилу! Я все объясню!<br><hero>- Я, значит, пришла сказать ему, что уладила всё с Анькой, - а он тут собрался меня "
                 "под другого парня подложить?! Ты не охамел ли, а?</hero>";
        str[3] = "<npc>- Светик, Светик, прости, ты не так всё поняла… Мишка сказал, что ты ни за что с ним трахаться не будешь, а я решил с ним на деньги"
                 " поспорить, потом уговорить тебя, а на выйгрошь купить Ане подарок, чтобы ее задобрить…</npc><br><hero>- И на сколько поспорил?</hero> "
                 "- все еще злясь спросили вы<br><npc>-На 10000 рублей...</npc>";
        str[4] = "Неожиданно для себя вы его крепко поцеловали, затем откинули одеяло и начали лизать его член. Коля был в полном недоумении.";
        str[5] = "Облизывая член вы спросили:<br><hero>- Если не хочешь остаться должен своему дружку денег то тебе придется хорошенько постараться</hero>"
                 "<br><npc>- Так ты не злишься?</npc> - с удивлением спросил Колька<br><hero>- Я тут кое что придумала ночью и не знала как тебя об этом"
                 " попросить, а ты мне без вопросов поможешь сам, ну а пока трахни меня меня как следует а то прошлый раз я даже не кончила...</hero>";
        str[6] = "Колька послушно стянул с вас трусики и начал вылизывать вашу задницу язычком.";
        str[7] = "Затем вы перевернулись на спину, расставили ноги и раздвинули пальчиками киску.<br><hero>- Поторопись уже, ты сегодня какой то "
                 "нерешительный!</hero>";
        str[8] = "Колька быстро загнал член в вашу киску и начал усердно работать.";
        str[9] = "Через пару минут Колько вновь почувствовал себя увереннее и взял инициативу в свои руки, перевернул вас на бок и начал двигаться наращивая"
                 " темп при этом поигрывая пальчиком с вашим клитором.<br><hero>- Хорошо, а теперь поработай над второй дырочкой.</hero> - хихикая сказали вы."
                 " Затем встали на колени и подставили задницу.";
        str[10] = "Колька не долго думая загнал в нее свой член и начал неистово долбить.<br><hero>- Коля помедленнее порвешь же.</hero> - тут же завопили вы.";
        str[11] = "Решив что в этой позе ему неудобно, он посадил вас сверху и начал рукой играть с вашей киской.<br><hero>- Ахх.. дда… Ну вот можешь же когда"
                  " захочешь!</hero>";
        str[12] = "Вы снова начали вопить как в прошлый раз, Колька не долго думая перевернул вас на бок.<br><npc>- Света прикуси одеяло не то родителей "
                  "разбудишь своими визгами!</npc><br><hero>- Ахх… хорошо.. тока еби меня, не останавливайся!</hero> - и прикусили одеяло.";
        str[13] = "Вы и извивались как змея, если бы не одеяло родителеи бы точно услышали вас. Наконец вы кончили. Заметив это Колька вытащил член и поднес"
                  " к вашему лицу.<br><npc>- Светик, открой ротик!</npc><br><hero>- Не сегодня кончай на лицо я все равно щас в душ.</hero> - но при этом все "
                  "равно немного приоткрыли ротик и высунули язычок.";
        str[14] = "Колька смачно обкончал ваше личико при этом попав и в слегка приоткрытый ротик. Вы явно были довольны таким началом дня.";
        str[15] = "Затем облизав сперму около рта вы уселись поэротичнее и начала рассказывать, что вы хочете от Кольки:<br><hero>- Слушай я тут подумала "
                  "ночью наверно нам стоит убедить Аню присоединится к нашим забавам.</hero><br><npc>-Света, ты что хочешь что бы я Аньку трахнул?</npc>"
                  "<br><hero>- А что девка она симпатичная небось сам не раз об этом мечтал!</hero><br><npc>- Ну …</npc> - Колька слегка опешил.<br><hero>"
                  "- Да не ломайся, я ее подготовлю.</hero><br><npc>- Ладно, но сначала тебе надо решить проблему с Мишкой он долго ждать не будет."
                  "</npc><br><hero>- Я сама к нему не пойду! Пусть к нам приходит когда родителей дома не будет.</hero><br><npc>- Блин, Света, и что"
                  " мне ему сказать ”Приходи к нам, Света тебя хочет трахнуть?”</npc><br><hero>- Ты главное его к нам приведи под любым предлогом, а "
                  "дальше я сама разберусь.</hero><br><npc>- Ладно я его в Хbox поиграть позову.</npc><br><hero>- Ну вот и молодец!</hero> - с этими"
                  " словами вы встали подняли трусики затем выглянули за дверь и огляделись думая при этом, что надо будет <b>заглянуть в зал часа "
                  "в 4 может колька приведет друга..</b>";
        return str[id - 113];
    }
    else if(id >= 129 && id <= 152)
    {
        str[0] = "Вы заходите в зал и видите, что Колька и Миша сидят и в режутся в какую-то игру.<br><npc>- А, Света! Заходи! Помнишь Мишу - мы с ним в"
                 " кафе познакомились, когда победу в городском турнире по футболу отмечали?</npc><br><hero>- Разве такое забудешь? Привет, Миш,</hero>"
                 " - улыбнулись вы.";
        str[1] = "Вы уселись на диван, а парни продолжили играть, не обращая на вас особого внимания.<br><hero>- Во что играете?</hero><br><npc>- В гонки"
                 "</npc> - пробурчал Коля, словно уже забыл - зачем на самом деле приглашал Мишу.";
        str[2] = "Недолго думая, вы положили свою руку Мише на пах:<br><hero>- Мишань, а может поиграем во что-нибудь более взрослое?</hero><br><npc>"
                 "- Что?</npc> - с замешательством в голосе покосился Миша.";
        str[3] = "Решив не объяснять - что вы от него хотите, вы молча извлекли его член из штанов и наклонившись, лизнули.<br><npc>- Мы же не одни, Светик!"
                 "</npc><br><hero>- Не переживай, щас мы его спровадим.</hero>";
        str[4] = "Вы оглянулись на Кольку: тот уже, забыв про игрушку, глядя во все глаза на вас, вовсю наяривает член.<br><hero>- Коля! Может свалишь отсюда"
                 " ненадолго?</hero><br><npc>- Ммм… а может… это... Может, мы вдвоём тебя… того?<br>- Колян! Она ж твоя сестра, ты чё!</npc>";
        str[5] = "<hero>- Коль! Ты с ума сошел - такое предлагать? Вообще что-ли мозгов нет?!</hero> - сделав гневное лицо, вы вышли в коридор, надеясь что"
                 " Мишаня ничего не заподозрит.";
        str[6] = "Присев на столик посреди комнаты, вы, задрав маечку, берёте собственные грудки так, чтобы Мишаня отлично их рассмотрел.<br><hero>- Мишань,"
                 " да я и не против! У нас с ним это не впервой. Но не вздумайте проболтаться кому! Пусть это останется между нами, хорошо?</hero> - пацаны"
                 " яростно кивают в ответ.<br><npc>- Светик, я думал - ты вся такая недотрога, а ты оказывается очень даже современная девушка! Я таких очень"
                 " люблю!</npc> - осклабился Мишаня.";
        str[7] = "Парни подошли поближе: вы по-хозяйски взяли их за торчащие “орудия”. Первым вы решили уделить внимание уже знакомому на вкус члену брата."
                 " Затем пришло время открывать новые для себя вкусы и вы переключаетесь на Михаила.<br><npc>- Колян, это ты её научил так сосать? Она не"
                 " хуже моей бывшей, которая в порно снималась, на флейте играет!<br>- Это уж сам у неё спроси,</npc> - Кольке явно сейчас не до ответов на"
                 " вопросы<npc>- где и с кем она так насобачилась! Я свечку не держал!</npc>";
        str[8] = "Миша, обойдя вас, отодвинул трусики и вы почувствовали его пальцы у себя в киске. От сладкого ощущения вы чуть рефлекторно не прикусили"
                 " Колькин агрегат.<br><npc>- Светик, да ты уже мокрая как лужа!</npc>";
        str[9] = "<npc>- А это что у нас тут?</npc> - ваши трусики съезжают вниз и вы чувствуете вдруг Мишанин язык, вылизывающий колечко ануса. Он ясно "
                 "даёт вам понять - чего ему хочется.<br><npc>- С такой попки грех не начать!</npc><br><hero>- Обычно я люблю чтобы меня спереди разогрели,"
                 " но раз уж ты мне задницу смазал - то ладно. Только не спеши!</hero> - на секунду выпускаете вы изо рта Колькин член.";
        str[10] = "Миша осторожно входит в вашу задницу и начинает медленно двигаться.<br><npc>- Попка что надо! Не узкая и не раздолбаная, а прям в самый"
                  " раз!</npc><br><npc>- Думаю это ненадолго</npc> - усмехнулся Колька.";
        str[11] = "Через пару минут уже Колян буравил вашу задницу при этом присосавшись к груди, что еще больше вас возбуждало.<br><npc>- Светик, как "
                  "насчёт двойного удовольствия?</npc> - поинтересовался Мишка, явно намекая, что тоже хочет присоединиться к Коляну.";
        str[12] = "Вы, почти уже теряя сознание от наслаждения, только кивнули. Коля переместился в вашу “главную дырочку”, а Мишаня пристроился сверху"
                  " к попе.";
        str[13] = "Ребята начали осторожно двигаться постепенно наращивая темп. К вашему удивлению вам это ужасно понравилось.<br><hero>- Охх… дааа! "
                  "Давайте, мальчики! Оххх… Как в раю!</hero> - ощущение асинхронно двигающихся в вас поршней, почти соприкасающихся промеж собой через"
                  " тоненькую перегородочку, доставляет чумовые ощущения и заводит до искр в глазах.<br><npc>- И там тебя трахнула толпа ангелов!</npc>"
                  " - съязвил Колька.";
        str[14] = "Чутка притеревшись, парни вас перевернули теперь уже Колька буравил ваш зад, а Миша наконец добрался до вашей щёлки.<br><hero>"
                  "- Ваши члены как будто специально подгоняли под меня…</hero> - пыхтите вы,<hero>- я раньше никогда так быстро не кончала!</hero>";
        str[15] = "С этими словами вас застрясло. Заметив это Колька остановился, но Миша лишь схватил вас за грудь и начал наращивать темп.<br>"
                  "<hero>- Миша-а-аа, остановии-и-иись, хвааатит!</hero> - извиваясь и пытаясь соскочить с членов парней завопили вы, задыхаясь "
                  "от волн оргазмов, накатывающих один за другим.<br><npc>- Расслабься, Светуля, я знаю, что делаю.</npc>";
        str[16] = "Секунд через десять Миша остановился и дал вам слезть. Вы кое-как отдышались и неожиданно ощутили что возбуждение после оргазма "
                  "никуда не пропало.<br><npc>- Ну как, Светик, хочется добавки не так ли?</npc> - широко улыбаясь сказал Мишка.<br><hero>- Ещё сильнее"
                  " чем прежде! Что ты со мной сделал, негодник?</hero> - изумились вы. Улегшись на стол, вы ухватили Колькин член, а Миша в этот раз "
                  "решил начать второй подход к вашей норке.";
        str[17] = "<npc>- Этому меня научила бывшая подружка из порнобизнеса.</npc><br><hero>- Колька! Учись, оболтус, как надо - потом мы с тобой "
                  "попрактикуемся</hero> - взмыленно выдыхаете вы.<br>А Миша тем временем снова принялся за ваш зад.";
        str[18] = "Спустя минуту вы уже не хотели выпускать Мишку из себя, хоть и пришла очередь брата.<br><npc>- Света, вставай: моя очередь!</npc> "
                  "- Колька как-то даже обиженно засопел.<br><hero>- Колюшка, солнышко, я всегда твоя! Но сегодня у Миши приоритетный вход</hero> "
                  "- вы повыше приподняли попку. Мишка засмеялся и вогнал член в вашу киску.";
        str[19] = "Наигравшись с вашей киской, Миша снова пристроился к попе, а Колька всё бурчал недовольно, что ему тоже хочется.<br><npc>"
                  "- Мишань, ну ты давай там кончай уже! Я тоже присунуть ей хочу!<br>- Светик, куда тебе спустить? В задницу? В ротик? А может ты "
                  "на таблетках я и в пизденьку тогда могу?</npc><br><hero>- Я предпочитаю в ротик!</hero>";
        str[20] = "Колька наконец то добрался до вожделенной дырочки и начал неистово вас долбить, словно навёрстывая упущенное и вас тут же накрыл "
                  "очередной оргазм, а Мишка засунул член вам в рот.<br><npc>- Свет, я уже почти готов!..</npc>";
        str[21] = "Через несколько секунд вы почувствовали горячую сперму у себя во рту.<br><npc>- Ай да Светик! Хороша почти как моя бывшая!</npc>"
                  "<br><hero>- Ну не наглец ли?</hero> - возмутились вы полушутя:<hero>- Нет бы сказал: “Лучше моей бывшей!”</hero><br><npc>"
                  "- Светка, до моей бывшей тебе ещё попрактиковаться надо малость. Хочешь - могу дать пару уроков?</npc> - ухмыльнулся Миша.";
        str[22] = " В это же время Колька вытащил член и кончил вам на живот.<br>Миша вышел из ванной и засобирался.<br><npc>- Мне надо бежать: "
                  "время поджимает - почти час с тобой кувыркались.</npc><br><hero>- Ох, щас уже родители домой вернутся! Нам тоже пора заканчивать,"
                  " Коль.</hero> - вы принялись приводить себя в порядок.<br><hero>- Машань, а ты ещё к нам заходи когда родителей дома не будет.</hero>"
                  "<br><npc>- Обязательно зайду!</npc> - убегая, сказал Мишка.<br><hero>- Коль, ты не подумай чего! Я просто Мишку соблазняла: "
                  "он мне для плана с Анькой пригодится. Ты не хуже его трахаешся, чуть опыта поднаберёшься - и можно в порно идти!</hero>"
                  " - вы нежно и многообещающе целуете брата. Кажется, все его обиды тут же забыты.";
        str[23] = "<hero>- Ну что. Ты теперь богаче на десять тысяч, а я опытнее на одно двойное проникновение</hero> - захихикали вы.<br>"
                  "<npc>- Не очень-то и смешно</npc> - угрюмо буркнул Колька.<npc>- Обидно, знаешь ли, было.</npc><br><hero>- Был бы ты девушкой "
                  "- ты бы меня понял! Да и это, не забывай, мы теперь на шаг ближе к моему плану: скоро у тебя будет богатый выбор, а не одна я.</hero><br><npc>- Не сцы! Я молодой, мне сил на обеих хватит и ещё на пятерых останется!</npc> - взбодрился Колька.<br><hero>- Ладно, я в душ побежала, а то родичи придут - а я тут вся в в ваших головастиках измазанная</hero> - с этими словами вы направляетесь в ванную, уже прокручивая в голове следующую часть плана:<b>теперь вам нужно застать Аньку на кухне после полуночи.</b>";
        return str[id - 129];
    }
    else if(id >= 153 && id <= 173)
    {
        str[0] = "Зайдя в зал, вы увидели, что там сидит Мишка и рубится в гоночки:<br><npc>- Аа, Светик, иди со мной поиграй, а то Колян куда-то отошел."
                 "</npc><br><hero>- Приветик, ну давай, правда, я не очень хорошо играю,</hero> - вы сели рядом и включились в игру.";
        str[1] = "Немного погоняв, Мишка понял, что ваши навыки игрока стремятся к нулю.<br><npc>- Светуля, может поиграем в игры которые тебе даются лучше?"
                 "</npc> - с этими словами Мишка стал вас целовать.";
        str[2] = "Затем он спустил вашу маечку и начал облизывать груди.<br><hero>- Да такие игры мне больше по душе,</hero> - со вздохом наслаждения"
                 " пробормотали вы.";
        str[3] = "Вдруг вы почувствовали, что кто-то схватил вас за другой сосок. Вы были так увлечены ласками Миши, что даже не заметили как Колька "
                 "подкрался к вам:<br><hero>- Колька, негодник! Я тебя даже не заметила!</hero>";
        str[4] = "Колька улыбнулся и начал гладить ваше обнаженное тело, а Миша расстегнул ваши джинсы и запустил свою руку вам в трусики вы почувствовали"
                 " как его рука стала гладить ваш лобок, горячая волна возбуждения прокатилась по вашему телу.<br><hero>- Ну, раз вся команда в сборе, "
                 "то пожалуй пора начинать нашу игру,</hero> - кокетливым голосом воскликнули вы.";
        str[5] = "Через несколько секунд Колька уже лежал на диване, надрачивая свой член одной рукой, а другой ласкал вашу грудь, Миша же спустил с вас"
                 " джинсы, затем приспустил трусики и начал рассматривать вашу упругую попку.";
        str[6] = "Вы с энтузиазмом начали обрабатывать Колькин член, когда почувствовали что Мишка трахает вашу киску своим пальцем.<br><npc>- Мокренькая,"
                 " как и всегда! Светуля, ты похоже нимфоманка. Всегда рада гостям,</npc> - хмыкнул Мишка, <npc>- Тебе с такой жаждой траха внутри самое"
                 " место в порнобизнесе.</npc>";
        str[7] = "Как только Миша наигрался с вашей дырочкой, вы тут же уселись на корточки и начали работать сразу с обоими инструментами парней, то"
                 " полизывая, то посасывая их и поочередно и оба сразу.<br><npc>- Я бы тоже в порно пошел,</npc> - пробормотал Колька, <npc>- особенно"
                 " если там все так сосут как Светик.</npc>";
        str[8] = "Вы, оторвавшись от членов ребят, сказали:<br><hero>- Коля там не болтать надо, а работать,</hero> - вы легли на диван и призывно "
                 "раздвинули ноги, <hero>- А раз хочешь туда попасть начинай тренироваться прямо сейчас, на мне!</hero><br><npc>- Да это мы запросто</npc>"
                 " - Колька вогнал свой инструмент в вашу киску и начал в ней двигаться.<br><npc>- Светик, а моим-то красавчиком забыла заняться?</npc>"
                 " - ухмыльнулся Мишка.<br><hero>- Ой, прости! Действительно забыла!</hero> - улыбнулись вы и начала работать с Мишкиным агрегатом ротиком"
                 " и ручками.";
        str[9] = "Увлекшись Мишкиным членом вы почувствовали как Колькино хозяйство покинуло вашу писечку. Вы уже хотели было возмутится, но тут "
                 "почувствовали, что он входит в вашу попку.<br><npc>- Светик, а давай представим что мы в порно снимаемся!</npc> - захихикал Колька.<br>"
                 "<npc>- Точно! Крутая идея!</npc> - поддержал Мишка. <npc>- Света, ну-ка покажи свои прелести зрителям.</npc>";
        str[10] = "Это предложение вас вдохновило. Представив себя порноактрисой, вы раздвинули свою писечку, чтобы всем предполагаемым зрителям было "
                  "ее видно, возбудившись еще сильнее.<br><npc>- Вау, Светик, да ты прирожденная порнозвезда!</npc> - восхитился Мишка.";
        str[11] = "Через минутку парни поменялись местами, теперь уже Мишкин член терся внутри вас, а вы обрабатывали Кольку.<br><npc>- Света, да ты "
                  "течешь рекой, в натуре!</npc> - отметил Мишка, услышав звуки хлюпанья от своих движений.<npc>- Это тебе так понравилось когда тебя "
                  "Колька в попку трахал или же от мысли, что на тебя будут смотреть миллионы людей?</npc>";
        str[12] = "С этими словами Мишка переключился на вашу попку, ощутив его елдак, плотно заполнивший задний проход, вы ненадолго выпустили изо рта"
                  " член брата и томно вздохнули:<br><hero>- Меня и то, и другое заводит, Миш! Давай глубже! Протрахай меня как в кино!</hero> - "
                  "восторженно сказали вы, и вновь страстно заглотили ждущий вас горячий шланг.";
        str[13] = "Хорошенько продрав вашу задницу, Мишаня снова вернул вас в руки брата. Тот поставил вас раком и вы почувствовали его напряженной кол "
                  "внутри себя - не то что бы вам это не нравилось, но вы почувствовали что парни крутят вами как куклой, передавая по очереди друг другу.";
        str[14] = "Наигравшись с вами, Колька передал инициативу Мишке, тот усадил вас сверху на свой член. Вы было подумали что наконец дождались этого"
                  " момента “двойного удовольствия” - то ради чего с подспудным предвкушением ждали каждый день появления Мишки. Но Колька снова вернул "
                  "свой шланг вам врот.<br><npc>- Сестренка, поработай с моим суперменом,</npc> - попросил братец.<br><hero>- Коля</hero> - освобождая"
                  " свой рот сказали вы, <hero>- хватит филонить, твоя сестренка хочет вас обоих.<br><npc>- Светик, ты не забыла что мы вроде как в"
                  " порнофильме? Что ты должна сказать зрителям? </npc>- напомнил вам Мишка.<br><hero>- Трахните меня в обе дырочки!</hero> - с восторгом"
                  " завопили вы, поддерживая игру.";
        str[15] = "И вот, наконец-то вы ощутили как второй член вошел в вас и начал двигаться внутри, пробуриваясь все глубже. Не прошло и минуты под "
                  "двойными яростными ударами, как волны оргазма стали накрывать вас, слегка потряхивая и заставив забыть обо всем.<br><hero>- Айи-ии, "
                  "да-а-а, божечки, еще, сильнее, продолжайте, ууууух!</hero> - замычали вы, мотая головой.<br><npc>- Блин, Светик, да ори ты потише,</npc>"
                  " - мощно отдупляя вашу задницу пробормотал брат,<npc> - кончила, что ли?</npc><br><hero>- Уммм,</hero> - только и смогли простонать вы.";
        str[16] = "Парни перевернули вас, кидая как неваляшку, и поменялись на дырках. Вы радостно раздвинули ягодицы:<br><hero>- Ну же, ну же, мальчики,"
                  " желаю вам кончить так же круто как и я!</hero>";
        str[17] = "<npc>- Ооох, бли-н блинский, Светик, в ротик, как настоящая актриса, давай, я уже сдерживаться не могу!</npc> - Миша опустил вас на "
                  "корточки перед диваном и сунул в рот подрагивающий, готовый выстрелить елдак.";
        str[18] = "<npc>- Вот так, уй, быстро-быстро, принимай на язычок! ...Фу-ух, вот еще последние капли.</npc><br><hero>- Что, глотать и облизываться,"
                  " как девчонки в фильмах, да?</hero> - рассмеялись вы, <hero>- Ну ладно!</hero>";
        str[19] = "<npc>- А теперь у меня, давай, сеструха,</npc> - сдавленно простонал Коля и разрядился туда же.<br><hero>- Мняяя, вот, проглотила!</hero>";
        str[20] = "Вы довольно облизали остатки спермы с заляпанного лица, снимая их пальчиком:<br><hero>- Все, конец фильма, я пошла приводить "
                  "себя в порядок, а то чего-то плохо соображаю уже.</hero>";
        return str[id - 153];
    }
    else if(id >= 174 && id <= 183)
    {
        str[0] = "Вы заходите на кухню и вдруг обнаруживаете там вашу сестру, роющуюся в холодильнике.<br>“Чего это она не спит? Ага, вот кто холодильник"
                 " тайком опустошает!, впрочем я так и думала”.<br><npc>- Пи-и-ироженка,</npc> - шепчет Аня и облизывается.<br>Кажется, она забыла обо всем"
                 " на свете кроме еды.";
        str[1] = "<hero>- Вот ты и попалась!</hero> - торжествующе говорите вы, делая вид, что схватили воришку.<br><npc>- Света! Фух, ну ты меня и напугала!"
                 " А я это... тут так... зашла...</npc><br><hero>- Ты же говорила, что на диете?</hero><br><npc>- Ну да.</npc><br><hero>- Просила меня следить,"
                 " не давать тебе обжираться.</hero><br><npc>-П-просила.</npc><br><hero>- А сама жрешь на ночь?! Смотри, пузико уже растет!</hero><br><npc>"
                 "- Я не толстая!</npc>";
        str[2] = "<hero>- Аха-ха, ну это пока! Ладно, рубай сколько влезет по ночам, а утром делай вид, что опять на диете. Я больше не буду париться.</hero>"
                 "<br><npc>- Свет, ну ладно, чо ты, я же чуть-чуть...на меня не влияет, я и так красивая.</npc><br><hero>- Ну ничего так, ну-ка повернись."
                 "</hero>";
        str[3] = "<hero>- Задница-то уже ого-го!</hero> - вы провели по заду Ани рукой, почувствовали возбуждение и желание продолжать. Сжали вполне упругие"
                 " и красивые ягодицы.<br><npc>- Ох, что ты делаешь...Света! Я вообще-то зашла заесть напряг...ну там, понимаешь? Давно секса уже с Рексом"
                 " не было...а ты еще меня заводишь!</npc><br><hero>- А может я тоже хочу?</hero> - игриво спросили вы, продолжая обнимать сестру, "
                 "<hero>- Давай поможем друг другу сбросить напряжение.</hero><br><npc>- Ну, я не лесба, да и ты вроде…</npc><br><hero>- А кто говорит про"
                 " лесбийство всякое? Не лесби. А еще не толстая. И красивая.</hero>";
        str[4] = "<npc>- Ох, хрен с ним,</npc> - Аня неожиданно приникает к вам, сливая губы в жарком поцелуе.<br><hero>- Да-да-да,</hero> - шепчете вы "
                 "ей, обнимая за талию, <hero>- мы быстро и тихонько, тебе понравится.</hero>";
        str[5] = "Вы стянули с сестры трусики и облизали открывшиеся соблазнительные формы. Она тяжело задышала и вы ощутили как ее горячее тело податливо"
                 " откликается на ваши ласки.";
        str[6] = "Вы усадили Аню на стол и так усердно заработали язычком в ее киске, особое внимание уделяя клитору, что девушка едва не вскрикнула от "
                 "быстро накатившего наслаждения.";
        str[7] = "<hero>- Давай, Ань, теперь твоя очередь!</hero> - вы взгромоздились на столешницу и уселись на корточки, раздвинув ноги.<br><npc>- Так,"
                 " Свет? Тебе хорошо?</npc> - сестра стала интенсивно водить языком по вашему разбуженному бугорку страсти.<br><hero>- Да-а, помедленнее,"
                 " оух… еще, главное не останавливайся!</hero><br>Вы притянули голову Ани к своему паху и стали двигать ей в нужном ритме. Вскоре слегка "
                 "запретное и оттого еще более сладкое удовольствие довело вас до высшей точки и вы со стоном оргазмировали.";
        str[8] = "<npc>- Уммм, так здорово,</npc> - целуя вас, крепко прижав к себе, пробормотала Аня, после того как вы обе кончили,<npc>- я и не думала…"
                 "</npc><br><hero>- Надо почаще такое устраивать,</hero> - хихикнули вы.<br><npc>- Ладно, время от времени неплохо. Хотя я больше крепкий"
                 " мужской член в себе люблю. Да Рекс в последнее время…</npc><br><hero>- Что, проблемы? Могу помочь. Не отходя от кассы, ха-ха.</hero>"
                 "<br><npc>- Это каким же образом?</npc><br><hero>- Да есть кандидатура помощника. Ближе чем ты думаешь,</hero> - лукаво посмотрели"
                 " вы на сестру,<hero>- только надо отбросить некоторые предрассудки. С этим у тебя, смотрю, нормально получается.</hero><br>Аня покраснела,"
                 " но продолжила ласкаться и улыбнулась:<br><npc>- Кажется, я знаю кого ты имеешь в виду. Не слепая. Но это...даже не знаю. Может, слишком?"
                 "</npc><br><hero>- Да нормально!</hero> - вы погладили сестру по груди и снова жарко поцеловали.";
        str[9] = "<npc>- А теперь давай съедим пироженку! Калорий-то много потратили!</npc> - Аня вытащила из холодильника вкусняшку и разделила ее с вами."
                 "<br><hero>- Пойдем теперь баиньки, тебе завтра на работу. А над очевидным решением проблемы все же подумай,</hero> - решительно заявили"
                 " вы.<br><npc>- Ладно, всё может быть. По-крайней мере, таскаться далеко не надо. Да и родня мы только наполовину.</npc><br><hero>"
                 "- Во-о-от, точно!</hero><br><b>Надо бы сообщить брату хорошую новость поймаю его на кухне часиков в 6 утра</b> - подумали вы";
        return str[id - 174];
    }
    else if(id >= 184 && id <= 200)
    {
        str[0] = "Решив перекусить пораньше, вы варите диетическую кашу - ведь вам надо следить за фигурой и не есть что попало. Каша почти готова и в "
                 "этот момент на кухню заходит Колька.<br><npc>- Светик, доброе утро! Что готовишь?</npc><br><hero>- Приветик! Кашу варю! Будешь?</hero>"
                 "<br><npc>- Буду,</npc> - улыбнулся Колька.";
        str[1] = "Положив кашу по тарелкам, вы уселись завтракать:<br><hero>- Коля, я как раз после завтрака хотела к тебе зайти, сообщить новость.</hero>"
                 "<br><npc>- Какую еще?</npc> - с недоумением посмотрел на вас Коля<br><hero>- Ну как же: ты, я, Аня! Забыл, что ли? Ну так вот: она "
                 "согласна! Вроде как. Если ты сам не лоханешься. Так, что заходи к нам вечерком!</hero><br><npc>- Вот это новость! Не ожидал, что "
                 "Анька на такое пойдет!</npc>";
        str[2] = "Колька ликующе улыбнулся и нежно взял вас за руку<br><npc>- Света, ты правда этого хочешь?</npc> - спросил он серьезно.<br><hero>"
                 "- Конечно! Мы тут развлекаемся, а у нее с Рексом проблемы, какая же я тогда сестра, если не помогу ей!</hero><br><npc>- Тогда хорошо!"
                 " Я к вам обязательно загляну.</npc><br><hero><b>- После 22 заглядывай в воскресенье, а то утром мы в магазин пойдем часиков в 9.</b></hero>";
        str[3] = "С этими словами Колька страстно вас поцеловал<br><npc>- Свет, а может отметим это дело как надо?</npc>";
        str[4] = "<hero>- Коль, нам обоим собираться надо, а после этого мне опять в душ идти, я тогда точно опоздаю…</hero><br><npc>- Ну ладно, тогда в"
                 " другой раз…,</npc> - с сожалением произнес Колька.";
        str[5] = "Колька встал из за стола и подошел к вам, начал целовать и обниматься. Вы почувствовали как ваша майка поднимается вверх, а затем ощутили"
                 " Колькину руку, сжимающую вашу грудь.<br><hero>- Коля, подожди секунду, надо все убрать со стола,</hero> - с этими словами вы поднялись и"
                 " стали прибираться.";
        str[6] = "Прибравшись, вы оба разделись и братец уложил вас на стол.<br><npc>- Сестренка, раздвигай-ка ножки, я тебя языком порадую для начала,"
                 "</npc> - Коля исследовал вашу трепетную писечку пальцами и стал ее вылизывать. Вы отдались блаженству, вскоре почувствовав палец, "
                 "поигрывающий в вашем заднем проходе.<br><hero>- Ухх.. Как классно!</hero> - от этих действий по вашему телу побежали мурашки возбуждения.";
        str[7] = "Поиграв с вашими дырочками, Колька сам возбудился так, что ему не нужна была дополнительная обработка, он встал и вошел в вашу киску.<br>"
                 "<hero>- Колька, ты сегодня окреп даже без моего участия!</hero> - вы положили руку себе на грудь и начали ее ласкать.";
        str[8] = "<npc>- Да от одной мысли про вас с Анькой вдвоем у меня дикий стояк! Надеюсь, ты не злишься?</npc> - Колька переместил свой инструмент в"
                 " вашу попку и, приподняв ваши ноги, свел их вместе.";
        str[9] = "<hero>- Конечно, нет! Меня и саму эта мысль сильно заводит!</hero> - Колька радостно прыснул, поняв что ваши желания совпадают. Он развел"
                 " ваши ноги в сторону и начал рассматривать вашу писечку.";
        str[10] = "Затем он поднес руку к вашим вторым губкам, раздвинул их, потом сжал и снова раздвинул. Он продолжал повторять это движение, пристально"
                  " глядя на вас. Вас охватил жар, и вы почувствовали как ваши соки вытекают наружу.<br><npc>- Похоже, моей сестренке это нравится!</npc>"
                  " - с победной ноткой произнес Колька.<br><hero>- Конечно, дурачок, ты же играешься с моей эрогенной зоной,</hero> - сквозь вздохи "
                  "пробормотали вы.";
        str[11] = "Присев на стул, брат посадил вас сверху на свой инструмент и снова начал играть рукой с вашей киской. Вы поняли что больше не сможете"
                  " сдерживаться, вас затрясло и из вашей дырочки потекли еще более обильные соки. Оргазм накрыл вас с головой, а Колька все не "
                  "останавливался<br><hero>- А-ах, Колечка, остановись, дай дух перевести,</hero> - завопили вы, ловя ртом воздух.";
        str[12] = "Он остановился и дал перевести вам дух. Вы, опершись на стол, сказали:<br><hero>- Фуу-ух, это было суперкруто! Но я еще готова можем"
                  " продолжать!</hero><br><npc>- Как скажешь, сестренка,</npc> - Коля вновь легко проскочил в вашу норку, что было и неудивительно - она"
                  " промокла насквозь.";
        str[13] = "Через минуту Колька снова сменил дырочку:<br><npc>- Светик, я почти готов! Куда ты сегодня хочешь?</npc> - ухмыльнулся Колька<br><hero>"
                  "- Обкончай мою попку!</hero> - все еще слегка задыхаясь, попросили вы.";
        str[14] = "Вы почувствовали как его член покинул вашу задницу, а затем почти сразу же по ней потекли горячие струйки его семени.<br><npc>- Аух, "
                  "чотко-о!</npc> - сдавленно простонал Николай, разрядившись.<br><hero>- Пыщь-пыщь, пиу-пиу, как в твоих игрушках на приставке,</hero>"
                  " - рассмеялись вы.";
        str[15] = "Вы уже было собирались вставать, как вдруг Колька резко всунул свой член обратно. Это было для вас весьма неожиданно, но крайне "
                  "приятно. Ваша норка снова потекла.<br><npc>- О, да-ааа, хоть бы никогда не вынимал!</npc>";
        str[16] = "Закончив свое дело, брат приподнял вас и нежно поцеловал, а вы, ощущая как с вас стекают обе жидкости и капают на пол, почувствовали"
                  " себя на седьмом небе от счастья.<br><npc>- Светуля, ну что теперь в душ?</npc><br><hero>- Ага!</hero> - кивнув головой сказали вы."
                  "<hero>Только я тут мигом уберу...ммм, всякое,</hero> - вы хихикнули и подмигнули:<hero>- Готовься к встрече с обеими сестрами, держи"
                  " себя в форме, футболист!</hero>";
        return str[id - 184];
    }
    else if(id >= 201 && id <= 212)
    {
        str[0] = "Вы, собираясь в школу, зашли в ванную. И увидели как ваш брат Николай принимает душ.<br><hero>- Колечка, ты сегодня рановато!</hero>"
                 "<br><npc>- Оо, вообще-то я тебя и ждал! Один мой дружок по тебе сильно соскучился.</npc>";
        str[1] = "Колян вышел из душа и с ходу, ласково обняв вашу шейку, подарил жаркий французский поцелуй с язычком.<br><hero>- Уу, неугомонный! Вот"
                 " я же теперь вся мокрая, мне тоже в душ надо!</hero><br><npc>- Так заходи, вместе и примем!</npc>";
        str[2] = "Колян быстро оставил на вас лишь одни трусики, затем затащил в душ. Целуя вашу шею, он добрался шаловливыми пальцами до вашей киски.<br>"
                 "<hero>- Ладно, ладно,</hero>- простонали вы,<hero>- давай только по-быстрому!</hero><br><npc>- Ну-ка в ротик тогда сразу!</npc>- нахально"
                 " заявил Коля.";
        str[3] = "Вы встали на колени и начали облизывать его член.<br><hero>- Я только недавно проснулась, так что тебе придется и мою норку разогреть,"
                 "</hero>- игриво сказали вы.";
        str[4] = "Колька поднял вас, быстро стянул и откинул трусики, затем отодвинул вашу ногу и впился своим язычком в вашу киску.<br><hero>- Ох да, "
                 "как хорошо, братец!... А у тебя все лучше получается!</hero>- ободрили вы.";
        str[5] = "Отлизав куночку, Колян повернул вас лицом к стене и быстро вошел в увлажнившуюся норку, а его рука стала гулять по вашему возбужденному"
                 " телу.<br><hero>- Колька, давай уже к любимой дырочке переходи!</hero>- изрядно возбудившись простонали вы.";
        str[6] = "Колька переместил свой инструмент в вашу попку и стал вгонять его поглубже:<br><npc>- Так и скажи, что хочешь в попку!</npc><br><hero>"
                 "- Я везде хочу! Всегда и во все!</hero>";
        str[7] = "Вы развернулись Николаю и начали его целовать. Он задрал вашу ногу и пристроился поудобнее.<br><hero>- Да! Да! Вгоняй! Обожаю это"
                 " чувство наполненности! Гляди, моя киска уже течет рекой!</hero>- прекратив целовать брата, выпалили вы.";
        str[8] = "Вы рукой стали поигрывать со своей норкой, из которой все сильнее струились соки.<br><hero>- Братец, дай-ка я сама поскачу на твоем"
                 " инструменте!</hero>";
        str[9] = "Вы как можно быстрее оседлали Колькин елдачок и стали неистово на нем прыгать.<br><npc>- Света, с такой скоростью я сейчас кончу!"
                 "</npc><br><hero>- Аааа... и я!</hero>- со стоном ответили вы.";
        str[10] = "Ваша киска вся горела: в тщетной попытке ее остудить, вы пальчиками раскрыли половые губы. Вас тут же затрясло и волны оргазмы"
                  " накрыли с головой, заставив забыться и громко заныть. Как блаженство чуть отступило, вы почувствовали горячую жидкость, выплеснувшуюся"
                  " в ваш задний проход и от этого вы снова оказались на пике.";
        str[11] = "Немного отойдя, вы слезли с члена. В ту же секунду из обоих ваших дырочек потекло.<br><npc>- Светуля, ты просто бомба! - констатировал "
                  "удовлетворенный брат.</npc><br><hero>- Насчет бомбы не знаю, а вот после наших приключений с Мишей кончаю от анала как из пулемета!</hero>"
                  "- рассмеялись вы,<hero>- Ну а теперь надо душ принимать, а то в родители проснутся скоро.</hero>Следующие минут десять вы принимали "
                  "вместе душ, с трудом сдерживаясь от повторного захода.";
        return str[id - 201];
    }
    else if(id >= 213 && id <= 233)
    {
        str[0] = "Вы утром ходили за покупками и теперь решили примерить обновки.<br><npc>- Сестренка нафига мы столько шмоток накупили?</npc> - смеясь,"
                 " спросила Аня.<br><hero>- Да ладно, не часто удается выбраться! Давай лучше мерять!</hero>";
        str[1] = "Вы начали раздеваться, Аня решила вам помочь<br><npc>-Светуля, у тебя соски торчат ты что, уже возбудилась?</npc> - ухмыльнулась Анька<br>"
                 "<hero>- Ага, я уже вся в предвкушении сегодняшнего вечера.</hero>";
        str[2] = "После того как вы разоблачились до трусиков, Аня тоже начала раздеваться, ваши руки сами потянулись к ее обнаженному телу.<br><hero>"
                 "- И все же классная у тебя попка, сестренка!</hero>";
        str[3] = "Раздевшись, Аня начала примерять новое нижнее белье. Вы же не могли оторвать от этого зрелища глаз.<br><npc>-Света, а ты что сидишь,"
                 " тоже примерь!</npc><br><hero>- Ох, засмотрелась на тебя и совсем забыла.</hero>";
        str[4] = "Переодевшись, вы обе подошли к зеркалу. Вы стали водить руками по своему телу и вертеться перед отражением, Аня подошла сзади и обняла"
                 " вас:<br><npc>- Светуля, ну где там наш футболист, ты же ему сказала приходить?</npc><br><hero>- Сказала. Но у меня есть идея чем заняться"
                 " пока мы его ждем!</hero> - ваше новое нижнее белье мгновенно оказалось на полу, а вы сами присели на кровать.";
        str[5] = "Аня тут же оказалась позади вас и начала нежно целовать, а ее рука уже играла с вашей киской.<br><hero>- Анька, ты же не лезби, помнишь?"
                 "</hero> - хихикнули вы.<br><npc>- Нет! Но я слегка изменила свое отношение к этому после нашей встречи на кухне,</npc> - нежно прошептала"
                 " уже горячая девушка вам на ушко.";
        str[6] = "Аня засунула два пальца в вашу киску и начала нежно ими двигать. Стон наслаждения вырвался из вашего рта.<br><hero>- Сестренка, да ты так"
                 " круто делаешь...еще! Я и не знала, что наша нелесби так умеет!</hero><br><npc>- Помастурбируешь с мое - тоже научишься,</npc> - весело"
                 " сказала Аня.";
        str[7] = "<npc>- Оба-на, девчонки, вы тут уже без меня начали развлекаться?!</npc> - услышали вы голос за спиной, Колька зашел как всегда очень"
                 " тихо.<br><npc>- А ты не опаздывай!</npc> - повернув голову, сказал Аня и встала на колени, подставляя свою попку Кольке.";
        str[8] = "Поняв намек, он быстро стащил с Аньки ее кружевные трусики и начал играться пальчиком с ее дырочкой, она не чуточки не смущаясь целовала"
                 " вас, а рукой поигрывала с вашей писечкой.<br><npc>- Аня, я начну с тебя, ты ведь не против?</npc>- решил уточнить Коля.<br><npc>"
                 "- А зачем я подставила тебе свою задницу по-твоему?</npc> - оторвавшись от вашего рта, кокетливо сказала Аня.";
        str[9] = "Колька решил показать себя с лучшей стороны, и медленно вошел в ее норку. Она тут же перестала вас целовать ее глаза округлились, а"
                 " изо рта вырвался стон.<br><npc>- Ох! Большой! Коля поосторожнее… - но, поняв что он знает что делать, Аня вернулась игре с вашей киской.";
        str[10] = "Через минуту Колька уже без стеснения и опаски двигался в ней, благо Аня была еще та распутница и кто знает что побывало внутри нее."
                  "<br><npc>- Ну как, сеструха, тебе нравится?</npc> - приподняв ее и, поигрывая руками с ее грудью, поинтересовался Колька.<br><npc>- "
                  "Ох! Да! Великолепно! Давно надо было такое попробовать!</npc><br><hero>- Я же говорила что ты не пожалеешь, Ань!</hero> - шепнули вы,"
                  " подползая к Ане и крепко ее целуя.";
        str[11] = "<hero>- Теперь моя очередь!</hero> - сказали вы, Аня нехотя слезла с члена, вы тут же запрыгнули на Кольку сверху так, чтобы ваша киска"
                  " оказалась прямо у его рта, а сами начали лизать елдак брата. Вскоре к вам присоединился второй жадный и умелый ротик.<br><hero>"
                  "- Подготовь мою кисулю!</hero> - нежно сказали вы брату и тут же почувствовали как его язычок касается вас.";
        str[12] = "Как только Коля вас разогрел, вы тут же запрыгнули на его инструмент и принялись прыгать в позе наездницы, потирая рукой клитор, что "
                  "еще больше вас возбуждало.<br><npc>- Светик, иди ко мне,</npc> - сидящая рядом сестра начала целовать вас и водить рукой по вашему "
                  "обнаженному телу.";
        str[13] = "Когда наступила очередь Ани, она уже избавилась от хоть и красивого, но ненужного белья и быстро оседлала Кольку.<br><hero>- Анюта, "
                  "а в попку не хочешь?- наклонившись и увидя неплохо разработанное заднее отверстие, спросили вы.<br><npc>- Хочу…</npc>- чуть поколебавшись,"
                  " решилась Аня.";
        str[14] = "Вы взяли рукой Колькин член и начали медленно ввинчивать его в Анину попочку.<br><hero>- Вау, да он как тут и был, вошел почти без "
                  "сопротивления!</hero><br><npc>- Я не об этом переживала… Я.. Я.. Мне было неловко в первый же раз просить об этом. Мало чего вы "
                  "подумаете!</npc><br><hero>- Не выдумывай, сестренка! Мы тут все свои! Правда, к нашей компашке можно еще кое-кого добавить, надо "
                  "больше крепких агрегатов, ага?</hero> - вы засмеялись,<hero>- и в обеих дырочках!</hero>";
        str[15] = "Вы снова встали так, чтобы Колька доставал своим язычком до вашей норки.<br><hero>- Коляша, можешь делать два дела разом?</hero> "
                  "- с иронией спросили вы.<br><npc>- Могу и больше!</npc> - восторженно ответил Колька и начал вылизывать вашу киску, не забывая и"
                  " протрахивать Анину попку.<br><npc>- Охх! Божечки! Я сейчас! Ахххх!</npc> - переходя почти на крик, Аня затряслась в оргазме.";
        str[16] = "Давая Ане передохнуть, Колька переключился на вашу истомившуюся по знакомому инструменту попку.<br><npc>- Светик, полижи мою киску,"
                  " я так давно не кончала, что еще хочу как ненормальная,</npc>- попросила сестра и прижала вашу голову к своей промежности.";
        str[17] = "Аня прилегла на кровать. Вы продолжили поигрывать с ее писечкой. Это продолжалось до тех пор пока вы тоже не кончили, ощутив "
                  "мощный импульс анального оргазма. Любуясь на него, Колька как обычно поинтересовался:<br><npc>- Свет, я почти готов, куда ты"
                  " хочешь сейчас?</npc><br><hero>- У меня сегодня для тебя подарочек! Можешь кончить прямо в киску, я сегодня на таблетках.</hero>";
        str[18] = "Колька тут же засунул свой инструмент в вашу дырочку и вы почувствовали как горячая жидкость начала толчками заполнять лоно.<br>"
                  "<npc>- Братишка, оставь и мне немного,</npc> - распутно хихикнула Аня.";
        str[19] = "Она взяла инструмент Кольки и нежно облизала язычком остатки спермы.";
        str[20] = "В финале вы втроем сомкнули языки и облизали друг друга.<br><npc>- Потряс!</npc> - довольно выдал Коля.<br><hero>- Угу,</hero>"
                  "- пробормотали вы,<hero>- хотя я больше люблю в обе щелки, как вы с Мишей меня вертите.</hero><br><npc>- Что еще за Миша?</npc>"
                  " - несколько ревниво спросила Аня.<br><hero>- Да есть такой, можем познакомить,</hero>- вы засмеялись в унисон с братом,<hero>"
                  "- потом, если захочешь, конечно.</hero><br><npc>- Уже хочу!</npc><br>Вы рассказали сестре про Михаила и ваши тройные развлечения."
                  " Коля воодушевленно комментировал, расписывая все в красках.<br><npc>- Блин, я так опять заведусь, все по койкам - спать!</npc>"
                  " - решительно заявила ваша старшая сестричка, затем добавила со смешком,<npc>- При случае подумаем о расширении компании вот "
                  "только как с родителями быть...</npc><br><hero>- Не беспокойся я все улажу</hero>- сказали вы.";
        return str[id - 213];
    }
    else if(id >= 234 && id <= 235)
    {
        str[0] = "<hero>Я тут по магазинам решила пробежаться. Пойдем вместе, вдвоем веселее!</hero><br><npc>- Здорово, погнали, а то я и сама хотела"
                 " по нормальным магазинам пробежаться!</npc>";
        str[1] = "<br>Вы поехали с сестрой в город и прошатались по магазинам до обеда, накупив кучу вещей и всякого сопутствующего барахла.";
        return str[id - 234];
    }
    else if(id >= 236 && id <= 256)
    {
        str[0] = "<npc>- Свет, давай кое-что прикинем. Не зря же столько барахла набрали.</npc><br>Вы усаживаетесь вдвоем на Анькину кровать и начинаете"
                 " прикидывать друг на друга обновки. Близость тел друг друга и постоянные легкие касания слегка заводят вас и явно возбуждают Аню. "
                 "Она слегка краснеет и посматривает на вас заблестевшими глазками с чувственным вызовом.";
        str[1] = "<hero>- Ох, не могу больше, я тебя хочу!</hero> - вы впиваетесь в губы сестры жарким поцелуем.<br><npc>- Умм, кто ж против-то…,</npc>"
                 "- страстно бормочет Аня.";
        str[2] = "Вы нежно раздеваете Аню, покрывая ее тело поцелуями и сами скидываете блузку.<br><hero>- Есть у меня для тебя один сюрприз, сестренка!"
                 "</hero><br><npc>- Ка-кой?</npc><br><hero>- Закрой-ка глаза!</hero>";
        str[3] = "Вы лезете в тайничок и достаете свое тайное оружие - замысловатый фаллоимитатор размером в 20 сантиметров:<br><hero>- А вот какой! "
                 "Можешь полюбоваться!</hero><br><npc>- Вау! Отличная игрушка.</npc>";
        str[4] = "Вы вдвоем принимаетесь облизывать каучуковый дилдак.<br><npc>- Mмм, крепкий какой, не у всякого мужика найдешь,</npc>- бормочет Аня,"
                 " уснащая слюной игрушку,<npc>- спасибо, что заботишься обо мне, сестренка.</npc>";
        str[5] = "Вы укладываете сестру на постель и начинаете играться дилдаком с ее клитором и возить его между быстро увлажняющихся половых губ Ани.";
        str[6] = "<npc>- Встааа-а-авляяяй! Ну же!</npc> - стонет Аня<br>Вы легонечко пропихиваете дилдо в ее киску.<br><npc>- Ооо, как хорошо, трахай"
                 " меня!</npc>";
        str[7] = "Вдруг вы заметили как в комнату зашел Николай, жадно наблюдая за происходящим. Вы подмигнули ему.<br>Аня сначала смутилась и попыталась"
                 " прикрыться.";
        str[8] = "<npc>- А я думаю что за стоны, вы бы уж потише.</npc><br><hero>- Присоединяйся, что стоишь как неродной!</hero> - сказали вы. Сестра"
                 " немного подумала, потом рассмеялась:<npc>- Ладно, иди уж к нам, любовничек!</npc>";
        str[9] = "Коля разделся и запрыгнул к вам на кровать. Аня обняла его, похотливо поинтересовавшись:<br><npc>- Ну что, готов к подвигам, а то я"
                 " вся горю сейчас!</npc><br><npc>- Всегда готов!</npc>";
        str[10] = "Николай достал свое хозяйство, лаская Аню. Она же принялась стаскивать с вас остатки одежды:<npc>- А я Свету буду радовать одной "
                  "ее забавной штучкой.</npc>";
        str[11] = "Вы тут же улеглись на сестру валетиком, подставили промежность и она вставила вам дилдак в киску.<br><npc>- Вот так! Твоя очередь "
                  "на каучук!</npc><br><hero>- Ууу, да-а!</hero> - проныли вы,<hero>- Как же круто!</hero>";
        str[12] = "Пока сестра протрахивала вашу писечку, Коля дал ей в ротик свой вставший инструмент и принялся с восторгом ласкать вашу задницу, "
                  "целуя ягодицы и вставляя пальцы в анус:<br><npc>- Как же я люблю эту попку.</npc><br><hero>- Так трахни меня туда-а!</hero>- "
                  "изможденно потребовали вы.";
        str[13] = "Николай вставил своего солдатика в ваш задний проход и стал медленно им двигать. Аня же ускорила работу фаллоимитатором. Вы замычали"
                  " от двойного наслаждения.";
        str[14] = "<hero>- Уй-яяяаах, кончаю, Коля, крепче вгоняй!</hero>- слегка забывшись завопили вы, вплотную приблизившись к оргазму.<br>"
                  "<npc>- Тише, дурочка,</npc>- в унисон произнесли Аня с Колей и оба рассмеялись.<br>Брат схватил ваши ягодицы и так крепко протаранил"
                  " вашу задницу, что вы разрядились в бурном оргазме, попутно неосознанно пихая пальцы в киску сестры.";
        str[15] = "<hero>- Ооух, это был абсолютный кайф,</hero>- довольно сообщили вы, оборачиваясь и даря брату нежный поцелуй,<npc>- А теперь вторую"
                  " сестру вытрахай!</npc>";
        str[16] = "Коля не заставил себя просить дважды. Аня в свою очередь устроилась валетиком, навалившись на вас разгоряченном телом и вновь вогнала"
                  " вам в киску дилдо.";
        str[17] = "Николай стал увлеченно протрахивать киску тут же сладко застонавшей девушки. Вы раздвинули ей ягодицы, чтобы вгонял поглубже и "
                  "принялись язычком ласкать его яйца.";
        str[18] = "Отлизав яйца брату вы принялись за клитор сестры, которая в полном самозабвении ерзала по всему вашему телу.<br><npc>- Господи, "
                  "ну еще, еще, сей-ча-ас, а да-а, Светуля!</npc>- заныла Аня, дойдя до высшей точки. Сестра пустила обильные соки прямо в ваш широко"
                  " раскрытый рот. Вы радостно облизнулись.<br><npc>- О-х, девчонки, я сейчас тоже кончу!</npc>- сообщил Николай, слегка задыхаясь"
                  " от взятого ритма.<br><npc>- Можешь в меня, я на таблетках!</npc><br>Коля со стоном финишировал в Анину щёлку.";
        str[19] = "Вы раскрыли ей промежность пошире и залюбовались как из сочного лона вытекает поток спермы. Затем вылизали капельки семени.";
        str[20] = "<npc>- Надо почаще такое повторять,</npc>- вся лучась невероятным довольством, пробормотала ваша старшая сестра.<br><hero>"
                  "- Значит, будем!</hero>- уверенно откликнулись вы, и снова взяли в рот головку члена брата,<hero>- уммм...</hero><br><npc>"
                  "- Я только за,</npc> - подтвердил Николай с энтузиазмом, хватая и тиская Анины сисечки,<npc>- Ну скажи, ведь классно, тебе "
                  "так понравилось...</npc><br><npc>- Все, пошел отсюда, как тебя и не было!</npc> - рассмеялась Аня,<npc>- Мы сами решим, когда"
                  " нужен будешь.</npc>";
        return str[id - 236];
    }
    else if(id >= 257 && id <= 263)
    {
        str[0] = "<hero>- Мальчики, я сегодня слегка припозднилась: наряжалась специально для вас,</hero> - сообщили вы, входя в комнату.<br>"
                 "<hero>- Нравится?</hero> - приоткрывая свою грудь, спросили вы.<br><npc>- Светуля, нам не то что на тебе надето, а то что под"
                 " одеждой скрыто интересно,</npc> - слегка хамовато ответил Мишка.";
        str[1] = "<hero>- Ну вот только зря время потратила,</hero> - сбрасывая с себя одежду и вставая на колени, фыркнули вы.<br><npc>- Ты в "
                 "любой одежде и без нее - красивая!</npc> - сказал Колька, пытаясь сгладить углы. Ребята спустили штаны и их члены привычно "
                 "оказались в ваших загребущих ручках. Вы принялись их посасывать.";
        str[2] = "Приведя в готовность инструменты, вы решили больше не тратить попусту время - ведь его у вас сегодня не так много.<br><hero>"
                 "- Так, мальчики, у нас сегодня ускоренный курс! Коля, начинай сразу с попки!</hero>";
        str[3] = "Разогрев вашу попку, Коля уступил место Мишке<br><hero>- Мишань, моя сестра Аня хочет с тобой познакомится. Как ты на это смотришь?"
                 "</hero>- сквозь вздохи спросили вы.<br><npc>- Сестра, говоришь? А она такая же раскрепощенная как ты?</npc> - решил уточнить Миша,"
                 " растрахивая ваш задик.";
        str[4] = "Ребята оккупировали обе ваши дырочки. Вам уже было не до ответов на вопросы. Заметив это, за вас ответил Коля:<br><npc>- Не совсем,"
                 " но мы над этим работаем! Ха-ха, крепко работаем! Вот примерно так!</npc><br><hero>- Ой-иии, да, ух, круто!</hero> - взвизгнули вы."
                 "<br><npc>- Ага, круто! Да я не против познакомиться, но там уж как выйдет,</npc> - ответил Мишка.";
        str[5] = "Парни перевернули вас и продолжили свое дело.<br><hero>- Ахх! Охх! Божечки! Миша, я тебе позвоню когда приходить!</hero> - это "
                 "последнее что вы успели пробормотать перед тем как вас охватили волны оргазма. Потом все мысли окончательно вылетели из вашей головы "
                 "и вы погрузились в безмятежное наслаждение.";
        str[6] = "Вновь и вновь кончая под двойными ударами, вы на миг открыли глаза и внезапно увидели за спиной у Кольки наблюдающего отчима."
                 " Парни ничего не замечали и продолжали разгоряченно двигаться внутри вас, а вы безостановочно оргазмировали не в силах вымолвить"
                 " и словечка. Только стон наслаждения вырвался, наконец, из груди. Отчим стоял все это время пока вы кончали, молча рассматривая "
                 "как вас трахают. Очевидно, он просто наслаждался зрелищем.<br><npc>- Так-так, что вы тут делаете, малолетки отмороженные?! А "
                 "ну-ка марш отсюда!</npc> - перепуганные парни вскочили и начали судорожно одеваться.<br><hero>- А с тобой, проститутка эдакая,"
                 " мы еще поговорим!</hero> - грозным тоном добавил он.";
        return str[id - 257];
    }
    else if(id >= 264 && id <= 271)
    {
        str[0] = "Как и договаривались ранее, вы пришли в зал одевшись как явная распутница. Там вас уже с нетерпением ожидали:<br><npc>- О, Светик, "
                 "как тебе идет наряд шлюхи-то! А теперь: покажи-ка нам свои прелести!</npc> - нагло усмехаясь, сказал отчим.";
        str[1] = "Вы с нарочитым вызовом медленно разделись, встали коленями на столик стоящий посередине комнаты и выставили на обозрение всю "
                 "промежность.<br><npc>- Отлично, ну что, начнем без прелюдий?</npc> - спросил отчим.<br><hero>- Только не сразу два в попку!</hero>"
                 " - хоть вы и смазали ее лубрикантом, вас терзали некоторые сомнения: влезут ли сразу оба?<br><npc>- Пап, предлагаю сперва по одному "
                 "на дырочку.</npc> - сказал Колька.";
        str[2] = "Такая поза для вас была уже привычна, поэтому вы не стали возражать, отчим лег на диван и усадил вас сверху, Колька же занялся вашей"
                 " попкой.<br><npc>- Колька, сынок, разработай ей проход!</npc> - возбужденно просипел отчим, наяривая увлажнившуюся киску.<br>"
                 "<hero>- Только не перестарайся, пожалуйста!</hero> - испуганно попросили вы. Колька вгонял свой инструмент глубоко, но осторожно, "
                 "вы уже привыкли к его размеру раньше, а со смазкой такой заход не доставлял вам неудобств. Постепенно приноровившись к ритму обоих"
                 " родственничков, вы стали все больше возбуждаться.<br><hero>- Думаю, я готова...ну наверно,</hero> - неуверенно произнесли вы, "
                 "между стонами.";
        str[3] = "Вы почувствовали как сначала один, а затем и второй член оказались в вашей попе.<br><hero>- Ай о-ой, не фига ж себе!</hero> - "
                 "вскрикнули вы.<br><npc>- Надо же, влезли!</npc> - изумился отчим.<br><hero>- Можете начинать двигаться, только медленно!</hero>"
                 "- наконец-то решились вы.<br>Поначалу вам было довольно больно и вы поняли, что требуется дополнительная работа с анусом.";
        str[4] = "<hero>- А-ай, бли-ин, постойте, я чуток поспешила, надо еще разработать!</hero> - переводя дыхание, сообщили вы, слегка скривясь от боли."
                 "<br><npc>- Колька, переворачивай ее, щас я ей быстренько жопу разработаю! Дело привычное, кхе!</npc><br><hero>- Эй-эй, только без"
                 " крайностей! Я вам не резиновая!</hero> - завопили вы, когда отчим стал неистово долбить вашу попку, а Коля буравил вашу киску. "
                 "К вашему удивлению, вы не почувствовали ничего, кроме наслаждения.<br>“Отличная марка смазки, еще и обезболивает. Надо такой лубрикант"
                 " всегда теперь брать!” - подумалось вам перед тем, как мысли окончательно вылетели из головы под жаркой волной сладострастия.<br><npc>"
                 "- Все, Светуля, раздвигай свою задницу на полную,</npc> - сказал отчим через пару минут интенсивной долбежки, почти обломав вам весь кайф.";
        str[5] = "Ощутив в своей попке оба инструмента, вы уже было приготовились терпеть неприятную боль, как вдруг поняли что ее нет, члены начали "
                 "движение, а она так и не появилась.<br><hero>- Все хорошо, можете продолжать,</hero> - вы почувствовали как елдаки начали двигаться "
                 "быстрее и быстрее, все глубже проникая в недра ануса.<br>Внутри вашей норки стало так горячо что невозможно было терпеть.<br>"
                 "<hero>- Божечки! Мне в норку как будто залили кипяток!</hero> - вы инстинктивно потянулись рукой к одиноко мокнущей писе и раздвинули"
                 " пошире пальцами, будто это могло ее охладить.<br><npc>- Папань, похоже ей по кайфу, реально!</npc> - воскликнул Колька, любуясь на"
                 " вашу норку.<br><hero>- А-аххх, Д-ДААА!</hero> - только и смогли вы пролепетать, прежде чем вас накрыло волной оргазма.<br><npc>"
                 "- Смотри-ка, она еще и кончила от первой же двойки в попце, а ведь все отнекивалась,</npc> - снимая ваше почти обмякшее тело с членов"
                 " и укладывая на диван, заметил невероятно довольный отчим.";
        str[6] = "Видя, что вы уже приходите в себя, отчим строго покачал пальцем у вас перед носом.<br><npc>- Ну что, сама- то обкончалась как мартовская"
                 " кошка, теперь семье помогай.</npc><br><hero>- Хор-ро-ош-шо,</hero> - с трудом промычали вы, еще не совсем оправившись от столь мощного"
                 " оргазма. Обнаружив, что вы еще не способны на активные действия отчим сунул свой инструмент вам в рот, а Колька примостился к заднице."
                 " Между тем вы потихоньку приходили в себя, начиная вести себя более активно.";
        str[7] = "Полностью оклемавшись, вы присели на корточки, а Коля и отчим по очереди кончили вам в рот. Первым тишину нарушил отчим, с ухмылкой"
                 " разглядывая как сперма стекает по вашему подбородку на сисечки.<br><npc>- Похоже, все остались довольны, а?</npc> - спросил он."
                 "<br><hero>- Я… Я… Мне понравилось,</hero> - наконец определились вы.<br><npc>- Ну вот и замечательно! Можете не переживать, я прикрою"
                 " вас перед матерью, но все равно будьте осторожнее!</npc><br><hero>- Спасибо,</hero> - выдавили из себя вы, а потом неожиданно "
                 "добавили,<hero>- А может это... того... ну вы понимаете!</hero><br><npc>- Вообще-то нет,</npc> - покачал головой Колька.<br>"
                 "<hero>- Коля! Дурак! Ну трахатся я хочу так почаще! Но только мне и другие варианты попробовать интересно…</hero><br><npc>"
                 "- Какие варианты?</npc> - на этот раз недоумевающе спросил отчим.<br>Вы умоляющим взглядом посмотрели на него, в надежде, что вам "
                 "не придется произносить ваши потаенные развратные желания вслух, но он по-прежнему недогонял.<br><hero>- Ну что вы не понимаете что"
                 " ли, после такого я хочу попробовать все! Секс с тремя, с четырьмя! Два члена в норке! И даже три в разных вариациях! Ой, я это "
                 "сказала?!</hero><br><npc>- Ого, ну ты разошлась! Хотя... могу тебе гарантировать что мы с Николаем по выходным тебя может оприходывать..."
                 " в разных позах и вариациях, а дополнительных участников ищи сама.</npc><br><hero>- Правда? Вы точно не против?</hero> - с "
                 "загоревшимися глазами спросили вы.<br><npc>- Да почему бы и нет! Можешь дружка вон своего подтянуть. Ну а пока бегом в душ - мыться,"
                 " а то мать скоро вернется. Чтоб была без малейших следов! И лимон бы неплохо съесть, ха-ха.</npc><br><npc>- Ха-ха-ха,</npc> - "
                 "заржал Колька.<br>“Это что, анекдот? Странный какой-то”, - подумали вы, собирая раскиданные шмотки.<br>Вы вышли из зала и направились"
                 " в ванную думая про себя <b>теперь можно звонить Мишке в пятницу после 10 вечера, сделаю Ане сюрприз.</b>";
        return str[id - 264];
    }
    else if(id >= 272 && id <= 290)
    {
        str[0] = "Вы заходите в зал, истомленная возбуждением с мыслью отдаться.<br>Ваш брат и отчим смотрят какое-то дурацкое шоу.";
        str[1] = "<hero>- Ой, ну сколько можно эту гадость по телеку зырить,</hero>- томно произносите вы с блудливой улыбкой.";
        str[2] = "Вы уваливаетесь на диванчик прямо на отчима:<hero>- Давайте займемся чем-нибудь повеселее!</hero><br>Вас тут же начинают тискать "
                 "за мягкие места. Вы радостно болтаете голыми ножками в воздухе.";
        str[3] = "Папочка с Коляном раздевают вас под кокетливые хихиканья.<br><npc>- Ого, Светик, ну у тебя и румянец! Жаром так и пылаешь!</npc><br>"
                 "<hero>- Мммм, хочу два члена, хочу в каждую дырку, и чтоб быть отодранной круче, чем потаскухи в порно!</hero>";
        str[4] = "Вас зацеловывают и начинают полизывать киску:<npc>- Сочная какая!</npc>";
        str[5] = "Отчим и Колька раздраконивают ваши горячие дырочки пальцами. Вы, раздвинув ноги, блаженствуете и тихо постанываете.";
        str[6] = "Затем жадно всасываетесь в приподнявшиеся члены, наяривая их ручками.";
        str[7] = "Затем жадно всасываетесь в приподнявшиеся члены, наяривая их ручками.";
        str[8] = "Колька впихивает вам елдачок поглубже в рот. Отчим трахает вашу норочку пальцами так, что вы испускаете громкий стон удовольствия.<br>"
                 "<hero>- Аууу, вставляйте уже, не могу!</hero>";
        str[9] = "Брат впендюривает вам агрегат на всю длину и, задрав ножку, лихо долбит:<hero>- Еще, еще, еще-е! Нет, давайте два! Тьфу, я сама все"
                 " сделаю!</hero>";
        str[10] = "Вы устраиваетесь на двух болтах разом в позе наездницы и начинаете как одержимая на них насаживаться:<hero>- Вот так, ваух, толкайте,"
                  " толкайте-е-е поглубжеее!</hero><br><npc>- Ну, доча, ты и затейница,</npc>- посмеивается отчим.";
        str[11] = "Вас дружно харят в вагину парой членов, шоркая с такой страстью, что вскоре неизбежный оргазм прокатывается по всему телу до самых"
                  " пальчиков ног. Вы радостно вопите.";
        str[12] = "Оклемавшись, разводите ягодицы и похотливо лепечете:<hero>- Давайте в обе щели теперь!</hero><br>Отчим хмыкает:<npc>- Погодь, блудодейка!"
                  " Я только что в твою розочку отстрелялся…</npc><br><hero>- Ой, а я и не заметила,</hero>- глупо хлопаете вы глазками и хихикаете.";
        str[13] = "Папочка сует вам елдачину в рот и жестко наяривает, таская за голову:<npc>- На сосочку, кушай, детка!</npc><br><hero>- Умффх!</hero>"
                  "<br>Вы энергично сосете, сладостно мыча и чувствуя как братец продолжает долбать киску.";
        str[14] = "<npc>- А где наша попочка?! На-ка в мою сладкую!</npc>- отчим ввинчивает вам вновь готовый орган в задний проход.<br><hero>- Айиии, "
                  "божечки, да-аа, наконец-то!</hero>- вы выгибаетесь и в экстазе елозите на болтах.<br>Вас крепко чихвостят в оба отверстия.";
        str[15] = "<npc>- Дай-ка я, пап!</npc>- Колька насаживает вас на свой вздыбившийся от возбуждения елдак до самого корня.<br><hero>- Умм-хууу!"
                  " Фкхх.. И в два туда, давайте-давайте! Раздерите задницу, чтоб я кончила еще!</hero>";
        str[16] = "Вам с некоторым трудом протыкают расфаканную попку двумя инструментами и распахивают до самых потрохов.<br><hero>- Йиииих...аааа!</hero>"
                  "- испустив животный вопль, вы буквально плавитесь под лавиной анального оргазма.";
        str[17] = "Брат с отчимом кончают вам в рот, набузгав столько, что вы проливаете на сисечки и животик.<br><npc>- Во ты даешь,</npc>- слегка "
                  "ошарашенно бормочет блаженствующий Колян.<br><npc>- Наша девочка!</npc>- довольно ухмыляется отчим.";
        str[18] = "Вы слизываете и глотаете пролитую сперму, пальчиком собирая ее с тела и таща в рот:<hero>- Умм-ня, это было здоровски! Надо"
                  " повторить!</hero><br><npc>- Все, давай дуй ванную пока мамки нет,</npc>- шлепает вас отчим по заднице, отправляя к двери.<br>"
                  "Вы удаляетесь, нарочито вихляя слегка побаливающей попкой.";
        return str[id - 272];
    }
    else if(id >= 291 && id <= 312)
    {
        str[0] = "Минут через 15 вы услышали звонок в дверь и пошли открывать. Мишка стоял на пороге слегка неуверенный. Вы быстро взяли его за руку"
                 " и потащили в свою комнату.<br><hero>- Миша, а ты быстро приехал.</hero><br><npc>- Говори потише, сестра же спит,</npc> - поднеся "
                 "палец к губам сказал он тихо,<npc>- Да я живу-то рядом, минут пять пешком.</npc><br><hero>- Круто, я не знала! Слушай, давай сестренке"
                 " сюрпризик устроим?</hero><br><npc>- Какой именно?</npc>- решил уточнить Миша.<br><hero>- Давай займемся тем, чем обычно занимаемся "
                 "прямо рядом с ней, она проснется и деваться ей будет некуда!</hero>";
        str[1] = "Мишке явно понравилась эта идея он присел на кровать где спала Аня и начал раздевать вас.<br><hero>- Кстати, как тебе моя сестрёнка?</hero>"
                 " - спросили вы.<br><npc>- Симпатичная! И фигурка что надо!</npc>";
        str[2] = "Избавившись от джинсов, вы тут же запрыгнули Михаилу на колени и стали его целовать, почти сразу же вы почувствовав как его рука "
                 "устремилась к вам в трусики. А затем его пальчик оказался в вашем заднем отверстии.<br><npc>- Света, пока мы не зашли слишком далеко,"
                 " скажи честно, что ты от меня хочешь?</npc>- с прямотой спросил ваш визитер.<br><hero>- Понимаешь, у нее вроде как есть парень, только"
                 " она с ним постоянно ссорится да и кампания у него не самая хорошая… В общем, она когда выпьет развратничать начинает, а они этим "
                 "пользуются.</hero><br><npc>- Ага, теперь понял. Значит, бескорыстная помощь?</npc><br><hero>- Ну, не совсем бескорыстная,</hero> - "
                 "хитро улыбнулись вы и притянули парня к себе.";
        str[3] = "Мишка стянул с вас трусики и положил на кровать рядом сестрой и начал обрабатывать язычком ваши отверстия. Убедившись что Аня все еще "
                 "спит вы продолжили.<br><hero>- Они ее можно сказать за шлюху считают, а ей ей всего лишь внимания хочется ну и крепкого инструмента в "
                 "себе по вечерам…</hero><br><npc>- История старая как мир…</npc>- оторвавшись от вашей промежности произнес Мишка, - и снова вернулся "
                 "к своему занятию.<br><hero>- Так и есть! А ты вроде парень приличный и как бы только рад если девушка развратничать начинает… Ну и ты "
                 "хотя бы с недотрахом помочь можешь сам понимаешь с Колькой-то часто опасно…,</hero>- борясь с нарастающим возбуждением сказали вы."
                 "<br><npc>- Таких красоток как вы я хоть целыми днями насаживать готов! Короче, я тебя понял: твоей сестренке нужен хороший трах как и"
                 " тебе. Это я могу вам обеим устроить!</npc>";
        str[4] = "Миша засунул пальчик в вашу норку вы застонали, а он продолжил радовать вашу киску.<br><hero>- А-ахх, да-а-а,</hero> - простонали вы"
                 " достаточно громко, чтобы сестра проснулась.<br><npc>- Света, какого черта, что ты делаешь на моей кровати? Блин, кто тут еще?!</npc>"
                 " - сказала Аня, поднимая голову.<br><hero>- А, ты наконец то проснулась,</hero> - сказали вы пока ваша сестра ошеломленно наблюдала"
                 " как незнакомый ей парень потрахивает вашу киску пальцем.";
        str[5] = "Вы рассмеялись и повернулись к сестре, Миша как ни в чем не бывало продолжал работать пальцем:<br><hero>- Анют, это Михаил, про "
                 "которого я тебе говорила.</hero><br><npc>- Привет Анют! Мне сказали, что я очень нужен двум красивым девушкам!</npc><br><npc>"
                 "- Привет,</npc> - озадаченно сказала Аня, но затем широко улыбнулась.<br><hero>- Не надо стеснятся!</hero> - сказали вы Ане<hero>"
                 "- Мишка у нас очень понимающий молодой человек. Иди лучше и поцелуй сестрёнку!</hero>";
        str[6] = "Чуть поколебавшись, Аня подползла к вам и начала целовать, Миша же тем временем оккупировал пальчиком вашу попку и начал ее "
                 "разрабатывать.<br><npc>- Аня, расскажи нам, что ты предпочитаешь?</npc>- спросил Мишка.<br><npc>- Предпочитаю?</npc>- оторвавшись "
                 "от ваших губ, с недоумением переспросила она.<br><hero>- Сестрёнка, он хочет знать в каких позах и в какие дырочки тебе больше "
                 "всего нравится!</hero><br><npc>- Светик, я и так поняла!</npc>- покраснев сказала Аня.<br><npc>- Ну хорошо давай начнем с другого,</npc>"
                 " - оторвавшись от вас, и подходя к Ане, сказал Мишка.";
        str[7] = "Затем ее маечка быстро оказалась на полу. Миша начал водить рукою по ее обнаженной груди, а вы решили заняться пока своей норкой, "
                 "то вынимая, то погружая туда пальчик.<br><npc>- Аня, смотри Света, к примеру любит, чтобы ей сначала разогрели норку,</npc> - "
                 "без малейшего смущения сказал Миша.<br><hero>- Именно так! И это только начало!</hero> - добавили вы.<br>Аня покраснела и улыбнулась,"
                 " а затем добавила:<br><npc>- В киску мне нравится….</npc>";
        str[8] = "Мишка тут же нагнул вашу сестру и спустил с нее шортики, отправив затем пару своих пальцев в глубины ее норки, Аня охнула, а вы продолжая"
                 " поигрывать уже со своей норкой наблюдали за выражением ее лица.<br><npc>- Аня, помоги-ка моему другу окрепнуть,</npc> - попросил Миша,"
                 " после того как обработал ее щелку.<br><npc>- Помогу!</npc> - коротко ответила Аня, но вы заметили ка на ее лице мелькнула похотливая"
                 " улыбка.";
        str[9] = "Мишка достал свой инструмент и принялся трахать Анин ротик, вы же занялись ее киской, отметив для себя что она была уже довольно "
                 "влажная.<br><npc>- Светуля, твоя сестренка сосет не хуже тебя!</npc> - заявил Мишка.<br><hero>- Правда, может устроим соревнование?</hero>"
                 " - игриво заявили вы, отрываясь от Аниной норки.";
        str[10] = "Спустя минуту, вы уже лежали на кровати избавившись от ненужной одежды и на пару с сестрой работали над инструментом Мишки.<br>"
                  "<npc>- Да вы обе потрясные!</npc> - заявил Мишка и продолжил<npc>- Кто будет первой сегодня?</npc><br><hero>- Давай я, сейчас мы "
                  "научим сестренку как надо себя вести! Но сначало мне нужна дополнительная обработка!</hero>- заявили вы.";
        str[11] = "Аня продолжила обрабатывать член Мишки и, уже возбудившись, стала играть со своей норкой. Вы практически полностью погрузили свою"
                  " киску в Мишин ротик, он же стал посасывать и полизывать вас, проникая своим языком прямо внутрь.<br><hero>- Ох, да как же круто!"
                  "</hero> - завопили вы, услышав это, Аня оторвалась от своего занятия и повернула голову к вам. Увидев ,что Мишка творит с вашей норкой"
                  " она сглотнула и вернулась к своему занятию начав еще усерднее натирать свою промежность.";
        str[12] = "Мишка положил вас на кровать и вогнал свой инструмент в вашу норку, затем начал двигаться, наращивая темп:<br><npc>- Аня, не хочешь "
                  "поиграть язычком с клитором своей сестренки, думаю, ей понравится!</npc><br><npc>- С удовольствием,</npc> - Аня усердно принялась "
                  "играть язычком с вашим клитором. Вы замычали от наслаждения.";
        str[13] = "Миша вынул из вас инструмент и сказал<br><npc>- Анюта, не хочешь попробовать на вкус свою сестренку?</npc> - Миша продолжал вести "
                  "себя ни чуть не смущаясь.<br><hero>- Сестрёнка, после разогрева я люблю ощущение когда чей то елдачок буравит мою попку, так что смажь"
                  " его получше!</hero> - добавили вы побольше пикантных комментариев. Аня фыркнула, но исполнила просьбу.";
        str[14] = "Миша вогнал свой член в вашу попку и начал двигаться, засовывая его почти на всю длину. Аня смотрела на это зрелище, потом сказала:<br>"
                  "<npc>- Хотите чтоб я разошлась на полную? Ну тогда потом не жалуйтесь!</npc>- с этими словами она схватила вас за бедра и начала вылизывать"
                  " вашу киску.<br><hero>- Ох да, вот это кайф, давно бы так!</hero> - простонали вы.<br><npc>- Миша, по-моему пришла моя очередь, ты так "
                  "не считаешь?</npc>- игриво спросила Аня.";
        str[15] = "Миша лег на кровать, Аня быстро оседлала его, вам же ничего не оставалось как продолжать возбуждать себя пальчиками.<br><npc>- Анюта,"
                  " ну может теперь скажет как ты любишь?</npc>- повторил свой вопрос Миша.<br><npc>- Я так же как Светик, мы с ней в этом очень похожи…,"
                  "</npc>- все еще стесняясь произнесла Аня.";
        str[16] = "Хорошо разогрев Аню, Миша решил опробовать ее попку.<br><hero>- Ну что, сестрёнка, ты довольна?</hero>- подходя и целуя Аню, спросили"
                  " вы.<br><npc>- Великолепно!</npc>- охая, ответила сестра.<br><hero>- А вот если Миша с Колькой будут тебя одновременно иметь - это будет"
                  " еще круче, уж поверь мне!</hero>";
        str[17] = "Аня вам ничего не ответила она и не могла. В этот момент ее застрясло и она стала кончать.<br>Вы вынули инструмент Мишки из ее заднего "
                  "отверстия и начала смачно его облизывать.<br><npc>- Кажется, Аня готова, теперь твоя очередь, Светик!</npc><br><hero>- Наконец-то я уже"
                  " заждалась!</hero>";
        str[18] = "Для финального рывка Миша предложил весьма интересную позу. Вы с Аней встали в позицию 69, а Мишка сверху вошел в вашу попку.<br><hero>-"
                  " Глубже! Вгоняй глубже!</hero> - завопили вы, когда вас начали накрывать волны оргазма.<br><hero>- Сестрёнка, у тебя из писи потекло!"
                  "</hero> - облизывая вашу норку, игриво сказала Аня";
        str[19] = "<npc>- Я тоже уже готов!</npc>- сказал Мишка, вы было хотели сказать, чтоб он кончил прямо в вас, но Аня была быстрее.<br><npc>- Миша,"
                  " спусти мне в ротик!</npc>- сказала сестра и пошире открыла рот.";
        str[20] = "Мишка кончил прямо в ротик Ани, последние капли остались лишь у нее на язычке. Вы быстро подоспели чтобы слизать их.";
        str[21] = "Вы обменялись поцелуем с сестрой, разделяя порцию спермы. Затем обе глянули на Мишку:<br><npc>- Спасибо, помощник свободен!</npc>- "
                  "Аня весело рассмеялась.<br><npc>- Да-да, я пошел, понадоблюсь - зовите в любое время.</npc><br>Михаил быстренько собрался и ушел."
                  "<br><hero>- Ну что, как тебе?</hero>- осведомились вы.<br><npc>- Суперкайф!</npc><br><hero>- Отлично. Хочешь двоих попробовать? "
                  "Я реально фанатею от этого!</hero><br><npc>- Нууу, даже не знаю, интересно, конечно…</npc><br><hero>- Всё, значит, организуем. "
                  "Готовься!</hero><br><npc>- Ладно, моя сеструха-нимфоманка, я досыпать буду, нарисуется чего-нибудь - скажешь.</npc>";
        return str[id - 291];
    }
    else if(id >= 313 && id <= 331)
    {
        str[0] = "Минут через 10 позвонили в дверь и вы пошли открывать. Возвращаясь в свою комнату, вы увидели, что Аня с Колей уже начали без вас. Особо "
                 "не раздумывая, вы тут же присоединись к ним.<br><npc>- Что у нас сегодня по программе?</npc> - спросил Миша.<br><hero>- Двойное "
                 "удовольствие!</hero> - воскликнули вы.";
        str[1] = "Аня обрабатывала инструмент Кольки, а Мишка работал с вашими дырочками.<br><npc>- Аня, ты тоже будешь участвовать?</npc>- отрываясь от "
                 "вашей попки, спросил Миша.<br><npc>- Я... я… еще не решила, вот! Давайте начнем с чего-нибудь обычного,</npc>- предложила Аня.";
        str[2] = "Аня запрыгнула на Кольку и начала интенсивно скакать на нем, Мишка же занялся вами.<br><hero>- Не переживайте, мальчики, я уж точно такой"
                 " возможности не упущу!</hero> - хихикая, сказали вы.<br><npc>- Вот и отлично!</npc> - сказал Колька,<npc>- Хотя бы одна сестренка у меня "
                 "не из стеснительных!</npc>";
        str[3] = "Теперь уже Колька насадил на себя Аню, а Мишаня поставил вас раком:<br><npc>- Светуля молодец, знает как доставить парням удовольствие"
                 " и самой провести время не хуже!</npc><br><npc>- Колька давай уже в попу,</npc>- умоляюще застонала Аня.";
        str[4] = "Колька уложил вашу сестру на бок и быстро вогнал свой кол в ее попку, вы тоже последовали их примеру и быстро насадили свой задик на Мишин"
                 " инструмент.<br><npc>- Ах, да-а, трахай мою задницу!</npc>- завопила Аня, начав теребить свою киску.<br><npc>- Анют, хочешь я тоже поработаю"
                 " над твоей попкой?</npc>- спросил Мишка.<br><npc>- Да,</npc>- Аня слегка замялась, а потом, отбросив сомнения, продолжила,<npc>- Да, да, да!"
                 " И сразу двоих тоже хочу...</npc>";
        str[5] = "Вы сменили партнеров, зато позы на этот раз были почти одинаковые. Вздохи и повизгивания шли от вас обеих нескончаемым потоком.<br><hero>"
                 "- А теперь пусть Аня получит что хотела ведь это для нее все и организовывалось,</hero>- сквозь стоны предложили вы.<br><npc>- Светик! Ты "
                 "из меня такую же нимфоманку как сама сделать хочешь!</npc>- провопила сестра.<br><hero>- А тебе, можно подумать, не нравится! Мальчики ну-ка"
                 " покажите этой недотроге! Растрахайте ее на пару, наконец!</hero>";
        str[6] = "Аньку уселась верхом на Колю, а Миша вошел сзади. Уже секунд через 10 сестренка начала сама подмахивать бедрами парням и вылизывать вашу "
                 "подставленную к ее ротику грудь.<br><npc>- Аня, ты как?</npc>- решил узнать Мишаня.<br><npc>- Ахх! Охх! Божественно! Что же я так долго "
                 "ждала-то!</npc>- спустя минуту Аня уже во всю кончала, а парни проделали с ней то же, что и в первый раз с вами.<br><hero>- Дайте-ка и мне"
                 " немного!</hero>- взяв члены парней сказали вы, а Аня тем временем приходила в себя.";
        str[7] = "Вы посасывали член Мишки, а рукой работали с Колиным инструментом.<br><npc>- Ну что Анюта продолжим?</npc>- осведомился Миша.<br><npc>"
                 "- Дааа! Еще хочу!</npc>";
        str[8] = "Мальчишки перевернули ее и теперь уже Колька занялся ее попкой, а Мишка взял на себя норку, вы же решили поиграть с сисечками сестры.<br>"
                 "<hero>- Вау! Похоже, нашу скромницу понесло,</hero>- прыснули вы со смеху, видя как через минуту Аня снова впала в предоргазменное состояние."
                 "<br><npc>- Типа мы слегка перегнули, ага? Надо бы дать ей передохнуть</npc>- сказал Миша.";
        str[9] = "Миша вынул из вашей сестры елдак, но вы были тут как тут и быстро обхватили его ротиком.<br><npc>- Эй-эй, оголодавшая, тут у нас кое-кто "
                 "почти отключился!</npc><br>Вы взглянули на сестру, на миг выпустив член.<br>Зрелище было воистину великолепным: Аня была в полу сознательном"
                 " состоянии, насаженная на Колькин инструмент, а из ее норки безостановочно сочились соки. Все это продолжалось до тех пор пока девушка не"
                 " пришла в себя.";
        str[10] = "После того как ваша сестра, наконец, оклемалась парни занялись уже вашими дырочками.<br><npc>- Ребята, я так никогда не кончала в голове"
                  " до сих пор все плывет!</npc><br><hero>- А ты думала я просто так на это дело подсела,</hero> - повизгивая от удовольствия, похвастались"
                  " вы.<br><npc>- Анечка, иди сюда обработай мой шланг,</npc>- сказал Мишаня, заметив, что Аня готова продолжить участие в оргии.";
        str[11] = "Девушка, причмокивая, начала работать с разгоряченным агрегатом. Вы хоть и ощутили пустоту в попке, но Коля не давал скучать второй "
                  "дырочке.<br><npc>- Эх, раз уж мы так сблизились теперь,</npc>- тяжело придыхая, сказал Миша,<npc>- я бы мог познакомить вас со своими "
                  "друзьями: они тоже это дело любят, сестренки им точно понравятся!</npc><br><hero>- Я согласна!!</hero>- завопили вы<hero>- А теперь "
                  "уже дотрахайте меня, наконец, чтоб я откончалась как наша Анька-пулемётчица!</hero>";
        str[12] = "Ребята перевернули вас и начали загонять свои разбухшие органы как можно глубже внутрь. Знакомое ощущения мощного двойного оргазма "
                  "прокатилось телу волна за волной.<br><npc>- Анют, как насчет тебя?</npc><br><npc>- Я не так быстро привыкаю к незнакомым как сестренка,"
                  " поэтому я бы пока ограничилась братцем и тобой...пока!</npc>";
        str[13] = "Пока вы пытались отдышаться, переживая достигнутое блаженство, Аня решила попробовать влезут ли сразу оба инструмента в ее ротик."
                  "<br><npc>- Ого, влезли сразу парой!</npc>- победоносно воскликнул Мишка,<npc>- Давай-давай, потренируй сосочку! Ооо, кайф!... "
                  "А что касается твоей просьбы Анюта, то я всегда готов помочь в этом благородном деле, особенно такой милашке.</npc>";
        str[14] = "Парни усадили вас с Аней на кроватке и дали финально выдоить подрагивающие от возбуждения члены.<br><npc>- Ну-ка, девчонки, попробуйте"
                  " вкус победы!</npc>";
        str[15] = "Николай разрядился в Анечкин ротик. Девушка жадно облизала член застонавшего брата.";
        str[16] = "Миша выстрелил в вас впечатляющим фонтаном семени.<br><hero>- Мняуу, как здорово!</hero>- пропели вы, пытаясь все проглотить, но все "
                  "же проливая.";
        str[17] = "После чего не забыли поделиться полученными порциями с сестрой.";
        str[18] = "Вкусно облизав остатки семени друг с друга, вы стали приводить себя в порядок.<br><hero>- Ух, классно провели времечко!</hero>- весело"
                  " констатировали вы.<br><npc>- Да, просто отлично,</npc>- дружно поддержали остальные.<br><npc>- Миша, ты не мог бы ты задержатся на "
                  "пару минут,</npc>- остановила сестра уже уходящего Михаила.<npc>- А вы идите-идите!</npc>- добавила она вам с Колей.<br>Что потом "
                  "происходило вам осталось неизвестно, однако, вы подметили как Мишка уходил минут через двадцать с широкой улыбкой на лице.";
        return str[id - 313];
    }
    else if(id >= 332 && id <= 370)
    {
        str[0] = "<npc>- Свет, мне вчера Мишичка звонил. Уговаривал нас с тобой поехать в Энск, оторваться в клубешнике. Какую-то сделку его друзья отмечают."
                 " Солидные мужчины, при деньгах, говорит. Едем?</npc><br><hero>- А Кольку-то пригласили?</hero>- хихикая, спрашиваете вы.<br><npc>- Ну, куда"
                 " ж без него,</npc>- смеётся Аня в ответ.<br><hero>- Да поехали,</hero>- пожимаете вы плечами,<hero>- а когда?</hero><br><npc>- Бых-ха, прямо"
                 " вот сейчас, если решаем. Думаю, накраситься надо поярче, ну и вообще... Успеешь?</npc><br><hero>- Уже бегу!</hero><br>Через пять минут к"
                 " подъезду вашего дома подъезжает такси. Вы с Аней спускаетесь и садитесь в машину. Миша с Колькой уже там.";
        str[1] = "Вы танцуете и веселитесь в клубе, обнимаясь с парнями. Вам постоянно приносят коктейли и вы легко выпиваете, но угнаться за сестрой явно не"
                 " в силах. Та выглатывает алкогольные напитки в минуту и скоро приходит в кондицию крепкого опьянения.<br>Вы весело болтаете с одним из "
                 "мужчин, с которыми познакомились. Он подмигивает вам и сует в ладошку какую-то розовую таблетку в виде сердечка.<br><npc>- Это экстази,"
                 " попробуй - понравится!</npc><br>Скептически глянув на таблеточку, вы решаете, что если экспериментировать, то уж точно не на себе.<br>"
                 "Вдруг видите Аню, целующейся с каким-то новым персонажем - кажется, это Руслан из ваших сегодняшних новых знакомых, друзей Миши.";
        str[2] = "Вы отводите Аню в туалет:<br><hero>- Анька, ты чо?! У вас же с Мишкой вроде отношения. Ты говорила он тебе нравится и хочешь, чтобы все"
                 " было серьезно?</hero><br><npc>- Ой, да! Чо-т-та я перепила слегка. Недоперепила... ик, ха-ха. Прости, сёстренка, спасибо тебе! М-мишка-то "
                 "не видел?</npc><br><hero>- Нет, я тебя вовремя утащила. Еще минута и ты бы тут всем дала!</hero><br><npc>- Ну прям всем… Но кое-кому,"
                 " хи-хи-хи...</npc><br><hero>- Всё, пора ехать!</hero>- решаете вы.<br>Вы находите Мишку с Колькой и ультимативно сообщаете, что надо "
                 "заканчивать затянувшееся веселье в клубе.<br>Миша пожимает плечами:<npc>- Давайте ко мне, сейчас такси вызову.</npc>";
        str[3] = "Вы приехали в квартиру Михаила. Аня требует еще выпить. Вы стаскиваете с нее юбку и шлепаете по заднице:<hero>- А ну хорош бухать, я "
                 "лучше покувыркаюсь.</hero><br><npc>- Ааа, давайте! Ребята, вы готовы?</npc><br> Дразня парней телесами - спрашиваете вы.";
        str[4] = "Миша с Колькой оперативно скидывают одежду и подходят к вам с членами наизготовку:<br><npc>- О, мои любимые кранчики!</npc>- Аня"
                 " с высунутым языком поглаживает елдак ладошкой, вторую руку опуская на киску,<npc>- Хочу-хочу-хочу!</npc>";
        str[5] = "Вы обе сосете у парней. Как обычно, член во рту вас возбуждает.<br><npc>- Давайте уже дырочки, девчата! Я так в этом клубе подзавелся…,"
                 "</npc>- говорит Михаил,<npc>- Попки к бою!</npc><br>Вы с Аней, хихикая, быстро уснащаете задницы смазкой.";
        str[6] = "И резво запрыгиваете на болты. Брат растянув ваши ягодицы, аккуратненько протрахивает ваш задний проход. Анька самозабвенно скачет на "
                 "Мишке, который разогревает ей кисочку рукой.";
        str[7] = "<npc>Давайте поприкольнее! Девчонки, залезайте друг на дружку!</npc>";
        str[8] = "Вы устраиваетесь на спине сестры. В ваших попках, тем временем, меняются стволы партнеров.<br><npc>- Вау-ух, не могу, трахните меня в"
                 " обе щёлки,</npc>- умоляюще просит Аня.";
        str[9] = "Парни выполняют просьбу, ваша сестра довольна до предела и визжит:<br><npc>- Еще, еще, как же я люблю когда все заполнена-ааа!</npc>"
                 "<br><npc>- Ань, примешь два в попочку?</npc>- спрашивает Михаил.<br><npc>- Йо-о! Да, я бы сейчас слона приняла!</npc>";
        str[10] = "<npc>- Сестричка, наслюнявь моего,</npc>- Коля сует вам в рот багровый от возбуждения елдак. Вы интенсивно работаете ротиком, добавляя"
                  " побольше слюны.<br><npc>- Во, теперь два в дырочку!</npc>";
        str[11] = "Аня с восторгом принимает пару членов в задний проход. Вы разгораетесь, наблюдая как она кайфует.<br><hero>- Теперь меня, меня!"
                  "</hero><br><npc>- Мы тебя не забудем, Свет, ха-ха!</npc>";
        str[12] = "Вы усаживаетесь на Мишкин корень. Аня услужливо раскрывает ваши ягодицы и член брата врубается между них.<br>Вы счастливо елозите "
                  "между елдаками, наслаждаясь все больше под каждым ударом таранов внутрь.";
        str[13] = "Аня сама жадно хватает разбухшее достоинство брата и насасывает как заведенная.<br>Вы стонете:<br><hero>- У-умх, и мне пару в задик,"
                  " я готова!</hero>";
        str[14] = "Ребята протыкают ваш анус двумя членами и вы, задрожав, оргазмируете.<br><hero>- Уууууу-йииии,</hero>- пищите вы,<hero>- как же"
                  " круто-о-ооо! Я улетаю, блин!</hero><br><npc>- Я еще хочу!</npc>- с завистью бормочет Аня.";
        str[15] = "Парни прохаривают ее по новой в две дырки и ваша сестра с протяжным стоном финиширует.";
        str[16] = "Мишка усаживает вас на раскаленный орган:<br><npc>- Давай, Светик, сейчас, уже скоро...прыгай...ой..на-а..</npc><br><hero>"
                  "- Мамочка-а, я же еще кончу-у…,</hero>- в экстазе вопите вы.<br>Зафаканная балдеющая Аня с чмоканьем обсасывает елдак брата.";
        str[17] = "Ребята снова меняются на ваших задних дырках, резко ускоряя фрикции.<br>И вы, внезапно, ловите еще один анальный оргазм.<br>"
                  "<npc>- Ааа, все девчонки, в ротики, в ротики, глотайте!</npc>- ревет трясущийся Миша.";
        str[18] = "Вы на коленках выдаиваете подрагивающие болты.";
        str[19] = "Коля спускает в рот Ани.";
        str[20] = "А Мишка разряжается на ваш подставленный язычок.";
        str[21] = "Вы целуетесь с сестрой, слизывая друг с друга теплое семя.<br><npc>- Классно отдохнули,</npc>- расслабленно бормочет Миша.<br>"
                  "<hero>- Уум-мня, я за то, чтобы всегда так,</hero>- практически хором говорите вы с Аней и смеетесь.<br><npc>- Домой надо, родоки"
                  " наедут,</npc>- напоминает Коля.<br>Приняв душь, вы втроем бегом, счастливо держась за руки, отправляетесь домой.<br><npc>- Нормально"
                  " погуляли,</npc>- констатирует Аня, с удивлением глядя, что уже стемнело.";

        str[22] = "Вы решаете довести развращение сестры до конца и тихонько подкидываете ей в спиртное таблетку-сердечко, отлично осознавая как она "
                  "подействует.<br>Аня заводится и начинает вести себя совершенно по-блядски, вешаясь на мужиков напропалую. Увидев это, Мишка только"
                  " усмехается.<br>Руслан предлагает поехать к нему всем вместе и достойно завершить вечер, чтобы было что вспомнить.<br><npc>- Да-да-да!"
                  " Едем,</npc>- загорается Аня.";
        str[23] = "Вы приехали на квартиру Руслана в компании изрядного количества подвыпивших парней. В неплохо обставленных апартаментах обнаружился крепкий"
                  " мускулистый мужчина в возрасте с характерной внешностью:<br><npc>- Это мой дядя Шавкат, все знакомьтесь!</npc><br>Дядя Шавкат весьма"
                  " плотоядно рассмотрел вас с сестрой:<br><npc>- Ошэн приятна, дэвушки! Э, сейчас гулять будем, отдыхать. Ви молодежь, виселье нада. Есть"
                  " коньяк - такой никто не пил, клянусь!</npc><br><npc>-Мне, мне!</npc>- радостно завопила Аня. Вы только вздохнули: не исправишь.";
        str[24] = "<npc>- Давайте продолжим танцевать! Девчонки, зажигайте!</npc><br>Вы танцуете с пьяной сестрой перед парнями и Шавкатом. Она вас обнимает"
                  " и вдруг начинает раздеваться.<br><npc>- Ох, что-то я завелась, прям зуд нестерпимый!</npc><br>Вы лижете обнаженные сисечки сестры:<br>"
                  "<hero>- Что, все так и будут глазеть? Присоединяйтесь!</hero>- командуете вы.<br><npc>- Р-рз...тьфу! Раздевайтесь! Я хочу быть проёбана"
                  " всеми!</npc>- бесстыдно заявляет Аня.";
        str[25] = "Вскоре вас окружают голые мужские тела. Аня с восторгом смотрит на елдак Шавката:<npc>- Уу, какой!</npc><br><npc> -Э, попробуй, нэ "
                  "атарвешься!</npc><br><npc>- Я с удовольствием!</npc><br>Вас обеих тискают и стаскивают нижнюю одежду.";
        str[26] = "Вы с сестрой устраиваетесь на коленях и принимаетесь сосать члены.<br>Аня чмокает с таким воодушевлением и жадностью, что каждый хочет"
                  " отпользовать именно ее ротик.";
        str[27] = "Вы сообразительно смазывате анус лубрикантом себе и самозабвенно глыркающей елдаками в горле Ане.";
        str[28] = "Вас устраивают на диване и вгоняют мощные посохи в подготовленные дырки.<br><npc>- Дай-ка попка твоя сладкая, вот так!</npc>- Шавкат "
                  "оккупирует своим солидным достоинством ваш задний проход.<br><hero>- Аууу! Какой же он...ох...круто-о!</hero><br><npc>- Светик, покажи "
                  "класс,</npc>- смеется Миша, наяривая в ротик вашу мычащую от наркоты, алкоголя и похоти сестру.<br><npc>- Фигачьте меня во все щели!</npc>"
                  "- стонет Аня.";
        str[29] = "Пока вашу попку яростно долбает болт кавказского родственника, Аню пропесочивают в три дырки.<br>Она с одержимостью изгибается и "
                  "насаживается на члены, иногда отрываясь от соски и мотая головой в экстазе:<br><npc>- Божечки, как обадленно! Ещё, ещё!</npc><br>Мишка"
                  " собирается протрахать вашу киску, но вы решительно возражаете:<hero>- Нет, сегодня меня только в зад! Добавь мне туда!</hero>";
        str[30] = "<hero>- Ыаааа, да-а!</hero>- вы с истошным воплем принимаете пару елдаков в попочку.";
        str[31] = "Вас с сестрой долбают в разных позах. Аня громко оргазмирует, но ваши похотливые вопли все перекрывают.";
        str[32] = "Вас усаживают на два горячих кола. Вы бешено скачете на них и, наконец, добиваетесь вожделенного анального оргазма.";
        str[33] = "Вас обеих на полу шкворят в услужливо раздвинутые попочки все по очереди, сменяя один другого.<br><npc>- Э, темненькая, ложысь на"
                  " бляндинка, в попа кончу,</npc>- Шавкат берет вас на руки и кладет на сестру.";
        str[34] = "Затем ускоряется, вбивая раскаленный таран в вашу кишку и с рыком эякулирует внутрь.";
        str[35] = "Затем в вашу попку финишируют еще двое, вы не видите кто.";
        str[36] = "Вы выпускаете полученное семя, напрягая сфинктер, прямо в Анькин ротик.<br>Уфаканная вусмерть сестра поглощает сперму. Глотает и"
                  " вылизывает остатки с вашей дырочки.";
        str[37] = "<npc>- Ааа, девчонки, держите ещё,</npc>- слегка наклюкавшийся и слабо участвовавший в оргии, Колька разряжается вам на лица.";
        str[38] = "<npc>- Нормально, девчат? Вы в порядке?</npc>- заботливо интересуется Руслан.<br><npc>- Вау, суперчётко оторвались!</npc>- осоловело "
                  "говорит Аня.<br><npc>- Т- только ч-чота я все ещё никакая малость, как в космосе,</npc>- добавляет шепотом она вам на ушко,<npc>- "
                  "и опять хочу, аж стыдно после такого...</npc><br><npc>- Пора нам, родаки накрутят!</npc>- вспоминаете вы одновременно с Колей и смеетесь."
                  "<br>Миша вызывает такси и доставляет вас троих до самого подъезда.<br><npc>- А еще мы так оторвёмся?</npc>- интересуется Аня, прощаясь."
                  " С ее лица не сходит блаженно-блудливая улыбка.<br><npc>- Да почему нет, устроим!</npc><br>Вы возвращаетесь в квартиру, удивляясь, что "
                  "уже вечер.";
        return str[id - 332];
    }
    else if(id >= 371 && id <= 377)
    {
        str[0] = "Вы подходите к своей комнате и слышите доносящиеся оттуда стоны. Приоткрыв дверь, вы обнаруживаете как Аня развлекается с Михаилом."
                 " Немного подумав, вы решаете оставить их кувыркаться дальше и идете по своим делам.";
        str[1] = "Вы подходите к своей комнате и слышите доносящиеся оттуда стоны. Приоткрыв дверь, вы обнаруживаете как Аня развлекается с Мишей и"
                 " Колькой. Слегка огорчившись, что они вас не позвали, вы, показав троице язык и крутанув задом, уходите, отправляясь по своим делам.";
        str[2] = "<hero>- Ну как тебе вечеринка, сестрёнка?</hero><br><npc>- Ох, да мне на такие лучше не соваться, а то я там на всех подряд лезу, "
                 "если бы не ты, то меня точно кто-нибудь из Мишкиных друзей в туалете оприходывал. Еще раз спасибо тебе, Светик.</npc><br><hero>- Ну,"
                 " мне бы хотелось бы, чтоб у тебя в жизни всё получилось...</hero>- обнимая сестру, сказали вы.<br><npc>- Я тебя тоже порадую, Светик!"
                 " В общем, мы с Мишей тут все серьёзно обсудили... Мы будем встречаться как настоящая пара! Он даже меня к себе жить позвал, представляешь?"
                 " Я пока отказала, думаю, что рановато еще…</npc><br><hero>- Эхх, как же я без вас буду - с одним только Колькой!</hero>- смеясь, сказали"
                 " вы.<br><npc>- И это мы с ним тоже обсудили. Решили так: с вами двумя мы можем делать что хотим оба! Но с другими - ни-ни! И к тебе просьба"
                 " моя личная еще: сестрёнка, по возможности, удерживай меня от необдуманных поступков…</npc><br><hero>- Не то что бы я не рада такой "
                 "новости... Но как-то странно это для влюбленной парочки, не находишь?</hero>- продолжая давиться смехом спросили вы Аню.<br><npc>- А"
                 " у нас вообще семейка странная! Скажу тебе по секрету: это я была инициатором той самой договоренности - уж больно мне в обе дырочки"
                 " понравилось,</npc>- прошептала вам Аня на ухо.<br>Вы поцеловали и обняли сестренку, сказав<hero>- Надеюсь, у вас все получится!</hero>";
        str[3] = "<hero>- Ну как тебе вечеринка, сестрёнка?</hero><br><npc>- Мне Мишичка звонил…</npc>- всхлипывая, рассказывает Аня,<npc>- он... он… не"
                 " будет со мной больше встреча-а-аться….</npc><br><hero>- Вот блин, это чо, из-за той классной групповушки у Руслана?</hero><br><npc>"
                 "- Да…. вот я дура, такого парня упустила, а все из-за бухла-а!</npc><br><hero>- Поздно теперь уже виниться да горевать, лучше подумай"
                 " о том, какую выгоду из этого извлечь можно!</hero><br><npc>- Ну и какую же?</npc>- заинтересовывается Аня, прекратив разводить сопли."
                 "<br><hero>- Теперь у нас есть целая толпа парней, которые не прочь удовлетворить все наши фантазии!</hero><br><npc>- Вот вы с Мишкой "
                 "одного поля ягодки! И он сказал примерно то же…</npc><br><hero>- Ты же сама говорила…,</hero>- вы не успели закончить, как сестра "
                 "вас оборвала.<br><npc>- Света! Он так мне выдал: “Анёк, я с друзьями по выходным можем вас с сестрой оттрахать как угодно, но кроме "
                 "этого - больше ничего!”</npc><br><hero>- Ну и радуйся, глупышка, может кого из их компашки подцепишь да и удовольствие получишь!</hero>"
                 "<br><npc>- Ох, Свет, наверно, ты права! Не стоит грустить из-за парня, которого я знаю совсем недавно!</npc>- наконец, улыбнулась Аня."
                 "<br>Вы поцеловали и обняли сестренку, сказав:<hero>- Надеюсь, у тебя все получится!</hero>";
        str[4] = "<npc>- Ой, Светик, чо скажу! МЫ! С МИШКОЙ! СЪЕЗЖАЕМСЯ!</npc><br><hero>- Круто! Вот это новость! Ну чо, поздравляю,</hero>- вы обняли "
                 "сестру, которая вся прямо-таки лучилась от счастья.";
        str[5] = "У вас звонит телефон:<npc>- Светик, привет, это Мишка! Слушай, сегодня такой день отличный, не хотите в бассейне покупаться?</npc><br>"
                 "<hero>- Ох, я б точно не отказалась! Подожди секунду, у Ани спрошу!</hero><br><npc>- И Коляна прихватите!</npc><br><hero>- Да оба поедут,"
                 " а куда только ехать-то?</hero><br><npc>- Никуда, я у вашего подъезда жду в такси, спускайтесь быстрее.</npc>";
        str[6] = "У вас звонит телефон:<npc>- Светик, привет, это Мишка! Слушай, сегодня такой день отличный, не хотите в бассейне покупаться?</npc><br>"
                 "<hero>- Ох, я б точно не отказалась! Подожди секунду, у Коли спрошу!</hero><br><npc>- Купальники не забудьте!</npc><br><hero>- Ага,"
                 " Колька готов, тоже поедет, а куда только ехать-то?</hero><br><npc>- Никуда, мы у вашего подъезда ждем в такси, спускайтесь.</npc>";
        return str[id - 371];
    }
    else if(id >= 378 && id <= 399)
    {
        str[0] = "Схватив купальники, вы уже через пару минут спустились к такси. По дороге Миша рассказал, что вы направляетесь в коттедж, к его знакомому."
                 " Минут через двадцать вы прибыли на место. Поздоровавшись с хозяином, которого Миша коротко представил Дмитрием, вы втроем помчались "
                 "переодеваться, а Мишка остался что-то обсудить с Димой.";
        str[1] = "Обустроившись в бассейне, вы принялись всячески дурачиться. Мишка и Аня о чем-то болтали в сторонке, но и одного взгляда на парочку было"
                 " достаточно, чтобы понять о чем разговор. Затем стали размышлять, что бы такое учудить для пущего веселья.";
        str[2] = "Вы купались и прозагорали весь день напролет. Потом отправились домой.";
        str[3] = "Убедившись что хозяин коттеджа смотрит на вас, причем с явной заинтересованностью, вы отодвинули свои зачаточного вида купальные трусики "
                 "и раздвинули половые губки пальцами. Затем вернули все на место и легли на бочок как будто ничего и не было.";
        str[4] = "<hero>- Дим, хочешь попробовать как в этой щелочке? Те-е-е-епло-о!</hero>- распутно улыбаясь, спросили вы.<br><npc>- Света, ха-ха, что ты "
                 "делаешь, мы же тут не одни!</npc><br><hero>- А мне нравится, когда не одни! И не один,</hero>- вы залихватски подмигнули парню,<hero>- Да"
                 " и остальные, я думаю, не против! Правда же?</hero>";
        str[5] = "Первым откликнулся Колька:<br><npc>- Я всегда за!</npc><br>Вы обернулись и посмотрели на сладкую парочку, услышав краем уха как Аня шепчет:"
                 " ”Миш, ну давай, пожалуйста, я только с тобой буду, если хочешь!”<br>”Ладно-ладно, если уж развлекаться, то по полной!”<br><npc>- Мы тоже"
                 " не против,</npc>- обернувшись, сказал Миша.<br><npc>- Я даже не знаю,</npc>- замялся Дима.";
        str[6] = "Без лишних слов, вы стянули с Ромки шорты и начали работать над его уже изрядно возбудившимся инструментом. Колька стал поигрывать с вашей"
                 " попкой, а Аня занялась подготовкой Мишкиного агрегата.<br><npc>- Света... ты... это ну...</npc>- пытался по началу остановить намечающуюся"
                 " оргию Дима, но увидев, что все уже завертелось, только пожал плечами.<br><hero>- Коль, я тут Димой вплотную займусь, а ты пока к Ане иди,"
                 " пусть она с тобой поиграет,</hero>- на секунду выпустив член изо рта, сказали вы.";
        str[7] = "Аня начала по очереди обрабатывать инструменты парней, а вы сосредоточились на Диме.<br><npc>- Мальчики, возьмите меня уже,</npc>- первой"
                 " не выдержала Аня.<br><npc>- Я первый!</npc>- выкрикнул Колька<br>Вы оставили агрегат Димы, затем оголив грудь прижались и поцеловали его,"
                 " шепча на ушко:<hero>- А ты меня хочешь?</hero>Ответ последовал незамедлительно:<npc>- Как устоять перед такой горячей штучкой!</npc>";
        str[8] = "Вы сдвинули бикини и насадились своей норкой на внушительных размеров член Димы, Аня последовала вашему примеру и, обнажив свои прелести,"
                 " оседлала брата. Миша избавился от лишней одежды и оккупировал ее ротик.<br><hero>- Один хорошо, а два лучше,</hero>- захихикали вы,"
                 "<hero>- давайте теперь обменяемся партнерами!</hero><br><npc>- Дима, идите теперь ко мне!</npc>- возбужденно позвала Аня.";
        str[9] = "Николай уже попробовал сегодня киску сестры, так что вашу он уступил Михаилу, а сам пристроился у вашего ротика. Дима же подошел к Ане "
                 "и начал нерешительно входить в ее норку. Она тут же взяла его агрегат рукой и перенаправила себе в попку, при этом сама насаживаясь на"
                 " него поглубже.<br><npc>- Дима! Не стесняйся вгоняй до упора!</npc>- эти слова взбодрили парня и он принялся действовать увереннее.<br>"
                 "<npc>- Ох да, вот так!</npc>- застонала Аня.";
        str[10] = "Миша сменил отверстие и начал засаживать вам в попку, Аня повизгивала неподалеку - видимо, Димитрий вошел во вкус.<br><npc>- Миша, "
                  "иди ко мне, я хочу тебя!</npc>- спрыгнув с Димкиного агрегата и обняв трахающего вас парня, сказала она.<br><npc>- Дима, а ты иди ко"
                  " мне!</npc>- пытаясь не отставать от сестры, сказали вы.<br><hero>- Пока эта парочка развлекается вы с Колькой займетесь моими "
                  "дырочками,</hero>- вы уложили полностью отдавшегося вашей воле Дмитрия на удобный столик рядом.";
        str[11] = "Оседлав Диму, вы тут же ощутили Колькин елдачок в своей второй дырочке и начали сами ерзать бедрами, давая понять Диме, что готовы"
                  " и не испытываете неудобств. Миша положил вашу сестру на бок и раздвинул ей ножки входя в ее писечку так, чтобы всем было прекрасно"
                  " видно чем они заняты.<br><hero>- Мальчики, ну же вгоняйте поглубже!</hero>- застонали вы.<br><npc>- Ах, божечки, я сейчас…ааа!</npc>"
                  "- Аня застонала от накатившего оргазма.";
        str[12] = "Давая Ане передохнуть, Миша переключился на вас. Вы развернулись и насадили свою попку на инструмент Димы, Миша пристроился к вашей"
                  " норке. Аня тем временем не давала заскучать братишке, посасывая его елдак.<br><hero>- Да-да, вот так</hero>- завопили вы, приближаясь"
                  " к пику<hero>- Не останавливайтесь!</hero><br><hero>- Анюта, а ты двушечку хочешь?</hero>- продолжая жарить вас, спросил Мишка.<npc>"
                  "- Конечно! Мои дырочки уже заскучали от одиночества,</npc>- пошутила Аня.";
        str[13] = "Миша улегся на стол и посадил вашу сестренку на себя. Дима снова замешкался и вам пришлось самой засовывать его инструмент в Анину попку."
                  " Затем вы повернулись задиком перед братом и призывно поставили одну ножку на стол, сказав только одно слово:<br><hero>- В киску!</hero>"
                  "- Колю не нужно было долго просить и вы тут же почувствовали внутри себя его орган.<br><npc>- Я уже готов кончить,</npc>- сдавленно"
                  " простонал Дмитрий.<npc>- Нет-нет, я еще хочу!</npc>- тут же завопила Анюта.";
        str[14] = "Миша, воспользовавшись моментом, перевернул вашу сестренку и вошел в ее попку. Освободившееся место тут же занял Колька. Вам ничего "
                  "не оставалось как заняться Димой, поддерживая его возбуждение, но не давая кончить раньше времени.<br><npc>- Ох, бли-ин, я снова"
                  " конча-а-аюююю!</npc>- завопила Аня под мощными толчками ребят.<br><npc>- Анька, подставляй ротик, я тоже уже готов,</npc>- сказал Колян.";
        str[15] = "Ребята устроились рядом с вами и Аня начала доводить парней до эякуляции, вы же стали усердно работать с Димой.<br><hero>- Дима, давай мне"
                  " прямо в ротик!</hero>- отрывая его пошире и высунув язычок, попросили вы.";
        str[16] = "Дима обильно кончил вам в ротик. Излишки семени медленно стекали по вашему подбородку, но большую часть вы все же успели проглотить.<br>"
                  "<hero>- Вкусное завершение нашей встречи!</hero>- хихикая, произнесли вы.";
        str[17] = "Парни дружно спустили в ротик вашей сестренке - большую часть горячего молочка она, правда, пролила, но, как бы извиняясь, смачно обсосала"
                  " оба инструмента.<br><npc>- Ну что, Анюта, довольна?</npc>- осведомился Михаил.<br><npc>- Очень, спасибо тебе, милый, за такой замечательный"
                  " отдых!</npc>";
        str[18] = "Парни отошли в сторонку и стали что-то обсуждать, вы с сестрой принялись целоватся, слизывая друг с друга остатки семени.<br><hero>"
                  "- Классно отдохнули!</hero>- прошептали вы на ушко сестре.<br><npc>- Да отлично!</npc>- сказала Аня, и тихо добавила<npc>- Что может "
                  "быть лучше сразу двух горячих елдаков, двигающихся внутри тебя!?</npc><br>Вы рассмеялись и шемпнули:<hero>- Только три!</hero>";
        str[19] = "Вы с сестрой повернулись к разговаривающим парням и громко спросили:<br><hero>- Дима, ну как, тебе понравилось?</hero><br><npc>- Да, "
                  "девочки, было здорово,</npc>- несколько смущенно ответил он.<br>Вы еще какое-то время купались и загорали, уже полностью голые, а потом "
                  "Миша вызвал такси и вы поехали домой.";
        str[20] = "Вы с сестрой повернулись к разговаривающим парням и громко спросили:<br><hero>- Дима, ну как, тебе понравилось?</hero><br><npc>- Да,"
                  " девочки, было здорово,</npc>- несколько смущенно ответил он.<br>Вы еще какое-то время купались и загорали, уже полностью голые, а потом"
                  " Миша вызвал такси и вы поехали домой.";
        str[21] = " По дороге домой Миша начал рассказывать вам про Дмитрия:<br><npc>- Девчата, скажу вам по секрету: Димка-то еще тот бабник, вот только "
                  "любит он притворяться невинной овечкой!</npc><br><hero>- А я сразу догадалась! Он по началу делает вид, что совсем не в курсе что делать,"
                  " а как войдет в тебя, так сразу чувствуешь - опытный парень!</hero>- в подробностях стали расписывать вы.<br><npc>- В общем, просьба "
                  "у меня к вам: если опять поедем к нему, уж вы подыграйте! Парень-то он классный, хоть и немного странный,</npc>- рассмеялся Мишка.<br>"
                  "<npc>- А мне это даже понравилось,</npc>- добавила Аня.";
        return str[id - 378];
    }
    else if(id >= 400 && id <= 418)
    {
        str[0] = "У вас звонит телефон:<npc>- Светик, привет! У нас сегодня корпоративный банкет намечается. Все с женами да подругами будут, а мне некого"
                 " взять, может, выручишь?</npc><br><hero>- А ты на мне жениться, что ли, хочешь, хи-хи-хи?!</hero><br><npc>- Ну, типа того, но, буквально,"
                 " на один день!</npc><br><hero>- Ой, здорово как! Почувствую себя мужней жёнушкой! Во сколько заедешь?</hero><br><npc>- Через часик успеешь?"
                 "</npc><br><hero>- Да, буду готова.</hero>";
        str[1] = "Миша, как обычно, заехал за вами на такси и вы уже по знакомому маршруту отправились в Энск.<br><npc>- Свет, если ты не против, я тебя всем"
                 " представлю как свою невесту,</npc>- начал разговор Михаил.<br><hero>- Ой, не против, конечно, а ребят с прошлой вечеринки не будет? А то"
                 " даже как то неловко...</hero><br><npc>- Нет, они не с работы, так, друзья,</npc>- ответил Михаил.";
        str[2] = "Когда вы приехали, банкет был уже в разгаре. Народ вовсю веселился и распивал шампанское. Вы быстро включились в веселье. Пили вы немного,"
                 " больше общались с коллегами Михаила, усердно играя роль невесты.<br><hero>- Миша, может быть, поедем уже домой я что-то так устала..."
                 " никогда столько не сплетничала!</hero>- прошептали вы на ухо парню.<br><npc>- Пожалуй, поехали, я и сам не в восторге от этих корпоративов."
                 " Но чтоб повышение получить - приходится посещать, как насчёт заехать ко мне, у меня там бутылочка хорошего вина имеется?</npc><br>"
                 "<hero>- Давай! Отметим наше грядущее “расставание”!</hero>";
        str[3] = "Миша вызвал такси и вы поехали к нему.<br><hero>- Ого, а у тебя шикарная квартира!</hero>- зайдя внутрь и осмотревшись, сказали вы.<br>"
                 "<npc>- Ага, недавно ремонт сделал. Ты тут пока осваивайся, чувствуй себя как дома, а я вино принесу или может еще что то будешь?</npc>";
        str[4] = "<hero>- Буду тебя!</hero>- решительно заявили вы, поднимая платье и показывая Мише свою попку - нижнее белье вы принципиально не надели."
                 "<br><npc>- Ух! Светуля ты так и ходила без трусиков на корпоратив?</npc>*<hero>- Конечно! Я надеялась, что ты меня прямо там! Но, увы, "
                 "момент так и не представился.</hero>";
        str[5] = "Миша подошел к вам обнял за талию и начал целовать вашу шею:<br><npc>- Света, ты не перестаешь меня удивлять.</npc><br><hero>- Я как "
                 "с тобой познакомилась - сама себя не узнаю!</hero>- расстегивая Мишину ширинку, сказали вы.";
        str[6] = "Вы достали его агрегат начали его обрабатывать ротиком:<br><npc>- Завела ты меня, негодница!</npc>";
        str[7] = "Парень схватил и поднял вас на руки, буквально насаживая вашу киску на свой член. Вы сладко вскрикнули, а затем стали страстно его"
                 " целовать.<br><hero>- Кажется, это первый раз когда мы с тобой только вдвоем,</hero>- прошептали вы, отрываясь от его губ.<br><npc>"
                 "- И правда!</npc>- подтвердил Михаил, ставя вас на пол.";
        str[8] = "Оказавшись на полу, вы сразу повернули к Мише свой задок.<br><hero>- В попку давай!</hero>- приказным тоном заявили вы.<br><npc>"
                 "- Как пожелаете, моя королева!</npc>- проникая в ваш задний проход, откликнулся Миша.<br><hero>- Раз я королева, тогда и трахни "
                 "меня по королевски!</hero>";
        str[9] = "Миша снял с вас платье и пристроил на диванчике:<br><hero>- Аааа!!! Божечки!!! Не так глубоко! Мы же без смазки!</hero>- завопили вы,"
                 " когда Мишка стал вгонять свой член вам в попку по самые яйца.<br><npc>- Терпи, сама хотела!</npc>- ехидно сказал Мишка.<br>Вы довольно"
                 " быстро перестали чувствовать неудобство и начали получать кайф от мощных толчков Михаила, о чем ярко свидетельствовала ваша текущая киска.";
        str[10] = "Вы сменили позу: теперь Миша лежал на диване, а вы практически устроились на нем. Он развел ваши ноги в разные стороны и начал быстро"
                  " двигаться внутри вас.<br><hero>- Кончаю, вставляй по глубже!</hero>- завопили вы и пальчиками раскрыли свою сочащуюся киску.<br>"
                  "<hero>- А-ах, ну же, еще, еще!!</hero>- уже оргазмируя, простонали вы.";
        str[11] = "Неожиданно для вас из вашей писечки брызнула мощная струя.<br><hero>- Миша, Миша-а, постой!</hero>- задыхаясь, застонали вы, пытаясь"
                  " слезть с его кола.<br><npc>- Уже нагрязнили, поздно останавливаться,</npc>- пожал плечами парень,<npc>- да и прикольно...</npc>"
                  "<br><hero>- Ох, прости, у меня раньше такого не было!</hero>- не успели вы закончить фразу как из вашей писечки вырвалась очередная струя.";
        str[12] = "Когда ваше тело наконец перестало извергать жидкости, а вы еле удерживались на Мишкином теле, он ухватил вас за бедра и медленно "
                  "стал двигатся:<br><npc>- Светик, ты там как? Живая?</npc><br><hero>- Н-не з-знаю,</hero>- заплетающимся языком пролепетали вы.<br>"
                  "<npc>- Давай тогда я тебе в ротик спущу!</npc>";
        str[13] = "Вы передвигаясь словно сомнабула, сползли с члена и встали на колени, открыв рот. Миша сам довел себя до эякуляции и кончил в ваш "
                  "раскрытый ротик.<br><npc>- Ну ты даешь, Светуля, у меня девки так еще не кончали</npc>- покачал головой Михаил.<br><hero>"
                  "- Миш, дико извиняюсь, не знаю, что нашло! Я все тут уберу...</hero>- вы начали приходить в себя и отбалтываться.";
        str[14] = "Усевшись на попу рядом со стоящим парнем, вы осмотрелись вокруг, оценивая объем предстоящей вам работы:<br><hero>"
                  "- Надеюсь у тебя есть чистящее средство.</hero><br><npc>- Ээ, найдется, наверно,</hero>- неуверенно пробормотал Миша, потом хмыкнул,"
                  "<npc>- да ты так, Светик, не переживай, я уборщицу вызову.</npc><br><hero>- Не-не-не, сама затопила, сама и убирать буду,</hero>"
                  "- мотая головой, настояли вы.";
        str[15] = "Встав, вы по хозяйски пошли в ванную и стали искать там все, что вам понадобится для уборки, при этом даже не думая одеться.<br>"
                  "<npc>- Светик, ты так и будешь голышем тут убираться? Трусики натянула бы, что ли.</npc><br><hero>- Я без трусиков сегодня, забыл?"
                  " Кто же знал что мне убираться придется, я бы тогда горничной нарядилась!</hero>- принимаясь за работу, ответили вы.<br>Миша не в"
                  " силах выдержать вид ваших прелестей, мелькающих перед его глазами, ушел на кухню, а вы полчаса приводили комнату в надлежащий вид.";
        str[16] = "Закончив уборку, вы, с довольным видом, уселись на диван и позвали Мишку, который все это время был на кухне.<br><hero>- Миш, я"
                  " закончила иди посмотри!</hero>- громко позвали вы и раздвинули ножки.<br><npc>- Ого!</npc>- зайдя в комнату воскликнул Мишка,"
                  " уставившись на вашу промежность, но потом все же взял себя в руки и осмотрел комнату.<br><hero>- Нравится?</hero>- поглаживая свое"
                  " обнаженная тело, спросили вы.<br><npc>- Убралась ты замечательно! Может ты у меня постоянно уборку делать будешь?</npc><br>"
                  "<hero>- Уборку…</hero>- задумчиво повторили вы, прекращая поглаживать себя.<hero>- Хорошо, но ты мне будешь должен!</hero>";
        str[17] = "<npc>- Да без проблем! Слушай, давай я тебе ключи дам. Сам-то я до четырех на работе, а ты приходи в любое время. И Колю можешь"
                  " приводить: у меня тут куча игр валяется,</npc>- показывая на огромную полку забитую дисками, предложил Михаил.<br><npc>"
                  "- Если хочешь, я тебе даже платить могу,</npc>- добавил он.<br><hero>- Я с тебя оплату другим способом возьму!</hero>"
                  "- засмеялись вы.<br><npc>- Ну окей, наше дело - предложить... Может, в душ тогда?</npc><br><hero>- Ага, пойдём вместе!</hero>";
        str[18] = "Приняв душ, вы вернулись вернулись в комнату и оделись: вам было пора возвращаться домой.<br><hero>- Миш, мне пора, еще раз спасибо"
                  " за отлично проведенный день!</hero><br><npc>- Увидимся, Светик,</npc>- парень вручил ключи от квартиры и попрощался.";
        return str[id - 400];
    }
    else
        return QString();
}

QString SisterQW::act(int id)
{
    QString act[56];
    act[0] = "Уйти";
    act[1] = "Продолжать наблюдать";
    act[2] = "Ласкать себя";
    act[3] = "Кончить";
    act[4] = "Целоваться";
    act[5] = "Убежать";
    act[6] = "Идти танцевать";
    act[7] = "Бухать";
    act[8] = "Продолжить танцевать";
    act[9] = "Танцевать с ними";
    act[10] = "Выпить";
    act[11] = "Попытаться отказаться";
    act[12] = "Встать танцевать";
    act[13] = "Пить";
    act[14] = "Сидеть";
    act[15] = "Искать Аню";
    act[16] = "Поздравить Рекса лично";
    act[17] = "Идти";
    act[18] = "Встать раком";
    act[19] = "Поменяться";
    act[20] = "В кухне";
    act[21] = "В туалете";
    act[22] = "В комнате";
    act[23] = "Повернуться";
    act[24] = "За Аней";
    act[25] = "Ждать";
    act[26] = "Присоединиться";
    act[27] = "В туалет";
    act[28] = "Я передумала";
    act[29] = "Отойти";
    act[30] = "Идти на вечеринку";
    act[31] = "Пить пиво";
    act[32] = "Далее";
    act[33] = "Проваливай";
    act[34] = "Ну так и быть, только веди себя как можно тише.";
    act[35] = "Лечь спать.";
    act[36] = "Опомниться и снизить темп";
    act[37] = "Идти в ванную";
    act[38] = "Оставить отношения с Колей в секрете и уйти";
    act[39] = "Вы уже сильно завелись и не против тройничка";
    act[40] = "Пойти спать";
    act[41] = "Нет, давай лучше доедим, я голодная";
    act[42] = "Я уж думала ты и не предложишь!";
    act[43] = "Прибраться";
    act[44] = "Выйти";
    act[45] = "Ехать в город";
    act[46] = "Положить вещи и идти по своим делам";
    act[47] = "Одется";
    act[48] = "Секс";
    act[49] = "Сосать";
    act[50] = "Зайти в квартиру";
    act[51] = "Оттащить ее и сделать внушение";
    act[52] = "Незаметно кинуть в ее бокал таблетку";
    act[53] = "Ехать";
    act[54] = "Просто хорошо провести время";
    act[55] = "Соблазнить Диму";
    return act[id];
}
