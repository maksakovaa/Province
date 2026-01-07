#include "popup.h"
#include <QLabel>
#include <QPropertyAnimation>
#include <QTimer>

PopUp::PopUp(QString text, QWidget *parent): QFrame(parent)
{
    QLabel* lbl = new QLabel(this);
    lbl->setText(text + "    ");
    lbl->setFixedSize(500,50);
    lbl->setStyleSheet("background-color: gray; color:white;");
    lbl->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QPropertyAnimation* anim = new QPropertyAnimation(lbl, "pos", this);
    anim->setDuration(500);
    anim->setStartValue(QPoint(-500, 0));
    anim->setEndValue(QPoint(0, 0));
    timer = new QTimer(this);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
    connect(anim, &QPropertyAnimation::finished, this, &PopUp::killNotification);
    this->setFixedSize(500,50);
    this->setStyleSheet("background-color: transparent; border-top-right-radius: 20px; border-bottom-right-radius: 20px; border: none");
}

void PopUp::killNotification()
{
    connect(timer, &QTimer::timeout, this, &PopUp::deleteLater);
    timer->start(1000);
}
