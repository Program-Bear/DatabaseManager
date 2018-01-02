#ifndef _CONDITION_H
#define _CONDITION_H

#include <string>
#include <iostream>
#include "Attr.h"
#include "Expr.h"
using namespace std;

class Condition
{
public: 
	enum CondType { COL_EXPR_TYPE, COL_LIKE_VALUE_TYPE, COL_IS_NULL_TYPE, COL_IS_NOT_NULL_TYPE };
	
	Condition() {}
    Condition(CondType ct) : condType(ct) {}
    
    CondType condType;

    string toString()
    {
        string ans = "";

        switch (condType)
        {
        case COL_EXPR_TYPE:
            ans += col.tbname == "" ? "this" : col.tbname; 
            ans += "." + col.attrname + " " + optr + " ";                
            if (expr.dataType == Expr::COL_EXPR_TYPE)
            {
                ans += expr.col.tbname == "" ? "this" : expr.col.tbname;
                ans += "." + expr.col.attrname;
            }
            else
            {
                ans += expr.value.toString();
            }
            return ans;
        case COL_LIKE_VALUE_TYPE:
            ans += col.tbname == "" ? "this" : col.tbname; 
            ans += "." + col.attrname + " LIKE ";
            ans += value.toString();
            return ans;
        case COL_IS_NULL_TYPE:
            ans += col.tbname == "" ? "this" : col.tbname; 
            ans += "." + col.attrname + " IS NULL";
            return ans;
        case COL_IS_NOT_NULL_TYPE:
            ans += col.tbname == "" ? "this" : col.tbname; 
            ans += "." + col.attrname + " IS NOT NULL";
        }
    }
	
	Attr col;
	string optr;
	Expr expr;
	Value value;
};

#endif
