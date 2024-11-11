#include "shared_ptr/shared_ptr.h"

int main()
{
    SharedPtr<int> ptr1(new int(5));
    std::cout << "ptr1 count: " << ptr1.count() << std::endl;
    std::cout << "ptr1 value: " << *ptr1 << std::endl;

    {
        SharedPtr<int> ptr2 = ptr1;
        std::cout << "Ptr1 count after copy: " << ptr1.count() << std::endl;

        SharedPtr<int> ptr3 = ptr1;
        std::cout << "Ptr1 count after copy: " << ptr1.count() << std::endl;
    }

    ptr1.reset(new int(12));

    std::cout << "Ptr1 count after ptr2 goes out of scope: " << ptr1.count() << std::endl;

    return 0;
}