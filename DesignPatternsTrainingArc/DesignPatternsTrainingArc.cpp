#include <cassert>
#include <iostream>
#include <mutex>
#include <vector>

#include "Singleton.h"

void TestSingleton() {
    auto instance1 = Singleton::GetInstance();
    auto instance2 = Singleton::GetInstance();
    assert(instance1 == instance2);
    
    constexpr int NUMBER_OF_THREADS = 100500;
    std::vector<std::thread> threads;
    threads.reserve(NUMBER_OF_THREADS);
    for(int i = 0; i < NUMBER_OF_THREADS; ++i) {
        threads.emplace_back([]() {
            Singleton::GetInstance();
        });
    }
    for(auto& thread : threads) {
        thread.join();
    }
    assert(Singleton::GetNumberOfInstances() == 1);
    std::cout << "Singleton tests have passed\n";
}

int main(int argc, char* argv[])
{
    TestSingleton();
    return 0;
}
