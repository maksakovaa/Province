#ifndef BROTHEREVENTS_H
#define BROTHEREVENTS_H

#include "../event.h"

class Game;

class BrotherEvents: public Event
{
public:
    BrotherEvents(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void watch_tv();
    void go_away();
    void brother_help_qw();
    void brother_help_qw2();
    void happy_ny(int i = 0);
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
};

#endif // BROTHEREVENTS_H
