#ifndef WEATHER_H
#define WEATHER_H
#include <QString>
#include "timeServer.h"

class Weather: public QObject
{
    Q_OBJECT
public:
    Weather();
    bool isDay();
    bool isSnow();
    QString getImage();
    QString getCurrentTemp();
    void setTimePtr(TimeServer* ptr);
    void updOnTimeMove();
public slots:
    void mainFunc();
private:
    TimeServer* m_time;
    int getSunrise(int month);
    int getSunset(int month);
    void initTemperatureArray();
    void setCurrentTemp();
    void setForecast();
    int getSunWeather();
    int sunWeather;
    int temperature[12][4];
    int weatherDay;
    int currentTemp;
    int m_forecast_day;
    int m_forecast_month;
    int m_forecast_sunny;
    int m_forecast_tc;
    int m_forecast_tcMin;
    int m_forecast_tcMax;
    int _forecast_flag;
    int m_snow;
};

#endif // WEATHER_H
