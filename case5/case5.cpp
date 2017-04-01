#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string Lower(string);
int SearchDistrict(string district_name, const vector<string> &);


int main(int argc, char *argv[]) {

    ifstream fin;
    istringstream sin;
    string line, district_name;
    double nonv_crime, v_crime, d_crime;
    int num_lines=0, size;
    vector<string> district_names;
    vector<int> nonviolent_crimes, violent_crimes, domestic_crimes;

    // check to see if user entered the correct command line arguments
    if(argc != 3) {
        cout << "Invaid command line arguments";
        return -1;
    }

    // convert command line argument into an integer
    sin.str(argv[2]);
    sin >> size;
    sin.clear()

    // open and check file 
    fin.open(argv[1]);
    if(fin.fail()) {
        cout << "file failed to open";
        return -1;
    }

    // add data entries to vectors
    while(getline(fin, line)) {

        num_lines++;
        sin.str(line);

        sin >> district_name >> nonv_crime >> v_crime >> d_crime;

        district_names.push_back(district_name);
        nonviolent_crimes.push_back(nonv_crime * 10);
        violent_crimes.push_back(v_crime * 10);
        domestic_crimes.push_back(d_crime * 10);

        sin.clear();

    }

    fin.close();

}


// convert string to all lowercase
string Lower(string str) {

    int i, size;
    size = str.length();

    for(i=0; i<size; i++) {
        str[i] = tolower(str[i]);
    }

    return str;

}

// search for index of district name while ignoring case
int SearchDistrict(string district_name, const vector<string> & dist_vec) {

    int i, index=-1, size;

    size = dist_vec.size();
    district_name = Lower(district_name);

    for(i=0; i<size; i++) {

        if(district_name == Lower(dist_vec[i])) {
            index = i;
            break;
        }

    }

    return index;

}
