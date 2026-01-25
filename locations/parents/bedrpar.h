#ifndef BEDRPAR_H
#define BEDRPAR_H

#include "../location.h"
#include "../loc_enums.h"

class BedrPar: public Location
{
public:
    BedrPar(Game* ptr);
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
    QString img(int id);
    Game* root;
};

#endif // BEDRPAR_H
