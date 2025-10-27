#include "locationform.h"
#include "qactionbutton.h"
#include "../Functions.h"
#include "sexviewform.h"
#include "ui_locationform.h"

void LocationForm::bathActions(std::vector<struct Action*> acts)
{
    for (auto i: acts)
    {
        if (!i->param.isEmpty())
        {
            if (i->param == "horny" && m_player->getVStatus(horny) >= i->minValue)
            {
                QActionButton* actionbtn = new QActionButton(0);
                actionbtn->setText(i->act);
                actionbtn->setActName(i->act);
                actionbtn->setLocPtr(m_currentLoc);
                m_actLayout->addWidget(actionbtn);
                connect(actionbtn, &QActionButton::sigMakeAct, this, &LocationForm::slotBathActionHandler);
            }
            if (i->param == "pubisHair" && m_player->getVBody(pubisHair) >= i->minValue)
            {
                if (m_bag->getQuantityof(razor) > 0)
                {
                    QActionButton* actionbtn = new QActionButton(0);
                    actionbtn->setText(i->act);
                    actionbtn->setActName(i->act);
                    actionbtn->setLocPtr(m_currentLoc);
                    m_actLayout->addWidget(actionbtn);
                    connect(actionbtn, &QActionButton::sigMakeAct, this, &LocationForm::slotBathActionHandler);
                }
            }
            if (i->param == "legHair" && m_player->getVBody(legHair) >= i->minValue)
            {
                if (m_bag->getQuantityof(razor) > 0)
                {
                    QActionButton* actionbtn = new QActionButton(0);
                    actionbtn->setText(i->act);
                    actionbtn->setActName(i->act);
                    actionbtn->setLocPtr(m_currentLoc);
                    m_actLayout->addWidget(actionbtn);
                    connect(actionbtn, &QActionButton::sigMakeAct, this, &LocationForm::slotBathActionHandler);
                }
            }
        }
    }
}

void LocationForm::slotBathActionHandler(Location* loc, QString action)
{
    if(action == "selfPlay")
    {
        m_page->widget(6)->findChild<SexViewForm*>("SexViewForm")->selfPlayStart(loc);
    }
    if (action == "shaveLegs")
    {
        m_time->increaseTime(15);
        m_player->updVBody(legHair, -5);
        m_player->updVStatus(horny, 5);
        m_bag->removeFromBag(razor, 1);
        emit sigUpdParams();
        ui->labelLocDesc->setText("Вы намыливаете ноги, и взяв бритву, ловкими движениями сбриваете волоски на ногах, смыв затем пенку для бритья.");
        videoWidg->setQUrl("qrc:/actions/shave/legs.webm");
        ui->imageAndWideoWdgt->setCurrentIndex(1);
        ClearLayout(m_actLayout);

        QActionButton* actionbtn = new QActionButton(0);
        actionbtn->setText("Отложить станок");
        actionbtn->setLocPtr(m_currentLoc);
        m_actLayout->addWidget(actionbtn);
        connect(actionbtn, &QActionButton::sigChangeSubLoc, this, &LocationForm::slotChangeLoc);
    }
    if(action == "shavePubic")
    {
        m_time->increaseTime(15);
        m_player->updVBody(pubisHair, -5);
        m_player->updVStatus(horny, 5);
        m_bag->removeFromBag(razor, 1);
        emit sigUpdParams();
        videoWidg->setQUrl("qrc:/actions/shave/pubic.webm");
        ui->labelLocDesc->setText("Вы намыливаете лобок, и взяв бритву, ловкими движениями сбриваете волоски вокруг киски.");
        ui->imageAndWideoWdgt->setCurrentIndex(1);
        ClearLayout(m_actLayout);

        QActionButton* actionbtn = new QActionButton(0);
        actionbtn->setText("Отложить станок");
        actionbtn->setLocPtr(m_currentLoc);
        m_actLayout->addWidget(actionbtn);
        connect(actionbtn, &QActionButton::sigChangeSubLoc, this, &LocationForm::slotChangeLoc);
    }
}

QString LocationForm::bathStr(int value)
{

    return QString();
}

QString LocationForm::bathActStr(int value)
{
    return QString();
}
