#ifndef NORMALPRIME_HPP
#define NORMALPRIME_HPP
#include <vector>

class Normalprime
{
public:
    static bool isPrime(int);
    static void printPrime(int);
    static void printPrime(int, int);
    static std::vector<int> getPrime(int n, int m);
};
#endif