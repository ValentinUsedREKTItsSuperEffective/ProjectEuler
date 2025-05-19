#include "BigInteger.hpp"
#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

BigInteger& BigInteger::operator=(int n){
    *this = static_cast<long long>(n);

    return *this;
}

BigInteger& BigInteger::operator=(unsigned n){
    *this = static_cast<unsigned long long>(n);

    return *this;
}

BigInteger& BigInteger::operator=(long long n){
    memset(value, 0, sizeof(value));

    sign = '\0';
    if(n < 0){
        n *= -1LL;
        sign = '-';
    }

    size = 0;
    do{
        value[size++] = n % 10;
        n /= 10;
    } while(n > 0);

    return *this;
}

BigInteger& BigInteger::operator=(unsigned long long n){
    memset(value, 0, sizeof(value));

    sign = '\0';

    size = 0;
    do{
        value[size++] = n % 10;
        n /= 10;
    } while(n > 0);

    return *this;
}

BigInteger& BigInteger::operator=(const BigInteger& bI){
    memset(value, 0, sizeof(value));

    sign = bI.sign;
    this->size = bI.size;

    for(unsigned int i = 0; i < size; i++){
        this->value[i] = bI.value[i];
    }

    return *this;
}

BigInteger& BigInteger::operator=(const string& str){
    memset(value, 0, sizeof(value));

    sign = '\0';
    bool isNegative = false;
    if('-' == *str.begin()){
        isNegative = true;
        sign = '-';
    }

    size = 0;

    for(auto it = str.rbegin(); it != str.rend() - (isNegative ? 1 : 0); it++){
        unsigned char charValue = *it - '0';
        if (charValue > 9){
            throw std::overflow_error("operator= for string can only accept digits between 0 and 9 and 'n'");
        }

        value[size++] = charValue;
    }

    return *this;
}

const BigInteger BigInteger::operator+(const BigInteger& bI){
    if(sign != bI.sign){
        throw std::runtime_error("TODO: operator- not implemented");
    }

    BigInteger r = *this;

    if(bI.size > size){
        r.size = bI.size;
    }

    unsigned char ret = 0;
    for(unsigned i = 0; i < bI.size; i++){
        r.value[i] += bI.value[i] + ret;
        ret = r.value[i] / 10;
        r.value[i] %= 10;
    }

    while(ret > 0){
        r.value[r.size++] = ret % 10;
        ret /= 10;
    }

    return r;
}

void BigInteger::operator*=(int n){
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

bool BigInteger::operator<(const BigInteger& bI){
    if(size != bI.size){
        return size < bI.size;
    }

    for(unsigned short i = size - 1; i >= 0; i--){
        if(value[i] != bI.value[i]){
            return value[i] < bI.value[i];
        }
    }

    return false; // at this point compaired integer are the same, so it's false
}

bool operator<(BigInteger& l, const BigInteger& r){
    return l.operator <(r);
}

bool operator<(const BigInteger& l, const BigInteger& r){
    return const_cast<BigInteger&>(l).operator <(r);
}

unsigned BigInteger::length(){
    return size;
}

string BigInteger::ToString() const {
    string s = "";
    for(unsigned int i = 0; i < size; i++){
        s = to_string(value[i]) + s;
    }

    if(sign == '-')
        s = "-" + s;

    return s;
}

void BigInteger::Print(){
    cout << ToString() << "\n";
}

void BigInteger::PerformIntegrationTests(){
    cout << "----- Big Integer -----\n";
    BigInteger big;
    BigInteger big_2;

    assert(big.length() == 1);
    assert(big.sign == '\0');
    assert(big.ToString() == "0");

    big = -25;
    assert(big.length() == 2);
    assert(big.sign == '-');
    assert(big.ToString() == "-25");

    big = 18446744073709551612ULL;
    assert(big.length() == 20);
    assert(big.sign == '\0');
    assert(big.ToString() == "18446744073709551612");

    big = "-88370351051124936122493198378815695858127594672917553146825";
    assert(big.length() == 59);
    assert(big.sign == '-');
    assert(big.ToString() == "-88370351051124936122493198378815695858127594672917553146825");

    big_2 = big;
    assert(big_2.length() == 59);
    assert(big_2.sign == '-');
    assert(big_2.ToString() == "-88370351051124936122493198378815695858127594672917553146825");

    big = "88370351051124936122493198378815695858127594672917553146825";
    big_2 = "598457757469857480393456777482423";

    BigInteger sum = big + big_2;
    assert(sum.length() == 59);
    assert(sum.sign == '\0');
    assert(sum.ToString() == "88370351051124936122493198977273453327985075066374330629248");

    big = "598457757469857480393456777482423";
    big_2 = "88370351051124936122493198378815695858127594672917553146825";

    sum = big + big_2;
    assert(sum.length() == 59);
    assert(sum.sign == '\0');
    assert(sum.ToString() == "88370351051124936122493198977273453327985075066374330629248");

    big = "88370351051124936122493198378815695858127594672917553146825";
    big_2 = "88370351051124936122493198378815695858127594672917553146825";

    sum = big + big_2;
    assert(sum.length() == 60);
    assert(sum.sign == '\0');
    assert(sum.ToString() == "176740702102249872244986396757631391716255189345835106293650");
}
