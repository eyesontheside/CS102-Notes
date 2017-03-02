#include <iostream>

using namespace std;

const int USFLIGHTS = 10;
const int TFLIGHTS = 10;

void checkFlight(const int [], int, const int [], int);

int main(){
    int usFlights[USFLIGHTS]={854, 129, 433, 2054, 954, 201, 1113, 403, 9898, 8438 };
    int travFlights[TFLIGHTS];
    int tsize, i;

    cin >> tsize;

    if(tsize > TFLIGHTS)
        tsize = TFLIGHTS;

    for(i = 0; i < tsize; i++) {
        cin >> travFlights[i];
    }
}

void checkFlights(const int allFlights[], int asize, const int travelFlights[], int tsize) {
    int i, j;
    bool match;

    for(i=0; i < tsize; i++) {
        match = false;

        for(j=0; j < asize; j++) {
            if(travelFlights[i] == allFlights[j]) {
                match = true;
                break;
            }
        }

        if(match)
            cout << "Flight is a US flight" << endl;
        else
            cout << "Flight is not a US flight" << endl;
    }
} 
