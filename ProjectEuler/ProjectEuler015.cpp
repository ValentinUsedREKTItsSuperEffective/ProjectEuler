#include <iostream>
#include <climits>

using namespace std;

/*
Starting in the top left corner of a 2*2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20*20 grid?

Answer: 137846528820
*/

// See : https://en.wikipedia.org/wiki/Lattice_path#Counting%20lattice%20paths
// See : https://en.wikipedia.org/wiki/Binomial_coefficient

unsigned long long BinomialCoeficient(unsigned long long n, unsigned long long k){
    unsigned long long c = 1, i;

    /*
        Reduce the number of test case by choosing the minimum k as we will iterate on k
        i.e. with (10 8)
        (10 8) = (10 2) = 10! / 2!*8! = 10 * 9 / 2!

        This is possible because there is a symetry
        cf Triangle Pascal
    */
    if (k > n-k){
        k = n-k;
    }

    for (i = 1; i <= k; i++, n--) {
        if (c/i >= ULONG_LONG_MAX/n) // return 0 on potential overflow
            return 0; // This won't resolve the problem for bigger coef

        c = c / i * n + c % i * n / i;  // split c * n / i into (c / i * i + c % i) * n / i
    }

  return c;
}

void ProjectEuler015(){
    int T = 3;
    int N[] = {2, 2, 3, 3, 20, 20};

    for(int i = 0; i < 2*T; i+=2){
        int w = N[i];
        int h = N[i+1];

        cout << BinomialCoeficient(w + h, h) << endl;
    }

    return;
}

