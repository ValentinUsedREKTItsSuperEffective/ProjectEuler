#include <iostream>
#include <map>

using namespace std;

/*
In the United Kingdom, the currency is made up of pound (l) and pence (p). There are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, 1l (100p), and 2l (200p).

It is possible to make 2l in the following way:

    1x1l + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p

How many different ways can 2l be made using any number of coins?

Answer: 73682
*/

/*
I tried at first the naive and tedious following way.
By considering that each coin has a fixed decomposition:
200 -> [100, 100]
100 -> [50, 50] or [20, 20, 20, 20, 20]
50 -> [20, 20, 10]
20 -> [10, 10]
10 -> [5, 5] or [2, 2, 2, 2, 2]
5 -> [2, 2, 1]
2 -> [1, 1]

but running it doesn't find every combination of coin.
For example, 20 cannot be lead to the combinaison [1*5p, 4*2p, 7*1p]
So, I stoped going this way.

void InsertCombinaison (map<unsigned short, unsigned short>& coinMap, map<unsigned long long, bool>& uniqueCombination) {
    unsigned long long key = coinMap[200] * 100000000000000ll +
                             coinMap[100] * 10000000000000ll +
                             coinMap[50]  * 1000000000000ll +
                             coinMap[20]  * 10000000000ll +
                             coinMap[10]  * 100000000ll +
                             coinMap[5]   * 1000000ll +
                             coinMap[2]   * 1000ll +
                             coinMap[1]   * 1ll;

    uniqueCombination[key] = true;
}

void SplitTwoPence(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    while (coinMap[2]-- > 0) {
        coinMap[1] += 2;

        InsertCombinaison(coinMap, uniqueCombination);
    }
}

void SplitFivePence(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    while (coinMap[5]-- > 0) {
        coinMap[2] += 2;
        coinMap[1] += 1;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitTwoPence(coinMap, uniqueCombination);
    }
}

void SplitTenPence(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    unsigned short t = coinMap[10], f = coinMap[5];

    while (coinMap[10]-- > 0) {
        coinMap[5] += 2;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitFivePence(coinMap, uniqueCombination);
    }

    coinMap[10] = t;
    coinMap[5] = f;
    while (coinMap[10]-- > 0) {
        coinMap[2] += 5;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitTwoPence(coinMap, uniqueCombination);
    }
}

void SplitTwentyPence(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    unsigned short tw = coinMap[20], te = coinMap[10];

    while (coinMap[20]-- > 0) {
        coinMap[10] += 2;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitTenPence(coinMap, uniqueCombination);
    }

    coinMap[20] = tw;
    coinMap[10] = te;

    while (coinMap[20]-- > 0) {
        coinMap[5] += 1;
        coinMap[2] += 7;
        coinMap[1] += 1;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitFivePence(coinMap, uniqueCombination);
        SplitTwoPence(coinMap, uniqueCombination);
    }
}

void SplitFiftyPence(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    while (coinMap[50]-- > 0) {
        coinMap[20] += 2;
        coinMap[10] += 1;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitTwentyPence(coinMap, uniqueCombination);
        SplitTenPence(coinMap, uniqueCombination);
    }
}

void SplitOnePound(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    unsigned short h = coinMap[100], f = coinMap[50];

    while (coinMap[100]-- > 0) {
        coinMap[50] += 2;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitFiftyPence(coinMap, uniqueCombination);
    }

    coinMap[100] = h;
    coinMap[50] = f;
    while (coinMap[100]-- > 0) {
        coinMap[20] += 5;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitTwentyPence(coinMap, uniqueCombination);
    }
}

void SplitTwoPounds(map<unsigned short, unsigned short> coinMap, map<unsigned long long, bool>& uniqueCombination) {
    while (coinMap[200]-- > 0) {
        coinMap[100] += 2;

        InsertCombinaison(coinMap, uniqueCombination);

        SplitOnePound(coinMap, uniqueCombination);
    }
}

void ProjectEuler031(){
    map<unsigned short, unsigned short> coinMap = map<unsigned short, unsigned short>();
    map<unsigned long long, bool> uniqueCombination = map<unsigned long long, bool>();

    coinMap[200] = 0;
    coinMap[100] = 0;
    coinMap[50] = 0;
    coinMap[20] = 1;
    coinMap[10] = 0;
    coinMap[5] = 0;
    coinMap[2] = 0;
    coinMap[1] = 0;
    InsertCombinaison(coinMap, uniqueCombination);

    SplitTwoPounds(coinMap, uniqueCombination);

    cout << uniqueCombination.size() << endl;
}

Instead, let's brute force.
*/

void NextCoin(unsigned short remain, unsigned short* coins, unsigned int& combinations) {
    unsigned short coin = *coins;
    if (coin == 1) {
        remain = 0;
    }

    if (remain == 0) {
        combinations++;
        return;
    } else {
        for (unsigned short i = 0; i <= remain; i += coin) {
            NextCoin(remain - i, coins+1, combinations);
        }
    }
}

void ProjectEuler031(){
    unsigned short coins[8] = {200, 100, 50, 20, 10, 5, 2, 1};
    unsigned int combinaison = 0;

    NextCoin(200, coins, combinaison);

    cout << combinaison << endl;
}
