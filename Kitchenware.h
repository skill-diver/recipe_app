
#include <string>

#ifndef GROUP23_KITCHENWARE_H
#define GROUP23_KITCHENWARE_H

using namespace std;

class Kitchenware {
private:
    string kitchenware_id;
    string kitchenware_name;

public:
    Kitchenware(string kitchenware_idP, string kitchenware_nameP);
    string get_kitchenware_id();
    void set_kitchenware_id(string kitchenware_idP);
    string get_kitchenware_name();
    void set_kitchenware_name(string new_kitchenware_name);

};


#endif //CS3307_GROUP_KITCHENWARE_H
