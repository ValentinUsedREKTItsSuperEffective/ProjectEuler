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

        static vector<unsigned short> breakNumber(unsigned int);

        static vector<unsigned int>& EratostheneSieve(unsigned int limit);
        static unsigned int SumOfDivisors(unsigned int n, bool properDivisor = false);

    private:
        static const float epsilon;
    };

#endif // PEUTILITY_H
