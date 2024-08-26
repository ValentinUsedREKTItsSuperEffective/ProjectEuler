#include <iostream>
#include <map>

using namespace std;

/*
145 is a curious number, as 1! + 4! + 5! = 145!.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

Answer: 40730

Tags: Factorial
*/

/*
Brute-forced the problem over the first 1.000.000 numbers.(0.029 sec)

Luckily (and somehow disappointing): https://mathworld.wolfram.com/Factorion.html
*/

constexpr int Factorial(int i) {
    if (i == 0) {
        return 1;
    }

    return i * Factorial(i - 1);
}

void ProjectEuler034(){
    int factorials[10] = {
        Factorial(0),
        Factorial(1),
        Factorial(2),
        Factorial(3),
        Factorial(4),
        Factorial(5),
        Factorial(6),
        Factorial(7),
        Factorial(8),
        Factorial(9)
    };

    int result = 0;
    for(int i = 3; i <= 1000000; i++) {
        int N = 0;
        int copyI = i;
        while (copyI > 0) {
            N += factorials[copyI%10];

            if (N > i) {
                break;
            }

            copyI /= 10;
        }

        if (N == i) {
            result += N;
        }
    }

    cout << result << endl;
}
