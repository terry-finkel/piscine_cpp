#include "Time.hpp"
#include <ctime>

Time::Time() { _visible = true; }

Time::Time(Time const &rhs) { *this = rhs; }

Time::~Time() {}

Time &
Time::operator=(Time const &rhs) {

	_date = rhs.getDate();
	_time = rhs.getTime();
	return *this;
}

std::string const &Time::getDate() const { return _date; }
std::string const &Time::getTime() const { return _time; }
bool Time::isVisible() const { return _visible; }
void Time::toggle() { _visible = !_visible; }


void
Time::updateModule() {

	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	char buffer[BUFSIZ];
	strftime(buffer, BUFSIZ, "%F", now);
	_date = std::string(buffer);

	strftime(buffer, BUFSIZ, "%r", now);
	_time = std::string(buffer);
}
