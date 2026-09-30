#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Movie {
public:
    Movie(const std::string& title, int year, double rating)
        : title(title), year(year), rating(rating) {}

    const std::string& getTitle() const {
        return title;
    }

    int getYear() const {
        return year;
    }

    double getRating() const {
        return rating;
    }

private:
    std::string title;
    int year;
    double rating;
};

int main() {
    std::vector<Movie> movies;

    movies.emplace_back("Inception", 2010, 8.8);
    movies.emplace_back("Interstellar", 2014, 8.7);
    movies.emplace_back("Arrival", 2016, 7.9);
    movies.emplace_back("The Prestige", 2006, 8.5);

    std::sort(movies.begin(), movies.end(),
        [](const Movie& a, const Movie& b) {
            return a.getRating() > b.getRating();
        });

    std::cout << "Movie Collection\n";
    std::cout << "================\n";

    for (const auto& movie : movies) {
        std::cout << movie.getTitle()
                  << " | "
                  << movie.getYear()
                  << " | "
                  << movie.getRating()
                  << std::endl;
    }

    return 0;
}