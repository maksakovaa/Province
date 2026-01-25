#ifndef DRUGS_H
#define DRUGS_H

#include <QWidget>

class Game;

class Drugs
{
public:
    Drugs(Game* ptr);
    void setStatus(int type);
    void setValues();
    void hourRecalc();
    bool drugBlock();
private:
    Game* root;
};

#endif // DRUGS_H
