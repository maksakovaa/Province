#include "buttons.h"

QActButton::QActButton(QString action,QString handler)
{
    m_action = action;
    m_handler = handler;
    connect(this, &QActButton::clicked, this, &QActButton::clickHandle);
}

void QActButton::clickHandle()
{
    emit sigAct(m_action);
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

BedActionButton::BedActionButton(QString actName, BedActs act): m_action(act)
{
    this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &BedActionButton::clicked, this, &BedActionButton::handleButtonClick);
}

void BedActionButton::handleButtonClick()
{
    emit sigAction(m_action);
}

MirrActionButton::MirrActionButton(QString actName, MirrorActs act): m_action(act)
{
    this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &MirrActionButton::clicked, this, &MirrActionButton::handleButtonClick);
}

void MirrActionButton::handleButtonClick()
{
    emit sigAction(m_action);
}

WardrActionButton::WardrActionButton(QString actName, WardrActs act): m_action(act)
{
    this->setText(actName); this->setCursor(Qt::PointingHandCursor);
    connect(this, &WardrActionButton::clicked, this, &WardrActionButton::handleButtonClick);
}

void WardrActionButton::handleButtonClick()
{
    emit sigAction(m_action);
}

BathActBtn::BathActBtn(bathActs act, QString actName)
{
    this->setCursor(Qt::PointingHandCursor);
    connect(this, &BathActBtn::clicked, this, &BathActBtn::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void BathActBtn::handleButtonClick()
{
    emit sigAction(m_action);
}
