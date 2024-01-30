// Copyright 2024
// By Louis Carrico-Braun

#ifndef _HOME_LCARRICO_PROJECTS_PS1_FIBLFSR_HPP_
#define _HOME_LCARRICO_PROJECTS_PS1_FIBLFSR_HPP_
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::cin;

namespace PhotoMagic {
class FibLFSR {
 public:
    // constructor to create LFSR with the given initial seed and tap
    explicit FibLFSR(string seed);

    // simulate one step and return the new bit as 0 or 1
    int step();

    // simulate k steps and return k-bit integer
    int generate(int k);
 private:
    // Checks to see if the string inputted is a 16 digit binary number
    bool isValid(string givenSeed);

    // Store seed
    std::string seed;

    // Store values to tap
    int pos13;
    int pos12;
    int pos10;
};
std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);
}  // namespace PhotoMagic
#endif  // _HOME_LCARRICO_PROJECTS_PS1_FIBLFSR_HPP_
