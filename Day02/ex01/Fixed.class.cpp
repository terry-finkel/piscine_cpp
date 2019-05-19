#include "Fixed.class.hpp"

int const Fixed::_WIDTH = 8;

Fixed::Fixed () : _point(0), _value(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (float const value) : _point(0), _value((int)value) {

    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed (int const value) : _point(0), _value(value) {

    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (Fixed const &f) : _point(f._point), _value(f._value) {

    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed () {

    std::cout << "Destructor called" << std::endl;
}

Fixed &
Fixed::operator = (Fixed const &f) {

    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(f._value);
    return *this;
}

int
Fixed::getRawBits () const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void
Fixed::setRawBits (int const raw) {

    this->_value = raw;
}

float
Fixed::toFloat () const {

    int value = this->_value;

    for (int k = 0; k < this->_point; k++) value >> 1;

    return value;
}

int
Fixed::toInt () const {

    return this->_value;
}

std::ostream &
operator << (std::ostream &os, Fixed const &f) {

    os << f.toFloat();
    return os;
}
