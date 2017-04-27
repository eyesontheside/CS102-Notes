#include <iostream>
#include <cstdlib>
using namespace std;

int DrawBall();
 
//set the highest and lowest numbers
const int HIGHNUM = 500;
const int LOWNUM = 100; 

int main(){

    int ball, preball, i, numdraw, seed; 
    // seed the random number generator once 
    cout<<"enter a seed value for the random number generator"; 
    cin>>seed; 
    srand(seed); 
    
    cout<< "Enter the number of balls to be drawn";
    cin>>numdraw;  
    
    // enter the Header Line
    cout<<endl;
    cout<<"The balls drawn for this lottery are:"; 
    
    preball = 0;
    
    for(i=0; i<numdraw; i++) {
        
        ball = DrawBall();
        
        if(ball == preball) {
            if(ball == 500) {
                ball = 100;
                cout << " " <<  ball;
            }
            else {
                cout << " " << ball;
            }
        }
        else {
            cout << " " << ball;
        }
        
        preball = ball;
        
    }


}