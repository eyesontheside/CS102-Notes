#include <iostream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

int main() {
    
    int dataset_length, data_num;
    int sum, max, min;
    int i, j, k;
    int average;
    bool divisible, nonzero;
    char response;
    
    do {
    
        max = INT_MIN;
        min = INT_MAX;
        divisible = false;
        nonzero = true;
        
        cout << "How many numbers are in your data set? ";
        cin >> dataset_length;
        
        
        for(i = 1; i <= dataset_length; i++){
            
            k = 0;
            
            cout << "Enter a number in your data set: ";
            cin >> data_num;
            
            if(data_num == 0)
                nonzero = false;
            
            cout << endl;
            
            if((data_num % 2) == 0)
                cout << data_num << " is even" << endl;
            else
                cout << data_num << " is odd" << endl;
                
                
            for(j = 2; j <= (data_num/2); j++) {
                
                if((data_num % j) == 0) {
                    divisible = true;
                    k++;
                    
                    if(k == 1) {
                    k++;
                    cout << data_num << " is divisible by";
                    }
                    
                }
                else {
                    divisible = false;
                }
                if(divisible){
                    cout << " " << j;
                }
                
            }
            
            // Determine if number is prime
            if(k == 0)
                cout << data_num << " is prime" << endl;
            else
                cout << endl;
                
            // Add current number to sum
            sum += data_num;
            
            // Check for new min/max
            if(data_num > max)
                max = data_num;
            if(data_num < min)
                min = data_num;
            
        }
        
        cout << endl;
        
        if(nonzero) {
            
            // Calculate average
            average = (1.0 * sum) / dataset_length;
            
            cout << "The sum is " << sum << " and the average is " << average << endl;
            cout << "The min is " << min << " and the max is " << max << endl << endl;
            
            cout << "Do you want to do another data set? ";
            cin >> response;
        }
        else {
            
            cout << "The sum is 0 and the average is 0" << endl;
            cout << "The min is 0 and the max is 0" << endl << endl;
            
        }
        
    }while(response == 'y');
    
    return 0;
    
}