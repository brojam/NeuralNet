#pragma once

#include "IThreadPool.h"
#include "IBlockingQueue.h"
#include <vector>
#include <condition_variable>

namespace ThreadPoolLib
{
    enum class Priority
    {
        High, Medium, Low
    };

    class ThreadPool
        : public IThreadPool
    {
    public: // Implements IThreadPool
        ThreadPool(int threadCount, IBlockingQueue<std::function<void()>> & workQueue);

        ~ThreadPool() override;

        void addWork(std::function<void()> & work) noexcept override;
        void stop() noexcept override;

    private:
        std::condition_variable condition_;
        std::mutex mutex_;
        bool stopped_;
        std::vector<std::thread> workers_;
        IBlockingQueue<std::function<void()>> & workQueue_;
    };
}
