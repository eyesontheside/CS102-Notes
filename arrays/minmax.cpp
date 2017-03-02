#include <iostream>

using namespace std;

const int MAX_SIZE = 255;

int main() {
    int myarray[MAX_SIZE];
    int min, max;
    int i;
    int size;

    cint >> size;

    if(size > MAX_SIZE)
        size = MAX_SIZE;
    
    for(i=0; i<size; i++) {
        cin >> myarray[i];
    }

    min = max = myarray[0];

    for(i=1; i<size; i++) {
        if(myarray[i] < min)
            min = myarray[i];
        else if(myarray[i] > max)
            max = myarray[i];
    }

}
