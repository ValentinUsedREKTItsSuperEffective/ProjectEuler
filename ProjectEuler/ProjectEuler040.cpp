#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
An irrational decimal fraction is created by concatenating the positive integers:

    0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If d_n represents the nth digit of the fractional part, find the value of the following expression.

    d_1 x d_10 x d_100 x d_1000 x d_10000 x d_100000 x d_1000000

Answer: 210 (0.653ms)

Tags: Champernowne's Constant
*/

void ProjectEuler040(){
    std::vector<unsigned long long> indexes = {1,10,100,1000,10000,100000,1000000};
    unsigned product = 1;

    for(unsigned long long index: indexes){
        unsigned long long x = 0LL;
        unsigned long long indexMin = 1LL;
        unsigned long long indexMax = 9LL;

        while(index > indexMax){
            x += 1LL;
            indexMin = indexMax + 1LL;
            indexMax += (x+1LL)*9LL*pow(10LL,x);
        }

        unsigned long long digitSize = x + 1LL;

        index -= indexMin;
        unsigned long long seekedNumber = pow(10LL, digitSize-1) + index/digitSize;

        unsigned modulo = index%digitSize;

        // -1 otherwise we divide the number one time too far
        while (digitSize - modulo - 1 > 0LL){
            seekedNumber /= 10LL;
            modulo++;
        }

        product *= seekedNumber%10LL;
    }

    cout << product << "\n";
}
