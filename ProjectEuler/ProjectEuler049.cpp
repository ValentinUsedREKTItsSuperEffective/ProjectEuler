#include <iostream>
#include <algorithm>
#include <math.h>
#include "PEUtility.hpp"

using namespace std;

/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
    1. Each of the three terms are prime, and,
    2. Each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property,
but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

Answer: 296962999629 (20.808ms)

Tags: Permutation, Algorithm
*/

void ProjectEuler049(){
    auto primes = PEUtility::EratostheneSieve(10000);
    char counter = 0;

    for(unsigned i = 0; i < primes.size(); i++){
        if (primes[i] < 1000){
            continue;
        }

        auto primeStr = std::to_string(primes[i]);
        unsigned prime = 0;
        while(std::next_permutation(primeStr.begin(), primeStr.end())){
            prime = std::stoi(primeStr);
            if (PEUtility::IsPrime(prime)){
                unsigned thirdPrime = 0;
                if (prime > primes[i]){
                    thirdPrime = 2*prime - primes[i];
                    if (PEUtility::IsPrime(thirdPrime)){
                        auto thirdPrimeStr = to_string(thirdPrime);
                        if (std::is_permutation(primeStr.begin(), primeStr.end(), thirdPrimeStr.begin())){
                            cout << primes[i] << prime << thirdPrime << "\n";

                            if(++counter >= 2){
                                return;
                            }
                        }
                    }
                } else {
                    thirdPrime = 2*primes[i] - prime;
                    if (PEUtility::IsPrime(thirdPrime)){
                        auto thirdPrimeStr = to_string(thirdPrime);
                        if (std::is_permutation(primeStr.begin(), primeStr.end(), thirdPrimeStr.begin())){
                            cout << prime << primes[i] << thirdPrime << "\n";

                            if(++counter >= 2){
                                return;
                            }
                        }
                    }
                }
            }

        }
    }
}
