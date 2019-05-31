#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class span {
private:
    std::vector<int>        _v;

public:
    explicit                span(unsigned int = 0);
                            span(span const &);
    virtual                 ~span();
    span                    &operator=(span const &);
    void                    addNumber(int);
    std::vector<int> const  &getSpan() const;
    unsigned int            longestSpan() const;
    unsigned int            shortestSpan() const;
};

#endif /* SPAN_HPP */
