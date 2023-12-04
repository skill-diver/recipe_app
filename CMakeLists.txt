cmake_minimum_required(VERSION 3.20)
project(group23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(Qt5_DIR "/usr/local/Cellar/qt@5/5.15.2/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)


include_directories(${CMAKE_CURRENT_LIST_DIR}/libs/json/single_include)


add_executable(group23 main.cpp NutritionalValue.cpp DataBase.cpp DataBase.h IngredientInventoryWindow.cpp IngredientInventoryWindow.h Ingredient.cpp Ingredient.h Kitchenware.cpp Kitchenware.h recipe.cpp recipe.h IngredientInventory.cpp IngredientInventory.h KitchenwareInventory.cpp KitchenwareInventory.h RecipeWindow.cpp RecipeWindow.h RecipeAddWindow.cpp RecipeAddWindow.h mainMenu.cpp mainMenu.h RecipeListWindow.cpp RecipeListWindow.h KitchenAddWindow.cpp KitchenAddWindow.h KitchenEditWindow.cpp KitchenEditWindow.h KitchenWindow.cpp KitchenWindow.h RecipeListWindow.cpp RecipeListWindow.h IngredientAdd.cpp IngredientAdd.h IngredientDetail.cpp IngredientDetail.h)
target_link_libraries(group23 Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql sqlite3 )
