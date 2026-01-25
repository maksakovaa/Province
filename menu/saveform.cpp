#include "saveform.h"
#include "ui_saveform.h"
#include "mainwindow.h"
#include "../objects/wardrobe.h"
#include "../Functions.h"
#include <QDir>
#include "buttons.h"
#include "../render.h"
#include "ui_mainwindow.h"

SaveForm::SaveForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SaveForm)
{
    ui->setupUi(this);
    root = parent;
}

SaveForm::~SaveForm()
{
    delete ui;
}

void SaveForm::viewSaves()
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
            saveCounter++;
            connect(btn, &SaveBtn::sigSaveClick,this,&SaveForm::saveGame);
        }
    }
    QPushButton* btn = new QPushButton;
    btn->setText("New save");
    connect(btn, &QPushButton::clicked, this, &SaveForm::saveHandler);
    ui->verticalLayout_2->addWidget(btn);
}

void SaveForm::saveGame(QString savefile)
{

    QFile file;
    if(savefile.isEmpty())
    {
        file.setFileName("savegame/save" + intQStr(saveCounter + 1));
    }
    else
    {
        file.setFileName("savegame/" + savefile);
    }
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Error opening file! ";
    }
    else
    {
        QTextStream out(&file);
        //save date & time
        out << "{\n";
        out << "    year:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_year << "\n";
        out << "    month:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_mon << "\n";
        out << "    day:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_mday << "\n";
        out << "    hour:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_hour << "\n";
        out << "    min:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_min << "\n";
        out << "    sec:" << ((MainWindow*)root)->m_game->m_time.currTimePoint.tm_sec << "\n";
        out << "}\n";

        out << "{\n";
        out << "    year:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_year << "\n";
        out << "    month:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_mon << "\n";
        out << "    day:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_mday << "\n";
        out << "    hour:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_hour << "\n";
        out << "    min:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_min << "\n";
        out << "    sec:" << ((MainWindow*)root)->m_game->m_time.oldTime.tm_sec << "\n";
        out << "}\n";

        //save current location
        out << "{\n";
        out << "    current_loc:" << ((MainWindow*)root)->m_game->m_locs->m_current->getLocId() << "\n";
        //save prev location
        out << "    prev_loc:";
        if(((MainWindow*)root)->m_game->m_locs->m_prev != nullptr)
        {
            out << ((MainWindow*)root)->m_game->m_locs->m_prev->getLocId() << "\n";
        }
        else
            out << -1 << "\n";
        out << "}\n";
        
        //save weather params
        out << "{\n";
        for (int i = sunWeather; i <= snow; ++i)
        {
            out << "    " + intQStr(i) + ":" << ((MainWindow*)root)->m_game->m_weather->m_weather[static_cast<WeatherVar>(i)] << "\n";
        }
        out << "}\n";
        //save player
        //save bithDate
        out << "{\n";
        out << "    year:" << ((MainWindow*)root)->m_game->m_player->m_birthDate.tm_year << "\n";
        out << "    month:" << ((MainWindow*)root)->m_game->m_player->m_birthDate.tm_mon << "\n";
        out << "    day:" << ((MainWindow*)root)->m_game->m_player->m_birthDate.tm_mday << "\n";
        out << "}\n";
        // save body params
        out << "{\n";
        for (int i = bodyGroup; i <= glass; ++i)
        {
            out << "    " + intQStr(i) + ":" << ((MainWindow*)root)->m_game->m_player->m_body[static_cast<Body>(i)] << "\n";
        }
        out << "}\n";
        //save skills
        out << "{\n";
        for (int i = strenght; i <= posSkill; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_skills[static_cast<Skills>(i)] << "\n";
        }
        out << "}\n";
        // save status params
        out << "{\n";
        for (int i = shamelessFlag; i <= vnesh; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_status[static_cast<Status>(i)] << "\n";
        }
        out << "}\n";
        // save sex params
        out << "{\n";
        for (int i = protect; i <= spanked; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_sex[static_cast<SexVar>(i)] << "\n";
        }
        out << "}\n";
        // save preg params
        out << "{\n";
        for (int i = status_mc_vagina; i <= estrus; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_preg[static_cast<PregVar>(i)] << "\n";
        }
        out << "}\n";
        // save statictics
        out << "{\n";
        for (int i = piss; i <= newGobelen; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_statistic[static_cast<SC>(i)] << "\n";
        }
        out << "}\n";
        // save addict params
        out << "{\n";
        for (int i = alko; i <= drugStatus; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_addict[static_cast<Addiction>(i)] << "\n";
        }
        out << "}\n";
        // save sickness params
        out << "{\n";
        for (int i = sick; i <= Kandidoz; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_sick[static_cast<Sickness>(i)] << "\n";
        }
        out << "}\n";
        // save job params
        out << "{\n";
        for (int i = workout; i <= last_job; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_player->m_job[static_cast<JobStatus>(i)] << "\n";
        }
        out << "}\n";
        //save School var
        out << "{\n";
        for (int i = lesson_count; i <= certificate_gift; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_events->m_schoolVal[static_cast<SchoolVar>(i)] << "\n";
        }
        out << "}\n";
        //save event params
        out << "{\n";
        for (int i = grandpa_ingadsarai; i <= lastEventParam; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_events->m_eventval[static_cast<EventParams>(i)] << "\n";
        }
        out << "}\n";
        //save quest params
        out << "{\n";
        for (int i = qwPodezdWhore; i <= lastQW; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_game->m_events->m_questval[static_cast<QuestParams>(i)] << "\n";
        }
        out << "}\n";
        // save bag items
        out << "{\n";
        for (int i = iFood; i <= iFatBurners; ++i)
        {
            out << "    " + intQStr(i) + ":"  << ((MainWindow*)root)->m_bag->m_storage[((MainWindow*)root)->m_bag->m_items[static_cast<Items>(i)]] << "\n";
        }
        out << "}\n";
        // save clothes on player
        out << "{\n";
        if(((MainWindow*)root)->m_game->m_player->m_clothSLots[ClothType::Main] != nullptr)
        {
            ClothMain* ptr = (ClothMain*)((MainWindow*)root)->m_game->m_player->m_clothSLots[ClothType::Main];
            out << "    cloth_type:" << ptr->getClothType() << "\n";
            out << "    group:" << ptr->getClothGroup() << "\n";
            out << "    id:" << ptr->getId() << "\n";
            out << "    size:" << ptr->getSize() << "\n";
            out << "    condition:" << ptr->getCondition() << "\n";
            out << "    name:" << ptr->getName() << "\n";
            out << "    price:" << ptr->getPrice() << "\n";
        }
        else
        {
            out << "    cloth_type:" << ClothType::Main << "\n";
            out << "    group:" << ClothGroup::nude << "\n";
        }
        out << "}\n";
        out << "{\n";
        if(((MainWindow*)root)->m_game->m_player->m_clothSLots[ClothType::Panties] != nullptr)
        {
            ClothPanties* ptr = (ClothPanties*)((MainWindow*)root)->m_game->m_player->m_clothSLots[ClothType::Panties];
            out << "    cloth_type:" << ptr->getClothType()  << "\n";
            out << "    price:" << ptr->getPrice() << "\n";
            out << "    condition:" << ptr->getCondition() << "\n";
        }
        else
        {
            out << "    cloth_type:" << ClothType::Panties << "\n";
            out << "    condition:" << "no" << "\n";
        }
        out << "}\n";
        // save prev clothes
        out << "{\n";
        if(((MainWindow*)root)->m_game->m_player->m_prevCloth[ClothType::Main] != nullptr)
        {
            ClothMain* ptr = (ClothMain*)((MainWindow*)root)->m_game->m_player->m_prevCloth[ClothType::Main];
            out << "    cloth_type:" << ptr->getClothType() << "\n";
            out << "    group:" << ptr->getClothGroup() << "\n";
            out << "    id:" << ptr->getId() << "\n";
            out << "    size:" << ptr->getSize() << "\n";
            out << "    condition:" << ptr->getCondition() << "\n";
            out << "    name:" << ptr->getName() << "\n";
            out << "    price:" << ptr->getPrice() << "\n";
        }
        else
        {
            out << "    cloth_type:" << ClothType::Main << "\n";
            out << "    group:" << ClothGroup::nude << "\n";
        }
        out << "}\n";
        out << "{\n";
        if(((MainWindow*)root)->m_game->m_player->m_prevCloth[ClothType::Panties] != nullptr)
        {
            ClothPanties* ptr = (ClothPanties*)((MainWindow*)root)->m_game->m_player->m_prevCloth[ClothType::Panties];
            out << "    cloth_type:" << ptr->getClothType()  << "\n";
            out << "    price:" << ptr->getPrice() << "\n";
            out << "    condition:" << ptr->getCondition() << "\n";
        }
        else
        {
            out << "    cloth_type:" << ClothType::Panties << "\n";
            out << "    condition:" << "no" << "\n";
        }
        out << "}\n";
        // save clothes in wardrobe:
        out << "{\n";
        for (const auto&[key, value] : ((MainWindow*)root)->m_game->m_objs->m_wardrobe->m_storage)
        {
            out << "    {\n";
            out << "        cloth_type:" << key->getClothType() << "\n";
            if(key->getClothType() == ClothType::Main)
            {
                out << "        group:" << ((ClothMain*)key)->getClothGroup() << "\n";
                out << "        id:" << ((ClothMain*)key)->getId() << "\n";
                out << "        size:" << ((ClothMain*)key)->getSize() << "\n";
                out << "        condition:" << ((ClothMain*)key)->getCondition() << "\n";
                out << "        name:" << ((ClothMain*)key)->getName() << "\n";
                out << "        price:" << ((ClothMain*)key)->getPrice() << "\n";
                out << "        count:" << value << "\n";
            }
            else if(key->getClothType() == ClothType::Panties)
            {
                out << "        count:" << value << "\n";
            }
            out << "    }\n";
        }
        out << "}\n";
        //save window state: current page, image/video, text, action buttons
        out << "{\n";
        out << "    currentpage:" << ((MainWindow*)root)->m_render->curpage << "\n";
        out << "}\n";

        out << "{\n";
        if(((MainWindow*)root)->m_render->curpage == 1)
        {
            out << "    video:" << ((MainWindow*)root)->m_render->m_vplayer->source().toString() << "\n";
            QSize vidSize = ((MainWindow*)root)->m_render->m_video->sizeHint();
            out << "    width:" << vidSize.width() << "\n";
            out << "    height:" << vidSize.height() << "\n";
        }
        else if(((MainWindow*)root)->m_render->curpage == 0)
        {
            out << "    image:" << ((MainWindow*)root)->m_render->imageLbl->text() << "\n";
        }
        out << "}\n";
        if(((MainWindow*)root)->m_render->curpage == 1 || ((MainWindow*)root)->m_render->curpage == 0)
        {
            out << "{\n";
            out << "    text|" << ((MainWindow*)root)->m_render->textLbl->text() << "\n";
            out << "}\n";
        }
        //Save buttons!
        out << "{\n";
        for (int i = 0; i < ((MainWindow*)root)->Layoutitems.size(); ++i)
        {
            QWidget* widget = ((MainWindow*)root)->Layoutitems[i]->widget();
            if(widget && widget->inherits("QPushButton"))
            {
                QActButton* type1 = qobject_cast<QActButton*>(widget);
                BedActionButton* type4 = qobject_cast<BedActionButton*>(widget);
                MirrActionButton* type5 = qobject_cast<MirrActionButton*>(widget);
                WardrActionButton* type6 = qobject_cast<WardrActionButton*>(widget);
                if(type1)
                {
                    qDebug() << "found QActButton!" << type1->text();
                    out << "    {\n";
                    out << "        buttonType:" << 1 << "\n";
                    out << "        buttonText:" << type1->text() << "\n";
                    out << "        action:" << type1->m_action << "\n";
                    out << "        handler:" << type1->m_handler << "\n";
                    out << "    }\n";
                }
                else if(type4)
                {
                    qDebug() << "found BedActionButton";
                }
                else if(type5)
                {
                    qDebug() << "found MirrActButton!";
                }
                else if(type6)
                {
                    qDebug() << "found WardrActButton!";
                }
            }
        }
        out << "}\n";
    }
    file.close();
    viewSaves();
}

void SaveForm::saveHandler()
{
    saveGame();
}
