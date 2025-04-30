#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
The prime 41, can be written as the sum of six consecutive primes:

                41 = 2 + 3 + 5 + 7 + 11 + 13.

This is the longest sum of consecutive primes that adds to a prime below one-hundred.
The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

Answer: 997651 (137.89ms)

Tags:
*/

/*
Thoughts:
The sum S has at least 21 terms.
S cannot be above the highest prime below 1000000.
There is most likely only one possible answer to this problem.
*/

void ProjectEuler050(){
    auto primes = PEUtility::EratostheneSieve(1000000);

    unsigned highestPrime = *primes.rbegin();
    unsigned sum = 0;
    unsigned j = 0;
    unsigned counter = 0;
    unsigned highestCounter = 21;
    unsigned answer = 953;

    for(unsigned i = 0; i < primes.size(); i++){
        sum = 0;
        j = i;
        counter = 0;

        do {
            sum += primes[j];
            counter++;
            j++;

            if (counter > highestCounter){
                if (sum < highestPrime && PEUtility::IsPrime(sum)){
                    highestCounter = counter;
                    answer = sum;
                }
            }
        } while(sum < highestPrime);

        // No need to continue when the sum cannot contains more than highestCounter consecutive prime
        if (counter < highestCounter){
            break;
        }
    }

    cout << answer << "\n";
}
