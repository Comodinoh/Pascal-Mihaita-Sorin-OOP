#pragma once

class Student {
public:
    ~Student();

    const char* GetName() const;
    void SetName(const char* name);

    float GetMathGrade() const;
    float GetEnglishGrade() const;
    float GetHistoryGrade() const;
    void SetMathGrade(float grade);
    void SetEnglishGrade(float grade);
    void SetHistoryGrade(float grade);

    float GetAverageGrade() const;

    void Print();
private:
    char* m_name = nullptr;
    float m_math;
    float m_english;
    float m_history;
};
