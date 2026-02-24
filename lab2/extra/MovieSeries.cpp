#include "MovieSeries.h"
#include <format>
#include <iostream>


void MovieSeries::init() {
  m_count = 0;
}

bool MovieSeries::add(Movie* movie) {
  if(m_count >= MOVIE_SERIES_MAX) return false;
  
  m_movies[m_count++] = movie;
  return true;
}

void MovieSeries::print() {
  for(std::size_t idx = 0; idx < m_count; idx++) {
    Movie* movie = m_movies[idx];
    // C++20 fancy formatting  :) (introduced from popular library fmt)
    std::cout << std::format("Movie: \"{}\" | Release Year: {} | Length: {}m | IMDB Score: {}/10 | Passed Years: {}", 
        movie->get_name(), movie->get_year(), movie->get_length(), movie->get_score(), movie->get_passed_years()) << std::endl;
  }
}
void MovieSeries::sort() {
  bool swapped = false;
  for(std::size_t i = 0; i < m_count-1; i++) {
    for(std::size_t j = 0; j < m_count-j-1; j++) {
      int p1 = m_movies[j]->get_passed_years();
      int p2 = m_movies[j+1]->get_passed_years();

      if(p1 < p2) {
        Movie* temp = m_movies[j];
        m_movies[j] = m_movies[j+1];
        m_movies[j+1] = temp;
        swapped = true;
      }
    }
    if(!swapped) break;
  }
}
