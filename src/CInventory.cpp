//
// Created by alexz on 5/6/18.
//

#include "CInventory.h"

void CInventory::getHealing() {
    m_Inventory[0]++;
}

void CInventory::getHaste() {
    m_Inventory[2]++;
}

void CInventory::getDD() {
    m_Inventory[1]++;
}

bool CInventory::useHealing() {
    if (m_Inventory[0] > 0){
        m_Inventory[0]--;
        return true;
    }
    return false;
}

bool CInventory::useHaste() {
    if (m_Inventory[2] > 0){
        m_Inventory[2]--;
        return true;
    }
    return false;
}

bool CInventory::useDD() {
    if (m_Inventory[1] > 0){
        m_Inventory[1]--;
        return true;
    }
    return false;
}

void CInventory::init(int heal, int haste, int dd) {
    m_Inventory[0] = heal;
    m_Inventory[1] = dd;
    m_Inventory[2] = haste;

}

std::ostream &operator<<(std::ostream &os, const CInventory &inv) {
    os << "Heal:" << inv.m_Inventory[0] << "|DD"
            ":" << inv.m_Inventory[1] << "|Haste:" << inv.m_Inventory[2] << "\n";
    return os;
}

std::string CInventory::save2String() const {
    return     std::to_string(m_Inventory[0]) + " "  + std::to_string(m_Inventory[1]) + " "
               + std::to_string(m_Inventory[2]);
}
