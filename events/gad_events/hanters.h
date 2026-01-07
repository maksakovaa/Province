#ifndef HANTERS_H
#define HANTERS_H

#include "../event.h"
class EventHandler;

class Hanters: public Event
{
public:
    Hanters(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    void groupfaint();
    void groupORALend1();
    void groupORALs();
    void groupORALs1();
    void groupORALs1end();
    void groupORALa1end();
    void groupORALi();
    void groupORALi1();
    void groupORALi1end();
    void groupORALai();
    void groupORALai1();
    void groupORALas();
    void groupORALsi();
    void groupORALsi1();
    void groupORALasi();
    void hanters_talk();
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void resetCounters();
    void setAndrei();
    void setSergei();
    void setIgor();
    void setMitka();
    void setKolyamba();
    void setVasyan();
private:
    EventHandler* root;
    int hantsexa;
    int hantsexb;

    int boyAsex;
    int boyAsexA;
    int boyBsex;
    int boyBsexA;
    int boyCsex;
    int boyCsexA;
};

#endif // HANTERS_H
