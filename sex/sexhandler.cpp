#include "sexhandler.h"
#include "../menu/mainwindow.h"
SexHandler::SexHandler(Render *ptr, QWidget *parent, QVBoxLayout *actions):
    m_render(ptr), root(parent), m_actions(actions)
{
    m_selfplay = new SelfPlay(this);
    m_sex = new Sex(this);
}

void SexHandler::selfPlayStart()
{
    m_selfplay->start();
}

void SexHandler::cum(QString target)
{
    m_sex->cum(target);
}

void SexHandler::sexStart()
{
    m_sex->sexStart();
}

void SexHandler::analStart(ToolType type)
{
    m_sex->analStart(type);
}

void SexHandler::vaginal(ToolType type, QString pos)
{
    m_sex->vaginal(type,pos);
}

void SexHandler::anal(ToolType type)
{
    m_sex->anal(type);
}

void SexHandler::sex_cum()
{
    m_sex->sex_cum();
}

void SexHandler::blow_job()
{
    m_sex->blow_job();
}

void SexHandler::anal_cum()
{
    m_sex->anal_cum();
}

void SexHandler::fnswallow()
{
    m_sex->fnswallow();
}

void SexHandler::dp_start()
{
    m_sex->dp_start();
}

void SexHandler::double_penetration()
{
    m_sex->double_penetration();
}

void SexHandler::updParams()
{
    ((MainWindow*)root)->slotUpdParams();
}

void SexHandler::setGape(Body holeType, int horny, int dick, int silavag)
{
    ((MainWindow*)root)->m_ccsex.slotSetGape(holeType,horny,dick,silavag);
}

void SexHandler::updVSC(SC param, int val)
{
    ((MainWindow*)root)->m_player->updVStatistic(param,val);
}

void SexHandler::updVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->updVBody(param,val);
}

void SexHandler::updVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->updVStatus(param,val);
}

void SexHandler::updVSexVar(SexVar param, int val)
{
    ((MainWindow*)root)->m_player->updVSexVar(param,val);
}

void SexHandler::incTime(int min)
{
    ((MainWindow*)root)->m_time.increaseTime(min);
}

void SexHandler::setVSexVar(SexVar param, int val)
{
    ((MainWindow*)root)->m_player->setVSexVar(param,val);
}

void SexHandler::setVStatus(Status param, int val)
{
    ((MainWindow*)root)->m_player->setVStatus(param,val);
}

void SexHandler::setVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->setVBody(param,val);
}

void SexHandler::changeLoc(LocId locId, int min)
{
    ((MainWindow*)root)->locHandler->slotChangeLoc(locId, min);
}

void SexHandler::useItem(Items id, int count)
{
    ((MainWindow*)root)->m_bag->useItem(id,count);
}

void SexHandler::chanceOfPreg()
{
    ((MainWindow*)root)->m_reproductSys.chanceOfPregnancy();
}

int SexHandler::getVStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int SexHandler::getVSexVar(SexVar param)
{
    return ((MainWindow*)root)->m_player->getVSexVar(param);
}

int SexHandler::getVBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

int SexHandler::getItemCount(Items id)
{
    return ((MainWindow*)root)->m_bag->getQuantityof(id);
}

int SexHandler::getVAddict(Addiction param)
{
    return ((MainWindow*)root)->m_player->getVAddict(param);
}

int SexHandler::getVSC(SC param)
{
    return ((MainWindow*)root)->m_player->getStatisticsValue(param);
}

LocId SexHandler::getCurLoc()
{
    return ((MainWindow*)root)->locHandler->getCurLoc();
}

LocId SexHandler::getPrevLoc()
{
    return ((MainWindow*)root)->locHandler->getPrevLoc();
}

QString SexHandler::getBoyName()
{
    return ((MainWindow*)root)->m_player->getBoyName();
}

QString SexHandler::getBoy2Name()
{
    return ((MainWindow*)root)->m_player->getBoy2Name();
}

QString SexHandler::getLipTalk()
{
    return ((MainWindow*)root)->m_player->getLipTalk();
}

QString SexHandler::getLipTalk2()
{
    return ((MainWindow*)root)->m_player->getLipTalk2();
}

QString SexHandler::getLipTalk3()
{
    return ((MainWindow*)root)->m_player->getLipTalk3();
}

QString SexHandler::getAnusTipe()
{
    return ((MainWindow*)root)->m_player->getAnusTipe1();
}

QString SexHandler::getAnusTipe2()
{
    return ((MainWindow*)root)->m_player->getAnusTipe2();
}

bool SexHandler::condomDefense()
{
    return ((MainWindow*)root)->m_reproductSys.condomDef();
}
