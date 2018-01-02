%{
    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <unistd.h>
    #include "SemValue.h"
    #include "SystemManagerInterface.cpp"
    #define YYSTYPE SemValue
    using namespace std;
    
    extern FILE * yyin;    

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
%token VALUE_DATE
%token VALUE_STRING
%token VALUE_FLOAT
%token LITERAL

%token LIKE

%token SUM
%token AVG
%token MAX
%token MIN

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

Program             :   /* empty */ 
                        {
                            /* do nothing */
                        }
                    |   Program Stmt
                        {

                        }
                    ;

Stmt                :   SysStmt
                        {

                        }
                    |   DbStmt
                        {

                        }
                    |   TbStmt
                        {

                        }
                    |   IdxStmt
                        {

                        }
                    ;

SysStmt             :   SHOW DATABASES ';'
                        {
                            manager.showDatabases();
                        }
                    ;

DbStmt              :   CREATE DATABASE DbName ';'
                        {
                            manager.createDatabase($3.id);
                        }
                    |   DROP DATABASE DbName ';'
                        {
                            manager.dropDatabase($3.id);
                        }
                    |   USE DbName ';'
                        {
                            manager.useDatabase($2.id);
                        }
                    |   SHOW TABLES ';'
                        {
                            manager.showTables();
                        }
                    ;                    

TbStmt              :   CREATE TABLE TbName '(' FieldList ')' ';'
                        {
                            manager.createTable($3.id, $5.schemaList);
                        }
                    |   DROP TABLE TbName ';'
                        {
                            manager.dropTable($3.id);
                        }
                    |   DESC TbName ';'
                        {
                            manager.descTable($2.id);
                        }
                    |   INSERT INTO TbName VALUES ValueLists ';'
                        {
                            manager.insertIntoTable($3.id, $5.valuesList);
                        }
                    |   DELETE FROM TbName WHERE WhereClauseList ';'
                        {
                            manager.deleteFromTable($3.id, $5.condList);
                        }
                    |   UPDATE TbName SET SetClause WHERE WhereClauseList ';'
                        {
                            manager.updateTable($2.id, $4.setList, $6.condList);                      
                        }
                    |   SELECT SelectorList FROM TableList WHERE WhereClauseList ';'
                        {
                            manager.selectFromTable($2.selectorList, $4.tableList, $6.condList);
                        }
                    ;                            

IdxStmt             :   CREATE INDEX TbName '(' ColName ')' ';'
                        {
                            manager.createIndex($3.id, $5.id);
                        }
                    |   DROP INDEX TbName '(' ColName ')' ';'
                        {
                            manager.dropIndex($3.id, $5.id);
                        } 
                    ;      

FieldList           :   Field
                        {
                            $$.schemaList.clear();
                            $$.schemaList.push_back($1.schemaEntry);
                        }
                    |   FieldList ',' Field    
                        {
                            $$.schemaList.push_back($3.schemaEntry);
                        }
                    ;
                    
Field               :   ColName Type
                        {
                            $$.schemaEntry = SchemaEntry($1.id, $2.dataType, $2.length, false);
                            $$.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }   
                    |   ColName Type NOT NULLL
                        {
                            $$.schemaEntry = SchemaEntry($1.id, $2.dataType, $2.length, true);
                            $$.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }   
                    |   PRIMARY KEY '(' ColumnList ')'
                        {
                            $$.schemaEntry.primaryKeyList = $4.columnList;
                            $$.schemaEntry.entrykind = SchemaEntry::PRIMARY_KIND;
                        }
                    |   FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'
                        {
                            $$.schemaEntry.foreignKey = $4.id;
                            $$.schemaEntry.foreignAttr = Attr($7.id, $9.id);
                            $$.schemaEntry.entrykind = SchemaEntry::FOREIGN_KIND;
                        }
                    ;                                      

Type                :   INT '(' VALUE_INT ')'
                        {
                            $$.dataType = "int";
                            $$.length = $3.length;
                        }
                    |   VARCHAR '(' VALUE_INT ')'
                        {
                            $$.dataType = "varchar";
                            $$.length = $3.length;
                        }   
                    |   DATE
                        {
                            $$.dataType = "date";
                        }   
                    |   FLOAT
                        {
                            $$.dataType = "float";
                        }
                    ;                     

ValueLists          :   '(' ValueList ')'
                        {
                            $$.valuesList.clear();
                            $$.valuesList.push_back($2.values);
                        }
                    |   ValueLists ',' '(' ValueList ')'
                        {
                            $$.valuesList.push_back($4.values);
                        }
                    ;        

ValueList           :   Value
                        {
                            $$.values.clear();
                            $$.values.push_back($1.value);
                        }
                    |   ValueList ',' Value
                        {
                            $$.values.push_back($3.value);
                        }
                    ;

Value               :   VALUE_INT
                        {
                            $$.value = Value(Value::VALUE_INT_TYPE, $1.length, "", 0);
                        }
                    |   VALUE_STRING
                        {
                            $$.value = Value(Value::VALUE_STRING_TYPE, 0, $1.literal, 0);
                        }
                    |   VALUE_DATE
                        {
                            $$.value = Value(Value::VALUE_DATE_TYPE, 0, $1.literal, 0);
                        }
                    |   VALUE_FLOAT
                        {
                            $$.value = Value(Value::VALUE_FLOAT_TYPE, 0, "", $1.float_value);
                        }
                    |   NULLL
                        {
                            $$.value = Value(Value::VALUE_NULL_TYPE, 0, "", 0);
                        }
                    ;                                                

WhereClauseList     :   WhereClause
                        {
                            $$.condList.clear();
                            $$.condList.push_back($1.cond);
                        }
                    |   WhereClauseList AND WhereClause
                        {
                            $$.condList.push_back($3.cond);
                        }
                    ;

WhereClause         :   Col Op Expr
                        {
                            $$.cond = Condition(Condition::COL_EXPR_TYPE);
                            $$.cond.col = $1.col;
                            $$.cond.optr = $2.optr;
                            $$.cond.expr = $3.expr;
                        }
                    |   Col LIKE Value
                		{
                			$$.cond = Condition(Condition::COL_LIKE_VALUE_TYPE);
                			$$.cond.col = $1.col;
                			$$.cond.value = $3.value;
                		}
                    |   Col IS NULLL
                        {
                            $$.cond = Condition(Condition::COL_IS_NULL_TYPE);
                            $$.cond.col = $1.col;
                        }
                    |   Col IS NOT NULLL
                        {
                            $$.cond = Condition(Condition::COL_IS_NOT_NULL_TYPE);
                            $$.cond.col = $1.col;
                        }
                    ;                   

Col                 :   ColName
                        {
                            $$.col = Attr("", $1.id);
                        }
                    |   TbName '.' ColName
                        {
                            $$.col = Attr($1.id, $3.id);
                        }    
                    ;

Op                  :   '='
                        {
                            $$.optr = "=";
                        }
                    |   NEQ
                        {
                            $$.optr = "<>";
                        }
                    |   LTE
                        {
                            $$.optr = "<=";
                        }
                    |   GTE
                        {
                            $$.optr = ">=";
                        }
                    |   '<'
                        {
                            $$.optr = "<";
                        }
                    |   '>'
                        {
                            $$.optr = ">";
                        }
                    ;
                                             
Expr                :   Value
                        {
                            $$.expr = Expr();
                            $$.expr.dataType = Expr::VALUE_EXPR_TYPE;
                            $$.expr.value = $1.value;
                        }
                    |   Col
                        {
                            $$.expr = Expr();
                            $$.expr.dataType = Expr::COL_EXPR_TYPE;
                            $$.expr.col = $1.col;
                        }
                    ;

SetClause           :   ColName '=' Value
                        {
                            $$.setList.clear();
                            $$.setList.push_back(Set($1.id, $3.value));
                        }
                    |   SetClause ',' ColName '=' Value
                        {
                            $$.setList.push_back(Set($3.id, $5.value));
                        }
                    ;

SelectorList        :   '*'
                        {
                            $$.selectorList.clear();
                            $$.selectorList.push_back(Selector(Selector::SELECTOR_ALL_TYPE));
                        }           
                    |   SelectorList ',' Selector
                        {
                            $$.selectorList.push_back($3.selector);
                        }
                    | 	Selector
            			{
            				$$.selectorList.clear();
            				$$.selectorList.push_back($1.selector);
            			}
                    ;                 

Selector            :   Col
                        {
                            $$.selector = Selector(Selector::SELECTOR_COL_TYPE, $1.col);                      
                        }             
                    |   SUM '(' Col ')'
                        {
                            $$.selector = Selector(Selector::SELECTOR_SUM_TYPE, $3.col);
                        }
                    |   AVG '(' Col ')'
                        {
                            $$.selector = Selector(Selector::SELECTOR_AVG_TYPE, $3.col);
                        }
                    |   MAX '(' Col ')'
                        {
                            $$.selector = Selector(Selector::SELECTOR_MAX_TYPE, $3.col);
                        }
                    |   MIN '(' Col ')'
                        {
                            $$.selector = Selector(Selector::SELECTOR_MIN_TYPE, $3.col);
                        }
                    ;                                                                                                                  

TableList           :   TbName
                        {
                            $$.tableList.clear();
                            $$.tableList.push_back($1.id);
                        }
                    |   TableList ',' TbName
                        {
                            $$.tableList.push_back($3.id);
                        }
                    ;

ColumnList          :   ColName
                        {
                            $$.columnList.clear();
                            $$.columnList.push_back($1.id);
                        }
                    |   ColumnList ',' ColName
                        {
                            $$.columnList.push_back($3.id);
                        }    
                    ; 

DbName              :   IDENTIFIER
                        {
                            $$.id = $1.id;
                        }
                    ;

TbName              :   IDENTIFIER
                        {
                            $$.id = $1.id;
                        }
                    ;

ColName             :   IDENTIFIER
                        {
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
    //FILE * f1 = fopen("SQL_TEST.txt", "r");
    //yyin = f1;
    yyparse();
    //fclose(f1);
    return 0;
}

