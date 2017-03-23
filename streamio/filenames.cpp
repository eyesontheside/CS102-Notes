#include <fstreams>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "please enter the name of the exam score file";
    cin >> filename;
    // open file using filename provided by c++
    examScores.open(filename.c_str());
}
