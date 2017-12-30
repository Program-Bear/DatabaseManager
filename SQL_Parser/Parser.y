%{
    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <unistd.h>
    #include "SemValue.h"
    #include "SystemManagerInterface.cpp"
    #define YYSTYPE SemValue
    using namespace std;

    extern "C"
    {
        void yyerror(const char*);
        
        int yylex(void);
        
        int yywrap();

        int yyparse(void);
    }

    SystemManagerInterface manager;
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// place any declarations here
%token DATABASE     DATABASES     TABLE        TABLES       SHOW       CREATE
%token DROP         USE           PRIMARY      KEY          NOT        NULLL
%token INSERT       INTO          VALUES       DELETE       FROM       WHERE
%token UPDATE       SET           SELECT       IS           INT        VARCHAR
%token DESC         INDEX         AND          DATE         FLOAT      FOREIGN
%token REFERENCES   
%token NEQ          LTE           GTE
%token IDENTIFIER
%token VALUE_INT
%token VALUE_STRING
%token LITERAL

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

Program             :   /* empty */ 
                        {
                            /* do nothing */
                            //cout << "Program : /* empty */" << endl;
                        }
                    |   Program Stmt
                        {
                            //cout << "Program : Program Stmt" << endl;
                            cout << ">>>>Context End" << endl;
                        }
                    ;

Stmt                :   SysStmt
                        {
                            //cout << "Stmt : SysStmt ';'" << endl;
                        }
                    |   DbStmt
                        {
                            //cout << "Stmt : DbStmt ';'" << endl;
                        }
                    |   TbStmt
                        {
                            //cout << "Stmt : TbStmt ';'" << endl;
                        }
                    |   IdxStmt
                        {
                            //cout << "Stmt : IdxStmt ';'" << endl;
                        }
                    ;

SysStmt             :   SHOW DATABASES ';'
                        {
                            manager.showDatabases();

                            //cout << "SysStmt : SHOW DATABASES" << endl;
                            //cout << ">>>>SystemManager::showDataBases() called" << endl;
                        }
                    ;

DbStmt              :   CREATE DATABASE DbName ';'
                        {
                            manager.createDatabase($3.id);

                            //cout << "DbStmt : CREATE DATABASE DbName" << endl;
                            //cout << ">>>>SystemManager::createDataBase(" << $3.id << ") called" << endl;
                        }
                    |   DROP DATABASE DbName ';'
                        {
                            manager.dropDatabase($3.id);

                            //cout << "DbStmt : DROP DATABASE DbName" << endl;
                            //cout << ">>>>SystemManager::dropDataBase(" << $3.id << ") called" << endl;
                        }
                    |   USE DbName ';'
                        {
                            manager.useDatabase($2.id);

                            //cout << "DbStmt : USE DbName" << endl;
                            //cout << ">>>>SystemManager::use(" << $2.id << ") called" << endl;
                        }
                    |   SHOW TABLES ';'
                        {
                            manager.showTables();

                            //cout << "DbStmt : SHOW TABLES" << endl;
                            //cout << ">>>>SystemManager::showTables() called" << endl;
                        }
                    ;                    

TbStmt              :   CREATE TABLE TbName '(' FieldList ')' ';'
                        {
                            manager.createTable($3.id, $5.schemaList);

                            //cout << "TbStmt : CREATE TABLE '(' FieldList ')'" << endl;
                            /*cout << ">>>>SystemManager::createTable(" << $3.id << ", FieldList) called" << endl;
                            cout << ">>>>FieldList.size: " << $5.schemaList.size() << endl;
                            for (SchemaEntry se : $5.schemaList)
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
                            }*/
                        }
                    |   DROP TABLE TbName ';'
                        {
                            manager.dropTable($3.id);

                            //cout << "TbStmt : DROP TABLE TbName" << endl;
                            //cout << ">>>>SystemManager::dropTable(" << $3.id << ") called" << endl;
                        }
                    |   DESC TbName ';'
                        {
                            manager.descTable($2.id);

                            //cout << "TbStmt : DESC TbName" << endl;
                            //cout << ">>>>SystemManager::desc(" << $2.id << ") called" << endl;
                        }
                    |   INSERT INTO TbName VALUES ValueLists ';'
                        {
                            manager.insertIntoTable($3.id, $5.valuesList);

                            //cout << "TbStmt : INSERT INTO TbName VALUES ValueLists" << endl;
                            /*cout << ">>>>SystemManager::insertIntoTableWithValues(" << $3.id << ", ValueLists) called" << endl;
                            cout << ">>>>ValueLists.size: " << $5.valuesList.size() << endl;

                            for (auto values : $5.valuesList)
                            {
                                cout << ">>>>    ValueList.size: " << values.size() << endl;

                                for (auto value : values)
                                {
                                    cout << ">>>>        " << value.type << " " << value.integer << " " << value.literal << endl;
                                }
                            }*/
                        }
                    |   DELETE FROM TbName WHERE WhereClauseList ';'
                        {
                            manager.deleteFromTable($3.id, $5.condList);

                            //cout << "TbStmt : DELETE FROM TbName WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::deleteFromTableWhere(" << $3.id << ", WhereClauseList) called" << endl;
                            cout << ">>>>WhereClauseList.size: " << $5.condList.size() << endl;

                            for (Condition cond : $5.condList)
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
                            }*/
                        }
                    |   UPDATE TbName SET SetClause WHERE WhereClauseList ';'
                        {
                            manager.updateTable($2.id, $4.setList, $6.condList);

                            //cout << "TbStmt : UPDATE TbName SET SetClause WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::updateTableSetWhere(" << $2.id << ", SetClause , WhereClauseList) called" << endl;
                            
                            cout << ">>>>SetClause.size: " << $4.setList.size() << endl;

                            for (Set set : $4.setList)
                            {
                                cout << ">>>>    " << set.colName << " = ";
                                cout << set.value.type << " " << set.value.integer << " " << set.value.literal << endl;
                            }

                            cout << ">>>>WhereClauseList.size: " << $6.condList.size() << endl;

                            for (Condition cond : $6.condList)
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
                            }*/                            
                        }
                    |   SELECT Selector FROM TableList WHERE WhereClauseList ';'
                        {
                            manager.selectFromTable($2.selectorList, $4.tableList, $6.condList);

                            //cout << "TbStmt : SELECT Selector FROM TableList WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::SelectFromTableWhere(Selector, TableList , WhereClauseList) called" << endl;

                            cout << ">>>>Selector.size: " << $2.selectorList.size() << endl;

                            for (Selector se : $2.selectorList)
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

                            cout << ">>>>TableList.size: " << $4.tableList.size() << endl;

                            for (string s : $4.tableList)
                            {
                                cout << ">>>>    " << s << endl;
                            }

                            cout << ">>>>WhereClauseList.size: " << $6.condList.size() << endl;

                            for (Condition cond : $6.condList)
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
                            }*/  
                        }
                    ;                            

