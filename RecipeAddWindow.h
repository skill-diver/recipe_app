
#ifndef GROUP23_RECIPEADDWINDOW_H
#define GROUP23_RECIPEADDWINDOW_H
#include "DataBase.h"
#include "main.h"
#include <vector>

class RecipeAddWindow : public QMainWindow{
    Q_OBJECT
private:
    DataBase *DB;
    recipe *rec;
    QWidget *RecipeAddWindowWidget;
    QVBoxLayout *RecipeAddLayout;
    QLineEdit *RecipeName;
    QLineEdit *RecipeType;
    QLineEdit *RecipeDuration;
    QGroupBox *IngredientList;
    QGroupBox *KitchenwareList;
    QGroupBox *ProcedureList;
    QGroupBox *Body;
    QVBoxLayout *BodyLayout;
    QScrollArea *scroll;


    std::unordered_map<QComboBox*, QLineEdit*> ingredients_map;
    std::unordered_map<QComboBox*, QLineEdit*> kitchenware_map;
    std::unordered_map<QLineEdit*, QTextEdit*> procedure_map;

    void RecipeAddHeader();
    void RecipeAddRecipeName();
    void RecipeAddTypeAndDuration();

    void RecipeAddIngredient();
    QGroupBox *RecipeAddIngredientRow();

    void RecipeAddKitchenware();
    QGroupBox *RecipeAddKitchenwareRow();

    void RecipeAddProcedure();
    QGroupBox *RecipeAddProcedureRow();

    void closeEvent(QCloseEvent *bar);
private slots:
    void RecipeNewIngredientRow();
    void RecipeDeleteIngredientRow();

    void RecipeNewKitchenwareRow();
    void RecipeDeleteKitchenwareRow();

    void RecipeNewProcedureRow();
    void RecipeDeleteProcedureRow();

    void RecipeNewSubmit();
public:
    RecipeAddWindow(DataBase *db);
    ~RecipeAddWindow();
    void WindowShow();
    void WindowClose();

};


#endif //GROUP23_RECIPEADDWINDOW_H
