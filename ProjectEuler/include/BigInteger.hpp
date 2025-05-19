#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <string>

using namespace std;

class BigInteger{
    public:
        unsigned char value[2000]; // Todo: unsigned long long instead of unsigned char to reduce operation and complexity
        unsigned char sign = '\0'; // empty char

        BigInteger& operator=(int n);
        BigInteger& operator=(unsigned n);
        BigInteger& operator=(long long n);
        BigInteger& operator=(unsigned long long n);
        BigInteger& operator=(const BigInteger& bI);
        BigInteger& operator=(const string& bI);

        const BigInteger operator+(const BigInteger& bI);
        void operator*=(int n);

        // Idea for comparison operators :
        // https://en.cppreference.com/w/cpp/language/operators#Comparison%20operators
        bool operator<(const BigInteger& bI);
        friend bool operator<(BigInteger& l, const BigInteger& r);
        friend bool operator<(const BigInteger& l, const BigInteger& r);

        unsigned length();

        string ToString() const ;

        void Print();
        static void PerformIntegrationTests();

    private:
        unsigned size = 1;
        // 10715086071862673209484250490600018105614048117055336074437503883703510511249361224931983788156958581275946729175531468251871452856923140435984577574698574803934567774824230985421074605062371141877954182153046474983581941267398767559165543946077062914571196477686542167660429831652624386837205668069376
};

#endif // BIGINTEGER_H
