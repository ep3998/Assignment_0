//#include <QtGui/QApplication>
//#include "qmlapplicationviewer.h"

//Q_DECL_EXPORT int main(int argc, char *argv[])
//{
//    QScopedPointer<QApplication> app(createApplication(argc, argv));

//    QmlApplicationViewer viewer;
//    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
//    viewer.setMainQmlFile(QLatin1String("qml/Assignment_0/main.qml"));
//    viewer.showExpanded();

//    return app->exec();
//}
/*
 * Assignment 0
 *
 * Desc: Code for EECS493 Assignment 0.
 * 		 Task is to compile this code to make
 * 		 sure your Qt environment is set up
 * 		 properly.
 *  January 23, 2006
 */

#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>

int main(int argc, char** argv)
{
  // QApplication is the object that needs to be defined before any Qt GUI
  // objects are used and is defined exactly once.
  QApplication app(argc, argv);
  // Base class for all Qt widgets. Used to define new types of widgets
  QWidget* window = new QWidget;

  // Our quit push button.
  QPushButton quit("Quit");
  quit.resize(75, 30);

  // Connects the quit pushbutton event of being clicked to the quit() function
  // of our QApplication object.
  QObject::connect(&quit, SIGNAL(clicked()), &app, SLOT(quit()));

  // Litte extra piece of UI used to show how layout works.
  // Will be useful in Assignment 1.
  QLabel welcome("If you see this message, means git finally is working.");
  welcome.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

  // A container to arrange widgets in a vertical/column type fashion.
  QVBoxLayout* layout = new QVBoxLayout;
  // Add our two widgets to the layout.
  layout->addWidget(&welcome);
  layout->addWidget(&quit);

  // Tell the window widget that it contains out two widgets in a vertical layout.
  window->setLayout(layout);
  // Show our base widget that now contains a pushbutton and a little text message.
  window->show();

  // Execute our application.
  return app.exec();
}


