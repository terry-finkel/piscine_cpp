#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>

template <typename T>
int
easyfind(T &x, int y) {

    typename T::iterator n;

    if ((n = std::find(x.begin(), x.end(), y)) != x.end())
        return std::distance(x.begin(), n);

    throw std::exception();
}

#endif /* EASYFIND_HPP */
