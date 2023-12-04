
#ifndef GROUP23_KitchenWINDOW_H
#define GROUP23_KitchenWINDOW_H
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
#include <QScrollArea>
#include "main.h"
#include <QMessageBox>





class KitchenWindow : public QMainWindow{
Q_OBJECT
private:

    KitchenwareInventory *kit;
    QWidget *Kitchen_Window = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QGroupBox *Nav = new QGroupBox();
    QGridLayout *NavLayout = new QGridLayout();
    QGroupBox *MainBody = new QGroupBox;
    QGridLayout *MainBodyLayout = new QGridLayout();
    DataBase *DB;
    QScrollArea *MainBodyScroll = new QScrollArea();

//    void KitchenAddWindow(DataBase *db);
//    void KitchenEditWindow(KitchenwareInventory *kit,DataBase *DB);

public slots:
    void KitchenWindowNav();
    void KitchenWindowNavBody();
    void KitchenWindowMainBody();
    void KitchenKitchenwareList();
    void handleBackButton();
    void handleAddButton();
    void handleInventoryButton();


public:
    KitchenWindow(KitchenwareInventory *Kitchen, DataBase *db);
    ~KitchenWindow();
    void WindowShow();
    void WindowHide();
};


#endif //GROUP23_KitchenWINDOW_H