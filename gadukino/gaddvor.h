#ifndef GADDVOR_H
#define GADDVOR_H

#include <QObject>
#include "../nav/location.h"

class Gaddvor: public Location
{
    Q_OBJECT
public:
    Gaddvor(LocationHandler* ptr);
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
    QString getStr(int id);
    QString media(int id);
private:
    int mira_temp{0};
};

#endif // GADDVOR_H
