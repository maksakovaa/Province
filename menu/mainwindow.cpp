#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menudial.h"
#include <QProcess>
#include "../map/mapform.h"
#include <QDebug>
#include "../Functions.h"


MainWindow::MainWindow(SettingsForm* settingsForm, int year, int month, int day, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_savePage(this), m_loadPage(this)
{
    this->setStyleSheet("background-color: #ffffff; color: #464646; font-size: 16px; font-family: 'Serif';");
    ui->setupUi(this);
    m_render = new Render(this);
    m_game = new Game(this, year, month, day, 8, 0);
    setupMainWindow(settingsForm);
    m_que = new NotificationQueue(ui->centralwidget);
}

MainWindow::MainWindow(SettingsForm *settingsForm, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_savePage(this),m_loadPage(this)
{
    this->setStyleSheet("background-color: #ffffff; color: #464646; font-size: 16px; font-family: 'Serif';");
    ui->setupUi(this);
    m_render = new Render(this);
    m_game = new Game(this);
    setupMainWindow(settingsForm);
    m_que = new NotificationQueue(ui->centralwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow *MainWindow::createMenu()
{
    MenuDial m;
    auto result = m.exec();
    if(result == QDialog::Rejected)
    {
        return nullptr;
    }
    else if (result == QDialog::Accepted)
    {
        SettingsForm* settings = m.getSettingsPtr();
        CharacterType type = m.getCharType();
        QString loc = m.getStartLoc();
        int year = m.getStartYear();
        int month = m.getStartMonth();
        int day = m.getStartDay();
        auto w = new MainWindow(settings, year, month, day);
        w->start(loc, type);
        w->setAttribute(Qt::WA_DeleteOnClose);
        return w;   
    }
    else
    {
        SettingsForm* settings = m.getSettingsPtr();
        auto w = new MainWindow(settings);
        w->m_loadPage.loadSave(m.getSave());
        w->setAttribute(Qt::WA_DeleteOnClose);
        return w;
    }
}

void MainWindow::start(QString loc, CharacterType charType)
{
    m_game->newGame(loc, charType);
}

void MainWindow::setupMainWindow(SettingsForm* settingsForm)
{
    m_settings = settingsForm;
    m_settings->setParent(this);
    if(m_settings->settings()->isFullScreen())
        this->showFullScreen();
    else
        this->showNormal();
    ui->stackedWidget->addWidget(m_settings);
    m_overlayStatus = new OverlayStatus(this,ui->scrollArea);
    m_bag = new BagForm(this);
    ui->scrollAreaBag->setWidget(m_bag);
    ui->page_2_pers->setPtr(m_game);
    connect(ui->page_1_map, SIGNAL(ChangeLocation(QString name,int min)), m_game->m_locs, SLOT(slotChangeLoc(QString name,int min)));
    connections();
    setupActionButtons();;
    loadStrings();
    ui->stackedWidget->addWidget(&m_savePage);
    ui->stackedWidget->addWidget(&m_loadPage);
    this->adjustSize();
}

void MainWindow::connections()
{
    connect(m_settings, &SettingsForm::sigChangeSettings, this, &MainWindow::slotUpdParams);
    connect(ui->page_2_pers, &TabWidgetPlayer::sigUpdateStatus, this, &MainWindow::slotUpdParams);
    // connect(&m_ccalko, &CC_Alko::sigIncreaseRiscs, &m_reproductSys, &Pregnancy::slotIncreaseRiscs);
    connect(ui->label_energy, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_water, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_health, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_horny, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_lust, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_mood, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_son, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
}

void MainWindow::slotUpdateDateTime()
{
    ui->labelDate->setText(m_game->m_time.getDayOfWeek() + ", " + m_game->m_time.getDateStr());
    ui->labelTime->setText(m_game->m_time.getTime());
    ui->labelTime->setStyleSheet("font-size: 30px;");
    ui->labelImageWeather->setPixmap(m_game->m_weather->getImage());
    ui->labelTextTemperature->setText(m_game->m_weather->getCurrentTemp());
    ui->labelTextTemperature->setStyleSheet("font-size: 50px;");
}

void MainWindow::slotIsMapAwaylable(bool status)
{
    ui->pushButtonMap->setEnabled(status);
}

void MainWindow::updStatusVal(Status stat, int val)
{
    m_game->m_player->vStatus(stat) += val;
}

void MainWindow::updatePlayerStatusValue()
{
    ui->progressBarHorny->setValue(m_game->m_player->vStatus(Status::horny));
    ui->progressBarLust->setValue(m_game->m_player->vStatus(Status::lust));
    ui->progressBarHealth->setValue(m_game->m_player->vStatus(Status::health));
    ui->progressBarMood->setValue(m_game->m_player->vStatus(Status::mood));
    ui->progressBarEnergy->setValue(m_game->m_player->vStatus(Status::energy));
    ui->progressBarWater->setValue(m_game->m_player->vStatus(Status::water));
    ui->progressBarSon->setValue(m_game->m_player->vStatus(Status::son));
    ui->progressBarVnesh->setValue(m_game->m_player->vStatus(Status::vnesh));
}

void MainWindow::updPlayerStatusBarStyle()
{
    ui->progressBarHorny->setStyleSheet(styleForBar(ui->progressBarHorny->value(),ui->progressBarHorny->maximum(),1));
    ui->progressBarLust->setStyleSheet(styleForBar(ui->progressBarLust->value(),ui->progressBarLust->maximum(),1));
    ui->progressBarHealth->setStyleSheet(styleForBar(ui->progressBarHealth->value(),ui->progressBarHealth->maximum(),0));
    ui->progressBarMood->setStyleSheet(styleForBar(ui->progressBarMood->value(),ui->progressBarMood->maximum(),0));
    ui->progressBarEnergy->setStyleSheet(styleForBar(ui->progressBarEnergy->value(),ui->progressBarEnergy->maximum(),0));
    ui->progressBarWater->setStyleSheet(styleForBar(ui->progressBarWater->value(),ui->progressBarWater->maximum(),0));
    ui->progressBarSon->setStyleSheet(styleForBar(ui->progressBarSon->value(),ui->progressBarSon->maximum(),0));
    ui->progressBarVnesh->setStyleSheet(styleForBar(ui->progressBarVnesh->value(),ui->progressBarVnesh->maximum(),2));
}

void MainWindow::slotUpdMoney()
{
    QString text = intQStr(m_game->m_player->vStatus(Status::money));

    if(m_settings->settings()->isCheats())
    {
        makeLink(text, "money");
    }
    text = "<img src='data/img/icons/money.png'></img> " + text;
    ui->labelMoney->setText(text);
}

void MainWindow::slotUpdParams()
{
    if(m_settings->settings()->isFullScreen())
        this->showFullScreen();
    else if(this->isFullScreen())
        this->showNormal();
    updatePlayerStatusValue();
    updPlayerStatusBarStyle();
    slotUpdPlayerIcon();
    ui->page_2_pers->reload();
    m_overlayStatus->genOverlay();
    slotUpdateDateTime();
    slotUpdMoney();
}

void MainWindow::showNotif(QString text)
{
    m_que->push(text);
}

void MainWindow::loadStrings()
{
    QString hornyStr{"возбуждение"}, lustStr{"похоть"}, healthStr{"здоровье"}, moodStr{"настроение"},
        energyStr{"сытость"}, waterStr{"жажда"}, sonStr{"бодрость"}, vneshStr{"привлекательность"};

    if(m_settings->isCheats())
    {
        makeLink(hornyStr, "horny");
        makeLink(lustStr, "lust");
        makeLink(healthStr, "health");
        makeLink(moodStr, "mood");
        makeLink(energyStr, "energy");
        makeLink(waterStr, "water");
        makeLink(sonStr, "son");
    }
    ui->label_horny->setText(hornyStr);
    ui->label_lust->setText(lustStr);
    ui->label_health->setText(healthStr);
    ui->label_mood->setText(moodStr);
    ui->label_son->setText(sonStr);
    ui->label_water->setText(waterStr);
    ui->label_energy->setText(energyStr);
    ui->label_vnesh->setText(vneshStr);
}

void MainWindow::setupActionButtons()
{
    QString style1 = "QFrame#frame {border: 1px solid gray}"
                     "QPushButton:hover { background-color: #dddddd;}";
    ui->frame->setStyleSheet(style1);
    ui->pushButtonBag->setCursor(Qt::PointingHandCursor);
    ui->pushButtonLoad->setCursor(Qt::PointingHandCursor);
    ui->pushButtonMap->setCursor(Qt::PointingHandCursor);
    ui->pushButtonPlayer->setCursor(Qt::PointingHandCursor);
    ui->pushButtonRestart->setCursor(Qt::PointingHandCursor);
    ui->pushButtonSave->setCursor(Qt::PointingHandCursor);
    ui->pushButtonSettings->setCursor(Qt::PointingHandCursor);

    QString style2 = "QPushButton { background-color: #eeeeee;"
        "border: none;"
        "border-radius: 5px;"
        "color: #1874A4;"
        "font-size: 14px;"
        "font-family: 'Serif';"
        "padding: 3px 3px;"
        "text-align: left;"
        "background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #eeeeee, stop:1 #ffffff);}"
        "QPushButton:hover { background-color: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #efefef, stop:1 #dddddd);}";
    ui->widgetActions->setStyleSheet(style2);
}

void MainWindow::saveActions()
{
    if(ui->actionsLayout->isEmpty())
        return;
    QLayoutItem* item;
    while (item = ui->actionsLayout->takeAt(0))
    {
        Layoutitems.push_back(std::move(item));
    }
}

void MainWindow::reloadActions()
{
    for (int i = 0; i < Layoutitems.size(); i++)
    {
        ui->actionsLayout->addItem(Layoutitems[i]);
    }
    Layoutitems.clear();
}

void MainWindow::on_pushButtonMap_clicked()
{
    if(ui->stackedWidget->currentIndex() != 1)
    {
        saveActions();
        LocId mainloc = m_game->m_locs->getMainLoc();
        LocId prevLoc = m_game->m_locs->getPrevLoc();
        ui->page_1_map->setMap(ui->page_1_map->genMap(mainloc, prevLoc, m_game->m_time.getHour()));
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}

void MainWindow::on_pushButtonRestart_clicked()
{
    QString program = qApp->applicationFilePath();
    QStringList arguments = qApp->arguments().mid(1); // Exclude the program path itself

    qApp->quit(); // Exit the current application instance
    QProcess::startDetached(program, arguments); // Launch a new instance
}

void MainWindow::on_pushButtonPlayer_clicked()
{
    if(ui->stackedWidget->currentIndex() != 2)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(2);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}

void MainWindow::on_pushButtonSettings_clicked()
{
    if(ui->stackedWidget->currentWidget() != m_settings)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentWidget(m_settings);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}

void MainWindow::on_pushButtonBag_clicked()
{
    if(ui->stackedWidget->currentIndex() != 3)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(3);
        m_bag->fillItemList();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}

void MainWindow::slotOnStatusClick(const QString &link)
{
    if(link == "horny")
    {
        updStatusVal(Status::horny, 5);
        if(m_game->m_player->vStatus(horny) > 100)
        {
            m_game->m_player->vStatus(lust) = 0;
            m_game->m_player->vStatus(horny) = 0;
        }
    }
    else if (link == "lust")
    {
        updStatusVal(Status::lust, 5);
        if(m_game->m_player->vStatus(lust) > 100)
        {
            m_game->m_player->vStatus(lust) = 5;
        }
    }
    else if (link == "health")
    {
        updStatusVal(Status::health, 5);
        if (m_game->m_player->vStatus(health) > 100)
        {
            m_game->m_player->vStatus(health) = 5;
        }
    }
    else if (link == "mood")
    {
        updStatusVal(Status::mood, 5);
        if(m_game->m_player->vStatus(mood) > 100)
        {
            m_game->m_player->vStatus(mood) = 0;
        }
        if (m_game->m_player->vStatus(mood) < 0)
        {
            m_game->m_player->vStatus(mood) = 0;
        }
    }
    else if (link == "energy")
    {
        updStatusVal(Status::energy, 4);
        if (m_game->m_player->vStatus(energy) > 24)
        {
            m_game->m_player->vStatus(energy) = 0;
        }
        if (m_game->m_player->vStatus(energy) < 0)
        {
            m_game->m_player->vStatus(energy) = 0;
        }

    }
    else if (link == "water")
    {
        updStatusVal(Status::water, 4);
        if (m_game->m_player->vStatus(water) > 24)
        {
            m_game->m_player->vStatus(water) = 0;
        }
    }
    else if (link == "son")
    {
        updStatusVal(Status::son, 4);

        if (m_game->m_player->vStatus(son) > 24)
        {
            m_game->m_player->vStatus(son) = 0;
        }
    }
    updatePlayerStatusValue();
}

void MainWindow::on_labelTime_linkActivated(const QString &link)
{
    if(link == "hour")
    {
        m_game->m_time.increaseTime(60);
    }
    if(link == "minutes")
    {
        m_game->m_time.increaseTime(5);
    }
    ui->page_2_pers->reload();
    slotUpdParams();
}

void MainWindow::on_labelDate_linkActivated(const QString &link)
{
    if (link == "day")
    {
        m_game->m_time.increaseTime(24*60);
    }
    if (link == "month")
    {
        m_game->m_time.increaseTime(30*24*60);
    }
    if (link == "year")
    {
        m_game->m_time.increaseTime(12*30*24*60);
    }
    m_game->m_weather->updOnTimeMove();
    ui->page_2_pers->reload();
    slotUpdParams();
}

void MainWindow::on_labelMoney_linkActivated(const QString &link)
{
    if (link == "money")
    {
        m_game->m_player->vStatus(Status::money) += 5000;
    }
    slotUpdMoney();
}

void MainWindow::slotUpdPlayerIcon()
{
    ui->pushButtonPlayer->setIcon(m_game->m_player->getPlayerIcon());
}

void MainWindow::on_pushButtonSave_clicked()
{
    if(ui->stackedWidget->currentIndex() != 5)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(5);
        ClearLayout(ui->actionsLayout);
        m_savePage.viewSaves();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}


void MainWindow::on_pushButtonLoad_clicked()
{
    if(ui->stackedWidget->currentIndex() != 6)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(6);
        ClearLayout(ui->actionsLayout);
        m_loadPage.viewSaves();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}


void MainWindow::on_pushButton_clicked()
{
    m_game->m_npc->rendNpcProfile(dimaNosov);
    m_game->setTime(23,00);
}

