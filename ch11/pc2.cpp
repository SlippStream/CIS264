//Nick Zimanski - CIS264
//30 August 2020

#include <iostream>
using namespace std;
struct MovieData {
        string title;
        string director;
        int yearReleased;
        int runningTime;
        int cost;
        int revenue;
};
void displayMovieData(MovieData m) {
    cout << m.title << " (" << m.yearReleased << ")\n";
    cout << "Directed by " << m.director << endl;
    cout << m.runningTime << " minutes\n";
    cout << "First year net income: $" << m.revenue - m.cost << endl;
}
int main() {
    MovieData m1 = {"Inglorious Basterds", "Quentin Tarantino", 2009, 153, 70000000, 321500000};
    MovieData m2 = {"Parasite", "Bong Joon Ho", 2019, 132, 11400000, 264300000};

    displayMovieData(m1);
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    displayMovieData(m2);
    return 0;
}