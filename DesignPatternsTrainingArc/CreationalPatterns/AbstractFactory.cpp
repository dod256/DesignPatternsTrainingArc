#include "AbstractFactory.h"

std::string Sword::GetName() {
    return "Sword";
}

std::string Staff::GetName() {
    return "Staff";
}

std::string Shield::GetName() {
    return "Shield";
}

std::string TomeOfMagic::GetName() {
    return "Tome Of Magic";
}

std::unique_ptr<Weapon> WarriorItemFactory::CreateWeapon() {
    return std::make_unique<Sword>();
}

std::unique_ptr<OffhandItem> WarriorItemFactory::CreateOffHandItem() {
    return std::make_unique<Shield>();
}

std::unique_ptr<Weapon> MageItemFactory::CreateWeapon() {
    return std::make_unique<Staff>();
}

std::unique_ptr<OffhandItem> MageItemFactory::CreateOffHandItem() {
    return std::make_unique<TomeOfMagic>();
}
