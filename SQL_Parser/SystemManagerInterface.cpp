#include <iostream>
#include "SystemManagerInterface.h"


// SysStmt
void SystemManagerInterface::showDatabases()
{
    cout << ">>>>showDataBases()" << endl;
    cout << ">>>>success" << endl << endl;
    // TODO show
}


// DbStmt
void SystemManagerInterface::createDatabase(string dbName)
{
    cout << ">>>>createDataBase(" << dbName << ")" << endl;

    // static check
    bool res = databases.insert(pair<string, Database>(dbName, Database(dbName))).second;

    if (!res)
    {
        cerr << ">>>>ERROR : This name already exists" << endl << endl;
    }
    else
    {
        cout << ">>>>success" << endl << endl;
        // TODO insert 
    }
}

void SystemManagerInterface::dropDatabase(string dbName)
{
    cout << ">>>>dropDataBase(" << dbName << ")" << endl;

    // static check
    int res = databases.erase(dbName);

    if (res) 
    {
        if (haveCurrentDatabase && dbName == currentDatabase->dbName)
        {
            haveCurrentDatabase = false;
            currentDatabase = nullptr;
        }

        cout << ">>>>success" << endl << endl;
        // TODO drop
    }
    else
    {
        cerr << ">>>>ERROR : Database " << dbName << " does not exist" << endl << endl;
    }

}

void SystemManagerInterface::useDatabase(string dbName)
{
    cout << ">>>>useDatabase(" << dbName << ")" << endl;

    // static check
    if (databases.count(dbName))
    {
        haveCurrentDatabase = true;
        currentDatabase = &databases[dbName];

        cout << ">>>>success" << endl << endl;
        // TODO use
    }
    else
    {
        if (!haveCurrentDatabase)
        {
            currentDatabase = nullptr;
        }
        
        cerr << ">>>>ERROR : Database " << dbName << " does not exist" << endl << endl;
    }
}

void SystemManagerInterface::showTables()
{
    cout << ">>>>showTables()" << endl;
    cout << ">>>>success" << endl << endl;
    // TODO show
}


