#include "hantersex.h"
#include "../../menu/buttons.h"
#include "../eventhandler.h"
#include "../../Functions.h"

HanterSex::HanterSex(EventHandler* ptr): root(ptr) {}

void HanterSex::start(QString arg)
{
    //секс после стриптиза если ГГ не шлюха
    if(root->gVEvent(hantdancesex) == 1)
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->sVStatus(mood,100);
        root->uVSkill(domination,-1);
        resetCounters();
        checkHantSex();
        root->setImage(media(0));
        root->setDesc(str(0));
        makeActBtn("danceSex1.0",act(0));
    }
    //секс после стриптиза если ГГ шлюха
    if(root->gVEvent(hantdancesex) == 3)
    {
        root->incTime(5);
        root->uVSC(gangBang,1);
        root->sVStatus(mood,100);
        root->uVSkill(domination,-1);
        resetCounters();
        root->uVSC(blowJob,3);
        checkHantSex();
        root->uVEvent(hantslutsex,getRandInt(9,12));
        root->setImage(media(1));
        root->setDesc(str(28));
        makeActBtn("hantergrOi",act(1));
    }
    //секс если ГГ голая перед охотниками
    if(root->gVEvent(hantersexnude) == 1)
    {
        root->incTime(1);
        root->uVSC(gangBang,1);
        root->sVEvent(hantersexnude,0);
        root->uVSkill(domination,-1);
        resetCounters();
        root->uVSC(blowJob,3);
        checkHantSex();
        root->uVEvent(hantslutsex,getRandInt(9,12));
        root->setImage(media(89));
        root->setDesc(str(29));
        makeActBtn("hantersgrOasi",act(1));
    }
    //если ГГ шлюха
    if(root->gVEvent(sluthomesex) == 1)
    {
        root->incTime(5);
        root->sVEvent(sluthomesex,0);
        root->uVEvent(hantslutsex,getRandInt(3,6));
        root->sVStatus(clothesswamphouse,1);
        root->uVSkill(domination,-1);
        resetCounters();
        root->uVSC(blowJob,1);
        root->redress(ClothType::Main,nullptr);
        if(root->gVEvent(temphant) == 1)
        {
            if(root->gVEvent(hantersAndreisex) == 0)
            {
                root->sVEvent(hantersAndreisex,1);
                root->uVSex(guy,1);
            }
            setAndrei();
        }
        if(root->gVEvent(temphant) == 2)
        {
            if(root->gVEvent(hantersSergeisex) == 0)
            {
                root->sVEvent(hantersSergeisex,1);
                root->uVSex(guy,1);
            }
            setSergei();
        }
        if(root->gVEvent(temphant) == 3)
        {
            if(root->gVEvent(hantersIgorsex) == 0)
            {
                root->sVEvent(hantersIgorsex,1);
                root->uVSex(guy,1);
            }
            setIgor();
        }
        root->setImage(media(90));
        root->setDesc(str(30));
        makeActBtn("sluthomeSTART",act(11));
    }
    //трио
    if(root->gVEvent(doublelovesex) == 1 || root->gVEvent(slutgosex) == 2 || root->gVEvent(forest_hantersex) == 2 || root->gVEvent(forest_gopsex) == 2)
    {
        root->incTime(5);
        root->uVSkill(domination,-1);
        root->uVSC(gangBang,1);
        root->uVSC(blowJob,2);
        resetCounters();
        root->setImage(media(91));
        if(root->gVEvent(slutgosex) == 2)
            root->uVEvent(hantslutsex,getRandInt(6,9));
        if(root->gVEvent(doublelovesex) == 1)
        {
            root->uVEvent(hantersAndreisex,getRandInt(6,24));
            root->uVEvent(hantersSergeisex,getRandInt(9,20));
            root->setDesc(str(31));
        }
        else
            root->setDesc(str(32));
        root->sVEvent(slutgosex,0);
        root->sVEvent(doublelovesex,0);
        hantsexa = getRandInt(1,5);
        if(hantsexa < 4) makeActBtn("doubleloveOral12",act(1));
        if(hantsexa == 4) makeActBtn("doubleloveOralCum12_1",act(1));
        if(hantsexa == 5) makeActBtn("doubleloveOralCum12_2",act(1));
    }
}

