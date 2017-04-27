#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    double a, b, c;
    int distance, speed;
    double avg_speed;
    
    cin >> distance >> speed;
    
    avg_speed = static_cast<double>(distance) / speed;
    
    cout << "Average speed = " << avg_speed << endl;
    
    cin >> a >> b >> c;
    
    cout << (-b + sqrt(pow(b, 2.0) -4 * a * c))/(2*a) << endl;
    
}