#include <iostream>

using namespace std;

/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.

Answer: 100
*/

/*
Numerator and denominator can't be modulo 10.
Denominator is always bigger than the numerator.

Should obviously contain at least the fraction 49/98.
*/

void ProjectEuler033(){
    int nProduct = 1, dProduct = 1;
    for(float a = 1.f; a <= 9.f; a++) {
        for (float n = 1.f; n <= 9.f; n++) {
            for (float d = n + 1.f; d <= 9.f; d++) {
                float nd = n/d;
                float an = 10.f*a+n;
                float na = 10.f*n+a;
                float ad = 10.f*a+d;
                float da = 10.f*d+a;
                if (nd == an/ad) {
                    cout << n << "/" << d << " = " << nd << endl;
                    cout << an << "/" << ad << " = " << an/ad << endl << endl;
                    nProduct *= (int)n;
                    dProduct *= (int)d;
                } else if (nd == an/da) {
                    cout << n << "/" << d << " = " << nd << endl;
                    cout << an << "/" << da << " = " << an/da << endl << endl;
                    nProduct *= (int)n;
                    dProduct *= (int)d;
                } else if (nd == na/ad) {
                    cout << n << "/" << d << " = " << nd << endl;
                    cout << na << "/" << ad << " = " << na/ad << endl << endl;
                    nProduct *= (int)n;
                    dProduct *= (int)d;
                } else if (nd == na/da) {
                    cout << n << "/" << d << " = " << nd << endl;
                    cout << na << "/" << da << " = " << na/da << endl << endl;
                    nProduct *= (int)n;
                    dProduct *= (int)d;
                }
            }
        }
    }
    cout << nProduct << "/" << dProduct << endl;
    // The result is the simplified denominator which is quite obvious so I'll not compute it.
}
