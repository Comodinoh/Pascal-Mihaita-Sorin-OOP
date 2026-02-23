#pragma once
#include <string>

class Student {
public:
    const std::string& GetName() const;
    void SetName(const std::string& name);

    float GetMathGrade() const;
    float GetEnglishGrade() const;
    float GetHistoryGrade() const;
    void SetMathGrade(float grade);
    void SetEnglishGrade(float grade);
    void SetHistoryGrade(float grade);

    float GetAverageGrade() const ;

    void Print();
private:
    std::string m_name;
    float m_math;
    float m_english;
    float m_history;
};
