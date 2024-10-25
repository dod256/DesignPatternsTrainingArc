#pragma once
#include <string>

#include "CharacterBuilder.h"

class NPC {
public:
    virtual ~NPC() = default;
    NPC() = default;
    virtual std::unique_ptr<NPC> Clone() = 0;

    std::string name;
    CharacterClass characterClass;
    float attackPower;
    float hp;
};

class WarriorNPC : public NPC{
public:
    ~WarriorNPC() override = default;
    std::unique_ptr<NPC> Clone() override;
};
