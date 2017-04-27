// Circle class
// Variables: need a radius (declare)
// Functions: change the radius, find the area, find the circumference, ect

// How to make a class
// A class is a "blueprint"
// In that blueprint you have variables and functions

// Class declaration
// Goes before int main
class Circle {
    double radius;             // declare the member variables
public:                        // will discuss this more later
    void setRadius(double r);  // prototype the functions
    double getRadius();
    double getArea();
    double getCirc();
};

// Class definition
// Goes after int main
void Circle::setRadius(double r) {
    radius = r;                // you can access member variables in member functions
}
double Circle::getRadius() {
    return radius;
}

// Declare the object
Circle c1, c2;

// Use the object
int main() {
    Circle c1, c2, c3;
    double myR;
    cout << "radius 1 and 2";
    cin >> myR;
    c1.setRadius(myR); // dot notation
    cin >> myR;
    c2.setRadius(myR);
    cout << c1.getRadius() << c1.getArea() << endl;
    cout << c2.getRadius() << c2.getArea() << endl;
    c3 = c2;  // whole classes canbe copied
}
