#include "ThreadPoolLib/BlockingQueue.h"

#include <gtest/gtest.h>

namespace test
{
    namespace
    {
        class BlockingQueueTests
            : public ::testing::Test
        {
        public:
            ThreadPoolLib::BlockingQueue<int> queue_;
        };
    } // anonymous namespace

    TEST_F(BlockingQueueTests, test_SingleItem)
    {
        int x = 123;
        queue_.push(x);
        ASSERT_EQ(1, queue_.length());

        auto poppedValue = queue_.pop();
        ASSERT_EQ(x, poppedValue);
    }
}
