#ifndef MEADOW_H
#define MEADOW_H

#include "../nav/location.h"

class LocationHandler;

class Meadow: public Location
{
public:
    Meadow(LocationHandler* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
};

#endif // MEADOW_H
