#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Cosmetic;
class CosmeticBig;
class Condoms;
class WetWipes;
class VagGel;
class MorningCare;
class Tampon;
class AntiPregPills;
class Razor;
class LipBalm;
class Lubricant;
class Shampoo;

class Dildo;
class MidDildo;
class LargeDildo;
class BigDildo;
class ExtraDildo;
class SuperDildo;
class MadDildo;
class AnalPlug;
class Vibrator;
class Strapon;

class Item
{
    friend Cosmetic;
    friend CosmeticBig;
    friend Condoms;
    friend WetWipes;
    friend VagGel;
    friend MorningCare;
    friend Tampon;
    friend AntiPregPills;
    friend Razor;
    friend LipBalm;
    friend Lubricant;
    friend Shampoo;
    friend Dildo;
    friend MidDildo;
    friend LargeDildo;
    friend BigDildo;
    friend ExtraDildo;
    friend SuperDildo;
    friend MadDildo;
    friend AnalPlug;
    friend Vibrator;
    friend Strapon;
public:
    Item() {};
    virtual ~Item(){};
    QString getName();;
    QString getDesc();;
    QString getImage();;
private:
    QString m_name;
    QString m_image;
    QString m_desc;
};

class CosmeticBig;

class Cosmetic: public Item
{
    friend CosmeticBig;
public:
    Cosmetic();
    int getQuantity();
    int getMaxQuantity();
    void useCosmetic(int value);
    void setQuantity(int value);
private:
    int m_quantity;
    int m_maxQuantity;
};

class CosmeticBig: public Cosmetic
{
public:
    CosmeticBig();
};

class Condoms: public Item
{
public:
    Condoms();
};

class WetWipes: public Item
{
public:
    WetWipes();
};

class VagGel: public Item
{
public:
    VagGel();
};

class MorningCare: public Item
{
public:
    MorningCare();
};

class Tampon: public Item
{
public:
    Tampon();
};

class AntiPregPills: public Item
{
public:
    AntiPregPills();
};

class Razor: public Item
{
public:
    Razor();
};

class LipBalm: public Item
{
public:
    LipBalm();
};

class Lubricant:public Item
{
public:
    Lubricant();
};

class Shampoo: public Item
{
public:
    Shampoo();
};

/////////////////   SEX TOYS \\\\\\\\\\\\\\\\\\\

class Dildo: public Item
{
public:
    Dildo();
};
class MidDildo: public Item
{
public:
    MidDildo();
};
class LargeDildo: public Item
{
public:
    LargeDildo();
};
class BigDildo: public Item
{
public:
    BigDildo();
};
class ExtraDildo: public Item
{
public:
    ExtraDildo();
};
class SuperDildo: public Item
{
public:
    SuperDildo();
};
class MadDildo: public Item
{
public:
    MadDildo();
};
class AnalPlug: public Item
{
public:
    AnalPlug();
};
class Vibrator: public Item
{
public:
    Vibrator();
};

class Strapon: public Item
{
public:
    Strapon();
};

#endif // ITEM_H
