#ifndef LOCATION_H
#define LOCATION_H

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

class Location: public QObject
{
    Q_OBJECT
public:
    Location(const QString& locIn, const QString& locName, Location* parent = nullptr, Player* ptr = nullptr, BagForm* bagPtr = nullptr);
    const std::vector<struct Action*> availableActions();
    const std::vector<Location*> awailableLocs();
    const std::vector<QString> availableObjs();
    bool isParent();
    QPixmap& getLocPic();
    QString& getLocId();
    QString& getLocIn();
    QString& getLocDesc();
    Location* getParentPtr();
private:
    void parseLocConfig(QString str, QString folder);
    void genLocation();
    std::vector<Location*> m_subLocs;
    Location* m_parent;
    std::vector<QString> m_obj;
    std::vector<struct Action*> m_actions;
    QPixmap m_image;
    QString m_locId;
    QString m_locName;
    QString m_locIn;
    QString m_desc;
    Player* m_player;
    BagForm* m_bag;
};

#endif // LOCATION_H
