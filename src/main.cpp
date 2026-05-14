#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include <cstdint> // uint8_t
#include <random> // To generate scrambles

#include "RubiksCubeTimer/RubiksCube.hpp"

int main(int argc, char* argv[]) {
    // Set up randomness in advance
    srand(time(nullptr));

    QApplication app (argc, argv);

    QPushButton button ("Hello World!");
    button.show();

    qInfo() << "Hello World!";

    return app.exec();
}