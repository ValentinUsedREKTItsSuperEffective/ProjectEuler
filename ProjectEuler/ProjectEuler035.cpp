#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>

#include "PEUtility.hpp"

using namespace std;

/*
The number 197, is called a circular prime because all rotations of the digits: 197, 971 and 719 are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 31. 37. 71. 73, 79 and 97.

How many circular primes are there below one million?

Answer: 55 (146.577ms)

Tags: Prime
*/

void ProjectEuler035(){
    unsigned int result = 0;

    // Pre-compute prime numbers
    vector<unsigned int> primes = PEUtility::EratostheneSieve(1000000);

    // Map prime for easier search after
    map<unsigned int, char> primesMap;
    for(unsigned int prime : primes) {
        primesMap[prime] = 0;
    }

    // Since we deal with circular number, it would be a shame to preform the same operation log10 time the prime
    // So let's remove encountered circular prime using a set
    set<unsigned int> primeToRemove;
    for(unsigned int prime : primes) {
        // Check the prime has not been removed already
        if (primesMap.find(prime) == primesMap.end()) {
            continue;
        }

        primeToRemove.clear();
        // Consider the prime to check as circular, then check if it is true using the loop below
        primeToRemove.insert(prime);
        unsigned char primeNumberSize = std::log10(prime); // 0 < log10(9) < 1. log10(10) = 1
        for(unsigned char i = primeNumberSize; i >= 0; i--) {
            if (i == 0) {
                // Means that all prime in the set are circular
                result += primeToRemove.size();
                for (auto it: primeToRemove) {
                    //cout << it << endl; // Uncomment to see the circular primes
                    primesMap.erase(it);
                }
                break;
            }

            // Swap first and last numbers
            prime = prime/10 + std::pow(10,primeNumberSize)*(prime%10);

            // Check if the permuted number is still a prime
            if(primesMap.find(prime) == primesMap.end()) {
                break;
            }

            primeToRemove.insert(prime);
        }
    }

    cout << result << endl;
}

