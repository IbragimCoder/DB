#include "InterfaceDB.h"


InterfaceDB::InterfaceDB(const QString& path):DBManager(path)
{
    QPushButton *AddPerson = new QPushButton("Add Person",this);
    QPushButton *PersonExist = new QPushButton("Person Exist",this);
    QPushButton *RemovePerson = new QPushButton("Remove Person",this);
    QPushButton *PrintAll = new QPushButton("Print All",this);
    QPushButton *RemoveAll = new QPushButton("Remove All",this);
    QPushButton *ContinueProcess = new QPushButton("Continue",this);
    QPushButton *DataBase = new QPushButton("to log in data base",this);

    grid = new QGridLayout(this);
    lineEdit = new QLineEdit(this);
    label_1 = new QLabel(this);
    label_2 = new QLabel(this);
    labelName = new QLabel(this);
    labelImage = new QLabel(this);
    QPixmap scaledImage = image->scaled(200, 200, Qt::KeepAspectRatio);
    labelImage->setPixmap(scaledImage);

    labelName->setText("<p style='color:red; font-size:40px;'>IbragimCoder's database</p>");

    grid->setAlignment( Qt::AlignTop);

    grid->addWidget(AddPerson, 0, 0,1,1);
    grid->addWidget(PersonExist, 0, 1,1,1);
    grid->addWidget(RemovePerson, 0, 2,1,1);
    grid->addWidget(PrintAll, 0, 3,1,1);
    grid->addWidget(RemoveAll, 0, 4,1,1);
    grid->addWidget(lineEdit, 1, 0, 1, 4);
    grid->addWidget(label_1,2,0,1,5);
    grid->addWidget(label_2,3,0,1,5);
    grid->addWidget(ContinueProcess,1,4);
    grid->addWidget(DataBase,5,0,4,3);
    grid->addWidget(labelName,7,0,5,5);
    grid->addWidget(labelImage,2,3,5,5);

    connect(AddPerson,&QPushButton::clicked, this,&InterfaceDB::Add);
    connect(ContinueProcess,&QPushButton::clicked, this,&InterfaceDB::ContinueProcessFunc);
    connect(PersonExist,&QPushButton::clicked, this,&InterfaceDB::ExistFunc);
    connect(RemovePerson,&QPushButton::clicked, this,&InterfaceDB::RemovePersonFunc);
    connect(PrintAll,&QPushButton::clicked, this,&InterfaceDB::PrintAllFunc);
    connect(RemoveAll,&QPushButton::clicked, this,&InterfaceDB::RemoveAllPersonFunc);
    connect(DataBase,&QPushButton::clicked, this,&InterfaceDB::PrintAllFunc);


    setFixedSize(500,370);


}

void InterfaceDB::Add()
{
    QString name;
    label_1->clear();
    label_2->clear();
    if (!lineEdit->text().isEmpty())
    {
        name = lineEdit->text();
        dataset.push_back(name);
        addPerson(name);
        lineEdit->clear();
        label_1->setText("the operation was successful");
        label_2->setText("to check the changes, log into the database");
        lineEdit->setDisabled(true);
    }

}
void InterfaceDB::ContinueProcessFunc()
{
    lineEdit->setDisabled(false);
    label_1->clear();
    label_2->clear();
    lineEdit->clear();
}

void InterfaceDB::ExistFunc()
{
    QString name;
    label_1->clear();
    label_2->clear();
    if (!lineEdit->text().isEmpty())
    {
        name = lineEdit->text();
        bool exists = personExists(name);
        lineEdit->clear();
        if(exists)
        {
            label_1->setText("there is such a person in the database");
        }
        else
        {
            label_1->setText("there is N0 such person in the database");
        }

        label_2->setText("to check the changes, log into the database");
        lineEdit->setDisabled(true);
    }
}

void InterfaceDB::RemovePersonFunc()
{
    QString name;
    label_1->clear();
    label_2->clear();
    if (!lineEdit->text().isEmpty())
    {
        name = lineEdit->text();
        bool dltPerson = removePerson(name);
        lineEdit->clear();
        int temp;
        if(dltPerson)
        {
            for (int i = 0; i < dataset.size(); i++) {
                if (dataset[i] == name) {
                    temp = i;
                    break;
                }
            }

            label_1->setText("this person has been removed from the database");
            auto it = std::find(dataset.begin(), dataset.end(), dataset[temp]);

            if (it != dataset.end()) {
                dataset.erase(it);
            }

        }
        else
        {
            label_1->setText("there is N0 such person in the database");
        }

        label_2->setText("to check the changes, log into the database");
        lineEdit->setDisabled(true);
    }
}

void InterfaceDB::PrintAllFunc()
{
    lineEdit->clear();

    model = new QStandardItemModel();
    dataset.clear();
    printAll();
    if(!dataset.empty())
    {
        for(int i = 0; i < dataset.size();i++)
        {
            model->setItem(i, 0, new QStandardItem(dataset[i]));
            label_1->setText("the database is open");
        }
    }
    else
    {
        label_1->setText("the database is empty");
    }

    tableView = new QTableView();
    tableView->setModel(model);

    tableView->setFixedWidth(150);

    tableView->show();
    lineEdit->setDisabled(true);
}

void InterfaceDB::RemoveAllPersonFunc()
{
    label_1->clear();
    label_2->clear();

    bool dltPeople = removeAll();
    lineEdit->clear();
    if(dltPeople)
    {
        label_1->setText("the database has been deleted");
        dataset.clear();
    }
    else
    {
        label_1->setText("Error!");
    }
    label_2->setText("to check the changes, log into the database");
    lineEdit->setDisabled(true);

}
