// Spencer Harper
// Program generates sentences using random numbers

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// number of elements in the following arrays 
const int NUMART=4, NUMNOUNS=6, NUMVERBS=3, NUMADVERBS=4;

// list of words divided by type
const string ARTICLES[] = {"The", "This", "A", "That"};
const string NOUNS[] = {"elephant", "tiger", "lion", "panther", "aardvark", "bear"};
const string VERBS[] = {"ate", "ran", "slept"};
const string ADVERBS[] = {"heartily", "fast", "upsidedown", "quickly"};

string PickWord(const string [], int);
string CreateSentence();
void CorrectSentence(string&);
void PrintSentences(string [], int);

int main() {

    int i, seed, num_sentences;
    string sentence;
    string sentences[20];

    // prompt user to seed the random number generator
    cout << "Enter a seed value for the random number generator ";
    cin >> seed;
    srand(seed);

    // ask the user how many sentences they would like to create
    // continue asking until a number between 1 and 20 is submitted
    do {
        cout << "Enter the number of sentences to create (1-20)";
        cin >> num_sentences;
    }while(num_sentences < 1 || num_sentences > 20);

    // generate sentences and add them to array
    for(i=0; i<num_sentences; i++) {
        sentence = CreateSentence();
        CorrectSentence(sentence);

        sentences[i] = sentence;
    }

    // print all silly sentences
    PrintSentences(sentences, num_sentences);

    return 0;

}

// generate a random word using provided arrays
string PickWord(const string word_class[], int len) {

    int random_index;

    random_index = rand() % len;
    return word_class[random_index];

}

// create silly sentences using random words
string CreateSentence() {

    string article, noun, verb, adverb, sentence;

    article = PickWord(ARTICLES, NUMART);
    noun = PickWord(NOUNS, NUMNOUNS);
    verb = PickWord(VERBS, NUMVERBS);
    adverb = PickWord(ADVERBS, NUMADVERBS);

    sentence = article + " " + noun + " " + verb + " " + adverb;
    return sentence;

}

// check to see if sentences are gramatically correct and correct if not
void CorrectSentence(string& sentence) {

    int i, verb_loc, space_loc; 
    bool vowel=false;
    string new_word;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};

    // check to see if sentence starts with A
    if(sentence[0] == 'A') {

        // check if the following word starts with a vowel
        for(i=0; i<5; i++) {
            if(sentence[2] == vowels[i]) {
                vowel = true;
                break;
            }
        }
        // if the next word does start with a vowel change 'A' to 'An'
        if(vowel) {
            sentence.insert(1, "n");
        }
        // if the next word does not start with a vowel generate a new verb
        else {
            // find the location of the verb
            for(i=0; i<NUMVERBS; i++) {
                verb_loc = sentence.find(VERBS[i]);
                if(verb_loc < sentence.length())
                    break;
            }
            // find location of space after verb
            space_loc = sentence.find(" ", verb_loc);
            // erase and replace verb
            sentence.erase(verb_loc, space_loc - verb_loc); 
            new_word = PickWord(VERBS, NUMVERBS);
            sentence.insert(verb_loc, new_word);
        }
    }
}

// print all silly sentences
void PrintSentences(string sentences[], int len) {

    int i;

    cout << endl;

    // print sentences
    for(i=0; i<len; i++) {
        cout << sentences[i] << endl;
    }

}
