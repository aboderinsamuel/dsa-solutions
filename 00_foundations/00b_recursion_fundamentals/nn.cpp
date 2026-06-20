
#include <iostream>
class Animal {
public:
    void speakNonVirtual()  { std::cout << "Animal\n"; }   // NON-virtual
    virtual void speak()    { std::cout << "Animal\n"; }   // VIRTUAL
};
