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
    SystemManagerInterface() : haveCurrentDatabase(false), currentDatabase(nullptr) {}


    // SysStmt
    virtual void showDatabases();


    // DbStmt
    virtual void createDatabase(string dbName);
    virtual void dropDatabase(string dbName);
    virtual void useDatabase(string dbName);
    virtual void showTables();


    // TbStmt
    virtual void createTable(string tbName, vector<SchemaEntry> fieldList);
	virtual void dropTable(string tbName);
	virtual void descTable(string tbName);
    virtual void insertIntoTable(string tbName, vector< vector<Value> > valuesList);
	virtual void deleteFromTable(string tbName, vector<Condition> condList);
    virtual void updateTable(string tbName, vector<Set> setList, vector<Condition> condList);
    virtual void selectFromTable(vector<Selector> selectorList, vector<string> tableList, vector<Condition> condList);

	// IdxStmt
    virtual void createIndex(string tbName, string colName);
    virtual void dropIndex(string tbName, string colName);

private:
    // private method
    bool validColumn(Attr col);                                            // need col.tbname, col.attrname and currentDatabase confirmed
    bool validWhereClause(string tbName, Condition & cond);                  // need tbName valid
    bool validWhereClauseList(string tbName, vector<Condition> condList);  // need tbName valid

    // vars
    bool haveCurrentDatabase;
    Database * currentDatabase;
    map<string, Database> databases;
};

#endif  // SYSTEM_MANAGER_INTERFACE_H
