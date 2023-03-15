#include <iostream>
#include <map>

using namespace std;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers "n" that can be written as the sum of fifth powers of their digits.


Answer: 443839
*/

/*
The power of five of digit is :
0 -> 0
1 -> 1
2 -> 32
3 -> 243
4 -> 1024
5 -> 3125
6 -> 7776
7 -> 16807
8 -> 32768
9 -> 59049

First of all, we need to find a sum so "n" has at least 2 digits.

Seems to be difficult/longer to find a solution on paper than brute force it.

The following gather all the reflexion I had before brute force.
"n" which has the same digits will give the same sum. I.e. 102 and 21 would give 33.

If "n" has a 2 in it, then "n" > 32. If "n" has a 3 in it, then "n" > 243. Etc.

Can we find a minimum value ? Doesn't look obivious at all.
A "n" cannot be composed only with 1 and 0 because 10 is already bigger than 1^5. (1)

A "n" compose with 0, 1, 2 have to be bigger than 32 so at least 102

Between 2 and 2, we have: 101, 102, 120, 121, 210ÅC211, 212, 220, 221, 222, 1001, 1002, 1010, ...
Numbers like 101, 102, 121 are candidates for testing even if

The maximum n possible seems to b 239999 as its sum is 236471.

While computing the sum for n, if the sum getting bigger than n, then no need to continue to compute
*/

void ProjectEuler030(){
    // Precompute powers
    map<unsigned short, unsigned int> pows;

    for(unsigned int i = 0; i < 10; i++){
        pows[i] = i*i*i*i*i;
    }

    unsigned int n, sum, answer = 0;
    for (unsigned int a = 0; a <= 9; a++) {
        for (unsigned int b = 0; b <= 9; b++) {
            for (unsigned int c = 0; c <= 9; c++) {
                for (unsigned int d = 0; d <= 9; d++) {
                    for (unsigned int e = 0; e <= 9; e++) {
                        for (unsigned int f = 0; f <= 9; f++) {
                            n = a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f;
                            sum = pows[a] + pows[b] + pows[c] + pows[d] + pows[e] + pows[f];

                            // 1 doesn't count
                            if (n == sum && sum > 1) {
                                answer += sum;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << answer << endl;
}

