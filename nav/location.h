#ifndef LOCATION_H
#define LOCATION_H
#include <QString>
#include <QObject>
#include <vector>
#include <QPixmap>
#include "bagform.h"

enum ValueType { min, max, accurate, notequal };
struct Action
{
    QString act;
    int actId;
    QString param;
    int paramValue;
    ValueType paramVType;
    QString item;
    int itmValue;
    ValueType itemVType;
};

enum params { name, actName, image, object, desc, subloc, action, required, param, minValue, maxValue, accValue, notValue, reqitem };

class Location: public QObject
{
    Q_OBJECT
public:
    Location(QString globalLoc);
    Location(Location* parent, QString subloc, QString folder);

//    Location(QString locIn, QString locName, Location* parent = nullptr, BagForm* bagPtr = nullptr);
    const std::vector<struct Action*> availableActions();
    const std::vector<Location*> awailableLocs();
    const std::vector<QString> availableObjs();
    bool isParent();
    QString getLocPic(bool isDay, bool isSnow);
    QString getLocId();
    QString getLocName();
    QString getActName();
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
    QString m_actName;
    QString m_locIn;
    QString m_desc;
    BagForm* m_bag;
    QString* indStart;
    QString* indEnd;
    void parseLocConfig(QString str, QString folder);
    void parseRequiredImage(QString str, QString folder);
    void parseActConfig(QString str);
    void parseValue(QString& str, int& value, ValueType& type);
    void initIndexQStrArr();
    // void genLocation();
};

#endif // LOCATION_H
