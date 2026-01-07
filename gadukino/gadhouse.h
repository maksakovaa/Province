#ifndef GADHOUSE_H
#define GADHOUSE_H

#include "../nav/location.h"

class LocationHandler;

class Gadhouse: public Location
{
    Q_OBJECT
public:
    Gadhouse(LocationHandler* ptr);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
private slots:
    void actionHandler(QString action) override;
private:
    QString str(int id);
    QString media(int id);
    void makeActBtn(QString action, QString actName);
private:

};

#endif // GADHOUSE_H
