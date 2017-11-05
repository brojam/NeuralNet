#pragma once
#include "IBlockingQueue.h"
#include <queue>
#include <condition_variable>

namespace ThreadPoolLib
{
    template <typename T>
    class BlockingQueue
        : public IBlockingQueue<T>
    {
    public:
        BlockingQueue();
        BlockingQueue(BlockingQueue & queue);
        ~BlockingQueue() override;

        T pop() override;
        void push(const T & value) override;
        bool isEmpty() override;
        long length() override;

    private:
        std::queue<T> queue_;
        std::mutex mutex_;
        std::condition_variable condition_;
    };

    template <typename T>
    BlockingQueue<T>::BlockingQueue()
        :
        mutex_ {},
        condition_ {}
    {
        queue_ = std::queue<T>{};
    }

    template <typename T>
    BlockingQueue<T>::BlockingQueue(BlockingQueue<T> & queue)
        :
        mutex_ {},
        condition_ {},
        queue_ { queue }
    {
    }

    template <typename T>
    BlockingQueue<T>::~BlockingQueue()
    {
        
    }

    template <typename T>
    T BlockingQueue<T>::pop()
    {
        std::unique_lock<std::mutex> lock(mutex_);

        while (queue_.empty())
        {
            condition_.wait(lock);
        }

        auto item = queue_.front();
        queue_.pop();

        return item;
    }

    template <typename T>
    void BlockingQueue<T>::push(const T & value)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        queue_.push(value);
        lock.unlock();
        condition_.notify_one();
    }

    template <typename T>
    bool BlockingQueue<T>::isEmpty()
    {
        return queue_.empty();
    }

    template <typename T>
    long BlockingQueue<T>::length()
    {
        return queue_.size();
    }
}
