#include "Student.h"
#include <iostream>
#include <algorithm>

const char* Student::GetName() const {return m_name;}
void Student::SetName(const char* name) {
    m_name = name;
}

float Student::GetMathGrade() const {
    return m_math;
}
float Student::GetEnglishGrade() const {
    return m_english;
}
float Student::GetHistoryGrade() const {
    return m_history;
}

void Student::SetMathGrade(float grade) {
    m_math = std::clamp(grade, 1.0f, 10.0f);
}
void Student::SetEnglishGrade(float grade) {
    m_english = std::clamp(grade, 1.0f, 10.0f);
}
void Student::SetHistoryGrade(float grade) {
    m_history = std::clamp(grade, 1.0f, 10.0f);
}

float Student::GetAverageGrade() const {
    return (m_math + m_english + m_history) / 3.0f;
}

void Student::Print() {
    std::cout << "{name: " << m_name <<
    ", math_grade: " << m_math << ", english_grade: " << m_english << ", history_grade: " << m_history
    << ", average_grade: " << GetAverageGrade() << "}" << std::endl;
}

