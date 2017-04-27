#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char gender;
    int fcount=0, mcount=0, numstudents;
    int grade;
    //process only the students in the 12th grade
    cout << "Enter the number of students ";
    cin >> numstudents;
    cin >> grade;
    while((numstudents > 0) && (grade == 12)) {
        cout << "Enter the gender ";
        cin >> gender;
        if(gender == 'F')
            fcount++;
        else
            mcount++;
        numstudents--;
    }
    cout << "The number of females " << fcount << " and males " << mcount << endl;
    return 0;
}