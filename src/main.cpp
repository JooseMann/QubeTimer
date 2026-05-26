#include <Qt>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QLabel>

#include "RubiksCube.hpp"

int main(int argc, char* argv[]) {
    // Set up randomness in advance
    srand(time(nullptr));

    // Base application
    QApplication app (argc, argv);
    
    // Generate the scramble
    qInfo() << "Generating Scramble...";
    RubiksCube cube;

    // Create the font
    QFont* font = new QFont();
    font->setFamily("Calibri");
    font->setPointSize(22);

    // Write the scramble as a label
    QLabel* scrambelLabel = new QLabel(cube.getStringScramble());
    scrambelLabel->setFont(*font);
    scrambelLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    scrambelLabel->setIndent(10); // Only indents 10 from the top
    scrambelLabel->show();

    return app.exec();
}
