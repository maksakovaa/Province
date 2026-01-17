#ifndef LOADFORM_H
#define LOADFORM_H

#include <QWidget>

namespace Ui {
class LoadForm;
}

class LoadForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoadForm(QWidget *parent = nullptr);
    ~LoadForm();
    void viewSaves();
signals:
    void load(QString file);
public slots:
    void loadSave(QString file);
private:
    int saveCounter;
    QWidget* root;
    Ui::LoadForm *ui;
};

#endif // LOADFORM_H