void HanterSex::actionHandler(QString action)
{
    if(action.startsWith("danceSex"))
    {
        if(action == "danceSex1.0")
        {
            root->setImage(media(16));
            root->setDesc(str(1));
            makeActBtn("danceSex1.1",act(1));
        }
        if(action == "danceSex1.1")
        {
            root->incTime(5);
            setIgor();
            root->uVBody(throat,1);
            root->uVSC(blowJob,1);
            root->uVStatus(horny,getRandInt(10,20));
            root->setImage(media(5));
            root->setDesc(str(5));
            root->blow_job();
            root->addDesc(str(6));
            makeActBtn("danceSex1.2",act(2));
        }
        if(action == "danceSex1.2")
        {
            root->incTime(5);
            setIgor();
            root->setImage(media(11));
            root->setDesc(str(7));
            makeActBtn("danceSex1.3",act(2));
        }
        if(action == "danceSex1.3")
        {
            root->incTime(5);
            root->sVSex(pose,0);
            root->uVSex(lubonus,1);
            root->uVSC(blowJob,2);
            root->uVStatus(horny, getRandInt(10,20));
            root->setImage(media(getRandInt(2,4)));
            root->setDesc(str(8));
            setAndrei();
            root->blow_job();
            setSergei();
            root->blow_job();
            setIgor();
            root->blow_job();
            makeActBtn("danceSex1.4",act(3));
        }
        if(action == "danceSex1.4")
        {
            root->incTime(5);
            root->sVSex(pose,0);
            root->uVSC(vaginalSex,1);
            root->setImage(media(getRandInt(67,68)));
            root->setDesc(str(9));
            setSergei();
            root->blow_job();
            setIgor();
            root->blow_job();
            setAndrei();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.5",act(4));
        }
        if(action == "danceSex1.5")
        {
            root->incTime(5);
            root->sVSex(pose,0);
            root->uVSC(vaginalSex,1);
            root->setImage(media(getRandInt(78,81)));
            root->setDesc(str(10));
            setAndrei();
            root->blow_job();
            setIgor();
            root->blow_job();
            setSergei();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.6",act(5));
        }
        if(action == "danceSex1.6")
        {
            root->incTime(5);
            root->sVSex(pose,1);
            root->setImage(media(getRandInt(58,60)));
            root->setDesc(str(11));
            setSergei();
            root->blow_job();
            setIgor();
            root->blow_job();
            setAndrei();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.7",act(6));
        }
        if(action == "danceSex1.7")
        {
            root->incTime(5);
            root->sVSex(pose,1);
            root->uVSC(vaginalSex,1);
            root->setImage(media(getRandInt(70,73)));
            root->setDesc(str(12));
            setAndrei();
            root->blow_job();
            setSergei();
            root->blow_job();
            setIgor();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.8",act(7));
        }
        if(action == "danceSex1.8")
        {
            root->incTime(5);
            root->sVSex(pose,2);
            root->setImage(media(getRandInt(82,84)));
            root->setDesc(str(13));
            setAndrei();
            root->blow_job();
            setIgor();
            root->blow_job();
            setSergei();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.9",act(7));
        }
        if(action == "danceSex1.9")
        {
            root->incTime(5);
            root->sVSex(pose,2);
            root->setImage(media(getRandInt(63,65)));
            root->setDesc(str(14));
            setSergei();
            root->blow_job();
            setIgor();
            root->blow_job();
            setAndrei();
            root->sVSex(protect,1);
            root->vaginal(tDick);
            makeActBtn("danceSex1.10",act(0));
        }
        if(action == "danceSex1.10")
        {
            root->incTime(5);
            root->sVSex(pose,1);
            root->setImage(media(12));
            root->setDesc(str(15));
            makeActBtn("danceSex1.11",act(0));
        }
        if(action == "danceSex1.11")
        {
            root->incTime(5);
            root->sVSex(pose,1);
            root->uVSex(lubonus,5);
            root->uVStatus(mood,25);
            root->setImage(media(13));
            root->setDesc(str(16));
            makeActBtn("danceSex1.12",act(7));
        }
        if(action == "danceSex1.12")
        {
            root->incTime(5);
            root->sVSex(pose,1);
            root->setImage(media(getRandInt(42,43)));
            root->setDesc(str(17));
            setSergei();
            root->blow_job();
            setAndrei();
            setIgor2();
            root->sVSex(protect,1);
            root->dp_start();
            root->double_penetration();
            makeActBtn("danceSex1.13",act(3));
        }
        if(action == "danceSex1.13")
        {
            root->incTime(1);
            root->sVSex(pose,0);
            root->setImage(media(14));
            root->setDesc(str(18));
            makeActBtn("danceSex1.14",act(8));
        }
        if(action == "danceSex1.14")
        {
            root->incTime(1);
            root->sVSex(pose,0);
            root->cum("face");
            root->cum("belly");
            root->cum("lip");
            root->uVSC(swallow,1);
            root->setImage(media(15));
            root->setDesc(str(19));
            makeActBtn("danceSex1.15",act(9));
        }
        if(action == "danceSex1.15")
        {
            root->incTime(1);
            root->setImage(media(87));
            root->setDesc(str(20));
            if(root->gVEvent(hantersIgorLove) > 0) root->addDesc(str(21));
            if(root->gVEvent(hantersIgorLove) == 1 || root->gVEvent(hantersIgorLove) == 2) root->addDesc(str(22));
            if(root->gVEvent(hantersIgorLove) == 3) root->addDesc(str(23));
            if(root->gVEvent(hantersSergeiLove) > 0) root->addDesc(str(24));
            if(root->gVEvent(hantersSergeiLove) > 0) root->addDesc(str(25));
            if(root->gVEvent(hantersAndreiLove) > 0) root->addDesc(str(26));
            makeActBtn("danceSex1end",act(10));
        }
        if(action == "danceSex1end")
        {
            root->incTime(600);
            root->uVStatus(son,20);
            root->uVStatus(health,50);
            root->uVStatus(mood,50);
            root->sVEvent(hantdanceslut,1);
            if(root->gVEvent(hantersIgorLove) == 3)
            {
                root->sVEvent(hantersIgorLove,0);
                root->uVQuest(hantersIgorQW,-100);
                //husband = 0 & divorced += 1 & husbandMark = 0 & husbharmin = 0 & husbizvradd = 0
            }
            if(root->gVEvent(hantersIgorLove) == 2)
            {
                root->sVEvent(hantersIgorLove,0);
                root->uVQuest(hantersIgorQW,-100);
                //bFa = 0
            }
            if(root->gVEvent(hantersIgorLove) == 3)
            {
                root->sVEvent(hantersIgorLove,0);
                root->uVQuest(hantersIgorQW,-100);
            }
            if(root->gVEvent(hantersSergeiLove) == 1)
            {
                root->sVEvent(hantersSergeiLove,0);
                root->uVQuest(hantersSergeiQW,-100);
            }
            if(root->gVEvent(hantersAndreiLove) == 1)
            {
                root->sVEvent(hantersAndreiLove,0);
                root->uVQuest(hantersAndreiQW,-100);
            }
            root->setImage(media(88));
            root->setDesc(str(27));
            makeActBtn("swamphouse",act(0));
        }
    }
    if(action.startsWith("hantergr"))
    {
        if(action == "hantergrOi") hantergrOi();
        if(action == "hantersgrOasi") hantersgrOasi();
        if(action == "hantersgrVaOsi") hantersgrVaOsi();
        if(action == "hantersgrVOsi") hantersgrVOsi();
        if(action == "hantersgrVaO") hantersgrVaO();
        if(action == "hantersgrVaOi") hantersgrVaOi();
        if(action == "hantersgrVsOai") hantersgrVsOai();
        if(action == "hantersgrVOai") hantersgrVOai();
        if(action == "hantersgrVsOi") hantersgrVsOi();
        if(action == "hantersgrVsO") hantersgrVsO();
        if(action == "hantersgrViOas") hantersgrViOas();
        if(action == "hantersgrViO") hantersgrViO();
        if(action == "hantersgrVsOia") hantersgrVsOia();
        if(action == "hantersgrVsOi1") hantersgrVsOi1();
        if(action == "hantersgrVaOis") hantersgrVaOis();
        if(action == "hantersgrVaOs") hantersgrVaOs();
        if(action == "hantersgrVO") hantersgrVO();
        if(action == "hantersgrV2aOsi") hantersgrV2aOsi();
        if(action == "hantersgrV2aOs") hantersgrV2aOs();
        if(action == "hantersgrDPVaAiOs") hantersgrDPVaAiOs();
        if(action == "hantersgrDPVaAOs") hantersgrDPVaAOs();
        if(action == "hantersgrAiOsa") hantersgrAiOsa();
        if(action == "hantersgrAiO") hantersgrAiO();
        if(action == "hantersgrO3") hantersgrO3();
        if(action == "hantersgrO3_wait")
        {
            root->incTime(1);
            root->sVSex(pose,0);
            root->cum("face");
            root->cum("belly");
            root->cum("lip");
            root->uVSC(swallow,1);
            root->setImage(media(getRandInt(52,57)));
            root->setDesc(str(19));
            if(root->gVEvent(hantersexnude) == 0) makeActBtn("hantersgrEND",act(9));
            if(root->gVEvent(hantersexnude) == 1) makeActBtn("exit2",act(0));
        }
        if(action == "hantersgrEND") hantersgrEND();
        if(action == "hantersgrEND_wakeup")
        {
            root->incTime(600);
            root->uVStatus(son,20);
            root->uVStatus(health,50);
            root->uVStatus(mood,50);
            root->setImage(media(88));
            root->setDesc(str(27));
            makeActBtn("swamphouse",act(0));
        }
        if(action == "hantersgrAOsa") hantersgrAOsa();
        if(action == "hantersgr2VaOi") hantersgr2VaOi();
        if(action == "hantersgr2VOi") hantersgr2VOi();
        if(action == "hantersgr2VO") hantersgr2VO();
        if(action == "hantersgr2ViOa") hantersgr2ViOa();
        if(action == "hantersgr2ViO") hantersgr2ViO();
        if(action == "hantersgr2VsO") hantersgr2VsO();
        if(action == "hantersgr2VaOs") hantersgr2VaOs();
        if(action == "hantersgr2VaO") hantersgr2VaO();
        if(action == "hantersgr2AiOs") hantersgr2AiOs();
        if(action == "hantersgr2AOs") hantersgr2AOs();
        if(action == "hantersgr2AiO") hantersgr2AiO();
        if(action == "hantersgr2AOi") hantersgr2AOi();
        if(action == "hantersgr2AsO") hantersgr2AsO();
        if(action == "hantersgr2DPVaAs") hantersgr2DPVaAs();
        if(action == "hantersgr2DPVaA") hantersgr2DPVaA();
        if(action == "hantersgrO2") hantersgrO2();
        if(action == "hantersgr1Va") hantersgr1Va();
        if(action == "hantersgr1Ai") hantersgr1Ai();
        if(action == "hantersgr1Aa") hantersgr1Aa();
        if(action == "hantersgr1As") hantersgr1As();
        if(action == "hantersgrO1") hantersgrO1();
    }
    if(action.startsWith("sluthome"))
    {
        if(action == "sluthomeSTART") sluthomeSTART();
        if(action == "sluthomeORAL1") sluthomeORAL1();
        if(action == "sluthomeORAL2") sluthomeORAL2();
        if(action == "sluthomeORAL3") sluthomeORAL3();
        if(action == "sluthomeORAL4") sluthomeORAL4();
        if(action == "sluthomeOralCum1") sluthomeOralCum1();
        if(action == "sluthomeOralCum2") sluthomeOralCum2();
        if(action == "sluthomeOralCum3") sluthomeOralCum3();
        if(action == "sluthomeOralCum4") sluthomeOralCum4();
        if(action == "sluthomeTanga") sluthomeTanga();
        if(action == "sluthomeAnalDog1") sluthomeAnalDog1();
        if(action == "sluthomeAnalDog2") sluthomeAnalDog2();
        if(action == "sluthomeAnalDogCum1") sluthomeAnalDogCum1();
        if(action == "sluthomeAnalDogCum2") sluthomeAnalDogCum2();
        if(action == "sluthomeAnalCow1") sluthomeAnalCow1();
        if(action == "sluthomeAnalCow2") sluthomeAnalCow2();
        if(action == "sluthomeAnalCowCum1") sluthomeAnalCowCum1();
        if(action == "sluthomeAnalCowCum2") sluthomeAnalCowCum2();
        if(action == "sluthomeAnalSide1") sluthomeAnalSide1();
        if(action == "sluthomeAnalSide2") sluthomeAnalSide2();
        if(action == "sluthomeAnalSideCum1") sluthomeAnalSideCum1();
        if(action == "sluthomeAnalSideCum2") sluthomeAnalSideCum2();
    }
    if(action.startsWith("doublelove"))
    {
        if(action == "doubleloveOral1") doubleloveOral1();
        if(action == "doubleloveOralCum1") doubleloveOralCum1();
        if(action == "doubleloveOral12") doubleloveOral12();
        if(action == "doubleloveOralCum12") doubleloveOralCum12();
        if(action == "doubleloveOralCum12_1") doubleloveOralCum12_1();
        if(action == "doubleloveOralCum12_2") doubleloveOralCum12_2();
        if(action == "doubleloveOral2") doubleloveOral2();
        if(action == "doubleloveOralCum2") doubleloveOralCum2();

        if(action == "doubleloveDog112") doubleloveDog112();
        if(action == "doubleloveDogCum112_1") doubleloveDogCum112_1();
        if(action == "doubleloveDogCum112_2") doubleloveDogCum112_2();
        if(action == "doubleloveDog212") doubleloveDog212();
        if(action == "doubleloveDogCum212_1") doubleloveDogCum212_1();
        if(action == "doubleloveDogCum212_2") doubleloveDogCum212_2();

        if(action == "doubleloveSide12") doubleloveSide12();
        if(action == "doubleloveSideCum12_1") doubleloveSideCum12_1();
        if(action == "doubleloveSideCum12_2") doubleloveSideCum12_2();
        if(action == "doubleloveSide2") doubleloveSide2();
        if(action == "doubleloveSideCum2") doubleloveSideCum2();

        if(action == "doubleloveCow1") doubleloveCow1();
        if(action == "doubleloveCowCum1") doubleloveCowCum1();
        if(action == "doubleloveCow112") doubleloveCow112();
        if(action == "doubleloveCowCum112_1") doubleloveCowCum112_1();
        if(action == "doubleloveCowCum112_2") doubleloveCowCum112_2();
        if(action == "doubleloveCow212") doubleloveCow212();
        if(action == "doubleloveCowCum212_1") doubleloveCowCum212_1();
        if(action == "doubleloveCowCum212_2") doubleloveCowCum212_2();
    }
    if(action == "hantersexfaint")
        hantersexfaint();
    if(action == "hantersexfaint_up1")
    {
        root->incTime(10);
        root->sVStatus(health,100);
        root->uVStatus(mood,10);
        root->setDesc(str(113));
        makeActBtn("back_to_loc",act(0));
    }
    if(action == "hantersexfaint_up2")
    {
        root->incTime(10);
        root->sVStatus(health,100);
        root->uVStatus(mood,10);
        root->setDesc(str(114));
        makeActBtn("swamphouse",act(0));
    }
    if(action == "swamphouse")
        root->changeLoc(lswamphouse);
    if(action == "back_to_loc")
        root->changeLoc(root->getCurLoc());
    if(action == "exit1")
    {
        root->sVEvent(forest_hantersex,0);
        root->incTime(60);
        root->changeLoc(lswampyard);
    }
    if(action == "exit2")
    {
        root->sVEvent(hantersexnude,0);
        root->changeLoc(lswamphouse);
    }
}

