#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "../player/player.h"
#include <QString>
#include "../player/bagform.h"

enum GameObjects {
    mirror,
    bed,
    wardrobe
};

class GameObj
{
public:
    GameObj(){};
    virtual ~GameObj(){};
    virtual QString getName(){ return "";};
    virtual QString getImage(){ return "";};
    virtual QString getDesc(){ return "";};
};

class Mirror: public GameObj
{
public:
    Mirror(Player* ptr, BagForm* bagPtr);
    ~Mirror();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
private:
    Player* m_player;
    BagForm* m_bag;
    QString m_name;
    QString m_desc;
};

class Bed: public GameObj
{
public:
    Bed(Player* ptr);
    ~Bed();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
    QString getDreamsDesc(int i);
    QString getDreamsAfter(int i);
private:
    Player* m_player;
    QString m_name;
    QString m_desc;
};

class WardrobeObj: public GameObj
{
public:
    WardrobeObj(Player* ptr);
    ~WardrobeObj();
    QString getName() override;
    QString getImage() override;
    QString getDesc() override;
private:
    Player* m_player;
    QString m_name;
    QString m_desc;
};

#endif // GAMEOBJ_H
