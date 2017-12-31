#ifndef SYSTEM_MANAGER_INTERFACE_H
#define SYSTEM_MANAGER_INTERFACE_H

#include <map>

#include "Database.h"
#include "SemValue.h"

using namespace std;

class SystemManagerInterface
{
public:
    // Constructor
    SystemManagerInterface() { haveCurrentDatabase = false; }


    // SysStmt
    virtual void showDatabases();


    // DbStmt
    virtual void createDatabase(string dbName);
    virtual void dropDatabase(string dbName);
    virtual void useDatabase(string dbName);
    virtual void showTables();


    // TbStmt
    virtual void createTable(string tbName, list<SchemaEntry> fieldList);
	virtual void dropTable(string tbName);
	virtual void descTable(string tbName);
    virtual void insertIntoTable(string tbName, list< list<Value> > valuesList);
	virtual void deleteFromTable(string tbName, list<Condition> condList);
    virtual void updateTable(string tbName, list<Set> setList, list<Condition> condList);
    virtual void selectFromTable(list<Selector> selectorList, list<string> tableList, list<Condition> condList);

	// IdxStmt
    virtual void createIndex(string tbName, string colName);
    virtual void dropIndex(string tbName, string colName);

private:
    bool haveCurrentDatabase;
    string currentDatabaseName;
    map<string, Database> databases;
};

#endif  // SYSTEM_MANAGER_INTERFACE_H
