#include <iostream>
#include <iomanip>
using namespace std;

// Values to multiply PPI by depending on input device
const double keyboard=1.00, mouse=0.60, finger=0.85;

// Values to multiply PPI by depending on screen size
const double desktop=1.0, laptop=1.1, phone=1.4, tablet=1.25;

int main() {
    
    char education_level, screen_size;
    string input_type;
    double ppi;
    int mental_sharpness, age;

    cout << "CSOZT Brain Trainer" << endl << endl;
    
    // Ask for and store education level, mental sharpness, and age
    cout << "Education level (a, c, or h): ";
    cin >> education_level;
    
    cout << "Mental sharpness (1-10): ";
    cin >> mental_sharpness;
    
    cout << "Age (in years): ";
    cin >> age;
    
    cout << "Input device (keyboard, mouse, finger): ";
    cin >> input_type;
    
    cout << "Screen size (d, l, p, t): ";
    cin >> screen_size;
    
    // Inital calculations of PPI based on education level, mental sharpness, and age
    if(education_level == 'h' || mental_sharpness <= 3){
        ppi = 4.72 * (455 + (6.8 * mental_sharpness * mental_sharpness)) / (2.1 * age);
    }
    else if(education_level == 'c'){
        ppi = 5.25 * (383 + (7.3 * mental_sharpness * mental_sharpness)) / (1.9 * age);
    }
    else{
        ppi = 5.73 * (573 + (7.9 * mental_sharpness * mental_sharpness)) / (1.75 * age);
    }
    
    // Initial PPI Output
    cout << endl << endl << "PPI = " << fixed << setprecision(0) << ppi << endl;
    
    // Adjust PPI for input type
    if(input_type == "keyboard"){
        ppi *= keyboard;
    }
    else if(input_type == "mouse"){
        ppi *= mouse;
    }
    else if(input_type == "finger"){
        ppi *= finger;
    }
    else{
        cout << "invalid input device";
        return 0;
    }
    
    // Adjust PPI for screen size
    switch(screen_size){
        case 'd':
            ppi *= desktop;
            break;
        case 'l':
            ppi *= laptop;
            break;
        case 'p':
            ppi *= phone;
            break;
        case 't':
            ppi *= tablet;
            break;
        default:
            cout << "invalid screen type";
            return 0;
    }
    
    // Adjusted PPI output
    cout << "Adjusted PPI = " << fixed << setprecision(2) << ppi << endl;
    
    return 0;
    
}