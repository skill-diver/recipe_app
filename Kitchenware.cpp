
#include "Kitchenware.h"
#include <string>

using namespace std;

Kitchenware::Kitchenware(string kitchenware_idP, string kitchenware_nameP) {

    kitchenware_id = kitchenware_idP;
    kitchenware_name = kitchenware_nameP;

}

string Kitchenware::get_kitchenware_id(){
    return kitchenware_id;
}

void Kitchenware::set_kitchenware_id(string kitchenware_idP) {
    kitchenware_id = kitchenware_idP;
}

string Kitchenware::get_kitchenware_name(){
    return kitchenware_name;
}

void Kitchenware::set_kitchenware_name(string new_kitchenware_name) {
    kitchenware_name = new_kitchenware_name;
}