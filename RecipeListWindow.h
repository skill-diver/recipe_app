#ifndef GROUP23_RECIPELISTWINDOW_H
#define GROUP23_RECIPELISTWINDOW_H
#include "DataBase.h"
#include "main.h"
#include "RecipeListWindow.h"
#include <vector>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
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
#include <QCloseEvent>
#include <QScrollArea>
#include "main.h"

class RecipeListWindow : public QMainWindow {
    Q_OBJECT
private:
    QPushButton* m_button = new QPushButton();
    QLabel* label = new QLabel();
    DataBase* DB;
    recipe* rec;
    QLineEdit* text = new QLineEdit();
    QVBoxLayout* MainLayout  = new QVBoxLayout();
    QWidget* Recipe_List_Window = new QWidget();
    QGroupBox* NavBox = new QGroupBox();
    QGridLayout* NavLayout = new QGridLayout();
    QGroupBox* searchBox = new QGroupBox();
    QHBoxLayout* SerchLayout = new QHBoxLayout();
    QGridLayout* MainListLayout = new QGridLayout();
    QScrollArea* MainBodyScroll = new QScrollArea();
    QGroupBox* MainList = new QGroupBox();
    void handleButton();
    void handleBackButton();
    void handleAddButton();

    void RecipeListWindowNav();
    void RecipeListWindowSerchBar();
    void RecipeListWindowNavBody(); 
    void RecipeList();
private slots:
    void handleInventoryButton();

public:
    RecipeListWindow(DataBase* db);
    ~RecipeListWindow();
    void WindowShow();
    void WindowHide();
};


#endif //GROUP23_RECIPELISTWINDOW_H