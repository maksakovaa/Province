#ifndef BOOKFORM_H
#define BOOKFORM_H

#include <QWidget>

namespace Ui {
class BookForm;
}

class BookForm : public QWidget
{
    Q_OBJECT

public:
    explicit BookForm(QWidget *parent = nullptr);
    ~BookForm();
    void setBook(int id, QString name, int read);
signals:
    void sigBookAct(QString action, int bookId);
private slots:
    void slotActHandler(QString action);
private:
    QString str(int id);
    void connections();
    int bookId;
    Ui::BookForm *ui;
};

#endif // BOOKFORM_H
