#include <iostream>

class Base {
public:
    virtual ~Base() {};
};

class A : public Base {
public:
    A() {};
    ~A() {};
};

class B : public Base {
public:
    B() {};
    ~B() {};
};

class C : public Base {
public:
    C() {};
    ~C() {};
};

Base *
generate() {

    srand(time(0));
    int r = rand() % 3;
    Base *base;

    if (!r) base = new A;
    else if (r == 1) base = new B;
    else base = new C;

    return base;
}

void
identify_from_pointer(Base *b) {

    if (dynamic_cast<A *>(b)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(b)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(b)) {
        std::cout << "C" << std::endl;
    }
}

void
identify_from_reference(Base &b) {

    if (dynamic_cast<A *>(&b)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(&b)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(&b)) {
        std::cout << "C" << std::endl;
    }
}

int
main () {

    Base *base = generate();
    std::cout << "Identifying from pointer: ";
    identify_from_pointer(base);
    std::cout << "Identifying from reference: ";
    identify_from_reference(*base);
    return 0;
}
