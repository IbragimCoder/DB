#include "dbmanager.h"

DBManager::DBManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);
    if(!m_db.open())
    {
        qDebug() << "connection to databsse failed ";
    }
    else
    {
        qDebug() <<" Connection to Database ok";
    }
}

DBManager::DBManager(){

}

bool DBManager::addPerson(const QString &name)
{
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO people (name) VALUES (:name)");
    query.bindValue(":name",name);
    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "add Person Error:" << query.lastError();
    }

    return success;
}

bool DBManager::personExists(const QString &name)
{
    bool found = false;
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE name = (:name)");
    query.bindValue(":name",name);
    if(query.exec())
    {
        if(query.next())
        {
            found = true;
        }

    }

    else
    {
        qDebug() << "person Exists Error:" << query.lastError();
    }

    return found;

}

bool DBManager::removePerson(const QString &name)
{
    bool success = false;
    QSqlQuery queryDelete;
    queryDelete.prepare("DELETE FROM people WHERE name = (:name)");
    queryDelete.bindValue(":name",name);
    success = queryDelete.exec();
    if(success)
    {
        if(queryDelete.next())
        {
            qDebug() << "remove person failed";
        }

    }

    else
    {
        qDebug() << "person does not exist";;
    }

    return success;

}

void DBManager::printAll()
{
    qDebug() << "people on db";
    QSqlQuery query("SELECT * FROM people");
    int idName = query.record().indexOf("name");
    while(query.next())
    {
        QString name= query.value(idName).toString();
        dataset.push_back(name);
        qDebug() << "===" << name;
    }

}

bool DBManager::removeAll()
{
    bool success = false;
    QSqlQuery removeQuery;;
    removeQuery.prepare("DELETE FROM people");

    if( removeQuery.exec())
    {
        success = true;
    }

    else
    {
        qDebug() << "removed failed " << removeQuery.lastError();
    }

    return success;

}

DBManager::~DBManager()
{
    if(m_db.isOpen())
    {
        m_db.close();
    }
}
