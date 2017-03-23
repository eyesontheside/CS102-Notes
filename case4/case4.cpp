#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// number of items in the article array
const int NUMART = 4;
const string ARTICLES[] = {"The", "This", "A", "That"};
const string NOUNS[] = {"elephant", "tiger", "lion", "panther", "aardvark", "bear"}
const string VERBS[] = {"ate", "ran", "slept"}
const string ADVERBS[] = {"heartily", "fast", "upsidedown", "quickly"}

int main() {

    int seed, num_sentences;

    cout << "Enter a seed value for the random number generator ";
    cin >> seed;

    cout << "Enter the number of sentences to create (1-20) ";
    cin >> num_sentences;

}
