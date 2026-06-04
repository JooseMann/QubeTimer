#include <Qt>
#include <QApplication>
#include <QDebug>
#include <QFont>
#include <QLabel>

#include "RubiksCube.hpp"
#include "UI/Window.hpp"

// Testing includes
#include <unistd.h> // Using for usleep(int)
#include <thread> // Using for threading, when incrementing the timer

void incTimer(UI::Window* window) {
    // 2 seconds
    // 200 * 10000 = 2 * 10^6 microseconds = 2 seconds
    for (int i = 0; i < 200; ++i) {
        window->incrementTimer();
        usleep(10000);
    }
}

int main(int argc, char* argv[]) {
    // Set up randomness in advance
    srand(time(nullptr));

    // Base application
    QApplication app (argc, argv);
    
    // Create the window
    // Handles making the rubiks cube (and its scramble) in the constructor
    UI::Window* window = new UI::Window();

    // Increment the timer immediately here (while testing)
    std::thread thr(incTimer, window);

    // Show the window when running the app (below) 
    window->show();

    // Run the app
    int rc = app.exec();

    // Cleanup below

    thr.join();

    delete window;

    return rc;
}
