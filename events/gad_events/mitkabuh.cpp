#include "mitkabuh.h"
#include "../eventhandler.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

MitkaBuh::MitkaBuh(EventHandler* ptr): root(ptr) {}

void MitkaBuh::start(QString arg)
{
    if(root->gVEvent(miraingop) == 0 && root->vAddict(alko) < 8)
    {
        root->setImage(media(0));
        root->setDesc(str(0));
        makeActBtn("drink1",act(0));
    }
    else if(root->gVEvent(miraingop) == 0 && root->gVEvent(gadriver_gang) < 3 && root->vAddict(alko) >= 8 && (root->gVEvent(mitkasextimes) > 0 || root->vSkill(domination) <= -10))
    {
        int sextimes = root->gVEvent(mitkasextimes);
        if(root->gVEvent(mitkadaybuh) != root->vStatus(daystart))
        {
            root->sVEvent(mitkadaybuh,root->vStatus(daystart));
            root->setImage(media(0));
            if(sextimes < 13) root->addDesc(str(2));
            else root->addDesc(str(3));
            if(sextimes < 3)
                makeActBtn("mitkaVag1",act(2));
            if(sextimes >= 3 && sextimes < 10)
            {
                int tmp = getRandInt(0,5);
                if(tmp < 3) makeActBtn("mitkaDepOnMesec1",act(2));
                else if(tmp >= 3 && tmp < 5) makeActBtn("mitkaBlowJob1",act(4));
                else if(tmp == 5) makeActBtn("mitkaAnal1",act(2));
            }
            if(sextimes == 10)
                makeActBtn("drunkSex1",act(2));
            if(sextimes == 11)
            {
                if(getRandInt(0,5) < 5)
                    makeActBtn("mitkaDepOnMesec4",act(6));
                else
                    makeActBtn("mitkaBlowJob2",act(4));
            }
            if(sextimes == 12)
            {
                if(getRandInt(0,5) < 4)
                    makeActBtn("mitkaDepOnMesec4",act(6));
                else
                    makeActBtn("mitkaBlowJob3",act(4));
            }
            if(sextimes == 13)
            {
                int tmp = getRandInt(0,5);
                if(tmp < 3)
                    makeActBtn("mitkaDepOnMesec4",act(6));
                else if(tmp == 3)
                    makeActBtn("mitkaBlowJob4",act(4));
                else if(tmp == 4)
                    makeActBtn("doubleBlowJob1",act(4));
                else if(tmp == 5)
                    makeActBtn("drunkSex2",act(9));
            }
            if(sextimes == 14)
            {
                int tmp = getRandInt(0,5);
                if(tmp < 2)
                    makeActBtn("mitkaBlowJob4",act(4));
                if(tmp == 2)
                    makeActBtn("mitkaDepOnMesec4",act(6));
                if(tmp == 3)
                    makeActBtn("doubleBlowJob1",act(4));
                if(tmp == 4)
                    makeActBtn("drunkSex2",act(9));
                if(tmp == 5)
                    makeActBtn("drunkSex3",act(2));
            }
            if(sextimes >= 15)
            {
                int tmp = getRandInt(0,5);
                if(tmp == 0) makeActBtn("mitkaBlowJob4",act(4));
                if(tmp == 1) makeActBtn("mitkaDepOnMesec4",act(6));
                if(tmp == 2) makeActBtn("doubleBlowJob1",act(4));
                if(tmp == 3) makeActBtn("drunkSex2",act(9));
                if(tmp == 4) makeActBtn("drunkSex4",act(2));
                if(tmp == 5) makeActBtn("drunkSex5",act(11));
            }
        }
        else
        {
            root->setImage(media(0));
            if(root->gVEvent(mirasextimes) < 12)
                root->setDesc(str(28));
            else
                root->setDesc(str(29));
            makeActBtn("gadukino",act(3));
        }
    }
    else if(root->gVEvent(miraingop) == 0 && root->vAddict(alko) >= 8 && root->gVEvent(mitkasextimes) == 0 && (root->vSkill(domination) > -10 || root->gVEvent(gadriver_gang) >= 3))
    {
        root->setImage(media(0));
        root->setDesc(str(26));
        makeActBtn("gadukino",act(3));
    }
    else if(root->gVEvent(miraingop) == 1 && root->gVQuest(miragopQW) > 0)
    {
        root->setImage(media(0));
        root->setDesc(str(27));
        if(root->vAddict(alko) >= 8 && root->gVEvent(gadriver_gang) < 3 && (root->gVEvent(mirasextimes) > 0 || root->gVQuest(miragopQW) > 10))
        {
            root->setImage(media(0));
            root->setDesc(str(2));
            if(root->gVEvent(mitkasextimes) < 10)
            {
                int tmp = getRandInt(0,5);
                if(tmp < 3) makeActBtn("mitkaDepOnMesec1",act(2));
                if(tmp >= 3 && tmp < 5) makeActBtn("mitkaBlowJob1",act(4));
                if(tmp == 5) makeActBtn("mitkaAnal1",act(2));
            }
            else if(root->gVEvent(mitkasextimes) == 10)
            {
                root->incTime(5);
                root->setImage(media(13));
                root->setDesc(str(11));
                if(root->vSkill(domination) < 0)
                    makeActBtn("mitkaDepOnMesec2",act(6));
                else
                    makeActBtn("drunkSex6",act(7));
            }
            else if(root->gVEvent(mitkasextimes) == 11)
            {
                if(getRandInt(1,3) < 3)
                    makeActBtn("mitkaDepOnMesec4",act(6));
                else
                    makeActBtn("mitkaBlowJob5",act(4));
            }
            else if(root->gVEvent(mitkasextimes) == 12)
            {
                if(getRandInt(1,3) < 3) makeActBtn("mitkaDepOnMesec4",act(6));
                else makeActBtn("mitkaBlowJob6",act(4));
            }
            else if(root->gVEvent(mitkasextimes) == 13)
            {
                int tmp = getRandInt(1,4);
                if(tmp == 1) makeActBtn("mitkaDepOnMesec4",act(6));
                if(tmp == 2) makeActBtn("mitkaBlowJob4",act(4));
                if(tmp == 3) makeActBtn("doubleBlowJob1",act(4));
                if(tmp == 4) makeActBtn("drunkSex2",act(9));
            }
            else if(root->gVEvent(mitkasextimes) == 14)
            {
                int tmp = getRandInt(1,5);
                if(tmp == 1) makeActBtn("mitkaBlowJob4",act(4));
                if(tmp == 2) makeActBtn("mitkaDepOnMesec4",act(6));
                if(tmp == 3) makeActBtn("doubleBlowJob1",act(4));
                if(tmp == 4) makeActBtn("drunkSex2",act(9));
                if(tmp == 5) makeActBtn("drunkSex4",act(2));
            }
            else if(root->gVEvent(mitkasextimes) >= 15)
            {
                int tmp = getRandInt(0,5);
                if(tmp == 0) makeActBtn("mitkaBlowJob4",act(4));
                if(tmp == 1) makeActBtn("mitkaDepOnMesec4",act(6));
                if(tmp == 2) makeActBtn("doubleBlowJob1",act(4));
                if(tmp == 3) makeActBtn("drunkSex2",act(9));
                if(tmp == 4) makeActBtn("drunkSex4",act(2));
                if(tmp == 5) makeActBtn("drunkSex5",act(11));
            }
        }
        else if(root->gVEvent(miralko) >= 8)
        {
            if(root->gVQuest(miragopQW) == 5)
            {
                root->incTime(5);
                root->setImage(media(13));
                root->setDesc(str(30));
                makeActBtn("miraWish2",act(12));
            }
            else
            {
                root->uVEvent(mirasextimes,1);
                root->incTime(10);
                root->setImage(media(13));
                root->setDesc(str(32));
                makeActBtn("exit2",act(3));
            }
        }
        else
        {
            if(order == 0) makeActBtn("drink2",act(0));
            if(order == 2) makeActBtn("drinkMira",act(13));
            if(order == 1) makeActBtn("drink2",act(14));
        }
    }
}

