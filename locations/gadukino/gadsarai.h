#ifndef GADSARAI_H
#define GADSRAI_H

#include "../location.h"

class LocationHandler;

class Gadsarai: public Location
{
    Q_OBJECT
public:
    Gadsarai(LocationHandler* ptr);
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
    QString media(int id);
};

#endif