IdxStmt             :   CREATE INDEX TbName '(' ColName ')' ';'
                        {
                            manager.createIndex($3.id, $5.id);

                            //cout << "IdxStmt : CREATE INDEX TbName '(' ColName ')'" << endl;
                            //cout << ">>>>SystemManager::createIndex(" << $3.id << ", " << $5.id << ") called" << endl;
                        }
                    |   DROP INDEX TbName '(' ColName ')' ';'
                        {
                            manager.dropIndex($3.id, $5.id);

                            //cout << "IdxStmt : DROP INDEX TbName '(' ColName ')'" << endl;
                            //cout << ">>>>SystemManager::dropIndex(" << $3.id << ", " << $5.id << ") called" << endl;
                        } 
                    ;      

FieldList           :   Field
                        {
                            //cout << "FieldList : Field" << endl;
                            $$.schemaList.clear();
                            $$.schemaList.push_back($1.schemaEntry);
                            //cout << ">>>>>>>>" << $1.schemaEntry.field << " " << $1.schemaEntry.type << " " << $1.schemaEntry.length << " " << $1.schemaEntry.notNull << endl;
                            //cout << $$.schemaList.size() << endl;
                        }
                    |   FieldList ',' Field    
                        {
                            //cout << "FieldList : FieldList ',' Field" << endl;
                            $$.schemaList.push_back($3.schemaEntry);
                            //cout << ">>>>>>>>" << $3.schemaEntry.field << " " << $3.schemaEntry.type << " " << $3.schemaEntry.length << " " << $3.schemaEntry.notNull << endl;
                            //cout << $$.schemaList.size() << " -> " << $1.schemaList.size() << endl;
                        }
                    ;
                    
