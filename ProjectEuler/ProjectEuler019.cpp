#include <iostream>

using namespace std;

/*
You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer: 171
*/

void ProjectEuler019(){
    unsigned int nbOfDays = 1;
    unsigned int nbOfSundays = 0;

    for(int y = 1900; y < 2001; y++){
        for(int m = 1; m <= 12; m++){
            switch(m){
                case 4:
                case 6:
                case 9:
                case 11:
                    nbOfDays += 30;
                    break;
                case 2:
                    if(y % 4 == 0){
                        if(y % 100 == 0 && y % 400 != 0){
                            nbOfDays += 28;
                        } else {
                            nbOfDays += 29;
                        }
                    } else {
                        nbOfDays += 28;
                    }
                    break;
                default:
                    nbOfDays += 31;
                    break;
            }

            if(nbOfDays % 7 == 0 && y >= 1901){ // Sunday
                nbOfSundays++;
            }
        }
    }

    cout << nbOfSundays << endl;
}

