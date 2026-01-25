#ifndef SITRPAR_H
#define SITRPAR_H

#include "../location.h"
#include "../loc_enums.h"

class SitrPar: public Location
{
public:
    SitrPar(Game* ptr);
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
private:
    Game* root;
};

#endif // SITRPAR_H
