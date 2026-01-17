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

class SaveForm; class LoadForm;

class Weather: public QObject
{
    Q_OBJECT
    friend SaveForm; friend LoadForm;
public:
    Weather(QWidget *ptr);
    bool isDay();
    bool isSnow();
    QString getImage();
    QString getCurrentTemp();
    void updOnTimeMove();
    int getSunWeather();
    int getSnow();
    int getTemp();
    int getSunrise();
    int getSunset();
public slots:
    void mainFunc();
private:
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
    int temperature[12][4];
};

#endif // WEATHER_H
