#include <cstddef>
#include <exception>

template <typename T = int>
class Array {
private:
    T               *_array;
    size_t          _size;

public:
    Array(unsigned int n = 0) : _array(new T[n]), _size(n) {}

    Array(Array const &rhs) { *this = rhs; }

    virtual ~Array() { delete [] _array; }

    Array &operator=(Array const &rhs) {

        delete [] _array;
        _array = new T[_size];
        _size = rhs._size;

        for (size_t k = _size; k < rhs._size; k++) {
            _array[k] = rhs._array[k];
        }

        return *this;
    }

    T &operator[](unsigned int idx) {

        if (idx >= _size) throw std::exception();

        return _array[idx];
    }

    unsigned int size() const { return _size; }
};
