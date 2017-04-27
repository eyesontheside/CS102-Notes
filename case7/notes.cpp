// File format

// P3
// [#cols] [#rows]
// [max intensitiy]
// pixel pixel pixel

// pixel (RBG)
// rgb rgb rgb 

// Pixel struct
struct Pixel {
    int red;
    int green;
    int blue;

    Pixel();
    Pixel(int, int, int);
};

// Use vector of vectors to store
// Outside vector should be rows and inside columns
// Decleration syntax
vector< vector<Pixel> > v;

// Reading process

vector<pixel> temp;

for(i=0; i<rows; i++) {
    temp.clear();
    for(j=0; j<cols; j++) {
        fin >> red >> green >> blue;
        p = Pixel(red, green, blue);
        temp.push_back(p);
    }
    v.push_back();
}

// Another method
count =;
vector< vector<Pixel> > v;
vector<Pixel> temp;

while(fin >> red >> green >> blue) {
    p = Pixel(red, green, blue);
    temp.push_back(p);
    count++;
    if(temp.size() == cols) {
        v.push_back(temp);
        temp.clear();
    }
}

if(count != (rows * cols)) {
    cout << "Bad data!";
    return -1;
}


// Flipping Vectors - by column (y axis)
// One vector reversal
for(j=0; j<size/2; j++) {
    swap vector[i] with vector[size-j-1];
}

// Two dimensions
for(i=0; i<rows; i++) {
    for(j=0; j<columns/2; j++) {
        swap vector[i][j] with vector[i][size-j-1];
    }
}

// Flipping Vectors - Rows (x axis)
vector <classtype> temp;

for(i=0; i<rows/2; i++) {
    temp = row[i];
    row[i] = row[size-i-1];
    row[size-i-1] = temp;
}

// Working with each element in a vector of vectors

vector of vectors
classtype temp;

for(i=0; i<rows; i++) {
    for(j=0; j<columns; j++) {
        vector[i][j].red = vector[i][j].red + 10;
        vector[i][j].green = vector[i][j].green + 10;
        vector[i][j].blue = vector[i][j].blue + 10;
    }
}
