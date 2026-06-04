#ifndef TIMER_HPP
#define TIMER_HPP

#include <QLabel>
#include <QString>
#include <QWidget>

namespace UI {

class Timer : public QWidget {
Q_OBJECT

public: 
	explicit Timer(QWidget* parent = nullptr);

	// double time
	double time() const { return m_time; }
	void tick(); // Increment time, calls tickAndUpdate() with m_time as a QString
	void resetTimer();

	// QLabel* timerLabel
	QLabel* timerLabel() const { return m_timerLabel; }
	void updateTimerLabelGeometry();

private:
	double m_time; // Internal representation of the time
	QLabel* m_timerLabel; // Label for the time

signals:
	void tickAndUpdate(QString string); // Signals to update the label

public slots:

};

}




#endif
