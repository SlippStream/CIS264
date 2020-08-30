//Nick Zimanski - CIS264
//30 August 2020

#include <iostream>
using namespace std;
struct MovieData {
        string title;
        string director;
        int yearReleased;
        int runningTime;
};
void displayMovieData(MovieData m) {
    cout << m.title << " (" << m.yearReleased << ")\n";
    cout << "Directed by " << m.director << endl;
    cout << m.runningTime << " minutes\n";
}
int main() {
    MovieData m1 = {"Inglorious Basterds", "Quentin Tarantino", 2009, 153};
    MovieData m2 = {"Parasite", "Bong Joon Ho", 2019, 132};

    displayMovieData(m1);
    cout << "-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
    displayMovieData(m2);
    return 0;
}