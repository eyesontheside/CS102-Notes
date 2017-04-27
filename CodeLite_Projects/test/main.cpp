//Spencer Harper
//Test program: just hacking random code for peeps
#include <iostream>
using namespace std;

int main() {
    
    int i, j;
    
    //Asking user where to end count
    cout << "Where do we want to end?" << endl;
    cin >> i;
    
    //Print numbers 0 through end
    for(j = 0; j < i; j++) {
        cout << j << endl;
    }
    
    return 0;
}