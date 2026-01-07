#include "mitkasex.h"
#include "../eventhandler.h"
#include "../../Functions.h"
#include "../../menu/qactbutton.h"

MitkaSex::MitkaSex(EventHandler *ptr):
    root(ptr),
    boy{"Митька", "Васян", "Колямба"},
    boyDick{16,14,15},
    boySilavag{0,0,0},
    textsexhanter
    {
        "Он смотрит вам в лицо пока ваши губы скользят по его напряженному члену. Прервав вас, парень говорит...",
        "Он кончил и ушел с довольной улыбкой на лице, а вы остались приводить себя в порядок...",
        "Вдоволь насладившись в этой позе, парень говорит...",
        "Парни смотрят вам в лицо пока ваши губы скользят по их напряженным членам. Прервав вас, они говорят...",
        "Он кончил и отошел в сторону с довольной улыбкой на лице, а вы остались продолжать со вторым парнем...",
        "Вдоволь насладившись в этой позе, парни говорят...",
        "Он смотрит вам в лицо пока ваши губы скользят по его напряженному члену...",
        "Парни смотрят вам в лицо пока ваши губы скользят по их напряженным членам...",
        "Он кончил и отошел в сторону с довольной улыбкой на лице, а вы остались с Мирой приводить себя в порядок...",
        "Постепенно приятное тепло и пульсация нарастают внизу живота, потом ощущения обрушиваются на вас и все ваше тело охватывают горячие волны оргазма.",
        "Вам становится приятно когда член движется внутри вашей попки и вы стонете от удовольствия. Постепенно приятное тепло и пульсация нарастают внизу живота, потом ощущения обрушиваются на вас и все ваше тело охватывают горячие волны оргазма."}{}

void MitkaSex::start(QString arg)
{    
    if(root->gVEvent(mitkaforestsex) == 3)
    {
        root->sVEvent(mitkaforestsex,0);
        root->incTime(5);
        root->uVSkill(domination,-1);
        root->uVSC(gangBang,1);
        boyAsex = 0;
        boyBsex = 0;
        boyCsex = 0;
        boyAsexa = 0;
        boyBsexa = 0;
        boyCsexa = 0;
        mitboysex = 0;
        mitboysexrand = getRandInt(1,5);
        hantsexa = getRandInt(1,3);
        if(root->getCurLoc() == lgadukino)
            root->eventStart("gadukino_event", "onlooker");
        root->setImage(media(2));
        root->setDesc(str(0));
        if(hantsexa == 1)
            makeActBtn("forestSexOral3_1",act(0));
        if(hantsexa == 2)
            makeActBtn("forestSexOral3_2",act(0));
        if(hantsexa == 3)
            makeActBtn("forestSexOral3_3",act(0));
    }
    if(root->gVEvent(mitkaforestsex) == 2)
    {
        root->sVEvent(mitkaforestsex,0);
        boyAsex = 0;
        boyBsex = 0;
        boyAsexa = 0;
        boyBsexa = 0;
        root->incTime(5);
        root->uVSkill(domination,-1);
        root->uVSC(gangBang,1);
        root->sVSex(lubonus,0);
        int tmp = getRandInt(1,2);
        if(root->gVEvent(mitboyrand) == 1)
        {
            if(tmp == 1)
                setMitka();
            if(tmp == 2)
                setKolyamba();
        }
        else if(root->gVEvent(mitboyrand) == 2)
        {
            if(tmp == 1)
                setMitka();
            if(tmp == 2)
                setVasyan();
        }
        else if(root->gVEvent(mitboyrand) == 3)
        {
            if(tmp == 1)
                setKolyamba();
            if(tmp == 2)
                setVasyan();
        }
        boyAhorny = getRandInt(0,90);
        boyBhorny = getRandInt(0,90);
        if(root->getCurLoc() == lgadukino)
            root->eventStart("gadukino_event","onlooker");
        root->setImage(media(1));
        root->setDesc(str(0));
        makeActBtn("forestSexOral2_1",act(0));
    }
    if(root->gVEvent(mitkaforestsex) == 1)
    {
        root->sVEvent(mitkaforestsex,0);
        root->incTime(5);
        boyAsex = 0;
        boyAsexa = 0;
        root->uVSkill(domination,-1);
        root->uVSC(blowJob,1);
        root->sVSex(lubonus,0);
        if(root->gVEvent(mitboyrand) == 1)
            setMitka();
        if(root->gVEvent(mitboyrand) == 2)
            setKolyamba();
        if(root->gVEvent(mitboyrand) == 3)
            setVasyan();
        boyAhorny = getRandInt(0,90);
        if(root->getCurLoc() == lgadukino)
            root->eventStart("gadukino_event","onlooker");
        root->setImage(media(0));
        root->setDesc(str(89));
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexOral1_1",act(0));
        if(hantsexa == 2)
            makeActBtn("forestSexOral1_2",act(0));
        if(hantsexa == 3)
            makeActBtn("forestSexOral1_3",act(0));
    }
    if(root->gVEvent(mitkagadsex) == 1)
    {
        root->sVEvent(mitkagadsex,0);
        root->incTime(5);
        boyAsex = 0;
        boyAsexa = 0;
        root->uVSkill(domination,-1);
        root->uVSC(blowJob,1);
        root->sVSex(lubonus,0);

        if(root->gVEvent(mitboyrand) == 1)
            setMitka();
        if(root->gVEvent(mitboyrand) == 2)
            setKolyamba();
        if(root->gVEvent(mitboyrand) == 3)
            setVasyan();
        boyAhorny = getRandInt(0,90);
        if (root->getCurLoc() == lgadukino)
            root->eventStart("gadukino_event", "onlooker");
        if(root->vStatus(horny) < 60)
            root->setImage(media(3));
        if(root->vStatus(horny) >= 60)
            root->setImage(media(4));
        root->setDesc(str(90));
        makeActBtn("gadSexOral1",act(0));        
    }
    if(root->gVEvent(mitkagadsex) == 2)
    {
        root->sVEvent(mitkagadsex,0);
        boyAsex = 0;
      	boyBsex = 0;
        boyAsexa = 0;
	    boyBsexa = 0;
        root->incTime(5);
        root->uVSkill(domination,-1);
        root->uVSC(blowJob,2);
        root->uVSC(gangBang,1);
        root->sVSex(lubonus,0);
        int tmp = getRandInt(1,2);
        if(root->gVEvent(mitboyrand) == 1)
        {
            if(tmp == 1)
                setMitka();
            if(tmp == 2)
                setKolyamba();            
        }
        if(root->gVEvent(mitboyrand) == 2)
        {
            if(tmp == 1)
                setMitka();
            if(tmp == 2)
                setVasyan();            
        }
        if(root->gVEvent(mitboyrand) == 3)
        {
            if(tmp == 1)
                setKolyamba();
            if(tmp == 2)
                setVasyan();            
        }

        boyBhorny = getRandInt(0,90);
        boyAhorny = getRandInt(0,90);

        if(root->getCurLoc() == lgadukino)
            root->eventStart("gadukino_event", "onlooker");
        if(root->vStatus(horny) < 60)
            root->setImage(media(5));
        if(root->vStatus(horny) >= 60)
            root->setImage(media(6));
        root->setDesc(str(91));
        makeActBtn("gadSexOral2",act(0));
    }
}

void MitkaSex::gadSexOral1()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,6);
    root->uVSex(lubonus,1);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    root->setImage(media(7));
    root->setDesc(str(58));
    root->blow_job();
    root->addDesc(textsexhanter[2]);
    if (boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexMisVag1",act(1));
        if(hantsexa == 3)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 5)
            makeActBtn("gadSexDogVag1",act(2));
        if(hantsexa == 6)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexOralCum1",act(4));
    
}

void MitkaSex::gadSexOral2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    hantsexa = getRandInt(1,3);
    if(root->vBody(throat) <= 15)
    {
        boyAhorny += 5;
        boyBhorny += 5;
    }
    if(root->vBody(throat) > 15)
    {
        boyAhorny += 10;
        boyBhorny += 10;
    }
    root->setImage(media(8));
    root->setDesc(str(92));
    if(root->gVEvent(mitboyrand) == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
    }
    if(root->gVEvent(mitboyrand) == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
        root->blow_job();
    }
    if(root->gVEvent(mitboyrand) == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    root->addDesc(textsexhanter[5]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexStan2",act(14));
        if(hantsexa == 2)
            makeActBtn("gadSexCow2",act(10));
        if(hantsexa == 3)
            makeActBtn("gadSexDog2",act(2));
    }
    else if (boyAhorny < 100 && boyBhorny >= 100)
        makeActBtn("gadSexOralCum2_2",act(4));
    else if (boyAhorny >= 100 && boyBhorny < 100)
        makeActBtn("gadSexOralCum2_1",act(4));
    else if (boyAhorny >= 100 && boyBhorny >= 100)
        makeActBtn("gadSexHandsCum2",act(15));
}

void MitkaSex::gadSexOralCum1()
{
    root->incTime(5);
    root->sVSex(protect,0);
    root->setImage(media(9));
    root->setDesc(str(93));
    root->fnswallow();
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexOralCum2_1()
{
    root->incTime(5);
    root->sVSex(protect,0);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    root->setImage(media(10));
    root->setDesc(str(99));
    root->fnswallow();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexOralCum2_2()
{
    root->incTime(5);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    root->setImage(media(11));
    root->setDesc(str(99));
    root->fnswallow();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexSideVag1()
{
    root->incTime(5);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;

    if(root->vStatus(horny) < 60)
        root->setImage(media(12));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(13));
    root->setDesc(str(46));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexMisVag1",act(1));
        if(hantsexa == 2)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 3)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexDogVag1",act(2));
        if(hantsexa == 5)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexSideVagCum1",act(13));
}

void MitkaSex::gadSexSideVagCum1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,1);
    root->setImage(media(35));
    root->setDesc(str(94));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexMisVag1()
{
    root->incTime(5);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,0);
    if(root->vStatus(horny) < 60)
        root->setImage(media(36));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(37));
    root->setDesc(str(95));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 3)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexDogVag1",act(2));
        if(hantsexa == 5)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexHandsCum1",act(16));
}

