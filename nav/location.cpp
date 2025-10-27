#include "location.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>

Location::Location(const QString& locIn, const QString& locName, Location* parent, Player* ptr, BagForm* bagPtr): m_locIn(locIn), m_locId(locName), m_parent(parent), m_player(ptr), m_bag(bagPtr) {
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
        qDebug() << "Error opening file! ";
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

QPixmap& Location::getLocPic()
{
    return m_image;
}

QString &Location::getLocId()
{
    return m_locId;
}

QString &Location::getLocIn()
{
    return m_locIn;
}

QString &Location::getLocDesc()
{
    return m_desc;
}

Location *Location::getParentPtr()
{
    return m_parent;
}

void Location::parseLocConfig(QString str, QString folder)
{
    enum params { image, object, desc, subloc, action, required, param, minvalue };
    QString startInd[] = { "<image>", "<obj>", "<desc>", "<subloc>", "<action>", "<required>", "<param>", "<minv>" };
    QString endInd[] = { "</image>", "</obj>", "</desc>", "</subloc>", "</action>", "</required>", "</param>", "</minv>" };
    QString res;
    if(str.startsWith(startInd[image]))
    {
        res = str.sliced(startInd[image].size(), str.indexOf(endInd[image]) - startInd[image].size());
        m_image = QPixmap(folder + res);
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
        Location* subLoc = new Location(m_locIn, res, this, m_player);
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
