#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void PrintLine(string, int, int, int);
string Lower(string);
int SearchDistrict(string district_name, const vector<string> &);

int main(int argc, char *argv[]) {

    ifstream fin;
    istringstream sin;
    string line, district_name;
    double nonv_crime, v_crime, d_crime;
    int i, num_lines=0, size;
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
    sin.clear();

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

    // if user prompts a number larger than file size print full file
    if(size > district_names.size())
        size = district_names.size();

    // print header information
    cout << "Top " << size << " Crime Ridden Areas In Baltimore" << endl;
    PrintLine("District", -1, -1, -1);
    for(i=0; i<size; i++) {
        PrintLine(district_names[i], nonviolent_crimes[i], violent_crimes[i], domestic_crimes[i]);
    }

}


void PrintLine(string district, int nonviolent, int violent, int domestic) {

    if(nonviolent == -1 && violent == -1 && domestic == -1) {
        cout << left << setw(26) << district;
        cout << left << setw(5) << "VC";
        cout << left << setw(5) << "DV";
        cout << left << setw(5) << "NVC" << endl << endl;
    }
    else {
        cout << left << setw(26) << district;
        cout << left << setw(5) << violent;
        cout << left << setw(5) << domestic;
        cout << left << setw(5) << nonviolent << endl;
    }

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
