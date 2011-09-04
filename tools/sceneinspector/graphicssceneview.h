/*
  graphicssceneview.h

  This file is part of Endoscope, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2011 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krauss@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ENDOSCOPE_GRAPHICSSCENEVIEW_H
#define ENDOSCOPE_GRAPHICSSCENEVIEW_H

#include <qwidget.h>

class QGraphicsScene;
class QGraphicsItem;

namespace Endoscope {

namespace Ui {
class GraphicsSceneView;
}

class GraphicsSceneView : public QWidget
{
  Q_OBJECT
  public:
    explicit GraphicsSceneView( QWidget *parent = 0 );
    ~GraphicsSceneView();

    void showGraphicsItem( QGraphicsItem *item );
    void setGraphicsScene( QGraphicsScene *scene );

  private slots:
    void sceneCoordinatesChanged( const QPointF &coord );
    void itemCoordinatesChanged( const QPointF &coord );

  private:
    Ui::GraphicsSceneView* ui;
};

}

#endif // ENDOSCOPE_GRAPHICSSCENEVIEW_H