void MitkaBuh::actionHandler(QString action)
{
    if(action == "drink1")
    {
        root->incTime(10);
        root->fnAlko(4);
        root->setImage(media(0));
        root->setDesc(str(1));
        makeActBtn("mitkabuh",act(1));
    }
    if(action == "drink2")
    {
        root->fnAlko(getRandInt(3,5));
        order = 2;
        root->setImage(media(24));
        root->setDesc(str(33));
        makeActBtn("mitkabuh",act(1));
    }
    if(action == "drinkMira")
    {
        if(root->gVEvent(gadriver_gang) < 3 && (root->gVQuest(miragopQW) > 10 || root->gVEvent(mitkasextimes) > 0))
            root->uVEvent(miralko,getRandInt(1,4));
        else
            root->uVEvent(miralko,getRandInt(3,4));
        root->incTime(15);
        order = 1;
        mirapiss = getRandInt(0,10);
        if(root->gVQuest(miragopQW) >= 8 && mirapiss <= 2)
        {
            root->incTime(5);
            if(root->gVQuest(miragopQW) < 10)
                root->uVQuest(miragopQW,1);
            root->setImage(media(26));
            root->setDesc(str(35));
            if(root->gVQuest(miragopQW) == 10)
            {
                root->incTime(5);
                root->setImage(media(0));
                root->setDesc(str(36));
                if(root->gVEvent(miralko) >= 4)
                {
                    root->addDesc(str(38));
                    makeActBtn("watchMiraBj1",act(12));
                }
                else
                {
                    root->addDesc(str(37));
                    makeActBtn("mitkabuh",act(15));
                }

            }
            makeActBtn("mitkabuh",act(15));
        }
        else if(root->gVQuest(miragopQW) >= 11 && mirapiss >= 3 && mirapiss < 6)
        {
            if(root->gVEvent(miralko) >= 4)
            {
                root->incTime(5);
                if(root->gVQuest(miragopQW) < 30)
                    root->uVQuest(miragopQW,1);
                root->setImage(media(32));
                root->setDesc(str(44));
                makeActBtn("miraSex1",act(12));
            }
            else
            {
                root->incTime(5);
                if(root->gVQuest(miragopQW) < 20)
                    root->uVQuest(miragopQW,1);
                root->setImage(media(36));
                root->setDesc(str(48));
                makeActBtn("miraSex2",act(12));
            }
        }
        else if(root->gVQuest(miragopQW) >= 15 && mirapiss == 6)
        {
            if(root->gVEvent(miralko) >= 4)
            {
                root->incTime(5);
                if(root->gVQuest(miragopQW) < 25)
                    root->uVQuest(miragopQW,1);
                root->setImage(media(13));
                root->setDesc(str(52));
                makeActBtn("miraSex3",act(12));
            }
            else
            {
                root->incTime(5);
                if(root->gVQuest(miragopQW) < 25)
                    root->uVQuest(miragopQW,1);
                root->setImage(media(13));
                root->setDesc(str(54));
                makeActBtn("miraDog",act(12));
            }
        }
        else
        {
            root->setImage(media(24));
            root->setDesc(str(34));
            makeActBtn("mitkabuh",act(15));
        }
    }
    if(action == "watchMiraBj1")
    {
        root->uVStatus(horny,getRandInt(5,10));
        root->incTime(5);
        root->setImage(media(27));
        root->setDesc(str(39));
        makeActBtn("watchMiraBjCum1",act(12));
    }
    if(action == "watchMiraBjCum1")
    {
        root->uVStatus(horny,getRandInt(10,20));
        root->incTime(5);
        root->setImage(media(28));
        root->setDesc(str(40));
        makeActBtn("watchMiraBj2",act(12));
    }
    if(action == "watchMiraBj2")
    {
        root->uVStatus(horny,getRandInt(10,25));
        root->incTime(10);
        root->setImage(media(29));
        root->setDesc(str(41));
        makeActBtn("miraStandPose",act(12));
    }
    if(action == "miraStandPose")
    {
        root->uVStatus(horny,getRandInt(10,30));
        root->incTime(5);
        root->setImage(media(30));
        root->setDesc(str(42));
        makeActBtn("mitkaFuckMira",act(12));
    }
    if(action == "mitkaFuckMira")
    {
        root->uVStatus(horny,getRandInt(10,35));
        root->incTime(10);
        root->sVQuest(miragopQW,11);
        root->uVEvent(mirasextimes,3);
        root->setImage(media(31));
        root->setDesc(str(43));
        makeActBtn("exit3",act(3));
    }

    if(action == "miraSex1")
    {
        root->uVStatus(horny,getRandInt(30,50));
        root->incTime(25);
        root->sVEvent(mirasextimes,1);
        if(mirapiss == 3)
        {
            root->setImage(media(33));
            root->setDesc(str(45));
        }
        else if(mirapiss == 4)
        {
            root->setImage(media(34));
            root->setDesc(str(46));
        }
        else if(mirapiss == 5)
        {
            root->setImage(media(35));
            root->setDesc(str(47));
        }
        makeActBtn("exit4",act(3));
    }
    if(action == "miraSex2")
    {
        root->incTime(25);
        root->uVEvent(mirasextimes,1);
        root->uVStatus(horny,getRandInt(20,35));
        if(mirapiss == 3)
        {
            root->setImage(media(37));
            root->setDesc(str(49));
        }
        else if(mirapiss == 4)
        {
            root->setImage(media(38));
            root->setDesc(str(50));
        }
        else if(mirapiss == 5)
        {
            root->setImage(media(39));
            root->setDesc(str(51));
        }
        makeActBtn("exit4",act(3));
    }
    if(action == "miraSex3")
    {
        root->incTime(5);
        root->setImage(media(40));
        root->setDesc(str(53));
        makeActBtn("mitkabuh",act(15));
    }
    if(action == "miraDog")
    {
        root->uVStatus(horny,getRandInt(25,50));
        root->incTime(5);
        root->setImage(media(41));
        root->setDesc(str(55));
        makeActBtn("mitkabuh",act(12));
    }

    if(action == "mitkaVag1") mitkaVag1();
    if(action == "mitkaVag2") mitkaVag2();
    if(action == "mitkaDepOnMesec1") mitkaDepOnMesec1();
    if(action == "mitkaDepOnMesec2") mitkaDepOnMesec2();
    if(action == "mitkaDepOnMesec3") mitkaDepOnMesec3();
    if(action == "mitkaDepOnMesec4") mitkaDepOnMesec4();
    if(action == "mitkaBlowJob1") mitkaBlowJob1();
    if(action == "mitkaBlowJob2") mitkaBlowJob2();
    if(action == "mitkaBlowJob3") mitkaBlowJob3();
    if(action == "mitkaBlowJob4") mitkaBlowJob4();
    if(action == "mitkaBlowJob5") mitkaBlowJob5();
    if(action == "mitkaBlowJob6") mitkaBlowJob6();
    if(action == "mitkaCum1") mitkaCum1();
    if(action == "mitkaCum2") mitkaCum2();
    if(action == "mitkaCum3") mitkaCum3();
    if(action == "mitkaCum4") mitkaCum4();
    if(action == "mitkaCum5") mitkaCum5();
    if(action == "mitkaCum6") mitkaCum6();
    if(action == "mitkaAnal1") mitkaAnal1();
    if(action == "doubleBlowJob1") doubleBlowJob1();
    if(action == "kolyaAnal1") kolyaAnal1();
    if(action == "vasyaBlowJob1") vasyaBlowJob1();
    if(action == "vasyaVag1") vasyaVag1();
    if(action == "kolyaBlowJob1") kolyaBlowJob1();
    if(action == "kolyaAnal2") kolyaAnal2();
    if(action == "kolyaAnal3") kolyaAnal3();
    if(action == "vasyaBlowJob2") vasyaBlowJob2();
    if(action == "vasyaVag2") vasyaVag2();
    if(action == "kolyaBlowJob2") kolyaBlowJob2();
    if(action == "kolyaAnal4") kolyaAnal4();
    if(action == "vasyaBlowJob3") vasyaBlowJob3();

    if(action == "drunkSex1")
    {
        root->incTime(5);
        root->setImage(media(12));
        root->setDesc(str(11));
        if(root->vSkill(domination) < 10)
            makeActBtn("mitkaDepOnMesec2",act(6));
        else
            makeActBtn("drunkSex1.1",act(7));
    }
    if(action == "drunkSex1.1")
    {
        root->incTime(10);
        root->setImage(media(13));
        root->setDesc(str(13));
        makeActBtn("mitkaDepOnMesec3",act(8));
    }
    if(action == "drunkSex2")
    {
        root->uVStatus(horny,20);
        root->incTime(5);
        root->setImage(media(18));
        root->setDesc(str(21));
        makeActBtn("drunkSex2.1",act(10));
    }
    if(action == "drunkSex2.1")
    {
        root->uVSkill(domination,-2);
        root->uVStatus(horny,30);
        root->sVSex(pose,0);
        root->incTime(10);
        root->uVSC(gangBang,1);
        root->uVEvent(mitkasextimes,1);
        root->setImage(media(19));
        root->setDesc(str(22));
        makeActBtn("kolyaAnal1",act(8));
    }
    if(action == "drunkSex3")
    {
        root->incTime(15);
        setKolyamba();
        root->sVSex(pose,1);
        root->uVSkill(domination,-2);
        if(root->vBody(anus) < 10)
            root->uVSkill(domination,-1);
        root->uVEvent(mitkasextimes,1);
        root->setImage(media(22));
        root->setDesc(str(24));
        if(getRandInt(0,5) < 4)
            makeActBtn("vasyaVag1",act(8));
        else
            makeActBtn("kolyaAnal2",act(8));
    }
    if(action == "drunkSex4")
    {
        root->incTime(15);
        setKolyamba();
        root->uVSkill(domination,-1);
        root->sVSex(pose,1);
        if(root->vBody(anus) < 10)
            root->uVSkill(domination,-1);
        if(root->gVEvent(mitkasextimes) < 20)
            root->uVEvent(mitkasextimes,1);
        root->setImage(media(22));
        root->setDesc(str(24));
        if(getRandInt(0,5) < 4)
            makeActBtn("vasyaVag1",act(8));
        else
            makeActBtn("kolyaAnal3",act(8));
    }
    if(action == "drunkSex5")
    {
        root->incTime(15);
        setMitka();
        root->sVSex(pose,1);
        root->uVSkill(domination,-2);
        root->setImage(media(17));
        root->setDesc(str(25));
        if(getRandInt(0,5) < 4)
            makeActBtn("vasyaVag2",act(8));
        else
            makeActBtn("kolyaAnal4",act(8));
    }
    if(action == "drunkSex6")
    {
        root->incTime(10);
        root->setImage(media(13));
        root->setDesc(str(13));
        makeActBtn("mitkaDepOnMesec3",act(8));
    }
    if(action == "miraWish2")
    {
        root->uVEvent(mirasextimes,1);
        root->sVQuest(miragopQW,6);
        root->uVStatus(horny,50);
        root->incTime(10);
        root->setImage(media(23));
        root->setDesc(str(31));
        makeActBtn("exit1",act(3));
    }


    if(action == "mitkabuh")
        root->startEvent(eMitkaBuh);
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "gadukino")
        root->changeLoc(lgadukino);
    if(action == "exit1")
    {
        root->sVEvent(miraingop,0);
        root->incTime(15);
        root->changeLoc(lgadukino);
    }
    if(action == "exit2")
    {
        root->sVEvent(miraingop,0);
        root->changeLoc(lgadukino);
    }
    if(action == "exit3")
    {
        root->sVEvent(miraingop,0);
        root->incTime(30);
        root->changeLoc(lgadukino);
    }
    if(action == "exit4")
    {
        root->sVEvent(miraingop,0);
        root->incTime(10);
        root->changeLoc(lgadukino);
    }
}

