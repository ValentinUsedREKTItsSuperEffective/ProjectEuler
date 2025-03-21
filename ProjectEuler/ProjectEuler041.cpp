#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

Answer: 7652413 (347.747ms)

Tags: Pandigital
*/

/*
I tried first to pre-compute primes up to 987654321.
But 1+2+3+4+5+6+7+8+9 = 45 and 1+2+3+4+5+6+7+8 = 36
which are both divisible by 3.
Thus, I just have to compute prime up 7654321 instead.
*/

void ProjectEuler041(){
    vector<unsigned>& primes = PEUtility::EratostheneSieve(7654321);

    for(auto it = primes.rbegin(); it != primes.rend(); ++it){
        if (PEUtility::IsPandigital(*it)) {
            cout << *it << "\n";
            return;
        }
    }
}
