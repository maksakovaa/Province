#include "timeServer.h"
#include <chrono>
#include "Functions.h"

TimeServer::TimeServer(int year, int month, int day, int hour, int minutes)
{
    counters.division = 0;
    counters.min_05 = 0;
    counters.min_10 = 0;
    counters.min_15 = 0;
    counters.min_20 = 0;
    counters.min_30 = 0;
    counters.min_60 = 0;

    currTimePoint.tm_year = year - 1900;
    currTimePoint.tm_mon = month - 1;
    currTimePoint.tm_mday = day;
    currTimePoint.tm_hour = hour;
    currTimePoint.tm_min = minutes;
    currTimePoint.tm_sec = 0;
    
    nul = intQStr(0);
    mktime(&currTimePoint);
    updOldTime();
    mktime(&oldTime);
}

QString TimeServer::getTime()
{
    QString hour, minutes;

    if(currTimePoint.tm_hour < 10)
        hour += nul;
    hour += intQStr(currTimePoint.tm_hour);

    if (currTimePoint.tm_min < 10)
        minutes += nul;
    minutes += QString::number(currTimePoint.tm_min);

    if (m_settings->isCheats())
    {
        makeLink(hour, "hour");
        makeLink(minutes, "minutes");
    }
    
    return hour + ":" + minutes;
}

QString TimeServer::getDateStr()
{
    return getDateStr(currTimePoint);
}

QString TimeServer::getDateStr(struct tm tp)
{
    QString day, year, month;
    if (tp.tm_mday < 10)
        day += nul;
    day += intQStr(tp.tm_mday);
    if (tp.tm_mon + 1 < 10)
        month += nul;
    month += intQStr(tp.tm_mon +1);
    year += intQStr(tp.tm_year + 1900);
    if (m_settings->isCheats())
    {
        makeLink(day, "day");
        makeLink(month, "month");
        makeLink(year, "year");
    }    
    return day + "." + month + "." + year;
}

QString TimeServer::getDayOfWeek()
{
    QString week[] {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    return week[currTimePoint.tm_wday];
}

int TimeServer::getYear()
{
    return currTimePoint.tm_year + 1900;
}

int TimeServer::getMonth()
{
    return currTimePoint.tm_mon + 1;
}

int TimeServer::getDay()
{
    return currTimePoint.tm_mday;
}

int TimeServer::getHour()
{
    return currTimePoint.tm_hour;
}

int TimeServer::getMin()
{
    return currTimePoint.tm_min;
}

void TimeServer::setSettingsPtr(Settings *ptr)
{
    m_settings = ptr;
}

int TimeServer::calcDateDiffInDays()
{
    std::chrono::time_point tp1 = std::chrono::system_clock::from_time_t(mktime(&currTimePoint));
    std::chrono::time_point tp2 = std::chrono::system_clock::from_time_t(mktime(&oldTime));
    auto diff = tp1 - tp2;
    return std::chrono::duration_cast<std::chrono::days>(diff).count();
}

void TimeServer::increaseTime(int minutes)
{
    if (minutes == 0)
    {
        emit updateTimeAndDate();
        return;
    }
    
    currTimePoint.tm_min += minutes;
    mktime(&currTimePoint);
    updCounters(minutes);
    isDayOver();
    emit sigElapsedTime();
    emit updateTimeAndDate();
}



void TimeServer::updCounters(int min)
{
    if (min == 0)
    {
        return;
    }
    
    int time = min + counters.division;
    counters.division = 0;

    while (time != 0)
    {
        if (time >= 5)
        {
            counters.min_05++;
            time -= 5;
            emit sigElapsed5minutes();
        }
        else
        {
            counters.division = time;
            time = 0;
        }
        chkCounters();
    }
}

void TimeServer::chkCounters()
{

    if (counters.min_05 == 2)
    {
        counters.min_10++;
        counters.min_05 = 0;
        emit sigElapsed10minutes();
    }

    if (counters.min_10 == 1 && counters.min_05 == 1)
    {
        emit sigElapsed15minutes();
    }

    if (counters.min_10 == 2)
    {
        counters.min_20++;
        counters.min_10 = 0;
        emit sigElapsed20minutes();
    }

    if (counters.min_20 == 1 && counters.min_10 == 1)
    {
        counters.min_30++;
        counters.min_20 = 0;
        counters.min_10 = 0;
        emit sigElapsed30minutes();
    }

    if (counters.min_30 == 2)
    {
        counters.min_60 = 0;
        counters.min_30 = 0;
        emit sigElapsed60minutes();
    }
}

void TimeServer::isDayOver()
{
    int dayDiff = calcDateDiffInDays();
    if (dayDiff > 0)
    {
        while (dayDiff != 0)
        {
            emit sigElapsedDay();
            dayDiff--;
        }
        updOldTime();
    }
}

void TimeServer::updOldTime()
{
    oldTime.tm_year = currTimePoint.tm_year;
    oldTime.tm_mon = currTimePoint.tm_mon;
    oldTime.tm_mday = currTimePoint.tm_mday;
    oldTime.tm_hour = currTimePoint.tm_hour;
    oldTime.tm_min = currTimePoint.tm_min;
    oldTime.tm_sec = currTimePoint.tm_sec;
}

void TimeServer::calcDateDiffInYears(int& years, struct tm from)
{
    std::chrono::time_point tp1 = std::chrono::system_clock::from_time_t(mktime(&currTimePoint));
    std::chrono::time_point tp2 = std::chrono::system_clock::from_time_t(mktime(&from));
    auto diff = tp1 - tp2;
    years = std::chrono::duration_cast<std::chrono::years>(diff).count();
}

