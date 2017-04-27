#include <iostream>
using namespace std;

int main() {
    double cost, money, change; // declaring variables
    cout << "Enter cost $"; // cout comes from iostream; it prints whatever is in quotes to the monitor
    cin >> cost; // cin also from iostream; it takes information from the keyboard and stores it in the given variable
    
    cout << "Enter money $";
    cin >> money;
    change = money - cost;
    cout << "Change = $" << change << endl; // endl means endline; it also flushes the console
    return 0; // way of saying this is the end of the program
}