void HanterSex::doubleloveOral1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,5);
    setAIMV();
    root->setImage(media(getRandInt(124,125)));
    root->setDesc(str(48));
    root->blow_job();
    root->addDesc(str(49));
    if(root->vStatus(health) > 50)
        makeActBtn("doubleloveOralCum1",act(2));
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveOralCum1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->cum("lip");
    root->uVSC(swallow,1);
    setAIMV();
    root->setImage(media(126));
    root->setDesc(str(48));
    root->blow_job();
    root->addDesc(str(46));
    root->sVSex(lubonus,0);
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("back_to_loc",act(0));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit1",act(0));
}
void HanterSex::doubleloveOral12()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,6);
    root->setImage(media(getRandInt(92,93)));
    root->setDesc(str(33));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->blow_job();
    root->addDesc(str(37));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDog112",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDog212",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveSide12",act(5));
        if(hantsexa == 5) makeActBtn("doubleloveCow112",act(7));
        if(hantsexa == 6) makeActBtn("doubleloveCow212",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveOralCum12()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->cum("lip");
    root->uVSC(swallow,1);
    root->cum("face");
    root->sVSex(lubonus,0);
    if(root->isNude()) root->cum("belly");
    if(root->isCloth()) root->uVStatus(cumFrot,getRandInt(0,1));
    root->setImage(media(getRandInt(130,132)));
    root->setDesc(str(50));
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("back_to_loc",act(0));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit1",act(0));
}
void HanterSex::doubleloveOralCum12_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,2);
    hantsexa = getRandInt(1,2);
    root->setImage(media(94));
    root->setDesc(str(33));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveOralCum12_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,2);
    hantsexa = getRandInt(1,2);
    root->setImage(media(95));
    root->setDesc(str(33));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveOral2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    setSIKV();
    root->setImage(media(getRandInt(127,128)));
    root->setDesc(str(48));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(49));
    if(root->vStatus(health) > 50)
        makeActBtn("doubleloveOralCum2",act(2));
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveOralCum2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    setSIKV();
    root->setImage(media(129));
    root->setDesc(str(48));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(46));
    root->sVSex(lubonus,0);
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("back_to_loc",act(0));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit1",act(0));
}
void HanterSex::doubleloveDog112()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,7);
    root->setImage(media(getRandInt(96,98)));
    root->setDesc(str(39));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(40));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDogCum112_1",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDogCum112_2",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveDog212",act(13));
        if(hantsexa == 5) makeActBtn("doubleloveSide12",act(5));
        if(hantsexa == 6) makeActBtn("doubleloveCow112",act(7));
        if(hantsexa == 7) makeActBtn("doubleloveCow212",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveDogCum112_1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    hantsexa = getRandInt(1,2);
    root->setImage(media(99));
    root->setDesc(str(41));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(38));
    root->uVSex(lubonus,1);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveDogCum112_2()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(100));
    root->setDesc(str(41));
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    setSIKV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveDog212()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,7);
    root->setImage(media(getRandInt(101,103)));
    root->setDesc(str(41));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(40));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDogCum212_1",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDogCum212_2",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveDog112",act(13));
        if(hantsexa == 5) makeActBtn("doubleloveSide12",act(5));
        if(hantsexa == 6) makeActBtn("doubleloveCow112",act(7));
        if(hantsexa == 7) makeActBtn("doubleloveCow212",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveDogCum212_1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    hantsexa = getRandInt(1,2);
    root->setImage(media(104));
    root->setDesc(str(41));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(38));
    root->uVSex(lubonus,1);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));

}
void HanterSex::doubleloveDogCum212_2()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(105));
    root->setDesc(str(41));
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    setAIMV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveSide12()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,7);
    root->setImage(media(getRandInt(106,107)));
    root->setDesc(str(42));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(40));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDog212",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDog112",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveSideCum12_1",act(5));
        if(hantsexa == 5) makeActBtn("doubleloveSideCum12_2",act(5));
        if(hantsexa == 6) makeActBtn("doubleloveCow112",act(7));
        if(hantsexa == 7) makeActBtn("doubleloveCow212",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveSideCum12_1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    hantsexa = getRandInt(1,2);
    root->setImage(media(108));
    root->setDesc(str(42));
    setAIMV();
    root->blow_job();
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(38));
    root->uVSex(lubonus,1);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveSideCum12_2()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(109));
    root->setDesc(str(42));
    setSIKV();
    root->analStart(tDick);
    root->anal(tDick);
    setAIMV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveSide2()
{
    root->incTime(5);
    hantsexa = getRandInt(1,2);
    setSIKV();
    root->setImage(media(getRandInt(118,119)));
    root->setDesc(str(44));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSideCum2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveSideCum2()
{
    root->incTime(5);
    root->cum("anus");
    setSIKV();
    root->setImage(media(120));
    root->setDesc(str(44));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    root->sVSex(lubonus,0);
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("back_to_loc",act(0));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit1",act(0));
}
void HanterSex::doubleloveCow1()
{
    root->incTime(5);
    hantsexa = getRandInt(1,2);
    setAIMV();
    root->setImage(media(getRandInt(121,122)));
    root->setDesc(str(47));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCowCum1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCowCum1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    setAIMV();
    root->setImage(media(123));
    root->setDesc(str(47));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    root->sVSex(lubonus,0);
    if(root->gVEvent(forest_hantersex) == 0)
        makeActBtn("back_to_loc",act(0));
    if(root->gVEvent(forest_hantersex) > 0)
        makeActBtn("exit1",act(0));
}
void HanterSex::doubleloveCow112()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,7);
    root->setImage(media(getRandInt(110,111)));
    root->setDesc(str(43));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(40));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDog112",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDog212",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveSide12",act(5));
        if(hantsexa == 5) makeActBtn("doubleloveCowCum112_1",act(7));
        if(hantsexa == 6) makeActBtn("doubleloveCowCum112_2",act(7));
        if(hantsexa == 7) makeActBtn("doubleloveCow212",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCowCum112_1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    hantsexa = getRandInt(1,2);
    root->setImage(media(112));
    root->setDesc(str(43));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(38));
    root->uVSex(lubonus,1);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCowCum112_2()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(113));
    root->setDesc(str(43));
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    setSIKV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCow212()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,7);
    root->setImage(media(getRandInt(114,115)));
    root->setDesc(str(43));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(40));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveOralCum12",act(12));
        if(hantsexa == 2) makeActBtn("doubleloveDog112",act(13));
        if(hantsexa == 3) makeActBtn("doubleloveDog212",act(13));
        if(hantsexa == 4) makeActBtn("doubleloveSide12",act(5));
        if(hantsexa == 5) makeActBtn("doubleloveCowCum212_1",act(7));
        if(hantsexa == 6) makeActBtn("doubleloveCowCum212_2",act(7));
        if(hantsexa == 7) makeActBtn("doubleloveCow112",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCowCum212_1()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    root->cum("anus");
    hantsexa = getRandInt(1,2);
    root->setImage(media(116));
    root->setDesc(str(43));
    setSIKV();
    root->blow_job();
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(38));
    root->uVSex(lubonus,1);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveSide2",act(5));
        if(hantsexa == 2) makeActBtn("doubleloveOral2",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::doubleloveCowCum212_2()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(117));
    root->setDesc(str(43));
    setAIMV();
    root->analStart(tDick);
    root->anal(tDick);
    setSIKV();
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(38));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("doubleloveCow1",act(7));
        if(hantsexa == 2) makeActBtn("doubleloveOral1",act(1));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}

void HanterSex::sluthomeSTART()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(1,5));
    root->uVSC(blowJob,1);
    hantsexa = getRandInt(5,10);
    root->setImage(media(133));
    root->setDesc(str(51));
    if(hantsexa == 1) makeActBtn("sluthomeORAL1",act(1));
    if(hantsexa == 2) makeActBtn("sluthomeOralCum1",act(1));
    if(hantsexa == 3) makeActBtn("sluthomeTanga",act(15));
}
void HanterSex::sluthomeORAL1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,5);
    root->setImage(media(getRandInt(134,136)));
    root->setDesc(str(52));
    root->blow_job();
    root->addDesc(str(49));
    if(hantsexa == 1) makeActBtn("sluthomeORAL2",act(2));
    if(hantsexa == 2) makeActBtn("sluthomeOralCum2",act(2));
    if(hantsexa == 3) makeActBtn("sluthomeORAL3",act(2));
    if(hantsexa == 4) makeActBtn("sluthomeOralCum3",act(2));
    if(hantsexa == 5) makeActBtn("sluthomeTanga",act(15));
}
void HanterSex::sluthomeOralCum1()
{
    root->incTime(5);
    root->sVSex(lubonus,0);
    root->setImage(media(137));
    root->setDesc(str(52));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeORAL2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,4);
    root->setImage(media(getRandInt(143,145)));
    root->setDesc(str(52));
    root->blow_job();
    root->addDesc(str(40));
    if(hantsexa == 1) makeActBtn("sluthomeOralCum2",act(2));
    if(hantsexa == 2) makeActBtn("sluthomeORAL3",act(2));
    if(hantsexa == 3) makeActBtn("sluthomeOralCum3",act(2));
    if(hantsexa == 4) makeActBtn("sluthomeTanga",act(15));
}
void HanterSex::sluthomeOralCum2()
{
    root->incTime(5);
    root->sVSex(lubonus,0);
    root->setImage(media(138));
    root->setDesc(str(52));
    root->blow_job();
    root->fnswallow();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeORAL3()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(getRandInt(146,147)));
    root->setDesc(str(53));
    if(root->vBody(throat) < root->vSex(dick))
        root->addDesc(str(54));
    if(root->vBody(throat) > root->vSex(dick))
        root->addDesc(str(55));
    if(hantsexa) makeActBtn("sluthomeOralCum3",act(2));
    if(hantsexa) makeActBtn("sluthomeTanga",act(15));
}
void HanterSex::sluthomeOralCum3()
{
    root->incTime(5);
    root->sVSex(lubonus,0);
    root->setImage(media(139));
    root->setDesc(str(53));
    if(root->vBody(throat) < root->vSex(dick))
        root->addDesc(str(54));
    if(root->vBody(throat) > root->vSex(dick))
        root->addDesc(str(55));
    root->addDesc(str(56));
    root->fnswallow();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeORAL4()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,2);
    root->setImage(media(getRandInt(146,147)));
    root->blow_job();
    root->addDesc(str(49));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeOralCum4",act(2));
        if(hantsexa == 2) makeActBtn("sluthomeAnalDog1",act(13));
        if(hantsexa == 3) makeActBtn("sluthomeAnalDogCum1",act(13));
        if(hantsexa == 4) makeActBtn("sluthomeAnalCow1",act(7));
        if(hantsexa == 5) makeActBtn("sluthomeAnalCowCum1",act(7));
        if(hantsexa == 6) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 7) makeActBtn("sluthomeAnalSideCum1",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeOralCum4()
{
    root->incTime(5);
    root->cum("lip");
    root->cum("face");
    root->uVSC(swallow,1);
    root->cum("belly");
    root->sVSex(lubonus,0);
    root->setImage(media(getRandInt(140,142)));
    root->addDesc(str(57));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeTanga()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->redress(ClothType::Panties,nullptr);
    hantsexa = getRandInt(1,6);
    root->setImage(media(151));
    root->setDesc(str(58));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeAnalDog1",act(13));
        if(hantsexa == 2) makeActBtn("sluthomeAnalDogCum1",act(13));
        if(hantsexa == 3) makeActBtn("sluthomeAnalCow1",act(7));
        if(hantsexa == 4) makeActBtn("sluthomeAnalCowCum1",act(7));
        if(hantsexa == 5) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 6) makeActBtn("sluthomeAnalSideCum1",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalDog1()
{
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,10);
    root->setImage(media(getRandInt(152,153)));
    root->setDesc(str(59));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeAnalDog2",act(13));
        if(hantsexa == 2) makeActBtn("sluthomeAnalDogCum2",act(13));
        if(hantsexa == 3) makeActBtn("sluthomeAnalCow1",act(7));
        if(hantsexa == 4) makeActBtn("sluthomeAnalCowCum1",act(7));
        if(hantsexa == 5) makeActBtn("sluthomeAnalCow2",act(7));
        if(hantsexa == 6) makeActBtn("sluthomeAnalCowCum2",act(7));
        if(hantsexa == 7) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 8) makeActBtn("sluthomeAnalSideCum1",act(5));
        if(hantsexa == 9) makeActBtn("sluthomeAnalSide2",act(5));
        if(hantsexa == 10) makeActBtn("sluthomeAnalSideCum2",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalDogCum1()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(154));
    root->setDesc(str(60));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeAnalDog2()
{
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,5);
    root->setImage(media(getRandInt(156,157)));
    root->setDesc(str(61));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeORAL4",act(1));
        if(hantsexa == 2) makeActBtn("sluthomeAnalCow1",act(7));
        if(hantsexa == 3) makeActBtn("sluthomeAnalCowCum1",act(7));
        if(hantsexa == 4) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 5) makeActBtn("sluthomeAnalSideCum1",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalDogCum2()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(155));
    root->setDesc(str(61));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeAnalCow1()
{
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,10);
    root->setImage(media(getRandInt(158,160)));
    root->setDesc(str(62));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeAnalDog1",act(13));
        if(hantsexa == 2) makeActBtn("sluthomeAnalDogCum1",act(13));
        if(hantsexa == 3) makeActBtn("sluthomeAnalDog2",act(13));
        if(hantsexa == 4) makeActBtn("sluthomeAnalDogCum2",act(13));
        if(hantsexa == 5) makeActBtn("sluthomeAnalCow2",act(7));
        if(hantsexa == 6) makeActBtn("sluthomeAnalCowCum2",act(7));
        if(hantsexa == 7) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 8) makeActBtn("sluthomeAnalSideCum1",act(5));
        if(hantsexa == 9) makeActBtn("sluthomeAnalSide2",act(5));
        if(hantsexa == 10) makeActBtn("sluthomeAnalSideCum2",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalCowCum1()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(161));
    root->setDesc(str(62));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeAnalCow2()
{
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,10);
    root->setImage(media(getRandInt(163,164)));
    root->setDesc(str(63));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeORAL4",act(1));
        if(hantsexa == 7) makeActBtn("sluthomeAnalSide1",act(5));
        if(hantsexa == 8) makeActBtn("sluthomeAnalSideCum1",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalCowCum2()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(162));
    root->setDesc(str(63));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeAnalSide1()
{
    root->sVSex(pose,0);
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,10);
    root->setImage(media(getRandInt(165,166)));
    root->setDesc(str(64));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeAnalDog1",act(13));
        if(hantsexa == 2) makeActBtn("sluthomeAnalDogCum1",act(13));
        if(hantsexa == 3) makeActBtn("sluthomeAnalDog2",act(13));
        if(hantsexa == 4) makeActBtn("sluthomeAnalDogCum2",act(13));
        if(hantsexa == 5) makeActBtn("sluthomeAnalCow1",act(7));
        if(hantsexa == 6) makeActBtn("sluthomeAnalCowCum1",act(7));
        if(hantsexa == 7) makeActBtn("sluthomeAnalCow2",act(7));
        if(hantsexa == 8) makeActBtn("sluthomeAnalCowCum2",act(7));
        if(hantsexa == 9) makeActBtn("sluthomeAnalSide2",act(5));
        if(hantsexa == 10) makeActBtn("sluthomeAnalSideCum2",act(5));
    }
    else
        makeActBtn("hantersexfaint",act(14));

}
void HanterSex::sluthomeAnalSideCum1()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(167));
    root->setDesc(str(64));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}
