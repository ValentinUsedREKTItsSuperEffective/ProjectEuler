#include <iostream>
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

Answer:
*/

/*
There are several point to know before coding.

Because n start at 0,
    0^2 +a*0 + b = b
so b needs to be a prime number (1).
Thus, can restrict the range of testing to prime numbers between [-1000, 1000]

Prime number are natural number, which means they are superior than 0.
Our formula is a quadratic it is possible to reduce further the number results.

First by looking at the Discriminant,
        D = b^2 - 4ac

When D < 0, every result of function are above 0 (2).

Otherwise, as the multiplicator of n^2 is positive,
all result exterior to the root will be positive.
*/

void ProjectEuler027(){
    PEUtility::EratostheneSieve(1000);
}


