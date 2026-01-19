#include "sex.h"
#include "../Functions.h"
#include "sexhandler.h"

Sex::Sex(SexHandler* parent): root(parent)
{
    m_protect = 0;
}

void Sex::sexStart()
{
    QString boy = root->getBoyName();

    if (boy.isEmpty()) { boy = "Парень"; }
    m_cc_sex_usecondom = 0;
    if (root->getVSexVar(vibratorIN) == 1)
    {
        root->setVSexVar(vibratorIN,0);
        root->m_render->addText("<br>Вы вынули вибратор из влагалища.");
    }
    if (root->getItemCount(iCondoms) > 0 && (root->getVSexVar(use_condoms) == 1 || root->getVSexVar(protect) == 1))
    {
        root->useItem(iCondoms, 1);
        m_protect = 1;
        root->updVSexVar(lubonus,1);
        m_cc_sex_usecondom = 1;
        root->m_render->addText(boy + " взял у вас презерватив и одел его на свой член.");
    }
    if (root->getVStatus(horny)/10 + root->getVBody(vagina) + root->getVAddict(alko) < root->getVSexVar(dick) && root->getItemCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->updVSexVar(lubonus,5);
        if(getRandInt(1,2) == 1)
        {
            root->m_render->addText("Вы выдавили лубрикант себе на руку и начали смазывать им свою вагину.");
        }
        else
        {
            root->m_render->addText("Выдавив лубрикант себе на руку, вы начали тщательно смазывать им свою вагину.");
        }
    } 
}

void Sex::analStart(ToolType type)
{
    QString boy = root->getBoyName();
    if (boy.isEmpty()) { boy = "Парень"; }
    
    m_cc_sex_usecondom = 0;
    QString final;
    if((root->getItemCount(iCondoms) > 0 && (root->getVSexVar(use_condoms) == 1) || root->getVSexVar(protect) == 1))
    {
        root->useItem(iCondoms, 1);
        m_protect = 1;
        m_cc_sex_usecondom = 1;
        root->updVSexVar(lubonus,1);
        root->m_render->addText(boy + " взял у вас презерватив и одел его на свой член.");
    }
    if(root->getVSexVar(analplugIN) == 1)
    {
        root->setVSexVar(analpluginbonus, 5);
        root->setVSexVar(analplugIN, 0);
        root->m_render->addText("Вы вытащили из вашей  попки анальную пробку.");
    }
    if(root->getItemCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->updVSexVar(lubonus, 10);
        final = "Вы выдавили анальной смазки себе на руку и начали намазывать свою попку. ";
        if(type == ToolType::tDick)
        {
            final += " После этого вы выдавили еще немного лубриканта на руку и начали смазывать им член.";
            final += boy + " был совсем не против и с легкой усмешкой наблюдал за вашими действиями.";
        }
        if(type == ToolType::tDildo || type == ToolType::tGirlDildo)
        {
            final += "После этого вы немного смазали дилдо.";
        }
        if(type == ToolType::tStrapon)
        {
            final += "После этого вы немного смазали дилдо.";
        }
        if(type == ToolType::tBottle || type == ToolType::tGirlBottle)
        {
            final += "После этого вы немного смазали бутылку.";
        }
        root->m_render->addText(final);
    }
}

