#include <iostream>
#include "BigInteger.hpp"

using namespace std;

void ProjectEuler001();
void ProjectEuler002();
void ProjectEuler003();
void ProjectEuler004();
void ProjectEuler005();
void ProjectEuler006();
void ProjectEuler007();
void ProjectEuler008();
void ProjectEuler009();
void ProjectEuler010();
void ProjectEuler011();
void ProjectEuler012();
void ProjectEuler012_Naive();
void ProjectEuler013();
void ProjectEuler014();
void ProjectEuler015();
void ProjectEuler016();
void ProjectEuler017();
void ProjectEuler018();
void ProjectEuler019();
void ProjectEuler020();
void ProjectEuler021();
void ProjectEuler022();
void ProjectEuler023();
void ProjectEuler024();

int main(){
    BigInteger a;
    a = 99;
    BigInteger b = a;

    a.Print();
    b.Print();

    b.value[0] = 1;

    a.Print();
    b.Print();

    BigInteger c = a + b;
    c.Print();
}
