#include <iostream>
#include <algorithm>

using namespace std;

/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

Answer: 142857 (7.58ms)

Tags: Permutation
*/

/*
Thoughts:
6x cannot increase the number of digits, meaning that x cannot exceed the patern 1666.....666 (6x < 10 -> x < 5/3).

This mean that the number will have at least compose of the digits '1', '2', '3', '4', '5', '6' to respect the permutation rule.
So x is at least composed of 6-digits.
*/

bool IsPermutation(unsigned y, const string& comparision){
    string yStr = to_string(y);
    return(std::is_permutation(yStr.begin(), yStr.end(), comparision.begin()));
}

void ProjectEuler052(){
    unsigned base = 123456;
    unsigned threshold = 166666;
    unsigned tenMul = 1;
    for(unsigned x = base;;){
        string xStr = to_string(x);

        if(IsPermutation(2*x, xStr) && IsPermutation(3*x, xStr) && IsPermutation(4*x, xStr) && IsPermutation(5*x, xStr) && IsPermutation(6*x, xStr)){
            cout << x << "\n";
            return;
        }

        if (x < threshold){
            x++;
        } else {
            tenMul *= 10;
            x = base * tenMul;
            threshold = threshold * 10 + 6;
        }
    }
}