void MitkaSex::gadSexDogVag1()
{
    root->incTime(5);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(38));
    root->setDesc(str(67));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexMisVag1",act(1));
        if(hantsexa == 3)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 5)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexOral1",act(0));
}

void MitkaSex::gadSexDogAnal1()
{
    root->incTime(5);
    if(boyAsexa == 0)
    {
        boyAsexa = 1;
        root->uVSC(analSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(anus) <= 25)
        boyAhorny += 30;
    if(root->vBody(anus) > 25)
        boyAhorny += 20;
    if(root->vStatus(horny) < 60)
        root->setImage(media(39));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(40));
    root->setDesc(str(96));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(textsexhanter[2]);
    if (boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexMisVag1",act(1));
        if(hantsexa == 3)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 5)
            makeActBtn("gadSexDogVag1",act(2));
    }
    else
        makeActBtn("gadSexDogAnalCum1",act(11));
}

void MitkaSex::gadSexDog2()
{
    root->incTime(5);
    if(boyBsex == 0)
    {
        boyBsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,2);
    if(root->vBody(throat) <= 25)
        boyAhorny += 5;
    if(root->vBody(throat) > 25)
        boyAhorny += 10;
    if(root->vBody(vagina) <= 25)
        boyBhorny += 20;
    if(root->vBody(vagina) > 25)
        boyBhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(41));
    root->setDesc(str(103));
    if(root->gVEvent(mitboyrand) == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
    }
    else if(root->gVEvent(mitboyrand) == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
    }
    else if(root->gVEvent(mitboyrand) == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
    }
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[5]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexStan2",act(14));
        if(hantsexa == 2)
            makeActBtn("gadSexCow2",act(10));
    }
    else if(boyAhorny < 100 && boyBhorny >= 100)
        makeActBtn("gadSexDogCum2_2",act(11));
    else if(boyAhorny >= 100 && boyBhorny < 100)
        makeActBtn("gadSexDogCum2_1",act(11));
    else if(boyAhorny >= 100 && boyBhorny >= 100)
        makeActBtn("gadHandsCum2",act(15));
}

void MitkaSex::gadSexDogAnalCum1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,1);
    root->cum("anus");
    root->sVSex(protect,0);
    root->setImage(media(42));
    root->setDesc(str(66));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[10]);
        root->uVSC(orgasm,1);
        root->uVSC(analOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->addDesc(str(97));
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexDogCum2_1()
{
    root->incTime(5);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    root->setImage(media(43));
    root->setDesc(str(99));
    root->fnswallow();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexDogCum2_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    if(root->vStatus(horny) < 60)
        root->setImage(media(44));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(45));
    root->setDesc(str(66));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[10]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexCowVag1()
{
    root->incTime(5);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,2);
    if(root->vStatus(horny) < 60)
        root->setImage(media(46));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(47));
    root->addDesc(str(77));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[2]);
    if (boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexMisVag1",act(1));
        if(hantsexa == 3)
            makeActBtn("gadSexCowAnal1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexDogVag1",act(2));
        if(hantsexa == 5)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexCowVagCum1",act(12));
}

void MitkaSex::gadSexCow2()
{
    root->incTime(5);
    if(boyBsex == 0)
    {
        boyBsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,2);
    if(root->vBody(throat) <= 25)
        boyAhorny += 5;
    if(root->vBody(throat) > 25)
        boyAhorny += 10;
    if(root->vBody(vagina) <= 25)
        boyBhorny += 20;
    if(root->vBody(vagina) > 25)
        boyBhorny += 10;
    root->sVSex(pose,2);
    root->setImage(media(48));
    root->addDesc(str(104));
    if(root->gVEvent(mitboyrand) == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
    }
    else if(root->gVEvent(mitboyrand) == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
    }
    else if(root->gVEvent(mitboyrand) == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
    }
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[5]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexStan2",act(14));
        if(hantsexa == 2)
            makeActBtn("gadSexDog2",act(2));
    }
    else if(boyAhorny < 100 && boyBhorny >= 100)
        makeActBtn("gadSexCowCum2_2",act(12));
    else if(boyAhorny >= 100 && boyBhorny < 100)
        makeActBtn("gadSexCowCum2_1",act(12));
    else if(boyAhorny >= 100 && boyBhorny >= 100)
        makeActBtn("gadSexHandsCum2",act(15));
}

