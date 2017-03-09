// the library to create streams from hard disk
#include <fstream>
#include <string>

using namespace std;

int main() {

    double midterm1, midterm2, final, weightedAvg;
    string studentName;

    ifstream examScores; // declares an empty input file object
    ofstream grades;     // decales an empty output file object

    // open files
    examScores.open("cs102.dat");

    //check if file failed
    if examScores.fail() {
        cout << "error";
        return 1;
    }

    grades.open("cs102FinalGrades.csv");

    // loop to calculate students grades
    // while will end when there is no more data
    while(examScores >> studentName >> midterm1 >> midterm2 >> final) {

        weightedAvg = 0.5 * final + .25*midterm1 + .25*midterm2;
        grades << studentName << ", " << weightedAvg << endl;

    }

    // close files 
    grades.close();
    examScores.close();

    return 0;

}
