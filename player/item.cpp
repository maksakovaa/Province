#include "item.h"
#include "Functions.h"

Item::Item(Items id)
{
    m_id = id;
    if (m_id <= iTicTac) m_type = itFood;
    else if (m_id > iTicTac && m_id <= iComb) m_type = itCosmetics;
    else if (m_id > iComb && m_id <= iFabric) m_type = itCommon;
    else if (m_id > iFabric && m_id <= iSinger) m_type = itTech;
    else if (m_id > iSinger && m_id <= iHoop) m_type = itSport;
    else if (m_id > iHoop && m_id <= iStrapon) m_type = itSexToys;
    else if (m_id > iStrapon) m_type = itMedSupplies;

    if (m_id == iCosmetic) m_quantity = m_quantity_max = 15;
    if (m_id == iCosmeticBig) m_quantity = m_quantity_max = 30;
    if (m_id == iTampon) m_quantity = m_quantity_max = 20;
    if (m_id == iMorningCare) m_quantity = m_quantity_max = 5;
    if (m_id == iVagGel) m_quantity = m_quantity_max = 5;
    if (m_id == iSunscreen) m_quantity = m_quantity_max = 20;
    if (m_id == iWetWipes) m_quantity = m_quantity_max = 10;
}

QString Item::getName()
{
    return str(m_id);
}

QString Item::getDesc()
{
    return strDesc(m_id);
}

QString Item::getImage()
{
    return "<img src=':/img/items/" + intQStr(m_type) + "/" + intQStr(m_id) + ".png'></img>";
}

int Item::getQuantity()
{
    return m_quantity;
}

int Item::getMaxQuantity()
{
    return m_quantity_max;
}

void Item::use(int count)
{
    m_quantity - count;
}

void Item::setQuantity(int value)
{
    m_quantity = value;
}

QString Item::str(Items id)
{
    QString str[55];
    str[0] = "Еда";
    str[1] = "Диетическая еда";
    str[2] = "Хлеб";
    str[3] = "Бутерброд";
    str[4] = "Бутылочка воды";
    str[5] = "Вино";
    str[6] = "Водка";
    str[7] = "Сосиски";
    str[8] = "Куриные крылышки";
    str[9] = "Шоколад";
    str[10] = "Печенье";
    str[11] = "TicTac";

    str[12] = "Косметика";
    str[13] = "Косметический набор";
    str[14] = "Бритвенный станок(5 шт)";
    str[15] = "Солнцезащитный крем";
    str[16] = "Шампунь";
    str[17] = "Тампоны(20 шт)";
    str[18] = "Влажные салфетки";
    str[19] = "Напиток Morning Care(5 доз)";
    str[20] = "Гель для вагины Touch(5 доз)";
    str[21] = "Расческа";

    str[22] = "Средство для мытья посуды";
    str[23] = "Стиральный порошок";
    str[24] = "Набор из 3-х тарелок";
    str[25] = "Краска для стен";
    str[26] = "Рулон ткани";

    str[27] = "Небольшой телевизор с кинескопом";
    str[28] = "Большой плазменный телевизор";
    str[29] = "Ноутбук";
    str[30] = "Посудомоечная машина";
    str[31] = "Стиральная машина";
    str[32] = "Веб камера";
    str[33] = "Швейная машинка Singer";

    str[34] = "Коньки";
    str[35] = "Скакалка";
    str[36] = "Обруч";
    str[37] = "Маленький фаллоимитатор";
    str[38] = "Фаллоимитатор, 15 см";
    str[39] = "Фаллоимитатор, 20 см";
    str[40] = "Фаллоимитатор, 25 см";
    str[41] = "Фаллоимитатор, 30 см";
    str[42] = "Фаллоимитатор, 35 см";
    str[43] = "Фаллоимитатор, 40 см";
    str[44] = "Анальная пробка";
    str[45] = "Вибратор";
    str[46] = "Страпон";
    str[47] = "Презервативы";
    str[48] = "Противозачаточные";
    str[49] = "Лубрикант";
    str[50] = "Тест на беременность";
    str[51] = "Витамины";
    str[52] = "Антибиотики";
    str[53] = "Бальзам для губ";
    str[54] = "Жиросжигатели";
    return str[id];
}

QString Item::strDesc(Items id)
{
    QString str[55];
    str[0] = "Еда";
    str[1] = "Диетическая еда";
    str[2] = "Хлеб";
    str[3] = "Бутерброд";
    str[4] = "Бутылочка воды";
    str[5] = "Вино";
    str[6] = "Водка";
    str[7] = "Сосиски";
    str[8] = "Куриные крылышки";
    str[9] = "Шоколад";
    str[10] = "Печенье";
    str[11] = "TicTac";

    str[12] = "Косметика";
    str[13] = "Косметический набор";
    str[14] = "Бритвенный станок(5 шт)";
    str[15] = "Солнцезащитный крем";
    str[16] = "Шампунь";
    str[17] = "Тампоны(20 шт)";
    str[18] = "Влажные салфетки";
    str[19] = "Напиток Morning Care(5 доз)";
    str[20] = "Гель для вагины Touch(5 доз)";
    str[21] = "Расческа";

    str[22] = "Средство для мытья посуды";
    str[23] = "Стиральный порошок";
    str[24] = "Набор из 3-х тарелок";
    str[25] = "Краска для стен";
    str[26] = "Рулон ткани";

    str[27] = "Небольшой телевизор с кинескопом";
    str[28] = "Большой плазменный телевизор";
    str[29] = "Ноутбук";
    str[30] = "Посудомоечная машина";
    str[31] = "Стиральная машина";
    str[32] = "Веб камера";
    str[33] = "Швейная машинка Singer";

    str[34] = "Коньки";
    str[35] = "Скакалка";
    str[36] = "Обруч";
    str[37] = "Маленький фаллоимитатор";
    str[38] = "Фаллоимитатор, 15 см";
    str[39] = "Страпон";
    str[40] = "Презервативы";
    str[41] = "Фаллоимитатор, 30 см";
    str[42] = "Фаллоимитатор, 35 см";
    str[43] = "Фаллоимитатор, 40 см";
    str[44] = "Анальная пробка";
    str[45] = "Вибратор";
    str[46] = "Страпон";
    str[47] = "Презервативы";
    str[48] = "Противозачаточные";
    str[49] = "Лубрикант";
    str[50] = "Тест на беременность";
    str[51] = "Витамины";
    str[52] = "Антибиотики";
    str[53] = "Бальзам для губ";
    str[54] = "Жиросжигатели";
    return str[id];
}
