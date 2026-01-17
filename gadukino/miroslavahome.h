#ifndef MIROSLAVAHOME_H
#define MIROSLAVAHOME_H

#include "../nav/location.h"

class LocationHandler;

class MiroslavaHome: public Location
{
public:
    MiroslavaHome(LocationHandler* ptr);
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
    int mira_temp;
    int grandpa_guest;
};

#endif // MIROSLAVAHOME_H
