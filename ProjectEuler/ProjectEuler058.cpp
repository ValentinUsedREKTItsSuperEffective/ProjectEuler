#include <iostream>
#include <climits>
#include "PEUtility.hpp"

using namespace std;

/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

                                            37 36 35 34 33 32 31
                                            38 17 16 15 14 13 30
                                            39 18  5  4  3 12 29
                                            40 19  6  1  2 11 28
                                            41 20  7  8  9 10 27
                                            42 21 22 23 24 25 26
                                            43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal,
but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime;
that is, a ratio of 8/13 (~62%).

If one complete new layer is wrapped around the spiral above,
a square spiral with side length 9 will be formed. If this process is continued,
what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%.

Answer: 26241 (39294.7ms)

Tags: Ulam spiral
*/

/* Thoughts
Step of 2:
1 -> 3 -> 5 -> 7 -> 9       (Layer 2)
Step of 4:
9 -> 13 -> 17 -> 21 -> 25   (Layer 3)
Step of 6:
25 -> 31 -> 37 -> 49        (Layer 4)
Step of 8:
...

We have pattern to follow.
*/

void ProjectEuler058(){
    unsigned sieveLimit = 1000000000;

    if(sieveLimit > std::numeric_limits<unsigned>::max()){
        cout << "Unsigned limit exceeded";
        return;
    }

    auto primes = PEUtility::EratostheneSieve(sieveLimit);
    auto primeIterator = primes.begin();

    unsigned primeCounter = 0;
    unsigned counter = 1;
    unsigned corner = 1;
    unsigned step = 0;

    do{
        step += 2;

        for(unsigned i = 0; i < 3; i++){
            corner += step;
            while (corner >= *primeIterator) {
                if(corner == *primeIterator) {
                    primeCounter++;
                }

                primeIterator++;
                if(primeIterator == primes.end()){
                    cout << "Sieve limit!\n";
                    return;
                }
            }
        }

        corner += step; // bottom right corner is always square of an odd number
        counter += 4; // + 4 for the 4 corners
    } while(10*primeCounter > counter);

    cout << step + 1 << "\n";
}