void HanterSex::sluthomeAnalSide2()
{
    root->sVSex(pose,0);
    root->incTime(5);
    checkBoyAsexA();
    hantsexa = getRandInt(1,2);
    root->setImage(media(getRandInt(169,170)));
    root->setDesc(str(65));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(45));
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("sluthomeORAL4",act(1));
        if(hantsexa == 2) makeActBtn("sluthomeOralCum4",act(12));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::sluthomeAnalSideCum2()
{
    root->incTime(5);
    root->cum("anus");
    root->setImage(media(168));
    root->setDesc(str(65));
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(46));
    makeActBtn("swamphouse",act(0));
}

void HanterSex::hantergrOi()
{
    root->sVSex(pose,0);
    root->incTime(5);
    setIgor();
    root->uVBody(throat,1);
    root->uVStatus(horny,getRandInt(10,20));
    root->setImage(media(getRandInt(6,10)));
    root->setDesc(str(66));
    root->blow_job();
    root->addDesc(str(67));
    hantsexa = getRandInt(1,2);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantergrOi",act(2));
        if(hantsexa == 2) makeActBtn("hantersgrOasi",act(16));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgrOasi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->uVStatus(horny,getRandInt(10,20));
    root->uVSex(lubonus,1);
    root->setImage(media(getRandInt(2,4)));
    setAndrei();
    root->uVSC(blowJob,1);
    root->blow_job();
    setSergei();
    root->uVSC(blowJob,1);
    root->blow_job();
    setIgor();
    root->uVSC(blowJob,1);
    root->blow_job();
    hantsexa = getRandInt(1,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrVaOsi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(getRandInt(67,68)));
    root->setDesc(str(9));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrVOsi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(77));
    root->setDesc(str(9));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(68));
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);

    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgr2VsO",act(7));
        if(hantsexa == 2 && hantsexb > 5) makeActBtn("hantersgr2AiOs",act(3));
        if(hantsexa == 2 && hantsexb == 5) makeActBtn("hantersgr2AiO",act(3));
        if(hantsexa == 2 && hantsexb < 5) makeActBtn("hantersgr2AOs",act(3));
        if(hantsexa == 3 && hantsexb <= 5) makeActBtn("hantersgr2AOi",act(7));
        if(hantsexa == 3 && hantsexb > 5) makeActBtn("hantersgr2AsO",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgrVaO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(66));
    root->setDesc(str(9));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setSergei();
    root->fnswallow();
    setIgor();
    root->fnswallow();
    root->addDesc(str(69));
    hantsexa = getRandInt(1,3);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgr1Va",act(7));
        if(hantsexa == 2) makeActBtn("hantersgrO1",act(3));
        if(hantsexa == 3) makeActBtn("hantersgr1Aa",act(7));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgrVaOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(62));
    root->setDesc(str(9));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setSergei();
    root->fnswallow();
    root->addDesc(str(70));
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);
    actions3();
}
void HanterSex::hantersgrVsOai()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(getRandInt(78,81)));
    root->setDesc(str(10));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrVOai()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(75));
    root->setDesc(str(10));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(71));
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);
    actions3();
}
void HanterSex::hantersgrVsOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(85));
    root->setDesc(str(10));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setAndrei();
    root->fnswallow();
    root->addDesc(str(72));
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);
    actions2();
}
void HanterSex::hantersgrVsO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(86));
    root->setDesc(str(10));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setIgor();
    root->fnswallow();
    root->addDesc(str(73));
    if(root->vStatus(health) > 50)
        makeActBtn("hantersgr1As",act(7));
    else
        makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgrViOas()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(70,73)));
    root->setDesc(str(74));
    setAndrei();
    root->blow_job();
    setSergei();
    root->blow_job();
    setIgor();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrViO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(74));
    root->setDesc(str(74));
    setAndrei();
    root->blow_job();
    setSergei();
    root->blow_job();
    setIgor();
    checkBoyCsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setSergei();
    root->fnswallow();
    setAndrei();
    root->fnswallow();
    root->addDesc(str(75));
    actions5();
}
void HanterSex::hantersgrVsOia()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(getRandInt(82,84)));
    root->setDesc(str(13));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrVsOi1()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(getRandInt(82,84)));
    root->setDesc(str(13));
    setAndrei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->vaginal(tDick);
    setAndrei();
    root->fnswallow();
    root->addDesc(str(76));
    actions2();
}
void HanterSex::hantersgrVaOis()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(getRandInt(63,65)));
    root->setDesc(str(14));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrVaOs()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(69));
    root->setDesc(str(14));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setIgor();
    root->fnswallow();
    root->addDesc(str(77));
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgrVO()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(76));
    root->setDesc(str(14));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    setIgor();
    root->fnswallow();
    setSergei();
    root->fnswallow();
    root->addDesc(str(78));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgrV2aOsi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(58,60)));
    root->setDesc(str(11));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrV2aOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(61));
    root->setDesc(str(11));
    setSergei();
    root->blow_job();
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setIgor();
    root->fnswallow();
    root->addDesc(str(79));
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgrDPVaAiOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(42,43)));
    root->setDesc(str(80));
    setSergei();
    root->blow_job();
    setAndrei();
    setIgor2();
    checkBoyAsex();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrDPVaAOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(44));
    root->setDesc(str(00));
    setSergei();
    root->blow_job();
    setAndrei();
    setIgor2();
    checkBoyAsex();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    root->uVSex(lubonus,2);
    root->cum("anus");
    root->addDesc(str(81));
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgrAiOsa()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(40));
    root->setDesc(str(82));
    setSergei();
    root->blow_job();
    setAndrei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(2,10);
    hantsexb = getRandInt(1,8);
    actions1();
}
void HanterSex::hantersgrAiO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(39));
    root->setDesc(str(82));
    setSergei();
    root->blow_job();
    setAndrei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    setAndrei();
    root->fnswallow();
    setSergei();
    root->fnswallow();
    root->addDesc(str(83));
    actions5();
}
void HanterSex::hantersgrO3()
{
    root->incTime(1);
    root->sVSex(pose,0);
    root->setImage(media(getRandInt(48,51)));
    root->setDesc(str(84));
    makeActBtn("hantersgrO3_wait",act(8));
}
void HanterSex::hantersgrEND()
{
    root->incTime(1);
    root->setImage(media(87));
    root->setDesc(str(20));
    makeActBtn("hantersgrEND_wakeup",act(10));
}
void HanterSex::hantersgrAOsa()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(41));
    root->setDesc(str(82));
    setSergei();
    root->blow_job();
    setAndrei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->uVSex(lubonus,2);
    root->addDesc(str(85));
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgr2VaOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(30));
    root->setDesc(str(86));
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);
    actions3();
}
void HanterSex::hantersgr2VOi()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(36));
    root->setDesc(str(86));
    setIgor();
    root->blow_job();
    setAndrei();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(68));
    actions5();
}
void HanterSex::hantersgr2VO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(37));
    root->setDesc(str(86));
    setIgor();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    setIgor();
    root->fnswallow();
    root->addDesc(str(87));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgr2ViOa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(33,34)));
    root->setDesc(str(88));
    setAndrei();
    root->blow_job();
    setIgor();
    root->sVSex(protect,1);
    checkBoyCsex();
    root->vaginal(tDick);
    hantsexa = getRandInt(1,3);
    hantsexa = getRandInt(1,8);
    actions3();
}
void HanterSex::hantersgr2ViO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(35));
    root->setDesc(str(88));
    setAndrei();
    root->blow_job();
    setIgor();
    root->sVSex(protect,1);
    checkBoyCsex();
    root->vaginal(tDick);
    setAndrei();
    root->fnswallow();
    root->addDesc(str(89));
    actions5();
}
void HanterSex::hantersgr2VsO()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(38));
    root->setDesc(str(90));
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setIgor();
    root->fnswallow();
    root->addDesc(str(91));
    if(root->vStatus(health) > 50) makeActBtn("hantersgr1As",act(7));
    else makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgr2VaOs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(32));
    root->setDesc(str(92));
    setSergei();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgr2VaO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(31));
    root->setDesc(str(92));
    setSergei();
    root->blow_job();
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->vaginal(tDick);
    setSergei();
    root->uVSC(swallow,1);
    root->fnswallow();
    root->addDesc(str(93));
    hantsexa = getRandInt(1,3);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgr1Va",act(7));
        if(hantsexa == 2) makeActBtn("hantersgrO1",act(3));
        if(hantsexa == 3) makeActBtn("hantersgr1Aa",act(7));
    }
    else makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgr2AiOs()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(22));
    root->setDesc(str(94));
    setSergei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    hantsexa = getRandInt(1,3);
    hantsexb = getRandInt(1,8);
    actions2();
}
void HanterSex::hantersgr2AOs()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(24));
    root->setDesc(str(94));
    setSergei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->uVSex(lubonus,2);
    root->addDesc(str(95));
    if(root->vStatus(health) > 50) makeActBtn("hantersgr1As",act(7));
    else makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgr2AiO()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(21));
    root->setDesc(str(94));
    setSergei();
    root->blow_job();
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    setSergei();
    root->uVSC(swallow,1);
    root->fnswallow();
    root->addDesc(str(96));
    actions5();
}
void HanterSex::hantersgr2AOi()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(23));
    root->setDesc(str(97));
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(98));
    actions5();
}
void HanterSex::hantersgr2AsO()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(25));
    root->setDesc(str(97));
    setIgor();
    root->blow_job();
    setSergei();
    checkBoyBsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    setIgor();
    root->fnswallow();
    root->addDesc(str(99));
    if(root->vStatus(health) > 50) makeActBtn("hantersgr1As",act(7));
    else makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgr2DPVaAs()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(getRandInt(27,29)));
    root->setDesc(str(100));
    setAndrei();
    setSergei2();
    checkBoyAsex();
    checkBoyBsexA();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    hantsexa = getRandInt(1,2);
    hantsexb = getRandInt(1,8);
    actions4();
}
void HanterSex::hantersgr2DPVaA()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(26));
    root->setDesc(str(100));
    setAndrei();
    setSergei2();
    checkBoyAsex();
    checkBoyBsexA();
    root->sVSex(protect,1);
    root->dp_start();
    root->double_penetration();
    root->addDesc(str(101));
    root->uVSex(lubonus,2);
    root->cum("anus");
    hantsexa = getRandInt(1,3);
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgr1Va",act(7));
        if(hantsexa == 2) makeActBtn("hantersgrO1",act(3));
        if(hantsexa == 3) makeActBtn("hantersgr1Aa",act(7));
    }
    else makeActBtn("hantersexfaint",act(14));
}
void HanterSex::hantersgrO2()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->cum("face");
    root->cum("lip");
    root->uVSC(swallow,2);
    root->setImage(media(getRandInt(46,47)));
    root->setDesc(str(102));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgr1Va()
{
    root->incTime(5);
    root->sVSex(pose,2);
    root->setImage(media(20));
    root->setDesc(str(103));
    setAndrei();
    checkBoyAsex();
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->sex_cum();
    root->addDesc(str(104));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgr1Ai()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->setImage(media(18));
    root->setDesc(str(106));
    setIgor();
    checkBoyCsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(105));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgr1Aa()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(17));
    root->setDesc(str(107));
    setAndrei();
    checkBoyAsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(108));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgr1As()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->setImage(media(19));
    root->setDesc(str(109));
    setSergei();
    checkBoyBsexA();
    root->sVSex(protect,1);
    root->analStart(tDick);
    root->anal(tDick);
    root->anal_cum();
    root->addDesc(str(110));
    makeActBtn("hantersgrEND",act(9));
}
void HanterSex::hantersgrO1()
{
    root->incTime(5);
    root->sVSex(pose,0);
    root->cum("face");
    root->cum("lip");
    root->uVSC(swallow,2);
    root->setImage(media(45));
    root->setDesc(str(111));
    makeActBtn("hantersgrEND",act(9));
}

