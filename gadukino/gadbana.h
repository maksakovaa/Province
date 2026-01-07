#ifndef GADBANA_H
#define GADBANA_H

#include "../nav/location.h"

class LocationHandler;

class Gadbana: public Location
{
    Q_OBJECT
public:
    Gadbana(LocationHandler* ptr);
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
    void cleanMe();
    void undress();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    bool isCanPar();
};

#endif // GADBANA_H
