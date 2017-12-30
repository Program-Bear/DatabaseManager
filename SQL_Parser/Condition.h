#ifndef _CONDITION_H
#define _CONDITION_H

#include <list>
#include <string>
#include <iostream>
#include "Attr.h"
#include "Expr.h"
using namespace std;

class Condition
{
public: 
	enum CondType { COL_EXPR_TYPE, COL_IS_NULL_TYPE, COL_IS_NOT_NULL_TYPE};
	
	Condition() {}
    Condition(CondType ct) : condType(ct) {}
    
    CondType condType;
	
	Attr col;
	string optr;
	Expr expr;
};

#endif