void MitkaBuh::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"MitkaBuh");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MitkaBuh::actionHandler);
    root->addActBtn(btn);
}

QString MitkaBuh::str(int id)
{
    QString str[70];
    str[0] = "Расположившись в укромном местечке три деревенских пацана, Митька Шкворень, Васян Пакет и Колямба пьют самогонку без всякой закуски. Митька наливает самогонки в стакан и подает вам.";
    str[1] = "Вы выпили самогонку и внутри все обожгло, задохнувшись вы стали занюхивать рукавом ,так как закуски не было. Митька одобрительно сказал: <npc>- Хороша зараза, продирает.</npc>";
    str[2] = "Вы напились в хлам, ноги уже практически не держат вас. Митька, заметив ваше состояние, удерживает вас за талию. <npc>- Ну чо, Светик, пойдем ебаться?</npc>";
    str[3] = "Вы напились в хлам, ноги уже практически не держат вас. Один из пацанов, заметив ваше состояние, требовательно предлагает вам перепихнуться.";
    str[4] = "Митька";
    str[5] = "Митька отвел вас к своему дому, где, ничуть не церемонясь, начал быстро вас раздевать.";
    str[6] = "Митяй, лег на бок и закурил. <npc>- Охуенно!</npc>";
    str[7] = "Митька отвел вас к своему дому, где требовательно начал давить вам на плечи, опуская на колени...";
    str[8] = "Вы покрепче сжимаете Митькин член рукой и не вынимая его изо рта, начинаете яростно надрачивать его, пока, наконец, не чувствуете, как вам в рот начинает извергаться его теплая липкая сперма...";
    str[9] = "Вы не успеваете взять Митькин член в рот и он начинает кончать вам на губы, пока вы пьяно пытаетесь сообразить, что только что произошло...";
    str[10] = "Вы пытаетесь взять Митькин член в рот, но он грубо хватает вас за волосы и отводит голову назад, тем самым начиная извергаться вам на лицо...";
    str[11] = "<npc>- Гы-гы,</npc> - внезапно развеселился Митька. <npc>- Но бля, что-то влом мне ногами топать, а елдак-то чешется... Слышь, Светик, давай, загибайся прямо тут, чего уж по углам да кустам прятаться, все равно пацаны и так знают, что я тебя трахаю. Вы ведь не против, да?</npc> - обернулся он уже к захмелевшим дружбанам."
              "<npc>- Неее,</npc> - пьяно протянул Колямба. <npc>- Развлекайтесь, чо уж там, а мы пока с Пакетом еще накатим...</npc>"
              "<npc>- Ну вот и... Ик... Чудно,</npc> - заикаясь, самодовольно промычал Митька, <npc>- так что давай, Света... Ик... Нагибайся!</npc>";
    str[12] = "Вы, едва удерживаясь на ногах, подходите к валяющемуся поблизости бревну и облегченно упираетесь в него руками, чувствуя, как сзади подходит Митька и начинает оголять вашу задницу...";
    str[13] = "Вы пьяно отнекиваетесь и едва удерживаясь на ногах, изо всех сил отпихиваете пристающего Митьку, пока наконец он не сдается и не ведет вас к себе на веранду...";
    str[14] = "Вы продолжаете надрачивать и сосать Митькин член, пока неожиданно не чувствуете, как сильные мужские руки приподнимают ваш таз. Вы отвлекаетесь от члена, и пока выясняете, что происходит, Колямба уже успевает оголить ваш зад и теперь грубо пихает в вашу киску свои шершавые мозолистые пальцы.";
    str[15] = "Вы покрепче сжимаете Митькин член рукой и не вынимая его изо рта, начинаете яростно надрачивать его, чувствуя при этом, как в вашей киске быстро движутся мужские пальцы. Вскоре упругая струя мужской солоноватой спермы начинает заливать вам рот...";
    str[16] = "Вы покрепче сжимаете Митькин член рукой и не вынимая его изо рта, начинаете яростно надрачивать его, пока, наконец, не чувствуете, как вам в рот начинает извергаться его теплая липкая сперма. Едва вы облизали его член и заправили в штаны, как к вам подошли Колямба с Васяном. Первый выжидательным горящим от возбуждения взглядом посмотрел на Митьку, а когда тут равнодушно махнул рукой, тут же подошел к вам и расстегнул ширинку. Через пару секунд его примеру, не теряя даром времени, последовал и Васян...";
    str[17] = "Вы, пьяно чавкая и причмокивая, послушно начинаете отсасывать пацанам.";
    str[18] = "Вскоре они кончают вам на лицо и теряют к вам всякий интерес...";
    str[19] = "Васян";
    str[20] = "Колямба";
    str[21] = "Вы плюхаетесь на лавочку и пацаны тут же начинают лапать вас и пихать пальцы во все щели.";
    str[22] = "Вы раздеваетесь и ложитесь на деревянную лавочку...";
    str[23] = "Обессиленные, вы слышите, как начинает натужно сопеть Васян и не мешкая, тут же покрепче сжимаете его член и направляете его себе в рот, через секунду ощущая в нем терпкий вкус спермы...";
    str[24] = "Васян с Колямбой отвели вас к Васяну в летнюю кухню, где быстро начали снимать с вас одежду...";
    str[25] = "Вы с ногами залезаете на лавку и послушно встаете на четвереньки. Пацаны тут же, пьяно переговариваясь между собой о каких-то своих делах, начинают вас раздевать и пристраиваться к вашим дырочкам...";
    str[26] = "Вы напились в хлам, ноги уже практически не держат вас. Митька, заметив ваше состояние, удерживает вас за талию. Кажется, с вас уже хватит...";
    str[27] = "Расположившись в укромном местечке, три деревенских пацана - Митька Шкворень, Васян Пакет и Колямба - пьют самогонку без всякой закуски. Вы с Мирославой подходите к ним и спрашиваете, можно ли к ним присоединиться. Парни тут же оживляются и активно кивают вам головами. Митька тут же начинает разливать самогон в стаканы, после чего подает один из них вам, сообщая, что так, как стаканов не всех не хватает, то вам придется пить из одного на двоих по очереди.";
    str[28] = "Пацаны болтают о чем-то своем, не обращая на вас совершенно никакого внимания.";
    str[29] = "<npc>- Чо, Светик, опять на палку чая пришла? Ха-ха! Не стоит уже, извиняй, найди кого-нибудь другого, что ли... Ха-ха-ха...</npc>";
    str[30] = "Вы уже изрядно пьяны, но помните Мирины слова, а потому все же стараетесь сильно не перебирать. Мирослава все время бросала на вас многозначительные взгляды, а как только они с Митькой распрощались с вами, вы через пару минут прощаетесь с Васяном и Коляндой и идете к Митькиному дому. Не доходя пару до дома пары десятков метров, вы уже слышите их негромкую пьяную болтовню. Пошарив глазами в темноте, вы находите укромное место, с которого вас не было бы видно и устроившись поудобнее, начинаете присматриваться к происходящему на Митькином дворе....";
    str[31] = "Пьяная голая Мирослава уже лежала на деревянном столе, прислоненном к забору, а Митька размеренно вколачивал в нее свой член. При каждом его толчке, болезненно кривясь, негромко мычала Мира, то и дело ударясь макушкой о забор, и надрывно скрипели доски. Присмотревшись, вы поняли, что Мира сдержала свое обещание, - член Митьки до самых яиц входил в ее задницу, из которой иногда раздавались странные хлюпанья, на которые, впрочем, никто, кроме вас, не обращал внимания. Громкие шлепки соприкасающихся тел вклинивались в эту животную музыкальную вакханалию двух сношающихся молодых людей, добавляя еще больше пикантности. Митька минут десять долбил в задницу извивающуюся и мычащую Мирославу, пока наконец на всю длинну последним рывком не вогнал в девушку свой член и начал шумно извергаться... Мира в это время пьяным взглядом шарила по окрестностям, наверняка выглядывая вас, но так и не заметила. Через полминуты Митяй вытащил из ее зада свой член и закурив, начал смотреть, как Мира подтирает салфетками сочащуюся из ануса сперму...";
    str[32] = "Мирослава напилась в хлам, ноги уже практически не держат ее, поэтому она прислонилась к деревеву и с последних сил пытается не упасть. Она мычит нечто совершенно невразумительное и вряд ли понимает, где она и что вообще вокруг происходит. Да и вы сами тоже не лучше - голова кружится, земля то и дело уходит из-под ног и все, что вам сейчас хочется, это прилечь на мягкую теплую постель. Вы, понимая, что если выпьете еще хотя бы один стакан, то свалитесь прямо здесь, решаете уйти, а потому прощаетесь с собутыльниками и уходите домой.";
    str[33] = "Вы берете стакан с самогоном и начинаете, кашляя и кривясь, цедить его сквозь зубы. Мирослава тем временем застенчиво отвечает на нагловатые вопросы деревенской молодежи.";
    str[34] = "Вы отдаете стакан с самогоном Мирославе и та, немного помедлив, начинает, кашляя и кривясь, цедить его сквозь зубы. Вы тем временем оживленно разговариваете с деревенскими.";
    str[35] = "Вы отдаете стакан с самогоном Мирославе, но та просит вас пару минут подождать и отходит к ближайшему дереву, где, задрав юбку, начинает справлять нужду. Васян с Коляндой громко ржут и пялятся на ссущую Мирку, а Митька, сцепив зубы, делает равнодушный вид. Сделав свое дело, Мирослава, как ни в чем не бывало, возвращается к компании и выпивает самогон.";
    str[36] = "Как только она выпила, подвыпивший Васян, словно в шутку, спрашивает у нее, как она смотрит на то, чтобы прямо здесь и сейчас отсосать у него с Колямбой.";
    str[37] = "Мирослава только хихикает в ответ, а Васян получает от Митьки подзатыльник...";
    str[38] = "Мирослава, уже изрядно подвыпившая, только хихикает в ответ и говорит, что ей нравится это дело. Митька тут же дает подзатыльник Васяну и говорит, чтобы не лез к ней, но тот отвечает, что она уже взрослая девка и может сама за себя ответить. Колямба тем временем уже встал и обнимает кокетничающую Мирославу, а через минуту настойчиво и с силой давит ей на плечи. Мира, пьяно хихикая, наигранно сопротивляется, но уже через пару секунд стает перед Колямбой на колени и словно завороженная смотрит, как тот расстегивает ширинку и приспускает штаны...";
    str[39] = "Мирослава, увидев еще не полностью вставший член, тут же нежно заглатывает его до самых яиц и начинает елозить губами по кожице, то втягивая его в себя, то выпуская до самой головки. Колямба блаженно прикрыв глазами, наслаждается Миркиным минетом, Васян в ожидании чешет яйца, а разочарованный Митька предлагает вам накатить еще по одной, но после того, как вы отказываетесь пьет сам.";
    str[40] = "Через пару минут Колямба грубо отталкивает присосавшуюся Мирославу от своего члена и начинает кончать ей на лицо. Та, закрыв глаза, пьяно мычит, пытаясь изобразить сексуальность и пальцем размазывает сперму себе по лицу.";
    str[41] = "<npc>- Ну а теперь моя очередь,</npc> - говорит Васян и подходит к Мирославе. Та с энтузиазмом отсасывает и ему, после чего Васян спускает ей на язык.";
    str[42] = "Митька, уже успевший добавиться парой стаканов, молча подходит к Мирославе и без предисловий говорит ей, чтобы та стала в позу. Мира, пьяно пошатываясь, послушно поворачивается к нему задницей и рукой отодвигает в сторону трусики, при этом захватив рукой еще и половую губу...";
    str[43] = "Но Митька, шлепнув ее по заднице, грубо спускает с нее трусы до самых колен и, приспустив свои штаны, начинает грубо ее трахать. Мира охает и постанывает, иногда стукаясь головой о дерево, о которое оперлась руками, и пытается подмахивать Митьке. Вы тем временем замечаете, как косятся на вас Васян с Колямбой и попрощавшись, решаете уйти от греха подальше...";
    str[44] = "<npc>- Ну чо, Мирка, готова поработать своей пизденкой?</npc> - раздается среди компашки пьяный требовательный голос."
              "Та что-то пьяно хихикает в ответ, после чего с готовностью разворачивается к компании спиной и приспустив штаны, подставляет гопоте свою голую задницу.";
    str[45] = "Колямба недовольно морщится и отводит ее в сторонку, где приказывает ей самой поработать своей пиздой. Там беспрекословно запрыгивает на него сверху и начинает скакать...";
    str[46] = "Митька одобрительно хмыкает и отводит пьяную Мирославу в сторонку, где и начинает ее бесцеременно трахать...";
    str[47] = "Васян отводит Миру немного в сторону и приказывает ей снять с себя шмотки, после чего, совершенно голую, начинает долбитьее своим членом...";
    str[48] = "<npc>- Ну чо, Мирка, пососешь у пацанов?</npc> - раздается среди компашки пьяный требовательный голос."
              "Та, краснея, кивает головой и покорно присаживается прямо там, где и стояла.";
    str[49] = "Пацаны тут же совершенно забыв о вас, обступают Мирославу и та начинает по очереди у всех отсасывать, громкая чавкая губами...";
    str[50] = "Пацаны тут же совершенно забыв о вас, обступают Мирославу и по очереди начинают грубо трахать ее в рот. Она постоянно мычит и давится, но те не обращают на это совершенно никакого внимания, продолжая насаживать ее голову на свой член...";
    str[51] = "Пацаны тут же совершенно забыв о вас, обступают Мирославу и та по очереди начинают у всех старательно отсасывать, одновременно надрачивая член рукой...";
    str[52] = "<npc>- Ну чо, Мирка, покажешь нам шоу?</npc> - гогочет Колямба. <npc>- Покажи нам, как ты надрачиваешь свои дырки...<npc>"
              "Мирослава утвердительно мычит в ответ, после чего раздевается, стает на четвереньки и оттопырив задницу в сторону компании, начинает трахать себя пальцами в обе дырочки...";
    str[53] = "Мирослава пьяно постанывает и протяжно стонет, неуклюже засовывая пальцы себе в дырочки. Васян дурашливо спрашивает у вас, смогли бы вы тоже так, но вы только презрительно хмыкаете в ответ и он тут же остает, - Мира наконец доводит себя до первого оргазма.";
    str[54] = "<npc>- Ну чо, Мирка, покажешь нам шоу?</npc> - гогочет Колямба. <npc>- Покажи нам, как ты надрачиваешь свои дырки...</npc>"
              "Мирослава отрицательно мотает головой, отчего гопники тут же набычиваются и начинают наезжать на Мирославу. Та отказывается выполнять их требование и предлагает найти какой-нибудь компромисс и они сходятся на том, что она просто разденется догола и немного поползает перед ними на четвереньках, изображая собаку...";
    str[55] = "Мирослава снимает с себя всю одежду и следующие пятнадцать минут на четвереньках ползает по земле, при этом постоянно вертя головой по сторонам, не идет ли кто. Но вокруг густые заросли и деревья, к тому же в деревне людей очень мало, да и темнеет уже, поэтому все обоходится благополучно...";
    return str[id];
}

