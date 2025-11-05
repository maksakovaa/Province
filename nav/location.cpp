#include "location.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include "../Functions.h"

Location::Location(QString globalLoc)
{
    m_parent = nullptr;
    m_locId = globalLoc;
    m_isweather = false;
    QString folder_path = ":/locations/" + globalLoc + "/";
    QFile file(folder_path + globalLoc + ".loc");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file! " + file.fileName();
    }
    else
    {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd())
        {
            line = in.readLine();
            parseLocConfig(line, folder_path);
        }
    }
}

Location::Location(Location *parent, QString subloc, QString folder): m_parent(parent), m_locId(subloc)
{
    m_isweather = false;
    QString folder_path = folder + subloc + "/";
    QFile file(folder_path + subloc + ".loc");
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error opening file! " + file.fileName();
    }
    else
    {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd())
        {
            line = in.readLine();
            parseLocConfig(line, folder_path);
        }
    }
}

const std::vector<struct Action*> Location::availableActions()
{
    return m_actions;
}

const std::vector<Location *> Location::awailableLocs()
{
    return m_subLocs;
}

const std::vector<QString> Location::availableObjs()
{
    return m_obj;
}

bool Location::isParent()
{
    if(m_parent == nullptr)
        return false;
    else
        return true;
}

QString Location::getLocPic(bool isDay, bool isSnow)
{
    if (m_isweather == true)
    {
        return makeImage(m_image, isDay, isSnow);   
    }
    else
    {
        return m_image;
    }
}

QString Location::getLocId()
{
    return m_locId;
}

QString Location::getLocName()
{
    if (m_locName.isEmpty())
    {
        return m_locId;
    }
    else
    {
        return m_locName;
    }
}

QString Location::getActName()
{
    if(m_actName.isEmpty())
    {
        return getLocName();
    }
    else
    {
        return m_actName;
    }
}

QString Location::getLocIn()
{
    Location* parent = m_parent;
    if (parent != nullptr)
    {
        while (parent->isParent())
        {
            parent = parent->getParentPtr();
        }
        return parent->getLocId();
    }
    else
        return m_locId;
}

QString Location::getLocDesc()
{
    return m_desc;
}

QString Location::getLocHandler()
{
    return m_linkHandler;
}

Location *Location::getParentPtr()
{
    return m_parent;
}

void Location::parseLocConfig(QString str, QString folder)
{
    QString res;
    if(str.startsWith(indStart[name]))
    {
        m_locName = str.sliced(indStart[name].size(), str.indexOf(indEnd[name]) - indStart[name].size());
    }
    if (str.startsWith(indStart[actName]))
    {
        m_locName = str.sliced(indStart[actName].size(), str.indexOf(indEnd[actName]) - indStart[actName].size());
    }
    if(str.startsWith(indStart[image]))
    {
        res = str.sliced(indStart[image].size(), str.indexOf(indEnd[image]) - indStart[image].size());
        if (res.startsWith(indStart[param]))
        {
            parseRequiredImage(res, folder);
        }
        else
        {
            m_image = folder + res;
        }
    }
    if(str.startsWith(indStart[object]))
    {
        res = str.sliced(indStart[object].size(), str.indexOf(indEnd[object]) - indStart[object].size());
        m_obj.push_back(res);
    }
    if(str.startsWith(indStart[desc]))
    {
        res = str.sliced(indStart[desc].size(), str.indexOf(indEnd[desc]) - indStart[desc].size());
        m_desc += res;
    }
    if(str.startsWith(indStart[subloc]))
    {
        res = str.sliced(indStart[subloc].size(), str.indexOf(indEnd[subloc]) - indStart[subloc].size());
        Location* subLoc = new Location(this, res, folder);
        m_subLocs.push_back(subLoc);
    }
    if(str.startsWith(indStart[action]))
    {
        res = str.sliced(indStart[action].size(), str.indexOf(indEnd[action]) - indStart[action].size());
        parseActConfig(res);
    }
    if (str.startsWith(indStart[linkHandler]))
    {
        res = str.sliced(indStart[linkHandler].size(), str.indexOf(indEnd[linkHandler]) - indStart[linkHandler].size());
        m_linkHandler = res;
    }
    
}

