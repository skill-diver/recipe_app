
#include "RecipeWindow.h"

RecipeWindow::RecipeWindow(recipe *Recipe, DataBase *db, QWidget *recipeListWindow) {
    prevWindow = recipeListWindow;
    rec = Recipe;
    DB = db;
    MainLayout->setSpacing(0);
    Recipe_Window->setWindowTitle("Recipe Details");
    Recipe_Window->setFixedSize(1280, 800);
    Recipe_Window->setLayout(MainLayout);
    Recipe_Window->setStyleSheet("QWidget {background-color: #FFFFFF }");
    MainLayout->setMargin(0);
    RecipeWindowNav();
    RecipeWindowMainBody();
    MainLayout->addStretch();
}

RecipeWindow::~RecipeWindow(){}

void RecipeWindow::RecipeWindowNav() {
    Nav->setLayout(NavLayout);
    Nav->setFixedHeight(90);
    Nav->setStyleSheet(
            "QGroupBox { background-color: #C37000; padding: 0 64px; } "
            "QLabel { font-size: 40px; font-weight: bold; background-color: transparent;} "
            "QPushButton { font-size: 20px; background-color: transparent; color: white;} ");
    RecipeWindowNavBody();
    MainLayout->addWidget(Nav);
    MainLayout->addWidget(MainBodyScroll);
}

void RecipeWindow::RecipeWindowNavBody() {

    // Nav Title
    auto *NavTitle = new QLabel("Recipe Details");

    // Nav Back Button
    auto *BackButton = new QPushButton("  Back");
    BackButton->setCursor(QCursor(Qt::PointingHandCursor));
    QObject::connect(BackButton, SIGNAL(clicked()), SLOT(Back()));
    BackButton->setIcon(QIcon("assets/icons/chevron-left-circle.svg"));
    BackButton->setIconSize(QSize(32,32));
    auto *PlaceHolder = new QPushButton("");

    // Add Widget
    NavLayout->addWidget(BackButton, 0, 0, 1, 1, {Qt::AlignLeft});
    NavLayout->addWidget(NavTitle, 0, 1, 1, 1, {Qt::AlignCenter});
    NavLayout->addWidget(PlaceHolder, 0,2,1,1);
}

void RecipeWindow::RecipeWindowMainBody() {
    MainBody->setStyleSheet("QGroupBox { background-color: white; border: none; }");

    RecipeInfo();
    RecipeIngredientList();
    RecipeKitchenwareList();
    RecipeProcedure();

    MainBodyLayout->setMargin(0);
    MainLayout->addStretch();
    MainBody->setLayout(MainBodyLayout);


    MainBodyScroll->setStyleSheet("QScrollArea { border: none }");
    MainBodyScroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    MainBodyScroll->setWidgetResizable(true);
    MainBodyScroll->setMinimumHeight(Recipe_Window->minimumHeight() - Nav->minimumHeight() );
    MainBodyScroll->setWidget(MainBody);

}

