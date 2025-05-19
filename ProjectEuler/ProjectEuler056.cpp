#include <iostream>
#include "BigInteger.hpp"

using namespace std;

/*
A googol (10^100) is a massive number: one followed by one-hundred zeros;
100^100 is almost unimaginably large: one followed by two-hundred zeros.
Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

Answer: 972 (4.249ms)
*/

void ProjectEuler056(){
    BigInteger bigA;
    unsigned maxSum = 0;
    for(unsigned a = 2; a < 100; a++){
        bigA = a;
        for(unsigned b = 2; b < 100; b++){
            bigA*=a;

            unsigned sum = 0;
            for(unsigned i = 0; i < bigA.length(); i++){
                sum += bigA.value[i];

                if(sum > maxSum){
                    maxSum = sum;
                }
            }
        }
    }

    cout << maxSum << "\n";
}
