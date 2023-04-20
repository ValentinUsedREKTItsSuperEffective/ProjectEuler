#include <iostream>
#include <cmath>
#include "PEUtility.hpp"

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 Å~ 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


Answer:
*/

/*
So we need a number of 9 digits that contain only one time the digits between 1 and 9.

So a number that include a 0 is not pandigital.

log 10 + 1 to get the length of a natural integer.
*/

unsigned int IntSize(int value){
    if (value == 0) {
        return 1;
    }

    if (value < 0){
        value = abs(value);
    }

    return 1 + log10(value);
}

bool IsNPandigital(unsigned short n, unsigned int value){
    if (IntSize(value) != n) {
        return false;
    }

    auto brokenValue = PEUtility::breakNumber(value);
    bool bMap[n];
    for (auto a : brokenValue) {
        if (a < 1 || a > n) {
            return false;
        }

        if (bMap[a]) {
            return false;
        }

        bMap[a] = true;
    }

    return true;
}

void ProjectEuler032(){
    unsigned long long total = 0ll;
    for (unsigned int i = 1; i < 10000; i++) {
        for (unsigned int j = i + 1; j < 10000; j++) {
            unsigned int product = i * j;
            unsigned int productSize = IntSize(product);
            unsigned int jSize = IntSize(j);
            if(IsNPandigital(9, i*pow(10, productSize+jSize) + j*pow(10, productSize) + product)) {
                // cout << i*pow(10, productSize+jSize) + j*pow(10, productSize) + product << endl;
                total += product;
            }
        }
    }

    cout << total << endl;
}
