#ifndef SWAMPHOUSE_H
#define SWAMPHOUSE_H

#include "../nav/location.h"

class LocationHandler;

class SwampHouse: public Location
{
public:
    SwampHouse(LocationHandler* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
private slots:
    void actionHandler(QString action) override;
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void dirtySwampHouse();
    void clothes_read_magazines();
};

#endif // SWAMPHOUSE_H
