#include "bagform.h"
#include "ui_bagform.h"
#include <vector>
#include "../Functions.h"

BagForm::BagForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BagForm)
{
    ui->setupUi(this);
    initBag();
    ui->verticalLayout_2->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    ui->verticalLayout_2->setSpacing(20);
}

BagForm::~BagForm()
{
    for (int i = 0; i < m_layouts.size(); ++i) {
        ClearLayout(m_layouts[i]);
        delete m_layouts[i];
    }
    m_layouts.clear();
    delete ui;
}

void BagForm::putInBag(Items name, int count)
{
    updQuantity(name, count);
}

int BagForm::getQuantityof(Items name)
{
    return m_storage[m_items[name]];
}

void BagForm::removeFromBag(Items name, int count)
{
    if (name == cosmetic)
    {
        ((Cosmetic*)m_items[name])->useCosmetic(count);
        if(((Cosmetic*)m_items[name])->getQuantity() <= 0)
        {
            m_storage[m_items[name]] -= 1;
            ((Cosmetic*)m_items[name])->setQuantity(((Cosmetic*)m_items[name])->getMaxQuantity() + ((Cosmetic*)m_items[name])->getQuantity());
        }
    }
    else if(name == cosmeticBig)
    {
        ((CosmeticBig*)m_items[name])->useCosmetic(count);
        if(((CosmeticBig*)m_items[name])->getQuantity() <= 0)
        {
            m_storage[m_items[name]] -= 1;
            ((CosmeticBig*)m_items[name])->setQuantity(((CosmeticBig*)m_items[name])->getMaxQuantity() + ((CosmeticBig*)m_items[name])->getQuantity());
        }
    }
    else
    {
        updQuantity(name, -count);
    }
}

void BagForm::fillItemList()
{
    for(int i = 0; i < m_layouts.size(); ++i)
    {
        ClearLayout(m_layouts[i]);
        delete m_layouts[i];
    }
    m_layouts.clear();

    imgs.clear();
    names.clear();
    descs.clear();
    counters.clear();

    if (m_storage[m_items[condoms]] > 0)
        grabItemsDesc(m_items[condoms]);
    if (m_storage[m_items[cosmetic]] > 0)
        grabItemsDesc(m_items[cosmetic]);
    if (m_storage[m_items[cosmeticBig]] > 0)
        grabItemsDesc(m_items[cosmeticBig]);
    if (m_storage[m_items[tampon]] > 0)
        grabItemsDesc(m_items[tampon]);
    if (m_storage[m_items[antiPregPills]] > 0)
        grabItemsDesc(m_items[antiPregPills]);
    if (m_storage[m_items[wetWipes]] > 0)
        grabItemsDesc(m_items[wetWipes]);
    if (m_storage[m_items[morningCare]] > 0)
        grabItemsDesc(m_items[morningCare]);
    if (m_storage[m_items[vagGel]] > 0)
        grabItemsDesc(m_items[vagGel]);
    if (m_storage[m_items[razor]] > 0)
        grabItemsDesc(m_items[razor]);
    if(m_storage[m_items[lipBalm]] > 0)
        grabItemsDesc(m_items[lipBalm]);
    if(m_storage[m_items[lubri]] > 0)
        grabItemsDesc(m_items[lubri]);

    if(m_storage[m_items[iDildo]] > 0)
        grabItemsDesc(m_items[iDildo]);
    if(m_storage[m_items[iMidDildo]] > 0)
        grabItemsDesc(m_items[iMidDildo]);
    if(m_storage[m_items[iLargeDildo]] > 0)
        grabItemsDesc(m_items[iLargeDildo]);
    if(m_storage[m_items[iBigDildo]] > 0)
        grabItemsDesc(m_items[iBigDildo]);
    if(m_storage[m_items[iExtraDildo]] > 0)
        grabItemsDesc(m_items[iExtraDildo]);
    if(m_storage[m_items[iSuperDildo]] > 0)
        grabItemsDesc(m_items[iSuperDildo]);
    if(m_storage[m_items[iMadDildo]] > 0)
        grabItemsDesc(m_items[iMadDildo]);
    if(m_storage[m_items[iAnalPlug]] > 0)
        grabItemsDesc(m_items[iAnalPlug]);
    if(m_storage[m_items[iVibrator]] > 0)
        grabItemsDesc(m_items[iVibrator]);
    if(m_storage[m_items[iStrapon]] > 0)
        grabItemsDesc(m_items[iStrapon]);

    int layoutIndex = 0;
    for (int i = 0; i < imgs.size(); ++i)
    {
        if(m_layouts.empty())
        {
            initNewLayout();
        }
        if(i % 3 == 0 && layoutIndex + 1  >= m_layouts.size())
        {
            initNewLayout();
            layoutIndex++;
        }
        ItemForm* form = makeItemWidget(imgs[i], names[i], descs[i]);
        form->addCounter(counters[i]);
        m_layouts.back()->addWidget(form);
    }
}

