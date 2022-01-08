#include <vector>

#ifndef PEUTILITY_H
#define PEUTILITY_H

using namespace std;

class PEUtility
{
    public:
        PEUtility();
        ~PEUtility();

        static vector<unsigned int> EratostheneSieve(unsigned int limit);
};

#endif // PEUTILITY_H
