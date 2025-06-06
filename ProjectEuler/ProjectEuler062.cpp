#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

/*
The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3).
In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

Answer: 127035954683 (12.877ms)
*/

/*
Hypothesis:
We can start from the cube of 345.
*/

struct PermutationCounter{
    unsigned char counter;
    unsigned long long smallestCube;

    PermutationCounter& operator++(int){
        counter++;
        return *this;
    }

    bool operator>=(unsigned char n){
        return counter >= n;
    }
};

void ProjectEuler062(){
    map<string, PermutationCounter> permutations = {};
    for(unsigned long long i = 345; true; i++){
        unsigned long long cube = i*i*i;
        string n = std::to_string(cube);
        std::sort(n.begin(), n.end());
        if(permutations.count(n) == 0){
            permutations[n] = {1, cube};
        } else {
            permutations[n]++;

            if(permutations[n] >= 5){
                cout << permutations[n].smallestCube << "\n";
                return;
            }
        }
    }
}

