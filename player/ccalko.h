#ifndef CCALKO_H
#define CCALKO_H

#include <QObject>

class Game;

class CC_Alko: public QObject
{
    Q_OBJECT
public:
    CC_Alko(Game* ptr);
    void anti_hangover();
    void alkoAbstain();
    void fnAlko(int val);
    int alkoBlock();
signals:
    void sigIncreaseRiscs(int value);
public slots:
    void slotDataInitAlko();
    void slotHangOver();
    void slotAlkoholism();
private:
    Game* root;
};

#endif
