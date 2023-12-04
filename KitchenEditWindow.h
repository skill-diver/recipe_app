#ifndef GROUP23_KitchenEditWindow_H
#define GROUP23_KitchenEditWindow_H
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
#include "Ingredient.h"
#include "DataBase.h"
#include <QComboBox>
#include "main.h"
#include "IngredientInventory.h"

class KitchenEditWindow : QMainWindow{
Q_OBJECT

private:
    std::string KitID;
    KitchenwareInventory *Kit;
    unordered_map<string, int> KitInv;
    QWidget *KitchenEditWindowW = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QGroupBox *Nav = new QGroupBox();
    QGridLayout *NavLayout = new QGridLayout();
    QGroupBox *MainBody = new QGroupBox;
    QVBoxLayout *MainBodyLayout = new QVBoxLayout();
    DataBase *DB;
    QScrollArea *MainBodyScroll = new QScrollArea();
    QLineEdit *UpdateTextBox = new QLineEdit();
    QLabel *FeedBack = new QLabel();
    QLabel *KitAmount = new QLabel();
private slots:
    void KitchenEditWindowNav();
    void KitchenEditWindowNavBody();
    void KitchenEditWindowMainBody();
    void KitchenwareAmount();
    void KitchenwareInventoryUpdate();
    void UpdateHandle();

public:
    KitchenEditWindow(string KitIDp, DataBase *DBp, KitchenwareInventory *Kitp);
    ~KitchenEditWindow();
    void WindowShow();
    void WindowHide();
};


#endif //GROUP23_KitchenEditWindow_H