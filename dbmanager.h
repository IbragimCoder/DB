#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QApplication>
#include <QWidget>
#include <vector>
#include <string>

class DBManager :public QWidget
{
public:
    DBManager(const QString& path);
    DBManager();
    bool addPerson(const QString& name);
    bool personExists(const QString& name);
    bool removePerson(const QString& name);
    void printAll();
    bool removeAll();
    ~DBManager();
protected:
    std::vector<QString> dataset;

private:
    QSqlDatabase m_db;
};

#endif