// TbStmt
void SystemManagerInterface::createTable(string tbName, vector<SchemaEntry> fieldList)
{
    cout << ">>>>createTable(" << tbName << ", FieldList)" << endl;
    cout << ">>>>FieldList.size: " << fieldList.size() << endl;

    for (SchemaEntry se : fieldList)
    {
        cout << ">>>>    " << se.toString() << endl;
    }

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (!currentDatabase->tables.count(tbName))
        {
            Table table = Table(tbName);
            
            for (auto se : fieldList)
            {                 
                if (se.entrykind == SchemaEntry::NORMAL_KIND)
                {
                    Column column = Column(se.field, se.type, se.length, se.notNull);
                    table.columns.insert(pair<string, Column>(se.field, column));
                    table.columnVector.emplace_back(column);
                }
                else if (se.entrykind == SchemaEntry::PRIMARY_KIND)
                {
                    for (auto name : se.primaryKeyList)
                    {
                        if (!table.columns.count(name))
                        {
                            cerr << ">>>>ERROR : Primary key " << name << " is not declared" << endl << endl;
                            return;
                        }
                        
                        if (!table.columns[name].isNotNull)
                        {
                            cerr << ">>>>ERROR : Primary key " << name << " must go with NOT NULL restriction" << endl << endl;
                            return;
                        }
                    } 
                }
                else if (se.entrykind == SchemaEntry::FOREIGN_KIND)
                {
                    if (!table.columns.count(se.foreignKey))
                    {
                        cerr << ">>>>ERROR : Foreign key " << se.foreignKey << " is not declared" << endl << endl;
                        return;
                    }

                    if (!currentDatabase->tables.count(se.foreignAttr.tbname))
                    {
                        cerr << ">>>>ERROR : Table " << se.foreignAttr.tbname << " does not exist" << endl << endl;
                        return;
                    }

                    if (!currentDatabase->tables[se.foreignAttr.tbname].columns.count(se.foreignAttr.attrname))
                    {
                        cerr << ">>>>ERROR : Table " << se.foreignAttr.tbname << " does not have key " << se.foreignAttr.attrname << endl << endl;
                        return;
                    }

                    table.columns[se.foreignKey].isForeign = true;
                    table.columns[se.foreignKey].referenceTableName = se.foreignAttr.tbname;
                    table.columns[se.foreignKey].referenceTableName = se.foreignAttr.attrname;
                }
            }

            currentDatabase->tables.insert(pair<string, Table>(tbName, table));
            cout << ">>>>success" << endl << endl;
            // TODO create
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " already exists in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::dropTable(string tbName)
{
    cout << ">>>>dropTable(" << tbName << ")" << endl;

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.erase(tbName))
        {
            cout << ">>>>success" << endl << endl;
            // TODO delete
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " does not exist in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::descTable(string tbName)
{
    cout << ">>>>descTable(" << tbName << ")" << endl;

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            // TODO desc
            cout << ">>>>success" << endl << endl;
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " does not exist in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::insertIntoTable(string tbName, vector< vector<Value> > valuesList)
{
    cout << ">>>>insertIntoTable(" << tbName << ", ValueLists)" << endl;
    cout << ">>>>ValueLists.size: " << valuesList.size() << endl;

    for (auto values : valuesList)
    {
        cout << ">>>>    ValueList.size: " << values.size() << endl;

        for (auto value : values)
        {
            cout << ">>>>        " << value.toString() << endl;
        }
    }
    
    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            Table & table = currentDatabase->tables[tbName];

            for (int j = 0; j < valuesList.size(); j++)  // for each values pair 
            {
                vector<Value> values = valuesList[j];

                if (values.size() != table.columns.size())
                {
                    cerr << ">>>>ERROR : Size of ValueList doesn't match that of table " << tbName << endl << endl;
                    return;
                }
                
                for (int i = 0; i < values.size(); i++)
                {
                    Value::ValueCompatiblity vc = table.columnVector[i].typeCompatible(values[i]);
                    
                    if (vc == Value::VALUE_NOT_COMPAT)
                    {
                        cerr << ">>>>ERROR : Datatype of " << i + 1 << "th value " << values[i].typeString() << " in ValueList " << j + 1 << " doesn't match that of table " << tbName << ", " << table.columnVector[i].dataType << " wanted" << endl << endl;
                        return;
                    }
                    else if (vc == Value::VALUE_INVALID_DATE)
                    {
                        cerr << ">>>>ERROR : " << values[i].toString() << " in ValueList " << j + 1 << " is invalid" << endl << endl;
                        return;
                    }
                }
            }
            
            // TODO insert
            cout << ">>>>success" << endl << endl;
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " does not exist in current database" << endl;
        }
    }
}

bool SystemManagerInterface::validColumn(Attr col)
{
    if (!currentDatabase->tables.count(col.tbname))
    {
        cerr << ">>>>ERROR : Table " << col.tbname << " does not exist in current database" << endl << endl;
        return false;
    }

    if (!currentDatabase->tables[col.tbname].columns.count(col.attrname))
    {
        cerr << ">>>>ERROR : Table " << col.tbname << " does not have key " << col.attrname << endl << endl;
        return false;
    }

    return true;
}

bool SystemManagerInterface::validWhereClause(string tbName, Condition & cond)
{
    // Col Op [Col2 / Value]
    // Col LIKE Value
    // Col IS [NOT] NULL
    
    // Col
    if (cond.col.tbname == "")
    {
        cond.col.tbname = tbName;
    }

    if (!validColumn(cond.col))
    {
        return false;
    }
    
    if (cond.condType == Condition::COL_EXPR_TYPE)  // Col1 Op [Col2 / Value]
    {                            
        // [Col2 / Value]
        if (cond.expr.dataType == Expr::COL_EXPR_TYPE)  // Col2
        {
            if (cond.expr.col.tbname == "")
            {
                cond.expr.col.tbname = tbName;
            }

            if (!validColumn(cond.expr.col))
            {
                return false;
            }
        }
        else  // Value
        {
            Value::ValueCompatiblity vc = currentDatabase->tables[cond.col.tbname].columns[cond.col.attrname].typeCompatible(cond.expr.value);
                    
            if (vc == Value::VALUE_NOT_COMPAT)
            {
                cerr << ">>>>ERROR : Datatype of " << cond.expr.value.typeString() << " doesn't match that of " << cond.col.tbname << "." << cond.col.attrname << endl << endl;
                return false;
            }
            else if (vc == Value::VALUE_INVALID_DATE)
            {
                cerr << ">>>>ERROR : " << cond.expr.value.toString() << " is invalid" << endl << endl;
                return false;
            }
        }       
    }
    else if (cond.condType == Condition::COL_LIKE_VALUE_TYPE)
    {
        if (cond.condType == Condition::COL_EXPR_TYPE)  // Col LIKE Value
        {
            // Value
            Value::ValueCompatiblity vc = currentDatabase->tables[cond.col.tbname].columns[cond.col.attrname].typeCompatible(cond.expr.value);
                    
            if (vc == Value::VALUE_NOT_COMPAT)
            {
                cerr << ">>>>ERROR : Datatype of " << cond.expr.value.typeString() << " doesn't match that of " << cond.col.tbname << "." << cond.col.attrname << endl;
                return false;
            }
            else if (vc == Value::VALUE_INVALID_DATE)
            {
                cerr << ">>>>ERROR : " << cond.expr.value.toString() << " is invalid" << endl << endl;
                return false;
            }
        }
    }

    return true;
}

bool SystemManagerInterface::validWhereClauseList(string tbName, vector<Condition> condList)
{
    for (Condition cond : condList)
    {
        if (!validWhereClause(tbName, cond))
        {
            return false;
        }
    }

    return true;
}

void SystemManagerInterface::deleteFromTable(string tbName, vector<Condition> condList)
{
    cout << ">>>>deleteFromTable(" << tbName << ", WhereClauseList)" << endl;
    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        cout << ">>>>    " << cond.toString() << endl;
    }

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            if (validWhereClauseList(tbName, condList))
            {
                // TODO delete
                cout << ">>>>success" << endl << endl;
            }
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " does not exist in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::updateTable(string tbName, vector<Set> setList, vector<Condition> condList)
{
    cout << ">>>>updateTable(" << tbName << ", SetClause , WhereClauselist)" << endl;
    cout << ">>>>Setclause.size: " << setList.size() << endl;

    for (Set set : setList)
    {
        cout << ">>>>    " << set.colName << " = " << set.value.toString() << endl;
    }

    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        cout << ">>>>    " << cond.toString() << endl;
    }

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            Table & table = currentDatabase->tables[tbName];

            // Set
            for (Set s : setList)
            {
                if (!table.columns.count(s.colName))
                {
                    cerr << ">>>>ERROR : Table " << tbName << " doesn't have key " << s.colName << endl << endl;
                    return;
                }
                
                Value::ValueCompatiblity vc = table.columns[s.colName].typeCompatible(s.value);
                    
                if (vc == Value::VALUE_NOT_COMPAT)
                {
                    cerr << ">>>>ERROR : Datatype " << s.value.typeString() << " doesn't match " << table.columns[s.colName].dataTypeString() << " in key " << s.colName << endl << endl;
                    return;
                }
                else if (vc == Value::VALUE_INVALID_DATE)
                {
                    cerr << ">>>>ERROR : " << s.value.toString() << " is invalid" << endl << endl;
                    return;
                }
            }
            
            // WhereClause
            if (validWhereClauseList(tbName, condList))
            {
                // TODO update
                cout << ">>>>success" << endl << endl;
            }
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " does not exist in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::selectFromTable(vector<Selector> selectorList, vector<string> tableList, vector<Condition> condList)
{
    cout << ">>>>selectFromTable(Selector, TableList , WhereClauseList)" << endl;
    cout << ">>>>Selector.size: " << selectorList.size() << endl;

    for (Selector se : selectorList)
    {
        cout << ">>>>    " << se.toString() << endl;
    }

    cout << ">>>>TableList.size: " << tableList.size() << endl;

    for (string s : tableList)
    {
        cout << ">>>>    " << s << endl;
    }

    cout << ">>>>WhereClauseList.size: " << condList.size() << endl;

    for (Condition cond : condList)
    {
        cout << ">>>>    " << cond.toString() << endl;
    }  

    // static check
    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl;
    }
    else
    {
        // 1. TableList
        for (string s : tableList)
        {
            if (!currentDatabase->tables.count(s))
            {
                cerr << ">>>>ERROR : Table " << s << " doesn't exist in current database" << endl << endl;
                return;
            }
        }

        // 2. SelectorList
        for (Selector & s : selectorList)
        {
            if (s.selectorType != Selector::SELECTOR_ALL_TYPE)
            {
                if (s.col.tbname == "")
                {
                    int properTableCnt = 0;
                    
                    for (string tbName : tableList)
                    {
                        if (currentDatabase->tables[tbName].columns.count(s.col.attrname))
                        {
                            s.col.tbname = tbName;
                            properTableCnt++;
                        }
                    }

                    if (properTableCnt == 0)
                    {
                        cerr << ">>>>ERROR : No table mentioned in TableList has key " << s.col.attrname << endl << endl;
                        return;
                    }

                    if (properTableCnt > 1)
                    {
                        cerr << ">>>>ERROR : Multiple tables mentioned in TableList have key " << s.col.attrname << ", please specify which " << s.col.attrname << " you mean" << endl << endl;
                        return;
                    }
                    
                    if (!currentDatabase->tables[s.col.tbname].columns.count(s.col.attrname))
                    {
                        cerr << ">>>>ERROR : Table " << s.col.tbname << " doesn't have key " << s.col.attrname << endl << endl;
                        return;
                    }

                    if (s.selectorType != Selector::SELECTOR_COL_TYPE && currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType != "int" && currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType != "float")
                    {
                        cerr << ">>>>ERROR : Datatype " << currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType <<  " of " << s.col.tbname << "." << s.col.attrname << " can't be calculated with aggregate function" << endl << endl;
                        return;
                    }
                }
                else
                {
                    if (!currentDatabase->tables.count(s.col.tbname))
                    {
                        cerr << ">>>>ERROR : Table " << s.col.tbname << " doesn't exist in current database" << endl << endl;
                        return;
                    }

                    if (!currentDatabase->tables[s.col.tbname].columns.count(s.col.attrname))
                    {
                        cerr << ">>>>ERROR : Table " << s.col.tbname << " doesn't have key " << s.col.attrname << endl << endl;
                        return;
                    }

                    if (s.selectorType != Selector::SELECTOR_COL_TYPE && currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType != "int" && currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType != "float")
                    {
                        cerr << ">>>>ERROR : Datatype " << currentDatabase->tables[s.col.tbname].columns[s.col.attrname].dataType <<  " of " << s.col.tbname << "." << s.col.attrname << " can't be calculated with aggregate function" << endl << endl;
                        return;
                    }
                }
            }
        }

        // 3. WhereClause
        for (Condition cond : condList)
        {
            if (cond.col.tbname == "")
            {
                cerr << ">>>>ERROR : All columns in WhereClauseList from a SelectStmt must have their tbNames explictly declared" << endl << endl;
                return;
            }
        }

        if (validWhereClauseList("", condList))  // former for stmt ensures all cols have valid col.tbname
        {
            // TODO select
            cout << ">>>>success" << endl << endl;
        }
    }
}


// IdxStmt
void SystemManagerInterface::createIndex(string tbName, string colName)
{
    cout << ">>>>createIndex(" << tbName << ", " << colName << ")" << endl;

    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            Table table = currentDatabase->tables[tbName];
            
            if (!table.columns.count(colName))
            {
                cerr << ">>>>ERROR : Table " << tbName << " doesn't have key " << colName << endl << endl;
                return;
            }

            if (table.columns[colName].hasIndex)
            {
                cerr << ">>>>ERROR : " << tbName << "." << colName << " is already indexed" << endl << endl;
                return;
            }

            table.columns[colName].hasIndex = true;

            cout << ">>>>success" << endl << endl;
            // TODO create
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " doesn't exist in current database" << endl << endl;
        }
    }
}

void SystemManagerInterface::dropIndex(string tbName, string colName)
{
    cout << ">>>>dropIndex(" << tbName << ", " << colName << ")" << endl;

    if (!haveCurrentDatabase)
    {
        cerr << ">>>>ERROR : You haven't chosen a database yet" << endl << endl;
    }
    else
    {
        if (currentDatabase->tables.count(tbName))
        {
            Table table = currentDatabase->tables[tbName];
            
            if (!table.columns.count(colName))
            {
                cerr << ">>>>ERROR : Table " << tbName << " doesn't have key " << colName << endl << endl;
                return;
            }

            if (!table.columns[colName].hasIndex)
            {
                cerr << ">>>>ERROR : " << tbName << "." << colName << " is not indexed" << endl << endl;
                return;
            }

            table.columns[colName].hasIndex = false;

            cout << ">>>>success" << endl << endl;
            // TODO drop
        }
        else
        {
            cerr << ">>>>ERROR : Table " << tbName << " doesn't exist in current database" << endl << endl;
        }
    }
}
