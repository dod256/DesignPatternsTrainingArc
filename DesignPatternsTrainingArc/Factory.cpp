#include "Factory.h"

std::string HealthPowerUp::GetName() {
    return "Health Power Up";
}

std::string HealthPowerUp::GetDescription() {
    return "Heals character.";
}

std::string AmmoPowerUp::GetName() {
    return "Ammo Power Up";
}

std::string AmmoPowerUp::GetDescription() {
    return "Refills ammo.";
}

std::unique_ptr<PowerUp> Factory::FactoryMethod(const PowerUpType type) {
    switch(type) {
    case HEALTH:
        return std::make_unique<HealthPowerUp>();
    case AMMO:
        return std::make_unique<AmmoPowerUp>();
    default:
        return nullptr;
    }
}
