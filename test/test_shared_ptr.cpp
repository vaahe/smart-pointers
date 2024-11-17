#include "shared_ptr/shared_ptr.h"
#include <gtest/gtest.h>

TEST(SharedPtrTest, BasicInitialization)
{
    SharedPtr<int> ptr(new int(5));
    EXPECT_EQ(*ptr, 5);
    EXPECT_EQ(ptr.use_count(), 1);
}