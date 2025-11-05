#ifndef SHOP_H
#define SHOP_H

#include "locationform.h"
#include "../player/itemform.h"

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
private:
    void initClothArray();
    std::vector<Cloth*> initClothArray(ClothGroup group);
    ItemForm* makeForm();
    int foodPrice(Food type);
    QString foodName(Food type);
    int cosmeticsPrice(Cosmetics type);
    QString cosmeticsName(Cosmetics type);
    int commonPrice(Common type);
    QString commonName(Common type);
    int clothPrice(ClothGroup type);
    QString clothName(ClothGroup type);
    int techPrice(Tech type);
    QString techName(Tech type);
    int sportPrice(Sport type);
    QString sportName(Sport type);
    LocationForm* root;
    std::unordered_map<ClothGroup, std::vector<QString>> m_cloth;
};

#endif
