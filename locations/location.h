#ifndef LOCATION_H
#define LOCATION_H

#include <QString>
#include <QPushButton>
#include <QLabel>
#include "loc_enums.h"

class Game;
class LocButton;
class LocationHandler;
class Location: public QObject
{
    Q_OBJECT
    friend LocationHandler;
public:
    Location() = default;
    virtual void show(QString arg = "") = 0;
    virtual LocId getLocId() = 0;
    virtual LocId getParId() = 0;
    virtual LocId getLocIn() = 0;
    virtual QString getLocName() = 0;
    virtual bool isParent() = 0;
private slots:
    virtual void actionHandler(QString action) = 0;
};

#endif // LOCATION_H
