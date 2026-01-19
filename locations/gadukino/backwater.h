#ifndef BACKWATER_H
#define BACKWATER_H

#include "../location.h"
#include "../loc_enums.h"

class LocationHandler;
class SwampEvents;

class Backwater: public Location
{
    friend SwampEvents;
public:
    Backwater(LocationHandler* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString act, QString actName);
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString act(int id);
    QString img(int id);
    bool checkBodyCum();
};

#endif // BACKWATER_H
