#include "sceneviewer.h"

void SceneViewer::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPointF scenePos = mapToScene(event->pos());
        QGraphicsItem *item = scene()->itemAt(scenePos, transform());
        if (item && item->type() == 4)
        {
            emit sigClickOnMarker(item->data(0).toString());
        }
    }
    QGraphicsView::mousePressEvent(event);
}
