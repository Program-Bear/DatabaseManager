#include <iostream>
#include "SystemManagerInterface.h"


// SysStmt
void SystemManagerInterface::showDatabases()
{
    cout << ">>>>showDataBases()" << endl;
    cout << ">>>>success" << endl;
    // TODO show
}


// DbStmt
void SystemManagerInterface::createDatabase(string dbName)
{
    cout << ">>>>createDataBase(" << dbName << ")" << endl;

    bool res = databases.insert(pair<string, Database>(dbName, Database(dbName))).second;

    if (!res)
    {
        cout << ">>>>ERROR : This name already exists" << endl;
    }
    else
    {
        cout << ">>>>success" << endl;
        // TODO insert 
    }
}

void SystemManagerInterface::dropDatabase(string dbName)
{
    cout << ">>>>dropDataBase(" << dbName << ")" << endl;

    int res = databases.erase(dbName);

    if (res) 
    {
        if (haveCurrentDatabase && dbName == currentDatabaseName)
        {
            haveCurrentDatabase = false;
            currentDatabaseName = "";
        }

        cout << ">>>>success" << endl;
        // TODO drop
    }
    else
    {
        cout << ">>>>ERROR : Database " << dbName << " does not exist" << endl;
    }

}

void SystemManagerInterface::useDatabase(string dbName)
{
    cout << ">>>>useDatabase(" << dbName << ")" << endl;

    if (databases.count(dbName))
    {
        haveCurrentDatabase = true;
        currentDatabaseName = dbName;

        cout << ">>>>success" << endl;
        // TODO use
    }
    else
    {
        if (!haveCurrentDatabase)
        {
            currentDatabaseName = "";
        }
     
        cout << ">>>>ERROR : Database " << dbName << " does not exist" << endl;
    }
}

void SystemManagerInterface::showTables()
{
    cout << ">>>>showTables()" << endl;
    cout << ">>>>success" << endl;
    // TODO show
}


// TbStmt
void SystemManagerInterface::createTable(string tbName, list<SchemaEntry> fieldList)
{
    cout << ">>>>createTable(" << tbName << ", FieldList)" << endl;
    cout << ">>>>FieldList.size: " << fieldList.size() << endl;

    for (SchemaEntry se : fieldList)
    {
        cout << ">>>>    " << se.field << " " << se.type << " " << se.length << " " << se.notNull << endl;
                                
        if (se.entrykind == SchemaEntry::PRIMARY_KIND)
        {
            cout << ">>>>        primaryKeyList.size: " << se.primaryKeyList.size() << endl;

            for (auto name : se.primaryKeyList)
            {
                cout << ">>>>            primaryKey: " << name << endl;
            } 
        }

        if (se.entrykind == SchemaEntry::FOREIGN_KIND)
        {
            cout << ">>>>        foreignKey: " << se.foreignKey << endl;
            cout << ">>>>        foreignAttr.tbname: " << se.foreignAttr.tbname << endl;
            cout << ">>>>        foreignAttr.attrname: " << se.foreignAttr.attrname << endl;
        }
    }

    if (!haveCurrentDatabase)
    {
        cout << ">>>>ERROR : You haven't chosen a database yet" << endl;
    }
    else
    {
        if (!databases[currentDatabaseName].tables.count(tbName))
        {
            Table table = Table(tbName);
            
            for (auto se : fieldList)
            {                 
                if (se.entrykind == SchemaEntry::NORMAL_KIND)
                {
                    Column column = Column(se.field, se.type, se.length, se.notNull);
                    table.columns.insert(pair<string, Column>(se.field, column));
                }
            }

            for (auto se : fieldList)
            { 
                if (se.entrykind == SchemaEntry::FOREIGN_KIND)
                {
                    if (!table.columns.count(se.foreignKey))
                    {
                        cout << ">>>>ERROR : Foreign key " << se.foreignKey << " is not declared" << endl;
                        return;
                    }

                    if (!databases[currentDatabaseName].tables.count(se.foreignAttr.tbname))
                    {
                        cout << ">>>>ERROR : Table " << se.foreignAttr.tbname << " does not exist" << endl;
                        return;
                    }

                    if (!databases[currentDatabaseName].tables[se.foreignAttr.tbname].columns.count(se.foreignAttr.attrname))
                    {
                        cout << ">>>>ERROR : Table " << se.foreignAttr.tbname << " does not have key " << se.foreignAttr.attrname << endl;
                        return;
                    }

                    Column column = Column(se.foreignKey, true, se.foreignAttr.tbname, se.foreignAttr.attrname);
                    table.columns.insert(pair<string, Column>(se.field, column));
                }
            }

            databases[currentDatabaseName].tables.insert(pair<string, Table>(tbName, table));
            cout << ">>>>success" << endl;
            // TODO create
        }
        else
        {
            cout << "ERROR : Table " << tbName << " already exists in current database" << endl;
        }
    }
}

void SystemManagerInterface::dropTable(string tbName)
{
    cout << ">>>>dropTable(" << tbName << ")" << endl;

    if (!haveCurrentDatabase)
    {
        cout << ">>>>ERROR : You haven't chosen a database yet" << endl;
    }
    else
    {
        if (databases[currentDatabaseName].tables.erase(tbName))
        {
            cout << ">>>>success" << endl;
            // TODO delete
        }
        else
        {
            cout << "ERROR : Table " << tbName << " does not exist in current database" << endl;
        }
    }
}

