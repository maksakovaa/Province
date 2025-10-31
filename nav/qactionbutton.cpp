#include "qactionbutton.h"

QActionButton::QActionButton(int time): m_time(time)
{
    connect(this, &QActionButton::clicked, this, &QActionButton::handleButtonClick);
    this->setCursor(Qt::PointingHandCursor);
}

void QActionButton::setLocPtr(Location *ptr)
{
    m_loc = ptr;
    m_obj = nullptr;
}

void QActionButton::setObjName(QString name)
{
    m_obj = name;
    m_loc = nullptr;
}

void QActionButton::setActName(QString name)
{
    m_act = name;
}

void QActionButton::handleButtonClick()
{
    if (m_loc != nullptr && m_act.isEmpty())
    {
        emit sigChangeSubLoc(m_loc, m_time);
    }
    else if (m_loc != nullptr && !m_act.isEmpty())
    {
        emit sigMakeAct(m_loc, m_act);
    }
    else if (m_obj != nullptr)
    {
        emit sigViewObj(m_obj);
    }
}

ObjActionButton::ObjActionButton(QString actName)
{
    m_actionName = actName;
    connect(this, &ObjActionButton::clicked, this, &ObjActionButton::handleButtonClick);
    this->setCursor(Qt::PointingHandCursor);
}

void ObjActionButton::handleButtonClick()
{
    emit sigAction(m_actionName);
}
