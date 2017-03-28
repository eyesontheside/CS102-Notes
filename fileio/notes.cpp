// getline function
// from cin: getline(cin, string s);
// from file: getline(ifstream i, string s);

// example
fin.open("temps.dat");
if(fin.fail()) {
    cout << "Unable to open input file.";
    return -1;
}
while(getline(fin, line)) {
    cout << line << endl; // writes the new line to the console
}

// string streams
// they allow you to extract fields form a string using the input operator >>
// this also works to create formatted data using <<
#include <sstream> // sstreams library
istringstream buffer; // declares an "input" stringsream named buffer


// example
int exams[3], count=0;
double sum=0;
string fname, lname, line;
istringstream sin;

getline(cin, line);           // read a student -- get the whole line
sin.str(line);                // assign the line to the string stream
sin >> fname >> lname;        // extracts first and last names
while(sin >> exams[count]) {  // extract exams until end of line
    sum += exams[count];
    count++;
}

cout << "average = " << sum/count << endl;


















