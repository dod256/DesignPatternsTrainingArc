#pragma once
#include <cassert>
#include <string>

#include "AbstractFactory.h"

enum CharacterClass {
    WARRIOR,
    MAGE
};

class Character {
    friend class CharacterBuilder;
public:
    std::string name;
    CharacterClass characterClass;
    std::unique_ptr<Weapon> weapon;
    std::unique_ptr<OffhandItem> offhandItem;
protected:
    Character(std::string _name, CharacterClass _class, std::unique_ptr<Weapon> _weapon, std::unique_ptr<OffhandItem> _offhandItem) : name(std::move(
            _name)),
        characterClass(_class), weapon(std::move(_weapon)), offhandItem(std::move(_offhandItem)) {}
};

class CharacterBuilder {
public:
    void SetName(std::string value) {
        name = std::move(value);
    }

    void SetCharacterClass(CharacterClass value) {
        switch (value) {
        case WARRIOR: {
            characterClass = value;
            WarriorItemFactory factory;
            weapon = factory.CreateWeapon();
            offhandItem = factory.CreateOffHandItem();
            break;
        }
        case MAGE: {
            characterClass = value;
            MageItemFactory factory;
            weapon = factory.CreateWeapon();
            offhandItem = factory.CreateOffHandItem();
            break;
        }
        }
    }
    
    std::unique_ptr<Character> GetCharacter() {
            return std::unique_ptr<Character>(new Character(name, characterClass, std::move(weapon),
                                                std::move(offhandItem)));
    }

private:
    std::string name;
    CharacterClass characterClass;
    std::unique_ptr<Weapon> weapon;
    std::unique_ptr<OffhandItem> offhandItem;
};
