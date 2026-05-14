#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char* argv[]) {
    QApplication app (argc, argv);

    QPushButton button ("Hello World!");
    button.show();

    qInfo() << "Hello World!";

    return app.exec();
}