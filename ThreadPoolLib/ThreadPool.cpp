#include "ThreadPool.h"

namespace ThreadPoolLib
{
    ThreadPool::ThreadPool(int threadCount, IBlockingQueue<std::function<void()>> & workQueue)
        :
    stopped_{ false },
    workQueue_ {}
    {
        workQueue_ = workQueue;

         for(auto i = 0; i < threadCount; ++i)
         {
             workers_.push_back(std::thread {
                [this]() -> void
                {
                    while(!stopped_ || !workQueue_.isEmpty())
                    {
                        // Will block until there is work to complete
                        auto work = workQueue_.pop();
                        work();
                    }
                }
             });
         }
    }

    ThreadPool::~ThreadPool()
    {
        stop();
    }

    void ThreadPool::addWork(std::function<void()> & work) noexcept
    {
        workQueue_.push(work);
    }

    void ThreadPool::stop() noexcept
    {
        stopped_ = true;
    }
}
