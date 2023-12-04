
#include "IngredientInventory.h"
#include <string>
#include <unordered_map>

using namespace std;

IngredientInventory::IngredientInventory(std::unordered_map<std::string, int> new_ingredients){

    ingredients = new_ingredients;

}

int IngredientInventory::get_ingredient_amount(std::string ingredient_id){

    return ingredients.at(ingredient_id);

}

void IngredientInventory::set_ingredient_amount(string ingredient_id, int amountP){

    ingredients[ingredient_id] = amountP;

}

unordered_map<string, int> IngredientInventory::get_all_inventory() {
    return ingredients;
}