void Sex::vaginal(ToolType type, QString pos)
{

    QString boy = root->getBoyName();

    if (boy.isEmpty()) { boy = "парень"; }
    if (root->getVStatus(cumPussy) > 0) root->updVSexVar(lubonus,2);
    if (root->getVSexVar(vibratorIN) == 1)
    {
        root->setVSexVar(vibratorIN,0);
        root->m_render->addText("Вы вынули вибратор из влагалища.");
    }
    QString result;
    if (root->getVBody(vagina) == 0)
    {
        root->setVStatus(lust,0);
        root->setVStatus(horny,0);
        root->updVStatus(mood, -15);
        emit root->setGape(vagina, root->getVStatus(horny),root->getVSexVar(dick),root->getVSexVar(silavag));
        QString str = "Вы закусили губу от боли и из глаз брызнули слезы когда ";
        QString str2 = " в вас, разорвав вашу девственную плеву. Вы заплакали от боли и ";
        if (type == tDick)
        {
            if (root->getVSexVar(pose) == 2)
                result = str + "сели на член и почувствовали как " + boy + " вошел" + str2 + " продолжили прыгать на крепком члене своей окровавленной киской.";
            else
                result = str + boy + " вошел в вас, разорвав вашу девственную плеву. Вы плачете и стонете пока крепкий член трахает вашу окровавленную киску.";
        }
        else if (type == tDildo)
            result = str + intQStr(root->getVSexVar(dick)) + " сантиметровый дилдо вошел" + str2 + " вынули из себя окровавленный дилдо.";
        else if (type == tStrapon)
            result = str + intQStr(root->getVSexVar(dick)) + "  сантиметровый страпон вошел" + str2 + boy + " вынула из вас окровавленный страпон.";
        else if (type == tBottle)
            result = str + "бутылка вошла" + str2 + "вынули из себя окровавленную бутылку.";
        else if (type == tGirlBottle)
            result = str + "бутылка вошла" + str2 + boy + " вынула из вас окровавленную бытылку.";
    }
    else if (root->getVStatus(mesec) > 0 && root->getVBody(vagina) > 0)
    {
        root->setVStatus(lust,0);
        root->setVStatus(horny,0);
        root->updVStatus(mood, -10);
        emit root->setGape(vagina,root->getVStatus(horny), root->getVSexVar(dick), root->getVSexVar(silavag));
        QString str0{"У вас месячные и в то время пока "}, str1{", из влагалища потихоньку вытекает кровь."}, str2{" Ощущения болезненные и неприятные. Вы стонете пока крепкий член "};
        if (type == tDick)
        {
            if(pos == "horse")
                result = str0 + "прыгаете на члене"+str1+str2+"входит в вас.";
            else
                result = str0 + "член таранит вас" + str1 + str2 + "входит в вас.";
        }
        else if (type == tDildo)
            result = str0 + "вы засовываете в себя " + intQStr(root->getVSexVar(dick)) + " сантиметровый дилдо" + str1;
        else if (type == tStrapon)
            result = str0 + boy + " вгоняет в вашу киску " + intQStr(root->getVSexVar(dick)) + "сантиметровый страпон" + str1;
        else if (type == tBottle)
            result = str0 + "вы засовываете в себя бутылку" + str1;
        else if (type == tGirlBottle)
            result = str0 + boy + " вгоняет в вашу киску бутылку" + str1;
    }
    else if (root->getVStatus(mesec) <= 0 && root->getVBody(vagina) > 0)
    {
        emit root->setGape(vagina,root->getVStatus(horny),root->getVSexVar(dick),root->getVSexVar(silavag));
        int hornyVal = root->getVStatus(horny);
        int prinat = hornyVal/10 + root->getVBody(vagina) + root->getVAddict(alko) + root->getVSexVar(lubonus);
        int dickVal = root->getVSexVar(dick);
        int silaVag = root->getVSexVar(silavag);
        int orgasm = 0;
        if(dickVal > prinat * 2)
        {
            if(silaVag == 0) orgasm = 0;
            if(silaVag == 1) orgasm = 1;
            if(silaVag == 2) orgasm = 2;
        }
        else if (dickVal < prinat * 2 && dickVal > prinat)
        {
            if(silaVag == 0)
            {
                if(hornyVal < 60) orgasm = 0;
                if(hornyVal >= 60 && hornyVal < 100) orgasm = hornyVal/10 - 5;
                if(hornyVal >= 100) orgasm = 5;
            }
            else if (silaVag == 1)
            {
                if(hornyVal < 50) orgasm = 0;
                if(hornyVal >= 50 && hornyVal < 90) orgasm = hornyVal/10 - 4;
                if(hornyVal >= 90) orgasm = 5;
            }
            else if (silaVag == 2)
            {
                if(hornyVal < 40) orgasm = 0;
                if(hornyVal >= 40 && hornyVal < 80) orgasm = hornyVal/10 - 3;
                if(hornyVal >= 80) orgasm = 5;
            }
        }
        else if (dickVal <= prinat && dickVal >= root->getVBody(vagina))
        {
            if(silaVag == 0)
            {
                if(hornyVal < 40) orgasm = 2;
                if(hornyVal >= 40 && hornyVal < 80) orgasm = hornyVal/20 + 1;
                if(hornyVal >= 80) orgasm = 5;
            }
            else if(silaVag == 1)
            {
                if(hornyVal < 30) orgasm = 2;
                if(hornyVal >= 30 && hornyVal < 70) orgasm = (hornyVal + 10)/20 + 1;
                if(hornyVal >= 70) orgasm = 5;
            }
            else if(silaVag == 2)
            {
                if(hornyVal < 20) orgasm = 2;
                if(hornyVal >= 20 && hornyVal < 60) orgasm = hornyVal/20 + 2;
                if(hornyVal >= 60) orgasm = 5;
            }
        }
        else if (dickVal <= prinat && dickVal < root->getVBody(vagina))
        {
            if(silaVag == 0)
            {
                if(hornyVal >= 100) orgasm = 5;
                if(hornyVal >= 90 && hornyVal < 100) orgasm = 4;
                if(hornyVal < 90) orgasm = 6;
            }
            else if(silaVag == 1)
            {
                if(hornyVal >= 90) orgasm = 5;
                if(hornyVal >= 80 && hornyVal < 90) orgasm = 4;
                if(hornyVal < 80) orgasm = 6;
            }
            else if(silaVag == 2)
            {
                if(hornyVal >= 80) orgasm = 5;
                if(hornyVal >= 70 && hornyVal < 80) orgasm = 4;
                if(hornyVal < 70) orgasm = 6;
            }
        }
        if (orgasm == 0)
        {
            root->setVStatus(lust,0);
            root->setVStatus(horny,0);
            root->updVStatus(mood, -15);
            if(root->getVBody(makeup) > 1)
            {
                root->setVBody(makeup,0);
                root->updVStatus(vidageday, -1);
            }
            QString str0{"Вы застонали от боли когда "},
                str1{", из глаз потекли слезы и между ног ощущение как будто вам вогнали раскаленный прут."};
            if(type == tDick)
            {
                if(pos == "horse")
                    result = str0 + "сели на член и почувствовали как " + boy + " вошел в вас своим членом" + str1;
                else
                    result = str0 + boy + " вошел в вас" + str1 + "Вы плачете и стонете пока крепкий член трахает вашу киску.";
            }
            else if(type == tDildo)
                result = str0 + "засунули в себя дилдо" + str1;
            else if(type == tStrapon)
                result = str0 + boy + " засунула в вас страпон" + str1;
            else if(type == tBottle)
                result = str0 + "засунули в себя бутылку" + str1;
            else if(type == tGirlBottle)
                result = str0 + boy + " засунула в вас бутылку" + str1;
        }
        else if (orgasm == 1)
        {
            root->updVStatus(horny, -10);
            root->updVStatus(mood,-10);
            QString str0{"Вы закусили губу от боли когда "},
                str1{", между ног болезненные ощущения."};
            if(type == tDick)
            {
                if(pos == "horse")
                    result = str0 + "сели на член и почувствовали как " + boy + " вошел в вас" + str1 + " Вы морщитесь и стонете от боли пока прыгаете на крепком члене.";
                else
                    result = str0 + boy + " вошёл в вас" + str1 + " Вы морщитесь и стонете от боли пока крепкий член трахает вашу киску.";
            }
            else if (type == tDildo)
                result = str0 + "засунули в себя " + intQStr(dickVal) + " сантиметровый дилдо" + str1;
            else if (type == tStrapon)
                result = str0 + boy + " засунула в вас " + intQStr(dickVal) + " сантиметровый страпон" + str1;
            else if (type == tBottle)
                result = str0 + "засунули в себя бутылку" + str1;
            else if (type == tGirlBottle)
                result = str0 + boy + " засунула в вас бутылку" + str1;
        }
        else if (orgasm == 2)
        {
            root->updVStatus(horny,-5);
            root->updVStatus(mood,-5);
            QString str0{"Вы вздрогнули от внезапной боли когда "},
                str1{", но болезненные ощущения между ног плавно успокаиваются и становятся вполне сносными. Вы пытаетесь возбудиться пока "},
                str2{" в вашей киске, но у вас ничего не выходит."};
            if(type == tDick)
            {
                if(root->getVSexVar(pose) == 2)
                    result = "";
                else
                    result = "";
            }
            else if (type == tDildo)
                result = "";
            else if (type == tStrapon)
                result = "";
            else if (type == tBottle)
                result = "";
            else if (type == tGirlBottle)
                result = "";
        }
        else if (orgasm == 3)
        {
            root->updVStatus(mood,5);
            root->updVStatus(horny,5);
            QString str0{"Вы вздрогнули от ощущения, что ваша киска растягивается, когда "},
                str1{" Между ног становится немного приятно, когда "};
            if(type == tDick)
            {
                if(pos == "horse")
                    result = str0 + "сели на член и почувствовали как " + boy + " вошел в вас." + str1 + "вы прыгаете на крепком члене";
                else
                    result = str0 + boy + " вошел в вас" + str1 + "крепкий член трахает вашу киску.";
            }
            else if (type == tDildo)
                result = str0 + "засунули в себя дилдо. " + str1 + "вы трахаете себя при помощи дилдо.";
            else if (type == tStrapon)
                result = str0 + boy + " засунула в вас страпон" + str1 + boy + " трахает вас страпоном.";
            else if (type == tBottle)
                result = str0 + "засунули в себя бутылку" + str1 + "вы трахаете себя при помощи бутылки.";
            else if (type == tGirlBottle)
                result = str0 + boy + " засунула в вас бутылку" + str1 + boy + " трахает вас бутылкой.";
        }
        else if (orgasm == 4)
        {
            root->updVStatus(mood,10);
            root->updVStatus(horny,10);
            QString str0{"Вы вздрогнули от ощущения, что ваша киска растягивается, когда "},
                str1{". Между ног становится немного приятно, когда "},
                str2{". Постепенно приятное тепло и пульсация нарастают в низу живота, потом ощущения чуть уменьшаются и остаются до конца."};
            if(type == tDick)
            {
                if(pos == "horse")
                    result = str0 + "сели на член и почувствовали как " + boy + "вошел в вас" + str1 + "вы прыгаете на крепком члене" + str2;
                else
                    result = str0 + boy + " вошел в вас" + str1 + "крепкий член трахает вашу киску" + str2;
            }
            else if (type == tDildo)
                result = str0 + "засунули в себя " + intQStr(dickVal) + " свнтиметровый дилдо" + str1 + "вы трахаете себя при помощи дилдо" + str2;
            else if (type == tStrapon)
                result = str0 + boy + " засунула в вас " + intQStr(dickVal) + " сантиметровый страпон" + str1 + boy + " трахает вас при помощи страпона" + str2;
            else if (type == tBottle)
                result = str0 + "засунули в себя бутылку" + str1 + "вы трахаете себя при помощи бутылки" + str2;
            else if (type == tGirlBottle)
                result = str0 + boy + " засунула в вас бутылку" + str1 + boy + " трахает вас при помощи бутылки" + str2;
        }
        else if (orgasm == 5)
        {
            root->setVStatus(lust,0);
            root->setVStatus(horny,0);
            root->setVStatus(mood,100);
            root->updVSC(SC::orgasm,1);
            root->updVSC(SC::vaginalOrgasm,1);
            root->setVBody(hairStatus,0);
            QString str0{"Вы вздрогнули от приятного ощущения, когда ваша киска начала растягиваться принимая в себя "},
                str1{". Между ног становится очень тепло и приятно, когда "},
                str2{" двигается в вашей киске. Постепенно приятное тепло и пульсация нарастают в низу живота, потом ощущения обрушиваются на вас и всё ваше тело охватывают горячие волны оргазма, вы невольно кричите от удовольствия извиваясь на "};
            if(type == tDick)
                result = str0 + "член" + str1 + "крепкий член" + str2 + "елде.";
            else if (type == tDildo)
                result = str0 + "дилдо" + str1 + intQStr(dickVal) + " сантиметровый дилдо" + str2 + "дилдо";
            else if (type == tStrapon)
                result = str0 + "страпон" + str1 + "крепкий " + intQStr(dickVal) + " сантиметровый страпон" + str2 + "страпоне.";
            else if (type == tBottle || type == tGirlBottle)
                result = str0 + "бутылку" + str1 + "бутылка" + str2 + "бутылке.";
        }
        else if (orgasm == 6)
        {
            root->updVStatus(horny,5);
            root->updVStatus(mood,5);
            QString str0;
            QString str1;
            if(type == tDick) { str0 = "член"; str1 = "его"; }
            else if (type == tDildo) { str0 = "дилдо"; str1 = "его"; }
            else if (type == tStrapon) { str0 = "страпон"; str1 = "его"; }
            else if (type == tBottle || type == tGirlBottle)  { str0 = "бутылка"; str1 = "её"; }
            result = "Вы почувствовали как " + str0 + " проникает в вашу киску. Между ног приятно, но " + str0 + " значительно меньше вашей киски и " + str1 + " для вас мало.**Постепенно приятное тепло и пульсация нарастают в низу живота, потом ощущения чуть уменьшаются и остаются до конца.";
        }
    }
    root->setVSexVar(lubonus,0);
    if(pos.isEmpty())
        root->updVSC(SC::vaginalSex, 1);
    if(type != tDick)
        m_protect = 0;
    root->m_render->addText(result);
}

