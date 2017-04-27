// Name
// NetID
// Assignment - Description

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class ShoppingItem {
    int quantity;
    double cost;
    string name;

    public:
        // Constructors
        ShoppingItem();
        ShoppingItem(int, double, const string &);

        // Getter functions
        int getQuantity() const;
        double getCost() const;
        string getName() const;

        double getTotalCost() const;

};

int main(int argc, char** argv) {

    vector<ShoppingItem> cart;
    string temp_str;
    int temp_int;
    double temp_dbl;
    string f_name, l_name;
    ifstream fin;
    ofstream fout;

    ShoppingItem SI;

    if(argc != 3) {
        cout << "Requires two command line arguments";
        return -1;
    }

    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "failed to open file";
        return -2;
    }

    cart.clear();

    while(fin >> temp_int) {
        if(temp_int != - 1) {
            fin >> temp_dbl >> temp_str;
            SI = ShoppingItem(temp_int, temp_dbl, temp_str);
            cart.push_back(SI);
        }
        else {
            fin >> l_name >> f_name;

            fout.open(argv[2]);
            if(fout.fail()) {
                cout << "Failed to open file";
                return -2;
            }

            for(int i=0; i < cart.size(); i++) {
                fout << cart[i].getName() << " " << cart[i].getQuantity() << " " << cart[i].getCost() << " " << cart[i].getTotalCost();
            }

            fout << "Shopper: " << f_name << " " 
        }
    }

    return 0;

}

// Default constructor
ShoppingItem::ShoppingItem() {
}

// Setter constructor
ShoppingItem::ShoppingItem(int q, double c, const string & n) {
    quantity = q;
    cost = c;
    name = n;
}

// Getter function for qunatity
int ShoppingItem::getQuantity() const {
    return quantity;
}

// Getter function for cost
double ShoppingItem::getCost() const {
    return cost;
}

// Getter function for name
string ShoppingItem::getName() const {
    return name;
}

// Getter function for calculating the total amount spent on item
double ShoppingItem::getTotalCost() const {
    return cost * quantity;
}
