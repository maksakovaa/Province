#ifndef OBJVIEWFORM_H
#define OBJVIEWFORM_H

#include "gameobj.h"
#include "location.h"
#include "locationform.h"
#include <QPushButton>
#include <QWidget>
#include <qstackedwidget.h>

namespace Ui {
class ObjViewForm;
}

class ObjViewForm : public QWidget
{
    Q_OBJECT
signals:
    void sigSpendTime(int min);
    void sigUpdParams();
public:
    explicit ObjViewForm(QWidget *parent = nullptr);
    ~ObjViewForm();
    void setPlayerPtr(Player* ptr);
    void setActLayoutPtr(QVBoxLayout* ptr);
    void setPagePtr(QStackedWidget* ptr);
    void setSettingsPtr(Settings* ptr);
    void setTimeServerPtr(TimeServer* ptr);
public slots:
    void slotViewObj(QString objName);
private:
    void viewMirror();
private slots:
    void slotMirrorActHandler(QString actName);
private:
    void viewBed();
private slots:
    void slotBedActHandler(QString actName);
    void on_labelObjImage_linkActivated(const QString &link);
    void on_labelObjDesc_linkActivated(const QString &link);

private:
    void sleepInBed();
    void relaxInBed();
    void selfPlay();
    void budilnik();
    void bedDreams();
    void makeMirrorActBtn(QString text);
    void makeBedActBtn(QString text);
    void makeBackBtn(QString text);
    void makeQActionButton();
    int getVStatus(Status type);
    int getVBody(Body type);
    int getVsexVar(SexVar type);
    void setVStatus(Status type, int value);
    void setVSexVar(SexVar type, int value);
    void updVStatus(Status type, int value);
    Location* getCurLoc();
    Ui::ObjViewForm *ui;
    Player* m_player;
    QVBoxLayout* m_actLayout;
    QStackedWidget* m_page;
    Settings* m_settings;
    BagForm* m_bag;
    TimeServer* m_time;
    LocationForm* m_loc;
    Cloth* old_cloth;
    Cloth* old_panties;
    Cloth* old_stockings;
    std::unordered_map<GameObjects, GameObj*> m_objs;
};

#endif // OBJVIEWFORM_H
