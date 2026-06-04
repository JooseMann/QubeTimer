#include <Qt>
#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QRect>
#include <QWidget>

#include "RubiksCube.hpp"
#include "UI/Timer.hpp"
#include "UI/Window.hpp"

namespace UI {

Window::Window(QWidget* parent) : QWidget(parent) {
	// First define the layout
	m_layout = new QGridLayout(this);

	// Then define the rest of the variables
	m_cube = new RubiksCube();
	m_scrambleLabel = new QLabel(m_cube->getStringScramble(), this);
	m_font = QFont();
	m_timer = new Timer(this);

	// Set the minimum size to 800x600 (though, ideally it'd be larger)
	setMinimumSize(800, 600);
	
	setupLayout();
	setupFont();
	setupScrambleLabel();
	setupTimer();
}

// Set the default layout settings
void Window::setupLayout() {
	
	// Get screen width and height for future reference
	int screenWidth = this->geometry().width();
	int screenHeight = this->geometry().height();

	// Set the basic properties of the layout
	// Takes up the whole screen as one big grid, and has no spacing
	m_layout->setGeometry(QRect(0, 0, screenWidth, screenHeight));
	m_layout->setHorizontalSpacing(0); // No horizontal spacing between columns
	m_layout->setVerticalSpacing(0); // No vertical spacing between rows

	// Add our widgets to the layout
	// Scramble is top-center, timer is in the exact center
	m_layout->addWidget(m_scrambleLabel, 0, 0, 1, 10, Qt::AlignHCenter); // Also creates 10 columns
	m_layout->addWidget(new QLabel("", this), 0, 0, 10, 1); // Dummy widget for creating 10 rows
	m_layout->addWidget(m_timer, 2, 0, 6, 10, Qt::AlignCenter);

	// Disallow the rows and columns from stretching
	// Also set each of their sizes to 1/10th of the screen's width or height, respectively
	// This way, the rows and columns always exactly fit the screen
	for (int i = 0; i < 10; ++i) {
		// Safety if statement, break out early if the row/column count wasn't set correctly (should be exactly 10)
		if (i >= m_layout->columnCount() || i >= m_layout->rowCount()) break;

		m_layout->setColumnStretch(i, 0);
		m_layout->setRowStretch(i, 0);

		m_layout->setColumnMinimumWidth(i, screenWidth / 10);
		m_layout->setRowMinimumHeight(i, screenHeight / 10);
	}

}

// Set default properties for m_scrambleLabel
void Window::setupScrambleLabel() {
	// Set the font and alignment of the label
	m_scrambleLabel->setFont(m_font);
	m_scrambleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop); // Align top-center
}

// Set default properties for m_font
void Window::setupFont() {
	m_font.setFamily("Calibri");
	m_font.setPointSize(22);
}

// Set the default properties for m_timer
void Window::setupTimer() {

	// Screen width and height, for convenience
	int screenWidth = this->geometry().width();
	int screenHeight = this->geometry().height();

	// Set the minimum size to account for the rows and columns we give it, so it fills the whole space
	// 10 / 10 columns and 6 / 10 rows -> (width, 0.6 * height)
	m_timer->setMinimumSize(screenWidth, 6 * (screenHeight / 10.0));
	m_timer->updateTimerLabelGeometry(); // Update the label for the timer accordingly
}

// Refresh the internal scramble
void Window::refreshScramble() {
	// To refresh the internal scramble, just recall generateScramble() to overwrite with a new scramble
	m_cube->generateScramble();
}

} // UI
