#include "BigInteger.hpp"
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

BigInteger::BigInteger(): size(1){
    memset(value, 0, sizeof(value));
}

BigInteger::~BigInteger(){}

BigInteger& BigInteger::operator =(int n){
    int i = 0;
    do{
        value[i++] = n % 10;
        n /= 10;
    } while(n > 0);

    size = i;

    return *this;
}

void BigInteger::operator *=(int n){
    int ret = 0;
    int tmp = 0;
    for(unsigned int i = 0; i < size; i++){
        tmp = value[i] * n + ret;
        ret = tmp / 10;
        value[i] = tmp % 10;
    }

    while(ret > 0){
        value[size++] = ret % 10;
        ret /= 10;
    }
}

void BigInteger::Print(){
    string s = "";
    for(unsigned int i = 0; i < size; i++){
        s = to_string(value[i]) + s;
    }
    cout << s << endl;
}
