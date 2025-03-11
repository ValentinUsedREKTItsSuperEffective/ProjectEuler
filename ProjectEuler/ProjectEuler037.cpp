#include <iostream>
#include <PEUtility.hpp>
#include <set>

using namespace std;

/*
The number 3797 has an interesting property.
Being prime itself, it is possible to continuously remove digits from left to right
and remain prime at each stage: 3797, 797, 97 and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE:
2, 3, 5, and 7 are not considered to be truncatable primes.

Answer: 748317

Tags: Prime, EratostheneSieve, iterator
*/

/*
False idea: After using Erathostene, we can also remove numbers ending with 1 and 9 has there not prime.
If we do so, it will remove the number 379 which is right-to-left truncatable from 3797.
*/

void ProjectEuler037(){
    int sum = 0;
    int counter = 0;

    // Let's suppose, these eleven numbers are below 1.000.000.
    std::vector<unsigned int>& primes = PEUtility::EratostheneSieve(1000000);
    std::set<unsigned int> primesSet = std::set<unsigned int>();

    for(auto it = primes.begin(); it != primes.end(); it++) {
        primesSet.insert(*it);

        if (*it < 10) continue;

        unsigned int right = *it/10;
        unsigned int left = *it%10;
        unsigned int mul = 10;

        for(; right > 0;) {
            if (primesSet.count(right) == 1 && primesSet.count(left) == 1){
                left += (right%10) * mul;
                right /= 10;
                mul *= 10;

                if (right <= 0) {
                    sum += *it;
                    counter++;

                    // Has mentioned there is only 11 of such truncatable numbers
                    if (counter == 11) {
                        cout << sum << "\n";
                        return;
                    }
                }
            } else {
                break;
            }
        }
    }


}