void RecipeWindow::RecipeInfo() {
    auto* TitleBox = new QGroupBox();
    auto* TitleLayout = new QHBoxLayout();

    auto *RecipeTitle = new QLabel(QString::fromStdString(rec->get_recipe_name()));
    auto *RecipeOtherInfo = new QGroupBox();
    auto *RecipeOtherInfoLayout = new QGridLayout();

    auto *DurationLabel = new QLabel("Duration");
    auto *Duration = new QLabel(QString::fromStdString(std::to_string(rec->get_time_minutes())+"min"));

    auto *RecipeTypeLabel = new QLabel("Cuisine Type");
    auto *Type = new QLabel(QString::fromStdString(rec->get_cuisine_type()));

    Duration->setObjectName("Duration");
    Duration->setStyleSheet("QLabel#Duration{font-weight: bold}");
    Type->setObjectName("Type");
    Type->setStyleSheet("QLabel#Type{font-weight: bold}");

    RecipeOtherInfoLayout->setMargin(0);
    RecipeOtherInfoLayout->setHorizontalSpacing(32);
    RecipeOtherInfoLayout->addWidget(DurationLabel, 0, 0, 1, 1, {Qt::AlignRight});
    RecipeOtherInfoLayout->addWidget(Duration, 0, 1, 1, 1,{Qt::AlignRight});
    RecipeOtherInfoLayout->addWidget(RecipeTypeLabel, 1, 0, 1, 1, {Qt::AlignRight});
    RecipeOtherInfoLayout->addWidget(Type, 1,1,1,1, {Qt::AlignRight});


    RecipeOtherInfo->setLayout(RecipeOtherInfoLayout);
    RecipeOtherInfo->setStyleSheet("QLabel { font-size: 20px; background-color: white; color: #5F3600; }");
    RecipeTitle->setStyleSheet("QLabel { font-size: 40px; background-color: white; color: #C37000; font-weight: bold}");

    TitleLayout->addWidget(RecipeTitle);
    TitleLayout->addStretch();
    TitleLayout->addWidget(RecipeOtherInfo);
    TitleBox->setObjectName("TitleBox");
    TitleBox->setStyleSheet("QGroupBox#TitleBox { margin: 32px 64px; padding-bottom: 32px; border-bottom: 1px solid #5F3600 }");
    TitleLayout->setMargin(0);


    TitleBox->setLayout(TitleLayout);
    MainBodyLayout->addWidget(TitleBox);
}

void RecipeWindow::RecipeIngredientList() {
    auto *RecipeIngredient = new QGroupBox();
    auto *RecipeIngredientLayout = new QVBoxLayout();
    auto *IngredientTitle = new QLabel("Ingredients");
    auto *IngredientList = new QGroupBox();
    auto *IngredientListLayout = new QGridLayout();

    RecipeIngredient->setObjectName("RecipeIngredient");
    RecipeIngredient->setStyleSheet("QGroupBox#RecipeIngredient { margin: 0 64px; padding-bottom: 32px; }");
    RecipeIngredient->setLayout(RecipeIngredientLayout);
    IngredientTitle->setStyleSheet("QLabel { font-size: 20px; background-color: white; color: #C37000; font-weight: bold}");

    IngredientList->setLayout(IngredientListLayout);
    IngredientListLayout->setMargin(0);
    int row = 0;
    int col = 0;
    for (std::pair<std::string, int> ing : rec->get_ingredients()){
        Ingredient *tmp = DB->getIngredientByID(ing.first);
        if (tmp == nullptr){
            std::cout << "null";
            exit(0);
        }else{
            auto *name = new QLabel(QString::fromStdString(tmp->get_ingredient_name()));
            auto *label = new QLabel(QString::fromStdString(std::to_string(ing.second)+"g"));
            IngredientListLayout->addWidget(name, row, col, 1, 1);
            col += 1;
            IngredientListLayout->addWidget(label, row, col , 1, 1);
            col += 1;
        }
        if (col == 4){
            col = 0; row += 1;
        }
    }
    RecipeIngredientLayout->setMargin(0);
    IngredientList->setStyleSheet("QLabel { color: #5F3600; font-size: 20px; }");
    RecipeIngredientLayout->addWidget(IngredientTitle);
    RecipeIngredientLayout->addWidget(IngredientList);
    MainBodyLayout->addWidget(RecipeIngredient);
}

