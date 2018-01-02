#ifndef COLUMN_H
#define COLUMN_H

#include <map>
#include <string>

#include "SemValue.h"

using std::map;
using std::string;

bool dateVerify(string literal)  
{  
    int year = 0, month = 0, day = 0;
    sscanf(literal.c_str(), "%4d-%2d-%2d", &year, &month, &day);
    
    if (month < 1 || month > 12 || day < 1 || day > 31) 
    {  
        return false;  
    }  
  
    switch (month) 
    {  
    case 4:  
    case 6:  
    case 9:  
    case 11:  
        if (day > 30) 
        {
            return false;  
        }  
        break;  
    case 2:   
        {  
            bool bLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  
            if ((bLeapYear && day > 29) || (!bLeapYear && day > 28)) 
            {  
                return false;  
            }  
        }  
        break;  
    default:  
        break;  
    }  
  
    return true;  
}  

class Column
{
public:
    Column() : isNotNull(false), isForeign(false), hasIndex(false) {}
    Column(string _colName) : colName(colName) {}
    Column(string _colName, string _dataType, int _length, bool _isNotNull) :
        colName(_colName), dataType(_dataType), length(_length), isNotNull(_isNotNull), isForeign(false), hasIndex(false) {}
    //Column(string _foreignKey, bool _isForeign, string t, string c) :
    //    isNotNull(false), colName(_foreignKey), isForeign(_isForeign), referenceTableName(t), referenceColName(c), hasIndex(false) {}

    Value::ValueCompatiblity typeCompatible(Value value)
    {
        Value::ValueType type = value.type;

        if ((dataType == "int" && type == Value::VALUE_INT_TYPE) || (dataType == "varchar" && type == Value::VALUE_STRING_TYPE) || (dataType == "float" && (type == Value::VALUE_FLOAT_TYPE || type == Value::VALUE_INT_TYPE)) || (!isNotNull && type == Value::VALUE_NULL_TYPE))
        {
            return Value::VALUE_COMPAT;
        }
        else if (dataType == "date" && type == Value::VALUE_DATE_TYPE)
        {
            if (dateVerify(value.literal))
            {
                return Value::VALUE_COMPAT;
            }
            else
            {
                return Value::VALUE_INVALID_DATE;
            }
        }
        else
        {
            return Value::VALUE_NOT_COMPAT;
        }
    }

    string dataTypeString()
    {
        string ans = dataType;
        if (isNotNull)
        {
            ans += " NOT NULL";
        }
        return ans;
    }

    string colName;

    string dataType;  // "int" "varchar" "date" "float"  date : "2017/12/31" stored as VARCHAR(15)
    int length;
    bool isNotNull;

    bool isForeign;
    string referenceTableName;
    string referenceColName;

    bool hasIndex;
};

#endif  // COLUMN_H
