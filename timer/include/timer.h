#ifndef TIME_H
#define TIME_H
#include <chrono>
using namespace std::chrono;
class timer{
    private:
        std::chrono::time_point<std::chrono::steady_clock> start_time;
        std::chrono::time_point<std::chrono::steady_clock> last_lap_time;
        bool running;
    public:
        timer();
        void start();
        double stop();
        void reset();
        double lap();
        bool isRunning();
};
#endif //TIME_H