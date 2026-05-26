#include <Qt>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QLabel>

#include "RubiksCube.hpp"
#include "UI/Window.hpp"

int main(int argc, char* argv[]) {
    // Set up randomness in advance
    srand(time(nullptr));

    // Base application
    QApplication app (argc, argv);
    
    // Create the window
    // Handles making the rubiks cube (and its scramble) in the constructor
    UI::Window window;

    // Show the window when running the app (below) 
    window.show();

    return app.exec();
}
