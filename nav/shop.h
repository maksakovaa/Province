#ifndef SHOP_H
#define SHOP_H

#include "locationform.h"

class Shop: public QObject
{
    friend LocationForm;
public:
    Shop(QWidget* parent);
    void shop_food();
    void shop_cosmetics();
    void shop_common();
    void shop_clothing();
    void shop_tech();
    void shop_sport();
private slots:
    void slotShopHandler(const QString& link);
    void slotBuyItem(Items id);
    void slotBuyCloth(int id, ClothGroup group);
private:
    void makeShop();
    void initClothArray();
    std::vector<int> initClothArray(ClothGroup group);
    int itemPrice(int itemId);
    QString itemName(int itemId);
    int clothPrice(ClothGroup type);
    QString clothName(ClothGroup type);
    void createHLayoyt();
    void makeItemForm(Items id, itemType type);
    void makeClothForm(int clothId, ClothGroup group);
    QString current;
    LocationForm* root;
    QVBoxLayout* layoutMain;
    QWidget* widgetMain;
    std::vector<QHBoxLayout*> m_layouts;
    std::unordered_map<ClothGroup, std::vector<int>> m_cloth;
};

#endif
