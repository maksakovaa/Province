#ifndef WEATHER_H
#define WEATHER_H
#include <QString>

class Weather
{
public:
    Weather();
    QString getImage(int year, int month, int day, int hour, int min);
    QString getCurrentTemp();
private:
    void mainFunc(int year, int month, int day);
    int getSunrise(int month);
    int getSunset(int month);
    bool getDayOrNight(int hour, int month); //0 night, 1 day
    void initTemperatureArray();
    void setCurrentTemp(int month, int day);
    void setForecast(int year, int month, int day);
    int getSunWeather(int month);
    int sunWeather;
    int temperature[12][4];
    int currentTemp;
    int m_forecast_day;
    int m_forecast_month;
    int m_forecast_sunny;
    int m_forecast_tc;
    int m_forecast_tcMin;
    int m_forecast_tcMax;
    int _forecast_flag;
    int snow;
};

#endif // WEATHER_H
