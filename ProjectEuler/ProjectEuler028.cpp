#include <iostream>

using namespace std;

/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

                                                21 22 23 24 25
                                                20  7  8  9 10
                                                19  6  1  2 11
                                                18  5  4  3 12
                                                17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

Answer: 669171001
*/

/*
Few observations here:
From one, it need a step of 2 to reach every diagonals of the layer 1, then a step of 4 for the layer 2, then a step of 6 for the layer 3, ...

Starting with n = 1, getting to the next diagonal is n + step of the layer.
So for the layer 1,
n = 1
n1 =  n + 2
n2 = n1 + 2 = n + 2*2
n3 = n2 + 2 = n + 3*2
n4 = n3 + 2 = n + 4*2

For layer 2,

n = 9
n1 =  n + 4
n2 = n1 + 4 = n + 2*4
n3 = n2 + 4 = n + 3*4
n4 = n3 + 4 = n + 4*4

So for a layer:

    n4 = n * step (1)

And for each layer, we need to add each diagonal to the result

    n1 + n2 + n3 + n4

which can be summarize as adding :

        4*n + 10*step (2)
*/

/*
    This spiral is called Ulam spiral.
    cf: https://en.wikipedia.org/wiki/Ulam_spiral
*/

void ProjectEuler028(){
    unsigned int n = 1;
    unsigned int sum = 1;

    for(int spiralSize = 3; spiralSize <= 1001; spiralSize += 2){
        int step = spiralSize - 1;

        sum += (4 * n + 10 * step); // (2)
        n += 4 * step; // (1)
    }

    cout << sum << endl;
}
