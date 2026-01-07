#ifndef CLOTHFORM_H
#define CLOTHFORM_H

#include <QWidget>
#include "cloth.h"

namespace Ui {
class ClothForm;
}

class ClothForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClothForm(ClothMain* cloth, int hips, QWidget *parent = nullptr);
    ~ClothForm();
signals:
    void sigCloth(Cloth* cloth, QString action);
private slots:
    void WearBtnClick();
    void FitBtnClick();
    void TrashBtnClick();
    void RemoveBtnClick();
private:
    Cloth* ptr;
    void setStyleWearBtn(int size, int hips, int condition, int group);
    void setStyleFitBtn(int size, int hips, int condition, int group);
    void setStyleTrahRemoveBtn(int group);
    Ui::ClothForm *ui;
};

#endif // CLOTHFORM_H
