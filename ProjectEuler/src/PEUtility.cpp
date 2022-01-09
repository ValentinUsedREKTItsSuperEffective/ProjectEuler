#include "PEUtility.hpp"
#include <map>
#include <algorithm>

vector<unsigned int> PEUtility::Primes = {2};

PEUtility::PEUtility(){}

PEUtility::~PEUtility(){}

vector<unsigned int>& PEUtility::EratostheneSieve(unsigned int limit){
    if(limit > *(Primes.end() - 1)){
        // Recompute all the primes if limit is superior than the biggest saved prime
        Primes = {2};

        for(unsigned int i = 3; i <= limit; i += 2){
            Primes.push_back(i);
        }

        unsigned int prime = 2;
        for(unsigned int i = 1; prime * prime <= limit && i < Primes.size(); i++){
            prime = Primes[i];

            for(unsigned int j = i + 1; j < Primes.size();){
                if(Primes[j] % prime == 0){
                    Primes.erase(Primes.begin() + j);
                } else {
                    j++;
                }
            }
        }
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
