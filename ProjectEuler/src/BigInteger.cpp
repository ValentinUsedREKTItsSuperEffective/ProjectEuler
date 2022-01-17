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

BigInteger& BigInteger::operator=(const BigInteger& bI){
    this->size = bI.size;

    for(unsigned int i = 0; i < size; i++){
        this->value[i] = bI.value[i];
    }

    return *this;
}

const BigInteger BigInteger::operator +(const BigInteger& bI){
    BigInteger r;
    r = *this;

    int ret = 0;
    for(unsigned int i = 0; i < bI.size; i++){
        r.value[i] += bI.value[i] + ret;
        ret = r.value[i] / 10;
        r.value[i] %= 10;
    }

    if(bI.size > r.size){
        r.size = bI.size;
    }

    while(ret > 0){
        r.value[r.size++] = ret % 10;
        ret /= 10;
    }

    return r;
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
