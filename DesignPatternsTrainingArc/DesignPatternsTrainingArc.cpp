#include <cassert>
#include <iostream>
#include <mutex>
#include <vector>

#include "Factory.h"
#include "Singleton.h"

void TestSingleton() {
    auto instance1 = Singleton::GetInstance();
    auto instance2 = Singleton::GetInstance();
    assert(instance1 == instance2);
    
    constexpr int NUMBER_OF_THREADS = 1000;
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

void TestFactory() {
    Factory factory;
    auto incorrectPowerUp = factory.FactoryMethod(ARMOR);
    assert(!incorrectPowerUp);
    auto correctPowerUp = factory.FactoryMethod(HEALTH);
    assert(correctPowerUp);
    assert(correctPowerUp->GetName() == "Health Power Up");
    std::cout << "Factory tests have passed\n";
}

int main(int argc, char* argv[])
{
    TestSingleton();
    TestFactory();
    return 0;
}
