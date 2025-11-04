#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menudial.h"
#include <QProcess>
#include "nav/mapform.h"
#include <QDebug>
#include "Functions.h"
#include "nav/locationform.h"

MainWindow::MainWindow(SettingsForm* settingsForm, CharacterType charType, int year, int month, int day, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_time(this, year, month, day, 8, 0),
    m_overlayStatus(this)
{
    this->setStyleSheet("background-color: #ffffff; color: #464646; font-size: 16px; font-family: 'Serif';");
    ui->setupUi(this);
    setupMainWindow(settingsForm, charType);
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
    SettingsForm* settings = m.getSettingsPtr();
    CharacterType type = m.getCharType();
    QString loc = m.getStartLoc();
    int year = m.getStartYear();
    int month = m.getStartMonth();
    int day = m.getStartDay();
    auto w = new MainWindow(settings, type, year, month, day);
    w->start(loc);
    w->setAttribute(Qt::WA_DeleteOnClose);
    return w;
}

void MainWindow::start(QString loc)
{
    emit m_player->sigInitWardrobe();
    m_player->calcVneshBonus();
    ui->page_0_main->init(loc);
}

void MainWindow::setupMainWindow(SettingsForm* settingsForm, CharacterType charType)
{
    page4 = settingsForm;
    page4->setParent(this);
    if(page4->settings()->isFullScreen())
        this->showFullScreen();
    else
        this->showNormal();
    ui->stackedWidget->addWidget(page4);
    m_bag = new BagForm(this);
    ui->scrollAreaBag->setWidget(m_bag);
    m_sex = new SexViewForm(this);
    ui->scrollAreaSexView->setWidget(m_sex);
    m_obj = new ObjViewForm(this);
    ui->objViewLayout->addWidget(m_obj);
    m_player = new Player(charType, this);
    m_weather = new Weather;
    setPointers();
    slotUpdateDateTime();
    connections();
    loadStrings();
    slotUpdMoney();
    m_reproductSys.slotEstrus();
    m_time.firstStart();
    slotUpdParams();
    setupActionButtons();
}

void MainWindow::setPointers()
{
    m_weather->setTimePtr(&m_time);
    this->ui->page_0_main->setRoot(this);
    ui->page_0_main->setActionsLayout(ui->actionsLayout);
    m_obj->setActLayoutPtr(ui->actionsLayout);

    m_reproductSys.setPlayerPtr(m_player);
    m_reproductSys.setBagPtr(m_bag);
    m_ccsex.setPlayerPtr(m_player);
    m_ccsex.setPregPtr(&m_reproductSys);
    m_ccalko.setPlayerPtr(m_player);
    ui->page_2_pers->setPtr(m_player);
    m_overlayStatus.setParentWidget(ui->page_0_main->getImageLblPtr());
    m_sex->setLayoutPtr(ui->actionsLayout);
}

void MainWindow::connections()
{
    connect(page4, &SettingsForm::sigChangeSettings, this, &MainWindow::slotUpdParams);

    connect(ui->page_1_map, &MapForm::ChangeLocation, ui->page_0_main, &LocationForm::slotOnChangeLocation);
    connect(ui->page_2_pers, &TabWidgetPlayer::sigUpdateStatus, this, &MainWindow::slotUpdParams);
    connect(ui->page_0_main, &LocationForm::sigIsMapAwaylable, this, &MainWindow::slotIsMapAwaylable);
    connect(ui->page_0_main, &LocationForm::sigUpdParams, this, &MainWindow::slotUpdParams);
    connect(m_obj, &ObjViewForm::sigUpdParams, this, &MainWindow::slotUpdParams);
    connect(m_obj, &ObjViewForm::sigSpendTime, &m_time, &TimeServer::increaseTime);

    connect(&m_ccalko, &CC_Alko::sigIncreaseRiscs, &m_reproductSys, &Pregnancy::slotIncreaseRiscs);

    connect(m_sex, &SexViewForm::sigSetGape, &m_ccsex, &CCSex::slotSetGape);
    connect(m_sex, &SexViewForm::sigUpdParams, this, &MainWindow::slotUpdParams);

    connect(ui->label_energy, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_water, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_health, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_horny, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_lust, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_mood, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(ui->label_son, &QLabel::linkActivated, this, &MainWindow::slotOnStatusClick);
    connect(m_player, &Player::sigInitWardrobe, m_obj, &ObjViewForm::slotInitWardrobe);
}

void MainWindow::slotUpdateDateTime()
{
    ui->labelDate->setText(m_time.getDayOfWeek() + ", " + m_time.getDateStr());
    ui->labelTime->setText(m_time.getTime());
    ui->labelTime->setStyleSheet("font-size: 30px;");
    ui->labelImageWeather->setPixmap(m_weather->getImage());
    ui->labelTextTemperature->setText(m_weather->getCurrentTemp());
    ui->labelTextTemperature->setStyleSheet("font-size: 50px;");
}

void MainWindow::slotIsMapAwaylable(bool status)
{
    ui->pushButtonMap->setEnabled(status);
}

void MainWindow::updStatusVal(Status stat, int val)
{
    m_player->updVStatus(stat, val);
}

void MainWindow::updatePlayerStatusValue()
{
    ui->progressBarHorny->setValue(m_player->getVStatus(Status::horny));
    ui->progressBarLust->setValue(m_player->getVStatus(Status::lust));
    ui->progressBarHealth->setValue(m_player->getVStatus(Status::health));
    ui->progressBarMood->setValue(m_player->getVStatus(Status::mood));
    ui->progressBarEnergy->setValue(m_player->getVStatus(Status::energy));
    ui->progressBarWater->setValue(m_player->getVStatus(Status::water));
    ui->progressBarSon->setValue(m_player->getVStatus(Status::son));
    ui->progressBarVnesh->setValue(m_player->getVStatus(Status::vnesh));
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
    QString text = intQStr(m_player->getVStatus(Status::money));

    if(page4->settings()->isCheats())
    {
        makeLink(text, "money");
    }
    text = "<img src=':/img/icons/money.png'></img> " + text;
    ui->labelMoney->setText(text);
}

void MainWindow::slotUpdParams()
{
    if(page4->settings()->isFullScreen())
        this->showFullScreen();
    else if(this->isFullScreen())
        this->showNormal();
    updatePlayerStatusValue();
    updPlayerStatusBarStyle();
    slotUpdPlayerIcon();
    ui->page_2_pers->reload();
    m_overlayStatus.genOverlay();
    slotUpdateDateTime();
}

void MainWindow::loadStrings()
{
    QString hornyStr{"возбуждение"}, lustStr{"похоть"}, healthStr{"здоровье"}, moodStr{"настроение"},
        energyStr{"сытость"}, waterStr{"жажда"}, sonStr{"бодрость"}, vneshStr{"привлекательность"};

    if(m_player->isCheatsOn())
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
    QString style1 = "QPushButton:hover { background-color: #dddddd;}";
    ui->widget->setStyleSheet(style1);
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
    ui->widget_2->setStyleSheet(style2);
}

void MainWindow::on_pushButtonMap_clicked()
{
    if(ui->stackedWidget->currentIndex() != 1)
    {
        QString mainloc = ui->page_0_main->getCurPtr()->getLocIn();
        QString prevLoc = ui->page_0_main->getPrevPtr()->getLocId();
        ui->page_1_map->setMap(ui->page_1_map->genMap(mainloc, prevLoc, m_time.getHour()));
        ClearLayout(ui->actionsLayout);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
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
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(2);
        ClearLayout(ui->actionsLayout);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->page_0_main->reloadLocation();
    }
}

void MainWindow::on_pushButtonSettings_clicked()
{
    if(ui->stackedWidget->currentWidget() != page4)
    {
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentWidget(page4);
        ClearLayout(ui->actionsLayout);
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->page_0_main->reloadLocation();
    }
}

void MainWindow::on_pushButtonBag_clicked()
{
    if(ui->stackedWidget->currentIndex() != 3)
    {
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(3);
        ClearLayout(ui->actionsLayout);
        m_bag->fillItemList();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        ui->page_0_main->reloadLocation();
    }
}

void MainWindow::slotOnStatusClick(const QString &link)
{
    if(link == "horny")
    {
        updStatusVal(Status::horny, 5);
        if(m_player->getVStatus(horny) > 100)
        {
            m_player->setVStatus(lust, 0);
            m_player->setVStatus(horny, 0);
        }
    }
    else if (link == "lust")
    {
        updStatusVal(Status::lust, 5);
        if(m_player->getVStatus(lust) > 100)
        {
            m_player->setVStatus(lust, 5);
        }
    }
    else if (link == "health")
    {
        updStatusVal(Status::health, 5);
        if (m_player->getVStatus(health) > 100)
        {
            m_player->setVStatus(health, 5);
        }
    }
    else if (link == "mood")
    {
        updStatusVal(Status::mood, 5);
        if(m_player->getVStatus(mood) > 100)
        {
            m_player->setVStatus(mood, 0);
        }
        if (m_player->getVStatus(mood) < 0)
        {
            m_player->setVStatus(mood, 0);
        }
    }
    else if (link == "energy")
    {
        updStatusVal(Status::energy, 4);
        if (m_player->getVStatus(energy) > 24)
        {
            m_player->setVStatus(energy, 0);
        }
        if (m_player->getVStatus(energy) < 0)
        {
            m_player->setVStatus(energy, 0);
        }

    }
    else if (link == "water")
    {
        updStatusVal(Status::water, 4);
        if (m_player->getVStatus(water) > 24)
        {
            m_player->setVStatus(water, 0);
        }
    }
    else if (link == "son")
    {
        updStatusVal(Status::son, 4);

        if (m_player->getVStatus(son) > 24)
        {
            m_player->setVStatus(son, 0);
        }
    }
    updatePlayerStatusValue();
}

void MainWindow::on_labelTime_linkActivated(const QString &link)
{
    if(link == "hour")
    {
        m_time.increaseTime(60);
    }
    if(link == "minutes")
    {
        m_time.increaseTime(5);
    }
    ui->page_2_pers->reload();
    slotUpdParams();
}

void MainWindow::on_labelDate_linkActivated(const QString &link)
{
    if (link == "day")
    {
        m_time.increaseTime(24*60);
    }
    if (link == "month")
    {
        m_time.increaseTime(30*24*60);
    }
    if (link == "year")
    {
        m_time.increaseTime(12*30*24*60);
    }
    m_weather->updOnTimeMove();
    ui->page_2_pers->reload();
    slotUpdParams();
}

void MainWindow::on_labelMoney_linkActivated(const QString &link)
{
    if (link == "money")
    {
        m_player->updVStatus(Status::money, 5000);
    }
    slotUpdMoney();
}

void MainWindow::slotUpdPlayerIcon()
{
    ui->pushButtonPlayer->setIcon(m_player->getPlayerIcon());
}
