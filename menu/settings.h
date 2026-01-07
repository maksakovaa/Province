#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include <QString>

class Settings
{
public:
    Settings();
    ~Settings();
    bool isCheats();
    bool isHapri();
    int getBody_tits();
    bool getPubicHair();
    int getBodyType();
    bool isAutoTampon();
    bool isFullScreen();
    int getLanguage();
    int getAddTxtSex();
    int getSexLevel();
    void switchCheats();
    void switchHapri();
    void switchTits();
    void switchBody();
    void switchLobok();
    void switchTampon();
    void switchScreen();
    void switchLang();
    void switchAddTxtSex();
    void switchSexLevel();
private:
    QFile file{"settings.ini"};
    void loadFromFile();
    void saveToFile();
    void loadDefault();
    bool fullScreen;
    bool cheatMode;
    bool hapri_mod;
    int body_tits;
    bool pubic_hair;
    int bodytype;
    bool autotampon;
    int sex_level;
    int lang;
    int add_txt_sex;
};

#endif
