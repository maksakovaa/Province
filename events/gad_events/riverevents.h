#ifndef RIVEREVENTS_H
#define RIVEREVENTS_H
#include "../event.h"
#include <QObject>

class EventHandler;
class RiverEvents: public Event
{
    Q_OBJECT
public:
    RiverEvents(EventHandler* ptr);
    void start(QString arg = "") override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    void mira_in_river();
    void mira_punish();
    void swim_guys();
    void sunbathe_guys();
    void guys_river();
    void guys_beach();
    void horse_river();
    void fishers();
    void fishing();
    void fishing_end();
    QString str(int id);
    QString act(int id);
    QString media(int id);
private:
    EventHandler* root;
    int i,g,f;
};

#endif // RIVEREVENTS_H
