#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator    iterator;
                                                                MutantStack() : std::stack<T>() {}
                                                                MutantStack(MutantStack const &rhs) { *this = rhs; }
    virtual                                                     ~MutantStack() {}
    MutantStack                                                 &operator=(MutantStack const &rhs) {

        std::stack<T>::operator=(rhs);
        return *this;
    }
    iterator                                                    begin() { return std::stack<T>::c.begin(); }
    iterator                                                    end() { return std::stack<T>::c.end(); }
};

#endif /* MUTANTSTACK_HPP */