QString MitkaBuh::act(int id)
{
    QString act[21];
    act[0] = "Выпить";
    act[1] = "Отдышаться";
    act[2] = "Нечленораздельно мычать";
    act[3] = "Уйти";
    act[4] = "Сосать";
    act[5] = "Глотать";
    act[6] = "Нагнуться";
    act[7] = "Протестовать";
    act[8] = "Стонать";
    act[9] = "Сесть на лавку";
    act[10] = "Дать пацанам";
    act[11] = "Встать в позу";
    act[12] = "Смотреть";
    act[13] = "Отдать стакан Мирославе";
    act[14] = "Выпить самой";
    act[15] = "Далее";
    act[16] = "";
    act[17] = "";
    act[18] = "";
    act[19] = "";
    act[20] = "";
    return act[id];
}

QString MitkaBuh::media(int id)
{
    QString med[50];
    med[0] = "data/npc/gadukino/mitka/3boys.2.jpg";
    med[1] = "data/sex/mitkasex2/mitkafirst.jpg";
    med[2] = "data/sex/mitkasex2/mitkasex1.jpg";
    med[3] = "data/sex/mitkasex2/mitkasex2.jpg";
    med[4] = "data/sex/mitkasex2/MitkaSexNoPublic.jpg";
    med[5] = "data/sex/mitkasex2/MitkaSexPublic.jpg";
    med[6] = "data/sex/mitkasex2/MitkaBj.jpg";
    med[7] = "data/sex/mitkasex2/MitkaBjCum.jpg";
    med[8] = "data/sex/mitkasex2/MitkaBjCum1.jpg";
    med[9] = "data/sex/mitkasex2/MitkaBjCum2.jpg";
    med[10] = "data/sex/mitkasex2/mitkaanal.jpg";
    med[11] = "data/sex/mitkasex2/mitkaanal1.jpg";
    med[12] = "data/sex/mitkabuh_group/drunkgirl1.jpg";
    med[13] = "data/sex/mitkabuh_group/drunkgirl.jpg";
    med[14] = "data/sex/mitkasex2/MitkaBjPublic.jpg";
    med[15] = "data/sex/mitkasex2/MitkaBjPublicCum.jpg";
    med[16] = "data/sex/mitkasex2/MitkaBjPublicGuys.jpg";
    med[17] = "data/sex/mitkasex2/MitkaBjPublicGuys2.jpg";
    med[18] = "data/sex/mitkabuh_group/MitkaGroup.jpg";
    med[19] = "data/sex/mitkabuh_group/MitkaGroupCum.jpg";
    med[20] = "data/sex/mitkabuh_group/MitkaGroupCum1.jpg";
    med[21] = "data/sex/mitkabuh_group/MitkaGroupCum2.jpg";
    med[22] = "data/sex/mitkasex2/MitkaGuys2.jpg";
    med[23] = "data/qwest/mira_wish/Mirawish1_2.jpg";
    med[24] = "data/qwest/gadukino/drinking.jpg";
    med[26] = "data/qwest/gadukino/MiraPiss.jpg";
    med[27] = "data/sex/mira/MiraQW10.jpg";
    med[28] = "data/sex/mira/MiraQW10_1.jpg";
    med[29] = "data/sex/mira/MiraQW10_2.jpg";
    med[30] = "data/sex/mira/MiraQW10_3.jpg";
    med[31] = "data/sex/mira/MiraQW10_4.jpg";
    med[32] = "data/sex/mira/MiraQW11.jpg";
    med[33] = "data/sex/mira/MiraQW11_1.jpg";
    med[34] = "data/sex/mira/MiraQW11_2.jpg";
    med[35] = "data/sex/mira/MiraQW11_3.jpg";
    med[36] = "data/sex/mira/MiraQW11_4.jpg";
    med[37] = "data/sex/mira/MiraQW11_5.jpg";
    med[38] = "data/sex/mira/MiraQW11_6.jpg";
    med[39] = "data/sex/mira/MiraQW11_7.jpg";
    med[40] = "data/sex/mira/MiraQW15.jpg";
    med[41] = "data/sex/mira/MiraQW15_1.jpg";
    return med[id];
}

