#include <iostream>

using namespace std;

/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order,
but it also has a rather interesting sub-string divisibility property.

Let d_1 be the 1st digit, d_2 be the 2nd digit, and so on. In this way, we note the following:

    d_2d_3d_4=406 is divisible by 2 (rule 1)
    d_3d_4d_5=063 is divisible by 3 (rule 2)
    d_4d_5d_6=635 is divisible by 5 (rule 3)
    d_5d_6d_7=357 is divisible by 7 (rule 4)
    d_6d_7d_8=572 is divisible by 11 (rule 5)
    d_7d_8d_9=728 is divisible by 13 (rule 6)
    d_8d_9d_10=289 is divisible by 17 (rule 7)

Find the sum of all 0 to 9 pandigital numbers with this property.

Answer: 16695334890 (1.214ms)

Tags: pandigital(char*), k-combinations
*/

void moveLeft(unsigned char* number, unsigned char size){
    unsigned char d_0 = *number;
    for(unsigned char i = 0; i < size-1; i++){
        *(number+i) = *(number+i+1);
    }
    *(number+size-1) = d_0;
}

void print(unsigned char number[10]){
    for(unsigned i = 0; i < 10; i++){
        cout << (unsigned short)number[i] << " ";
    };
    cout << "\n";
}

void Rule7(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[9];

    do{
        if ((number[7]*100 + number[8]*10 + number[9])%17 == 0){
            unsigned long long mul = 1;
            for(char i = 9; i >= 0; i--){
                sum += mul*number[i];
                mul*=10;
            }
        }

        moveLeft(number+9, 1);
    } while(number[9] != first);
}

void Rule6(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[8];

    do{
        if ((number[6]*100 + number[7]*10 + number[8])%13 == 0){
            Rule7(number, sum);
        }

        moveLeft(number+8, 2);
    } while(number[8] != first);
}

void Rule5(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[7];

    do{
        if ((number[5]*100 + number[6]*10 + number[7])%11 == 0){
            Rule6(number, sum);
        }

        moveLeft(number+7, 3);
    } while(number[7] != first);
}

void Rule4(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[6];

    do{
        if ((number[4]*100 + number[5]*10 + number[6])%7 == 0){
           Rule5(number, sum);
        }

        moveLeft(number+6, 4);
    } while(number[6] != first);
}

// Divisible by 5
void Rule3(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[5];

    do{
        if (number[5] == 0 || number[5] == 5){
            Rule4(number, sum);
        }

        moveLeft(number+5, 5);
    }while(number[5] != first);
}

// Divisible by 3
void Rule2(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[4];

    do{
        if((number[2] + number[3] + number[4])%3 == 0){
            Rule3(number, sum);
        }

        moveLeft(number+4, 6);
    }while(number[4] != first);
}

// Divisible by 2
void Rule1(unsigned char number[10], unsigned long long& sum){
    unsigned char first = number[3];

    do{
        if(number[3]%2 == 0){
            Rule2(number, sum);
        }

        moveLeft(number+3, 7);
    }while(number[3] != first);
}

void ProjectEuler043(){
    unsigned long long sum = 0;

    unsigned char number[10] = {0,1,2,3,4,5,6,7,8,9};

    unsigned char d_0 = number[0];

    do{
        unsigned char d_1 = number[1];

        do{
            unsigned char d_2 = number[2];

            do{
                Rule1(number, sum);

                moveLeft(number+2, 8);
            }while(number[2] != d_2);

            moveLeft(number+1, 9);
        }while(number[1] != d_1);

        moveLeft(number, 10);
    }while(number[0] != d_0);

    cout << sum << "\n";
}
