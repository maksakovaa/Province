#include "weather.h"
#include "Functions.h"

Weather::Weather() 
{
    initTemperatureArray();
    _forecast_flag = 0;
}

bool Weather::isDay()
{
    return (m_time->getHour() >= getSunrise(m_time->getMonth()) && m_time->getHour() <= getSunset(m_time->getMonth()));
}

bool Weather::isSnow()
{
    return m_snow > 0;
}

QString Weather::getImage()
{
    QString image;
    if (sunWeather == 1)
    {
        if(m_time->getHour() > 12)
        {
            image += intQStr(4);
        }
        else
        {
            image += intQStr(3);
        }
    }

    if(sunWeather == 2)
    {
        image += intQStr(2);
    }

    if(sunWeather == 3)
    {
        image += intQStr(1);
    }
    if(sunWeather >= 4)
    {
        image += intQStr(0);
    }
    if(sunWeather == -1)
    {
        if(currentTemp > 0)
        {
            image += intQStr(5);
        }
        else
        {
            image += intQStr(7);
        }
    }
    if(sunWeather < -1)
    {
        if(currentTemp > 0)
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
    return ":/img/weather/"+ image + ".png";
}

QString Weather::getCurrentTemp()
{
    QString text;
    if(_forecast_flag == 0)
    {
        text = intQStr(currentTemp) + " °C";
    }
    else
    {
        if(m_forecast_tcMin <= m_forecast_tcMax)
        {
            text = intQStr(m_forecast_tcMin) + "..." + intQStr(m_forecast_tcMax) + "<br>°C";
        }
        else
        {
            text = intQStr(m_forecast_tcMax) + "..." + intQStr(m_forecast_tcMin) + "<br>°C";
        }
    }
    return text;
}

void Weather::setTimePtr(TimeServer *ptr)
{
    m_time = ptr;
    mainFunc();
}

void Weather::updOnTimeMove()
{
    weatherDay = -1;
    mainFunc();
    if (currentTemp < 0)
    {
        m_snow += getRandInt(2,5);
    }
    else if (currentTemp > 0)
    {
        m_snow = 0;
    }
}

void Weather::mainFunc()
{
    if (weatherDay == m_time->getDay())
    {
        return;
    }
    weatherDay = m_time->getDay();
    
    if(currentTemp > 0 && m_snow > 0)
    {
        m_snow -= currentTemp;
    }
    getSunWeather();
    setCurrentTemp();
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
            if (m_snow < 30)
            {
                m_snow += 1;
                currentTemp += getRandInt(1,3);
            }
            if(currentTemp > 0)
            {
                currentTemp = 0;
            }
        }
    }
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
    currentTemp = temperature[m_time->getMonth() - 1][m_time->getDay()/10];
}

void Weather::setForecast()
{
    m_forecast_month = m_time->getMonth();
    m_forecast_day = m_time->getDay();

    if((m_time->getMonth() == 1 || m_time->getMonth() == 5|| m_time->getMonth() == 7|| m_time->getMonth() == 8|| m_time->getMonth() == 10 || m_time->getMonth() == 12) && m_time->getDay() == 31)
    {
        m_forecast_day = 1;
    }
    else if(m_time->getMonth() == 2 && ( m_time->getDay() == 28 || m_time->getDay() == 29))
    {
        if((m_time->getYear() % 4 == 0 && m_time->getDay() == 29) || (m_time->getYear() % 4 > 0 && m_time->getDay() == 28))
        {
            m_forecast_day = 1;
        }
        else
        {
            m_forecast_day += 1;
        }
    }
    else if ((m_time->getMonth() == 2 || m_time->getMonth() == 4 || m_time->getMonth() == 6 || m_time->getMonth() == 9 || m_time->getMonth() == 11) && m_time->getDay() == 30)
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

int Weather::getSunWeather()
{
    if(sunWeather == 1)
    {
        if(m_time->getMonth() == 4 || m_time->getMonth() == 5)
        {
            sunWeather = getRandInt(-3,-1);
        }
        else if(m_time->getMonth() >= 9 && m_time->getMonth() <= 11)
        {
            sunWeather = getRandInt(-4,-1);
        }
        else if (m_time->getMonth() >= 6 && m_time->getMonth() <= 8)
        {
            sunWeather = getRandInt(-2,-1);
        }
        else
            sunWeather = getRandInt(-3,-1);
    }
    else if (sunWeather == -1)
    {
        if(m_time->getMonth() == 4 || m_time->getMonth() == 5)
        {
            sunWeather = getRandInt(4,6);
        }
        else if(m_time->getMonth() >= 9 && m_time->getMonth() <= 11)
        {
            sunWeather = getRandInt(3,5);
        }
        else if (m_time->getMonth() >= 6 && m_time->getMonth() <= 8)
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
