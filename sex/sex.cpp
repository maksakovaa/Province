#include "sex.h"
#include "../Functions.h"
#include "../game.h"

Sex::Sex(Game* parent): root(parent)
{
    m_protect = 0;
}

void Sex::rand_cum(int min)
{
    QString str[4];
    str[0] = "cumfrot";
    str[1] = "lip";
    str[2] = "face";
    str[3] = "belly";
    cum(str[getRandInt(min,3)]);
}

void Sex::sexStart()
{
    QString boy = root->getBoyName();

    if (boy.isEmpty()) { boy = "Парень"; }
    m_cc_sex_usecondom = 0;
    if (root->vSex(vibratorIN) == 1)
    {
        root->vSex(vibratorIN) = 0;
        root->addText("<br>Вы вынули вибратор из влагалища.");
    }
    if (root->getItmCount(iCondoms) > 0 && (root->vSex(use_condoms) == 1 || root->vSex(protect) == 1))
    {
        root->useItem(iCondoms, 1);
        m_protect = 1;
        root->vSex(lubonus) += 1;
        m_cc_sex_usecondom = 1;
        root->addText(boy + " взял у вас презерватив и одел его на свой член.");
    }
    if (root->vStatus(horny)/10 + root->vBody(vagina) + root->vAddict(alko) < root->vSex(dick) && root->getItmCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->vSex(lubonus) += 5;
        if(getRandInt(1,2) == 1)
        {
            root->addText("Вы выдавили лубрикант себе на руку и начали смазывать им свою вагину.");
        }
        else
        {
            root->addText("Выдавив лубрикант себе на руку, вы начали тщательно смазывать им свою вагину.");
        }
    } 
}

void Sex::analStart(ToolType type)
{
    QString boy = root->getBoyName();
    if (boy.isEmpty()) { boy = "Парень"; }
    
    m_cc_sex_usecondom = 0;
    QString final;
    if((root->getItmCount(iCondoms) > 0 && (root->vSex(use_condoms) == 1) || root->vSex(protect) == 1))
    {
        root->useItem(iCondoms, 1);
        m_protect = 1;
        m_cc_sex_usecondom = 1;
        root->vSex(lubonus) += 1;
        root->addText(boy + " взял у вас презерватив и одел его на свой член.");
    }
    if(root->vSex(analplugIN) == 1)
    {
        root->vSex(analpluginbonus) = 5;
        root->vSex(analplugIN) = 0;
        root->addText("Вы вытащили из вашей  попки анальную пробку.");
    }
    if(root->getItmCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->vSex(lubonus) += 10;
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
        root->addText(final);
    }
}

