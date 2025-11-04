#include "shop.h"
#include "locationform.h"

Shop::Shop(QWidget *parent)
{
    root = (LocationForm*)parent;
}

void Shop::shop_food()
{

}

void Shop::shop_cosmetics()
{

}

void Shop::shop_common()
{

}

void Shop::shop_clothing()
{

}

void Shop::shop_tech()
{

}

void Shop::shop_sport()
{

}

int Shop::foodPrice(Food type)
{
    int price[12];
    price[0] = 200;
    price[1] = 300;
    price[2] = 30;
    price[3] = 100;
    price[4] = 50;
    price[5] = 500;
    price[6] = 400;
    price[7] = 300;
    price[8] = 250;
    price[9] = 100;
    price[10] = 80;
    price[11] = 100;

    return price[type];
}

QString Shop::foodName(Food type)
{
    QString str[12];
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
    return str[type];
}

int Shop::cosmeticsPrice(Cosmetics type)
{
    int price[10];
    price[0] = 500;
    price[1] = 1000;
    price[2] = 300;
    price[3] = 300;
    price[4] = 300;
    price[5] = 200;
    price[6] = 100;
    price[7] = 4500;
    price[8] = 5000;
    price[9] = 200;

    return price[type];
}

QString Shop::cosmeticsName(Cosmetics type)
{
    QString str[10];
    str[0] = "Косметика";
    str[1] = "Косметический набор";
    str[2] = "Бритвенный станок(5 шт)";
    str[3] = "Солнцезащитный крем";
    str[4] = "Шампунь";
    str[5] = "Тампоны(20 шт)";
    str[6] = "Влажные салфетки";
    str[7] = "Напиток Morning Care(5 доз)";
    str[8] = "Гель для вагины Touch(5 доз)";
    str[9] = "Расческа";
    return str[type];
}

int Shop::commonPrice(Common type)
{
    int price[5];
    price[0] = 200;
    price[1] = 200;
    price[2] = 1000;
    price[3] = 800;
    price[4] = 500;

    return price[type];
}

QString Shop::commonName(Common type)
{
    QString str[5];
    str[0] = "Средство для мытья посуды";
    str[1] = "Стиральный порошок";
    str[2] = "Набор из 3-х тарелок";
    str[3] = "Краска для стен";
    str[4] = "Рулон ткани";
    return str[type];
}

int Shop::clothPrice(ClothGroup type)
{
    return 0;
}

QString Shop::clothName(ClothGroup type)
{
    return "";
}

int Shop::techPrice(Tech type)
{
    int price[7];
    price[0] = 10000;
    price[1] = 35000;
    price[2] = 25000;
    price[3] = 30000;
    price[4] = 20000;
    price[5] = 5000;
    price[6] = 25000;

    return price[type];
}

QString Shop::techName(Tech type)
{
    QString str[7];
    str[0] = "Небольшой телевизор с кинескопом";
    str[1] = "Большой плазменный телевизор";
    str[2] = "Ноутбук";
    str[3] = "Посудомоечная машина";
    str[4] = "Стиральная машина";
    str[5] = "Веб камера";
    str[6] = "Швейная машинка Singer";
    return str[type];
}

int Shop::sportPrice(Sport type)
{
    int price[3];
    price[0] = 2000;
    price[1] = 300;
    price[2] = 500;

    return price[type];
}

QString Shop::sportName(Sport type)
{
    QString str[3];
    str[0] = "Коньки";
    str[1] = "Скакалка";
    str[2] = "Обруч";
    return str[type];
}