void Sex::anal(ToolType type)
{
    QString boy = root->getBoyName();

    QString result, tmp0, tmp1;
    if (root->getVSexVar(analplugIN) == 1)
    {
        root->setVSexVar(analpluginbonus,5);
        root->setVSexVar(analplugIN,0);
        tmp0 = "Вы вытащили из вашей  попки анальную пробку.";
        if (type == tDick)
        {
            if (boy.isEmpty()) { boy = "Парень"; }
            result = boy + "вытащил из вашей попки анальную пробку";
        }
        else if (type == tDildo || type == tGirlDildo || type == tStrapon || type == tBottle || type == tGirlBottle)
            result = tmp0;
    }
    tmp0 = " массировать анальное отверстие пальцами, сначала одним, потом двумя.";
    tmp1 = "Вы раздвинув свои ягодицы стали";
    if(type == tDick)
    {
        if (boy.isEmpty()) { boy = "Парень"; }
        result = boy + "раздвинув ваши ягодицы стал" + tmp0;
    }
    else if(type == tDildo || type == tBottle)
        result = tmp1 + tmp0;
    else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
    {
        if (boy.isEmpty()) { boy = "Няшка"; }
        result = boy + " раздвинув ваши ягодицы стала" + tmp0;
    }

    if (root->getVStatus(cumAnus) > 0) root->updVSexVar(lubonus,2);
    if (root->getVBody(anus) >= 10)
    {
        tmp0 = "Потом вы ввели себе три пальца и начали растягивать анус.";
        if(type == tDick)
        {
            if (boy.isEmpty()) { boy = "парень"; }
            result += "Потом " + boy + " ввел вам три пальца и начал растягивать ваш анус.";
        }
        else if(type == tDildo || type == tBottle)
            result += tmp0;
        else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
        {
            if (boy.isEmpty()) { boy = "Няшка"; }
            result += "Потом " + boy + " ввела вам три пальца и начала растягивать анус.";
        }
    }
    else
    {
        result += "Когда в вашу попку вошло три пальца вы невольно застонали от боли.";
    }
    tmp0 = "Вы вытащили пальцы из своей попы и приставили ";
    if (type == tDick)
    {
        if (boy.isEmpty()) { boy = "Парень"; }
        result += boy + " вытащил пальцы из вашей попы и вы почувствовали как его твердый член уперся в вашу дырочку.";
    }
    else if (type == tDildo) result += tmp0 + "дилдо к своей дырочке.";
    else if (type == tBottle) result += tmp0 + "бутылку к своей дырочке.";
    else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo) 
    {
        if (boy.isEmpty()) { boy = "Няшка"; }
        result += boy + "вытащила пальцы из вашей попы и приставила ";
        if(type == tStrapon) result += "страпон";
        else if (type == tGirlBottle) result += "бутылку";
        else if (type == tGirlDildo) result += "дилдо";
        result += " к вашей дырочке.";   
    }
    int anusCapab = root->getVBody(anus) + root->getVSexVar(lubonus) + root->getVSexVar(analpluginbonus) + root->getVAddict(alko);
    if (anusCapab < root->getVSexVar(dick))
    {
        tmp0 = "Вы взвизгнули и закусили губы от резкой боли когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметровый страпон" + tmp1;
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылка" + tmp1;
    }
    else if(anusCapab >= root->getVSexVar(dick))
    {
        tmp0 = "Вы застонали от чувства переполненности когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметровый страпон" + tmp1;
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылка" + tmp1;
    }
    tmp0 = " попе приспособится к торчащему в ней ";
    tmp1 = " водить им всё настойчивей, растягивая ваш анус.";
    if(type == tDick)
    {
        if (boy.isEmpty()) { boy = "Парень"; }
        result += boy + " замер на минуту, давая вашей" + tmp0 + "члену, после чего начал" + tmp1;
    }
    else if(type == tDildo) result += "Вы замерли на минуту, давая своей" + tmp0 + "дилдо, после чего начали" + tmp1;
    else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
    {
        result += boy + " замерла на минуту, давая вашей" + tmp0;
        if (type == tStrapon) result += "страпону";
        else if(type == tGirlBottle) result += "горлышку бутылки";
        else if(type == tGirlDildo) result += "дилдо";
        result += ", после чего начала" + tmp1;
    }
    else if(type == tBottle) result += "Вы замерли на минуту, давая своей" + tmp0 + " горлышку бутылки, после чего начали водить ей все настойчивей, растягивая свой анус.";
    if (root->getVSexVar(lubonus) > 0)
    {
        root->setGape(anus,10, root->getVSexVar(dick),root->getVSexVar(silavag));
    }
    else
    {
        root->setGape(anus,0, root->getVSexVar(dick),root->getVSexVar(silavag));
    }
    if (anusCapab < root->getVSexVar(dick))
    {
        if (root->getVBody(makeup) > 1) root->setVBody(makeup,0);
        root->updVStatus(vidageday, -1);
        root->updVStatus(horny, -20);
        root->updVStatus(mood, -20);
        tmp0 = "Вашу попу пронзила острая боль когда ";
        if(type == tDick) result += tmp0 + "член начал трахать её на полную силу. В попе всё горит огнем и вы мечтаете только о том, чтобы эта пытка побыстрее кончилась.";
        else if(type == tDildo) result += tmp0 + "вы начали двигать в своей попе " + intQStr(root->getVSexVar(dick)) + " сантиметровый дилдо.";
        else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
        {
            result += boy + "  начала трахать вашу попу при помощи ";
            if (type == tStrapon)
            {
                result += intQStr(root->getVSexVar(dick)) + " сантиметрового страпона.";
            }
            else if(type == tGirlBottle) result += "бутылки.";
            else if(type == tGirlDildo) result += intQStr(root->getVSexVar(dick)) + " сантиметрового дилдо.";
        }
        else if(type == tBottle)
            result += tmp0 + "вы начали двигать в своей попе бутылку.";
    }
    else if (anusCapab >= root->getVSexVar(dick))
    {
        root->updVStatus(horny, 10);
        tmp0 = "Вы начали ритмично стонать в такт движениям ";
        tmp1 = " Вы чувствуете как ваш анус растягивается когда ";
        if(type == tDick) result += tmp0 + "члена внутри вас." + tmp1 + "член входит в вас.";
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметрового дилдо внутри вас." + tmp1 + "дилдо двигается внутри попки.";
        else if (type == tStrapon) result += tmp0 + intQStr(root->getVSexVar(dick)) + " сантиметрового страпона внутри вас." + tmp1 + "страпон двигается внутри попки.";
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылки внутри вас." + tmp1 + "бутылка двигается внутри попки.";
        if (root->getVStatus(horny) >= 100 && root->getVBody(anus) >= 10 && root->getVSC(orgasm) > 0)
        {
            root->setVStatus(mood, 100);
            root->updVSC(orgasm, 1);
            root->updVSC(analOrgasm, 1);
            root->setVStatus(horny, 0);
            root->setVStatus(lust, 0);
            root->setVBody(hairStatus, 0);
            tmp0 = "Вам становится очень приятно, когда ";
            tmp1 = " движется внутри вашей попки. В анусе полыхает пожар и волны удовольствия охватывают ваше тело. Вы стонете и сами насаживаетесь попкой на член, сотрясаясь от охватившего вас оргазма.";
            if (type == tDick)
                result += tmp0 + "член" + tmp1;
            else if (type == tDildo || type == tGirlDildo)
                result += tmp0 + "дилдо" + tmp1;
            else if (type == tStrapon)
                result += tmp0 + "страпон" + tmp1;
            else if (type == tBottle || type == tGirlBottle)
                result += tmp0 + "бутылка" + tmp1;
        }
    }
    root->setVSexVar(lubonus,0);
    root->setVSexVar(analpluginbonus,0);
    root->m_render->addText(result);
}

