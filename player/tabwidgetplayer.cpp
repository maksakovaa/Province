#include "tabwidgetplayer.h"
#include "ui_tabwidgetplayer.h"
#include "../Functions.h"
#include <QLayoutItem>
#include "../game.h"

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

void TabWidgetPlayer::setPtr(Game *ptr)
{
    root = ptr;
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
    QString desc = root->getNameDesc() + "<br>";
    desc += root->getBirthDayDesc() + "<br><br>";
    desc += root->getAgesDesc() + "<br>";
    desc += root->getHeightDesc() + "<br>";
    desc += root->getBodyDesc() + "<br>";
    desc += root->getBreastsDesc() + "<br>";
    desc += root->getBodyTypeFigureDesc() + "<br>";
    desc += root->getVneshDesc() + "<br>";
    desc += root->getHairDesc() + "<br>";
    desc += root->getLipsDesc() + "<br>";
    desc += root->getThroatDesc() + "<br>";
    desc += root->getSkinDesc() + "<br>";
    desc += root->getEyeDesc() + "<br>";
    desc += root->getMakeupDesc() + "<br>";
    desc += root->getLegsDesc() + "<br>";
    desc += root->getPubisDesc() + "<br>";
    desc += root->getVaginaDesc() + "<br>";
    desc += root->getAnusDesc() + "<br>";
    desc += root->getShamelessDesc();

    QString arr[] { "Лицо", "Одежда","Тело","Грудь","Лобок","Вагина","Анус" };
    QString img[] {root->getPlayerFace(),
                  root->getPlayerClothes(),
                  root->getPlayerBody(),
                  root->getPlayerBreasts(),
                  root->getPlayerPubis(),
                  root->getPlayerVagina(),
                  root->getPlayerAnus()};
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
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(std::abs(root->vSkill(static_cast<Skills>(i))));
        }
        else if(i == 22)
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(root->vSchool(progress));
        }
        else if(i == 23)
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(root->vSchool(absent));
        }
        else
        {
            ((QProgressBar*)ui->formLayout->itemAt(i, QFormLayout::LabelRole)->widget())->setValue(root->vSkill(static_cast<Skills>(i)));
        }
    }
    
    setBarStyle();
    loadStrings();
}

void TabWidgetPlayer::cheatSkillCheck()
{
    if(root->vSkill(strenght) > 100)
        root->vSkill(strenght) = 5;
    if(root->vSkill(speed) > 100)
        root->vSkill(speed) = 5;
    if(root->vSkill(agility) > 100)
        root->vSkill(agility) = 5;
    if(root->vSkill(endurance) > 100)
        root->vSkill(endurance) = 5;
    if(root->vSkill(intellect) > 100)
        root->vSkill(intellect) = 5;
    if(root->vSkill(react) > 100)
        root->vSkill(react) = 5;
    if(root->vSkill(domination) > 100)
        root->vSkill(domination) = -100;
    if(root->vSkill(jab) > 120)
        root->vSkill(jab) = 0;
    if(root->vSkill(punch) > 120)
        root->vSkill(punch) = 0;
    if(root->vSkill(kik) > 120)
        root->vSkill(kik) = 0;
    if(root->vSkill(kikDef) > 120)
        root->vSkill(kikDef) = 0;
    if(root->vSkill(boxing) > 120)
        root->vSkill(boxing) = 0;
    if(root->vSkill(runner) > 2000)
        root->vSkill(runner) = 10;
    if(root->vSkill(volleyball) > 100)
        root->vSkill(volleyball) = 0;
    if(root->vSkill(oficiant) > 100)
        root->vSkill(oficiant) = 0;
    if(root->vSkill(maid) > 100)
        root->vSkill(maid) = 0;
    if(root->vSkill(vokal) > 100)
        root->vSkill(vokal) = 0;
    if(root->vSkill(dance) > 100)
        root->vSkill(dance) = 0;
    if(root->vSkill(dancePro) > 100)
        root->vSkill(dancePro) = 0;
    if(root->vSkill(danceStrip) > 100)
        root->vSkill(danceStrip) = 0;
    if(root->vSkill(dancePole) > 100)
        root->vSkill(dancePole) = 0;
    if(root->vSkill(posSkill) > 1000)
        root->vSkill(posSkill) = 0;
}

