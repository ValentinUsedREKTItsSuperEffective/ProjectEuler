#include <iostream>

using namespace std;

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

Answer: 233168
*/

/*
The sum of the multiple of a number R is the sum of the arithmetic progression of reason R:

    U(n+1) = U(n) + R

with U(0) = 0.

The sum of an arithmetic progression, when the first term is U(0), is :

    (n + 1) / 2 * (U(0) + U(n))

Here U(0) = R and U(n) = U(0) + nR = nR

    nR(n + 1)/2

The solution is then the sum of the progression of reason 3 and 5 minus the sum of the progression of reason 15.
*/

struct ProjectEuler001 {
    int samples[3];

    ProjectEuler001(): samples({10, 100, 1000}) {}

    long Solution(int upperValue){
        long n = upperValue;

        long three = (n - 1)  / 3;
        long five = (n - 1) / 5;
        long fifteen = (n - 1) / 15;

        return 3 * three * (three + 1) / 2 + 5 * five * (five + 1) / 2 - 15 * fifteen * (fifteen + 1) / 2;
    }

    void RunSample(){
        for(int sample : samples){
            cout << Solution(sample) << endl;
        }
    }
};
