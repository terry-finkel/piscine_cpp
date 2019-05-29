#include "Scalar.hpp"
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <iostream>

Scalar::Scalar(char const *s) : _asChar(0), _asDouble(0), _asFloat(0), _asInt(0) ,
                                _impossibleC(false), _impossibleD(false), _impossibleF(false), _impossibleI(false) {

    if (!isdigit(s[0]) && !s[1]) {
        _asInt = s[0];
        _asDouble = static_cast<double>(_asInt);
        _asFloat = static_cast<float>(_asInt);
    } else {
        try {
            _asDouble = std::stod(s);
            _asFloat = static_cast<float>(_asDouble);
        } catch (std::invalid_argument &e) {
            _impossibleD = true;
            _impossibleF = true;
            _impossibleI = true;
        } catch (std::out_of_range &e) {
            _impossibleD = true;
            _impossibleF = true;
            _impossibleI = true;
        }
        _asInt = static_cast<int>(_asDouble);
    }

    /* Check int overflow and NaN. */
    if (_asDouble != _asDouble || _asInt > nextafter(INT_MAX, 0) || _asInt < nextafter(INT_MIN, 0)) {
        _impossibleC = true;
        _impossibleI = true;
    }

    if (!_impossibleI && isprint(s[0]) && !s[1]) {
        _asChar = s[0];
    } else if (!_impossibleI && static_cast<double>(_asInt) == _asDouble) {
        _asChar = static_cast<char>(_asInt);
    } else {
        _impossibleC = true;
    }
}

Scalar::Scalar(Scalar const &rhs) { *this = rhs; }

Scalar::~Scalar() {}

Scalar &
Scalar::operator=(Scalar const &rhs) {

    _asChar = rhs._asChar;
    _asDouble = rhs._asDouble;
    _asFloat = rhs._asFloat;
    _asInt = rhs._asInt;
    _impossibleD = rhs._impossibleD;
    _impossibleF = rhs._impossibleF;
    _impossibleI = rhs._impossibleI;
    return *this;
}

void
Scalar::display() const {

    std::cout << std::setprecision(1) << std::fixed << "char: ";

    if (isprint(static_cast<int>(_asChar))) {
        std::cout << "'" << _asChar << "'" << std::endl;
    } else if (_impossibleC) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

    std::cout << "int: ";
    if (_impossibleI) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << _asInt << std::endl;
    }

    std::cout << "float: ";
    if (_impossibleF) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << _asFloat << "f" << std::endl;
    }

    std::cout << "double: ";
    if (_impossibleD) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << _asDouble << std::endl;
    }
}
