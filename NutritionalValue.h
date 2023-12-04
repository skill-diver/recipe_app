
#ifndef GROUP23_NUTRITIONALVALUE_H
#define GROUP23_NUTRITIONALVALUE_H
#include <unordered_map>
#include <stdexcept>
class NutritionalValue {
private:
    int calories;
    double totalFat;
    double sodium;
    double totalCarbs;
    double protein;
    std::unordered_map<std::string, double> otherNutritionalValues;
public:
    NutritionalValue(int calories, double totalFat, double sodium, double totalCarbs, double protein,
                     std::unordered_map<std::string, double> otherNutritionalValues);
    ~NutritionalValue();

    int getCalories();
    double getTotalFat();
    double getSodium();
    double getTotalCarbs();
    double getProtein();
    double getOtherNutritionalValue(std::string nutrientName);
    std::string getAllContents();

    void setCalories(int calories);
    void setTotalFat(double totalFat);
    void setSodium(double sodium);
    void setTotalCarbs(double totalCarbs);
    void setProtein(double protein);
    void addOtherNutritionalValue(std::string nutrientName, double nutrientAmount);
};

#endif //GROUP23_NUTRITIONALVALUE_H