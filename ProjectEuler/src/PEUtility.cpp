#include "PEUtility.hpp"

PEUtility::PEUtility(){}

PEUtility::~PEUtility(){}

vector<unsigned int> PEUtility::EratostheneSieve(unsigned int limit){
    vector<unsigned int> primes;

    primes.push_back(2);

    for(unsigned int i = 3; i <= limit; i += 2){
        primes.push_back(i);
    }

    unsigned int prime = 2;
    for(int i = 1; prime * prime <= limit && i < primes.size(); i++){
        prime = primes[i];

        for(int j = i + 1; j < primes.size();){
            if(primes[j] % prime == 0){
                primes.erase(primes.begin() + j);
            } else {
                j++;
            }
        }
    }

    return primes;
}
