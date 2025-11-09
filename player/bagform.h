#ifndef BAGFORM_H
#define BAGFORM_H

#include <QWidget>
#include "item.h"
#include "itemform.h"
#include <unordered_map>
#include "enums.h"

namespace Ui {
class BagForm;
}

class BagForm : public QWidget
{
    Q_OBJECT

public:
    explicit BagForm(QWidget *parent = nullptr);
    ~BagForm();
    void putInBag(Items name, int count = 1);
    int getQuantityof(Items name);
    void useItem(Items name, int count = 1);
    void fillItemList();
    QString getItemName(Items id);
private:
    void updQuantity(Items type, int count);
    void initNewLayout();
    Ui::BagForm *ui;
    std::vector<QString> imgs;
    std::vector<QString> names;
    std::vector<QString> descs;
    std::vector<int> counters;
    std::vector<QHBoxLayout*> m_layouts;
    std::unordered_map<Items, Item*> m_items;
    std::unordered_map<Item*, int> m_storage;
    void initBag();
    ItemForm* makeItemWidget(QString image, QString name, QString desc);
    void grabItemsDesc(Item* item);
};

#endif // BAGFORM_H
