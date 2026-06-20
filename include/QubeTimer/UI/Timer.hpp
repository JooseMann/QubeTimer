#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>

#include <QLabel>
#include <QString>
#include <QWidget>

// Millisecond typedef: we will need millisecond precision, so we use std::chrono here
typedef std::chrono::time_point<std::chrono::steady_clock> ms_t;

namespace UI {

class Timer : public QWidget {
Q_OBJECT

public: 
	explicit Timer(QWidget* parent = nullptr);

	// ms_t absoluteTime
	ms_t absoluteTime() const { return m_absoluteTime; }
	void updateAbsoluteTime() { m_absoluteTime = std::chrono::steady_clock::now(); }

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
	ms_t m_absoluteTime; // Time since the Unix Epoch, for calculating elapsed time
	bool m_active; // Whether the timer is currently running or not.
	double m_time; // Internal representation of the time
	QLabel* m_timerLabel; // Label for the time

	// Util method to convert ms_t to a double, for use in elapsed time calculations
	double toTimeDouble(ms_t time) { return std::chrono::duration<double>(time.time_since_epoch()).count(); }

signals:
	void tickAndUpdate(QString string); // Signals to update the label

public slots:

};

}




#endif
