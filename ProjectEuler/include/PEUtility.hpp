#include <vector>
#include <math.h>
#include <algorithm>
#include <type_traits>

#ifndef PEUTILITY_H
#define PEUTILITY_H

using namespace std;

class PEUtility {
    public:
        static vector<unsigned int> Primes;

        PEUtility();
        ~PEUtility();

        static bool isNatural(float n);

        template<class T>
        static vector<unsigned char> BreakIntegral(T n, bool performReverse = false){
            static_assert(std::is_integral<T>::value, "PEUtility::BreakIntegral: Integral type required!");

            vector<unsigned char> broken;

            if(n == 0)
                return {0};

            while(n > 0){
                broken.push_back(n % 10);
                n /= 10;
            }

            if(!performReverse)
                std::reverse(broken.begin(), broken.end());

            return broken;
        }

        static vector<unsigned int>& EratostheneSieve(unsigned int limit);
        static bool IsPrime(unsigned N);

        static unsigned int SumOfDivisors(unsigned int n, bool properDivisor = false);

        static int GCD(int a, int b);

        static unsigned int UIntLength(unsigned int value);
        static bool IsPandigital(unsigned int value);

        static unsigned long long BinomialCoeficient(unsigned long long n, unsigned long long k);

        static bool IsPalindrome(unsigned long long N);

    private:
        static const float epsilon;
    };

#endif // PEUTILITY_H
