#include "notificationqueue.h"
#include "popup.h"
// #include <iostream>

NotificationQueue::NotificationQueue(QWidget* parent)
{
    connect(this, &NotificationQueue::sigQueNotEmpty, this, &NotificationQueue::runQue);
    isRun = false;
    m_widget = parent;
}

void NotificationQueue::push(QString text)
{
    std::lock_guard<std::mutex> lock(m_mtxPush);
    que.push(text);
    // std::cout << "Notification pushed! " << que.size() << std::endl;
    if(isRun != true)
        emit sigQueNotEmpty();
}

void NotificationQueue::runQue()
{
    if (!que.empty() && isRun == false)
    {
        m_mtxRun.lock();
        // std::cout << "Notification running!" << std::endl;
        isRun = true;
        PopUp* ptr = new PopUp(que.front(), m_widget);
        que.pop();
        connect(ptr, &PopUp::destroyed, this, &NotificationQueue::whenStop);
        ptr->show();
    }
}

void NotificationQueue::whenStop()
{
    m_mtxRun.unlock();
    // std::cout << "notification deleted!" << std::endl;
    isRun = false;
    runQue();
}
