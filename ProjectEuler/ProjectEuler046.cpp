#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

    9   =   7 + 2 * 1^2
    15  =   7 + 2 * 2^2
    21  =   3 + 2 * 3^2
    25  =   7 + 2 * 3^2
    27  =   19 + 2 * 2^2
    33  =   31 + 2 * 1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

Answer: 5777 (67.589ms)

Tags: Prime
*/

/* Thoughts
The conjecture is

    composite_odd = P + 2 * n^2

with P a prime number and n a positive integer.

Potentially, there is a n such as P cannot be prime.
*/

void ProjectEuler046(){
    vector<unsigned int>& primes = PEUtility::EratostheneSieve(1000000);
    unsigned primeIndex = 3; // primes[3] = 7
    unsigned compositeOdd = primes[primeIndex] + 2;
    primeIndex++;

    unsigned n = 1;
    while(2*n*n < compositeOdd){
        unsigned P = compositeOdd - 2*n*n;
        n++;

        bool isPrime = false;
        for(unsigned prime : primes){
            if(prime > P){
                break;
            }

            if(prime == P){
                isPrime = true;
                break;
            }
        }

        if (isPrime){
            compositeOdd += 2;
            while (compositeOdd == primes[primeIndex]){
                compositeOdd += 2;
                primeIndex++; // ! oob
            }

            n = 1;
        }
    }

    cout << compositeOdd << "\n";
}
