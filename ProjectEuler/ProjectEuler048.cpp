#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.

Answer: 9110846700 (4.847ms)

Tags:
*/

void ProjectEuler048(){
    unsigned long long sum = 0LL;
    unsigned long long mod = 10000000000LL;
    for(unsigned long long i = 1; i <= 1000; i++){
        unsigned long long exp = 1;
        for(unsigned long long e = 1; e <= i; e++){
            exp *= i;
            exp %= mod;
        }

        sum += exp;
        sum %= mod;
    }

    cout << sum << "\n";
}
