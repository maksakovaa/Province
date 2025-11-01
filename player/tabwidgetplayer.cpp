#include "tabwidgetplayer.h"
#include "ui_tabwidgetplayer.h"
#include "../Functions.h"
#include <QLayoutItem>

TabWidgetPlayer::TabWidgetPlayer(QWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::TabWidgetPlayer)
{
    ui->setupUi(this);
    connections();
}

TabWidgetPlayer::~TabWidgetPlayer()
{
    delete ui;
}

void TabWidgetPlayer::setPtr(Player *ptr)
{
    m_player = ptr;
    fillBodyDesc();
    fillCharacteristics();
    loadStrings();
}

void TabWidgetPlayer::reload()
{
    fillBodyDesc();
    fillCharacteristics();
    setBarStyle();
    loadStrings();
}

void TabWidgetPlayer::fillBodyDesc()
{
    QString desc = m_player->getNameDesc() + "<br>";
    desc += m_player->getBirthDayDesc() + "<br><br>";
    desc += m_player->getAgesDesc() + "<br>";
    desc += m_player->getHeightDesc() + "<br>";
    desc += m_player->getBodyDesc() + "<br>";
    desc += m_player->getBreastsDesc() + "<br>";
    desc += m_player->getBodyTypeFigureDesc() + "<br>";
    desc += m_player->getVneshDesc() + "<br>";
    desc += m_player->getHairDesc() + "<br>";
    desc += m_player->getLipsDesc() + "<br>";
    desc += m_player->getThroatDesc() + "<br>";
    desc += m_player->getSkinDesc() + "<br>";
    desc += m_player->getEyeDesc() + "<br>";
    desc += m_player->getMakeupDesc() + "<br>";
    desc += m_player->getLegsDesc() + "<br>";
    desc += m_player->getPubisDesc() + "<br>";
    desc += m_player->getVaginaDesc() + "<br>";
    desc += m_player->getAnusDesc() + "<br>";
    desc += m_player->getShamelessDesc();

    QString arr[] { "Лицо", "Одежда","Тело","Грудь","Лобок","Вагина","Анус" };
    QString img[] {m_player->getPlayerFace(),
                  m_player->getPlayerClothes(),
                  m_player->getPlayerBody(),
                  m_player->getPlayerBreasts(),
                  m_player->getPlayerPubis(),
                  m_player->getPlayerVagina(),
                  m_player->getPlayerAnus()};
    QString tabs;
    if(currView == -1) { currView = 0; }
    for (int i = 0; i < 7; ++i)
    {
        if(i == currView) { tabs += "<td>" + arr[i] + "</td>"; }
        else { tabs += "<td style='background: #e6f4be;'><a style='text-decoration:none; color: black' href='view" + intQStr(i) + "'>" + arr[i] + "</a></td>"; }
    }
    desc = "<table><tr>" + tabs + "<td rowspan = 2>" + desc + "</td>"
                    "</tr><tr><td colspan = 7>" + img[currView] + "</td></tr></table>";

    ui->label_pers_desc->setWordWrap(true);
    ui->label_pers_desc->setText(desc);
}

void TabWidgetPlayer::fillCharacteristics()
{
    for (int i = 0; i < ui->formLayout->rowCount(); i++)
    {
        if (i == 6)
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(std::abs(m_player->getSkillValue(static_cast<Skills>(i))));
        }
        else
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(m_player->getSkillValue(static_cast<Skills>(i)));
        }
    }
    
    setBarStyle();
    loadStrings();
}