void MitkaBuh::setMitka()
{
    root->setBoyName(str(4));
    root->sVSex(silavag,0);
    root->sVSex(dick,16);
}

void MitkaBuh::setVasyan()
{
    root->setBoyName(str(19));
    root->sVSex(silavag,0);
    root->sVSex(dick,14);
}

void MitkaBuh::setKolyamba()
{
    root->setBoyName(str(20));
    root->sVSex(silavag,0);
    root->sVSex(dick,15);
}

void MitkaBuh::checkMitkaSex()
{
    if(root->gVEvent(mitkasex) == 0)
    {
        root->sVEvent(mitkasex,1);
        root->uVSex(guy,1);
    }
}

void MitkaBuh::sexDepOnMesec()
{
    if(root->isMesec())
    {
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
    }
    else
    {
        root->sVSex(protect,1);
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
    }
}

void MitkaBuh::mitkaBlowJob1()
{
    checkMitkaSex();
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(6));
    root->setDesc(str(7));
    root->blow_job();
    int tmp = getRandInt(0,5);
    if(tmp < 3)
        makeActBtn("mitkaCum1",act(5));
    else if(tmp >= 3 && tmp < 5)
        makeActBtn("mitkaCum2",act(5));
    else if(tmp == 5)
        makeActBtn("mitkaCum3",act(5));
}

