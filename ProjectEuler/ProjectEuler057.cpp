#include <iostream>
#include "BigInteger.hpp"
#include <cmath>

using namespace std;

/*
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

                            sqrt (2) = 1 + (1 / (2 + 1 / (2 + 1 / (2 + ...))))

By expanding this for the first four iterations, we get:

   1 + 1 /  2                               =   3 / 2   = 1.5
   1 + 1 / {2 + 1 / 2}                      =   7 / 5   = 1.4
   1 + 1 / {2 + 1 / {2 + 1 / 2}}            =  17 / 12  = 1.41666...
   1 + 1 / {2 + 1 / {2 + 1 / {2 + 1 / 2}}}  =  41 / 29  = 1.41379...

The next three expansions are 99 / 70, 239 / 169, and 577 / 408,
but the eighth expansion, 1393 / 985, is the first example where
the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than the denominator?</p>

Answer: 153 (3.335ms)
*/

/* Thoughts
    Obvious patterns:

   1 + 1 /  2
   1 + 1 /                            {2 + 1 / 2}
   1 + 1 /                   {2 + 1 / {2 + 1 / 2}}
   1 + 1 /          {2 + 1 / {2 + 1 / {2 + 1 / 2}}}
   1 + 1 / {2 + 1 / {2 + 1 / {2 + 1 / {2 + 1 / 2}}}}

    Can be rewrite to:

   1 + 1 /  2
   1 + 1 /                            {2 + 1 / 2}       = 1 + 1 / {2 + {1/2}    = 1 + 1 / {5/2}   = 1 + {2/5}
   1 + 1 /                   {2 + 1 / {2 + 1 / 2}}      = 1 + 1 / {2 + {2/5}}   = 1 + 1 / {12/5}  = 1 + {5/12}
   1 + 1 /          {2 + 1 / {2 + 1 / {2 + 1 / 2}}}     = 1 + 1 / {2 + {5/12}}  = 1 + 1 / {29/12} = 1 + {12/29}
   1 + 1 / {2 + 1 / {2 + 1 / {2 + 1 / {2 + 1 / 2}}}}    = 1 + 1 / {2 + {12/29}} = 1 + 1 / {70/29} = 1 + {29/70}
*/

unsigned ProjectEuler057(){
    BigInteger numerator = 1;
    BigInteger denominator = 2;
    unsigned counter = 0;

    for(unsigned i = 0; i < 1000; i++){
        numerator += denominator * 2;
        numerator.Swap(denominator);

        if((numerator + denominator).length() > denominator.length()){
            //cout << (numerator + denominator) << " / " << denominator << "\n";
            counter++;
        }
    }

    cout << counter << "\n";
    return counter;
}
