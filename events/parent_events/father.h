#ifndef FATHER_H
#define FATHER_H

#include "../event.h"
class Game;

class Father: public Event
{
public:
    Father(Game* ptr);
    void start(QString arg = 0) override;
    void makeActBtn(QString action, QString actName);
private slots:
    void actionHandler(QString action);
private:
    QString media(int id);
    QString str(int id);
    QString act(int id);
private:
    Game* root;
    std::unordered_map<int, int> m_cloth_remember;
    int i;
};

#endif // FATHER_H
