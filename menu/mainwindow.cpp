#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menudial.h"
#include <QProcess>
#include "../map/mapform.h"
#include <QDebug>
#include "Functions.h"


MainWindow::MainWindow(SettingsForm* settingsForm, int year, int month, int day, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_time(this, year, month, day, 8, 0),
    m_ccalko(this),
    m_reproductSys(this),
    m_ccsex(this),
    savePage(this), loadPage(this)
{
    this->setStyleSheet("background-color: #ffffff; color: #464646; font-size: 16px; font-family: 'Serif';");
    ui->setupUi(this);
    setupMainWindow(settingsForm);
    m_que = new NotificationQueue(ui->centralwidget);
}

MainWindow::MainWindow(SettingsForm *settingsForm, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_time(this),
    m_ccalko(this),
    m_reproductSys(this),
    m_ccsex(this),
    savePage(this),loadPage(this)
{
    this->setStyleSheet("background-color: #ffffff; color: #464646; font-size: 16px; font-family: 'Serif';");
    ui->setupUi(this);
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
        w->loadPage.loadSave(m.getSave());
        w->setAttribute(Qt::WA_DeleteOnClose);
        return w;
    }
}

void MainWindow::start(QString loc, CharacterType charType)
{
    m_player->newPlayer(charType);
    emit m_player->sigInitWardrobe();
    m_player->calcVneshBonus();
    m_reproductSys.slotEstrus();
    m_time.firstStart();
    slotUpdParams();
    if(loc == "gaddvor")
        locHandler->slotChangeLoc(lgaddvor,0);
    else if(loc == "parents_home")
        locHandler->slotChangeLoc(lbedrpar2,0);
    initNpc();
}

void MainWindow::setupMainWindow(SettingsForm* settingsForm)
{
    page4 = settingsForm;
    page4->setParent(this);
    if(page4->settings()->isFullScreen())
        this->showFullScreen();
    else
        this->showNormal();
    ui->stackedWidget->addWidget(page4);
    m_overlayStatus = new OverlayStatus(this,ui->scrollArea);
    m_bag = new BagForm(this);
    ui->scrollAreaBag->setWidget(m_bag);
    m_player = new Player(this);
    m_weather = new Weather(this);
    pageRender = new Render(this);
    locHandler = new LocationHandler(pageRender,this,ui->actionsLayout);
    ui->page_2_pers->setPtr(m_player,locHandler);
    connect(ui->page_1_map, SIGNAL(ChangeLocation(QString name,int min)), locHandler, SLOT(slotChangeLoc(QString name,int min)));
    objHandler = new ObjectHandler(pageRender,this,ui->actionsLayout);
    connect(m_player, &Player::sigInitWardrobe, objHandler, &ObjectHandler::slotInitWardrobe);
    sexHandler = new SexHandler(pageRender,this,ui->actionsLayout);
    
    connections();
    setupActionButtons();;
    loadStrings();
    ui->stackedWidget->addWidget(&savePage);
    ui->stackedWidget->addWidget(&loadPage);
    this->adjustSize();
}

void MainWindow::connections()
{
    connect(page4, &SettingsForm::sigChangeSettings, this, &MainWindow::slotUpdParams);
    connect(ui->page_2_pers, &TabWidgetPlayer::sigUpdateStatus, this, &MainWindow::slotUpdParams);
    connect(&m_ccalko, &CC_Alko::sigIncreaseRiscs, &m_reproductSys, &Pregnancy::slotIncreaseRiscs);
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
    text = "<img src='data/img/icons/money.png'></img> " + text;
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

    if(page4->isCheats())
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

void MainWindow::initNpc()
{
    npcs.push_back(NPC{"","","",0,-1,0,0,0,0}); //0
    //1-5
    npcs.push_back(NPC{"Дима","Носов","",40,3, genDick(),0,1,1});
    npcs.push_back(NPC{"Артём","Чеботарёв","",40,1,genDick(),0,0,1});
    npcs.push_back(NPC {"Иван", "Прохоров", "", 40,2,genDick(),0,2,1});
    npcs.push_back(NPC{"Игорь","Круглов","",40,3,genDick(16),0,0,1});
    npcs.push_back(NPC{"Фёдор", "Козлов","",40,2,genDick(),0,0,1});
    //6-10
    npcs.push_back(NPC{"Петя","Клюев","",40,1,genDick(),0,0,1});
    npcs.push_back(NPC{"Алексей","Князев","Лошик",40,0,genDick(),0,0,1});
    npcs.push_back(NPC{"Святослав","Воинов","Свят",40,2,genDick(),0,0,1});
    npcs.push_back(NPC{"Витёк","Котов","Кот",40,4,genDick(),0,2,1});
    npcs.push_back(NPC{"Денис","Рыжов","Дэн",40,4,genDick(),0,0,1});
    //11-15
    npcs.push_back(NPC{"Вася","Шульгин","Васян",40,4,genDick(),0,0,1});
    npcs.push_back(NPC{"Юля","Милова","",40,1,0,0,0,1});
    npcs.push_back(NPC{"Лариска","Груздева","",40,2,0,0,0,1});
    npcs.push_back(NPC{"Катя","Мейнольд","",40,3,0,0,0,1});
    npcs.push_back(NPC{"Вика","Мейнольд","Рыжик",40,3,0,0,0,1});
    //16-20
    npcs.push_back(NPC{"Наташа","Белова","",40,1,0,0,0,1});
    npcs.push_back(NPC{"Инна","Девятова","Девятка",40,3,0,0,0,1});
    npcs.push_back(NPC{"Кристинв","Зверева","",40,2,0,0,0,1});
    npcs.push_back(NPC{"Лина","Старова","",40,2,0,0,0,1});
    npcs.push_back(NPC{"Лена","Котова","",40,4,0,0,0,1});
    //21-25
    npcs.push_back(NPC{"Лера", "Царева", "",40,4,0,0,0,1});
    npcs.push_back(NPC{"Бэлла", "Артамонова", "Белка",40,2,0,0,0,1});
    npcs.push_back(NPC{"Альбина", "Барловская", "",40,3,0,0,1});
    npcs.push_back(NPC{"Полина", "Себаготулина", "",40,4,0,0,1});
    npcs.push_back(NPC{"Соня", "Иванько","",40,0,0,0,0,1});
    //26-30
    npcs.push_back(NPC{"Анатолий Евгеньевич", "Царёв", "Онотоле",40,6,genDick(),0,1,1});
    npcs.push_back(NPC{"Александр", "Лобов", "Рекс",40,6,genDick(),0,1,0});
    npcs.push_back(NPC{"Михаил Николаевич", "Власов", "",40,6,genDick(),0,2,0});
    npcs.push_back(NPC{"Вера", "Царева", "",40,6,0,0,0,0});
    npcs.push_back(NPC{"Евгения", "Долина", "Женя",40,8,genDick(),0,1,0});
    //31-35
    npcs.push_back(NPC{"Татьяна", "Агузарова", "Таня",40,8,0,0,0,0});
    npcs.push_back(NPC{"Пётр", "Кироров", "Питер",40,8,0,0,2,0});
    npcs.push_back(NPC{"Катя", "","\"Кэт\"",40,8,0,0,0,0});
    npcs.push_back(NPC{"Гиви Карапетович", "", "Карпетыч",40,8,genDick(28),0,2,0});
    npcs.push_back(NPC{"Владимир", "Скрябин", "Отчим",40,5,genDick(28),0,1,1});
    //36-40
    npcs.push_back(NPC{"Сергей", "Шульгин","",40,9,genDick(28),0,2,1});
    npcs.push_back(NPC{"Наталья", "Лебедева", "Мать",40,5,0,0,0,1});
    npcs.push_back(NPC{"Аня", "Лебедева", "Сестра",40,5,0,0,0,1});
    npcs.push_back(NPC{"Николай", "Скрябин", "Колька",40,5,genDick(21),0,0,1});
    npcs.push_back(NPC{"Артур","","",40,9,30,0,2,0});
    //41-45
    npcs.push_back(NPC{"Алексей", "Каталкин", "Катала",40,9,genDick(18),0,1,0});
    npcs.push_back(NPC{"Михаил Александрович", "Гробов", "дядя Миша",40,9,genDick(26),0,1,1});
    npcs.push_back(NPC{"","","",0,-1,0,0,0,0}); //EMPTY SLOT
    npcs.push_back(NPC{"Ирина", "Пугач","",40,8,0,0,0,0});
    npcs.push_back(NPC{"Тамара Михайловна", "Мейнольд","",40,9,0,0,0,0});
    //46-50
    npcs.push_back(NPC{"Ашот", "", "", 40,8,genDick(26),0,2,0});
    npcs.push_back(NPC{"Демаркус", "" ,"Марки", 40,8,genDick(31),1,0});
    npcs.push_back(NPC{"Миша", "", "",40,9,genDick(),0,2,0});
    npcs.push_back(NPC{"Айгуль","","",40,10,0,0,0,0});
    npcs.push_back(NPC{"Вероника", "" ,"Ника", 40,10,0,0,0,0});
    //50-53
    npcs.push_back(NPC{"Наташа","","",50,10,0,0,0,0});
    npcs.push_back(NPC{"Алексей Николаевич", "Гергин","",5,8,genDick(),0,1,0});
    npcs.push_back(NPC{"Кристина", "Николаева","",5,8,0,0,0,0});

    for(int i = 0; i <= 199; i++)
    {
        boyfriends.push_back(genRandboyfriend(i));
    }
}

NPCboyfriend MainWindow::genRandboyfriend(int i)
{
    QStringList lst = QString("Саша,Леша,Коля,Петя,Вася,Гоша,Миша,Дэн,Паша,Гена,Дима,Славик,Виталик,Валера,Ваня,Серега,Андрей").split(',');
    NPCboyfriend boy;
    boy.name = lst[getRandInt(0,lst.size() - 1)];
    boy.surname = "";
    boy.nickname = "";
    boy.relation = 40;
    if(i < 100)
        boy.group = 6;
    else
        boy.group = 8;
    boy.dick = getRandInt(12,18);
    boy.sex = 0;
    boy.know = 0;
    boy.silavag = getRandInt(0,2);
    boy.meet_day = 0;
    boy.boyfriend = 0;
    boy.boy_type = static_cast<BoyType>(getRandInt(0,2));
    if(boy.boy_type == tgopnik)
        boy.boy_character = static_cast<BoyChar>(getRandInt(1,2));
    else
        boy.boy_character = static_cast<BoyChar>(getRandInt(0,2));

    if(getRandInt(0,100) > 80) boy.izvrat = true;
    else boy.izvrat = false;

    boy.boy_beauty = getRandInt(40+boy.boy_type*10,60+boy.boy_type*10);
    boy.boy_haircolor = getRandInt(0,3);
    boy.boy_tits = getRandInt(0,6);
    boy.boy_body = getRandInt(0,4);
    return boy;
}

void MainWindow::on_pushButtonMap_clicked()
{
    if(ui->stackedWidget->currentIndex() != 1)
    {
        saveActions();
        LocId mainloc = locHandler->getMainLoc();
        LocId prevLoc = locHandler->getPrevLoc();
        ui->page_1_map->setMap(ui->page_1_map->genMap(mainloc, prevLoc, m_time.getHour()));
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
    if(ui->stackedWidget->currentWidget() != page4)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentWidget(page4);
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

void MainWindow::on_pushButtonSave_clicked()
{
    if(ui->stackedWidget->currentIndex() != 5)
    {
        saveActions();
        ui->pushButtonMap->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(5);
        ClearLayout(ui->actionsLayout);
        savePage.viewSaves();
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
        loadPage.viewSaves();
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(0);
        reloadActions();
    }
}

