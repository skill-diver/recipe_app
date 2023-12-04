
#ifndef GROUP23_INGREDIENTDETAIL_H
#define GROUP23_INGREDIENTDETAIL_H
#include <QPushButton>
#include <QGridLayout>
#include <QStackedLayout>
#include <QLabel>
#include <QTextBlock>
#include <QLineEdit>
#include <QObject>
#include <QMainWindow>
#include <QTextEdit>
#include <QGroupBox>
#include <QListWidget>
#include <QScrollBar>
#include <QColor>
#include <string>
#include <QStyle>
#include <QFont>
#include <regex>
#include "Ingredient.h"
#include "DataBase.h"
#include "main.h"
#include "IngredientInventory.h"

class IngredientDetail : QMainWindow{
Q_OBJECT

private:
    string IngID;
    Ingredient *Ing;
    unordered_map<string, int> IngInv;
    QWidget *IngredientDetailW = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QGroupBox *Nav = new QGroupBox();
    QGridLayout *NavLayout = new QGridLayout();
    QGroupBox *MainBody = new QGroupBox;
    QVBoxLayout *MainBodyLayout = new QVBoxLayout();
    DataBase *DB;
    QScrollArea *MainBodyScroll = new QScrollArea();
    QLabel *FeedBack = new QLabel();
    QLineEdit *UpdateTextBox = new QLineEdit();
    QLabel *IngAmount = new QLabel();

    void IngredientDetailNav();
    void IngredientDetailNavBody();
    void IngredientDetailMainBody();
    void IngredientAmount();
    void IngredientNutrition();
    void IngredientUpdate();
    bool isNumber(const string& str);

private slots:
    void UpdateHandle();

public:
    IngredientDetail(string IngIDp, DataBase *DBp);

    ~IngredientDetail();


};


#endif //GROUP23_INGREDIENTDETAIL_H
