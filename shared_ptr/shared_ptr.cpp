#include "shared_ptr.h"

SharedPtr::SharedPtr()
{
    std::cout << "SharedPtr ctor" << std::endl;
}

SharedPtr::~SharedPtr()
{
    std::cout << "SharedPtr dtor" << std::endl;
}