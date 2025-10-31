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
    , m_time(year, month, day, 8, 0)
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
    m_player = new Player(charType, page4->settings());
    m_weather = new Weather;
    setPointers();
    slotUpdateDateTime();
    connections();
    loadStrings();
    slotUpdMoney();
    m_reproductSys.slotEstrus();
    slotUpdParams();
    setupActionButtons();
}

void MainWindow::setPointers()
{
    m_time.setSettingsPtr(page4->settings());
    m_weather->setTimePtr(&m_time);

    ui->page_0_main->setWeatherPtr(m_weather);
    ui->page_0_main->setPagePtr(ui->stackedWidget);
    ui->page_0_main->setActionsLayout(ui->actionsLayout);
    ui->page_0_main->setPlayerPtr(m_player);
    ui->page_0_main->setTimePtr(&m_time);
    ui->page_0_main->setCCSEX(&m_ccsex);

    ui->page_5_objView->setSettingsPtr(page4->settings());
    ui->page_5_objView->setActLayoutPtr(ui->actionsLayout);
    ui->page_5_objView->setPlayerPtr(m_player);
    ui->page_5_objView->setPagePtr(ui->stackedWidget);
    ui->page_5_objView->setTimeServerPtr(&m_time);

    m_reproductSys.setPlayerPtr(m_player);
    m_reproductSys.setBagPtr(m_bag);
    m_ccsex.setPlayerPtr(m_player);
    m_ccsex.setPregPtr(&m_reproductSys);
    m_ccalko.setPlayerPtr(m_player);
    ui->page_2_pers->setPtr(m_player);
    m_overlayStatus.setPlayerPtr(m_player);
    m_overlayStatus.setCCSexPtr(&m_ccsex);
    m_overlayStatus.setPregPtr(&m_reproductSys);
    m_overlayStatus.setBagPtr(m_bag);
    m_overlayStatus.setParentWidget(ui->page_0_main->getImageLblPtr());

    m_sex->setPagePtr(ui->stackedWidget);
    m_sex->setPlayerPtr(m_player);
    m_sex->setLayoutPtr(ui->actionsLayout);
    m_sex->setTimeServerPtr(&m_time);
}

void MainWindow::connections()
{
    connect(page4, &SettingsForm::sigChangeSettings, this, &MainWindow::slotUpdParams);

    connect(m_player, &Player::sigCalcAge, &m_time, &TimeServer::calcDateDiffInYears);
    connect(m_player, &Player::sigCalcRubbing, &m_ccsex, &CCSex::slotCalcRubbing);
    connect(m_player, &Player::sigVagGelTouch, &m_ccsex, &CCSex::slotVagGelTouch);
    connect(m_player, &Player::sigPregRecalc, &m_reproductSys, &Pregnancy::slotPregRecalc);
    connect(m_player, &Player::sigDataInitAlko, &m_ccalko, &CC_Alko::slotDataInitAlko);
    connect(m_player, &Player::sigHangOver, &m_ccalko, &CC_Alko::slotHangOver);
    connect(m_player, &Player::sigAlcoholism, &m_ccalko, &CC_Alko::slotAlkoholism);
    connect(m_player, &Player::sigSexCorrector, &m_ccsex, &CCSex::slotSexCorrector);
    connect(m_player, &Player::sigGetVagDamp, &m_ccsex, &CCSex::slotGetVagDamp);
    connect(m_player, &Player::sigDecRubbing, &m_ccsex, &CCSex::slotDecRubbing);

    connect(ui->page_1_map, &MapForm::ChangeLocation, ui->page_0_main, &LocationForm::slotOnChangeLocation);
    connect(ui->page_2_pers, &TabWidgetPlayer::sigUpdateStatus, this, &MainWindow::slotUpdParams);
    connect(ui->page_0_main, &LocationForm::sigIsMapAwaylable, this, &MainWindow::slotIsMapAwaylable);
    connect(ui->page_0_main, &LocationForm::sigUpdParams, this, &MainWindow::slotUpdParams);
    connect(ui->page_5_objView, &ObjViewForm::sigUpdParams, this, &MainWindow::slotUpdParams);
    connect(ui->page_5_objView, &ObjViewForm::sigSpendTime, &m_time, &TimeServer::increaseTime);

    connect(&m_ccalko, &CC_Alko::sigIncreaseRiscs, &m_reproductSys, &Pregnancy::slotIncreaseRiscs);

    connect(&m_time, &TimeServer::updateTimeAndDate, this, &MainWindow::slotUpdateDateTime);
    connect(&m_time, &TimeServer::sigElapsed10minutes, m_player, &Player::slotElapsed10min);
    connect(&m_time, &TimeServer::sigElapsed15minutes, m_player, &Player::slotElapsed15min);
    connect(&m_time, &TimeServer::sigElapsed20minutes, m_player, &Player::slotElapsed20min);
    connect(&m_time, &TimeServer::sigElapsed30minutes, m_player, &Player::slotElapsed30min);
    connect(&m_time, &TimeServer::sigElapsed60minutes, m_player, &Player::slotElapsed60min);
    connect(&m_time, &TimeServer::sigElapsedDay, m_player, &Player::slotElapsedDay);
    connect(&m_time, &TimeServer::sigElapsedDay, &m_reproductSys, &Pregnancy::slotMenstruus);
    connect(&m_time, &TimeServer::sigElapsedDay, m_weather, &Weather::mainFunc);
    connect(&m_time, &TimeServer::sigElapsedTime, m_player, &Player::slotElapsedTime);

    connect(m_sex, &SexViewForm::sigSetGape, &m_ccsex, &CCSex::slotSetGape);
    connect(m_sex, &SexViewForm::sigUpdParams, this, &MainWindow::slotUpdParams);
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
    ui->progressBarManna->setValue(m_player->getVStatus(Status::mood));
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
    ui->progressBarManna->setStyleSheet(styleForBar(ui->progressBarManna->value(),ui->progressBarManna->maximum(),0));
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
    else
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
    QString hornyStr{"возбуждение"}, lustStr{"похоть"}, healthStr{"здоровье"}, mannaStr{"настроение"},
        energyStr{"сытость"}, waterStr{"жажда"}, sonStr{"бодрость"}, vneshStr{"привлекательность"}, result;

    if(m_player->isCheatsOn())
    {
        makeLink(hornyStr, "horny");
        makeLink(lustStr, "lust");
        makeLink(healthStr, "health");
        makeLink(mannaStr, "mood");
        makeLink(energyStr, "energy");
        makeLink(waterStr, "water");
        makeLink(sonStr, "son");
    }
    result = "<html><head/><body><p style='line-height: 1.32;'>";
    result += hornyStr + "<br>" + lustStr + "<br>" + healthStr + "<br>" + mannaStr + "<br>" + energyStr + "<br>" + waterStr + "<br>" + sonStr + "<br>" + vneshStr;
    result += "</p></body></html>";
    ui->verticalLayoutBar->setAlignment(Qt::AlignTop);
    ui->verticalLayoutDesc->setAlignment(Qt::AlignTop);
    ui->labelStatusDesc->setText(result);
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
        ui->page_1_map->setMap(ui->page_1_map->genMap(ui->page_0_main->getCurPtr()->getLocIn(), ui->page_0_main->getCurPtr()->getLocId()));
        ClearLayout(ui->actionsLayout);
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        ui->page_0_main->slotOnChangeLocation(ui->page_0_main->getCurPtr()->getLocId(), 0);
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

void MainWindow::on_labelStatusDesc_linkActivated(const QString &link)
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
