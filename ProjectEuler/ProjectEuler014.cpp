#include <iostream>
#include <map>

using namespace std;

/*
The following iterative sequence is defined for the set of positive integers:

                            n → n/2 (n is even)
                            n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
                13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Answer: 837799
*/

// See : https://en.wikipedia.org/wiki/Collatz_conjecture

struct Node014{
    unsigned int number;
    Node014* next;
    int stepToOne;

    Node014(){
        number = 1;
        next = nullptr;
        stepToOne = 0;
    }

    Node014(unsigned int number){
        this->number = number;
        this->next = nullptr;
        stepToOne = -1;
    }

    void PrintPath(){
        cout << number;

        if(number == 1){
            cout << endl;
        } else {
            cout << " -> ";
            next->PrintPath();
        }
    }
};

class Graph014{

    public:
    map<unsigned int, Node014*> indexes;

    Graph014(){
        indexes[1] = new Node014();
        AddNode(256);
    }

    ~Graph014(){
        for(auto p : indexes){
            delete p.second;
        }
    }

    inline Node014* operator[](unsigned int number){
        return indexes[number];
    }

    Node014* AddNode(unsigned int number){
        if(indexes[number]){
            //cout << "Index exist for " << number << endl;
            return indexes[number];
        } else {
            //cout << "Create node for " << number << endl;

            Node014* n = new Node014(number);
            indexes[number] = n;

            if(number % 2 == 0){
                number /= 2;
            } else {
                number *= 3;
                number++;
            }

            n->next = AddNode(number);
            n->stepToOne = n->next->stepToOne + 1;
            return n;
        }
    }
};

void ProjectEuler014(){
    int T = 8;
    unsigned int N[] = {
        10,
        15,
        20,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000, // inacurrate
        100000000, // bad_alloc
        1000000000
    };

    Graph014 graph;
    // Precompute power of 2 numbers
    for(int i = 2; i < 5000000; i *= 2){
        graph.AddNode(i);
    }

    for(int a = 0; a < T; a++){
        int n = N[a];

        Node014* maxStep = graph[1];
        for(int i = 2; i <= n; i++){
            graph.AddNode(i);

            if(graph[i]->stepToOne >= maxStep->stepToOne){
                maxStep = graph[i];
            }
        }

        cout << maxStep->number << " with " << maxStep->stepToOne << " steps." << endl;
        //maxStep->PrintPath();
    }

    return;
}
