#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Answer: 232792560
*/

void ProjectEuler005(){
    int T = 3;
    long long N[] = {3, 10, 20};

    for(int i = 0; i < T; i++){
        long long n = N[i];

        if(n == 1){
            cout << 1 << endl;
            continue;
        } else if(n == 2){
            cout << 2 << endl;
            continue;
        } else if(n == 3){
            cout << 6 << endl;
            continue;
        }

        vector<int> erase;

        set<int> s;
        for(int i = 2; i <= n; i++){
            for(int nb : s){
                if(i % nb == 0){
                    erase.push_back(nb);
                }
            }

            for(int e : erase){
                s.erase(e);
            }
            erase.clear();

            s.emplace(i);
        }

        unsigned long long end = *s.rbegin();
        unsigned long long k = end * (*(++s.rbegin()));
        bool flag = true;
        while(flag){
            for(unsigned long long nb : s){
                if(k % nb != 0){
                    break;
                }

                if(nb == end){
                    cout << k << endl;
                    flag = false;
                }
            }

            k += end;
        }
    }

    return;
}

