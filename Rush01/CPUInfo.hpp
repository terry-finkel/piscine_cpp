#ifndef CPUINFO_HPP
# define CPUINFO_HPP

# include "IMonitorModule.hpp"
# include <iostream>

class CPUInfo : public IMonitorModule {
private:
    std::string         _cpuDetails;
    std::string         _nCpu;
    bool                _visible;

public:
                        CPUInfo();
                        CPUInfo(CPUInfo const &);
    virtual             ~CPUInfo();
    CPUInfo             &operator=(CPUInfo const &);
    std::string const   &getCpuDetails() const;
    std::string const   &getNCpu() const;
    bool                isVisible() const;
    void                toggle();
    void                updateModule();
};

#endif /* CPUINFO_HPP */