void MitkaSex::gadSexCowVagCum1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,0);
    root->setImage(media(49));
    root->setDesc(str(76));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexCowCum2_1()
{
    root->incTime(5);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    root->setImage(media(50));
    root->addDesc(str(99));
    root->fnswallow();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexCowCum2_2()
{
    root->incTime(5);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    root->setImage(media(51));
    root->addDesc(str(76));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexCowAnal1()
{
    root->incTime(5);
    if(boyAsexa == 0)
    {
        boyAsexa = 1;
        root->uVSC(analSex,1);
    }
    hantsexa = getRandInt(1,5);
    if(root->vBody(anus) <= 25)
        boyAhorny += 30;
    if(root->vBody(anus) > 25)
        boyAhorny += 20;
    if(root->vStatus(horny) < 60)
        root->setImage(media(52));
    if(root->vStatus(horny) >= 60)
        root->setImage(media(53));
    root->setDesc(str(77));
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(textsexhanter[2]);
    if (boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexSideVag1",act(9));
        if(hantsexa == 2)
            makeActBtn("gadSexMisVag",act(1));
        if(hantsexa == 3)
            makeActBtn("gadSexCowVag1",act(10));
        if(hantsexa == 4)
            makeActBtn("gadSexDogVag1",act(2));
        if(hantsexa == 5)
            makeActBtn("gadSexDogAnal1",act(2));
    }
    else
        makeActBtn("gadSexHandsCum1",act(15));

}

void MitkaSex::gadSexHandsCum1()
{
    root->incTime(5);
    root->sVSex(protect,0);
    root->cum("belly");
    root->uVSC(handJob,1);
    root->setImage(media(54));
    root->setDesc(str(98));
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexHandsCum2()
{
    root->incTime(5);
    root->sVSex(protect,0);
    root->cum("belly");
    root->uVSC(handJob,1);
    root->setImage(media(55));
    root->setDesc(str(100));
    if(root->getItmCount(iCosmetic) <= 0 && root->getItmCount(iCosmeticBig) <= 0)
        root->addDesc(str(101));
    if(root->getItmCount(iCosmetic) > 0 || root->getItmCount(iCosmeticBig) > 0)
    {
        makeActBtn("bawd_body", act(7));
    }
    else
        makeActBtn("back_to_loc",act(7));
}

void MitkaSex::gadSexStan2()
{
    root->incTime(5);
    if(boyBsex == 0)
    {
        boyBsex = 1;
        root->uVSC(vaginalSex,1);
    }
    hantsexa = getRandInt(1,2);
    if(root->vBody(throat) <= 25)
        boyAhorny += 5;
    if(root->vBody(throat) > 25)
        boyAhorny += 10;
    if(root->vBody(vagina) <= 25)
        boyBhorny += 20;
    if(root->vBody(vagina) > 25)
        boyBhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(56));
    root->setDesc(str(105));
    if(root->gVEvent(mitboyrand) == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
    }
    else if(root->gVEvent(mitboyrand) == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
    }
    else if(root->gVEvent(mitboyrand) == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
    }
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(textsexhanter[5]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("gadSexCow2",act(10));
        if(hantsexa == 2)
            makeActBtn("gadSexDog2",act(2));
    }
    else if(boyAhorny < 100 && boyBhorny >= 100)
        makeActBtn("gadSexStanCum2_2",act(17));
    else if(boyAhorny >= 100 && boyBhorny < 100)
        makeActBtn("gadSexStanCum2_1",act(17));
    else if(boyAhorny >= 100 && boyBhorny >= 100)
        makeActBtn("gadHandsCum2",act(15));
}

void MitkaSex::gadSexStanCum2_1()
{
    root->incTime(5);
    if(root->gVEvent(mitboyrand) == 1)
        setMitka();
    else if(root->gVEvent(mitboyrand) == 2)
        setVasyan();
    else if(root->gVEvent(mitboyrand) == 3)
        setKolyamba();
    root->setImage(media(57));
    root->setDesc(str(99));
    root->fnswallow();
    root->addDesc(textsexhanter[4]);
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    else if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    else if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::gadSexStanCum2_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    if(root->gVEvent(mitboyrand) == 1)
        setKolyamba();
    else if(root->gVEvent(mitboyrand) == 2)
        setMitka();
    else if(root->gVEvent(mitboyrand) == 3)
        setVasyan();
    root->setImage(media(58));
    root->setDesc(str(106));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[4]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[4]);
    hantsexa = getRandInt(1,6);
    if(hantsexa == 1)
        makeActBtn("gadSexSideVag1",act(9));
    if(hantsexa == 2)
        makeActBtn("gadSexMisVag1",act(1));
    if(hantsexa == 3)
        makeActBtn("gadSexCowVag1",act(10));
    if(hantsexa == 4)
        makeActBtn("gadSexCowAnal1",act(10));
    if(hantsexa == 5)
        makeActBtn("gadSexDogVag1",act(2));
    if(hantsexa == 6)
        makeActBtn("gadSexDogAnal1",act(2));
}

void MitkaSex::actionHandler(QString action)
{
    if(action == "back_to_loc")
    {
        root->changeLoc(root->getCurLoc());
    }

    if(action == "bawd_body")
    {
        root->incTime(5);
        if(root->getItmCount(iCosmetic) > 0)
            root->useItem(iCosmetic,1);
        else
            root->useItem(iCosmeticBig,1);
        root->setImage(media(59));
        root->setDesc(str(102));
        makeActBtn("back_to_loc",act(7));
    }
//GADUKINO EVENTS
    if(action == "gadSexOral1")
        gadSexOral1();
    if(action == "gadSexOral2")
        gadSexOral2();
    if(action == "gadSexOralCum1")
        gadSexOralCum1();
    if(action == "gadSexOralCum2_1")
        gadSexOralCum2_1();
    if(action == "gadSexOralCum2_2")
        gadSexOralCum2_2();
    if(action == "gadSexSideVag1")
        gadSexSideVag1();
    if(action == "gadSexSideVagCum1")
        gadSexSideVagCum1();
    if(action == "gadSexMisVag1")
        gadSexMisVag1();
    if(action == "gadSexDogVag1")
        gadSexDogVag1();
    if(action == "gadSexDogAnal1")
        gadSexDogAnal1();
    if(action == "gadSexDog2")
        gadSexDog2();
    if(action == "gadSexDogAnalCum1")
        gadSexDogAnalCum1();
    if(action == "gadSexDogCum2_1")
        gadSexDogCum2_1();
    if(action == "gadSexDogCum2_2")
        gadSexDogCum2_2();
    if(action == "gadSexCowVag1")
        gadSexCowVag1();
    if(action == "gadSexCow2")
        gadSexCow2();
    if(action == "gadSexCowVagCum1")
        gadSexCowVagCum1();
    if(action == "gadSexCowCum2_1")
        gadSexCowCum2_1();
    if(action == "gadSexCowCum2_2")
        gadSexCowCum2_2();
    if(action == "gadSexCowAnal1")
        gadSexCowAnal1();
    if(action == "gadSexHandsCum1")
        gadSexHandsCum1();
    if(action == "gadSexHandsCum2")
        gadSexHandsCum2();
    if(action == "gadSexStan2")
        gadSexStan2();
    if(action == "gadSexStanCum2_1")
        gadSexStanCum2_1();
    if(action == "gadSexStanCum2_2")
        gadSexStanCum2_2();
//FOREST EVENTS

    if(action == "forestSexOral1_1")
        forestSexOral1_1();
    if(action == "forestSexOral1_2")
        forestSexOral1_2();
    if(action == "forestSexOral1_3")
        forestSexOral1_3();
    if(action == "forestSexOral2_1")
        forestSexOral2_1();
    if(action == "forestSexOral3_1")
        forestSexOral3_1();
    if(action == "forestSexOral3_2")
        forestSexOral3_2();
    if(action == "forestSexOral3_3")
        forestSexOral3_3();
    if(action == "forestSexOralCum1_1")
        forestSexOralCum1_1();
    if(action == "forestSexOralCum2_1")
        forestSexOralCum2_1();
    if(action == "forestCowKiss1_1")
        forestCowKiss1_1();
    if(action == "forestSexCowOral1_1")
        forestSexCowOral1_1();
    if(action == "forestSexCow1_1")
        forestSexCow1_1();
    if(action == "forestSexCow1_2")
        forestSexCow1_2();
    if(action == "forestSexCow2_1")
        forestSexCow2_1();
    if(action == "forestSexCowCum1_1")
        forestSexCowCum1_1();
    if(action == "forestSexCowCum1_2")
        forestSexCowCum1_2();
    if(action == "forestSexDog1_1")
        forestSexDog1_1();
    if(action == "forestSexDog1_2")
        forestSexDog1_2();
    if(action == "forestSexDog1_3")
        forestSexDog1_3();
    if(action == "forestSexDog2_1")
        forestSexDog2_1();
    if(action == "forestSexDog2_2")
        forestSexDog2_2();
    if(action == "forestSexDogCum1_1")
        forestSexDogCum1_1();
    if(action == "forestSexDogCum1_2")
        forestSexDogCum1_2();
    if(action == "forestSexDogCum1_3")
        forestSexDogCum1_3();
    if(action == "forestSexSide1_1")
        forestSexSide1_1();
    if(action == "forestSexSide1_2")
        forestSexSide1_2();
    if(action == "forestSexSide2_1")
        forestSexSide2_1();
    if(action == "forestSexSide2_2")
        forestSexSide2_2();
    if(action == "forestSexSide2_3")
        forestSexSide2_3();
    if(action == "forestSexSideCum1_1")
        forestSexSideCum1_1();
    if(action == "forestSexVag3")
        forestSexVag3();
    if(action == "forestSexAnal3_1")
        forestSexAnal3_1();
    if(action == "forestSexAnal3_2")
        forestSexAnal3_2();
    if(action == "forestSexAnal3_3")
        forestSexAnal3_3();
    if(action == "forestSexCum3_1")
        forestSexCum3_1();
    if(action == "forestSexCum3_2")
        forestSexCum3_2();
    if(action == "forestSexCum3_3")
        forestSexCum3_3();
    if(action == "forestSexRelax")
        forestSexRelax();
    if(action == "forestSexRelax2")
        forestSexRelax2();
    if(action == "forestSexRelaxMira")
        forestSexRelaxMira();
    if(action == "forestSexDPMira3")
        forestSexDPMira3();
    if(action == "forestSexCowMira2")
        forestSexCowMira2();
    if(action == "forestSexCowMira3")
        forestSexCowMira3();
    if(action == "forestSexSideMira2")
        forestSexSideMira2();
    if(action == "forestSexDogMira2_1")
        forestSexDogMira2_1();
    if(action == "forestSexMisMira2")
        forestSexMisMira2();
    if(action == "forestSexDogMira2")
        forestSexDogMira2();
    if (action == "forestSexCowMira1")
        forestSexCowMira1();
    if(action == "forestSexCowMira2_1")
        forestSexCowMira2_1();
    if(action == "forestSexDogVMira1")
        forestSexDogVMira1();
    if(action == "forestSexDogAMira1")
        forestSexDogAMira1();
    if(action == "forestSexThroatMira1")
        forestSexThroatMira1();
    if(action == "forestSexOralMira1")
        forestSexOralMira1();
    if(action == "forestSexOralMira2_1")
        forestSexOralMira2_1();
    if(action == "forestSexOralCumMira2_1")
        forestSexOralCumMira2_1();
    if(action == "forestSexCumMira1")
        forestSexCumMira1();
    if(action == "forestSexCumMira2")
        forestSexCumMira2();
    if(action == "forestSexCumMira3")
        forestSexCumMira3();
}

void MitkaSex::forestSexOral1_1()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,7);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    root->setImage(media(60));
    root->setDesc(str(85));
    root->blow_job();
    root->addDesc(str(88));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 7)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexOralCum1_1",act(4));
}

void MitkaSex::forestSexOral1_2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,7);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    if(root->gVEvent(mirasextimes) < 50)
        boyAhorny += 5;
    if(root->gVEvent(mirasextimes) >= 50)
        boyAhorny += 10;
    root->setImage(media(61));
    root->setDesc(str(85));
    root->blow_job();
    root->addDesc(str(87));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 7)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexOralCum1_1",act(4));
}

void MitkaSex::forestSexOral1_3()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,7);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    if(root->gVEvent(mirasextimes) < 50)
        boyAhorny += 5;
    if(root->gVEvent(mirasextimes) >= 50)
        boyAhorny += 10;
    root->setImage(media(62));
    root->setDesc(str(85));
    root->blow_job();
    root->addDesc(str(86));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 7)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexOralCum1_1",act(4));
}

void MitkaSex::forestSexOral2_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,3);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    root->setImage(media(62));
    root->setDesc(str(58));
    root->blow_job();
    root->addDesc(str(59));
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 5;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexCow2_1",act(10));
        if(hantsexa == 2)
            makeActBtn("forestSexDog2_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexDog2_2",act(2));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(4));
    }
}

void MitkaSex::forestSexOral3_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->uVSC(blowJob,1);
    root->setImage(media(63));
    root->setDesc(str(1));
    if(tmp == 1)
        setMitka();
    if(tmp == 2)
        setKolyamba();
    if(tmp == 3)
        setVasyan();
    root->blow_job();

    mirarand = getRandInt(1,4);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(2));
        if(mirarand == 2)
            root->addDesc(str(3));
        if(mirarand == 3)
            root->addDesc(str(4));
        if(mirarand == 4)
            root->addDesc(str(5));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        root->addDesc(str(6));
        makeActBtn("forestSexCum3_1",act(4));
    }
    root->addDesc(textsexhanter[2]);
}

void MitkaSex::forestSexOral3_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->uVSex(lubonus,1);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->uVSC(blowJob,1);
    root->setImage(media(64));
    root->setDesc(str(21));
    if(tmp == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
    }
    if(tmp == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
        root->blow_job();
    }
    if(tmp == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    mirarand = getRandInt(1,5);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(8));
        if(mirarand == 2)
            root->addDesc(str(9));
        if(mirarand == 3)
            root->addDesc(str(10));
        if(mirarand == 4)
            root->addDesc(str(11));
        if(mirarand == 5)
            root->addDesc(str(12));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        root->addDesc(str(13));
        makeActBtn("forestSexCum3_2",act(4));
    }
    root->addDesc(textsexhanter[3]);
}

void MitkaSex::forestSexOral3_3()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    root->uVSex(lubonus,1);
    mitboysex += 1;
    root->uVSC(blowJob,1);
    root->setImage(media(65));
    root->setDesc(str(21));
    setMitka();
    root->blow_job();
    setKolyamba();
    root->blow_job();
    setVasyan();
    root->blow_job();
    root->addDesc(str(23));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_3",act(4));
    }
}

