%{
    #include <iostream>
    #include <cstdlib>
    #include "SemValue.cpp"
    #define YYSTYPE SemValue
    #include "Parser.tab.h"

    extern "C"
    {
        void yyerror(const char*);
        
        int yylex(void);
        
        int yywrap();

        //int yyparse(void);
    }

    std::string str;
%}


NEWLINE         (\r|\n|\r\n)
DIGIT           ([0-9])

IDENTIFIER      ([A-Za-z][_0-9A-Za-z]*)
VALUE_INT       ({DIGIT}+)
VALUE_STRING    ('[^']*')

OPERATOR        (","|"."|"*"|"("|")"|"="|"<"|">"|";")
WHITESPACE	    ([ \t]+)
LTE             ("<=")
GTE             (">=")
NEQ             ("<>")


DATABASE        ("DATABASE"|"database")
DATABASES       ("DATABASES"|"databases")
TABLE           ("TABLE"|"table")
TABLES          ("TABLES"|"tables")
SHOW            ("SHOW"|"show")
CREATE          ("CREATE"|"create")
DROP            ("DROP"|"drop")
USE             ("USE"|"use")
PRIMARY         ("PRIMARY"|"primary")
KEY             ("KEY"|"key")
NOT             ("NOT"|"not")
NULLL           ("NULL"|"null")
INSERT          ("INSERT"|"insert")
INTO            ("INTO"|"into")
VALUES          ("VALUES"|"values")
DELETE          ("DELETE"|"delete")
FROM            ("FROM"|"from")
WHERE           ("WHERE"|"where")
UPDATE          ("UPDATE"|"update")
SET             ("SET"|"set")
SELECT          ("SELECT"|"select")
IS              ("IS"|"is")
INT             ("INT"|"int")
VARCHAR         ("VARCHAR"|"varchar")
DESC            ("DESC"|"desc")
INDEX           ("INDEX"|"index")
AND             ("AND"|"and")
DATE            ("DATE"|"date")
FLOAT           ("FLOAT"|"float")
FOREIGN         ("FOREIGN"|"foreign")
REFERENCES      ("REFERENCES"|"references")

LIKE            ("LIKE"|"like")

SUM             ("SUM"|"sum")
AVG             ("AVG"|"avg")
MAX             ("MAX"|"max")
MIN             ("MIN"|"min")


%x SS
%x S






%%






{WHITESPACE}    { /* Just ignore */                     }
{NEWLINE}       { /* Just ignore */                     }


{DATABASE}      { return SemValue::keyword(DATABASE);   }
{DATABASES}     { return SemValue::keyword(DATABASES);  }
{TABLE}         { return SemValue::keyword(TABLE);      }
{TABLES}        { return SemValue::keyword(TABLES);     }
{SHOW}          { return SemValue::keyword(SHOW);       }
{CREATE}        { return SemValue::keyword(CREATE);     }
{DROP}          { return SemValue::keyword(DROP);       }
{USE}           { return SemValue::keyword(USE);        }
{PRIMARY}       { return SemValue::keyword(PRIMARY);    }
{KEY}           { return SemValue::keyword(KEY);        }
{NOT}           { return SemValue::keyword(NOT);        }
{NULLL}         { return SemValue::keyword(NULLL);      }
{INSERT}        { return SemValue::keyword(INSERT);     }
{INTO}          { return SemValue::keyword(INTO);       }
{VALUES}        { return SemValue::keyword(VALUES);     }
{DELETE}        { return SemValue::keyword(DELETE);     }
{FROM}          { return SemValue::keyword(FROM);       }
{WHERE}         { return SemValue::keyword(WHERE);      }
{UPDATE}        { return SemValue::keyword(UPDATE);     }
{SET}           { return SemValue::keyword(SET);        }
{SELECT}        { return SemValue::keyword(SELECT);     }
{IS}            { return SemValue::keyword(IS);         }
{INT}           { return SemValue::keyword(INT);        }
{VARCHAR}       { return SemValue::keyword(VARCHAR);    }
{DESC}          { return SemValue::keyword(DESC);       }
{INDEX}         { return SemValue::keyword(INDEX);      }
{AND}           { return SemValue::keyword(AND);        }
{DATE}          { return SemValue::keyword(DATE);       }
{FLOAT}         { return SemValue::keyword(FLOAT);      }
{FOREIGN}       { return SemValue::keyword(FOREIGN);    }
{REFERENCES}    { return SemValue::keyword(REFERENCES); }


{OPERATOR}      { return *yytext;                       }
{LTE}           { return SemValue::keyword(LTE);        }
{GTE}           { return SemValue::keyword(GTE);        }
{NEQ}           { return SemValue::keyword(NEQ);        }

{LIKE}          { return SemValue::keyword(LIKE);       }

{SUM}           { return SemValue::keyword(SUM);        }
{AVG}           { return SemValue::keyword(AVG);        }
{MAX}           { return SemValue::keyword(MAX);        }
{MIN}           { return SemValue::keyword(MIN);        }


{IDENTIFIER}    {
                    yylval = SemValue();
                    yylval.code = IDENTIFIER;
                    yylval.id = std::string(yytext);
                    return IDENTIFIER;
                }

{VALUE_INT}     {
                    yylval = SemValue();
                    yylval.code = VALUE_INT;
                    yylval.length = atoi(yytext);
                    return VALUE_INT;
                }

{VALUE_STRING}  {
                    yylval = SemValue();
                    yylval.code = VALUE_STRING;
                    yylval.literal = std::string(yytext);
                    return VALUE_STRING;
                }             

<INITIAL>\"     {
                    str = std::string();
                    BEGIN(SS);
                }

<INITIAL>\'     {
                    str = std::string();
                    BEGIN(S);
                }

<SS>\"          {
                    BEGIN(INITIAL);
                    yylval = SemValue();
                    yylval.code = LITERAL;
                    yylval.literal = str;
                    return LITERAL;
                }

<S>\'           {
                    BEGIN(INITIAL);
                    yylval = SemValue();
                    yylval.code = LITERAL;
                    yylval.literal = str;
                    return LITERAL;
                }

<SS>.           {
                    str += char(*yytext);
                }

<S>.            {
                    str += char(*yytext);
                }
                
.               {
                    return 256;
                }






%%






int yywrap(void)
{
    return 1;
}
