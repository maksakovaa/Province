#include "clothform.h"
#include "../Functions.h"
#include "ui_clothform.h"

ClothForm::ClothForm(ClothMain *cloth, int hips, QWidget *parent) : QWidget(parent), ui(new Ui::ClothForm), ptr(cloth)
{
    ui->setupUi(this);
    connect(ui->pushBtnFitCloth, &QPushButton::clicked, this, &ClothForm::FitBtnClick);
    connect(ui->pushBtnRemove, &QPushButton::clicked, this, &ClothForm::RemoveBtnClick);
    connect(ui->pushBtnTrash, &QPushButton::clicked, this, &ClothForm::TrashBtnClick);
    connect(ui->pushBtnWear, &QPushButton::clicked, this, &ClothForm::WearBtnClick);
    ui->label->setText("<img src='" + cloth->getClothImage() + "'></img>");
    ui->label->setToolTip(cloth->getName());
    setStyleWearBtn(cloth->m_size, hips, cloth->getCondition(), cloth->getClothGroup());
    setStyleFitBtn(cloth->m_size, hips, cloth->getCondition(), cloth->getClothGroup());
    setStyleTrahRemoveBtn(cloth->getClothGroup());
    this->setStyleSheet("QPushButton:hover { background-color: #dddddd;}");
}

ClothForm::~ClothForm()
{
    ptr = nullptr;
    delete ui;
}

void ClothForm::WearBtnClick()
{
    emit sigCloth(ptr,"wear");
}

void ClothForm::FitBtnClick()
{
    emit sigCloth(ptr,"fit");
}

void ClothForm::TrashBtnClick()
{
    emit sigCloth(ptr,"trash");
}

void ClothForm::RemoveBtnClick()
{
    emit sigCloth(ptr, "remove");
}

void ClothForm::setStyleWearBtn(int size, int hips, int condition, int group)
{
    int iconNum = 0;
    QString toolTip;
    if(condition <= 0 && condition != -99)
    {
        iconNum = 0; toolTip = "Вы не можете надеть эту вещь.<br>- Вещь изношена";
        ui->pushBtnWear->setEnabled(false);
    }
    else if(condition == -99 || condition > 75)
    {
        iconNum = 4; toolTip = "Надеть.<br>- Вещь в отличном состоянии";
    }
    else if (condition >50 && condition <= 75)
    {
        iconNum = 3; toolTip = "Надеть.<br>- Вещь в хорошем состоянии";
    }
    else if (condition > 25 && condition <= 50)
    {
        iconNum = 2; toolTip = "Надеть.<br>- Вещь в нормальном состоянии";
    }
    else
    {
        iconNum = 1; toolTip = "Надеть.<br>- Вещь в плохом состоянии";
    }
    QIcon icon = QIcon(":/img/clothing/icons/" + intQStr(iconNum) + ".png");
    QString razmer = "<br>- Имеет размер: " + intQStr(size);
    if(group < ClothGroup::sportsSuit || (size >= hips -8 && size <= hips + 8 && condition > 0 && group >= ClothGroup::sportsSuit))
    {
        toolTip += razmer;
    }
    else
    {
        toolTip = "Вы не можете надеть эту вещь.<br>- ";
        if(size > hips) toolTip += "Она слишком большая";
        else toolTip += "Она слишком маленькая";
        toolTip +=  "на вас.";
        if(group >= ClothGroup::sportsSuit)
            toolTip += razmer;
        ui->pushBtnWear->setEnabled(false);
    }
    ui->pushBtnWear->setIcon(icon);
    ui->pushBtnWear->setToolTip(toolTip);
}

void ClothForm::setStyleFitBtn(int size, int hips, int condition, int group)
{

}

void ClothForm::setStyleTrahRemoveBtn(int group)
{
    if(group < ClothGroup::sportsSuit)
    {
        ui->pushBtnTrash->setIcon(QIcon(":/img/clothing/icons/8.svg"));
        ui->pushBtnTrash->setToolTip("Вы не можете отправить эту вещь в корзину.");
        ui->pushBtnRemove->setIcon(QIcon(":/img/clothing/icons/10.svg"));
        ui->pushBtnRemove->setToolTip("Вы не можете выбросить эту вещь.");
        ui->pushBtnRemove->setEnabled(false);
        ui->pushBtnTrash->setEnabled(false);
    }
    else
    {
        ui->pushBtnTrash->setIcon(QIcon(":/img/clothing/icons/7.svg"));
        ui->pushBtnTrash->setToolTip("В корзину.");
        ui->pushBtnRemove->setIcon(QIcon(":/img/clothing/icons/9.svg"));
        ui->pushBtnRemove->setToolTip("Выбросить.");

    }
}
