#include <iostream>

using namespace std;

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer: 906609

Tags: Palindrome
*/

void ProjectEuler004(){
    int T = 2;
    long long N[] = {101110, 800000};

    for(int i = 0; i < T; i++){
        long long n = N[i];

        if(n < 101101){
            cout << 101101 << endl;
        } else {
            bool continueFlag = true;
            for( int leftPart = n / 1000; leftPart >= 101 && continueFlag; leftPart--){
                int rightPart = leftPart / 100 + leftPart % 100 - leftPart % 10 + leftPart % 10 * 100;
                int pal = leftPart * 1000 + rightPart;
                if(pal < n){
                    for(int i = 100; i < 1000 && continueFlag; i++){
                        if(pal % i == 0 && pal / i < 1000){
                            cout << pal << endl;
                            continueFlag = false;
                        }
                    }
                }
            }

        }
    }

    return;
}

