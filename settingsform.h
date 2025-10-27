#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include "settings.h"
#include <QWidget>

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT
signals:
    void sigChangeSettings();
public:
    explicit SettingsForm(QWidget *parent = nullptr);
    ~SettingsForm();
    Settings* settings();
private slots:
    void on_labelCurValue_linkActivated(const QString &link);
private:
    void setupSettingsWidget();
    Settings* m_settings;
    Ui::SettingsForm *ui;
};

#endif // SETTINGSFORM_H
