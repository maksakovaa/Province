#include "sister.h"
#include "../../game.h"
#include "../../Functions.h"
#include "../../menu/buttons.h"

Sister::Sister(Game* ptr): root(ptr) {}

void Sister::start(QString arg)
{
    makeActBtn("back_to_loc",act(0));
    age = root->getAge() + 2;
    root->gNPC(sister).talk_max_count = root->gNPC(sister).relation / 20;
    root->rendNpcProfile(sister);
    root->startEvent(eFamily, "sister_sheduler");
    if(root->vEvent(sister_book) < 0)
        root->vEvent(sister_book) = root->sisBook();
    if(root->gNPC(sister).location == lkuhrpar)
    {
        root->incTime(1);
        root->addText(str(0));
        return;
    }
    if(root->gNPC(sister).location == lshop)
    {
        root->addText(str(1));
        makeActBtn("shop",act(0));
    }
    if(root->gNPC(sister).relation >= 80 && root->getHour() >= 22 && (root->vEvent(sisterKnowSlut) + root->vEvent(sisterKnowMastr) + root->novel_readed()) > 0 && root->vEvent(reading_erotic_enable) == 0)
        root->erotic_enable();
    if(root->vQuest(qwKolka) >= 5 && root->getWeek() == 0 && root->getHour() == 10 && root->vEvent(family_trip) == 0 && root->vStatus(money) >= 10000)
        makeActBtn("cityShopping",act(1));
    if(root->vQuest(qwKolka) == 10 && root->vQuest(qwMisha) == 0)
        makeActBtn("askMihail",act(2));
    if(root->vQuest(wedding) == 1 && root->vEvent(family_trip) == 0)
        makeActBtn("askParty1",act(3));
    if(root->vQuest(anayslut) == 1 && root->vEvent(family_trip) == 0)
        makeActBtn("askParty2",act(3));
    if(root->vEvent(sisInitRelocDay) >= root->vStatus(daystart) && root->vQuest(wedding) == 2)
        makeActBtn("talkReloc",act(4));
    if((root->getHour() == 10 || root->getHour() == 11) && (root->getWeek() == 0 || root->getWeek() == 6))
    {
        root->setImage(media(0));
        root->setText(str(44));
        return;
    }
    root->startEvent(eDinSister,"piercing");
    if(root->getHour() >= 7)
    {
        if(root->isNude())
        {
            if(root->vQuest(qwSisterLesbi) == 0)
                root->addText(str(4));
            else
                root->addText(str(5));
        }
        if(root->vEvent(pregTalkSister) == 0 && root->PregVisibility())
        {
            root->addText(str(6));
            root->vEvent(pregTalkSister) = 1;
        }
        if(root->vEvent(pregTalkSister) == 0 && root->PregVisibility())
        {
            root->addText(str(7));
            root->vEvent(pregTalkSister) = 1;
        }
        if(root->vStatus(cumLips) > 1 || root->vStatus(cumFace) > 0 || root->vStatus(cumFrot) > 0)
        {
            if(root->repGet() < 3 && root->vEvent(sisterKnowSlut) == 0)
            {
                root->vEvent(sisterKnowSlut) = 1;
                root->addText(str(8));
            }
            else if(root->repGet() >= 3 && root->vEvent(sisterKnowSlut) == 0)
            {
                root->vEvent(sisterKnowSlut) = 1;
                root->addText(str(9));
            }
            else if(root->repGet() >= 3 && root->vEvent(sisterKnowSlut) > 0)
            {
                root->addText(str(10));
            }
        }
        if(root->getHour() == 16 || ((root->getWeek() > 5 || root->getWeek() == 0) && root->getHour() >= 12 && root->getHour() < 16))
        {
            root->startEvent(eSisterQW, "meet_sister");
            return;
        }
        if(root->gNPC(sister).relation > 65 && root->isMesec() && root->vStatus(pregnancy) == 0 && root->getItmCount(iTampon) == 0)
            makeActBtn("askTampon",act(5));
        if(root->gNPC(sister).talk_count < 100)
            makeActBtn("talkSis",act(6));
        root->startEvent(eKolkaPrince, "main");
        if(root->vQuest(wedding) < 1)
        {
            if(root->vQuest(qwSisterLesbi) == 2)
            {
                root->incTime(5);
                root->setImage(media(5));
                root->setText(str(17));
                root->vQuest(qwSisterLesbi) = 3;
                makeActBtn("sister",act(11));
                return;
            }
            if(root->vQuest(qwSisterBoy) == 0 && root->gNPC(sister).relation >= 40)
                makeActBtn("askBoyfriend",act(13));
            if(root->vQuest(qwSisterBoy) >= 2 && root->gNPC(sister).relation >= 40 && root->vQuest(qwSisterTrio) > -1 && root->vEvent(sisBoyTrioDayOtkaz) <= root->vStatus(daystart) && root->vQuest(qwSisBoyParty) < 2)
                makeActBtn("talkRoma",act(20));
            if(((root->vEvent(sisBoyDay) + 1 == root->vStatus(daystart) && root->getHour() > 18) || root->vEvent(sisBoyDay) + 1 < root->vStatus(daystart)) &&  root->vEvent(sisThank) == 1)
            {
                if(root->vQuest(qwSisterBoy) == 9 || root->vQuest(qwSisterBoy) == 7 || root->vQuest(qwSisterBoy) == 5 || root->vQuest(qwSisterBoy) == 3)
                    root->vQuest(qwSisterBoy) -= 1;
                root->vEvent(sisBoyDay) = 0;
                root->vEvent(sisThank) = 0;
                root->setImage(media(7));
                root->setText(str(38));
                if(root->vQuest(qwSisterTrio) != 1)
                    root->addText(str(39));
                else
                {
                    root->addText(str(40));
                    root->vQuest(qwSisterTrio) = 0;
                }
                makeActBtn("sister",act(11));
            }
        }
        if(root->vEvent(sisterKnowMastr) > 0 && root->vQuest(qwSister) == 0)
        {
            root->vQuest(qwSister) = 1;
            root->rendNpcProfile(sister);
            root->setText(str(41));
            makeActBtn("back_to_loc",act(0));
        }
        if(root->gNPC(sister).relation >= 80 && root->vEvent(sisterKnowSlut) > 0)
            makeActBtn("talkSex",act(21));
    }
    else
    {
        root->addText(str(43));
    }
}

