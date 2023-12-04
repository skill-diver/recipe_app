
#ifndef GROUP23_INGREDIENT_H
#define GROUP23_INGREDIENT_H
#include <string>
#include <unordered_map>
#include "NutritionalValue.h"

using namespace std;

class Ingredient {

private:
    string ingredient_id;
    string ingredient_name;
    string best_storing_duration;
    NutritionalValue *NutritionValue;
public:
    Ingredient(string ingredient_nameP, string best_storing_durationP,
               NutritionalValue *nutrition_value, string ingredient_id);
    string get_ingredient_name();
    string get_ingredient_id();
    string get_best_storing_duration();
    int get_nutritional_value(string item_name);
    int get_other_nutritional_value(string item_name);
    void set_ingredient_name(string name);
    void set_best_storing_name(int day);
    void set_nutritional_value(string item_name, int nutritional_value);
    void set_other_nutritional_value(string item_name, int nutritional_value);
};




    #endif //GROUP23_INGREDIENT_H
