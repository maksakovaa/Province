#ifndef SCENEMARKER_H
#define SCENEMARKER_H

#include <QObject>
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QCursor>

class SceneMarker: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    explicit SceneMarker(qreal x, qreal y, QObject *parent = nullptr);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QBrush m_brush = Qt::blue;
    QCursor m_cursor = Qt::PointingHandCursor;
};

#endif // SCENEMARKER_H
