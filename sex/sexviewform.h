#ifndef SEXVIEWFORM_H
#define SEXVIEWFORM_H

#include "nav/location.h"
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <settingsform.h>
#include "sex.h"
#include "selfplay.h"

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
    void sigReload();
public:
    explicit SexViewForm(QWidget *parent = nullptr);
    ~SexViewForm();
    void setLayoutPtr(QVBoxLayout* ptr);
    void selfPlayStart();
    void reloadActions();
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

#endif // SEXVIEWFORM_H
