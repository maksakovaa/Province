#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../player/player.h"
#include "../player/pregnancy.h"
#include "../sex/ccsex.h"
#include "../player/ccalko.h"
#include "settingsform.h"
#include "../timeServer.h"
#include "../weather.h"
#include "overlaystatus.h"
#include "notificationqueue.h"
#include "bagform.h"
#include "saveform.h"
#include "loadform.h"

#include "../render.h"
#include "../locations/locationhandler.h"
#include "../objects/objecthandler.h"
#include "../sex/sexhandler.h"
#include "../npc/npc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend LoadForm;
    friend Render; friend LocationHandler; friend ObjectHandler; friend SexHandler;
    friend Player; friend TimeServer; friend OverlayStatus; friend CC_Alko;
    friend Weather; friend Pregnancy; friend CCSex; friend SaveForm;
public:
    MainWindow(SettingsForm* settingsForm, int year, int month, int day, QWidget *parent = nullptr);
    MainWindow(SettingsForm* settingsForm, QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* createMenu();
    void start(QString loc, CharacterType charType);
public slots:
    void slotUpdateDateTime();
    void slotUpdMoney();
    void slotUpdParams();
    void showNotif(QString text);
private slots:
    void slotIsMapAwaylable(bool status);
    void on_pushButtonMap_clicked();
    void on_pushButtonRestart_clicked();
    void on_pushButtonPlayer_clicked();
    void on_pushButtonSettings_clicked();
    void on_pushButtonBag_clicked();
    void slotOnStatusClick(const QString &link);
    void on_labelTime_linkActivated(const QString &link);
    void on_labelDate_linkActivated(const QString& link);
    void on_labelMoney_linkActivated(const QString &link);
    void slotUpdPlayerIcon();
    void on_pushButtonSave_clicked();

    void on_pushButtonLoad_clicked();

private: //methods
    void setupMainWindow(SettingsForm* settingsForm);
    void connections();
    void updStatusVal(Status stat, int val);
    void updatePlayerStatusValue();
    void updPlayerStatusBarStyle();
    void loadStrings();
    void setupActionButtons();
    void saveActions();
    void reloadActions();
    void initNpc();
    NPCboyfriend genRandboyfriend(int i);
private: //members
    std::vector<NPC> npcs;
    std::vector<NPCboyfriend> boyfriends;
    NotificationQueue* m_que;
    SettingsForm* page4;
    Weather* m_weather;
    Ui::MainWindow* ui;
    TimeServer m_time;
    Player* m_player;
    Pregnancy m_reproductSys;
    OverlayStatus* m_overlayStatus;
    CCSex m_ccsex;
    CC_Alko m_ccalko;
    BagForm* m_bag;
    std::vector<QLayoutItem*> Layoutitems;
    Render* pageRender;
    LocationHandler* locHandler;
    ObjectHandler* objHandler;
    SexHandler* sexHandler;
    SaveForm savePage;
    LoadForm loadPage;
};
#endif // MAINWINDOW_H
