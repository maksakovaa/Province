#ifndef SAVEFORM_H
#define SAVEFORM_H

#include <QWidget>

namespace Ui {
class SaveForm;
}

class SaveForm : public QWidget
{
    Q_OBJECT

public:
    explicit SaveForm(QWidget *parent = nullptr);
    ~SaveForm();
    void viewSaves();
private slots:
    void saveHandler();
    void saveGame(QString savefile = "");
private:
    QWidget* root;
    int saveCounter;
    Ui::SaveForm *ui;
};

#endif // SAVEFORM_H
