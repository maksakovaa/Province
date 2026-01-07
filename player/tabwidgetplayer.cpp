#include "tabwidgetplayer.h"
#include "ui_tabwidgetplayer.h"
#include "../Functions.h"
#include <QLayoutItem>
#include "../nav/locationhandler.h"

TabWidgetPlayer::TabWidgetPlayer(QWidget* parent)
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

void TabWidgetPlayer::setPtr(Player *ptr, LocationHandler* locHandlerPtr)
{
    m_player = ptr;
    locHandler = locHandlerPtr;
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
        else if(i == 22)
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(locHandler->gVSchool(progress));
        }
        else if(i == 23)
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(locHandler->gVSchool(absent));
        }
        else
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(m_player->getSkillValue(static_cast<Skills>(i)));
        }
    }
    
    setBarStyle();
    loadStrings();
}

void TabWidgetPlayer::cheatSkillCheck()
{
    if(m_player->getSkillValue(strenght) > 100)
        m_player->setVSkill(strenght,5);
    if(m_player->getSkillValue(speed) > 100)
        m_player->setVSkill(speed,5);
    if(m_player->getSkillValue(agility) > 100)
        m_player->setVSkill(agility,5);
    if(m_player->getSkillValue(endurance) > 100)
        m_player->setVSkill(endurance,5);
    if(m_player->getSkillValue(intellect) > 100)
        m_player->setVSkill(intellect,5);
    if(m_player->getSkillValue(react) > 100)
        m_player->setVSkill(react,5);
    if(m_player->getSkillValue(domination) > 100)
        m_player->setVSkill(domination,-100);
    if(m_player->getSkillValue(jab) > 120)
        m_player->setVSkill(jab,0);
    if(m_player->getSkillValue(punch) > 120)
        m_player->setVSkill(punch,0);
    if(m_player->getSkillValue(kik) > 120)
        m_player->setVSkill(kik,0);
    if(m_player->getSkillValue(kikDef) > 120)
        m_player->setVSkill(kikDef,0);
    if(m_player->getSkillValue(boxing) > 120)
        m_player->setVSkill(boxing,0);
    if(m_player->getSkillValue(runner) > 2000)
        m_player->setVSkill(runner,10);
    if(m_player->getSkillValue(volleyball) > 100)
        m_player->setVSkill(volleyball,0);
    if(m_player->getSkillValue(oficiant) > 100)
        m_player->setVSkill(oficiant,0);
    if(m_player->getSkillValue(maid) > 100)
        m_player->setVSkill(maid,0);
    if(m_player->getSkillValue(vokal) > 100)
        m_player->setVSkill(vokal,0);
    if(m_player->getSkillValue(dance) > 100)
        m_player->setVSkill(dance,0);
    if(m_player->getSkillValue(dancePro) > 100)
        m_player->setVSkill(dancePro,0);
    if(m_player->getSkillValue(danceStrip) > 100)
        m_player->setVSkill(danceStrip,0);
    if(m_player->getSkillValue(dancePole) > 100)
        m_player->setVSkill(dancePole,0);
    if(m_player->getSkillValue(posSkill) > 1000)
        m_player->setVSkill(posSkill,0);

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

int TabWidgetPlayer::getVBody(Body param)
{
    return m_player->getVBody(param);
}

void TabWidgetPlayer::updBodyVal(Body param, int val)
{
    m_player->updVBody(param, val);
}

void TabWidgetPlayer::setVBody(Body param, int val)
{
    m_player->setVBody(param,val);
}

int TabWidgetPlayer::getVSc(SC param)
{
    return m_player->getStatisticsValue(param);
}

void TabWidgetPlayer::setVSc(SC param, int val)
{
    m_player->setVSC(param,val);
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
        if(getVBody(vidage) > 24)
            setVBody(vidage,16);
    }
    if (link == "skinTan")
    {
        int cur = getVBody(Body::skinTan);
        if (cur == 0)
            setVBody(Body::skinTan, 10);
        else if (cur > 0 && cur <= 30)
            setVBody(Body::skinTan, 70);
        else if (cur > 30 && cur <= 100)
            setVBody(Body::skinTan, 120);
        else
            setVBody(Body::skinTan, 0);
    }
    if (link == "skin")
    {
        updBodyVal(Body::skin, 1);
        if(getVBody(skin) > 4)
            setVBody(skin,0);
    }
    if (link == "lips")
    {
        updBodyVal(Body::lip, 1);
        if(getVBody(lip) > 4)
            setVBody(lip, 0);
    }
    if (link == "anus")
    {
        int anus = m_player->getVBody(Body::anus);
        if (anus == 0)
        {
            setVBody(Body::anus, 1);
            if(getVSc(analSex) < 1)
                setVSc(analSex,1);
        }
        else if (anus > 0 && anus <= 5)
        {
            setVBody(Body::anus, 6);
            if(getVSc(analSex) < 6)
                setVSc(analSex,6);
        }
        else if (anus > 5 && anus <= 10)
        {
            setVBody(Body::anus, 11);
            if(getVSc(analSex) < 6)
                setVSc(analSex,6);
        }
        else if (anus > 10 && anus <= 15)
        {
            setVBody(Body::anus, 16);
            if(getVSc(analSex) < 51)
                setVSc(analSex,51);
        }
        else if (anus > 15 && anus <= 25)
        {
            setVBody(Body::anus, 26);
            if(getVSc(analSex) < 201)
                setVSc(analSex,201);
        }
        else if (anus > 25 && anus <= 35)
        {
            setVBody(Body::anus, 36);
            if(getVSc(analSex) < 201)
                setVSc(analSex,201);
        }
        else
        {
            setVBody(Body::anus, 0);
            setVSc(analSex,0);
        }
    }
    if (link == "vagina")
    {
        int vag = m_player->getVBody(Body::vagina);
        if (vag == 0)
        {
            setVBody(Body::vagina, 1);
            if(getVSc(vaginalSex) < 1)
                setVSc(vaginalSex,1);
        }
        else if (vag > 0 && vag <= 5)
        {
            setVBody(Body::vagina, 6);
            if(getVSc(vaginalSex) < 6)
                setVSc(vaginalSex,6);
        }
        else if (vag > 5 && vag <= 10)
        {
            setVBody(Body::vagina, 11);
            if(getVSc(vaginalSex) < 6)
                setVSc(vaginalSex,6);
        }
        else if (vag > 10 && vag <= 15)
        {
            setVBody(Body::vagina, 16);
            if(getVSc(vaginalSex) < 51)
                setVSc(vaginalSex,51);
        }
        else if (vag > 15 && vag <= 25)
        {
            setVBody(Body::vagina, 26);
            if(getVSc(vaginalSex) < 201)
                setVSc(vaginalSex,201);
        }
        else if (vag > 25 && vag <= 35)
        {
            setVBody(Body::vagina, 36);
            if(getVSc(vaginalSex) < 201)
                setVSc(vaginalSex,201);
        }
        else
        {
            setVBody(Body::vagina, 0);
            setVSc(vaginalSex,0);
        }
    }
    if (link == "throat")
    {
        int thrVal = m_player->getVBody(Body::throat);
        if (thrVal == 0)
            updBodyVal(Body::throat, 1);
        else if (thrVal > 0 && thrVal <= 15)
            updBodyVal(Body::throat, 5);
        else if (thrVal > 15 && thrVal <= 35)
            updBodyVal(Body::throat, 10);
        else
            setVBody(Body::throat, 0);
    }
    if (link == "pubisHair")
    {
        updBodyVal(Body::pubisHair, 2);
        if(getVBody(Body::pubisHair) > 4)
        {
            setVBody(Body::pubisHair, 0);
        }
    }
    if (link == "legHair")
    {
        if (getVBody(Body::legHair) == 3)
        {
            updBodyVal(Body::legHair, 3);
        }
        else
        {
            updBodyVal(Body::legHair, 2);
        }
        if(getVBody(Body::legHair) > 6)
        {
            setVBody(Body::legHair, 0);
        }
        
    }
    if (link == "weight")
    {
        updBodyVal(Body::weight, 1);
        if(getVBody(weight) > 100)
            setVBody(weight,40);
    }
    if (link == "height")
    {
        updBodyVal(Body::height, 1);
        if(getVBody(Body::height) > 180)
            setVBody(Body::height,160);
    }
    if (link == "makeup")
    {
        updBodyVal(Body::makeup, 1);
        if(getVBody(makeup) >= 5)
            setVBody(makeup,0);
    }
    if (link == "hairCurly")
    {
        updBodyVal(Body::hairCurly, 10);
        if(getVBody(hairCurly) > 10)
            setVBody(hairCurly,0);
    }
    if (link == "hairColor")
    {
        updBodyVal(Body::hairColor, 1);
        if(getVBody(hairColor) >= 4)
            setVBody(hairColor,0);
    }
    if (link == "hairLength")
    {
        updBodyVal(Body::hairLength, 1);
        if(getVBody(hairLength) >= 4)
            setVBody(hairLength,0);
    }
    if (link == "eyeColor")
    {
        updBodyVal(Body::eyeColor, 1);
        if(getVBody(eyeColor) > 3)
            setVBody(eyeColor,0);
    }
    if (link == "eyeSize")
    {
        updBodyVal(Body::eyeSize, 1);
        if(getVBody(eyeSize) > 3)
            setVBody(eyeSize,0);
    }
    if (link == "eyeLashes")
    {
        updBodyVal(Body::eyeLashes, 1);
        if(getVBody(eyeLashes) > 2)
            setVBody(eyeLashes,0);
    }
    if (link == "eyeBrows")
    {
        updBodyVal(Body::eyeBrows, 10);
        if(getVBody(eyeBrows) >= 20)
            setVBody(eyeBrows,-1);
    }
    if (link == "glass")
    {
        updBodyVal(Body::glass, 1);
        if(getVBody(glass) > 3)
            setVBody(glass,1);
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
        else { value = 5; }
        m_player->updVSkill(skill, value);
    }
    cheatSkillCheck();
    fillCharacteristics();
}

void TabWidgetPlayer::slotSchoolUpdate(const QString &link)
{
    if(link == "22")
    {
        locHandler->uVSchool(progress,5);
        if(locHandler->gVSchool(progress) > 100)
            locHandler->sVSchool(progress,0);
    }
    if(link == "23")
    {
        locHandler->uVSchool(absent,3);
        if(locHandler->gVSchool(absent) > 30)
            locHandler->sVSchool(absent,0);
    }
    fillCharacteristics();
}

void TabWidgetPlayer::connections()
{
    for(int i = 0; i < ui->formLayout->rowCount() - 2; ++i)
    {
        connect(((QLabel*)ui->formLayout->itemAt(i, QFormLayout::FieldRole)->widget()), &QLabel::linkActivated, this, &TabWidgetPlayer::slotSkillUpdate);
    }
    connect(((QLabel*)ui->formLayout->itemAt(22, QFormLayout::FieldRole)->widget()), &QLabel::linkActivated, this, &TabWidgetPlayer::slotSchoolUpdate);
    connect(((QLabel*)ui->formLayout->itemAt(23, QFormLayout::FieldRole)->widget()), &QLabel::linkActivated, this, &TabWidgetPlayer::slotSchoolUpdate);
}

