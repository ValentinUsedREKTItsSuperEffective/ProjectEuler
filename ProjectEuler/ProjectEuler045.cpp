#include <iostream>

using namespace std;

/*
Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

    Triangle    T_n=n(n + 1)/2      1, 3,  6, 10, 15, ...
    Pentagonal  P_n=n(3n - 1)/2     1, 5, 12, 22, 35, ...
    Hexagonal   H_n=n(2n - 1)       1, 6, 15, 28, 45, ...

It can be verified that T_285 = P_165 = H_143 = 40755

Find the next triangle number that is also pentagonal and hexagonal.

Answer: 1533776805 (0.507ms)

Tags:
*/

/* Thoughts:
I want to be sure that H_n >= P_n >= T_n.

Let see, function differences.

For n a positive integer,

    P_n - T_n   =   n(3n - 1)/2 - n(n + 1)/2
                =   n(3n - n - 1 - 1)/2
                =   n(2n - 2)/2
                =   n(n - 1)    >= 0

So,
        P_n - T_n   >=  0
    <=> P_n         >=  T_n

    H_n - P_n   =   n(2n - 1) - n(3n - 1)/2
                =   n(2n - 1 - 1.5n + 0.5)
                =   n(0.5n - 0.5)
                =   n(n - 1)/2  >= 0

Again,
        H_n - P_n   >=  0
    <=> H_n         >=  P_n

This prove that H_n  >= P_n >= T_n.

So, if we want T_a = P_b = H_c, a, b & c must follow:

    a > b > c

-------------
From 044, we know that P_n+1 = P_n + 3n + 1

What about the other two ?

    T_n+1   =   (n+1)((n+1) + 1)/2
            =   ((n+1)^2 + (n+1))/2
            =   (n^2 + 2n + 1 + n + 1)/2
            =   (n^2 + n)/2 + (2n + 2)/2
            =   n(n + 1)/2 + n + 1
            =   T_n + n + 1

    H_n+1   =   (n+1)(2(n+1) - 1)
            =   2(n+1)^2 - (n+1)
            =   2(n^2 + 2n + 1) - n - 1
            =   2n^2 + 4n + 2 - n - 1
            =   2n^2 - n + 4n + 2 - 1
            =   n(2n - 1) + 4n + 1
            =   H_n + 4n + 1
*/

void ProjectEuler045(){
    unsigned c = 143;
    unsigned b = 165;
    unsigned a = 285;
    unsigned H_c = 40755 + 4*c++ + 1;
    unsigned P_b = 40755 + 3*b++ + 1;
    unsigned T_a = 40755 + a++ + 1;

    while(H_c != P_b || H_c != T_a) {
        while(H_c > P_b){
            P_b += 3*b++ + 1;
        }

        if(P_b > H_c){
            while(H_c <= P_b){
                H_c += 4*c++ + 1;
            }
        } else {
            while(H_c > T_a){
                T_a += a++ + 1;
            }

            if(T_a > H_c){
                while(H_c <= T_a){
                    H_c += 4*c++ + 1;
                }
            }
        }
    }

    cout << T_a << "\n";
}

