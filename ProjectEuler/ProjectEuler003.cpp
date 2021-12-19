#include <iostream>

using namespace std;

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

Answer: 6857
*/

void ProjectEuler003(){
    int T = 3;
    long long N[] = {5, 17, 600851475143};

    for(int i = 0; i < T; i++){
        long long n = N[i];

        long long prime = 2LL;
        while(n % prime == 0LL){
            n /= prime;
        }

        if(n == 1){
            cout << 2 << endl;
            return;
        }

        prime = 3LL;

        while(prime * prime <= n){
            if(n % prime == 0LL){
                n /= prime;
            } else {
                prime += 2LL;
            }
        }

        cout << n << endl;
    }

    return;
}

