#include <iostream>
#include "PEUtility.hpp"
#include <climits>

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer:

Tags: Pandigital
*/

void ProjectEuler041(){
    static_assert(UINT_MAX >= 987654321);

    vector<unsigned>& primes = PEUtility::EratostheneSieve(987654321);

    for(auto it = primes.rbegin(); it != primes.rend(); ++it){
        if (PEUtility::IsPandigital(*it)) {
            cout << *it << "\n";
            return;
        }
    }

    cout << "0\n";
}