Field               :   ColName Type
                        {
                            //cout << "Field : ColName Type" << endl;
                            $$.schemaEntry = SchemaEntry($1.id, $2.dataType, $2.length, false);
                            $$.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }   
                    |   ColName Type NOT NULLL
                        {
                            //cout << "Field : ColName Type NOT NULLL" << endl;
                            $$.schemaEntry = SchemaEntry($1.id, $2.dataType, $2.length, true);
                            $$.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }   
                    |   PRIMARY KEY '(' ColumnList ')'
                        {
                            //cout << "Field : PRIMARY KEY '(' ColumnList ')'" << endl;
                            $$.schemaEntry.primaryKeyList = $4.columnList;
                            $$.schemaEntry.entrykind = SchemaEntry::PRIMARY_KIND;
                        }
                    |   FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'
                        {
                            //cout << "Field : FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'" << endl;
                            $$.schemaEntry.foreignKey = $4.id;
                            $$.schemaEntry.foreignAttr = Attr($7.id, $9.id);
                            $$.schemaEntry.entrykind = SchemaEntry::FOREIGN_KIND;
                        }
                    ;                                      

Type                :   INT '(' VALUE_INT ')'
                        {
                            //cout << "Type : INT '(' VALUE_INT ')'" << endl;
                            $$.dataType = "int";
                            $$.length = $3.length;
                        }
                    |   VARCHAR '(' VALUE_INT ')'
                        {
                            //cout << "Type : VARCHAR '(' VALUE_INT ')'" << endl;
                            $$.dataType = "varchar";
                            $$.length = $3.length;
                        }   
                    |   DATE
                        {
                            //cout << "Type : DATE" << endl;
                            $$.dataType = "date";
                        }   
                    |   FLOAT
                        {
                            //cout << "Type : FLOAT" << endl;
                            $$.dataType = "float";
                        }
                    ;                     

ValueLists          :   '(' ValueList ')'
                        {
                            //cout << "ValueLists : '(' ValueList ')'" << endl;
                            $$.valuesList.clear();
                            $$.valuesList.push_back($2.values);
                        }
                    |   ValueLists ',' '(' ValueList ')'
                        {
                            //cout << "ValueLists : ValueLists ',' '(' ValueList ')'" << endl;
                            $$.valuesList.push_back($4.values);
                        }
                    ;        

ValueList           :   Value
                        {
                            //cout << "ValueList : Value" << endl;
                            $$.values.clear();
                            $$.values.push_back($1.value);
                        }
                    |   ValueList ',' Value
                        {
                            //cout << "ValueList : ValueList ',' Value" << endl;
                            $$.values.push_back($3.value);
                        }
                    ;

Value               :   VALUE_INT
                        {
                            //cout << "Value : VALUE_INT" << endl;
                            $$.value = Value(Value::VALUE_INT_TYPE, $1.length, "");
                        }
                    |   VALUE_STRING
                        {
                            //cout << "Value : VALUE_STRING" << endl;
                            $$.value = Value(Value::VALUE_STRING_TYPE, $0.length, $1.literal);
                        }
                    |   NULLL
                        {
                            //cout << "Value : NULLL" << endl;
                            $$.value = Value(Value::VALUE_NULL_TYPE, 0, "");
                        }
                    ;                                                

WhereClauseList     :   WhereClause
                        {
                            $$.condList.clear();
                            $$.condList.push_back($1.cond);
                            //cout << $$.condList.size() << endl;
                        }
                    |   WhereClauseList AND WhereClause
                        {
                            
                            $$.condList.push_back($3.cond);
                            //cout << $$.condList.size() << endl;

                        }
                    ;

WhereClause         :   Col Op Expr
                        {
                            //cout << "WhereClause : Col Op Expr" << endl;
                            $$.cond = Condition(Condition::COL_EXPR_TYPE);
                            $$.cond.col = $1.col;
                            $$.cond.optr = $2.optr;
                            $$.cond.expr = $3.expr;
                        }
                    |   Col IS NULLL
                        {
                            //cout << "WhereClause : Col IS NULLL" << endl;
                            $$.cond = Condition(Condition::COL_IS_NULL_TYPE);
                            $$.cond.col = $1.col;
                        }
                    |   Col IS NOT NULLL
                        {
                            //cout << "WhereClause : Col IS NOT NULLL" << endl;
                            $$.cond = Condition(Condition::COL_IS_NOT_NULL_TYPE);
                            $$.cond.col = $1.col;
                        }
                    ;                   

