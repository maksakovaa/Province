#include "sexviewform.h"
#include "ui_sexviewform.h"

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
        //'zz_dynamic_sex','check text output',1,iif(rand(1,2) = 1,'Вы выдавили лубрикант себе на руку и начали смазывать им свою вагину.','Выдавив лубрикант себе на руку, вы начали тщательно смазывать им свою вагину.')
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

void Sex::useItem(Items item, int count)
{
    root->m_bag->removeFromBag(item, count);
}
