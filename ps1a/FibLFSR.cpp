// Copyright 2024
// By Louis Carrico-Braun

#include "FibLFSR.hpp"
#include <math.h>
#include <iostream>
using PhotoMagic::FibLFSR;

FibLFSR::FibLFSR(string seed) {
    // Check if input is a valid 16 char string
    while (seed.length() != 16) {
        cout
        << "This string is NOT 16 characters, do it correctly or not at all: ";
        cin >> seed;
    }

    while (!isValid(seed)) {
        cout <<
        "Making up 1s and 0s isn't that hard, no way you thought this worked";
        cin >> seed;
    }

    this->seed = seed;
}

int FibLFSR::step() {
    int lastDigit = 0;

    // Store values to tap
    pos13 = seed.at(2) - '0';
    pos12 = seed.at(3) - '0';
    pos10 = seed.at(5) - '0';

    lastDigit = seed.at(0) - '0';

    lastDigit = lastDigit ^ pos13;

    lastDigit = lastDigit ^ pos12;

    lastDigit = lastDigit ^ pos10;

    seed.erase(0, 1);
    seed.push_back(lastDigit);

    return lastDigit;
}

int FibLFSR::generate(int k) {
    string binaryResult = "";
    int result = 0;

    for (int i = 0; i < k; i++) {
        binaryResult.push_back(step());
    }

    for (int i = binaryResult.length() - 1; i > 0; i--) {
        result += pow(2, (i)) * (binaryResult.at(i) - '0');
    }

    return result;
}

bool FibLFSR::isValid(string givenSeed) {
    int tempSeed = givenSeed.length();
    for (int i = 0; i < tempSeed; i++) {
        if (isdigit(givenSeed[i]) == false) {
            return false;
        } else if (givenSeed[i] == '0' || givenSeed[i] == '1') {
            return true;
        }
    }

    return false;
}
