#ifndef GADFIELD_H
#define GADFIELD_H

#include "../location.h"

class Game;

class Gadfield: public Location
{
public:
    Gadfield(Game* ptr);
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

    void gadfield_mira();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    QString metka;
private:
    Game* root;
};

#endif // GADFIELD_H
