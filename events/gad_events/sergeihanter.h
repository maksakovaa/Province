#ifndef SERGEIHANTER_H
#define SERGEIHANTER

#include "../event.h"
class EventHandler;

class SergeiHanter: public Event
{
public:
    SergeiHanter(EventHandler* ptr);
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
    QString boy;
    int dicksize;
    int sexskill;
    int harakBoy;
    int boyAge;
};

#endif // SergeiHanter_H
