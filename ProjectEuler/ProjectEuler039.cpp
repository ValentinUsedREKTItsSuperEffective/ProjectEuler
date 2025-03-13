#include <iostream>
#include <cstring>
#include <cmath>


using namespace std;

/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
{20,48,52},{24,45,51},{30,40,50}

For which value of p <= 1000, is the number of solutions maximised?

Answer: 840 (6.503ms)

Tags:
*/

/* Thoughts:
This is brute force solution.

See https://mathworld.wolfram.com/PythagoreanTriple.html for alternative (most likely faster) solution..
... but I don't really understand the how T_T
*/

#define PERIMETER 1000

void ProjectEuler039(){
    unsigned counters[PERIMETER];
    memset(counters, 0, sizeof(counters));
    for(unsigned a = 1; a <= PERIMETER; a++){
        for(unsigned b = a; b <= PERIMETER; b++){
            float floatC = std::sqrt(a*a + b*b);
            unsigned c = floatC;
            // Without this condition, I would count many non-integer solution of c sqrt(a*a + b*b)
            // Like {2,59,59.0338885725817658507} which is correct but c is not an integer.
            // However a, b, c MUST be integer. The word "integral" is confusing here.
            if (floatC - (float)c > 0.f){
                continue;
            }

            unsigned p = a + b + c;
            if (p > PERIMETER){
                break;
            }

            counters[p - 1]++;
        }
    }

    unsigned maxSolution = 0;
    unsigned index = 0;
    for(unsigned i = 0; i < PERIMETER; i++){
        if(counters[i] > maxSolution){
            maxSolution = counters[i];
            index = i + 1;
        }
    }

    cout << index << "\n";
}