void MitkaSex::forestSexOralCum1_1()
{
    root->incTime(5);
    root->sVSex(protect,0);
    root->setImage(media(66));
    root->setDesc(str(84));
    root->blow_job();
    root->fnswallow();
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexOralCum2_1()
{
    root->incTime(5);
    root->cum("face");
    root->setImage(media(67));
    root->setDesc(str(1));
    root->blow_job();
    root->fnswallow();
    root->addDesc(textsexhanter[1]);
    if(boyBhorny < 100 && boyBcum == 0)
    {
        int tmp = getRandInt(1,2);
        if(tmp == 1)
            root->addDesc(str(51));
        if(tmp == 2)
            root->addDesc(str(52));
    }
    else if(boyBhorny >= 100 && boyBcum == 0)
        root->addDesc(str(53));
    else
        root->addDesc(str(49));
    root->sVSex(protect,0);
    if(boyBcum == 0)
        makeActBtn("forestSexRelax2",act(7));
    else
        makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestCowKiss1_1()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    root->setImage(media(68));
    root->setDesc(str(71));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexDogCum1_2",act(8));
}

void MitkaSex::forestSexCowOral1_1()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    if(root->vBody(throat) <= 15)
        boyAhorny += 5;
    if(root->vBody(throat) > 15)
        boyAhorny += 10;
    if(boyAhorny < 100)
        root->setImage(media(69));
    if(boyAhorny >= 100)
        root->setImage(media(70));
    root->setDesc(str(69));
    root->blow_job();
    if(boyAhorny >= 100)
        root->fnswallow();
    if(boyAhorny < 100)
        root->addDesc(textsexhanter[2]);
    if(boyAhorny >= 100)
        root->addDesc(textsexhanter[8]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexCow1_1()
{
    root->incTime(5);
    hantsexa = getRandInt(1,6);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->sVSex(pose,2);
    if(root->gVEvent(miralesb) == 0)
        root->setImage(media(71));
    else
    {
        root->setImage(media(72));
        root->uVStatus(horny,5);
    }
    root->setDesc(str(77));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(root->gVEvent(miralesb) == 0)
        root->addDesc(str(78));
    if(root->gVEvent(miralesb) > 2)
        root->addDesc(str(79));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexCowCum1_1",act(12));
}

void MitkaSex::forestSexCow1_2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,6);
    if(root->gVEvent(mirasextimes) < 50)
        boyAhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyAhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(73));
    if(root->gVEvent(mirasextimes) < 50)
        root->setDesc(str(72));
    if(root->gVEvent(mirasextimes) >= 50)
        root->setDesc(str(73));
    if(root->gVEvent(miralesb) > 0)
        root->addDesc(str(74));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->addDesc(str(75));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexCowCum1_2",act(8));
}

void MitkaSex::forestSexCow2_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,2);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(74));
    root->setDesc(str(45));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(boyAhorny < 100 && boyBcum == 0)
        root->addDesc(str(46));
    if(boyAhorny >= 100 && boyBcum == 0)
        root->addDesc(str(47));
    if(boyBcum == 1)
        root->addDesc(str(48));
    root->addDesc(textsexhanter[2]);
    boyBcum = 1;
    if(boyAhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide2_3",act(9));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(5));
    }
}

void MitkaSex::forestSexCowCum1_1()
{
    root->incTime(1);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,1);
    root->setImage(media(75));
    root->setDesc(str(76));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexCowCum1_2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(76));
    root->setDesc(str(70));
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexDog1_1()
{
    root->incTime(5);
    hantsexa = getRandInt(1,6);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->sVSex(pose,1);
    root->setImage(media(77));
    root->setDesc(str(67));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(68));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexDogCum1_1",act(11));
}

void MitkaSex::forestSexDog1_2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    hantsexa = getRandInt(1,6);
    if(root->gVEvent(mirasextimes) < 50)
        boyAhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyAhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(78));
    if(root->gVEvent(mirasextimes) < 50)
        root->setDesc(str(64));
    if(root->gVEvent(mirasextimes) >= 50)
        root->setDesc(str(65));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexDogCum1_2",act(8));
}

void MitkaSex::forestSexDog1_3()
{
    root->incTime(5);
    hantsexa = getRandInt(1,6);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,1);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(79));
    root->setDesc(str(61));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(62));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 4)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_2",act(3));
    }
    else
        makeActBtn("forestSexDogCum1_3",act(2));
}

void MitkaSex::forestSexDog2_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->sVSex(pose,1);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(80));
    root->setDesc(str(17));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(57));
    if(boyBhorny >= 100)
        root->addDesc(str(40));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexDog2_2",act(2));
    }
    else if (boyAhorny < 100 && boyBhorny >= 100)
    {
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide2_3",act(9));
        if(hantsexa == 3)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(5));
    }
}

void MitkaSex::forestSexDog2_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->sVSex(pose,1);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(81));
    root->setDesc(str(17));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(56));
    if(boyBhorny >= 100)
        root->addDesc(str(40));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexCow2_1",act(10));
        if(hantsexa == 2)
            makeActBtn("forestSexDog2_1",act(2));
    }
    else if (boyAhorny < 100 && boyBhorny >= 100)
    {
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide2_3",act(9));
        if(hantsexa == 3)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(5));
    }
}

void MitkaSex::forestSexDogCum1_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,1);
    root->setImage(media(82));
    root->setDesc(str(66));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
        root->sex_cum();
        root->addDesc(textsexhanter[8]);
        makeActBtn("back_to_loc",act(7));
    }
}

void MitkaSex::forestSexDogCum1_2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(83));
    root->setDesc(str(63));
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexDogCum1_3()
{
    root->incTime(5);
    root->sVSex(pose,1);
    root->cum("ass");
    root->setImage(media(84));
    root->setDesc(str(60));
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexSide1_1()
{
    root->incTime(5);
    hantsexa = getRandInt(1,6);
    if(root->vBody(vagina) <= 25)
        boyAhorny +=20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,0);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(85));
    root->setDesc(str(46));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(82));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_2",act(3));
        if(hantsexa == 2)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
        makeActBtn("forestSexSideCum1_1",act(13));
}

void MitkaSex::forestSexSide1_2()
{
    root->incTime(5);
    root->uVStatus(horny,5);
    if(root->gVEvent(mirasextimes) < 50)
        boyAhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyAhorny += 10;
    root->sVSex(pose,1);
    root->setImage(media(86));
    if(root->gVEvent(mirasextimes) < 50)
        root->setDesc(str(80));
    if(root->gVEvent(mirasextimes) >= 50)
        root->setDesc(str(81));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexSide1_1",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexCow1_1",act(10));
        if(hantsexa == 3)
            makeActBtn("forestSexCow1_2",act(3));
        if(hantsexa == 4)
            makeActBtn("forestSexDog1_1",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexDog1_2",act(3));
        if(hantsexa == 6)
            makeActBtn("forestSexDog1_3",act(2));
    }
    else
    {
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexOral1_1",act(0));
        if(hantsexa == 2)
            makeActBtn("forestSexOral1_2",act(0));
        if(hantsexa == 3)
            makeActBtn("forestSexOral1_3",act(0));
    }
}

void MitkaSex::forestSexSide2_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    if(root->vBody(vagina) <= 25)
        boyAhorny +=20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->sVSex(pose,1);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(87));
    root->setDesc(str(46));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    root->addDesc(str(54));
    if(boyBhorny >= 100)
        root->addDesc(str(55));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100 && boyBhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexDog2_1",act(2));
        if(hantsexa == 2)
            makeActBtn("forestSexDog2_2",act(2));
    }
    else if (boyAhorny < 100 && boyBhorny >= 100)
    {
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide2_3",act(9));
        if(hantsexa == 3)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(5));
    }
}

void MitkaSex::forestSexSide2_2()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,0);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(88));
    root->setDesc(str(46));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(boyAhorny < 100 && boyBcum == 0)
        root->addDesc(str(47));
    if(boyAhorny >= 100 && boyBcum == 0)
        root->addDesc(str(48));
    if(boyBcum == 1)
        root->addDesc(str(49));
    root->addDesc(textsexhanter[2]);
    boyBcum = 1;
    if(boyAhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_3",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
        makeActBtn("forestSexOralCum2_1",act(5));
}

void MitkaSex::forestSexSide2_3()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    hantsexa = getRandInt(1,5);
    if(root->vBody(vagina) <= 25)
        boyAhorny += 20;
    if(root->vBody(vagina) > 25)
        boyAhorny += 10;
    root->sVSex(pose,1);
    if(boyAsex == 0)
    {
        boyAsex = 1;
        root->uVSC(vaginalSex,1);
    }
    root->setImage(media(89));
    root->setDesc(str(46));
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    if(boyAhorny < 100 && boyBcum == 0)
        root->addDesc(str(47));
    if(boyAhorny >= 100 && boyBcum == 0)
        root->addDesc(str(48));
    if(boyBcum == 1)
        root->addDesc(str(49));
    root->addDesc(textsexhanter[2]);
    boyBcum = 1;
    if(boyAhorny < 100)
    {
        hantsexa = getRandInt(1,2);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
        makeActBtn("forestSexOralCum2_1",act(5));
}

void MitkaSex::forestSexSideCum1_1()
{
    root->incTime(5);
    root->uVStatus(horny,getRandInt(5,10));
    root->sVSex(pose,1);
    root->setImage(media(90));
    root->setDesc(str(83));
    if(root->vStatus(horny) >= 100)
    {
        root->addDesc(textsexhanter[9]);
        root->uVSC(orgasm,1);
        root->uVSC(vaginalOrgasm,1);
        root->sVStatus(lust,0);
        root->sVStatus(horny,0);
        root->uVStatus(mood,15);
    }
    root->sex_cum();
    root->addDesc(textsexhanter[8]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexVag3()
{
    root->incTime(5);
    root->uVSex(lubonus,1);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->sVSex(pose,0);
    root->setImage(media(91));
    root->setDesc(str(7));
    if(tmp == 1)
    {
        setMitka();
        root->blow_job();
        if(boyBsex == 0)
        {
            boyBsex = 1;
            root->uVSC(vaginalSex,1);
        }
        setKolyamba();
    }
    if(tmp == 2)
    {
        setVasyan();
        root->blow_job();
        if(boyAsex == 0)
        {
            boyAsex = 1;
            root->uVSC(vaginalSex,1);
        }
        setMitka();
    }
    if(tmp == 3)
    {
        setKolyamba();
        root->blow_job();
        if(boyCsex == 0)
        {
            boyCsex = 1;
            root->uVSC(vaginalSex,1);
        }
        setVasyan();
    }
    root->sVSex(protect,1);
    root->sexStart();
    root->vaginal(tDick);
    mirarand = getRandInt(1,5);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(8));
        if(mirarand == 2)
            root->addDesc(str(9));
        if(mirarand == 3)
            root->addDesc(str(10));
        if(mirarand == 4)
            root->addDesc(str(11));
        if(mirarand == 5)
            root->addDesc(str(12));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        root->setDesc(str(13));
        makeActBtn("forestSexCum3_2",act(5));
    }
    root->addDesc(textsexhanter[3]);
}

