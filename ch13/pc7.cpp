//Nick Zimanski - CIS264
//24 September 2020

#include <iostream>
using namespace std;
class TestScores {
    private:
        int scores[3];
    public:
        TestScores(int s1, int s2, int s3) {
            scores[0] = s1;
            scores[1] = s2;
            scores[2] = s3;
        }
        int getScore(int index) {return scores[index-1];}
        void setScore(int index, int newScore) {scores[index-1] = newScore;}
        double getAverage() {return (scores[0] + scores[1] + scores[2])/3;}

};
int main() {
    int s1, s2, s3;
    cout << "Please enter score 1: ";
    cin >> s1;
    cout << "Please enter score 2: ";
    cin >> s2;
    cout << "Please enter score 3: ";
    cin >> s3;
    TestScores t = TestScores(s1, s2, s3);
    cout << "Average: " << t.getAverage();
    return 0;
}