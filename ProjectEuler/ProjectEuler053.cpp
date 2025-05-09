#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
There are exactly ten ways of selecting three from five, 12345:

    123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

                                         5
In combinatorics, we use the notation, (   ) = 10
                                         3
              n
In general, (   ) = n!/r!(n-r)!, where r <= n, n! = n * (n-1) * ... * 3 * 2 * 1, and 0! = 1.
              r
                                                            23
It is not until n = 23, that a value exceeds one-million: (    ) = 1144066.
                                                            10
                                                n
How many, not necessarily distinct, values of (   ) for 1 <= n <= 100, are greater than one-million?
                                                r
Answer: 4075 (2.031ms)

Tags: BinomialCoeficient
*/

/*
Thoughts:
I suppose that n = 23 and r = 10 are the base value.
(Turned out the above is wrong for r)
*/

unsigned ProjectEuler053(){
    unsigned counter = 0;

    for(unsigned long long n = 23; n <= 100; n++){
        for(unsigned long long r = 1; r <= n; r++){
            if (PEUtility::BinomialCoeficient(n, r) >= 1000000){
                counter++;
            }
        }
    }

    cout << counter << "\n";
    return counter;
}
