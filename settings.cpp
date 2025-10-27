#include "settings.h"
#include <QFile>
#include <QDebug>

Settings::Settings()
{
    loadDefault();
    loadFromFile();
}

Settings::~Settings()
{
    saveToFile();
}

bool Settings::isCheats()
{
    return cheatMode;
}

bool Settings::isHapri()
{
    return hapri_mod;
}

int Settings::getBody_tits()
{
    return body_tits;
}

bool Settings::getPubicHair()
{
    return pubic_hair;
}

int Settings::getBodyType()
{
    return bodytype;
}

bool Settings::isAutoTampon()
{
    return autotampon;
}

bool Settings::isFullScreen()
{
    return fullScreen;
}

int Settings::getLanguage()
{
    return lang;
}

void Settings::switchCheats()
{
    cheatMode = !cheatMode;
}

void Settings::switchHapri()
{
    hapri_mod = !hapri_mod;
}

void Settings::switchTits()
{
    body_tits++;
    if(body_tits > 2)
    {
        body_tits = 0;
    }
}

void Settings::switchBody()
{
    bodytype++;
    if(bodytype > 2)
    {
        bodytype = 0;
    }
}

void Settings::switchLobok()
{
    pubic_hair = !pubic_hair;
}

void Settings::switchTampon()
{
    autotampon = !autotampon;
}

void Settings::switchScreen()
{
    fullScreen = !fullScreen;
}

void Settings::switchLang()
{
    if(lang == 0)
        lang = 1;
    else
        lang = 0;
}

void Settings::loadFromFile()
{
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file! ";
    }
    else
    {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd())
        {
            line = in.readLine();
            QStringList val = line.split(" = ");
            if(val[0] == "fullScreen") fullScreen = val[1].toInt();
            if(val[0] == "cheatMode") cheatMode = val[1].toInt();
            if(val[0] == "hapri_mod") hapri_mod = val[1].toInt();
            if(val[0] == "body_tits") body_tits = val[1].toInt();
            if(val[0] == "pubic_hair") pubic_hair = val[1].toInt();
            if(val[0] == "bodytype") bodytype = val[1].toInt();
            if(val[0] == "autotampon") autotampon = val[1].toInt();
            if(val[0] == "sex_level") sex_level = val[1].toInt();
            if(val[0] == "lang") lang = val[1].toInt();
        }
    }
}

void Settings::saveToFile()
{
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error opening file! ";
    }
    else
    {
        QTextStream out(&file);
        out << "fullScreen = " + QString::number(fullScreen) + "\n";
        out << "cheatMode = " + QString::number(cheatMode) + "\n";
        out << "hapri_mod = " + QString::number(hapri_mod) + "\n";
        out << "body_tits = " + QString::number(body_tits) + "\n";
        out << "pubic_hair = " + QString::number(pubic_hair) + "\n";
        out << "bodytype = " + QString::number(bodytype) + "\n";
        out << "autotampon = " + QString::number(autotampon) + "\n";
        out << "sex_level = " + QString::number(sex_level) + "\n";
        out << "lang = " + QString::number(lang);
    }

}

void Settings::loadDefault()
{
    fullScreen = false;
    cheatMode = true;
    hapri_mod = false;
    bodytype = 1;
    pubic_hair = true;
    body_tits = 1;
    autotampon = 1;
    sex_level = 0;
    lang = 1;
}
