#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>

#include "GameView/mainwindow.h"

void registerQmlTypes()
{
  qmlRegisterType<View::GameView>("GoL", 1, 0, "GameView");
  qmlRegisterType<View::MainWindow>("GoL", 1, 0, "MainWindow");
  qmlRegisterType<View::GameParams>("GoL", 1, 0, "GameParams");
}

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif 
  QGuiApplication app(argc, argv);
  registerQmlTypes();

  QQuickView view(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
  QObject::connect(view.engine(), &QQmlEngine::quit, &app, &QGuiApplication::quit);

  view.setResizeMode(QQuickView::SizeRootObjectToView);
  view.show();
  return app.exec();
}