void Sex::vaginal(ToolType type, QString pos)
{

    QString boy = root->getBoyName();

    if (boy.isEmpty()) { boy = "парень"; }
    if (root->vStatus(cumPussy) > 0) root->vSex(lubonus) += 2;
    if (root->vSex(vibratorIN) == 1)
    {
        root->vSex(vibratorIN) = 0;
        root->addText("Вы вынули вибратор из влагалища.");
    }
    QString result;
    if (root->vBody(vagina) == 0)
    {
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatus(mood) -= 15;
        emit root->setGape(vagina, root->vStatus(horny),root->vSex(dick),root->vSex(silavag));
        QString str = "Вы закусили губу от боли и из глаз брызнули слезы когда ";
        QString str2 = " в вас, разорвав вашу девственную плеву. Вы заплакали от боли и ";
        if (type == tDick)
        {
            if (root->vSex(pose) == 2)
                result = str + "сели на член и почувствовали как " + boy + " вошел" + str2 + " продолжили прыгать на крепком члене своей окровавленной киской.";
            else
                result = str + boy + " вошел в вас, разорвав вашу девственную плеву. Вы плачете и стонете пока крепкий член трахает вашу окровавленную киску.";
        }
        else if (type == tDildo)
            result = str + intQStr(root->vSex(dick)) + " сантиметровый дилдо вошел" + str2 + " вынули из себя окровавленный дилдо.";
        else if (type == tStrapon)
            result = str + intQStr(root->vSex(dick)) + "  сантиметровый страпон вошел" + str2 + boy + " вынула из вас окровавленный страпон.";
        else if (type == tBottle)
            result = str + "бутылка вошла" + str2 + "вынули из себя окровавленную бутылку.";
        else if (type == tGirlBottle)
            result = str + "бутылка вошла" + str2 + boy + " вынула из вас окровавленную бытылку.";
    }
    else if (root->vStatus(mesec) > 0 && root->vBody(vagina) > 0)
    {
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatus(mood) -= 10;
        emit root->setGape(vagina,root->vStatus(horny), root->vSex(dick), root->vSex(silavag));
        QString str0{"У вас месячные и в то время пока "}, str1{", из влагалища потихоньку вытекает кровь."}, str2{" Ощущения болезненные и неприятные. Вы стонете пока крепкий член "};
        if (type == tDick)
        {
            if(pos == "horse")
                result = str0 + "прыгаете на члене"+str1+str2+"входит в вас.";
            else
                result = str0 + "член таранит вас" + str1 + str2 + "входит в вас.";
        }
        else if (type == tDildo)
            result = str0 + "вы засовываете в себя " + intQStr(root->vSex(dick)) + " сантиметровый дилдо" + str1;
        else if (type == tStrapon)
            result = str0 + boy + " вгоняет в вашу киску " + intQStr(root->vSex(dick)) + "сантиметровый страпон" + str1;
        else if (type == tBottle)
            result = str0 + "вы засовываете в себя бутылку" + str1;
        else if (type == tGirlBottle)
            result = str0 + boy + " вгоняет в вашу киску бутылку" + str1;
    }
    else if (root->vStatus(mesec) <= 0 && root->vBody(vagina) > 0)
    {
        emit root->setGape(vagina,root->vStatus(horny),root->vSex(dick),root->vSex(silavag));
        int hornyVal = root->vStatus(horny);
        int prinat = hornyVal/10 + root->vBody(vagina) + root->vAddict(alko) + root->vSex(lubonus);
        int dickVal = root->vSex(dick);
        int silaVag = root->vSex(silavag);
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
        else if (dickVal <= prinat && dickVal >= root->vBody(vagina))
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
        else if (dickVal <= prinat && dickVal < root->vBody(vagina))
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
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            root->vStatus(mood) -= 15;
            if(root->vBody(makeup) > 1)
            {
                root->vBody(makeup) = 0;
                root->vStatus(vidageday) -= 1;
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
            root->vStatus(horny) -= 10;
            root->vStatus(mood) -= 10;
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
            root->vStatus(horny) -= 5;
            root->vStatus(mood) -= 5;
            QString str0{"Вы вздрогнули от внезапной боли когда "},
                str1{", но болезненные ощущения между ног плавно успокаиваются и становятся вполне сносными. Вы пытаетесь возбудиться пока "},
                str2{" в вашей киске, но у вас ничего не выходит."};
            if(type == tDick)
            {
                if(root->vSex(pose) == 2)
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
            root->vStatus(mood) += 5;
            root->vStatus(horny) += 5;
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
            root->vStatus(mood) += 10;
            root->vStatus(horny) += 10;
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
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            root->vStatus(mood) = 100;
            root->vStatistics(SC::orgasm) += 1;
            root->vStatistics(vaginalOrgasm) += 1;
            root->vBody(hairStatus) = 0;
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
            root->vStatus(horny) += 5;
            root->vStatus(mood) += 5;
            QString str0;
            QString str1;
            if(type == tDick) { str0 = "член"; str1 = "его"; }
            else if (type == tDildo) { str0 = "дилдо"; str1 = "его"; }
            else if (type == tStrapon) { str0 = "страпон"; str1 = "его"; }
            else if (type == tBottle || type == tGirlBottle)  { str0 = "бутылка"; str1 = "её"; }
            result = "Вы почувствовали как " + str0 + " проникает в вашу киску. Между ног приятно, но " + str0 + " значительно меньше вашей киски и " + str1 + " для вас мало.**Постепенно приятное тепло и пульсация нарастают в низу живота, потом ощущения чуть уменьшаются и остаются до конца.";
        }
    }
    root->vSex(lubonus) = 0;
    if(pos.isEmpty())
        root->vStatistics(vaginalSex) += 1;
    if(type != tDick)
        m_protect = 0;
    root->addText(result);
}

void Sex::anal(ToolType type)
{
    QString boy = root->getBoyName();

    QString result, tmp0, tmp1;
    if (root->vSex(analplugIN) == 1)
    {
        root->vSex(analpluginbonus) = 5;
        root->vSex(analplugIN) = 0;
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

    if (root->vStatus(cumAnus) > 0) root->vSex(lubonus) += 2;
    if (root->vBody(anus) >= 10)
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
    int anusCapab = root->vBody(anus) + root->vSex(lubonus) + root->vSex(analpluginbonus) + root->vAddict(alko);
    if (anusCapab < root->vSex(dick))
    {
        tmp0 = "Вы взвизгнули и закусили губы от резкой боли когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметровый страпон" + tmp1;
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылка" + tmp1;
    }
    else if(anusCapab >= root->vSex(dick))
    {
        tmp0 = "Вы застонали от чувства переполненности когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметровый страпон" + tmp1;
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
    if (root->vSex(lubonus) > 0)
    {
        root->setGape(anus,10, root->vSex(dick),root->vSex(silavag));
    }
    else
    {
        root->setGape(anus,0, root->vSex(dick),root->vSex(silavag));
    }
    if (anusCapab < root->vSex(dick))
    {
        if (root->vBody(makeup) > 1) root->vBody(makeup) = 0;
        root->vStatus(vidageday) -= 1;
        root->vStatus(horny) -= 20;
        root->vStatus(mood) -= 20;
        tmp0 = "Вашу попу пронзила острая боль когда ";
        if(type == tDick) result += tmp0 + "член начал трахать её на полную силу. В попе всё горит огнем и вы мечтаете только о том, чтобы эта пытка побыстрее кончилась.";
        else if(type == tDildo) result += tmp0 + "вы начали двигать в своей попе " + intQStr(root->vSex(dick)) + " сантиметровый дилдо.";
        else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
        {
            result += boy + "  начала трахать вашу попу при помощи ";
            if (type == tStrapon)
            {
                result += intQStr(root->vSex(dick)) + " сантиметрового страпона.";
            }
            else if(type == tGirlBottle) result += "бутылки.";
            else if(type == tGirlDildo) result += intQStr(root->vSex(dick)) + " сантиметрового дилдо.";
        }
        else if(type == tBottle)
            result += tmp0 + "вы начали двигать в своей попе бутылку.";
    }
    else if (anusCapab >= root->vSex(dick))
    {
        root->vStatus(horny) += 10;
        tmp0 = "Вы начали ритмично стонать в такт движениям ";
        tmp1 = " Вы чувствуете как ваш анус растягивается когда ";
        if(type == tDick) result += tmp0 + "члена внутри вас." + tmp1 + "член входит в вас.";
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметрового дилдо внутри вас." + tmp1 + "дилдо двигается внутри попки.";
        else if (type == tStrapon) result += tmp0 + intQStr(root->vSex(dick)) + " сантиметрового страпона внутри вас." + tmp1 + "страпон двигается внутри попки.";
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылки внутри вас." + tmp1 + "бутылка двигается внутри попки.";
        if (root->vStatus(horny) >= 100 && root->vBody(anus) >= 10 && root->vStatistics(orgasm) > 0)
        {
            root->vStatus(mood) = 100;
            root->vStatistics(orgasm) += 1;
            root->vStatistics(analOrgasm) += 1;
            root->vStatus(horny) = 0;
            root->vStatus(lust) = 0;
            root->vBody(hairStatus) = 0;
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
    root->vSex(lubonus) = 0;
    root->vSex(analpluginbonus) = 0;
    root->addText(result);
}

void Sex::cum(QString target)
{
    if(target == "cumfrot")
        root->vStatus(cumFrot) += getRandInt(1,2);
    if(target == "face")
    {
        root->vStatus(cumFace) += getRandInt(1,2);
        root->vStatistics(facialCum) += getRandInt(1,2);
    }
    if(target == "lip")
        root->vStatus(cumLips) += getRandInt(1,2);
    if(target == "belly")
        root->vStatus(cumBelly) += getRandInt(2,3);
    if(target == "ass")
        root->vStatus(cumAss) += getRandInt(2,3);
    if(target == "pussy")
    {
        if(root->vSex(protect) == 1)
        {
            bool defcondom = false;
            if(root->vSex(use_condoms) == 1 && root->getItmCount(iCondoms) > 0)
            {
                defcondom = root->condomDef();
            }
            if((root->vStatus(pregnancyKnow) > 0 && root->getItmCount(iCondoms) == 0) ||
                (root->vStatus(pregnancyKnow) > 0 && root->getItmCount(iCondoms) > 0 && defcondom == false))
            {
                root->addText("<br>Вы усмехнулись про себя, ну по крайней мере вы не залетите.");
                root->vStatus(cumPussy) = getRandInt(3,4);
            }
            else if((root->vStatus(mesec) > 0 && root->getItmCount(iCondoms) == 0) ||
                       (root->vStatus(mesec) > 0 && root->getItmCount(iCondoms) > 0 && defcondom == false))
            {
                root->addText("<br>\"- Хорошо, что месячные, хоть не залечу...\", - с облегчением подумали вы.");
                root->chanceOfPreg();
                root->vStatus(cumPussy) = getRandInt(3,4);
            }
            else if(root->vSex(use_anti_preg_pills) == 1 && root->getItmCount(iAntiPregPills) > 0)
            {
                root->addText("<br>\\\"- Хорошо, что месячные, хоть не залечу...\"///, - с облегчением подумали вы.");
                root->chanceOfPreg();
                root->vStatus(cumPussy) = getRandInt(3,4);
            }
            else if(root->getItmCount(iCondoms) > 0 && defcondom == false)
            {
                root->vStatus(mood) -= 25;
                root->addText("<br>\\\"- Блин, бля... залететь же так можно!\"///, - подумали вы с ужасом, смотря на порваный презерватив.");
                root->chanceOfPreg();
                root->vStatus(cumPussy) = getRandInt(3,4);
            }
            else if (root->getItmCount(iCondoms) > 0 && defcondom == true)
            {
                root->vStatus(cumPussy) = 0;
            }
            else if(root->getItmCount(iCondoms) == 0)
            {
                root->vStatus(mood) -= 15;
                root->addText("<br>\\\"- Черт, так ведь и залететь можно\"///, - подумали вы с ужасом.");
                root->chanceOfPreg();
                root->vStatus(cumPussy) = getRandInt(3,4);
            }
        }
        else
        {
            if(root->vStatus(pregnancyKnow) > 0)
            {
                root->addText("<br>Вы усмехнулись про себя, ну по крайней мере вы не залетите.");
            }
            else if(root->vStatus(mesec) > 0)
            {
                root->addText("<br>\\\"- Хорошо, что месячные, хоть не залечу...\"///, - с облегчением подумали вы.");
            }
            else if(root->getItmCount(iAntiPregPills) > 0 && root->vSex(use_anti_preg_pills) == 1)
            {
                root->addText("<br>\\\"- Надеюсь таблетки помогут\"///, - подумали вы.");
            }
            else
            {
                root->addText("<br>\\\"- Черт, так ведь и залететь можно\"///, - подумали вы с ужасом.");
            }
            root->chanceOfPreg();
            root->vStatus(cumPussy) = getRandInt(3,4);
        }
    }
    if(target == "anus")
    {
        root->vStatus(cumAnus) = getRandInt(3,4);
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
            root->addText(str[getRandInt(0,2)]);
            cum("pussy");
        }
        else
        {
            if(pose == 0)
            {
                cum("belly");
                root->addText(boy + " застонал и вынув член из вас, кончил на ваш живот.");
            }
            else
            {
                cum("ass");
                root->addText(boy + " застонал и вынув член из вас, кончил на вашу попу.");
            }
        }
    }
    else
    {
        bool defcondom = root->condomDef();
        if(defcondom == true)
        {
            root->addText(boy + " застонал и вы поняли, что он кончил в презерватив.");
        }
        else
        {
            m_protect = 0;
            root->addText("Вынув из вас член " + boy + " сказал:- Хмм, презерватив лопнул...");
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
        root->addText(str[getRandInt(0,2)]);
        cum("anus");
    }
    else
    {
        bool defcondom = root->condomDef();
        if(defcondom == true)
        {
            root->addText(boy + " застонал и вы поняли, что он кончил в презерватив.");
        }
        else
        {
            m_protect = 0;
            root->addText("Вынув из вашей попки член " + boy + " сказал:- Хмм, презерватив лопнул...");
            cum("anus");
        }
    }
}

void Sex::blow_job()
{
    root->vStatus(lipkoef) += 1;
    if(root->vStatus(lipkoef) > 50)
    {
        root->vStatus(lipkoef) = 0;
        root->vBody(lip) += 1;
    }
    QString boy = root->getBoyName();
    if(boy.isEmpty())
        boy = "Парень";
    QString add;
    if(root->vSex(dick) >= root->vBody(throat))
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
    root->addText(str[a] + str[b] + str [b+3]);
    if(b == 6 && root->vSex(dick) >= root->vBody(throat))
    {
        if(root->vBody(makeup) > 1)
        {
            root->vBody(makeup) = 0;
            root->vStatus(vidageday) -= 1;
        }
        root->vBody(throat) += 1;
    }
    if(root->vStatus(horny) >= 100 && root->vStatistics(swallow) >= 100)
    {
        root->vStatistics(orgasm) += 1;
        root->vStatus(horny) = 0;
        root->vStatus(lust) = 0;
        root->vStatus(mood) += 15;
        root->addText("Неожиданно для вас отсасывая член вы начали кончать сами. Между ног полыхал пожар и волны удовольствия охватывали тело, вы стонали но не выпускали член изо рта продолжая его отсасывать.");
    }
}

void Sex::fnswallow()
{
    root->vStatistics(swallow) += 1;
    cum("lip");
    root->vStatus(water) -= 1;
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
    root->addText(str[getRandInt(0,2)] + str[getRandInt(3,5)] + str[getRandInt(6,8)]);
}

void Sex::dp_start()
{
    QString boy;
    if(root->getBoyName().isEmpty())
        boy = "Парень";
    else
        boy = root->getBoyName();
    m_cc_sex_usecondom = 0;
    if(root->vSex(use_condoms) == 1 && root->vSex(protect) == 1 && root->getItmCount(iCondoms) > 0)
    {
        root->useItem(iCondoms,1);
        m_cc_sex_usecondom = 1;
        root->vSex(lubonus_v) += 1;
        root->addText(boy + "взял у вас презерватив и одел его на свой член.");
    }
    if(root->vSex(analplugIN) == 1)
    {
        root->vSex(analpluginbonus) = 5;
        root->vSex(analplugIN) = 0;
        root->addText("Вы вытащили из вашей  попки анальную пробку.");
    }
    if(root->getItmCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->vSex(lubonus_a) += 5;
        root->addText("Выдавив анальной смазки себе на руку, вы начали смазывать им свою попку. После этого вы выдавили еще немного лубриканта на руку и начали смазывать им член." + boy + " был совсем не против и с легкой усмешкой наблюдал за вашими действиями.");
    }
    if(root->vStatus(horny) / 10 + root->vBody(vagina) + root->vAddict(alko) < root->vSex(dick) && root->getItmCount(iLubri) > 0)
    {
        root->useItem(iLubri,1);
        root->vSex(lubonus_v) += 5;
        if(getRandInt(1,2) == 1)
            root->addText("Вы выдавили лубрикант себе на руку и начали намазывать парню член.");
        else
            root->addText("Парень взял у вас тюбик с лубрикантом и смазал свой член смазкой.");
    }
}

void Sex::double_penetration()
{
    if(root->vSex(analplugIN) == 1)
    {
        root->vSex(analpluginbonus) = 5;
        root->vSex(analplugIN) = 0;
        root->addText(root->getBoy2Name() + " вытащил из вашей  попки пробку.");
    }
    if(root->vStatus(cumAnus) > 0)
        root->vSex(lubonus_a) += 2;
    if(root->vStatus(cumPussy) > 0)
        root->vSex(lubonus_v) += 2;
    root->setGape(vagina, root->vStatus(horny), root->vSex(dick), root->vSex(silavag));
    int bonus;
    if(root->vSex(lubonus_a) > 0)
        bonus = 10;
    else
        bonus = 0;
    root->setGape(anus,bonus,root->vSex(dick2),root->vSex(silavag));
    int capab = root->vStatus(horny) / 10 + root->vBody(vagina) + root->vAddict(alko) + root->vSex(lubonus_v);
    if(root->vBody(vagina) == 0)
    {
        root->vStatus(lust) = 0;
        root->vStatus(horny) = 0;
        root->vStatus(mood) -= 15;
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
        if(root->vBody(vagina) == 0)
            add = "окровавленное";
        root->addText("Вы закусили губу от боли и из глаз брызнули слезы когда " + boy + " вошел в вас, разорвав вашу девственную плеву.");
        if(root->vStatus(mesec) > 0 && root->vBody(vagina) > 0)
        {
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            root->vStatus(mood) -= 10;
            root->addText("У вас месячные и вам неприятно и больно, пока член первого парня таранит вашу кровоточащую вагину. Одновременно вы чувствуете как ваш " + root->getAnusTipe() + " анус трахает второй член.");
        }
        int pain = root->vSex(stat_agape) + root->vSex(stat_vgape);
        if(pain == 0)
        {
            root->addText("Ощущения сливаются воедино, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Внизу живота горит приятный огонек распространяя тепло по всему телу.");
            int DPplus = root->vStatistics(vaginalOrgasm) * 10 + root->vStatus(horny) + root->vStatus(mood);
            int DPmminus = getRandInt(250,350);
            if(DPplus > DPmminus)
            {
                root->vStatistics(vaginalOrgasm) += 1;
                root->vStatistics(DualPenetrationOrgasm) += 1;
                root->vStatistics(orgasm) += 1;
                root->vStatus(mood) = 100;
                root->vStatus(lust) = 0;
                root->vStatus(horny) = 0;
                root->vBody(hairStatus) = 0;
                root->addText("Внезапно вас охватывает оргазм и вы, не помня себя, стонете и кричите, пока ваши мышцы судорожно сокращаются вокруг двух членов внутри вашего тела.");
            }
        }
        else if(pain == 1)
        {
            root->addText("Ощущения сливаются воедино, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Немного больно, но все же очень приятно чувствовать как все свободные отверстия заполняются членами.");
        }
        else if(pain == 2)
        {
            root->vStatus(horny) = root->vStatus(horny)/2;
            root->vStatus(mood) = root->vStatus(mood)/2;
            root->addText("Вы чуствуете себя так, как будто вот-вот готовы лопнуть от переполненности, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалище и ваш " + root->getAnusTipe() + " анус. Ощущения очень странные, в один клубок смешалась боль, удовольствие и болезненная переполненность.");
        }
        else if (pain == 3)
        {
            root->vStatus(horny) = root->vStatus(horny)/4;
            root->vStatus(mood) = root->vStatus(mood)/4;
            root->addText("Вам больно и иногда резкие вспышки боли заставляют вас застонать, когда внутри вас двигаются два члена, соприкасаясь друг с другом через тоненькую стеночку, разделяющую ваше " + add + " влагалищеи ваш " + root->getAnusTipe() + " анус. Вы чувствуете себя готовой лопнуть, ваша попа и киска по ощущениям слились в один довольно болезненный комок. Ваши глаза не произвольно застилает пелена слез.");
        }
        else
        {
            root->vStatus(mood) = 0;
            root->vStatus(lust) = 0;
            root->vStatus(horny) = 0;
            if(root->vBody(makeup) > 1)
            {
                root->vBody(makeup) = 0;
                root->vStatus(vidageday) -= 1;
            }
            QString add = "";
            if(root->vBody(vagina) == 0)
                add = "в окровавленное";
            else
                add = "во";
            root->addText("Вы визжите и слезы ручьем льются из ваших глаз от жуткой боли, весь ваш низ живота и попа отдает острой болью, пока вас трахает " + boy + " " + add + " влагалище и " + boy2 + " практически рвет ваш " + root->getAnusTipe() + " анус своим орудием.");
        }
        root->vStatistics(vaginalSex) += 1;
        root->vStatistics(analSex) += 1;
        root->vSex(lubonus_a) = 0;
        root->vSex(lubonus_v) = 0;
        root->vSex(protect) = 0;
    }
}

void Sex::dp_cum()
{
    if(getRandInt(0,1) == 0)
        root->setBoyName(root->getBoyName());
    else
        root->setBoyName(root->getBoy2Name());
    int randFunc = getRandInt(1,3);
    if(randFunc == 1) sex_cum();
    if(randFunc == 2) anal_cum();
    if(randFunc == 3) rand_cum();
}

void Sex::dd_anus(int dick1, int dick2, QString name1, QString name2, int protection)
{
    if(getRandInt(0,1) == 0)
    {
        root->setBoyName(name1);
        root->setBoy2Name(name2);
    }
    else
    {
        root->setBoyName(name2);
        root->setBoy2Name(name1);
    }
    int toool = (dick1 + dick2) * 9 / 11;
    root->vSex(dick) = toool;
    root->vSex(silavag) = getRandInt(0,2);
    root->vSex(protect) = protection;
    analStart(tDick);
    anal(tDick);
    anal_cum();
}

void Sex::dd_vagina(int dick1, int dick2, QString name1, QString name2, int protection)
{
    if(getRandInt(0,1) == 0)
    {
        root->setBoyName(name1);
        root->setBoy2Name(name2);
    }
    else
    {
        root->setBoyName(name2);
        root->setBoy2Name(name1);
    }
    int tool = (dick1 + dick2) * 9 / 11;
    root->vSex(silavag) = getRandInt(0,2);
    root->vSex(protect) = protection;
    sexStart();
    vaginal(tDick);
    sex_cum();
}