void Sex::cum(QString target)
{
    if(target == "cumfrot")
        root->updVStatus(cumFrot,getRandInt(1,2));
    if(target == "face")
    {
        root->updVStatus(cumFace,getRandInt(1,2));
        root->updVSC(facialCum,getRandInt(1,2));
    }
    if(target == "lip")
        root->updVStatus(cumLips,getRandInt(1,2));
    if(target == "belly")
        root->updVStatus(cumBelly,getRandInt(2,3));
    if(target == "ass")
        root->updVStatus(cumAss,getRandInt(2,3));
    if(target == "pussy")
    {
        if(root->getVSexVar(protect) == 1)
        {
            bool defcondom = false;
            if(root->getVSexVar(use_condoms) == 1 && root->getItemCount(iCondoms) > 0)
            {
                defcondom = root->condomDefense();
            }
            if((root->getVStatus(pregnancyKnow) > 0 && root->getItemCount(iCondoms) == 0) ||
                (root->getVStatus(pregnancyKnow) > 0 && root->getItemCount(iCondoms) > 0 && defcondom == false))
            {
                root->m_render->addText("<br>Вы усмехнулись про себя, ну по крайней мере вы не залетите.");
                root->setVStatus(cumPussy,getRandInt(3,4));
            }
            else if((root->getVStatus(mesec) > 0 && root->getItemCount(iCondoms) == 0) ||
                       (root->getVStatus(mesec) > 0 && root->getItemCount(iCondoms) > 0 && defcondom == false))
            {
                root->m_render->addText("<br>\"- Хорошо, что месячные, хоть не залечу...\", - с облегчением подумали вы.");
                root->chanceOfPreg();
                root->setVStatus(cumPussy,getRandInt(3,4));            }
            else if(root->getVSexVar(use_anti_preg_pills) == 1 && root->getItemCount(iAntiPregPills) > 0)
            {
                root->m_render->addText("<br>\\\"- Хорошо, что месячные, хоть не залечу...\"///, - с облегчением подумали вы.");
                root->chanceOfPreg();
                root->setVStatus(cumPussy,getRandInt(3,4));
            }
            else if(root->getItemCount(iCondoms) > 0 && defcondom == false)
            {
                root->updVStatus(mood, -25);
                root->m_render->addText("<br>\\\"- Блин, бля... залететь же так можно!\"///, - подумали вы с ужасом, смотря на порваный презерватив.");
                root->chanceOfPreg();
                root->setVStatus(cumPussy,getRandInt(3,4));
            }
            else if (root->getItemCount(iCondoms) > 0 && defcondom == true)
            {
                root->setVStatus(cumPussy,0);
            }
            else if(root->getItemCount(iCondoms) == 0)
            {
                root->updVStatus(mood, -15);
                root->m_render->addText("<br>\\\"- Черт, так ведь и залететь можно\"///, - подумали вы с ужасом.");
                root->chanceOfPreg();
                root->setVStatus(cumPussy,getRandInt(3,4));
            }
        }
        else
        {
            if(root->getVStatus(pregnancyKnow) > 0)
            {
                root->m_render->addText("<br>Вы усмехнулись про себя, ну по крайней мере вы не залетите.");
            }
            else if(root->getVStatus(mesec) > 0)
            {
                root->m_render->addText("<br>\\\"- Хорошо, что месячные, хоть не залечу...\"///, - с облегчением подумали вы.");
            }
            else if(root->getItemCount(iAntiPregPills) > 0 && root->getVSexVar(use_anti_preg_pills) == 1)
            {
                root->m_render->addText("<br>\\\"- Надеюсь таблетки помогут\"///, - подумали вы.");
            }
            else
            {
                root->m_render->addText("<br>\\\"- Черт, так ведь и залететь можно\"///, - подумали вы с ужасом.");
            }
            root->chanceOfPreg();
            root->setVStatus(cumPussy,getRandInt(3,4));
        }
    }
    if(target == "anus")
    {
        root->setVStatus(cumAnus,getRandInt(3,4));
    }
}

