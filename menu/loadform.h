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
    void loadTimeServer(QTextStream& in);
    void loadlocPointers(QTextStream& in);
    void loadWeather(QTextStream& in);
    void loadPlayer(QTextStream& in);
    void loadEventVal(QTextStream& in);
    void loadQuestVal(QTextStream& in);
    void loadItems(QTextStream& in);
    void loadClothOnPlayer(QTextStream& in);
    void loadClothPrev(QTextStream& in);
    void loadClothWardr(QTextStream& in);
    void loadCurScreen(QTextStream& in);
    void loadButtons(QTextStream& in);
    void makeButton(std::unordered_map<QString,QString>& params);
private:
    int saveCounter;
    QWidget* root;
    Ui::LoadForm *ui;
};

#endif // LOADFORM_H
