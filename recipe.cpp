#include "recipe.h"


recipe::recipe(std::string new_recipe_id, std::string new_recipe_name, std::string new_cuisine,  int new_time_minutes,
               std::unordered_map<std::string,int> new_ingredients,
               std::unordered_map<std::string, int> new_kitchenware, std::unordered_map<std::string, std::vector<std::string>> new_procedure){
    recipe_id = new_recipe_id;
    recipe_name = new_recipe_name;
    time_minutes = new_time_minutes;
    ingredients = new_ingredients;
    kitchenware = new_kitchenware;
    procedure = new_procedure;
    cuisine_type = new_cuisine;
}

recipe::~recipe(){

}
std::string recipe::get_recipe_id(){
    return recipe_id;
}
void recipe::set_recipe_id(int new_recipe_id){
    recipe_id = new_recipe_id;
}
std::string recipe::get_recipe_name(){
    return recipe_name;
}
void recipe::set_recipe_name(std::string new_recipe_name){
    recipe_name = new_recipe_name;
}
int recipe::get_time_minutes(){
    return time_minutes;
}
void recipe::set_time_minutes(int new_time_minutes){
    time_minutes = new_time_minutes;
}
std::string recipe::get_cuisine_type(){
    return cuisine_type;
}
void recipe::set_cuisine_type(std::string new_cuisine_type){
    cuisine_type = new_cuisine_type;
}
std::unordered_map<std::string, int> recipe::get_ingredients(){
    return ingredients;
}
void recipe::set_ingredients(std::unordered_map<std::string,int> new_ingredients){
    ingredients.insert(new_ingredients.begin(),new_ingredients.end());
}
void recipe::increment_ingredient_amount(std::string ingredient_id){
    ingredients[ingredient_id]++;
}
void recipe::decrement_ingredient_amount(std::string ingredient_id){
    ingredients[ingredient_id]--;
}
void recipe::set_ingredient_amount(std::string ingredient_id, int amount){
    ingredients[ingredient_id] = amount;
}
std::unordered_map<std::string, int> recipe::get_kitchenware(){
    return kitchenware;
}
void recipe::set_kitchenware(std::unordered_map<std::string,int> new_kitchenware){
    kitchenware.insert(new_kitchenware.begin(),new_kitchenware.end());
}
void recipe::increment_kitchenware_amount(std::string kitchenware_id){
    kitchenware[kitchenware_id]++;
}
void recipe::decrement_kitchenware_amount(std::string kitchenware_id){
    kitchenware[kitchenware_id]--;
}
void recipe::set_kitchenware_amount(std::string kitchenware_id, int amount){
    kitchenware[kitchenware_id] = amount;
}
void recipe::set_procedure(std::unordered_map<std::string, std::vector<std::string>> new_procedures){
    procedure = new_procedures;
}
std::unordered_map<std::string, std::vector<std::string>> recipe::get_procedure() {
    return procedure;
}
