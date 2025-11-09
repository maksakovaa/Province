#ifndef ITEMFORM_H
#define ITEMFORM_H

#include "cloth.h"
#include "enums.h"
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
    void setUnavailable(QString text);
    void setUseBtnText(QString text);
private slots:
    virtual void useHandler(const QString &link);
private:
    void clearLayout();
    QVBoxLayout* countLayout;
    Ui::ItemForm *ui;
};

class ItemFormCloth : public ItemForm
{
    Q_OBJECT
public:
    ItemFormCloth(int id, ClothGroup group, QString image, QString name, QString desc, QWidget *parent = nullptr);
signals:
    void sigBuyCloth(int id, ClothGroup group);
private slots:
    void useHandler(const QString &link) override;
private:
    int m_Id;
    ClothGroup m_group;
};

class ItemFormShop: public ItemForm
{
    Q_OBJECT
public:
    ItemFormShop(Items id, QString image, QString name, QString desc, QWidget *parent = nullptr);
signals:
    void sigBuyItem(Items id);
private slots:
    void useHandler(const QString& link) override;
private:
    Items m_id;
};

#endif // ITEMFORM_H
