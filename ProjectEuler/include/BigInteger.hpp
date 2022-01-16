#ifndef BIGINTEGER_H
#define BIGINTEGER_H


class BigInteger{
    public:
        short value[10000];
        unsigned int size;

        BigInteger();
        ~BigInteger();

        BigInteger& operator =(int n);
        BigInteger& operator =(const BigInteger& bI);

        BigInteger operator +(const BigInteger& bI);
        void operator *=(int n);

        void Print();

    private:
};

#endif // BIGINTEGER_H
