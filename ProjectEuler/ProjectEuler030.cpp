#include <iostream>
#include <map>

using namespace std;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers "n" that can be written as the sum of fifth powers of their digits.


Answer:
*/

/*
First of all, we need to find a sum so n has at least 2 digits.

The maximum n possible seems to b 239999 as its sum is 236471.

While computing the sum for n, if the sum getting bigger than n, then no need to continue to compute
*/

void ProjectEuler030(){
    // Precompute powers
    map<unsigned short, unsigned int> pows;

    for(int i = 0; i < 10; i++){
        pows[0] = i*i*i*i*i;
    }

    for(int i = 10; i < 239999; i++){

    }
}