void HanterSex::hantersexfaint()
{
    root->incTime(1);
    root->uVStatus(horny,getRandInt(5,10));
    root->setImage(media(171));
    root->setDesc(str(112));
    if(root->gVEvent(hantersRape) == 4 || root->gVEvent(hantdanceslut) == 4)
        makeActBtn("hantersexfaint_up1",act(17));
    else
        makeActBtn("hantersexfaint_up2",act(17));
}

void HanterSex::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action,"HanterSex");
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &HanterSex::actionHandler);
    root->addActBtn(btn);
}

QString HanterSex::str(int id)
{
    QString str[115];
    if(id < 21)
    {
        str[0] = "Вы устало присели на край стола, чтобы отдохнуть и перекурить. Во время танца вы не обращали на парней внимания, "
                 "однако когда к вам подошел Игорь, вы поняли, что они все тоже полностью обнажены."
                 "<npc>- Светик, мы требуем продолжения банкета,</npc> - сказал он улыбаясь и показав на свой член.";
        str[1] = "Алкоголь притупил ваше чувство стыда и вы не сомневаясь взяли член в руку и поднесли ко рту...";
        str[2] = "Игорь";
        str[3] = "Сергей";
        str[4] = "Андрей";
        str[5] = "Вы принялись сосать...";
        str[6] = "Вдруг Игорь не дав вам опомнится засадил свой член вам в горло на всю длинну, аж слезы из глаз брызгнули...";
        str[7] = "Игорь продолжать долбить ваш рот, а Андрей с Сергеем с интереом наблюдали и даже помогали ему, давя врямя от времени вам на затылок...";
        str[8] = "Андрей с Сергеем решили тоже принять участие и подставили вам свои члены. Вы принялись сосать у обступивших вас парней, поочередно уделяя внимание каждому члену.";
        str[9] = "Парни положили вас на топчан, Андрей начал пристраиваться между ног, а Игорь и Сергей стали над вами выставив свои члены перед вашим лицом...";
        str[10] = "Парни положили вас на топчан. Сергей начал пристраиваться между ног, а Игорь и Андрей стали над вами выставив свои члены перед вашим лицом...";
        str[11] = "Андрей положил вас на бок и начал пристраиваться между ног, а Игорь и Сергей стали перед вами выставив свои члены перед лицом...";
        str[12] = "Вас поставили на четвереньки. Игорь начал пристраиваться сзади, а Игорь и Андрей стали перед вами выставив свои члены перед вашим лицом...";
        str[13] = "Сергей сел на топчан, потянув вас за собой, а Игорь и Андрей стали перед вами выставив свои члены перед вашим лицом...";
        str[14] = "Андрей сел на топчан, потянув вас за собой, а Игорь и Сергей пристроились рядом вами выставив свои члены перед вашим лицом...";
        str[15] = "Вы отсасывали у Игоря, когда почувствовали как чей-то палец начинает проникать в вашу попу..."
                  "<hero>- Попе видно сегодня тоже достанется,</hero> - подумали вы.";
        str[16] = "Андрей обильно смазал вашу попу вазелином..."
                  "<hero>- Ну хоть так, не на сухую,</hero> - подумали вы с облегчением.";
        str[17] = "Андрей лёг на землю, потянув вас за собой, Игорь сразу же начал пристраиваться к вашей второй дырочке, вам остается лишь расслабиться и сосать член Сергея...";
        str[18] = "Парни положили вас на спину, а сами нависли над вами. Они принялись дрочить перед вашим лицом, и вы поняли что они скоро кончат...";
        str[19] = "Наконец парни начали кончать, струи спермы ударили в ваше лицо, попали вам в рот и на тело тоже немного прилетело...";
        str[20] = "Как только парни отошли от вас, вы моментально отрубились не одеваясь и не меняя позы...";
    }
    if(id > 20 && id < 41)
    {
        str[21] = "<npc>- Я же говорил тебе Игорь, что она шлюха, а ты мне не верил,</npc> - услышали напоследок голос Андрея.";
        str[22] = "<npc>- Ну теперь знаю... а я то думал у нас все серьезно будет,</npc> - и ответ Игоря. Вы поняли, он вас бросил.";
        str[23] = "<npc>- Ну теперь знаю... а я то вирил ей,</npc> - и ответ Игоря. Вы поняли, это развод.";
        str[24] = "<npc>- Я же говорил тебе Сергей, что она шлюха, а ты мне не верил,</npc> - услышали напоследок голос Андрея.";
        str[25] = "<npc>- Да уж, ты был прав,</npc> - и ответ Сергея. Вы поняли, он вас бросил.";
        str[26] = "<npc>- Да уж, думал ты другая,</npc> - услышали напоследок голос Андрея. Плюнув напоследок вам между ног, он вышел. Вы поняли, он вас бросил.";
        str[27] = "Вы проспали некоторое время, проснувшись растрепанная еле оторвали голову от подушки. Голова болела и вы смутно помнили, что вчера происходило.";
        str[28] = "Вы устало присели на край стола, чтобы отдохнуть и перекурить. К вам с улыбкой подошел уже голый Игорь."
                  "<npc>- Светик, это было круто,</npc> - сказал он улыбаясь. <npc> - Продолжим?</npc>"
                  "<hero>- Конечно,</hero> - пьяно улыбаясь ответили вы.";
        str[29] = "Вы подошли к парням с игривой улыбкой..."
                  "<npc>- Ты знаешь, что делать Светик,</npc> - сказал Андрей улыбаясь. <npc>- Приступай.</npc>";
        str[30] = "Дойдя до топчана, парень тут же принялся вас раздевать."
                  "<npc>- Ты знаешь, что делать Светик,</npc> - сказал " + root->getBoyName() + " улыбаясь. <npc>- Приступай.</npc>";
        str[31] = "Войдя поглубже в заросли парни подошли к вам вплотную и начали обнимать и целовать. Они надавили вам на плечи и вы принялись...";
        str[32] = "Войдя поглубже в заросли парни подошли к вам вплотную и начали раздевать. Они надавили вам на плечи и вы принялись...";
        str[33] = "Вы стоите на коленях перед парнями, и сосете их члены, поочередно уделяю внимание каждому...";
        str[34] = "Митька";
        str[35] = "Васян";
        str[36] = "Колямба";
        str[37] = "Парни смотрят вам в лицо пока ваши губы скользят по их напряженным членам. Прервав вас, они говорят...";
        str[38] = "Он кончил и отошел в сторону с довольной улыбкой на лице, а вы остались продолжать со вторым парнем...";
        str[39] = "Вы стоите на ногах перед парнями, согнувшись раком, и сосете их член одного, пока второй пристраивается сзади...";
        str[40] = "Вдоволь насладившись в этой позе, парни говорят...";
    }
    if(id > 40 && id < 61)
    {
        str[41] = "Вы стоите на ногах перед парнями, согнувшись раком, и сосете их член одного, пока второй пристраивается сзади...";
        str[42] = "Вы лежите на боку, член одного парня перед вашим лицом, а второй в это время пристраивается сзади...";
        str[43] = "Один из парней лег на землю, пристраивая вас сверху, второй стал рядом, поднеся свой член к вашему лицу...";
        str[44] = "Вы лежите на боку, " + root->getBoyName() + " за вашей спиной пристраивается сзади...";
        str[45] = "Вдоволь насладившись в этой позе, парень говорит...";
        str[46] = "Он кончил и ушел с довольной улыбкой на лице, а вы остались приводить себя в порядок...";
        str[47] = root->getBoyName() + " лег на землю, приглашая вам пристроиться сверху...";
        str[48] = "Вы стоите на коленях перед парнем, его член прямо перед вашим лицом...";
        str[49] = "Он смотрит вам в лицо пока ваши губы скользят по его напряженному члену. Прервав вас, парень говорит...";
        str[50] = "Вы, стоите на коленях перед парнями с открытым ртом. Они яростно надрачивают свой члены перед вашим лицом..."
                  "Вскоре струи спермы ударяют вам в рот, одна, вторая, третья. Спермы оказалось слишком много. Она стекает по "
                  "подбородку, капая вниз. Парни убрали члены в штаны и пошели по своим делам, оставив вас одну приводить себя в порядок.";
        str[51] = "Вы опустились на корточки и принялись стягивать с парня штаны. Когда дело было сделано, парень глянув на вас, сказал...";
        str[52] = "Вы, стоя раком перед парнем, подносите член к свом губам...";
        str[53] = root->getBoyName() + " навалился на вас всем телом, заставив запрокинуть голову назад, и стал с силой вгонять свой член, проникая в самое горло.";
        str[54] = "Вас тут же скручивает рвотный рефлекс и из глаз тект слезы.";
        str[55] = "К счастью горло у вас тренированное и вы заглатываете член парня до основания без каких либо трудностей.";
        str[56] = root->getBoyName() + " начал двигаться быстрее и вы поняли что он уже на грани и готов кончить";
        str[57] = "Вы, стоите на коленях перед парнем с открытым ртом. " + root->getBoyName() + " яростно надрачивает свой " + intQStr(root->vSex(dick)) + " член перед вашим лицом..."
                  "Вскоре струя спермы ударяет вам в рот, за ней вторая и третья. Спермы оказалось слишком много. Она стекает по подбородку,"
                  " капая вниз и пачкая вашу грудь и живот. " + root->getBoyName() + " убрал член в штаны и пошел по своим делам, оставив вас одну, приводить себя в порядок.";
        str[58] = "<npc>- Светик, снимай давай трусики,</npc> - сказал " + root->getBoyName() + " прервавшись. <npc>- Приступим к самому интересному.</npc>"
                  "Вы быстренько сели на топчан и стянули с себя последнюю деталь одежды. Увидев это парень сказал.";
        str[59] = root->getBoyName() + " ставит вас раком на топчане и начинает пристраиваться сзади...";
        str[60] = "Вы стоите раком на топчане, " + root->getBoyName() + " пристраиваться сзади...";
    }
    if(id > 60 && id < 81)
    {
        str[61] = "Вы стоите раком на топчане, согнув своими руками ноги в коленях, чтобы " + root->getBoyName() + " мог войти в вшу попу поглубже...";
        str[62] = root->getBoyName() + " ложится на спину, вы забираетесь на него верхом...";
        str[63] = root->getBoyName() + " ложится на спину, вы забираетесь на него верхом, подогнув ноги под себя...";
        str[64] = root->getBoyName() + " ложит вас на бок, а сам пристраивается сзади...";
        str[65] = "Вы лежите на боку, высоко задрав ногу вверх, " + root->getBoyName() + " пристроился сзади...";
        str[66] = "Вы приблизили губы к члену Игоря..";
        str[67] = "Стараясь доставить больше удовольствия, вы стараетесь заглатывать как можно глубже и Игорю похоже это нравится...";
        str[68] = "Андрей кончил и отошел в сторону.";
        str[69] = "Сергей с Игорем кончили и отошли отдыхать.";
        str[70] = "Сергей кончил и присел рядом, просто понаблюдать";
        str[71] = "Сергей кончил и отошел.";
        str[72] = "Андрей кончил и вышел на перекур";
        str[73] = "Сергей с Игорем кончили и отошли в сторону.";
        str[74] = "Вас поставили на четвереньки. Игорь начал пристраиваться сзади, а Сергей и Андрей стали перед вами выставив свои члены перед вашим лицом...";
        str[75] = "Андрей с Сергей кончили одновременно и сели за стол отдыхать";
        str[76] = "Андрей кончил и вырубился, а вы продолжили с Сергеем и Игорем";
        str[77] = "Игорь кончил и отвалил на боковую.";
        str[78] = "Парни кончили и сразу уснули.";
        str[79] = "Игорь кончил и ушел на перекур.";
        str[80] = "Андрей лёг на топчан, потянув вас за собой, Игорь сразу же начал пристраиваться к вашей второй дырочке, вам остается лишь расслабиться и сосать член Сергея...";
    }
    if(id > 80 && id < 101)
    {
        str[81] = "Через некоторое время " + root->getBoyName() + " застонал и вы почувствовали как вашу попу наполняет тепло. Он кончил и ушел на улицу.";
        str[82] = "Парни положили вас на спину, Игорь задрав вам ноги, принялся пристраиваться к вашей попе, а Андрей и Сергей стали над вами выставив свои члены перед вашим лицом...";
        str[83] = "Андрей с Сергеем кончили и пошли за стол.";
        str[84] = "Парни положили вас на спину, а сами нависли над вами. Они принялись дрочить перед вашим лицом, иногда вставляя члены вам в рот, и вы поняли что они скоро кончат...";
        str[85] = "Игорь кончил и пошел за стол.";
        str[86] = "Парни положили вас на топчан, Андрей начал пристраиваться между ног, а Игорь стал над вами выставив свой член перед вашим лицом. Кончивший ранее Сергей просто с интересом наблюдает...";
        str[87] = "Парни кончили и пошли все вместе за стол.";
        str[88] = "Вас поставили на четвереньки. Игорь начал пристраиваться сзади, а Андрей стал перед вами выставив свои член перед вашим лицом. Сергей с интересом наблюдает...";
        str[89] = "Андрей кончил и отошел в сторону, а вы продолжили с Игорем.";
        str[90] = "Сергей сел на топчан, потянув вас за собой, а Игорь стал перед вами выставив член перед вашим лицом...";
        str[91] = "Игорь кончил и вырубился, а вы продолжили с Сергеем.";
        str[92] = "Андрей положил вас на бок и начал пристраиваться между ног, а Сергей стал перед вами выставив член перед вашим лицом...";
        str[93] = "Сергей кончил и отошел в сторону, вы продолжили с Андреем.";
        str[94] = "Парни положили вас на спину, Игорь задрав вам ноги, принялся пристраиваться к вашей попе, а Сергей стал над вами выставив свой член перед вашим лицом...";
        str[95] = "Игорь кончил и отрубился, вы остались с Сергеем.";
        str[96] = "Сергей кончил и отошел, вы остались с Игорем.";
        str[97] = "Сергей сел на топчан, потянув вас за собой, а Игорь стал перед вами выставив свой член перед вашим лицом...";
        str[98] = "Сергей кончил и ушел за стол к Андрею, вы остались с Игорем.";
        str[99] = "Игорь кончил и ушел за стол к Андрею, вы остались с Сергеем.";
        str[100] = "Андрей лёг на топчан, потянув вас за собой, Сергей сразу же начал пристраиваться к вашей второй дырочке...";
    }
    if(id > 100)
    {
        str[101] = "Через некоторое время " + root->getBoyName() + " застонал и вы почувствовали как вашу попу наполняет тепло. Он кончил и ушел на улицу, вы остались с Андреем";
        str[102] = "Сергей с Игорем положили вас на спину и тут же струи спермы ударили в ваш рот и лицо.";
        str[103] = "Андрей сел на топчан, потянув вас за собой, вы уселись сверху на его член...";
        str[104] = "Андрей кончил и ушел к столу.";
        str[105] = "Игорь кончил и пошел спать.";
        str[106] = "Игорь положил вас на спину и принялся пристраиваться к вашей попе...";
        str[107] = "Андрей поставил вас на четвереньки и начал пристраиваться сзади...";
        str[108] = "Андрей кончил и ушел на улицу курить.";
        str[109] = "Сергей  сел на топчан, потянув вас за собой, вы уселись сверху на его член...";
        str[110] = "Сергей кончил и ушел.";
        str[111] = "Андрей положил вас на спину и тут же накачал кончать. Струи спермы ударили в ваш рот, попав и на лицо и на волосы. Кончив Андрей ушел, оставив вас одну...";
        str[112] = "Вдруг от нестерпимой боли в глазах у вас потемнело, мир закружился и вы потеряли сознание...";
        str[113] = "Вы очнулись от потока воды, вылившегося на вас..."
                   "<npc>- Ну что, Света, живая?</npc> - спросил Андрей убедившись, что вы пришли в себя."
                   "Вы слабо качнули головой."
                   "<npc>- Ну и ладно,</npc> - сказал он и отошел в сторону.";
        str[114] = "Вы очнулись от легкого похлопывания по щекам..."
                   "<npc>- Ну что, Светик, ты как, живая?</npc> - спросил Андрей убедившись, что вы пришли в себя."
                   "Вы слабо качнули головой."
                   "<npc>- Напугала ты нас, признаться, пиздец,</npc> - сказал он и отошел в сторону. <npc>- Иди в избушку, отдохни.</npc>";
        }
    return str[id];
}

