#pragma once

#define MOVIE_NAME_MAX_CHARACTERS 256

class Movie {
public:
    const char* get_name() const;
    void set_name(const char* name);

    int get_year() const;
    void set_year(int new_year);

    double get_score() const;
    void set_score(double new_score);

    int get_length() const;
    void set_length(int new_length);

    int get_passed_years() const;
private:
    char m_name[MOVIE_NAME_MAX_CHARACTERS];

    int m_year;
    int m_length;
    double m_score;
};
