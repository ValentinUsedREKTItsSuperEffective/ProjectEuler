#include <iostream>
#include <chrono>
#include <cassert>

#include "PEUtility.hpp"

#include "ProjectEuler001.hpp"

// #define TEST

using namespace std;

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
void ProjectEuler025();
void ProjectEuler026();
void ProjectEuler027();
void ProjectEuler028();
void ProjectEuler029();
void ProjectEuler030();
void ProjectEuler031();
unsigned long long ProjectEuler032();
void ProjectEuler033();
void ProjectEuler034();
void ProjectEuler035();
void ProjectEuler036();
void ProjectEuler037();
unsigned ProjectEuler038();
void ProjectEuler039();
void ProjectEuler040();
void ProjectEuler041();
void ProjectEuler042();
void ProjectEuler043();
void ProjectEuler044();
void ProjectEuler045();

int main(){
#ifdef TEST
    assert(PEUtility::BreakNumber((unsigned)3201).size() == 4);
    assert(PEUtility::BreakNumber((unsigned long long)3201).size() == 4);
    assert(PEUtility::IsPandigital(3201) == false);
    assert(PEUtility::IsPandigital(98765431) == false);
    assert(PEUtility::IsPandigital(887645321) == false);

    assert(ProjectEuler032() == 45228LL);
    assert(ProjectEuler038() == 932718654);
#endif // TEST

    std::chrono::steady_clock::time_point startTimePoint = std::chrono::steady_clock::now();

    ProjectEuler045();

    std::chrono::steady_clock::time_point endTimePoint = std::chrono::steady_clock::now();
    cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(endTimePoint - startTimePoint).count() / 1000.0 << "ms\n";
}
