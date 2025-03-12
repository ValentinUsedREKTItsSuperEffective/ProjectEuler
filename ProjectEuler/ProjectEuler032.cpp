#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include "PEUtility.hpp"

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 Å~ 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.


Answer: 45228 (837.116ms)
*/

/*
So we need a number of 9 digits that contain only one time the digits between 1 and 9.

So a number that include a 0 is not pandigital.

log 10 + 1 to get the length of a natural integer.
*/

unsigned int IntSize(unsigned long long value){
    if (value == 0ll) {
        return 1;
    }

    return 1 + log10(value);
}

bool IsNPandigital(unsigned short n, unsigned long long value){
    if (IntSize(value) != n) {
        return false;
    }

    vector<unsigned short> brokenValue = PEUtility::BreakNumber(value);
    vector<bool> bMap;
    bMap.assign(n+1, false);
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

template<unsigned int E, unsigned int N>
struct pow_struct {
    enum {value = E * pow_struct<E, N - 1>::value };
};

template<unsigned int E>
struct pow_struct<E, 0> {
    enum {value = 1};
};

template<unsigned int E>
unsigned long long FastPow(unsigned int n) {
    static unsigned long long table[] = {
        pow_struct<E, 0>::value,
        pow_struct<E, 1>::value,
        pow_struct<E, 2>::value,
        pow_struct<E, 3>::value,
        pow_struct<E, 4>::value,
        pow_struct<E, 5>::value,
        pow_struct<E, 6>::value,
        pow_struct<E, 7>::value,
        pow_struct<E, 8>::value,
        pow_struct<E, 9>::value,
        pow_struct<E, 10>::value
    };

    return table[n];
}

void ProjectEuler032(){
    map<unsigned long long, unsigned short> productMap;
    unsigned long long total = 0ll;
    for (unsigned long long i = 1ll; i < 1000ll; i++) {
        // J = I + 1 because previous value of I have been already computed and would false the result
        for (unsigned long long j = i + 1ll; j < 10000ll; j++) {
            unsigned long long product = i * j;
            unsigned long long productSize = IntSize(product);
            unsigned long long jSize = IntSize(j);
            if(IsNPandigital(9, i*FastPow<10>(productSize+jSize) + j*FastPow<10>(productSize) + product)) {
                //cout << i*FastPow<10>(productSize+jSize) + j*FastPow<10>(productSize) + product << endl;
                if (productMap[product] == 0) {
                    total += product;
                    productMap[product] = 1;
                }
            }
        }
    }

    cout << total << endl;
}
