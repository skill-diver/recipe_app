

#ifndef GROUP23_INGREDIENTINVENTORYWINDOW_H
#define GROUP23_INGREDIENTINVENTORYWINDOW_H
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
#include <QScrollArea>
#include "IngredientInventory.h"
#include "DataBase.h"
#include "IngredientDetail.h"
using namespace std;

class IngredientInventoryWindow : public QMainWindow{
Q_OBJECT
private:
    DataBase *DataB;
    QWidget *IngredientInventoryW = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QGridLayout *InventoryLayout = new QGridLayout();
    QGridLayout *TitleLayout = new QGridLayout();
    QGroupBox *Title = new QGroupBox();
    QGroupBox *Main = new QGroupBox();
    QScrollArea *MainBodyScroll = new QScrollArea();
    void setTitle();
    void setMain();
    void CreateInventoryButton(string IngredientID);

    private slots:
        void LinkDetailWindow();
        void LinkAddWindow();
        void OpenMainMenu();
        void widgetDestroyed(QObject * q);



public:
    IngredientInventoryWindow(DataBase *DataBp);
    ~IngredientInventoryWindow();
};


#endif //GROUP23_INGREDIENTINVENTORYWINDOW_H
