
#include "IngredientDetail.h"
using namespace std;



IngredientDetail::IngredientDetail(string IngIDp, DataBase *DBp){
        IngID = IngIDp;
        DB = DBp;
        Ing = DB->getIngredientByID(IngID);
        IngInv = DB->getIngredientInventory();
        MainLayout->setSpacing(0);
        IngredientDetailW->setWindowTitle("Ingredient Details");
        IngredientDetailW->setFixedSize(800, 600);
        IngredientDetailW->setLayout(MainLayout);
        IngredientDetailW->setStyleSheet("QWidget {background-color: #FFFFFF }");
        MainLayout->setMargin(0);


        IngredientDetailNav();
        IngredientUpdate();
        IngredientDetailMainBody();
        IngredientDetailW->show();


};

void IngredientDetail::IngredientDetailNav(){

    Nav->setLayout(NavLayout);
    Nav->setFixedHeight(90);
    Nav->setStyleSheet(
            "QGroupBox { background-color: #C37000; padding: 0 64px; } "
            "QLabel { font-size: 40px; font-weight: bold; background-color: transparent;} "
            "QPushButton { font-size: 20px; background-color: transparent; color: white;} ");
    IngredientDetailNavBody();
    MainLayout->addWidget(Nav);
    MainLayout->addWidget(MainBodyScroll);

};

void IngredientDetail::IngredientDetailNavBody(){
    // Nav Title
    auto *NavTitle = new QLabel(QString::fromStdString(Ing->get_ingredient_name()));

    // Nav Back Button
//    auto *BackButton = new QPushButton("  Back");
//    BackButton->setIcon(QIcon("assets/icons/chevron-left-circle.svg"));
//    BackButton->setStyleSheet(" ");
//    BackButton->setIconSize(QSize(32,32));
//    auto *PlaceHolder = new QPushButton("");

    // Add Widget
//    NavLayout->addWidget(BackButton, 0, 0, 1, 1, {Qt::AlignLeft});
    NavLayout->addWidget(NavTitle, 0, 0, 1, 1, {Qt::AlignCenter});
//    NavLayout->addWidget(PlaceHolder, 0,2,1,1);
}

void IngredientDetail::IngredientDetailMainBody(){

    MainBody->setStyleSheet("QGroupBox { background-color: white; border: none; }");

    IngredientAmount();
    IngredientNutrition();

    MainBodyLayout->setMargin(0);
    MainLayout->addStretch();
    MainBody->setLayout(MainBodyLayout);


    MainBodyScroll->setStyleSheet("QScrollArea { border: none }");
    MainBodyScroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    MainBodyScroll->setWidgetResizable(true);
    MainBodyScroll->setMinimumHeight(IngredientDetailW->minimumHeight() - Nav->minimumHeight() );
    MainBodyScroll->setWidget(MainBody);

}

void IngredientDetail::IngredientAmount(){
    string IngName = Ing->get_ingredient_name();
    int amount = IngInv.at(IngID);
    string amountStr = to_string(amount);
    auto *AmountLayout = new QVBoxLayout();
    auto *AmountBox = new QGroupBox();
    auto *YouHave = new QLabel("You have");
    IngAmount = new QLabel(QString::fromStdString(amountStr));
    IngAmount->setStyleSheet("font-size: 60px; font-weight: bold");
    auto *IngInYourInventory = new QLabel(QString::fromStdString(IngName) + " in you inventory");


    AmountBox->setLayout(AmountLayout);

    AmountLayout->addWidget(YouHave);
    AmountLayout->addWidget(IngAmount);
    AmountLayout->addWidget(IngInYourInventory);
    AmountLayout->addStretch();

    MainBodyLayout->addWidget(AmountBox);
    AmountBox->setStyleSheet("QLabel{color: #5F3600; background-color: white; font-size: 20px} QGroupBox{background-color: white; border: 0}");


};

void IngredientDetail::IngredientUpdate(){

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

void IngredientDetail::IngredientNutrition(){
    auto *NutritionLayout = new QVBoxLayout();
    auto *NutritionBox = new QGroupBox();
    NutritionBox->setStyleSheet("QLabel{color: #5F3600; background-color: white} QGroupBox{background-color: white; border: 0}");

    NutritionBox->setLayout(NutritionLayout);

    auto *NutritionTitle = new QLabel("Nutrition Value");
    NutritionTitle->setStyleSheet("font-size:20px; font-weight: bold");

    auto *Calories = new QLabel("Calories               " + QString::fromStdString(to_string(Ing->get_nutritional_value("Calories"))));
    auto *Fat = new QLabel("Total Fat:              " + QString::fromStdString(to_string(Ing->get_nutritional_value("Total Fat"))));
    auto *Sodium = new QLabel("Sodium:              " + QString::fromStdString(to_string(Ing->get_nutritional_value("Sodium"))));
    auto *Carbs = new QLabel("Total Carbs:              "+ QString::fromStdString(to_string(Ing->get_nutritional_value("Total Carbs"))));
    auto *Protein = new QLabel("Protein:                " + QString::fromStdString(to_string(Ing->get_nutritional_value("Protein"))));

    NutritionLayout->addWidget(NutritionTitle);
    NutritionLayout->addWidget(Calories);
    NutritionLayout->addWidget(Fat);
    NutritionLayout->addWidget(Sodium);
    NutritionLayout->addWidget(Carbs);
    NutritionLayout->addWidget(Protein);

    MainLayout->addWidget(NutritionBox);
}

void IngredientDetail::UpdateHandle(){
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
            if (DB->addIngredientInventory(IngID, input_number)){
                IngInv.at(IngID) = input_number;
                IngAmount->setText(QString::fromStdString(std::to_string(input_number)));
                std::cout << "Input successful" << std::endl;
                FeedBack->setText("Input successful");
            }

        }

    }catch(exception &e){
        FeedBack->setText("This is not an int, please input and int");
        std::cout << "This is not an int, please input and int" << std::endl;
    }

}



    IngredientDetail::~IngredientDetail(){};

