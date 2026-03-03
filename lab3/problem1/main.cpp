#include "Math.h"
#include <iostream>
#include <print>


int main() {
    int a = 2, b = 3, c = 5;
    double d = 2.5, e = 4.3, f =  3.4;
    const char* s1 = "Hello";
    const char* s2 = ", World!";


    std::println("{} + {} = {}", a, b, Math::Add(a, b));
    std::println("{} + {} + {} = {}", a, b, c, Math::Add(a, b, c));
    std::println("{} * {} = {}", a, b, Math::Mul(a, b));
    std::println("{} * {} * {} = {}", a, b, c, Math::Mul(a, b, c));

    std::println("{} + {} = {}", d, e, Math::Add(d, e));
    std::println("{} + {} + {} = {}", d, e, f, Math::Add(d, e, f));
    std::println("{} * {} = {}", d, e, Math::Mul(d, e));
    std::println("{} * {} = {}", d, e, f, Math::Mul(d, e, f));

    char* s3 = Math::Add(s1, s2);
    std::println("\"{}\" + \"{}\" = \"{}\"", s1, s2, s3);

    delete[] s3;

    int g = 6;
    std::println("{} + {} + {} + {} = {}", a, b, c, g, Math::Add(4, a, b, c, g));

    return 0;
}
