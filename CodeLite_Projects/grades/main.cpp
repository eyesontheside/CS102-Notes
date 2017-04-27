#include <iostream>
using namespace std;

int main() {
    
    char letter_grade;
    
    cout << "Enter letter grade: ";
    cin >> letter_grade;
    
    switch(letter_grade){
        case 'A':
            cout << "Excellent";
            break;
        case 'B':
        case 'C':
            cout << "Well done!";
            break;
        case 'D':
            cout << "You passed!";
            break;
        case 'F':
            cout << "You failed";
            break;
        default:
            cout << "Invalid grade";
            break;
            
        return 0;
    }
    
}