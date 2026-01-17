#ifndef SWAMPYARD_H
#define SWAMPYARD_H

#include "../nav/location.h"

class LocationHandler;

class SwampYard: public Location
{
public:
    SwampYard(LocationHandler* ptr);
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
private:
    int tmp;
    QString boy;
};

#endif // SWAMPYARD_H
