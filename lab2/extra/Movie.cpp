#include "Movie.h"
#include <cstring>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

const char* Movie::get_name() const {
  return m_name;
}
void Movie::set_name(const char* name) {
  std::strcpy(m_name, name);
}

int Movie::get_year() const {
  return m_year;
}
void Movie::set_year(int new_year) {
  m_year = new_year;
}

double Movie::get_score() const {
  return m_score;
}
void Movie::set_score(double new_score) {
  m_score = std::clamp(new_score, 1.0, 10.0);
}

int Movie::get_length() const {
  return m_length;
}
void Movie::set_length(int new_length) {
  m_length = new_length;
}

int Movie::get_passed_years() const {
  // hell.
  system_clock::time_point now = system_clock::now();
  year_month_day ymd = {round<days>(now)};

  return (int)ymd.year() - m_year;
}
