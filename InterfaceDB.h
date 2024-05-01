#ifndef DB_INTERFACEDB_H
#define DB_INTERFACEDB_H
#include "dbmanager.h"
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <vector>
#include <string>
#include <QPixmap>
#include <QMainWindow>
#include <QIcon>
class InterfaceDB :public DBManager
{
private:
    QLabel *label_1;
    QLabel *label_2;
    QLabel *labelName;
    QLabel *labelImage;
    QPixmap* image = new QPixmap(":/Assets/miki.jpg");
    QStandardItemModel *model;
    QTableView *tableView;
    QGridLayout *grid;
    QLineEdit *lineEdit;
public:
    InterfaceDB(const QString& path);
public slots:
    void Show();
    void Add();
    void ExistFunc();
    void ContinueProcessFunc();
    void RemovePersonFunc();
    void RemoveAllPersonFunc();
    void PrintAllFunc();

};


#endif
