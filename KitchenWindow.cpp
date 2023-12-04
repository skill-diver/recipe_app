/** 
 * @class KitchenWindow(KitchenwareInventory *Kitchen, DataBase *db). 
 * @brief kitchen inventory window show the buttons of current kitchenware inventory, user can edit current amount and add new kitchenware.
 */
#include "KitchenWindow.h"
/** 
 * @brief set the window layout
 * @param Kitchen kitchenware inventory object
 * @param db database pointer for main to call kitchenware methods
 */
KitchenWindow::KitchenWindow(KitchenwareInventory *Kitchen, DataBase *db) {
    kit=Kitchen;
    DB = db;
    MainLayout->setSpacing(0);
    Kitchen_Window->setWindowTitle("Kitchenware List");
    Kitchen_Window->setFixedSize(1280, 800);
    Kitchen_Window->setLayout(MainLayout);
    Kitchen_Window->setStyleSheet("QWidget {background-color: #FFFFFF }");
    MainLayout->setMargin(0);
    KitchenWindowNav();
    KitchenWindowMainBody();
    MainLayout->addStretch();
    Kitchen_Window->show();

}

KitchenWindow::~KitchenWindow(){}
/** 
 * @brief set window title
 */
void KitchenWindow::KitchenWindowNav() {
    Nav->setLayout(NavLayout);
    Nav->setFixedHeight(90);
    Nav->setStyleSheet(
            "QGroupBox { background-color: white; padding: 0 64px; border:0 } "
            "QLabel { font-size: 40px; font-weight: bold; background-color: transparent; color:#C37000 } "
            "QPushButton { font-size: 20px; background-color: transparent; color: #C37000;} ");
    KitchenWindowNavBody();
    MainLayout->addWidget(Nav);
    MainLayout->addWidget(MainBodyScroll);
}
/** 
 * @brief set window title, add, back button, title name and scroll bar
 */
void KitchenWindow::KitchenWindowNavBody() {

    // Nav Title
    auto *NavTitle = new QLabel("Kitchen Inventory");

    // Nav Back Button
    auto *BackButton = new QPushButton("Back");
    BackButton->setIcon(QIcon("assets/icons/left-brown.svg"));
    BackButton->setStyleSheet(" ");
    BackButton->setIconSize(QSize(32,32));
    connect(BackButton,SIGNAL(clicked()),SLOT(handleBackButton()));
    auto *AddButton = new QPushButton("Add");
    AddButton->setIcon(QIcon("assets/icons/add.svg"));//
    AddButton->setIconSize(QSize(32,32));
    QObject::connect(AddButton,SIGNAL(clicked()),SLOT(handleAddButton()));

    // Add Widget for button title and placeholder(info prompt)
    NavLayout->addWidget(BackButton, 0, 0, 1, 1, {Qt::AlignLeft});
    NavLayout->addWidget(AddButton, 0, 2, 1, 1, {Qt::AlignRight});//
    NavLayout->addWidget(NavTitle, 0, 1, 1, 1, {Qt::AlignCenter});
}
/** 
 * @brief set window main body
 */
void KitchenWindow::KitchenWindowMainBody() {
    MainBody->setStyleSheet("QGroupBox { background-image:url(\"assets/img/background.png\"); border: none; padding: 0 64px}");
    //set content
    KitchenKitchenwareList();

    //Layout
    MainBodyLayout->setMargin(0);
    MainLayout->addStretch();
    MainBody->setLayout(MainBodyLayout);

    // set schroll bar
    MainBodyScroll->setStyleSheet("QScrollArea { border: none }");
    MainBodyScroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    MainBodyScroll->setWidgetResizable(true);
    MainBodyScroll->setMinimumHeight(Kitchen_Window->height() - Nav->height() );
    MainBodyScroll->setWidget(MainBody);

}
/** 
 * @brief set kitchenwares buttons
 */
void KitchenWindow::KitchenKitchenwareList() {
    int row = 1;//start from second row
    int col = 0;
    std::cout << kit->get_all_inventory().size() << std::endl;
    for (std::pair<std::string, int> ing: kit->get_all_inventory()) {
        Kitchenware *tmp = DB->getKitchenwareByID(ing.first);
        if (tmp == nullptr) {
            std::cout << "null";
            exit(0);
        } else {
            auto *InventoryButton = new QPushButton(QString::fromStdString(tmp->get_kitchenware_name()));
            InventoryButton->setStyleSheet("border-radius:10px; background-color: white; color: #5F3600; font-size: 20px;height: 100px; ");
            connect(InventoryButton, SIGNAL(clicked()), SLOT(handleInventoryButton()));
            InventoryButton->setObjectName(QString::fromStdString(ing.first));
            MainBodyLayout->addWidget(InventoryButton, row, col, 1, 1);//add into main boday of main
            col += 1;
        }
        if (col == 4) {
            col =  0;
            row += 1;
        }
    }

}
/** 
 * @brief handle back button event when user click back button
 */
void KitchenWindow::handleBackButton(){
    WindowHide();
    auto *main = new mainMenu(DB);
}
/** 
 * @brief handle add button event when user click add button
 */
void KitchenWindow::handleAddButton(){
    WindowHide();
    KitchenAddWindow *window = new KitchenAddWindow(DB, this);
    window->WindowShow();
}
/** 
 * @brief handle inventory button event when user click inventory button
 */
void KitchenWindow::handleInventoryButton(){
//    WindowHide();
    QWidget *w = qobject_cast<QWidget *>(sender());
    KitchenEditWindow *W2 =new KitchenEditWindow(w->objectName().toStdString(), DB, this->kit);

    W2->WindowShow();
}
/** 
 * @brief show window
 */
void KitchenWindow::WindowShow(){
    this->Kitchen_Window->show();
}
/** 
 * @brief hide window
 */
void KitchenWindow::WindowHide(){
    this->Kitchen_Window->close();
}