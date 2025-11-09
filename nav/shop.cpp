#include "shop.h"
#include "locationform.h"
#include "qactionbutton.h"
#include "ui_locationform.h"
#include "../Functions.h"
// #include <iostream>
#include <QDirIterator>
#include <QScrollArea>
#include "../player/itemform.h"

Shop::Shop(QWidget *parent): QObject(parent)
{
    root = (LocationForm*)parent;
    initClothArray();
    layoutMain = new QVBoxLayout;
    widgetMain = new QWidget;
    widgetMain->setLayout(layoutMain);
    root->ui->scrollAreaShop->setWidget(widgetMain);
}

void Shop::slotShopHandler(const QString& link)
{
    current = link;
    makeShop();

    if (link == "shop_food")
    {
        shop_food();
    }
    else if(link == "shop_cosmetics")
    {
        shop_cosmetics();
    }
    else if(link == "shop_common")
    {
        shop_common();
    }
    else if(link == "shop_clothing")
    {
        shop_clothing();
    }
    else if (link == "shop_tech")
    {
        shop_tech();
    }
    else if (link == "shop_sport")
    {
        shop_sport();
    }
}

void Shop::slotBuyItem(Items id)
{
    root->updVStatus(money, - itemPrice(id));
    root->addItem(id);
    root->sendNotif("<img src=':/img/icons/money.png'></img> -" + intQStr(itemPrice(id)));
    root->sendNotif(itemName(id) + " добавлено");
    slotShopHandler(current);
}

void Shop::slotBuyCloth(int id, ClothGroup group)
{
    ClothMain* ptr = new ClothMain(id, group,clothName(group));
    root->addCloth(ptr);
    root->updVStatus(money, -clothPrice(group));
    root->sendNotif("<img src=':/img/icons/money.png'></img> -" + intQStr(clothPrice(group)));
    root->sendNotif(clothName(group) + " добавлен в гардероб");
    slotShopHandler(current);
}

void Shop::makeShop()
{
    root->incTime(1);
    root->ui->imageAndWideoWdgt->setCurrentIndex(2);
    if(!m_layouts.empty())
    {
        for (int i = 0; i < m_layouts.size(); i++)
        {
            ClearLayout(m_layouts[i]);
            delete m_layouts[i];
        }
        m_layouts.clear();
    }
    ClearLayout(root->m_actLayout);

    QActionButton* btn = new QActionButton(1);
    btn->setText("Назад");
    btn->setLocPtr(root->getCurPtr());
    root->m_actLayout->addWidget(btn);
    connect(btn, &QActionButton::sigChangeSubLoc, root, &LocationForm::slotChangeLoc);
}

