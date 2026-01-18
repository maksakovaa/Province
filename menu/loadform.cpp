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
#include "../nav/location_headers.h"
#include "../events/EventHeaders.h"

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
            loadTimeServer(in);
            loadlocPointers(in);
            loadWeather(in);
            loadPlayer(in);
            loadEventVal(in);
            loadQuestVal(in);
            loadItems(in);
            loadClothOnPlayer(in);
            loadClothPrev(in);
            loadClothWardr(in);
            loadCurScreen(in);
            loadButtons(in);
            ((MainWindow*)root)->adjustSize();
            ((MainWindow*)root)->slotUpdParams();
            ((MainWindow*)root)->locHandler->checkMapAwailable();
        }
    }
}

void LoadForm::loadTimeServer(QTextStream &in)
{
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
}

void LoadForm::loadlocPointers(QTextStream &in)
{
    QString line;
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
}

void LoadForm::loadWeather(QTextStream& in)
{
    QString line;
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
}

void LoadForm::loadPlayer(QTextStream& in)
{
    QString line;
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
}

void LoadForm::loadEventVal(QTextStream& in)
{
    QString line;
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
}

void LoadForm::loadQuestVal(QTextStream& in)
{
    QString line;
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
}

void LoadForm::loadItems(QTextStream& in)
{
    QString line;
    while (line != "}")
    {
        line = in.readLine();
        if(line == "{" || line == "}")
            continue;
        line = line.trimmed();
        QStringList list = line.split(":");
        ((MainWindow*)root)->m_bag->m_storage[((MainWindow*)root)->m_bag->m_items[static_cast<Items>(list[0].toInt())]] = list[1].toInt();
    }
}

void LoadForm::loadClothOnPlayer(QTextStream &in)
{
    QString line;
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
}

void LoadForm::loadClothPrev(QTextStream &in)
{
    QString line;
    std::unordered_map<QString,QString> clothes;
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
}

void LoadForm::loadClothWardr(QTextStream &in)
{
    QString line;
    std::unordered_map<QString,QString> clothes;
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
            if(((MainWindow*)root)->m_player->m_clothSLots[ClothType::Panties] != nullptr)
                ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[((MainWindow*)root)->m_player->m_clothSLots[ClothType::Panties]] = clothes["count"].toInt();
            else if(((MainWindow*)root)->m_player->m_prevCloth[ClothType::Panties] != nullptr)
                ((MainWindow*)root)->objHandler->m_wardrobe->m_storage[((MainWindow*)root)->m_player->m_prevCloth[ClothType::Panties]] = clothes["count"].toInt();
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
}

void LoadForm::loadCurScreen(QTextStream& in)
{
    QString line;
    ((MainWindow*)root)->ui->stackedWidget->setCurrentIndex(0);
    int cur_page = -1;
    while (line != "}")
    {
        line = in.readLine();
        if(line == "{" || line == "}")
            continue;
        line = line.trimmed();
        QStringList list = line.split(":");
        if(list[0] == "currentpage")
            cur_page = list[1].toInt();
    }
    line = "";
    if(cur_page == 0)
    {
        QString image = "";
        while (line != "}")
        {
            line = in.readLine();
            if(line == "{" || line == "}")
                continue;
            line = line.trimmed();
            QStringList list = line.split(":");
            if(list[0] == "image")
                image = list[1];
        }
        // qDebug() << "loading" << image;
        ((MainWindow*)root)->pageRender->rendImagePage(this);
        ((MainWindow*)root)->pageRender->imageLbl->setText(image);
    }
    if(cur_page == 1)
    {
        QString video = "";
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
            else if(list[0] == "width")
                width = list[1].toInt();
            else if(list[0] == "height")
                height = list[1].toInt();
        }
        // qDebug() << "loading" << video;
        ((MainWindow*)root)->pageRender->rendVideoPage(this);
        ((MainWindow*)root)->pageRender->setVideo(video,width,height);
    }
    line = "";
    if(cur_page == 0 || cur_page == 1)
    {
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
    }
}

