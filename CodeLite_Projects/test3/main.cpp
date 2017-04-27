#include <iostream>
using namespace std;

int main() {
    
    string name;
    int age;
    
    //Get name
    cout << "What is your name? ";
    cin >> name;
    
    //Get age
    cout << "Hello " << name << ", how old are you?";
    cin >> age;
    
    //Greet person
    cout << "Hey " << name << ", I think it's great that you're " << age << ".";
    
    return 0;
}