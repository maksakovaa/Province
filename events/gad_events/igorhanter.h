#ifndef IGORHANTER_H
#define IGORHANTER_H

#include "../event.h"
class EventHandler;

class IgorHanter: public Event
{
public:
    IgorHanter(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int boypic;
    int dick;
    int silaVag;
    int finance;
    int vneshBoy;
    int figurBoy;
    int titBoy;
    int haerBoy;
    int harakBoy;
    int izvrat;
    int boyage;
};

#endif // IGORHANTER_H
