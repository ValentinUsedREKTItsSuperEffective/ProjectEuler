#include <iostream>
#include <set>
#include <vector>
#include "PEUtility.hpp"

using namespace std;

/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Answer: 4179871
*/

/* cf
https://en.wikipedia.org/wiki/Abundant_number (1)
https://brilliant.org/wiki/abundant-number/ (2)
*/

void ProjectEuler023(){
    PEUtility::EratostheneSieve(20161); // (1) for 20161

    unsigned int sum = 276; // Sum of the integer lower than 24

    set<unsigned int> n;

    for(int i = 25; i < 47; i++){
        n.emplace(i);
    }

    for(int i = 47; i <= 20161; i+=2){ // (2) for the i += 2
        n.emplace(i);
    }

    vector<unsigned int> abundants = {12};
    for(unsigned int i = 13; i <= 20161 - 12; i++){
        if(PEUtility::SumOfDivisors(i, true) > i){
            abundants.push_back(i);

            for(unsigned int ab : abundants){
                if(ab + i > 20161){
                    break;
                }

                auto it = n.find(ab + i);
                if(it != n.end()){
                    n.erase(it);
                }
            }
        }
    }

    for(unsigned int i : n){
        sum += i;
    }

    cout << sum << endl;
}


