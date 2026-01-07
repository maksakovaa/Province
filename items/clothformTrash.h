#ifndef CLOTHFORMTRASH_H
#define CLOTHFORMTRASH_H

#include <QWidget>
#include "cloth.h"

namespace Ui {
class ClothFormTrash;
}

class ClothFormTrash : public QWidget
{
    Q_OBJECT

public:
    explicit ClothFormTrash(ClothMain* cloth, QWidget *parent = nullptr);
    ~ClothFormTrash();
signals:
    void sigCloth(Cloth* cloth, QString action);
private slots:
    void WardrbBtnClick();
    void RemoveBtnClick();
private:
    Cloth* ptr;
    void setStyleBtns();
    Ui::ClothFormTrash *ui;
};

#endif // CLOTHFORMTRASH_H
