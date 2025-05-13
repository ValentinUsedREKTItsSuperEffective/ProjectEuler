#include <iostream>
#include <fstream>
#include <array>
#include <map>
#include <set>
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

Answer:

Tags:
*/

/*
Thoughts:
*/

// Include Royal flush
// Return highest card value
unsigned short IsStraightFlush(const array<unsigned short, 4>& hand){
    for(unsigned short suit: hand){
        if (suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 256 /* = '9' */; i *= 2){
            // '==' operator has higher priority than '&' operator
            if((suit & i) == i){
                unsigned short expectedHand = i + i*2 + i*4 + i*8 + i*16;
                return suit == expectedHand ? i*16 : 0;
            }
        }
    }

    return 0;
}

// Return value of the "four of a kind"
unsigned short IsFourOfAKind(const array<unsigned short, 4>& hand, unsigned short& kicker){
    unsigned short kind = 0;
    for(unsigned short suit: hand){
        if(suit == 0){
            // each suit should have a value > 0 to be Four of a kind
            return 0;
        }

        if(suit != kind){
            if (kind == 0){
                kind = suit;
            } else {
                if(kicker == 0){
                    if(suit > kind){
                        kicker = suit - kind;
                    } else {
                        kicker = kind - suit;
                    }
                } else {
                    // The hand has at least 3 different values
                    return 0;
                }
            }
        }
    }

    return kind;
}

// Return value of the "three of a kind"
unsigned short IsFullHouse(const array<unsigned short, 4>& hand, unsigned short& pair){
    array<unsigned short, 2> values = {};
    array<unsigned short, 2> counters = {};

    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 4096 /* = 'A' */; i *= 2){
            unsigned short v = suit & i;
            if(v == 0){
                continue;
            }

            if(values[0] == 0){
                values[0] = v;
                counters[0]++;
                continue;
            }

            if(values[0] == v){
                counters[0]++;
                continue;
            }

            if(values[1] == 0){
                values[1] = v;
                counters[1]++;
                continue;
            }

            if(values[1] == v){
                counters[1]++;
                continue;
            }

            // more than two different values
            return 0;
        }
    }

    if(counters[0] == 3 && counters[1] == 2){
        pair = values[1];
        return values[0];
    }

    if(counters[1] == 3 && counters[0] == 2){
        pair = values[0];
        return values[1];
    }

    // Error
    return 0;
}

// Return hand value
unsigned short IsFlush(const array<unsigned short, 4>& hand){
    unsigned short flushValue = 0;

    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        if(flushValue == 0){
            flushValue = suit;
        } else {
            // more than 1 suit has value
            return 0;
        }
    }

    return flushValue;
}

// Return highest card value
unsigned short IsStraight(const array<unsigned short, 4>& hand){
    for(unsigned short i = 1; i <= 256 /* = '9' */; i *= 2){
        if(hand[0] & i == i || hand[1] & i == i || hand[2] & i == i || hand[3] & i == i){
            if(hand[0] + hand[1] + hand[2] + hand[3] == i + i*2 + i*4 + i*8 + i*16){
                return i*16;
            }

            // not a straight
            return 0;
        }
    }
}

unsigned short IsThreeOfAKind(const array<unsigned short, 4>& hand, array<unsigned short, 2>& kickers){
    array<unsigned short, 3> values = {};
    array<unsigned short, 3> counters = {};

    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 4096 /* = 'A' */; i *= 2){
            unsigned short v = suit & i;
            if(v == 0){
                continue;
            }

            if(values[0] == 0){
                values[0] = v;
                counters[0]++;
                continue;
            }

            if(values[0] == v){
                counters[0]++;
                continue;
            }

            if(values[1] == 0){
                values[1] = v;
                counters[1]++;
                continue;
            }

            if(values[1] == v){
                counters[1]++;
                continue;
            }

            if(values[2] == 0){
                values[2] = v;
                counters[2]++;
                continue;
            }

            if(values[2] == v){
                counters[2]++;
                continue;
            }

            // more than two different values
            return 0;
        }
    }

    unsigned short kind = 0;
    for(unsigned char i = 0; i < 3; i++){
        if(counters[i] == 3){
            kind = values[i];
        } else {
            if(kickers[0] == 0) {
                kickers[0] = values[i];
            } else {
                if(values[i] > kickers[0]){
                    kickers[1] = kickers[0];
                    kickers[0] = values[i];
                } else {
                    kickers[1] = values[i];
                }
            }
        }
    }

    return kind;
}

