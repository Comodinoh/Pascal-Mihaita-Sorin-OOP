#include "Math.h"

#include <cstdarg>
#include <cstdlib>
#include <cstring>

int Math::Add(int a, int b) {
    return a + b;
}
int Math::Add(int a, int b, int c) {
    return a + b + c;
}
int Math::Add(double a, double b) {
    // Explicitly cast to int (aka floor) since it doesn't specify rounding method to use 
    return (int)(a + b);
}
int Math::Add(double a, double b, double c) {
    return (int)(a + b + c);
}
int Math::Mul(int a, int b) {
    return a * b;
}
int Math::Mul(int a, int b, int c) {
    return a * b * c;
}
int Math::Mul(double a, double b) {
    return (double)(a * b);
}
int Math::Mul(double a, double b, double c) {
    return (double)(a * b * c);
}
char* Math::Add(const char * a, const char * b) {
    if(a == nullptr || b == nullptr) return nullptr;
    size_t alen = strlen(a);
    size_t blen = strlen(b);
    
    size_t reslen = alen+blen;
    char* result = new char[reslen+1];

    result[reslen] = '\0';

    for(size_t i = 0; i < alen; i++) {
        result[i] = a[i];
    }
    for(size_t j = 0; j < blen; j++) {
        result[alen+j] = b[j];
    }

    return result;
}
int Math::Add(int count,...) {
    va_list args;
    va_start(args, count);

    int sum = 0;
    for(size_t idx = 0; idx < count; idx++) {
        sum += va_arg(args, int);
    }

    va_end(args);

    return sum;
} // sums up a list of integers
