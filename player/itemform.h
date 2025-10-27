#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QFrame>
#include <QVBoxLayout>

namespace Ui {
class ItemForm;
}

class ItemForm : public QFrame
{
    Q_OBJECT
public:
    explicit ItemForm(QString image, QString name, QString desc, QWidget *parent = nullptr);
    ~ItemForm();
    void addCounter(int value);
private:
    void clearLayout();
    QVBoxLayout* countLayout;
    Ui::ItemForm *ui;
};

#endif // ITEMFORM_H
