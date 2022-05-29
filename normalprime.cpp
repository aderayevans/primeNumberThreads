#include <iostream>
#include "normalprime.hpp"

bool Normalprime::isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void Normalprime::printPrime(int number)
{
    for (int i = 1; i <= number; ++i) {
        if (isPrime(i))
            std::cout << i << " ";
    }
}

void Normalprime::printPrime(int n, int m)
{
    for (int i = n; i <= m; ++i) {
        if (isPrime(i))
            std::cout << i << " ";
    }
}

std::vector<int> Normalprime::getPrime(int n, int m)
{
    std::vector<int> results;
    for (int i = n; i <= m; ++i) {
        if (isPrime(i))
            results.push_back(i);
    }
    return results;
}