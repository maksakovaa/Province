#include "tabwidgetplayer.h"
#include "ui_tabwidgetplayer.h"
#include "../Functions.h"

TabWidgetPlayer::TabWidgetPlayer(QWidget *parent)
    : QTabWidget(parent)
    , ui(new Ui::TabWidgetPlayer)
{
    ui->setupUi(this);
}

TabWidgetPlayer::~TabWidgetPlayer()
{
    delete ui;
}

void TabWidgetPlayer::setPtr(Player *ptr)
{
    ptrToMplayer = ptr;
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
    QString desc = ptrToMplayer->getNameDesc() + "<br>";
    desc += ptrToMplayer->getBirthDayDesc() + "<br><br>";
    desc += ptrToMplayer->getAgesDesc() + "<br>";
    desc += ptrToMplayer->getHeightDesc() + "<br>";
    desc += ptrToMplayer->getBodyDesc() + "<br>";
    desc += ptrToMplayer->getBreastsDesc() + "<br>";
    desc += ptrToMplayer->getBodyTypeFigureDesc() + "<br>";
    desc += ptrToMplayer->getVneshDesc() + "<br>";
    desc += ptrToMplayer->getHairDesc() + "<br>";
    desc += ptrToMplayer->getLipsDesc() + "<br>";
    desc += ptrToMplayer->getThroatDesc() + "<br>";
    desc += ptrToMplayer->getSkinDesc() + "<br>";
    desc += ptrToMplayer->getEyeDesc() + "<br>";
    desc += ptrToMplayer->getMakeupDesc() + "<br>";
    desc += ptrToMplayer->getLegsDesc() + "<br>";
    desc += ptrToMplayer->getPubisDesc() + "<br>";
    desc += ptrToMplayer->getVaginaDesc() + "<br>";
    desc += ptrToMplayer->getAnusDesc() + "<br>";
    desc += ptrToMplayer->getShamelessDesc();

    QString arr[] { "Лицо", "Одежда","Тело","Грудь","Лобок","Вагина","Анус" };
    QString img[] {ptrToMplayer->getPlayerFace(),
                  ptrToMplayer->getPlayerClothes(),
                  ptrToMplayer->getPlayerBody(),
                  ptrToMplayer->getPlayerBreasts(),
                  ptrToMplayer->getPlayerPubis(),
                  ptrToMplayer->getPlayerVagina(),
                  ptrToMplayer->getPlayerAnus()};
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
    ui->progressBarStrength->setValue(ptrToMplayer->getSkillValue(Skills::strenght));
    ui->progressBarSpeed->setValue(ptrToMplayer->getSkillValue(Skills::speed));
    ui->progressBarAgility->setValue(ptrToMplayer->getSkillValue(Skills::agility));
    ui->progressBarEndurance->setValue(ptrToMplayer->getSkillValue(Skills::endurance));
    ui->progressBarIntellect->setValue(ptrToMplayer->getSkillValue(Skills::intellect));
    ui->progressBarReact->setValue(ptrToMplayer->getSkillValue(Skills::react));
    ui->progressBarDomination->setValue(std::abs(ptrToMplayer->getSkillValue(Skills::domination)));
    ui->progressBarJab->setValue(ptrToMplayer->getSkillValue(Skills::jab));
    ui->progressBarPunch->setValue(ptrToMplayer->getSkillValue(Skills::punch));
    ui->progressBarKik->setValue(ptrToMplayer->getSkillValue(Skills::kik));
    ui->progressBarKikDef->setValue(ptrToMplayer->getSkillValue(Skills::kikDef));
    ui->progressBarBoxing->setValue(ptrToMplayer->getSkillValue(Skills::boxing));
    ui->progressBarRunner->setValue(ptrToMplayer->getSkillValue(Skills::runner));
    ui->progressBarVolleyball->setValue(ptrToMplayer->getSkillValue(Skills::volleyball));
    ui->progressBarOfficiant->setValue(ptrToMplayer->getSkillValue(Skills::oficiant));
    ui->progressBarMaid->setValue(ptrToMplayer->getSkillValue(Skills::maid));
    ui->progressBarVokal->setValue(ptrToMplayer->getSkillValue(Skills::vokal));
    ui->progressBarDance->setValue(ptrToMplayer->getSkillValue(Skills::dance));
    ui->progressBarDancePro->setValue(ptrToMplayer->getSkillValue(Skills::dancePro));
    ui->progressBarDanceStrip->setValue(ptrToMplayer->getSkillValue(Skills::danceStrip));
    ui->progressBarDancePole->setValue(ptrToMplayer->getSkillValue(Skills::dancePole));
    ui->progressBarPosSkill->setValue(ptrToMplayer->getSkillValue(Skills::posSkill));
    ui->progressBarSchoolProgress->setValue(ptrToMplayer->getSkillValue(Skills::schoolProgress));
    ui->progressBarTruancy->setValue(ptrToMplayer->getSkillValue(Skills::truancy));
    setBarStyle();
    loadStrings();
}

