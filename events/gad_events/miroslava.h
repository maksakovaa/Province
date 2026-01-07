#ifndef MIROSLAVA_H
#define MIROSLAVA_H

#include "../event.h"
class EventHandler;

class Miroslava: public Event
{
public:
    Miroslava(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    void miraclothes();
    void mira_river();
    void miratalk();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int age;
};

#endif // MIROSLAVA_H
