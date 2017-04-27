#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double price, amount_paid;
    double double_price;
    int int_price, dollars, quarters, dimes, nickels, pennies;
    int rem_dollars, rem_quarters, rem_dimes, rem_nickels;
    
    cout << "Enter price: ";
    cin >> price;
    
    cout << "Enter amount paid: ";
    cin >> amount_paid;
    
    double_price = amount_paid - price;
    
    int_price = double_price * 100.0001; // multiply by 100.0001 to keep precision
    
    dollars = int_price / 100;
    rem_dollars = int_price % 100;
    cout << endl << setw(2) << "Dollars: " << dollars << endl;
    
    quarters = rem_dollars / 25;
    rem_quarters = rem_dollars % 25;
    cout << setw(3) << "Quarters: " << quarters << endl;
    
    dimes = rem_quarters / 10;
    rem_dimes = rem_quarters % 10;
    cout << setw(3) << "Dimes: " << dimes<< endl;
    
    nickels = rem_dimes / 5;
    rem_nickels = rem_dimes % 5;
    cout << setw(3) << "Nickels: " << nickels << endl;
    
    pennies = rem_nickels / 1;
    cout << setw(3) << "Pennies: " << pennies << endl;
    
    return 0;
    
}

/*
int main() {
    
    double price, amt_paid;
    int new_price, dollars, quarters, dimes, nickels, pennies;
    int dollar_rem, quarters_rem, dimes_rem;
    
    cout << "Please enter the price of the item: ";
    cin >> price;
    cout << "Please enter the payment amount: ";
    cin  >> amt_paid;
    
    new_price = 100*amt_paid - 100*price;
    
    dollars = new_price / 100;
    dollar_rem = new_price % 100;
    cout << "Dollars: " << dollars << endl;
    
    quarters = dollar_rem / 25;;
    quarters_rem = dollar_rem % 25;
    cout << "Quarters: " << quarters << endl;
    
    dimes = quarters_rem / 10;
    dimes_rem = quarters_rem / 10;
    cout << "Dimes: " << dimes << endl;
    
    nickels = dimes_rem / 5;
    cout << "Nickels: " << nickels << endl;
    
    pennies = dimes_rem % 5;
    cout << "Pennies: " << pennies << endl;
    
    return 0;

}
*/