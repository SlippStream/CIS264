//Nick Zimanski - CIS264
//24 September 2020

#include <iostream>
using namespace std;
class PayRoll {
    private:
        double hourlyPayRate;
        int hoursWorked;
        double totalPay;
    public:
        void setHourlyPayRate(double hourlyPayRate) {this->hourlyPayRate=hourlyPayRate;}
        void setHoursWorked(int hoursWorked) {this->hoursWorked=hoursWorked;}
        double getTotalPay() {return hourlyPayRate *hoursWorked;}
};
int main() {
    PayRoll pr[7];
    double hpr;
    int hw;
    for (int i=0; i<7;i++) {
        hw = hpr = 0;
        do {
        cout << "Please enter the hours worked for employee " << i+1 << ": ";
        cin >> hw;
        } while (hw > 60 || hw < 0);
        do {
        cout << "Please enter the hourly pay for employee " << i+1 << ": $";
        cin >> hpr;
        } while (hw < 0);
        pr[i].setHourlyPayRate(hpr);
        pr[i].setHoursWorked(hw);
    }
    cout << endl;
    for (int o=0; o<7;o++) {
        cout << "Employee " << o+1 << ": $" << pr[o].getTotalPay() << endl;
    }
    return 0;
}