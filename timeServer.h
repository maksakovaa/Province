#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QString>
#include <ctime>
#include <QObject>
#include "settings.h"

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
    TimeServer(int year, int month, int day, int hour, int minutes);
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
    void setSettingsPtr(Settings* ptr);
signals:
    void updateTimeAndDate();
    void sigElapsed5minutes();
    void sigElapsed10minutes();
    void sigElapsed15minutes();
    void sigElapsed20minutes();
    void sigElapsed30minutes();
    void sigElapsed60minutes();
    void sigElapsedDay();
    void sigElapsedTime();
public slots:
    void calcDateDiffInYears(int& years, struct tm from);
    int calcDateDiffInDays();
    void increaseTime(int minutes);
private:
    void updCounters(int min);
    void chkCounters();
    void isDayOver();
    void updOldTime();
    Settings* m_settings;
    struct tm currTimePoint{};
    struct tm oldTime{};
    struct TimeCounters counters;
    QString nul;
};
#endif
