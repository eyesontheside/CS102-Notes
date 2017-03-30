#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v(1, 5);
    cout << v.size() << endl;
    v.push_back(42);
    cout << v.size() << endl;
    cout << v[v.size() - 1] << endl;
    v.resize(5);
    cout << v.size() << endl;
}
