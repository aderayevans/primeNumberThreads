#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include "threadsprime.hpp"
#include "normalprime.hpp"

void Threadsprime::printPrime(int number, int thread_num)
{
    if (thread_num > number)    
        thread_num = number;
    int first = 1;
    int last;
    std::vector<std::promise<std::vector<int>>> vectorOfPromise;
    std::vector<std::future<std::vector<int>>> vectorOfFuture;

    vectorOfPromise.resize(thread_num);
    vectorOfFuture.resize(thread_num);

    for (int i = 0; i < thread_num; ++i) 
    {
        vectorOfFuture[i] = vectorOfPromise[i].get_future();
    }

    for (int i = 0; i < thread_num; ++i) 
    {
        last = (i+1)*number/thread_num;
        std::cout << "{" << first << ", " << last << "}" << std::endl;

        std::thread temp(
            [](std::promise<std::vector<int>>& prom, int first, int last)
            {
                std::cout << "Thread id:" << std::this_thread::get_id() << std::endl;
                prom.set_value(Normalprime::getPrime(first, last));
            }, ref(vectorOfPromise[i]), first, last);

        temp.join();
        first = last + 1;
    }
    std::thread last_thread(
        [&]()
        {
            for (auto &vec:vectorOfFuture)
            {
                for (auto val:vec.get())
                    std::cout << val << " ";
            }
            std::cout << std::endl;
        });

    last_thread.join();
}