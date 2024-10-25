#pragma once
#include <memory>
#include <string>

enum PowerUpType {
    EMPTY,
    HEALTH,
    AMMO,
    ARMOR
};

class PowerUp {
public:
    PowerUpType GetType() const { return type; }
    virtual ~PowerUp() = default;
    virtual std::string GetName() = 0;
    virtual std::string GetDescription() = 0;
private:
    PowerUpType type = EMPTY;
};

class HealthPowerUp : public PowerUp {
    std::string GetName() override;
    std::string GetDescription() override;
};

class AmmoPowerUp : public PowerUp {
    std::string GetName() override;
    std::string GetDescription() override;
};

class FactoryMethodShowcase {
public:
    std::unique_ptr<PowerUp> FactoryMethod(PowerUpType type);
};
