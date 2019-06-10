#include "CPUInfo.hpp"
#include <sys/sysctl.h>

CPUInfo::CPUInfo() {

    updateModule();
}

CPUInfo::CPUInfo(CPUInfo const &rhs) { *this = rhs; }

CPUInfo::~CPUInfo() {}

CPUInfo &
CPUInfo::operator=(CPUInfo const &rhs) {

    _cpuDetails = rhs.getCpuDetails();
    _nCpu = rhs.getNCpu();
    return *this;
}

std::string const &CPUInfo::getCpuDetails() const { return _cpuDetails; }
std::string const &CPUInfo::getNCpu() const { return _nCpu; }
bool CPUInfo::isVisible() const { return _visible; }

void
CPUInfo::toggle() {

    _visible = !_visible;
}

void
CPUInfo::updateModule() {

    uint64_t n = 0;
    size_t size = sizeof n;
    sysctlbyname("hw.ncpu", &n, &size, NULL, 0);
    _nCpu = std::to_string(n);

    char buff[BUFSIZ];
    size = BUFSIZ;
    sysctlbyname("machdep.cpu.brand_string", &buff, &size, NULL, 0);
    _cpuDetails = std::string(buff);
}
