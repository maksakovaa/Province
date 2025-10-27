#include "menudial.h"
#include "ui_menudial.h"
#include "Functions.h"
#include <QMediaFormat>

MenuDial::MenuDial(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuDial)
{
    ui->setupUi(this);
    ui->menuStackedWidget->setCurrentIndex(0);
    fillLegend();
    videoWidg = new Video(ui->widget_2);
    videoWidg->setFixedSize(900,600);
    videoWidg->setQUrl("qrc:/img/start/" + QString::number(getRandInt(4,5)) + ".webm");
    ui->verticalLayout_5->addWidget(videoWidg);
    ui->verticalLayout_5->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

MenuDial::~MenuDial()
{
    delete ui;
}

CharacterType MenuDial::getCharType()
{
    return playerType;
}

SettingsForm *MenuDial::getSettingsPtr()
{
    return ui->page_2_settings;
}

QString MenuDial::getStartLoc()
{
    return m_loc;
}

int MenuDial::getStartYear()
{
    return year;
}

int MenuDial::getStartMonth()
{
    return month;
}

int MenuDial::getStartDay()
{
    return day;
}

void MenuDial::on_pbExitGame_clicked()
{
    reject();
}


void MenuDial::on_pbLoadGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MenuDial::on_pbNewGame_clicked()
{
    ui->menuStackedWidget->setCurrentIndex(1);
}

void MenuDial::fillLegend()
{
    QString persons = "<table style=\"width: 630; align: center;\">";
    persons +="<th><p><span style=\"font-size:14pt;\">" + getStr(12) + "</span></p></th>";
    persons += "<tr>";
    persons += "<td><p><img src=\":/img/start/nerd.jpg\"/></p><p><a href=\"nerd\"><span style=\" font-size:14pt; font-weight:700; color:#000000;\">" + getStr(0) + "</span></a><br/>" + getStr(1) + "</p></td>";
    persons += "<td><p><img src=\":/img/start/schoolgirl.jpg\"/></p><p><a href=\"schoolgirl\"><span style=\" font-size:14pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(2) + "</span></a><br/>" + getStr(3) + "</p></td>";
    persons += "<td><p><img src=\":/img/start/dancer.jpg\"/></p><p><a href=\"dancer\"><span style=\" font-size:14pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(4) + "</span></a><br/>" + getStr(5) + "</p></td>";
    persons += "</tr>";
    persons += "<tr>";
    persons += "<td><p><img src=\":/img/start/sportgirl.jpg\"/></p><p><a href=\"sportgirl\"><span style=\" font-size:14pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(6) + "</span></a><br/>" + getStr(7) + "</p></td>";
    persons += "<td><p><img src=\":/img/start/playgirl.jpg\"/></p><p><a href=\"playgirl\"><span style=\" font-size:14pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(8) + "</span></a><br/>" + getStr(9) + "</p></td>";
    persons += "<td><p><img src=\":/img/start/frivolous.jpg\"/></p><p><a href=\"frivolous\"><span style=\" font-size:14pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(10) + "</span></a><br/>" + getStr(11) + "</p></td>";
    persons += "</tr>";
    persons += "</table>";
    ui->labelPersons->setText(persons);
    ui->labelPersons->setStyleSheet("background-color: #eeeeee; color: #000000;");


    QString txt = "<img src=':/img/start/start1.jpg'></img><br>";
    txt += "<a href='start1'><span style=\" font-size:30pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(21) + "</span></a><br>";
    txt += getStr(23) +" 01.06.2015";
    ui->labelPavlovo1->setText(txt);
    ui->labelPavlovo1->setStyleSheet("color: #000000; background-color: #eeeeee;");

    QString txt2 = "<img src=':/img/start/start3.jpg'></img><br>";
    txt2 += "<a href='start2'><span style=\" font-size:30pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(21) + "</span></a><br>";
    txt2 += getStr(23) +" 29.08.2015";
    ui->labelPavlovo2->setText(txt2);
    ui->labelPavlovo2->setStyleSheet("color: #000000; background-color: #eeeeee;");

    QString txt3 = "<img src=':/img/start/start2.jpg'></img><br>";
    txt3 += "<a href='start3'><span style=\" font-size:30pt; font-weight:700; text-decoration: underline; color:#000000;\">" + getStr(22) + "</span></a><br>";
    txt3 += getStr(23) +" 01.06.2015";
    ui->labelGadukino->setText(txt3);
    ui->labelGadukino->setStyleSheet("color: #000000; background-color: #eeeeee;");
    connect(ui->labelPavlovo1, &QLabel::linkActivated, this, &MenuDial::slotStart);
    connect(ui->labelPavlovo2, &QLabel::linkActivated, this, &MenuDial::slotStart);
    connect(ui->labelGadukino, &QLabel::linkActivated, this, &MenuDial::slotStart);
}

QString MenuDial::getStr(int id)
{
    QString begin_str[26];
    begin_str[0] = "Эмо";
    begin_str[1] = "Бонус за чтение<br>Девушка в теле<br>Штраф к общению<br>Очки";
    begin_str[2] = "Ботанка";
    begin_str[3] = "Бонус к успеваемости<br>Хрупкое телосложение<br>Штраф к общению<br>Очки";
    begin_str[4] = "Творческая";
    begin_str[5] = "Навык танцев<br>Навык вокала<br>Причёска";
    begin_str[6] = "Спортсменка";
    begin_str[7] = "Членство в спортсекциях<br>Спортивное телосложение<br>Бонус к доминантности";
    begin_str[8] = "Пацанка";
    begin_str[9] = "Бонус в отношения<br>Бонус к доминантности<br>Цветные линзы";
    begin_str[10] = "Беспечная";
    begin_str[11] = "Бонус к танцам<br>Бонус к красоте и фигуре<br>Причёска";
    begin_str[12] = "Выберите персонажа:";
    begin_str[13] = "С детства вы были инфантильной девицей, вечной эльфой, витающей в облаках средь книжных миров. Персонажи фэнтези и выдуманные вселенные заменили вам реальных людей и обычный, бренный мир. Чтением посажено зрение. Учёба тоже хромает: вы слишком увлечены выдуманными мирами, чтобы обращать внимание на жалкий скучный Мидгард.";
    begin_str[14] = "Вы рано научились читать, и книги заменили вам всё: когда сверстницы играли во дворе в \"резиночку\", вы сажали зрение, просиживая за \"умными книжками\" целыми днями. Одноклассники с первых классов просят списать, но сторонятся \"очкастой заучки\".";
    begin_str[15] = "С детства в вас проявилась творческая жилка: на любом утреннике ещё с детсада вы всегда пели и танцевали; в школе вы всегда участвовали во всевозможных постановках, уже тогда всерьёз подумывая о профессиональной карьере в шоу-бизнесе. Благо, хороший голос и слух позволяют на это надеяться. Но заниматься профессионально танцами и вокалом в Павлово негде: а ездить постоянно в город, где такая возможно есть, дорого и долго. Родители, помявшись, в своё время вам отказали: \"Не потянем, прости!\". Секция спортивных танцев в ДК вам уже неинтересна: вы сами можете там преподавать.";
    begin_str[16] = "Вы с детства занимались спортом. Свободного времени почти не оставалось: тренировки, режим и ещё раз тренировки. На учёбе это отразилось не в лучшую сторону, вы лишь кое-как учитесь на тройки-четвёрки, но по физкультуре у вас неизменная \"пятёрка\". Жёсткий режим не дал возможности завести подруг-друзей, но зато вашей поджарой атлетичной фигуре завидуют все девчонки, хоть некоторые и хихикают втихаря, боясь сказать в лицо: \"баба-конь\"!";
    begin_str[17] = "Учились вы всегда неважно, но зато были бессменной \"королевой Камчатки\" - задних парт в классе - и \"заводилой\". С вами стремятся дружить все: вы легко общаетесь как со школьной гопотой - \"Она ж свой пацан, хоть и девка!\" - так и умудряетесь находить общий язык с ботанами с первых парт (списывать они вам всегда дают). Вы всегда можете \"разрулить вопрос\" так, что и волки сыты, и овцы целы.";
    begin_str[18] = "Учились с двойки на тройку, ибо вы любили погулять. Вы не пропускали ни одну тусовоку и дискотеку. Благодаря врожденной красоте вам удавалось не скатиться на двойки, парни вам всегда давали списывать \"домашку\". С вами стремятся дружить все парни, а девчёнки завидуют - \"Вон идёт школьная принцесса!\", учителя - мужчины, заглядваются на вас, но в целях дружбы...";
    begin_str[19] = "Назад";
    begin_str[20] = "Начать";
    begin_str[21] = "Павлово";
    begin_str[22] = "Гадюкино";
    begin_str[23] = "Старт";
    begin_str[24] = "Выберите время и место начала игры:";
    begin_str[25] = "китайский пуховик";

    return begin_str[id];
}

void MenuDial::on_label_back_btn_linkActivated(const QString &link)
{
    ui->menuStackedWidget->setCurrentIndex(1);
}


void MenuDial::on_label_next_btn_linkActivated(const QString &link)
{
    ui->menuStackedWidget->setCurrentIndex(3);
}


void MenuDial::on_labelPersons_linkActivated(const QString &link)
{
    QString desc;
    if(link == "nerd")
    {
        playerType = CharacterType::nerd;
        desc = getStr(13);
    }
    else if (link == "schoolgirl")
    {
        playerType = CharacterType::schoolgirl;
        desc = getStr(14);
    }
    else if (link == "dancer")
    {
        playerType = CharacterType::dancer;
        desc = getStr(15);
    }
    else if (link == "sportgirl")
    {
        playerType = CharacterType::sportgirl;
        desc = getStr(16);
    }
    else if (link == "playgirl")
    {
        playerType = CharacterType::playgirl;
        desc = getStr(17);
    }
    else if (link == "frivolous")
    {
        playerType = CharacterType::frivolous;
        desc = getStr(18);
    }
    ui->label_image->setPixmap(QPixmap(":/img/start/" + link + "_big.jpg"));
    ui->textBrowserDesc->setText(desc);
    ui->textBrowserDesc->setStyleSheet("background-color: rgb(211, 211, 211); color: #000000;");
    ui->menuStackedWidget->setCurrentIndex(2);
}


void MenuDial::on_pbSettings_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MenuDial::slotStart(const QString &link)
{
    if(link == "start1")
    {
        m_loc = "parents_home";
        year = 2015;
        month = 6;
        day = 1;
    }
    else if(link=="start2")
    {
        m_loc = "parents_home";
        year = 2015;
        month = 8;
        day = 29;
    }
    else if(link=="start3")
    {
        m_loc = "gaddvor";
        year = 2015;
        month = 6;
        day = 1;
    }
    accept();
}

