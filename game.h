#ifndef GAME_H
#define GAME_H

#include "events/eventhandler.h"
#include "locations/locationhandler.h"
#include "objects/objecthandler.h"
#include "player/player.h"
#include "player/pregnancy.h"
#include "player/ccalko.h"
#include "player/drugs.h"
#include "player/reputation.h"
#include "sex/sexhandler.h"
#include "sex/ccsex.h"
#include "weather.h"
#include "timeServer.h"
#include "npc/npc_editor.h"

class Game: public QObject
{
    Q_OBJECT
    friend MainWindow; friend SaveForm; friend LoadForm;
public:
    Game(QWidget* ptr, int year, int month, int day, int hour, int min);
    Game(QWidget* ptr);
    void newGame(QString loc, CharacterType charType);
    void loadGame();
//Render actions:
    void rendVideoPage(QObject* ptr);
    void rendImagePage(QObject* ptr);
    void rendObjPage(QObject* ptr);
    void setImage(QString path);
    void setText(QString text);
    void addText(QString text);
    void setVideo(QString path, int width, int height);
    void addLayoutsInObjPage(QLayout* layout);
    void addQWidgetInObjPage(QWidget* widget);
    QLabel* getTextPtr();
    QLabel* getImagePtr();
    void addActions(QWidget* widget);
    void clearActions();
    void updateParams();
    void sendNotif(QString msg);
//Items
    void addItem(Items name, int count = 1);
    int getItmCount(Items name);
    void useItem(Items name, int count = 1);
    QString getItemName(Items id);
    void setItemCount(Items id,int count);
//Settings actions:
    bool isAutoTampon();
    bool isCheats();
    bool isHapri();
    int getBody_tits();
    bool getPubicHair();
    int getBodyType();
    bool isFullScreen();
    int getLanguage();
    int getAddTxtSex();
    int getSexLevel();
    bool whoreState();
//TimeServer actions:
    void incTime(int min);
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMin();
    int getWeek();
    int calcYears(struct tm from);
    void setTime(int hour, int min = 0);
//Weather actions:
    bool isDay();
    bool isSnow();
    QString getImage();
    QString getCurrentTemp();
    void updOnTimeMove();
    int getSunWeather();
    int getSnow();
    int getTemp();
    int getSunrise();
    int getSunset();
    void fnWeather();
//Event actions:
    void startEvent(Events event, QString args = 0);
    int& vSchool(SchoolVar param);
    int& vEvent(EventParams param);
    int& vQuest(QuestParams param);
    bool isHanters();
//Player actions:
    void newPlayer(CharacterType history);
    void setBoyName(QString name);
    void setBoy2Name(QString name);
    int getAge();
    void calcShamelessFlag();
    void updBody();
    //clothing
    bool isPanties();
    bool isSkirt();
    bool isGlamour();
    bool isJeans();
    bool isNude();
    bool isCloth();
    Cloth* getCloth(ClothType type);
    void decreaseClothCond(int value = 1);
    int getClothGroup();
    void redress(ClothType type, Cloth* newCloth);
    void redressOld();
    void storeOldToWardrobe();
    void wearClothes(Cloth* thing);
    int getCurClothId();
    //params
    int& vSkill(Skills skill);
    int& vBody(Body param);
    int& vStatus(Status param);
    int& vSex(SexVar param);
    int& vStatistics(SC param);
    int& vSick(Sickness param);
    int& vAddict(Addiction param);
    int& vJob(JobStatus param);
    int& vBuzzer(budilnik param);
    int vConst(Const param);
    int& vRep(LocId param);
    void updSkin(char c, int value);
    void checkPanties();
    //Desc
    QString getName();
    QString getNickName();
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

    QString getLipTalk();
    QString getLipTalk2();
    QString getLipTalk3();
    QString getThroattipe();
    QString getVaginaTipe1();
    QString getVaginaTipe2();
    QString getVaginaTipe3();
    QString getAnusTipe();
    QString getAnusTipe2();
    QString getAnusTipe3();

