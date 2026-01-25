#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// #include "../player/player.h"
// #include "../player/pregnancy.h"
// #include "../sex/ccsex.h"
// #include "../player/ccalko.h"
// #include "../timeServer.h"
// #include "../weather.h"
// #include "../locations/locationhandler.h"
// #include "../objects/objecthandler.h"
// #include "../sex/sexhandler.h"
// #include "../npc/npc_editor.h"
// #include "../player/drugs.h"

#include <QMainWindow>
#include "settingsform.h"
#include "overlaystatus.h"
#include "notificationqueue.h"
#include "bagform.h"
#include "saveform.h"
#include "loadform.h"
#include "../render.h"
#include "../game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend LoadForm; friend Render; friend OverlayStatus; friend SaveForm; friend Game;
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
    void on_pushButton_clicked();
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
private: //members
    Ui::MainWindow* ui;
    NotificationQueue* m_que;
    SettingsForm* m_settings; // m_settings
    OverlayStatus* m_overlayStatus;
    BagForm* m_bag;
    std::vector<QLayoutItem*> Layoutitems;
    Render* m_render;
    SaveForm m_savePage;
    LoadForm m_loadPage;
    Game* m_game;
};
#endif // MAINWINDOW_H
