#ifndef _VALUE_H
#define _VALUE_H

#include <string>

class Value
{
public:
    enum ValueCompatiblity { VALUE_NOT_COMPAT, VALUE_COMPAT, VALUE_INVALID_DATE };
	enum ValueType { VALUE_INT_TYPE, VALUE_DATE_TYPE, VALUE_STRING_TYPE, VALUE_FLOAT_TYPE, VALUE_NULL_TYPE };
	
    Value() {}
    
    Value(ValueType t, int i, std::string s, double d)
    {
        type = t;
        integer = i;
        literal = s;
        float_value = d;
    }

    std::string typeString()
    {
        switch (type)
        {
        case VALUE_INT_TYPE:
            return "int";
        case VALUE_DATE_TYPE:
            return "date";
        case VALUE_STRING_TYPE:
            return "string";
        case VALUE_FLOAT_TYPE:
            return "float";
        case VALUE_NULL_TYPE:
            return "NULL";
        }
    }

    std::string toString()
    {
        switch (type)
        {
        case VALUE_INT_TYPE:
            return "INT " + std::to_string(integer);
        case VALUE_DATE_TYPE:
            return "DATE " + literal;
        case VALUE_STRING_TYPE:
            return "STRING " + literal;
        case VALUE_FLOAT_TYPE:
            return "FLOAT " + std::to_string(float_value);
        case VALUE_NULL_TYPE:
            return "NULL";
        }
    }
    
    ValueType type;
    int integer;
    std::string literal;
    double float_value;
};

#endif