void Shop::shop_food()
{
    int layoutIndex = 0;
    for (int i = 0; i <= iTicTac; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if(i % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        makeItemForm(static_cast<Items>(i), itFood);
    }
}

void Shop::shop_cosmetics()
{
    int layoutIndex = 0;
    for (int i = iCosmetic; i <= iComb; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if((i - iCosmetic) % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        makeItemForm(static_cast<Items>(i), itCosmetics);
    }
}

void Shop::shop_common()
{
    int layoutIndex = 0;
    for (int i = iDishwashBotltle; i <= iFabric; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if((i - iDishwashBotltle) % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        makeItemForm(static_cast<Items>(i), itCommon);
    }
}

void Shop::shop_clothing()
{
    std::vector<int> a = initClothArray(jeans);
    std::vector<int> b = initClothArray(skirt);
    std::vector<int> c = initClothArray(officeSuit);
    int acount = a.size();
    int bcount = b.size();
    int ccount = c.size();
    int sum = acount + bcount + ccount;

    int layoutIndex = 0;
    for (int i = 0; i < sum; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if(i % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        if(i < acount)
        {
            makeClothForm(a[i],jeans);
        }
        else if(i >= acount && i < acount + bcount)
        {
            makeClothForm(b[i-acount],skirt);
        }
        else
        {
            makeClothForm(c[i - acount - bcount],officeSuit);
        }
    }
}

void Shop::shop_tech()
{
    int layoutIndex = 0;
    for (int i = iCRTTV; i <= iSinger; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if((i - iCRTTV) % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        makeItemForm(static_cast<Items>(i), itTech);
    }
}

void Shop::shop_sport()
{
    std::vector<int> a = initClothArray(sportsSuit);

    for (int i = iSkates; i <= iHoop; ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        makeItemForm(static_cast<Items>(i),itSport);
    }
    int layoutIndex = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if(m_layouts.empty())
        {
            createHLayoyt();
        }
        if(i % 4 == 0 && layoutIndex + 1 >= m_layouts.size())
        {
            createHLayoyt();
            layoutIndex++;
        }
        makeClothForm(a[i], sportsSuit);
    }
}

void Shop::initClothArray()
{
    QString path = ":/img/clothing/";
    for(int i = ClothGroup::sportsSuit; i <= ClothGroup::sexualUnderwear; i++)
    {
        QDirIterator iter(path + intQStr(i), QDir::Files);
        while (iter.hasNext())
        {
            iter.next();
            QStringList list = iter.fileName().split('.');
            int id = list[0].toInt();
            m_cloth[static_cast<ClothGroup>(i)].push_back(id);
        }
    }   
}

std::vector<int> Shop::initClothArray(ClothGroup group)
{
    std::vector<int> clothes;
    
    switch (group)
    {
    case ClothGroup::sportsSuit:
        for (size_t i = 0; i < m_cloth[sportsSuit].size(); i++)
        {
            clothes.push_back(m_cloth[sportsSuit][i]);
        }
        break;
    case ClothGroup::jeans:
        for (size_t i = 0; i < m_cloth[jeans].size(); i++)
        {
            clothes.push_back(m_cloth[jeans][i]);
        }
        break;
    case ClothGroup::skirt:
        for (size_t i = 0; i < m_cloth[skirt].size(); i++)
        {
            clothes.push_back(m_cloth[skirt][i]);
        }
        break;
    case ClothGroup::casualDress:
        for (size_t i = 0; i < m_cloth[casualDress].size(); i++)
        {
            clothes.push_back(m_cloth[casualDress][i]);
        }
        break;
    case ClothGroup::eveningDress:
        for (size_t i = 0; i < m_cloth[eveningDress].size(); i++)
        {
            clothes.push_back(m_cloth[eveningDress][i]);
        }
        break;
    case ClothGroup::officeSuit:
        for (size_t i = 0; i < m_cloth[officeSuit].size(); i++)
        {
            clothes.push_back(m_cloth[officeSuit][i]);
        }
        break;
    case ClothGroup::revealingOutfit:
        for (size_t i = 0; i < m_cloth[revealingOutfit].size(); i++)
        {
            clothes.push_back(m_cloth[revealingOutfit][i]);
        }
        break;
    case ClothGroup::blouseWithShorts:
        for (size_t i = 0; i < m_cloth[blouseWithShorts].size(); i++)
        {
            clothes.push_back(m_cloth[blouseWithShorts][i]);
        }
        break;
    case ClothGroup::sexualUnderwear:
        for (size_t i = 0; i < m_cloth[sexualUnderwear].size(); i++)
        {
            clothes.push_back(m_cloth[sexualUnderwear][i]);
        }
        break;
    }

    return clothes;
}

int Shop::itemPrice(int itemId)
{
    int price[37];
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

    price[12] = 500;
    price[13] = 1000;
    price[14] = 300;
    price[15] = 300;
    price[16] = 300;
    price[17] = 200;
    price[18] = 100;
    price[19] = 4500;
    price[20] = 5000;
    price[21] = 200;

    price[22] = 200;
    price[23] = 200;
    price[24] = 1000;
    price[25] = 800;
    price[26] = 500;

    price[27] = 10000;
    price[28] = 35000;
    price[29] = 25000;
    price[30] = 30000;
    price[31] = 20000;
    price[32] = 5000;
    price[33] = 25000;

    price[34] = 2000;
    price[35] = 300;
    price[36] = 500;
    return price[itemId];
}

QString Shop::itemName(int itemId)
{
    QString str[37];
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

    return str[itemId];
}

int Shop::clothPrice(ClothGroup type)
{
    int price[9];
    price[0] = 5000;
    price[1] = 3000;
    price[2] = 7000;
    price[3] = 10000;
    price[4] = 40000;
    price[5] = 20000;
    price[6] = 15000;
    price[7] = 15000;
    price[8] = 8000;
    return price[type - 6];
}

QString Shop::clothName(ClothGroup type)
{
    QString str[9];
    str[0] = "Спортивный костюм";
    str[1] = "Джинсы";
    str[2] = "Наряд с юбкой";
    str[3] = "Повседневное платье";
    str[4] = "Вечернее платье";
    str[5] = "Офисный костюм";
    str[6] = "Откровенный наряд";
    str[7] = "Блузка с шортами";
    str[8] = "Сексуальное бельё";
    return str[type - 6];
}

void Shop::createHLayoyt()
{
    QHBoxLayout* lay = new QHBoxLayout;
    m_layouts.push_back(lay);
    layoutMain->addLayout(lay);
}

void Shop::makeItemForm(Items id, itemType type)
{
    QString image = "<img src=':/img/items/" + intQStr(type)+"/" + intQStr(id) + ".png'></img>";
    ItemFormShop* item = new ItemFormShop(id, image,root->getItemName(id), intQStr(itemPrice(id)));
    if(itemPrice(id) > root->getVStatus(money))
    {
        item->setUnavailable("Недостаточно средств");
    }
    else
    {
        item->setUseBtnText("<a style='text-decoration: none; color: rgb(255, 255, 255);' href='buy'>Купить</a>");
    }
    m_layouts.back()->addWidget(item);
    connect(item, &ItemFormShop::sigBuyItem, this, &Shop::slotBuyItem);
}

void Shop::makeClothForm(int clothId, ClothGroup group)
{
    QString imagePath = "<img style='max-width: 200px; max-height: 200px' src=':/img/clothing/" + intQStr(group) + "/" + intQStr(clothId) + ".jpg'></img>";
    ItemFormCloth* item = new ItemFormCloth(clothId,group,imagePath, clothName(group), intQStr(clothPrice(group)));
    if(clothPrice(group) > root->getVStatus(money))
    {
        item->setUnavailable("Недостаточно средств");
    }
    else
    {
        item->setUseBtnText("<a style='text-decoration: none; color: rgb(255, 255, 255);' href='buy'>Купить</a>");
    }
    m_layouts.back()->addWidget(item);
    connect(item, &ItemFormCloth::sigBuyCloth, this, &Shop::slotBuyCloth);
}
