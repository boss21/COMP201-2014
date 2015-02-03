#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

enum Suit { HEARTS, SPADES, CLUBS, DIAMONDS };
const string suit_names[] = { "Hearts", "Spades", "Clubs", "Diamonds" };
enum Rank {
TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};
const string rank_names[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

typedef struct {
Suit suit;
Rank rank;
} Card;

void printCard(Card card);

vector<Card> makeDeck()
{
vector<Card> deck;

Card card;

for (int i = 0; i < 4; i++)
{
for (int j = 0; j < 13; j++)
{
card.suit = (Suit) i;
card.rank = (Rank) j;
deck.push_back(card);
}
}
return deck;
}

int main()
{
	vector<Card> deck = makeDeck();
	
	for (int i = 0; i < deck.size(); i++)
	{
	printCard(deck[i]);
	cout << endl;
	}
	return 0;
}
void printCard(Card card)
{
cout << rank_names[card.rank] << " of " <<  suit_names[card.suit];
}