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

    Canvas canvas = Canvas(80, 29);

    double t = 0;
    double accumulator = 0.0;
    std::timespec spec;
    double now;
    double last = getms(&spec);

    while(true) {
        now = getms(&spec);
        double passed_time = now-last;
        accumulator += passed_time;
        while(accumulator >= 16.66) {
            double factor = (cos(t*10) + 1) / 2.0;
            int x = 0;
        
            canvas.Clear();
            int width = 20;
            int height = 10;
            int y = 10;
            int size = 15;
            // Surprise
            //canvas.DrawLine(30, 10+height/2, 40 + size, 11+height/2, '#');
            //canvas.SetPoint(40 + size - 1, 10+height/2 - 1, 'O');
            //canvas.SetPoint(40 + size - 1, 10+height/2 + 1, 'O');
            canvas.DrawRect(x, y, x + width*factor*2.0, y + height, '+');
            canvas.Print();
            t += M_PI / 180.0;

            accumulator -= 16.66;
        }
    
        

        last = now;
    }

    return 0;
}
