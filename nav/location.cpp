#include "location.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include "../Functions.h"

Location::Location(QString locIn, QString locName, Location* parent, BagForm* bagPtr): m_locIn(locIn), m_locId(locName), m_parent(parent), m_bag(bagPtr) 
{
    startInd = new QString[]{ "<name>", "<actName>", "<image>", "<obj>", "<desc>", "<subloc>", "<action>", "<required>", "<param>", "<minv>" };
    endInd = new QString[]{ "</name>", "</actName>" , "</image>", "</obj>", "</desc>", "</subloc>", "</action>", "</required>", "</param>", "</minv>" };
    m_isweather = false;
    genLocation();
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

void Location::genLocation()
{
    QString folder_path;
    if (m_parent == nullptr)
    {
        folder_path = ":/locations/" + m_locIn + "/" + m_locId + "/";
    }
    else
    {
        folder_path = ":/locations/" + m_parent->m_locIn + "/" + m_parent->m_locId + "/";
    }
    QFile file(folder_path + m_locId + ".loc");
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

QString Location::getLocPic(bool isDay, bool isSnow)
{
    QString txt;
    if (m_isweather == true)
    {
        txt = "<img src='" + makeImage(m_image, isDay, isSnow) + "'></img>";   
    }
    else
    {
        txt = "<img src='" + m_image + "'></img>";
    }
    return txt;
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
    return m_locIn;
}

QString Location::getLocDesc()
{
    return m_desc;
}

Location *Location::getParentPtr()
{
    return m_parent;
}

void Location::parseLocConfig(QString str, QString folder)
{
    QString res;
    if(str.startsWith(startInd[name]))
    {
        m_locName = str.sliced(startInd[name].size(), str.indexOf(endInd[name]) - startInd[name].size());
    }
    if (str.startsWith(startInd[actName]))
    {
        m_locName = str.sliced(startInd[actName].size(), str.indexOf(endInd[actName]) - startInd[actName].size());
    }
    if(str.startsWith(startInd[image]))
    {
        res = str.sliced(startInd[image].size(), str.indexOf(endInd[image]) - startInd[image].size());
        std::cout << res.toStdString() << std::endl;
        if (res.startsWith(startInd[param]))
        {
            std::cout << res.toStdString() << std::endl;
            parseRequiredImage(res, folder);
        }
        else
        {
            m_image = folder + res;
        }
    }
    if(str.startsWith(startInd[object]))
    {
        res = str.sliced(startInd[object].size(), str.indexOf(endInd[object]) - startInd[object].size());
        m_obj.push_back(res);
    }
    if(str.startsWith(startInd[desc]))
    {
        res = str.sliced(startInd[desc].size(), str.indexOf(endInd[desc]) - startInd[desc].size());
        m_desc = res;
    }
    if(str.startsWith(startInd[subloc]))
    {
        res = str.sliced(startInd[subloc].size(), str.indexOf(endInd[subloc]) - startInd[subloc].size());
        Location* subLoc = new Location(m_locIn, res, this, m_bag);
        m_subLocs.push_back(subLoc);
    }
    if(str.startsWith(startInd[action]))
    {
        res = str.sliced(startInd[action].size(), str.indexOf(endInd[action]) - startInd[action].size());
        if(res.startsWith(startInd[required]))
        {
            size_t reqOn = res.indexOf(startInd[required]) + startInd[required].size();
            size_t reqOff = res.indexOf(endInd[required]) - startInd[required].size();
            QString req = res.sliced(reqOn, reqOff);
 
            size_t parStart = req.indexOf(startInd[param]) + startInd[param].size();
            size_t parEnd = req.indexOf(endInd[param]) - startInd[param].size();
            QString par = req.sliced(parStart, parEnd);

            size_t valStart = req.indexOf(startInd[minvalue]) + startInd[minvalue].size();
            size_t valEnd = req.indexOf(endInd[minvalue]) - valStart;
            QString val = req.sliced(valStart,valEnd);

            QString action = res.sliced(res.indexOf(endInd[required]) + endInd[required].size());
            m_actions.push_back(new Action{action, par, val.toInt()});
        }
    }
}

void Location::parseRequiredImage(QString str, QString folder)
{
    QString req = str.sliced(str.indexOf(startInd[param]) + startInd[param].size(), str.indexOf(endInd[param]) - startInd[param].size());
    if (req == "night_snow")
    {
        m_image = folder + str.sliced(str.indexOf(endInd[param]) + endInd[param].size());
        std::cout << m_image.toStdString() << std::endl;
        m_isweather = true;
    }
}
