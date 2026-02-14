#ifndef MOTHERQW_H
#define MOTHERQW_H

#include "../event.h"
class Game;

class MotherQW: public Event
{
public:
    MotherQW(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString str(int id);
    QString act(int id);
private:
    Game* root;
};

#endif // MOTHERQW_H
