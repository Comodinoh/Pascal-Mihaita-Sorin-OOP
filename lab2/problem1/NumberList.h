#pragma once

class NumberList {
public:
    void Init();
    bool Add(int x);

    void Sort();
    void Print();
private:
    int m_numbers[10];
    int m_count;
};
