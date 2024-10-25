#include "NPC.h"

std::unique_ptr<NPC> WarriorNPC::Clone() {
    WarriorNPC newNPC;
    newNPC.hp = hp;
    newNPC.characterClass = characterClass;
    newNPC.attackPower = attackPower;
    newNPC.name = name;
    return std::make_unique<WarriorNPC>(newNPC);
}
