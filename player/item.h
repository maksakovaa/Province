#ifndef ITEM_H
#define ITEM_H

#include "enums.h"
#include <QString>

class Item
{
public:
    Item(Items id);
    QString getName();
    QString getDesc();
    QString getImage();
    int getQuantity();
    int getMaxQuantity();
    void use(int count = 1);
    void setQuantity(int value);
private:
    QString str(Items id);
    QString strDesc(Items id);
    itemType m_type;
    Items m_id;
    int m_quantity;
    int m_quantity_max;
};

#endif // ITEM_H