QString HanterSex::act(int id)
{
    QString act[18];
    act[0] = "Далее";
    act[1] = "Сосать";
    act[2] = "Сосать дальше";
    act[3] = "Лечь на спину";
    act[4] = "Лежать на спине";
    act[5] = "Лечь на бок";
    act[6] = "Стать на четвереньки";
    act[7] = "Сесть сверху";
    act[8] = "Ждать";
    act[9] = "Вырубиться";
    act[10] = "Проснуться";
    act[11] = "Сесть на корточки";
    act[12] = "Стать на колени";
    act[13] = "Стать раком";
    act[14] = "Потерять сознание";
    act[15] = "Снять трусики";
    act[16] = "Сосать у всех";
    act[17] = "Очнуться";
    return act[id];
}

QString HanterSex::media(int id)
{
    QString med[174];
    if(id < 21)
    {
        med[0] = "data/sex/dancesex/dance5.jpg";
        med[1] = "data/sex/dancesex/dance6.jpg";
        med[2] = "data/sex/dancesex/dancesexOasi1.1.jpg";
        med[3] = "data/sex/dancesex/dancesexOasi1.2.jpg";
        med[4] = "data/sex/dancesex/dancesexOasi1.3.jpg";
        med[5] = "data/sex/dancesex/dancesexOi1.jpg";
        med[6] = "data/sex/dancesex/dancesexOi2.0.jpg";
        med[7] = "data/sex/dancesex/dancesexOi2.1.jpg";
        med[8] = "data/sex/dancesex/dancesexOi2.2.jpg";
        med[9] = "data/sex/dancesex/dancesexOi2.3.jpg";
        med[10] = "data/sex/dancesex/dancesexOi2.4.jpg";
        med[11] = "data/sex/dancesex/dancesexOi2.jpg";
        med[12] = "data/sex/dancesex/dancesexOi3.jpg";
        med[13] = "data/sex/dancesex/dancesexOi4.jpg";
        med[14] = "data/sex/dancesex/dancesexOi5.jpg";
        med[15] = "data/sex/dancesex/dancesexOi6.jpg";
        med[16] = "data/sex/dancesex/dancesexOi.jpg";
        med[17] = "data/sex/dancesex/hantersgr1Aa.jpg";
        med[18] = "data/sex/dancesex/hantersgr1Ai.jpg";
        med[19] = "data/sex/dancesex/hantersgr1As.jpg";
        med[20] = "data/sex/dancesex/hantersgr1Va.jpg";
    }
    if(id > 20 && id < 41)
    {
        med[21] = "data/sex/dancesex/hantersgr2AiO.jpg";
        med[22] = "data/sex/dancesex/hantersgr2AiOs.jpg";
        med[23] = "data/sex/dancesex/hantersgr2AOi.jpg";
        med[24] = "data/sex/dancesex/hantersgr2AOs.jpg";
        med[25] = "data/sex/dancesex/hantersgr2AsO.jpg";
        med[26] = "data/sex/dancesex/hantersgr2DPVaA.jpg";
        med[27] = "data/sex/dancesex/hantersgr2DPVaAs1.1.jpg";
        med[28] = "data/sex/dancesex/hantersgr2DPVaAs1.2.jpg";
        med[29] = "data/sex/dancesex/hantersgr2DPVaAs1.3.jpg";
        med[30] = "data/sex/dancesex/hantersgr2VaOi.jpg";
        med[31] = "data/sex/dancesex/hantersgr2VaO.jpg";
        med[32] = "data/sex/dancesex/hantersgr2VaOs.jpg";
        med[33] = "data/sex/dancesex/hantersgr2ViOa1.1.jpg";
        med[34] = "data/sex/dancesex/hantersgr2ViOa1.2.jpg";
        med[35] = "data/sex/dancesex/hantersgr2ViO.jpg";
        med[36] = "data/sex/dancesex/hantersgr2VOi.jpg";
        med[37] = "data/sex/dancesex/hantersgr2VO.jpg";
        med[38] = "data/sex/dancesex/hantersgr2VsO.jpg";
        med[39] = "data/sex/dancesex/hantersgrAiO.jpg";
        med[40] = "data/sex/dancesex/hantersgrAiOsa.jpg";
    }
    if(id > 40 && id < 61)
    {
        med[41] = "data/sex/dancesex/hantersgrAOsa.jpg";
        med[42] = "data/sex/dancesex/hantersgrDPVaAiOs1.1.jpg";
        med[43] = "data/sex/dancesex/hantersgrDPVaAiOs1.2.jpg";
        med[44] = "data/sex/dancesex/hantersgrDPVaAOs.jpg";
        med[45] = "data/sex/dancesex/hantersgrO1cum.jpg";
        med[46] = "data/sex/dancesex/hantersgrO2cum1.1.jpg";
        med[47] = "data/sex/dancesex/hantersgrO2cum1.2.jpg";
        med[48] = "data/sex/dancesex/hantersgrO3.1.jpg";
        med[49] = "data/sex/dancesex/hantersgrO3.2.jpg";
        med[50] = "data/sex/dancesex/hantersgrO3.3.jpg";
        med[51] = "data/sex/dancesex/hantersgrO3.4.jpg";
        med[52] = "data/sex/dancesex/hantersgrO3cum1.1.jpg";
        med[53] = "data/sex/dancesex/hantersgrO3cum1.2.jpg";
        med[54] = "data/sex/dancesex/hantersgrO3cum1.3.jpg";
        med[55] = "data/sex/dancesex/hantersgrO3cum1.4.jpg";
        med[56] = "data/sex/dancesex/hantersgrO3cum1.5.jpg";
        med[57] = "data/sex/dancesex/hantersgrO3cum1.6.jpg";
        med[58] = "data/sex/dancesex/hantersgrV2aOsi1.1.jpg";
        med[59] = "data/sex/dancesex/hantersgrV2aOsi1.2.jpg";
        med[60] = "data/sex/dancesex/hantersgrV2aOsi1.3.jpg";
    }
    if(id > 60 && id < 81)
    {
        med[61] = "data/sex/dancesex/hantersgrV2aOs.jpg";
        med[62] = "data/sex/dancesex/hantersgrVaOi.jpg";
        med[63] = "data/sex/dancesex/hantersgrVaOis1.1.jpg";
        med[64] = "data/sex/dancesex/hantersgrVaOis1.2.jpg";
        med[65] = "data/sex/dancesex/hantersgrVaOis1.3.jpg";
        med[66] = "data/sex/dancesex/hantersgrVaO.jpg";
        med[67] = "data/sex/dancesex/hantersgrVaOsi1.1.jpg";
        med[68] = "data/sex/dancesex/hantersgrVaOsi1.2.jpg";
        med[69] = "data/sex/dancesex/hantersgrVaOs.jpg";
        med[70] = "data/sex/dancesex/hantersgrViOas1.1.jpg";
        med[71] = "data/sex/dancesex/hantersgrViOas1.2.jpg";
        med[72] = "data/sex/dancesex/hantersgrViOas1.3.jpg";
        med[73] = "data/sex/dancesex/hantersgrViOas1.4.jpg";
        med[74] = "data/sex/dancesex/hantersgrViO.jpg";
        med[75] = "data/sex/dancesex/hantersgrVOai.jpg";
        med[76] = "data/sex/dancesex/hantersgrVO.jpg";
        med[77] = "data/sex/dancesex/hantersgrVOsi.jpg";
        med[78] = "data/sex/dancesex/hantersgrVsOai1.1.jpg";
        med[79] = "data/sex/dancesex/hantersgrVsOai1.2.jpg";
        med[80] = "data/sex/dancesex/hantersgrVsOai1.3.jpg";
    }
    if(id > 80 && id < 101)
    {
        med[81] = "data/sex/dancesex/hantersgrVsOai1.4.jpg";
        med[82] = "data/sex/dancesex/hantersgrVsOia1.1.jpg";
        med[83] = "data/sex/dancesex/hantersgrVsOia1.2.jpg";
        med[84] = "data/sex/dancesex/hantersgrVsOia1.3.jpg";
        med[85] = "data/sex/dancesex/hantersgrVsOi.jpg";
        med[86] = "data/sex/dancesex/hantersgrVsO.jpg";
        med[87] = "data/actions/swamphouse/dancesexson.jpg";
        med[88] = "data/actions/drunk_ev/pohmel1.jpg";
        med[89] = "data/locations/gadukino/swamp/hantersrelax1.4.jpg";
        med[90] = "data/sex/hantersex/sluthomesex1.jpg";
        med[91] = "data/sex/hantersex/doublelovesex.jpg";
        med[92] = "data/sex/hantersex/doubleloveOral12.1.jpg";
        med[93] = "data/sex/hantersex/doubleloveOral12.2.jpg";
        med[94] = "data/sex/hantersex/doubleloveOralCum12_1.jpg";
        med[95] = "data/sex/hantersex/doubleloveOralCum12_2.jpg";
        med[96] = "data/sex/hantersex/doubleloveDog112.1.jpg";
        med[97] = "data/sex/hantersex/doubleloveDog112.2.jpg";
        med[98] = "data/sex/hantersex/doubleloveDog112.3.jpg";
        med[99] = "data/sex/hantersex/doubleloveDogCum112_1.jpg";
        med[100] = "data/sex/hantersex/doubleloveDogCum112_2.jpg";
    }
    if(id > 100 && id < 121)
    {
        med[101] = "data/sex/hantersex/doubleloveDog212.1.jpg";
        med[102] = "data/sex/hantersex/doubleloveDog212.2.jpg";
        med[103] = "data/sex/hantersex/doubleloveDog212.3.jpg";
        med[104] = "data/sex/hantersex/doubleloveDogCum212_1.jpg";
        med[105] = "data/sex/hantersex/doubleloveDogCum212_2.jpg";
        med[106] = "data/sex/hantersex/doubleloveSide12.1.jpg";
        med[107] = "data/sex/hantersex/doubleloveSide12.2.jpg";
        med[108] = "data/sex/hantersex/doubleloveSideCum12_1.jpg";
        med[109] = "data/sex/hantersex/doubleloveSideCum12_2.jpg";
        med[110] = "data/sex/hantersex/doubleloveCow112.1.jpg";
        med[111] = "data/sex/hantersex/doubleloveCow112.2.jpg";
        med[112] = "data/sex/hantersex/doubleloveCowCum112_1.jpg";
        med[113] = "data/sex/hantersex/doubleloveCowCum112_2.jpg";
        med[114] = "data/sex/hantersex/doubleloveCow212.1.jpg";
        med[115] = "data/sex/hantersex/doubleloveCow212.2.jpg";
        med[116] = "data/sex/hantersex/doubleloveCowCum212_1.jpg";
        med[117] = "data/sex/hantersex/doubleloveCowCum212_2.jpg";
        med[118] = "data/sex/hantersex/doubleloveSide2.1.jpg";
        med[119] = "data/sex/hantersex/doubleloveSide2.2.jpg";
        med[120] = "data/sex/hantersex/doubleloveSideCum2.jpg";
    }
    if(id > 120 && id < 141)
    {
        med[121] = "data/sex/hantersex/doubleloveCow1.1.jpg";
        med[122] = "data/sex/hantersex/doubleloveCow1.2.jpg";
        med[123] = "data/sex/hantersex/doubleloveCowCum1.jpg";
        med[124] = "data/sex/hantersex/doubleloveOral1.1.jpg";
        med[125] = "data/sex/hantersex/doubleloveOral1.2.jpg";
        med[126] = "data/sex/hantersex/doubleloveOralCum1.jpg";
        med[127] = "data/sex/hantersex/doubleloveOral2.1.jpg";
        med[128] = "data/sex/hantersex/doubleloveOral2.2.jpg";
        med[129] = "data/sex/hantersex/doubleloveOralCum2.jpg";
        med[130] = "data/sex/hantersex/doubleloveOralCum12.1.jpg";
        med[131] = "data/sex/hantersex/doubleloveOralCum12.2.jpg";
        med[132] = "data/sex/hantersex/doubleloveOralCum12.3.jpg";
        med[133] = "data/sex/hantersex/sluthomeSTART.jpg";
        med[134] = "data/sex/hantersex/sluthomeORAL1.1.jpg";
        med[135] = "data/sex/hantersex/sluthomeORAL1.2.jpg";
        med[136] = "data/sex/hantersex/sluthomeORAL1.3.jpg";
        med[137] = "data/sex/hantersex/sluthomeOralCum1.jpg";
        med[138] = "data/sex/hantersex/sluthomeOralCum2.jpg";
        med[139] = "data/sex/hantersex/sluthomeOralCum3.jpg";
        med[140] = "data/sex/hantersex/sluthomeOralCum4.1.jpg";
    }
    if(id > 140 && id < 161)
    {
        med[141] = "data/sex/hantersex/sluthomeOralCum4.2.jpg";
        med[142] = "data/sex/hantersex/sluthomeOralCum4.3.jpg";
        med[143] = "data/sex/hantersex/sluthomeORAL2.1.jpg";
        med[144] = "data/sex/hantersex/sluthomeORAL2.2.jpg";
        med[145] = "data/sex/hantersex/sluthomeORAL2.3.jpg";
        med[146] = "data/sex/hantersex/sluthomeORAL3.1.jpg";
        med[147] = "data/sex/hantersex/sluthomeORAL3.2.jpg";
        med[148] = "data/sex/hantersex/sluthomeORAL4.1.jpg";
        med[149] = "data/sex/hantersex/sluthomeORAL4.2.jpg";
        med[150] = "data/sex/hantersex/sluthomeORAL4.3.jpg";
        med[151] = "data/sex/hantersex/sluthomeTanga.jpg";
        med[152] = "data/sex/hantersex/sluthomeAnalDog1.1.jpg";
        med[153] = "data/sex/hantersex/sluthomeAnalDog1.2.jpg";
        med[154] = "data/sex/hantersex/sluthomeAnalDogСum1.jpg";
        med[155] = "data/sex/hantersex/sluthomeAnalDogСum2.jpg";
        med[156] = "data/sex/hantersex/sluthomeAnalDog2.1.jpg";
        med[157] = "data/sex/hantersex/sluthomeAnalDog2.2.jpg";
        med[158] = "data/sex/hantersex/sluthomeAnalCow1.1.jpg";
        med[159] = "data/sex/hantersex/sluthomeAnalCow1.2.jpg";
        med[160] = "data/sex/hantersex/sluthomeAnalCow1.3.jpg";
    }
    if(id > 160)
    {
        med[161] = "data/sex/hantersex/sluthomeAnalCowСum1.jpg";
        med[162] = "data/sex/hantersex/sluthomeAnalCowСum2.jpg";
        med[163] = "data/sex/hantersex/sluthomeAnalCow2.1.jpg";
        med[164] = "data/sex/hantersex/sluthomeAnalCow2.2.jpg";
        med[165] = "data/sex/hantersex/sluthomeAnalSide1.1.jpg";
        med[166] = "data/sex/hantersex/sluthomeAnalSide1.2.jpg";
        med[167] = "data/sex/hantersex/sluthomeAnalSideСum1.jpg";
        med[168] = "data/sex/hantersex/sluthomeAnalSideСum2.jpg";
        med[169] = "data/sex/hantersex/sluthomeAnalSide2.1.jpg";
        med[170] = "data/sex/hantersex/sluthomeAnalSide2.2.jpg";
        med[171] = "data/sex/hantersex/hantersgroupfaint.jpg";
        med[172] = "data/sex/hantersex/hantersgroupfaint1.jpg";
        med[173] = "data/sex/hantersex/hantersgroupfaint2.jpg";
    }
    return med[id];
}

