#include "Fixed.class.hpp"
#include <iostream>

int const Fixed::_WIDTH = 8;

Fixed::Fixed () : _value(0) {

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const &f) : _value(f._value) {

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