void TabWidgetPlayer::setBarStyle()
{
    int type;
    if(ptrToMplayer->getSkillValue(Skills::domination) < 0) { type = 1; }
    else { type = 0; }
    ui->progressBarStrength->setStyleSheet(styleForBar(ui->progressBarStrength->value(),ui->progressBarStrength->maximum(),0));
    ui->progressBarSpeed->setStyleSheet(styleForBar(ui->progressBarSpeed->value(),ui->progressBarSpeed->maximum(),0));
    ui->progressBarAgility->setStyleSheet(styleForBar(ui->progressBarAgility->value(),ui->progressBarAgility->maximum(),0));
    ui->progressBarEndurance->setStyleSheet(styleForBar(ui->progressBarEndurance->value(),ui->progressBarEndurance->maximum(),0));
    ui->progressBarIntellect->setStyleSheet(styleForBar(ui->progressBarIntellect->value(),ui->progressBarIntellect->maximum(),0));
    ui->progressBarReact->setStyleSheet(styleForBar(ui->progressBarReact->value(),ui->progressBarReact->maximum(),0));
    ui->progressBarDomination->setStyleSheet(styleForBar(ui->progressBarDomination->value(),ui->progressBarDomination->maximum(),type));
    ui->progressBarJab->setStyleSheet(styleForBar(ui->progressBarJab->value(),ui->progressBarJab->maximum(),0));
    ui->progressBarPunch->setStyleSheet(styleForBar(ui->progressBarPunch->value(),ui->progressBarPunch->maximum(),0));
    ui->progressBarKik->setStyleSheet(styleForBar(ui->progressBarKik->value(),ui->progressBarKik->maximum(),0));
    ui->progressBarKikDef->setStyleSheet(styleForBar(ui->progressBarKikDef->value(),ui->progressBarKikDef->maximum(),0));
    ui->progressBarBoxing->setStyleSheet(styleForBar(ui->progressBarBoxing->value(),ui->progressBarBoxing->maximum(),0));
    ui->progressBarRunner->setStyleSheet(styleForBar(ui->progressBarRunner->value(),ui->progressBarRunner->maximum(),0));
    ui->progressBarVolleyball->setStyleSheet(styleForBar(ui->progressBarVolleyball->value(),ui->progressBarVolleyball->maximum(),0));
    ui->progressBarOfficiant->setStyleSheet(styleForBar(ui->progressBarOfficiant->value(),ui->progressBarOfficiant->maximum(),0));
    ui->progressBarMaid->setStyleSheet(styleForBar(ui->progressBarMaid->value(),ui->progressBarMaid->maximum(),0));
    ui->progressBarVokal->setStyleSheet(styleForBar(ui->progressBarVokal->value(),ui->progressBarVokal->maximum(),0));
    ui->progressBarDance->setStyleSheet(styleForBar(ui->progressBarDance->value(),ui->progressBarDance->maximum(),0));
    ui->progressBarDancePro->setStyleSheet(styleForBar(ui->progressBarDancePro->value(),ui->progressBarDancePro->maximum(),0));
    ui->progressBarDanceStrip->setStyleSheet(styleForBar(ui->progressBarDanceStrip->value(),ui->progressBarDanceStrip->maximum(),0));
    ui->progressBarDancePole->setStyleSheet(styleForBar(ui->progressBarDancePole->value(),ui->progressBarDancePole->maximum(),0));
    ui->progressBarPosSkill->setStyleSheet(styleForBar(ui->progressBarPosSkill->value(),ui->progressBarPosSkill->maximum(),0));
    ui->progressBarSchoolProgress->setStyleSheet(styleForBar(ui->progressBarSchoolProgress->value(),ui->progressBarSchoolProgress->maximum(),0));
    ui->progressBarTruancy->setStyleSheet(styleForBar(ui->progressBarTruancy->value(),ui->progressBarTruancy->maximum(),0));
}

