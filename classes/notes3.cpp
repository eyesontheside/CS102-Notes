// Constructor classes
// Example
Student st("John", "CS", 4.0);

Student::Student(string n, string maj, double gpaPtAvg) {
    name = n;
    major = maj;
    gpa = gradePtAvg;
}

// Multiple constructors
class Student {
    public:
        Student();
        Student(string n);
        Student(string n, string maj, double gradePtAvg);
}

// Zero argument constructor
Student::Student() {
    name = "";
    major = "";
    gpa = 0.0;
}

Student st;    // Constructor with 0 args does not use parenthesis
Student st();  // NOT OKAY

// Alternative way to initalize member variables
Student::Student(string n, string maj, double gradePtAvg) : name(n), major(maj), gpa(gradePtAvg) {}

// Structs
// Structs and classes are exactly the same thing with one exception -- all variables in the struct are public by default
struct myStruct {
    int a;
    int b;
};
