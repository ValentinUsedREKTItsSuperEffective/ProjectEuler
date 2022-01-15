
#include <iostream>
#include <vector>

using namespace std;

/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

                            012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

Answer: 2783915460
*/

/*
                                        [0, 1, 2, 3] -> 4! possibilities

                0[1, 2, 3]                          1[0, 2, 3]    2[0, 1, 3]    3[0, 1, 2] -> 3! possibilities each

   01[2, 3]      02[1, 3]       03[1, 2]                ...          ...            ...      -> 2! possibilities each
    /   \          /   \           /   \
0123    0132    0213    0231    0312    0321
*/

unsigned int factorial(unsigned int n){
    if(n == 1){
        return 1;
    }

    return n * factorial(n-1);
}

void ProjectEuler024(){
    vector<short> digits;
    for(short i = 0; i < 10; i++){
        digits.push_back(i);
    }

    unsigned int search = 999999; // desired index - 1
    unsigned int f = factorial(digits.size());
    if(search >= f){
        search = f-1;
    }

    unsigned int i = 0;
    while(digits.size() > 1){
        unsigned int f = factorial(digits.size() - 1);
        i = search / f;
        search -= f * i;
        cout << digits[i];
        digits.erase(digits.begin() + i);
    }

    cout << digits[0] << endl;
}
