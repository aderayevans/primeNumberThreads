/*
Create m threads that running simultaneously
Input:
- int n;
- int m;
We divide m into m parts
Thread[1] count the number of prime number in the range 
    from [1..n/m]
Thread[2] count the number of prime number in the range 
    from [(n/m)+1..(2*n/m)]
...
Thread[m-1] count the number of prime number in the range 
    from [((m-1)*n/m)+1..n]
Thread[m]: waiting for result from threads above then
    show result to console
*/

#include <iostream>
#include <regex>
#include "normalprime.hpp"
#include "threadsprime.hpp"

void print_usage();
void start(int, int);
bool isDigit(std::string);

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1]=="-h")
    {
        print_usage();
    }
    else if (argc == 2 && isDigit(argv[1]))
    {
        // Normalprime::printPrime(std::stod(argv[1]));
        Threadsprime::printPrime(std::stod(argv[1]), 1);
    }
    else if (argc == 3)
    {
        if (isDigit(argv[1]) && isDigit(argv[2]))
        {
            Threadsprime::printPrime(std::stod(argv[1]), std::stod(argv[2]));
        }
        else
        {
            print_usage();
        }
    }
    else
    {
        print_usage();
    }

    // exit(0);
    return 0;
}

void print_usage()
{
    std::cout << R"(
usage: primenumber.exe [N]

Adding description

optional arguments:
    [-h], [--help]  show this help message and exit
    [N]             which N is an interger, print all prime numbers from 1 to N
    [N T]           which N and T are interger, print all prime numbers from 1 to N 
                        with T threads

example:
    primenumber.exe -h

    primenumber.exe 50

    primenumber.exe 100 10
)";
}

bool isDigit(std::string str)
{
    std::regex regex_pattern("-?[0-9]+");

    if (std::regex_match(str, regex_pattern))
        return true;
    return false;
}