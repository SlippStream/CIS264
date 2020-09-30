//Nick Zimanski - CIS264
//22 September 2020

#include <iostream>
using namespace std;
class Employee {
    private:
        string name;
        int idNumber;
        string department;
        string position;
    public: 
        Employee(string name, int idNumber, string department, string position) {
            this->name = name;
            this->idNumber = idNumber;
            this->department = department;
            this->position =position;
        }
        Employee(string name, int idNumber) {
            Employee(name, idNumber, "", "");
        }
        Employee() {Employee("", 0);}
        void setName(string name) {this->name=name;}
        void setIdNumber(int idNumber) {this->idNumber=idNumber;}
        void setDepartment(string department) {this->department=department;}
        void setPosition(string position) {this->position=position;}
        string getName() {return name;}
        int getIdNumber() {return idNumber;}
        string getDepartment() {return department;}
        string getPosition() {return position;}
};
int main() {
    Employee e[3] = {Employee("Susan Meyers", 47899, "Accounting", "Vice President"),
                    Employee("Mark Jones", 39119, "IT", "Programmer"),
                    Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")};

    for (int i=0; i<3; i++) {
       cout << e[i].getName() << " #" << e[i].getIdNumber() << " (" <<e[i].getPosition() << ", " << e[i].getDepartment() << ")\n"; 
    }
    return 0;
}