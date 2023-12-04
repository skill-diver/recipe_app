
#ifndef GROUP23_RECIPE_H
#define GROUP23_RECIPE_H
#include <iostream>
#include <vector>
#include <unordered_map>

class recipe
{
private:
    std::string recipe_name;
    std::string cuisine_type;
    std::unordered_map<std::string, int> ingredients;
    std::unordered_map<std::string, int> kitchenware;
    std::unordered_map<std::string, std::vector<std::string>> procedure;
    std::string recipe_id;
    int time_minutes;

public:
    recipe(std::string, std::string, std::string, int,std::unordered_map<std::string,int>,std::unordered_map<std::string,int>, std::unordered_map<std::string, std::vector<std::string>>);
    ~recipe();
    std::string get_recipe_id();
    void set_recipe_id(int);
    std::string get_recipe_name();
    void set_recipe_name(std::string);
    int get_time_minutes();
    void set_time_minutes(int);
    std::string get_cuisine_type();
    void set_cuisine_type(std::string);
    std::unordered_map<std::string, int> get_ingredients();
    void set_ingredients(std::unordered_map<std::string,int>);
    void increment_ingredient_amount(std::string );
    void decrement_ingredient_amount(std::string);
    void set_ingredient_amount(std::string, int);
    std::unordered_map<std::string, int> get_kitchenware();
    void set_kitchenware(std::unordered_map<std::string,int>);
    void increment_kitchenware_amount(std::string);
    void decrement_kitchenware_amount(std::string);
    void set_kitchenware_amount(std::string, int);
    void set_procedure(std::unordered_map<std::string, std::vector<std::string>>);
    std::unordered_map<std::string, std::vector<std::string>> get_procedure();
};


#endif //GROUP23_RECIPE_H
