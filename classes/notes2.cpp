// Student class definition
class Student {
public:
    string name;
    string address;
    double gpa;
    void printStudent();
};

void Student::printStudent() {
    cout << name << endl;
    cout << address << endl;
    cout << gpa << endl;
}

// Using the class
Student st1, st2;
st1.name = "John";
st1.address = "1678 Cardiff Rd.";
st1.gpa = 4.0;
st1.printStudent();
st2 = st1;

// Access Protection
// public: accessible by entities outside the class
// private: accessible only by other class members
//    analogous to social networking where you might have a group
//    of friends with more restricted access

// Public and private example
class Student {
    public:
        // mutator functions
        void setName(string s);
        // accessor functions
        string getName();
    private:
        string name;
        double gpa;
        string major;
}

Student st;
st.name = "John";   // illegal -- the wrong way to do it
st.setName("John"); // the right way to do it

// Programming tip
// Member functions should be private
// Use public accessor and mutator functions to manipulate member variables
//     accessor function: returns a variable
//     mutator function: changes a value
