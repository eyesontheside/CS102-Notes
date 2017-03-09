// string class member functions examples
// length()
// at()
// substr()
// find()

// example
#include <string>
#include <iostream>
using namespace std;
int main() {
    string myString = "hello world";
    string yourString = "good by world";
    cout << myString << " " << yourString << endl;
    // length()
    cout << myString.length() << endl;
    return 0;
}

// strings can be considered char arrays
int i;
string addr = "1712 Edgehill Dr"
for(i = 0; i < addr.length(); i++) {
    cout << addr[i] << endl;
}

// The at member function
// at(i) behaves like [i]: it returns the character at index i
// at() is safer because it lets you know if your index goes out of bounds
addr.at(1);

// string concatenation
string x = "high"
string y = "school"
string z;
z = x + y;
// z = "highschool"

// string comparision
// if (s1 == s2) then they are the same string
// if (s1 > s2) then s1 comes before s2 alphabetically


// 2 ways to substitute 18 for #N
string answer = "The answer is in chapter #N, my friend ";
int i;
int position = answer.find("#N")
//form a new string by concatenating fragments from the original answer
string newAnswer = answer.substr(0, position) + 18 + answer.substr(position+2);
cout << NewAnswer << endl;
// replace #N with 18 in the original answer
answer.erase(position, 2);
answer.insert(position, "18");
cout << answer << endl;
