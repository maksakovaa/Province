#include "sexviewform.h"
#include "ui_sexviewform.h"
#include "Functions.h"

SexViewForm::SexViewForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SexViewForm)
{
    ui->setupUi(this);
    m_selfplay = new SelfPlay(this);
    ui->labelSexDesc->setWordWrap(true);
}

SexViewForm::~SexViewForm()
{
    delete ui;
}

void SexViewForm::setPagePtr(QStackedWidget *ptr)
{
    m_page = ptr;
    m_loc = (LocationForm*)m_page->widget(0);
    m_bag = m_page->widget(3)->findChild<BagForm*>("BagForm");;
}

void SexViewForm::setPlayerPtr(Player *ptr)
{
    m_player = ptr;
}

void SexViewForm::setLayoutPtr(QVBoxLayout *ptr)
{
    m_actLayout = ptr;
}

void SexViewForm::setTimeServerPtr(TimeServer *ptr)
{
    m_time = ptr;
}

void SexViewForm::selfPlayStart(Location *current)
{
    m_selfplay->start(current);
}

void SexViewForm::clearLayout()
{
    ClearLayout(m_actLayout);
}

SexActionButton::SexActionButton(SelfPlayActs act, QString actName)
{
    connect(this, &SexActionButton::clicked, this, &SexActionButton::handleButtonClick);
    this->setText(actName);
    m_action = act;
}

void SexActionButton::handleButtonClick()
{
    emit sigAction(m_action);
}
