#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "player/player.h"
#include "player/pregnancy.h"
#include "sex/ccsex.h"
#include "player/ccalko.h"
#include "settingsform.h"
#include "sex/sexviewform.h"
#include "timeServer.h"
#include "weather.h"
#include "overlaystatus.h"
#include "nav/objviewform.h"
#include "nav/locationform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend Player; friend TimeServer; friend OverlayStatus;
    friend LocationForm; friend ObjViewForm;
    friend SexViewForm;
public:
    MainWindow(SettingsForm* settingsForm, CharacterType charType, int year, int month, int day, QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* createMenu();
    void start(QString loc);
public slots:
    void slotUpdateDateTime();
    void slotUpdMoney();
    void slotUpdParams();
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
private: //methods
    void setupMainWindow(SettingsForm* settingsForm, CharacterType charType);
    void connections();
    void setPointers();
    void updStatusVal(Status stat, int val);
    void updatePlayerStatusValue();
    void updPlayerStatusBarStyle();
    void loadStrings();
    void setupActionButtons();
    void reloadActions();
private: //members
    int prevPage;
    SettingsForm* page4;
    Weather* m_weather;
    Ui::MainWindow* ui;
    TimeServer m_time;
    Player* m_player;
    Pregnancy m_reproductSys;
    OverlayStatus m_overlayStatus;
    CCSex m_ccsex;
    CC_Alko m_ccalko;
    BagForm* m_bag;
    SexViewForm* m_sex;
    ObjViewForm* m_obj;
};
#endif // MAINWINDOW_H
