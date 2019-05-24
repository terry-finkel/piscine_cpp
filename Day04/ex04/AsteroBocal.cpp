#include "AsteroBocal.hpp"

AsteroBocal::AsteroBocal(AsteroBocal const &rhs) { *this = rhs; }

AsteroBocal &
AsteroBocal::operator=(AsteroBocal const &) {

    return *this;
}

std::string
AsteroBocal::beMined(DeepCoreMiner *) const {

    return "Thorite";
}

std::string
AsteroBocal::beMined(StripMiner *) const {

    return "Flavium";
}

std::string
AsteroBocal::getName() const {

    return "AsteroBocal";
}
