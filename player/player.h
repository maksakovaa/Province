#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <unordered_map>
#include <QString>
#include <QObject>
#include "enums.h"
#include "../nav/cloth.h"

class Player: public QObject
{
    Q_OBJECT
public:
    Player();
    Player(CharacterType history, QWidget* ptr2);
    ~Player() = default;

    bool isCheatsOn();
    bool isPanties();
    bool isAutoTampon();
    void updVSkill(Skills skill_name, int value);
    void updVBody(Body param, int value);
    void updVStatus(Status stat, int value);
    void updVBuzzer(budilnik type, int value);
    void updVSexVar(SexVar param, int value);
    void updVStatistic(SC param, int value);
    void updVSick(Sickness param, int value);
    void updVAddict(Addiction param, int value);
    void updSkin(char c, int value);

    Cloth* getCloth(ClothType type);
    void slotWearAndTear(int value = 1);
    int getCurClothGroup();
    void redress(Cloth* newCloth);

    void setVStatus(Status stat, int value);
    void setVBody(Body param, int value);
    void setVSexVar(SexVar param, int value);
    void setVSC(SC param, int value);
    void setVSkill(Skills param, int val);
    void setVSick(Sickness param, int val);
    void setVAddict(Addiction param, int value);
    int getAge();
    int getSkillValue(Skills skill_name);
    int getVBody(Body param);
    int getStatisticsValue(SC stat);
    int getVStatus(Status stat);
    int getVConst(Const param);
    int getVBuzzer(budilnik param);
    int getVSexVar(SexVar param);
    int getVSick(Sickness param);
    int getVAddict(Addiction param);

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

    void calcShamelessFlag();
    void checkPanties();
    void updBody();
signals:
    void sigUpdClothSize(int size);
private:
    //methods
    void zz_body();

    void initDefaultArrays();

    void initWardrobeClothes();
    void wearClothes(Cloth* thing);


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
    QWidget* m_main;
    QString f_name;
    QString l_name;
    struct tm m_birthDate{};
    //Wardrobe m_wardrobe;
    std::unordered_map<ClothType, Cloth*> m_clothSLots;
    std::unordered_map<Skills, int> m_skills;
    std::unordered_map<Body, int> m_body;
    std::unordered_map<Status, int> m_status;
    std::unordered_map<SexVar, int> m_sex;
    std::unordered_map<SC, int> m_statistic;
    std::unordered_map<Const, int> m_const;
    std::unordered_map<budilnik, int> m_budilnik;
    std::unordered_map<Sickness, int> m_sick;
    std::unordered_map<Addiction, int> m_addict;
};

#endif
