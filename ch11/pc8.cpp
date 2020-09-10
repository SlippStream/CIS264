//Nick Zimanski - CIS264
//8 September 2020

#include <iostream>
#include <vector>
using namespace std;
const int NUM_CUST = 10;
const string DIV = "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
struct Customer
{
    string name;
    string address;
    string city;
    string state;
    int zip;
    int phoneNum;
    double accBalance;
    string dateOfLastPayment;
    bool dataPresent;
};
void displayCustomers(Customer c[], int d) {
    for (int i = 0; i < d; i++) {
        Customer s = c[i];
        cout << "Customer " << i+1 << ":\n";
        if (s.dataPresent) {
            cout << s.name << " (" << s.phoneNum << ")\n";
            cout << s.city << ", " << s.state << ", " << s.zip << endl;
            cout << "Balance: $" << s.accBalance << endl;
            cout << "Last payment: " << s.dateOfLastPayment << endl;
        }
        else {
            cout << "NO DATA FOUND\n";
        }
        cout << DIV;
    }
}
void displayCustomers(Customer c[]) {
    displayCustomers(c, 10);
}
Customer changeData(Customer &customer) {
    cin.ignore();
    cout << "Please enter the new name: ";
    getline(cin, customer.name);
    cout << "Please enter the new address: ";
    getline(cin, customer.address);
    cout << "Please enter the new city: ";
    getline(cin, customer.city);
    cout << "Please enter the new state: ";
    getline(cin, customer.state);
    do {
    cout << "Please enter the new zip: ";
    cin >> customer.zip;
    } while(customer.zip < 0);
    cout << "Please enter the new telephone number: ";
    cin >> customer.phoneNum;
    do {
    cout << "Please enter the new account balance: $";
    cin >> customer.accBalance;
    } while(customer.accBalance < 0);
    cout << "Please enter the new date of last payment (mm/dd/yyyy): ";
    cin >> customer.dateOfLastPayment;
    customer.dataPresent = true;
    return customer;
}
void searchFor(Customer *customers) {
    string n;
    int d;
    Customer* cs;
    cs = new Customer[NUM_CUST];
    cout << "Please enter the name to search for: ";
    getline(cin, n);
    for (int i = 0; i < NUM_CUST; i++) {
        if (customers[i].dataPresent) {
            if (customers[i].name.find(n) != string::npos) {
                *(cs+d) = customers[i];
                d++;
            }
        }
    }
    if (d > 0) {
        displayCustomers(cs, d);
    }
    else {
        cout << "-- NAME NOT FOUND --\n";
    }
}
void displayMenu(Customer *customers) {
    int in;
    do {
        cout << "\n- Enter the number of a customer to change their data\n- Enter 0 to display all customers' data\n- Enter \'-1\' to search for a name\n- Enter -2 to quit\n";
        cin >> in;
        if (in==-2) break;
        else if (in == -1) searchFor(customers);
        else if (in == 0) displayCustomers(customers);
        else if (in > 0 || in <= 10) customers[in-1] = changeData(customers[in-1]);
    } while (in != -2);
}
int main() {
    Customer customers[NUM_CUST];
    for (int i = 0; i < NUM_CUST; i++) {
        customers[i].dataPresent = false;
    }
    displayCustomers(customers);
    displayMenu(customers);
    return 0;
}