#include "sexhandler.h"


SexHandler::SexHandler(Game *ptr): root(ptr)
{
    m_selfplay = new SelfPlay(root);
    m_sex = new Sex(root);
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
