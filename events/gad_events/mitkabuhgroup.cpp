#include "mitkabuhgroup.h"
#include "../../game.h"
#include "../../menu/buttons.h"
#include "../../Functions.h"

MitkaBuhGroup::MitkaBuhGroup(Game* ptr): root(ptr) {}

void MitkaBuhGroup::start(QString arg)
{
    if(root->vEvent(miraingop) == 1 && root->vQuest(miragopQW) > 0)
    {
        root->setImage(media(0));
        root->setText(str(0));
        if(root->vAddict(alko) >= 8)
        {
            root->setImage(media(1));
            root->setText(str(1));
            if(root->vEvent(mitkasextimes) >= 15)
            {
                int tmp = getRandInt(0,5);
                if(tmp == 0) makeActBtn("BJtriple1",act(0));
                if(tmp == 1) makeActBtn("mitkaSex1",act(1));
                if(tmp == 2) makeActBtn("BJtriple2",act(0));
                if(tmp == 3) makeActBtn("inBed1",act(2));
                if(tmp == 4) makeActBtn("goGuys",act(3));
                if(tmp == 5) makeActBtn("standPose",act(4));
            }
        }
        else
        {
            if(order == 0) makeActBtn("drink",act(11));
            else if(order == 1) makeActBtn("drink",act(13));
            else if(order == 2) makeActBtn("drinkMira",act(14));
        }
    }
}

