#pragma once
#include <memory>
#include <string>

class Weapon {
public:
    virtual ~Weapon() = default;
    virtual std::string GetName() = 0;
};

class Sword : public Weapon {
public:
    std::string GetName() override;
};

class Staff : public Weapon {
public:
    std::string GetName() override;
};

class OffhandItem {
public:
    virtual ~OffhandItem() = default;
    virtual std::string GetName() = 0;
};

class Shield : public OffhandItem {
public:
    std::string GetName() override;
};

class TomeOfMagic : public OffhandItem {
public:
    std::string GetName() override;
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<Weapon> CreateWeapon() = 0;
    virtual std::unique_ptr<OffhandItem> CreateOffHandItem() = 0;
};

class WarriorItemFactory : public AbstractFactory {
public:    
    std::unique_ptr<Weapon> CreateWeapon() override;
    std::unique_ptr<OffhandItem> CreateOffHandItem() override;
};

class MageItemFactory : public AbstractFactory {
public:    
    std::unique_ptr<Weapon> CreateWeapon() override;
    std::unique_ptr<OffhandItem> CreateOffHandItem() override;
};
