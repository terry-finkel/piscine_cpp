#include "Ram.hpp"
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <sys/sysctl.h>

Ram::Ram() {

    updateModule();
}

Ram::Ram(Ram const &rhs) { *this = rhs; }

Ram::~Ram() {}

Ram &
Ram::operator=(Ram const &rhs) {

    _maxRam = rhs.getMaxRam();
    _usedRam = rhs.getUsedRam();
    return *this;
}

std::string const &Ram::getMaxRam() const { return _maxRam; }
std::string const &Ram::getUsedRam() const { return _usedRam; }
size_t            Ram::getSizeMax() const { return _sizeMax; }
size_t            Ram::getSizeUsed() const { return _sizeUsed; }
bool Ram::isVisible() const { return _visible; }

void
Ram::toggle() {

    _visible = !_visible;
}

void
Ram::updateModule() {

    uint64_t n = 0;
    size_t size = sizeof n;
    sysctlbyname("hw.memsize", &n, &size, NULL, 0);
    _sizeMax = n;
    _maxRam = std::to_string(n).substr(0, 1) + "gB";

    vm_size_t page_size;
    vm_statistics64_data_t vm_stats;
    mach_port_t mach_port = mach_host_self();
    mach_msg_type_number_t count = sizeof(vm_stats) / sizeof(natural_t);
    size_t usedRam = 0;
    if (KERN_SUCCESS == host_page_size(mach_port, &page_size)
        && KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO, (host_info64_t)&vm_stats, &count)) {
        usedRam = (vm_stats.active_count + vm_stats.inactive_count + vm_stats.wire_count) * page_size;
    }
    _sizeUsed = usedRam;
    _usedRam = std::to_string(usedRam);
    switch (_usedRam.size()) {
        case 9:
        case 8:
        case 7:
            _usedRam = _usedRam.substr(0, _usedRam.size() - 6) + "mB";
            break;
        case 6:
        case 5:
        case 4:
            _usedRam = _usedRam.substr(0, _usedRam.size() - 3) + "kB";
            break;
        default:
            _usedRam = _usedRam.substr(0, _usedRam.size() - 9) + "gB";
    }
}
