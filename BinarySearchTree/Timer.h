#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class Timer {
public:
	Timer() {
		startTime.QuadPart = 0;
		QueryPerformanceFrequency(&frequency);
	}

	void start() {
		QueryPerformanceCounter(&startTime);
	}

	unsigned long getTimeMicroseconds() {
		LARGE_INTEGER curTime;
		QueryPerformanceCounter(&curTime);
		LONGLONG ellapsedTicks = curTime.QuadPart - startTime.QuadPart;
		double ellapsedSeconds = (double)ellapsedTicks / (double)frequency.QuadPart;

		return (unsigned long)(ellapsedSeconds * 1000000);
	}

private:
	LARGE_INTEGER startTime, frequency;
};