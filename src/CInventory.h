//
// Created by alexz on 5/6/18.
//

#ifndef SEMESTRAL_WORK_CINVENTORY_H
#define SEMESTRAL_WORK_CINVENTORY_H


#include <ostream>

class CInventory {
public:
    CInventory() : m_Inventory() {}
    ~CInventory() = default;
    void init (int heal, int haste, int inv);
    void getHealing();
    void getHaste();
    void getDD();
    bool useHealing();
    bool useHaste();
    bool useDD();
    friend std::ostream & operator << (std::ostream& os, const CInventory & inv);
    std::string save2String () const;
private:
    int m_Inventory[3];
};


#endif //SEMESTRAL_WORK_CINVENTORY_H
