#include <vector>
#include <math.h>

#ifndef PEUTILITY_H
#define PEUTILITY_H

using namespace std;

class PEUtility {
    public:
        static vector<unsigned int> Primes;

        PEUtility();
        ~PEUtility();

        static bool isNatural(float n);

        static vector<unsigned char> BreakNumber(unsigned int);
        static vector<unsigned char> BreakNumber(unsigned long long);

        static vector<unsigned int>& EratostheneSieve(unsigned int limit);
        static bool IsPrime(unsigned N);

        static unsigned int SumOfDivisors(unsigned int n, bool properDivisor = false);

        static int GCD(int a, int b);

        static unsigned int UIntLength(unsigned int value);
        static bool IsPandigital(unsigned int value);

    private:
        static const float epsilon;
    };

#endif // PEUTILITY_H
