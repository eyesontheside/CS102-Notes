// The push_back member function
vector<int> grades;
grades.push_back(20);    // [20]
grades.push_back(30);    // [20, 30]
grades.push_back(80);    // [20, 30, 80]
grades.push_back(70);    // [20, 30, 80, 70]

vector<int> grades(5, 3);  // [3, 3, 3, 3, 3]
grades.push_back(20);      // [3, 3, 3, 3, 3, 20]
grades.push_back(30);      // [3, 3, 3, 3, 3, 20, 30]
grades.push_back(80);      // [3, 3, 3, 3, 3, 20, 30, 80]
grades.push_back(70);      // [3, 3, 3, 3, 3, 20, 30 ,80, 70]

// Vector Declaration
vector<type> name;
vector<type> name(size);
vector<type> name(size, defaultValue);

vector<string> names;               // vector of strings with an initial size of 0
vector<string> grades(10);          // creates a vector capable of storing 10 strings
vector<string> grades(10, "brad");  // creates a vector capable of storing 10 strings initialized to "brad"

// Resizing a vector
grades.resize(20);
grades.push_back(3);
