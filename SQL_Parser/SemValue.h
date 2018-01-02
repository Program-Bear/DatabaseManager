#ifndef _SEM_VALUE_H
#define _SEM_VALUE_H

#include <vector>
#include <string>
#include "Set.h"
#include "Expr.h"
#include "Value.h"
#include "Selector.h"
#include "Condition.h"
#include "SchemaEntry.h"

using std::string;
using std::vector;

class SemValue
{
public:
	// IDENTIFIER Name
    string id;
	
	// VALUE_INT Value
	int length;
    
    // VALUE_STRING String
	string literal;
    
    // VALUE_FLOAT float
    double float_value;
    
    // Type (eg: INT(VALUE_INT), VARCHAR(VALUE_INT))
    string dataType;
    
    // FieldList & Field
    vector<SchemaEntry> schemaList;
    SchemaEntry schemaEntry;
	
	// ValueLists & ValueList & Value
	vector< vector<Value> > valuesList;
	vector<Value> values;
	Value value;
	
	// ColumnList 
	vector<string> columnList;
	
	// TableList
	vector<string> tableList;
	
	// SetClause
	Set set;
	vector<Set> setList;
	
	// Selector
	Selector selector;
	vector<Selector> selectorList;
	
	// Col : [TbName .] ColName
	Attr col;
	
	// Expr : Col | Value
	Expr expr;
	
	// Op
	string optr;
	
	// Keyword Code 
    int code;
    
    // WhereClauseList & WhereClause
    vector<Condition> condList;
    Condition cond;
	
	// For Generating Keywords
    static int keyword(int);
};

#endif
