#include "mapform.h"
#include "ui_mapform.h"
#include "sceneviewer.h"
#include "scenemarker.h"
#include <QFile>
#include <iostream>

MapForm::MapForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MapForm)
{
    ui->setupUi(this);
    init();
}

MapForm::~MapForm()
{
    delete ui;
}

QGraphicsScene *MapForm::genMap(const QString &loc_name, const QString &current_loc)
{
    m_current = current_loc;
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setObjectName(loc_name);
    scene->addText(loc_name);
    if(loc_name == "pavlovo")
    {
        scene->addPixmap(QPixmap(":/img/maps/pavlovo.png"));
        for (auto& i: pavlovo_markers) 
        {
            SceneMarker* marker = new SceneMarker(i.x,i.y);
            marker->setData(0, i.name);
            marker->setToolTip(i.name);
            scene->addItem(marker);
        }
        for (auto& i: player_markers)
        {
            if (i.name == m_current)
            {
                SceneMarker* marker = new SceneMarker(i.x,i.y);
                marker->setData(0, i.name);
                marker->setToolTip(i.name);
                marker->setBrush(Qt::red);
                scene->addItem(marker);
            }
            
        }
                
    }
    return scene;
}

void MapForm::setMap(QGraphicsScene *Scene)
{
    if(ui->graphicsView->scene() != nullptr)
    {
        ui->graphicsView->scene()->deleteLater();
    }

    ui->graphicsView->setScene(Scene);
    ui->verticalLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    connect(ui->graphicsView, &SceneViewer::sigClickOnMarker, this, &MapForm::onMarkerClicked);
}

void MapForm::onMarkerClicked(const QString &name)
{
    emit ChangeLocation(name, calcTimeToGo(m_current, name));
}

void MapForm::init()
{
    QFile file(":/locations/map_pavlovo_location_markers");
    if(!file.open(QIODevice::ReadOnly))
    {
        std::cout << "Error opening file!" << std::endl;
    }
    else
    {
        QTextStream in(&file);
        QString line;
        while (!in.atEnd())
        {
            line = in.readLine();
            QStringList list = line.split(" ");
            pavlovo_markers.push_back(loc(list.at(0), list.at(1).toInt() - 10, list.at(2).toInt() - 10));
        }
    }
    QFile file2(":/locations/map_pavlovo_player_markers");
    if(!file2.open(QIODevice::ReadOnly))
    {
        std::cout << "Error opening file!" << std::endl;
    }
    else
    {
        QTextStream in2(&file2);
        QString line2;
        while (!in2.atEnd())
        {
            line2 = in2.readLine();
            QStringList list2 = line2.split(" ");
            player_markers.push_back(loc(list2.at(0), list2.at(1).toInt() - 10, list2.at(2).toInt() - 10));
        }
    }
}

int MapForm::calcDistance(const QString &from, const QString &to)
{
    int x1, x2, y1, y2;
    for (auto& i: player_markers)
    {
        if(i.name == from)
        {
            x1 = i.x;
            y1 = i.y;
        }
    }
    for (auto& i: pavlovo_markers)
    {
        if(i.name == to)
        {
            x2 = i.x;
            y2 = i.y;
        }
    }
    return std::sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

int MapForm::calcTimeToGo(const QString &from, const QString &to)
{
    return calcDistance(from, to) / 6;
}