Col                 :   ColName
                        {
                            //cout << "Col : ColName" << endl;
                            $$.col = Attr("", $1.id);
                        }
                    |   TbName '.' ColName
                        {
                            //cout << "Col : TbName '.' ColName" << endl;
                            $$.col = Attr($1.id, $3.id);
                        }    
                    ;

Op                  :   '='
                        {
                            //cout << "Op : '='" << endl;
                            $$.optr = "=";
                        }
                    |   NEQ
                        {
                            //cout << "Op : '<>'" << endl;
                            $$.optr = "<>";
                        }
                    |   LTE
                        {
                            //cout << "Op : '<='" << endl;
                            $$.optr = "<=";
                        }
                    |   GTE
                        {
                            //cout << "Op : '>='" << endl;
                            $$.optr = ">=";
                        }
                    |   '<'
                        {
                            //cout << "Op : '<'" << endl;
                            $$.optr = "<";
                        }
                    |   '>'
                        {
                            //cout << "Op : '>'" << endl;
                            $$.optr = ">";
                        }
                    ;
                                             
Expr                :   Value
                        {
                            //cout << "Expr : Value" << endl;
                            $$.expr = Expr();
                            $$.expr.dataType = Expr::VALUE_EXPR_TYPE;
                            $$.expr.value = $1.value;
                        }
                    |   Col
                        {
                            //cout << "Expr : Col" << endl;
                            $$.expr = Expr();
                            $$.expr.dataType = Expr::COL_EXPR_TYPE;
                            $$.expr.col = $1.col;
                        }
                    ;

SetClause           :   ColName '=' Value
                        {
                            //cout << "SetClause : ColName '=' Value" << endl;
                            $$.setList.clear();
                            $$.setList.push_back(Set($1.id, $3.value));
                        }
                    |   SetClause ',' ColName '=' Value
                        {
                            //cout << "SetClause : SetClause ',' ColName '=' Value" << endl;
                            $$.setList.push_back(Set($3.id, $5.value));
                        }
                    ;

Selector            :   '*'
                        {
                            //cout << "Selector : '*'" << endl;
                            $$.selectorList.clear();
                            $$.selectorList.push_back(Selector::SELECTOR_ALL_TYPE);
                        }  
                    |   Col
                        {
                            $$.selectorList.clear();
                            $$.selectorList.push_back(Selector(Selector::SELECTOR_COL_TYPE, $1.col));                            
                        }             
                    |   Selector ',' Col
                        {
                            //cout << "Selector : SubSelector Col" << endl;
                            $$.selectorList.push_back(Selector(Selector::SELECTOR_COL_TYPE, $3.col));

                        }
                    ;                                                                                                                  

TableList           :   TbName
                        {
                            //cout << "TableList : TbName" << endl;
                            $$.tableList.clear();
                            $$.tableList.push_back($1.id);
                        }
                    |   TableList ',' TbName
                        {
                            //cout << "TableList : TableList ',' TbName" << endl;
                            $$.tableList.push_back($3.id);
                        }
                    ;

ColumnList          :   ColName
                        {
                            //cout << "ColumnList : ColName" << endl;
                            $$.columnList.clear();
                            $$.columnList.push_back($1.id);
                        }
                    |   ColumnList ',' ColName
                        {
                            //cout << "ColumnList : ColumnList ',' ColName" << endl;
                            $$.columnList.push_back($3.id);
                        }    
                    ; 

DbName              :   IDENTIFIER
                        {
                            //cout << "DbName : " << $1 << endl;
                            $$.id = $1.id;
                        }
                    ;

TbName              :   IDENTIFIER
                        {
                            //cout << "TbName : " << $1 << endl;
                            $$.id = $1.id;
                        }
                    ;

ColName             :   IDENTIFIER
                        {
                            //cout << "ColName : " << $1 << endl;
                            $$.id = $1.id;
                        }
                    ;                                                                                                                      
                         

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
void yyerror(const char *s)
{
    cout << "yyerror: " << s << endl;
}


int main()
{
    yyparse();
    return 0;
}