void MitkaBuhGroup::actionHandler(QString action)
{
    if(action == "BJtriple1")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 3;
        if(root->vQuest(miragopQW) < 20)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(getRandInt(2,9)));
        root->setText(str(5));
        setMitka();
        root->blow_job();
        setVasyan();
        root->blow_job();
        setKolyamba();
        root->blow_job();
        makeActBtn("cum1",act(5));
    }
    if(action == "cum1")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(swallow) += 3;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(10,14)));
        root->setText(str(6));
        makeActBtn("gadukino",act(6));
    }
    if(action == "BJtriple2")
    {
        root->incTime(15);
        root->vStatus(horny) += 30;
        root->cum("face");
        root->vStatistics(blowJob) += 3;
        root->vSkill(domination) -= 1;
        if(root->vQuest(miragopQW) < 20)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(getRandInt(15,19)));
        root->setText(str(7));
        setMitka();
        root->blow_job();
        setVasyan();
        root->blow_job();
        setKolyamba();
        root->blow_job();
        root->addText(str(8));
        makeActBtn("gadukino",act(6));
    }
    if(action == "mitkaSex1")
    {
        root->incTime(15);
        setMitka();
        root->vSex(pose) = 1;
        root->vSkill(domination) -= 1;
        if(root->vQuest(miragopQW) < 30)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(getRandInt(20,24)));
        root->setText(str(9));
        sexDepOnMesec();
        makeActBtn("kolyaSex1",act(7));
    }
    if(action == "kolyaSex1")
    {
        root->incTime(15);
        setKolyamba();
        root->vSex(pose) = 1;
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(20,24)));
        sexDepOnMesec();
        makeActBtn("vasyaSex1",act(8));
    }
    if(action == "vasyaSex1")
    {
        root->incTime(15);
        setVasyan();
        root->vSex(pose) = 1;
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(20,24)));
        sexDepOnMesec();
        root->vStatistics(gangBang) += 1;
        makeActBtn("cum2",act(5));
    }
    if(action == "cum2")
    {
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(swallow) += 3;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(10,14)));
        root->setText(str(10));
        makeActBtn("gadukino",act(6));
    }
    if(action == "inBed1")
    {
        root->vStatus(horny) += 30;
        root->incTime(5);
        root->vEvent(mitkasextimes) += 1;
        if(root->vQuest(miragopQW) < 30)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(getRandInt(28,29)));
        root->setText(str(11));
        makeActBtn("inBed1.1",act(9));
    }
    if(action == "inBed1.1")
    {
        root->vSkill(domination) -= 2;
        root->vStatus(horny) += 30;
        root->vSex(pose) = 0;
        root->vStatistics(gangBang) += 1;
        root->incTime(10);
        root->setImage(media(getRandInt(26,27)));
        root->setText(str(12));
        makeActBtn("inBed1.2",act(10));
    }
    if(action == "inBed1.2")
    {
        setKolyamba();
        root->vStatus(horny) += 10;
        root->incTime(10);
        root->setImage(media(getRandInt(30,34)));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        root->cum("anus");
        makeActBtn("inBed1.3",act(10));
    }
    if(action == "inBed1.3")
    {
        setMitka();
        root->vStatus(horny) += 40;
        root->incTime(10);
        root->setImage(media(getRandInt(35,39)));
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("inBed1.4",act(0));
    }
    if(action == "inBed1.4")
    {
        root->vStatistics(blowJob) += 1;
        setVasyan();
        root->vStatus(horny) += 15;
        root->incTime(5);
        root->cum("lip");
        root->setImage(media(getRandInt(10,12)));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }
    if(action == "goGuys")
    {
        root->incTime(15);
        root->vSkill(domination) -= 2;
        root->vSex(pose) = 1;
        if(root->vEvent(mitkasextimes) < 20)
            root->vEvent(mitkasextimes) += 1;
        if(root->vQuest(miragopQW) < 30)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(40));
        root->setText(str(14));
        if(getRandInt(0,5) < 4) makeActBtn("goGuys1",act(10));
        else makeActBtn("goGuys2",act(10));
    }
    if(action == "goGuys1")
    {
        setVasyan();
        root->vStatus(horny) += 50;
        root->incTime(10);
        root->setImage(media(getRandInt(35,39)));
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("goGuys1.1",act(0));
    }
    if(action == "goGuys1.1")
    {
        setKolyamba();
        root->vStatus(horny) += 15;
        root->vStatistics(blowJob) += 1;
        root->incTime(5);
        root->cum("lip");
        root->setImage(media(getRandInt(13,14)));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }
    if(action == "goGuys2")
    {
        setKolyamba();
        root->vStatus(horny) += 10;
        root->incTime(10);
        root->cum("anus");
        root->vBody(anus) += 1;
        root->setImage(media(getRandInt(30,34)));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        makeActBtn("goGuys2.1",act(0));
    }
    if(action == "goGuys2.1")
    {
        setVasyan();
        root->vStatus(horny) += 15;
        root->incTime(5);
        root->vStatistics(blowJob) += 1;
        root->cum("lip");
        root->setImage(media(getRandInt(13,14)));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }
    if(action == "standPose")
    {
        root->incTime(15);
        root->vSex(pose) = 1;
        root->vSkill(domination) -= 2;
        if(root->vQuest(miragopQW) < 30)
            root->vQuest(miragopQW) += 1;
        root->setImage(media(29));
        root->setText(str(15));
        if(getRandInt(0,5) < 4) makeActBtn("standPose1",act(10));
        else makeActBtn("standPose2",act(10));
    }
    if(action == "standPose1")
    {
        setVasyan();
        root->vStatus(horny) += 50;
        root->incTime(10);
        root->setImage(media(getRandInt(20,24)));
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("standPose1.1",act(0));
    }
    if(action == "standPose1.1")
    {
        setKolyamba();
        root->vStatus(horny) += 15;
        root->incTime(5);
        root->vStatistics(blowJob) += 1;
        root->cum("lip");
        root->setImage(media(getRandInt(13,14)));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }
    if(action == "standPose2")
    {
        setKolyamba();
        root->vStatus(horny) += 10;
        root->incTime(10);
        root->cum("anus");
        root->vBody(anus) += 1;
        root->setImage(media(getRandInt(20,24)));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        makeActBtn("standPose2.1",act(0));
    }
    if(action == "standPose2.1")
    {
        setVasyan();
        root->vStatus(horny) += 15;
        root->incTime(5);
        root->vStatistics(blowJob) += 1;
        root->cum("lip");
        root->setImage(media(getRandInt(13,14)));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }
    if(action == "drink")
    {
        root->fnAlko(getRandInt(3,5));
        order = 2;
        root->setImage(media(41));
        root->setText(str(16));
        makeActBtn("mitkabuhgroup",act(12));
    }
    if(action == "drinkMira")
    {
        root->vEvent(miralko) += getRandInt(1,4);
        root->incTime(15);
        order = 1;
        mirapiss = getRandInt(0,10);
        if(root->vQuest(miragopQW) >= 15 && mirapiss <= 2)
        {
            root->incTime(5);
            if(root->vQuest(miragopQW) < 20)
                root->vQuest(miragopQW) += 1;
            root->setImage(media(42));
            root->setText(str(18));
            makeActBtn("suckVasya",act(0));
        }
        else if(root->vQuest(miragopQW) >= 15 && mirapiss >= 3 && mirapiss < 6)
        {
            if(root->vEvent(miralko) >= 4)
            {
                root->incTime(5);
                if(root->vQuest(miragopQW) < 30)
                    root->vQuest(miragopQW) += 1;
                root->setImage(media(55));
                root->setText(str(24));
                makeActBtn("onBench",act(17));
            }
            else
            {
                root->incTime(5);
                if(root->vQuest(miragopQW) < 20)
                    root->vQuest(miragopQW) += 1;
                root->setImage(media(56));
                root->setText(str(25));
                makeActBtn("suckVasya2",act(0));
            }
        }
        else if(root->vQuest(miragopQW) >= 15 && mirapiss == 6)
        {
            if(root->vEvent(miralko) >= 4)
            {
                root->incTime(5);
                if(root->vQuest(miragopQW) < 30)
                    root->vQuest(miragopQW) += 1;
                if(root->vEvent(mitkasextimes) < 20)
                    root->vEvent(mitkasextimes) += 1;
                root->setImage(media(61));
                root->setText(str(32));
                makeActBtn("joinMiraMastr",act(18));
            }
            else
            {
                root->incTime(5);
                if(root->vQuest(miragopQW) < 25)
                    root->vQuest(miragopQW) += 1;
                root->setImage(media(42));
                root->setText(str(33));
                makeActBtn("dance",act(19));
            }
        }
        else
        {
            root->setImage(media(41));
            root->setText(str(17));
            makeActBtn("mitkabuhgroup",act(15));
        }
    }

    if(action == "suckVasya")
    {
        setVasyan();
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(getRandInt(43,47)));
        root->setText(str(19));
        root->blow_job();
        makeActBtn("swallowVasya",act(5));
    }
    if(action == "swallowVasya")
    {
        root->incTime(10);
        root->vStatistics(swallow) += 1;
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(48,52)));
        root->setText(str(20));
        makeActBtn("suckKolya",act(0));
    }
    if(action == "suckKolya")
    {
        setKolyamba();
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(getRandInt(45,47)));
        root->setText(str(21));
        root->blow_job();
        makeActBtn("swallowKolya",act(5));
    }
    if(action == "swallowKolya")
    {
        root->incTime(10);
        root->vStatistics(swallow) += 1;
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(48,52)));
        root->setText(str(22));
        makeActBtn("standBehindMitka",act(16));
    }
    if(action == "standBehindMitka")
    {
        root->incTime(15);
        setMitka();
        root->vSex(pose) = 1;
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(53,54)));
        root->setText(str(23));
        sexDepOnMesec();
        makeActBtn("gadukino",act(6));
    }

    if(action == "onBench")
    {
        root->incTime(5);
        root->vStatus(horny) += 20;
        root->setImage(media(57));
        root->setText(str(26));
        makeActBtn("onBench1",act(9));
    }
    if(action == "onBench1")
    {
        root->vSkill(domination) -= 2;
        root->vStatus(horny) += 30;
        root->vSex(pose) = 0;
        root->vStatistics(gangBang) += 1;
        root->incTime(10);
        root->setImage(media(58));
        root->setText(str(27));
        makeActBtn("onBench2",act(10));
    }
    if(action == "onBench2")
    {
        setKolyamba();
        root->vStatus(horny) += 10;
        root->incTime(10);
        root->cum("anus");
        root->setImage(media(58));
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
        makeActBtn("onBench3",act(10));
    }
    if(action == "onBench3")
    {
        setMitka();
        root->vStatus(horny) += 40;
        root->incTime(10);
        root->setImage(media(59));
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
        makeActBtn("onBench4",act(0));
    }
    if(action == "onBench4")
    {
        setVasyan();
        root->vStatus(horny) += 15;
        root->incTime(5);
        root->cum("lip");
        root->vStatistics(blowJob) += 1;
        root->setImage(media(60));
        root->blow_job();
        root->addText(str(13));
        makeActBtn("gadukino",act(6));
    }

    if(action == "suckVasya2")
    {
        setVasyan();
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(getRandInt(43,47)));
        root->setText(str(19));
        root->blow_job();
        makeActBtn("swallowVasya2",act(5));
    }
    if(action == "swallowVasya2")
    {
        root->incTime(10);
        root->vStatistics(swallow) += 1;
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(48,52)));
        root->setText(str(20));
        makeActBtn("suckKolya2",act(0));
    }
    if(action == "suckKolya2")
    {
        setKolyamba();
        root->incTime(10);;
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(getRandInt(43,47)));
        root->setText(str(28));
        root->blow_job();
        makeActBtn("swallovKolya2",act(5));
    }
    if(action == "swallovKolya2")
    {
        root->incTime(10);
        root->vStatistics(swallow) += 1;
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(48,52)));
        root->setText(str(29));
        makeActBtn("suckMitka",act(0));
    }
    if(action == "suckMitka")
    {
        setMitka();
        root->incTime(10);
        root->vStatus(horny) += 10;
        root->vStatistics(blowJob) += 1;
        root->setImage(media(getRandInt(43,47)));
        root->setText(str(30));
        root->blow_job();
        makeActBtn("swallovMitka",act(5));
    }
    if(action == "swallovMitka")
    {
        root->incTime(10);
        root->vStatistics(swallow) += 1;
        root->vStatus(horny) += 10;
        root->cum("lip");
        root->vSkill(domination) -= 1;
        root->setImage(media(getRandInt(48,52)));
        root->setText(str(31));
        makeActBtn("gadukino",act(6));
    }

    if(action == "joinMiraMastr")
    {
        root->incTime(15);
        root->vStatistics(orgasm) += 1;
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        if(root->vBody(anus) <= 15) root->setImage(media(62));
        if(root->vBody(anus) > 15) root->setImage(media(63));
        root->setText(str(34));
        makeActBtn("mitkabuhgroup",act(15));
    }

    if(action == "dance")
    {
        root->vStatus(horny) += getRandInt(25,50);
        root->setImage(media(getRandInt(64,67)));
        root->setText(str(35));
        makeActBtn("mitkabuhgroup",act(15));
    }

    if(action == "mitkabuhgroup")
        root->startEvent(eMitkaBuhGroup);
    if(action == "gadukino")
        root->changeLoc(lgadukino);
}

