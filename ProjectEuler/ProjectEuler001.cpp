#include <iostream>

using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Answer: 233168
*/

void ProjectEuler001(){
    int T = 3;
    int N[] = {10, 100, 1000};

    for(int i = 0; i < T; i++){
        long n = N[i];

        long three = (n - 1)  / 3;
        long five = (n - 1) / 5;
        long fifteen = (n - 1) / 15;

        long sum = 3 * three * (three + 1) / 2 + 5 * five * (five + 1) / 2 - 15 * fifteen * (fifteen + 1) / 2;

        cout << sum << endl;
    }

    return;
}
