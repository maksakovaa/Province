#ifndef KORRPAR_H
#define KORRPAR_H

#include "../location.h"

class korrPar: public Location
{
    Q_OBJECT
public:
    korrPar(LocationHandler* ptr);
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
};

#endif