void MitkaBuhGroup::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"MitkaBuhGroup");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MitkaBuhGroup::actionHandler);
    root->addActions(btn);
}

QString MitkaBuhGroup::str(int id)
{
    QString str[36];
    str[0] = "Расположившись в укромном местечке, три деревенских пацана - Митька Шкворень, Васян Пакет и Колямба - пьют "
             "самогонку без всякой закуски. Вы с Мирославой подходите к ним и спрашиваете, можно ли к ним присоединиться. "
             "Парни тут же оживляются и активно кивают вам головами. Митька тут же начинает разливать самогон в стаканы, "
             "после чего подает один из них вам, сообщая, что так, как стаканов не всех не хватает, то вам придется пить из "
             "одного на двоих по очереди.";
    str[1] = "Вы напились в хлам, ноги уже практически не держат вас. Пацаны, заметив ваше состояние, тут же хватают вас с "
             "Мирой под руки и ведут домой к Митяю.";
    str[2] = "Митька";
    str[3] = "Васян";
    str[4] = "Колямба";
    str[5] = "Пацаны раздевают вас с Мирой и начинают ебать в рот по очереди, вместе, раздельно, насколько у них хватало фантазии.";
    str[6] = "Парни быстро насытились и начали кончать вам с Мирой на лица";
    str[7] = "Вас не раздевая поставили на колени перед вставшими членами и вы по одному стали их обслуживать.";
    str[8] = "Вскоре они кончают вам на лицо и теряют к вам всякий интерес...";
    str[9] = "Вас с Миркой быстро раздели и начали грубо трахать по очереди.";
    str[10] = "Под конец они поставили вас с Миркой на колени и начали кончать вам на лица.";
    str[11] = "Вы плюхаетесь на кровать и пацаны тут же начинают лапать вас и пихать пальцы во все щели.";
    str[12] = "Вы не успеваете устроится на кровати, как в рот вам тут же врывается чей-то член...";
    str[13] = "Обессиленные, вы слышите, как начинает натужно сопеть Васян и не мешкая, тут же покрепче сжимаете его член и направляете"
              " его себе в рот, через секунду ощущая в нем терпкий вкус спермы...";
    str[14] = "Пацаны махнув на прощание Митяю с Миркой отвели вас к Васяну домой, где быстро начали снимать с вас одежду...";
    str[15] = "Вы с Миркой послушно встаете на четвереньки. Пацаны тут же начинают пристраиваться к вашим дырочкам...";
    str[16] = "Вы берете стакан с самогоном и начинаете, кашляя и кривясь, цедить его сквозь зубы. Мирослава тем временем застенчиво "
              "отвечает на нагловатые вопросы деревенской молодежи.";
    str[17] = "Вы отдаете стакан с самогоном Мирославе и та, немного помедлив, начинает, кашляя и кривясь, цедить его сквозь зубы. Вы "
              "тем временем оживленно разговариваете с деревенскими.";
    str[18] = "Как только она выпила, подвыпивший Васян, словно в шутку, спрашивает у вас обоих, как вы смотрите на то, чтобы прямо здесь"
              " и сейчас отсосать."
              "Мирослава, уже изрядно подвыпившая, только хихикает в ответ, а вы, пожав плечами, согласно киваете головой. Колямба сразу "
              "же встал и обнял кокетничающую Мирославу, а Васян подошел к вам. Мира, пьяно хихикая встает перед Колямбой на колени, вы"
              " следуете её примеру и смотрите, как Васян неспеша расстегивает ширинку и приспускает штаны...";
    str[19] = "Вы, пьяно чавкая и причмокивая, послушно начинаете отсасывать...";
    str[20] = "Вы покрепче сжимаете член Васяна рукой и не вынимая его изо рта, начинаете яростно надрачивать его, пока, наконец,"
              " не чувствуете, как вам в рот начинает извергаться его теплая липкая сперма...";
    str[21] = "<npc>- Ну а теперь моя очередь,</npc> - говорит Колямба и подходит к вам.";
    str[22] = "Вы с энтузиазмом отсасываете и ему, после чего " + root->getBoyName() + " кончает.";
    str[23] = "Митька, уже успевший добавиться парой стаканов, молча подходит к вам и без предисловий говорит, чтобы вы стали в позу."
              " Вы, едва удерживаясь на ногах, подходите к валяющемуся поблизости бревну и облегченно упираетесь в него руками, "
              "чувствуя, как сзади подходит Митька и начинает оголять вашу задницу и приспустив свои штаны, начинает грубо вас трахать.";
    str[24] = "<npc>- Ну чо, девки, готовы поработать своими дырками?</npc> - раздается среди компашки пьяный требовательный голос."
              "Мирка что-то пьяно хихикает в ответ, после вы вдвоем с готовностью разворачиваетесь к компании спиной, подставляя гопоте"
              " свои голые задницы.";
    str[25] = "<npc>- Ну чо, девки, соснете у пацанов?</npc> - раздается среди компашки пьяный требовательный голос."
              "Вы киваете головой и покорно присаживаетесь прямо там, где и стояли, рядом присаживается Мирослава.";
    str[26] = "Вы плюхаетесь на лавочку и пацаны тут же начинают лапать вас и пихать пальцы во все щели.";
    str[27] = "Вы раздеваетесь и ложитесь на деревянную лавочку...";
    str[28] = "Вы причмокивая послушно сосете, изредко косясь на Мирославу.";
    str[29] = "Вы быстрее начинаете двигать своей головой, пока наконец, не чувствуете, как вам в рот начинает извергаться его теплая "
              "липкая сперма...";
    str[30] = "Вы устали, но послушно начинаете отсасывать...";
    str[31] = "Вы покрепче сжимаете член Митьки губами и наращиваете темп, пока наконец, не чувствуете, как вам в рот начинает извергаться"
              " его теплая липкая сперма...";
    str[32] = "<npc>- Ну чо, Мирка, покажешь нам шоу?</npc> - гогочет Колямба. <npc>- Покажи нам, как ты надрачиваешь свои дырки...</npc>"
              "Мирослава утвердительно мычит в ответ, после чего раздевается, стает на четвереньки и оттопырив задницу в сторону компании,"
              " начинает трахать себя пальцами в обе дырочки. Мирослава пьяно постанывает и протяжно стонет, неуклюже засовывая пальцы себе"
              " в дырочки. Васян смотрит на вас оценивающе и говорит: <npc>- Светик, че стала, давай присоеденяйся,</npc> - и начинает хохатать.";
    str[33] = "<npc>- Ну чо, девчонки, покажете нам шоу?</npc> - гогочет Колямба. <npc>- Давайте танцы...</npc>"
              "Мирослава и вы со смехом скидываете одежду...";
    str[34] = "Вы пьяно покачиваясь подходите к Мирославе и бухаетесь рядом с ней на колени. Сначала вам неудобно, но возбуждение берёт"
              " своё, и вот вы уже стонете, засовывая пальцы себе в дырочки, и наконец доводите себя до первого оргазма.";
    str[35] = "Вы кружитесь вокруг костранца в танце совершенно голые, вы пьяны, вам весело и интересно...";
    return str[id];
}

