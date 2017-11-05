#pragma once
#include "IRunner.h"
#include "BlockingQueue.h"

namespace ThreadPoolLib
{
    class Runner
        : public IRunner, std::thread
    {
    public:
        Runner(BlockingQueue<IRunner> workQueue_);

        void Runner::run() override;
        void Runner::stop() override;

    private:
        BlockingQueue<std::function<void()>> & workQueue_;
        bool isStopped_;
    };
}

