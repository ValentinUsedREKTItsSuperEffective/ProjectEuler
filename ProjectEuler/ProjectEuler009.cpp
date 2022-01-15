#include <iostream>

using namespace std;

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
                                a^2 + b^2 = c^2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Answer: 31875000
*/

void findABC(int N){
    if(N < 12 || N % 2 == 1){
        cout << "-1" << endl;
        return;
    }

    int b, c;

    for(int a = N / 3; a >= 0; a--){
        b = (a * a - (N - a)*(N - a)) / (2 * (a - N));
        if(a >= b){
            continue;
        }

        c = N - a - b;
        if(b >= c){
            continue;
        }

        if(a * a + b * b == c * c){
            cout << a * b * c << endl;
            return;
        }
    }

    cout << "-1" << endl;

}

void ProjectEuler009(){
    int T = 3;
    long long N[] = {12, 4, 1000};

    for(int i = 0; i < T; i++){
        findABC(N[i]);
    }
}


