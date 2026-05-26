#include <Qt>
#include <QFont>
#include <QLabel>
#include <QRect>
#include <QWidget>

#include "RubiksCube.hpp"
#include "UI/Window.hpp"

namespace UI {

Window::Window(QWidget* parent) : QWidget(parent) {
	m_cube = new RubiksCube();
	m_scrambleLabel = new QLabel(m_cube->getStringScramble(), this);
	m_font = QFont();

	// Set the minimum size to 800x600 (though, ideally it'd be larger)
	setMinimumSize(800, 600);
	
	setupFont();
	setupScrambleLabel();
}

// Set default properties for m_scrambleLabel
void Window::setupScrambleLabel() {
	// Set the bounding box
	// NOTE: This takes up the whole screen for now, because it's the only element on screen at the moment. 
	// In the future, this will have to be changed to accompany other elements (!!)
	QRect rect = m_scrambleLabel->geometry();
	rect.setWidth(this->width());
	rect.setHeight(this->height());

	m_scrambleLabel->setGeometry(rect);
	m_scrambleLabel->setFont(m_font);
	m_scrambleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop); // Align top-center
}

// Set default properties for m_font
void Window::setupFont() {
	m_font.setFamily("Calibri");
	m_font.setPointSize(22);
}

// Refresh the internal scramble
void Window::refreshScramble() {
	// To refresh the internal scramble, just recall generateScramble() to overwrite with a new scramble
	m_cube->generateScramble();
}

}; // UI
