#include <windows.h>
#ifndef hr_timer
#include "hr_time.h"
#define hr_timer
#endif // hr_timer

void startTimer(stopWatch *timer){
    QueryPerformanceCounter(&timer->start);
    return;
}

void stopTimer(stopWatch *timer){
    QueryPerformanceCounter(&timer->stop);
    return;
}

double LITOSecs(LARGE_INTEGER *L){
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    return ((double)L->QuadPart/(double)frequency.QuadPart)*1000;
}

double getElapsedTime(stopWatch *timer){
    LARGE_INTEGER time;
    time.QuadPart = timer->stop.QuadPart - timer->start.QuadPart;
    return LITOSecs(&time);
}
