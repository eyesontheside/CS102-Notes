#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

const int DECKSIZE = 52;

int DrawCard();
int GenerateHand(string);
int AddCard(string, int);

int main() {

    int seed, num_games, player, dealer;
    string name;
    char response;

    cout << "Enter a seed value for the random number generator: ";
    cin >> seed;
    srand(seed);

    cout << "Enter your name: ";
    cin >> name;

    cout << "How many games do you want to play? ";
    cin >> num_games;

    for(i = 0; i < num_games; i++) {

        player = GenerateHand(name);
        dealer = GenerateHand("Dealer");

        cout << "Would you like another card? (y/n) ";
        cin >> response;

        while(response == 'y' && player < 21) {

            player = AddCard(name, player);
            cout << "Would you like to draw another card? (y/n) ";
            cin >> response;

        }

        if(player <= 21) {
            while(dealer <= 16) {
                dealer = AddCard("Dealer", dealer);
            }
        }
        else {
            cout << "test" << endl;
        }
       
    } 
}

// Background function for drawing a card. Returns integer value of card.
int DrawCard() {
    
    int card, x, y;

    x = rand() % DECKSIZE;

    y = x - ((x - 36) * (x / 36));

    card = (y / 4) + 1;

    cout << "Card is " << x << " with a value of " << card << endl;

    return card;

}

// Generates a new hand for a player. Returns the total value of the hard.
int GenerateHand(string name) {

    int card_1, card_2, total;

    card_1 = DrawCard();
    card_2 = DrawCard();
    total = card_1 + card_2;

    cout << name << " first card is a " << card_1 << endl;
    cout << name << " second card is a " << card_2 << endl;
    cout << name << " total points are " << total << endl;

    return total;
    
}

// Draws another card for an existing hand. Returns the new total value of the hand.
int AddCard(string name, int current_total) {
    
    int new_card, new_total;

    new_card = DrawCard();
    new_total = new_card + current_total;

    cout << name << " drew a " << new_card << endl;
    cout << name << " total points are " << new_total << endl;

}
