#include "settingsform.h"
#include "ui_settingsform.h"
#include "Functions.h"

SettingsForm::SettingsForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingsForm)
{
    ui->setupUi(this);
    m_settings = new Settings;
    setupSettingsWidget();
}

SettingsForm::~SettingsForm()
{
    delete ui;
}

Settings *SettingsForm::settings()
{
    return m_settings;
}

void SettingsForm::setupSettingsWidget()
{
    if(m_settings->isFullScreen()) { this->showFullScreen(); }
    else { this->showNormal(); }
    QString param[] {"Читы", "Телосложение", "Грудь", "Лобок", "Альтернативная внешность", "Автоприменение прокладок", "Полный экран", "Язык" };
    QString boolValue[] {"Выключено","Включено"};
    QString bodyValue[] {"Худощавое", "Обычное", "Пышка"};
    QString lobokValue[] {"Бритый", "Волосатый"};
    QString breastsValue[] {"Маленькая","Средняя","Большая"};
    QString language[] {"English", "Russian"};
    int defValue[] {1,1,1,0,0,1,0,1};
    int curValue[] {m_settings->isCheats(), m_settings->getBodyType(), m_settings->getBody_tits(), m_settings->getPubicHair(), m_settings->isHapri(), m_settings->isAutoTampon(), m_settings->isFullScreen(), m_settings->getLanguage()};
    QString resParam{"<hr>"}, resDef{"<hr>"}, resCur{"<hr>"};

    for (size_t i = 0; i < 8; i++)
    {
        resParam += param[i] + "<hr>";
        if (i == 0 || i == 4 || i == 5 || i == 6)
        {
            resDef += boolValue[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + boolValue[curValue[i]] + "</a><hr>";
        }
        else if (i == 1)
        {
            resDef += bodyValue[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + bodyValue[curValue[i]] + "</a><hr>";
        }
        else if (i == 2)
        {
            resDef += breastsValue[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + breastsValue[curValue[i]] + "</a><hr>";
        }
        else if (i == 3)
        {
            resDef += lobokValue[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + lobokValue[curValue[i]] + "</a><hr>";
        }
        else if (i == 7)
        {
            resDef += language[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + language[curValue[i]] + "</a><hr>";
        }
    }

    ui->labelParam->setText(resParam);
    ui->labelCurValue->setText(resCur);
    ui->labelDefValue->setText(resDef);
}

void SettingsForm::on_labelCurValue_linkActivated(const QString &link)
{
    if (link == "param0") { m_settings->switchCheats(); }
    if (link == "param1") { m_settings->switchBody(); }
    if (link == "param2") { m_settings->switchTits(); }
    if (link == "param3") { m_settings->switchLobok(); }
    if (link == "param4") { m_settings->switchHapri(); }
    if (link == "param5") { m_settings->switchTampon(); }
    if (link == "param6") { m_settings->switchScreen(); }
    if (link == "param7") { m_settings->switchLang(); }
    setupSettingsWidget();
    emit sigChangeSettings();
}