void Sister::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"Sister");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &Sister::actionHandler);
    root->addActions(btn);
}

void Sister::actionHandler(QString action)
{
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "shop")
        root->changeLoc(lshop);
    if(action == "cityShopping")
        root->startEvent(eSisterQW,"incest_event6shop");
    if(action == "askMihail")
        root->startEvent(eSisterQW,"incest_event10sub");
    if(action == "askParty1")
        root->startEvent(eSisterQW,"incest_dialog1");
    if(action == "askParty2")
        root->startEvent(eSisterQW,"incest_dialog2");
    if(action == "talkReloc")
        root->startEvent(eSisterQW,"incest_dialog3");
    if(action == "sister")
        root->startEvent(eSister);
    if(action == "askTampon")
    {
        root->addText(str(11));
        root->addItem(iTampon,3);
        root->incTime(3);
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "talkSis")
    {
        root->incTime(getRandInt(10,15));
        root->rendNpcProfile(sister);
        if(root->vQuest(wedding) < 1)
        {
            // sisboyparty
            // -1 - не пошла на вечеринку
            // 0 - не знает о вечеренках
            // 1 - знает о вечеринках
            // 2 - согласилась пойти на вечеринку
            if(root->vQuest(qwSisBoyParty) >= 2 && root->vEvent(sisBoyParty) == 1 && root->getWeek() > 0 && root->getWeek() < 5)
            {
                root->addText(str(12));
                makeActBtn("sisBoyPartyAccept",act(7));
                makeActBtn("sisBoyPartyLearn",act(8));
                if(root->vStatistics(bronzBeg) > 0 || root->vStatistics(silverBeg) > 0 || root->vStatistics(goldBeg) > 0)
                    makeActBtn("sisBoyPartyBeg",act(9));
                if(root->vSkill(volleyball) >= 85)
                    makeActBtn("sisBoyPartyVolley",act(10));
            }
            root->startEvent(eDinSister, "talk");
            makeActBtn("sister",act(12));
        }
    }
    if(action == "sisBoyPartyAccept")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = 2;
        root->setImage(media(1));
        root->setText(str(13));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyAccept2")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = 2;
        root->setImage(media(1));
        root->setText(str(21));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyLearn")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(2));
        root->setText(str(14));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyLearn2")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(2));
        root->setText(str(22));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyBeg")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(3));
        root->setText(str(15));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyBeg2")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(3));
        root->setText(str(23));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyVolley")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(4));
        root->setText(str(16));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyPartyVolley2")
    {
        root->incTime(5);
        root->vEvent(sisBoyParty) = -1;
        root->setImage(media(4));
        root->setText(str(24));
        makeActBtn("sister",act(11));
    }
    if(action == "askBoyfriend")
    {
        root->incTime(5);
        root->changeRep('+',sister);
        root->vQuest(qwSisterBoy) = 1;
        root->rendNpcProfile(sister);
        root->addText(str(18));
        makeActBtn("sister",act(11));
    }
    if(action == "talkRoma")
    {
        root->incTime(5);
        root->vEvent(sisBoyRand) = getRandInt(1,10);
        if(root->vEvent(sisBoyTrio) >= 5 && root->vEvent(sisBoyParty) == 0 && root->getWeek() > 0 && root->getWeek() < 5)
        {
            root->incTime(5);
            root->vEvent(sisBoyParty) = 1;
            root->setImage(media(6));
            root->setText(str(20));
            makeActBtn("sisBoyPartyAccept2",act(7));
            makeActBtn("sisBoyPartyLearn2",act(8));
            if(root->vStatistics(bronzBeg) > 0 || root->vStatistics(silverBeg) > 0 || root->vStatistics(goldBeg) > 0)
                makeActBtn("sisBoyPartyBeg2",act(9));
            if(root->vSkill(volleyball) >= 85)
                makeActBtn("sisBoyPartyVolley2",act(10));
        }
        else if(root->vEvent(sisBoyRand) >= 8 && root->vQuest(qwSisterBoy) == 2 && root->vEvent(sisBoyDay) != root->vStatus(daystart))
        {
            root->setImage(media(8));
            root->setText(str(25));
            makeActBtn("sisBoyDateYes",act(14));
            makeActBtn("sisBoyDateNo",act(15));
        }
        else if(root->vEvent(sisBoyRand) >= 8 && (root->vQuest(qwSisterBoy) == 4 || root->vQuest(qwSisterBoy) == 6 || root->vQuest(qwSisterBoy) == 8) && root->vEvent(sisBoyDay) != root->vStatus(daystart) && root->vEvent(sisBoyParty) == 0)
        {
            root->setImage(media(16));
            root->setText(str(28));
            makeActBtn("sisBoyDateYes2",act(14));
            makeActBtn("sisBoyDateNo2",act(15));
        }
        else if(root->vEvent(sisBoyRand) >= 8 && root->vQuest(qwSisterBoy) == 9 && root->vQuest(qwSisterLesbi) == 4 && root->vQuest(qwSisterTrio) == 0 && root->vEvent(sisBoyTrio) < 5)
        {
            if(root->vEvent(sisBoyDay) == root->vStatus(daystart))
                sisBoyDayText = act(16);
            if(root->vEvent(sisBoyDay) + 1 == root->vStatus(daystart))
                sisBoyDayText = act(17);
            root->setImage(media(16));
            if(root->vEvent(sisBoyTrio) == 0)
                root->setText(str(31));
            else
                root->setText(str(32));
            makeActBtn("trioAccept",act(18));
            makeActBtn("trioDecline",act(19));
        }
        else
        {
            root->incTime(10);
            root->changeRep('+',sister);
            int talkRand = getRandInt(0,10);
            if(talkRand < 9)
                root->setText(str(45 + talkRand));
            else if(talkRand == 9)
            {
                if(root->vEvent(reksLike) == 0)
                {
                    root->vEvent(reksLike) = 1;
                    root->gNPC(AleksLobov).relation = 50;
                    root->vQuest(qwRexSisTalk) = 0;
                    root->vEvent(rexPark) = 0;
                    root->vEvent(rexCar) = 0;
                    root->addText(str(35));
                }
                else
                    root->addText(str(36));
            }
            else if(talkRand == 10)
                root->setText(str(53));
            makeActBtn("sister",act(11));
        }

    }
    if(action == "sisBoyDateYes")
    {
        root->incTime(5);
        root->changeRep('+',sister,10);
        root->vEvent(sisThank) += 1;
        root->vQuest(qwSisterBoy) = 3;
        root->vEvent(sisBoyDay) = root->vStatus(daystart);
        root->setImage(media(10));
        root->setText(str(26));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyDateNo")
    {
        root->incTime(5);
        root->changeRep('-',sister,10);
        root->vEvent(sisBoyDay) = root->vStatus(daystart);
        root->setImage(media(11));
        root->setText(str(27));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyDateYes2")
    {
        root->incTime(5);
        root->changeRep('+',sister,10);
        root->vEvent(sisThank) += 1;
        if(root->vQuest(qwSisterBoy) == 4 || root->vQuest(qwSisterBoy) == 6 || root->vQuest(qwSisterBoy) == 8)
            root->vQuest(qwSisterBoy) += 1;
        root->vEvent(sisBoyDay) = root->vStatus(daystart);
        root->setImage(media(10));
        root->setText(str(29));
        makeActBtn("sister",act(11));
    }
    if(action == "sisBoyDateNo2")
    {
        root->incTime(5);
        root->changeRep('-',sister,10);
        root->vEvent(sisBoyDay) = root->vStatus(daystart);
        root->setImage(media(11));
        root->setText(str(30));
        makeActBtn("sister",act(11));
    }
    if(action == "talkSex")
    {
        if((root->getWeek() > 0 && root->getWeek() < 6 && root->getHour() < 18) ||
            ((root->getWeek() > 5 || root->getWeek() == 0)) && root->getHour() >= 11 && root->getHour() < 18)
        {
            root->rendNpcProfile(sister);
            root->setText(str(42));
            makeActBtn("bedrPar",act(0));
            return;
        }
        root->incTime(getRandInt(10,15));
        root->vStatus(horny) += getRandInt(5,10);
        root->changeRep('+',sister);
        root->startEvent(eDinSister,"sex_stories");
        makeActBtn("sister",act(0));
    }
    if(action == "trioAccept")
    {
        root->vQuest(qwSisterTrio) = 1;
        root->incTime(5);
        root->changeRep('+',sister,10);
        root->setImage(media(43));
        root->setText(str(33));
        makeActBtn("sister",act(11));
    }
    if(action == "trioDecline")
    {
        root->vQuest(qwSisterTrio) = -1;
        root->vEvent(sisBoyTrioDayOtkaz) = root->vStatus(daystart) + 3;
        root->incTime(5);
        root->gNPC(sister).relation = 0;
        root->vQuest(qwSisterBoy) = 2;
        root->vEvent(sisThank) = 0;
        root->setImage(media(44));
        root->setText(str(34));
        makeActBtn("sister",act(11));
    }
}

QString Sister::media(int id)
{
    QString med[68];
    med[0] = "data/npc/pavlovo/sister/progulka.jpg";
    med[1] = "/home/maks/Документы/Province-lin/data/sex/sisPartyQW/sisboyQWParty_2.jpg";
    med[2] = "/home/maks/Документы/Province-lin/data/sex/sisPartyQW/sisboyQWParty_3.jpg";
    med[3] = "/home/maks/Документы/Province-lin/data/sex/sisPartyQW/sisboyQWParty_4.jpg";
    med[4] = "/home/maks/Документы/Province-lin/data/sex/sisPartyQW/sisboyQWParty_5.jpg";
    med[5] = "/home/maks/Документы/Province-lin/data/sex/sisBoyQW/sisboyQW_24.jpg";
    med[6] = "data/sex/sisPartyQW/sisboyQWParty_1.jpg";
    med[7] = "data/sex/sisBoyQW/sisboyQW_00.jpg";
    med[8] = "data/sex/sisBoyQW/sisboyQW_01.jpg";
    med[9] = "data/sex/sisBoyQW/sisboyQW_02.jpg";
    med[10] = "data/sex/sisBoyQW/sisboyQW_03.jpg";
    med[11] = "data/sex/sisBoyQW/sisboyQW_04.jpg";
    med[12] = "data/sex/sisBoyQW/sisboyQW_05.jpg";
    med[13] = "data/sex/sisBoyQW/sisboyQW_06.jpg";
    med[14] = "data/sex/sisBoyQW/sisboyQW_07.jpg";
    med[15] = "data/sex/sisBoyQW/sisboyQW_08.jpg";
    med[16] = "data/sex/sisBoyQW/sisboyQW_09.jpg";
    med[17] = "data/sex/sisBoyQW/sisboyQW_10.webm";
    med[18] = "data/sex/sisBoyQW/sisboyQW_11.jpg";
    med[19] = "data/sex/sisBoyQW/sisboyQW_12.jpg";
    med[20] = "data/sex/sisBoyQW/sisboyQW_13.jpg";
    med[21] = "data/sex/sisBoyQW/sisboyQW_14.jpg";
    med[22] = "data/sex/sisBoyQW/sisboyQW_15.jpg";
    med[23] = "data/sex/sisBoyQW/sisboyQW_16.jpg";
    med[24] = "data/sex/sisBoyQW/sisboyQW_17.jpg";
    med[25] = "data/sex/sisBoyQW/sisboyQW_18.jpg";
    med[26] = "data/sex/sisBoyQW/sisboyQW_19.jpg";
    med[27] = "data/sex/sisBoyQW/sisboyQW_20.jpg";
    med[28] = "data/sex/sisBoyQW/sisboyQW_21.jpg";
    med[29] = "data/sex/sisBoyQW/sisboyQW_22.jpg";
    med[30] = "data/sex/sisBoyQW/sisboyQW_23.jpg";
    med[31] = "data/sex/sisBoyQW/sisboyQW_24.jpg";
    med[32] = "data/sex/sisBoyQW/sisboyQW_25.jpg";
    med[33] = "data/sex/sisBoyQW/sisboyQW_26.jpg";
    med[34] = "data/sex/sisBoyQW/sisboyQW_27.jpg";
    med[35] = "data/sex/sisBoyQW/sisboyQW_28.jpg";
    med[36] = "data/sex/sisBoyQW/sisboyQW_29.jpg";
    med[37] = "data/sex/sisBoyQW/sisboyQW_30.jpg";
    med[38] = "data/sex/sisBoyQW/sisboyQW_31.jpg";
    med[39] = "data/sex/sisBoyQW/sisboyQW_32.jpg";
    med[40] = "data/sex/sisBoyQW/sisboyQW_33.jpg";
    med[41] = "data/sex/sisBoyQW/sisboyQW_34.jpg";
    med[42] = "data/sex/sisBoyQW/sisboyQW_35.jpg";
    med[43] = "data/sex/sisBoyQW/sisboyQW_36.jpg";
    med[44] = "data/sex/sisBoyQW/sisboyQW_37.jpg";
    med[45] = "data/sex/sisBoyQW/sisboyQW_38.jpg";
    med[46] = "data/sex/sisBoyQW/sisboyQW_39.jpg";
    med[47] = "data/sex/sisBoyQW/sisboyQW_40.jpg";
    med[48] = "data/sex/sisBoyQW/sisboyQW_41.jpg";
    med[49] = "data/sex/sisBoyQW/sisboyQW_42.jpg";
    med[50] = "data/sex/sisBoyQW/sisboyQW_43.jpg";
    med[51] = "data/sex/sisBoyQW/sisboyQW_44.jpg";
    med[52] = "data/sex/sisBoyQW/sisboyQW_45.jpg";
    med[53] = "data/sex/sisBoyQW/sisboyQW_46.jpg";
    med[54] = "data/sex/sisBoyQW/sisboyQW_47.jpg";
    med[55] = "data/sex/sisBoyQW/sisboyQW_48.jpg";
    med[56] = "data/sex/sisBoyQW/sisboyQW_49.jpg";
    med[57] = "data/sex/sisBoyQW/sisboyQW_50.jpg";
    med[58] = "data/sex/sisBoyQW/sisboyQW_51.jpg";
    med[59] = "data/sex/sisBoyQW/sisboyQW_52.jpg";
    med[60] = "data/sex/sisBoyQW/sisboyQW_53.jpg";
    med[61] = "data/sex/sisBoyQW/sisboyQW_54.jpg";
    med[62] = "data/sex/sisBoyQW/sisboyQW_55.jpg";
    med[63] = "data/sex/sisBoyQW/sisboyQW_56.jpg";
    med[64] = "data/sex/sisBoyQW/sisboyQW_57.jpg";
    med[65] = "data/sex/sisBoyQW/sisboyQW_58.jpg";
    med[66] = "data/sex/sisBoyQW/sisboyQW_59.jpg";
    med[67] = "data/sex/sisBoyQW/sisboyQW_60.jpg";
    return med[id];
}

QString Sister::str(int id)
{
    QString str[54];
    str[0] = "<npc>- Света, некогда болтать, я спешу!</npc>";
    str[1] = "<npc>- Света, не мешай мне: не видишь, у меня покупатели.</npc>";
    str[2] = "Я не могу к ней подойти потому, что она спалит меня, что я под кайфом.";
    str[3] = "Меня отпустило и теперь решусь подойти.";
    str[4] = "Сестра смотрит на вас, округлив глаза: <npc>- Света,вот это номер, как тебе не стыдно ходить голышом? Я так не смогла бы.</npc>";
    str[5] = "Сестра смотрит на вас, округлив глаза: <npc>- Света, ты такая раскрепощённая! Я так не смогла бы.</npc>";
    str[6] = "Сестра удивлённо смотрит на ваш животик: <npc>- Света, ты беременная что ли? Ничего себе, сестрёнка! А от кого знаешь хоть?</npc><br><hero>- Ой, сестрёнка, скорее всего папой станет " + root->getBoyName() + ".</hero>";
    str[7] = "Сестра удивлённо смотрит на ваш явно выступающий под одеждой живот: <npc>- Света, ты беременная что ли? Ничего себе, сестрёнка!"
             " А от кого знаешь хоть?</npc><br><hero>- Ой, сестрёнка, скорее всего папой станет " + root->getBoyName() + "</hero>";
    str[8] = "Сестра присматривается к вам: <npc>- Света, а что это?</npc> - Внезапно ее глаза округляются,<npc> - Света, да это же сперма!"
             " Вот так маленькая сестренка, ну и ну! Это хорошо, что я заметила, а если бы мама?!</npc>";
    str[9] = "Сестра присматривается к вам: <npc>- Света, правда говорят, что ты " + root->getNickName() + "</npc>";
    str[10] = "Сестра присматривается к вам: <npc>- Светик, опять тебя кончой обляпали, сходи умойся что ли.</npc>";
    str[11] = "Вы рассказываете сестре о том, что у вас месячные и закончились тампоны. Она понимающе смотрит на вас, приносит несколько"
              " своих и рекомендует вам в следующий раз позаботиться об этом заранее.";
    str[12] = "<npc>- Слушай, Света, в пятницу у Рекса квартира свободна и будет вечеринка - ты пойдёшь?</npc>";
    str[13] = "Вы согласились прийти на вечеринку.<br><npc>- Здорово, Светик, там будет весело. Не забудь найти нас до 17:00, иначе мы"
              " уйдем без тебя.</npc><br>С эти словами вы обнялись и поцеловались с сестрой.";
    str[14] = "Вы отказались прийти на вечеринку:<hero> - Прости Ань, я бы с радостью, но у меня завалы в школе. Контрольные, сочинения,"
              " куча литературы, сама понимаешь...</hero>";
    str[15] = "Вы отказались прийти на вечеринку:<hero> - Я бы с радостью, но у меня соревнования на носу, и я должна тренироваться. "
              "В отличии от тебя, я все-таки мечтаю стать великой спортсменкой...</hero>";
    str[16] = "Вы отказались прийти на вечеринку:<hero> - У меня режим, тренер не разрешает гулять допоздна, да и пить тоже запрещает...</hero>";
    str[17] = "Вы обе смущайтесь после произошедшего ночью, и не смотрите друг другу в глаза, но всё-таки Аня заговаривает с вами:<npc><br>"
              "- Светик,</npc> улыбаясь говорит тебе,<npc> ну ты и дура, я думала мне парни нравятся, а оказывается твои ручки намного "
              "приятней мужских.</npc><br>Вы краснея смотрите на Аню,<hero> - Прости меня, я сильно завелась, и не контролировала себя."
              " Не знаю что на меня нашло...</hero><br><npc>- Ну, я не против, чтоб ты иногда так теряла над собой контроль...</npc>"
              "хитро улыбнулась сестра. Вы тоже улыбнулись ей в ответ...";
    str[18] = "Вы спросили сестру про ее парня. Она стрельнула глазами и улыбнулась:<br><npc>- Ну у меня есть парень. Хотя... ничего "
              "серьезного! Почти!</npc> - гыкнула Анька.<br><hero>- Здорово! </hero>- восхитились вы. <hero>- А можно и я как-нибудь"
              " с вами, а?</hero> - подлизнулись вы к сестре.<br><npc>- Ладно. Ты уже достаточно взрослая</npc> - согласилась та."
              " <npc>- Летом мы на пляже обычно тусим или у ДК. Пока погода позволяет. А если дождь - в кафешке в парке зависаем. "
              "С пяти до девяти - я у Ромки. А уж по тяпницам… по пятницам -</npc> поправилась Анька, <npc>- у Рекса посиделки!"
              "</npc><br><hero>- Ты просто обязана меня с ними познакомить! Ну пожалуйста-а-а, Ань!</hero> - умильно поглядели вы"
              " на сестру. <npc>- Ладно, приходи! </npc>- разрешила Анька.";
    str[20] = "<npc>- Света, ты уже близкий друг нашей компании, а в пятницу у Рекса день рождения, и он попросил меня тебя позвать.</npc>"
              "<br><hero>- Ой, даже не знаю Ань! Мы как-то с ним плохо знакомы, я-то в основном из ваших только с девочками общалась!.</hero>"
              "<br><npc>- Да брось, он очень сильно просил! Мне даже кажется, что ты ему нравишься. Так что ты решила?</npc>";
    str[21] = "Вы согласились прийти на день рождения.<br><npc>- Здорово, Светик, там должно быть весело, а насчет подарка не переживай"
              " - Рекс не любит всё это. Не забудь найти нас до 17:00, иначе мы уйдём без тебя!</npc><br><hero>- Спасибище!</hero>"
              " - расцвели вы. <hero>- Буду!</hero><br>С этими словами вы обнялись и поцеловались с сестрой.";
    str[22] = "Вы отказались прийти на день рождения.<br><hero>- Прости Ань, я бы с радостью, но у меня завалы в школе. Контрольные, сочинения,"
              " куча литературы, сама понимаешь...</npc>";
    str[23] = "Вы отказались прийти на день рождения.<br><hero>- Я бы с радостью, но у меня соревнования на носу, я должна тренироваться."
              " В отличии от тебя, я все-таки мечтаю стать великой спортсменкой.</hero><br><npc>- Ну была бы честь предложена!</npc>"
              " - фыркнула Анька.<npc> - Может в следующий раз.</npc>";
    str[24] = "Вы отказались прийти на день рождения.<br><hero>- У меня режим, тренер не разрешает гулять допоздна, да и пить тоже запрещает..."
              " - понурились вы.</hero>";
    str[25] = "Аня долго и нерешительно смотрит на вас, и все же решается спросить:<br><npc>- Светик, не могла бы ты завтра после шести вечера "
              "пойти часик погулять где-нибудь? Мы тут с Ромкой хотим немного... ну... посидеть, ну ты понимаешь о чем я!?</npc>"
              "<br>Сестра, чуть покраснев, смотрит на вас умоляющим взглядом.";
    str[26] = "<hero>- Конечно, сестренка! Я всё понимаю! Погуляю допоздна. Только громко не шумите: вы же не хотите порушить тонкую психику "
              "братца? Да и мама с отцом тоже...</hero>";
    str[27] = "<hero>- Извини Анька, мне по вечерам учиться надо</hero> - отказали вы сестре.<br><npc>- Ну ладно... </npc>- сестра сердито "
              "развернулась от вас и уткнулась в свою книжку.";
    str[28] = "<npc>- В прошлый раз ты нас с Ромкой так сильно выручила, спасибо тебе огромное!</npc> - поблагодарила вас сестра.<br>"
              "<npc>- Мы тут завтра снова хотим посидеть у меня. Ты не против прогуляться часок?</npc> - попросила Аня.";
    str[29] = "<hero>- Не вопрос, сестрёнка! Погуляю! - понимающе ухмыльнулись вы. - Только громко не шумите! Вы же не хотите, чтобы наш "
              "братишка лопнул от спермотоксикоза? </hero>- хихикнули вы.<br><npc>- Ты у меня самая лучшая!</npc> - обняла сестра вас.";
    str[30] = "<hero>- Извини Ань, мне по вечерам нужно учиться.</hero><br><npc>- Ну и ладно!</npc> - Аня сердито развернулась от вас и "
              "уткнулась в свою книжку.";
    str[31] = "<npc>- Сестрёнка, мы тут с Ромкой долго думали и... даже не знаю как сказать...</npc> - смущённо замялась Анька.<br>"
              "<hero>- Ну же, не тяни кота за... лапу! Ну чего ещё?</hero><br><npc>- В общем, ммм... мы... это... мы хотим, чтобы ты"
              " " + sisBoyDayText + " вечером к нам присоединилась!</npc> - зарделась сестра.";
    str[32] = "<npc>- Света, слушай, тут такое дело: как тебе наш... наше... ну... Ну, как, тебе понравилось в прошлый раз? Нам с Ромой очень!"
              "</npc><br>Вы ничего не говорите, и только хитро улыбаетесь, глядя на сестру.<br><npc>- Мы хотим " + sisBoyDayText + " вечером"
              " повторить наши игры. Это было ОФИГЕННО!</npc> - облизнула губы Анька.";
    str[33] = "Вы соглашаетесь на предложение Ани.<br><hero>- Ну вы и развратники! Можно. Это будет очень интересно</hero> - согласились вы."
              "<br>Сестра радостно обнимает вас:<br><npc>- Света - ты у меня - самая лучшая!</npc>";
    str[34] = "Вы отказываетесь от непристойного предложения сестры.<br><hero>- Извращенцы! Да пошли вы, больные ублюдки!</hero>"
              "<br>Вы ссоритесь с сестрой, она отворачивается от вас и не хочет больше говорить.";
    str[35] = "Анька долго рассказывает про их компанию, про Ромкиных друзей.<br>";
    str[36] = "<npc>- Вот познакомишься - может, и встречаться с кем из них начнёшь! Они классные, вот увидишь!</npc><br>"
              "<hero>- Ну... Вообще-то Рекс ничего так.</hero><br><npc>- Хмм... Он парень конечно симпотный, правда иногда немного странно"
              " себя ведет. Мне тут Ромка недавно рассказал, что Рекс просто тащится от женских ног. Был случай когда Рекс без прав ехал"
              " на отцовской машине и загляделся на идущую по тротуару девушку, которая шла в чулочках и коротенькой юбочке. Представь, он"
              " так засмотрелся, что не заметил впереди стоящий на светофоре фургон. Самое смешное - фирмы «Rex»! Так и впендюрился в него!"
              " Машину помял. Так его и прозвали с тех пор \"Рекс\"</npc> - засмеялась Аня. <npc>- Постоянно замечаю как он пялится на мои"
              " ноги. Особенно когда я в открытой обуви. Фетишист, блин!</npc>";
    str[37] = "Вы расспрашиваете сестру про Ромку. Она долго и с удовольствием рассказывает какой он добрый, отзывчивый и мужественный.";
    str[38] = "Весёлая Анька внезапно подбегает к вам и обвивает вашу шею.";
    str[39] = "<npc>- Сестрёнка, я тебя обожаю! Мы провели с Ромкой прекрасный вечер!</npc><br><hero>- Да рада я за вас, отцепись уже от меня,"
              " задушишь!</hero> - и счастливая Аня отпустила вас, звонко чмокнув в щёчку.";
    str[40] = "<npc>- Сестрёнка, я тебя обожаю! Офигенно вышел наш совместный вечер с Ромкой!</npc><br><hero>- Да отцепись уже от меня, "
              "задушишь</hero>! - со смехом отпихиваетесь вы. Счастливая сестрица отпустила вас, звонко чмокнув в щёчку.";
    str[41] = "Аня смотрит на вас и смеется:<br><npc>- Ну, Светик, ты и даёшь! Захожу в комнату - а она тут наяривает! "
              "Парня себе заведи, что ли...\"</npc>";
    str[42] = "<npc>- Мне надо бежать, давай поболтаем позже.</npc>";
    str[43] = "<npc>- Все, Света, спать пора.</npc>";
    str[44] = "По комнате ходит, собираясь на прогулку, ваша сестра Аня. Она любуется собой в зеркале и вертит задом, пытаясь разглядеть "
              "себя получше. Аня, не поворачиваясь к вам, говорит: <br><npc>- Светик, если надумаешь погулять, то я после работы возле клуба"
              " с друзьями или на пляже. Или в кафешку в парке пойдём если будет дождь. С пяти до девяти вечера - я у своего.</npc>";

    str[45] = "Вы расспрашиваете сестру про Ромку, она долго и с удовольствием говорит какой он добрый, отзывчивый и мужественный.";
    str[46] = "Анька рассказывает, как до неё Ромка встречался с какой-то мымрой, и после расставания та долго названивала ему, и из-за"
              " этого Аня сильно ругалась и ревновала.";
    str[47] = "Однажды они вместе с Ромкой были в кино, и они заметили как на последних рядах девушка сосала парню, и что Ромка предложил"
              " ей как-нибудь сделать то же самое.";
    str[48] = "Аня ругается, что Рома слишком много пьёт пива, не дарит подарки, и вообще мало уделяет ей времени.";
    str[49] = "Аня рассказывает, что Ромка предложил ей секс втроём с другой девушкой, на что она сильно обиделась и неделю не общалась с ним.";
    str[50] = "Анька в подробностях с увлечением рассказывает вам про большое достоинство Ромки, и если бы не оно, то они бы давно расстались.";
    str[51] = "Анька делится с вами по секрету, что её любимая поза \"наездницей\", а Ромке больше нравится \"раком\".";
    str[52] = "Вы говорите с сестрой на очень сокровенные темы, и она смущенно говорит, что ей не нравится глотать сперму, но Ромку"
              " это сильно заводит, и она ради него готова глотать.";
    str[53] = "Аня говорит, что вы очень понравились Роме.";
    return str[id];
}

QString Sister::act(int id)
{
    QString act[22];
    act[0] = "Отойти";
    act[1] = "Позвать в город на шопинг";
    act[2] = "Спросить про Михаила";
    act[3] = "Спросить о вечеринке";
    act[4] = "Поговорить о переезде";
    act[5] = "Попросить тампон";
    act[6] = "Болтать";
    act[7] = "Скажи, что я буду";
    act[8] = "Извини, у меня учеба";
    act[9] = "Некогда, у меня соревнования";
    act[10] = "У меня волейбол";
    act[11] = "Закончить";
    act[12] = "Далее";
    act[13] = "Спросить про ее парня";
    act[14] = "Конечно";
    act[15] = "Нет";
    act[16] = "завтра";
    act[17] = "сегодня";
    act[18] = "Согласиться";
    act[19] = "Отказаться";
    act[20] = "Говорить о Роме";
    act[21] = "Поговорить о сексе";
    return act[id];
}
