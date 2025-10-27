#include "item.h"

QString Item::getName()
{
    return m_name;
}

QString Item::getDesc()
{
    return m_desc;
}

QString Item::getImage()
{
    return "<img src='" + m_image + "'></img>";
}

Cosmetic::Cosmetic()
{
    m_name = "Косметичка";
    m_image = ":/img/items/kosmet_small.png";
    m_desc = "Улучшает внешность";
    m_quantity = 15;
    m_maxQuantity = 15;
}

int Cosmetic::getQuantity()
{
    return m_quantity;
}

int Cosmetic::getMaxQuantity()
{
    return m_maxQuantity;
}

void Cosmetic::useCosmetic(int value)
{
    m_quantity -= value;
}

void Cosmetic::setQuantity(int value)
{
    m_quantity = value;
}

Condoms::Condoms()
{
    m_image = ":/img/items/condom.png";
    m_name = "Презервативы";
    m_desc = "Резиновое изделение № 1";
}

CosmeticBig::CosmeticBig()
{
    m_name = "Набор косметики";
    m_image = ":/img/items/kosmet_big.png";
    m_quantity = 30;
    m_maxQuantity = 30;
}

WetWipes::WetWipes()
{
    m_name = "Влажные салфетки";
    m_image = ":/img/items/wet_wipes.png";
    m_desc = "Подтереть последствия";
}

VagGel::VagGel()
{
    m_name = "Гель для вагины Touch";
    m_image = ":/img/items/vaggel.png";
    m_desc = "Лечит натертости в течении 8 часов";
}

MorningCare::MorningCare()
{
    m_name = "Напиток Morning Care";
    m_image = ":/img/items/antihangover.png";
    m_desc = "Выпить при полхмелье";
}

Tampon::Tampon()
{
    m_name = "Прокладки";
    m_image = ":/img/items/tampons.png";
    m_desc = "Защитят при тех самых днях";
}

AntiPregPills::AntiPregPills()
{
    m_name = "Противозачаточные";
    m_image = ":/img/items/pills.png";
    m_desc = "От нежелательной беременности";
}

Razor::Razor()
{
    m_name = "Одноразовая бритва";
    m_image = ":/img/items/razor.png";
    m_desc = "Убрать растительность";
}

LipBalm::LipBalm()
{
    m_name = "Бальзам для губ";
    m_image = ":/img/items/libpalm.png";
    m_desc = "Бальзам увлажняет губы, придает им блеск, тем самым увеличивает привлекательность губ. Есть побочные эффекты: при постоянном использовании необратимо увеличивает губы.**Тюбик, хватит на 25 применений.";
}

Lubricant::Lubricant()
{
    m_name = "Лубрикант";
    m_image = ":/img/items/lubri.png";
    m_desc = "Смазать дырочки";
}

/////////////////   SEX TOYS \\\\\\\\\\\\\\\\\\\

Dildo::Dildo()
{
    m_name = "Маленький фаллоимитатор";
    m_image = ":/img/items/dildo-mini.png";
    m_desc = "Смазать дырочки";
}

MidDildo::MidDildo()
{
    m_name = "Фаллоимитатор, 15 см";
    m_image = ":/img/items/dildo15.png";
    m_desc = "";
}

LargeDildo::LargeDildo()
{
    m_name = "Фаллоимитатор, 20 см";
    m_image = ":/img/items/dildo20.png";
    m_desc = "";
}

BigDildo::BigDildo()
{
    m_name = "Фаллоимитатор, 25 см";
    m_image = ":/img/items/dildo25.png";
    m_desc = "";
}

ExtraDildo::ExtraDildo()
{
    m_name = "Фаллоимитатор, 30 см";
    m_image = ":/img/items/dildo30.png";
    m_desc = "";
}

SuperDildo::SuperDildo()
{
    m_name = "Фаллоимитатор, 35 см";
    m_image = ":/img/items/dildo35.png";
    m_desc = "";
}

MadDildo::MadDildo()
{
    m_name = "Фаллоимитатор, 40 см";
    m_image = ":/img/items/dildo40.png";
    m_desc = "";
}

AnalPlug::AnalPlug()
{
    m_name = "Анальная пробка";
    m_image = ":/img/items/analplug.png";
    m_desc = "";
}

Vibrator::Vibrator()
{
    m_name = "Вибратор";
    m_image = ":/img/items/vibrator.png";
    m_desc = "";
}

Strapon::Strapon()
{
    m_name = "Страпон";
    m_image = ":/img/items/strapon.png";
    m_desc = "";
}
