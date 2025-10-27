#ifndef CLOTH_H
#define CLOTH_H

#include <QString>
#include <QPixmap>

enum ClothType {
    Main,                   // главная одежда
    Panties,                // трусики
    Stockings               // чулки
};

enum ClothGroup
{
    nude,                   //  0
    towel,                  //  1
    swimsuit,               //  2
    sundress,               //  3
    schoolUniform,          //  4
    waitressUniform,        //  5
    sportsSuit,             //  10 - 29
    jeans,                  //  30 - 49
    skirt,                  //  50 - 69
    casualDress,            //  70 - 89
    eveningDress,           //  90 - 110
    officeSuit,             //  110 - 129
    revealingOutfit,        //  130 - 149
    blouseWithShorts,       //  150 - 169
    sexualUnderwear         //  170 - 189
};

class Cloth
{
public:
    Cloth(ClothType type, QString name, int price, int condition = 100);
    ClothType getClothType();
    QString getName();
    void decreaseCondition(int value = 1);
    int getCondition();
private:
    ClothType m_type;
    QString m_name;
protected:
    int m_price;
    int m_condition;
};

class ClothMain: public Cloth
{
public:
    ClothMain(int id, ClothType type, ClothGroup group, QString name, int price = 0, int condition = 100);
    QString getClothImage();
    ClothType getType();
    ClothGroup getClothGroup();
    int getId();
    int getClothBonus();
    void setSize(int size);
private:
    int m_id;
    ClothGroup m_group;
protected:
    int m_size;
    int m_bonus;
};

class ClothPanties: public Cloth
{
public:
    ClothPanties(ClothType type, int price = 0, int condition = 500);
    QString getImage();
private:
    QString m_image;
};

#endif // CLOTH_H
