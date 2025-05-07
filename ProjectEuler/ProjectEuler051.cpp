#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values:

                            13, 23, 43, 53, 73, and 83,

are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes
among the ten generated numbers, yielding the family:

                56003, 56113, 56333, 56443, 56663, 56773, and 56993.

Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit,
is part of an eight prime value family.

Answer:

Tags:
*/

/*
Thoughts:
8 members family.
The size of the digit is not known.
The number of replaced digits is unknown.

The most right digit cannot be replaced to match an eight prime value family because prime number cannot end with 2, 4, 5, 6, 8, 0.

A family member is composed of a constant C, plus a [0, 1, ..., 9] * FalseBinary, that is to say a number composed of 0 and 1 only.
*/


void ProjectEuler051(){
    auto primes = PEUtility::EratostheneSieve(1000000);

}
