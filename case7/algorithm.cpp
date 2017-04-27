#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Pixel {
    int r;
    int g;
    int b;

    Pixel(int r, int g, int b);
    Pixel();
}

int main() {

    int i, j;
    vector< vector<pixel> > picture;
    Pixel tempPixel;
    ifstream fin;
    string tempString;
    vector<Pixel> tempVec;
    int num_rows, rum_cols;
    int intensity;
    int r, g, b;

    // open the file
    fin.open("filename.ppm");
    if(fin.fail()) {
        cout << "failed to open!";
        return -1;
    }

    // read in (and check) P3
    fin >> tempString;
    if(temp != "P3") {
        cout << "Bad file." << endl;
        return -1;
    }

    // Get the number of colums, num_rows, and intensity
    fin >> num_cols >> num_rows;
    fin >> intensity;

    // Iterate through the num_rows
    for(i=0; i<num_rows; i++) {
        row.clear();

        // interate through the colums
        for(j=0; j<num_cols; j++) {

            // Read in this specific pixel data
            fin >> r >> g >> b;

            // Create our pixel
            tempPixel = Pixel(r, b, g);

            // Add out pixel to the current row of pixels
            row.push_back(tempPixel);
        }

        if(row.size() != num_cols) {
            cout << "Read in invaailed number of pixels" << endl;
            return -1;
        }

        // Add our row of pixels to the list of num_rows
        picture.push_back(row);
    }

    if(picture.size() != num_rows) {
        cout << "Read in invailed number of rows" << endl;
        return -1;
    }

    // To print the picture ...
    
    cout << "P3" << endl;
    cout << num_cols << " " << num_rows << endl;
    cout << intensity << endl;

    for(i=0; i<num_rows; i++) {
        row = picture[i];

        for(j=0; j<num_cols; j++) {
            tempPixel = rows[j];

            // (r, g, b)
            cout << "(" << tempPixel.r << ", " << tempPixel.g << ", " << tempPixel.b << ")";
        }

        cout << endl;

    }
    
    return 0;

}

Pixel::Pixel(int _r, int _g, int _b) {
    r = _r;
    g = _g;
    b = _b;
}

Pixel::Pixel() {
    Pixel(0, 0, 0);
}