    //Pregnancy
    bool isEstrus();
    bool isMesec();
    bool isPregnant();
    int& vPreg(PregVar param);
    void slotMenstruus();
    void slotEstrus();
    void slotIncreaseRiscs(int value);
    void slotPregRecalc();
    void slotRiscsUpdate();
    bool condomDef();
    void chanceOfPreg();
    bool PregVisibility();
    //Reputation:
    QString repDesc();
    int repGet();
    void repEdit(int val, LocId loc);
// Locations:
    void setMapAwailable(bool status);
    void setCurrentPage(int id);
    LocId getCurLoc();
    LocId getMainLoc();
    LocId getPrevLoc();
    Location* getCurPtr();
    void changeLoc(LocId id, int time = 0, QString arg = "");
    Location* getLocPtr(LocId locId);
    void checkMapAwailable();
    void setPrevLoc(LocId loc);
    void setCurLoc(LocId loc);
////beach acts
    void walk();
    void undress(int arg = 0);
    void sunbathe(int isCream = 0);
    void cream();
    void swim();
    void getDressed(int arg = 0);
///Kitchen acts
    void kitchenActsAll(int arg = 0);
    void drinkAll();
    void cookies();
    void fatDel();
    void vitamin();
    void pills();
    void eat(QString foodtype = "", QString image = "", QString text = "");
    void drink(QString napitokType);
//Common
    void icecream();
    void coffee();
    void read_porn();
    void crossing(int arg);
    void home_workout();
    void lokerchoice();
    void sitrobrd();
    void sitrskakd();
    void sitrpressd();
    void sitrpushd();
    void watch_tv_on_sofa();
    void run_competition(QString arg);
    void fancywork();
    bool check_inhome();
    void wet_wipes();
    int getClothDecreaseLevel();
    void fnSport(int arg = 0);
    void waiting(int arg = 0);
//Cards
    void cardInit(int count, int min);
    int cardCheck();
    int getCardTime();
    int getCardHorny();
    QString getCard();
//SexHandler:
    void selfPlayStart();
    void cum(QString target);
    void sexStart();
    void analStart(ToolType type = tDick);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
    void sex_cum();
    void blow_job();
    void anal_cum();
    void fnswallow();
    void dp_start();
    void double_penetration();
    void dp_cum();
    void rand_cum(int min = 0);
    void dd_anus(int dick1, int dick2, QString name1, QString name2, int protection = 0);
        void dd_vagina(int dick1, int dick2, QString name1, QString name2, int protection = 0);
//Objects handler:
    void viewObj(QString objName);
    Cloth* wearCloth(Cloth* thing);
    void storeCloth(Cloth* thing, int count = 1);
    void removeCloth(ClothGroup group);
    ClothMain* addRandCloth(ClothGroup group);
    void sleep();
    QString getBookName(int id);
    void readOnWalk();
    int eroReaded();
    void eroBlock();
    int sisBook();
    int novel_readed();
    void erotic_enable();
//NPC Editor:
    NPC& gNPC(int id);
    QString getNpcTex(int id);
    QString getNpcLink(int id);
    QString getNpcGroup(int id);
    QString makeNpcGroup(int group);
    int getAvgRelation(npcGroup group);
    void rendRealationList();
    void rendNpcProfile(NPCId id);
    void changeRep(char act, int id, int val = 0, int cup = 0, bool msgShow = true);
//CC_ALKO
    void fnAlko(int val);
    void anti_hangover();
    void alkoAbstain();
    int alkoBlock();
    void slotDataInitAlko();
    void slotHangOver();
    void slotAlkoholism();
//CC_SEX
    void ability(Body holeType, int value = 0);
    QString sextToysBlock(int arg);
    int getVaginaDampness();
    int calc_rubb(QString holeType);
    void antiRubbing();
    int getVagDamp();
    void calcRubbing();
    void vagGelTouch();
    void decRubbing(Body holeType);
    void sexCorrector();
    void setGape(Body holeType, int horny, int dick, int silavag);
//Drugs
    void setStatus(int type);
    void setValues();
    void hourRecalc();
    bool drugBlock();
private:
    QWidget* m_window;
    EventHandler* m_events;
    LocationHandler* m_locs;
    ObjectHandler* m_objs;
    SexHandler* m_sex;
    Player* m_player;
    Pregnancy m_preg;
    CCSex m_ccsex;
    CC_Alko m_ccalko;
    Weather* m_weather;
    TimeServer m_time;
    NPC_Editor* m_npc;
    Drugs* m_drugs;
    Render* m_render;
    QVBoxLayout* m_actions;
    Reputation m_rep;
};

#endif // GAME_H
