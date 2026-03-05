#include "Canvas.h"
#include <cmath>
#include <thread>
#include <chrono>
#include <ctime>

using namespace std::chrono_literals;

double FromDegToRad(int deg) {
    return deg * (M_PI / 180.0);
}

double getms(std::timespec* spec) {
    clock_gettime(CLOCK_MONOTONIC, spec);

    return spec->tv_sec*1000.0 + spec->tv_nsec/1000000.0;
}

int main() {

    Canvas canvas = Canvas(80, 40);

    long long t = 0;
    double accumulator = 0.0;
    std::timespec spec;
    double now = getms(&spec);
    double last = 0.0;

    while(true) {
        now = getms(&spec);
        double passed_time = now-last;
        last = now;
        accumulator += passed_time;

        system("clear");
        while(accumulator >= 1/30.0) {
            int x = abs(floor(cos(t*(1/30.0))*40.0));

            canvas.DrawLine(0, 0, x, 39 , '+');
            canvas.Print();
            canvas.Clear();

            accumulator -= 1/30.0;
        }
    
        
        t++;
    }
    canvas.Print();
    return 0;
}
