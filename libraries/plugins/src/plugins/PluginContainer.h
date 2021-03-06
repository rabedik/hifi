//
//  Created by Bradley Austin Davis on 2015/08/08
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#pragma once

#include <functional>
#include <QString>

class QAction;
class QGLWidget;
class QScreen;

class PluginContainer {
public:
    PluginContainer();
    virtual void addMenu(const QString& menuName) = 0;
    virtual void removeMenu(const QString& menuName) = 0;
    virtual QAction* addMenuItem(const QString& path, const QString& name, std::function<void(bool)> onClicked, bool checkable = false, bool checked = false, const QString& groupName = "") = 0;
    virtual void removeMenuItem(const QString& menuName, const QString& menuItem) = 0;
    virtual bool isOptionChecked(const QString& name) = 0;
    virtual void setIsOptionChecked(const QString& path, bool checked) = 0;
    virtual void setFullscreen(const QScreen* targetScreen, bool hideMenu = false) = 0;
    virtual void unsetFullscreen(const QScreen* avoidScreen = nullptr) = 0;
    virtual void showDisplayPluginsTools() = 0;
    virtual QGLWidget* getPrimarySurface() = 0;
    virtual bool isForeground() = 0;
};