void MitkaBuh::mitkaBlowJob2()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(14));
    root->blow_job();
    if(getRandInt(0,5) < 5)
        makeActBtn("mitkaCum4",act(5));
    else
    {
        root->addDesc(str(14));
        makeActBtn("mitkaCum5",act(5));
    }
}

void MitkaBuh::mitkaBlowJob3()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(14));
    root->blow_job();
    if(getRandInt(0,5) < 4)
        makeActBtn("mitkaCum4",act(5));
    else
        makeActBtn("mitkaCum6",act(5));
}

void MitkaBuh::mitkaBlowJob4()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(14));
    root->blow_job();
    makeActBtn("mitkaCum4",act(5));
}

void MitkaBuh::mitkaBlowJob5()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(14));
    root->blow_job();
    if(getRandInt(1,2) == 1)
        makeActBtn("mitkaCum4",act(5));
    else
    {
        root->addDesc(str(14));
        makeActBtn("mitkaCum5",act(5));
    }
}
void MitkaBuh::mitkaBlowJob6()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,0);
    root->uVStatus(horny,10);
    root->uVSC(blowJob,1);
    root->setImage(media(14));
    root->blow_job();
    if(getRandInt(1,2) == 1)
        makeActBtn("mitkaCum4",act(5));
    else
        makeActBtn("mitkaCum6",act(5));
}


