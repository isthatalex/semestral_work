//
// Created by alexz on 5/6/18.
//

#include "CInventory.h"

void CInventory::getHealing() {
    m_Inventory[0]++;
}

void CInventory::getHaste() {
    m_Inventory[1]++;
}

void CInventory::getInvulnerability() {
    m_Inventory[2]++;
}

bool CInventory::useHealing() {
    if (m_Inventory[0] > 0){
        m_Inventory[0]--;
        return true;
    }
    return false;
}

bool CInventory::useHaste() {
    if (m_Inventory[1] > 0){
        m_Inventory[1]--;
        return true;
    }
    return false;
}

bool CInventory::useInvulnerability() {
    if (m_Inventory[2] > 0){
        m_Inventory[2]--;
        return true;
    }
    return false;
}
