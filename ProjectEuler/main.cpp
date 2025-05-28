#include <iostream>
#include <chrono>
#include <cassert>

#include "PEUtility.hpp"

#include "ProjectEuler001.hpp"

// #define TEST
#ifdef TEST
#include "BigInteger.hpp"
#endif // TEST

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
void ProjectEuler027(); // Require a clear of the prime sieve otherwise testing 027 takes ages
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
void ProjectEuler046();
void ProjectEuler047();
void ProjectEuler048();
void ProjectEuler049();
void ProjectEuler050();
void ProjectEuler051();
void ProjectEuler052();
unsigned ProjectEuler053();
void ProjectEuler054();
void ProjectEuler055();
void ProjectEuler056();
unsigned ProjectEuler057();
void ProjectEuler058();
void ProjectEuler059();
void ProjectEuler060();

int main(){
#ifdef TEST
    cout << "===== Start Tests =====\n";
    assert(PEUtility::BreakIntegral<unsigned>(3201).size() == 4);
    assert(PEUtility::BreakIntegral<unsigned>(3201) == std::vector<unsigned char>({3,2,0,1}));
    assert(PEUtility::BreakIntegral<unsigned>(3201, true) == std::vector<unsigned char>({1,0,2,3}));
    assert(PEUtility::IsPandigital(3201) == false);
    assert(PEUtility::IsPandigital(98765431) == false);
    assert(PEUtility::IsPandigital(887645321) == false);
    assert(PEUtility::BinomialCoeficient(10,2) == PEUtility::BinomialCoeficient(10,8));
    assert(PEUtility::BinomialCoeficient(40,20) == 137846528820LL); // ProjectEuler015
    assert(PEUtility::BinomialCoeficient(23,10) == 1144066);

    BigInteger::PerformIntegrationTests();

    assert(ProjectEuler032() == 45228LL);
    assert(ProjectEuler038() == 932718654);
    assert(ProjectEuler053() == 4075);
    assert(ProjectEuler057() == 153);

    cout << "----- Primes -----\n";
    auto primes = PEUtility::EratostheneSieve(1000000);
    assert(primes.size() == 78498);
    assert(primes.at(0) == 2);
    assert(primes.at(29) == 113);
    assert(primes.at(37) == 163);
    assert(primes.at(42) == 191);
    assert(primes.at(92) == 487);
    assert(primes.at(376) == 2591);
    assert(primes.at(735) == 5573);
    assert(primes.at(837) == 6451);
    assert(primes.at(985) == 7789);
    assert(primes.at(2874) == 26161);
    assert(primes.at(5983) == 59183);
    assert(primes.at(7847) == 80153);
    assert(primes.at(8374) == 86143);
    assert(primes.at(78497) == 999983);

    assert(PEUtility::IsPrime(1) == false);
    assert(PEUtility::IsPrime(11) == true);
    assert(PEUtility::IsPrime(17) == true);
    assert(PEUtility::IsPrime(53) == true);
    assert(PEUtility::IsPrime(67) == true);
    assert(PEUtility::IsPrime(73) == true);
    assert(PEUtility::IsPrime(89) == true);
    assert(PEUtility::IsPrime(97) == true);
    assert(PEUtility::IsPrime(149) == true);
    assert(PEUtility::IsPrime(193) == true);
    assert(PEUtility::IsPrime(229) == true);
    assert(PEUtility::IsPrime(619) == true);
    assert(PEUtility::IsPrime(10005) == false);
    assert(PEUtility::IsPrime(10035) == false);
    assert(PEUtility::IsPrime(10125) == false);
    assert(PEUtility::IsPrime(10215) == false);
    assert(PEUtility::IsPrime(10395) == false);
    assert(PEUtility::IsPrime(10575) == false);
    assert(PEUtility::IsPrime(10725) == false);
    assert(PEUtility::IsPrime(10845) == false);
    assert(PEUtility::IsPrime(11025) == false);
    assert(PEUtility::IsPrime(11265) == false);
    assert(PEUtility::IsPrime(673109) == true);
    cout << "===== End Tests =====\n";
#endif // TEST

    std::chrono::steady_clock::time_point startTimePoint = std::chrono::steady_clock::now();

    ProjectEuler060();

    std::chrono::steady_clock::time_point endTimePoint = std::chrono::steady_clock::now();
    cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::microseconds>(endTimePoint - startTimePoint).count() / 1000.0 << "ms\n";
}
