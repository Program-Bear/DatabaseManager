#ifndef _SEM_VALUE_H
#define _SEM_VALUE_H

#include <list>
#include <string>
#include "Set.h"
#include "Expr.h"
#include "Value.h"
#include "Selector.h"
#include "Condition.h"
#include "SchemaEntry.h"

using std::string;
using std::list;

class SemValue
{
public:
	// IDENTIFIER Name
    string id;
	
	// VALUE_INT Value
	int length;
    
    // VALUE_STRING String
	string literal;
    
    // Type (eg: INT(VALUE_INT), VARCHAR(VALUE_INT))
    string dataType;
    
    // FieldList & Field
    list<SchemaEntry> schemaList;
    SchemaEntry schemaEntry;
	
	// ValueLists & ValueList & Value
	list< list<Value> > valuesList;
	list<Value> values;
	Value value;
	
	// ColumnList 
	list<string> columnList;
	
	// TableList
	list<string> tableList;
	
	// SetClause
	Set set;
	list<Set> setList;
	
	// Selector
	Selector selector;
	list<Selector> selectorList;
	
	// Col : [TbName .] ColName
	Attr col;
	
	// Expr : Col | Value
	Expr expr;
	
	// Op
	string optr;
	
	// Keyword Code 
    int code;
    
    // WhereClauseList & WhereClause
    list<Condition> condList;
    Condition cond;
	
	// For Generating Keywords
    static int keyword(int);
};

#endif
