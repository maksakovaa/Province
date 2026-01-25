#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QString>
#include <ctime>
#include <QObject>

struct TimeCounters {
    int min_05;
    int min_10;
    int min_15;
    int min_20;
    int min_30;
    int min_60;
    int division;
};

class SaveForm;
class LoadForm;
class Game;

class TimeServer: public QObject
{
    Q_OBJECT
    friend SaveForm; friend LoadForm;
public:
    TimeServer(Game* ptr);
    TimeServer(Game* ptr,int year, int month, int day, int hour, int minutes);
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
    void setTime(int hour, int min = 0);
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
       
    void updCounters(int min);
    void chkCounters();
    void isDayOver();
    void updOldTime();
    Game* root;
    struct tm currTimePoint{};
    struct tm oldTime{};
    struct TimeCounters counters;
    QString nul;
};
#endif
