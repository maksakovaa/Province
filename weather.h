#ifndef WEATHER_H
#define WEATHER_H

#include <QString>
#include <QObject>

enum WeatherVar
{
    sunWeather,
    weatherDay,
    currentTemp,
    forecast_day,
    forecast_month,
    forecast_sunny,
    forecast_tc,
    forecast_tcMin,
    forecast_tcMax,
    _forecast_flag,
    snow
};

class Weather: public QObject
{
    Q_OBJECT
public:
    Weather(QWidget *ptr);
    bool isDay();
    bool isSnow();
    QString getImage();
    QString getCurrentTemp();
    // void setTimePtr(TimeServer* ptr);
    void updOnTimeMove();
    int getSunWeather();
    int getSnow();
    int getTemp();
    int getSunrise();
    int getSunset();
public slots:
    void mainFunc();
private:
//    TimeServer* m_time;
    int getHour();
    int getMonth();
    int getDay();
    int getYear();
    int getSunrise(int month);
    int getSunset(int month);
    void initTemperatureArray();
    void setCurrentTemp();
    void setForecast();
private:
    QWidget* root;
    std::unordered_map<WeatherVar,int> m_weather;
    // int sunWeather;
    int temperature[12][4];
    // int weatherDay;
    // int currentTemp;
    // int m_forecast_day;
    // int m_forecast_month;
    // int m_forecast_sunny;
    // int m_forecast_tc;
    // int m_forecast_tcMin;
    // int m_forecast_tcMax;
    // int _forecast_flag;
    // int m_snow;
};

#endif // WEATHER_H
