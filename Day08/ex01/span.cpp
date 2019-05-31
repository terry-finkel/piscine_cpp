#include "span.hpp"
#include <algorithm>
#include <climits>
#include <stdexcept>

span::span(unsigned int n) {

    _v.reserve(n);
}

span::span(span const &rhs) { *this = rhs; }

span::~span() {}

span &
span::operator=(span const &rhs) {

    _v = rhs._v;
    return *this;
}

void
span::addNumber(int n) {

    if (_v.size() == _v.capacity())
        throw std::runtime_error("max capacity reached");
    _v.push_back(n);
}

std::vector<int> const &
span::getSpan() const {

    return *(const_cast<std::vector<int> *>(&_v));
}

unsigned int
span::longestSpan() const {

    if (!(_v.size()) || _v.size() == 1)
        throw std::runtime_error("span doesn't contain enough elements");

    return std::abs(*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

unsigned int
span::shortestSpan() const {

    if (!(_v.size()) || _v.size() == 1)
        throw std::runtime_error("span doesn't contain enough elements");

    std::vector<int> copy = _v;
    std::sort(copy.begin(), copy.end());
    for (std::vector<int>::const_iterator it = copy.begin(); it != copy.end() - 1; it++) {
        if (*it != *(it + 1))
            return std::abs(*(it + 1) - *it);
    }

    return 0;
}
