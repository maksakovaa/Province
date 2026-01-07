#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <QObject>
class GameObj: public QObject
{
    Q_OBJECT
public:
    GameObj(){};
    virtual ~GameObj(){};
    virtual QString getName() = 0;
    virtual QString getImage() = 0;
    virtual QString getDesc() = 0;
};


#endif