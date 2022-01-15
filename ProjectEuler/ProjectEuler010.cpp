#include <iostream>
#include <vector>
#include "PEUtility.hpp"

using namespace std;

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Answer: 142913828922
*/

void ProjectEuler010(){
    int T = 3;
    unsigned int N[] = {5, 1000, 2000000};

    auto primes = PEUtility::EratostheneSieve(1999999);
    unsigned long long sum = 0LL;

    for(int i = 0; i < T; i++){
        long long n = N[i];

        sum = 0LL;

        for(unsigned int j = 0; primes[j] < n && j < primes.size(); j++){
            sum += primes[j];
            //cout << j << " : / " <<  primes.size() << " + " << primes[j] << " = " << sum << endl;
        }

        cout << sum << endl;
    }
}