void TabWidgetPlayer::updBodyVal(Body param, int val)
{
    ptrToMplayer->updVBody(param, val);
}

void TabWidgetPlayer::loadStrings()
{
    std::vector<QString> strings {"сила", "скорость","ловкость",
        "выносливость","интеллект","Реакция","Доминантность","Джебы",
        "Силовые удары","Удары ногами","Защита от ударов","Навыки бокса",
        "Бег","Воллейбол","Навыки официантки","Навыки горничной","Вокал",
        "Танцы","Проф.танцы","Стриптиз","Танцы на шесте","Кройка и шитьё",
        "Успеваемость","Прогулы"};
    int dom = ptrToMplayer->getSkillValue(Skills::domination);
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

    if(ptrToMplayer->isCheatsOn())
    {
        for (int i = 0; i < strings.size(); ++i) {
            if (i != Skills::domination) {
                makeLink(strings[i], QString::number(i));
            }
            else
            {
                makeLink(domina, QString::number(i));
                strings[Skills::domination] += domina;
            }
        }
    }

    result = "<html><head/><body><p style='line-height: 1.36;'>";
    for (int i = 0; i < strings.size(); ++i)
    {
        result += strings[i] + "<br>";
    }
    result += "</p></body></html>";
    ui->verticalLayoutBar->setAlignment(Qt::AlignTop);
    ui->verticalLayoutDesc->setAlignment(Qt::AlignTop);
    ui->labelSkills->setText(result);
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
        int cur = ptrToMplayer->getVBody(Body::skinTan);
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
        int anus = ptrToMplayer->getVBody(Body::anus);
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
        int vag = ptrToMplayer->getVBody(Body::vagina);
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
        int thrVal = ptrToMplayer->getVBody(Body::throat);
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
        if(ptrToMplayer->getVBody(Body::pubisHair) > 4)
        {
            ptrToMplayer->setVBody(Body::pubisHair, 0);
        }
    }
    if (link == "legHair")
    {
        if (ptrToMplayer->getVBody(Body::legHair) == 3)
        {
            updBodyVal(Body::legHair, 3);
        }
        else
        {
            updBodyVal(Body::legHair, 2);
        }
        if(ptrToMplayer->getVBody(Body::legHair) > 6)
        {
            ptrToMplayer->setVBody(Body::legHair, 0);
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


void TabWidgetPlayer::on_labelSkills_linkActivated(const QString &link)
{
    Skills skill = static_cast<Skills>(link.toInt());
    int value;
    if(skill == Skills::boxing)
    {
        value = 4;
        ptrToMplayer->updVSkill(Skills::jab, value);
        ptrToMplayer->updVSkill(Skills::punch, value);
        ptrToMplayer->updVSkill(Skills::kik, value);
        ptrToMplayer->updVSkill(Skills::kikDef, value);
    }
    else
    {
        if (skill == Skills::runner) { value = 20; }
        else if (skill == Skills::volleyball) { value = 10; }
        else if (skill == Skills::posSkill) { value = 50; }
        else if (skill == Skills::truancy) { value = 3; }
        else { value = 5; }
        ptrToMplayer->updVSkill(skill, value);
    }
    fillCharacteristics();
}

