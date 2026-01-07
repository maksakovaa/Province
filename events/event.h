#ifndef EVENT_H
#define EVENT_H

#include <QString>
#include <QObject>

class Event: public QObject
{
public:
    Event(){};
    virtual void start(QString arg = "")=0;
};

#endif
