#include <cassert>
#include <iostream>
#include <mutex>
#include <vector>

#include "CreationalPatterns/AbstractFactory.h"
#include "CreationalPatterns/CharacterBuilder.h"
#include "CreationalPatterns/FactoryMethodShowcase.h"
#include "CreationalPatterns/NPC.h"
#include "CreationalPatterns/Singleton.h"

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

void TestFactoryMethod() {
    FactoryMethodShowcase factory;
    auto incorrectPowerUp = factory.FactoryMethod(ARMOR);
    assert(!incorrectPowerUp);
    auto correctPowerUp = factory.FactoryMethod(HEALTH);
    assert(correctPowerUp);
    assert(correctPowerUp->GetName() == "Health Power Up");
    std::cout << "Factory method tests have passed\n";
}

void TestAbstractFactory() {
    WarriorItemFactory warriorItemFactory;
    MageItemFactory mageItemFactory;
    auto weapon1 = warriorItemFactory.CreateWeapon();
    assert(weapon1->GetName() == "Sword");
    auto weapon2 = mageItemFactory.CreateWeapon();
    assert(weapon2->GetName() == "Staff");
    std::cout << "Abstract factory tests have passed\n";
}

void TestBuilder() {
    CharacterBuilder builder;
    builder.SetName("Alice");
    builder.SetCharacterClass(MAGE);
    auto character = builder.GetCharacter();
    assert(character->name == "Alice");
    std::cout << "Builder tests have passed\n";
}

void TestPrototype() {
    WarriorNPC npc;
    npc.hp = 50;
    npc.attackPower = 10;
    npc.name = "Bob";
    npc.characterClass = WARRIOR;
    auto npc2 = npc.Clone();
    assert(npc.name == npc2->name);
    std::cout << "Prototype tests have passed\n";
}

int main(int argc, char* argv[])
{
    TestSingleton();
    TestFactoryMethod();
    TestAbstractFactory();
    TestBuilder();
    TestPrototype();
    return 0;
}
