#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <Qt>
#include <QFont>
#include <QLabel>
#include <QWidget>

#include "RubiksCube.hpp"

namespace UI {

class Window : public QWidget {
Q_OBJECT

public: 
	explicit Window(QWidget* parent = nullptr);
	~Window() { delete m_cube; } // Only the rubiks cube isn't automatically deleted, so delete it in the destructor

	// QLabel* scrambleLabel
	QLabel* scrambleLabel() const { return m_scrambleLabel; }
	void setScrambleLabel(QLabel* label) { m_scrambleLabel = label; }
	void setupScrambleLabel();

	// QFont font
	QFont font() const { return m_font; }
	void setFont(QFont font) { m_font = font; m_scrambleLabel->setFont(m_font); }
	void setupFont();

	// Reset the scramble
	void refreshScramble();

private:
	QLabel* m_scrambleLabel; // Label that contains the scramble, to be shown on the screen
	QFont m_font; // The scramble's font
	RubiksCube* m_cube; // Our representation of the Rubiks cube

signals:
public slots:

};


} // UI

#endif // WINDOW_HPP
