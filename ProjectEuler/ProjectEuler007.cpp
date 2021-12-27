#include <iostream>
#include <vector>

using namespace std;

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

Answer: 104743
*/

void ProjectEuler007(){
    int T = 3;
    long long N[] = {3, 6, 10001};

    vector<long> primes({2,3,5,7,11,13,17,19,23,29});

    for(int i = 0; i < T; i++){
        long long n = N[i];

        long prime = primes.back();
        while(primes.size() < n){
            prime += 2;

            for(long p : primes){
                if(prime % p == 0){
                    break;
                }

                if(p == primes.back()){
                    primes.push_back(prime);
                }
            }
        }

        cout << primes[n-1] << endl;
    }

    return;
}

