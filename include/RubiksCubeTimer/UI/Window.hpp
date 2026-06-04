#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Qt>
#include <QFont>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>

#include "RubiksCube.hpp"
#include "UI/Timer.hpp"

namespace UI {

class Window : public QWidget {
Q_OBJECT

public: 
	explicit Window(QWidget* parent = nullptr);
	~Window() { delete m_cube; } // Only the rubiks cube isn't automatically deleted, so delete it in the destructor

	// QGridLayout* layout
	QGridLayout* layout() const { return m_layout; }
	void setupLayout();

	// QFont font
	QFont font() const { return m_font; }
	void setFont(QFont font) { m_font = font; m_scrambleLabel->setFont(m_font); }
	void setupFont();

	// QLabel* scrambleLabel
	QLabel* scrambleLabel() const { return m_scrambleLabel; }
	void setScrambleLabel(QLabel* label) { m_scrambleLabel = label; }
	void setupScrambleLabel();

	// Timer* timer
	Timer* timer() const { return m_timer; }
	void incrementTimer() { m_timer->tick(); }
	void setupTimer();

	// Reset the scramble
	void refreshScramble();

private:
	// UI
	QGridLayout* m_layout; // Grid layout of the window
	QFont m_font; // The scramble's font
	QLabel* m_scrambleLabel; // Label that contains the scramble, to be shown on the screen
	Timer* m_timer; // Timer to be shown on screen

	// Other
	RubiksCube* m_cube; // Our representation of the Rubiks cube

signals:
public slots:

};


} // UI

#endif // WINDOW_HPP
