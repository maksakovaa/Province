#ifndef LOCATION_H
#define LOCATION_H
#include <QString>
#include <QObject>
#include <any>
#include <vector>
#include <QPixmap>
#include "gameobj.h"

struct Action
{
    QString act;
    QString param;
    int minValue;
};

enum params { image, object, desc, subloc, action, required, param, minvalue };

class Location: public QObject
{
    Q_OBJECT
public:
    Location(QString locIn, QString locName, Location* parent = nullptr, BagForm* bagPtr = nullptr);
    const std::vector<struct Action*> availableActions();
    const std::vector<Location*> awailableLocs();
    const std::vector<QString> availableObjs();
    bool isParent();
    QString getLocPic(bool isDay, bool isSnow);
    QString getLocId();
    QString getLocIn();
    QString getLocDesc();
    Location* getParentPtr();
private:
    std::vector<Location*> m_subLocs;
    Location* m_parent;
    std::vector<QString> m_obj;
    std::vector<struct Action*> m_actions;
    QString m_image;
    bool m_isweather;
    QString m_locId;
    QString m_locName;
    QString m_locIn;
    QString m_desc;
    BagForm* m_bag;
    QString* startInd;
    QString* endInd;
    void parseLocConfig(QString str, QString folder);
    void parseRequiredImage(QString str, QString folder);
    void genLocation();
};

#endif // LOCATION_H
