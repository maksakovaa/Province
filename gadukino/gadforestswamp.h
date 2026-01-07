#ifndef GADFORESTSWAMP_H
#define GADFORESTSWAMP_H


#include "../nav/location.h"

class LocationHandler;

class GadForestSwamp: public Location
{
public:
    GadForestSwamp(LocationHandler* ptr);
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
    void swampClothes();
};

#endif // GADFORESTSWAMP_H