void Location::parseRequiredImage(QString str, QString folder)
{
    QString req = str.sliced(str.indexOf(indStart[param]) + indStart[param].size(), str.indexOf(indEnd[param]) - indStart[param].size());
    if (req == "night_snow")
    {
        m_image = folder + str.sliced(str.indexOf(indEnd[param]) + indEnd[param].size());
        m_isweather = true;
    }
}

void Location::parseActConfig(QString res)
{
    Action *Act = new Action;
    if (res.startsWith(indStart[required]))
    {
        size_t reqOn = res.indexOf(indStart[required]) + indStart[required].size();
        size_t reqOff = res.indexOf(indEnd[required]) - reqOn;
        QString req = res.sliced(reqOn, reqOff);

        if (req.startsWith(indStart[reqitem]))
        {
            size_t itemStart = req.indexOf(indStart[reqitem]) + indStart[reqitem].size();
            size_t itemEnd = req.indexOf(indEnd[reqitem]) - itemStart;
            Act->item = req.sliced(itemStart, itemEnd);
            req = req.sliced(req.indexOf(indEnd[reqitem]) + indEnd[reqitem].size());
            parseValue(req, Act->itmValue, Act->itemVType);                
        }
        if (req.startsWith(indStart[param]))
        {
            size_t paramStart = indStart[param].size();
            size_t paramEnd = req.indexOf(indEnd[param]) - paramStart;
            Act->param = req.sliced(paramStart, paramEnd);
            req = req.sliced(req.indexOf(indEnd[param]) + indEnd[param].size());
            parseValue(req, Act->paramValue, Act->paramVType);
        }
        QString act = res.sliced(res.indexOf(indEnd[required]) + indEnd[required].size());
        if (act.startsWith(indStart[actName]))
        {
            size_t actNameStart = indStart[actName].size();
            size_t actNameEnd = act.indexOf(indEnd[actName]) - actNameStart;
            Act->actId = act.sliced(actNameStart,actNameEnd).toInt();
            act = act.sliced(act.indexOf(indEnd[actName]) + indEnd[actName].size());
        }
        Act->act = act;
    }
    m_actions.push_back(Act);
}

void Location::parseValue(QString &str, int &value, ValueType &type)
{
    if (str.startsWith(indStart[minValue]))
    {
        type = ValueType::min;
        value = str.sliced(indStart[minValue].size(), str.indexOf(indEnd[minValue]) - indStart[minValue].size()).toInt();
        str = str.sliced(str.indexOf(indEnd[minValue]) + indEnd[minValue].size());
    }
    else if (str.startsWith(indStart[maxValue]))
    {
        type = ValueType::max;
        value = str.sliced(indStart[maxValue].size(), str.indexOf(indEnd[maxValue]) - indStart[maxValue].size()).toInt();
        str = str.sliced(str.indexOf(indEnd[maxValue]) + indEnd[maxValue].size());
    }
    else if (str.startsWith(indStart[accValue]))
    {
        type = ValueType::accurate;
        value = str.sliced(indStart[accValue].size(), str.indexOf(indEnd[accValue]) - indStart[accValue].size()).toInt();
        str = str.sliced(str.indexOf(indEnd[accValue]) + indEnd[accValue].size());
    }
    else if (str.startsWith(indStart[notValue]))
    {
        type = ValueType::notequal;
        value = str.sliced(indStart[notValue].size(), str.indexOf(indEnd[notValue]) - indStart[notValue].size()).toInt();
        str = str.sliced(str.indexOf(indEnd[notValue]) + indEnd[notValue].size());
    }
    
}
