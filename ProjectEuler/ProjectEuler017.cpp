#include <iostream>
#include <map>

using namespace std;

/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.

Answer: 21124
*/

void ProjectEuler017(){
    string s = "";

    map<int, string> words;
    for(int i = 0; i < 1000; i++){
        words[i] = "";
    }

    words[1] = "one";
    words[2] = "two";
    words[3] = "three";
    words[4] = "four";
    words[5] = "five";
    words[6] = "six";
    words[7] = "seven";
    words[8] = "eight";
    words[9] = "nine";
    words[10] = "ten";
    words[11] = "eleven";
    words[12] = "twelve";
    words[13] = "thirteen";
    words[14] = "fourteen";
    words[15] = "fifteen";
    words[16] = "sixteen";
    words[17] = "seventeen";
    words[18] = "eighteen";
    words[19] = "nineteen";
    words[20] = "twenty";
    words[30] = "thirty";
    words[40] = "forty";
    words[50] = "fifty";
    words[60] = "sixty";
    words[70] = "seventy";
    words[80] = "eighty";
    words[90] = "ninety";
    words[100] = "hundred";
    words[1000] = "thousand";

    for(int i = 1; i < 1000; i++){
        if(words[i] != ""){
            if(i == 100){
                s += "one";
            }

            s += words[i];
        } else {
            int hundred = i / 100;

            if(hundred > 0){
                s += words[hundred] + words[100];

                if(i % 100 != 0){
                    s += "and";
                }
            }

            hundred = i % 100;

            if(hundred != 0){
                if(words[hundred] == ""){
                    int d = i / 10;
                    words[hundred] = words[d*10] + words[i%10];
                }

                s += words[hundred];
            }
        }
    }

    s += "onethousand";

    cout << s.length() << endl;
}