void Sex::sex_cum()
{
    QString boy = root->getBoyName();
    if(boy.isEmpty())
        boy = "Парень";
    if(m_protect == 0)
    {
        if(getRandInt(1,4) != 1)
        {
            QString str[3];
            str[0] = "Наконец движения парня ускоряются и, загнав напоследок по самые яйца, с блаженной улыбкой он кончил глубоко в вас. "
                     "Вы ощутили как теплая жикдость разливается по вашим внутренностям.";
            str[1] = boy + " не стал тянуть и кончил прямо в вас так, что из вашей  вагины с чавканьем вылетели брызги спермы.";
            str[2] = boy + " застонал и вы почувствовали как струя спермы ударила вам внутрь вашего тела.";
            root->m_render->addText(str[getRandInt(0,2)]);
            cum("pussy");
        }
        else
        {
            if(pose == 0)
            {
                cum("belly");
                root->m_render->addText(boy + " застонал и вынув член из вас, кончил на ваш живот.");
            }
            else
            {
                cum("ass");
                root->m_render->addText(boy + " застонал и вынув член из вас, кончил на вашу попу.");
            }
        }
    }
    else
    {
        bool defcondom = root->condomDefense();
        if(defcondom == true)
        {
            root->m_render->addText(boy + " застонал и вы поняли, что он кончил в презерватив.");
        }
        else
        {
            m_protect = 0;
            root->m_render->addText("Вынув из вас член " + boy + " сказал:- Хмм, презерватив лопнул...");
            cum("pussy");
        }
    }
}

