#include "clothformTrash.h"
#include "ui_clothformTrash.h"

ClothFormTrash::ClothFormTrash(ClothMain *cloth, QWidget *parent) : QWidget(parent), ui(new Ui::ClothFormTrash), ptr(cloth)
{
    ui->setupUi(this);
    connect(ui->pushBtnRemove, &QPushButton::clicked, this, &ClothFormTrash::RemoveBtnClick);
    connect(ui->pushBtnToWardr, &QPushButton::clicked, this, &ClothFormTrash::WardrbBtnClick);
    ui->label->setText("<img src='" + cloth->getClothImage() + "'></img>");
    ui->label->setToolTip(cloth->getName());
    setStyleBtns();
}

ClothFormTrash::~ClothFormTrash()
{
    delete ui;
}

void ClothFormTrash::WardrbBtnClick()
{
    emit sigCloth(ptr, "toWardrobe");
}

void ClothFormTrash::RemoveBtnClick()
{
    emit sigCloth(ptr, "remove");
}

void ClothFormTrash::setStyleBtns()
{
    QString style = "QPushButton:hover { background-color: #dddddd;}";

    ui->pushBtnToWardr->setIcon(QIcon(":/img/clothing/icons/11.svg"));
    ui->pushBtnToWardr->setToolTip("В шкаф");
    ui->pushBtnToWardr->setStyleSheet(style);

    ui->pushBtnRemove->setIcon(QIcon(":/img/clothing/icons/9.svg"));
    ui->pushBtnRemove->setToolTip("Выбросить.");
    ui->pushBtnRemove->setStyleSheet(style);
}
