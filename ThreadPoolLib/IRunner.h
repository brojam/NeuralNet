#pragma once
#include <thread>

class IRunner
    : public std::thread
{
	virtual ~IRunner() = 0;

	virtual void run() = 0;
	virtual void stop() = 0;
};
