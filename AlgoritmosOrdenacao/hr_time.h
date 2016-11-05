typedef struct {
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
}stopWatch;

void startTimer(stopWatch *timer);

void stopTimer(stopWatch *timer);

double LITOSecs(LARGE_INTEGER *L);

double getElapsedTime(stopWatch *timer);
