#pragma once

namespace ThreadPoolLib
{
    template <typename T>
    class IBlockingQueue
    {
    public:
        virtual ~IBlockingQueue() {}

        virtual T pop() = 0;
        virtual void push(const T & value) = 0;
        virtual bool isEmpty() = 0;
        virtual long length() = 0;
    };
}
