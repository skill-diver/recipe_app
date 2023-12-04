
#include "IngredientAdd.h"

IngredientAdd::IngredientAdd(DataBase *db) {

    DB = db;
    IngredientAddW->setAttribute(Qt::WA_DeleteOnClose);
    QObject::connect(IngredientAddW, SIGNAL(destroyed(QObject *)), SLOT(showIngredientWindow()));
    IngredientAddW->setWindowTitle("Add Ingredient");
    IngredientAddW->setFixedSize(800, 400);
    IngredientAddW->setStyleSheet("background-color: #ffffff");

    SelectIngredient();

    auto *submitButton = new QPushButton("Add");
    submitButton->setStyleSheet("color: #FFFFFF; background-color: #C37000; padding: 20px 16px; border: 0; font-size: 16px;");
    submitButton->setCursor(QCursor(Qt::PointingHandCursor));
    QObject::connect(submitButton, SIGNAL(clicked()), SLOT(IngredientNewSubmit()));
    this->BodyLayout->addWidget(submitButton);

    IngredientAddLayout->setMargin(0);
    BodyLayout->addStretch();
    BodyLayout->setMargin(0);
    Body->setLayout(BodyLayout);
//    IngredientAddLayout->addWidget(scroll);
    IngredientAddW->setLayout(IngredientAddLayout);

    Body->setStyleSheet("QGroupBox { background-color: white; border: none; }");
//    scroll->setStyleSheet("QScrollArea { border: none; background-color: white }");
//    scroll->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
//    scroll->setWidgetResizable(true);
//    scroll->setWidget(Body);
    auto *PlaceHold_1 = new QLabel();
    auto *PlaceHold_2 = new QLabel();
    auto *PlaceHold_3 = new QLabel();
    auto *PlaceHold_4 = new QLabel();
    auto *PlaceHold_5 = new QLabel();

    this->IngredientAddLayout->addWidget(PlaceHold_1);
    this->IngredientAddLayout->addWidget(PlaceHold_2);
    this->IngredientAddLayout->addWidget(PlaceHold_3);
    this->IngredientAddLayout->addWidget(PlaceHold_4);
    this->IngredientAddLayout->addWidget(PlaceHold_5);

    IngredientAddLayout->addWidget(Body);
    IngredientAddW->show();

}

void IngredientAdd::SelectIngredient() {

    auto *layout = new QVBoxLayout();
    //auto *selectIngredientButton = new QPushButton("Select Ingredient");
    IngredientList->setStyleSheet("margin: 0; padding: 0; background-color: white; border: 0");
    layout->setMargin(0);
    layout->setSpacing(8);
    layout->addWidget(IngredientAddRow());
    IngredientList->setLayout(layout);
    BodyLayout->addWidget(IngredientList);
    //selectIngredientButton->setStyleSheet("color: #C37000; border: none; margin: 16px 32px; text-align: right; font-size: 16px");

    //QObject::connect(selectIngredientButton, SIGNAL(clicked()), SLOT(IngredientNewRow()));
    //BodyLayout->addWidget(selectIngredientButton);

}

QGroupBox* IngredientAdd::IngredientAddRow(){
    //auto *deleteButton = new QPushButton("");
    //deleteButton->setIcon(QIcon("assets/icons/delete.svg"));
    auto *IngredientBox = new QComboBox();
    IngredientBox->setStyleSheet("QComboBox { color: #5F3600; border: none; border-bottom: 1px solid #707070; padding: 0; font-size: 20px }");
    IngredientBox->setMinimumContentsLength(IngredientAddW->width()/2);

    std::vector<Ingredient*> ing = DB->getAllIngredient();
    IngredientBox->addItem("Select an Ingredient", QVariant("0"));

    for (Ingredient* i : ing){
        IngredientBox->addItem(QString::fromStdString(i->get_ingredient_name()), QVariant(QString::fromStdString(i->get_ingredient_id())));
    }
    auto *amount = new QLineEdit();
    amount->setAttribute(Qt::WA_MacShowFocusRect, false);
    amount->setPlaceholderText("Amount");
    auto *container = new QGroupBox();
    container->setStyleSheet("QGroupBox{ background: white; padding: 0px 32px; border: none; } QLineEdit { color: #5F3600; border: none; border-bottom: 1px solid #707070; font-size: 20px}");
    auto *layout_1 = new QVBoxLayout();
    layout_1->setMargin(0);
    layout_1->setSpacing(16);
    layout_1->addWidget(IngredientBox);
    layout_1->addWidget(amount);
    //layout_1->addWidget(deleteButton);
    container->setLayout(layout_1);
    this->Ingredient_map[IngredientBox] = amount;

    //QObject::connect(deleteButton, SIGNAL(clicked()), SLOT(IngredientDeleteRow()));
    return container;
}

void IngredientAdd::IngredientNewRow(){
    this->IngredientList->layout()->addWidget(this->IngredientAddRow());
}

void IngredientAdd::IngredientDeleteRow() {
    auto *msg = new QMessageBox();
    if (this->Ingredient_map.size() > 1){
        msg->setText("Are you sure to delete this ingredient?");
        msg->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg->setDefaultButton(QMessageBox::No);
        int ret = msg->exec();

        if (ret == QMessageBox::Yes){
            QWidget *w = qobject_cast<QWidget *>(sender()->parent());
            auto *tmp = (QComboBox*) w->layout()->itemAt(0)->widget();
            this->Ingredient_map.erase(tmp);
            this->IngredientList->layout()->removeWidget(w);
        }
    }else{
        msg->setText("Deletion Error: Each Fridge required at least 1 Ingredient.");
        msg->exec();
    }
}


void IngredientAdd::IngredientNewSubmit() {
    auto *msg = new QMessageBox();
    for (auto[key, val]: this->Ingredient_map) {
        if (key->currentData().toString().toStdString() == "0") {
            msg->setText("Oops! There are 1 or more Ingredient you haven't select.");
            msg->exec();
            return;
        } else if (val->text().isEmpty()) {
            msg->setText("Oops! There are 1 or more Ingredient does not specified the amount.");
            msg->exec();
            return;
        } else {
            try {
                int amount = std::stoi(val->text().toStdString());
            } catch (exception &e) {
                msg->setText("Oops! One of the kitchenware amount is not an integer.");
                msg->exec();
                return;
            }
        }
    }

    // Finalizing the recipe
    std::unordered_map<std::string, int> Ing_map;
    for (auto [key, val] : this->Ingredient_map){
        Ing_map[key->currentData().toString().toStdString()] = std::stoi(val->text().toStdString());
        if (DB->addIngredientInventory(key->currentData().toString().toStdString(), val->text().toInt())){
            msg->setText("Ingredient Inventory Saved!");
            msg->exec();
            IngredientAddW->close();
        }
        else{
            msg->setText("Oops! save failed!");
            msg->exec();
        }
    }
}



IngredientAdd::~IngredientAdd(){}

void IngredientAdd::showIngredientWindow() {
    auto *IngredientInventoryWindowPointer = new IngredientInventoryWindow(DB);
}
