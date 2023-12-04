#ifndef GROUP23_KitchenADDWINDOW_H
#define GROUP23_KitchenADDWINDOW_H
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
#include <QComboBox>
#include <QMessageBox>
#include "DataBase.h"
#include "main.h"
#include <vector>

class KitchenAddWindow : public QMainWindow{
Q_OBJECT
private:
    QWidget *previouswindow;
    DataBase *DB;
    KitchenwareInventory *kit;
    QWidget *KitchenAddWindowWidget;
    QVBoxLayout *KitchenAddLayout;
    QGroupBox *KitchenwareList;
    QGroupBox *Body;
    QVBoxLayout *BodyLayout;
    QScrollArea *scroll;

    std::unordered_map<QComboBox*, QLineEdit*> kitchenwares_map;

    void KitchenSelectKitchenware();
    QGroupBox *KitchenwareAddRow();

private slots:

    void KitchenwareNewRow();
    void KitchenDeletekitchenwareRow();
    void KitchenNewSubmit();
public:
    KitchenAddWindow(DataBase *db, QWidget *prev);
    ~KitchenAddWindow();
    void WindowShow();
    void WindowHide();
};


#endif //GROUP23_KitchenADDWINDOW_H