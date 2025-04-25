#include <iostream>
#include "PEUtility.hpp"
#include <array>
#include <set>
#include <math.h>

using namespace std;

/*
The first two consecutive numbers to have two distinct prime factors are:

                                14 = 2 * 7
                                15 = 3 * 5

The first three consecutive numbers to have three distinct prime factors are:

                            644 = 2^2 * 7 * 23
                            645 = 3 * 5 * 43
                            646 = 2 * 17 * 19

Find the first four consecutive integers to have four distinct prime factors each.
What is the first of these numbers?

Answer: 134043 (25595.6ms)

Tags: Prime, Prime decomposition
*/

bool DecomposeIntoFourPrime(unsigned long long integer, const vector<unsigned>& primes, array<unsigned long long, 4>& decomposition){
    unsigned primeIndex = 0;
    unsigned decompositionIndex = 0;

    while(!PEUtility::IsPrime(integer) && decompositionIndex < 3){
            if (primes[primeIndex] == 0){
                cout << integer << " " <<  primeIndex << "\n";
            }
        while(integer % primes[primeIndex] == 0){
            integer /= primes[primeIndex];
            if(decomposition[decompositionIndex] == 0){
                decomposition[decompositionIndex] = primes[primeIndex];
            } else {
                decomposition[decompositionIndex] *= primes[primeIndex];
            }
        }

        if(integer == 1){
            break;
        }

        primeIndex++;
        if(primeIndex > primes.size()){
            break;
        }

        if (decomposition[decompositionIndex] > 0){
            decompositionIndex++;
        }
    }

    if (PEUtility::IsPrime(integer)){
        decomposition[decompositionIndex] = integer;
    } else {
        return false;
    }

    return decomposition[3] != 0;
}

bool InsertIfDistinct(set<unsigned long long>& distincts, const array<unsigned long long, 4>& decomposition){
    for(unsigned long long n : decomposition){
        if(distincts.count(n) == 0){
            distincts.insert(n);
        } else {
            return false;
        }
    }

    return true;
}

void ProjectEuler047(){
    auto primes = PEUtility::EratostheneSieve(1000000);
    set<unsigned long long> distincts = set<unsigned long long>();

    unsigned long long integer = 2 * 3 * 5 * 7;
    distincts.insert(2);
    distincts.insert(3);
    distincts.insert(5);
    distincts.insert(7);

    unsigned consecutive = 1; // integer being the first of a potential four consecutive integers, we initialize with 1 here
    array<unsigned long long, 4> D;
    while(consecutive < 4){
        integer++;
        D = {0,0,0,0};

        if(DecomposeIntoFourPrime(integer, primes, D) && InsertIfDistinct(distincts, D)){
            consecutive++;
        } else {
            distincts.clear();
            consecutive = 0;
        }
    }

    cout << integer-3 << "\n";
}
