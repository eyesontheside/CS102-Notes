#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Pixel {
    int red;
    int green;
    int blue;

    Pixel();
    Pixel(int, int, int);
};

class Picture {
    vector< vector<Pixel> > picture;
    string filetype;
    int rows, cols, color_range;

    public:
        bool readPicture(ifstream &);
        bool outputPicture(ofstream &);
        void flipCols();
        void flipRows();
        void invertPicture();
};

int main(int argc, char *argv[]) {

    ifstream fin;
    ofstream fout;
    Picture pic;

    // Check for correct number of command line arguments
    if(argc != 3 && argc != 4) {
        cout << "Usage: inputfile outputfile [XYI]";
        return -1;
    }

    // open and check input file
    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "Error: unable to read PPM file " << argv[1];
        return -1;
    }

    // pass file to Picture class
    pic.readPicture(fin);

    if(argc == 4) {
        if(argv[3][0] == 'Y')
            pic.flipCols();
        else if(argv[3][0] == 'X')
            pic.flipRows();
        else if(argv[3][0] == 'I')
            pic.invertPicture();
        else {
            cout << "Error: " << argv[3][0] << " is an invalid command. Use either X, Y, or I";
            return -1;
        }
    }

    // open and check output file 
    fout.open(argv[2]);
    if(fout.fail()) {
        cout << "Error: unable to write PPM file " << argv[2];
        return -1;
    }

    // pass file to Picture class member function
    pic.outputPicture(fout);

    fin.close();
    fout.close();

    return 0;

}

Pixel::Pixel(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
}

Pixel::Pixel() {
    Pixel(0, 0, 0);
}

// read file and format for Picture class
bool Picture::readPicture(ifstream & fin) {

    vector<Pixel> row;
    Pixel temp_pix;
    int r, g, b;
    int i, j;

    // read and check filetype
    fin >> filetype;
    if(filetype != "P3") {
        cout << "Invalid file type.";
        return false;
    }

    // read the number of columns, rows, and the color range
    fin >> cols >> rows >> color_range;

    // read pixel values from input file and put them into a multidimensional vector
    for(i=0; i<rows; i++) {
        row.clear();

        for(j=0; j<cols; j++) {
            fin >> r >> g >> b;
            temp_pix = Pixel(r, g, b);

            row.push_back(temp_pix);
        }

        picture.push_back(row);

    }

    return true;

}

// output Picture class to a formatted file
bool Picture::outputPicture(ofstream & fout) {

    int i, j;

    if(rows == 0) {
        cout << "Error: tried to output an uninitialized PPM picture";
        return false;
    }

    // output header
    fout << filetype << endl;
    fout << cols << " " << rows << endl;
    fout << color_range << endl;

    // output pixels
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            fout << picture[i][j].red << " " << picture[i][j].green << " " << picture[i][j].blue << endl;
        }
    }

}

// flip picture across the x-axis
void Picture::flipCols() {

    Pixel temp;
    int i, j;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols/2; j++) {
            temp = picture[i][j];
            picture[i][j] = picture[i][cols-j-1];
            picture[i][cols-j-1] = temp;
        }
    }

}

// flip picture across the y-axis
void Picture::flipRows() {

    vector<Pixel> temp;
    int i;

    for(i=0; i<rows/2; i++) {
        temp = picture[i];
        picture[i] = picture[rows-i-1];
        picture[rows-i-1] = temp; 
    }

}

// invert picture color
void Picture::invertPicture() {

    int i, j;

    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            picture[i][j].red = color_range - picture[i][j].red;
            picture[i][j].green = color_range - picture[i][j].green;
            picture[i][j].blue = color_range - picture[i][j].blue;
        }
    }

}
