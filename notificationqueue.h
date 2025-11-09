#ifndef NOTIFICATIONQUEUE_H
#define NOTIFICATIONQUEUE_H

#include <QObject>
#include <QString>
#include <queue>

class NotificationQueue: public QObject
{
    Q_OBJECT
signals:
    void sigQueNotEmpty();
public:
    NotificationQueue(QWidget* parent);
    void push(QString text);
private slots:
    void runQue();
    void whenStop();
private:
    QWidget* m_widget;
    std::mutex m_mtxPush;
    std::mutex m_mtxRun;
    bool isRun;
    std::queue<QString> que;
};

#endif // NOTIFICATIONQUEUE_H
