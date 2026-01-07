#ifndef BACKWATER_H
#define BACKWATER_H

#include "../nav/location.h"
#include "../nav/loc_enums.h"

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
private slots:
    void actionHandler(QString action) override;
private:
    void makeActBtn(QString act, QString actName);
    QString str(int id);
    QString act(int id);
    QString img(int id);
    bool checkBodyCum();
};

#endif // BACKWATER_H
