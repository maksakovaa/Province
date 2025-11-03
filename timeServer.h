#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QString>
#include <ctime>
#include <QObject>
#include "player/enums.h"

struct TimeCounters {
    int min_05;
    int min_10;
    int min_15;
    int min_20;
    int min_30;
    int min_60;
    int division;
};

class TimeServer: public QObject
{
    Q_OBJECT
public:
    TimeServer(QWidget* ptr,int year, int month, int day, int hour, int minutes);
    ~TimeServer() = default;
    QString getTime();
    QString getDateStr();
    QString getDateStr(struct tm tp);
    QString getDayOfWeek();
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMin();
    int getWeekNum();
    void firstStart();
    int calcYears(struct tm from);
signals:
    void sigElapsed5minutes();
public slots:
    int calcDateDiffInDays();
    void increaseTime(int minutes);
private:

    void slotUpdParams();
    void statNoTime();
    void Elapsed5minutes();
    void Elapsed10minutes();
    void Elapsed15minutes();
    void Elapsed20minutes();
    void Elapsed30minutes();
    void Elapsed60minutes();
    void ElapsedDay();
    void ElapsedTime();
    void calcEnding();
       
    int vBody(Body param);
    int vSex(SexVar param);
    int vStatus(Status param);
    int vSkill(Skills param);
    int vConst(Const param);
    int vSC(SC param);
    int vAddict(Addiction param);
    int vSick(Sickness param);

    void updVBody(Body param, int val);
    void updVStatus(Status param, int val);
    void updVSex(SexVar param, int val);
    void updVSkill(Skills param, int val);
    void updVSick(Sickness param, int val);
    void updVAddict(Addiction param, int val);

    void setVBody(Body param, int val);
    void setVSex(SexVar param, int val);
    void setVStatus(Status param, int val);
    void setVSC(SC param, int val);
    void setVSkill(Skills param, int val);
    void setVSick(Sickness param, int val);
    void setVAddict(Addiction param, int val);

    void updCounters(int min);
    void chkCounters();
    void isDayOver();
    void updOldTime();
    QWidget* root;
    struct tm currTimePoint{};
    struct tm oldTime{};
    struct TimeCounters counters;
    QString nul;
};
#endif
