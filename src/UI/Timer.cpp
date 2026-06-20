#include <chrono>

#include <Qt>
#include <QLabel>
#include <QString>
#include <QObject>
#include <QWidget>

#include "UI/Timer.hpp"

// Millisecond typedef: we will need millisecond precision, so we use std::chrono here
typedef std::chrono::time_point<std::chrono::steady_clock> ms_t;

namespace UI {

Timer::Timer(QWidget* parent) : QWidget(parent) {
	m_time = 0.00;
	m_timerLabel = new QLabel(QString("0.00"), this);
	m_active = false;
	m_absoluteTime = std::chrono::steady_clock::now(); // Default misc. value for the absolute time

	// Set up the label's font
	QFont font ("Calibri", 48);
	m_timerLabel->setFont(font);

	// Set up the label's alignment
	m_timerLabel->setAlignment(Qt::AlignCenter);

	// Connect our tick function to update the label's text
	QObject::connect(this, &Timer::tickAndUpdate, m_timerLabel, &QLabel::setText);

}

void Timer::tick() {	

	// Absolute time, as of the moment that we are updating the timer
	ms_t absoluteTime = std::chrono::steady_clock::now();

	// Calculate elapsed time since last adding to the timer
	double elapsed = this->toTimeDouble(absoluteTime) - this->toTimeDouble(m_absoluteTime);

	// Now add this time to the timer, so that the timer is consistently accurate
	m_time += elapsed;

	// Update the absolute time
	m_absoluteTime = absoluteTime;
	
	// Format the number as a string, use 2 decimal points
	// Send the signal to the label to update its value
	tickAndUpdate(QString::number(m_time, 'f', 2));
}

void Timer::resetTimer() {
	m_time = 0.00;
	m_timerLabel->setText("0.00");
}

void Timer::updateTimerLabelGeometry() {
	m_timerLabel->setGeometry(QRect(0, 0, this->minimumSize().width(), this->minimumSize().height()));
}

}
