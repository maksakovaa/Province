#include "sexviewform.h"
#include "../mainwindow.h"
#include "../ui_mainwindow.h"
#include "ui_sexviewform.h"
#include "Functions.h"

SexViewForm::SexViewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SexViewForm)
{
    root = parent;
    ui->setupUi(this);
    m_selfplay = new SelfPlay(this);
    m_sex = new Sex(this);
    ui->labelSexDesc->setWordWrap(true);
}

SexViewForm::~SexViewForm()
{
    delete ui;
}

void SexViewForm::setLayoutPtr(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

void SexViewForm::selfPlayStart()
{
    ((MainWindow*)root)->prevPage = 5;
    m_selfplay->start();
    connect(this, &SexViewForm::sigReload, m_selfplay, &SelfPlay::reloadActions);
}

void SexViewForm::reloadActions()
{
    emit sigReload();
}

void SexViewForm::clearLayout()
{
    ClearLayout(m_actLayout);
}

SexActionButton::SexActionButton(SelfPlayActs act, QString actName)
{
    this->setCursor(Qt::PointingHandCursor);
    connect(this, &SexActionButton::clicked, this, &SexActionButton::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void SexActionButton::handleButtonClick()
{
    emit sigAction(m_action);
}

int SexViewForm::getSexVar(SexVar param)
{
    return ((MainWindow*)root)->m_player->getVSexVar(param);
}

int SexViewForm::getVStatus(Status param)
{
    return ((MainWindow*)root)->m_player->getVStatus(param);
}

int SexViewForm::getVBody(Body param)
{
    return ((MainWindow*)root)->m_player->getVBody(param);
}

int SexViewForm::getItemCount(Items item)
{
    return ((MainWindow*)root)->m_bag->getQuantityof(item);
}

int SexViewForm::getVAddict(Addiction param)
{
    return ((MainWindow*)root)->m_player->getVAddict(param);
}

int SexViewForm::getBSC(SC param)
{
    return ((MainWindow*)root)->m_player->getStatisticsValue(param);
}

void SexViewForm::setSexVar(SexVar param, int value)
{
    ((MainWindow*)root)->m_player->setVSexVar(param, value);
}

void SexViewForm::updSexVar(SexVar param, int value)
{
    ((MainWindow*)root)->m_player->updVSexVar(param,value);
}

void SexViewForm::setVStatus(Status param, int value)
{
    ((MainWindow*)root)->m_player->setVStatus(param, value);
}

void SexViewForm::updVStatus(Status param, int value)
{
    ((MainWindow*)root)->m_player->updVStatus(param,value);
}

void SexViewForm::updVSC(SC param, int val)
{
    ((MainWindow*)root)->m_player->updVStatistic(param,val);
}

void SexViewForm::updVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->updVBody(param,val);
}

void SexViewForm::useItem(Items item, int count)
{
    ((MainWindow*)root)->m_bag->useItem(item, count);
}

void SexViewForm::setVBody(Body param, int val)
{
    ((MainWindow*)root)->m_player->setVBody(param,val);
}

void SexViewForm::incTime(int min)
{
    ((MainWindow*)root)->m_time.increaseTime(min);
}

void SexViewForm::setMainWidgetpage(int page)
{
    ((MainWindow*)root)->ui->stackedWidget->setCurrentIndex(page);
}

void SexViewForm::changeLoc(Location *loc)
{
    ((MainWindow*)root)->ui->page_0_main->slotChangeLoc(loc,1);
}

Location *SexViewForm::getCurLoc()
{
    return ((MainWindow*)root)->ui->page_0_main->getCurPtr();
}
