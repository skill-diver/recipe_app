/** 
 * @class KitchenAddWindow(DataBase *db, QWidget* prev). 
 * @brief When users click add right top button "Add" button in KitchenInventory window, this window will show.User select kitchenware and amount of it to add. then new kitchenware will be added in kitchenwareInventory.
 */
#include "KitchenAddWindow.h"
/** 
 * @param db database pointer used to call kithchenware methods
 * @param prev is previous window.
 * @brief set the main layout, button, schroll bar then add subcontent into it 
 */
KitchenAddWindow::KitchenAddWindow(DataBase *db, QWidget* prev) {
    previouswindow = prev;
    DB = db;
    this->scroll = new QScrollArea();
    this->KitchenAddLayout = new QVBoxLayout();
    this->KitchenAddWindowWidget = new QWidget();
    this->KitchenAddWindowWidget->setWindowTitle("Add Kitchenware");
    this->KitchenAddWindowWidget->setFixedSize(600, 300);
    this->KitchenAddWindowWidget->setStyleSheet("background-color: #ffffff");
    this->Body = new QGroupBox();
    this->BodyLayout = new QVBoxLayout();


    KitchenSelectKitchenware();

    auto *submitButton = new QPushButton("Add");
    submitButton->setStyleSheet("color: #FFFFFF; background-color: #C37000; padding: 20px 16px; border: 0; font-size: 16px;");
    submitButton->setCursor(QCursor(Qt::PointingHandCursor));
    QObject::connect(submitButton, SIGNAL(clicked()), this, SLOT(KitchenNewSubmit()));
    this->BodyLayout->addWidget(submitButton);

    this->KitchenAddLayout->setMargin(0);
    this->BodyLayout->addStretch();
    this->BodyLayout->setMargin(0);
    this->Body->setLayout(BodyLayout);
    this->KitchenAddLayout->addWidget(this->scroll);
    this->KitchenAddWindowWidget->setLayout(KitchenAddLayout);

    this->Body->setStyleSheet("QGroupBox { background-color: white; border: none; }");
    this->scroll->setStyleSheet("QScrollArea { border: none; background-color: white }");
    this->scroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    this->scroll->setWidgetResizable(true);
    this->scroll->setWidget(Body);
}

KitchenAddWindow::~KitchenAddWindow() {

}
 /** 
 
 * @brief show this window

 */
void KitchenAddWindow::WindowShow() {
    this->KitchenAddWindowWidget->show();
}
/** 
 * @brief Hide this window 
 */
void KitchenAddWindow::WindowHide() {
    this->KitchenAddWindowWidget->close();
}

/** 

 * @brief user select an kitchenware to add and show the options
 */
void KitchenAddWindow::KitchenSelectKitchenware() {
    KitchenwareList = new QGroupBox();
    auto *layout = new QVBoxLayout();
    auto *selectKitchenwareButton = new QPushButton("Select Kitchenware");
    KitchenwareList->setStyleSheet("margin: 0; padding: 0; background-color: white; border: 0");
    layout->setMargin(0);
    layout->setSpacing(8);
    layout->addWidget(this->KitchenwareAddRow());
    KitchenwareList->setLayout(layout);
    this->BodyLayout->addWidget(KitchenwareList);
    selectKitchenwareButton->setStyleSheet("color: #C37000; border: none; margin: 16px 32px; text-align: right; font-size: 16px");
    QObject::connect(selectKitchenwareButton, SIGNAL(clicked()),SLOT(KitchenwareNewRow()));
    this->BodyLayout->addWidget(selectKitchenwareButton);
}
/** 
 
 * @brief if user want to add multiple kitchenwares and amount, the new row will be created
 * @returns container include kitchenware, amount and button for deleting row
 */
