
#ifndef GROUP23_RECIPEWINDOW_H
#define GROUP23_RECIPEWINDOW_H
#include "main.h"
#include "RecipeListWindow.h"
#include "QCloseEvent"

class RecipeWindow : public QMainWindow{
Q_OBJECT
private:
    QWidget *prevWindow;
    recipe *rec;
    QWidget *Recipe_Window = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QGroupBox *Nav = new QGroupBox();
    QGridLayout *NavLayout = new QGridLayout();
    QGroupBox *MainBody = new QGroupBox;
    QVBoxLayout *MainBodyLayout = new QVBoxLayout();
    DataBase *DB;
    QScrollArea *MainBodyScroll = new QScrollArea();
    void RecipeWindowNav();
    void RecipeWindowNavBody();
    void RecipeWindowMainBody();
    void RecipeInfo();
    void RecipeIngredientList();
    void RecipeKitchenwareList();
    void RecipeProcedure();

private slots:
    void Back();
protected:
    void closeEvent(QCloseEvent *event);



public:
    RecipeWindow(recipe *Recipe, DataBase *db, QWidget *recipeListWindow);
    ~RecipeWindow();
    void WindowShow();
    void WindowClose();
};


#endif //GROUP23_RECIPEWINDOW_H
