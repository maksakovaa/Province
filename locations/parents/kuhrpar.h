#ifndef KUHRPAR_H
#define KUHRPAR_H

#include "../location.h"
#include "../loc_enums.h"

class KuhrPar: public Location
{
public:
    KuhrPar(Game* ptr);
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
    Game* root;
};

#endif // KUHRPAR_H
