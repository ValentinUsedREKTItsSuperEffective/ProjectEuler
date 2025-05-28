#include <iostream>
#include "PEUtility.hpp"
#include <cmath>
#include <limits>

using namespace std;

/*
The primes 3, 7, 109, and 673, are quite remarkable.
By taking any two primes and concatenating them in any order the result will always be prime.
For example, taking 7 and 109, both 7109 and 1097 are prime.
The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

Answer: 26033 (22071ms)
*/

void ProjectEuler060(){
    constexpr unsigned sieveLimit = 100000000;
    auto primes = PEUtility::EratostheneSieve(sieveLimit);
    unsigned sumMin = std::numeric_limits<unsigned>::max();

    for(auto itA = primes.begin(); itA != primes.end(); itA++){
        unsigned sum = *itA;
        if(sum >= sumMin){
            break;
        }

        unsigned sizeA = std::log10(*itA) + 1;
        unsigned shiftA = std::pow(10, sizeA);

        for(auto itB = itA + 1; itB != primes.end(); itB++){
            sum = *itA + *itB;
            if(sum >= sumMin){
                break;
            }

            unsigned BA = *itB * shiftA + *itA;
            if(BA > sieveLimit){
                break;
            }

            if(!PEUtility::IsPrime(BA)){
                continue;
            }

            unsigned sizeB = std::log10(*itB) + 1;
            unsigned shiftB = std::pow(10, sizeB);
            unsigned AB = *itA * shiftB + *itB;

            if(!PEUtility::IsPrime(AB)){
                continue;
            }

            for(auto itC = itB + 1; itC != primes.end(); itC++){
                sum = *itA + *itB + *itC;
                if(sum >= sumMin){
                    break;
                }

                unsigned CA = *itC * shiftA + *itA;
                unsigned CB = *itC * shiftB + *itB;
                if(CB > sieveLimit){
                    break;
                }

                if(!PEUtility::IsPrime(CA)){
                    continue;
                }

                if(!PEUtility::IsPrime(CB)){
                    continue;
                }

                unsigned sizeC = std::log10(*itC) + 1;
                unsigned shiftC = std::pow(10, sizeC);
                unsigned AC = *itA * shiftC + *itC;
                unsigned BC = *itB * shiftC + *itC;

                if(!PEUtility::IsPrime(AC)){
                    continue;
                }

                if(!PEUtility::IsPrime(BC)){
                    continue;
                }

                for(auto itD = itC + 1; itD != primes.end(); itD++){
                    sum = *itA + *itB + *itC + *itD;
                    if(sum >= sumMin){
                        break;
                    }

                    unsigned DA = *itD * shiftA + *itA;
                    unsigned DB = *itD * shiftB + *itB;
                    unsigned DC = *itD * shiftC + *itC;
                    if(DC > sieveLimit){
                        break;
                    }

                    if(!PEUtility::IsPrime(DA)){
                        continue;
                    }

                    if(!PEUtility::IsPrime(DB)){
                        continue;
                    }

                    if(!PEUtility::IsPrime(DC)){
                        continue;
                    }

                    unsigned sizeD = std::log10(*itD) + 1;
                    unsigned shiftD = std::pow(10, sizeD);
                    unsigned AD = *itA * shiftD + *itD;
                    unsigned BD = *itB * shiftD + *itD;
                    unsigned CD = *itC * shiftD + *itD;

                    if(!PEUtility::IsPrime(AD)){
                        continue;
                    }

                    if(!PEUtility::IsPrime(BD)){
                        continue;
                    }

                    if(!PEUtility::IsPrime(CD)){
                        continue;
                    }

                    for(auto itE = itD + 1; itE != primes.end(); itE++){
                        sum = *itA + *itB + *itC + *itD + *itE;
                        if(sum >= sumMin){
                            break;
                        }

                        unsigned EA = *itE * shiftA + *itA;
                        unsigned EB = *itE * shiftB + *itB;
                        unsigned EC = *itE * shiftC + *itC;
                        unsigned ED = *itE * shiftD + *itD;
                        if(ED > sieveLimit){
                            //cout << "Sieve limit!\n";
                            break;
                        }

                        if(!PEUtility::IsPrime(EA)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(EB)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(EC)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(ED)){
                            continue;
                        }

                        unsigned sizeE = std::log10(*itE) + 1;
                        unsigned shiftE = std::pow(10, sizeE);
                        unsigned AE = *itA * shiftE + *itE;
                        unsigned BE = *itB * shiftE + *itE;
                        unsigned CE = *itC * shiftE + *itE;
                        unsigned DE = *itD * shiftE + *itE;

                        if(!PEUtility::IsPrime(AE)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(BE)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(CE)){
                            continue;
                        }

                        if(!PEUtility::IsPrime(DE)){
                            continue;
                        }


                        if(sum < sumMin){
                            sumMin = sum;
                            cout << *itA << ", " << *itB << ", " << *itC << ", " << *itD << ", " << *itE << ", sum = " << sumMin << "\n";
                            break;
                        }
                    }
                }
            }
        }
    }
}
