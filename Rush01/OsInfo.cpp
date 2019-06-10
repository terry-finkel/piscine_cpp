#include "OsInfo.hpp"
#include <sys/utsname.h>
#include <zconf.h>

OsInfo::OsInfo() {
    _visible = true;
    updateModule();
}

OsInfo::OsInfo(OsInfo const &rhs) { *this = rhs; }

OsInfo::~OsInfo() {}

OsInfo &
OsInfo::operator=(OsInfo const &rhs) {

    _machine = rhs.getMachine();
    _release = rhs.getRelease();
    _sysname = rhs.getSysname();
    _version = rhs.getVersion();
    return *this;
}

std::string const &OsInfo::getMachine() const { return _machine; }
std::string const &OsInfo::getRelease() const { return _release; }
std::string const &OsInfo::getSysname() const { return _sysname; }
std::string const &OsInfo::getVersion() const { return _version; }
bool OsInfo::isVisible() const { return _visible; }
void OsInfo::toggle() { _visible = !_visible; }


void
OsInfo::updateModule() {

    struct utsname u;
    uname(&u);
    _machine = u.machine;
    _release = u.release;
    _sysname = u.sysname;
    _version = u.version;
}
