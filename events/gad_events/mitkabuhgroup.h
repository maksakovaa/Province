#ifndef MITKABUHGROUP_H
#define MITKABUHGROUP_H

#include "../event.h"
class EventHandler;

class MitkaBuhGroup: public Event
{
public:
    MitkaBuhGroup(EventHandler* ptr);
    void start(QString arg = "") override;
private slots:
    void actionHandler(QString action);
private:
    void makeActBtn(QString action, QString actName);
    QString str(int id);
    QString act(int id);
    QString media(int id);
    void setMitka();
    void setVasyan();
    void setKolyamba();
    void sexDepOnMesec();
private:
    EventHandler* root;
    int order{0};
    int mirapiss;
};

#endif // MITKABUHGROUP_H
