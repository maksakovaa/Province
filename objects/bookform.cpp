#include "bookform.h"
#include "ui_bookform.h"
#include "../Functions.h"

BookForm::BookForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BookForm)
{
    ui->setupUi(this);
    connections();
}

BookForm::~BookForm()
{
    delete ui;
}

void BookForm::setBook(int id, QString name, int read)
{
    bookId = id;
    ui->labelBookLink->setText("<a href ='read'>" + name + "</a>" + "(" + intQStr(id) + ")");
    ui->labelImage->setText("<img width=150 src='data/img/items/books/" + intQStr(id) + ".jpg'></img>");
    ui->labelPutInBag->setText(str(2));
    ui->labelSaleBook->setText(str(3));
    if(read/20 == 0)
        ui->labelPagesRead->setText(intQStr(read*20) +  str(0));
    else
        ui->labelPagesRead->setText(str(1));
}

void BookForm::slotActHandler(QString action)
{
    emit sigBookAct(action, bookId);
}

QString BookForm::str(int id)
{
    QString str[4];
    str[0] = "страниц прочтено";
    str[1] = "(Уже прочтена)";
    str[2] = "<a href='putInBag'>Положить в сумочку</a>";
    str[3] = "<a href='sale'>Продать за 300 руб</a>";
    return str[id];
}

void BookForm::connections()
{
    connect(ui->labelBookLink, &QLabel::linkActivated, this, &BookForm::slotActHandler);
    connect(ui->labelPutInBag, &QLabel::linkActivated, this, &BookForm::slotActHandler);
    connect(ui->labelSaleBook, &QLabel::linkActivated, this, &BookForm::slotActHandler);
}