void LoadForm::loadButtons(QTextStream& in)
{
    QString line;
    std::unordered_map<QString,QString> params;

    while (line != "}")
    {
        while (line != "    }")
        {
            line = in.readLine();
            if(line == "    }" || line == "    {" || line == "{" || line == "}")
                continue;
            line = line.trimmed();
            QStringList list = line.split(":");
            params[list[0]] = list[1];
        }
        makeButton(params);
        params.clear();
        line = in.readLine();
    }
}

void LoadForm::makeButton(std::unordered_map<QString, QString>& params)
{
    if(params["handler"] == "beach")
    {
        ((MainWindow*)root)->locHandler->m_beach->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "common")
    {
        ((MainWindow*)root)->locHandler->m_common->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadbana")
    {
        Gadbana* ptr = (Gadbana*)((MainWindow*)root)->locHandler->m_locations[lgadbana];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadbeach")
    {
        Gadbeach* ptr = (Gadbeach*)((MainWindow*)root)->locHandler->m_locations[lgadbeach];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gaddvor")
    {
        Gaddvor* ptr = (Gaddvor*)((MainWindow*)root)->locHandler->m_locations[lgaddvor];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadgarden")
    {
        Gadgarden* ptr = (Gadgarden*)((MainWindow*)root)->locHandler->m_locations[lgadgarden];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadhouse")
    {
        Gadhouse* ptr = (Gadhouse*)((MainWindow*)root)->locHandler->m_locations[lgadhouse];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadmarket")
    {
        Gadmarket* ptr = (Gadmarket*)((MainWindow*)root)->locHandler->m_locations[lgadmarket];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadriver")
    {
        Gadriver* ptr = (Gadriver*)((MainWindow*)root)->locHandler->m_locations[lgadriver];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadroad")
    {
        Gadroad* ptr = (Gadroad*)((MainWindow*)root)->locHandler->m_locations[lgadroad];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadsarai")
    {
        Gadsarai* ptr = (Gadsarai*)((MainWindow*)root)->locHandler->m_locations[lgadsarai];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadukino")
    {
        Gadukino* ptr = (Gadukino*)((MainWindow*)root)->locHandler->m_locations[lgadukino];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "kitchActs")
    {
        ((MainWindow*)root)->locHandler->m_kitchenActs->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "shop")
    {
        Shop* ptr = (Shop*)((MainWindow*)root)->locHandler->m_locations[lshop];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "backwater")
    {
        Backwater* ptr = (Backwater*)((MainWindow*)root)->locHandler->m_locations[lbackwater];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadfield")
    {
        Gadfield* ptr = (Gadfield*)((MainWindow*)root)->locHandler->m_locations[lgadfield];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "mirahome")
    {
        MiroslavaHome* ptr = (MiroslavaHome*)((MainWindow*)root)->locHandler->m_locations[lmirahome];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadforestswamp")
    {
        GadForestSwamp* ptr = (GadForestSwamp*)((MainWindow*)root)->locHandler->m_locations[lgadforestswamp];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadforest")
    {
        Gadforest* ptr = (Gadforest*)((MainWindow*)root)->locHandler->m_locations[lgadforest];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "meadow")
    {
        Meadow* ptr = (Meadow*)((MainWindow*)root)->locHandler->m_locations[lmeadow];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadukinoevents")
    {
        GadukinoEvent* ptr = (GadukinoEvent*)((MainWindow*)root)->locHandler->m_events->m_events[eGadukinoEvents];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "swampspring")
    {
        SwampSpring* ptr = (SwampSpring*)((MainWindow*)root)->locHandler->m_locations[lswampspring];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "swampyard")
    {
        SwampYard* ptr = (SwampYard*)((MainWindow*)root)->locHandler->m_locations[lswampyard];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "swamphouse")
    {
        SwampHouse* ptr = (SwampHouse*)((MainWindow*)root)->locHandler->m_locations[lswamphouse];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "swamp")
    {
        Swamp* ptr = (Swamp*)((MainWindow*)root)->locHandler->m_locations[lswamp];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "gadforestevent")
    {
        GadforestEvent* ptr = (GadforestEvent*)((MainWindow*)root)->locHandler->m_events->m_events[eGadForestEvent];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "korrparr")
    {
        korrPar* ptr = (korrPar*)((MainWindow*)root)->locHandler->m_locations[lkorrpar];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "miroslava")
    {
        Miroslava* ptr = (Miroslava*)((MainWindow*)root)->locHandler->m_events->m_events[eMiroslava];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "mitka")
    {
        Mitka* ptr = (Mitka*)((MainWindow*)root)->locHandler->m_events->m_events[eMitka];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "riverevents")
    {
        RiverEvents* ptr = (RiverEvents*)((MainWindow*)root)->locHandler->m_events->m_events[eRiverEvents];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "mitkasex")
    {
        MitkaSex* ptr = (MitkaSex*)((MainWindow*)root)->locHandler->m_events->m_events[eMitkaSex];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "AndreiHanter")
    {
        AndreiHanter* ptr = (AndreiHanter*)((MainWindow*)root)->locHandler->m_events->m_events[eAndreiHanter];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "swampevents")
    {
        SwampEvents* ptr = (SwampEvents*)((MainWindow*)root)->locHandler->m_events->m_events[eSwampEvents];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "bicycle")
    {
        Bicycle* ptr = (Bicycle*)((MainWindow*)root)->locHandler->m_events->m_events[eBicycle];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "grandpa")
    {
        Grandpa* ptr = (Grandpa*)((MainWindow*)root)->locHandler->m_events->m_events[eGrandPa];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "GadforestLost")
    {
        GadforestLost* ptr = (GadforestLost*)((MainWindow*)root)->locHandler->m_events->m_events[eGadForestLost];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "pirat")
    {
        Pirat* ptr = (Pirat*)((MainWindow*)root)->locHandler->m_events->m_events[ePirat];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "grandma")
    {
        Grandma* ptr = (Grandma*)((MainWindow*)root)->locHandler->m_events->m_events[eGrandMa];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "GadforestRelax")
    {
        GadforestRelax* ptr = (GadforestRelax*)((MainWindow*)root)->locHandler->m_events->m_events[eGadForestRelax];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "GrandmaHelp")
    {
        GrandmaHelp* ptr = (GrandmaHelp*)((MainWindow*)root)->locHandler->m_events->m_events[eGrandMaHelp];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "GrandpaHelp")
    {
        GrandpaHelp* ptr = (GrandpaHelp*)((MainWindow*)root)->locHandler->m_events->m_events[eGrandPaHelp];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "GrandparentsEvents")
    {
        GrandparentsEvents* ptr = (GrandparentsEvents*)((MainWindow*)root)->locHandler->m_events->m_events[eGrandParentEvents];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "HanterSex")
    {
        HanterSex* ptr = (HanterSex*)((MainWindow*)root)->locHandler->m_events->m_events[eHanterSex];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "IgorHanter")
    {
        IgorHanter* ptr = (IgorHanter*)((MainWindow*)root)->locHandler->m_events->m_events[eIgorHanter];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "Hanters")
    {
        Hanters* ptr = (Hanters*)((MainWindow*)root)->locHandler->m_events->m_events[eHanters];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "HantersLoveSex")
    {
        HantersLoveSex* ptr = (HantersLoveSex*)((MainWindow*)root)->locHandler->m_events->m_events[eHantersLoveSex];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "MeadowEvent")
    {
        MeadowEvent* ptr = (MeadowEvent*)((MainWindow*)root)->locHandler->m_events->m_events[eMeadowEvent];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "MiraFather")
    {
        MiraFather* ptr = (MiraFather*)((MainWindow*)root)->locHandler->m_events->m_events[eMiraFather];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "MiraSex")
    {
        MiraSex* ptr = (MiraSex*)((MainWindow*)root)->locHandler->m_events->m_events[eMiraSex];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "MitkaBuhGroup")
    {
        MitkaBuhGroup* ptr = (MitkaBuhGroup*)((MainWindow*)root)->locHandler->m_events->m_events[eMitkaBuhGroup];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "MitkaBuh")
    {
        MitkaBuh* ptr = (MitkaBuh*)((MainWindow*)root)->locHandler->m_events->m_events[eMitkaBuh];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
    if(params["handler"] == "SergeiHanter")
    {
        SergeiHanter* ptr = (SergeiHanter*)((MainWindow*)root)->locHandler->m_events->m_events[eSergeiHanter];
        ptr->makeActBtn(params["action"],params["buttonText"]);
    }
}
