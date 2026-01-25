#ifndef SWAMPEVENTS_H
#define SWAMPEVENTS_H

#include "../event.h"
#include <QObject>

class Game;

class SwampEvents: public Event
{
public:
    SwampEvents(Game* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    Game* root;

};

#endif // SWAMPEVENTS_H