unsigned short IsDoublePair(const array<unsigned short, 4>& hand, unsigned short& kicker){
    array<unsigned short, 3> values = {};
    array<unsigned short, 3> counters = {};

    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 4096 /* = 'A' */; i *= 2){
            unsigned short v = suit & i;
            if(v == 0){
                continue;
            }

            if(values[0] == 0){
                values[0] = v;
                counters[0]++;
                continue;
            }

            if(values[0] == v){
                counters[0]++;
                continue;
            }

            if(values[1] == 0){
                values[1] = v;
                counters[1]++;
                continue;
            }

            if(values[1] == v){
                counters[1]++;
                continue;
            }

            if(values[2] == 0){
                values[2] = v;
                counters[2]++;
                continue;
            }

            if(values[2] == v){
                counters[2]++;
                continue;
            }

            // more than two different values
            return 0;
        }
    }

    unsigned short DoublePair = 0;
    for(unsigned char i = 0; i < 3; i++){
        if(counters[i] == 2){
            DoublePair = values[i];
        } else {
            kicker = values[i];
        }
    }

    return DoublePair;
}

unsigned short IsPair(const array<unsigned short, 4>& hand, multiset<unsigned short>& kickers){
    array<unsigned short, 4> values = {};
    array<unsigned short, 4> counters = {};

    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 4096 /* = 'A' */; i *= 2){
            unsigned short v = suit & i;
            if(v == 0){
                continue;
            }

            if(values[0] == 0){
                values[0] = v;
                counters[0]++;
                continue;
            }

            if(values[0] == v){
                counters[0]++;
                continue;
            }

            if(values[1] == 0){
                values[1] = v;
                counters[1]++;
                continue;
            }

            if(values[1] == v){
                counters[1]++;
                continue;
            }

            if(values[2] == 0){
                values[2] = v;
                counters[2]++;
                continue;
            }

            if(values[2] == v){
                counters[2]++;
                continue;
            }

            if(values[3] == 0){
                values[3] = v;
                counters[3]++;
                continue;
            }

            if(values[3] == v){
                counters[3]++;
                continue;
            }

            // more than two different values
            return 0;
        }
    }

    unsigned short pair = 0;
    for(unsigned char i = 0; i < 3; i++){
        if(counters[i] == 2){
            pair = values[i];
        } else {
            kickers.insert(values[i]);
        }
    }

    return pair;
}

void ToMultiset(const array<unsigned short, 4>& hand, multiset<unsigned short>& handset){
    for(unsigned short suit: hand){
        if(suit == 0){
            continue;
        }

        for(unsigned short i = 1; i <= 4096 /* = 'A' */; i *= 2){
            unsigned short v = suit & i;
            if(v == 0){
                continue;
            }

            handset.insert(v);
        }
    }
}

