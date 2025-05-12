#include "PEUtility.hpp"
#include <map>
#include <algorithm>
#include <cmath>
#include <set>
#include <stdexcept>

vector<unsigned int> PEUtility::Primes;

PEUtility::PEUtility(){}

PEUtility::~PEUtility(){}

const float PEUtility::epsilon = 0.0000001f;

bool PEUtility::isNatural(float n){
    float r = std::round(n);
    return (n <= r + epsilon && n >= r - epsilon);
}

vector<unsigned char> PEUtility::BreakNumber(unsigned int n){
    vector<unsigned char> ret = vector<unsigned char>();

    while(n > 0){
        ret.push_back(n % 10);
        n /= 10;
    }

    return ret;
}

vector<unsigned char> PEUtility::BreakNumber(unsigned long long n){
    vector<unsigned char> ret = vector<unsigned char>();

    while(n > 0ll){
        unsigned short v = n % 10ll;
        ret.push_back(v);
        n /= 10ll;
    }

    return ret;
}

// See: https://fr.wikipedia.org/wiki/Crible_d%27%C3%89ratosth%C3%A8ne
vector<unsigned int>& PEUtility::EratostheneSieve(unsigned int limit){
    vector<bool> isPrime = {false, false, true}; // 0 & 1 aren't primes, 2 is prime
    Primes.push_back(2);

    for(unsigned int i = 3; i <= limit; i++){
        // set even(fr: pair) numbers as false
        isPrime.push_back(i%2 == 1);
    }

    unsigned int prime = 3;
    while(prime * prime <= limit){
        // i starting at prime * prime is the same logic than why we stop the sieve at prime^2 <= limit
        for(unsigned int i = prime * prime; i <= limit; i += prime){
            isPrime[i] = false;
        }

        // find the next prime number
        do{
            prime += 2;
        }while(!isPrime[prime]);
    }

    // 2 already in Primes, start from 3 and ignore even numbers
    for(unsigned int i = 3; i <= limit; i+=2){
        if(isPrime[i])
            Primes.push_back(i);
    }

    return Primes;
}

bool PEUtility::IsPrime(unsigned N){
    if(Primes.empty()) { // empty() = isEmpty()
        throw std::length_error("Primes has not been initialized");
    }

    for(unsigned prime: Primes){
        if (prime > N){
            return false;
        }

        if (prime == N){
            return true;
        }
    }

    return false;
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

int PEUtility::GCD(int a, int b) {
    if (b == 0) {
        return a;
    }

    if (b > a) {
        // Perform the modulo of the bigger integer by the lower integer
        return GCD(b, a);
    }

    return GCD(b, a % b);
}

unsigned int PEUtility::UIntLength(unsigned int n) {
    if (n == 0) {
        return 1;
    }

    return 1 + log10(n);
}

bool PEUtility::IsPandigital(unsigned int n){
    if(n == 0) {
        return false;
    }

    vector<unsigned char> brokenN = BreakNumber(n);

    // For a pandigital number, there should be no loss of cypher due to set uniqueness property
    set<unsigned char> setN = set<unsigned char>();
    for(auto c: brokenN){
        if(c == 0) { // Pandigital number are composed of digit between 1 and n
            return false;
        }

        setN.insert(c);
    }

    // set is sorted. So the last digit in setN should be the size of setN for a pandigital number
    return *setN.rbegin() == setN.size() && UIntLength(n) == setN.size();
}

// See : https://en.wikipedia.org/wiki/Binomial_coefficient
unsigned long long PEUtility::BinomialCoeficient(unsigned long long n, unsigned long long k){
    if(k > n){
        throw std::invalid_argument("k cannot be greater than n in binomial coefficient");
    }

    unsigned long long result = 1;

    /*
    Reduce the number of test case by choosing the minimum k as we will iterate on k
    i.e. with (10 8)
    (10 8) = (10 2) = 10! / 2!*8! = (10 * 9) / (2 * 1)

    This is possible because we can write n! / k!(n-k)! like n! / (n-k)!k!
    cf Triangle Pascal
    */

    unsigned diff = n - k;
    if (k > diff){
        k = diff;
    }

    for (unsigned long long i = 1; i <= k; i++, n--) {
        result = result / i * n + result % i * n / i;  // split result * n / i into (result / i * i + result % i) * n / i

        if (result >= ULONG_LONG_MAX) {
            throw std::overflow_error("Exceed ULONG_LONG_MAX limit");
        }
    }

  return result;
}
