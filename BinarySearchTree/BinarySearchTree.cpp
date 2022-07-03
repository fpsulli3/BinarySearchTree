// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tests.h"

int main() {
    // First, run the functional tests to make sure that 
    // the binary tree implementation works.
    bool functionalTestsPass = runFunctionalTests();

    std::cout << "" << std::endl; // blank line

    if (functionalTestsPass) {
        runPerformanceTest(100);
        runPerformanceTest(1000);
        runPerformanceTest(10000);
        runPerformanceTest(100000);
    }
    else {
        std::cout << "Skipping performance tests because there were errors in the functional tests.";
    }

    std::cout << "" << std::endl; // blank line

    return functionalTestsPass ? 0 : 1;
}