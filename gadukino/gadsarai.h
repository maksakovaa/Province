#ifndef GADSARAI_H
#define GADSRAI_H

#include "../nav/location.h"

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
private slots:
    void actionHandler(QString action) override;
private:
    void makeActBtn(QString act, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    int know_no_pirat{0};
};

#endif
