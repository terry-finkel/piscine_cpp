#include "CpuUsage.hpp"


CpuUsage::CpuUsage() {
    _visible = true;
    updateModule();
}

CpuUsage::CpuUsage(CpuUsage const &rhs) { *this = rhs; }

CpuUsage::~CpuUsage() {}

CpuUsage &
CpuUsage::operator=(CpuUsage const &rhs) {

    _cpu = rhs.getCPU();
    _user = rhs.getUser();

    return *this;
}

double CpuUsage::getCPU() const { return _cpu; }
double CpuUsage::getUser() const { return _user; }
bool   CpuUsage::isVisible() const { return _visible; }
void   CpuUsage::toggle() { _visible = !_visible; }


void
CpuUsage::updateModule() {
    std::string info = Monitor::exec("top -U $USER -l 1");
    info = info.substr(info.find('\n') + 1);
    info = info.substr(info.find('\n') + 1);
    info = info.substr(info.find('\n') + 1);
    info = info.substr(info.find(':') + 1);

    _user = std::stod(info.c_str());
    
    info = info.substr(info.find(',') + 1);
    
    _cpu = std::stod(info);
}
