#include "scenemarker.h"

SceneMarker::SceneMarker(qreal x, qreal y, QObject *parent): QObject(parent), QGraphicsEllipseItem(x,y,20,20)
{
    setBrush(m_brush);
    setOpacity(0.5);
    setCursor(m_cursor);
}

void SceneMarker::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsEllipseItem::mousePressEvent(event);
}
