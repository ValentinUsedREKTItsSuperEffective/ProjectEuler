#include <iostream>

using namespace std;

/*
In the United Kingdom the currency is made up of pound (l) and pence (p). There are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, 1l (100p), and 2l (200p).

It is possible to make 2l in the following way:

    1x1l + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p

How many different ways can 2l be made using any number of coins?

Answer:
*/

unsigned int SplitTwoPence() {
    return 1;
}

unsigned int SplitFivePence() {
    return 1 +  SplitTwoPence() +  SplitTwoPence();
}

unsigned int SplitTenPence() {
    // Last one because 1L can be 5*2p
    return 1 + SplitFivePence() + SplitFivePence() + 1;
}

unsigned int SplitTwentyPence() {
    return 1 + SplitTenPence() + SplitTenPence();
}

unsigned int SplitFiftyPence() {
    return 1 + SplitTwentyPence() + SplitTwentyPence() + SplitTenPence();
}

unsigned int SplitOnePound() {
    // Last one because 1L can be 5*20p
    return 1 + SplitFiftyPence() + SplitFiftyPence() + 1;
}

unsigned int SplitTwoPounds() {
    // Two coins of 1l
    return 1 + SplitOnePound() + SplitOnePound();
}

void ProjectEuler031(){
    // A coins of 2l
    unsigned int ways = 1;

    ways += SplitTwoPounds();

    cout << ways << endl;
}

