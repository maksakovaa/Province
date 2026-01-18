#ifndef SHOP_H
#define SHOP_H

#include <QObject>
#include <QVBoxLayout>
#include "enums.h"
#include "../items/cloth.h"
#include "../nav/location.h"

class LocationHandler;

class Shop: public Location
{
    Q_OBJECT
    friend LocationHandler;
public:
    Shop(LocationHandler* parent);
    void show(QString arg = "") override;
    LocId getLocId() override;
    LocId getParId() override;
    LocId getLocIn() override;
    QString getLocName() override;
    bool isParent() override;
    void makeActBtn(QString act, QString actName);
private slots:
    void actionHandler(const QString link) override;
    void slotBuyItem(Items id);
    void slotBuyCloth(int id, ClothGroup group);
private:
    QString getStr(int id);
    void shop_food();
    void shop_cosmetics();
    void shop_common();
    void shop_clothing();
    void shop_tech();
    void shop_sport();
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
    QVBoxLayout* layoutMain;
    std::vector<QHBoxLayout*> m_layouts;
    std::unordered_map<ClothGroup, std::vector<int>> m_cloth;
};

#endif
