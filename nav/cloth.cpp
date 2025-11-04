#include "cloth.h"
#include "../Functions.h"

Cloth::Cloth(ClothType type, QString name, int price, int condition) : m_type(type), m_name(name), m_price(price), m_condition(condition) {}

ClothType Cloth::getClothType()
{
    return m_type;
}

QString Cloth::getName()
{
    return m_name;
}

void Cloth::decreaseCondition(int value)
{
    m_condition -= value;
}

int Cloth::getCondition()
{
    return m_condition;
}

ClothMain::ClothMain(int id, ClothType type, ClothGroup group, QString name, int price, int condition): Cloth(type, name, price, condition)
{
    m_id = id;
    m_group = group;

    if (m_group == ClothGroup::nude) { m_bonus = 0; }
    else if (m_group == ClothGroup::towel) { m_bonus = 10; }
    else if (m_group == ClothGroup::swimsuit) { m_bonus = 10; }
    else if (m_group == ClothGroup::sundress) { m_bonus = 15; }
    else if (m_group == ClothGroup::schoolUniform) { m_bonus = 15; }
    else if (m_group == ClothGroup::waitressUniform) { m_bonus = 15; }
    else if (m_group == ClothGroup::sportsSuit) { m_bonus = 5; }
    else if (m_group == ClothGroup::jeans) { m_bonus = 10; }
    else if (m_group == ClothGroup::skirt) { m_bonus = 15; }
    else if (m_group == ClothGroup::casualDress) { m_bonus = 20; }
    else if (m_group == ClothGroup::eveningDress) { m_bonus = 30; }
    else if (m_group == ClothGroup::officeSuit) { m_bonus = 15; }
    else if (m_group == ClothGroup::revealingOutfit) { m_bonus = 15; }
    else if (m_group == ClothGroup::blouseWithShorts) { m_bonus = 15; }
    m_size = -1;
    if(m_group < ClothGroup::sportsSuit)
        m_condition = -99;
}

QString ClothMain::getClothImage()
{
    return ":/img/clothing/" + intQStr(m_group) + "/" + intQStr(m_id) + ".jpg";
}

ClothType ClothMain::getType()
{
    return getClothType();
}

ClothGroup ClothMain::getClothGroup()
{
    return m_group;
}

int ClothMain::getId()
{
    return m_id;
}

int ClothMain::getClothBonus()
{
    int k;
    if(m_group >= ClothGroup::nude && m_group <= ClothGroup::waitressUniform)
    {
        k = 100;
    }
    else
    {
        k = m_condition;
    }
    return m_bonus * k / 100;
}
void ClothMain::setSize(int size)
{
    m_size = size;
}

ClothPanties::ClothPanties(ClothType type, int price, int condition): Cloth(type, "трусы", price, condition)
{
    m_image = ":/img/items/cowards.png";
}

QString ClothPanties::getImage()
{
    return m_image;
}
