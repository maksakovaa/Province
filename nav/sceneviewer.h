#ifndef SCENEVIEWER_H
#define SCENEVIEWER_H

#include <QGraphicsView>
#include <QObject>
#include <QMouseEvent>
#include <QGraphicsItem>

class SceneViewer: public QGraphicsView
{
    Q_OBJECT
public:
    explicit SceneViewer(QGraphicsScene* scene, QWidget* parent = nullptr): QGraphicsView(scene, parent) {}
    explicit SceneViewer(QWidget *parent = nullptr): QGraphicsView(parent) {}
signals:
    void sigClickOnMarker(const QString& name);
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // SCENEVIEWER_H