QGroupBox *KitchenAddWindow::KitchenwareAddRow() {
    auto *deleteButton = new QPushButton("");

    deleteButton->setIcon(QIcon("assets/icons/delete.svg"));
    auto *kitchenware = new QComboBox();
    kitchenware->setStyleSheet("QComboBox { color: #5F3600; border: none; border-bottom: 1px solid #707070; padding: 0; font-size: 20px }");

    kitchenware->setMinimumWidth(KitchenAddWindowWidget->width()/2);
    std::vector<Kitchenware*> kit = DB->getAllKitchenware();
    kitchenware->addItem("Select an kitchenware", QVariant("0"));
    for (Kitchenware* i : kit){
        kitchenware->addItem(QString::fromStdString(i->get_kitchenware_name()), QVariant(QString::fromStdString(i->get_kitchenware_id())));
    }
    auto *amount = new QLineEdit();
    amount->setAttribute(Qt::WA_MacShowFocusRect, false);
    amount->setPlaceholderText("Amount");
    auto *container = new QGroupBox();
    container->setStyleSheet("QGroupBox{ background: white; padding: 0px 32px; border: none; } QLineEdit { color: #5F3600; border: none; border-bottom: 1px solid #707070; font-size: 20px}");
    auto *layout = new QHBoxLayout();
    layout->setMargin(0);
    layout->setSpacing(16);
    layout->addWidget(kitchenware);
    layout->addWidget(amount);
    layout->addWidget(deleteButton);
    container->setLayout(layout);
    this->kitchenwares_map[kitchenware] = amount;
    QObject::connect(deleteButton, SIGNAL(clicked()), SLOT(KitchenDeletekitchenwareRow()));
    return container;
}
/** 
 
 * @brief add the row into the kitchenware option list for user to select.
 
 */
void KitchenAddWindow::KitchenwareNewRow() {
    this->KitchenwareList->layout()->addWidget(this->KitchenwareAddRow());
}
/** 
 
 * @brief delete row if user want to delete.
 
 */
void KitchenAddWindow::KitchenDeletekitchenwareRow() {
    auto *msg = new QMessageBox();
    if (this->kitchenwares_map.size() > 1){
        msg->setText("Are you sure to delete this kitchenware?");
        msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg->setDefaultButton(QMessageBox::No);
        int ret = msg->exec();

        if (ret == QMessageBox::Yes){
            QWidget *w = qobject_cast<QWidget *>(sender()->parent());
            auto *tmp = (QComboBox*) w->layout()->itemAt(0)->widget();
            this->kitchenwares_map.erase(tmp);
            this->KitchenwareList->layout()->removeWidget(w);
        }
    }else{
        msg->setText("Deletion Error: Each Kithen required at least 1 kitchenware.");
        msg->exec();
    }


}
/** 
 
 * @brief user submit when finish adding kithenwares and their amount. if user set kitchenware and amount incorrectly it will prompt.
 
 */

void KitchenAddWindow::KitchenNewSubmit() {
    auto *msg = new QMessageBox();
    for (auto [key, val] : this->kitchenwares_map){
        if(key->currentData().toString().toStdString() == "0"){
            msg->setText("Oops! There are 1 or more kitchenware you haven't select.");
            msg->exec();
            return;
        }
        else if(val->text().isEmpty()){
            msg->setText("Oops! There are 1 or more kitchenware does not specified the amount.");
            msg->exec();
            return;
        }
        else{
            try{
                int amount = std::stoi(val->text().toStdString());
            } catch (exception &e) {
                msg->setText("Oops! One of the kitchenware amount is not an integer.");
                msg->exec();
                return;
            }
        }
    }
    // Finalizing the recipe
    std::unordered_map<std::string, int> kitchenware;
    for (auto [key, val] : this->kitchenwares_map){
        kitchenware[key->currentData().toString().toStdString()] = std::stoi(val->text().toStdString());

        //kit = new KitchenwareInventory(kitchenware[key->currentData().toString().toStdString()],);
        if (DB->addKitchenwareInventory(key->currentData().toString().toStdString(),val->text().toInt())){//
            msg->setText("Kitchenware Inventory Saved!");
            msg->exec();
            this->WindowHide();
            KitchenWindow *kit = new KitchenWindow(new KitchenwareInventory(DB->getKitchenWareInventory()), DB);
        }else{
            msg->setText("Oops! Kitchenware Inventory save failed!");
            msg->exec();
        }
    }
}