#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin;

    string fileName = "example.txt";
    string name;
    double grade, sum;
    int count;

    vector <string> Names;
    vector <int> fGrades;

    fin.open("example.txt");

    if(fin.fail()) {
        cout << "File failed to open!";
        return -1;
    }

    while(fin >> name) {
        Names.push_back(name);

        count = 0;
        sum = 0;

        while(fin >> grade) {
            count++;
            sum+=grade;
        }

        fin.clear();

        fGrades.push_back(sum / count);
    }

    for(int i=0; i < Names.size(); i++) {
        cout << setw(10) << right << Names[i];
        cout << setw(5) << right << fGrades[i];
        cout << endl;
    }

    return 0;

}
