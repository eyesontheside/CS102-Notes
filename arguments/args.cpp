#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int i;

    cout << argc << endl;

    for(i=0; i < argc; i++) {
        cout << "This is argument #" << i << "->" << argv[i] << endl;
    }

    return 0;

}