void Sex::anal_cum()
{
    QString boy = root->getBoyName();
    if(boy.isEmpty())
        boy = "Парень";
    if(m_protect == 0)
    {
        QString str[] {
            "Наконец он ускоряется и, загнав напоследок по самые яйца, кончил глубоко в вас. Вы ощутили как теплая жикдость разливается по вашим внутренностям.",
            boy + "не стал тянуть и кончил в вашу " + root->getAnusTipe2() + " попу, заливая внутренности своим вязким семенем.",
            "Через некоторое время " + boy + " застонал и вы почувствовали как вашу попу наполняет тепло."
        };
        root->m_render->addText(str[getRandInt(0,2)]);
        cum("anus");
    }
    else
    {
        bool defcondom = root->condomDefense();
        if(defcondom == true)
        {
            root->m_render->addText(boy + " застонал и вы поняли, что он кончил в презерватив.");
        }
        else
        {
            m_protect = 0;
            root->m_render->addText("Вынув из вашей попки член " + boy + " сказал:- Хмм, презерватив лопнул...");
            cum("anus");
        }
    }
}

void Sex::blow_job()
{
    root->updVStatus(lipkoef,1);
    if(root->getVStatus(lipkoef) > 50)
    {
        root->setVStatus(lipkoef,0);
        root->updVBody(lip,1);
    }
    QString boy = root->getBoyName();
    if(boy.isEmpty())
        boy = "Парень";
    QString add;
    if(root->getVSexVar(dick) >= root->getVBody(throat))
        add = "от ударов члена в горло у вас потекли слезы из глаз.";
    else
        add = "но ваше горло уже достаточно тренировано, и поэтому вы только пошире открываете рот, давая " + boy + " полный доступ.";
    QString str[] = {
        "Вы обхватили своими " + root->getLipTalk() + " его член. ",
        "Вы обхватили своими " + root->getLipTalk() + " багровую головку его члена.",
        "Вы провели своими " + root->getLipTalk() + " по головке члена и вобрали его в свой ротик.",
        "Его член уперся вам в ваши " + root->getLipTalk() + ", вы приоткрыли их и впустили член в свой рот.",
        "Ваш ротик оказался быстро заполнен чуть солоноватым и твердым членом который вы начали сосать. ",
        "В ваш ротик вошел твердый и горячий член который вы начали сосать. ",
        "Твердый член заполнял весь ваш рот, обхватывая его губами вы каждым движением его вбирали до горла. ",
        boy + " закрыл глаза от удовольствия и наслаждается лаской ваших губ.",
        boy + " смотрит вам в лицо пока ваши губы скользят по его напряженному члену.",
        boy + " взял вас за волосы и стал трахать вас в рот, " + add
    };
    int a = getRandInt(0,3);
    int b = getRandInt(4,6);
    root->m_render->addText(str[a] + str[b] + str [b+3]);
    if(b == 6 && root->getVSexVar(dick) >= root->getVBody(throat))
    {
        if(root->getVBody(makeup) > 1)
        {
            root->setVBody(makeup,0);
            root->updVStatus(vidageday,-1);
        }
        root->updVBody(throat,1);
    }
    if(root->getVStatus(horny) >= 100 && root->getVSC(swallow) >= 100)
    {
        root->updVSC(orgasm,1);
        root->setVStatus(horny,0);
        root->setVStatus(lust,0);
        root->updVStatus(mood,15);
        root->m_render->addText("Неожиданно для вас отсасывая член вы начали кончать сами. Между ног полыхал пожар и волны удовольствия охватывали тело, вы стонали но не выпускали член изо рта продолжая его отсасывать.");
    }
}

