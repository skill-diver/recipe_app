

#ifndef GROUP23_INGREDIENTINVENTORY_H
#define GROUP23_INGREDIENTINVENTORY_H
#include <string>
#include <unordered_map>

using namespace std;

class IngredientInventory {

private:
    unordered_map<string, int> ingredients;

public:
    IngredientInventory(unordered_map<std::string, int> new_ingredients);
    int get_ingredient_amount(string ingredient_id);
    void set_ingredient_amount(string ingredient_id, int amount);
    unordered_map<string, int> get_all_inventory();
};


#endif //GROUP23_INGREDIENTINVENTORY_H
