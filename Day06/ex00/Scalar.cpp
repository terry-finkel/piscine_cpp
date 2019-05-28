#include "Scalar.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

Scalar::Scalar(char const *s) : _asChar(0), _asDouble(0), _asFloat(0), _asInt(0) ,
                                _impossibleC(false), _impossibleD(false), _impossibleF(false), _impossibleI(false) {

    struct s_conv {
        void    (Scalar::*setValue)(double);
        void    (Scalar::*setImpossible)(bool);
    } conv[2] = {
            {&Scalar::setAsDouble, &Scalar::setImpossibleD},
            {&Scalar::setAsFloat, &Scalar::setImpossibleF}
    };

    for (int k = 0; k < 2; k++) {
        try {
            (this->*(conv[k].setValue))(std::stod(s));
        } catch (std::invalid_argument &e) {
            (this->*(conv[k].setImpossible))(true);
        } catch (std::out_of_range &e) {
            (this->*(conv[k].setImpossible))(true);
        }
    }

    if (_asDouble != _asDouble || _asDouble > nextafter(INT_MAX, 0) || _asDouble < nextafter(INT_MIN, 0)) {
        _impossibleC = true;
        _impossibleI = true;
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

void Scalar::setAsDouble(double d) { _asDouble = d; }
void Scalar::setAsFloat(double d) { _asFloat = static_cast<float>(d); }
void Scalar::setImpossibleD(bool b) { _impossibleD = b; }
void Scalar::setImpossibleF(bool b) { _impossibleF = b; }

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
