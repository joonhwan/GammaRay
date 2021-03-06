/*
  palettemodel.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010 Ariya Hidayat <ariya.hidayat@gmail.com>
  Copyright (C) 2012 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

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

#include "palettemodel.h"

#include <QIcon>
#include <QPainter>

using namespace GammaRay;


struct role_t {
    const char *name;
    QPalette::ColorRole role;
};

static role_t paletteRoles[] =  {
    { "Window",          QPalette::Window },
    { "WindowText",      QPalette::WindowText },
    { "Base",            QPalette::Base },
    { "AlternateBase",   QPalette::AlternateBase },
    { "Text",            QPalette::Text },
    { "ToolTipBase",     QPalette::ToolTipBase },
    { "ToolTipText",     QPalette::ToolTipText },
    { "Button",          QPalette::Button },
    { "ButtonText",      QPalette::ButtonText },
    { "BrightText",      QPalette::BrightText },
    { "Light",           QPalette::Light },
    { "Midlight",        QPalette::Midlight },
    { "Dark",            QPalette::Dark },
    { "Mid",             QPalette::Mid },
    { "Shadow",          QPalette::Shadow },
    { "Highlight",       QPalette::Highlight },
    { "HighlightedText", QPalette::HighlightedText },
    { "Link",            QPalette::Link },
    { "LinkVisited",     QPalette::LinkVisited }
};

struct group_t {
    const char *name;
    QPalette::ColorGroup group;
};

static group_t paletteGroups[] = {
    { "Active",    QPalette::Active },
    { "Inactive",  QPalette::Inactive },
    { "Disabled",  QPalette::Disabled },
};


PaletteModel::PaletteModel(QObject* parent): QAbstractTableModel(parent)
{
}

QPalette PaletteModel::palette() const
{
  return m_palette;
}

void PaletteModel::setPalette(const QPalette& palette)
{
  beginResetModel();
  m_palette = palette;
  endResetModel();
}

QVariant PaletteModel::data(const QModelIndex& index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (role == Qt::DisplayRole) {
    if (index.column() == 0)
      return paletteRoles[index.row()].name;
    return m_palette.color(paletteGroups[index.column()-1].group, paletteRoles[index.row()].role).name();
  } else if (role == Qt::DecorationRole && index.column() != 0) {
    const QBrush brush = m_palette.brush(paletteGroups[index.column()-1].group, paletteRoles[index.row()].role);
    QPixmap pixmap(32, 32);
    QPainter painter(&pixmap);
    painter.fillRect(pixmap.rect(), Qt::black);
    painter.fillRect(pixmap.rect().adjusted(1, 1, -1, -1), brush);
    return QIcon(pixmap);
  }

  return QVariant();
}

int PaletteModel::columnCount(const QModelIndex& parent) const
{
  Q_UNUSED(parent);
  return 1 + sizeof(paletteGroups) / sizeof(paletteGroups[0]);
}

int PaletteModel::rowCount(const QModelIndex& parent) const
{
  if (parent.isValid())
    return 0;
  return sizeof(paletteRoles) / sizeof(paletteRoles[0]);
}

QVariant PaletteModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
    if (section == 0)
      return tr("Role");
    return paletteGroups[section-1].name;
  }
  return QAbstractItemModel::headerData(section, orientation, role);
}

#include "palettemodel.moc"