void MitkaSex::forestSexAnal3_1()
{
    root->incTime(5);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->setImage(media(92));
    root->setDesc(str(17));
    if(tmp == 1)
    {
        if(boyAsexa == 0)
        {
            boyAsexa = 1;
            root->uVSC(analSex,1);
        }
        setMitka();
    }
    else if(tmp == 2)
    {
        if(boyBsexa == 0)
        {
            boyBsexa = 1;
            root->uVSC(analSex,1);
        }
        setKolyamba();
    }
    else if(tmp == 3)
    {
        if(boyCsexa == 0)
        {
            boyCsexa = 1;
            root->uVSC(analSex,1);
        }
        setVasyan();
    }
    root->analStart(tDick);
    root->anal(tDick);
    mirarand = getRandInt(1,4);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(2));
        if(mirarand == 2)
            root->addDesc(str(3));
        if(mirarand == 3)
            root->addDesc(str(4));
        if(mirarand == 4)
            root->addDesc(str(5));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        root->addDesc(str(6));
        makeActBtn("forestSexCum3_1",act(5));
    }
    root->addDesc(textsexhanter[2]);
}

void MitkaSex::forestSexAnal3_2()
{
    root->incTime(5);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->setImage(media(93));
    root->setDesc(str(16));
    if(tmp == 1)
    {
        setMitka();
        root->blow_job();
        if(boyBsexa == 0)
        {
            boyBsexa = 1;
            root->uVSC(analSex,1);
        }
        setKolyamba();
    }
    else if(tmp == 2)
    {
        setVasyan();
        root->blow_job();
        if(boyAsexa == 0)
        {
            boyAsexa = 1;
            root->uVSC(analSex,1);
        }
        setMitka();
    }
    else if(tmp == 3)
    {
        setKolyamba();
        root->blow_job();
        if(boyCsexa == 0)
        {
            boyCsexa = 1;
            root->uVSC(analSex,1);
        }
        setVasyan();
    }
    root->analStart(tDick);
    root->anal(tDick);
    root->uVSex(lubonus,1);
    mirarand = getRandInt(1,5);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(8));
        if(mirarand == 2)
            root->addDesc(str(9));
        if(mirarand == 3)
            root->addDesc(str(10));
        if(mirarand == 4)
            root->addDesc(str(11));
        if(mirarand == 5)
            root->addDesc(str(12));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        root->addDesc(str(13));
        makeActBtn("forestSexCum3_2",act(5));
    }
    root->addDesc(textsexhanter[3]);
}

void MitkaSex::forestSexAnal3_3()
{
    root->incTime(5);
    int tmp = getRandInt(1,3);
    hantsexa = getRandInt(1,5);
    mitboysex += 1;
    root->setImage(media(94));
    root->setDesc(str(14));
    root->addDesc(textsexhanter[3]);
    if(tmp == 1)
    {
        setVasyan();
        root->blow_job();
        setMitka();
        root->blow_job();
        if(boyBsexa == 0)
        {
            boyBsexa = 1;
            root->uVSC(analSex,1);
        }
        setKolyamba();
    }
    else if(tmp == 2)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
        if(boyAsexa == 0)
        {
            boyAsexa = 1;
            root->uVSC(analSex,1);
        }
        setMitka();
    }
    else if(tmp == 3)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
        if(boyCsexa == 0)
        {
            boyCsexa = 1;
            root->uVSC(analSex,1);
        }
        setVasyan();
    }
    root->analStart(tDick);
    root->anal(tDick);
    root->addDesc(str(15));
    root->addDesc(textsexhanter[5]);
    root->uVSex(lubonus,1);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_3",act(5));
    }

}

void MitkaSex::forestSexCum3_1()
{
    root->incTime(1);
    mitboysex = 0;
    root->sVSex(protect,0);
    root->setImage(media(95));
    root->setDesc(str(1));
    int tmp = getRandInt(1,3);
    if(tmp == 1)
        setMitka();
    else if(tmp == 2)
        setKolyamba();
    else if(tmp == 3)
        setVasyan();
    root->blow_job();
    root->fnswallow();
    root->addDesc(textsexhanter[1]);
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexCum3_2()
{
    root->incTime(2);
    root->cum("lip");
    root->uVSC(swallow,1);
    root->cum("face");
    if(root->isNude())
        root->cum("belly");
    else
        root->uVStatus(cumFrot, getRandInt(0,1));
    mitboysex = 0;
    root->setImage(media(96));
    root->setDesc(str(21));
    int tmp = getRandInt(1,3);
    if(tmp == 1)
    {
        setMitka();
        root->blow_job();
        setKolyamba();
        root->blow_job();
    }
    else if(tmp == 2)
    {
        setVasyan();
        root->blow_job();
        setMitka();
        root->blow_job();
    }
    else if(tmp == 3)
    {
        setKolyamba();
        root->blow_job();
        setVasyan();
        root->blow_job();
    }
    root->addDesc(str(22));
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexCum3_3()
{
    root->incTime(3);
    root->cum("lip");
    root->uVSC(swallow,1);
    root->cum("face");
    if(root->isNude())
        root->cum("belly");
    else
        root->uVStatus(cumFrot, getRandInt(0,1));
    mitboysex = 0;
    root->sVSex(protect,0);
    root->setImage(media(97));
    root->setDesc(str(21));
    setMitka();
    root->blow_job();
    setKolyamba();
    root->blow_job();
    setVasyan();
    root->blow_job();
    root->addDesc(str(22));
    makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexRelax()
{
    root->incTime(5);
    root->uVStatus(horny, getRandInt(5,10));
    hantsexa = getRandInt(1,4);
    mitboysex += 1;
    root->setImage(media(33));
    root->setDesc(str(18));
    mirarand = getRandInt(1,2);
    if(mitboysex < mitboysexrand)
    {
        if(mirarand == 1)
            root->addDesc(str(19));
        if(mirarand == 2)
            root->addDesc(str(20));
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
    }
    else
    {
        makeActBtn("forestSexCumMira3",act(6));
    }
    root->addDesc(textsexhanter[5]);
}

void MitkaSex::forestSexRelax2()
{
    root->incTime(5);
    root->setImage(media(34));
    root->setDesc(str(50));
    if(boyBhorny < 100)
    {
        int tmp = getRandInt(1,2);
        if(tmp == 1)
            makeActBtn("forestSexDogMira2_1",act(3));
        if(tmp == 2)
            makeActBtn("forestSexCowMira2_1",act(3));
    }
    else
        makeActBtn("forestSexOralCumMira2_1",act(3));
}

void MitkaSex::forestSexRelaxMira()
{
    root->incTime(1);
    root->setImage(media(32));
    root->setDesc(str(24));
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_3",act(0));
    }
}

void MitkaSex::forestSexDPMira3()
{
    root->incTime(1);
    root->uVStatus(horny,getRandInt(20,30));
    root->uVSex(lubonus,1);
    root->setImage(media(31));
    root->setDesc(str(25));
    root->addDesc(textsexhanter[5]);
    if(hantsexa == 1)
        makeActBtn("forestSexVag3",act(1));
    if(hantsexa == 2)
        makeActBtn("forestSexAnal3_1",act(2));
    if(hantsexa == 3)
        makeActBtn("forestSexAnal3_2",act(2));
    if(hantsexa == 4)
        makeActBtn("forestSexAnal3_3",act(2));
}

void MitkaSex::forestSexCowMira3()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(30));
    root->setDesc(str(26));
    root->addDesc(textsexhanter[5]);
    if(hantsexa == 1)
        makeActBtn("forestSexVag3",act(1));
    if(hantsexa == 2)
        makeActBtn("forestSexAnal3_1",act(2));
    if(hantsexa == 3)
        makeActBtn("forestSexAnal3_2",act(2));
    if(hantsexa == 4)
        makeActBtn("forestSexAnal3_3",act(2));
}

void MitkaSex::forestSexCowMira2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(29));
    root->setDesc(str(27));
    root->addDesc(textsexhanter[2]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_1",act(0));
    }
}

void MitkaSex::forestSexSideMira2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(28));
    root->setDesc(str(28));
    root->addDesc(textsexhanter[2]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_1",act(0));
    }
}

void MitkaSex::forestSexDogMira2_1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->setImage(media(27));
    root->setDesc(str(41));
    if(boyBhorny >= 100)
        root->addDesc(str(42));
    if(boyBhorny < 100)
        makeActBtn("forestSexRelax2",act(7));
    else
        makeActBtn("forestSexOralCumMira2",act(8));
}

void MitkaSex::forestSexMisMira2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(26));
    root->setDesc(str(29));
    root->addDesc(textsexhanter[2]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_1",act(0));
    }
}

void MitkaSex::forestSexDogMira2()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(24));
    root->setDesc(str(30));
    root->addDesc(textsexhanter[2]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_1",act(0));
    }
}

void MitkaSex::forestSexCowMira1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(25));
    root->setDesc(str(31));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_2",act(0));
    }
}

void MitkaSex::forestSexCowMira2_1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    if(root->gVEvent(mirasextimes) < 50)
        boyBhorny += 20;
    if(root->gVEvent(mirasextimes) >= 50)
        boyBhorny += 10;
    root->setImage(media(23));
    root->setDesc(str(39));
    if(boyBhorny >= 100)
        root->addDesc(str(40));
    if(boyBhorny < 100)
        makeActBtn("forestSexRelax2",act(7));
    else
        makeActBtn("forestSexOralCumMira2()",act(8));
}

