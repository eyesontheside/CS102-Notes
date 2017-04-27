#include <iostream>
using namespace std;

int main() {
    string weather;
    int temperature;
    
    cout << "What's the weather and temperature? ";
    cin >> weather >> temperature;
    
    if (weather == "precipitating") {
        if (temperature < 32)
            cout << "it's snowing";
        else
            cout << "it's raining";
    }
    else if (weather == "sunny") {
        if (temperature < 60)
            cout << "it's a sunny but cold day";
        else if (temperature < 80)
            cout << "it's a beautiful, sunny day";
        else
            cout << "it's a hot, sunny day";
    }
    else
        cout << "it's a cloudy day";
    
    return 0;
}