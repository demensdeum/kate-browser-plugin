#include "MyBrowserPlugin.h"

#include <QMainWindow>
#include <KPluginFactory>
#include <KLocalizedString>
#include <QLineEdit>
#include <QVBoxLayout>

K_PLUGIN_FACTORY_WITH_JSON(MyBrowserPluginFactory, "plugin.json", registerPlugin<MyBrowserPlugin>();)

QObject *MyBrowserPlugin::createView(KTextEditor::MainWindow *mainWindow)
{
    return new MyBrowserPluginView(this, mainWindow);
}

MyBrowserPluginView::MyBrowserPluginView(MyBrowserPlugin *plugin, KTextEditor::MainWindow *mainWindow)
    : m_mainWindow(mainWindow)
{
    m_dock = new QDockWidget(i18n("Web Browser"), qobject_cast<QWidget *>(mainWindow->window()));
    QWidget *content = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(content);
    QLineEdit *addressBar = new QLineEdit;
    m_webView = new QWebEngineView;

    QString initialUrl = QStringLiteral("https://demensdeum.com");
    addressBar->setText(initialUrl);
    m_webView->setUrl(QUrl(initialUrl));
    m_webView->load(QUrl(initialUrl));

    layout->addWidget(addressBar);
    layout->addWidget(m_webView);
    content->setLayout(layout);
    m_dock->setWidget(content);

    qobject_cast<QMainWindow *>(mainWindow->window())->addDockWidget(Qt::RightDockWidgetArea, m_dock);

    connect(addressBar, &QLineEdit::returnPressed, [=]() {
        QString url = addressBar->text();
        if (!url.startsWith(QStringLiteral("http")))
            url.prepend(QStringLiteral("https://"));
        m_webView->setUrl(QUrl(url));
    });
}

#include "MyBrowserPlugin.moc"
