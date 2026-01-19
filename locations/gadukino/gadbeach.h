#ifndef GADBEACH_H
#define GADBEACH_H

#include "../location.h"

class LocationHandler;

class Gadbeach: public Location
{
public:
    Gadbeach(LocationHandler* ptr);
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

#endif // GADBEACH_H
