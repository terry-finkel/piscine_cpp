#include "CentralBureaucracy.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

CentralBureaucracy::CentralBureaucracy() : _currentBlock(0), _blockCount(0), _queueHead(NULL), _queueTail(NULL) {

    srand(time(0));
    for (int k = 0; k < OFFICE_MAX; k++) {
        _blocks[k] = NULL;
    }
}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &rhs) { *this = rhs; }

CentralBureaucracy::~CentralBureaucracy() {

    _clearOffice();
    _clearQueue();
}

CentralBureaucracy &
CentralBureaucracy::operator=(CentralBureaucracy const &rhs) {

    _clearOffice();
    _clearQueue();

    for (int k = 0; k < OFFICE_MAX; k++) {
        _blocks[k] = rhs._blocks[k];
    }

    _currentBlock = rhs._currentBlock;
    _blockCount = rhs._blockCount;
    _queueHead = rhs._queueHead;
    _queueTail = rhs._queueTail;
    return *this;
}

void
CentralBureaucracy::_clearOffice() {

    for (unsigned int k = 0; k < _blockCount; k++) {
        delete _blocks[k]->getIntern();
        delete _blocks[k]->getSigningBureaucrat();
        Bureaucrat *exec = _blocks[k]->getExecutingBureaucrat();

        if (exec) delete exec;
    }
}

void
CentralBureaucracy::_clearQueue() {

    for (CentralBureaucracy::queue_t *link = _queueHead, *tmp; link; link = tmp) {
        tmp = link->next;
        delete link;
    }
}

void
CentralBureaucracy::doBureaucracy() {

    std::string bureaucracy[3] = {
            "presidential pardon",
            "robotomy request",
            "shrubbery creation"
    };

    if (_queueTail) {

        _blocks[_currentBlock]->doBureaucracy(bureaucracy[rand() % 3], _queueTail->name);

        /* Offices are called one after the other. */
        _currentBlock = (_currentBlock == OFFICE_MAX ? 0 : _currentBlock + 1);

        if ((_queueTail = _queueTail->prev) == NULL) _queueHead = NULL;
    }
}

void
CentralBureaucracy::feed(Bureaucrat *b) {

    if (_blockCount == OFFICE_MAX) {
        std::cout << "Thanks for applying but all our blocks are currently occupied." << std::endl;
        delete b;
        return;
    }

    if (_blocks[_blockCount] == NULL) {
        _blocks[_blockCount] = new OfficeBlock();
        _blocks[_blockCount]->setIntern(new Intern());
        _blocks[_blockCount]->setSigningBureaucrat(b);
    } else {
        _blocks[_blockCount]->setExecutingBureaucrat(b);
        _blockCount += 1;
    }
}

void
CentralBureaucracy::queueUp(std::string const &name) {

    CentralBureaucracy::queue_t *it = new CentralBureaucracy::queue_t;

    if (_queueHead != NULL) _queueHead->prev = it;

    it->name = name;
    it->next = _queueHead;
    it->prev = NULL;
}