void TabWidgetPlayer::setBarStyle()
{
    int type;
    if(m_player->getSkillValue(Skills::domination) < 0) { type = 1; }
    else { type = 0; }

    for (int i = 0; i < ui->formLayout->rowCount(); i++)
    {
        QProgressBar* ptr = (QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget();
        QString style;
        if (i == 6)
        {
            style = styleForBar(ptr->value(),ptr->maximum(),type);
        }
        else
        {
            style = styleForBar(ptr->value(),ptr->maximum(),0);
        }

        ptr->setStyleSheet(style);
    }
}

void TabWidgetPlayer::updBodyVal(Body param, int val)
{
    m_player->updVBody(param, val);
}

void TabWidgetPlayer::loadStrings()
{
    std::vector<QString> strings {"сила", "скорость","ловкость",
        "выносливость","интеллект","Реакция","Доминантность","Джебы",
        "Силовые удары","Удары ногами","Защита от ударов","Навыки бокса",
        "Бег","Воллейбол","Навыки официантки","Навыки горничной","Вокал",
        "Танцы","Проф.танцы","Стриптиз","Танцы на шесте","Кройка и шитьё",
        "Успеваемость","Прогулы"};
    int dom = m_player->getSkillValue(Skills::domination);
    if (dom < 0)
    {
        strings[Skills::domination] = "Сабмиссивность: ";
    }
    else
    {
        strings[Skills::domination] = "Доминантность: ";
    }
    QString domina;
    if(dom <= -10)
    {
        if(dom <= -10 && dom > -25)
        {
            domina = "Склонная к подчинению";
        }
        else if (dom <= -25 && dom > -50)
        {
            domina = "Покорная";
        }
        else if (dom <= -50 && dom > -75)
        {
            domina = "Рабыня";
        }
        else if (dom <= -75)
        {
            domina = "На всё готовая рабыня";
        }
    }
    else if (dom >= 10)
    {
        if (dom >= 10 && dom < 25) { domina = "Склонная к доминированию"; }
        if (dom >= 25 && dom < 50) { domina = "Домина"; }
        if (dom >= 50 && dom < 75) { domina = "Госпожа"; }
        if (dom >= 75) { domina = "Строгая госпожа"; }
    }
    else
    {
        domina += "Без склонностей";
    }

//Block Skill description
    QString result;

    if(m_player->isCheatsOn())
    {
        for (int i = 0; i < strings.size(); ++i)
        {
            if (i != Skills::domination)
            {
                makeLink(strings[i], QString::number(i));
            }
            else
            {
                makeLink(domina, QString::number(i));
                strings[Skills::domination] += domina;
            }
        }
    }

    for (int i = 0; i < ui->formLayout->rowCount(); ++i)
    {
        QLabel* ptr = (QLabel*)ui->formLayout->itemAt(i, QFormLayout::FieldRole)->widget();
        ptr->setText(strings[i]);
    }
}

void TabWidgetPlayer::on_label_pers_desc_linkActivated(const QString &link)
{
    if(link == "view0") { currView = 0; }
    if(link == "view1") { currView = 1; }
    if(link == "view2") { currView = 2; }
    if(link == "view3") { currView = 3; }
    if(link == "view4") { currView = 4; }
    if(link == "view5") { currView = 5; }
    if(link == "view6") { currView = 6; }

    if(link == "vidage")
    {       
        updBodyVal(Body::vidage, 1);
    }
    if (link == "skinTan")
    {
        int cur = m_player->getVBody(Body::skinTan);
        if (cur == 0)
        {
            updBodyVal(Body::skinTan, 10);
        }
        else if (cur > 0 && cur <= 30)
        {
            updBodyVal(Body::skinTan, 70 - cur);
        }
        else if (cur > 30 && cur <= 100)
        {
            updBodyVal(Body::skinTan, 120 - cur);
        }
        else
        {
            updBodyVal(Body::skinTan, 0 - cur);
        }
    }
    if (link == "skin")
    {
        updBodyVal(Body::skin, 1);
    }
    if (link == "lips")
    {
        updBodyVal(Body::lip, 1);
    }
    if (link == "anus")
    {
        int anus = m_player->getVBody(Body::anus);
        if (anus == 0)
        {
            updBodyVal(Body::anus, 1);   
        }
        else if (anus > 0 && anus <= 5)
        {
            updBodyVal(Body::anus, 6 - anus);
        }
        else if (anus > 5 && anus <= 10)
        {
            updBodyVal(Body::anus, 11 - anus);
        }
        else if (anus > 10 && anus <= 15)
        {
            updBodyVal(Body::anus, 16 - anus);
        }
        else if (anus > 15 && anus <= 25)
        {
            updBodyVal(Body::anus, 26 - anus);
        }
        else if (anus > 25 && anus <= 35)
        {
            updBodyVal(Body::anus, 36 - anus);
        }
        else
        {
            updBodyVal(Body::anus, 0 - anus);
        }
    }
    if (link == "vagina")
    {
        int vag = m_player->getVBody(Body::vagina);
        if (vag == 0)
        {
            updBodyVal(Body::vagina, 1);
        }
        else if (vag > 0 && vag <= 5)
        {
            updBodyVal(Body::vagina, 6 - vag);
        }
        else if (vag > 5 && vag <= 10)
        {
            updBodyVal(Body::vagina, 11 - vag);
        }
        else if (vag > 10 && vag <= 15)
        {
            updBodyVal(Body::vagina, 16 - vag);
        }
        else if (vag > 15 && vag <= 25)
        {
            updBodyVal(Body::vagina, 26 - vag);
        }
        else if (vag > 25 && vag <= 35)
        {
            updBodyVal(Body::vagina, 36 - vag);
        }
        else
        {
            updBodyVal(Body::vagina, 0 - vag);
        }
        
    }
    if (link == "throat")
    {
        int thrVal = m_player->getVBody(Body::throat);
        if (thrVal == 0)
        {
            updBodyVal(Body::throat, 1);
        }
        else if (thrVal > 0 && thrVal <= 15)
        {
            updBodyVal(Body::throat, 5);
        }
        else if (thrVal > 15 && thrVal <= 35)
        {
            updBodyVal(Body::throat, 10);
        }
        else
        {
            updBodyVal(Body::throat, 0 - thrVal);
        }
    }
    if (link == "pubisHair")
    {
        updBodyVal(Body::pubisHair, 2);
        if(m_player->getVBody(Body::pubisHair) > 4)
        {
            m_player->setVBody(Body::pubisHair, 0);
        }
    }
    if (link == "legHair")
    {
        if (m_player->getVBody(Body::legHair) == 3)
        {
            updBodyVal(Body::legHair, 3);
        }
        else
        {
            updBodyVal(Body::legHair, 2);
        }
        if(m_player->getVBody(Body::legHair) > 6)
        {
            m_player->setVBody(Body::legHair, 0);
        }
        
    }
    if (link == "weight")
    {
        updBodyVal(Body::weight, 1);
    }
    if (link == "height")
    {
        updBodyVal(Body::height, 1);
    }
    if (link == "makeup")
    {
        updBodyVal(Body::makeup, 1);
    }
    if (link == "hairCurly")
    {
        updBodyVal(Body::hairCurly, 10);
    }
    if (link == "hairColor")
    {
        updBodyVal(Body::hairColor, 1);
    }
    if (link == "hairLength")
    {
        updBodyVal(Body::hairLength, 1);
    }
    if (link == "eyeColor")
    {
        updBodyVal(Body::eyeColor, 1);
    }
    if (link == "eyeSize")
    {
        updBodyVal(Body::eyeSize, 1);
    }
    if (link == "eyeLashes")
    {
        updBodyVal(Body::eyeLashes, 1);
    }
    if (link == "eyeBrows")
    {
        updBodyVal(Body::eyeBrows, 10);
    }
    if (link == "glass")
    {
        updBodyVal(Body::glass, 1);
    }    
    fillBodyDesc();
    emit sigUpdateStatus();
}


void TabWidgetPlayer::slotSkillUpdate(const QString &link)
{
    Skills skill = static_cast<Skills>(link.toInt());
    int value;
    if(skill == Skills::boxing)
    {
        value = 4;
        m_player->updVSkill(Skills::jab, value);
        m_player->updVSkill(Skills::punch, value);
        m_player->updVSkill(Skills::kik, value);
        m_player->updVSkill(Skills::kikDef, value);
    }
    else
    {
        if (skill == Skills::runner) { value = 20; }
        else if (skill == Skills::volleyball) { value = 10; }
        else if (skill == Skills::posSkill) { value = 50; }
        else if (skill == Skills::truancy) { value = 3; }
        else { value = 5; }
        m_player->updVSkill(skill, value);
    }
    fillCharacteristics();
}

void TabWidgetPlayer::connections()
{
    for(int i = 0; i < ui->formLayout->rowCount(); ++i)
    {
        connect(((QLabel*)ui->formLayout->itemAt(i, QFormLayout::FieldRole)->widget()), &QLabel::linkActivated, this, &TabWidgetPlayer::slotSkillUpdate);
    }
}

