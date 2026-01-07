#ifndef POPUP_H
#define POPUP_H
#include <QFrame>

class PopUp: public QFrame
{
public:
    PopUp(QString text, QWidget* parent = nullptr);
private slots:
    void killNotification();
private:
    QTimer* timer;
};

#endif // POPUP_H
