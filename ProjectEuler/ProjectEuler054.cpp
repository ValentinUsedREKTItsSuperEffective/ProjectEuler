#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <algorithm>
#include "PEUtility.hpp"

using namespace std;

/*
In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

    - High Card: Highest value card.
    - One Pair: Two cards of the same value.
    - Two Pairs: Two different pairs.
    - Three of a Kind: Three cards of the same value.
    - Straight: All cards are consecutive values.
    - Flush: All cards of the same suit.
    - Full House: Three of a kind and a pair.
    - Four of a Kind: Four cards of the same value.
    - Straight Flush: All cards are consecutive values of same suit.
    - Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below).
But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared (see example 4 below);
if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand        Player 1            Player 2         Winner

 1      5H 5C 6S 7S KD      2C 3S 8S 8D TD      Player 2
         Pair of Fives      Pair of Eights

 2      5D 8C 9S JS AC      2C 5C 7D 8S QH      Player 1
       Highest card Ace   Highest card Queen

 3      2D 9C AS AH AC      3D 6D 7D TD QD      Player 2
          Three Aces      Flush with Diamonds

 4      4D 6S 9H QH QC      3D 6D 7H QD QS      Player 1
        Pair of Queens      Pair of Queens
       Highest card Nine  Highest card Seven

 5      2H 2D 4C 4D 4S      3C 3D 3S 9S 9D      Player 1
          Full House          Full House
        with Three Fours   with Three Threes

The file, .../Resources0054_poker.txt contains one-thousand random hands dealt to two players.
Each line of the file contains ten cards (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
You can assume that all hands are valid (no invalid characters or repeated cards),
each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?

Answer: 376 (3.572ms)

Tags: Poker
*/

/*
Thoughts:
There is no TIE possible
*/

struct Card{
    unsigned char value = 0;
    unsigned char suit = 0;

    bool operator==(const Card& o){
        return o.value == value;
    }

    bool operator==(const unsigned char v){
        return v == value;
    }
};

struct Hand{
    array<Card, 5> cards = {};

    void Add(unsigned char value, unsigned char suit){
        unsigned char index = 0;
        while(cards[index].value != 0){
            index++;
            if(index >= 5){
                return;
            }
        }

        cards[index].value = value;
        cards[index].suit = suit;
    }

    bool IsHandFull(){
        return cards[4].value > 0;
    }

    void Clear(){
        cards = {};
    }

    void Swap(unsigned char index, unsigned char index2){
        Card tmp = cards[index];
        cards[index] = cards[index2];
        cards[index2] = tmp;
    }

    bool IsPair(){
        if(cards[0] == cards[1]){
            return true;
        }

        if(cards[1] == cards[2]){
            Swap(0, 2);
            if(cards[0].value != cards[1].value){
                cout << "TROUBLE\n";
            }
            return true;
        }

        if(cards[2] == cards[3]){
            Swap(0, 2);
            Swap(1, 3);
            if(cards[0].value != cards[1].value){
                cout << "TROUBLE\n";
            }
            return true;
        }

        if(cards[3] == cards[4]){
            Swap(0, 3);
            Swap(1, 4);
            if(cards[0].value != cards[1].value){
                cout << "TROUBLE\n";
            }
            return true;
        }

        return false;
    }

    bool IsDoublePair(){
        if(cards[0] == cards[1] && cards[2] == cards[3]){
            return true;
        }

        if(cards[0] == cards[1] && cards[3] == cards[4]){
            Swap(2, 4);
            return true;
        }

        if(cards[1] == cards[2] && cards[3] == cards[4]){
            Swap(0, 2);
            Swap(2, 4);
            return true;
        }

        return false;
    }

    bool IsThreeOfAKind(){
        if(cards[0] == cards[2]){
            return true;
        }

        if(cards[1] == cards[3]){
            Swap(0, 3);
            return true;
        }

        if(cards[2] == cards[4]){
            Swap(0, 3);
            Swap(1, 4);
            return true;
        }

        return false;
    }

    bool IsStraight(){
        // Case [A, 2, 3, 4, 5]
        if (cards[0].value == 14 /* = 'A' */ && cards[1] == 5 /* = '5' */){
            return cards[2] == 4 && cards[3] == 3 && cards[4] == 2;
        }

        for(unsigned char i = 0; i < 4; i++){
            if(cards[i].value != cards[i+1].value + 1){
                return false;
            }
        }

        return true;
    }

