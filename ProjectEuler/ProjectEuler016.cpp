#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

Answer: 1366
*/

void print(short number[10000]){
    string s = "";
    for(int i = 0; i < 10000 && number[i] != -1; i++){
        s = to_string(number[i]) + s;
    }
    cout << s << endl;
}

void mul(short number[10000], int val){
    short ret = 0;
    for(int i = 0; i < 10000; i++){
        if(number[i] == -1){
            if(ret > 0){
                number[i] = ret;
            }
            return;
        }

        number[i] *= 2;
        number[i] += ret;
        ret = number[i] / 10;
        number[i] %= 10;
    }
}

void ProjectEuler016(){
    int T = 5;
    int N[] = {3, 4, 7, 15, 1000};

    short number[10000];

    for(int i = 0; i < T; i++){
        memset(number, -1, sizeof(number));
        number[0] = 1;
        unsigned int sum = 0;

        for(int j = 1; j <= N[i]; j++){
            mul(number, 2);
        }

        for(int i = 0; i < 10000 && number[i] != -1; i++){
            sum += number[i];
        }

        cout << sum << endl;
    }

    return;
}
