#include <iostream>
#include "PEUtility.hpp"

using namespace std;

/*
Take the number 192 and multiply it by each of 1, 2, and 3:
192 x 1 = 192
192 x 2 = 384
192 x 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576.
We will call 192384576 the concatenated product of 192 and (1,2,3).

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5,
giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product
of an integer with (1,2,...,n) where n > 1?

Answer: 932718654 (12.033ms)

Tags: Pandigital
*/

/* Thoughts:
The concatenating product of N over (1,2,..,n) will always have N at first.
So N has to be Pandigital at first.
-> This makes the program slower. Expected.

Potentially, the largest 9-digit pandigital number is 987654321.
Since it has to be the concatenation of at least two numbers,
I suppose that N have a maximum of 9876.
*/

unsigned ProjectEuler038(){
    unsigned int largestPandigital = 0;
    for(unsigned i = 1; i <= 9876; i++){
        unsigned concatenatedProduct = i;
        for(unsigned n = 2; PEUtility::UIntLength(concatenatedProduct) < 9; n++){
            unsigned product = i*n;
            unsigned lenghtP = PEUtility::UIntLength(product);
            concatenatedProduct = concatenatedProduct * pow(10, lenghtP) + product;
        }

        if(PEUtility::UIntLength(concatenatedProduct) != 9){
            continue;
        }

        if(!PEUtility::IsPandigital(concatenatedProduct)) {
            continue;
        }

        if(concatenatedProduct > largestPandigital){
            largestPandigital = concatenatedProduct;
        }
    }

    cout << largestPandigital << "\n";
    return largestPandigital;
}