void MitkaSex::forestSexDogVMira1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(22));
    root->setDesc(str(32));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_2",act(0));
    }
}

void MitkaSex::forestSexDogAMira1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(21));
    root->setDesc(str(33));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_2",act(0));
    }
}

void MitkaSex::forestSexThroatMira1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(20));
    root->setDesc(str(34));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_2",act(0));
    }
}

void MitkaSex::forestSexOralMira1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->uVSex(lubonus,1);
    root->setImage(media(19));
    root->setDesc(str(35));
    root->addDesc(textsexhanter[3]);
    if(mitboysex < mitboysexrand)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexVag3",act(1));
        if(hantsexa == 2)
            makeActBtn("forestSexAnal3_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexAnal3_2",act(2));
        if(hantsexa == 4)
            makeActBtn("forestSexAnal3_3",act(2));
        if(hantsexa == 5)
            makeActBtn("forestSexRelax",act(3));
    }
    else
    {
        makeActBtn("forestSexCum3_2",act(0));
    }
}

void MitkaSex::forestSexOralMira2_1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    root->setImage(media(18));
    root->setDesc(str(44));
    root->addDesc(textsexhanter[2]);
    if(boyAhorny < 100)
    {
        if(hantsexa == 1)
            makeActBtn("forestSexCow2_1",act(10));
        if(hantsexa == 2)
            makeActBtn("forestSexDog2_1",act(2));
        if(hantsexa == 3)
            makeActBtn("forestSexDog2_2",act(2));
    }
    else
    {
        makeActBtn("forestSexOralCum2_1",act(4));
    }
}

void MitkaSex::forestSexOralCumMira2_1()
{
    root->incTime(1);
    root->uVStatus(horny,5);
    boyBcum = 1;
    root->setImage(media(17));
    root->setDesc(str(43));
    if(boyAhorny < 100)
    {
        root->addDesc(textsexhanter[2]);
        hantsexa = getRandInt(1,3);
        if(hantsexa == 1)
            makeActBtn("forestSexSide2_2",act(9));
        if(hantsexa == 2)
            makeActBtn("forestSexSide2_3",act(9));
        if(hantsexa == 3)
            makeActBtn("forestSexCow2_1",act(10));
    }
    else
        makeActBtn("back_to_loc",act(7));
}

void MitkaSex::forestSexCumMira1()
{
    root->incTime(1);
    root->setImage(media(14));
    root->setDesc(str(36));
    root->addDesc(textsexhanter[3]);
    makeActBtn("forestSexCum3_2",act(0));
}

void MitkaSex::forestSexCumMira2()
{
    root->incTime(1);
    root->setImage(media(15));
    root->setDesc(str(37));
    root->addDesc(textsexhanter[2]);
    makeActBtn("forestSexCum3_2",act(0));
}

void MitkaSex::forestSexCumMira3()
{
    root->incTime(1);
    root->setImage(media(16));
    root->setDesc(str(38));
    makeActBtn("back_to_loc",act(7));
}

