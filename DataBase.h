/**
 * Include Headings
 */
#ifndef GROUP23_DATABASE_H
#define GROUP23_DATABASE_H
#include <cstdio>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QDebug>
#include <iostream>
#include <unordered_map>
#include <nlohmann/json.hpp>



#include "Ingredient.h"
#include "Kitchenware.h"
#include "recipe.h"

/**
 * Using namespace for the json library
 */
using namespace nlohmann;

/**
 * @brief DataBase class is to use to connect to database
 */
class DataBase {
private:
    /**
     * Create a new QSqlDatabase object and connect it to the sqlite database
     */
    QSqlDatabase m_db;
    /**
     * Create a new QSqlQuery object to search in the database
     */
    QSqlQuery *search;

    std::vector<recipe*> filterRecipe(std::string field, std::string order);
public:
    DataBase();
    ~DataBase();
    std::vector<Ingredient*> getAllIngredient();
    std::vector<Kitchenware*> getAllKitchenware();
    std::vector<recipe*> getAllRecipe();
    std::vector<recipe*> searchRecipe(std::string search);
    std::vector<recipe*> filterRecipeNameASC();
    std::vector<recipe*> filterRecipeNameDESC();
    std::vector<recipe*> filterRecipeDurationASC();
    std::vector<recipe*> filterRecipeDurationDESC();
    std::unordered_map<std::string, int> getKitchenWareInventory();
    std::unordered_map<std::string, int> getIngredientInventory();


    Ingredient* getIngredientByID(const std::string& id);
    Kitchenware* getKitchenwareByID(const std::string& id);
    recipe* getRecipeByID(const std::string& ID);

    bool addIngredientInventory(const std::string& ingredient_id, int amount);
    bool addKitchenwareInventory(const std::string& kitchenware_id, int amount);
    bool updateRecipe(recipe* rec);
    bool addRecipe(recipe* rec);
};


#endif //GROUP23_DATABASE_H