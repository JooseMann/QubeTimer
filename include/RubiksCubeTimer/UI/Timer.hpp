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

	// bool active
	bool active() const { return m_active; }
	void toggleActive() { m_active = !m_active; }

	// double time
	double time() const { return m_time; }
	void tick(); // Increment time, calls tickAndUpdate() with m_time as a QString
	void resetTimer();

	// QLabel* timerLabel
	QLabel* timerLabel() const { return m_timerLabel; }
	void updateTimerLabelGeometry();

private:
	bool m_active; // Whether the timer is currently running or not.
	double m_time; // Internal representation of the time
	QLabel* m_timerLabel; // Label for the time

signals:
	void tickAndUpdate(QString string); // Signals to update the label

public slots:

};

}




#endif
