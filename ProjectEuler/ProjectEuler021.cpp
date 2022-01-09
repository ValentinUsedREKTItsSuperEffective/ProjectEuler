#include <iostream>
#include <set>
#include "PEUtility.hpp"

using namespace std;

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

Answer: 31626
*/

// Naive
int divisorSum(int n){
    int sum = 1; // 1 is always a proper divisor
    int tmp = n;
    for(int i = 2; i < tmp; i++){
        if(n % i == 0){
            tmp = n / i;
            sum += i;
            if(tmp != i){
                sum += tmp;
            }
        }
    }

    return sum;
}

void ProjectEuler021(){
    int T = 1;
    int N[] = {10000, 100};

    PEUtility::EratostheneSieve(10000);

    set<int> amicables;

    for(int i = 0; i < T; i++){
        for(int j = 6; j < N[i]; j++){
            int a = PEUtility::SumOfDivisors(j, true);
            if(a != j && PEUtility::SumOfDivisors(a, true) == j){
                if(a < N[i])
                    amicables.emplace(a);
                amicables.emplace(j);
            }
        }

        int sum = 0;
        for(int i : amicables){
            sum += i;
        }
        cout << sum << endl;
    }
}

