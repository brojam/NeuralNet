#pragma once

#include "IRunner.h"

namespace ThreadPoolLib
{
    class IThreadPool
    {
    public:
        virtual ~IThreadPool() {}

        virtual void addWork(std::function<void()> & work) noexcept = 0;
        virtual void stop() noexcept = 0;
    };
}