void Sex::fnswallow()
{
    root->updVSC(swallow,1);
    cum("lip");
    root->updVStatus(water,-1);
    QString str[] {
        "Внезапно в ваш рот стрельнула струя вязкого семени. ",
        "Член дернулся и струя спермы влетела между ваших губ вам в рот. ",
        "Ваш рот наполнился спермой когда член между ваших губ начал кончать. ",
        "Ваш ротик быстро заполнился теплой спермой и вы чувствовали ее резкий вкус. ",
        "Сперма наполнила ваш рот и стала стекать по вашим " + root->getLipTalk2() + ". ",
        "Горячее семя быстро наполнило ваш рабочий рот заставляя прочувствовать всю гамму вкуса терпкой и резкой спермы. ",
        "Вы сглотнули и проглотили сперму находящуюся в вашем рабочем ротике. Во рту остался вкус спермы и чувствовался ее запах.",
        "Вы проглотили теплую сперму наполнявшую ваш рот и облизали свои " + root->getLipTalk3() + " слизывая остатки семени с них.",
        "Вы проглотили вязкую сперму заполнявшую ваш рабочий рот, после чего облизнулись."
    };
    root->m_render->addText(str[getRandInt(0,2)] + str[getRandInt(3,5)] + str[getRandInt(6,8)]);
}

void Sex::dp_start()
{
    QString boy;
    if(root->getBoyName().isEmpty())
        boy = "Парень";
    else
        boy = root->getBoyName();
    m_cc_sex_usecondom = 0;
    if(root->getVSexVar(use_condoms) == 1 && root->getVSexVar(protect) == 1 && root->getItemCount(iCondoms) > 0)
    {
        root->useItem(iCondoms,1);
        m_cc_sex_usecondom = 1;
        root->updVSexVar(lubonus_v,1);
        root->m_render->addText(boy + "взял у вас презерватив и одел его на свой член.");
    }
    if(root->getVSexVar(analplugIN) == 1)
    {
        root->setVSexVar(analpluginbonus,5);
        root->setVSexVar(analplugIN,0);
        root->m_render->addText("Вы вытащили из вашей  попки анальную пробку.");
    }
    if(root->getItemCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->updVSexVar(lubonus_a,5);
        root->m_render->addText("Выдавив анальной смазки себе на руку, вы начали смазывать им свою попку. После этого вы выдавили еще немного лубриканта на руку и начали смазывать им член." + boy + " был совсем не против и с легкой усмешкой наблюдал за вашими действиями.");
    }
    if(root->getVStatus(horny) / 10 + root->getVBody(vagina) + root->getVAddict(alko) < root->getVSexVar(dick) && root->getItemCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->updVSexVar(lubonus_v,5);
        if(getRandInt(1,2) == 1)
            root->m_render->addText("Вы выдавили лубрикант себе на руку и начали намазывать парню член.");
        else
            root->m_render->addText("Парень взял у вас тюбик с лубрикантом и смазал свой член смазкой.");
    }
}

