#include "weather.h"
#include "Functions.h"
#include "mainwindow.h"

Weather::Weather(QWidget* ptr): root(ptr)
{
    initTemperatureArray();
    m_weather[_forecast_flag] = 0;
    mainFunc();
}

bool Weather::isDay()
{
    return (getHour() >= getSunrise(getMonth()) && getHour() <= getSunset(getMonth()));
}

bool Weather::isSnow()
{
    return m_weather[snow] > 0;
}

QString Weather::getImage()
{
    QString image;
    if (m_weather[sunWeather] == 1)
    {
        if(getHour() > 12)
        {
            image += intQStr(4);
        }
        else
        {
            image += intQStr(3);
        }
    }

    if(m_weather[sunWeather] == 2)
    {
        image += intQStr(2);
    }

    if(m_weather[sunWeather] == 3)
    {
        image += intQStr(1);
    }
    if(m_weather[sunWeather] >= 4)
    {
        image += intQStr(0);
    }
    if(m_weather[sunWeather] == -1)
    {
        if(m_weather[currentTemp] > 0)
        {
            image += intQStr(5);
        }
        else
        {
            image += intQStr(7);
        }
    }
    if(m_weather[sunWeather] < -1)
    {
        if(m_weather[currentTemp] > 0)
        {
            image += intQStr(6);
        }
        else
        {
            image += intQStr(8);
        }
    }

    if(m_weather[_forecast_flag] == 0)
    {
        if(isDay())
        {
            image = "d" + image;
        }
        else
        {
            image = "n" + image;
        }
    }
    else
    {
        image = "d" + image;
    }
    return "data/img/weather/"+ image + ".png";
}

QString Weather::getCurrentTemp()
{
    QString text;
    if(m_weather[_forecast_flag] == 0)
    {
        text = intQStr(m_weather[currentTemp]) + " °C";
    }
    else
    {
        if(m_weather[forecast_tcMin] <= m_weather[forecast_tcMax])
        {
            text = intQStr(m_weather[forecast_tcMin]) + "..." + intQStr(m_weather[forecast_tcMax]) + "<br>°C";
        }
        else
        {
            text = intQStr(m_weather[forecast_tcMax]) + "..." + intQStr(m_weather[forecast_tcMin]) + "<br>°C";
        }
    }
    return text;
}

void Weather::updOnTimeMove()
{
    m_weather[weatherDay] = -1;
    mainFunc();
    if (m_weather[currentTemp] < 0)
    {
        m_weather[snow] += getRandInt(2,5);
    }
    else if (m_weather[currentTemp] > 0)
    {
        m_weather[snow] = 0;
    }
}

void Weather::mainFunc()
{
    if (m_weather[weatherDay] == getDay())
    {
        return;
    }
    m_weather[weatherDay] = getDay();
    
    if(m_weather[currentTemp] > 0 && m_weather[snow] > 0)
    {
        m_weather[snow] -= m_weather[currentTemp];
    }
    getSunWeather();
    setCurrentTemp();
    if(m_weather[sunWeather] < -1)
    {
        m_weather[sunWeather] += 1;
    }
    else if (m_weather[sunWeather] > 1)
    {
        m_weather[sunWeather] -= 1;
    }

    if (m_weather[sunWeather] >0)
    {
        if(m_weather[currentTemp] < 0)
        {
            m_weather[currentTemp] -= getRandInt(1,3);
        }
        else
        {
            m_weather[currentTemp] += getRandInt(1,3);
        }
    }
    else if (m_weather[sunWeather] < 0)
    {
        if(m_weather[currentTemp] < 0)
        {
            if (m_weather[snow] < 30)
            {
                m_weather[snow] += 1;
                m_weather[currentTemp] += getRandInt(1,3);
            }
            if(m_weather[currentTemp] > 0)
            {
                m_weather[currentTemp] = 0;
            }
        }
    }
}

int Weather::getHour()
{
    return ((MainWindow*)root)->m_time.getHour();
}

int Weather::getMonth()
{
    return ((MainWindow*)root)->m_time.getMonth();
}

int Weather::getDay()
{
    return ((MainWindow*)root)->m_time.getDay();
}

int Weather::getYear()
{
    return ((MainWindow*)root)->m_time.getYear();
}

int Weather::getSunrise(int month)
{
    int arr[] = {8,7,7,6,5,5,5,6,6,7,7,8};
    return getItemArr(arr, 12, month - 1);
}

int Weather::getSunset(int month)
{
    int arr[] = {16,17,18,19,20,21,21,20,19,18,17,16};
    return getItemArr(arr, 12, month - 1);
}

void Weather::initTemperatureArray()
{
    temperature[0][0] = -10;
    temperature[0][1] = -12;
    temperature[0][2] = -14;
    temperature[0][3] = -12;

    temperature[1][0] = -8;
    temperature[1][1] = -6;
    temperature[1][2] = -4;
    temperature[1][3] = -6;

    temperature[2][0] = -2;
    temperature[2][1] = 0;
    temperature[2][2] = 2;
    temperature[2][3] = 4;

    temperature[3][0] = 6;
    temperature[3][1] = 8;
    temperature[3][2] = 10;
    temperature[3][3] = 11;

    temperature[4][0] = 12;
    temperature[4][1] = 14;
    temperature[4][2] = 16;
    temperature[4][3] = 17;

    temperature[5][0] = 19;
    temperature[5][1] = 21;
    temperature[5][2] = 23;
    temperature[5][3] = 25;

    temperature[6][0] = 27;
    temperature[6][1] = 29;
    temperature[6][2] = 31;
    temperature[6][3] = 30;

    temperature[7][0] = 30;
    temperature[7][1] = 28;
    temperature[7][2] = 26;
    temperature[7][3] = 24;

    temperature[8][0] = 24;
    temperature[8][1] = 22;
    temperature[8][2] = 20;
    temperature[8][3] = 18;

    temperature[9][0] = 16;
    temperature[9][1] = 13;
    temperature[9][2] = 10;
    temperature[9][3] = 8;

    temperature[10][0] = 6;
    temperature[10][1] = 3;
    temperature[10][2] = 0;
    temperature[10][3] = -2;

    temperature[11][0] = -4;
    temperature[11][1] = -6;
    temperature[11][2] = -8;
    temperature[11][3] = -10;
}