    bool IsFlush(){
        unsigned char suit = cards[0].suit;
        for(unsigned char i = 1; i < 5; i++){
            if(cards[i].suit != suit){
                return false;
            }
        }

        return true;
    }

    bool IsFullHouse(){
        if(cards[0] == cards[2] && cards[3] == cards[4]){
            return true;
        }

        if (cards[0] == cards[1] && cards[2] == cards[4]){
            std::sort(cards.begin(), cards.end(), [](Card a, Card b){ return a.value < b.value; });
            return true;
        }

        return false;
    }

    bool IsFourOfAKind(){
        if(cards[0].value == cards[3].value){
            return true;
        }

        if(cards[1].value == cards[4].value){
            Swap(0, 4);
            return true;
        }

        return false;
    }

    bool IsStraightFlush(){
        return IsStraight() && IsFlush();
    }

    void SortByValue(){
        std::sort(cards.begin(), cards.end(), [](Card a, Card b){ return a.value > b.value; });
    }

    bool operator>(const Hand& other){
        for(unsigned char i = 0; i < 5; i++){
            if(cards[i].value > other.cards[i].value){
                return true;
            }

            if(cards[i].value < other.cards[i].value){
                return false;
            }
        }

        return false;
    }

    string ToString(){
        string str = "";

        const map<unsigned char, unsigned char> values = {
            {2, '2'},{3, '3'},{4, '4'},{5, '5'},{6,'6'},{7, '7'},{8, '8'},
            {9, '9'},{10, 'T'},{11, 'J'},{12, 'Q'}, {13, 'K'}, {14, 'A'}
        };

        const map<unsigned char, unsigned char> suits = {
            {0, 'S'},{1, 'H'},{2, 'D'},{3, 'C'}
        };

        for(Card c: cards){
            str += values.at(c.value);
            str += suits.at(c.suit);
            str += " ";
        }

        return str;
    }
};

char CompareHands(Hand& h1, bool hasRankHand_1, const Hand& h2, bool hasRankHand_2){
    if(hasRankHand_2 && !hasRankHand_1){
        return -1;
    }

    if(hasRankHand_1 && !hasRankHand_2){
        return 1;
    }

    if(hasRankHand_1 && hasRankHand_2){
        if(h1 > h2){
            return 1;
        }

        return -1;
    }

    return 0;
}

void ProjectEuler054(){
    Hand player1Hand = {};
    Hand player2Hand = {};

    const map<unsigned char, unsigned char> values = {
        {'2', 2},{'3', 3},{'4', 4},{'5', 5},{'6', 6},{'7', 7},{'8', 8},
        {'9', 9},{'T', 10},{'J', 11},{'Q', 12}, {'K', 13}, {'A', 14}
    };

    const map<unsigned char, unsigned char> suits = {
        {'S', 0},{'H', 1},{'D', 2},{'C', 3}
    };

    unsigned winCounter = 0;

    ifstream pokerFile;
    string line;
    pokerFile.open("../Resources/0054_poker.txt");
    if (pokerFile.is_open()){
        while ( std::getline (pokerFile,line) ){
            player1Hand.Clear();
            player2Hand.Clear();

            for(auto it = line.begin(); it != line.end(); it++){
                if(' ' == *it || '\n' == *it){
                    continue;
                }

                unsigned char value = values.at(*it);
                unsigned char suit = suits.at(*(++it));
                if(!player1Hand.IsHandFull()){
                    player1Hand.Add(value, suit);
                } else {
                    player2Hand.Add(value, suit);
                }
            }

            player1Hand.SortByValue();
            player2Hand.SortByValue();

            // --- Treat hands ---
            char comp = CompareHands(player1Hand, player1Hand.IsStraightFlush(), player2Hand, player2Hand.IsStraightFlush());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsFourOfAKind(), player2Hand, player2Hand.IsFourOfAKind());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsFullHouse(), player2Hand, player2Hand.IsFullHouse());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsFlush(), player2Hand, player2Hand.IsFlush());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsStraight(), player2Hand, player2Hand.IsStraight());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsThreeOfAKind(), player2Hand, player2Hand.IsThreeOfAKind());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsDoublePair(), player2Hand, player2Hand.IsDoublePair());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, player1Hand.IsPair(), player2Hand, player2Hand.IsPair());
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }

            comp = CompareHands(player1Hand, true, player2Hand, true);
            if(0 != comp){
                if(1 == comp){
                    winCounter++;
                }
                continue;
            }
            // --- Treat hands ---
        }

        pokerFile.close();

        cout << winCounter << "\n";
    }
}
