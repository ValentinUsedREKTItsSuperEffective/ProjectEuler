#include <iostream>
#include <map>

using namespace std;

/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10 = 	0.1


Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

Answer: 983
*/

/*
To detect if there is a recurring cycle, each number in the left part of the euclidean division must be unique.
if at some point, the left part end with a 0, it means that there is no cycle.

So for 1/4:

1   |4
10  |------
 2  |0.25
 20 |
  0 <- no cycle

For 1/7:
1       |4
10      |------
 3      |0.142857
 30     |
  2     |
  20
   4
   40
    5
    50
     1 <- numerator 1 already in the left part

To check uniqueness of each numerator, we use a map.
This map store the moment(value) when numerator(key) has been encounter in the left part

Warning:
    This algorithm doesn't compute the length of the cycle nor its value.
    That's not the goal of the problem.
*/

void ProjectEuler026(){
    map<unsigned int, unsigned int> m;
    unsigned int max = 0, numerator = 0, index = 0, maxI = 0;

    // start at 7 since it's the earliest biggest sequence
    for(unsigned int i = 7; i < 1000; i++){
        m.clear();

        numerator = 1;
        index = 0;
        m[numerator] = index;

        while(numerator > 0){
            if(numerator < i){
                numerator *= 10;
            } else {
                numerator %= i;
            }

            if(m[numerator] != 0){
                break;
            } else {
                m[numerator] = ++index;
            }
        }

        if(numerator > 0){
            if(max < index - m[numerator]){
                max = index - m[numerator];
                maxI = i;
            }
        }
    }

    cout << maxI << endl;
}

