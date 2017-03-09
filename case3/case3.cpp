#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// size of a deck of cards
const int DECKSIZE = 52;

int DrawCard();
int GenerateHand(string);
int AddCard(string, int);

int main() {

    int seed, num_games, i;
    int player, dealer, player_count=0, dealer_count=0;
    char response;
    string name;
    bool bust;

    // prompt user to seed random number generator
    cout << "Enter a seed value for the random number generator: ";
    cin >> seed;
    srand(seed);

    cout << "Enter your name: ";
    cin >> name;

    cout << name << ", how many hands would you like to play?";
    cin >> num_games;

    // loop to play "num_games" games
    for(i = 0; i < num_games; i++) {

        bust = false;

        cout << endl;

        // generate a hand for player and dealer
        player = GenerateHand(name);
        cout << endl;

        dealer = GenerateHand("Dealer");
        cout << endl;
       
        // draw a card for player until they request to stop
        cout << name << ", do you want to draw another card? (y/n)";
        cin >> response;

        while(response == 'y') {

            cout << endl;
            player = AddCard(name, player);

            if(player <= 21) {
                cout << name << ", do you want to draw another card? (y/n)";
                cin >> response;
            }
            else {
                bust = true;
                break;
            }
             
        }

        cout << endl;

        // if the player did not bust then have the dealer draw until they have 17 points or more
        if(!bust) {
            while(dealer < 17) {

                dealer = AddCard("Dealer", dealer);
                cout << endl; 

            }
            cout << endl;
        }

        // print the results of this game
        cout << "The Result" << endl;
        cout << name << ": has " << player << " points" << endl;
        cout << "Dealer: has " << dealer << " points" << endl;

        // determine winner
        if(bust) {
            cout << name << ": lose" << endl;
            dealer_count += 1;
        }
        else if(player > dealer || dealer > 21) {
            cout << name << ": win!" << endl; 
            player_count += 1;
        }
        else {
            cout << name << ": lose" << endl;
            dealer_count += 1;
        }


    }

    // print the recap for every round
    cout << endl;
    cout << "The Recap" << endl;
    cout << name << ": won " << player_count << " games" << endl;
    cout << "Dealer: won " << dealer_count << " games" << endl;
}

// Background function for drawing a card. Returns integer value of card.
int DrawCard() {
    
    int card, x, y;

    x = rand() % DECKSIZE;

    y = x - ((x - 36) * (x / 36));

    card = (y / 4) + 1;

    return card;

}

// Generates a new hand for a player. Returns the total value of the hard.
int GenerateHand(string name) {

    int card_1, card_2, total;

    card_1 = DrawCard();
    card_2 = DrawCard();
    total = card_1 + card_2;

    cout << name << ": first card is a " << card_1 << endl;
    cout << name << ": second card is a " << card_2 << endl;
    cout << name << ": total points are " << total << endl;

    return total;
    
}

// Draws another card for an existing hand. Returns the new total value of the hand.
int AddCard(string name, int current_total) {
    
    int new_card, new_total;

    new_card = DrawCard();
    new_total = new_card + current_total;

    cout << name << ": drew a " << new_card << endl;
    cout << name << ": total points are " << new_total << endl;

    return new_total;

}
