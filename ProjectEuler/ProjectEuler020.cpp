#include <iostream>
#include "BigInteger.hpp"

using namespace std;

/*
n! means n * (n - 1) * ... * 3 * 2 * 1

For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

Answer: 648
*/

void ProjectEuler020(){
    int T = 2;
    int N[] = {10, 100};

    BigInteger number;

    for(int i = 0; i < T; i++){
        number = 1;
        unsigned int sum = 0;

        for(int j = 2; j <= N[i]; j++){
            number *= j;
        }

        for(int i = 0; i < number.size; i++){
            sum += number.value[i];
        }

        cout << sum << endl;
    }
}

