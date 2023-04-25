#pragma once

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
    constexpr static int sampleSize = 3;
    int samples[sampleSize];
    long answers[sampleSize];

    ProjectEuler001(): samples({10, 100, 1000}), answers({23, 2318, 233168}) {}

    long Solution(int upperValue){
        // - 1 because upperValue isn't included
        long n = upperValue - 1;

        long three = n  / 3;
        long five = n / 5;
        long fifteen = n / 15;

        return (3 * three * (three + 1) + 5 * five * (five + 1) - 15 * fifteen * (fifteen + 1)) / 2;
    }

    void RunSample() {
        for(int sample : samples){
            cout << Solution(sample) << endl;
        }
    }

    bool TestSample() {
        for(int i = 0; i < sampleSize; i++){
            auto answer = Solution(samples[i]);
            if (answer != answers[i]) {
                cout << "Error in the solution for archive 001. Expected value for the sample " <<  samples[i] << " is " << answers[i];
                cout << "But the computed value is " <<  Solution(samples[i]) << " is " << answer << endl;
                return false;
            }
        }

        cout << "Archive 001 tested successfully." << endl;
        return true;
    }
};
