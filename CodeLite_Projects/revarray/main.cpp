#include <iostream>
using namespace std;

const int NUM_SCORES = 5;

int main() {
    
    int i;
    int sum=0;
    int scores[NUM_SCORES];
    
    for (i = 0; i < NUM_SCORES; i++)
        cin >> scores[i];
        
    for (i=NUM_SCORES-1; i >= 0; i--) {
        
        cout << scores[i] << endl;
        sum += scores[i];
        
    }
    
    cout << "sum = " << sum << endl;
    
}