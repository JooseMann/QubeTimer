#include <Qt>
#include <QLabel>
#include <QString>
#include <QObject>
#include <QWidget>

#include <format> // std::format

#include "UI/Timer.hpp"

namespace UI {

Timer::Timer(QWidget* parent) : QWidget(parent) {
	m_time = 0.00;
	m_timerLabel = new QLabel(QString("0.00"), this);
	m_active = false;

	// Set up the label's font
	QFont font ("Calibri", 48);
	m_timerLabel->setFont(font);

	// Set up the label's alignment
	m_timerLabel->setAlignment(Qt::AlignCenter);

	// Connect our tick function to update the label's text
	QObject::connect(this, &Timer::tickAndUpdate, m_timerLabel, &QLabel::setText);

}

void Timer::tick() {
	m_time += 0.01;
	
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
