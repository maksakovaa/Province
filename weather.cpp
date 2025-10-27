#include "weather.h"
#include "Functions.h"

Weather::Weather() {
    initTemperatureArray();
    _forecast_flag = 1;
}

QString Weather::getImage(int year, int month, int day, int hour, int min)
{
    mainFunc(year, month, day);
    QString image;
    if (m_forecast_sunny == 1)
    {
        if(hour > 12)
        {
            image += intQStr(4);
        }
        else
        {
            image += intQStr(3);
        }
    }

    if(m_forecast_sunny == 2)
    {
        image += intQStr(2);
    }

    if(m_forecast_sunny == 3)
    {
        image += intQStr(1);
    }
    if(m_forecast_sunny >= 4)
    {
        image += intQStr(0);
    }
    if(m_forecast_sunny == -1)
    {
        if(m_forecast_tc > 0)
        {
            image += intQStr(5);
        }
        else
        {
            image += intQStr(7);
        }
    }
    if(m_forecast_sunny < -1)
    {
        if(m_forecast_tc > 0)
        {
            image += intQStr(6);
        }
        else
        {
            image += intQStr(8);
        }
    }

    if(_forecast_flag == 0)
    {
        if(getDayOrNight(hour, min))
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
    return ":/img/weather/"+ image + ".png";
}

QString Weather::getCurrentTemp()
{
    QString text;
    if(_forecast_flag == 0)
    {
        text = intQStr(m_forecast_tc) + "&deg;C";
    }
    else
    {
        if(m_forecast_tcMin <= m_forecast_tcMax)
        {
            text = intQStr(m_forecast_tcMin) + "..." + intQStr(m_forecast_tcMax) + "<br>&deg;C";
        }
        else
        {
            text = intQStr(m_forecast_tcMax) + "..." + intQStr(m_forecast_tcMin) + "<br>&deg;C";
        }
    }
    return text;
}

void Weather::mainFunc(int year, int month, int day)
{
    if(currentTemp > 0 && snow >0)
    {
        snow -= currentTemp;
    }
    getSunWeather(month);
    setCurrentTemp(month, day);
    if(sunWeather < -1)
    {
        sunWeather += 1;
    }
    else if (sunWeather > 1)
    {
        sunWeather -= 1;
    }

    if (sunWeather >0)
    {
        if(currentTemp < 0)
        {
            currentTemp -= getRandInt(1,3);
        }
        else
        {
            currentTemp += getRandInt(1,3);
        }
    }
    else if (sunWeather < 0)
    {
        if(currentTemp < 0)
        {
            if (snow < 30)
            {
                snow += 1;
                currentTemp += getRandInt(1,3);
            }
            if(currentTemp > 0)
            {
                currentTemp = 0;
            }
        }
    }
    setForecast(year, month, day);
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

bool Weather::getDayOrNight(int hour, int month)
{
    return (hour >= getSunrise(month) && hour <= getSunset(month));
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

void Weather::setCurrentTemp(int month, int day)
{
    currentTemp = temperature[month - 1][day/10];
}

void Weather::setForecast(int year, int month, int day)
{
    m_forecast_month = month;
    m_forecast_day = day;

    if((month == 1 || month == 5|| month == 7|| month == 8|| month == 10 || month == 12) && day == 31)
    {
        m_forecast_day = 1;
    }
    else if(month == 2 && ( day == 28 || day == 29))
    {
        if((year % 4 == 0 && day == 29) || (year % 4 > 0 && day == 28))
        {
            m_forecast_day = 1;
        }
        else
        {
            m_forecast_day += 1;
        }
    }
    else if ((month == 2 || month == 4 || month == 6 || month == 9 || month == 11) && day == 30)
    {
        m_forecast_day = 1;
    }
    else
    {
        m_forecast_day += 1;
    }
    //check month
    if(m_forecast_day == 1)
    {
        m_forecast_month += 1;
    }
    if (m_forecast_month == 13)
    {
        m_forecast_month = 1;
    }
    if(sunWeather > 1)
    {
        m_forecast_sunny = sunWeather - 1;
    }
    else if (sunWeather == 1)
    {
        m_forecast_sunny = -1;
    }
    else if(sunWeather == 0)
    {
        m_forecast_sunny = 1;
    }
    else if(sunWeather == -1)
    {
        m_forecast_sunny = 3;
    }
    else if(sunWeather < -1)
    {
        m_forecast_sunny = sunWeather + 1;
    }
    m_forecast_tc = temperature[m_forecast_month - 1][m_forecast_day / 10];
    if (m_forecast_sunny >= 0)
    {
        if(m_forecast_tc < 0)
        {
            m_forecast_tcMin = m_forecast_tc - 3;
            m_forecast_tcMax = m_forecast_tc - 1;
        }
        else
        {
            m_forecast_tcMin = m_forecast_tc + 1;
            m_forecast_tcMax = m_forecast_tc + 3;
        }
    }
    else
    {
        if(m_forecast_tc < 0)
        {
            m_forecast_tcMin = m_forecast_tc + 1;
            m_forecast_tcMax = m_forecast_tc + 3;
            if(m_forecast_tcMax > 0)
            {
                m_forecast_tcMax = 0;
            }
        }
        else
        {
            m_forecast_tcMin = m_forecast_tc - 3;
            m_forecast_tcMax = m_forecast_tc - 1;
            if(m_forecast_tcMin < 0)
            {
                m_forecast_tcMin = 0;
            }
        }
    }
}

int Weather::getSunWeather(int month)
{
    if(sunWeather == 1)
    {
        if(month == 4 || month == 5)
        {
            sunWeather = getRandInt(-3,-1);
        }
        else if(month >= 9 && month <= 11)
        {
            sunWeather = getRandInt(-4,-1);
        }
        else if (month >= 6 && month <= 8)
        {
            sunWeather = getRandInt(-2,-1);
        }
        else
            sunWeather = getRandInt(-3,-1);
    }
    else if (sunWeather == -1)
    {
        if(month == 4 || month == 5)
        {
            sunWeather = getRandInt(4,6);
        }
        else if(month >= 9 && month <= 11)
        {
            sunWeather = getRandInt(3,5);
        }
        else if (month >= 6 && month <= 8)
        {
            sunWeather = getRandInt(6,10);
        }
        else
            sunWeather = getRandInt(3,6);
    }
    else if (sunWeather == 0)
    {
        sunWeather = getRandInt(1,3);
    }
    return sunWeather;
}
