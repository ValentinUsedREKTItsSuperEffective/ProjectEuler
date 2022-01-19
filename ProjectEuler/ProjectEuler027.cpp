#include <iostream>
#include <math.h>
#include <algorithm>
#include "PEUtility.hpp"

using namespace std;

/*
Euler discovered the remarkable quadratic formula:

                    n^2 + n +41

It turns out that the formula will produce 40 primes for the consecutive integer values n in [0, 39].
However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n in [0, 79].
The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:

            n^2 + an + b where |a| < 1000 and |b| <= 1000
            |x| is the absolute value of x

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.

Answer: -59231
*/

/*
There are several point to know before coding.

Because n start at 0,
    0^2 +a*0 + b = b
so b needs to be a prime number (1).
Thus, can restrict the range of testing to prime numbers between [-1000, 1000]

Prime number are natural number, which means they are superior than 0.
As our formula is a quadratic it is possible to reduce further the number of tests.

First by looking at the Discriminant,
        D = b^2 - 4ac

When D < 0, every result of function are above 0 whatever n (2).

Otherwise, as the multiplicator of n^2 is positive, all result exterior to the root will be positive.

Moreover, the roots give us a capital information because n must increase from 0.
If 0 is between the roots, the result of the formula can't be positive so can't be a prime. (3)

And to finish, we know that for a = 1 and b = 41, we can compute 40 primes.
This give us a lower bound because if the left root is smaller than 40, consecutive values of n will give us a negative result before attaining n = 40. (4)
*/

int quadratic(int a, int b, int n){
    return n*n + a*n + b;
}

void ProjectEuler027(){
    auto primes = PEUtility::EratostheneSieve(100000);

    int coefProduct = 41; // for a = 1 & b = 41 ...
    unsigned int maxConsecutiveN = 39; // ... maximum n is 39

    for(int a = -999; a < 1000; a++){
        for(int i = 0; primes[i] < 1000; i++){ // (1)
            int b = primes[i];
            float discriminant = a * a - 4 * b;

            int lRoot = 0, rRoot = 0;

            if(discriminant >= 0){
                if(discriminant > 0){
                    lRoot = floor((-a - sqrt(discriminant)) * .5f);
                    rRoot = ceil((-a + sqrt(discriminant)) * .5f);
                } else if(discriminant == 0){
                    lRoot = floor(-a * .5f);
                    rRoot = ceil(-a * .5f);
                }

                if(lRoot >= 0 && lRoot != rRoot && lRoot < 40){ // (4)
                    //cout << "lRoot < 40" << endl;
                    continue;
                }

                if(lRoot < 0 && rRoot > 0){ // (3)
                    //cout << "n = 0 between roots" << endl;
                    continue;
                }
            }

            unsigned int n = 1;
            int r = quadratic(a, b, n);

            while(find(primes.begin(), primes.end(), r) != primes.end()){
                //cout << "For n = " << n << "  :  " << r << endl;
                r = quadratic(a, b, ++n);
            }

            if(maxConsecutiveN < n){
                maxConsecutiveN = n;
                coefProduct = a * b;
            }
        }
    }

    cout << coefProduct << endl;
}


