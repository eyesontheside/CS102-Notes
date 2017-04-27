#include <iostream>
#include <string>

using namespace std;

void printDate(string, int, int);

int main() {
    
    string month;
    int day, year;
    
    cout << "Enter month, day, and year";
    cin >> month >> day >> year;
    
    printDate(month, day, year);
    
    return 0;
    
}

void printDate(string month, int day, int year) {
    cout << month << " " << day << " " << year << endl;
}