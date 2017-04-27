#include <iostream>
using namespace std;

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    
    if ((a < b) && (b < c))
        cout << "They are in order" << endl;
    else
        cout << "Conditions are not true" << endl;
    
}