#include "sex.h"
#include "sexviewform.h"
#include "ui_sexviewform.h"
#include "Functions.h"
#include "../mainwindow.h"
Sex::Sex(QWidget* parent)
{
    root = (SexViewForm*)parent;
    m_protect = 0;
}

void Sex::sexStart(int protect)
{
//////////////
QString boy;
//////////////
    if (boy.isEmpty()) { boy = "Парень"; }    
    m_cc_sex_usecondom = 0;
    if (getSexVar(vibratorIN) == 1)
    {
        setSexVar(vibratorIN,0);
        root->ui->labelSexDesc->setText(root->ui->labelSexDesc->text() + "<br>" + "Вы вынули вибратор из влагалища.");
    }
    if (getItemCount(iCondoms) > 0 && (getSexVar(use_condoms) == 1 || protect == 1))
    {
        useItem(iCondoms, 1);
        m_protect = 1;
        updSexVar(lubonus,1);
        m_cc_sex_usecondom = 1;
        checkTextOutput(1, boy + " взял у вас презерватив и одел его на свой член.");
    }
    if (getVStatus(horny)/10 + getVBody(vagina) + getVAddict(alko) < getSexVar(dick) && getItemCount(iLubri) > 0)
    {
        useItem(iLubri,1);
        updSexVar(lubonus,5);
        if(getRandInt(1,2) == 1)
        {
            checkTextOutput(1, "Вы выдавили лубрикант себе на руку и начали смазывать им свою вагину.");
        }
        else
        {
            checkTextOutput(1, "Выдавив лубрикант себе на руку, вы начали тщательно смазывать им свою вагину.");
        }
    } 
}

void Sex::analStart(ToolType type, int protect)
{
/////////////////////    
    QString boy;
////////////////////
    if (boy.isEmpty()) { boy = "Парень"; }
    
    m_cc_sex_usecondom = 0;
    QString final;
    if(getItemCount(iCondoms) > 0 && (getSexVar(use_condoms) == 1 || protect == 1))
    {
        useItem(iCondoms, 1);
        m_protect = 1;
        m_cc_sex_usecondom = 1;
        updSexVar(lubonus,1);
        checkTextOutput(1, boy + " взял у вас презерватив и одел его на свой член.");
    }
    if(getSexVar(analplugIN) == 1)
    {
        setSexVar(analpluginbonus, 5);
        setSexVar(analplugIN, 0);
        checkTextOutput(1, "Вы вытащили из вашей  попки анальную пробку.");
    }
    if(getItemCount(iLubri) > 0)
    {
        useItem(iLubri,1);
        updSexVar(lubonus, 10);
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
        checkTextOutput(1, final);
    }
}