void MitkaBuh::doubleBlowJob1()
{
    root->incTime(15);
    root->sVSex(pose,0);
    root->uVStatus(horny,30);
    root->cum("face");
    root->uVSex(guy,2);
    root->uVSC(gangBang,1);
    root->uVSkill(domination,-2);
    root->setImage(media(17));
    root->setDesc(str(17));
    setVasyan();
    root->blow_job();
    setKolyamba();
    root->blow_job();
    root->addDesc(str(18));
    root->uVEvent(mitkasextimes,1);
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaVag1()
{
    root->incTime(15);
    checkMitkaSex();
    setMitka();
    root->sVSex(pose,0);
    root->uVEvent(mitkasextimes,1);
    if(root->vBody(vagina) == 0)
        root->setImage(media(1));
    else
        root->setImage(media(2));
    root->setDesc(str(5));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(6));
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::mitkaVag2()
{
    setMitka();
    root->uVStatus(horny,40);
    root->incTime(10);
    root->setImage(media(20));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    makeActBtn("vasyaBlowJob1",act(4));
}

void MitkaBuh::mitkaAnal1()
{
    root->incTime(15);
    setMitka();
    checkMitkaSex();
    root->sVSex(pose,0);
    root->cum("anus");
    if(root->vBody(anus) < 10)
        root->uVSkill(domination,-1);
    if(root->vBody(anus) < root->vSex(dick))
        root->uVBody(anus,1);
    root->uVEvent(mitkasextimes,1);
    if(root->vBody(anus) < 10)
        root->setImage(media(10));
    else
        root->setImage(media(11));
    root->setDesc(str(5));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaDepOnMesec1()
{
    root->incTime(15);
    checkMitkaSex();
    setMitka();
    root->sVSex(pose,0);
    root->uVEvent(mitkasextimes,1);
    if(root->vBody(vagina) == 0)
        root->setImage(media(1));
    else
        root->setImage(media(2));
    root->setDesc(str(5));
    sexDepOnMesec();
    root->addDesc(str(6));
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::mitkaDepOnMesec2()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,1);
    root->uVSkill(domination,-2);
    root->uVEvent(mitkasextimes,1);
    root->setImage(media(5));
    root->setDesc(str(12));
    sexDepOnMesec();
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::mitkaDepOnMesec3()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,1);
    root->uVSkill(domination,-1);
    root->uVEvent(mitkasextimes,1);
    root->setImage(media(4));
    sexDepOnMesec();
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::mitkaDepOnMesec4()
{
    root->incTime(15);
    setMitka();
    root->sVSex(pose,1);
    root->uVSkill(domination,-1);
    root->uVEvent(mitkasextimes,1);
    root->setImage(media(5));
    root->setDesc(str(12));
    sexDepOnMesec();
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum1()
{
    root->incTime(10);
    root->uVStatus(horny,10);
    root->cum("lip");
    root->uVSC(swallow,1);
    root->uVEvent(mitkasextimes,1);
    root->setImage(media(7));
    root->setDesc(str(8));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum2()
{
    root->incTime(10);
    root->uVStatus(horny,10);
    root->cum("face");
    root->uVEvent(mitkasextimes,1);
    root->setImage(media(8));
    root->setDesc(str(9));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum3()
{
    root->incTime(10);
    root->uVStatus(horny,10);
    root->cum("face");
    root->uVEvent(mitkasextimes,1);
    root->uVSkill(domination,-1);
    root->setImage(media(9));
    root->setDesc(str(10));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum4()
{
    root->incTime(10);
    root->uVStatus(horny,10);
    root->cum("lip");
    root->uVSC(swallow,1);
    root->uVEvent(mitkasextimes,1);
    root->uVSkill(domination,-1);
    root->setImage(media(15));
    root->setDesc(str(8));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum5()
{
    root->incTime(10);
    root->uVStatus(horny,30);
    root->cum("lip");
    root->uVSC(swallow,1);
    root->uVEvent(mitkasextimes,1);
    root->uVSkill(domination,-2);
    root->setImage(media(16));
    root->setDesc(str(15));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::mitkaCum6()
{
    root->incTime(10);
    root->uVStatus(horny,10);
    root->uVSC(swallow,1);
    root->cum("lip");
    root->uVSkill(domination,-1);
    root->setImage(media(15));
    root->setDesc(str(16));
    makeActBtn("doubleBlowJob1",act(4));
}

void MitkaBuh::kolyaBlowJob1()
{
    setKolyamba();
    root->uVStatus(horny,15);
    root->incTime(5);
    root->cum("lip");
    root->uVSC(blowJob,1);
    root->setImage(media(22));
    root->blow_job();
    root->addDesc(str(23));
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::kolyaBlowJob2()
{
    setKolyamba();
    root->uVStatus(horny,15);
    root->incTime(5);
    root->uVSC(blowJob,1);
    root->cum("lip");
    root->setImage(media(17));
    root->blow_job();
    root->addDesc(str(23));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::kolyaAnal1()
{
    setKolyamba();
    root->uVStatus(horny,10);
    root->incTime(10);
    root->cum("anus");
    root->setImage(media(19));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    makeActBtn("mitkaVag2",act(8));
}

void MitkaBuh::kolyaAnal2()
{
    setKolyamba();
    root->uVStatus(horny,10);
    root->incTime(10);
    root->cum("anus");
    root->uVBody(anus,1);
    root->setImage(media(22));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    makeActBtn("vasyaBlowJob1",act(4));
}
void MitkaBuh::kolyaAnal3()
{
    setKolyamba();
    root->uVStatus(horny,10);
    root->incTime(10);
    root->cum("anus");
    root->uVBody(anus,1);
    root->setImage(media(22));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    makeActBtn("vasyaBlowJob2",act(4));
}
void MitkaBuh::kolyaAnal4()
{
    setKolyamba();
    root->uVStatus(horny,10);
    root->incTime(10);
    root->cum("anus");
    root->uVBody(anus,1);
    root->setImage(media(17));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    makeActBtn("vasyaBlowJob3",act(4));
}

void MitkaBuh::vasyaBlowJob1()
{
    setVasyan();
    root->uVStatus(horny,15);
    root->incTime(5);
    root->cum("lip");
    root->uVSC(blowJob,1);
    root->setImage(media(21));
    root->blow_job();
    root->addDesc(str(23));
    makeActBtn("gadukino",act(3));
}

void MitkaBuh::vasyaBlowJob2()
{
    setVasyan();
    root->uVStatus(horny,15);
    root->incTime(5);
    root->uVSC(blowJob,1);
    root->cum("lip");
    root->setImage(media(22));
    root->blow_job();
    root->addDesc(str(23));
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::vasyaBlowJob3()
{
    setVasyan();
    root->uVStatus(horny,15);
    root->incTime(5);
    root->uVSC(blowJob,1);
    root->cum("lip");
    root->setImage(media(17));
    root->blow_job();
    root->addDesc(str(23));
    makeActBtn("gadukino",act(3));
}
void MitkaBuh::vasyaVag1()
{
    setVasyan();
    root->uVStatus(horny,50);
    root->incTime(10);
    root->setImage(media(22));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    makeActBtn("kolyaBlowJob1",act(4));
}
void MitkaBuh::vasyaVag2()
{
    setVasyan();
    root->uVStatus(horny,50);
    root->incTime(10);
    root->setImage(media(17));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    makeActBtn("kolyaBlowJob2",act(4));
}
