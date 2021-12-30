#include <iostream>
#include "BigInteger.hpp"

using namespace std;

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer: 1366
*/

void ProjectEuler016(){
    int T = 5;
    int N[] = {3, 4, 7, 15, 1000};

    BigInteger number;

    for(int i = 0; i < T; i++){
        number = 1;
        unsigned int sum = 0;

        for(int j = 1; j <= N[i]; j++){
            number *= 2;
        }

        for(int i = 0; i < number.size; i++){
            sum += number.value[i];
        }

        cout << sum << endl;
    }

    return;
}