void Sex::vaginal(ToolType type, QString pos)
{
////////////////
    QString boy;
////////////////
    if (boy.isEmpty()) { boy = "парень"; }
    if (getVStatus(cumPussy) > 0) updSexVar(lubonus,2);
    if (getSexVar(vibratorIN) == 1) 
    {
        setSexVar(vibratorIN,0);
        checkTextOutput(1, "Вы вынули вибратор из влагалища.");
    }
    QString result;
    if (getVBody(vagina) == 0)
    {
        setVStatus(lust,0);
        setVStatus(horny,0);
        updVStatus(mood, -15);
        emit root->sigSetGape(vagina, getVStatus(horny),getSexVar(dick),getSexVar(silavag));
        QString str = "Вы закусили губу от боли и из глаз брызнули слезы когда ";
        QString str2 = " в вас, разорвав вашу девственную плеву. Вы заплакали от боли и ";
        if (type == tDick)
        {
            if (getSexVar(pose) == 2)
                result = str + "сели на член и почувствовали как " + boy + " вошел" + str2 + " продолжили прыгать на крепком члене своей окровавленной киской.";
            else
                result = str + boy + " вошел в вас, разорвав вашу девственную плеву. Вы плачете и стонете пока крепкий член трахает вашу окровавленную киску.";
        }
        else if (type == tDildo)
            result = str + intQStr(getSexVar(dick)) + " сантиметровый дилдо вошел" + str2 + " вынули из себя окровавленный дилдо.";
        else if (type == tStrapon)
            result = str + intQStr(getSexVar(dick)) + "  сантиметровый страпон вошел" + str2 + boy + " вынула из вас окровавленный страпон.";
        else if (type == tBottle)
            result = str + "бутылка вошла" + str2 + "вынули из себя окровавленную бутылку.";
        else if (type == tGirlBottle)
            result = str + "бутылка вошла" + str2 + boy + " вынула из вас окровавленную бытылку.";
    }
    else if (getVStatus(mesec) > 0 && getVBody(vagina) > 0)
    {
        setVStatus(lust,0);
        setVStatus(horny,0);
        updVStatus(mood, -10);
        emit root->sigSetGape(vagina,getVStatus(horny), getSexVar(dick), getSexVar(silavag));
        QString str0{"У вас месячные и в то время пока "}, str1{", из влагалища потихоньку вытекает кровь."}, str2{" Ощущения болезненные и неприятные. Вы стонете пока крепкий член "};
        if (type == tDick)
        {
            if(pos == "horse")
                result = str0 + "прыгаете на члене"+str1+str2+"входит в вас.";
            else
                result = str0 + "член таранит вас" + str1 + str2 + "входит в вас.";
        }
        else if (type == tDildo)
            result = str0 + "вы засовываете в себя " + intQStr(getSexVar(dick)) + " сантиметровый дилдо" + str1;
        else if (type == tStrapon)
            result = str0 + boy + " вгоняет в вашу киску " + intQStr(getSexVar(dick)) + "сантиметровый страпон" + str1;
        else if (type == tBottle)
            result = str0 + "вы засовываете в себя бутылку" + str1;
        else if (type == tGirlBottle)
            result = str0 + boy + " вгоняет в вашу киску бутылку" + str1;
    }
    else if (getVStatus(mesec) <= 0 && getVBody(vagina) > 0)
    {
        emit root->sigSetGape(vagina,getVStatus(horny),getSexVar(dick),getSexVar(silavag));
        int hornyVal = getVStatus(horny);
        int prinat = hornyVal/10 + getVBody(vagina) + getVAddict(alko) + getSexVar(lubonus);
        int dickVal = getSexVar(dick);
        int silaVag = getSexVar(silavag);
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
        else if (dickVal <= prinat && dickVal >= getVBody(vagina))
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
        else if (dickVal <= prinat && dickVal < getVBody(vagina))
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
            setVStatus(lust,0);
            setVStatus(horny,0);
            updVStatus(mood, -15);
            if(getVBody(makeup) > 1)
            {
                setVBody(makeup,0);
                updVStatus(vidageday, -1);
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
            updVStatus(horny, -10);
            updVStatus(mood,-10);
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
            updVStatus(horny,-5);
            updVStatus(mood,-5);
            QString str0{"Вы вздрогнули от внезапной боли когда "},
                str1{", но болезненные ощущения между ног плавно успокаиваются и становятся вполне сносными. Вы пытаетесь возбудиться пока "},
                str2{" в вашей киске, но у вас ничего не выходит."};
            if(type == tDick)
            {
                if(getSexVar(pose) == 2)
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
            updVStatus(mood,5);
            updVStatus(horny,5);
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
            updVStatus(mood,10);
            updVStatus(horny,10);
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
            setVStatus(lust,0);
            setVStatus(horny,0);
            setVStatus(mood,100);
            updVSC(SC::orgasm,1);
            updVSC(SC::vaginalOrgasm,1);
            setVBody(hairStatus,0);
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
            updVStatus(horny,5);
            updVStatus(mood,5);
            QString str0;
            QString str1;
            if(type == tDick) { str0 = "член"; str1 = "его"; }
            else if (type == tDildo) { str0 = "дилдо"; str1 = "его"; }
            else if (type == tStrapon) { str0 = "страпон"; str1 = "его"; }
            else if (type == tBottle || type == tGirlBottle)  { str0 = "бутылка"; str1 = "её"; }
            result = "Вы почувствовали как " + str0 + " проникает в вашу киску. Между ног приятно, но " + str0 + " значительно меньше вашей киски и " + str1 + " для вас мало.**Постепенно приятное тепло и пульсация нарастают в низу живота, потом ощущения чуть уменьшаются и остаются до конца.";
        }
    }
    setSexVar(lubonus,0);
    if(pos.isEmpty())
        updVSC(SC::vaginalSex, 1);
    if(type != tDick)
        m_protect = 0;
    checkTextOutput(0,result);
}

void Sex::anal(ToolType type)
{
////////////////
    QString boy;
////////////////
    QString result, tmp0, tmp1;
    if (getSexVar(analplugIN) == 1)
    {
        setSexVar(analpluginbonus,5);
        setSexVar(analplugIN,0);
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

    if (getVStatus(cumAnus) > 0) updSexVar(lubonus,2);
    if (getVBody(anus) >= 10)
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
    int anusCapab = getVBody(anus) + getSexVar(lubonus) + getSexVar(analpluginbonus) + getVAddict(alko);
    if (anusCapab < getSexVar(dick))
    {
        tmp0 = "Вы взвизгнули и закусили губы от резкой боли когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметровый страпон" + tmp1;
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылка" + tmp1;
    }
    else if(anusCapab >= getSexVar(dick))
    {
        tmp0 = "Вы застонали от чувства переполненности когда ";
        tmp1 = " раздвинув вашу попку вошел в вас.";
        if(type == tDick) result += tmp0 + "его член" + tmp1;
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметровый дилдо" + tmp1;
        else if(type == tStrapon) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметровый страпон" + tmp1;
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
    if (getSexVar(lubonus) > 0)
    {
        emit root->sigSetGape(anus,10, getSexVar(dick),getSexVar(silavag));       
    }
    else
    {
        emit root->sigSetGape(anus,0, getSexVar(dick),getSexVar(silavag));
    }
    if (anusCapab < getSexVar(dick))
    {
        if (getVBody(makeup) > 1) setVBody(makeup,0);
        updVStatus(vidageday, -1);
        updVStatus(horny, -20);
        updVStatus(mood, -20);
        tmp0 = "Вашу попу пронзила острая боль когда ";
        if(type == tDick) result += tmp0 + "член начал трахать её на полную силу. В попе всё горит огнем и вы мечтаете только о том, чтобы эта пытка побыстрее кончилась.";
        else if(type == tDildo) result += tmp0 + "вы начали двигать в своей попе " + intQStr(getSexVar(dick)) + " сантиметровый дилдо.";
        else if (type == tStrapon || type == tGirlBottle || type == tGirlDildo)
        {
            result += boy + "  начала трахать вашу попу при помощи ";
            if (type == tStrapon)
            {
                result += intQStr(getSexVar(dick)) + " сантиметрового страпона.";
            }
            else if(type == tGirlBottle) result += "бутылки.";
            else if(type == tGirlDildo) result += intQStr(getSexVar(dick)) + " сантиметрового дилдо.";
        }
        else if(type == tBottle)
            result += tmp0 + "вы начали двигать в своей попе бутылку.";
    }
    else if (anusCapab >= getSexVar(dick))
    {
        updVStatus(horny, 10);
        tmp0 = "Вы начали ритмично стонать в такт движениям ";
        tmp1 = " Вы чувствуете как ваш анус растягивается когда ";
        if(type == tDick) result += tmp0 + "члена внутри вас." + tmp1 + "член входит в вас.";
        else if(type == tDildo || type == tGirlDildo) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметрового дилдо внутри вас." + tmp1 + "дилдо двигается внутри попки.";
        else if (type == tStrapon) result += tmp0 + intQStr(getSexVar(dick)) + " сантиметрового страпона внутри вас." + tmp1 + "страпон двигается внутри попки.";
        else if(type == tBottle || type == tGirlBottle) result += tmp0 + "бутылки внутри вас." + tmp1 + "бутылка двигается внутри попки.";
        if (getVStatus(horny) >= 100 && getVBody(anus) >= 10 && getBSC(orgasm) > 0)
        {
            setVStatus(mood, 100);
            updVSC(orgasm, 1);
            updVSC(analOrgasm, 1);
            setVStatus(horny, 0);
            setVStatus(lust, 0);
            setVBody(hairStatus, 0);
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
    setSexVar(lubonus,0);
    setSexVar(analpluginbonus,0);
    checkTextOutput(1,result);
}

int Sex::getSexVar(SexVar param)
{
    return root->getSexVar(param);
}

int Sex::getVStatus(Status param)
{
    return root->getVStatus(param);
}

int Sex::getVBody(Body param)
{
    return root->getVBody(param);
}

int Sex::getItemCount(Items item)
{
    return root->getItemCount(item);
}

int Sex::getVAddict(Addiction param)
{
    return root->getVAddict(param);
}

int Sex::getBSC(SC param)
{
    return root->getBSC(param);
}

void Sex::setSexVar(SexVar param, int value)
{
    root->setSexVar(param, value);
}

void Sex::updSexVar(SexVar param, int value)
{
    root->updSexVar(param,value);
}

void Sex::setVStatus(Status param, int value)
{
    root->setVStatus(param, value);
}

void Sex::updVStatus(Status param, int value)
{
    root->updVStatus(param,value);
}

void Sex::updVSC(SC param, int val)
{
    root->updVSC(param,val);
}

void Sex::useItem(Items item, int count)
{
    root->useItem(item, count);
}

void Sex::setVBody(Body param, int val)
{
    root->setVBody(param,val);
}

void Sex::checkTextOutput(int addTxtSex, QString text)
{
    root->ui->labelSexDesc->setText(root->ui->labelSexDesc->text() + "<br>" + text);
}
