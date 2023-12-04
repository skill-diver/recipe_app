

#include "KitchenwareInventory.h"

KitchenwareInventory::KitchenwareInventory(std::unordered_map<std::string, int> kitchenwareInventory) {
    this->kitchenware = kitchenwareInventory;
}

KitchenwareInventory::~KitchenwareInventory() {

}

int KitchenwareInventory::get_kitchenware_amount(std::string kitchenware_id) {
    int result;
    try{
        result = this->kitchenware.at(kitchenware_id);
    } catch (std::out_of_range &e){
        result = -1;
    }
    return result;
}

void KitchenwareInventory::set_kitchenware_amount(std::string kitchenware_id, int amount) {
    this->kitchenware[kitchenware_id] = amount;
}

std::unordered_map<std::string, int> KitchenwareInventory::get_all_inventory() {
    return this->kitchenware;
}