void RecipeWindow::RecipeKitchenwareList() {
    auto *RecipeKitchenware = new QGroupBox();
    auto *RecipeKitchenwareLayout = new QVBoxLayout();
    auto *KitchenwareTitle = new QLabel("Kitchenware");
    auto *KitchenwareList = new QGroupBox();
    auto *KitchenwareListLayout = new QGridLayout();

    RecipeKitchenware->setObjectName("RecipeKitchenware");
    RecipeKitchenware->setStyleSheet("QGroupBox#RecipeKitchenware { margin: 0 64px; padding-bottom: 32px; }");
    RecipeKitchenware->setLayout(RecipeKitchenwareLayout);
    KitchenwareTitle->setStyleSheet("QLabel { font-size: 20px; background-color: white; color: #C37000; font-weight: bold}");

    KitchenwareList->setLayout(KitchenwareListLayout);
    KitchenwareListLayout->setMargin(0);

    int row = 0;
    int col = 0;
    for (std::pair<std::string, int> ing : rec->get_kitchenware()){
        Kitchenware *tmp = DB->getKitchenwareByID(ing.first);
        if (tmp == nullptr){
            std::cout << "null";
            exit(0);
        }else{
            auto *name = new QLabel(QString::fromStdString(tmp->get_kitchenware_name()));
            auto *label = new QLabel(QString::fromStdString(std::to_string(ing.second)));
            KitchenwareListLayout->addWidget(name, row, col, 1, 1);
            col += 1;
            KitchenwareListLayout->addWidget(label, row, col , 1, 1);
            col += 1;
        }
        if (col == 4){
            col = 0; row += 1;
        }
    }

    RecipeKitchenwareLayout->setMargin(0);
    KitchenwareList->setStyleSheet("QLabel { color: #5F3600; font-size: 20px; }");
    RecipeKitchenwareLayout->addWidget(KitchenwareTitle);
    RecipeKitchenwareLayout->addWidget(KitchenwareList);
    MainBodyLayout->addWidget(RecipeKitchenware);
}

void RecipeWindow::RecipeProcedure() {
    auto *RecipeProcedureBox = new QGroupBox();
    RecipeProcedureBox->setObjectName("RecipeProcedureBox");
    RecipeProcedureBox->setStyleSheet("QGroupBox#RecipeProcedureBox { margin: 0 64px; padding-bottom: 32px; }");
    auto *RecipeProcedureTitle = new QLabel("Procedure");
    RecipeProcedureTitle->setObjectName("RecipeProcedureTitle");
    RecipeProcedureTitle->setStyleSheet("QLabel#RecipeProcedureTitle{ font-size: 20px; background-color: white; color: #C37000; font-weight: bold }");

    auto *RecipeProcedureBoxLayout = new QVBoxLayout();
    RecipeProcedureBoxLayout->setMargin(0);
    RecipeProcedureBoxLayout->setSpacing(16);
    RecipeProcedureBoxLayout->addWidget(RecipeProcedureTitle);
    for (std::pair<std::string, std::vector<std::string>> pro : rec->get_procedure()){
        auto *StepName = new QLabel(QString::fromStdString(pro.first));
        StepName->setStyleSheet("QLabel{ font-size: 20px; background-color: white; color: #5F3600; font-weight: bold}");
        RecipeProcedureBoxLayout->addWidget(StepName);
        for (const auto& step : pro.second){
            auto *StepLabel = new QLabel(QString::fromStdString(step));
            StepLabel->setStyleSheet("QLabel{color: #5F3600; font-size: 20px; background-color: white; }");
            StepLabel->setWordWrap(true);
//            StepLabel->setMaximumWidth(1280);
            RecipeProcedureBoxLayout->addWidget(StepLabel);
        }
    }


    RecipeProcedureBox->setLayout(RecipeProcedureBoxLayout);
    MainBodyLayout->addWidget(RecipeProcedureBox);
}

void RecipeWindow::WindowShow(){
    this->Recipe_Window->show();
}

void RecipeWindow::WindowClose(){
    this->Recipe_Window->close();
}

void RecipeWindow::Back() {
    this->WindowClose();
    ((RecipeListWindow*)prevWindow)->WindowShow();
}

void RecipeWindow::closeEvent(QCloseEvent *event){
    std::cout << "closing" << std::endl;
    auto *recWindow = new RecipeListWindow(DB);
    recWindow->WindowShow();
}