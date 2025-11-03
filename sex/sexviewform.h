#ifndef SEXVIEWFORM_H
#define SEXVIEWFORM_H

#include "nav/location.h"
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <settingsform.h>

namespace Ui {
class SexViewForm;
}

class SelfPlay;
class Sex;

class SexViewForm : public QWidget
{
    Q_OBJECT
    friend SelfPlay;
    friend Sex;
signals:
    void sigSetGape(Body holeType, int horny, int dick, int silavag);
    void sigUpdParams();
public:
    explicit SexViewForm(QWidget *parent = nullptr);
    ~SexViewForm();
    void setLayoutPtr(QVBoxLayout* ptr);
    void selfPlayStart(Location* current);
private:
    void clearLayout();
    Ui::SexViewForm *ui;
    SelfPlay* m_selfplay;
    Sex* m_sex;
    QVBoxLayout* m_actLayout;
    int getSexVar(SexVar param);
    int getVStatus(Status param);
    int getVBody(Body param);
    int getItemCount(Items item);
    int getVAddict(Addiction param);
    int getBSC(SC param);
    void setSexVar(SexVar param, int value);
    void updSexVar(SexVar param, int value);
    void setVStatus(Status param, int value);
    void updVStatus(Status param, int value);
    void updVSC(SC param, int val);
    void updVBody(Body param, int val);
    void useItem(Items item, int count);
    void setVBody(Body param, int val);
    void incTime(int min);
    void setMainWidgetpage(int page);
    void changeLoc(Location* loc);
    Location* getCurLoc();
    QWidget* root;
};

enum SelfPlayActs
{
    actSP1, actSP2, actSP3, actSP4, actSP5, actSP6, actSP7, actSP8, actSP9, actSP10, actSP11, actSP12, actSP13, actSP14, actSP15,
    actSP16, actSP17, actSP18, actSP19, actSP20, actSP21, actSP22, actSP23, actSP24, actSP25, actSP26
};

enum SelfPlayDesc
{
    descSP1, descSP2, descSP3, descSP4, descSP5, descSP6, descSP7, descSP8, descSP9, descSP10, descSP11, descSP12, descSP13,
    descSP14, descSP15, descSP16, descSP17, descSP18, descSP19, descSP20, descSP21, descSP22, descSP23, descSP24, descSP25,
    descSP26, descSP27, descSP28, descSP29, descSP30, descSP31, descSP32, descSP33, descSP34, descSP35, descSP36, descSP37,
    descSP38, descSP39, descSP40, descSP41, descSP42, descSP43, descSP44, descSP45, descSP46, descSP47, descSP48, descSP49,
    descSP50, descSP51, descSP52, descSP53, descSP54, descSP55, descSP56, descSP57, descSP58, descSP59
};

class SexActionButton: public QPushButton
{
    Q_OBJECT
public:
    SexActionButton(SelfPlayActs act, QString actName);
signals:
    void sigAction(SelfPlayActs act);
private:
    SelfPlayActs m_action;
private slots:
    void handleButtonClick();
};

class SelfPlay: public QObject
{
    Q_OBJECT
public:
    SelfPlay(QWidget* parent);
    void start(Location* current);
private slots:
    void slotActionHandler(SelfPlayActs act);
private:
    Location* getCurLoc();
    void makeActBtn(SelfPlayActs act);
    void incTime(int min);
    void updVSexVar(SexVar var, int count);
    int getVSexVar(SexVar var);
    void bathInvasion();
    void selfPlayEnding();
    int getVStatus(Status param);
    int getVBody(Body param);
    void updVStatus(Status param, int value);
    void setVStatus(Status param, int value);
    void setVSexVar(SexVar param, int value);
    void setImg(QString text);
    void setDesc(QString text);
    void appendDesc(QString text);
    int m_vagTemp{0};
    int getItemCount(Items i);
    QString getActName(SelfPlayActs act);
    QString getActDesc(SelfPlayDesc desc);
    SexViewForm* root;
    int m_dildohand;
};

enum ToolType
{
    tDick,
    tDildo,
    tBottle,
    tGirlDildo,
    tGirlBottle,
    tStrapon
};

class Sex
{
public:
    Sex(QWidget* parent);
    void sexStart(int protect);
    void analStart(ToolType type = tDick, int protect = 0);
    void vaginal(ToolType type, QString pos = "");
    void anal(ToolType type);
private:
    SexViewForm* root;
    int m_protect;
    int m_cc_sex_usecondom;
//methods:
    int getSexVar(SexVar param);
    int getVStatus(Status param);
    int getVBody(Body param);
    int getItemCount(Items item);
    int getVAddict(Addiction param);
    int getBSC(SC param);
    void setSexVar(SexVar param, int value);
    void updSexVar(SexVar param, int value);
    void setVStatus(Status param, int value);
    void updVStatus(Status param, int value);
    void updVSC(SC param, int val);
    void useItem(Items item, int count);
    void setVBody(Body param, int val);
    void checkTextOutput(int addTxtSex, QString text);
};

#endif // SEXVIEWFORM_H
