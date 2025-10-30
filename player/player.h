#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <unordered_map>
#include <QString>
#include <QObject>
#include "enums.h"
#include "wardrobe.h"
#include "../settings.h"

class Player: public QObject
{
    Q_OBJECT
public:
    Player();
    Player(CharacterType history, Settings* ptr);
    ~Player() = default;

    bool isCheatsOn();
    bool isPanties();
    bool isAutoTampon();
    bool updVSkill(Skills skill_name, int value);
    bool updVBody(Body param, int value);
    bool updVStatus(Status stat, int value);
    void updVBuzzer(budilnik type, int value);
    void updVSexVar(SexVar param, int value);
    void updVStatistic(SC param, int value);
    void updSkin(char c, int value);

    Cloth* getCloth(ClothType type);
    void slotWearAndTear(int value = 1);
    int getCurClothGroup();
    void redress(Cloth* newCloth);

    void setSettingsPtr(Settings* ptr);
    void setVStatus(Status stat, int value);
    void setVBody(Body param, int value);
    void setVSexVar(SexVar param, int value);

    int getAge();
    int getSkillValue(Skills skill_name);
    int getVBody(Body param);
    int getStatisticsValue(SC stat);
    int getVStatus(Status stat);
    int getVConst(Const param);
    int getVBuzzer(budilnik param);
    int getVSexVar(SexVar param);

    QString getName();
    QString getBirthDate();

    QString getNameDesc();
    QString getBirthDayDesc();
    QString getAgesDesc();
    QString getHeightDesc();
    QString getBreastsDesc();
    QString getLipsDesc();
    QString getThroatDesc();
    QString getVaginaDesc();
    QString getAnusDesc();
    QString getBodyDesc();
    QString getBodyTypeFigureDesc();
    QString getHairDesc();
    QString getPubisDesc();
    QString getSkinDesc();
    QString getEyeDesc();
    QString getMakeupDesc();
    QString getLegsDesc();
    QString getShamelessDesc();
    QString getVneshDesc();
    QString getCurClothName();

    QString getPlayerFace();
    QPixmap getPlayerIcon();
    QString getPlayerBody();
    QString getPlayerVagina();
    QString getPlayerAnus();
    QString getPlayerPubis();
    QString getPlayerClothes();
    QString getPlayerBreasts();
signals:
    void sigCalcAge(int& years, struct tm from);
    void sigUpdClothSize(int size);
    void sigCalcRubbing();
    void sigVagGelTouch();
    void sigPregRecalc();
    void sigDecRubbing(Body holeType);
    void sigDataInitAlko();
    void sigHangOver();
    void sigRiscsUpdate();
    void sigAlcoholism();
    void sigSexCorrector();
    void sigGetVagDamp(int& value);
public slots:
    void slotElapsed10min();
    void slotElapsed15min();
    void slotElapsed20min();
    void slotElapsed30min();
    void slotElapsed60min();
    void slotElapsedDay();
    void slotElapsedTime();
private:
    //methods
    void zz_body();

    void calcShamelessFlag();

    void initDefaultArrays();
    void checkBodyParams();
    void checkStatusParams();
    void checkSkillParams();
    void updBody();

    void initWardrobeClothes();
    void wearClothes(Cloth* thing);
    void checkPanties();

    int calcHairCurlyBonus();
    int calcLipBonus();
    int calcLipAlmstatBonus();
    int calcLenseBonus();
    int calcSkinTanBonus();
    int calcEyeSizeBonus();
    int calcEyeBrowBonus();
    int calcBodyBonus();
    int calcPubisBonus();
    int calcClothesBonus();
    int calcVidageBonus();
    int calcGlassBonus();
    int calcLegBonus();

    int calcZZTits();
    void calcVneshBonus();

    void skinDecrement(int value = 0);
    void skinIncrement(int value = 0);
    //members
    QString f_name;
    QString l_name;
    struct tm m_birthDate{};
    Wardrobe m_wardrobe;
    std::unordered_map<ClothType, Cloth*> m_clothSLots;
    std::unordered_map<Skills, int> m_skills;
    std::unordered_map<Body, int> m_body;
    std::unordered_map<Status, int> m_status;
    std::unordered_map<SexVar, int> m_sex;
    std::unordered_map<SC, int> m_statistic;
    std::unordered_map<Const, int> m_const;
    std::unordered_map<budilnik, int> m_budilnik;
    Settings* m_settings;
    // int m_tampon;
};

#endif
