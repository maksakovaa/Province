#ifndef QUEST_H
#define QUEST_H

#include <QString>
#include <QObject>

class QuestHandler;

class Quest: public QObject
{
    Q_OBJECT
public:
    Quest(QuestHandler* ptr): root(ptr){};
    ~Quest(){};
    virtual void start() = 0;
    QuestHandler* root;
public slots:
    virtual void slotActHandler(QString act) = 0;
};

#endif
