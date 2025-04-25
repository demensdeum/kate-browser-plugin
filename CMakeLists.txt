cmake_minimum_required(VERSION 3.16)
project(katebrowserplugin)

find_package(ECM REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDEFrameworkCompilerSettings)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)
find_package(KF6 REQUIRED COMPONENTS CoreAddons I18n TextEditor)

add_library(katebrowserplugin MODULE
    MyBrowserPlugin.cpp
    MyBrowserPlugin.h
)

target_link_libraries(katebrowserplugin
    PRIVATE
        Qt6::Widgets
        Qt6::WebEngineWidgets
        KF6::TextEditor
        KF6::CoreAddons
        KF6::I18n
)

install(TARGETS katebrowserplugin
    DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/ktexteditor
)

install(FILES plugin.json
    DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf6/ktexteditor/katebrowserplugin
)
