// Spencer Harper
// hjw848
// Read in shopping items from file and output a file of formatted purchases

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

class ShoppingItem {
    int quantity;
    double cost;
    string name;

    public:
    ShoppingItem();
    ShoppingItem(int, double, const string);

    int getQuantity() const;
    double getCost() const;
    string getName() const;

    double getTotalCost() const;

};

string formatString(string);
double getTotal(const vector<ShoppingItem> &, ShoppingItem &, ShoppingItem &);
void sortItems(vector<ShoppingItem> &);

int main(int argc, char *argv[]) {

    ifstream fin;
    ofstream fout;
    ShoppingItem item, min_item, max_item;
    vector<ShoppingItem> items;
    int i, quantity, items_length;
    double cost, total_cost;
    string i_name, f_name, l_name;

    // Exit program if there are invalid command line arguments
    if(argc != 3) {
        cout << "Invalid command line arguments";
        return -1;
    }

    // open user specified input file
    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "Unable to open input file.";
        return -2;
    }
    
    // open and check output file
    fout.open(argv[2]);
    if(fout.fail()) {
        cout << "Output file failed to open";
        return -2;
    }

    // read in quantities from input file
    while(fin >> quantity) {
        // if quantity is -1 then read in the first and last name
        if(quantity == -1) {
            fin >> l_name >> f_name;
            // sort items from lowest to highest price
            sortItems(items);
            // calculate the total cost of all items
            total_cost = getTotal(items, min_item, max_item);

            items_length = items.size();

            // print report of all items prices, quantities, and name
            for(i=0; i<items_length; i++) {
                fout << left << setw(15) << items[i].getName();
                fout << right << setw(4) << items[i].getQuantity();
                fout << fixed << setprecision(2) << right << setw(7) << items[i].getCost();
                fout << fixed << setprecision(2) << right << setw(8) << items[i].getTotalCost() << endl;
            }

            // print report of cheapest item, most expensive item, total cost, and shopper
            fout << endl << "cheapest item = " << min_item.getName() << endl;
            fout << "most expensive item = " << max_item.getName() << endl;
            fout << "total cost = " << total_cost << endl;
            fout << "shopper " << "= " << formatString(f_name) << " " << formatString(l_name) << endl << endl;

            items.clear();

        }
        else {
            // read the following cost and item name
            fin >> cost >> i_name;
            item = ShoppingItem(quantity, cost, i_name);
            items.push_back(item);
        }

    }

    fin.close();
    fout.close();

    return 0;

}

// Default constructor
ShoppingItem::ShoppingItem(){
}

// Setter constructor
ShoppingItem::ShoppingItem(int q, double c, const string n) {
    quantity = q;
    cost = c;
    name = n;
}

// Getter function for quantity
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

// Getter function for caclulating the total amount spent on items
double ShoppingItem::getTotalCost() const {
    return quantity * cost;
}

// Format a string to start with a capital letter and all the following to be lowercase
string formatString(string str) {

    int i, str_length;
    str_length = str.length();

    str[0] = toupper(str[0]);

    for(i=1; i<str_length; i++) {
        str[i] = tolower(str[i]);
    }

    return str;

}

// function to set the minimum and maximum items and return the total cost of all items
double getTotal(const vector<ShoppingItem> & shopping_items, ShoppingItem & min, ShoppingItem & max) {

    int i, shopping_length;
    double total_cost, cost;

    shopping_length = shopping_items.size();
    min = shopping_items[0];
    max = shopping_items[0];
    total_cost = shopping_items[0].getTotalCost();

    for(i=1; i<shopping_length; i++) {
        cost = shopping_items[i].getCost();
        total_cost += shopping_items[i].getTotalCost();

        if(min.getCost() > cost)
            min = shopping_items[i];
        else if(max.getCost() < cost)
            max = shopping_items[i];
    }

    return total_cost;

}

// sort items vector based on the price of items
void sortItems(vector<ShoppingItem> & shopping_items) {
    
    bool sorted;
    ShoppingItem temp;
    int vec_size, i;
    
    vec_size = shopping_items.size();
    
    do {
        sorted = true;
        
        for(i=1; i<vec_size; i++) {
            if(shopping_items[i-1].getCost() > shopping_items[i].getCost()) {
                temp = shopping_items[i-1];
                shopping_items[i-1] = shopping_items[i];
                shopping_items[i] = temp;
                sorted = false;
            }
        }
        
    }while(sorted == false);
    
}