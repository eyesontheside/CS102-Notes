// apending data to an existing file
grades.open("finalGrades.csv", ios:app);

// passing files to functions
// must be passed using call-by-reference

void copy(ifstream& file_from, ofstream& file_to);
