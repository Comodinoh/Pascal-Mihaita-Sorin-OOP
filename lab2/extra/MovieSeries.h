#pragma once

#include "Movie.h"
#include <cstdint>

#define MOVIE_SERIES_MAX 16

class MovieSeries {
public:
  void init();

  bool add(Movie* movie);
  void print();
  void sort();
private:
  Movie* m_movies[MOVIE_SERIES_MAX];
  std::size_t m_count;
};
