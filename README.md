Data Base 

This is a database with little functionality, you can add delete and also perform various actions with the data.

In order for the code to work, you need to install Qt (preferably Qt 6), as well as install the SQLITE library.

In my database you will be able to add delete check for existence clean and view the database.
The dbmanager class contains the logic and Sqlite commands. The interfaceDB class uses Qt for graphic design, as well as to use functionality and logic, the interfaceDB class was inherited by the dbmanager class.

Here is a small sample code from the project:

<font size="100">Description</font>

This code is an Add() method in the Interface DB class. It performs the following actions:

Clears text labels.
Checks if the lineedit input field is empty.
If the input field is not empty:
Gets the name from the input field.
Adds this name to the dataset.
Calls the AddPerson(name) function.
Clears the input field.
Sets the text label to “operation completed successfully".
Sets the text label to “log in to the database to check for changes".
Disables the input field.

``` c++
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
```