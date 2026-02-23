#include "StudentCompare.h"
int max(int a, int b) {
    return a > b ? b : a;
}

int CompareStudentNames(const Student& first, const Student& second) {
    return first.GetName().compare(second.GetName());
}
int CompareStudentMath(const Student& first, const Student& second) {
    float first_math = first.GetMathGrade();
    float second_math = second.GetMathGrade();
    if(first_math == second_math) return 0;
    if(first_math > second_math) return 1;
    return -1;
}
int CompareStudentHistory(const Student& first, const Student& second) {
    float first_history = first.GetHistoryGrade();
    float second_history = second.GetHistoryGrade();
    if(first_history == second_history) return 0;
    if(first_history > second_history) return 1;
    return -1;
}
int CompareStudentEnglish(const Student& first, const Student& second) {
    float first_english = first.GetEnglishGrade();
    float second_english = second.GetEnglishGrade();
    if(first_english == second_english) return 0;
    if(first_english > second_english) return 1;
    return -1;
}
int CompareStudentAverage(const Student& first, const Student& second) {
    float first_avg = first.GetAverageGrade();
    float second_avg = second.GetAverageGrade();
    if(first_avg == second_avg) return 0;
    if(first_avg > second_avg) return 1;
    return -1;
}
