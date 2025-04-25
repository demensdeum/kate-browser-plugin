#pragma once

#include <KTextEditor/Plugin>
#include <KTextEditor/MainWindow>
#include <KXMLGUIClient>
#include <QDockWidget>
#include <QWebEngineView>

class MyBrowserPlugin : public KTextEditor::Plugin
{
    Q_OBJECT
public:
    explicit MyBrowserPlugin(QObject *parent = nullptr, const QList<QVariant> & = QList<QVariant>())
        : KTextEditor::Plugin(parent) {}

    QObject *createView(KTextEditor::MainWindow *mainWindow) override;
};

class MyBrowserPluginView : public QObject, public KXMLGUIClient
{
    Q_OBJECT
public:
    explicit MyBrowserPluginView(MyBrowserPlugin *plugin, KTextEditor::MainWindow *mainWindow);

private:
    KTextEditor::MainWindow *m_mainWindow = nullptr;
    QDockWidget *m_dock = nullptr;
    QWebEngineView *m_webView = nullptr;
};
