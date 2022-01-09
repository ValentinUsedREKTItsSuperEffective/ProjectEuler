#include <vector>

#ifndef PEUTILITY_H
#define PEUTILITY_H

using namespace std;

class PEUtility {
    public:
        static vector<unsigned int> Primes;

        PEUtility();
        ~PEUtility();

        static vector<unsigned int>& EratostheneSieve(unsigned int limit);
        static unsigned int SumOfDivisors(unsigned int n, bool properDivisor = false);
    };

#endif // PEUTILITY_H
