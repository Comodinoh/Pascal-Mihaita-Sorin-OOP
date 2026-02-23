#include "NumberList.h"
#include <iostream>

void NumberList::Init() {
    m_count = 0;
}

bool NumberList::Add(int x) {
    if(m_count >= 10) {
        return false;
    }

    m_numbers[m_count++] = x;
    return true;
}

void NumberList::Sort() {
    bool swapped = false;
    for(size_t i = 0; i < m_count-1; i++) {
        for(size_t j = 0; j < m_count-i-1; j++) {
            if(m_numbers[j] >= m_numbers[j+1]) {
                int temp = m_numbers[j];
                m_numbers[j] = m_numbers[j+1];
                m_numbers[j+1] = temp;
                
                swapped = true;
            }
        }

        if(!swapped) break;
    }
}

void NumberList::Print() {
    std::cout << "[";
    for(size_t i = 0; i < m_count-1; i++) {
        std::cout << m_numbers[i] << ", ";
    }
    std::cout << m_numbers[m_count-1] << "]" << std::endl;
}
