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

QGraphicsScene *MapForm::genMap(const QString &loc_name, const QString &current_loc, int hour)
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
            if (i.hmin !=0 && i.hmax != 0)
            {
                if (hour >= i.hmin && hour <= i.hmax)
                {
                    SceneMarker* marker = new SceneMarker(i.x,i.y);
                    marker->setData(0, i.name);
                    marker->setToolTip(i.name);
                    scene->addItem(marker);
                }                                
            }
            else
            {
                SceneMarker* marker = new SceneMarker(i.x,i.y);
                marker->setData(0, i.name);
                marker->setToolTip(i.name);
                scene->addItem(marker);
            }
            

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
            if (list.size() == 3)
            {
                pavlovo_markers.push_back(loc(list.at(0), list.at(1).toInt() - 10, list.at(2).toInt() - 10, 0, 0));
            }
            else if (list.size() == 5)
            {
                pavlovo_markers.push_back(loc(list.at(0), list.at(1).toInt(), list.at(2).toInt(), list.at(3).toInt(), list.at(4).toInt()));
            }
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

    QFile file3(":/locations/time_markers");
    if (!file3.open(QIODevice::ReadOnly))
    {
        std::cout << "Error opening file!" << std::endl;
    }
    else
    {
        QTextStream in3(&file3);
        QString line3;
        while (!in3.atEnd())
        {
            line3 = in3.readLine();
            QStringList list3 = line3.split(" ");
            timeMarkers.push_back(loc(list3.at(0), list3.at(1).toInt(), list3.at(2).toInt()));
        }
    }
}

int MapForm::calcDistance(const QString &from, const QString &to)
{
    int x1, x2, y1, y2;
    for (auto& i: timeMarkers)
    {
        if(i.name == from)
        {
            x1 = i.x;
            y1 = i.y;
        }
    }
    for (auto& i: timeMarkers)
    {
        if(i.name == to)
        {
            x2 = i.x;
            y2 = i.y;
        }
    }
    int t1, t2;
    if(x2 - x1 < 0)
        t1 = x1 - x2;
    else
        t1 = x2 - x1;
    if(y2 - y1 < 0)
        t2 = y1 - y2;
    else
        t2 = y2 - y1;
    return (t1+t2)*2;
}

int MapForm::calcTimeToGo(const QString &from, const QString &to)
{
    return calcDistance(from, to);
}
