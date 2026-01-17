#include "loadform.h"
#include "ui_loadform.h"
#include <QDir>
#include "../Functions.h"
#include "iostream"
#include "buttons.h"
#include "mainwindow.h"
#include <QDialog>
#include "../objects/wardrobe.h"
#include "ui_mainwindow.h"

LoadForm::LoadForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadForm)
{
    ui->setupUi(this);
    root = parent;
}

LoadForm::~LoadForm()
{
    delete ui;
}

void LoadForm::viewSaves()
{
    ClearLayout(ui->verticalLayout_2);
    QDir dir("savegame");
    QFileInfoList entries = dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    saveCounter = 0;
    for (const QFileInfo &entry: entries)
    {
        if(entry.isFile())
        {
            SaveBtn* btn = new SaveBtn(entry.fileName());
            btn->setText(entry.fileName());
            ui->verticalLayout_2->addWidget(btn);
            connect(btn, &SaveBtn::sigSaveClick, this, &LoadForm::loadSave);
            saveCounter++;
        }
    }
}

void LoadForm::loadSave(QString file)
{
    std::cout << "file is :" << file.toStdString() << std::endl;
    if(root == nullptr)
    {
        std::cout << "MainWindow is nullptr!\n";
        emit load(file);
        return;
    }
    else
    {
        std::cout << "MainWindow is exists!\n";
            QFile save{"savegame/" + file};
        if(!save.open(QIODevice::ReadOnly))
        {
            qDebug() << "Error opening file! " << file;
        }
        else
        {
            QTextStream in(&save);
            QString line;
            //qDebug() << "load date & time";
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                // qDebug() << line;
                line = line.trimmed();
                QStringList list = line.split(":");
                if(list[0] == "year")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_year = list[1].toInt();
                if(list[0] == "month")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_mon = list[1].toInt();
                if(list[0] == "day")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_mday = list[1].toInt();
                if(list[0] == "hour")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_hour = list[1].toInt();
                if(list[0] == "min")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_min = list[1].toInt();
                if(list[0] == "sec")
                    ((MainWindow*)root)->m_time.currTimePoint.tm_sec = list[1].toInt();
            }
            line = "";
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                // qDebug() << line;
                line = line.trimmed();
                QStringList list = line.split(":");
                if(list[0] == "year")
                    ((MainWindow*)root)->m_time.oldTime.tm_year = list[1].toInt();
                if(list[0] == "month")
                    ((MainWindow*)root)->m_time.oldTime.tm_mon = list[1].toInt();
                if(list[0] == "day")
                    ((MainWindow*)root)->m_time.oldTime.tm_mday = list[1].toInt();
                if(list[0] == "hour")
                    ((MainWindow*)root)->m_time.oldTime.tm_hour = list[1].toInt();
                if(list[0] == "min")
                    ((MainWindow*)root)->m_time.oldTime.tm_min = list[1].toInt();
                if(list[0] == "sec")
                    ((MainWindow*)root)->m_time.oldTime.tm_sec = list[1].toInt();
            }
            line = "";
            // qDebug() << "load locations";
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                // qDebug() << line;
                line = line.trimmed();
                QStringList list = line.split(":");
                if(list[0] == "current_loc")
                {
                    ((MainWindow*)root)->locHandler->m_current = ((MainWindow*)root)->locHandler->m_locations[static_cast<LocId>(list[1].toInt())];
                }
                if(list[0] == "prev_loc")
                {
                    if(list[1] != "-1")
                        ((MainWindow*)root)->locHandler->m_prev = ((MainWindow*)root)->locHandler->m_locations[static_cast<LocId>(list[1].toInt())];
                    else
                        ((MainWindow*)root)->locHandler->m_prev = nullptr;
                }
            }
            line = "";
            //load weather params
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_weather->m_weather[static_cast<WeatherVar>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load birthDate
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                if(list[0] == "year")
                    ((MainWindow*)root)->m_player->m_birthDate.tm_year = list[1].toInt();
                if(list[0] == "month")
                    ((MainWindow*)root)->m_player->m_birthDate.tm_mon = list[1].toInt();
                if(list[0] == "day")
                    ((MainWindow*)root)->m_player->m_birthDate.tm_mday = list[1].toInt();
            }
            line = "";
            //load body params
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_body[static_cast<Body>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load skills
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_skills[static_cast<Skills>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load status
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_status[static_cast<Status>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load sex
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_sex[static_cast<SexVar>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load preg
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_preg[static_cast<PregVar>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load statistic
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_statistic[static_cast<SC>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            // load addict
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_addict[static_cast<Addiction>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load sick
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_sick[static_cast<Sickness>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load job
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_player->m_job[static_cast<JobStatus>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load school var
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->locHandler->m_events->m_schoolVal[static_cast<SchoolVar>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load event params
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->locHandler->m_events->m_eventval[static_cast<EventParams>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load quest params
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->locHandler->m_events->m_questval[static_cast<QuestParams>(list[0].toInt())] = list[1].toInt();
            }
            line = "";
            //load bag items
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                ((MainWindow*)root)->m_bag->m_storage[((MainWindow*)root)->m_bag->m_items[static_cast<Items>(list[0].toInt())]] = list[1].toInt();
            }
            line = "";

            qDebug() << "load cloth on player";
            std::unordered_map<QString,QString> clothes;
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                qDebug() << line;
                line = line.trimmed();
                QStringList list = line.split(":");
                clothes[list[0]] = list[1];
            }
            for (const auto&[key,value] : clothes)
            {
                qDebug() << "Key: " << key << " Value: " << value;
            }
            ClothMain* ptr = nullptr;
            if(clothes["group"] != "0")
            {
                ptr = new ClothMain(clothes["id"].toInt(), static_cast<ClothGroup>(clothes["group"].toInt()), clothes["name"],clothes["price"].toInt(),clothes["condition"].toInt());
                ptr->setSize(clothes["size"].toInt());
            }
            ((MainWindow*)root)->m_player->m_clothSLots[ClothType::Main] = ptr;
            clothes.clear();
            line = "";

            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                clothes[list[0]] = list[1];
            }
            ClothPanties* ptr2 = nullptr;
            if(clothes["condition"] != "no")
            {
                ptr2 = new ClothPanties(ClothType::Panties,clothes["price"].toInt(),clothes["condition"].toInt());
            }
            ((MainWindow*)root)->m_player->m_clothSLots[ClothType::Panties] = ptr2;
            line = "";


            // load prev cloth
            clothes.clear();

            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split(":");
                clothes[list[0]] = list[1];
            }
            ClothMain* prevptr = nullptr;
            if(clothes["group"] != "0")
            {
                prevptr = new ClothMain(clothes["id"].toInt(), static_cast<ClothGroup>(clothes["group"].toInt()), clothes["name"],clothes["price"].toInt(),clothes["condition"].toInt());
                prevptr->setSize(clothes["size"].toInt());
            }
            ((MainWindow*)root)->m_player->m_prevCloth[ClothType::Main] = prevptr;
            clothes.clear();
            line = "";
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                qDebug() << line;
                line = line.trimmed();
                QStringList list = line.split(":");
                clothes[list[0]] = list[1];
            }
            ClothPanties* prevptr2 = nullptr;
            if(clothes["condition"] != "no")
            {
                prevptr2 = new ClothPanties(ClothType::Panties,clothes["price"].toInt(),clothes["condition"].toInt());
            }
            ((MainWindow*)root)->m_player->m_prevCloth[ClothType::Panties] = prevptr2;
            clothes.clear();

            //qDebug() << "load wardrobe clothes";
            line = "";
            while (line != "}")
            {
                while (line != "    }")
                {
                    line = in.readLine();
                    if(line == "    }" || line == "    {" || line == "{" || line == "}")
                        continue;
                    line = line.trimmed();
                    QStringList list = line.split(":");
                    clothes[list[0]] = list[1];
                }
                if(clothes["cloth_type"] == "1" && clothes["count"] != "0")
                {
                    if(ptr2 != nullptr)
                        ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[ptr2] = clothes["count"].toInt();
                    else if(prevptr2 != nullptr)
                        ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[prevptr2] = clothes["count"].toInt();
                    else
                        ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[new ClothPanties(ClothType::Panties)] = clothes["count"].toInt();

                }
                else if(clothes["cloth_type"] == "0" && clothes["count"] != "0")
                {
                    ClothMain* ptrX = new ClothMain(clothes["id"].toInt(), static_cast<ClothGroup>(clothes["group"].toInt()),clothes["name"],clothes["price"].toInt(),clothes["condition"].toInt());
                    ptrX->setSize(clothes["size"].toInt());
                    ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[ptrX] = clothes["count"].toInt();
                }
                clothes.clear();
                line = in.readLine();
            }
            line = "";

            ((MainWindow*)root)->ui->stackedWidget->setCurrentIndex(0);
            QString video = "";
            QString image = "";
            int width = 0;
            int height = 0;
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                
                line = line.trimmed();
                QStringList list = line.split(":");
                if(list[0] == "video")
                    video = list[1];
                else if(list[0] == "image")
                    image = list[1];
                else if(list[0] == "width")
                    width = list[1].toInt();
                else if(list[0] == "height")
                    height = list[1].toInt();
            }
            if(image.isEmpty())
            {
                // qDebug() << "loading" << video;
                ((MainWindow*)root)->pageRender->rendVideoPage(this);
                ((MainWindow*)root)->pageRender->setVideo(video,width,height);
            }
            else
            {
                // qDebug() << "loading" << image;
                ((MainWindow*)root)->pageRender->rendImagePage(this);
                ((MainWindow*)root)->pageRender->imageLbl->setText(image);
            }
            line = "";
            QString text;
            while (line != "}")
            {
                line = in.readLine();
                if(line == "{" || line == "}")
                    continue;
                line = line.trimmed();
                QStringList list = line.split("|");
                text = list[1];
            }
            ((MainWindow*)root)->pageRender->setText(text);
            ((MainWindow*)root)->adjustSize();
            ((MainWindow*)root)->slotUpdParams();
        }
    }
}


