#include "OHName.hpp"
#include <sys/param.h>
#include <zconf.h>

OHName::OHName() {
	_visible = true;
    updateModule();
}

OHName::OHName(OHName const &rhs) { *this = rhs; }

OHName::~OHName() {}

OHName &
OHName::operator=(OHName const &rhs) {

    _hostname = rhs.getHostname();
    _username = rhs.getUsername();
    return *this;
}

std::string	const &OHName::getHostname() const { return _hostname; }
std::string const &OHName::getUsername() const { return _username; }
bool OHName::isVisible() const { return _visible; }
void OHName::toggle() { _visible = !_visible; }

void
OHName::updateModule() {

    char buff[MAXHOSTNAMELEN];
    gethostname(buff, MAXHOSTNAMELEN);
    _hostname = std::string(buff);
    getlogin_r(buff, MAXHOSTNAMELEN);
    _username = std::string(buff);
}
