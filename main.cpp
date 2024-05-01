#include <iostream>
#include "dbmanager.h"
#include "InterfaceDB.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    InterfaceDB object("C:/Users/Asus/CLionProjects/DB/data.sqlite");
    object.show();
    object.setWindowIcon(QIcon(":/Assets/mikititle.jpg"));
    return app.exec();
}
