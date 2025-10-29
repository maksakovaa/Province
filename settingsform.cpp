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

bool SettingsForm::isCheats()
{
    return m_settings->isCheats();
}

bool SettingsForm::isHapri()
{
    return m_settings->isHapri();
}

bool SettingsForm::getPubicHair()
{
    return m_settings->getPubicHair();
}

bool SettingsForm::isAutoTampon()
{
    return m_settings->isAutoTampon();
}

bool SettingsForm::isFullScreen()
{
    return m_settings->isFullScreen();
}

int SettingsForm::getBodyType()
{
    return m_settings->getBodyType();
}

int SettingsForm::getBody_tits()
{
    return m_settings->getBody_tits();
}

int SettingsForm::getLanguage()
{
    return m_settings->getLanguage();
}

int SettingsForm::getAddTxtSex()
{
    return m_settings->getAddTxtSex();
}

int SettingsForm::getSexLevel()
{
    return m_settings->getSexLevel();
}

void SettingsForm::setupSettingsWidget()
{
    if(m_settings->isFullScreen()) { this->showFullScreen(); }
    else { this->showNormal(); }
    QString param[] {"Читы",//0
        "Телосложение", //1
        "Грудь", //2
        "Лобок", //3
        "Альтернативная внешность",//4
        "Автоприменение прокладок",//5
        "Уровень сложности секса",//6
        "Уровень вывода текста при описания секса",//7
        "Полный экран",//8
        "Язык" };//9
    QString boolValue[] {"Выключено","Включено"};
    QString bodyValue[] {"Худощавое", "Обычное", "Пышка"};
    QString lobokValue[] {"Бритый", "Волосатый"};
    QString breastsValue[] {"Маленькая","Средняя","Большая"};
    QString language[] {"English", "Russian"};
    QString sexLevel[] {"Реалистично", "Тяжело", "Очень сложно", "Сложно", "Нормально", "Просто"};
    QString AddTxtSet[] {"Полностью", "Частично", "Только оргазм", "Не выводить"};
    int defValue[] {1,1,1,0,0,1,0,0,0,1};
    int curValue[] {isCheats(), getBodyType(), getBody_tits(), getPubicHair(), 
        isHapri(), isAutoTampon(), getSexLevel(), getAddTxtSex(), 
        isFullScreen(), getLanguage()};
    QString resParam{"<hr>"}, resDef{"<hr>"}, resCur{"<hr>"};

    for (size_t i = 0; i < 8; i++)
    {
        resParam += param[i] + "<hr>";
        if (i == 0 || i == 4 || i == 5 || i == 8)
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
        else if (i == 6)
        {
            resDef += sexLevel[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + sexLevel[curValue[i]] + "</a><hr>";
        }
        else if (i == 7)
        {
            resDef += AddTxtSet[defValue[i]] + "<hr>";
            resCur += "<a href='param" + intQStr(i) + "'>" + AddTxtSet[curValue[i]] + "</a><hr>";
        }
        else if (i == 9)
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
    if (link == "param6") { m_settings->switchSexLevel(); }
    if (link == "param7") { m_settings->switchAddTxtSex(); }
    if (link == "param8") { m_settings->switchScreen(); }
    if (link == "param9") { m_settings->switchLang(); }
    setupSettingsWidget();
    emit sigChangeSettings();
}
