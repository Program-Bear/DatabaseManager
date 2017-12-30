#include <iostream>
#include "SystemManagerInterface.h"


// SysStmt
void SystemManagerInterface::showDatabases()
{
    cout << ">>>>showDataBases()" << endl;
}


// DbStmt
void SystemManagerInterface::createDatabase(string dbName)
{
    cout << ">>>>createDataBase(" << dbName << ")" << endl;
}

void SystemManagerInterface::dropDatabase(string dbName)
{
    cout << ">>>>dropDataBase(" << dbName << ")" << endl;
}

void SystemManagerInterface::useDatabase(string dbName)
{
    cout << ">>>>useDatabase(" << dbName << ") called" << endl;
}

void SystemManagerInterface::showTables()
{
    cout << ">>>>showTables()" << endl;
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
}

void SystemManagerInterface::dropTable(string tbName)
{
    cout << ">>>>dropTable(" << tbName << ")" << endl;
}

void SystemManagerInterface::descTable(string tbName)
{
    cout << ">>>>descTable(" << tbName << ")" << endl;
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
    cout << ">>>>updateTable(" << tbName << ", SetClause , WhereClauseList) called" << endl;                  
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
        else
        {
            cout << ">>>>    " << se.col.tbname << "." << se.col.attrname << endl;
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