void HanterSex::actions1()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgrOasi",act(2)); //Сосать дальше

        if(hantsexa == 2) //Лечь на спину
        {
            if(hantsexb > 5) makeActBtn("hantersgrVaOsi",act(3));
            if(hantsexb < 4) makeActBtn("hantersgrVOsi",act(3));
            if(hantsexb == 4) makeActBtn("hantersgrVaO",act(3));
            if(hantsexb == 5) makeActBtn("hantersgrVaOi",act(3));
        }
        if(hantsexa == 3) // Лечь на спину
        {
            if(hantsexb > 5) makeActBtn("hantersgrVsOai",act(3));
            if(hantsexb == 5) makeActBtn("hantersgrVsO",act(3));
            if(hantsexb < 4) makeActBtn("hantersgrVOai",act(3));
            if(hantsexb == 4) makeActBtn("hantersgrVsOi",act(3));
        }
        if(hantsexa == 4) //Стать на четвереньки
        {
            if(hantsexb <= 5) makeActBtn("hantersgrViOas",act(6));
            if(hantsexb > 5) makeActBtn("hantersgrViO",act(6));
        }
        if(hantsexa == 5) //Сесть сверху
        {
            if(hantsexb == 5) makeActBtn("hantersgrVsOia",act(7));
            if(hantsexb > 5) makeActBtn("hantersgrVsOi1",act(7));
            if(hantsexb < 5) makeActBtn("hantersgrVaOis",act(7));
        }
        if(hantsexa == 6) //Сесть сверху
        {
            if(hantsexb <= 5) makeActBtn("hantersgrVO",act(7));
            if(hantsexb > 5) makeActBtn("hantersgrVaOs",act(7));
        }
        if(hantsexa == 7) //Лечь на бок
        {
            if(hantsexb <= 5) makeActBtn("hantersgrV2aOsi",act(5));
            if(hantsexb > 5) makeActBtn("hantersgrV2aOs",act(5));
        }
        if(hantsexa == 8) //Сесть сверху
        {
            if(hantsexb <= 4) makeActBtn("hantersgrDPVaAiOs",act(7));
            if(hantsexb > 4) makeActBtn("hantersgrDPVaAOs",act(7));
        }
        if(hantsexa == 9) //Лечь на спину
        {
            if(hantsexb > 5) makeActBtn("hantersgrAiOsa",act(3));
            if(hantsexb == 5) makeActBtn("hantersgrAiO",act(3));
            if(hantsexb < 5) makeActBtn("hantersgrAOsa",act(3));
        }
        if(hantsexa == 10) makeActBtn("hantersgrO3",act(3)); //Лечь на спину
    }
    else
        makeActBtn("hantersexfaint",act(14));
}

