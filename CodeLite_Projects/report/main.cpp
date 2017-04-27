#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main() {
    
    // declare variables
    int num_classes, num_students;
    int max_score, min_score;
    int max_class;
    string max_class_name;
    double avg_score;
    int student_score, score_sum;
    int i, j;
    string class_name;
    string student_name;
    
    // initalize all grand total variables
    // output main headers
    cout << "Class Reports Spring 2016" << endl;
    cout << "Enter number of classes: ";
    cin >> num_classes;
    
    max_class = INT_MIN;
    
    // start outer loop for each class
    for(i=0; i < num_classes; i++) {
        max_score = INT_MIN;
        min_score = INT_MAX;
        score_sum = 0;
        
        cout << "Enter class name and number of students: ";
        cin >> class_name >> num_students;
        
        for(j=0; j < num_students; j++) {
            cout << "Enter student name and grade: ";
            cin >> student_name >> student_score;
            score_sum += student_score;
            
            if(student_score > max_score)
                max_score = student_score;
            if(student_score < min_score)
                min_score = student_score;
        }
        
        avg_score = (1.0 * score_sum) / num_students;
        
        cout << "Min score: " << min_score << ", Max score: " << max_score << ", and Average score: " << avg_score << endl;
        
        if(avg_score > max_class) {
            max_class = avg_score;
            max_class_name = class_name;
        }
    }
    
    cout << max_class_name << " had the highest average at " << max_class << endl;
    return 0;
    
}