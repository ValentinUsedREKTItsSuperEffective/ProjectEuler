#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
The decimal number, 585 = 1001001001(binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

Answer: 872187 (0.905sec)

Tags: Palindrome
*/

bool IsPalindrome(unsigned int N) {
    // Use vector here to manage '0' in the numbers
    vector<unsigned short> vecN = vector<unsigned short>();
    while(N > 0) {
        vecN.push_back(N%10);
        N /= 10;
    }

    for(int i = 0, j = vecN.size() - 1; j > i; i++, j--) {
        if(vecN[i] != vecN[j]) {
            return false;
        }
    }

    return true;
}

bool IsBase2Palindrome(unsigned int Base10Number) {
    vector<unsigned short> binaryN = vector<unsigned short>();
    unsigned int uintBits = sizeof(unsigned int) * 8;
    unsigned int mask = 1 << (uintBits - 1); // = 2^31
    unsigned int bitShift = 0;
    while ((Base10Number & mask) == 0) {
        Base10Number <<= 1;
        bitShift++;
    }

    for(; bitShift < uintBits; bitShift++, Base10Number <<= 1) {
        binaryN.push_back((Base10Number & mask) == mask ? 1 : 0);
    }

    for(int i = 0, j = binaryN.size() - 1; j > i; i++, j--) {
        if(binaryN[i] != binaryN[j]) {
            return false;
        }
    }

    return true;
}

void ProjectEuler036(){
    int result = 0;
    for (unsigned int N = 1; N < 1000000; N++){
        if (IsPalindrome(N) && IsBase2Palindrome(N)) {
            result += N;
        }
    }

    cout << result << endl;
}