void ProjectEuler054(){
    array<unsigned short, 4> player1Hand = array<unsigned short, 4>();
    array<unsigned short, 4> player2Hand = array<unsigned short, 4>();

    const map<char, unsigned short> values = {
        {'2', 1},{'3', 2},{'4', 4},{'5', 8},{'6', 16},{'7', 32},{'8', 64},
        {'9', 128},{'T', 256},{'J', 512},{'Q', 1024}, {'K', 2048}, {'A', 4096}
    };

    const map<char, char> suits = {
        {'S', 0},{'H', 1},{'D', 2},{'C', 3}
    };

    unsigned player1WinCounter = 0;

/*
    cout << "--- Royal flush ---\n";
    player1Hand = {0, 0, 0, 7936};
    cout << (IsStraightFlush(player1Hand) > 0)<< "\n";
    player2Hand = {0, 7935, 0, 1};
    cout << (IsStraightFlush(player2Hand) > 0) << "\n";

    cout << "--- Straight flush ---\n";
    player1Hand = {0, 0, 496, 0};
    cout << IsStraightFlush(player1Hand) << "\n";
    player1Hand = {0, 0, 0, 0};
    cout << IsStraightFlush(player1Hand) << "\n";
    player1Hand = {0, 16, 480, 0};
    cout << IsStraightFlush(player1Hand) << "\n";

    cout << "--- Four of a kind ---\n";
    unsigned short k = 0;
    player1Hand = {1024, 1024, 1025, 1024};
    cout << (IsFourOfAKind(player1Hand, k) == 1024 && k == 1)<< "\n";
    player1Hand = {1024, 1024, 514, 1024};
    cout << (IsFourOfAKind(player1Hand, k) == 0)<< "\n";

    cout << "--- Full house ---\n";
    player1Hand = {1024, 1024, 1025, 1024};
    cout << (IsFourOfAKind(player1Hand, k) == 1024 && k == 1)<< "\n";

    return;
    */

    ifstream pokerFile;
    string line;
    pokerFile.open("../Resources/0054_poker.txt");
    if (pokerFile.is_open()){
        while ( std::getline (pokerFile,line) ){
            player1Hand = {};
            player2Hand = {};

            // cout << line << "\n";
            unsigned char player1Cards = 5;
            for(auto it = line.begin(); it != line.end(); it++){
                if(' ' == *it || '\n' == *it){
                    continue;
                }

                unsigned short value = values.at(*it);
                char suit = suits.at(*(++it));
                if(player1Cards){
                    player1Hand[suit] += value;
                    player1Cards--;
                } else {
                    player2Hand[suit] += value;
                }
            }

            // --- Treat hands ---
            unsigned short v1 = IsStraightFlush(player1Hand);
            unsigned short v2 = IsStraightFlush(player2Hand);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v1 > 0){
                if(v2 == v1){
                    // tie
                    continue;
                }

                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " straight flush\n";
                continue;
            }

            unsigned short player1Kicker = 0;
            unsigned short player2Kicker = 0;
            v1 = IsFourOfAKind(player1Hand, player1Kicker);
            v2 = IsFourOfAKind(player2Hand, player2Kicker);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v2 == v1 && v1 > 0){
                if(player2Kicker > player1Kicker) {
                    // p2 win by kicker
                    continue;
                }

                if(player1Kicker == player2Kicker){
                    // tie
                    continue;
                }

                // p1 win by kicker
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " kind of four\n";
                continue;
            }

            if(v1 > 0){
                // p1 win
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " kind of four(kicker)\n";
                continue;
            }

            unsigned short player1Pair = 0;
            unsigned short player2Pair = 0;
            v1 = IsFullHouse(player1Hand, player1Pair);
            v2 = IsFullHouse(player2Hand, player2Pair);
            if(v2 > v1){
                // p2 win by full house
                continue;
            }

            if(v2 == v1 && v1 > 0){
                if(player2Pair > player1Pair) {
                    // p2 win by higher pair
                    continue;
                }

                if(player1Pair == player2Pair){
                    // tie
                    continue;
                }

                // p1 win by higherPair
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " full house\n";
                continue;
            }

            if(v1 > 0){
                // p1 win by full house
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " full house\n";
                continue;
            }

            v1 = IsFlush(player1Hand);
            v2 = IsFlush(player2Hand);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v1 > 0){
                if(v2 == v1){
                    // tie
                    continue;
                }

                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " flush\n";
                continue;
            }

            v1 = IsStraight(player1Hand);
            v2 = IsStraight(player2Hand);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v1 > 0){
                if(v2 == v1){
                    // tie
                    continue;
                }

                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " straight\n";
                continue;
            }

            array<unsigned short, 2> player1Kickers = {};
            array<unsigned short, 2> player2Kickers = {};
            v1 = IsThreeOfAKind(player1Hand, player1Kickers);
            v2 = IsThreeOfAKind(player2Hand, player2Kickers);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v2 == v1 && v1 > 0){
                if(player2Kickers[0] > player1Kickers[0]) {
                    // p2 win by kicker
                    continue;
                }

                if(player1Kickers[0] == player2Kickers[0]){
                    if(player2Kickers[1] > player1Kickers[1]) {
                        // p2 win by kicker
                        continue;
                    }

                    if(player1Kickers[1] == player1Kickers[1]){
                        // tie
                        continue;
                    }

                    // p1 win by kicker
                    cout << line << "\n";
                    player1WinCounter++;
                    cout << player1WinCounter << " kind of three(kicker)\n";
                    continue;
                }

                // p1 win by kicker
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " kind of three(kicker)\n";
                continue;
            }

            if(v1 > 0){
                // p1 win
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " kind of three\n";
                continue;
            }

            v1 = IsDoublePair(player1Hand, player1Kicker);
            v2 = IsDoublePair(player2Hand, player2Kicker);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v2 == v1 && v1 > 0){
                if(player2Kicker > player1Kicker) {
                    // p2 win by kicker
                    continue;
                }

                if(player1Kicker == player2Kicker){
                    // tie
                    continue;
                }

                // p1 win by kicker
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " double pair(kicker)\n";
                continue;
            }

            if(v1 > 0){
                // p1 win
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " double pair\n";
                continue;
            }

            multiset<unsigned short> player1KickersMultiset = {};
            multiset<unsigned short> player2KickersMultiset = {};
            v1 = IsPair(player1Hand, player1KickersMultiset);
            v2 = IsPair(player2Hand, player2KickersMultiset);
            if(v2 > v1){
                // p2 win
                continue;
            }

            if(v2 == v1 && v1 > 0){
                if(player2KickersMultiset > player1KickersMultiset) {
                    // p2 win by kicker
                    continue;
                }

                if(player2KickersMultiset == player1KickersMultiset){
                    // tie
                    continue;
                }

                // p1 win by kicker
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " pair(kicker)\n";
                continue;
            }

            if(v1 > 0){
                // p1 win
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " pair\n";
                continue;
            }

            player1KickersMultiset.clear();
            player2KickersMultiset.clear();
            ToMultiset(player1Hand, player1KickersMultiset);
            ToMultiset(player2Hand, player2KickersMultiset);
            bool a_less_than_b = std::lexicographical_compare(
                player1KickersMultiset.rbegin(), player1KickersMultiset.rend(),
                player2KickersMultiset.rbegin(), player2KickersMultiset.rend()
            );

            if(!a_less_than_b){
                cout << line << "\n";
                player1WinCounter++;
                cout << player1WinCounter << " highest\n";
            }

            // --- Treat hands ---
        }

        pokerFile.close();

        cout << player1WinCounter << "\n";
    }
}
