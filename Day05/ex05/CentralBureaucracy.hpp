#ifndef CENTRALBUREAUCRACY_HPP
# define CENTRALBUREAUCRACY_HPP

# include <iostream>

# define OFFICE_MAX 20

class Bureaucrat;
class OfficeBlock;

class CentralBureaucracy {

    typedef struct      queue {
        std::string     &name;
        struct queue    *next;
        struct queue    *prev;
    }                   queue_t;

private:
    OfficeBlock         *_blocks[OFFICE_MAX];
    unsigned int        _currentBlock;
    unsigned int        _blockCount;
    queue_t             *_queueHead;
    queue_t             *_queueTail;
    void                _clearOffice();
    void                _clearQueue();

public:
                        CentralBureaucracy();
                        CentralBureaucracy(CentralBureaucracy const &);
    virtual             ~CentralBureaucracy();
    CentralBureaucracy  &operator=(CentralBureaucracy const &);
    void                doBureaucracy();
    void                feed(Bureaucrat *);
    void                queueUp(std::string const &);
};

#endif /* CENTRALBUREAUCRACY_HPP */