QString MitkaBuhGroup::act(int id)
{
    QString act[20];
    act[0] = "Сосать";
    act[1] = "Отдаться Митьке";
    act[2] = "Плюхнуться на кровать";
    act[3] = "Идти с пацанами";
    act[4] = "Встать в позу";
    act[5] = "Глотать";
    act[6] = "Уйти";
    act[7] = "Отдаться Колямбе";
    act[8] = "Отдаться Васяну";
    act[9] = "Дать пацанам";
    act[10] = "Стонать";
    act[11] = "Выпить";
    act[12] = "Отдышаться";
    act[13] = "Выпить самой";
    act[14] = "Отдать стакан Мирославе";
    act[15] = "Далее";
    act[16] = "Нагнуться";
    act[17] = "Сесть на лавку";
    act[18] = "Присоединиться";
    act[19] = "Танцевать";
    return act[id];
}

QString MitkaBuhGroup::media(int id)
{
    QString med[68];
    med[0] = "data/npc/gadukino/mitka/3boys.2.jpg";
    med[1] = "data/sex/mitkabuh_group/drunkgirl1.jpg";
    med[2] = "data/sex/mitkabuh_group/mitkabuhOral0.1.jpg";
    med[3] = "data/sex/mitkabuh_group/mitkabuhOral0.2.jpg";
    med[4] = "data/sex/mitkabuh_group/mitkabuhOral0.3.jpg";
    med[5] = "data/sex/mitkabuh_group/mitkabuhOral0.4.jpg";
    med[6] = "data/sex/mitkabuh_group/mitkabuhOral0.5.jpg";
    med[7] = "data/sex/mitkabuh_group/mitkabuhOral0.6.jpg";
    med[8] = "data/sex/mitkabuh_group/mitkabuhOral0.7.jpg";
    med[9] = "data/sex/mitkabuh_group/mitkabuhOral0.8.jpg";
    med[10] = "data/sex/mitkabuh_group/mitkabuhOralCum0.1.jpg";
    med[11] = "data/sex/mitkabuh_group/mitkabuhOralCum0.2.jpg";
    med[12] = "data/sex/mitkabuh_group/mitkabuhOralCum0.3.jpg";
    med[13] = "data/sex/mitkabuh_group/mitkabuhOralCum0.4.jpg";
    med[14] = "data/sex/mitkabuh_group/mitkabuhOralCum0.5.jpg";
    med[15] = "data/sex/mitkabuh_group/mitkabuh1.1.jpg";
    med[16] = "data/sex/mitkabuh_group/mitkabuh1.2.jpg";
    med[17] = "data/sex/mitkabuh_group/mitkabuh1.3.jpg";
    med[18] = "data/sex/mitkabuh_group/mitkabuh1.4.jpg";
    med[19] = "data/sex/mitkabuh_group/mitkabuh1.5.jpg";
    med[20] = "data/sex/mitkabuh_group/mitkabuhgroup1.1.jpg";
    med[21] = "data/sex/mitkabuh_group/mitkabuhgroup1.2.jpg";
    med[22] = "data/sex/mitkabuh_group/mitkabuhgroup1.3.jpg";
    med[23] = "data/sex/mitkabuh_group/mitkabuhgroup1.4.jpg";
    med[24] = "data/sex/mitkabuh_group/mitkabuhgroup1.5.jpg";
    med[25] = "data/sex/mitkabuh_group/mitkabuh2.1.jpg";
    med[26] = "data/sex/mitkabuh_group/mitkabuh2.2.jpg";
    med[27] = "data/sex/mitkabuh_group/mitkabuh2.3.jpg";
    med[28] = "data/sex/mitkabuh_group/mitkabuh2.3.jpg";
    med[29] = "data/sex/mitkabuh_group/mitkabuh2.4.jpg";
    med[30] = "data/sex/mitkabuh_group/mitkabuhanal0.1.jpg";
    med[31] = "data/sex/mitkabuh_group/mitkabuhanal0.2.jpg";
    med[32] = "data/sex/mitkabuh_group/mitkabuhanal0.3.jpg";
    med[33] = "data/sex/mitkabuh_group/mitkabuhanal0.4.jpg";
    med[34] = "data/sex/mitkabuh_group/mitkabuhanal0.5.jpg";
    med[35] = "data/sex/mitkabuh_group/mitkabuhgroup0.1.jpg";
    med[36] = "data/sex/mitkabuh_group/mitkabuhgroup0.2.jpg";
    med[37] = "data/sex/mitkabuh_group/mitkabuhgroup0.3.jpg";
    med[38] = "data/sex/mitkabuh_group/mitkabuhgroup0.4.jpg";
    med[39] = "data/sex/mitkabuh_group/mitkabuhgroup0.5.jpg";
    med[40] = "data/sex/mitkabuh_group/mitkabuhgroup.jpg";
    med[41] = "data/qwest/gadukino/drinking.jpg";
    med[42] = "data/sex/mitkabuh_group/drunk1.jpg";
    med[43] = "data/sex/mitkabuh_group/mitkabuh0.1.jpg";
    med[44] = "data/sex/mitkabuh_group/mitkabuh0.2.jpg";
    med[45] = "data/sex/mitkabuh_group/mitkabuh0.3.jpg";
    med[46] = "data/sex/mitkabuh_group/mitkabuh0.4.jpg";
    med[47] = "data/sex/mitkabuh_group/mitkabuh0.5.jpg";
    med[48] = "data/sex/mitkabuh_group/mitkabuhCum0.1.jpg";
    med[49] = "data/sex/mitkabuh_group/mitkabuhCum0.2.jpg";
    med[50] = "data/sex/mitkabuh_group/mitkabuhCum0.3.jpg";
    med[51] = "data/sex/mitkabuh_group/mitkabuhCum0.4.jpg";
    med[52] = "data/sex/mitkabuh_group/mitkabuhCum0.5.jpg";
    med[53] = "data/sex/mitkabuh_group/MitkaSexPublic0.1.jpg";
    med[54] = "data/sex/mitkabuh_group/MitkaSexPublic0.2.jpg";
    med[55] = "data/sex/mitkabuh_group/mitkabuhshow1.jpg";
    med[56] = "data/sex/mira/MiraQW11_4.jpg";
    med[57] = "data/sex/mitkabuh_group/MitkaGroup.jpg";
    med[58] = "data/sex/mitkabuh_group/MitkaGroupCum.jpg";
    med[59] = "data/sex/mitkabuh_group/MitkaGroupCum1.jpg";
    med[60] = "data/sex/mitkabuh_group/MitkaGroupCum2.jpg";
    med[61] = "data/sex/mira/MiraQW15.jpg";
    med[62] = "data/sex/mitkabuh_group/mitkabuhshow2.jpg";
    med[63] = "data/sex/mitkabuh_group/mitkabuhshow2.gif";
    med[64] = "data/sex/mitkabuh_group/mitkabuhdance0.0.jpg";
    med[65] = "data/sex/mitkabuh_group/mitkabuhdance0.1.jpg";
    med[66] = "data/sex/mitkabuh_group/mitkabuhdance0.2.jpg";
    med[67] = "data/sex/mitkabuh_group/mitkabuhdance0.3.jpg";
    return med[id];
}

void MitkaBuhGroup::setMitka()
{
    root->setBoyName(str(2));
    root->vSex(silavag) = 0;
    root->vSex(dick) = 16;
}

void MitkaBuhGroup::setVasyan()
{
    root->setBoyName(str(3));
    root->vSex(silavag) = 0;
    root->vSex(dick) = 14;
}

void MitkaBuhGroup::setKolyamba()
{
    root->setBoyName(str(4));
    root->vSex(silavag) = 0;
    root->vSex(dick) = 15;
}

void MitkaBuhGroup::sexDepOnMesec()
{
    if(root->isMesec())
    {
        root->analStart(tDick);
        root->anal(tDick);
        root->anal_cum();
    }
    else
    {
        root->vSex(protect) = 1;
        root->sexStart();
        root->vaginal(tDick);
        root->sex_cum();
    }
}