void HanterSex::actions2()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1) makeActBtn("hantersgr2VsO",act(7));
        if(hantsexa == 2)
        {
            if(hantsexb > 5) makeActBtn("hantersgr2AiOs",act(3));
            if(hantsexb == 5) makeActBtn("hantersgr2AiO",act(3));
            if(hantsexb < 5) makeActBtn("hantersgr2AOs",act(3));
        }
        if(hantsexa == 3)
        {
            if(hantsexb <= 5) makeActBtn("hantersgr2AOi",act(7));
            if(hantsexb > 5) makeActBtn("hantersgr2AsO",act(7));
        }
    }
    else
        makeActBtn("hantersexfaint",act(14));
}

void HanterSex::actions3()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1)
        {
            if(hantsexb > 5) makeActBtn("hantersgr2VaOi",act(3));
            if(hantsexb == 5) makeActBtn("hantersgr2VO",act(3));
            if(hantsexb < 5) makeActBtn("hantersgr2VOi",act(3));
        }
        if(hantsexa == 2)
        {
            if(hantsexb <= 4) makeActBtn("hantersgr2ViOa",act(6));
            if(hantsexb > 4) makeActBtn("hantersgr2ViO",act(6));
        }
        if(hantsexa == 3) makeActBtn("hantersgrO2",act(3));
    }
    else
        makeActBtn("hantersexfaint",act(14));
}

void HanterSex::actions4()
{
    if(root->vStatus(health) > 50)
    {
        if(hantsexa == 1)
        {
            if(hantsexb > 4) makeActBtn("hantersgr2VaOs",act(5));
            if(hantsexb <= 4) makeActBtn("hantersgr2VaO",act(5));
        }
        if(hantsexa == 2)
        {
            if(hantsexb > 5) makeActBtn("hantersgr2DPVaAs",act(7));
            if(hantsexb <= 5) makeActBtn("hantersgr2DPVaA",act(7));
        }
    }
    else makeActBtn("hantersexfaint",act(14));
}

void HanterSex::actions5()
{
    if(root->vStatus(health) > 50) makeActBtn("hantersgr1Ai",act(3));
    else makeActBtn("hantersexfaint",act(14));
}

void HanterSex::resetCounters()
{
    boyAsex = 0;
    boyBsex = 0;
    boyCsex = 0;
    boyAsexA = 0;
    boyBsexA = 0;
    boyCsexA = 0;
}

void HanterSex::checkHantSex()
{
    if(root->gVEvent(hantersAndreisex) == 0)
    {
        root->sVEvent(hantersAndreisex,1);
        root->uVSex(guy,1);
    }
    if(root->gVEvent(hantersSergeisex) == 0)
    {
        root->sVEvent(hantersSergeisex,1);
        root->uVSex(guy,1);
    }
    if(root->gVEvent(hantersIgorsex) == 0)
    {
        root->sVEvent(hantersIgorsex,1);
        root->uVSex(guy,1);
    }
}

void HanterSex::checkBoyAsex()
{
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void HanterSex::checkBoyAsexA()
{
    if(boyAsexA == 0)
    {
        boyAsexA = 1;
        root->uVSC(analSex,1);
    }
}

void HanterSex::checkBoyBsex()
{
    if(boyBsex == 0)
    {
        boyBsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void HanterSex::checkBoyBsexA()
{
    if(boyBsexA == 0)
    {
        boyBsexA = 1;
        root->uVSC(analSex,1);
    }
}

void HanterSex::checkBoyCsex()
{
    if(boyCsex == 0)
    {
        boyCsex = 1;
        root->uVSC(vaginalSex,1);
    }
}

void HanterSex::checkBoyCsexA()
{
    if(boyCsexA == 0)
    {
        boyCsexA = 1;
        root->uVSC(analSex,1);
    }
}

void HanterSex::setAIMV()
{
    int partner = root->gVEvent(temphant);
    if(partner <= 2) setAndrei();
    if(partner == 3) setIgor();
    if(partner == 4 || partner == 5) setMitka();
    if(partner == 6) setVasyan();
}

void HanterSex::setSIKV()
{
    int partner = root->gVEvent(temphant);
    if(partner == 1 || partner == 3) setSergei();
    if(partner == 2) setIgor();
    if(partner == 4 || partner == 6) setKolyamba();
    if(partner == 5) setVasyan();
}

void HanterSex::setIgor()
{
    root->setBoyName(str(2));
    root->sVSex(silavag,2);
    root->sVSex(dick,16);
}

void HanterSex::setIgor2()
{
    root->setBoy2Name(str(2));
    root->sVSex(silavag,2);
    root->sVSex(dick2,16);
}

void HanterSex::setSergei()
{
    root->setBoyName(str(3));
    root->sVSex(silavag,1);
    root->sVSex(dick,18);
}

void HanterSex::setSergei2()
{
    root->setBoy2Name(str(3));
    root->sVSex(silavag,1);
    root->sVSex(dick2,18);
}

void HanterSex::setAndrei()
{
    root->setBoyName(str(4));
    root->sVSex(silavag,0);
    root->sVSex(dick,20);
}

void HanterSex::setMitka()
{
    root->setBoyName(str(34));
    root->sVSex(silavag,0);
    root->sVSex(dick,16);
}

void HanterSex::setVasyan()
{
    root->setBoyName(str(35));
    root->sVSex(silavag,0);
    root->sVSex(dick,14);
}

void HanterSex::setKolyamba()
{
    root->setBoyName(str(36));
    root->sVSex(silavag,0);
    root->sVSex(dick,15);
}
