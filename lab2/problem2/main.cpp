#include <iostream>

#include "Student.h"
#include "StudentCompare.h"

int main() {
    Student first;
    first.SetName("Bogdan");
    first.SetMathGrade(6.7);
    first.SetEnglishGrade(1.0);
    first.SetHistoryGrade(10.0);

    Student second;
    second.SetName("Florin");
    second.SetMathGrade(100.0f);
    second.SetEnglishGrade(10.0f);
    second.SetHistoryGrade(9.6f);

    first.Print();
    second.Print();

    int compare_name = CompareStudentNames(first, second);
    int compare_math = CompareStudentMath(first, second);
    int compare_history = CompareStudentHistory(first, second);
    int compare_english = CompareStudentEnglish(first, second);
    int compare_avg = CompareStudentAverage(first, second);

    std::cout << first.GetName() << " has " << (compare_name == 0 ? "the same name as " : (compare_name == 1 ? "a bigger name than " : "a smaller name than ")) << second.GetName() << std::endl;
    std::cout << first.GetName() << " has " << (compare_math == 0 ? "the same math grade as " : (compare_math == 1 ? "a bigger math grade than " : "a smaller math grade than ")) << second.GetName() << std::endl;
    std::cout << first.GetName() << " has " << (compare_history == 0 ? "the same history grade as " : (compare_history == 1 ? "a bigger history grade than " : "a smaller history grade than ")) << second.GetName() << std::endl;
    std::cout << first.GetName() << " has " << (compare_english == 0 ? "the same english grade as " : (compare_english == 1 ? "a bigger english grade than " : "a smaller english grade than ")) << second.GetName() << std::endl;
    std::cout << first.GetName() << " has " << (compare_avg == 0 ? "the same average grade as " : (compare_avg == 1 ? "a bigger average grade than " : "a smaller average grade than ")) << second.GetName() << std::endl;
    return 0;
}
