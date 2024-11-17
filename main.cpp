#include "shared_ptr/shared_ptr.h"
#include "unique_ptr/unique_ptr.h"

#include <iostream>

struct Deleter
{
    void operator()(int *ptr) const
    {
        std::cout << "Deleting resource with value: " << *ptr << std::endl;
        delete ptr;
    }
};

int main()
{
    UniquePtr<int, Deleter> ptr1(new int(5));
    std::cout << "ptr1 value: " << *ptr1 << std::endl;

    ptr1.reset(new int(10));
    std::cout << "ptr1 value after resetting: " << *ptr1 << std::endl;

    // SharedPtr<int> ptr1(new int(5));
    // std::cout << "ptr1 count: " << ptr1.use_count() << std::endl;
    // std::cout << "ptr1 value: " << *ptr1 << std::endl;

    // {
    //     SharedPtr<int> ptr2 = ptr1;
    //     std::cout << "Ptr1 count after copy: " << ptr1.use_count() << std::endl;

    //     SharedPtr<int> ptr3 = ptr1;
    //     std::cout << "Ptr1 count after copy: " << ptr1.use_count() << std::endl;
    // }

    // ptr1.reset(new int(12));

    // std::cout << "Ptr1 count after ptr2 goes out of scope: " << ptr1.use_count() << std::endl;

    return 0;
}