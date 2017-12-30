#ifndef _VALUE_H
#define _VALUE_H

#include <string>

class Value
{
public:
	enum ValueType { VALUE_INT_TYPE, VALUE_STRING_TYPE, VALUE_NULL_TYPE };
	
    Value() {}
    
    Value(ValueType t, int i, std::string s)
    {
        type = t;
        integer = i;
        literal = s;
    }
    
    ValueType type;
    int integer;
    std::string literal;
};

#endif
