#ifndef PLAYER_H
#define PLAYER_H

#include <ctime>
#include <unordered_map>
#include <QString>
#include <QObject>
#include "enums.h"
#include "../items/cloth.h"
#include "../locations/loc_enums.h"

class MainWindow;
class Wardrobe;
class SaveForm;
class LoadForm;
class Game;

class Player: public QObject
{
    Q_OBJECT
    friend MainWindow; friend SaveForm; friend LoadForm;
public:
    Player(Game* ptr);
    void newPlayer(CharacterType history);
    ~Player() = default;

    // bool isCheatsOn();
    bool isPanties();
    bool isAutoTampon();
    bool isSkirt();
    bool isGlamour();
    bool isJeans();
    bool isNude();
    bool isCloth();

    Cloth* getCloth(ClothType type);
    void decreaseCondition(int value = 1);
    int getClothGroup();
    void redress(ClothType type, Cloth* newCloth);
    void redressOld();
    void storeOldToWardrobe();
    void wearClothes(Cloth* thing);

    int& vSkill(Skills skill);
    int& vBody(Body param);
    int& vStatus(Status param);
    int& vBuzzer(budilnik param);
    int& vSex(SexVar param);
    int& vStatistics(SC param);
    int& vSick(Sickness param);
    int& vAddict(Addiction param);
    int& vJob(JobStatus param);
    int& vPreg(PregVar param);
    int& vRep(LocId param);
    int vConst(Const param);

    void updSkin(char c, int value);

    void setBoyName(QString name);
    void setBoy2Name(QString name);

    int getAge();

    QString getName();
    QString getPFName();
    QString getBoyName();
    QString getBoy2Name();
    QString getBirthDate();

    QString getNameDesc();
    QString getBirthDayDesc();
    QString getAgesDesc();
    QString getHeightDesc();
    QString getBreastsDesc();
    QString getLipsDesc();
    QString getLipTalk();
    QString getLipTalk2();
    QString getLipTalk3();
    QString getThroatDesc();
    QString getThroattipe();
    QString getVaginaDesc();
    QString getVaginaTipe1();
    QString getVaginaTipe2();
    QString getVaginaTipe3();
    QString getAnusDesc();
    QString getAnusTipe1();
    QString getAnusTipe2();
    QString getAnusTipe3();
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
    void calcVneshBonus();
signals:
    void sigInitWardrobe();
private: //methods
    void zz_body();

    void initDefaultArrays();
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


    void skinDecrement(int value = 0);
    void skinIncrement(int value = 0);
private: //members
    Game* root;
    QString f_name;
    QString l_name;
    QString pfname;
    QString boy;
    QString boy2;
    struct tm m_birthDate{};
    std::unordered_map<ClothType, Cloth*> m_clothSLots;
    std::unordered_map<ClothType, Cloth*> m_prevCloth;
    std::unordered_map<Skills, int> m_skills;
    std::unordered_map<Body, int> m_body;
    std::unordered_map<Status, int> m_status;
    std::unordered_map<SexVar, int> m_sex;
    std::unordered_map<PregVar, int> m_preg;
    std::unordered_map<SC, int> m_statistic;
    std::unordered_map<Const, int> m_const;
    std::unordered_map<budilnik, int> m_budilnik;
    std::unordered_map<Sickness, int> m_sick;
    std::unordered_map<Addiction, int> m_addict;
    std::unordered_map<JobStatus, int> m_job;
    std::unordered_map<LocId, int> m_reputation;
};

#endif