void TabWidgetPlayer::setBarStyle()
{
    int type;
    if(root->vSkill(Skills::domination) < 0) { type = 1; }
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

void TabWidgetPlayer::loadStrings()
{
    std::vector<QString> strings {"сила", "скорость","ловкость",
        "выносливость","интеллект","Реакция","Доминантность","Джебы",
        "Силовые удары","Удары ногами","Защита от ударов","Навыки бокса",
        "Бег","Воллейбол","Навыки официантки","Навыки горничной","Вокал",
        "Танцы","Проф.танцы","Стриптиз","Танцы на шесте","Кройка и шитьё",
        "Успеваемость","Прогулы"};
    int dom = root->vSkill(Skills::domination);
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

    if(root->isCheats())
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
        root->vBody(vidage) += 1;
        if(root->vBody(vidage) > 24)
            root->vBody(vidage) = 16;
    }
    if (link == "skinTan")
    {
        int cur = root->vBody(skinTan);
        if (cur == 0)
            root->vBody(skinTan) = 10;
        else if (cur > 0 && cur <= 30)
            root->vBody(skinTan) = 70;
        else if (cur > 30 && cur <= 100)
            root->vBody(skinTan) = 120;
        else
            root->vBody(skinTan) = 0;
    }
    if (link == "skin")
    {
        root->vBody(skin) += 1;
        if(root->vBody(skin) > 4)
            root->vBody(skin) = 0;
    }
    if (link == "lips")
    {
        root->vBody(lip) += 1;
        if(root->vBody(lip) > 4)
            root->vBody(lip) = 0;
    }
    if (link == "anus")
    {
        int val = root->vBody(anus);
        if (val == 0)
        {
            root->vBody(anus) = 1;
            if(root->vStatistics(analSex) < 1)
                root->vStatistics(analSex) =1;
        }
        else if (val > 0 && val <= 5)
        {
            root->vBody(anus) = 6;
            if(root->vStatistics(analSex) < 6)
                root->vStatistics(analSex) =6;
        }
        else if (val > 5 && val <= 10)
        {
            root->vBody(anus) = 11;
            if(root->vStatistics(analSex) < 6)
                root->vStatistics(analSex) =6;
        }
        else if (val > 10 && val <= 15)
        {
            root->vBody(anus) = 16;
            if(root->vStatistics(analSex) < 51)
                root->vStatistics(analSex) =51;
        }
        else if (val > 15 && val <= 25)
        {
            root->vBody(anus) = 26;
            if(root->vStatistics(analSex) < 201)
                root->vStatistics(analSex) =201;
        }
        else if (val > 25 && val <= 35)
        {
            root->vBody(anus) = 36;
            if(root->vStatistics(analSex) < 201)
                root->vStatistics(analSex) =201;
        }
        else
        {
            root->vBody(anus) = 0;
            root->vStatistics(analSex) =0;
        }
    }
    if (link == "vagina")
    {
        int vag = root->vBody(vagina);
        if (vag == 0)
        {
            root->vBody(vagina) = 1;
            if(root->vStatistics(vaginalSex) < 1)
                root->vStatistics(vaginalSex) =1;
        }
        else if (vag > 0 && vag <= 5)
        {
            root->vBody(vagina) = 6;
            if(root->vStatistics(vaginalSex) < 6)
                root->vStatistics(vaginalSex) =6;
        }
        else if (vag > 5 && vag <= 10)
        {
            root->vBody(vagina) = 11;
            if(root->vStatistics(vaginalSex) < 6)
                root->vStatistics(vaginalSex) =6;
        }
        else if (vag > 10 && vag <= 15)
        {
            root->vBody(vagina) = 16;
            if(root->vStatistics(vaginalSex) < 51)
                root->vStatistics(vaginalSex) =51;
        }
        else if (vag > 15 && vag <= 25)
        {
            root->vBody(vagina) = 26;
            if(root->vStatistics(vaginalSex) < 201)
                root->vStatistics(vaginalSex) =201;
        }
        else if (vag > 25 && vag <= 35)
        {
            root->vBody(vagina) = 36;
            if(root->vStatistics(vaginalSex) < 201)
                root->vStatistics(vaginalSex) =201;
        }
        else
        {
            root->vBody(vagina) = 0;
            root->vStatistics(vaginalSex) =0;
        }
    }
    if (link == "throat")
    {
        int thrVal = root->vBody(throat);
        if (thrVal == 0)
            root->vBody(throat) += 1;
        else if (thrVal > 0 && thrVal <= 15)
            root->vBody(throat) += 5;
        else if (thrVal > 15 && thrVal <= 35)
            root->vBody(throat) += 10;
        else
            root->vBody(throat) = 0;
    }
    if (link == "pubisHair")
    {
        root->vBody(pubisHair) += 2;
        if(root->vBody(pubisHair) > 4)
        {
            root->vBody(pubisHair) = 0;
        }
    }
    if (link == "legHair")
    {
        if (root->vBody(legHair) == 3)
        {
            root->vBody(legHair) += 3;
        }
        else
        {
            root->vBody(legHair) += 2;
        }
        if(root->vBody(legHair) > 6)
        {
            root->vBody(legHair) = 0;
        }
        
    }
    if (link == "weight")
    {
        root->vBody(weight) += 1;
        if(root->vBody(weight) > 100)
            root->vBody(weight) = 40;
    }
    if (link == "height")
    {
        root->vBody(Body::height) += 1;
        if(root->vBody(Body::height) > 180)
            root->vBody(Body::height) = 160;
    }
    if (link == "makeup")
    {
        root->vBody(makeup) += 1;
        if(root->vBody(makeup) >= 5)
            root->vBody(makeup) = 0;
    }
    if (link == "hairCurly")
    {
        root->vBody(hairCurly) += 10;
        if(root->vBody(hairCurly) > 10)
            root->vBody(hairCurly) = 0;
    }
    if (link == "hairColor")
    {
        root->vBody(hairColor) += 1;
        if(root->vBody(hairColor) >= 4)
            root->vBody(hairColor) = 0;
    }
    if (link == "hairLength")
    {
        root->vBody(hairLength) += 1;
        if(root->vBody(hairLength) >= 4)
            root->vBody(hairLength) = 0;
    }
    if (link == "eyeColor")
    {
        root->vBody(eyeColor) += 1;
        if(root->vBody(eyeColor) > 3)
            root->vBody(eyeColor) = 0;
    }
    if (link == "eyeSize")
    {
        root->vBody(eyeSize) += 1;
        if(root->vBody(eyeSize) > 3)
            root->vBody(eyeSize) = 0;
    }
    if (link == "eyeLashes")
    {
        root->vBody(eyeLashes) += 1;
        if(root->vBody(eyeLashes) > 2)
            root->vBody(eyeLashes) = 0;
    }
    if (link == "eyeBrows")
    {
        root->vBody(eyeBrows) += 10;
        if(root->vBody(eyeBrows) >= 20)
            root->vBody(eyeBrows) = -1;
    }
    if (link == "glass")
    {
        root->vBody(glass) += 1;
        if(root->vBody(glass) > 3)
            root->vBody(glass) = 1;
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
        root->vSkill(Skills::jab) += value;
        root->vSkill(Skills::punch) += value;
        root->vSkill(Skills::kik) += value;
        root->vSkill(Skills::kikDef) += value;
    }
    else
    {
        if (skill == Skills::runner) { value = 20; }
        else if (skill == Skills::volleyball) { value = 10; }
        else if (skill == Skills::posSkill) { value = 50; }
        else { value = 5; }
        root->vSkill(skill) += value;
    }
    cheatSkillCheck();
    fillCharacteristics();
}

void TabWidgetPlayer::slotSchoolUpdate(const QString &link)
{
    if(link == "22")
    {
        root->vSchool(progress) +=5;
        if(root->vSchool(progress) > 100)
            root->vSchool(progress) = 0;
    }
    if(link == "23")
    {
        root->vSchool(absent) += 3;
        if(root->vSchool(absent) > 30)
            root->vSchool(absent) = 0;
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