void Weather::setCurrentTemp()
{
    m_weather[currentTemp] = temperature[getMonth() - 1][getDay()/10];
}

void Weather::setForecast()
{
    m_weather[forecast_month] = getMonth();
    m_weather[forecast_day] = getDay();

    if((getMonth() == 1 || getMonth() == 5|| getMonth() == 7|| getMonth() == 8|| getMonth() == 10 || getMonth() == 12) && getDay() == 31)
    {
        m_weather[forecast_day] = 1;
    }
    else if(getMonth() == 2 && ( getDay() == 28 || getDay() == 29))
    {
        if((getYear() % 4 == 0 && getDay() == 29) || (getYear() % 4 > 0 && getDay() == 28))
        {
            m_weather[forecast_day] = 1;
        }
        else
        {
            m_weather[forecast_day] += 1;
        }
    }
    else if ((getMonth() == 2 || getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11) && getDay() == 30)
    {
        m_weather[forecast_day] = 1;
    }
    else
    {
        m_weather[forecast_day] += 1;
    }
    //check month
    if(m_weather[forecast_day] == 1)
    {
        m_weather[forecast_month] += 1;
    }
    if (m_weather[forecast_month] == 13)
    {
        m_weather[forecast_month] = 1;
    }
    if(m_weather[sunWeather] > 1)
    {
        m_weather[forecast_sunny] = sunWeather - 1;
    }
    else if (m_weather[sunWeather] == 1)
    {
        m_weather[forecast_sunny] = -1;
    }
    else if(m_weather[sunWeather] == 0)
    {
        m_weather[forecast_sunny] = 1;
    }
    else if(m_weather[sunWeather] == -1)
    {
        m_weather[forecast_sunny] = 3;
    }
    else if(m_weather[sunWeather] < -1)
    {
        m_weather[forecast_sunny] = m_weather[sunWeather] + 1;
    }
    m_weather[forecast_tc] = temperature[m_weather[forecast_month] - 1][m_weather[forecast_day] / 10];
    if (m_weather[forecast_sunny] >= 0)
    {
        if(m_weather[forecast_tc] < 0)
        {
            m_weather[forecast_tcMin] = m_weather[forecast_tc] - 3;
            m_weather[forecast_tcMax] = m_weather[forecast_tc] - 1;
        }
        else
        {
            m_weather[forecast_tcMin] = m_weather[forecast_tc] + 1;
            m_weather[forecast_tcMax] = m_weather[forecast_tc] + 3;
        }
    }
    else
    {
        if(m_weather[forecast_tc] < 0)
        {
            m_weather[forecast_tcMin] = m_weather[forecast_tc] + 1;
            m_weather[forecast_tcMax] = m_weather[forecast_tc] + 3;
            if(m_weather[forecast_tcMax] > 0)
            {
                m_weather[forecast_tcMax] = 0;
            }
        }
        else
        {
            m_weather[forecast_tcMin] = m_weather[forecast_tc] - 3;
            m_weather[forecast_tcMax] = m_weather[forecast_tc] - 1;
            if(m_weather[forecast_tcMin] < 0)
            {
                m_weather[forecast_tcMin] = 0;
            }
        }
    }
}

int Weather::getSunWeather()
{
    if(m_weather[sunWeather] == 1)
    {
        if(getMonth() == 4 || getMonth() == 5)
        {
            m_weather[sunWeather] = getRandInt(-3,-1);
        }
        else if(getMonth() >= 9 && getMonth() <= 11)
        {
            m_weather[sunWeather] = getRandInt(-4,-1);
        }
        else if (getMonth() >= 6 && getMonth() <= 8)
        {
            m_weather[sunWeather] = getRandInt(-2,-1);
        }
        else
            m_weather[sunWeather] = getRandInt(-3,-1);
    }
    else if (m_weather[sunWeather] == -1)
    {
        if(getMonth() == 4 || getMonth() == 5)
        {
            m_weather[sunWeather] = getRandInt(4,6);
        }
        else if(getMonth() >= 9 && getMonth() <= 11)
        {
            m_weather[sunWeather] = getRandInt(3,5);
        }
        else if (getMonth() >= 6 && getMonth() <= 8)
        {
            m_weather[sunWeather] = getRandInt(6,10);
        }
        else
            m_weather[sunWeather] = getRandInt(3,6);
    }
    else if (m_weather[sunWeather] == 0)
    {
        m_weather[sunWeather] = getRandInt(1,3);
    }
    return m_weather[sunWeather];
}

int Weather::getSnow()
{
    return m_weather[snow];
}

int Weather::getTemp()
{
    return m_weather[currentTemp];
}

int Weather::getSunrise()
{
    return getSunrise(getMonth());
}

int Weather::getSunset()
{
    return getSunset(getMonth());
}
