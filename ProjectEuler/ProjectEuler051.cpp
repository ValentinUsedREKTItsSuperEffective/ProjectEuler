#include <iostream>
#include "PEUtility.hpp"

#include <set>

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

Answer: 121313 (4515.46ms)

Tags: Prime, XOR swap
*/

/*
Thoughts:
8 members family.
The size of the digit is not known.
The number of replaced digits is unknown.

The most right digit cannot be replaced to match an eight prime value family because prime number cannot end with 2, 4, 5, 6, 8, 0.

A family member is composed of a constant C, plus a multiplicator of [0, 1, ..., 9] * FalseBinary, FalseBinary a number composed of 0 and 1 only:

                                                            56003 + 0 * 00110 = 56003
                                                            56003 + 1 * 00110 = 56113
                                                            56003 + 3 * 00110 = 56333
                                                            56003 + 4 * 00110 = 56443
                                                            56003 + 6 * 00110 = 56663
                                                            56003 + 7 * 00110 = 56773
                                                            56003 + 9 * 00110 = 56993.
*/

bool CanBePartOfEightMemberFamily(unsigned A, unsigned B, unsigned& constant, unsigned& expectedMultiplicatorB, unsigned& falseBinary){
    // See Thoughts: The most right digit cannot be replaced.
    if (A % 10 != B % 10){
        return false;
    }

    if (A == B){
        return false;
    }

    if (B > A){
        // XOR swap
        B ^= A;
        A ^= B;
        B ^= A;
    }

    constant = B;
    falseBinary = 0;
    unsigned expectedMultiplicatorA = 0;
    expectedMultiplicatorB = 666;
    unsigned tenMul = 10;

    do{
        A /= 10;
        B /= 10;

        unsigned modA = A % 10;
        unsigned modB = B % 10;
        if (modA != modB){
            if(expectedMultiplicatorB == 666){
                expectedMultiplicatorB = modB;
                expectedMultiplicatorA = modA;

                // expectedMultiplicatorB > 2 would mean that the family member have at most multiplicators of [3, 4, 5, 6, 7, 8, 9] which is 7 members
                if(expectedMultiplicatorB > 2){
                    return false;
                }
            } else {
                // check here that the replaced digits stay the same amoung there respective numbers A and B
                if (expectedMultiplicatorA != modA || expectedMultiplicatorB != modB){
                    return false;
                }
            }

            falseBinary += tenMul;
        }

        tenMul *= 10;
    } while (A > 0);

    constant -= (expectedMultiplicatorB * falseBinary);

    return true;
}

void ProjectEuler051(){
    auto primes = PEUtility::EratostheneSieve(1000000);

    // Sort primes depending on their rightmost digit
    set<unsigned> primeSet = set<unsigned>();
    unsigned roof = 100;

    for(auto it = primes.begin(); it != primes.end();){
        unsigned prime = *it;
        if (prime < 10){
            it++;
            continue;
        }

        if (prime < roof){
            primeSet.insert(prime);

            it++;

            // condition to prevent an early exit because it reach the end()
            if(it != primes.end()){
                continue;
            }
        }


        for(auto itB = primeSet.begin(); itB != primeSet.end(); itB++){
            for(auto itA = std::next(itB,1); itA != primeSet.end(); itA++){
                unsigned constant = 0;
                unsigned mul = 0;
                unsigned falseBinary = 0;
                char counter = 10;
                if(CanBePartOfEightMemberFamily(*itA, *itB, constant, mul, falseBinary)){
                    counter -= mul;

                    unsigned mulPlus = 0;
                    while(counter >= 8){
                        if(primeSet.count(constant+(mul+mulPlus)*falseBinary) == 0){
                            counter--;
                        } else {
                            if (mul + mulPlus == 9){
                                cout << *itB << "\n";
                                return;
                            }
                        }

                        mulPlus++;
                    }
                }
            }
        }


        primeSet.clear();
        roof *= 10;
    }
}
