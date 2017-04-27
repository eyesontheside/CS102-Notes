#include <iostream>
#include <iomanip>
#include <climits>
#include <string>

using namespace std;

int main() {
    
    int dataset_length, current_number;
    int min, max;
    int sum, average;
    int i, j, k;
    char response;
    
    do {
    
        cout << "How many numbers are in your data set? ";
        cin >> dataset_length;
        
        // If data set length is 0 skip to the final response
        if(dataset_length) {
            
            min = INT_MAX;
            max = INT_MIN;
            sum = 0;
        
            // Loop through each number in data set
            for(i = 0; i < dataset_length; i++) {
            
                cout << "Enter a number in your data set: ";
                cin >> current_number;
                cout << endl;
                
                // Add current number to sum
                sum += current_number;
                
                //Check if number is even or odd
                if((current_number % 2) == 0)
                    cout << current_number << " is even" << endl;
                else
                    cout << current_number << " is odd" << endl;
                
                k = 0;
                
                // Check for divisors of current number in data set
                for(j = 2; j <= (current_number/2); j++) {
                    
                    // If a divisor is found add it to output
                    if((current_number % j) == 0) {
                        
                        // Check to see if this is the first divisor in loop
                        if(k == 0) {
                            cout << current_number << " is divisible by " << j;
                            k++;
                        }
                        else {
                            cout << " " << j;
                        }
                        
                    }
                    
                }
                
                // Check if number is prime
                if(k == 0)
                    cout << current_number << " is prime" << endl;
                else
                    cout << endl;
                    
                // Check is there is a new min or max number
                if(current_number > max)
                    max = current_number;
                if(current_number < min)
                    min = current_number;
                    
            }
            
            // Calculate the average for current data set
            average = (1.0 * sum) / dataset_length;
            
            cout << endl << "The sum is " << sum << " and the average is " << average << endl;
            cout << "The min is " << min << " and the max is " << max << endl;
        
        }
        else {
            cout << endl << "The sum is 0 and the average is 0" << endl;
            cout << "The min is 0 and the max is 0" << endl;
        }
        
        cout << endl << "Do you want to do another data set? ";
        cin >> response;
    
    }while(response == 'y');
    
    return 0;
        
}