

#include "Ingredient.h"
#include <string>
#include <unordered_map>

using namespace std;

Ingredient::Ingredient(string ingredient_nameP, string best_storing_durationP,
                       NutritionalValue *nutritionalValue, string ingredient_id) {
    this->ingredient_id = ingredient_id;
    this->best_storing_duration = best_storing_durationP;
    this->NutritionValue = nutritionalValue;
    this->ingredient_name = ingredient_nameP;

}

string Ingredient::get_ingredient_name(){
    return ingredient_name;
};

string Ingredient::get_best_storing_duration(){
    return best_storing_duration;
};

int Ingredient::get_nutritional_value(string item_name) {
    if (item_name == "Calories"){
        return this->NutritionValue->getCalories();
    }
    else if (item_name == "Total Fat"){
        return this->NutritionValue->getTotalFat();
    }
    else if (item_name == "Sodium"){
        return this->NutritionValue->getSodium();
    }
    else if (item_name == "Total Carbs"){
        return this->NutritionValue->getTotalCarbs();
    }
    else if (item_name == "Protein"){
        return this->NutritionValue->getProtein();
    }
    else{
        return -1;
    }
}

int Ingredient::get_other_nutritional_value(string item_name){
    return this->NutritionValue->getOtherNutritionalValue(item_name);
}

void Ingredient::set_ingredient_name(string name){
    ingredient_name = name;
}

void Ingredient::set_best_storing_name(int day) {
    best_storing_duration = day;
}

void Ingredient::set_nutritional_value(string item_name, int nutritional_value) {
    if (item_name == "Calories"){
        this->NutritionValue->setCalories(nutritional_value);
    }
    else if (item_name == "Total Fat"){
        this->NutritionValue->setTotalFat(nutritional_value);
    }
    else if (item_name == "Sodium"){
        this->NutritionValue->setSodium(nutritional_value);
    }
    else if (item_name == "Total Carbs"){
        this->NutritionValue->setTotalFat(nutritional_value);
    }
    else if (item_name == "Protein"){
        this->NutritionValue->setProtein(nutritional_value);
    }
}

void Ingredient::set_other_nutritional_value(string item_name, int nutritional_value) {
    this->NutritionValue->addOtherNutritionalValue(item_name, nutritional_value);
}

string Ingredient::get_ingredient_id() {
    return this->ingredient_id;
}