void Sex::double_penetration()
{
    if(root->getVSexVar(analplugIN) == 1)
    {
        root->setVSexVar(analpluginbonus,5);
        root->setVSexVar(analplugIN,0);
        root->m_render->addText(root->getBoy2Name() + " вытащил из вашей  попки пробку.");
    }
    if(root->getVStatus(cumAnus) > 0)
        root->updVSexVar(lubonus_a,2);
    if(root->getVStatus(cumPussy) > 0)
        root->updVSexVar(lubonus_v,2);
    root->setGape(vagina, root->getVStatus(horny), root->getVSexVar(dick), root->getVSexVar(silavag));
    int bonus;
    if(root->getVSexVar(lubonus_a) > 0)
        bonus = 10;
    else
        bonus = 0;
    root->setGape(anus,bonus,root->getVSexVar(dick2),root->getVSexVar(silavag));
    int capab = root->getVStatus(horny) / 10 + root->getVBody(vagina) + root->getVAddict(alko) + root->getVSexVar(lubonus_v);
    if(root->getVBody(vagina) == 0)
    {
        root->setVStatus(lust,0);
        root->setVStatus(horny,0);
        root->updVStatus(mood, -15);
        QString boy, boy2;
        if(root->getBoyName().isEmpty())
            boy = "парень";
        else
            boy = root->getBoyName();

        if(root->getBoy2Name().isEmpty())
            boy2 = "парень";
        else
            boy2 = root->getBoy2Name();

        QString add = "";
        if(root->getVBody(vagina) == 0)
            add = "окровавленное";
        root->m_render->addText("Вы закусили губу от боли и из глаз брызнули слезы когда " + boy + " вошел в вас, разорвав вашу девственную плеву.");
        if(root->getVStatus(mesec) > 0 && root->getVBody(vagina) > 0)
        {
            root->setVStatus(lust,0);
            root->setVStatus(horny,0);
            root->updVStatus(mood, -10);
            root->m_render->addText("У вас месячные и вам неприятно и больно, пока член первого парня таранит вашу кровоточащую вагину. Одновременно вы чувствуете как ваш " + root->getAnusTipe() + " анус трахает второй член.");
        }
        int pain = root->getVSexVar(stat_agape) + root->getVSexVar(stat_vgape);
        if(pain == 0)
        {
            root->m_render->addText("Ощущения сливаются воедино, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Внизу живота горит приятный огонек распространяя тепло по всему телу.");
            int DPplus = root->getVSC(vaginalOrgasm) * 10 + root->getVStatus(horny) + root->getVStatus(mood);
            int DPmminus = getRandInt(250,350);
            if(DPplus > DPmminus)
            {
                root->updVSC(vaginalOrgasm,1);
                root->updVSC(DualPenetrationOrgasm,1);
                root->updVSC(orgasm,1);
                root->setVStatus(mood,100);
                root->setVStatus(lust,0);
                root->setVStatus(horny,0);
                root->setVBody(hairStatus,0);
                root->m_render->addText("Внезапно вас охватывает оргазм и вы, не помня себя, стонете и кричите, пока ваши мышцы судорожно сокращаются вокруг двух членов внутри вашего тела.");
            }
        }
        else if(pain == 1)
        {
            root->m_render->addText("Ощущения сливаются воедино, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Немного больно, но все же очень приятно чувствовать как все свободные отверстия заполняются членами.");
        }
        else if(pain == 2)
        {
            root->setVStatus(horny,root->getVStatus(horny)/2);
            root->setVStatus(mood,root->getVStatus(mood)/2);
            root->m_render->addText("Вы чуствуете себя так, как будто вот-вот готовы лопнуть от переполненности, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Ощущения очень странные, в один клубок смешалась боль, удовольствие и болезненная переполненность.");
        }
        else if (pain == 3)
        {
            root->setVStatus(horny,root->getVStatus(horny)/4);
            root->setVStatus(mood,root->getVStatus(mood)/4);
            root->m_render->addText("Вам больно и иногда резкие вспышки боли заставляют вас застонать, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалищеи ваш " + root->getAnusTipe() + " анус. Вы чувствуете себя готовой лопнуть, ваша попа и киска по ощущениям слились в один довольно болезненный комок. Ваши глаза не произвольно застилает пелена слез.");
        }
        else
        {
            root->setVStatus(mood,0);
            root->setVStatus(lust,0);
            root->setVStatus(horny,0);
            if(root->getVBody(makeup) > 1)
            {
                root->setVBody(makeup,0);
                root->updVStatus(vidageday,-1);
            }
            QString add = "";
            if(root->getVBody(vagina) == 0)
                add = "в окровавленное";
            else
                add = "во";
            root->m_render->addText("Вы визжите и слезы ручьем льются из ваших глаз от жуткой боли, весь ваш низ живота и попа отдает острой болью, пока вас трахает " + boy + " " + add + " влагалище и " + boy2 + " практически рвет ваш " + root->getAnusTipe() + " анус своим орудием.");
        }
        root->updVSC(vaginalSex,1);
        root->updVSC(analSex,1);
        root->setVSexVar(lubonus_a,0);
        root->setVSexVar(lubonus_v,0);
        root->setVSexVar(protect,0);
    }
}
