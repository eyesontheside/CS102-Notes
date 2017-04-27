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

int main(int argc, char *argv[]) {

    ifstream fin;
    ofstream fout;
    ShoppingItem item, min_item, max_item;
    vector<ShoppingItem> items;
    int i, quantity, items_length;
    double cost, total_cost;
    string i_name, f_name, l_name;

    if(argc != 3) {
        cout << "Invalid command line arguments";
        return -1;
    }

    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "Input file failed to open";
        return -2;
    }

    fout.open(argv[2]);
    if(fout.fail()) {
        cout << "Output file failed to open";
        return -2;
    }

    while(fin >> quantity) {
        if(quantity == -1) {
            fin >> l_name >> f_name;
            total_cost = getTotal(items, min_item, max_item);

            items_length = items.size();

            for(i=0; i<items_length; i++) {
                fout << left << setw(16) << formatString(items[i].getName());
                fout << right << setw(4) << items[i].getQuantity();
                fout << right << setw(7) << items[i].getCost();
                fout << right << setw(8) << items[i].getTotalCost() << endl << endl;
            }

            fout << "cheapest item = " << formatString(min_item.getName()) << endl;
            fout << "most expensive item = " << formatString(max_item.getName()) << endl;
            fout << "total cost = " << total_cost << endl;
            fout << "shopper " << "= " << formatString(f_name) << formatString(l_name);

            items.clear();

        }
        else {
            fin >> cost >> i_name;
            item = ShoppingItem(quantity, cost, i_name);
            items.push_back(item);
        }

    }

    fin.close();
    fout.close();

    return 0;

}

ShoppingItem::ShoppingItem(){
    quantity = 0;
    cost = 0.0;
    name = "";
}

ShoppingItem::ShoppingItem(int q, double c, const string n) {
    quantity = q;
    cost = c;
    name = n;
}

int ShoppingItem::getQuantity() const {
    return quantity;
}

double ShoppingItem::getCost() const {
    return cost;
}

string ShoppingItem::getName() const {
    return name;
}

double ShoppingItem::getTotalCost() const {
    return quantity * cost;
}

string formatString(string str) {

    int i, str_length;
    str_length = str.length();

    str[0] = toupper(str[0]);

    for(i=1; i<str_length; i++) {
        str[i] = tolower(str[i]);
    }

    return str;

}

double getTotal(const vector<ShoppingItem> & shopping_items, ShoppingItem & min, ShoppingItem & max) {

    int i, shopping_length;
    double total_cost=0.0, cost;

    shopping_length = shopping_items.size();

    for(i=0; i<shopping_length; i++) {
        cost = shopping_items[i].getCost();
        total_cost += cost;

        if(min.getCost() > cost)
            min = shopping_items[i];
        else if(max.getCost() < cost)
            max = shopping_items[i];
    }

    return total_cost;

}
