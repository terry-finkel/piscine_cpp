#include "Fixed.class.hpp"
#include <cmath>

int const Fixed::_WIDTH = 8;

Fixed::Fixed () : _value(0) {}

Fixed::Fixed (float const value) {

    this->setRawBits(value);
}

Fixed::Fixed (int const value) {

    this->setRawBits(value);
}

Fixed::Fixed (Fixed const &f) : _value(f._value) {}

Fixed::~Fixed () {}

Fixed &
Fixed::operator = (Fixed const &rhs) {

    this->setRawBits(rhs._value);
    return *this;
}

bool
Fixed::operator > (Fixed const &rhs) const {

    return this->_value > rhs._value;
}

bool
Fixed::operator < (Fixed const &rhs) const {

    return this->_value < rhs._value;
}

bool
Fixed::operator >= (Fixed const &rhs) const {

    return this->_value >= rhs._value;
}

bool
Fixed::operator <= (Fixed const &rhs) const {

    return this->_value <= rhs._value;
}

bool
Fixed::operator == (Fixed const &rhs) const {

    return this->_value == rhs._value;
}

bool
Fixed::operator != (Fixed const &rhs) const {

    return this->_value != rhs._value;
}

Fixed
Fixed::operator + (Fixed const &rhs) const {

    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed
Fixed::operator - (Fixed const &rhs) const {

    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed
Fixed::operator * (Fixed const &rhs) const {

    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed
Fixed::operator / (Fixed const &rhs) const {

    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &
Fixed::operator ++ () {

    this->_value += 1;
    return *this;
}

Fixed const
Fixed::operator ++ (int const) {

    return Fixed(++(*this));
}

Fixed &
Fixed::operator -- () {

    this->_value -= 1;
    return *this;
}

Fixed const
Fixed::operator -- (int const) {

    return Fixed(--(*this));
}

int
Fixed::getRawBits () const {

    return this->_value;
}

Fixed &
Fixed::max (Fixed &a, Fixed &b) {

    return a > b ? a : b;
}

Fixed const &
Fixed::max (Fixed const &a, Fixed const &b) {

    return a > b ? a : b;
}

Fixed &
Fixed::min (Fixed &a, Fixed &b) {

    return a > b ? a : b;
}

Fixed const &
Fixed::min (Fixed const &a, Fixed const &b) {

    return a > b ? a : b;
}

void
Fixed::setRawBits (float const value) {

    this->_value = static_cast<int>(roundf(value * (1 << Fixed::_WIDTH)));
}

void
Fixed::setRawBits (int const value) {

    this->_value = value * (1 << Fixed::_WIDTH);
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
