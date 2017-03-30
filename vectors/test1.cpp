#include <iostream>
#include <vector>

using namespace std;

int main() {

    int i, sum=0, size;
    double salesAmt;
    vector<double> v;

    while(cin >> salesAmt) {
        v.push_back(salesAmt);
    }

    size = v.size();
    for(i=0; i<size; i++) {
        sum += v[i];
    }

    cout << sum;

}
