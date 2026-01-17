#include "buttons.h"

QActButton::QActButton(QString action)
{
    m_action = action;
    connect(this, &QActButton::clicked, this, &QActButton::clickHandle);
}

void QActButton::clickHandle()
{
    emit sigAct(m_action);
}

LocButton::LocButton(LocId locId, int min): m_locId(locId), m_time(min)
{
    connect(this, &LocButton::clicked, this, &LocButton::slotClick);
}

void LocButton::slotClick()
{
    emit sigChangeLoc(m_locId, m_time);
}

ObjButton::ObjButton(QString objectName): m_objName(objectName)
{
    connect(this, &ObjButton::clicked, this, &ObjButton::slotClick);
}

void ObjButton::slotClick()
{
    emit sigViewObject(m_objName);
}

SaveBtn::SaveBtn(QString file)
{
    m_file = file;
    connect(this, &SaveBtn::clicked, this, &SaveBtn::slotClick);
}

void SaveBtn::slotClick()
{
    emit sigSaveClick(m_file);
}
