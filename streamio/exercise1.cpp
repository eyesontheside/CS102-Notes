#include <iostream>
#include <fstream>

using namespace std;

int main() {

    int x;
    ifstream input;

    input.open("table.dat");
    if(input.fail()) {
        cout << "Enter data: ";
        cin >> x;
    }
    else {
        input >> x;
        input.close();
    }

}
