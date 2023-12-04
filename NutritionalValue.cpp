
#include <unordered_map>
#include <string>
#include "NutritionalValue.h"

NutritionalValue::NutritionalValue(int calories, double totalFat, double sodium, double totalCarbs, double protein,
                 std::unordered_map<std::string, double> otherNutritionalValues) {
    this->calories = calories;
    this->totalFat = double((int)(totalFat * 100))/ 100;
    this->sodium = double((int)(sodium * 100)) / 100;
    this->totalCarbs = double((int)(totalCarbs * 100)) / 100;
    this->protein = double((int)(protein * 100)) / 100;
    this->otherNutritionalValues = otherNutritionalValues;
}
NutritionalValue::~NutritionalValue() = default;

int NutritionalValue::getCalories() {
    return this->calories;
}
double NutritionalValue::getTotalFat() {
    return this->totalFat;
}
double NutritionalValue::getSodium() {
    return this->sodium;
}
double NutritionalValue::getTotalCarbs() {
    return this->totalCarbs;
}
double NutritionalValue::getProtein() {
    return this->protein;
}
double NutritionalValue::getOtherNutritionalValue(std::string nutrientName) {
    double result;
    try {
        result = this->otherNutritionalValues.at(nutrientName);
    } catch (std::out_of_range &e) {
        result = -1.0;
    }
    return result;
}

void NutritionalValue::setCalories(int calories) {
    this->calories = calories;
}

void NutritionalValue::setTotalFat(double totalFat) {
    this->totalFat = double((int)(totalFat * 100))/ 100;
}

void NutritionalValue::setSodium(double sodium) {
    this->sodium = double((int)(sodium * 100))/ 100;
}

void NutritionalValue::setTotalCarbs(double totalCarbs) {
    this->totalCarbs = double((int)(totalCarbs * 100))/ 100;
}

void NutritionalValue::setProtein(double protein) {
    this->protein = double((int)(protein * 100))/ 100;
}

void NutritionalValue::addOtherNutritionalValue(std::string nutrientName, double nutrientAmount) {
    otherNutritionalValues[nutrientName] = double((int)(nutrientAmount * 100))/ 100;
}

std::string NutritionalValue::getAllContents() {
    std::string returnString;
    returnString.append("Calories: \t\t" + std::to_string(getCalories()) + "\nTotal Fat: \t\t" +
    std::to_string(getTotalFat()) + "\nSodium: \t\t" + std::to_string(getSodium()) + "\nTotal Carbs: \t" +
    std::to_string(getTotalCarbs()) + "\nProtein: \t\t" + std::to_string(getProtein()) + "\n");

    for (auto const &pair: otherNutritionalValues) {
        returnString.append(pair.first + ": \t\t" + std::to_string(pair.second) + "\n");
    }
    return returnString;
}

