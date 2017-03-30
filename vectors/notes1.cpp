#include <iostream>
#include <vectors>
#include <fstream>

using namespace std;

int main() {
    vector<int> temperatures;
    int i, nextTemp;
    ifstream tempFile;
    tempFile.open("temps.dat");
    while(tempFile >> nextTemp) {
        temperatures.push_back(nextTemp);
    }
    cout << "number of elements = " << temperatures.size() << endl;
    for(i=temperatures.size() - 1; i>=0; i--){
        cout << i+1 << ": " << temperatures[i] << endl;
    }
}
