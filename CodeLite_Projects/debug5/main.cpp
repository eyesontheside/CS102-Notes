#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int getNumber(int, int);

int main() {

    char ans;
    int seed, num;
    int min, max;

    cout << "Enter seed: ";
    cin >> seed;

    srand(seed);

    do {
        
       cout << endl;
       cout << "Enter minimum: ";
       cin >> min;

       cout << "Enter maximum: ";
       cin >> max;

       cout << endl << endl;

       num = getNumber(min, max);

       // The number printed below seems to always be the same and is
       // garbage!

       cout << "Random number = " << num << endl;

       cout << "New random number? ";
       cin >> ans;
       
    // loop while ans is not n or N
    }while(ans != 'n' && ans != 'N');

    return 0;

}

int getNumber(int min, int max) {

    // should return numbers between min and max
    return min + (rand() % (max - min + 1));
        
}