#include "Functions.h"
#include <random>
#include <QVBoxLayout>
#include <QLabel>

int getRandInt(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<> dist(min,max);
    return dist(rng);
}

int getItemArr(int arr[], int arr_size, int id)
{
    int result {0};
    if(id < 0)
    {
        result = arr[getRandInt(0,arr_size - 1)];
    }
    else
    {
        if ((arr_size) > id)
        {
            result = arr[id];
        }
    }
    return result;
}

QString letgoda(int age)
{   
    QString result;
    int lastNum = age % 10;

    if(age == 11 || age == 12 || age == 13 || age == 14)
    {
        result = "лет";
    }
    else if(lastNum == 2 || lastNum == 3 || lastNum == 4 || lastNum % 10 == 1 && age != 11 && age != 12 && age !=13 && age !=14)
    {
        result = "года";
    }
    else if(lastNum == 5 || lastNum == 6 || lastNum == 7 || lastNum == 8 || lastNum == 9 || lastNum == 0)
    {
        result = "лет";
    }
    return result;
}

QString letgoda2(int age)
{
    if(age % 10 == 1) { return "года";}
    else { return "лет"; }
}

QString intQStr(int value)
{
    return QString::number(value);
}

void makeLink(QString& txt, const QString& link)
{
    txt = "<a style='text-decoration:none' href = '" + link + "'>" + txt + "</a>";
}

QString styleForBar(int value, int maxv, int type)
{
    int maxValue, val;

    if(maxv == 0) { maxValue = 1; }
    else { maxValue = maxv; }

    val = std::abs(value * 100 / maxValue);

    if (val < 1) { val = 1; }
    if (val > 100) { val = 100; }

    QString res;
    if(val < 30)
    {
        if (type == 1)
        {
            res = "#348017";
        }
        else
        {
            res = "#C11B17";
        }
    }
    if(val >= 30 && val < 70 && type == 0)
    {
        res = "#3BB9FF";
    }
    if(val >= 30 && val < 50 && type == 1)
    {
        res = "#FFA62F";
    }
    if(val >= 50 && val < 70 && type == 1)
    {
        res = "#E56717";
    }
    if (val >= 70)
    {
        if(type == 1)
        {
            res = "#C11B17";
        }
        else
        {
            res = "#348017";
        }
    }
    if(type == 2)
    {
        if(val < 20) { res = "#C11B17"; }
        if(val >= 20 && val < 40) { res = "#E56717"; }
        if(val >= 40 && val < 60) { res = "#FFA62F"; }
        if(val >= 60 && val < 80) { res = "#3BB9FF"; }
        if(val >= 80) { res = "#348017"; }
    }

    QString style = "QProgressBar { background-color: #C0C6CA; border: 0px; padding: 0px; height: 16px; text-align: right; margin-right: 25px;}"
                    "QProgressBar::chunk { background: " + res + "; width:5px; height: 16px;}";

    return style;
}

int getSexuality()
{
    return getRandInt(0, 2);
}

int genDick(int arg)
{
    if(arg != 0) { return arg; }
    int _tmp = getRandInt(1,100);
    int _tmpDick;
    if(_tmp >= 99)
    {
        _tmpDick = getRandInt(28,31);
    }
    else if (_tmp >= 95)
    {
        _tmpDick = getRandInt(24,27);
    }
    else if (_tmp >= 75)
    {
        _tmpDick = getRandInt(22,23);
    }
    else if (_tmp >= 65)
    {
        _tmpDick = getRandInt(18,21);
    }
    else if (_tmp >= 25)
    {
        _tmpDick = getRandInt(16,17);
    }
    else
    {
        _tmpDick = getRandInt(12,15);
    }
    return _tmpDick;
}

QString makeImg(QString path)
{
    return "<img style='max-width: 500px; max-height: 1000px' src='"+path+"'></img>";
}

void ClearLayout(QLayout *layout)
{
    while (layout->count() > 0)
    {
        QLayoutItem* item = layout->takeAt(0);
        if(item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}
