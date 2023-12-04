#ifndef GROUP23_MAINMENU_H
#define GROUP23_MAINMENU_H

#include <iostream>
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QTime>
#include <Qtimer>
#include "main.h"
#include "DataBase.h"

class mainMenu : public QMainWindow {
    Q_OBJECT
public:
    mainMenu(DataBase *DB);
    ~mainMenu();
public slots:
    void HandleRecipeButtonPress();
    void HandleIngredientButtonPress();
    void HandleKitchenwareButtonPress();
private:
    DataBase *db;

    QWidget *window;
    QGridLayout *layout;

    QWidget *timeDateWidget;
    QLabel *currentDateLabel;
    QLabel *currentTimeLabel;

    QGridLayout *recipeLayout;
    QPushButton *recipeButton;
    QLabel *recipeLayoutTitle;
    QLabel *recipeLayoutText;

    QGridLayout *ingredientLayout;
    QPushButton *ingredientButton;
    QLabel *ingredientLayoutTitle;
    QLabel *ingredientLayoutText;

    QGridLayout *kitchenwareLayout;
    QPushButton *kitchenwareButton;
    QLabel *kitchenwareLayoutTitle;
    QLabel *kitchenwareLayoutText;
};

#endif //GROUP23_MAINMENU_H
