#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

// call by reference
void swap(int& x, int& y);
// array call by value
void value(const int []);
int randomNumber(int, int);
double stdev(double []);

int main() {

    int seed;

    cout << "Enter a seed: ";
    cin >> seed;
    // seed random number generator
    srand(seed);

    return 0;

}

// generate random number
int randomNumber(int max, int min) {
    return (rand() % (max - min + 1)) + min;
}
