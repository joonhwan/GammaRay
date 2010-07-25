#ifndef ENDOSCOPE_PROPERTYWIDGET_H
#define ENDOSCOPE_PROPERTYWIDGET_H

#include "ui_propertywidget.h"

namespace Endoscope {

class ObjectDynamicPropertyModel;
class ObjectStaticPropertyModel;

class PropertyWidget : public QWidget
{
  Q_OBJECT
  public:
    PropertyWidget( QWidget *parent = 0 );

    void setObject( QObject *object );

  private:
    Ui::PropertyWidget ui;
    ObjectStaticPropertyModel *m_staticPropertyModel;
    ObjectDynamicPropertyModel *m_dynamicPropertyModel;
};

}

#endif // ENDOSCOPE_PROPERTYWIDGET_H