QString MitkaSex::str(int id)
{
    QString str[107];
    str[0] = "Войдя поглубже в заросли парни подошли к вам с Мирой вплотную и начали раздевать. Они надавили вам на плечи и вы принялись...";
    str[1] = "Вы стоите на коленях перед парнем, его член перед вашим лицом...";

    str[2] = "Недалеко от вас слышится громкое мычание <a href='forestSexCowMira2'>Мирославы</a>.";
    str[3] = "Недалеко от вас слышится возня пацанов и Миры. <a href='forestSexSideMira2'>Посмотреть</a>.";
    str[4] = "Недалеко от вас слышится сопение <a href='forestSexMisMira2'>Миры</a>.";
    str[5] = "Недалеко от вас мычание <a href='forestSexDogMira2'>Миры</a>.";
    str[6] = "Недалеко от вас находится <a href='forestSexCumMira2'>Мирослава</a>.";

    str[7] = "Вы лежите на земле. Один парень пристроился между ваших ног, второй подносит член к вашим губам...";

    str[8] = "Недалеко от вас слышатся причмокивающие звуки. <a href='forestSexOralMira1'>Посмотреть</a>.";
    str[9] = "Недалеко от вас слышится сопение и хрюкающие звуки. <a href='forestSexThroatMira1>Посмотреть</a>.";
    str[10] = "Недалеко от вас постанывает <a href='forestSexCowMira1'>Мира</a>.";
    str[11] = "Недалеко от вас постанывает <a href='forestSexDogVMira1'>Мира</a>.";
    str[12] = "Недалеко от вас громко охает <a href='forestSexDogAMira1'>Мира</a>.";

    str[13] = "Недалеко от вас находится <a href='forestSexCumMira1'>Мира</a>.";

    str[14] = "Вы стоите раком перед пацанами. Один пристраевается к вашей попке, двое других вывалили члены перед вашим лицом...";
    str[15] = "Недалеко от вас на земле сидит <a href='forestSexRelaxMira'>Мирослава</a>.";
    str[16] = "Вы стоите раком перед пацанами. Один из них пристраивается к попе, второй подносит член к вашим губам...";
    str[17] = "Вы стоите раком перед парнем, он пристаивается сзади...";
    str[18] = "Вы сидите на земле, пацанам пока до вас нет дела...";
    str[19] = "Недалеко от вас пацаны в три ствола трахают <a href='forestSexDPMira3'>Миру</a>.";
    str[20] = "Недалеко от вас пацаны в три ствола трахают <a href='forestSexCowMira3'>Миру</a>.";

    str[21] = "Вы стоите на коленях перед пацанами, и сосете их члены, поочередно уделяю внимание каждому...";
    str[22] = "Вскоре не выдержав вашего напора парни начинают кончать. Струи спермы ударяют вам в рот и попадают на лицо, одна, вторая, третья. Спермы оказалось слишком много. Она стекает по подбородку, капая вниз. Парни убрали члены в штаны и пошели по своим делам, оставив вас с Мирой приводить себя в порядок.";
    str[23] = "Недалеко от вас на земле сидит <a href='forestSexRelaxMira'>Мирослава</a>.";
    str[24] = "Мира сидит рядом и пока пацанам не до неё, смотрит на как вас трахают...";
    str[25] = "Вы с интересом наблюдаете как Миру пацаны натягивают Миру сразу на три члена, заполняя все её дырочки. Мире остается только мычать и напряженно сопеть.";
    str[26] = "Вы смотрите как Мира, громко мыча, скачет на члене одного пацана, а двоих других, поочередно, обслуживает ртом.";
    str[27] = "Повернув голову в сторону Миры, вы видите как она, громко мыча, скачет на члене одного пацана, одновременно сося член второго.";
    str[28] = "Повернув голову в сторону Миры, вы видите как её, лежащую на боку, трахает один из парней, пока она сосет второму.";
    str[29] = "Повернув голову в сторону Миры, вы видите как её, лежащую на спине, трахает один из парней, пока она сосет второму.";
    str[30] = "Повернув голову в сторону Миры, вы видите как её, стоящую раком, обступили парни и трахают с двух сторон одновременно.";
    str[31] = "Скосив взгляд в сторону, вы видите Мирославу, которая постанывая, скачет на члене парня.";
    str[32] = "Скосив взгляд в сторону, вы видите Мирославу, которая постанывает стоя раком, пока парень размашисто долбит её киску.";
    str[33] = "Скосив взгляд в сторону, вы видите Мирославу, которая громко охает стоя раком, когда парень, пристроившийся сзади, таранит её зад своим членом.";
    str[34] = "Скосив взгляд в сторону, парня, который запрокинув голову сопящей и хрюкающей Миры, долбит её прямо в горло.";
    str[35] = "Скосив взгляд в сторону, вы видите Мирославу, усердно отсасывающую парню.";
    str[36] = "Скосив взгляд в сторону, вы видите лежащую на земле Мирославу, лицо которой все залито спермой, и стоящего над ней парня.";
    str[37] = "Скосив взгляд в сторону, вы видите лежащую на земле Мирославу, и кончающих ей на лицо пацанов.";
    str[38] = "Вы видите, пацанов обступивших со всех сторонстоящую на коленях Миру, лицо которой покрыто толстым слоем спермы.";
    str[39] = "Вы видите стоящую раком Мирославу. Она постанывает и слегка и раскачивается в такт толчков второго парня.";
    str[40] = "Неожиданно парень грубо спихивает её с себя и поставив перед собой на колени, начинает дрочить перед лицом.";
    str[41] = "Мира, постанывая, бойко скачет на члене второго парня.";
    str[42] = "Неожиданно парень хватает Миру за волосы и поставив перед собой на колени, начинает дрочить перед её лицом.";
    str[43] = "Посмотрев в сторону Миры, вы видите парня кончающего в её открытый рот, пока она стоит на коленях перед ним.";
    str[44] = "Скосив взгляд в сторону, вы видите Мирославу, усердно отсасывающую второму парню.";
    str[45] = root->getBoyName() + " ложится на землю, вы, перекинув ногу через его тело, пристраиваетесь сверху...";
    str[46] = "Вы лежите на боку, " + root->getBoyName() + " пристраивается к вашей киске...";
    str[47] = "Недалеко от вас стоит на коленях с открытым ртом <a href='forestSexOralCumMira2_1'>Мира</a>.";
    str[48] = "Недалеко от вас второй парень кончает, стоящей на коленях перед ним Мире, прямо в широко открытый рот.";
    str[49] = "Растрепаная Мира сидит на земле недалеко от вас и приводит себя в порядок, изредка кидая взгляды в вашу сторону.";
    str[50] = "Ничем не занятые вы стоите в сторонке и приводите себя в порядок, изредка поглядывая на постанывающую Мирославу.";
    str[51] = "Недалеко от вас постанывает <a href='forestSexDogMira2_1'>Мира</a>.";
    str[52] = "Недалеко от вас постанывает <a href='forestSexCowMira2_1'>Мира</a>.";
    str[53] = "Недалеко от вас стоит на коленях с открытым ртом <a href='forestSexOralCumMira2_1'>Мира</a>.";
    str[54] = "Прямо перед вами Мира с энтузиазмом отсасывает второму парню.";
    str[55] = "Неожиданно парень высовывает член из её рта и начинает дрочить перед лицом.";
    str[56] = "Недалеко от вас скачет верхом на втором парне Мира.";
    str[57] = "Недалеко от вас стоит раком Мира, слегка постанывая и раскачиваясь в такт толчков второго парня.";
    str[58] = "Вы стоите на коленях перед парнем. " + root->getBoyName() + " достав свой член, подносит его к вашим губам...";
    str[59] = "Недалеко от вас стоит на корточках <a href='forestSexOralMira2_1'>Мира</a>.";
    str[60] = "Чувствуя приближающийся оргазм " + root->getBoyName() + " поставил вас раком, рядом друг с другом и начал надрачивать свой член. Вскоре он застонал и вы почувствовали горячие капли спермы на вашей попе.";
    str[61] = root->getBoyName() + " поставил вас раком, а Миру взгромоздил сверху, на вашу спину, сделав из вас своеобразный бутерброд. Оглядев эту конструкцию он начал пристраиватся к вашей киске...";
    str[62] = "Через некоторое время достав из вас свой член, он вснул его в Мирославу, и вы почувствовали, как задрожало её тело под его ритмичными ударами, заодно раскачивая и вас в такт.";
    str[63] = "Вы видите, что " + root->getBoyName() + ", находясь в Мире, постепенно ускоряет темп. Внезапно " + root->getBoyName() + " застонал и вы поняли, что он кончил в неё.";
    str[64] = "Вы стоите раком рядом с Мирославой и смотрите как " + root->getBoyName() + " своим " + intQStr(root->vSex(dick)) + " сантиметровым членом таранит её разработанную киску.";
    str[65] = "Вы стоите раком рядом с Мирославой и смотрите как " + root->getBoyName() + " своим " + intQStr(root->vSex(dick)) + " сантиметровым членом таранит её раздолбаную вагину.";
    str[66] = "Вы стоите раком, оттопырив попу, и чувствуете, что " + root->getBoyName() + " начинает двигаться быстрее...";
    str[67] = "Вы стоите раком, " + root->getBoyName() + " сзади пристраивается к вашей киске...";
    str[68] = "Мирослава сидит на коленках рядом с вами и наблюдает, как поршень долбит в вашу " + root->getVaginaTipe2() + " вагину.";
    str[69] = "Вынув член из вагины Миры вы поднесли его к своим губам...";
    str[70] = "Мира скачет на члене парня постепенно ускоряя темп. Внезапно " + root->getBoyName() + " застонал и вы поняли, что он кончил в Мирославу.";
    str[71] = "Наблюдая как Мира скачет на члене парня, вам вдруг захотелось поцеловать её. Вы приблизили губы к её губам и слились в страстном поцелуе, ощущая ритмичные толчки её тела.";
    str[72] = "Вы сидите у изголовья парня и смотрите как как Мира скачет на его члене. Одновременно с этим " + root->getBoyName() + ", просунув руку между ваших ног, теребит пальцами вашу киску, постепенно возбуждая вас.";
    str[73] = "Вы сидите у изголовья парня и смотрите как Мира насаживается своей раздолбаной вагиной на член парня. Одновременно с этим " + root->getBoyName() + ", просунув руку между ваших ног, теребит пальцами вашу киску, постепенно возбуждая вас.";
    str[74] = "Вы можете нагнуться и поцеловать <a href='forestCowKiss1_1'>Миру</a>.";
    str[75] = "Вы можете вынуть из Миры член парня и <a href='forestSexCowOral1_1'>пососать</a>.";
    str[76] = "Вы скачете на члене парня постепенно ускоряя темп, понимая что он скоро кончит...";
    str[77] = root->getBoyName() + " лежит на земле, а вы пристраиваетесь к его члену, забравшись верхом на парня...";
    str[78] = "Мирослава лежит рядом с вами и наблюдает, как вы скачете на члене парня.";
    str[79] = "Пока вы скачете на парне, Мирослава, приблизив свое лицо, целует ваши губы, чувствуя как ваше тело содрогается от ритмичных ударов члена.";
    str[80] = "Вы лежите рядом с Мирославой и смотрите как " + root->getBoyName() + " своим " + intQStr(root->vSex(dick)) + " сантиметровым членом таранит её разработанную киску.";
    str[81] = "Вы лежите рядом с Мирославой и смотрите как " + root->getBoyName() + " своим " + intQStr(root->vSex(dick)) + " сантиметровым членом таранит её раздолбаную вагину.";
    str[82] = "Мирослава лежит рядом с вами и наблюдает, как поршень долбит в вашу " + root->getVaginaTipe2() + " вагину.";
    str[83] = "Вы лежите на боку, немного изменив позу, " + root->getBoyName() + " постепенно начинает двигаться быстрее...";
    str[84] = "Понимая, что " + root->getBoyName() + " скоро кончит, вы наращиваете темп. Мира стоит рядом с вами, не вмешиваясь в процесс.";
    str[85] = "Вы c Мирой стоите на коленях перед парнем. " + root->getBoyName() + " достав свой член, подносит его к вашим губам...";
    str[86] = "Вы с Мирославой усердно сосете и лижете член парня, ваши губы и языки иногда соприкасаются, сливаясь в таком своеобразном поцелуе.";
    str[87] = "Мира опустившись ниже ласкает своим язычком яйца парня, доставляя ему дополнительное удовольствие.";
    str[88] = "Мира стоит рядом с вами, не вмешиваясь в процесс.";
    str[89] = "Войдя поглубже в заросли " + root->getBoyName() + " подошел к вам с Мирой вплотную и сказал раздеваться раздевать. Потом надавил вам на плечи и вы принялись...";
    str[90] = root->getBoyName() + " отвел вас подальше, на какой-то пустырь, и начал раздевать. Потом надавил вам на плечи и вы принялись...";
    str[91] = "Парни отвели вас на какой-то пустырь, опустили на колени, и вручив вам в руки свои члены, сказали...";
    str[92] = "Вы стоите на коленях перед парнями. Они достав свой члены, подносит их к вашим губам...";
    str[93] = "Понимая, что " + root->getBoyName() + " скоро кончит, вы наращиваете темп...";
    str[94] = "Вы лежите на боку, чувствуя, что " + root->getBoyName() + " постепенно начинает двигаться быстрее...";
    str[95] = "Вы лежите на спине, " + root->getBoyName() + " рядом, на боку, пристраивается к вашей киске...";
    str[96] = "Вы стоите раком, " + root->getBoyName() + " сзади пристраивается к вашей попе...";
    str[97] = "Через некоторое время " + root->getBoyName() + " застонал и вы почувствовали как вашу попу наполняет тепло.";
    str[98] = "Вы лежите на земле. " + root->getBoyName() + ", чувствуя приближающийся оргазм, вложив вам в ладошку свой член, и сказал дрочить. Вы принялись за работу и вскоре были вознаграждены за свое усердие, он застонал и вы почувствовали горячие капли спермы на вашем теле.";
    str[99] = "Понимая, что " + root->getBoyName() + " скоро кончит, вы наращиваете темп, активнее действуя губами и языком...";
    str[100] = "Вы лежите на земле. Парни, чувствуя приближающийся оргазм, вложили вам в ладошки свой члены, и сказали дрочить. Вы принялись за работу и вскоре были вознаграждены за свое усердие, они застонали и вы почувствовали как выше тело орашают горячие капли спермы.";
    str[101] = "Кончив парни ушли по своим делам. А вы остались приводить себя в порядок.";
    str[102] = "Кончив, парни нарисовали на вашем теле \"хуй\" вашей же помадой, и написав еще пару похабных словечек, ушли по своим делам. А вы остались приводить себя в порядок.";
    str[103] = "Вы стоите раком перед парнями. Один пристраивается сзади к вашей киске, второй поднес член к вашим губам...";
    str[104] = "Один парень лежит на земле. Вы, пристраиваетесь к его члену, забравшись верхом на него. Второй парень в это время поднес член к вашим губам...";
    str[105] = "Вы стоите нагнувшись перед парнями. Один пристраивается сзади к вашей киске, второй поднес член к вашим губам...";
    str[106] = "Вы стоите нагнувшись, оттопырив попу, и чувствуете, что " + root->getBoyName() + " начинает двигаться быстрее...";
    return str[id];
}

QString MitkaSex::act(int id)
{
    QString str[18];
    str[0] = "Сосать";
    str[1] = "Лечь на спину";
    str[2] = "Стать раком";
    str[3] = "Смотреть";
    str[4] = "Сосать дальше";
    str[5] = "Встать на колени";
    str[6] = "Смотреть на Миру";
    str[7] = "Далее";
    str[8] = "Смотреть дальше";
    str[9] = "Лечь на бок";
    str[10] = "Сесть сверху";
    str[11] = "Стать раком дальше";
    str[12] = "Скакать дальше";
    str[13] = "Лежать на боку дальше";
    str[14] = "Нагнуться";
    str[15] = "Лечь на землю";
    str[16] = "Лежать на земле";
    str[17] = "Стоять нагнувшись дальше";
    return str[id];
}

