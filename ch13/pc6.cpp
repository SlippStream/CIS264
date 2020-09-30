//Nick Zimanski - CIS264
//22 September 2020

#include <iostream>
using namespace std;
class Inventory {
    private:
        int itemNumber;
        int quantity;
        double cost;
        double totalCost;
    public:
        Inventory() {Inventory(0,0,0);}
        Inventory(int itemNumber, int quantity, double cost) {
            this->cost=cost;
            this->itemNumber=itemNumber;
            this->quantity=quantity;
            setTotalCost();
        }
        void setItemNumber(int itemNumber) {this->itemNumber=itemNumber;}
        void setQuantity(int quantity) {this->quantity=quantity;}
        void setCost(int cost) {this->cost=cost;}
        void setTotalCost() {this->totalCost=quantity*cost;}
        int getItemNumber() {return itemNumber;}
        int getQuantity() {return quantity;}
        double getCost() {return cost;}
        double getTotalCost() {return totalCost;}
};
int main() {
    Inventory i;
    int n, q;
    double c;
    do {
        cout << "Please enter the item number: ";
        cin >> n;
    } while (n<0);
    i.setItemNumber(n);
    do {
        cout << "Please enter the item quantity: ";
        cin >> q;
    } while (q<0);
    i.setQuantity(q);
    do {
        cout << "Please enter the item cost: $";
        cin >> c;
    } while (c<0);
    i.setCost(c);

    cout << "\nItem #" << i.getItemNumber() << endl;
    cout << i.getQuantity() << " units @ $" << i.getCost() << endl;
    cout << "Total: $" << i.getTotalCost();
    return 0;
}