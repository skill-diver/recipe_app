/** 
 * @class KitchenEditWindow(DataBase *DBp, KitchenwareInventory *Kitp). 
 * @brief user click button to see and edit the amount of the kitchenwareInventory
 */
#include "KitchenEditWindow.h"

#include <utility>
using namespace std;


/** 
 * @brief user click button to see and edit the amount of the kitchenwareInventory
 * @param KitIDp kitchenware name
 * @param DBp database pointer in the main to call kitchenware inventory methods
 * @param Kitp kitchewareInventory object
 */
KitchenEditWindow::KitchenEditWindow(string KitIDp, DataBase *DBp, KitchenwareInventory *Kitp){
    KitID = std::move(KitIDp);
    DB = DBp;
    Kit = Kitp;
    KitInv = DB->getKitchenWareInventory();
    MainLayout->setSpacing(0);
    KitchenEditWindowW->setWindowTitle("Kitchenware Details");
    KitchenEditWindowW->setFixedSize(800, 600);
    KitchenEditWindowW->setLayout(MainLayout);
    KitchenEditWindowW->setStyleSheet("QWidget {background-color: #FFFFFF }");
    MainLayout->setMargin(0);

    KitchenEditWindowNav();
    KitchenwareInventoryUpdate();
    KitchenEditWindowMainBody();
    KitchenEditWindowW->show();


};
/** 
 * @brief set title lay out of window
 */
void KitchenEditWindow::KitchenEditWindowNav(){

    Nav->setLayout(NavLayout);
    Nav->setFixedHeight(90);
    Nav->setStyleSheet(
            "QGroupBox { background-color: #C37000; padding: 0 64px; } "
            "QLabel { font-size: 40px; font-weight: bold; background-color: transparent;} "
            "QPushButton { font-size: 20px; background-color: transparent; color: white;} ");
    KitchenEditWindowNavBody();
    MainLayout->addWidget(Nav);
    MainLayout->addWidget(MainBodyScroll);

};
/** 
 * @brief set title name of the window
 */
void KitchenEditWindow::KitchenEditWindowNavBody(){
    // Nav Title
    auto *NavTitle = new QLabel(QString::fromStdString(DB->getKitchenwareByID(KitID)->get_kitchenware_name()));
    // Add Widget
    NavLayout->addWidget(NavTitle, 0, 1, 1, 1, {Qt::AlignCenter});
}
/** 
 * @brief set mainbody of the window
 */
void KitchenEditWindow::KitchenEditWindowMainBody(){

    MainBody->setStyleSheet("QGroupBox { background-color: white; border: none; }");

    KitchenwareAmount();

    MainBodyLayout->setMargin(0);
    MainLayout->addStretch();
    MainBody->setLayout(MainBodyLayout);
    MainBody->setStyleSheet("color: #5F3600");


    MainBodyScroll->setStyleSheet("QScrollArea { border: none }");
    MainBodyScroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    MainBodyScroll->setWidgetResizable(true);
    MainBodyScroll->setMinimumHeight(KitchenEditWindowW->minimumHeight() - Nav->minimumHeight() );
    MainBodyScroll->setWidget(MainBody);

}
/** 
 * @brief show current kitchenware inventory amount
 */
void KitchenEditWindow::KitchenwareAmount(){
    std::string KitName = DB->getKitchenwareByID(KitID)->get_kitchenware_name();
    int amount = KitInv.at(KitID);
    auto *setAmountButton = new QPushButton("Edit");
    //connect(setAmountButton,SIGNAL(&QPushButton::released),this,SLOT(setAmount(KitName,amount)));
    string amountStr = to_string(amount);
    auto *AmountLayout = new QVBoxLayout();
    auto *AmountBox = new QGroupBox();
    auto *YouHave = new QLabel("You have");
    KitAmount = new QLabel(QString::fromStdString(amountStr));
    KitAmount->setStyleSheet("font-size: 60px; font-weight: bold");
    auto *KitInYourInventory = new QLabel(QString::fromStdString(KitName) + " in you inventory");
   
    AmountBox->setLayout(AmountLayout);

    AmountLayout->addWidget(YouHave);

    AmountLayout->addWidget(KitAmount);
    AmountLayout->addWidget(KitInYourInventory);
    AmountLayout->addStretch();
   


    AmountBox->setStyleSheet("QLabel{color: #5F3600; background-color: white; font-size: 20px} QGroupBox{background-color: white; border: 0}");
    MainBodyLayout->addWidget(AmountBox);//set amount box layout
    
};
/** 
 * @brief allow user click button to edit the current amount
 */
void KitchenEditWindow::KitchenwareInventoryUpdate(){

    auto *UpdateBox = new QGroupBox();
    auto *UpdateLayout = new QVBoxLayout();
    auto *UpdateMessage = new QLabel("Please Enter New Amount: ");

    auto *UpdateButton = new QPushButton("Update");
    UpdateTextBox->setPlaceholderText("Input here...");
    UpdateButton->setObjectName(UpdateTextBox->text());

    std::cout << UpdateTextBox->text().toStdString() << std::endl;
    connect(UpdateButton, SIGNAL(clicked()), SLOT(UpdateHandle()));

    UpdateBox->setLayout(UpdateLayout);
    UpdateBox->setStyleSheet("QPushButton{background-color: #c37000; color: white; border-radius: 10px; padding: 16px} QLabel{color: #5F3600; background-color: white} QGroupBox{background-color: white; border: 0} QLineEdit{color: #5F3600}");
    UpdateLayout->addWidget(UpdateMessage);
    UpdateLayout->addWidget(UpdateTextBox);
    UpdateLayout->addWidget(UpdateButton);
    UpdateLayout->addWidget(FeedBack);


    MainLayout->addWidget(UpdateBox);

}
/** 
 * @brief button method for update the amount of currect kitchenware inventory
 */
void KitchenEditWindow::UpdateHandle(){
    string input = "";
    std::cout << input << std::endl;
    int input_number;
    try{
        input_number = stoi(UpdateTextBox->text().toStdString());
        if (input_number>100000){
            std::cout << "Input too large" << std::endl;
            FeedBack->setText("Input too large");
        }
        else{
            if (DB->addKitchenwareInventory(KitID, input_number)){
                KitAmount->setText(QString::fromStdString(to_string(input_number)));
                std::cout << "Input successful" << std::endl;
                FeedBack->setText("Input successful");
            }

        }

    }catch(exception &e){
        FeedBack->setText("This is not an int, please input and int");
        std::cout << "This is not an int, please input and int" << std::endl;
    }

}

/** 
 * @brief show this window
 */
void KitchenEditWindow::WindowShow(){
    this->KitchenEditWindowW->show();
}
/** 
 * @brief hide this window
 */
void KitchenEditWindow::WindowHide(){
    this->KitchenEditWindowW->hide();
}

KitchenEditWindow::~KitchenEditWindow(){};