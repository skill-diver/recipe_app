
#ifndef GROUP23_KITCHENWAREINVENTORY_H
#define GROUP23_KITCHENWAREINVENTORY_H
#include <unordered_map>
#include <string>
#include <stdexcept>

class KitchenwareInventory {
private:
    std::unordered_map <std::string, int>kitchenware;
public:
    KitchenwareInventory(std::unordered_map <std::string, int> kitchenwareInventory);
    ~KitchenwareInventory();
    int get_kitchenware_amount(std::string kitchenware_id);
    void set_kitchenware_amount(std::string kitchenware_id, int amount);
    std::unordered_map <std::string, int> get_all_inventory();
};


#endif //GROUP23_KITCHENWAREINVENTORY_H
