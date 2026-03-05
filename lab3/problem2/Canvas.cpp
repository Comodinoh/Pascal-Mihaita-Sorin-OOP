#include "Canvas.h"
#include <cmath>
#include <print>
#include <cstring>

constexpr char EMPTY = ' ';


int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int clamp(int val, int lower, int higher) {
    return max(lower, min(val, higher));
}

void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

Canvas::Canvas(int width,int height) : m_canvas(new char*[height]), m_width(width), m_height(height) {
    for(int i = 0; i < height; i++) {
        char* rows = new char[width];
        memset(rows, EMPTY, sizeof(char)*width);

        m_canvas[i] = rows;
    }
}

Canvas::~Canvas() {
    for(int i = 0; i < m_height; i++) {
        char* rows = m_canvas[i];

        delete[] rows;
    }
    delete[] m_canvas;
}

void Canvas::DrawEllipse(int x, int y, int xray, int yray, char ch) {
    double rad = 0;
    const double rad_rate = M_PI/720.0;

    while(rad <= M_PI*2.0) {
        double x2d = std::cos(rad);
        double y2d = std::sin(rad);

        int x2 = x2d*xray;
        int y2 = y2d*yray;

        SetPoint(x + x2, y + y2, ch);

        rad += rad_rate;
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    DrawEllipse(x, y, ray*2, ray, ch);
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for(double i = ray; i > 0.0; i -= 0.5) {
        DrawEllipse(x, y, i*2, i, ch);
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom-1, right, bottom-1, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right-1, top, right-1, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    if(top > bottom) swap(top, bottom);
    if(left > right) swap(left, right);
    for(int y = top; y < bottom; y++) {
        for(int x = left; x < right; x++) {
            SetPoint(x, y, ch);
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if(x >= m_width || x < 0 || y >= m_height || y < 0) return;
    m_canvas[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    if(x1 == x2 && y1 == y2) return;
    if(x1 == x2) {
        if(y1 > y2) swap(y1, y2);
        y2 = min(y2, m_height);
        y1 = max(y1, 0);

        for(int y = y1; y < y2; y++) {
            SetPoint(x1, y, ch);
        }
    }
    else if(y1 == y2) {
        if(x1 > x2) swap(x1, x2);
        x2 = min(x2, m_height);
        x1 = max(x1, 0);

        for(int x = x1; x < x2; x++) {
            SetPoint(x, y1, ch);
        }
    }
    else {
        int dx = x2-x1;
        int dy = y2-y1;
        int x = x1;
        int y = y1;

        if(dx >= dy) {
            double slope = (double)dy/(double)dx;
            double acc = slope-1;
            while(x < x2 && y <= y2) {
                SetPoint(x, y, ch);
                x++;

                acc += slope;
            
                if(acc >= 0.5) {
                    y++;
                    acc -= 1.0;
                }
           }
        }else {
            double slope = (double)dx/(double)dy;
            double acc = slope-1;
            while(x <= x2 && y < y2) {
                SetPoint(x, y, ch);
                y++;

                acc += slope;
            
                if(acc >= 0.5) {
                    x++;
                    acc -= 1.0;
                }
            }
        }
    
        
    }
}

void Canvas::Print() {
    for(int y = 0; y < m_height; y++) {
        for(int x = 0; x < m_width; x++) {
            std::print("\x1B[48;2m{}", m_canvas[y][x]);
        }
        std::print("\n");
    }
} 
void Canvas::Clear() {
    for(int y = 0; y < m_height; y++) {
        std::memset(m_canvas[y], EMPTY, sizeof(char)*m_width);
    }
} 
