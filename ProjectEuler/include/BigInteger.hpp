#ifndef BIGINTEGER_H
#define BIGINTEGER_H


class BigInteger{
    public:
        short value[10000];
        unsigned int size;

        BigInteger();
        BigInteger(int n);
        ~BigInteger();

        BigInteger& operator =(int n);
        BigInteger& operator =(const BigInteger& bI);

        const BigInteger operator +(const BigInteger& bI);
        void operator *=(int n);

        // Idea for comparison operators :
        // https://en.cppreference.com/w/cpp/language/operators#Comparison%20operators
        bool operator <(const BigInteger& bI);
        friend bool operator <(BigInteger& l, const BigInteger& r);
        friend bool operator <(const BigInteger& l, const BigInteger& r);

        void Print();

    private:
};

#endif // BIGINTEGER_H
