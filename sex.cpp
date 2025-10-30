#include "sexviewform.h"
#include "ui_sexviewform.h"
#include "Functions.h"

Sex::Sex(QWidget* parent)
{
    root = (SexViewForm*)parent;
    m_protect = 0;
}

void Sex::sexStart(int protect)
{
    m_cc_sex_usecondom = 0;
    if (getSexVar(vibratorIN) == 1)
    {
        setSexVar(vibratorIN,0);
        root->ui->labelSexDesc->setText(root->ui->labelSexDesc->text() + "<br>" + "Вы вынули вибратор из влагалища.");
    }
    if (getItemCount(Items::condoms) > 0 && (getSexVar(use_condoms) == 1 || protect == 1))
    {
        useItem(Items::condoms, 1);
        m_protect = 1;
        updSexVar(lubonus,1);
        m_cc_sex_usecondom = 1;
        //gs 'zz_dynamic_sex','check text output',1,iif($boy!'',$boy,'Парень')+' взял у вас презерватив и одел его на свой член.'
    }
    if (getVStatus(horny)/10 + getVBody(vagina) + getVStatus(alko) < getSexVar(dick) && getItemCount(Items::lubri) > 0)
    {
        useItem(Items::lubri,1);
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
    m_cc_sex_usecondom = 0;
    QString final;
    if(getItemCount(Items::condoms) > 0 && (getSexVar(use_condoms) == 1 || protect == 1))
    {
        useItem(Items::condoms, 1);
        m_protect = 1;
        m_cc_sex_usecondom = 1;
        updSexVar(lubonus,1);

        //gs 'zz_dynamic_sex','check text output',1,iif($boy!'',$boy,'Парень')+' взял у вас презерватив и одел его на свой член.'
    }
    if(getSexVar(analplugIN) == 1)
    {
        setSexVar(analpluginbonus, 5);
        setSexVar(analplugIN, 0);
        checkTextOutput(1, "Вы вытащили из вашей  попки анальную пробку.");
    }
    if(getItemCount(lubri) > 0)
    {
        useItem(lubri,1);
        updSexVar(lubonus, 10);
        final = "Вы выдавили анальной смазки себе на руку и начали намазывать свою попку. ";
        if(type == ToolType::tDick)
        {
            final += " После этого вы выдавили еще немного лубриканта на руку и начали смазывать им член.";
            //final += '+iif($boy!'',$boy,'Парень')+' был совсем не против и с легкой усмешкой наблюдал за вашими действиями.'
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

void Sex::vaginal(ToolType type)
{

////////////////
        QString boy;
////////////////
    if (getVStatus(cumPussy) > 0) updSexVar(lubonus,2);
    if (getSexVar(vibratorIN) == 1) 
    {
        setSexVar(vibratorIN,0);
        checkTextOutput(1, "Вы вынули вибратор из влагалища.");
    }
    if (getVBody(vagina) == 0)
    {
        setVStatus(lust,0);
        setVStatus(horny,0);
        updVStatus(mood, -15);
        emit root->sigSetGape(vagina, getVStatus(horny),getSexVar(dick),getSexVar(silavag));
        QString str = "Вы закусили губу от боли и из глаз брызнули слезы когда ";
        QString str2 = " в вас, разорвав вашу девственную плеву. Вы заплакали от боли и ";
        QString result;
        if (type == tDick)
        {
            if (boy.isEmpty()) { boy = "парень"; }
            if (getSexVar(pose) == 2)
            {
                result = str + "сели на член и почувствовали как " + boy + " вошел" + str2 + " продолжили прыгать на крепком члене своей окровавленной киской.";
            }
            else
            {
                result = str + boy + " вошел в вас, разорвав вашу девственную плеву. Вы плачете и стонете пока крепкий член трахает вашу окровавленную киску.";
            }
        }
        else if (type == tDildo)
        {
            result = str + intQStr(getSexVar(dick)) + " сантиметровый дилдо вошел" + str2 + " вынули из себя окровавленный дилдо.";
        }
        else if (type == tStrapon)
        {
            result = str + intQStr(getSexVar(dick)) + "  сантиметровый страпон вошел" + str2 + boy + " вынула из вас окровавленный страпон.";
        }        
        else if (type == tBottle)
        {
            result = str + "бутылка вошла" + str2 + "вынули из себя окровавленную бутылку.";
        }
        else if (type == tGirlBottle)
        {
            result = str + "бутылка вошла" + str2 + boy + " вынула из вас окровавленную бытылку.";
        }
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
            /* code */
        }
        else if (type == tDildo)
        {
            /* code */
        }
        
        
        
    }
    

}

int Sex::getSexVar(SexVar param)
{
    return root->m_player->getVSexVar(param);
}

int Sex::getVStatus(Status param)
{
    return root->m_player->getVStatus(param);
}

int Sex::getVBody(Body param)
{
    return root->m_player->getVBody(param);
}

int Sex::getItemCount(Items item)
{
    return root->m_bag->getQuantityof(item);
}

void Sex::setSexVar(SexVar param, int value)
{
    root->m_player->setVSexVar(param, value);
}

void Sex::updSexVar(SexVar param, int value)
{
    root->m_player->updVSexVar(param,value);
}

void Sex::setVStatus(Status param, int value)
{
    root->m_player->setVStatus(param, value);
}

void Sex::updVStatus(Status param, int value)
{
    root->m_player->updVStatus(param,value);
}

void Sex::useItem(Items item, int count)
{
    root->m_bag->removeFromBag(item, count);
}

void Sex::checkTextOutput(int addTxtSex, QString text)
{
    root->ui->labelSexDesc->setText(root->ui->labelSexDesc->text() + "<br>" + text);    
}
