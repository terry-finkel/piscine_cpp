#include "Fixed.class.hpp"
#include <cmath>

int const Fixed::_WIDTH = 8;

Fixed::Fixed () : _value(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (float const value) {

    this->_value = static_cast<int>(roundf(value * (1 << Fixed::_WIDTH)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (int const value) {

    this->_value = value * (1 << Fixed::_WIDTH);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (Fixed const &f) : _value(f._value) {

    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed () {

    std::cout << "Destructor called" << std::endl;
}

Fixed &
Fixed::operator = (Fixed const &f) {

    this->setRawBits(f._value);
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

int
Fixed::getRawBits () const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void
Fixed::setRawBits (int const value) {

    this->_value = value;
    std::cout << "setRawBits member function called" << std::endl;
}

float
Fixed::toFloat () const {

    return this->_value / (static_cast<float>(1 << Fixed::_WIDTH));
}

int
Fixed::toInt () const {

    return this->_value >> Fixed::_WIDTH;
}

std::ostream &
operator << (std::ostream &os, Fixed const &f) {

    os << f.toFloat();
    return os;
}
