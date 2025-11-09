#include "itemform.h"
#include "../Functions.h"
#include "ui_itemform.h"

ItemForm::ItemForm(QString image, QString name, QString desc, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ItemForm)
{
    ui->setupUi(this);
    countLayout = new QVBoxLayout(ui->imageLabel);
    ui->imageLabel->setText(image);
    ui->textLabel->setText(name);
    ui->descLabel->setText(desc);
    ui->textLabel->setStyleSheet("color: green");
    this->setStyleSheet("QFrame#ItemForm { "
                         "border: 1px solid black; "
                         "border-radius: 10px; "
                         "background-color: #eee; "
                         "}"
                        "QLabel#imageLabel {background-color: transparent;}"
                        "QLabel#descLabel {background-color: transparent;}");
    connect(ui->labelUse, &QLabel::linkActivated, this, &ItemForm::useHandler);
}

ItemForm::~ItemForm()
{
    clearLayout();
    delete countLayout;
    delete ui;
}

void ItemForm::addCounter(int value)
{
    QLabel* text = new QLabel;
    text->setFixedSize(250,150);
    text->setText(intQStr(value));
    text->setAlignment(Qt::AlignBottom | Qt::AlignRight);
    text->setStyleSheet("font-size: 14pt; background-color: transparent;");
    countLayout->addWidget(text);
}

void ItemForm::setUnavailable(QString text)
{
    ui->labelUse->setStyleSheet("QLabel#labelUse {border: 1px solid black; border-radius: 10px; background-color: gray; color: rgb(255, 255, 255);}");
    ui->labelUse->setText(text);
}

void ItemForm::setUseBtnText(QString text)
{
    ui->labelUse->setText(text);
}

void ItemForm::useHandler(const QString &link)
{

}

void ItemForm::clearLayout()
{
    while (countLayout->count() > 0)
    {
        QLayoutItem* item = countLayout->takeAt(0);
        if(item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}

ItemFormCloth::ItemFormCloth(int id, ClothGroup group, QString image, QString name, QString desc, QWidget *parent): ItemForm(image,name,desc,parent)
{
    m_Id = id;
    m_group = group;
}

void ItemFormCloth::useHandler(const QString &link)
{
    emit sigBuyCloth(m_Id, m_group);
}

ItemFormShop::ItemFormShop(Items id, QString image, QString name, QString desc, QWidget *parent): ItemForm(image,name,desc,parent)
{
    m_id = id;
}

void ItemFormShop::useHandler(const QString &link)
{
    emit sigBuyItem(m_id);
}
