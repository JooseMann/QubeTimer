#include <Qt>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QLabel>

#include "RubiksCube.hpp"
#include "SolveManager.hpp"
#include "UI/Window.hpp"

int main(int argc, char* argv[]) {
    // Set up randomness in advance
    srand(time(nullptr));

    // Create our solve manager, to keep track of past solves
    // test_solves.csv is filled with random solves 
    SolveManager* solveManager = new SolveManager("../test_solves.csv");

    // Base application
    QApplication app (argc, argv);
    
    // Create the window
    // Handles making the rubiks cube (and its scramble) in the constructor
    UI::Window* window = new UI::Window();

    // Show the window when running the app (below) 
    window->show();

    // Run the app
    int rc = app.exec();

    // Cleanup
    delete window;
    delete solveManager;

    return rc;
}
