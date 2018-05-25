//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CINVENTORY_H
#define SEMESTRAL_WORK_CINVENTORY_H


class CInventory {
public:
    CInventory() : m_Inventory() {}
    void getHealing();
    void getHaste();
    void getInvulnerability();
    bool useHealing();
    bool useHaste();
    bool useInvulnerability();

private:
    unsigned m_Inventory[3];
};


#endif //SEMESTRAL_WORK_CINVENTORY_H