void BagForm::updQuantity(Items type, int count)
{
    m_storage[m_items[type]] += count;
}

void BagForm::initNewLayout()
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft);
    m_layouts.push_back(layout);
    ui->verticalLayout_2->addLayout(m_layouts.back());
}

void BagForm::initBag()
{
    m_items[Items::antiPregPills] = new AntiPregPills;
    m_items[Items::condoms] = new Condoms;
    m_items[Items::cosmetic] = new Cosmetic;
    m_items[Items::cosmeticBig] = new CosmeticBig;
    m_items[Items::lipBalm] = new LipBalm;
    m_items[Items::morningCare] = new MorningCare;
    m_items[Items::razor] = new Razor;
    m_items[Items::tampon] = new Tampon;
    m_items[Items::vagGel] = new VagGel;
    m_items[Items::wetWipes] = new WetWipes;
    m_items[Items::lipBalm] = new LipBalm;
    m_items[Items::lubri] = new Lubricant;
    m_items[iDildo] = new Dildo;
    m_items[iMidDildo] = new MidDildo;
    m_items[iLargeDildo] = new LargeDildo;
    m_items[iBigDildo] = new BigDildo;
    m_items[iExtraDildo] = new ExtraDildo;
    m_items[iSuperDildo] = new SuperDildo;
    m_items[iMadDildo] = new MadDildo;
    m_items[iAnalPlug] = new AnalPlug;
    m_items[iVibrator] = new Vibrator;
    m_items[iStrapon] = new Strapon;


    for (int i = 0; i < lipBalm; ++i)
    {
        m_storage[m_items[static_cast<Items>(i)]] = 0;
    }

    m_storage[m_items[condoms]] = 10;
    m_storage[m_items[cosmetic]] = 10;
    m_storage[m_items[cosmeticBig]] = 10;
    m_storage[m_items[tampon]] = 20;
    m_storage[m_items[antiPregPills]] = 10;
    m_storage[m_items[wetWipes]] = 1;
    m_storage[m_items[morningCare]] = 1;
    m_storage[m_items[vagGel]] = 1;
    m_storage[m_items[razor]] = 10;
    m_storage[m_items[lipBalm]] = 25;
    m_storage[m_items[lubri]] = 20;

    m_storage[m_items[iDildo]] = 1;
    m_storage[m_items[iMidDildo]] = 1;
    m_storage[m_items[iLargeDildo]] = 1;
    m_storage[m_items[iBigDildo]] = 1;
    m_storage[m_items[iExtraDildo]] = 1;
    m_storage[m_items[iSuperDildo]] = 1;
    m_storage[m_items[iMadDildo]] = 1;
    m_storage[m_items[iAnalPlug]] = 1;
    m_storage[m_items[iVibrator]] = 1;
    m_storage[m_items[iStrapon]] = 1;
}

ItemForm *BagForm::makeItemWidget(QString image, QString name, QString desc)
{
    ItemForm* result = new ItemForm(image, name, desc, this);
    return result;
}

void BagForm::grabItemsDesc(Item *item)
{
    imgs.push_back(item->getImage());
    names.push_back(item->getName());
    descs.push_back(item->getDesc());
    counters.push_back(m_storage[item]);
}