QString MitkaSex::media(int id)
{
    QString med[98];
    if(true)
    {
        med[0] = "data/qwest/mitkasex/mitkaforestsex1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[1] = "data/qwest/mitkasex/mitkaforestsex2.jpg";
        med[2] = "data/qwest/mitkasex/mitkaforestsex3.jpg";
        med[3] = "data/qwest/mitkasex/mitkagadsex1.1.jpg";
        med[4] = "data/qwest/mitkasex/mitkagadsex1.2.jpg";
        med[5] = "data/qwest/mitkasex/mitkagadsex2.1.jpg";
        med[6] = "data/qwest/mitkasex/mitkagadsex2.2.jpg";
        med[7] = "data/qwest/mitkasex/mitkagadsexOral1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[8] = "data/qwest/mitkasex/mitkagadsexOral2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[9] = "data/qwest/mitkasex/mitkagadsexOralCuml1.jpg";
        med[10] = "data/qwest/mitkasex/mitkagadsexOralCum2_1.jpg";
        med[11] = "data/qwest/mitkasex/mitkagadsexOralCum2_2.jpg";
        med[12] = "data/qwest/mitkasex/mitkagadsexSideVag1.1.jpg";
        med[13] = "data/qwest/mitkasex/mitkagadsexSideVag1.2.jpg";
        med[14] = "data/qwest/mitkasex/mitkaforestsexCum_mira1.jpg";
        med[15] = "data/qwest/mitkasex/mitkaforestsexCum_mira2.jpg";
        med[16] = "data/qwest/mitkasex/mitkaforestsexCum_mira3.jpg";
        med[17] = "data/qwest/mitkasex/mitkaforestsexOralCum_mira2_1.jpg";
        med[18] = "data/qwest/mitkasex/mitkaforestsexOral_mira2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[19] = "data/qwest/mitkasex/mitkaforestsexOral_mira1.jpg";
        med[20] = "data/qwest/mitkasex/mitkaforestsexThroat_mira1.jpg";
    }
    if(true)
    {
        med[21] = "data/qwest/mitkasex/mitkaforestsexDogA_mira1.jpg";
        med[22] = "data/qwest/mitkasex/mitkaforestsexDogV_mira1.jpg";
        med[23] = "data/qwest/mitkasex/mitkaforestsexDog_mira2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[24] = "data/qwest/mitkasex/mitkaforestsexDog_mira2.jpg";
        med[25] = "data/qwest/mitkasex/mitkaforestsexCow_mira1.jpg";
        med[26] = "data/qwest/mitkasex/mitkaforestsexMis_mira2.jpg";
        med[27] = "data/qwest/mitkasex/mitkaforestsexCow_mira2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[28] = "data/qwest/mitkasex/mitkaforestsexSide_mira2.jpg";
        med[29] = "data/qwest/mitkasex/mitkaforestsexCow_mira2." + intQStr(getRandInt(1,3)) + ".jpg";
        med[30] = "data/qwest/mitkasex/mitkaforestsexCow_mira3.jpg";
        med[31] = "data/qwest/mitkasex/mitkaforestsexDP_mira3.jpg";
        med[32] = "data/qwest/mitkasex/mitkaforestsexRelax_mira" + intQStr(getRandInt(1,2)) + ".jpg";
        med[33] = "data/qwest/mitkasex/mitkaforestsexRelax1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[34] = "data/qwest/mitkasex/mitkaforestsexRelax2.jpg";
        med[35] = "data/qwest/mitkasex/mitkagadsexSideVagCum1.jpg";
        med[36] = "data/qwest/mitkasex/mitkagadsexMisVag1.1.jpg";
        med[37] = "data/qwest/mitkasex/mitkagadsexMisVag1.2.jpg";
        med[38] = "data/qwest/mitkasex/mitkagadsexDogVag1.jpg";
        med[39] = "data/qwest/mitkasex/mitkagadsexDogAnal1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[40] = "data/qwest/mitkasex/mitkagadsexDogAnal1." + intQStr(getRandInt(3,4)) + ".jpg";
    }
    if(true)
    {
        med[41] = "data/qwest/mitkasex/mitkagadsexDog2." + intQStr(getRandInt(1,3)) + ".jpg";
        med[42] = "data/qwest/mitkasex/mitkagadsexDogAnalCum1.jpg";
        med[43] = "data/qwest/mitkasex/mitkagadsexDogCum2_1.jpg";
        med[44] = "data/qwest/mitkasex/mitkagadsexDogCum2_2.jpg";
        med[45] = "data/qwest/mitkasex/mitkagadsexDogCum2_3.jpg";
        med[46] = "data/qwest/mitkasex/mitkagadsexCowVag1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[47] = "data/qwest/mitkasex/mitkagadsexCowVag1." + intQStr(getRandInt(3,4)) + ".jpg";
        med[48] = "data/qwest/mitkasex/mitkagadsexCow2.jpg";
        med[49] = "data/qwest/mitkasex/mitkagadsexCowVagCum1.jpg";
        med[50] = "data/qwest/mitkasex/mitkagadsexCowCum2_1.jpg";
        med[51] = "data/qwest/mitkasex/mitkagadsexCowCum2_2.jpg";
        med[52] = "data/qwest/mitkasex/mitkagadsexCowAnal1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[53] = "data/qwest/mitkasex/mitkagadsexCowAnal1." + intQStr(getRandInt(3,4)) + ".jpg";
        med[54] = "data/qwest/mitkasex/mitkagadsexHandsCum1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[55] = "data/qwest/mitkasex/mitkagadsexHandsCum2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[56] = "data/qwest/mitkasex/mitkagadsexStan2.jpg";
        med[57] = "data/qwest/mitkasex/mitkagadsexStanCum2_1.jpg";
        med[58] = "data/qwest/mitkasex/mitkagadsexStanCum2_2.jpg";
        med[59] = "data/qwest/mitkasex/mitkagadsexHandsCum2.3.jpg";
        med[60] = "data/qwest/mitkasex/mitkaforestsexOral1_1.jpg";
    }
    if(true)
    {
        med[61] = "data/qwest/mitkasex/mitkaforestsexOral1_2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[62] = "data/qwest/mitkasex/mitkaforestsexOral2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[63] = "data/qwest/mitkasex/mitkaforestsexOral3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[64] = "data/qwest/mitkasex/mitkaforestsexOral3." + intQStr(getRandInt(3,4)) + ".jpg";
        med[65] = "data/qwest/mitkasex/mitkaforestsexOral3." + intQStr(getRandInt(5,6)) + ".jpg";
        med[66] = "data/qwest/mitkasex/mitkaforestsexOralCuml1_1.jpg";
        med[67] = "data/qwest/mitkasex/mitkaforestsexOralCum2_1.jpg";
        med[68] = "data/qwest/mitkasex/mitkaforestsexСowKiss1_1.jpg";
        med[69] = "data/qwest/mitkasex/mitkaforestsexСowOral1_1.jpg";
        med[70] = "data/qwest/mitkasex/mitkaforestsexСowOralCuml1_1.jpg";
        med[71] = "data/qwest/mitkasex/mitkaforestsexCow1_1.jpg";
        med[72] = "data/qwest/mitkasex/mitkaforestsexСowKiss1_2.jpg";
        med[73] = "data/qwest/mitkasex/mitkaforestsexСow1_2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[74] = "data/qwest/mitkasex/mitkaforestsexCow2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[75] = "data/qwest/mitkasex/mitkaforestsexCowCum1_1.jpg";
        med[76] = "data/qwest/mitkasex/mitkaforestsexCowCum1_2.jpg";
        med[77] = "data/qwest/mitkasex/mitkaforestsexDog1_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[78] = "data/qwest/mitkasex/mitkaforestsexDog1_2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[79] = "data/qwest/mitkasex/mitkaforestsexDog1_3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[80] = "data/qwest/mitkasex/mitkaforestsexDog2_1." + intQStr(getRandInt(1,2)) + ".jpg";
    }
    if(true)
    {
        med[81] = "data/qwest/mitkasex/mitkaforestsexDog2_2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[82] = "data/qwest/mitkasex/mitkaforestsexDogCum1_1.jpg";
        med[83] = "data/qwest/mitkasex/mitkaforestsexDogCum1_2.jpg";
        med[84] = "data/qwest/mitkasex/mitkaforestsexDogCum1_3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[85] = "data/qwest/mitkasex/mitkaforestsexSide1_1.jpg";
        med[86] = "data/qwest/mitkasex/mitkaforestsexSide1_2.jpg";
        med[87] = "data/qwest/mitkasex/mitkaforestsexSide2_1." + intQStr(getRandInt(1,2)) + ".jpg";
        med[88] = "data/qwest/mitkasex/mitkaforestsexSide2_2." + intQStr(getRandInt(1,2)) + ".jpg";
        med[89] = "data/qwest/mitkasex/mitkaforestsexSide2_3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[90] = "data/qwest/mitkasex/mitkaforestsexSideCum1_1.jpg";
        med[91] = "data/qwest/mitkasex/mitkaforestsexVag3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[92] = "data/qwest/mitkasex/mitkaforestsexAnal3." + intQStr(getRandInt(1,2)) + ".jpg";
        med[93] = "data/qwest/mitkasex/mitkaforestsexAnal3." + intQStr(getRandInt(3,4)) + ".jpg";
        med[94] = "data/qwest/mitkasex/mitkaforestsexAnal3." + intQStr(getRandInt(5,6)) + ".jpg";
        med[95] = "data/qwest/mitkasex/mitkaforestsexCum3.1.jpg";
        med[96] = "data/qwest/mitkasex/mitkaforestsexCum3.2.jpg";
        med[97] = "data/qwest/mitkasex/mitkaforestsexCum3.3.jpg";
    }
    return med[id];
}

void MitkaSex::setMitka()
{
    root->setBoyName(boy[0]);
    root->sVSex(silavag,boySilavag[0]);
    root->sVSex(dick,boyDick[0]);
}

void MitkaSex::setVasyan()
{
    root->setBoyName(boy[1]);
    root->sVSex(silavag,boySilavag[1]);
    root->sVSex(dick,boyDick[1]);
}

void MitkaSex::setKolyamba()
{
    root->setBoyName(boy[2]);
    root->sVSex(silavag,boySilavag[2]);
    root->sVSex(dick,boyDick[2]);
}

void MitkaSex::makeActBtn(QString action, QString actName)
{
    QActButton* btn = new QActButton(action);
    btn->setText(actName);
    connect(btn, &QActButton::sigAct, this, &MitkaSex::actionHandler);
    root->addActBtn(btn);
}
