#include "PEUtility.hpp"
#include <map>
#include <algorithm>

vector<unsigned int> PEUtility::Primes;

PEUtility::PEUtility(){}

PEUtility::~PEUtility(){}

const float PEUtility::epsilon = 0.0000001f;

bool PEUtility::isNatural(float n){
    float r = std::round(n);
    return (n <= r + epsilon && n >= r - epsilon);
}

vector<unsigned int>& PEUtility::EratostheneSieve(unsigned int limit){
    vector<bool> isPrime = {false, false}; // 0 & 1 aren't primes
    for(unsigned int i = 2; i <= limit; i++){
        isPrime.push_back(true);
    }

    unsigned int prime = 2;
    while(prime * prime <= limit){
        for(unsigned int i = prime * prime; i <= limit; i += prime){ // i start a prime * prime is the same logic than why we stop the sieve at prime^2 <= limit
            isPrime[i] = false;
        }

        while(!isPrime[++prime]){} // find the next prime number
    }

    for(unsigned int i = 0; i <= limit; i++){
        if(isPrime[i])
            Primes.push_back(i);
    }

    return Primes;
}

unsigned int PEUtility::SumOfDivisors(unsigned int n, bool properDivisor){
    if(n == 1){
        return properDivisor ? 0 : 1;
    }

    vector<unsigned int> primes = EratostheneSieve(n);

    auto it = find(primes.begin(), primes.end(), n);
    if(it != primes.end()){
        return properDivisor ? 1 : n + 1;
    }


    map<unsigned int, unsigned int> primeExponents;

    unsigned int prime = primes[0];
    unsigned int tmp = n;
    unsigned int i = 0;
    while(prime * prime <= n){
        if(tmp % prime == 0){
            tmp /= prime;

            if(primeExponents[prime] == 0){
                primeExponents[prime] = prime;
            }
            primeExponents[prime] *= prime;
        } else {
            prime = primes[++i];
        }
    }

    if(tmp > 1){
        primeExponents[tmp] = tmp * tmp;
    }

    unsigned int sum = 1;
    for(auto p : primeExponents){
        sum *= (p.second - 1) / (p.first - 1);
    }

    return properDivisor ? sum - n : sum;
}
