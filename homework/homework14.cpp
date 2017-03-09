#include <iostream>

using namespace std;

const int SIZE=5;

int GetMin(int []);

int main() {
    int i;
    int value_array[SIZE];
    int mindex;

    for(i=0; i<SIZE; i++) {
        cin >> value_array[i];
    }

    mindex = GetMin(value_array);

    cout << "Minimum is index " << mindex << " which is value " << value_array[mindex] << endl;

    return 0;
}

int GetMin(int a[]) {

    int i;
    int min, mindex;

    min = a[0];
    mindex = 0;

    for(i=1; i<SIZE; i++) {
        if(a[i] < min) {
            min = a[i];
            mindex = i;
        }
    }

    return mindex;

}
