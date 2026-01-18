#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QObject>

class LocationHandler;

class Common: public QObject
{
    Q_OBJECT
public:
    Common(LocationHandler* ptr);
    void icecream();
    void coffee();
    void go_back();
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
    void check_inhome();
    void wet_wipes();
    int getClothDecreaseLevel();
    void fnsport(int arg = 0);
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
    void select_coffee(QString coffee);
private:
    void check_sport_suit();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    LocationHandler* root;
    int watch_tv_count{0};
};

#endif // COMMON_H
