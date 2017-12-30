#ifndef _EXPR_H
#define _EXPR_H

#include <string>
#include "Attr.h"
#include "Value.h"

class Expr
{
public:
    enum ExprType { COL_EXPR_TYPE, VALUE_EXPR_TYPE };
    
    Expr() {}
    
    ExprType dataType;
    
    Attr col;
    
    Value value;
};

#endif
