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

void BagForm::useItem(Items name, int count)
{
    if (name == iCosmetic || name == iCosmeticBig || name == iTampon || name == iMorningCare || name == iVagGel || name == iSunscreen || iWetWipes)
    {
        (m_items[name])->use(count);
        if((m_items[name])->getQuantity() <= 0)
        {
            m_storage[m_items[name]] -= 1;
            m_items[name]->setQuantity(m_items[name]->getMaxQuantity() + m_items[name]->getQuantity());
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

    for (int i = iFood; i < iFatBurners; ++i)
    {
        if(m_storage[m_items[static_cast<Items>(i)]] > 0)
            grabItemsDesc(m_items[static_cast<Items>(i)]);
    }

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

QString BagForm::getItemName(Items id)
{
    return m_items[id]->getName();
}

void BagForm::updQuantity(Items type, int count)
{
    m_storage[m_items[type]] += count;
}

void BagForm::initNewLayout()
{
    QHBoxLayout* layout = new QHBoxLayout;
    layout->setAlignment(Qt::AlignLeft);
    m_layouts.push_back(layout);
    ui->verticalLayout_2->addLayout(m_layouts.back());
}

void BagForm::initBag()
{
    for (size_t i = 0; i <= iFatBurners; i++)
    {
        m_items[static_cast<Items>(i)] = new Item(static_cast<Items>(i));
    }
    
    for (int i = 0; i < iFatBurners; ++i)
    {
        m_storage[m_items[static_cast<Items>(i)]] = 0;
    }

    m_storage[m_items[iCondoms]] = 10;
    m_storage[m_items[iCosmetic]] = 10;
    m_storage[m_items[iCosmeticBig]] = 10;
    m_storage[m_items[iTampon]] = 20;
    m_storage[m_items[iAntiPregPills]] = 0;
    m_storage[m_items[iWetWipes]] = 1;
    m_storage[m_items[iMorningCare]] = 1;
    m_storage[m_items[iVagGel]] = 1;
    m_storage[m_items[iRazor]] = 10;
    m_storage[m_items[iLipBalm]] = 25;
    m_storage[m_items[iLubri]] = 20;

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