void SystemManagerInterface::descTable(string tbName)
{
    cout << ">>>>descTable(" << tbName << ")" << endl;

    if (!haveCurrentDatabase)
    {
        cout << ">>>>ERROR : You haven't chosen a database yet" << endl;
    }
    else
    {
        if (databases[currentDatabaseName].tables.count(tbName))
        {
            // TODO desc
            cout << ">>>>success" << endl;
        }
        else
        {
            cout << "ERROR : Table " << tbName << " does not exist in current database" << endl;
        }
    }
}

void SystemManagerInterface::insertIntoTable(string tbName, list< list<Value> > valuesList)
{
    cout << ">>>>insertIntoTable(" << tbName << ", ValueLists)" << endl;
    cout << ">>>>ValueLists.size: " << valuesList.size() << endl;

    for (auto values : valuesList)
    {
        cout << ">>>>    ValueList.size: " << values.size() << endl;

        for (auto value : values)
        {
            cout << ">>>>        " << value.type << " " << value.integer << " " << value.literal << endl;
        }
    }
}

void SystemManagerInterface::deleteFromTable(string tbName, list<Condition> condList)
{
    cout << ">>>>deleteFromTable(" << tbName << ", WhereClauseList)" << endl;
    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        if (cond.condType == Condition::COL_EXPR_TYPE)
        {
            cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
            cout << " " << cond.optr << " ";
                            
            if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
            {
                cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
            }
            else
            {
                cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
            }
                            
        }
        else if (cond.condType == Condition::COL_LIKE_VALUE_TYPE)
        {
        	cout << ">>>>WhereClause: COL_LIKE_VALUE_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " LIKE " << cond.value.type << " " << cond.value.integer << " " << cond.value.literal << endl;
        }
        else if (cond.condType == Condition::COL_IS_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
        }
        else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
        }
    }
}

void SystemManagerInterface::updateTable(string tbName, list<Set> setList, list<Condition> condList)
{
    cout << ">>>>updateTable(" << tbName << ", SetClause , WhereClauseList)" << endl;
    cout << ">>>>SetClause.size: " << setList.size() << endl;

    for (Set set : setList)
    {
        cout << ">>>>    " << set.colName << " = ";
        cout << set.value.type << " " << set.value.integer << " " << set.value.literal << endl;
    }

    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        if (cond.condType == Condition::COL_EXPR_TYPE)
        {
            cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
            cout << " " << cond.optr << " ";
                            
            if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
            {
                cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
            }
            else
            {
                cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
            }
                            
        }
        else if (cond.condType == Condition::COL_LIKE_VALUE_TYPE)
        {
        	cout << ">>>>WhereClause: COL_LIKE_VALUE_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " LIKE " << cond.value.type << " " << cond.value.integer << " " << cond.value.literal << endl;
        }
        else if (cond.condType == Condition::COL_IS_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
                             
        }
        else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
        }
    }
}

void SystemManagerInterface::selectFromTable(list<Selector> selectorList, list<string> tableList, list<Condition> condList)
{
    cout << ">>>>selectFromTable(Selector, TableList , WhereClauseList)" << endl;
    cout << ">>>>Selector.size: " << selectorList.size() << endl;

    for (Selector se : selectorList)
    {
        if (se.selectorType == Selector::SELECTOR_ALL_TYPE)
        {
            cout << ">>>>    *" << endl;
        }
        else if (se.selectorType == Selector::SELECTOR_SUM_TYPE)
        {
            cout << ">>>>    SUM(" << se.col.tbname << "." << se.col.attrname << ")" << endl;
        }
        else if (se.selectorType == Selector::SELECTOR_AVG_TYPE)
        {
            cout << ">>>>    AVG(" << se.col.tbname << "." << se.col.attrname << ")" << endl;
        }
        else if (se.selectorType == Selector::SELECTOR_MAX_TYPE)
        {
            cout << ">>>>    MAX(" << se.col.tbname << "." << se.col.attrname << ")" << endl;
        }
        else  // se.selectorType == Selector::SELECTOR_MIN_TYPE
        {
            cout << ">>>>    MIN(" << se.col.tbname << "." << se.col.attrname << ")" << endl;
        }
        
    }

    cout << ">>>>TableList.size: " << tableList.size() << endl;

    for (string s : tableList)
    {
        cout << ">>>>    " << s << endl;
    }

    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        if (cond.condType == Condition::COL_EXPR_TYPE)
        {
            cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
            cout << " " << cond.optr << " ";
                            
            if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
            {
                cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
            }
            else
            {
                cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
            }
                            
        }
        else if (cond.condType == Condition::COL_LIKE_VALUE_TYPE)
        {
        	cout << ">>>>WhereClause: COL_LIKE_VALUE_TYPE" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " LIKE " << cond.value.type << " " << cond.value.integer << " " << cond.value.literal << endl;
        }
        else if (cond.condType == Condition::COL_IS_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
                             
        }
        else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
        {
            cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
            cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
        }
    }  
}


// IdxStmt
void SystemManagerInterface::createIndex(string tbName, string colName)
{
    cout << ">>>>createIndex(" << tbName << ", " << colName << ")" << endl;
}

void SystemManagerInterface::dropIndex(string tbName, string colName)
{
    cout << ">>>>dropIndex(" << tbName << ", " << colName << ")" << endl;
}
