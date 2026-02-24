#include "MovieCmp.h"
#include <cstring>

std::size_t max(std::size_t a, std::size_t b) {
    return a > b ? b : a;
}

int string_compare(const char* first, const char* second) {
  if(first == second) return 0;

  std::size_t first_len = std::strlen(first);
  std::size_t second_len = std::strlen(second);

  std::size_t smallest = max(first_len, second_len);

  std::size_t idx = 0;
  while(idx < smallest) {
    char c1 = first[idx];
    char c2 = second[idx];
    idx++;
    if(c1 == c2) continue;
    if(c1 > c2) return 1;
    return -1;
  }

  if(first_len == second_len) return 0;
  if(idx != first_len) return 1;
  return -1;
}

int int_compare(int first, int second) {
  if(first == second) return 0;
  if(first > second) return 1;
  return -1;
}

double double_compare(double first, double second) {
  if(first == second) return 0;
  if(first > second) return 1;
  return -1;
}

int movie_compare_name(const Movie& first, const Movie& second) {
  return string_compare(first.get_name(), second.get_name());
}
int movie_compare_year(const Movie& first, const Movie& second) {
  return int_compare(first.get_year(), second.get_year());
}
int movie_compare_score(const Movie& first, const Movie& second) {
  return double_compare(first.get_score(), second.get_score());
}
int movie_compare_length(const Movie& first, const Movie& second) {
  return int_compare(first.get_length(), second.get_length());
}
int movie_compare_passed_years(const Movie& first, const Movie& second) {
  return int_compare(first.get_passed_years(), second.get_passed_years());
}
